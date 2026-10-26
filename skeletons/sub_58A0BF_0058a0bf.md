## sub_58A0BF_0058a0bf — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** LockCallUnlockWrapper (00589ffd), ThunkToSub58A0BF (0058a0b6)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008d4a24 | dword_8D4A24 | R | HeapSlotArrayPtr [DERIVED] |
| 008d5a40 | dword_8D5A40 | R | ThreadPoolCount [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058a02c | MemoryBlockValidationCheck | [LLM] |
| 0058c1e0 | CriticalSectionEnter | [LLM] |
| 0058c232 | CriticalSectionLeave_c232 | [LLM] |
| 0058dfea | CriticalSectionLazyInitEnter | [LLM] |
| 0058e04b | CritSectLeave | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
