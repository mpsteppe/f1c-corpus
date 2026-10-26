## sub_58AA6F_0058aa6f — OS-version-dispatched memory deallocation

**Summary:** Memory free/dispose function dispatching to pool-based free or HeapFree based on OS version code (2=Win2K pool, 3=WinXP pool, else HeapFree). NULL-safe — returns immediately on null pointer.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** ConditionalCall_7ec8 (00517ec8), FreeWrapper_9351 (00519351), FileHandleDestructorWithModeCheck (00534ee0), AllocatorFreeWrapper (00536ff0), SocketCloseAndCleanup (00561f80), NetworkCleanup (00562c50), sub_5640F0 (005640f0), sub_564630 (00564630), DestroyAudioArrayFreeElementsThenContainer (00564740), BatchLoopWithMemoryCleanup (00564860), FreeWrapper_7bcf (00587bcf), MSVCCRTFileClose (00587d33), sub_588A34 (00588a34), sub_588C7A (00588c7a), sub_588D95 (00588d95), sub_589901 (00589901), sub_58B5D4 (0058b5d4), sub_58C411 (0058c411), CriticalSectionLazyInitEnter (0058dfea), PhysicsAllocatorNodeInit (0058ef83), sub_58F362 (0058f362), AudioCodecBufferAllocation (0058f4f2), PhysicsAllocatorNodeInit_f6fe (0058f6fe), MultiFieldFree_f8eb (0058f8eb), sub_58F939 (0058f939), sub_5921F3 (005921f3), sub_592AF4 (00592af4), sub_592DFA (00592dfa), sub_5968F6 (005968f6), sub_598323 (00598323), ObjectTeardownWithIteratorCleanup (0059ac7f), TypeInfoDestructor (0059baa3)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0058895c | ScriptFrameProcessor | R | Unused in this function |
| 0059e1bc | HeapFree | R | HeapFree function pointer for fallback deallocation |
| 005b8ce8 | stru_5B8CE8 | R | HeapFree exception information structure |
| 008d4904 | hHeap | R | Private heap handle for fallback HeapFree |
| 008d4908 | dword_8D4908 | R | OS version code discriminator (2=Win2K, 3=WinXP) |
| ff00000000001692 | byte_FF00000000001692 | R | TLS access base for thread-local storage |
| ff00000000001695 | byte_FF00000000001695 | W | TLS access base for thread-local storage |
| ff0000000000169b | byte_FF0000000000169B | RW | TLS access base for thread-local storage |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058dfea | CriticalSectionLazyInitEnter | Enter critical section 9 to serialize pool deallocation |
| 0058e04b | CritSectLeave | Leave critical section 9 after pool deallocation |
| 00593e1b | sub_593E1B | Lookup memory block metadata in pool (WinXP path) |
| 00593e46 | sub_593E46 | Return memory block to pool (WinXP path) |
| 00594b76 | MemoryRegionValidationHeapLookup | Validate memory region and retrieve heap block info (Win2K path) |
| 00594bcd | CounterThreshold | Update counter/threshold for freed block (Win2K path) |

**Guard conditions:** Returns immediately if lpMem is NULL. Checks dword_8D4908 (OSVersionCode) == 3 for WinXP pool path: looks up block via sub_593E1B, frees via sub_593E46, returns on success. Checks dword_8D4908 == 2 for Win2K pool path: validates via MemoryRegionValidationHeapLookup, updates counters via CounterThreshold, returns on success. Falls through to HeapFree on failure or when neither code matches.
