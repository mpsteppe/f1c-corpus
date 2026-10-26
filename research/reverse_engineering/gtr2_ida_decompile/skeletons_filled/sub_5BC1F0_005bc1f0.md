## sub_5BC1F0_005bc1f0 — per-item virtual callback sweep with time argument

**Summary:** Iterates the collection held by the object (count at `this+0x1BC`, pointer array at `this+0x1C4`) and, for each element, checks the current index `this+0x21C` against two per-element arrays (offsets +0x12C/+0x134 and +0x144/+0x14C) and, when an entry exists and its predicate virtual method (vtable +12) returns non-zero, invokes the entry's virtual method at vtable +4 with `(this, element, *a2)` — a double time/value argument split across two dword slots.

**Called by:** sub_5BD390 (005bd390)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1BC | R | — | Element count of the swept collection (`this[111]`); bounds the loop. |
| this | 0x1C4 | R | — | Pointer to the array of element pointers (`this[113]`); indexed as `this[113] + 4*v4`. |
| this | 0x21C | R | — | Current index/state (`this[135]`), compared against each element's per-array counts before selecting the callback entry. |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Loop runs for `v4 < this[111]`. Per element: first block executes only when `this[135] < v5[75]` (and the entry pointer from `v5[77]` is non-null and its virtual +12 predicate returns non-zero); otherwise skipped. Second block repeats the pattern with `this[135] < v5[81]` and `v5[83]`. Entry pointers that fail the vtable +12 predicate (returns 0) block the callback invocation. No value comparisons beyond these index bounds and null/predicate tests.
