## PlayerNameSetup_004326e0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DynMan_Init (0042c1a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(*(obj+0x20)+0x4)+0x0) | 0x0 | R | — | [LLM] |
| *(*(obj+0x20)+0x4) | 0x0 | R | — | [LLM] |
| *(*(obj+0x20)+0x4) | 0x4 | R | — | [LLM] |
| obj | 0x20 | R | — | [LLM] |
| obj | 0x2C | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec4c0 | byte_5EC4C0 | R | EmptyStringBuffer [DERIVED] |
| 005ec4cc | byte_5EC4CC | RW | MessageDisplayBuffer [DERIVED] (also: ` (byte_5EC4CC) |
| 007ce5ec | dword_7CE5EC | R | SettingsFilePath [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00423a00 | BinarySearchInStringTable | [LLM] |
| 00432180 | SettingsSetupFileRead | [LLM] |
| 00432220 | SettingsCopySetupFileCopy | [LLM] |
| 004326a0 | SettingsFolderResolver | [LLM] |
| 004326d0 | Wrapper | [LLM] |
| 00432980 | PathNormalizerFileEnumeration | [LLM] |
| 00566650 | StringCopyWithBufferRealloc | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |
| 00588410 | sub_588410 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
