## DirectDrawDisplayModeInit_00563e00 — ReinitSessionSubObjects

**Summary:** Reinitializes the session's internal sub-objects: cleans up the existing batch at this+0x4, allocates a new 0x18-byte sub-struct, frees and reallocates the audio array at this+0x94, and resets this+0x98 to 0. Returns 4 if already initialized (*this non-zero).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** StartNetworkUpdate (00461de0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | initialized flag; non-zero prevents reinitialization |
| this | 0x4 | RW | — | pointer to batch sub-object (freed then reallocated) |
| this | 0x94 | RW | — | pointer to audio array (freed then reallocated) |
| this | 0x98 | RW | 0 | counter reset to zero |

**Written-by note (persistence):**
- this 0x4: set to result of Malloc0x18ByteStructWithInnerBuffer on reinit. Survives until next reinit.
- this 0x94: set to result of AllocateIntArrayViaFactory on reinit. Survives until next reinit.
- this 0x98: set to 0 on reinit. Survives until next reinit or increment.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005640f0 | sub_5640F0 | R | callback for creating inner sub-struct at this+0x4 |
| 005645a0 | sub_5645A0 | R | element factory for array allocator at this+0x94 |
| 00564600 | IndirectDwordCompare | R | comparison callback for array sorting/lookup |
| 00564630 | sub_564630 | R | additional callback for array management |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005646d0 | AllocateIntArrayViaFactory | create typed dynamic array with factory/comparison callbacks |
| 00564740 | DestroyAudioArrayFreeElementsThenContainer | free audio array elements and container |
| 00564810 | Malloc0x18ByteStructWithInnerBuffer | allocate 0x18-byte sub-structure containing inner buffer |
| 00564860 | BatchLoopWithMemoryCleanup | batch cleanup loop over memory entries |

**Guard conditions:** *this (offset 0x0) non-zero → return 4 (already initialized, skip reinit). Zero → perform full reinitialization.

