## Sound_Exit_004c8d00 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GameExit (0042db20)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d3398 | aDDevF119992002_24 | R | DefaultScenePath24 [DERIVED] |
| 005d3424 | aEnteredSoundEx | R | EnteredSoundExString [DERIVED] |
| 005ea618 | flt_5EA618 | R | PointerTableEntry [DERIVED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00411740 | GlobalVTableDispatchWithQuery | [LLM] |
| 00418900 | ShortComputation_8900 | [LLM] |
| 004c8630 | VirtualDispatchStateReset | [LLM] |
| 004d7a50 | StringSplitLoop | [LLM] |
| 004d7aa0 | DebugLogWrite | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
