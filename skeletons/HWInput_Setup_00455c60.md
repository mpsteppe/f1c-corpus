## HWInput_Setup_00455c60 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Setup (0042d5d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ad4a0 | riidltf | R | riidltf [DERIVED] |
| 005c56a4 | aDDevF119992002_13 | R | SourcePathFormatString [DERIVED] |
| 005c56cc | aEnteredHwinput_0 | R | StringEnteredHWInput [DERIVED] |
| 005ec4a4 | byte_5EC4A4 | R | MessageActiveFlag [DERIVED] (also: ` — input config path) |
| 007c569c | dword_7C569C | R | SessionType5 (5=server) [DERIVED] (also: ` — SessionType5 (guards dev logging) |
| 007ce2a0 | hinst | R | HInstance [DERIVED] (also: ` — DirectInput instance handle) |
| 007ce2dc | hWnd | R | HWnd [DERIVED] (also: ` — DirectInput device pointer) |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0044ee10 | D3DWindowSurfaceCreation | [LLM] |
| 0044fa60 | DirectXDeviceInitialization | [LLM] |
| 0044fbe0 | CollisionObjectDestructor | [LLM] |
| 004d7a50 | StringSplitLoop | [LLM] |
| 004d7aa0 | DebugLogWrite | [LLM] |
| 0052d8b0 | DirectInput8Create | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
