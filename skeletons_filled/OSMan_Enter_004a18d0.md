## OSMan_Enter_004a18d0 — SingleInstanceGuard

**Summary:** Ensures only one instance of the application runs by creating a named mutex. Logs OS manager entry. Returns TRUE if another instance is already running (mutex already exists) or creation fails.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Enter (0042d370)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e188 | GetLastError | R | kernel32 GetLastError function pointer |
| 0059e1ac | CreateMutexA | R | kernel32 CreateMutexA function pointer |
| 005cd0b4 | Name | R | s_Name [DERIVED] |
| 005cd0d4 | aEnteredOsmanEn | R | EnteredOsmanEn [DERIVED] |
| 005cd0ec | aDDevF119992002_19 | R | sBuildVersion [DERIVED] |
| 007ce2d8 | hObject | W | FileHandle_7CE2D8 [DERIVED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d7a50 | StringSplitLoop | Parses build version string for entry detection |
| 004d7aa0 | DebugLogWrite | Writes debug log entry for OS manager enter |

**Guard conditions:** No guard on entry detection/mutex creation. Mutex is always created. Returns TRUE if hObject (mutex handle) is NULL (creation failed) OR GetLastError returns 183 (ERROR_ALREADY_EXISTS — another instance running).
