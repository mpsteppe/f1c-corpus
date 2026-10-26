## SceneExtentComputation_004bdc10 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Init (0042d6b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x924 | RW | — | [LLM] |
| this | 0x928 | RW | — | [LLM] |
| this | 0x92C | RW | — | [LLM] |
| this | 0x930 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x924: [LLM: once/conditional? does external poke survive?]
- this 0x928: [LLM: once/conditional? does external poke survive?]
- this 0x92C: [LLM: once/conditional? does external poke survive?]
- this 0x930: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e4dc | flt_59E4DC | R | FullResponseThreshold [DERIVED] (also: ` — full response threshold (float) |
| 005d25d0 | aCouldNotGetExt | R | String_CouldNotGetExt [DERIVED] |
| 005d2604 | aDDevF119992002_23 | R | DebugSourcePath_F1C [DERIVED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |
| 008afe88 | dword_8AFE88 | R | CollisionGeometryHandle [DERIVED] (also: ` — global collision geometry handle) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d7a50 | StringSplitLoop | [LLM] |
| 004d7aa0 | DebugLogWrite | [LLM] |
| 004dd550 | BoundingBoxComputation | [LLM] |
| 005452f0 | AudioNetworkNodeCount | [LLM] |
| 00545340 | LinkedListNodeFinder | [LLM] |
| 0054fb70 | LinkedListFlagBitExtraction | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
