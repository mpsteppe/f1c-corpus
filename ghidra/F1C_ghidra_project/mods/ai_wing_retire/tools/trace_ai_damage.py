"""
trace_ai_damage.py — live diff-scanner for ONE AI vehicle slot.

No "wing damage" field is documented anywhere in this corpus (name_index.json /
skeletons_filled / f1c_sdk.h). This tool exists to FIND it live: it polls a
window of an AI car's struct every tick and reports any 4-byte offset whose
value changes, tagging the offset with its known name if name_index.json
already has one, so we don't have to blind-guess.

Non-ASLR exe: vehicle base 0x5EC6D8, stride 0x48C0, 104 slots (FACT, see
tools/sdk/f1c_sdk.json). Slot 0 = player. Pick an AI slot (1-103), watch it,
then ram/collide it into a wall until it loses a wing in-game.

USAGE
-----
  python tools/trace_ai_damage.py list                       # slot -> driver name
  python tools/trace_ai_damage.py <slot> [--lo 0x3000] [--hi 0x4900] [--hz 5]

Defaults to the 0x3000-0x4900 band, where every currently-known per-vehicle
status/damage/timer field lives (fuel, tires, gearbox, engine failure,
lap/finish/retire state). Widen with --lo 0 --hi 0x48c0 for a full scan if
the wing field turns out to live in the low physics-heavy region.

Writes nothing. Read-only.
"""

import ctypes
import ctypes.wintypes as wt
import json
import os
import re
import struct
import sys
import time

if sys.platform == 'win32':
    sys.stdout.reconfigure(encoding='utf-8', errors='replace')

TOOLS_DIR = os.path.dirname(os.path.abspath(__file__))
CORPUS_ROOT = os.path.abspath(os.path.join(TOOLS_DIR, "..", "..", ".."))
NAME_INDEX = os.path.join(CORPUS_ROOT, "name_index.json")
PROC_NAME = "F1 Challenge Online.exe"

VEH_BASE = 0x5EC6D8
VEH_STRIDE = 0x48C0
VEH_SLOTS = 104
VEH_PTR_ARRAY = 0x7C54F0

PROCESS_ALL = 0x0010 | 0x0020 | 0x0008 | 0x0400  # VM_READ|VM_WRITE|VM_OPERATION|QUERY

# Fields already known (FACT/CONFIRMED) to change every single frame — skip
# these so the log isn't drowned in expected noise. Everything else that
# moves in the scan window is a live lead.
NOISY_OFFSETS = {
    0x357C,  # ThrottleFactor
    0x3584,  # BrakeFactor
    0x39A0,  # EngineRPM
    0x39FC,  # CurrentGear
    0x34B8,  # elapsedTime (alt)
    0x4570,  # elapsedTime
    0x4098,  # totalTimeOnFinishLine
}


class PROCESSENTRY32(ctypes.Structure):
    _fields_ = [('dwSize', wt.DWORD), ('cntUsage', wt.DWORD),
                ('th32ProcessID', wt.DWORD),
                ('th32DefaultHeapID', ctypes.POINTER(wt.ULONG)),
                ('th32ModuleID', wt.DWORD), ('cntThreads', wt.DWORD),
                ('th32ParentProcessID', wt.DWORD), ('pcPriClassBase', wt.LONG),
                ('dwFlags', wt.DWORD), ('szExeFile', ctypes.c_char * 260)]


def find_pid(name=PROC_NAME):
    k32 = ctypes.windll.kernel32
    snap = k32.CreateToolhelp32Snapshot(0x2, 0)
    entry = PROCESSENTRY32()
    entry.dwSize = ctypes.sizeof(PROCESSENTRY32)
    pid = None
    if k32.Process32First(snap, ctypes.byref(entry)):
        while True:
            if entry.szExeFile.decode(errors='replace').lower() == name.lower():
                pid = entry.th32ProcessID
                break
            if not k32.Process32Next(snap, ctypes.byref(entry)):
                break
    k32.CloseHandle(snap)
    return pid


