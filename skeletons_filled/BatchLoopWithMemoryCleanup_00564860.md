## BatchLoopWithMemoryCleanup_00564860 — batch-processing array with sub-resource cleanup

**Summary:** Iterates over array using count at offset 0, calls IndirectCallViaFunctionPointer on each element, then frees two resources via sub_58AA6F (element[5] and the array itself). Part of audio/networking resource cleanup subsystem.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** NetworkCleanup (00562c50), DirectDrawDisplayModeInit (00563e00), DestroyAudioArrayFreeElementsThenContainer (00564740)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | array element count |
| this | 0x14 | R | — | sub-resource pointer to free via sub_58AA6F |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00564890 | IndirectCallViaFunctionPointer | calls per-element processing callback |
| 0058aa6f | sub_58AA6F | memory deallocation routine |

**Guard conditions:** None — unconditionally loops for i < this[0] (count), then frees both resources. No early returns or skip checks.
