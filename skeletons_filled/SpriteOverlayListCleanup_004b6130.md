## SpriteOverlayListCleanup_004b6130 — Overlay/Sprite List Cleanup

**Summary:** Frees an array of overlay/sprite entries at this+0x9B0. Reads entry count from a header at offset -4, iterates backward with 44-byte stride calling QuadrupleListCleanup per entry, then frees the allocation and zeroes the pointer and count fields.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DestroyUIWidgetHierarchy (004b5a30), BufferPoolAllocatorInitialization (004b71e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x9B0 | RW | 0 | Pointer to overlay/sprite array (cleared after free) |
| this | 0x9B4 | RW | 0 | Array count/size field (cleared after free) |

**Written-by note (persistence):**
- this 0x9B0: Set to 0 after freeing; persists as null.
- this 0x9B4: Set to 0 after freeing; persists as zero.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b46f0 | QuadrupleListCleanup | Cleanup/release resources within each 44-byte entry |
| 00587bcf | FreeWrapper_7bcf | Free the entire array allocation |

**Guard conditions:** If this+0x9B0 is NULL, return immediately — nothing to free. Otherwise read entry count from *(this+0x9B0 - 4), iterate backward through entries (44 bytes each), calling QuadrupleListCleanup per entry, then free the block and zero the fields.
