## D3DMarkDirty_00556cd0 — MarkD3DBuffersDirty

**Summary:** Marks D3D resources as dirty for re-upload. Checks flags at offset 0x44/0x4C for unconditional or conditional dirty marking, then iterates a linked list at offset 0x204 to set dirty bit 0x400 on each element and call sub_55D720. Part of D3D resource update system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** NestedLinkedListTraversalWithDirtyMark (005570c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x44 | R | — | flag: if non-zero, mark resources dirty unconditionally |
| this | 0x4C | R | — | flag: if non-zero AND a3 non-zero, mark resources dirty |
| this | 0x204 | R | — | linked list head for resource descriptor blocks |
| this | 0x224 | R | — | count of elements in each resource block (from node at this+0x204 +0x20) |
| this | 0x228 | RW | — | pointer to resource element array (from node at this+0x204 +0x24) |
| this | 0x32C | R | — | additional resource property field (from node at this+0x204 +0x128) |
| this | 0x330 | R | — | additional resource property field (from node at this+0x204 +0x12C) |
| this | 0x368 | RW | — | flag field at this+0x204 +0x164; bit 0x10000000 cleared after iteration |

**Written-by note (persistence):**
- this 0x228: pointer to resource array, set externally (not modified in this function)
- this 0x368: bit 0x10000000 cleared after processing each node

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00556cd0 | D3DMarkDirty | self: recursive call for inner resource marking |
| 0055d720 | sub_55D720 | mark single resource/buffer as dirty, trigger re-upload |

**Guard conditions:** 
1. `this[17]` (offset 0x44) non-zero → call D3DMarkDirty(a2, 1) unconditionally
2. `this[19]` (offset 0x4C) non-zero AND a3 non-zero → call D3DMarkDirty(a2, 1)
3. Linked list at this[129] (offset 0x204) null → skip inner loop
4. Inner loop: for each node, iterate over `i[70]` elements, set bit 0x400 at offset 0x56 of each element, call sub_55D720
5. After inner loop: clear bit 0x10000000 from node flags at offset 0x14