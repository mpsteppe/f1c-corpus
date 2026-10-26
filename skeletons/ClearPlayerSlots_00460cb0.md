## ClearPlayerSlots_00460cb0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** NetCommPlayerSlotSync (0045fc50), SynchronizeWithServer (00464290), SessionScoringUpdate (004643c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1D4 | RW | 18446744073709551615 | [LLM] |
| this | 0x3C74 | R | — | [LLM] |
| this | 0x3E14 | RW | 0 | [LLM] |
| this | 0x3E18 | RW | 18446744073709551615 | [LLM] |
| this | 0x3FB8 | R | — | [LLM] |
| this | 0x3FC4 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x1D4: [LLM: once/conditional? does external poke survive?]
- this 0x3E14: [LLM: once/conditional? does external poke survive?]
- this 0x3E18: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c5ce4 | aDDevF119992002_1 | R | SourceDevPathStr [DERIVED] |
| 005c6098 | aMarkingSlotDAs | R | MarkingSlotDAsField [DERIVED] |
| 007c569c | dword_7C569C | R | SessionType5 (5=server) [DERIVED] (also: ` — SessionType5 (guards dev logging) |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00461480 | StructFieldZeroInitWithDefaults | [LLM] |
| 004d7a50 | StringSplitLoop | [LLM] |
| 004d7aa0 | DebugLogWrite | [LLM] |
| 0057a800 | UtilityFunction_a800 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x1D4 | != | 18446744073709551615 | [LLM] |
| this | 0x3FC4 | != | 3 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
