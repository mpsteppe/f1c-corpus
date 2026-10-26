## sub_58C5AC_0058c5ac — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_587D7F (00587d7f), sub_58AE69 (0058ae69)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e16c | InitializeCriticalSection | R | [LLM] |
| 0059e174 | EnterCriticalSection | R | [LLM] |
| 008d4a24 | dword_8D4A24 | R | HeapSlotArrayPtr [DERIVED] |
| 008d5a40 | dword_8D5A40 | R | ThreadPoolCount [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058a935 | MallocWrapperForNhMalloc | [LLM] |
| 0058c1e0 | CriticalSectionEnter | [LLM] |
| 0058c232 | CriticalSectionLeave_c232 | [LLM] |
| 0058dfea | CriticalSectionLazyInitEnter | [LLM] |
| 0058e04b | CritSectLeave | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
