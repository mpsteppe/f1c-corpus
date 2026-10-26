#!/usr/bin/env python3
"""
Physics System-ID — Step 0: Channel discovery.

Attaches Frida to a RUNNING F1 Challenge session, follows PlayerVehiclePtr, and
polls a byte range of the vehicle struct as doubles + floats. Logs every sample to
CSV, then ranks each offset by variance so you can see WHICH offsets are live
telemetry channels (grip / slip / load / speed / temp) vs static/zero.

This answers the first gating unknown: "does the struct expose the channels we want
to fit?" — BEFORE building any input sweep or fitting pipeline.

PREREQUISITE: game must be in an active on-track session (hotlap/practice) while
this runs. Drive the car — channels only move when the physics is ticking.

    pip install frida frida-tools

Usage:
    python map_channels.py                       # default: 0x1100..0x1600, 100Hz, 20s
    python map_channels.py --lo 0x1100 --hi 0x1600 --hz 100 --secs 20
    python map_channels.py --out mychannels.csv

Then read the ranked summary it prints. Offsets with high variance during driving
= your candidate physics channels. Feed those to the next stage (input sweep).
"""

import argparse
import csv
import sys
import time
from pathlib import Path

try:
    import frida
except ImportError:
    sys.exit("frida not installed. Run: pip install frida frida-tools")

PROCESS_NAME = "F1 Challenge Online.exe"
PLAYER_VEHICLE_PTR = 0x007c54e8   # docs/22 §11 — ptr to player vehicle struct (GUESS-tier; verify)

# Frida agent: resolve the player vehicle ptr each poll (it can move / be null between
# sessions), then read [lo, hi) as both f64 (stride 8) and f32 (stride 4). Sends rows up.
AGENT = r"""
const PLAYER_PTR_ADDR = ptr('%(player_ptr)s');
const LO = %(lo)d, HI = %(hi)d;
const INTERVAL_MS = %(interval_ms)d;

function poll() {
    try {
        const veh = PLAYER_PTR_ADDR.readPointer();
        if (veh.isNull()) { send({t: 'noveh'}); return; }
        const f64 = {}, f32 = {};
        for (let off = LO; off + 8 <= HI; off += 8) {
            const v = veh.add(off).readDouble();
            if (isFinite(v)) f64[off] = v;
        }
        for (let off = LO; off + 4 <= HI; off += 4) {
            const v = veh.add(off).readFloat();
            if (isFinite(v)) f32[off] = v;
        }
        send({t: 'sample', ts: Date.now(), veh: veh.toString(), f64: f64, f32: f32});
    } catch (e) {
        send({t: 'err', msg: e.message});
    }
}
setInterval(poll, INTERVAL_MS);
send({t: 'ready', lo: LO, hi: HI});
"""


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--lo', type=lambda x: int(x, 0), default=0x1100,
                    help='low struct offset (default 0x1100)')
    ap.add_argument('--hi', type=lambda x: int(x, 0), default=0x1600,
                    help='high struct offset, exclusive (default 0x1600)')
    ap.add_argument('--hz', type=int, default=100, help='poll rate (default 100)')
    ap.add_argument('--secs', type=float, default=20.0, help='capture duration (default 20)')
    ap.add_argument('--out', default=str(Path(__file__).parent / 'channels.csv'))
    args = ap.parse_args()

    interval_ms = max(1, int(1000 / args.hz))
    rows = []          # list of dicts: {ts, off, kind, val}
    seen_veh = set()
    state = {'ready': False, 'noveh': 0}

    def on_message(msg, data):
        if msg.get('type') != 'send':
            print('[frida]', msg, file=sys.stderr); return
        p = msg['payload']
        t = p.get('t')
        if t == 'ready':
            state['ready'] = True
            print(f"agent ready — reading struct [{hex(p['lo'])}, {hex(p['hi'])})")
        elif t == 'noveh':
            state['noveh'] += 1
        elif t == 'sample':
            seen_veh.add(p['veh'])
            ts = p['ts']
            for off, v in p['f64'].items():
                rows.append((ts, int(off), 'f64', v))
            for off, v in p['f32'].items():
                rows.append((ts, int(off), 'f32', v))
        elif t == 'err':
            print('[agent err]', p['msg'], file=sys.stderr)

    print(f"attaching to {PROCESS_NAME} ...")
    try:
        session = frida.attach(PROCESS_NAME)
    except frida.ProcessNotFoundError:
        sys.exit(f"process not found — is the game running? ({PROCESS_NAME})")

    script_src = AGENT % {
        'player_ptr': hex(PLAYER_VEHICLE_PTR),
        'lo': args.lo, 'hi': args.hi, 'interval_ms': interval_ms,
    }
    script = session.create_script(script_src)
    script.on('message', on_message)
    script.load()

    print(f"capturing {args.secs}s at ~{args.hz}Hz — DRIVE THE CAR NOW")
    time.sleep(args.secs)
    try:
        script.unload()
    except frida.InvalidOperationError:
        pass
    session.detach()

    if state['noveh']:
        print(f"WARNING: player vehicle ptr was null on {state['noveh']} polls "
              f"(not in an active session?)")
    if not rows:
        sys.exit("no samples captured — was the game in an on-track session?")

    # write raw
    with open(args.out, 'w', newline='') as f:
        w = csv.writer(f)
        w.writerow(['ts_ms', 'offset', 'kind', 'value'])
        for ts, off, kind, v in rows:
            w.writerow([ts, hex(off), kind, v])
    print(f"\nwrote {len(rows)} samples to {args.out}")
    print(f"player vehicle ptr(s) seen: {sorted(seen_veh)}")

    # rank offsets by variance (per kind) — the 'live' channels
    from collections import defaultdict
    series = defaultdict(list)
    for ts, off, kind, v in rows:
        series[(off, kind)].append(v)

    def stats(vals):
        n = len(vals)
        m = sum(vals) / n
        var = sum((x - m) ** 2 for x in vals) / n
        return m, var, min(vals), max(vals)

    ranked = []
    for (off, kind), vals in series.items():
        m, var, lo, hi = stats(vals)
        ranked.append((var, off, kind, m, lo, hi, len(vals)))
    ranked.sort(reverse=True)

    print("\n=== LIVE CHANNELS (ranked by variance during driving) ===")
    print(f"{'offset':>8} {'kind':>4} {'variance':>14} {'mean':>14} "
          f"{'min':>12} {'max':>12}")
    shown = 0
    for var, off, kind, m, lo, hi, n in ranked:
        if var <= 0:
            continue
        print(f"{hex(off):>8} {kind:>4} {var:>14.4g} {m:>14.4g} "
              f"{lo:>12.4g} {hi:>12.4g}")
        shown += 1
        if shown >= 40:
            print("... (truncated; full data in CSV)")
            break
    if shown == 0:
        print("no channel varied — car wasn't moving, or offsets/ptr are wrong.")

    print("\nNext: pick the channels that match physics quantities you want to fit "
          "(grip/slip/load/speed/temp), confirm each against raw .c, then build the "
          "input-drive sweep on those offsets.")


if __name__ == '__main__':
    main()
