## sub_6B7BF6_006b7bf6 — Write IEND chunk and set end-of-image flag

**Summary:** Writes the "IEND" (PNG end-of-image) chunk with zero length through sub_6B7904, then sets bit 0x10 in the object's flag dword at +0x58. Terminates the PNG/image stream.

**Called by:** sub_67A14C (0067a14c)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x58 | RW | — | Flag dword; bit 0x10 OR-ed in to record that the stream was terminated (IEND written) |

**Written-by note (persistence):**
- this 0x58: OR-masked (`|= 0x10`) unconditionally on every call — sticky set, so an external poke of this bit is re-added on the next call; other bits are preserved

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00745048 | aIend_0 | R | String literal "IEND" (PNG chunk type) passed as the chunk name |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 006b7904 | sub_6B7904 | Chunk-writing composite: swap-writes the size (0 here), emits the chunk type buffer, finalizes via pointer-array cleanup, and swap-writes the object's +0x100 value |

**Guard conditions:** No branches — always writes the IEND chunk with length 0 and always sets flag bit 0x10 at this+0x58; nothing is skipped.

**String literals referenced (deterministic):**

- `IEND`
