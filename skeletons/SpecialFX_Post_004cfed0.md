## SpecialFX_Post_004cfed0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Post (0042da30)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | [LLM] |
| this | 0x4 | RW | 0 | [LLM] |
| this | 0x8 | RW | 0 | [LLM] |
| this | 0xC | RW | 0 | [LLM] |
| this | 0x10 | RW | 0 | [LLM] |
| this | 0x14 | RW | 0 | [LLM] |
| this | 0x18 | RW | 0 | [LLM] |
| this | 0x1C | RW | 0 | [LLM] |
| this | 0x20 | RW | 0 | [LLM] |
| this | 0x24 | RW | 0 | [LLM] |
| this | 0x28 | RW | 0 | [LLM] |
| this | 0x2C | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: once/conditional? does external poke survive?]
- this 0x4: [LLM: once/conditional? does external poke survive?]
- this 0x8: [LLM: once/conditional? does external poke survive?]
- this 0xC: [LLM: once/conditional? does external poke survive?]
- this 0x10: [LLM: once/conditional? does external poke survive?]
- this 0x14: [LLM: once/conditional? does external poke survive?]
- this 0x18: [LLM: once/conditional? does external poke survive?]
- this 0x1C: [LLM: once/conditional? does external poke survive?]
- this 0x20: [LLM: once/conditional? does external poke survive?]
- this 0x24: [LLM: once/conditional? does external poke survive?]
- this 0x28: [LLM: once/conditional? does external poke survive?]
- this 0x2C: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d3624 | aDDevF119992002_25 | R | SourcePath_25 [DERIVED] |
| 005d39f0 | aEnteredSpecial_3 | R | Str_EnteredSpecial_3 [DERIVED] |
| 007c9360 | dbl_7C9360 | R | Unknown_Struct_7C9360 [DERIVED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0044c470 | CollisionTreeNodeCleanup | [LLM] |
| 00499ae0 | FreeIfNonNull | [LLM] |
| 004ca280 | sub_4CA280 | [LLM] |
| 004ca410 | sub_4CA410 | [LLM] |
| 004cb4f0 | MultiFieldFree | [LLM] |
| 004d7a50 | StringSplitLoop | [LLM] |
| 004d7aa0 | DebugLogWrite | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
