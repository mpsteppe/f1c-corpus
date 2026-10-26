## SceneFileTEAMDIRVEHDIRNOTSPINWriter_004ddf90 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** VehicleSceneLoadAndPositionTires (004681b0), VehgenScnFileLoader (004c6c40)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004de580 | jpt_4DE16F | R | [LLM] |
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
| 005c67d4 | a03d | R | [LLM] |
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
| 005ef9a0 | dword_5EF9A0 | R | VEH[0].0x32C8 [LLM: field purpose] |
| 007c569c | dword_7C569C | R | SessionType5 (5=server) [DERIVED] (also: ` — SessionType5 (guards dev logging) |
| 007cf7f4 | dword_7CF7F4 | R | PhysicsFlag [DERIVED] |
| 007cf818 | dword_7CF818 | R | Dword_7CF818 [DERIVED] |
| 008ac394 | dword_8AC394 | R | VehicleArray (stride 0x424) [DERIVED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d7a50 | StringSplitLoop | [LLM] |
| 004d7aa0 | DebugLogWrite | [LLM] |
| 00534b00 | sub_534B00 | [LLM] |
| 005351d0 | LineInputReader | [LLM] |
| 005355a0 | StreamFileTypeCheckWithDispatch | [LLM] |
| 005651b0 | sub_5651B0 | [LLM] |
| 00587c20 | sub_587C20 | [LLM] |
| 00587d02 | FileCloseWithLock | [LLM] |
| 00587db0 | sub_587DB0 | [LLM] |
| 0058815f | StringFormatWithBufferOverflowCheck | [LLM] |
| 00588410 | sub_588410 | [LLM] |
| 005887b1 | StringFormatWithNestedIO | [LLM] |
| 00589898 | BufferedCharacterWriteWithOverflowHandling | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
