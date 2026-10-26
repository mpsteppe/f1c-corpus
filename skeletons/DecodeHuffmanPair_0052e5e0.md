## DecodeHuffmanPair_0052e5e0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CompressedAudioDecoder (0052e6f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x24A4 | R | — | [LLM] |
| this | 0x24A8 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x24A8: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005b4788 | dword_5B4788 | R | HuffmanDecodeTable [DERIVED] |
| 005b4820 | dword_5B4820 | R | HashTableMask [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
