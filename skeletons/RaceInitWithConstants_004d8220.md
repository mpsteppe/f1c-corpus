## RaceInitWithConstants_004d8220 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** OnScreen_Init (0049efa0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xE4 | RW | — | [LLM] |
| this | 0xE8 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0xE4: [LLM: once/conditional? does external poke survive?]
- this 0xE8: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005acf38 | flt_5ACF38 | R | GBChannelScaleFactor [DERIVED] |
| 005acf3c | flt_5ACF3C | R | Renderer_SceneScaleFactor [DERIVED] |
| 005d6d60 | dword_5D6D60 | R | ScreenWidth [DERIVED] |
| 005d6d64 | dword_5D6D64 | R | ScreenWidth [DERIVED] (also: input device parameters) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d8720 | UtilityFunction_8720 | [LLM] |
| 004d8760 | sub_4D8760 | [LLM] |
| 004d88d0 | sub_4D88D0 | [LLM] |
| 004d8ab0 | sub_4D8AB0 | [LLM] |
| 004d8cf0 | sub_4D8CF0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
