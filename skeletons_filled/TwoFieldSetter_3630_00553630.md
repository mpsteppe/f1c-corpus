## TwoFieldSetter_3630_00553630 — TwoFieldSetter

**Summary:** Simple two-field setter. Writes a2 to this[2] (offset 0x8) and a3 to this[3] (offset 0xC). Returns a2. No guards.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ObjectConstructorWithAllocationAndSubInit (00553980)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | RW | — | First parameter (position/offset value) |
| this | 0xC | RW | — | Second parameter (position/offset value) |

**Written-by note (persistence):**
- this 0x8: unconditional write; survives external poke
- this 0xC: unconditional write; survives external poke

**Guard conditions:** None. Always writes both fields.
