## ServerOpenTrackSignal_00460e90 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ConditionalStateDispatch (00463760), SessionScoringUpdate (004643c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1B774) | 0x4 | RW | — | [LLM] |
| this | 0x29 | RW | 1 | [LLM] |
| this | 0x3FB8 | R | — | [LLM] |
| this | 0x1B770 | RW | — | [LLM] |
| this | 0x1B774 | RW | — | [LLM] |
| this | 0x1B778 | RW | — | [LLM] |
| this | 0x1B77C | RW | — | [LLM] |

**Written-by note (persistence):**
- *(this+0x1B774) 0x4: [LLM: once/conditional? does external poke survive?]
- this 0x29: [LLM: once/conditional? does external poke survive?]
- this 0x1B770: [LLM: once/conditional? does external poke survive?]
- this 0x1B774: [LLM: once/conditional? does external poke survive?]
- this 0x1B778: [LLM: once/conditional? does external poke survive?]
- this 0x1B77C: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c5ce4 | aDDevF119992002_1 | R | SourceDevPathStr [DERIVED] |
| 005c60e8 | aOpening | R | OpeningString [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 007c569c | dword_7C569C | R | SessionType5 (5=server) [DERIVED] (also: ` — SessionType5 (guards dev logging) |
| 007d0398 | dword_7D0398 | R | PhotoFreeCameraFlag [DERIVED] (also: � photo/free camera mode flag) |
| 008ac368 | unk_8AC368 | R | VehicleSetupBase [DERIVED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b33b0 | ProgressBarEventEncode | [LLM] |
| 004c5920 | TrackNameReader | [LLM] |
| 004d7a50 | StringSplitLoop | [LLM] |
| 004d7aa0 | DebugLogWrite | [LLM] |
| 005665b0 | sub_5665B0 | [LLM] |
| 00566650 | StringCopyWithBufferRealloc | [LLM] |
| 0057a680 | COMVTableCallVia0x60 | [LLM] |
| 0057a690 | VirtualMethodDispatch | [LLM] |
| 0057a6a0 | NetworkSendDispatch | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
