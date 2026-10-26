## FileSettingExistenceCheck_004b8010 — FileSettingExistenceCleanup

**Summary:** Checks if a settings file exists by attempting to open it; if found, removes read-only attribute and deletes it. Part of file/settings cleanup system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GameDataFileIO (004b7300), sub_4B7500 (004b7500)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005be828 | aRb | R | FileModeRb [DERIVED] (also: ` — string comparison template) |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b9830 | sub_4B9830 | retrieves file path to check for existence |
| 00587bcf | FreeWrapper_7bcf | frees allocated path buffer |
| 00587d02 | FileCloseWithLock | closes opened file handle |
| 00587db0 | sub_587DB0 | opens file with specified mode string |
| 0058986e | FileDeleteWithErrorHandling | deletes file from disk |
| 0058ba36 | ToggleFileReadOnlyAttributeViaWin32API | removes read-only flag before deletion |

**Guard conditions:** If sub_587DB0 fails to open the file (returns 0), skips close/toggle/delete and returns true (file did not exist). Returns false if file existed and was deleted.
