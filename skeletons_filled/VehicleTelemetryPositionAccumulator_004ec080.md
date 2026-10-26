## VehicleTelemetryPositionAccumulator_004ec080 — position accumulator with velocity integration

**Summary:** Accumulates velocity-scaled deltas into position, transforms by rotation matrix, dispatches to rigid-body or pointer-based update depending on mode selector. Part of vehicle telemetry/positioning system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** UICameraModeDispatchWithVehicleDataRead (0040f550), ParticleEffectUpdateDispatch (004eb430), VehicleYawRotationRecoveryController (004f1c40)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x4894 | R | — | game object field accessed via *this pointer dereference |
| this | 0x0 | R | — | postProcessInput [CONFIRMED] — pointer to game object |
| this | 0x32BC | R | — | update mode selector (0=rigid body, 2=pointer-based) |
| this | 0x34D4 | RW | — | accumulated position X |
| this | 0x34D8 | RW | — | accumulated position Y |
| this | 0x34DC | RW | — | accumulated position Z |

**Written-by note (persistence):**
- this 0x34D4: recalc every frame — external poke does NOT persist
- this 0x34D8: recalc every frame — external poke does NOT persist
- this 0x34DC: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007c7428 | dbl_7C7428 | R | RaceTimeElapsed [DERIVED] |
| 007cd25c | dword_7CD25C | R | GameModuleManager [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0043e6a0 | RigidBodyTransformUpdate | updates rigid body transform with velocity accumulation |
| 00463dc0 | ConditionalStridePointerComputation | resolves stride-based pointer for update target |
| 004b2310 | sub_4B2310 | applies accumulated position delta to target pointer |
| 004b2420 | ArithmeticComparison_2420 | reads initial position values from target pointer |
| 004e16c0 | FieldReadDelegate | reads field value at this+1764 offset |
| 004e23d0 | F_3x3MatrixTransform | transforms position by 3x3 rotation matrix |

**Guard conditions:** this[3247] (0x32BC) == 0 → rigid body update path. == 2 → pointer-based stride update path. All other values → skip (return).
