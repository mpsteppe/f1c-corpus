## LoadingPhase1_004b87c0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4B9890 (004b9890)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x734 | RW | — | [LLM] |
| this | 0x93C | RW | — | [LLM] |
| this | 0xF30 | R | — | [LLM] |
| this | 0xF34 | R | — | [LLM] |
| this | 0xF40 | RW | — | [LLM] |
| this | 0xF80 | RW | 1 | [LLM] |
| this | 0xF81 | RW | 1 | [LLM] |

**Written-by note (persistence):**
- this 0x734: [LLM: once/conditional? does external poke survive?]
- this 0x93C: [LLM: once/conditional? does external poke survive?]
- this 0xF40: [LLM: once/conditional? does external poke survive?]
- this 0xF80: [LLM: once/conditional? does external poke survive?]
- this 0xF81: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 005acd1c | flt_5ACD1C | R | AIFollowDistThreshold [DERIVED] |
| 005c329c | dword_5C329C | R | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 005ea4e8 | flt_5EA4E8 | R | RandomOffsetFlag [DERIVED] |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |
| 008ad298 | dword_8AD298 | R | SessionModeIdentifier [DERIVED] |
| 008afe90 | dbl_8AFE90 | R | EngineCoolingRate [DERIVED] (also: ` — cooling rate per frame) |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00408420 | ReciprocalWithSignCheck | [LLM] |
| 004b7a00 | QueuePop | [LLM] |
| 004b86e0 | AngleClampWrap | [LLM] |
| 004b8ae0 | StateTriggerCheck | [LLM] |
| 004d8840 | ConditionalIndexSetter | [LLM] |
| 004e1970 | EffectDataTableInitialization | [LLM] |
| 004e3a50 | MultiObjectRemove | [LLM] |
| 004ef5a0 | SessionStateTransition | [LLM] |
| 00566e20 | ResourceLookupDispatcher | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
