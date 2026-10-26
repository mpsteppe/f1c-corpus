## sub_5BCCE0_005bcce0 — Destroy 8-byte element array

**Summary:** Container cleanup: iterates this[0] (count) elements in the array at this[2] (offset 0x8), calling each element's first-vtable-slot method (pointer at element+0) with argument 0, then runs sub_4F14D0 and frees the array via sub_5A8D10. Matches the 8-byte records initialized by sub_5BC540.

**Called by:** sub_5C0B97 (005c0b97)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | element count of the array |
| this | 0x8 | R | — | base pointer of the 8-byte-element array; passed to sub_5A8D10 for release |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004f14d0 | sub_4F14D0 | cleanup helper invoked after the per-element pass (argument lost by the decompiler — register-passed) |
| 005a8d10 | sub_5A8D10 | frees/releases the element array at this+0x8 |

**Guard conditions:** loop runs while i < this[0]; zero count → per-element virtual calls skipped, cleanup and array free still execute. No other branches.
