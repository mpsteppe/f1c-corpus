## CopyProfileIconBMP_0046cd20 — ProfileIconBmpCopy

**Summary:** Copies ProfileIcon.bmp file from source path to destination, then triggers game state reload. Builds destination path from this[57] or default directory, appends "ProfileIcon.bmp", verifies source file exists via sub_497AD0, copies with CopyFileA, then dispatches game commands (17, 45) to reload scene/track configuration.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xE4 | R | — | source directory path pointer (this[57]) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e19c | CopyFileA | R | Windows CopyFileA import |
| 005c6658 | lpExistingFileName | R | sProfileIconBmp [DERIVED] — source icon path buffer |
| 005c6950 | aProfileiconBmp | R | ProfileIconBmpStr [DERIVED] — "ProfileIcon.bmp" string literal |
| 005c6954 | byte_5C6954 | R | StrProfileIconBmp [DERIVED] |
| 005c6958 | byte_5C6958 | R | StrProfileIconBMP [DERIVED] |
| 005c695c | byte_5C695C | R | String_ProfileIconBmp [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] — default fallback directory |
| 007cd8c0 | dword_7CD8C0 | R | GameCommandDispatchInterface [DERIVED] — game command dispatch interface |
| 007ce498 | byte_7CE498 | R | AutoLoadConfigFile [DERIVED] |
| 007ce630 | dword_7CE630 | R | ProfileIconPath_ptr [DERIVED] |
| 007ce64c | dword_7CE64C | R | GameFilterDataPath [DERIVED] |
| 007ce684 | dword_7CE684 | R | NationalityDataPath [DERIVED] — nationality data pointer (for filename stripping) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00477640 | SeasonSceneNameAccessor | accesses scene name after game command dispatch |
| 00477680 | TrackSceneConfigLoader | loads track/scene configuration after copy |
| 00497ad0 | sub_497AD0 | checks if source icon file exists |
| 00497c40 | LinkedListNodeRemovalByStringKey | removes existing linked list entry for destination path |
| 004b0220 | PathTruncationUtility | truncates/cleans destination path buffer |
| 004b0770 | sub_4B0770 | post-copy cleanup/refresh with parameter 0 |
| 004b1410 | NameCompareAndFormat | normalizes source path name format |
| 00566650 | StringCopyWithBufferRealloc | copies string with buffer reallocation |
| 00568540 | FileAttributesExistenceCheck | checks if destination file exists |
| 00587bcf | FreeWrapper_7bcf | frees allocated memory |

**Guard conditions:** sub_497AD0(lpExistingFileName, 0) returns non-null → source file exists, proceeds with copy. BLOCKED if null → skips file copy. Inner: v6 (filename pointer after backslash search) non-null → proceeds with filename processing.
