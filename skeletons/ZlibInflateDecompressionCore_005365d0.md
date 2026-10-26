## ZlibInflateDecompressionCore_005365d0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005b82f8 | byte_5B82F8 | R | Zlib_DistanceBaseTable [DERIVED] |
| 005b83f8 | byte_5B83F8 | R | zlib_LengthExtraBits [DERIVED] |
| 005b84f8 | byte_5B84F8 | R | ZLibLengthTable [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00536160 | BufferCopyWithSizeTracking | [LLM] |
| 00536440 | TextBufferDecompressor | [LLM] |
| 00536900 | ZlibDeflateLongestMatch | [LLM] |
| 005381f0 | HuffmanBitStreamEncoder | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
