## WheelForceCalculationSpringDamperTorque_004e5470 — Per-Wheel Spring/Damper Force and Torque Computation

**Summary:** Computes per-wheel spring/damper forces, tire contact forces, and resulting suspension torques for all 4 wheels using wheel-space coordinate transforms. Core physics tick for suspension force integration.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** PhysicsIntegrationStateMachine (004e4e60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x34B0 | R | — | wheel-space rotation matrix row0 col0 (v3[0]) |
| this | 0x34B4 | R | — | wheel-space rotation matrix row0 col1 (v3[1]) |
| this | 0x34B8 | R | — | elapsedTime (alt) [CONFIRMED] |
| this | 0x34BC | R | — | wheel-space rotation matrix row1 col0 (v3[3]) |
| this | 0x34C0 | R | — | wheel-space rotation matrix row1 col1 (v3[4]); also guard threshold at 0.7f |
| this | 0x34C4 | R | — | wheel-space rotation matrix row1 col2 (v3[5]) |
| this | 0x34C8 | R | — | wheel-space rotation matrix row2 col0 (v3[6]) |
| this | 0x34CC | R | — | wheel-space rotation matrix row2 col1 (v3[7]) |
| this | 0x34D0 | R | — | wheel-space rotation matrix row2 col2 (v3[8]) |
| this | 0x34D4 | R | — | world-space position offset X per wheel (v2[0]) |
| this | 0x34D8 | R | — | world-space position offset Y per wheel (v2[1]) |
| this | 0x34DC | R | — | world-space position offset Z per wheel (v2[2]) |
| this | 0x34F8 | R | — | RenderZ [FACT] |
| this | 0x34FC | R | — | spring attachment cross-term for steer offset (this[3393]) |
| this | 0x3500 | R | — | spring attachment cross-term for steer offset (this[3394]) |
| this | 0x3504 | R | — | spring attachment cross-term for steer offset (this[3395]) |
| this | 0x3508 | R | — | world-space wheel center X (this[3390]) |
| this | 0x350C | R | — | world-space wheel center Y (this[3391]) |
| this | 0x354C | RW | — | per-wheel accumulated suspension force X (output, 4 lanes) |
| this | 0x3550 | RW | — | per-wheel accumulated suspension force Y (output, 4 lanes) |
| this | 0x3554 | RW | — | per-wheel accumulated suspension force Z (output, 4 lanes) |
| this | 0x3558 | RW | — | per-wheel accumulated suspension torque X (output, 4 lanes) |
| this | 0x355C | RW | — | per-wheel accumulated suspension torque Y (output, 4 lanes) |
| this | 0x3560 | RW | — | per-wheel accumulated suspension torque Z (output, 4 lanes) |
| this | 0x3574 | R | — | steering angle input (this[3421], used for sin/cos) |
| this | 0x3588 | RW | — | per-wheel suspension travel / contact force workspace (v4 start, 4 lanes) |
| this | 0x358C | R | — | suspension damping coefficient per wheel (v4[1]) |
| this | 0x3594 | R | — | steering torque contribution per wheel (v4[3]) |
| this | 0x3598 | RW | — | per-wheel tire contact normal force |
| this | 0x359C | RW | — | per-wheel tire contact lateral force |
| this | 0x35A0 | RW | — | per-wheel tire contact longitudinal force |
| this | 0x35A8 | RW | — | per-wheel steering axis torque |
| this | 0x35B4 | R | — | spring rate constant scalar (this[3429]) |
| this | 0x35C4 | RW | — | smoothed suspension travel for damping (v14 start, 4 lanes) |
| this | 0x35E0 | R | — | anti-roll bar force redistribution source (this[3437]) |
| this | 0x35F4 | R | — | anti-roll bar force redistribution target (this[3499]) |
| this | 0x3600 | R | — | anti-roll bar torque scale factor (this[3677]) |
| this | 0x363C | RW | — | tirePuncture_RR [CONFIRMED] |
| this | 0x3640 | RW | — | tire burst/damage accumulation RR |
| this | 0x36A0 | RW | — | tire temperature RR |
| this | 0x36AC | R | — | tire wear level RR |
| this | 0x36BC | RW | — | tire grip coefficient RR |
| this | 0x3734 | RW | — | tirePuncture_RL [CONFIRMED] |
| this | 0x3738 | RW | — | tire burst/damage accumulation RL |
| this | 0x37A4 | R | — | tire temperature RL |
| this | 0x37B4 | RW | — | tire grip coefficient RL |
| this | 0x389C | R | — | tire wear level RL |
| this | 0x38AC | RW | — | secondary tire grip RL |
| this | 0x3960 | R | — | tire pressure FR |
| this | 0x3974 | R | — | FR wheel rotation rate |

**Written-by note (persistence):**
- this 0x354C: recalc every frame — external poke does NOT persist
- this 0x3550: recalc every frame — external poke does NOT persist
- this 0x3554: recalc every frame — external poke does NOT persist
- this 0x3558: recalc every frame — external poke does NOT persist
- this 0x355C: recalc every frame — external poke does NOT persist
- this 0x3560: recalc every frame — external poke does NOT persist
- this 0x3588: recalc every frame — external poke does NOT persist
- this 0x3598: recalc every frame — external poke does NOT persist
- this 0x359C: recalc every frame — external poke does NOT persist
- this 0x35A0: recalc every frame — external poke does NOT persist
- this 0x35A8: recalc every frame — external poke does NOT persist
- this 0x35C4: recalc every frame — external poke does NOT persist
- this 0x363C: recalc every frame — external poke does NOT persist
- this 0x3640: recalc every frame — external poke does NOT persist
- this 0x36A0: recalc every frame — external poke does NOT persist
- this 0x36BC: recalc every frame — external poke does NOT persist
- this 0x3734: recalc every frame — external poke does NOT persist
- this 0x3738: recalc every frame — external poke does NOT persist
- this 0x37B4: recalc every frame — external poke does NOT persist
- this 0x38AC: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e448 | flt_59E448 | R | TileSteppingMultiplier [DERIVED] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e664 | flt_59E664 | R | RenderTransformScale [DERIVED] |
| 0059e6e8 | flt_59E6E8 | R | TireDampingBlendFactor [DERIVED] |
| 0059e8ec | flt_59E8EC | R | SpeedDeadzone [DERIVED] |
| 008b8f24 | dword_8B8F24 | R | D3DDeviceWrapperPtr [DERIVED] (also: ` — D3D device wrapper / scene manager singleton vtable (docs/22) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004e3aa0 | TireContactForceComputation | computes tire-road normal and friction forces at contact patch per wheel |
| 004e3d00 | WheelSpringDamperForceAndSteering | computes spring reaction force, damper force, and steering axis torque per wheel |
| 0053ac70 | EmptyStubWithFlagCheck | debug/profile marker with integer flag check; no functional effect |

**Guard conditions:** `this[3376] > 0.69999999` (offset 0x34C0) — roll ratio / body attitude threshold. PASSES (>0.7): redistributes accumulated roll torque through anti-roll bar (adds differential to front pair, subtracts from rear pair). BLOCKED (≤0.7): skip anti-roll bar redistribution; each wheel pair handles forces independently.
