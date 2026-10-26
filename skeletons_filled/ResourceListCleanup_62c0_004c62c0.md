## ResourceListCleanup_62c0_004c62c0 — Free resource list nodes and reset structure

**Summary:** Copies default directory path string, then walks a linked list of resource nodes freeing each node's data (including any secondary allocation within the data struct) and the node itself. Zeroes all list-management fields.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GameFilterSetup (00477830), ShortComputation_5db0 (004c5db0), sub_4C5DE0 (004c5de0), SceneFileFilterBuilder (004c6330)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x8) | 0x4 | R | — | Secondary pointer in first data node (freed if non-null) |
| *(this+0xC) | 0x4 | R | — | Secondary pointer in tail data node |
| this | 0x8 | RW | 0 | Head pointer of linked list; zeroed after cleanup |
| this | 0xC | RW | 0 | Tail pointer; zeroed |
| this | 0x10 | RW | 0 | Iterator/first-node pointer; zeroed |
| this | 0x14 | RW | 0 | Count of items; zeroed |
| this | 0x18 | RW | 0 | Extra field; zeroed |

**Written-by note (persistence):**
- this 0x8: set to 0 unconditionally
- this 0xC: set to 0 unconditionally
- this 0x10: set to 0 unconditionally
- this 0x14: set to 0 unconditionally
- this 0x18: set to 0 unconditionally

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00566650 | StringCopyWithBufferRealloc | Copy default directory path (return value used but not stored) |
| 00587bcf | FreeWrapper_7bcf | Free node data struct (with optional secondary pointer) and node itself |

**Guard conditions:** If `this[2]` (head pointer at offset 0x8) is zero, skip cleanup loop; only zeroing of fields occurs.
