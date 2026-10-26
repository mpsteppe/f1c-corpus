## ConditionalFieldSetter_004bc2f0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** NetCommPlayerSlotSync (0045fc50), sub_462E20 (00462e20), sub_4B3400 (004b3400), AIDriverSorting (004bf390), sub_4BFF70 (004bff70), sub_4C01A0 (004c01a0), sub_4C0850 (004c0850)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | [LLM] |
| this | 0x2C | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x2C: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005eb978 | dword_5EB978 | R | GameStatePtrArray3 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00419120 | AIDriverStateTransition | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
