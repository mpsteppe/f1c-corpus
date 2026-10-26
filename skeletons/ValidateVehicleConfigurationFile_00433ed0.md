## ValidateVehicleConfigurationFile_00433ed0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** LoadAIDriverNamesFromConfig (004336f0), InitWithStackBuffer (0046e5c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | [LLM] |
| this | 0x8 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec6d0 | unk_5EC6D0 | R | [LLM] |
| 007c54e8 | dword_7C54E8 | R | PlayerVehiclePtr [FACT] |
| 007c56c0 | byte_7C56C0 | RW | SessionNameBuffer [DERIVED] (also: file loader flag (save/restore around file operations, docs/08) |
| 007c56c4 | dword_7C56C4 | W | CostDisplayModeBackup [DERIVED] |
| 007d0450 | dword_7D0450 | R | CostDisplayMode [DERIVED] |
| 008ac394 | dword_8AC394 | R | VehicleArray (stride 0x424) [DERIVED] |
| 008adb00 | dword_8ADB00 | R | TireModelConstants [DERIVED] (also: /40/60 � Tire model constants (camber, friction, etc.) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042bc10 | ScoringGateCheck | [LLM] |
| 0042ebc0 | HistoryBufferShift | [LLM] |
| 0042ed70 | sub_42ED70 | [LLM] |
| 00430f00 | VehicleStatsEstimationDisplay | [LLM] |
| 004f4270 | TheSvmHdvVehicleFileParser | [LLM] |
| 00566650 | StringCopyWithBufferRealloc | [LLM] |
| 00568b00 | sub_568B00 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
