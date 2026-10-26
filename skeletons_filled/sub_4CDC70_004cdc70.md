## sub_4CDC70_004cdc70 — TrackSurfaceTokenToFloat

**Summary:** Parses a track surface material token string and converts to a float value. If the token is numeric (digit or '.'), parses directly as float. Otherwise, searches a linked list of named entries for a matching string and returns its associated float value. Logs a debug message on lookup failure.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** TrackSurfaceMaterialLoader (004cdd80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d3624 | aDDevF119992002_25 | R | SourcePath_25 [DERIVED] |
| 005d37e8 | aCouldNotFindTr | R | Str_CouldNotFindTr [DERIVED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d7a50 | StringSplitLoop | conditional debug string split for error tracing |
| 004d7aa0 | DebugLogWrite | write debug log message on lookup failure |
| 00565520 | sub_565520 | read string token from input (INI-like token parsing) |
| 0058850f | sub_58850F | convert string to float value (atof-like) |

**Guard conditions:** If first character is digit (48-57) or '.' (46) → parse as float directly. Else if a4 (linked list head) is non-null → walk linked list via offset 0x20 for next, compare names via strcmp, return float at offset 0x20 + 12 (0x32?) — actually looking at the code: v6 starts at a4, walks via *(_DWORD *)(v6 + 36), and returns *(float *)(v6 + 32). If not found or a4 is null → log debug error and return 0.
