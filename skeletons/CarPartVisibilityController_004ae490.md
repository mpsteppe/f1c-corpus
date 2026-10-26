## CarPartVisibilityController_004ae490 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_472930 (00472930), TrackEnvironmentSelect (004ade20)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xB10 | RW | 1 | [LLM] |
| this | 0xB18 | R | — | [LLM] |
| this | 0xB1C | R | — | [LLM] |
| this | 0xB34 | RW | 1 | [LLM] |
| this | 0xB3C | R | — | [LLM] |
| this | 0xB40 | R | — | [LLM] |
| this | 0xB58 | RW | 1 | [LLM] |
| this | 0xB60 | R | — | [LLM] |
| this | 0xB64 | R | — | [LLM] |
| this | 0x1AC8 | R | — | [LLM] |
| this | 0x1C30 | RW | 0 | [LLM] |
| this | 0x1C38 | R | — | [LLM] |
| this | 0x1C3C | R | — | [LLM] |
| this | 0x2348 | RW | 1056964608 → 0.5f | [LLM] |
| this | 0x2350 | R | — | [LLM] |
| this | 0x2354 | R | — | [LLM] |
| this | 0x236C | RW | 1056964608 → 0.5f | [LLM] |
| this | 0x2374 | R | — | [LLM] |
| this | 0x2378 | R | — | [LLM] |
| this | 0x26F0 | RW | 1 | [LLM] |
| this | 0x26F8 | R | — | [LLM] |
| this | 0x26FC | R | — | [LLM] |
| this | 0x2714 | RW | 1 | [LLM] |
| this | 0x271C | R | — | [LLM] |
| this | 0x2720 | R | — | [LLM] |
| this | 0x2738 | RW | 1 | [LLM] |
| this | 0x2740 | R | — | [LLM] |
| this | 0x2744 | R | — | [LLM] |
| this | 0x27EC | RW | 1 | [LLM] |
| this | 0x27F4 | R | — | [LLM] |
| this | 0x27F8 | R | — | [LLM] |
| this | 0x2810 | RW | 1 | [LLM] |
| this | 0x2818 | R | — | [LLM] |
| this | 0x281C | R | — | [LLM] |
| this | 0x2834 | RW | 1 | [LLM] |
| this | 0x283C | R | — | [LLM] |
| this | 0x2840 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0xB10: [LLM: once/conditional? does external poke survive?]
- this 0xB34: [LLM: once/conditional? does external poke survive?]
- this 0xB58: [LLM: once/conditional? does external poke survive?]
- this 0x1C30: [LLM: once/conditional? does external poke survive?]
- this 0x2348: [LLM: once/conditional? does external poke survive?]
- this 0x236C: [LLM: once/conditional? does external poke survive?]
- this 0x26F0: [LLM: once/conditional? does external poke survive?]
- this 0x2714: [LLM: once/conditional? does external poke survive?]
- this 0x2738: [LLM: once/conditional? does external poke survive?]
- this 0x27EC: [LLM: once/conditional? does external poke survive?]
- this 0x2810: [LLM: once/conditional? does external poke survive?]
- this 0x2834: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ec3d0 | dword_5EC3D0 | R | SeasonParentPath [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00423060 | ShortComputation_3060 | [LLM] |
| 004646c0 | FloatClamp | [LLM] |
| 0047f1f0 | ClampByRange | [LLM] |
| 004b20d0 | ArithmeticComparison_20d0 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x1AC8 | != | 2 | [LLM] |
| this | 0x1AC8 | == | 1 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
