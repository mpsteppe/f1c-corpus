## UILargeRenderDispatcher_00488be0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UIRenderDispatchWrapper (00488f40), ConditionalRenderingCall (0048d6f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xB8) | 0x0 | R | — | [LLM] |
| this | 0x4 | R | — | [LLM] |
| this | 0x8 | R | — | [LLM] |
| this | 0xC | R | — | [LLM] |
| this | 0x10 | R | — | [LLM] |
| this | 0xB0 | R | — | [LLM] |
| this | 0xB8 | R | — | [LLM] |
| this | 0xE0 | RW | 3 | [LLM] |
| this | 0xE4 | R | — | [LLM] |
| this | 0xE8 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0xE0: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec4c0 | byte_5EC4C0 | R | EmptyStringBuffer [DERIVED] |
| 005ec4cc | byte_5EC4CC | RW | MessageDisplayBuffer [DERIVED] (also: ` (byte_5EC4CC) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00423a00 | BinarySearchInStringTable | [LLM] |
| 004980d0 | BitmapDraw | [LLM] |
| 004981f0 | BitmapDraw_81f0 | [LLM] |
| 004982c0 | BitmapDrawWithAlpha | [LLM] |
| 004983b0 | TextRenderToSurface | [LLM] |
| 0049a9c0 | ShortComputation_a9c0 | [LLM] |
| 00587bdc | CRTFtol | [LLM] |
| 00589a35 | sub_589A35 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0xE0 | == | 3 | [LLM] |
| this | 0xE0 | == | 2 | [LLM] |
| this | 0xE4 | <= | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
