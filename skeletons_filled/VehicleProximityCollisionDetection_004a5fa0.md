## VehicleProximityCollisionDetection_004a5fa0 — Proximity collision detection and response

**Summary:** Checks if vehicle is within proximity collision range of another object, evaluates direction/velocity for collision response, and triggers collision state notification. Part of vehicle physics/tick system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** PitStateUpdateMachine (004a6e50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x32C8 | R | — | Collision active flag (0 = not in collision, allows notification) |
| obj | 0x34C4 | R | — | Vehicle relative velocity X component |
| obj | 0x34D0 | R | — | Vehicle relative velocity Y component |
| obj | 0x34DC | R | — | Vehicle relative velocity Z component |
| obj | 0x34F8 | R | — | Wheel/tire slip velocity X |
| obj | 0x34FC | R | — | Wheel/tire slip velocity Y |
| obj | 0x3500 | R | — | Wheel/tire slip velocity Z |
| obj | 0x48A4 | R | — | Array index for target object lookup via ArrayOfStructIndexedFieldCopy |
| this | 0x0 | R | — | this pointer (self-reference for SessionCleanupFlagClear, StateChangeNotify) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e46c | flt_59E46C | R | TireSlipOffset [DERIVED] (also: ` — offset value) |
| 0059e8a0 | flt_59E8A0 | R | InvSqrtThreshold [DERIVED] (also: ` — proximity distance² threshold) |
| 0059e8a4 | flt_59E8A4 | R | ReverseGearThrottleMult [DERIVED] (also: ` â€” reverse gear throttle multiplier) |
| 0059e908 | flt_59E908 | R | CollisionEventThreshold [DERIVED] (also: ` — collision time threshold) |
| 0059f11c | flt_59F11C | R | ContactNormalDotThreshold [DERIVED] |
| 005acb50 | flt_5ACB50 | R | Flt_AiCornerSpeedGain_CB50 [DERIVED] (also: ` — alternate velocity threshold) |
| 005ea2c0 | dword_5EA2C0 | R | SetupScenePtr [DERIVED] |
| 007ce7a8 | dword_7CE7A8 | R | BrakeDiffBlock [DERIVED] (also: ` — BrakeDiffSettings byte (docs/12) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00403f70 | ArrayOfStructIndexedFieldCopy | Copy target object transform data from indexed array |
| 0042adb0 | SessionCleanupFlagClear | Clear session cleanup flags on backward collision path |
| 004a5c80 | StateChangeNotify | Notify state machine of collision state (state ID 4) |
| 004efb20 | F_3DTransformWithMatrixMultiplication | Transform vehicle position to world space |
| 00566e40 | EulerToRotationMatrix | Convert euler angles to rotation matrix for directional checks |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| obj | 0x32C8 | == | 0 | Collision active flag (0 = not active) |

**Guard interpretation:** When obj+0x32C8 == 0 (collision not active), PASSES — StateChangeNotify is called to set collision state 4. When obj+0x32C8 != 0 (already in collision), BLOCKED — StateChangeNotify is skipped.
