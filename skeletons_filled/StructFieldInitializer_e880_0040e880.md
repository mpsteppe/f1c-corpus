## StructFieldInitializer_e880_0040e880 — StructFieldInitializer_e880

**Summary:** Sets three struct fields: WORD at offset 0x8 from a2, DWORD at offset 0x1C to constant 7, DWORD at offset 0x20 from a3; then calls ShortComputation_e770(this, a3, 0) and returns its result.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_40FE50 (0040fe50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | RW | — | WORD field written with parameter a2 |
| this | 0x1C | RW | 7 | DWORD field set to constant 7 (mode/selector) |
| this | 0x20 | RW | — | DWORD field written with parameter a3 (pointer/identifier) |

**Written-by note (persistence):**
- this 0x8: unconditional write, value = a2 — persists
- this 0x1C: unconditional write, 7 — persists
- this 0x20: unconditional write, value = a3 — persists

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard conditions — straight-line writes, all unconditional.
