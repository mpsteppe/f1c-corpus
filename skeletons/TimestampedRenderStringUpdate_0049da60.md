## TimestampedRenderStringUpdate_0049da60 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_49D5D0 (0049d5d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | [LLM] |
| this | 0x14 | R | — | [LLM] |
| this | 0x68 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ccbb8 | dword_5CCBB8 | R | UITextLayoutBaseY [DERIVED] |
| 005ccbbc | dword_5CCBBC | R | UISectionOffsetStride [DERIVED] |
| 005ccbc0 | dword_5CCBC0 | R | TextureSurfaceRef1 [DERIVED] |
| 007ce048 | dword_7CE048 | R | RaceSessionState [DERIVED] (also: ` (dword_7CE048) |
| 007ce234 | unk_7CE234 | R | DriverAppearanceFlag [DERIVED] |
| 007ce238 | dword_7CE238 | R | TextDataBatchSource [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0049c8f0 | sub_49C8F0 | [LLM] |
| 0049c960 | sub_49C960 | [LLM] |
| 0049e410 | DualTextDisplay | [LLM] |
| 0049f6a0 | StringFormatAndRender | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
