## PhysicsCollisionDamageDNFDetection_00438690 — Collision Damage Accumulator with DNF Detection

**Summary:** Per-frame collision damage computation: accumulates impact energy into a damage integrator (scaled by velocity and contact normal), computes temperature-based thermal damage component, checks if accumulated damage exceeds threshold, and when overflow/peak is detected marks the first non-DNF vehicle as DNF (sets state to 5).

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehiclePhysicsIntegrationStep (00441650)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xBC | R | — | impact force magnitude (absolute value at 188) |
| this | 0xCC | R | — | position base offset (for output transform) |
| this | 0xD4 | RW | — | output position (written: damage_scale * accumulator + base) |
| this | 0x15C | R | — | pointer to sub-object (offset +188 used as copy source) |
| this | 0x3D4 | R | — | force scale factor (multiplies impact force to get base damage) |
| this | 0x3E4 | RW | 0 | cosine-modulated damage component (cos(angle_diff * freq) * 0.25 + 0.75) * threshold |
| this | 0x3E8 | RW | 0 | secondary damage accumulator (zeroed on DNF) |
| this | 0x3EC | R | — | damage threshold constant (reference for cosine modulation) |
| this | 0x3F4 | R | — | angle threshold for partial damage response (if temp_diff <= this, use cosine path) |
| this | 0x3FC | R | — | frequency/scale factor for cosine modulation |
| this | 0x404 | RW | — | thermal damage integrator (accumulated temperature * velocity damage) |
| this | 0x40C | R | — | previous/reference temperature value |
| this | 0x414 | R | — | velocity-to-damage scale factor |
| this | 0x41C | R | — | damage base offset (added to contact-normal damage term) |
| this | 0x424 | R | — | contact normal damage scale |
| this | 0x42C | RW | 0 | main damage accumulator (impact energy, integrated over time) |
| this | 0x430 | RW | 0 | secondary damage word (high 32 bits or companion, zeroed on DNF) |
| this | 0x434 | R | — | position output scale factor |
| this | 0x43C | R | — | cubic velocity damage coefficient (multiplies temperature^3 * force_scale * dt) |
| this | 0x444 | R | — | damage upper threshold (comparison limit for accumulator) |

**Written-by note (persistence):**
- this 0xD4: recalc every frame — external poke does NOT persist
- this 0x3E4: recalc every frame — external poke does NOT persist
- this 0x3E8: recalc every frame — external poke does NOT persist
- this 0x404: recalc every frame — external poke does NOT persist
- this 0x42C: recalc every frame — external poke does NOT persist
- this 0x430: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |
| 0059e880 | dbl_59E880 | R | HalfStep [DERIVED] (also: ` — lower threshold constant) |
| 0059ea60 | dbl_59EA60 | R | DampingFactorB [DERIVED] (also: ` — angular threshold for partial response) |
| 0059eac8 | dbl_59EAC8 | R | ThermalTempOffset [DERIVED] (also: ` = 273.15 (C→K) |
| 0059eb50 | dbl_59EB50 | R | InputScaleFactor [DERIVED] |
| 005c329c | dword_5C329C | R | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 005eb978 | dword_5EB978 | R | GameStatePtrArray3 [DERIVED] |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |
| 008afef0 | flt_8AFEF0 | R | TemperatureOffset [CONFIRMED] (also: GlobalForceReference, ` — global force/torque reference) |
| 008afef4 | flt_8AFEF4 | R | Flt_PhysicsBrakeBalance [CONFIRMED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0041b200 | DisplayMessage0x4a | display HUD message (called when half-damage threshold crossed) |
| 004388d0 | Mat3x3MulVec | multiply 3×3 matrix by vector (transform contact normal to local space) |
| 005697a0 | StructCopyWithReciprocalDivision | copy struct and compute reciprocal 1/value for position output |

**Guard conditions:** The function has two key branches:
1. **Damage threshold comparison** (this+0x42C <= this+0x444): when accumulator is below the upper threshold, compute simple ratio v5/threshold (normal operation, PASSES). When above threshold (BLOCKED simple path), enters the full damage path with cubic velocity term, accumulator update, and DNF check.
2. **Accumulator sign/overflow check** (implied by `if (v8 | v9)` after the subtraction/update): when the updated accumulator stays positive (v8|v9 = 0, zero/positive flags), enters the thermal cosine-modulation path. When it goes negative or overflows (PASSES overflow branch), zeros the accumulators, iterates all vehicles to find the first non-DNF vehicle, and sets its state to 5 (DNF).
3. **Temperature difference check** (temp_diff <= this+0x3F4): when small angle difference, applies cosine-modulated partial damage. When larger, checks half-damage threshold and displays a message.
