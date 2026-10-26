## MaskedFieldSetter_00552fd0 — MaskedFieldSetter

**Summary:** Writes masked flag values to two fields. Stores (a2 & 0x20) to this[19] (offset 0x4C) and (a3 & 0xC0) to this[20] (offset 0x50). Returns the masked a2 value.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4D8AB0 (004d8ab0), FontSurfaceLookupDispatch (0053d260)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4C | RW | — | Flags/state field storing bit 5 of a2 (texture coordinate mode or clamp flag) |
| this | 0x50 | RW | — | Flags/state field storing bits 6-7 of a3 (filter/blend mode flags) |

**Written-by note (persistence):**
- this 0x4C: written with masked bit 0x20; survives external poke
- this 0x50: written with masked bits 0xC0; survives external poke

**Guard conditions:** None. Always writes both masked values.
