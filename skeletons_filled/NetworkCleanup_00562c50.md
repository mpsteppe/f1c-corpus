## NetworkCleanup_00562c50 — NetworkSessionDestructor

**Summary:** Tears down a network session object by freeing sub-objects at offsets +4, +8, and +0x94, then freeing the object itself and calling WSACleanup.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ConditionalObjectCleanup (00464670)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | pointer to first sub-object (batch-loop cleanup via BatchLoopWithMemoryCleanup) |
| this | 0x8 | R | — | pointer to second sub-object (freed via sub_58AA6F) |
| this | 0x94 | R | — | pointer to audio element array (freed via DestroyAudioArrayFreeElementsThenContainer) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00564740 | DestroyAudioArrayFreeElementsThenContainer | frees audio array elements and container |
| 00564860 | BatchLoopWithMemoryCleanup | batch cleanup loop over memory entries |
| 0058aa6f | sub_58AA6F | memory deallocation helper |

**Guard conditions:** none — unconditional teardown of all sub-objects followed by self-free.

