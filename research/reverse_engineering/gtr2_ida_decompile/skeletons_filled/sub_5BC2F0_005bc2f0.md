## sub_5BC2F0_005bc2f0 — broadcast float update to each element passing the sub_5BFC80 predicate

**Summary:** Loops over the collection (count at `this+0x1C8`, array at `this+0x1D0`); for every element for which sub_5BFC80 returns non-zero, calls the element's virtual method at vtable +4 with the incoming double truncated to a float. A per-element tick/update broadcast guarded by that predicate.

**Called by:** sub_5BD390 (005bd390)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1C8 | R | — | Element count (`this[114]`); bounds the loop. |
| this | 0x1D0 | R | — | Pointer to the element-pointer array (`this[116]`); indexed as `this[116] + 4*i`. |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005bfc80 | sub_5BFC80 | Predicate on an element pointer returning a byte; non-zero means the element should receive the update. |

**Guard conditions:** Per element: only when `sub_5BFC80(v5)` returns non-zero is the virtual callback invoked (`(*v5 + 4)(v5, (float)a2)`); a zero result blocks the call and the loop continues. Loop itself bounded by `i < this[114]`.
