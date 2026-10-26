## CUBESceneLoaderEntry_0048e8d0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** StateInitializerWithFlagCheck (00466300)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x40 | R | — | [LLM] |
| this | 0xE0 | R | — | [LLM] |
| this | 0xE8 | R | — | [LLM] |
| this | 0xEC | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0xEC: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005cc220 | aCubeErrorLoadi_1 | R | String_CubeError [DERIVED] |
| 005cc248 | aDDevF119992002_27 | R | Str_DevF119992002_27 [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |
| 008afe64 | dword_8AFE64 | R | RaceTimeDelta [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00496e40 | LinkedListTraversalWithVirtualCall | [LLM] |
| 004d7a50 | StringSplitLoop | [LLM] |
| 004d7aa0 | DebugLogWrite | [LLM] |
| 0053c5b0 | StringRelocationCopy | [LLM] |
| 00541ca0 | sub_541CA0 | [LLM] |
| 00541cd0 | UtilityFunction_1cd0 | [LLM] |
| 00545020 | SimpleGetter_5020 | [LLM] |
| 00546010 | AudioEngineInitialization | [LLM] |
| 00588410 | sub_588410 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
