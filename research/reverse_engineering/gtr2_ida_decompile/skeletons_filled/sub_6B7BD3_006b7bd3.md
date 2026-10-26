## sub_6B7BD3_006b7bd3 — Write IDAT chunk and set image-data flag

**Summary:** Writes an "IDAT" (PNG image data) chunk through sub_6B7904, then sets bit 0x4 in the object's flag dword at +0x58 to mark that image data has been emitted. Part of the PNG/image stream writer.

**Called by:** sub_67A35B (0067a35b), sub_6B7C17 (006b7c17), sub_6B7D98 (006b7d98)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x58 | RW | — | Flag dword; bit 0x4 OR-ed in to record that an IDAT chunk was written |

**Written-by note (persistence):**
- this 0x58: OR-masked (`|= 4`) unconditionally on every call — sticky set, so an external poke of this bit is re-added on the next call; other bits are preserved

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00745040 | aIdat_0 | R | String literal "IDAT" (PNG chunk type) passed as the chunk name |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 006b7904 | sub_6B7904 | Chunk-writing composite: swap-writes the size, emits the chunk type buffer, finalizes via pointer-array cleanup, and swap-writes the object's +0x100 value |

**Guard conditions:** No branches — always writes the IDAT chunk and always sets flag bit 0x4 at this+0x58; nothing is skipped.

**String literals referenced (deterministic):**

- `IDAT`
