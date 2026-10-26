## MP3AudioDecoderHuffmanSampleRendering_00530050 — Huffman sample render to float buffer

**Summary:** Renders Huffman-decoded audio samples into float output buffer. Iterates over subbands and samples, reads codebook selectors, Huffman-decodes bitstream data, applies DCT coefficients and scale factors, writes 3 interleaved float samples per iteration. Zero-fills unused output slots based on subband count and stereo flag.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** TextureDecompression_1250 (00531250)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x24A4 | R | — | input bitstream buffer pointer (this[2345]) |
| this | 0x24A8 | RW | — | bitstream bit-offset cursor (this[2346]), advances per Huffman read |
| this | 0x24B8 | R | — | subband/granule count (this[2350]), loop bound |
| this | 0x24CC | R | — | samples per subband / channels (this[2355]), loop bound and stereo flag |

**Written-by note (persistence):**
- this 0x24A8: updated per Huffman symbol read; cursor advances through input bitstream

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0053073c | jpt_5302EF | R | jump table for switch/case dispatch |
| 005307bc | jpt_5304EA | R | jump table for switch/case dispatch |
| 005b10a4 | flt_5B10A4 | R | DCTDecodeTable [DERIVED] — cosine/MDCT coefficient lookup table |
| 005b4788 | dword_5B4788 | R | HuffmanDecodeTable [DERIVED] |
| 005da738 | dword_5DA738 | R | AnimationWeightScale [DERIVED] — Huffman scale factor offset table |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x24B8 | > | 0 | subband count (this[2350]) |
| this | 0x24CC | > | 0 | samples per subband (this[2355]) |

**Guard interpretation:** Outer loop iterates while v24 < this[2350]; if this[2350] <= 0, entire decoding loop is skipped and only zero-fill switch executes. Inner loop iterates while v23 < this[2355]; if this[2355] <= 0, inner per-sample decode is skipped. After loops, a second switch block conditionally zeros output slots a3[0..31], a3[32..63], a3[64..95], and a3[96..127], a3[128..159] only when this[2355] == 2 (stereo mode).
