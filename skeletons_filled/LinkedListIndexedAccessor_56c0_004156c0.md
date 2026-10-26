## LinkedListIndexedAccessor_56c0_004156c0 — LinkedListIndexedAccessor_56c0

**Summary:** Returns the value (first DWORD) at a given index in a singly-linked list with head at this[8] and count at this[11]. Returns 0 if index out of bounds or node not found.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** TextAttributeLookup_3600 (00413600), TextAttributeLookup_3710 (00413710)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x20 | R | — | Head pointer of the linked list (this[8]) |
| this | 0x24 | R | — | Next pointer for traversal within list nodes |
| this | 0x28 | R | — | Node data pointer used as traversal accumulator |
| this | 0x2C | R | — | Count of entries in the list (this[11]) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If a2 (index) < 0 or >= this[11] (count), returns 0. Traverses list from this[8] to indexed node; returns first DWORD of that node, or 0 if node not reachable.
