## LoadingPhase2_004b8940 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4B9890 (004b9890)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x734 | R | — | [LLM] |
| this | 0x93C | R | — | [LLM] |
| this | 0xF40 | RW | 18446744073709551615 | [LLM] |
| this | 0xF80 | RW | 1 | [LLM] |
| this | 0xF81 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0xF40: [LLM: once/conditional? does external poke survive?]
- this 0xF80: [LLM: once/conditional? does external poke survive?]
- this 0xF81: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e8a4 | flt_59E8A4 | R | ReverseGearThrottleMult [DERIVED] (also: ` â€” reverse gear throttle multiplier) |
| 005acd1c | flt_5ACD1C | R | AIFollowDistThreshold [DERIVED] |
| 005c329c | dword_5C329C | R | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 005ea4e8 | flt_5EA4E8 | R | RandomOffsetFlag [DERIVED] |
| 005ea560 | dword_5EA560 | R | GlobalInstance_5EA560 [CONFIRMED] |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |
| 008ac494 | byte_8AC494 | R | SceneArrayFirstSceneName [DERIVED] |
| 008afe90 | dbl_8AFE90 | R | EngineCoolingRate [DERIVED] (also: ` — cooling rate per frame) |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00408450 | SafeDivisionWithZeroGuard | [LLM] |
| 00411120 | SessionStructureCleanup | [LLM] |
| 004b86e0 | AngleClampWrap | [LLM] |
| 004b8ae0 | StateTriggerCheck | [LLM] |
| 004c7aa0 | SetDriverVisibility | [LLM] |
| 004c8dc0 | GuardedVirtualCall | [LLM] |
| 004e0ed0 | AudioSoundEffectController | [LLM] |
| 004e19a0 | UIElementIterateUpdate | [LLM] |
| 004e3a50 | MultiObjectRemove | [LLM] |
| 004ef5a0 | SessionStateTransition | [LLM] |
| 00566db0 | sub_566DB0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
