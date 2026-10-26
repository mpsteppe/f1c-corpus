## LinkedIndexedAccess_00545820 — Indexed access into category 2 drawable list with bounds check

**Summary:** Returns the node at index `a2` from category 2 linked list. Validates index against `this[75]` (category 2 counter) and walks forward from head using next pointers at offset 0x6C.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4FCEE0 (004fcee0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x19C) | 0x6C | R | — | Next-node pointer in category 2 list |
| this | 0x12C | R | — | Counter for category 2 (upper bound for index) |
| this | 0x130 | R | — | Head of category 2 linked list |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** `a2 < 0 || a2 >= this[75]`: BLOCKED (return 0) when out of bounds; PASSES (walk to index) when in bounds.
