## VehicleProximityCollisionDetection_004a5fa0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** PitStateUpdateMachine (004a6e50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x32C8 | R | — | [LLM] |
| obj | 0x34C4 | R | — | [LLM] |
| obj | 0x34D0 | R | — | [LLM] |
| obj | 0x34DC | R | — | [LLM] |
| obj | 0x34F8 | R | — | [LLM] |
| obj | 0x34FC | R | — | [LLM] |
| obj | 0x3500 | R | — | [LLM] |
| obj | 0x48A4 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |

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
| 00403f70 | ArrayOfStructIndexedFieldCopy | [LLM] |
| 0042adb0 | SessionCleanupFlagClear | [LLM] |
| 004a5c80 | StateChangeNotify | [LLM] |
| 004efb20 | F_3DTransformWithMatrixMultiplication | [LLM] |
| 00566e40 | EulerToRotationMatrix | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| obj | 0x32C8 | == | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
