## FileFinder_004c40d0 — FileFinder

**Summary:** Searches for a file across multiple paths (custom path, season directory, common directory), opens it if found and copies the path; logs a debug message if not found in any location.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehFileParser (004c3200), TheSvmHdvVehicleFileParser (004f4270)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005be860 | aSS | R | PathFormatString [DERIVED] (also: ` â€” format string for path construction) |
| 005beb48 | word_5BEB48 | R | PathSepWord [DERIVED] |
| 005c36f0 | aR | R | Token_R [DERIVED] |
| 005c6784 | aSSS_0 | R | sFormatPath [DERIVED] |
| 005d3044 | aDDevF119992002_8 | R | StringDevF119992002_8 [DERIVED] |
| 005d30a0 | aCouldNotFindS | R | CouldNotFindStr [DERIVED] |
| 005d30b4 | aScommonS | R | SCommonSString [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec3d8 | dword_5EC3D8 | R | SeasonDir [DERIVED] |
| 005ec428 | dword_5EC428 | R | SeasonName [DERIVED] |
| 007c569c | dword_7C569C | R | SessionType5 (5=server) [DERIVED] (also: ` — SessionType5 (guards dev logging) |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d7a50 | StringSplitLoop | string splitting for debug message |
| 004d7aa0 | DebugLogWrite | write debug log entry |
| 00566650 | StringCopyWithBufferRealloc | copy resulting file path with buffer reallocation |
| 00587c20 | sub_587C20 | check if path ends with path separator |
| 00587d02 | FileCloseWithLock | close opened file handle |
| 00587db0 | sub_587DB0 | attempt to open file for reading |
| 0058815f | StringFormatWithBufferOverflowCheck | format path strings for search |

**Guard conditions:** If sub_587C20 determines a1 doesn't end with path separator, appends a2 (file name) to a1. Then tries up to 3 path combinations. If any succeeds, closes the file, copies the path, and returns 0. If all fail: logs "Could not find" debug message (unless server mode) and returns -1.
