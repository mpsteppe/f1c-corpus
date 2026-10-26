## sub_4C1AD3_004c1ad3 — Conditional command-8 dispatcher with fallback

**Summary:** Queries the object's predicate helper sub_4BFDE0 with id 8; when it returns true, dispatches through the object's vtable method at slot +0x1C with argument 8, otherwise forwards the second argument to the fallback routine sub_4CC3A1.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x1C | R | — | Vtable slot (offset 28) holding the method pointer invoked as (this, 8) when the predicate passes |
| this | 0x0 | R | — | Object vtable pointer, read to resolve the method at vtable offset +0x1C |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004bfde0 | sub_4BFDE0 | Predicate/state check on the object with id 8; returns nonzero when the object can handle command 8 itself |

**Guard conditions:** `sub_4BFDE0(a1, 8)` must return nonzero. PASS: virtual method at `*a1 + 28` is called with (a1, 8). BLOCK (else): the fallback routine sub_4CC3A1 is called with the forwarded argument a2.
