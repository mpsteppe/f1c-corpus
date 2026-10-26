## sub_6B88CC_006b88cc — Emit 16-bit big-endian value to output buffer

**Summary:** Writes a 16-bit value big-endian (high byte then low byte) into the object's output buffer and advances the write cursor by two. Low-level byte emitter used by the compression step (sub_6B8942).

**Called by:** sub_6B8942 (006b8942)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | Base pointer of the output buffer being written |
| this | 0x14 | R | — | Byte cursor/position within the buffer — read, incremented by 1 for each byte written |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No branches — always writes both bytes (HIBYTE then LOBYTE of a2) at the cursor and leaves the cursor advanced by 2; nothing is checked or skipped.
