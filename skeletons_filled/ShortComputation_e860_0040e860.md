## ShortComputation_e860_0040e860 — StructFieldSetter_e860

**Summary:** Writes three struct fields: WORD at offset 0x8 from parameter a2, DWORD at offset 0x1C set to constant 6, and DWORD at offset 0x20 from parameter a3. Returns a2 sign-extended.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_40FE50 (0040fe50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | RW | — | WORD field written with parameter a2 |
| this | 0x1C | RW | 6 | DWORD field set to constant 6 (mode/selector) |
| this | 0x20 | RW | — | DWORD field written with parameter a3 (pointer/identifier) |

**Written-by note (persistence):**
- this 0x8: unconditional write, value = a2 — persists
- this 0x1C: unconditional write, 6 — persists
- this 0x20: unconditional write, value = a3 — persists

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard conditions — straight-line writes, all unconditional.
