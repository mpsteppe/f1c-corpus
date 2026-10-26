## LinkedListIndexedAccessor_5680_00415680 — LinkedListIndexedAccessor_5680

**Summary:** Returns the value (first DWORD) at a given index in a singly-linked list with head at this[4] and count at this[7]. Returns 0 if index out of bounds or node not found.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** TextAttributeLookup (004133b0), TextAttributeLookup_34d0 (004134d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x10 | R | — | Head pointer of the linked list (this[4]) |
| this | 0x14 | R | — | Next pointer for traversal within list nodes |
| this | 0x18 | R | — | Node data pointer used as traversal accumulator |
| this | 0x1C | R | — | Count of entries in the list (this[7]) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If a2 (index) < 0 or >= this[7] (count), returns 0. Traverses list from this[4] to indexed node; returns first DWORD of that node, or 0 if node not reachable.
