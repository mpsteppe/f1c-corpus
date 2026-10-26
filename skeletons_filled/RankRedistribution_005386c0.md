## RankRedistribution_005386c0 — Huffman code length limiter

**Summary:** Enforces maximum Huffman code length constraint (length limiting). Redistributes tree depths by decrementing overflowed length counts and reassigning reduced depths to symbols while updating bit cost accumulators. Ensures Huffman codes fit within deflate's 15-bit max length constraint.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_5383D0 (005383d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | frequency table base (a2[0]) |
| this | 0x4 | R | — | max literal index (a2[1]) |
| this | 0x8 | R | — | tree state block pointer (a2[2]) |
| this | 0xC | R | — | secondary state pointer (a2[3]) |
| this | 0x10 | R | — | extra bits pointer (a2[4]) |
| this | 0x18 | R | — | max code length limit v23 (a2[6]) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Main body skipped when tree node index (a1+5194)+1 >= 573 (no overflow to process). Overflow detection: when computed depth v9 exceeds limit v23, increments overflow counter v6 and clamps depth to limit. After main pass, if overflow count v6 > 0, redistributes by finding shorter depths (scanning from max_length-1 downward) and reassigning overflow count in pairs to next-shorter depth. Final pass walks tree nodes to reassign any symbol with depth > max_length down to max_length.
