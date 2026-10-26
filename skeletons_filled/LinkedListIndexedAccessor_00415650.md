## LinkedListIndexedAccessor_00415650 — LinkedListIndexedAccessor

**Summary:** Returns the value (first DWORD) at a given index in a singly-linked list with head at *this and count at this[3]. Returns 0 if index out of bounds or node not found.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SessionStringNameLookup (004122c0), ShortComputation_5730 (00415730)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x4 | R | — | Next pointer in linked list node for traversal |
| obj | 0x8 | R | — | Flag/active byte for list node |
| this | 0x0 | R | — | Head pointer of the linked list |
| this | 0xC | R | — | Count of entries in the list (this[3]) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If a2 (index) < 0 or >= this[3] (count), returns 0. Traverses list to indexed node; returns first DWORD of node data, or 0 if node not reachable.
