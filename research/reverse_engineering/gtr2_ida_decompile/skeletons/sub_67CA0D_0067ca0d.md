## sub_67CA0D_0067ca0d — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_67AC9B (0067ac9b)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x5C | R | — | [LLM] |
| this | 0x60 | R | — | [LLM] |
| this | 0x61 | R | — | [LLM] |
| this | 0xDC | R | — | [LLM] |
| this | 0xF4 | R | — | [LLM] |
| this | 0xF8 | R | — | [LLM] |
| this | 0x104 | R | — | [LLM] |
| this | 0x10A | R | — | [LLM] |
| this | 0x116 | R | — | [LLM] |
| this | 0x11E | R | — | [LLM] |
| this | 0x12C | R | — | [LLM] |
| this | 0x138 | R | — | [LLM] |
| this | 0x144 | R | — | [LLM] |
| this | 0x15C | R | — | [LLM] |
| this | 0x174 | R | — | [LLM] |
| this | 0x178 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0073cbd8 | aPngDoDitherRet | R | [LLM] |
| 0073cbfc | aNullRowBuffer | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00679f05 | GuardedCallWithLongjmp [structural] | [LLM] |
| 0067b4ef | sub_67B4EF | [LLM] |
| 0067b522 | sub_67B522 | [LLM] |
| 0067b719 | BitPackingUnpacking [structural] | [LLM] |
| 0067b82c | sub_67B82C | [LLM] |
| 0067b9aa | BitExpandDecompress [structural] | [LLM] |
| 0067b9f4 | sub_67B9F4 | [LLM] |
| 0067bc29 | sub_67BC29 | [LLM] |
| 0067bf7b | sub_67BF7B | [LLM] |
| 0067c186 | BitmapDecompression [structural] | [LLM] |
| 0067c4df | sub_67C4DF | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x61 | < | 0 | [LLM] |
| this | 0xF8 | == | 3 | [LLM] |
| this | 0x116 | != | 3 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `NULL row buffer`
