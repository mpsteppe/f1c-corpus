## TwoFieldSetter_3050_00553050 — TwoFieldSetter

**Summary:** Simple two-field setter. Writes a2 to this[23] (offset 0x5C) and a3 to this[24] (offset 0x60). Returns a2. No guards.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4988D0 (004988d0), GuardedDelegation (0053d2b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x5C | RW | — | First parameter (scale factor or position, float passed as int) |
| this | 0x60 | RW | — | Second parameter (scale factor or position, float passed as int) |

**Written-by note (persistence):**
- this 0x5C: unconditional write; survives external poke
- this 0x60: unconditional write; survives external poke

**Guard conditions:** None. Always writes both fields.
