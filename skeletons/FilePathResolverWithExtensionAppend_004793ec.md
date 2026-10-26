## FilePathResolverWithExtensionAppend_004793ec — [LLM: short descriptive name]

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
| 005c7190 | dword_5C7190 | R | FileExtensionMagic [DERIVED] |
| 005c7194 | word_5C7194 | R | TrackExtMagic [DERIVED] |
| 005c7196 | byte_5C7196 | R | FileExtSepByte [DERIVED] |
| 005c71c0 | dword_5C71C0 | R | FileExtensionDword [DERIVED] |
| 005c71c4 | dword_5C71C4 | R | TrackNameSuffix [DERIVED] |
| 005c71c8 | byte_5C71C8 | R | Byte_FileExtension [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 007cd618 | unk_7CD618 | R | FilePathBuffer_7CD618 [DERIVED] |
| 007cd717 | byte_7CD717 | W | FileCopied_Flag [DERIVED] |
| 007cd718 | byte_7CD718 | R | FileDialog_SelectedPath [DERIVED] |
| 007cd817 | byte_7CD817 | W | FilePathNullTerminator [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00478e80 | SingleCallWrapper_8e80 | [LLM] |
| 00479170 | sub_479170 | [LLM] |
| 00497ad0 | sub_497AD0 | [LLM] |
| 00566650 | StringCopyWithBufferRealloc | [LLM] |
| 00587dd0 | sub_587DD0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
