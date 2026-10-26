## LinkedListTraversal_005457c0 — Indexed access into category 1 drawable list with bounds check

**Summary:** Returns the node at index `a2` from category 1 linked list. Validates index against `this[71]` (category 1 counter) and walks forward from head using next pointers at offset 0x6C.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4FCEE0 (004fcee0), sub_558E70 (00558e70), sub_560C10 (00560c10), sub_560FE0 (00560fe0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x18C) | 0x6C | R | — | Next-node pointer in category 1 list |
| this | 0x11C | R | — | Counter for category 1 (upper bound for index) |
| this | 0x120 | R | — | Head of category 1 linked list |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** `a2 < 0 || a2 >= this[71]`: BLOCKED (return 0) when out of bounds; PASSES (walk to index) when in bounds.
