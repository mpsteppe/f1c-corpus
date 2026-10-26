## sub_54EB0F_0054eb0f — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_54EEB6 (0054eeb6)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005f47d4 | dword_5F47D4 | R | [LLM] |
| 005f47f0 | dword_5F47F0 | R | [LLM] |
| 005f4814 | aIdat | R | [LLM] |
| 005f4930 | aExtraCompresse | R | [LLM] |
| 005f4948 | aDecompressionE | R | [LLM] |
| 005f495c | aNotEnoughImage | R | [LLM] |
| 005f4974 | aInvalidAttempt | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0054e7fc | sub_54E7FC | [LLM] |
| 00550831 | sub_550831 | [LLM] |
| 00550b64 | sub_550B64 | [LLM] |
| 00550c6b | sub_550C6B | [LLM] |
| 00554a6a | sub_554A6A | [LLM] |
| 00554e6f | MemoryCopy [exact] | [LLM] |
| 00554ec3 | ByteArrayToInt [exact] | [LLM] |
| 00554ee6 | sub_554EE6 | [LLM] |
| 00554fc0 | JPEGHuffmanDecoder [exact] | [LLM] |
| 005551d6 | TextureHorizontalStretch [exact] | [LLM] |
| 0055549f | sub_55549F | [LLM] |
| 0055561a | AudioBufferSizeCalc [structural] | [LLM] |
| 005557b6 | sub_5557B6 | [LLM] |
| 00555fa7 | sub_555FA7 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `IDAT`
- `Extra compressed data`
- `Decompression error`
- `Not enough image data`
- `Invalid attempt to read row data`
