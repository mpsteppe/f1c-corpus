## PlayerNameNeverUsedProfileFileCreateRead_004b03f0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ProfileAlreadyExistsPageHandler (0046cb50), sub_485B90 (00485b90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x49A8 | RW | 1 | [LLM] |
| this | 0x49A9 | RW | 1 | [LLM] |

**Written-by note (persistence):**
- this 0x49A8: [LLM: once/conditional? does external poke survive?]
- this 0x49A9: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005be860 | aSS | R | PathFormatString [DERIVED] (also: ` â€” format string for path construction) |
| 005c6970 | aPlayernameneve | R | Str_UI_PlayerNameNever [DERIVED] |
| 005cc1f4 | aPlr | R | StringSuffixDword [DERIVED] (also: � Suffix dword) |
| 005d1ff0 | off_5D1FF0 | R | VTable_FUN_004b03f0 [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec440 | dword_5EC440 | R | SettingsDirectory [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b03f0 | PlayerNameNeverUsedProfileFileCreateRead | [LLM] |
| 004b04e0 | StringCopyFileCheckDispatch | [LLM] |
| 004b09a0 | TextFileReader | [LLM] |
| 00565dc0 | AllocateStructWithDefaultValues | [LLM] |
| 00565e20 | LinkedListDestructorWithChildCleanup | [LLM] |
| 00565f80 | sub_565F80 | [LLM] |
| 005662d0 | DirectoryEntryIterator | [LLM] |
| 00566380 | sub_566380 | [LLM] |
| 0058815f | StringFormatWithBufferOverflowCheck | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
