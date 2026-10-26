## HuffmanBitStreamEncoder_005381f0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DecompressionBufferFlush (00536300), ZlibInflateDecompressionCore (005365d0), InflateDecompressionLoop (00536a70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005b7e00 | unk_5B7E00 | R | ZlibTreeTable [DERIVED] |
| 005b8280 | unk_5B8280 | R | InflateState_5B8280 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00537ec0 | ScorecardZero | [LLM] |
| 00537f30 | BitstreamWriteBits | [LLM] |
| 005383d0 | sub_5383D0 | [LLM] |
| 00538940 | PerformanceSectorTimeAccumulator | [LLM] |
| 00538a90 | BitBufferWriter | [LLM] |
| 00539200 | HuffmanBitStreamDecoder | [LLM] |
| 00539600 | BufferChecksumValidator | [LLM] |
| 00539720 | UnicodeBufferFlusher | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
