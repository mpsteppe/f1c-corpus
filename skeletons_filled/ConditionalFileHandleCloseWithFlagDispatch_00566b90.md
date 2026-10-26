## ConditionalFileHandleCloseWithFlagDispatch_00566b90 — ConditionalFileHandleClose

**Summary:** Conditionally closes a file handle stored in this[0]. If this[4] flag is 0, closes directly via FileCloseWithLock; if non-0, dispatches through StreamFileTypeCheckWithDispatch for type-specific close. Sets handle to 0 after close.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** CameraViewSystem (00408e20), sub_409770 (00409770), StaticCameraSceneLoader (0040b030), MultiLineTextDraw (0040bd10), VehicleSetupFileWriter (0042fd00), AutoLoadEntryListLoader (00432e70), ConfigFileParser (004330d0), sub_44BC50 (0044bc50), HTreeTerrainFileFormatLoader (0044be70), sub_45ECD0 (0045ecd0), sub_4A51C0 (004a51c0), sub_4B0770 (004b0770), GameDataFileIO (004b7300), sub_4B7500 (004b7500), sub_4B7DE0 (004b7de0), sub_4BA1F0 (004ba1f0), FAILWRONGTRIAGECATEGORY (004c22a0), CareerSectionReader (004c2700), sub_4D24D0 (004d24d0), TireBrandFileParser (004d7150), sub_4E3360 (004e3360), VehicleDamageModel (004f24f0), EngineSectionParser (004f3c80), sub_4F7460 (004f7460), SubCallWithConditionalFieldFree (005668d0), AudioStreamOpen (00566b20), AudioFileLoadDecode (00567f40)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | file handle to close |
| this | 0x10 | R | — | close-method flag: 0 = direct close, non-0 = type-checked dispatch close |

**Written-by note (persistence):**
- this 0x0: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005355a0 | StreamFileTypeCheckWithDispatch | closes file handle using type-specific dispatch (called when flag is non-0) |
| 00587d02 | FileCloseWithLock | directly closes file handle with lock (called when flag is 0) |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x10 | == | 0 | close-method flag (0 = direct, non-0 = type-dispatched) |

**Guard interpretation:** If this[4] == 0: direct close path (FileCloseWithLock) taken if handle non-0. If this[4] != 0: type-dispatched close path (StreamFileTypeCheckWithDispatch) taken if handle non-0. If handle is 0 on either path, returns 0 without action. Both paths set handle to 0 after closing.
