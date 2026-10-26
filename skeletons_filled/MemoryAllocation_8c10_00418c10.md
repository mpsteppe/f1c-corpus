## MemoryAllocation_8c10_00418c10 — TextStructDeepCleanup

**Summary:** Destructor for text display structure. Checks flag at this+0x8; if set, reinitializes data block via TextFormatStructInitializer_4d70, frees 9 allocated pointers within block at strides of 5 dwords, frees block itself, then optionally frees `this` container if a2 bit 0 is set.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** NameListBuilderFromVehicleArray (004159b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x0 | R | — | First pointer in data block (v3[0]), freed last |
| this | 0x0 | R | — | Pointer to data block (v3); freed after internal cleanup |
| this | 0x8 | R | — | Cleanup enable flag (byte); must be non-zero to proceed |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00414d70 | TextFormatStructInitializer_4d70 | Reinitializes text format data within the block |
| 00587bcf | FreeWrapper_7bcf | Memory deallocation wrapper (called for each pointer) |

**Guard conditions:** this+0x8 (cleanup flag) must be non-zero to enter cleanup path. If *this (data block) is null, skip all internal freeing. Each individual pointer in block is checked for null before FreeWrapper_7bcf call. After internal cleanup, if a2 bit 0 is set, `this` container is also freed.
