## sub_6D9DD5_006d9dd5 — send_all_trees — dynamic block header

**Summary:** Writes the dynamic-block header for a DEFLATE stream: HLIT-257 (5 bits), HDIST-1 (5 bits) and HCLEN-4 (4 bits), then the 3-bit bit-lengths of a4 code-length codes taken from bl_tree in bl_order sequence, and finally calls send_tree for the literal/length tree (a2-1 codes at state+140) and the distance tree (a3-1 codes at state+2432). Matches zlib's send_all_trees.

**Called by:** sub_6DAAC0 (006daac0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | output buffer base pointer; flushed bytes are stored at buf[byte counter] |
| this | 0x14 | R | — | output byte counter, incremented for every flushed byte |
| this | 0x16B0 | RW | — | 16-bit bit accumulator; each header field is OR-ed in and flushed as two bytes when it does not fit |
| this | 0x16B1 | R | — | high byte of the accumulator, read as the second flushed byte |
| this | 0x16B4 | RW | — | number of valid bits in the accumulator (grows by 5/5/4/3, drops by 16 or the field width on flush) |

**Written-by note (persistence):**
- this 0x16B0: rewritten continuously — OR of each header field plus flushes; an external poke is consumed by the next emitted field.
- this 0x16B4: recalculated per field (plus width, minus 16 or width on flush); an external poke changes only the base and is superseded by the next update.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00748104 | byte_748104 | R | bl_order lookup table: the transmission order of the 19 code-length codes (index -> bl_tree entry) used in the 3-bit length loop |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 006d9938 | sub_6D9938 | send_tree — emits the run-length-coded lengths of the literal/length tree (a2-1 codes, state+140) and of the distance tree (a3-1 codes, state+2432) |

**Guard conditions:** Each header field checks free accumulator bits before accumulating: bit count <= 11 for the two 5-bit counts (HLIT-257 and HDIST-1), <= 12 for the 4-bit count (HCLEN-4); if the check fails, both accumulator bytes are flushed through the 0x8 buffer/0x14 counter and the remaining bits are shifted in. The code-length loop runs for i = 0 .. a4-1, reading bl_tree[bl_order[i]].Len through byte_748104 and emitting it in 3 bits with the same <= 13 room check. a2/a3 drive the two send_tree calls (a2-1 and a3-1 nodes); a4 drives how many code-length codes are transmitted.
