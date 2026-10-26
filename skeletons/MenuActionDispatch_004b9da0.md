## MenuActionDispatch_004b9da0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4BA1F0 (004ba1f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0xF8C | RW | — | [LLM] |
| this | 0x0 | R | — | [LLM] |

**Written-by note (persistence):**
- obj 0xF8C: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004b9e04 | jpt_4B9DB0 | R | [LLM] |
| 004b9e1c | byte_4B9E1C | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b81a0 | SortedLinkedListInsert | [LLM] |
| 004b8360 | SpriteOverlayDisplayListCleanup | [LLM] |
| 004b8480 | LinkedListDestructor_8480 | [LLM] |
| 004b84f0 | SortedListSeekByValue | [LLM] |
| 004b85d0 | LinkedListPrioritySearchByFloatThreshold | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
