## CameraModeViewportUpdate_00409a00 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x1C)+0x0) | 0x18 | R | — | [LLM] |
| *(*(this+0x1C)+0x0) | 0x1C | R | — | [LLM] |
| *(this+0x1C) | 0x0 | R | — | [LLM] |
| *(this+0x1C) | 0xC | R | — | [LLM] |
| *(this+0x1C) | 0x10 | R | — | [LLM] |
| *(this+0x1C) | 0x14 | R | — | [LLM] |
| *(this+0x1C) | 0x18 | R | — | [LLM] |
| *(this+0x1C) | 0x1C | R | — | [LLM] |
| *(this+0x1C) | 0x20 | R | — | [LLM] |
| *(this+0x1C) | 0x48 | R | — | [LLM] |
| *(this+0x1C) | 0xA0 | RW | — | [LLM] |
| *(this+0x1C) | 0xA4 | RW | — | [LLM] |
| *(this+0x1C) | 0xA8 | RW | — | [LLM] |
| *(this+0x2C) | 0xBC | R | — | [LLM] |
| *(this+0x2C) | 0xC0 | R | — | [LLM] |
| *(this+0x30) | 0xBC | RW | — | [LLM] |
| *(this+0x30) | 0xC0 | RW | — | [LLM] |
| *(this+0x30) | 0xC4 | RW | — | [LLM] |
| *(this+0x4) | 0x1B0 | R | — | [LLM] |
| obj | 0x14 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x4 | R | — | [LLM] |
| this | 0x10 | R | — | [LLM] |
| this | 0x14 | R | — | [LLM] |
| this | 0x18 | R | — | [LLM] |
| this | 0x1C | R | — | [LLM] |
| this | 0x20 | R | — | [LLM] |
| this | 0x24 | R | — | [LLM] |
| this | 0x28 | R | — | [LLM] |
| this | 0x2C | R | — | [LLM] |
| this | 0x30 | R | — | [LLM] |
| this | 0x34 | R | — | [LLM] |
| this | 0x3C | R | — | [LLM] |
| this | 0x40 | R | — | [LLM] |
| this | 0x44 | R | — | [LLM] |
| this | 0x48 | R | — | [LLM] |
| this | 0x4C | R | — | [LLM] |

**Written-by note (persistence):**
- *(this+0x1C) 0xA0: [LLM: once/conditional? does external poke survive?]
- *(this+0x1C) 0xA4: [LLM: once/conditional? does external poke survive?]
- *(this+0x1C) 0xA8: [LLM: once/conditional? does external poke survive?]
- *(this+0x30) 0xBC: [LLM: once/conditional? does external poke survive?]
- *(this+0x30) 0xC0: [LLM: once/conditional? does external poke survive?]
- *(this+0x30) 0xC4: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00409f1c | jpt_409A3C | R | [LLM] |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e65c | flt_59E65C | R | CameraShakeMultiplier [DERIVED] (also: ` — camera shake multiplier / conversion factor (docs/09, 19) |
| 0059e660 | flt_59E660 | R | VehicleBodyDamping [DERIVED] |
| 0059e664 | flt_59E664 | R | RenderTransformScale [DERIVED] |
| 0059e668 | flt_59E668 | R | FloatRead_59E668 [DERIVED] |
| 005be8fc | flt_5BE8FC | R | Unknown_Float_5BE8FC [DERIVED] |
| 005be900 | dword_5BE900 | RW | Int_GameStateSubmode [DERIVED] |
| 007c54e0 | dword_7C54E0 | R | postProcessInput [CONFIRMED] (also: unknown (near PlayerVehiclePtr +0x8)) |
| 007cfe70 | byte_7CFE70 | R | ReconScreenFlag [DERIVED] |
| 008ad298 | dword_8AD298 | R | SessionModeIdentifier [DERIVED] |
| 008afe88 | dword_8AFE88 | R | CollisionGeometryHandle [DERIVED] (also: ` — global collision geometry handle) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004084a0 | ShortComputation_84a0 | [LLM] |
| 0040c780 | ScoringGateConditionCheck | [LLM] |
| 00456060 | DualFieldGetter | [LLM] |
| 00456080 | ShortComputation_6080 | [LLM] |
| 004d8860 | ConditionalBranchByFlag | [LLM] |
| 004e1fd0 | F_3DTransformPointByMatrixAndTranslation | [LLM] |
| 004e2070 | LocalToWorldCoordinateTransform | [LLM] |
| 004e2130 | ChassisWorldTransform | [LLM] |
| 00541cd0 | UtilityFunction_1cd0 | [LLM] |
| 00542050 | sub_542050 | [LLM] |
| 005423c0 | TwoFieldSetterCall | [LLM] |
| 00542680 | ConditionalFloatSetter | [LLM] |
| 0054a160 | FlagBitSetter_a160 | [LLM] |
| 00566e40 | EulerToRotationMatrix | [LLM] |
| 00567340 | RotationMatrixYAxisRotationEulerExtraction | [LLM] |
| 00567400 | RotationMatrixY | [LLM] |
| 005674c0 | RotateMatrixAndExtractAngles | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
