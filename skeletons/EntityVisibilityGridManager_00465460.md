## EntityVisibilityGridManager_00465460 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** InputCommandDispatchToEntities (0045f4a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(*(obj+0xE5B8)+0x0)+0x0) | 0x6C | R | — | [LLM] |
| *(*(*(obj+0xE5B8)+0x0)+0x0) | 0x6D | R | — | [LLM] |
| *(*(*(obj+0xE5B8)+0x0)+0x0) | 0x71 | R | — | [LLM] |
| *(*(*(obj+0xE5B8)+0x0)+0x0) | 0x219 | R | — | [LLM] |
| *(*(obj+0x7C)+0x0) | 0x1AC | R | — | [LLM] |
| *(*(obj+0xE5B0)+0x0) | 0x6D | R | — | [LLM] |
| *(*(obj+0xE5B8)+0x0) | 0x0 | R | — | [LLM] |
| *(obj+0x6C) | 0x0 | R | — | [LLM] |
| *(obj+0x6C) | 0x1AC | R | — | [LLM] |
| *(obj+0x74) | 0x0 | R | — | [LLM] |
| *(obj+0x7C) | 0x0 | R | — | [LLM] |
| *(obj+0x84) | 0x0 | R | — | [LLM] |
| *(obj+0xE5B0) | 0x0 | R | — | [LLM] |
| *(obj+0xE5B8) | 0x0 | R | — | [LLM] |
| *(obj+0xE5C0) | 0x8 | R | — | [LLM] |
| obj | 0x60 | R | — | [LLM] |
| obj | 0x64 | R | — | [LLM] |
| obj | 0x6C | R | — | [LLM] |
| obj | 0x74 | RW | — | [LLM] |
| obj | 0x78 | R | — | [LLM] |
| obj | 0x7C | R | — | [LLM] |
| obj | 0x84 | RW | — | [LLM] |
| obj | 0x88 | R | — | [LLM] |
| obj | 0xE5B0 | RW | 0 | [LLM] |
| obj | 0xE5B4 | RW | 0 | [LLM] |
| obj | 0xE5B8 | RW | 0 | [LLM] |
| obj | 0xE5BC | RW | 0 | [LLM] |
| obj | 0xE5C0 | RW | 0 | [LLM] |
| obj | 0xE5C4 | RW | 0 | [LLM] |
| obj | 0xE5C8 | RW | 0 | [LLM] |
| obj | 0xE5CC | RW | 0 | [LLM] |
| this | 0x0 | R | — | [LLM] |

**Written-by note (persistence):**
- obj 0x74: [LLM: once/conditional? does external poke survive?]
- obj 0x84: [LLM: once/conditional? does external poke survive?]
- obj 0xE5B0: [LLM: once/conditional? does external poke survive?]
- obj 0xE5B4: [LLM: once/conditional? does external poke survive?]
- obj 0xE5B8: [LLM: once/conditional? does external poke survive?]
- obj 0xE5BC: [LLM: once/conditional? does external poke survive?]
- obj 0xE5C0: [LLM: once/conditional? does external poke survive?]
- obj 0xE5C4: [LLM: once/conditional? does external poke survive?]
- obj 0xE5C8: [LLM: once/conditional? does external poke survive?]
- obj 0xE5CC: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00465c18 | jpt_4655B3 | R | [LLM] |
| 005ec6d8 | unk_5EC6D8 | R | VEH[0].0x0 = postProcessInput [CONFIRMED] |
| 005ef9a0 | dword_5EF9A0 | R | VEH[0].0x32C8 [LLM: field purpose] |
| 005f0f88 | word_5F0F88 | R | VEH[0].0x48B0 [LLM: field purpose] |
| 007cd2ac | dword_7CD2AC | W | � base address for sort priority table [DERIVED] |
| 008afe90 | dbl_8AFE90 | R | EngineCoolingRate [DERIVED] (also: ` — cooling rate per frame) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00464990 | ShortComputation_4990 | [LLM] |
| 00464ad0 | DispatchWrapper | [LLM] |
| 00464ae0 | CharacterRangeCheckWithSignFlag | [LLM] |
| 00464bb0 | UtilityFunction_4bb0 | [LLM] |
| 00464bd0 | FloatFieldDecrementWithClamp | [LLM] |
| 00464f50 | DivisionWithCapComputation | [LLM] |
| 00464f90 | ThresholdToRankClassifier | [LLM] |
| 00465c70 | MergeSortOnLinkedList | [LLM] |
| 00465d70 | sub_465D70 | [LLM] |
| 004b2c80 | VectorToShort3Conversion | [LLM] |
| 004b33b0 | ProgressBarEventEncode | [LLM] |
| 00582290 | ConditionalFreeByFlagCheck | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |
| 00587bdc | CRTFtol | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(*(obj+0xE5B8)+0x0) | 0x0 | != | 18446744073709551507 | [LLM] |
| obj | 0x7C | == | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
