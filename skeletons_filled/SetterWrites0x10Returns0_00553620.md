## SetterWrites0x10Returns0_00553620 — SetterWrites0x10Returns0

**Summary:** Writes parameter a2 to this[4] (offset 0x10) and returns 0. No guards.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4D8CF0 (004d8cf0), ObjectConstructorWithAllocationAndSubInit (00553980)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x10 | RW | — | Render state parameter (vertex buffer pointer or state value) |

**Written-by note (persistence):**
- this 0x10: unconditional write; survives external poke

**Guard conditions:** None. Always writes a2 to field and returns 0.
