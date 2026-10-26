## FilePathExtensionCheck_00414900 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_414600 (00414600), sub_414A90 (00414a90), CommentaryTVPWSPathBuilder (00414e60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | RW | 18446744073709551615 | [LLM] |
| this | 0xC | RW | 18446744073709551615 | [LLM] |
| this | 0x10 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x8: [LLM: once/conditional? does external poke survive?]
- this 0xC: [LLM: once/conditional? does external poke survive?]
- this 0x10: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005be868 | dword_5BE868 | R | StrncpyFillPattern [DERIVED] |
| 005be86c | byte_5BE86C | R | ` — 1-byte extension suffix byte [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00566650 | StringCopyWithBufferRealloc | [LLM] |
| 00587dd0 | sub_587DD0 | [LLM] |
| 0058ba36 | ToggleFileReadOnlyAttributeViaWin32API | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