class Game:
    def __init__(self):
        self.k32 = ctypes.windll.kernel32
        pid = find_pid()
        if not pid:
            sys.exit(f"'{PROC_NAME}' is not running — start the game first")
        self.h = self.k32.OpenProcess(PROCESS_ALL, False, pid)
        if not self.h:
            sys.exit(f"OpenProcess failed (run as admin?) — pid {pid}")

    def read(self, addr, size):
        buf = ctypes.create_string_buffer(size)
        got = ctypes.c_size_t()
        if not self.k32.ReadProcessMemory(self.h, ctypes.c_void_p(addr), buf,
                                           size, ctypes.byref(got)):
            return None
        return buf.raw[:got.value]

    def read_u32(self, addr):
        raw = self.read(addr, 4)
        return None if raw is None else struct.unpack('<I', raw)[0]


def load_offset_names():
    """offset(int) -> name, for entries in name_index.json keyed by a hex
    offset smaller than the vehicle stride (i.e. vehicle-relative fields)."""
    names = {}
    try:
        with open(NAME_INDEX, encoding='utf-8') as f:
            idx = json.load(f)
    except FileNotFoundError:
        return names
    for k, v in idx.items():
        m = re.match(r'^0x([0-9a-fA-F]+)$', k)
        if not m:
            continue
        off = int(m.group(1), 16)
        if 0 <= off < VEH_STRIDE:
            names[off] = f"{v.get('name','?')} [{v.get('trust','?')}]"
    return names


def cmd_list(game):
    # DriverName [FACT] at +0x4620, ActiveFlag [FACT] at +0x45F4, slot-active
    # test +0x32C8 != -1 (FACT, see CLAUDE.md vehicle array note).
    for slot in range(VEH_SLOTS):
        base = VEH_BASE + slot * VEH_STRIDE
        active = game.read_u32(base + 0x32C8)
        if active is None or active == 0xFFFFFFFF:
            continue
        raw = game.read(base + 0x4620, 0x58) or b""
        name = raw.split(b"\x00", 1)[0].decode(errors="replace")
        print(f"  slot {slot:3d}  {name}")


def main():
    if len(sys.argv) < 2:
        print(__doc__)
        return
    if sys.argv[1] == 'list':
        cmd_list(Game())
        return
    slot = int(sys.argv[1], 0)
    if not (0 <= slot < VEH_SLOTS):
        sys.exit(f"slot must be 0-{VEH_SLOTS-1}")

    lo, hi, hz = 0x3000, 0x4900, 5.0
    args = sys.argv[2:]
    it = iter(args)
    for a in it:
        if a == '--lo':
            lo = int(next(it), 0)
        elif a == '--hi':
            hi = int(next(it), 0)
        elif a == '--hz':
            hz = float(next(it))

    lo &= ~0x3  # align to 4 bytes
    hi &= ~0x3
    names = load_offset_names()
    game = Game()
    base = VEH_BASE + slot * VEH_STRIDE

    print(f"tracing slot {slot} @ 0x{base:08x}, offsets 0x{lo:04x}-0x{hi:04x}, {hz} Hz")
    print("Ctrl+C to stop. Cause the damage in-game now.")

    n = (hi - lo) // 4
    prev = [None] * n
    first = True
    try:
        while True:
            ts = time.strftime('%H:%M:%S')
            for i in range(n):
                off = lo + i * 4
                if off in NOISY_OFFSETS:
                    continue
                raw = game.read_u32(base + off)
                if raw is None:
                    continue
                if not first and prev[i] is not None and raw != prev[i]:
                    fval = struct.unpack('<f', struct.pack('<I', raw))[0]
                    pfval = struct.unpack('<f', struct.pack('<I', prev[i]))[0]
                    tag = names.get(off, "")
                    print(f"  {ts}  +0x{off:04x} {tag:30s} "
                          f"int {prev[i]}->{raw}  float {pfval:.6g}->{fval:.6g}")
                prev[i] = raw
            first = False
            time.sleep(1.0 / hz)
    except KeyboardInterrupt:
        pass


if __name__ == '__main__':
    main()
