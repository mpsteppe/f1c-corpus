## HWInput_Post_00455e70 — HWInput_Post

**Summary:** Tears down HWInput post-frame: fills collision data, destructs array and collision objects, cleans up collision culling, and releases the DirectInput device interface.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Post (0042da30)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c56a4 | aDDevF119992002_13 | R | SourcePathFormatString |
| 005c571c | aEnteredHwinput_3 | R | debug log entry string |
| 007c569c | dword_7C569C | R | SessionType (5=server, guards debug logging) |
| 008ad25c | dword_8AD25C | R | debug message buffer |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0044efe0 | CollisionCullCleanup | cleans up collision culling data |
| 0044f070 | CollisionDataFill | fills collision data buffers |
| 0044fbe0 | CollisionObjectDestructor | destructs collision objects |
| 004526c0 | ArrayDestructorViaVirtualDispatch | destructs array at a1+1376 via virtual dispatch |
| 004d7a50 | StringSplitLoop | checks debug-log enable condition |
| 004d7aa0 | DebugLogWrite | writes post-entry message |

**Guard conditions:** a1[1637] (field at offset 0x1A1C) checked nonzero before ArrayDestructorViaVirtualDispatch. *a1 (DirectInput device pointer) checked nonzero before calling its virtual Release method.
