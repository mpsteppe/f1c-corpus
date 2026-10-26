## SettingsSetupFileRead_00432180 — SettingsFilePathResolver

**Summary:** Builds a settings file directory path by composing base path with a subdirectory component, then enumerates files in that directory. Used during settings/player name setup to locate configuration files.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PlayerNameSetup (004326e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | String pointer passed to DirectoryFileEnumerator as search path |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c2aac | word_5C2AAC | R | BackslashChar [DERIVED] (also: ` — backslash character (docs/08 path_util.cpp) |
| 005c3fa0 | off_5C3FA0 | R | Unknown_Off_5C3FA0 [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 007ce498 | byte_7CE498 | R | AutoLoadConfigFile [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00431db0 | DirectoryFileEnumerator | Enumerates files in a given directory matching a pattern |
| 004b0220 | PathTruncationUtility | Sanitizes/truncates a path string to safe length |
| 00566650 | StringCopyWithBufferRealloc | Copies a string with automatic buffer reallocation |

**Guard conditions:** None — unconditional path building and file enumeration. Always returns 1.
