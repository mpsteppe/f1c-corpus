## SetupFileLoadAndFinalize_00469630 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PlayerProfileScanner (00468ee0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x40) | 0x1C | R | — | [LLM] |
| this | 0x40 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005be860 | aSS | R | PathFormatString [DERIVED] (also: ` â€” format string for path construction) |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec3d8 | dword_5EC3D8 | R | SeasonDir [DERIVED] |
| 007ce498 | byte_7CE498 | R | AutoLoadConfigFile [DERIVED] |
| 007d0434 | dword_7D0434 | R | SeasonPath [DERIVED] |
| 008ad3b4 | dword_8AD3B4 | R | GameDataDir [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004693e0 | FilenameFromLinkedList | [LLM] |
| 00470190 | sub_470190 | [LLM] |
| 0048d360 | GuardedAccessor | [LLM] |
| 004b04e0 | StringCopyFileCheckDispatch | [LLM] |
| 00566650 | StringCopyWithBufferRealloc | [LLM] |
| 00567f40 | AudioFileLoadDecode | [LLM] |
| 005684a0 | ObjectIDLookupAcross9Arrays | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |
| 0058969d | StringFormatProcessingWithNullTerm | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
