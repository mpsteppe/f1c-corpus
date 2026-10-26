## HWInput_Setup_00455c60 — HWInput_Setup

**Summary:** Sets up DirectInput8 device and initializes up to four sub-devices (keyboard, mouse, force-feedback) via DirectXDeviceInitialization and CollisionObjectDestructor. Logs entry unless session type is 5 (server).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Setup (0042d5d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ad4a0 | riidltf | R | IID_IDirectInput8A reference |
| 005c56a4 | aDDevF119992002_13 | R | SourcePathFormatString |
| 005c56cc | aEnteredHwinput_0 | R | debug log entry string |
| 005ec4a4 | byte_5EC4A4 | R | MessageActiveFlag (also used as input config path) |
| 007c569c | dword_7C569C | R | SessionType (5=server, guards debug logging) |
| 007ce2a0 | hinst | R | application HINSTANCE |
| 007ce2dc | hWnd | R | main window HWND |
| 008ad25c | dword_8AD25C | R | debug message buffer |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0044ee10 | D3DWindowSurfaceCreation | creates D3D window surface for input device |
| 0044fa60 | DirectXDeviceInitialization | initializes DirectX input sub-device |
| 0044fbe0 | CollisionObjectDestructor | destructs/reinitializes collision objects |
| 004d7a50 | StringSplitLoop | checks debug-log enable condition |
| 004d7aa0 | DebugLogWrite | writes setup-entry message |
| 0052d8b0 | DirectInput8Create | creates DirectInput8 interface |

**Guard conditions:** dword_7C569C != 5 gates debug logging (server session skips log write).
