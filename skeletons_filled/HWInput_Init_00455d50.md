## HWInput_Init_00455d50 — HWInput_Init

**Summary:** Initializes HWInput state: logs entry (unless server session), calls audio scene update and global state initialization, then configures camera viewport.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Init (0042d6b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c56a4 | aDDevF119992002_13 | R | SourcePathFormatString |
| 005c56e8 | aEnteredHwinput_1 | R | debug log entry string |
| 007c569c | dword_7C569C | R | SessionType (5=server, guards debug logging) |
| 008ad25c | dword_8AD25C | R | debug message buffer |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004532d0 | AudioSceneUpdateLoop | updates audio scene state |
| 004533a0 | GlobalStateInitializerWithEnumValues | initializes global state with enum defaults |
| 004d7a50 | StringSplitLoop | checks debug-log enable condition |
| 004d7aa0 | DebugLogWrite | writes init-entry message |

**Guard conditions:** dword_7C569C != 5 gates debug logging (server session skips log write). No other guards.
