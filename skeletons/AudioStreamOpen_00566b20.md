## AudioStreamOpen_00566b20 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** CameraViewSystem (00408e20), StaticCameraSceneLoader (0040b030), MainView (0040b850), AutoLoadEntryListLoader (00432e70), SuspensionSetupSectionReader (00435410), HTreeTerrainFileFormatLoader (0044be70), sub_45ECD0 (0045ecd0), CreditsTxtParser (00467e40), UIScreenLoad (0048aed0), sub_4A51C0 (004a51c0), PlayerFileInit (004b0540), GameDataFileIO (004b7300), sub_4B7500 (004b7500), sub_4BA1F0 (004ba1f0), FAILWRONGTRIAGECATEGORY (004c22a0), TireBrandFileParser (004d7150), sub_4E3360 (004e3360), VehicleDamageModel (004f24f0), EngineSectionParser (004f3c80), sub_4F7460 (004f7460), AudioFileLoadDecode (00567f40)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | [LLM] |
| this | 0xC | RW | — | [LLM] |
| this | 0x10 | RW | 1 | [LLM] |
| this | 0x18 | RW | 1 | [LLM] |

**Written-by note (persistence):**
- this 0x0: recalc every frame — external poke does NOT persist
- this 0xC: recalc every frame — external poke does NOT persist
- this 0x10: recalc every frame — external poke does NOT persist
- this 0x18: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005be828 | aRb | R | FileModeRb [DERIVED] (also: ` — string comparison template) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00534b00 | sub_534B00 | [LLM] |
| 00566650 | StringCopyWithBufferRealloc | [LLM] |
| 00566b90 | ConditionalFileHandleCloseWithFlagDispatch | [LLM] |
| 00568620 | sub_568620 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
