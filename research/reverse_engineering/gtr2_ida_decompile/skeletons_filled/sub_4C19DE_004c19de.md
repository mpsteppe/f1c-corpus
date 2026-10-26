## sub_4C19DE_004c19de — Conditional command-3 dispatcher with fallback

**Summary:** Queries the object's predicate helper sub_4BFDE0 with id 3; when it returns true, dispatches through the object's vtable method at slot +0x1C with argument 3, otherwise forwards the second argument to the fallback routine sub_4CC3A1.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x1C | R | — | Vtable slot (offset 28) holding the method pointer invoked as (this, 3) when the predicate passes |
| this | 0x0 | R | — | Object vtable pointer, read to resolve the method at vtable offset +0x1C |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004bfde0 | sub_4BFDE0 | Predicate/state check on the object with id 3; returns nonzero when the object can handle command 3 itself |

**Guard conditions:** `sub_4BFDE0(a1, 3)` must return nonzero. PASS: virtual method at `*a1 + 28` is called with (a1, 3). BLOCK (else): the fallback routine sub_4CC3A1 is called with the forwarded argument a2.
