"""
trace_broad_write.py — broad instruction-level write tracer with an
auto-learned noise floor, for one vehicle slot.

Rationale: watching a handful of hand-picked offsets (trace_write_source.py)
already produced one clean negative result (Hakkinen's wing+2 wheels: zero
writes on the 6 watched fields) — meaning the real damage field, if any, is
somewhere else in the struct. Instead of guessing more offsets one at a
time, this watches the WHOLE 0x3000-0x4900 band via Frida
MemoryAccessMonitor and resolves every writer's instruction address. To
keep it usable (that band is full of legitimate per-frame physics writes),
it runs a short WARMUP first: writes seen during warmup (car driving,
undamaged) are learned as "normal" and suppressed. Only offsets that start
writing AFTER warmup — i.e. new activity, presumably triggered by whatever
happens next in-game — are printed, with their writer instruction address.

USAGE
-----
  python tools/trace_broad_write.py <slot> [--lo 0x3000] [--hi 0x4900] [--warmup 2.0]

Sequence: arm on a car that is CURRENTLY DRIVING NORMALLY (undamaged),
let the warmup window elapse doing nothing special, then cause the hit.
Anything printed after warmup is new — a real candidate.
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
const BASE = ptr(%(base)s);
const SIZE = %(size)d;
const start = Date.now();

// MemoryAccessMonitor is one-shot per page: after the first trap on a page,
// that page's guard is gone until re-armed. Re-enable on every hit so
// monitoring survives repeated writes across the whole session, not just
// the first touch.
function arm() {
    MemoryAccessMonitor.enable([{base: BASE, size: SIZE}], {
        onAccess: function (details) {
            if (details.operation === 'write') {
                const addr = details.address;
                const off = addr.sub(BASE).toInt32();
                let val;
                try { val = addr.readS32(); } catch (e) { val = null; }
                send({
                    type: 'write',
                    off: off,
                    value: val,
                    writer: details.from.toString(),
                    time: Date.now() - start
                });
            }
            arm();
        }
    });
}
arm();
send({type: 'armed', base: BASE.toString(), size: SIZE});
"""


def load_func_index():
    try:
        with open(FACTS_JSON, encoding='utf-8') as f:
            facts = json.load(f)
    except FileNotFoundError:
        return [], []
    items = sorted((int(a, 16), v.get('name', a)) for a, v in facts.items())
    return [a for a, _ in items], items


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
    if len(sys.argv) < 2:
        print(__doc__)
        return
    slot = int(sys.argv[1], 0)
    if not (0 <= slot < VEH_SLOTS):
        sys.exit(f"slot must be 0-{VEH_SLOTS-1}")

    lo, hi, warmup = 0x3000, 0x4900, 2.0
    args = sys.argv[2:]
    it = iter(args)
    for a in it:
        if a == '--lo':
            lo = int(next(it), 0)
        elif a == '--hi':
            hi = int(next(it), 0)
        elif a == '--warmup':
            warmup = float(next(it))

    base = VEH_BASE + slot * VEH_STRIDE + lo
    size = hi - lo
    addrs, items = load_func_index()

    try:
        session = frida.attach(PROC_NAME)
    except frida.ProcessNotFoundError:
        sys.exit(f"'{PROC_NAME}' is not running — start the game first")

    script = session.create_script(AGENT_JS % {"base": hex(base), "size": size})

    warm_until = [None]  # set once armed
    seen_noisy = set()
    counts = {}

    def on_message(message, data):
        if message.get('type') != 'send':
            print(message)
            return
        p = message['payload']
        if p['type'] == 'armed':
            print(f"armed slot {slot} @ {p['base']} size 0x{p['size']:x} "
                  f"(offsets 0x{lo:04x}-0x{hi:04x})")
            print(f"warming up {warmup}s — do NOT cause the hit yet, let the car drive normally")
            warm_until[0] = time.time() + warmup
        elif p['type'] == 'write':
            off = p['off']
            now = time.time()
            if warm_until[0] is None:
                return
            if now < warm_until[0]:
                seen_noisy.add(off)
                return
            if off in seen_noisy:
                counts[off] = counts.get(off, 0) + 1
                return  # already-known noisy offset, suppress spam
            writer = resolve_writer(p['writer'], addrs, items)
            print(f"[{p['time']:>7d}ms] NEW +0x{off:04x} = {p['value']:<12} written by {writer}")

    script.on('message', on_message)
    script.load()

    try:
        while warm_until[0] is None:
            time.sleep(0.05)
        remaining = warm_until[0] - time.time()
        if remaining > 0:
            time.sleep(remaining)
        print(f"warmup done — {len(seen_noisy)} offsets flagged as normal/noisy. "
              f"Cause the event now. Ctrl+C to stop.")
        while True:
            time.sleep(0.5)
    except KeyboardInterrupt:
        pass
    session.detach()


if __name__ == '__main__':
    main()
