## sub_4E5AE0_004e5ae0 — VehicleAngularDynamicsAndSuspensionUpdate

**Summary:** Integrates vehicle angular velocity and torque from engine contribution and per-wheel forces, then computes suspension/damper response based on a mode selector. Part of the physics simulation system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** PhysicsIntegrationStateMachine (004e4e60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x34A8 | R | — | timestep/dt — multiplier for all integrations |
| this | 0x34B0 | R | — | rotation matrix row 0, col 0 |
| this | 0x34B4 | R | — | rotation matrix row 0, col 1 |
| this | 0x34B8 | R | — | rotation matrix row 0, col 2 |
| this | 0x34BC | R | — | rotation matrix row 1, col 0 |
| this | 0x34C0 | R | — | rotation matrix row 1, col 1 |
| this | 0x34C4 | R | — | rotation matrix row 1, col 2 |
| this | 0x34C8 | R | — | rotation matrix row 2, col 0 |
| this | 0x34CC | R | — | rotation matrix row 2, col 1 |
| this | 0x34D0 | R | — | rotation matrix row 2, col 2 |
| this | 0x34D4 | RW | — | accumulated angular velocity X (body frame) |
| this | 0x34D8 | RW | — | accumulated angular velocity Y (body frame) |
| this | 0x34DC | RW | — | accumulated angular velocity Z (body frame) |
| this | 0x34EC | RW | — | accumulated torque X (body frame) |
| this | 0x34F0 | RW | — | accumulated torque Y (body frame) |
| this | 0x34F4 | RW | — | accumulated torque Z (body frame) |
| this | 0x34F8 | RW | — | world-space torque X |
| this | 0x34FC | RW | — | world-space torque Y |
| this | 0x3500 | RW | — | world-space torque Z |
| this | 0x3504 | RW | — | accumulated body-frame torque contribution X |
| this | 0x3508 | RW | — | accumulated body-frame torque contribution Y |
| this | 0x350C | RW | — | accumulated body-frame torque contribution Z |
| this | 0x3518 | R | — | engine torque direction magnitude |
| this | 0x3528 | R | — | engine torque coefficient A |
| this | 0x352C | R | — | engine torque coefficient B |
| this | 0x3530 | R | — | engine torque coefficient C |
| this | 0x3534 | RW | — | local-frame angular velocity X |
| this | 0x3538 | RW | — | local-frame angular velocity Y |
| this | 0x353C | RW | — | local-frame angular velocity Z |
| this | 0x3540 | RW | — | transformed vector X |
| this | 0x3544 | RW | — | transformed vector Y |
| this | 0x3548 | RW | — | transformed vector Z |
| this | 0x354C | R | — | engine direction vector component X |
| this | 0x3550 | R | — | engine direction vector component Y |
| this | 0x3554 | R | — | engine direction vector component Z |
| this | 0x3558 | R | — | engine torque factor D |
| this | 0x355C | R | — | engine torque factor E |
| this | 0x3560 | R | — | engine torque factor F |
| this | 0x3564 | R | — | engine torque factor G |
| this | 0x3568 | R | — | engine torque factor H |
| this | 0x356C | R | — | engine torque factor I |
| this | 0x3570 | R | — | suspension interpolation/blend factor |
| this | 0x35B0 | R | — | per-wheel data array base (4 wheels, 62 bytes each) |
| this | 0x36A8 | R | — | suspension value A (front or rear pair) |
| this | 0x37A0 | R | — | suspension value B (front or rear pair) |
| this | 0x3898 | R | — | suspension value C |
| this | 0x3964 | RW | — | averaged suspension position |
| this | 0x3978 | R | — | computed suspension force / ride-height force |
| this | 0x398C | R | — | damper condition threshold |
| this | 0x3990 | R | — | damper coefficient (body-frame force multiplier) |
| this | 0x3994 | RW | 0 | damper target value |
| this | 0x3998 | R | — | damper state (current force/position) |
| this | 0x399C | R | — | damper upper clamp limit |
| this | 0x39A0 | R | — | damper lower clamp limit |
| this | 0x39B4 | R | — | damper rate coefficient |
| this | 0x39C8 | R | — | suspension mode selector (0=both-pairs-avg, 1=pair-A, 2=pair-B) |
| this | 0x39EC | R | — | spring rate (stiffness) |
| this | 0x39F0 | R | — | damper mode B enabled flag |

**Written-by note (persistence):**
- this 0x34D4: recalc every frame — external poke does NOT persist
- this 0x34D8: recalc every frame — external poke does NOT persist
- this 0x34DC: recalc every frame — external poke does NOT persist
- this 0x34EC: recalc every frame — external poke does NOT persist
- this 0x34F0: recalc every frame — external poke does NOT persist
- this 0x34F4: recalc every frame — external poke does NOT persist
- this 0x34F8: recalc every frame — external poke does NOT persist
- this 0x34FC: recalc every frame — external poke does NOT persist
- this 0x3500: recalc every frame — external poke does NOT persist
- this 0x3504: recalc every frame — external poke does NOT persist
- this 0x3508: recalc every frame — external poke does NOT persist
- this 0x350C: recalc every frame — external poke does NOT persist
- this 0x3534: recalc every frame — external poke does NOT persist
- this 0x3538: recalc every frame — external poke does NOT persist
- this 0x353C: recalc every frame — external poke does NOT persist
- this 0x3540: recalc every frame — external poke does NOT persist
- this 0x3544: recalc every frame — external poke does NOT persist
- this 0x3548: recalc every frame — external poke does NOT persist
- this 0x3964: recalc every frame — external poke does NOT persist
- this 0x3994: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e7f8 | flt_59E7F8 | R | AntiRollMixingFactor [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004e43d0 | sub_4E43D0 | per-wheel physics processing (called 4 times, once per wheel) |
| 00567120 | sub_567120 | vector/matrix operation (likely cross product or matrix-vector multiply) |

**Guard conditions:** Suspension mode (this+0x39C8 / field 14772): 0 → average all four suspension values (pairs A+B); 1 → average suspension pair A only; 2 → use suspension pair B only. Damper threshold (this+0x398C): if ≤0 → clamp damper state to zero when negative; if >0 → three sub-paths based on damper mode (this+0x39F4): mode 0 integrates damper with coefficient, mode 1 uses interpolation with flag check from this+0x39F0, mode 2 sets damper directly. Damper clamped between lower (this+0x39A0) and upper (this+0x399C) limits.
