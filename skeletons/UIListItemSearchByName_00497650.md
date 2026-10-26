## UIListItemSearchByName_00497650 — SearchUIListItemByName

**Summary:** Traverses a linked list rooted at this+0x4. For each node, reads name string pointer at offset 0x34 (defaulting to byte_5EA438 if null), compares with parameter `a2` via sub_588410 (likely string compare). Returns matching node pointer or 0 if not found.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_49A5D0 (0049a5d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x4) | 0x34 | R | — | Name string pointer at node offset 0x34 |
| this | 0x4 | R | — | Linked list head pointer |
| this | 0xC | RW | — | Current node pointer during search traversal |
| this | 0x10 | R | — | Loop boundary or list count (read, not modified) |

**Written-by note (persistence):**
- this 0xC: Written at entry and each iteration. External poke does not survive.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | Default name string when node name is null |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00588410 | sub_588410 | String comparison function (returns 0 on match) |

**Guard conditions:** Head pointer this[1] (0x4) must be non-null — null returns 0. First node data must be non-null — null returns 0. Loop checks next node pointer before advancing — null returns 0.
