## FormatStringBatchDisplay_0049e170 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_49D5D0 (0049d5d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | R | — | [LLM] |
| this | 0x14 | R | — | [LLM] |
| this | 0x68 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ccef0 | aC | R | FormatString [DERIVED] |
| 007ce6ac | dword_7CE6AC | R | [LLM] |
| 007ce6f4 | dword_7CE6F4 | R | BrakeDiffSettings [DERIVED] (also: ` to `DAT_007ce7a8` — 11 byte brake/diff settings) |
| 007ce718 | dword_7CE718 | R | FontRendererRef [DERIVED] (also: referenced by field 199) |
| 007ce73c | dword_7CE73C | R | UnknownModuleInterface [DERIVED] (also: ` — referenced but not in docs/12) |
| 007ce760 | dword_7CE760 | R | ControlMapping_Accel [DERIVED] |
| 007ce784 | dword_7CE784 | R | UITextDataReference [DERIVED] |
| 007ce7a8 | dword_7CE7A8 | R | BrakeDiffBlock [DERIVED] (also: ` — BrakeDiffSettings byte (docs/12) |
| 007ce7cc | dword_7CE7CC | R | ControlMapping_UI7 [DERIVED] |
| 007ce7f0 | dword_7CE7F0 | R | Unknown_Byte_7CE7F0 [DERIVED] |
| 007ce850 | dword_7CE850 | R | UI_RefStore_ed [DERIVED] (also: ` — stored in param_1[199]) |
| 007ce8a4 | dword_7CE8A4 | R | ConfigByte_PitSettings [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00553070 | sub_553070 | [LLM] |
| 0058815f | StringFormatWithBufferOverflowCheck | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
