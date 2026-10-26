"""Watch player-car (slot 0) fields tied to the wheel-detach hypothesis derived
statically from RepairServiceStateDispatcher_004ed250 / SubslotCleanup_004e0e70.

Watches:
  veh+0x3D60  int   damage-severity enum (0/1/2, DERIVED)
  veh+0x3D6C  float carConditions (CONFIRMED, for correlation)
  veh+0x32BC  int   collision processing mode flag (CONFIRMED)
  veh+0x6E4 + 296*i + 324  ptr   per-wheel subslot resource handle A (i=0..3)
  veh+0x6E4 + 296*i + 716  ptr   per-wheel subslot resource handle B (i=0..3)

Read-only. Ctrl+C to stop.
"""
import os, sys, time
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from trace_ai_damage import Game, VEH_BASE, VEH_STRIDE

slot = 0
base = VEH_BASE + slot * VEH_STRIDE

WATCH = {
    0x3D60: 'damageState',
    0x3D6C: 'carConditions',
    0x32BC: 'collisionModeFlag',
}
for i in range(4):
    WATCH[0x6E4 + 296 * i + 324] = f'wheel{i}_resA'
    WATCH[0x6E4 + 296 * i + 716] = f'wheel{i}_resB'

g = Game()
prev = {off: g.read_u32(base + off) for off in WATCH}
print(f"watching player slot 0 @ 0x{base:08x} — {len(WATCH)} fields, Ctrl+C to stop")
for off, name in sorted(WATCH.items()):
    print(f"  +0x{off:04x} {name:16s} = {prev[off]}")
t0 = time.time()
try:
    while True:
        for off, name in WATCH.items():
            v = g.read_u32(base + off)
            if v != prev[off]:
                print(f"[{time.time()-t0:7.2f}s] {name:16s} +0x{off:04x}  {prev[off]} -> {v}")
                prev[off] = v
        time.sleep(0.15)
except KeyboardInterrupt:
    pass
