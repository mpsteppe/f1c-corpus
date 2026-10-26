## PhysicsTireSystemConstructor_004e4500 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** RaceStructInit (00423e80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x32BC | RW | 18446744073709551615 | [LLM] |
| this | 0x39A4 | RW | 0 | EngineMaxRPM [CONFIRMED] |

**Written-by note (persistence):**
- this 0x32BC: [LLM: once/conditional? does external poke survive?]
- this 0x39A4: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004a48c0 | F_5LoopInitCall | [LLM] |
| 004dfb90 | sub_4DFB90 | [LLM] |
| 004dfbb0 | sub_4DFBB0 | [LLM] |
| 004e4790 | sub_4E4790 | [LLM] |
| 004f2430 | ConstructorZeroInitSubCalls | [LLM] |
| 004f6f20 | sub_4F6F20 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
