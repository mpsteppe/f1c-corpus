## sub_5E4DB0_005e4db0 — get pair of values (0x7C, 0x80)

**Summary:** Small getter that copies two DWORD fields of `this` (0x7C and 0x80) into caller-supplied output pointers; both outputs are optional. No transformation — a plain accessor pair.

**Called by:** sub_4145A0 (004145a0), sub_51CC50 (0051cc50), sub_5D85D0 (005d85d0), sub_5FE3F0 (005fe3f0), sub_608270 (00608270), sub_611020 (00611020)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x7C | R | — | first value source (float index 31) copied out through a2 |
| this | 0x80 | R | — | second value source (float index 32) copied out through a3 |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Each output pointer is optional: if a2 is non-null, *a2 receives this[31] (0x7C); if a3 is non-null, *a3 receives this[32] (0x80). Null pointers are silently skipped; no early return — the function always returns a3.
