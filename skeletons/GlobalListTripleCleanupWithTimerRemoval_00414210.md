## GlobalListTripleCleanupWithTimerRemoval_00414210 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00414370 | ShortComputation_4370 | R | [LLM] |
| 005ea5e8 | dword_5EA5E8 | RW | MemoryCleanupList3 [DERIVED] |
| 005ea5ec | dword_5EA5EC | W | [LLM] |
| 005ea5f0 | dword_5EA5F0 | W | [LLM] |
| 005ea5f4 | dword_5EA5F4 | W | [LLM] |
| 005ea5f8 | dword_5EA5F8 | RW | ResourceList_Geom [DERIVED] |
| 005ea5fc | dword_5EA5FC | W | [LLM] |
| 005ea600 | dword_5EA600 | W | [LLM] |
| 005ea604 | dword_5EA604 | W | [LLM] |
| 005ea608 | dword_5EA608 | RW | DestroyLinkedListHead1 [DERIVED] |
| 005ea60c | dword_5EA60C | W | [LLM] |
| 005ea610 | dword_5EA610 | W | [LLM] |
| 005ea614 | dword_5EA614 | W | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00401030 | ArrayDestructorIterator | [LLM] |
| 00414370 | ShortComputation_4370 | [LLM] |
| 00414380 | MultiFieldPointerFree | [LLM] |
| 00414420 | MultiPointerFree | [LLM] |
| 004149a0 | TextFormatStructInitializer | [LLM] |
| 004150c0 | DrawableResourceCleanup | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
