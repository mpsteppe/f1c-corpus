## sub_4C1BF9_004c1bf9 — Conditional command-11 dispatcher with fallback

**Summary:** Queries the object's predicate helper sub_4BFDE0 with id 11; when it returns true, dispatches through the object's vtable method at slot +0x1C with argument 11, otherwise forwards the second argument to the fallback routine sub_4CC3A1.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x1C | R | — | Vtable slot (offset 28) holding the method pointer invoked as (this, 11) when the predicate passes |
| this | 0x0 | R | — | Object vtable pointer, read to resolve the method at vtable offset +0x1C |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004bfde0 | sub_4BFDE0 | Predicate/state check on the object with id 11; returns nonzero when the object can handle command 11 itself |

**Guard conditions:** `sub_4BFDE0(a1, 11)` must return nonzero. PASS: virtual method at `*a1 + 28` is called with (a1, 11). BLOCK (else): the fallback routine sub_4CC3A1 is called with the forwarded argument a2.
