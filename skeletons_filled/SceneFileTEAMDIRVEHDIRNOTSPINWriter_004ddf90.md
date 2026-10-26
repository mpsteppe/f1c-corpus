## SceneFileTEAMDIRVEHDIRNOTSPINWriter_004ddf90 — VehicleSceneFileTemplateWriter

**Summary:** Processes a vehicle scene file template by reading the source file, replacing directive tags (teamdir, vehdir, spin, notspin, high/med/low detail, dashhigh/dashlow) with runtime values, and writing the result to an output file. Also handles merging backup override files for physics detail levels.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** VehicleSceneLoadAndPositionTires (004681b0), VehgenScnFileLoader (004c6c40)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004de580 | jpt_4DE16F | R | Jump table for switch-case dispatch on physics detail levels (v29) |
| 005be828 | aRb | R | FileModeRb [DERIVED] (also: ` — string comparison template) |
| 005be860 | aSS | R | PathFormatString [DERIVED] (also: ` â€” format string for path construction) |
| 005c2c18 | aS_4 | R | FmtStr_PercentS [DERIVED] |
| 005c30b4 | word_5C30B4 | R | ConfigSubstringToken [DERIVED] |
| 005c30b8 | unk_5C30B8 | R | QuoteDelimiter [DERIVED] (also: /b4/b0/ac` — delimiter/separator character constants) |
| 005c4064 | aS_7 | R | BackupExt [DERIVED] |
| 005c67a8 | off_5C67A8 | R | VTable_Renderer_67A8 [DERIVED] |
| 005c67ac | aHigh_0 | R | HighField [DERIVED] |
| 005c67b4 | aMed | R | MediumString [DERIVED] |
| 005c67b8 | off_5C67B8 | R | VTablePtr8 [DERIVED] |
| 005c67bc | aSpin | R | SpinString [DERIVED] |
| 005c67c4 | aNotspin | R | Str_Notspin [DERIVED] |
| 005c67cc | aTeamdir | R | StringTeamDir [DERIVED] |
| 005c67d4 | a03d | R | Format string for zero-padded 3-digit integer (e.g., "%03d") used for vehicle ID output |
| 005c67dc | aId | R | IdString [DERIVED] |
| 005c67e0 | aDoesNotHaveMat | R | DoesNotHaveMatStr [DERIVED] |
| 005c6804 | asc_5C6804 | R | Unknown_Asc_5C6804 [DERIVED] |
| 005c6808 | asc_5C6808 | R | Asc5C6808 [DERIVED] |
| 005c680c | aW | R | StringW [DERIVED] |
| 005c6810 | aCouldNotOpenS | R | Str_CouldNotOpenS [DERIVED] |
| 005d4cc4 | aDashhigh | R | DashHighString [DERIVED] |
| 005d4cd0 | aDashlow | R | DashLow [DERIVED] |
| 005d4cd8 | aVehdir | R | VehdirString [DERIVED] |
| 005d4ce0 | aDDevF119992002_6 | R | SourcePath_F1_1999_2002_6 [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec3d8 | dword_5EC3D8 | R | SeasonDir [DERIVED] |
| 005ec428 | dword_5EC428 | R | SeasonName [DERIVED] |
| 005ef9a0 | dword_5EF9A0 | R | VEH[0].0x32C8: Vehicle physics detail level array (indexed by a3, element size 4656), value 0 or 3 means default/none |
| 007c569c | dword_7C569C | R | SessionType5 (5=server) [DERIVED] (also: ` — SessionType5 (guards dev logging) |
| 007cf7f4 | dword_7CF7F4 | R | PhysicsFlag [DERIVED] |
| 007cf818 | dword_7CF818 | R | Dword_7CF818 [DERIVED] |
| 008ac394 | dword_8AC394 | R | VehicleArray (stride 0x424) [DERIVED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d7a50 | StringSplitLoop | Logs debug messages with source file name and line number reference |
| 004d7aa0 | DebugLogWrite | Writes a formatted debug log message to the debug buffer |
| 00534b00 | sub_534B00 | Opens a file with the given mode string (fopen wrapper), returns file handle |
| 005351d0 | LineInputReader | Reads the next line from the file stream into buffer |
| 005355a0 | StreamFileTypeCheckWithDispatch | Closes the file stream with type-specific cleanup dispatch |
| 005651b0 | sub_5651B0 | Returns a token type code for the current line (3 = end-of-section marker) |
| 00587c20 | sub_587C20 | Searches a string buffer for a delimiter character (like strchr), returns pointer to match |
| 00587d02 | FileCloseWithLock | Closes a file handle and releases associated lock |
| 00587db0 | sub_587DB0 | Opens a file for writing with the given mode string |
| 0058815f | StringFormatWithBufferOverflowCheck | Safe sprintf with buffer overflow protection, constructs path strings |
| 00588410 | sub_588410 | Case-insensitive string comparison (stricmp-style) for matching directive tags |
| 005887b1 | StringFormatWithNestedIO | Writes a formatted string to the file stream (fprintf-style) |
| 00589898 | BufferedCharacterWriteWithOverflowHandling | Writes a single character to the file output buffer with overflow handling |

**Guard conditions:** Source file path (v5) NULL → falls back to byte_5EA438 (default app directory). sub_534B00 returns NULL (cannot open source file) → returns 0 immediately; when SessionType5 != 5, logs debug warning first. sub_587DB0 returns NULL (cannot open output file) → closes source and returns 0 (BLOCKED). Token type == 3 (end-of-section marker) → skips line processing for that block. `<teamdir>` tag: reads vehicle path from VehicleArray[a2] at offset 0, strips trailing backslash to get directory. `<notspin>` tag: skipped (writes nothing) when v29 (physics detail level) is 0. `<spin>`, `<dashhigh>`, `<dashlow>` tags: checked against v30 (physics flag) and v29 to determine which detail level text to emit. Angle-bracket matching: if opening `<` has no closing `>`, logs warning and skips processing for that line.
