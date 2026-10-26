## BufferChecksumValidator_00539600 — Frequency table ratio check

**Summary:** Validates Huffman frequency distribution by summing word counts from three table ranges (literal/length/distance frequency tables). Checks if total code length frequency sum (v2) is within ratio of distance table sum (v1>>2). Sets status byte at this+28 (offset 0x1C) to indicate valid/invalid ratio. Used for deflate block validation.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** HuffmanBitStreamEncoder (005381f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1C | RW | — | validation result byte (this+28), set to 0/1 based on ratio check |
| this | 0x8A | R | — | start of first frequency sum range (this+69, 7 entries at stride 2) |
| this | 0xA6 | R | — | start of second frequency sum range (this+83, 121 entries at stride 2) |
| this | 0x28A | R | — | start of third frequency sum range (this+325, 128 entries at stride 2) |

**Written-by note (persistence):**
- this 0x1C: written with validation result each call; persists until next check

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No branches except final comparison. Sums all entries unconditionally. Result: v2 <= (v1 >> 2) means valid (sets byte at offset 0x1C to 1).
