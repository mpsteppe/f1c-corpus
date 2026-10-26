## ValidateVehicleConfigurationFile_00433ed0 — ValidateVehicleConfigurationFile

**Summary:** Validates vehicle configuration by parsing two SVM/HDV files: first the vehicle's default file, then an override file. Returns 0 on success (both files parse), 1 on failure.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** LoadAIDriverNamesFromConfig (004336f0), InitWithStackBuffer (0046e5c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | first string pointer (source path passed to sub_568B00) |
| this | 0x8 | R | — | second string pointer (destination path for sub_568B00) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | default application directory path (fallback null string) |
| 005ec6d0 | unk_5EC6D0 | R | unknown |
| 007c54e8 | dword_7C54E8 | R | PlayerVehiclePtr — pointer to player vehicle struct (contains index at +0x4898) |
| 007c56c0 | byte_7C56C0 | RW | SessionNameBuffer — parse target buffer; cleared to 0 on success |
| 007c56c4 | dword_7C56C4 | W | CostDisplayModeBackup — saved cost display mode |
| 007d0450 | dword_7D0450 | R | CostDisplayMode — current cost display mode to save |
| 008ac394 | dword_8AC394 | R | VehicleArray (stride 0x424) — base of vehicle data array |
| 008adb00 | dword_8ADB00 | R | TireModelConstants [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042bc10 | ScoringGateCheck | check if scoring/gate system is active |
| 0042ebc0 | HistoryBufferShift | shift history buffer for next parse |
| 0042ed70 | sub_42ED70 | initialize/reset session name buffer |
| 00430f00 | VehicleStatsEstimationDisplay | display vehicle stats estimation |
| 004f4270 | TheSvmHdvVehicleFileParser | parse SVM/HDV vehicle file into buffer |
| 00566650 | StringCopyWithBufferRealloc | copy string with buffer reallocation |
| 00568b00 | sub_568B00 | process/compare two path strings |

**Guard conditions:** `ScoringGateCheck()` must return non-zero to proceed. Vehicle data pointer from array indexing must be non-null. First `TheSvmHdvVehicleFileParser` call (default vehicle file) must return 0 to proceed; if non-zero, skips second parse and display. Second `TheSvmHdvVehicleFileParser` (override file) must also return 0 for validation success (v4=0). Parameter `a3` (flag) gates the optional string copy and sub_568B00 call after successful validation.
