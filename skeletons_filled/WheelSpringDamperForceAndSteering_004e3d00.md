## WheelSpringDamperForceAndSteering_004e3d00 — Wheel Spring-Damper Force and Steering Torque Computation

**Summary:** Computes per-frame spring/damper forces and steering torques for a single wheel using suspension geometry. Applies a suspension model with bump/rebound damping, contact patch displacement tracking, and outputs force components along the wheel's local axes.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** WheelForceCalculationSpringDamperTorque (004e5470)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | wheel world position X (contact patch reference) |
| this | 0x8 | R | — | wheel world position Y (contact patch reference) |
| this | 0x18 | R | — | spring/body force X component (lateral) |
| this | 0x1C | R | — | spring/body force Y component (vertical) |
| this | 0x20 | R | — | spring/body force Z component (longitudinal) |
| this | 0x30 | R | — | damper compression velocity |
| this | 0x38 | R | — | suspension geometry axis X (sin of steer/lean angle) |
| this | 0x3C | R | — | suspension compression ratio (cos φ, threshold 0.985 for near-vertical) |
| this | 0x40 | R | — | suspension geometry axis Z |
| this | 0x44 | R | — | damper displacement (current compression) |
| this | 0x48 | RW | — | spring stiffness (set to 5.0 each frame) |
| this | 0x4C | RW | — | spring force magnitude (computed each frame) |
| this | 0x50 | RW | — | force-applied flag (set to 1.0 when force active) |
| this | 0x54 | RW | — | accumulated longitudinal displacement (integrated per frame) |
| this | 0x58 | RW | — | accumulated lateral displacement (friction-based, updated per frame) |
| this | 0x6C | R | — | damper coefficient (bump/rebound tuning parameter) |
| this | 0x70 | R | — | damper rate factor (combined with coeff for force calc) |
| this | 0x90 | R | — | inverse mass or inertia factor (1/m scaling for acceleration) |
| this | 0x94 | R | — | damper-to-force scaling factor |
| this | 0x9C | R | — | spring rate (stiffness coefficient) |
| this | 0xA8 | R | — | bump damping coefficient (velocity-dependent damping) |
| this | 0xAC | R | — | maximum damper travel limit (clamp for displacement) |
| this | 0xB8 | R | — | friction/stiction factor (couples lateral to longitudinal force) |
| this | 0xBC | R | — | suspension type flag: 1.0 = simple axis-aligned steer, else 3D-rotated steer axis |
| this | 0xC0 | R | — | steer axis rotation sin component (couples to geometry) |
| this | 0xC4 | RW | — | wheel contact patch position X (updated from world pos each frame) |
| this | 0xC8 | RW | — | wheel contact patch position Y (updated from world pos each frame) |
| this | 0xD8 | RW | — | output force X (wheel-local longitudinal/lateral, computed) |
| this | 0xDC | RW | — | output force Y (wheel-local vertical, computed) |
| this | 0xE0 | RW | — | output force Z (wheel-local longitudinal/lateral, computed) |

**Written-by note (persistence):**
- this 0x48: recalc every frame — external poke does NOT persist
- this 0x4C: recalc every frame — external poke does NOT persist
- this 0x50: recalc every frame — external poke does NOT persist
- this 0x54: recalc every frame — external poke does NOT persist
- this 0x58: recalc every frame — external poke does NOT persist
- this 0xC4: recalc every frame — external poke does NOT persist
- this 0xC8: recalc every frame — external poke does NOT persist
- this 0xD8: recalc every frame — external poke does NOT persist
- this 0xDC: recalc every frame — external poke does NOT persist
- this 0xE0: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e7f8 | flt_59E7F8 | R | AntiRollMixingFactor [DERIVED] |
| 0059e7fc | flt_59E7FC | R | BumpDampingConstant [DERIVED] (also: ` — bump damping constants) |
| 005ad148 | flt_5AD148 | R | ContactProximityThreshold [DERIVED] |
| 005ad168 | flt_5AD168 | R | DWLimitThreshold [DERIVED] (also: ` — suspension type threshold (double-wishbone limit) |
| 005ad16c | flt_5AD16C | R | TrackCamberFactor1 [DERIVED] |
| 005ad170 | flt_5AD170 | R | PhysicsCamberFactor [DERIVED] (also: ` — track/camber factors) |
| 005ad178 | dbl_5AD178 | R | CasterAngleThreshold [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0xBC | == | 1065353216 → 1.0f | suspension type: 1.0=simple steer axis (identity rotation), else rotated axis |

**Guard interpretation:** When this[47] (offset 0xBC) == 1.0f, the suspension steer axis is aligned with the body axes — a simplified path uses identity transforms (force components pass through directly). When NOT 1.0f, the full 3D-rotated steer axis is used: forces are projected via the suspension geometry quaternion (this[14], this[15], this[16], this[48]) using cross-product axis construction. Both paths converge to the same output: steering torque and spring/damper force components written to this[54-56] (offsets 0xD8-0xE0). The function also checks `this[15] <= 0.985` to decide whether to use the full quaternion-based axis construction or an orthogonalized fallback when the suspension is near-vertical.
