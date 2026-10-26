## NameCompareAndFormat_004b1410 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SessionConfigWriteback (00461900), CopyProfileIconBMP (0046cd20), TrackConfigurationNameBuilder (004b16b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1F9C | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005be860 | aSS | R | PathFormatString [DERIVED] (also: ` â€” format string for path construction) |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec3d8 | dword_5EC3D8 | R | SeasonDir [DERIVED] |
| 008ad3b4 | dword_8AD3B4 | R | GameDataDir [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b0720 | F_5StepInit | [LLM] |
| 004b0930 | SettingsFileInit | [LLM] |
| 00566650 | StringCopyWithBufferRealloc | [LLM] |
| 00567f40 | AudioFileLoadDecode | [LLM] |
| 005684a0 | ObjectIDLookupAcross9Arrays | [LLM] |
| 00588410 | sub_588410 | [LLM] |
| 0058969d | StringFormatProcessingWithNullTerm | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
