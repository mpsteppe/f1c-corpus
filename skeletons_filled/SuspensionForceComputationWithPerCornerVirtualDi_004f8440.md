## SuspensionForceComputationWithPerCornerVirtualDi_004f8440 — Suspension Force Per-Corner Virtual Dispatch

**Summary:** Computes suspension forces for each corner of the vehicle by transforming body-space positions through a 3x3 rotation matrix, applying parametric interpolation blending for brake/steering force feedback, and dispatching to per-corner virtual function handlers. Iterates over 40 corner slots (i=5..44) calling setup-specific force computation.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** RenderTickUpdate (004c8b70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x48BC | R | — | vehicle physics state flags (bit 2 = suspension force computation enabled) |
| this | 0x0 | R | — | pointer to vehicle physics object |
| this | 0x8 | R | — | body-space position X (from 3x3 rotation matrix column 1) |
| this | 0xC | R | — | body-space position Y (from 3x3 rotation matrix column 1) |
| this | 0x10 | R | — | body-space position Z (from 3x3 rotation matrix column 1) |
| this | 0x14 | R | — | body-space position X (from 3x3 rotation matrix column 2) |
| this | 0x18 | R | — | body-space position Y (from 3x3 rotation matrix column 2) |
| this | 0x1C | R | — | body-space position Z (from 3x3 rotation matrix column 2) |
| this | 0x20 | R | — | body-space position X (from 3x3 rotation matrix column 3) |
| this | 0x24 | R | — | body-space position Y (from 3x3 rotation matrix column 3) |
| this | 0x28 | R | — | body-space position Z (from 3x3 rotation matrix column 3) |
| this | 0x2C | R | — | world-space position offset X |
| this | 0x30 | R | — | world-space position offset Y |
| this | 0x34 | R | — | world-space position offset Z |
| this | 0x38 | R | — | world-space position offset X (duplicate/secondary) |
| this | 0x3C | R | — | world-space position offset Y (duplicate/secondary) |
| this | 0x40 | R | — | world-space position offset Z (duplicate/secondary) |
| this | 0x84 | R | — | brake/throttle input value |
| this | 0x88 | R | — | steering input value |
| this | 0x8C | R | — | clutch input value |
| this | 0x90 | R | — | handbrake input value |
| this | 0x9C | R | — | brake force feedback multiplier |
| this | 0xA0 | R | — | steering force feedback multiplier |
| this | 0xB0 | R | — | per-corner suspension enable flag byte |
| this | 0x63C | RW | 0 | suspension damping multiplier per-corner (index 44/399) |
| this | 0x6D8 | R | — | per-corner virtual dispatch function table pointer (vtable for force computation) |

**Written-by note (persistence):**
- this 0x63C: conditionally written (only when i==44 and suspension enabled); recalc each call — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 005d6798 | dword_5D6798 | R | BrakeForceConst_5D6798 [DERIVED] |
| 005d679c | dword_5D679C | R | PedalForceCoeff [DERIVED] |
| 005d67a0 | dword_5D67A0 | R | SteeringForceCoeff [DERIVED] |
| 005d67a4 | dword_5D67A4 | R | AeroDownforceConstant [DERIVED] |
| 005d67a8 | dword_5D67A8 | R | Flt_AiBrakeBiasGain_67A8 [DERIVED] |
| 005d67ac | dword_5D67AC | R | FFBParam_5D67AC [DERIVED] |
| 007cf2cc | flt_7CF2CC | R | DSPTransformParam [DERIVED] (also: ` — DSP transform parameter) |
| 007cf2f0 | flt_7CF2F0 | R | BrakeForceMult [DERIVED] |
| 007cf314 | flt_7CF314 | R | SuspensionDampingMultiplier [DERIVED] |
| 007cf338 | flt_7CF338 | R | Flt_ForceFeedbackMult [DERIVED] |
| 007cf35c | flt_7CF35C | R | ForceFeedbackGain [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004c7bd0 | sub_4C7BD0 | checks whether AI/CPU driver is active (returns true if AI controlled) |
| 004f6d90 | ParametricInterpolationBlending | blends suspension parameters based on input and force feedback |
| 004f8850 | PerIndexStructFieldSetter | sets a field at a given index in a per-index struct array |

**Guard conditions:** The outer guard is `((*(this+0x48BC)) & 2) != 0` — suspension force computation only runs when bit 1 of the vehicle state flags is set. The inner loop also checks `*((_BYTE *)v7 + 180)` (per-corner enable flag at offset 0xB4) and whether the virtual dispatch pointer (v6) is non-null.
