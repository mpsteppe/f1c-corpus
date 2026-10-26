## VehicleYawRotationRecoveryController_004f1c40 — Vehicle Yaw Rotation Recovery Controller

**Summary:** Detects excessive vehicle yaw rotation (spinning/flipping) and triggers recovery by resetting vehicle dynamics state, recomputing orientation from atan2 of direction components, and snapping position to the racing line. Monitors wheel contact states and applies corrective contact forces for partial loss of ground contact.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** MainGameTickUpdate (0042c690)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x48BC | R | — | vehicle control/input flags (bit 3 = control mode enabled, gates recovery logic) |
| this | 0x0 | R | — | postProcessInput [CONFIRMED] |
| this | 0x828 | R | — | wheel contact data array base (4 wheels, 296 bytes each, checked for ground contact) |
| this | 0x868 | R | — | wheel 0 contact active flag byte (offset +64 within first wheel entry; nonzero = wheel touching ground) |
| this | 0x32BC | R | — | vehicle yaw-rotation state counter (<=1 allows recovery; higher values suppress it) |
| this | 0x34B8 | R | — | elapsedTime (alt) [CONFIRMED] |
| this | 0x34C0 | R | — | vehicle forward-axis Z component (used in atan2 for yaw angle computation) |
| this | 0x34D0 | R | — | vehicle forward-axis X component (atan2 denominator for yaw angle computation) |
| this | 0x34D4 | RW | — | cached previous vehicle X position (snapshot for movement delta) |
| this | 0x34D8 | RW | — | cached previous vehicle Y position |
| this | 0x34DC | RW | — | cached previous vehicle Z position |
| this | 0x34E0 | RW | 0 | Euler angle X component (reset to 0 during recovery rotation matrix setup) |
| this | 0x34E4 | RW | — | Euler angle Y component (yaw correction angle from atan2, set during recovery) |
| this | 0x34E8 | RW | 0 | Euler angle Z component (reset to 0 during recovery) |
| this | 0x3668 | R | — | wheel active-state flag array pointer (4 entries, 62-byte stride; zero = wheel lost contact) |
| this | 0x3FF4 | RW | 0 | yaw-rotation recovery timer accumulator (increments by frame delta a2; resets when vehicle upright > cos(45°)) |
| this | 0x4008 | RW | — | current vehicle X position (updated from physics each frame) |
| this | 0x400C | RW | — | current vehicle Y position |
| this | 0x4010 | RW | — | current vehicle Z position |

**Written-by note (persistence):**
- this 0x34D4: recalc every frame — external poke does NOT persist
- this 0x34D8: recalc every frame — external poke does NOT persist
- this 0x34DC: recalc every frame — external poke does NOT persist
- this 0x34E0: recalc every frame — external poke does NOT persist
- this 0x34E4: recalc every frame — external poke does NOT persist
- this 0x34E8: recalc every frame — external poke does NOT persist
- this 0x3FF4: recalc every frame — external poke does NOT persist
- this 0x4008: recalc every frame — external poke does NOT persist
- this 0x400C: recalc every frame — external poke does NOT persist
- this 0x4010: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e478 | flt_59E478 | R | SteeringCenterBoost [DERIVED] |
| 0059e7ec | flt_59E7EC | R | ZeroConstant [DERIVED] (also: ` — compared constant (5.0f encoded indirectly) |
| 0059e84c | flt_59E84C | R | VelocityRateLimit [DERIVED] (also: ` — display message threshold) |
| 0059e8a0 | flt_59E8A0 | R | InvSqrtThreshold [DERIVED] (also: ` — proximity distance² threshold) |
| 005ad1c4 | flt_5AD1C4 | R | CollisionVelocityThreshold [DERIVED] |
| 007c749f | byte_7C749F | R | Byte_PlayerControlFlag [DERIVED] |
| 007c74a3 | byte_7C74A3 | R | VehicleFlagByte_7C74A3 [DERIVED] |
| 007d0af8 | byte_7D0AF8 | R | Byte_DriverFlag [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004ebc60 | VehicleContactForceAccumulation | accumulates contact force impulse for vehicle recovery physics |
| 004ec080 | VehicleTelemetryPositionAccumulator | accumulates telemetry position data from recovery event |
| 004ed420 | VehicleGeometryProximityTest | tests vehicle geometry against track/world for proximity and penetration depth |
| 004ef7c0 | AIVehiclePathPositionTracking | resets AI vehicle path tracking to current position after recovery teleport |
| 004efb20 | F_3DTransformWithMatrixMultiplication | applies 3D transformation using matrix multiply (world-to-local transform) |
| 004f1fe0 | sub_4F1FE0 | follow-up recovery function called with frame delta after main logic |
| 004f2320 | VehicleDynamicsStateReset | full reset of vehicle dynamics/physics state (position, velocity, orientation) |
| 00566e40 | EulerToRotationMatrix | converts Euler angles (XYZ triplet) to 3x3 rotation matrix for recovery orientation |

**Guard conditions:** Outer guard: this+0x32BC (yaw state counter) must be <= 1 AND obj+0x48BC bit 3 (control mode flag) must be set. byte_7D0AF8 must equal 1 (driver/race flag active). Recovery timer logic: if this+0x34B8 >= 0.70710677 (vehicle nearly upright, cos(45°)), timer reset to 0. Otherwise timer accumulates frame delta a2. Timer > 5.0 seconds (or > 3.0s if byte_7C749F or byte_7C74A3 set — player control mode): triggers full reset (VehicleDynamicsStateReset, recompute yaw via atan2, rebuild rotation matrix, transform position, re-track racing line). Wheel contact check: 4 wheels iterated; if any wheel has contact byte set but corresponding active-state flag at this+0x3668 is zero, counted as lost contact (v9). If v9 > 0 or total contacts v10 <= 2: position recovery branch. All contacts new (v9 == v10): full reset with position snap to last known position. Partial loss (v9 > 1): compute movement delta, normalize direction, run VehicleGeometryProximityTest for penetration, apply contact force impulse. If all wheels have old contacts (no loss): snapshot current position as baseline. Always calls sub_4F1FE0 with frame delta at end.
