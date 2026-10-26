## PerformanceSectorTimeAccumulator_00538940 — Huffman tree cost estimator

**Summary:** Computes bit cost overhead for encoding the Huffman tree itself in deflate. Calls RunLengthAnalyzer on length+distance tree frequency tables, builds encoding tree via sub_5383D0, then scans code length frequencies to determine the tree description size (3*result + 17 bits). Accumulates total bit cost in this+5787.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** HuffmanBitStreamEncoder (005381f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xB12 | R | — | length tree frequency table pointer (this+2834) |
| this | 0xB1E | R | — | distance tree frequency table pointer (this+2846) |
| this | 0x169B | RW | — | bit cost accumulator (this+5787), incremented by tree encoding overhead |

**Written-by note (persistence):**
- this 0x169B: incremented by tree description cost each call; accumulates total block bit budget

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005b7dec | byte_5B7DEC | R | EncodeLookupTable [DERIVED] — code length alphabet ordering (18..3) for tree scan |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005383d0 | sub_5383D0 | build Huffman tree for code length encoding table |
| 005389b0 | RunLengthAnalyzer | analyze run-length frequencies of code length sequences |

**Guard conditions:** For loop scans from 18 down to 3, breaks when a non-zero code length frequency is found at this+4*byte_5B7DEC[result]+2676. If all zero, result = 3 (minimum tree description size).
