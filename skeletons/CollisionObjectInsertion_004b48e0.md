## CollisionObjectInsertion_004b48e0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PitStallProximityCheck (004b5da0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004b4a10 | jpt_4B4900 | R | [LLM] |
| 008ab6f0 | dword_8AB6F0 | R | AudioBucketListHead [DERIVED] |
| 008ab700 | dword_8AB700 | R | FreeListHead [DERIVED] |
| 008ab708 | dword_8AB708 | R | GlobalAllocPoolNode [DERIVED] (also: global pool/pre-allocated node) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b3a90 | ArithmeticComparison_3a90 | [LLM] |
| 004b4760 | ArithmeticComparison_4760 | [LLM] |
| 004b47a0 | ArithmeticComparison_47a0 | [LLM] |
| 004ba780 | ShortComputation_a780 | [LLM] |
| 004ba950 | ConditionalAllocation | [LLM] |
| 004bac40 | LinkedListNodeInsertion_ac40 | [LLM] |
| 004bacf0 | LinkedListNodeRemoval_acf0 | [LLM] |
| 004bb6b0 | sub_4BB6B0 | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
