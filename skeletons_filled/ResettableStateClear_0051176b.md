## ResettableStateClear_0051176b — Reset two state fields to zero

**Summary:** Clears two fields (offsets 0x14 and 0x6C) in a struct pointed to by `*this` back to zero, performing a partial state reset.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x14 | RW | 0 | state/counter field, reset to 0 |
| obj | 0x6C | RW | 0 | state/reference field, reset to 0 |
| this | 0x0 | R | — | pointer to the state struct |

**Written-by note (persistence):**
- obj 0x14: unconditionally written to 0 each call; external poke clears until next write
- obj 0x6C: unconditionally written to 0 each call; external poke clears until next write

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — always writes both fields unconditionally, no branches.
