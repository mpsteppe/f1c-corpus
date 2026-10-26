## SteeringInterpolationCameraFollow_00434d60 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CarSelectionStateMachine (00434460), sub_4348B0 (004348b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0xC)+0x0) | 0x18 | R | — | [LLM] |
| *(this+0xC) | 0x0 | R | — | [LLM] |
| *(this+0xC) | 0x38 | RW | — | [LLM] |
| *(this+0xC) | 0x3C | RW | — | [LLM] |
| *(this+0xC) | 0xA8 | RW | 0 | [LLM] |
| *(this+0xC) | 0xB0 | R | — | [LLM] |
| *(this+0xC) | 0xBC | R | — | [LLM] |
| this | 0x1 | RW | 0 | [LLM] |
| this | 0x4 | R | — | [LLM] |
| this | 0xC | R | — | [LLM] |
| this | 0x10 | R | — | [LLM] |
| this | 0x14 | R | — | [LLM] |
| this | 0x18 | R | — | [LLM] |
| this | 0x1C | R | — | [LLM] |
| this | 0x2C | R | — | [LLM] |
| this | 0x30 | R | — | [LLM] |

**Written-by note (persistence):**
- *(this+0xC) 0x38: [LLM: once/conditional? does external poke survive?]
- *(this+0xC) 0x3C: [LLM: once/conditional? does external poke survive?]
- *(this+0xC) 0xA8: [LLM: once/conditional? does external poke survive?]
- this 0x1: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e7ec | flt_59E7EC | R | ZeroConstant [DERIVED] (also: ` — compared constant (5.0f encoded indirectly) |
| 0059e8a4 | flt_59E8A4 | R | ReverseGearThrottleMult [DERIVED] (also: ` â€” reverse gear throttle multiplier) |
| 0059e8ec | flt_59E8EC | R | SpeedDeadzone [DERIVED] |
| 005c329c | dword_5C329C | R | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 005ea2c0 | dword_5EA2C0 | R | SetupScenePtr [DERIVED] |
| 005eb978 | dword_5EB978 | R | GameStatePtrArray3 [DERIVED] |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |
| 008afe90 | dbl_8AFE90 | R | EngineCoolingRate [DERIVED] (also: ` — cooling rate per frame) |
| 008afe98 | dbl_8AFE98 | R | ScoringDefaultReturn [DERIVED] (also: ` — default return value (float) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00403cd0 | sub_403CD0 | [LLM] |
| 00456060 | DualFieldGetter | [LLM] |
| 004582a0 | StridedArrayElementPointer | [LLM] |
| 004582c0 | GuardedFunctionWithFlagSet | [LLM] |
| 004e1fd0 | F_3DTransformPointByMatrixAndTranslation | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x4 | == | 5 | [LLM] |
| this | 0x18 | < | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
