## SuspensionBarLookup_0043af50 — Suspension anti-roll bar lookup by name

**Summary:** Searches for a suspension anti-roll bar entry by string name, then reads its rotation matrix and position offset to transform into world coordinates. If not found, zeros output and optionally logs debug error. Part of suspension setup.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** SteeringGeometryComputation (0043b590)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c421c | aDDevF119992002 | R | SourcePathPrefix [DERIVED] |
| 005c4248 | aCouldNotFindSu | R | s_ErrorCouldNotFindSub [DERIVED] |
| 007c569c | dword_7C569C | R | SessionType5 (5=server) [DERIVED] (also: ` — SessionType5 (guards dev logging) |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d7a50 | StringSplitLoop | Formats debug log source file path |
| 004d7aa0 | DebugLogWrite | Writes debug error message to log |
| 0056eb30 | LinearSearchInStructArrayByString | Searches struct array for matching string name |

**Guard conditions:** If search returns null, zero output array and (if not server session) log debug error.
