"""
trace_write_source.py — instruction-level write tracer for a vehicle struct
offset, using Frida's MemoryAccessMonitor (guard-page based), which reports
the actual writer instruction address (`details.from`) for every write.

This is NOT polling. Static/live-diff tools (poke.py, trace_ai_damage.py)
can only tell you an offset changed; they cannot tell you which instruction
changed it. This tool answers that question directly, adapting the proven
pattern already used in F1C_ghidra_project/tools/trace/agent.js (there it
watches fixed globals like GameState/SessionType; here it watches arbitrary
vehicle-struct offsets, which is possible because the exe is non-ASLR so
VEH_BASE + slot*STRIDE + offset is a fixed absolute address computable
ahead of time).

USAGE
-----
  python tools/trace_write_source.py <slot> <offset_hex> [<offset_hex> ...]
  python tools/trace_write_source.py 8 0x42f4 0x4348 0x434c

Attaches to the running game, arms a write watchpoint on each address, and
prints every write with: elapsed ms, new value (as int32), and the writer's
address — resolved to the nearest known function name from
skeleton_facts_all.json if one starts at or before it.

Ctrl+C to stop and detach cleanly.
"""

import bisect
import json
import os
import sys
import time

import frida

TOOLS_DIR = os.path.dirname(os.path.abspath(__file__))
CORPUS_ROOT = os.path.abspath(os.path.join(TOOLS_DIR, "..", "..", ".."))
FACTS_JSON = os.path.join(CORPUS_ROOT, "skeleton_facts_all.json")
PROC_NAME = "F1 Challenge Online.exe"

VEH_BASE = 0x5EC6D8
VEH_STRIDE = 0x48C0
VEH_SLOTS = 104

AGENT_JS = r"""
'use strict';
const TARGETS = %(targets)s; // [{addr, label}]
const start = Date.now();

for (const t of TARGETS) {
    try {
        const target = ptr(t.addr);
        MemoryAccessMonitor.enable([{base: target, size: 4}], {
            onAccess: function (details) {
                if (details.operation !== 'write') return;
                let val;
                try { val = target.readS32(); } catch (e) { val = null; }
                send({
                    type: 'write',
                    label: t.label,
                    addr: t.addr,
                    value: val,
                    writer: details.from.toString(),
                    time: Date.now() - start
                });
            }
        });
        send({type: 'armed', label: t.label, addr: t.addr});
    } catch (e) {
        send({type: 'error', label: t.label, msg: e.message});
    }
}
"""


def load_func_index():
    """sorted list of (addr_int, name) for nearest-function-below lookup."""
    try:
        with open(FACTS_JSON, encoding='utf-8') as f:
            facts = json.load(f)
    except FileNotFoundError:
        return [], []
    items = sorted((int(a, 16), v.get('name', a)) for a, v in facts.items())
    addrs = [a for a, _ in items]
    return addrs, items


def resolve_writer(addr_str, addrs, items):
    try:
        addr = int(addr_str, 16)
    except ValueError:
        return "?"
    i = bisect.bisect_right(addrs, addr) - 1
    if i < 0:
        return "?"
    base, name = items[i]
    return f"{name}+0x{addr - base:x} (0x{base:06x})"


def main():
    if len(sys.argv) < 3:
        print(__doc__)
        return
    slot = int(sys.argv[1], 0)
    if not (0 <= slot < VEH_SLOTS):
        sys.exit(f"slot must be 0-{VEH_SLOTS-1}")
    offsets = [int(o, 16) for o in sys.argv[2:]]

    base = VEH_BASE + slot * VEH_STRIDE
    targets = [{"addr": hex(base + off), "label": f"slot{slot}+0x{off:04x}"} for off in offsets]

    addrs, items = load_func_index()

    try:
        session = frida.attach(PROC_NAME)
    except frida.ProcessNotFoundError:
        sys.exit(f"'{PROC_NAME}' is not running — start the game first")

    script = session.create_script(AGENT_JS % {"targets": json.dumps(targets)})

    def on_message(message, data):
        if message.get('type') != 'send':
            print(message)
            return
        p = message['payload']
        if p['type'] == 'armed':
            print(f"armed  {p['label']} @ {p['addr']}")
        elif p['type'] == 'error':
            print(f"ERROR  {p['label']}: {p['msg']}")
        elif p['type'] == 'write':
            writer = resolve_writer(p['writer'], addrs, items)
            print(f"[{p['time']:>7d}ms] {p['label']:20s} = {p['value']:<12} written by {writer}")

    script.on('message', on_message)
    script.load()

    print("watching — Ctrl+C to stop. Cause the event in-game now.")
    try:
        while True:
            time.sleep(0.5)
    except KeyboardInterrupt:
        pass
    session.detach()


if __name__ == '__main__':
    main()
