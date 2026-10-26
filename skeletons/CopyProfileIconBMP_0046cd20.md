## CopyProfileIconBMP_0046cd20 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xE4 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e19c | CopyFileA | R | [LLM] |
| 005c6658 | lpExistingFileName | R | sProfileIconBmp [DERIVED] |
| 005c6950 | aProfileiconBmp | R | ProfileIconBmpStr [DERIVED] (also: ` — "ProfileIcon.bmp" string) |
| 005c6954 | byte_5C6954 | R | StrProfileIconBmp [DERIVED] |
| 005c6958 | byte_5C6958 | R | StrProfileIconBMP [DERIVED] |
| 005c695c | byte_5C695C | R | String_ProfileIconBmp [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 007cd8c0 | dword_7CD8C0 | R | GameCommandDispatchInterface [DERIVED] (also: ` — game command dispatch interface pointer) |
| 007ce498 | byte_7CE498 | R | AutoLoadConfigFile [DERIVED] |
| 007ce630 | dword_7CE630 | R | ProfileIconPath_ptr [DERIVED] |
| 007ce64c | dword_7CE64C | R | GameFilterDataPath [DERIVED] |
| 007ce684 | dword_7CE684 | R | NationalityDataPath [DERIVED] (also: ` — nationality data pointer) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00477640 | SeasonSceneNameAccessor | [LLM] |
| 00477680 | TrackSceneConfigLoader | [LLM] |
| 00497ad0 | sub_497AD0 | [LLM] |
| 00497c40 | LinkedListNodeRemovalByStringKey | [LLM] |
| 004b0220 | PathTruncationUtility | [LLM] |
| 004b0770 | sub_4B0770 | [LLM] |
| 004b1410 | NameCompareAndFormat | [LLM] |
| 00566650 | StringCopyWithBufferRealloc | [LLM] |
| 00568540 | FileAttributesExistenceCheck | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
