## sub_5E4DD0_005e4dd0 — get pair of values (0x24, 0x28)

**Summary:** Small getter that copies two DWORD fields of `this` (0x24 and 0x28) into caller-supplied output pointers; both outputs are optional. Same shape as sub_5E4DB0 with a different field pair.

**Called by:** sub_40E950 (0040e950), sub_411100 (00411100), sub_51CC50 (0051cc50), sub_60E3E0 (0060e3e0), sub_60E820 (0060e820), sub_60E9B0 (0060e9b0), sub_6103F0 (006103f0), sub_611020 (00611020)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x24 | R | — | first value source (DWORD index 9) copied out through a2 |
| this | 0x28 | R | — | second value source (DWORD index 10) copied out through a3 |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Each output pointer is optional: if a2 is non-null, *a2 receives this[9] (0x24); if a3 is non-null, *a3 receives this[10] (0x28). Null pointers are silently skipped; no early return — the function always returns a3.
