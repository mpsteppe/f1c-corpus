## SeasonRacesSceneSorter_004c5940 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SceneFileLoader (004c52c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d31c8 | aSeasonraces | R | ParamKey_SeasonRaces [DERIVED] |
| 008ac488 | dword_8AC488 | R | SceneFileCount [DERIVED] |
| 008ac490 | dword_8AC490 | R | SceneArray (stride 0x18c) [DERIVED] |
| 008ad3b4 | dword_8AD3B4 | R | GameDataDir [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00499e20 | StringPointerAccessor | [LLM] |
| 00567980 | LinkedListCount | [LLM] |
| 005679a0 | NullCheckWrapper | [LLM] |
| 00568210 | AudioChannelStop | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |
| 00588410 | sub_588410 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
