## QuadrupleListCleanup_004b46f0 — QuadrupleListCleanup

**Summary:** Walks and frees 4 linked lists of physics/collision nodes at offsets 0x70-0xAC (16 dwords of head/tail/next pointers). Frees type-1 nodes' associated buffers, frees all node structs, zeroes all pointers. Also zeroes 4 fields at offsets 0xB0-0xBC. Called from SpriteOverlayListCleanup.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SpriteOverlayListCleanup (004b6130)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xB0 | RW | 0 | List pointer field (zeroed at end) |
| this | 0xB4 | RW | 0 | List pointer field (zeroed at end) |
| this | 0xB8 | RW | 0 | List pointer field (zeroed at end) |
| this | 0xBC | RW | 0 | List pointer field (zeroed at end) |

**Written-by note (persistence):**
- this 0xB0: written once — zeroed during cleanup
- this 0xB4: written once — zeroed during cleanup
- this 0xB8: written once — zeroed during cleanup
- this 0xBC: written once — zeroed during cleanup

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b4e10 | PhysicsObjectListManager | Manage/pre-process physics object list before cleanup |
| 00587bcf | FreeWrapper_7bcf | Free node struct and associated buffer memory |

**Guard conditions:** For each of 4 lists: iterates while list head pointer is non-null. If node type byte at offset +8 is non-zero (type-1, active): frees the buffer pointer stored in the node before freeing the node itself. Type-0 (free list) nodes are freed without freeing buffer.
