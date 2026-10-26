## NetCommParseCommandLine_00463160 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GameMainEntry (0045b200)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0xC5 | RW | 1 | [LLM] |
| obj | 0xC6 | RW | 1 | [LLM] |
| obj | 0xC8 | RW | 0 | [LLM] |
| obj | 0x117 | RW | 0 | [LLM] |
| obj | 0x1AC | RW | 2 | [LLM] |
| this | 0x0 | R | — | [LLM] |

**Written-by note (persistence):**
- obj 0xC5: [LLM: once/conditional? does external poke survive?]
- obj 0xC6: [LLM: once/conditional? does external poke survive?]
- obj 0xC8: [LLM: once/conditional? does external poke survive?]
- obj 0x117: [LLM: once/conditional? does external poke survive?]
- obj 0x1AC: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c3280 | aD_1 | R | ConfigParseTokenList [DERIVED] |
| 005c3f6c | byte_5C3F6C | R | ConfigDefaultValue [DERIVED] (also: Lookup/config data) |
| 005c5ce4 | aDDevF119992002_1 | R | SourceDevPathStr [DERIVED] |
| 005c6350 | aMaxplayers | R | MaxPlayersString [DERIVED] |
| 005c6360 | aNetcommSetNetw | R | NetCommSetNetworkField [DERIVED] |
| 005c6384 | aName_1 | R | Field_Name [DERIVED] |
| 005c638c | aNoPortSpecifie | R | String_NoPortSpecified [DERIVED] |
| 005c63c8 | aNewAddressStri | R | NewAddressString [DERIVED] |
| 005c63e8 | aAutojoinAddres | R | AutojoinAddresString [DERIVED] |
| 005c642c | aNetcommActivat_0 | R | NetcommActivateString [DERIVED] |
| 005c644c | aConnect | R | String_Connect [DERIVED] |
| 005c6458 | aSettingGameNam | R | s_DebugSettingGameName [DERIVED] |
| 005c6474 | aGamename | R | GameName [DERIVED] |
| 005c6480 | aNetcommActivat | R | NetcommActivateString [DERIVED] |
| 005c64a0 | aHost | R | HostString [DERIVED] |
| 005c64a8 | aDedicated | R | DedicatedString [DERIVED] |
| 005c64b4 | aSettingGamePas | R | SettingGamePasString [DERIVED] |
| 005c64d4 | asc_5C64D4 | R | String_DefaultFont [DERIVED] |
| 005c64d8 | aPassword | R | Str_Password [DERIVED] |
| 005c64e4 | aNetcommCheckin | R | StringNetCommCheckin [DERIVED] |
| 007c569c | dword_7C569C | R | SessionType5 (5=server) [DERIVED] (also: ` — SessionType5 (guards dev logging) |
| 007d1004 | word_7D1004 | R | Unknown_Word_7D1004 [DERIVED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00463710 | StringCopyToStructField | [LLM] |
| 004d7a50 | StringSplitLoop | [LLM] |
| 004d7aa0 | DebugLogWrite | [LLM] |
| 00566810 | sub_566810 | [LLM] |
| 00587c20 | sub_587C20 | [LLM] |
| 00587dd0 | sub_587DD0 | [LLM] |
| 00587ece | sub_587ECE | [LLM] |
| 0058815f | StringFormatWithBufferOverflowCheck | [LLM] |
| 005897ca | sub_5897CA | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
