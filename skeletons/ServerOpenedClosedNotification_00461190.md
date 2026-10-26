## ServerOpenedClosedNotification_00461190 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ConditionalStateDispatch (00463760)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1B774) | 0x4 | RW | — | [LLM] |
| this | 0x29 | RW | 0 | [LLM] |
| this | 0x2C | RW | 18446744072627421184 → -1.0f | [LLM] |
| this | 0x1B770 | RW | — | [LLM] |
| this | 0x1B774 | RW | — | [LLM] |
| this | 0x1B778 | RW | — | [LLM] |
| this | 0x1B77C | R | — | [LLM] |

**Written-by note (persistence):**
- *(this+0x1B774) 0x4: [LLM: once/conditional? does external poke survive?]
- this 0x29: [LLM: once/conditional? does external poke survive?]
- this 0x2C: [LLM: once/conditional? does external poke survive?]
- this 0x1B770: [LLM: once/conditional? does external poke survive?]
- this 0x1B774: [LLM: once/conditional? does external poke survive?]
- this 0x1B778: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059f0b4 | flt_59F0B4 | R | TrackOpenInitialSpeed [DERIVED] (also: ` — initial open flag value) |
| 005c5ce4 | aDDevF119992002_1 | R | SourceDevPathStr [DERIVED] |
| 005c610c | aTheServerSS | R | TheServerFormat [DERIVED] |
| 005c6124 | aClosed | R | ClosedString [DERIVED] |
| 005c612c | aOpened | R | OpenedString [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 007c569c | dword_7C569C | R | SessionType5 (5=server) [DERIVED] (also: ` — SessionType5 (guards dev logging) |
| 007cd204 | dword_7CD204 | R | ResourceDispatch_007CD204 [DERIVED] |
| 007d0398 | dword_7D0398 | R | PhotoFreeCameraFlag [DERIVED] (also: � photo/free camera mode flag) |
| 008ac368 | unk_8AC368 | R | VehicleSetupBase [DERIVED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0045bd10 | TextLineWrappingAndRendering | [LLM] |
| 004c5920 | TrackNameReader | [LLM] |
| 004d7a50 | StringSplitLoop | [LLM] |
| 004d7aa0 | DebugLogWrite | [LLM] |
| 00566650 | StringCopyWithBufferRealloc | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |
| 0058815f | StringFormatWithBufferOverflowCheck | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
