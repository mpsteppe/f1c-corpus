"""Poll key retirement-related fields for one vehicle slot until Ctrl+C, printing every change with a timestamp. Read-only."""
import os, sys, time, struct
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from trace_ai_damage import Game, VEH_BASE, VEH_STRIDE

slot = int(sys.argv[1], 0)
base = VEH_BASE + slot * VEH_STRIDE

NAMED = {
 0x4068:'ReasonCode', 0x454c:'callToBox', 0x4040:'pitState', 0x3450:'pittingStatus',
 0x4510:'driverStatus', 0x4410:'RetiredFlag', 0x4064:'FinishState', 0x39fa:'retirementPending',
 0x3d6c:'carConditions', 0x39fc:'CurrentGear', 0x45f4:'ActiveFlag', 0x4440:'Speed',
 0x41f8:'new_41f8', 0x423c:'new_423c', 0x4280:'new_4280', 0x42c4:'new_42c4',
 0x42ec:'new_42ec', 0x4308:'new_4308', 0x4324:'new_4324', 0x4338:'new_4338',
 0x4344:'new_4344', 0x4458:'new_4458', 0x4468:'new_4468', 0x4544:'new_4544',
 0x455c:'new_455c', 0x456c:'new_456c',
}

g = Game()
prev = {off: g.read_u32(base+off) for off in NAMED}
print(f"watching slot {slot} @ 0x{base:08x} — {len(NAMED)} fields, Ctrl+C to stop")
t0 = time.time()
try:
    while True:
        for off, name in NAMED.items():
            v = g.read_u32(base+off)
            if v != prev[off]:
                print(f"[{time.time()-t0:7.2f}s] {name:12s} +0x{off:04x}  {prev[off]} -> {v}")
                prev[off] = v
        time.sleep(0.2)
except KeyboardInterrupt:
    pass
