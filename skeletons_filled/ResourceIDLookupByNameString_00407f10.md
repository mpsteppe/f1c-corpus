## ResourceIDLookupByNameString_00407f10 — ResourceIDLookupByString

**Summary:** Traverses a linked list looking for a node whose string name matches the input, then returns the node's integer ID at offset 0x5C. Returns -1 if not found. Nodes with ID == -1 are skipped (treated as unregistered).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ShortComputation_5050 (00405050)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x18) | 0x5C | R | — | ID field at offset 0x5C within resource data node |
| *(this+0x20) | 0x5C | R | — | ID field from the final matching node returned to caller |
| this | 0x18 | R | — | head pointer of linked list |
| this | 0x20 | RW | — | traversal cursor, updated as iteration advances |
| this | 0x24 | R | — | count of nodes in linked list |

**Written-by note (persistence):**
- this 0x20: overwritten every call — cursor is reset to head, then advanced per node during traversal

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00499e20 | StringPointerAccessor | retrieves string pointer from resource data node (used for name comparison) |
| 00588410 | sub_588410 | compares two strings; returns 0 on match (like strcmp) |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(this+0x18) | 0x5C | != | 18446744073709551615 | resource ID at offset 0x5C; -1 means unregistered/inactive |

**Guard interpretation:** Nodes whose ID field (offset 0x5C) equals -1 are skipped during traversal — their string is not compared and they cannot match. Only nodes with a valid (non -1) ID participate in string matching. If `a2` is null or equals byte_5EA438, function returns -1 immediately without list traversal.
