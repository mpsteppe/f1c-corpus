## VehicleDynamicsStateReset_004f2320 — vehicle dynamics state zero reset

**Summary:** Zeroes rendering state fields (RenderX/Y/Z and related) and per-wheel data blocks. Optionally triggers additional suspension physics reset based on enable flag.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AISteeringRacingLineCorrection (0042b0e0), VehicleYawRotationRecoveryController (004f1c40)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x32BC | R | — | flag: zero triggers additional suspension reset |
| this | 0x34EC | RW | 0 | render state field cleared to zero |
| this | 0x34F0 | RW | 0 | RenderX [FACT] |
| this | 0x34F4 | RW | 0 | RenderY [FACT] |
| this | 0x34F8 | RW | 0 | RenderZ [FACT] |
| this | 0x34FC | RW | 0 | render state field cleared to zero |
| this | 0x3500 | RW | 0 | render state field cleared to zero |
| this | 0x3504 | RW | 0 | render state field cleared to zero |
| this | 0x3508 | RW | 0 | render state field cleared to zero |
| this | 0x350C | RW | 0 | render state field cleared to zero |
| this | 0x35B0 | RW | 0 | start of per-wheel data array (4 entries, 62 DWORD stride each) |

**Written-by note (persistence):**
- this 0x34EC: recalc every frame — external poke does NOT persist
- this 0x34F0: recalc every frame — external poke does NOT persist
- this 0x34F4: recalc every frame — external poke does NOT persist
- this 0x34F8: recalc every frame — external poke does NOT persist
- this 0x34FC: recalc every frame — external poke does NOT persist
- this 0x3500: recalc every frame — external poke does NOT persist
- this 0x3504: recalc every frame — external poke does NOT persist
- this 0x3508: recalc every frame — external poke does NOT persist
- this 0x350C: recalc every frame — external poke does NOT persist
- this 0x35B0: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007c7428 | dbl_7C7428 | R | RaceTimeElapsed [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Always zeroes render state fields (0x34EC-0x350C) and 4 per-wheel blocks. If field 0x32BC is zero → additionally calls PhysicsStateZeroingResetForSuspension. If 0x32BC non-zero → skips suspension reset path.
