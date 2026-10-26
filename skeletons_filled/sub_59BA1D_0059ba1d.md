## sub_59BA1D_0059ba1d — SetPerDriveCurrentDir

**Summary:** Sets the per-drive current directory environment variable (e.g., "=C:") by changing to the specified path, retrieving the full directory, and calling SetEnvironmentVariableA; skips UNC paths.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_565F80 (00565f80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e0b0 | SetEnvironmentVariableA | R | Import: SetEnvironmentVariableA kernel32 API |
| 0059e188 | GetLastError | R | Import: GetLastError kernel32 API |
| 0059e1b0 | GetCurrentDirectoryA | R | Import: GetCurrentDirectoryA kernel32 API |
| 0059e20c | SetCurrentDirectoryA | R | Import: SetCurrentDirectoryA kernel32 API |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058af5c | ErrorIDLookupTable | Raise error for GetLastError code |
| 0059c0ac | sub_59C0AC | Convert drive letter character to uppercase |

**Guard conditions:** If SetCurrentDirectoryA or GetCurrentDirectoryA fails, blocked: calls ErrorIDLookupTable and returns -1. If resolved path is UNC (starts with `\\` or `//`), returns 0 without setting environment variable.
