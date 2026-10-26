## ThreeFieldAccessor_0053b170 — ThreeFieldBatchGetter

**Summary:** Reads three consecutive DWORD fields from a struct (offsets 0x4, 0x8, 0xC) and writes them to caller-provided output pointers. Each output is conditionally written only if the pointer is non-null.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_558E70 (00558e70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | First data field of struct |
| this | 0x8 | R | — | Second data field of struct |
| this | 0xC | R | — | Third data field of struct |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Each output pointer (a2, a3, a4) is checked individually; if null, that corresponding field write is skipped. No early return — all three checks are independent.
