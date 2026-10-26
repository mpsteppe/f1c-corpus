## CollisionBroadphaseBuilder_00490ee0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** RenderSurfaceFillCopy (004918d0), DualDispatchWithGuard (00491960)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x0 | R | — | [LLM] |
| obj | 0x4 | RW | — | [LLM] |
| obj | 0x8 | R | — | [LLM] |
| this | 0x0 | RW | — | [LLM] |
| this | 0x4 | RW | — | [LLM] |
| this | 0x8 | RW | — | [LLM] |
| this | 0xC | RW | — | [LLM] |

**Written-by note (persistence):**
- obj 0x4: [LLM: once/conditional? does external poke survive?]
- this 0x0: [LLM: once/conditional? does external poke survive?]
- this 0x4: [LLM: once/conditional? does external poke survive?]
- this 0x8: [LLM: once/conditional? does external poke survive?]
- this 0xC: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00434030 | DoublyLinkedListAppend | [LLM] |
| 00490940 | ResourcePoolNodeAllocDealloc | [LLM] |
| 00490aa0 | LinkedListNodePrepend | [LLM] |
| 00490d00 | sub_490D00 | [LLM] |
| 00491350 | RectangleClipping | [LLM] |
| 00491680 | sub_491680 | [LLM] |
| 00491db0 | LinkedListDestructor_1db0 | [LLM] |
| 00491e10 | ConditionalResourceCleanup | [LLM] |
| 004bac20 | ShortComputation_ac20 | [LLM] |
| 00581780 | LinkedListNodeAdvance | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | == | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
