## CarSelectionStateMachine_00434460 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_40DE60 (0040de60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xC) | 0xC | R | — | [LLM] |
| *(this+0xC) | 0x10 | R | — | [LLM] |
| *(this+0xC) | 0x14 | R | — | [LLM] |
| *(this+0xC) | 0x18 | R | — | [LLM] |
| *(this+0xC) | 0x1C | R | — | [LLM] |
| *(this+0xC) | 0x20 | R | — | [LLM] |
| *(this+0xC) | 0x48 | R | — | [LLM] |
| *(this+0xC) | 0xB0 | R | — | [LLM] |
| *(this+0xC) | 0xBC | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x4 | RW | 4 | [LLM] |
| this | 0xC | R | — | [LLM] |
| this | 0x18 | RW | — | [LLM] |
| this | 0x1C | RW | — | [LLM] |
| this | 0x24 | RW | — | [LLM] |
| this | 0x28 | RW | — | [LLM] |
| this | 0x2C | RW | 1 | [LLM] |
| this | 0x34 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x4: [LLM: once/conditional? does external poke survive?]
- this 0x18: [LLM: once/conditional? does external poke survive?]
- this 0x1C: [LLM: once/conditional? does external poke survive?]
- this 0x24: [LLM: once/conditional? does external poke survive?]
- this 0x28: [LLM: once/conditional? does external poke survive?]
- this 0x2C: [LLM: once/conditional? does external poke survive?]
- this 0x34: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e65c | flt_59E65C | R | CameraShakeMultiplier [DERIVED] (also: ` — camera shake multiplier / conversion factor (docs/09, 19) |
| 005c329c | dword_5C329C | R | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 005ea510 | dword_5EA510 | R | SessionManager [DERIVED] |
| 005ea535 | byte_5EA535 | W | byte_5EA535 [DERIVED] |
| 005ea538 | dword_5EA538 | W | FileInitCounter [DERIVED] |
| 005ea618 | flt_5EA618 | R | PointerTableEntry [DERIVED] |
| 005eb978 | dword_5EB978 | R | GameStatePtrArray3 [DERIVED] |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |
| 008ad298 | dword_8AD298 | R | SessionModeIdentifier [DERIVED] |
| 008afe98 | dbl_8AFE98 | R | ScoringDefaultReturn [DERIVED] (also: ` — default return value (float) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040c910 | ShortComputation_c910 | [LLM] |
| 00418b90 | ScoreThresholdGateCheck | [LLM] |
| 0041c0f0 | PitExit | [LLM] |
| 00434820 | ModuleInitializationWithFallback | [LLM] |
| 00434d60 | SteeringInterpolationCameraFollow | [LLM] |
| 00435240 | StateFlagCheck_5240 | [LLM] |
| 00456060 | DualFieldGetter | [LLM] |
| 00456080 | ShortComputation_6080 | [LLM] |
| 004582a0 | StridedArrayElementPointer | [LLM] |
| 004d8760 | sub_4D8760 | [LLM] |
| 004d88b0 | IteratorCheck | [LLM] |
| 00541cd0 | UtilityFunction_1cd0 | [LLM] |
| 00542050 | sub_542050 | [LLM] |
| 005423c0 | TwoFieldSetterCall | [LLM] |
| 00542680 | ConditionalFloatSetter | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | == | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
