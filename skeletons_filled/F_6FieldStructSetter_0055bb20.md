## F_6FieldStructSetter_0055bb20 — SixFieldStructWrite

**Summary:** Writes 6 integer/pointer parameters into consecutive DWORD fields (offsets 0x4 through 0x18) of a struct. Returns 0. Generic struct field setter for linked list nodes.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_55BC00 (0055bc00)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | RW | — | Field 1 — user-defined (varies by context) |
| this | 0x8 | RW | — | Field 2 — user-defined |
| this | 0xC | RW | — | Field 3 — user-defined |
| this | 0x10 | RW | — | Field 4 — user-defined |
| this | 0x14 | RW | — | Field 5 — user-defined (node type identifier) |
| this | 0x18 | RW | — | Field 6 — user-defined |

**Written-by note (persistence):**
- this 0x4: unconditional write each call. External poke survives.
- this 0x8: unconditional write each call. External poke survives.
- this 0xC: unconditional write each call. External poke survives.
- this 0x10: unconditional write each call. External poke survives.
- this 0x14: unconditional write each call. External poke survives.
- this 0x18: unconditional write each call. External poke survives.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — all 6 fields written unconditionally. Returns 0 always.
