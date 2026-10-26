## LinkedListNthElement_005457f0 — Indexed access into category 4 drawable list with bounds check

**Summary:** Returns the node at index `a2` from category 4 linked list. Validates index against `this[73]` (category 4 counter) and walks forward from head using next pointers at offset 0x6C.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4FCEE0 (004fcee0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x194) | 0x6C | R | — | Next-node pointer in category 4 list |
| this | 0x124 | R | — | Counter for category 4 (upper bound for index) |
| this | 0x128 | R | — | Head of category 4 linked list |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** `a2 < 0 || a2 >= this[73]`: BLOCKED (return 0) when out of bounds; PASSES (walk to index) when in bounds.
