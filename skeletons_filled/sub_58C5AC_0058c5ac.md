## sub_58C5AC_0058c5ac — FILE stream structure pool allocator

**Summary:** Allocates a FILE stream structure from the CRT's global stream pool (dword_8D4A24 array). Searches for an available slot — either allocates a new 56-byte stream via MallocWrapperForNhMalloc or reuses an inactive slot with no I/O flags set. Initializes stream with handle=-1 and zeroed fields under critical section protection.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_587D7F (00587d7f), sub_58AE69 (0058ae69)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e16c | InitializeCriticalSection | R | Win32 InitializeCriticalSection function pointer |
| 0059e174 | EnterCriticalSection | R | Win32 EnterCriticalSection function pointer |
| 008d4a24 | dword_8D4A24 | R | Pointer array to stream structures (stream pool) |
| 008d5a40 | dword_8D5A40 | R | Number of slots in the stream pool |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058a935 | MallocWrapperForNhMalloc | Allocate 56-byte stream structure memory |
| 0058c1e0 | CriticalSectionEnter | Enter per-stream critical section during reuse claim |
| 0058c232 | CriticalSectionLeave_c232 | Leave per-stream critical section after claim attempt |
| 0058dfea | CriticalSectionLazyInitEnter | Enter global stream pool critical section (index 2) |
| 0058e04b | CritSectLeave | Leave global stream pool critical section (index 2) |

**Guard conditions:** Iterates through stream pool array. If slot pointer is NULL, allocates new 56-byte stream via MallocWrapperForNhMalloc and initializes its embedded CRITICAL_SECTION at +0x20. If slot exists and its flags at +0xC have no I/O bits (0x83), claims it under double-check within per-stream CS. Falls through if all slots in use or allocation fails.
