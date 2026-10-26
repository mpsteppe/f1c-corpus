## UtilityFunction_8a60_00568a60 — WeightedFileChecksumCalculator

**Summary:** Opens a file in binary read mode, computes a weighted checksum over its bytes using a cycling multiplier. Each byte read is multiplied by the current multiplier value (which cycles modulo a2), accumulated into the output dword. Returns 1 on success, 0 if file cannot be opened.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GameFileLoader (0042d260), sub_45C0C0 (0045c0c0), ParserDispatchWrapper (0045c3d0), sub_45C400 (0045c400), DataFileCheckSizeQuery (0045c650), SceneFilePathFormatter (004c5bb0), SpecialFX_Init (004cf070), TelemetryDataDump (004d4a80), TireBrandFileParser (004d7150)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005be828 | aRb | R | FileModeRb [DERIVED] (also: ` — string comparison template) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587d02 | FileCloseWithLock | closes the opened file handle |
| 00587db0 | sub_587DB0 | opens file with given mode string "rb" |
| 00587f64 | sub_587F64 | seeks to specified position in file |
| 00589fcc | StreamGetcWithUnderflowHandler | reads one byte from file stream |

**Guard conditions:** if sub_587DB0 fails to open file (returns 0), returns 0 immediately.
