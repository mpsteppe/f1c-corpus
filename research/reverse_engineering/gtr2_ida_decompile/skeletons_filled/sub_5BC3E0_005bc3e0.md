## sub_5BC3E0_005bc3e0 — any-match search: no-arg virtual predicate (vtable +24)

**Summary:** Same search shape as sub_5BC390 but with no argument and a different slot: walks the collection (count `this[111]` at `this+0x1BC`, array at `this+0x1C4`), calls each element's virtual method at vtable +24, and returns 1 on the first non-zero result; 0 if the list is empty or nothing matches.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1BC | R | — | Element count (`this[111]`); bounds the search loop. |
| this | 0x1C4 | R | — | Pointer to the element-pointer array (`this[113]`); indexed as `this[113] + 4*v3`. |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If `this[111] <= 0` → return 0. Otherwise: element predicate (vtable +24) returning non-zero → return 1; after the last element (`++v3 >= v2`) → return 0. Only the predicate result is tested.
