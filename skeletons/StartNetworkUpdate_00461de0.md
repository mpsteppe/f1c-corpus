## StartNetworkUpdate_00461de0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** StateResetAndConditionalInit (00475530)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x1B79C | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c5ce4 | aDDevF119992002_1 | R | SourceDevPathStr [DERIVED] |
| 005c616c | aStartingIntern | R | StartingInternalString [DERIVED] |
| 005c6194 | aStartingLanUpd | R | StartingLanUpdString [DERIVED] |
| 007c569c | dword_7C569C | R | SessionType5 (5=server) [DERIVED] (also: ` — SessionType5 (guards dev logging) |
| 007d0e74 | dword_7D0E74 | R | NetworkType [DERIVED] (also: ` — network type (0=LAN, 1=Internet) |
| 007d0fe8 | word_7D0FE8 | R | SessionPortBase [DERIVED] (also: Global state (used via uint cast) |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d7a50 | StringSplitLoop | [LLM] |
| 004d7aa0 | DebugLogWrite | [LLM] |
| 00562c80 | InitWrapper | [LLM] |
| 00563020 | MultiStageInitializationChainWithErrorChecking | [LLM] |
| 00563df0 | SetFlagIfPointerNonNull | [LLM] |
| 00563e00 | DirectDrawDisplayModeInit | [LLM] |
| 00563e70 | sub_563E70 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
