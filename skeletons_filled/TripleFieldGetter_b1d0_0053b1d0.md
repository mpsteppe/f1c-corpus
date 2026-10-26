## TripleFieldGetter_b1d0_0053b1d0 — TripleFieldBatchGetter_1C_20_24

**Summary:** Reads three consecutive DWORD fields from a struct (offsets 0x1C, 0x20, 0x24) and writes them to caller-provided output pointers. Each output is conditionally written only if the pointer is non-null.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_558E70 (00558e70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1C | R | — | Fourth consecutive data field of struct |
| this | 0x20 | R | — | Fifth consecutive data field of struct |
| this | 0x24 | R | — | Sixth consecutive data field of struct |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Each output pointer (a2, a3, a4) is checked individually; if null, that corresponding field write is skipped. No early return — all three checks are independent.
