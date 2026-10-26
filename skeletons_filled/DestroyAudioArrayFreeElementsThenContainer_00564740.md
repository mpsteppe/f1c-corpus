## DestroyAudioArrayFreeElementsThenContainer_00564740 — FreePointerArrayAndContainer

**Summary:** Iterates over a pointer array (element count at lpMem+4, buffer at *lpMem), frees each element via BatchLoopWithMemoryCleanup, then frees the buffer and the container struct via sub_58AA6F.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** NetworkCleanup (00562c50), DirectDrawDisplayModeInit (00563e00), sub_5640F0 (005640f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | pointer to array buffer (*lpMem = pointer to first element pointer) |
| this | 0x4 | R | — | element count (lpMem[1]) — number of entries in the array |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00564860 | BatchLoopWithMemoryCleanup | batch cleanup loop for each element |
| 0058aa6f | sub_58AA6F | memory deallocation helper |

**Guard conditions:** loop runs while i < lpMem[1] (element count). If count is 0, only the buffer and container are freed.

