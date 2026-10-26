## SlabBuddyAllocatorInitialization_0059491a — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_59325D (0059325d), sub_594C12 (00594c12)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e0a0 | VirtualAlloc | R | [LLM] |
| 0059e0a4 | VirtualFree | R | [LLM] |
| 0059e1bc | HeapFree | R | [LLM] |
| 0059e1c0 | HeapAlloc | R | [LLM] |
| 005e7968 | off_5E7968 | RW | HeapListHead [DERIVED] |
| 005e796c | off_5E796C | RW | MemMgr_HeapFreeListHead [DERIVED] |
| 005e7978 | dword_5E7978 | R | HeapMarker [DERIVED] (also: HeapMarker (-1 = static pool) |
| 008d4904 | hHeap | R | PrivateHeapHandle [DERIVED] (also: PrivateHeapHandle (docs/12) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058bb10 | sub_58BB10 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
