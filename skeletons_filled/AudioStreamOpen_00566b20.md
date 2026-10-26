## AudioStreamOpen_00566b20 — OpenAudioStream

**Summary:** Opens an audio stream file: closes previous handle, allocates 1024-byte string buffer, opens file via sub_534B00, stores handle and flags, copies filename string if handle valid.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** CameraViewSystem (00408e20), StaticCameraSceneLoader (0040b030), MainView (0040b850), AutoLoadEntryListLoader (00432e70), SuspensionSetupSectionReader (00435410), HTreeTerrainFileFormatLoader (0044be70), sub_45ECD0 (0045ecd0), CreditsTxtParser (00467e40), UIScreenLoad (0048aed0), sub_4A51C0 (004a51c0), PlayerFileInit (004b0540), GameDataFileIO (004b7300), sub_4B7500 (004b7500), sub_4BA1F0 (004ba1f0), FAILWRONGTRIAGECATEGORY (004c22a0), TireBrandFileParser (004d7150), sub_4E3360 (004e3360), VehicleDamageModel (004f24f0), EngineSectionParser (004f3c80), sub_4F7460 (004f7460), AudioFileLoadDecode (00567f40)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | file handle returned by sub_534B00 |
| this | 0xC | RW | — | audio stream parameter from caller (a3) |
| this | 0x10 | RW | 1 | initialized flag |
| this | 0x18 | RW | 1 | stream active flag |

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
| 00534b00 | sub_534B00 | opens audio file / stream, returns file handle (0 on failure) |
| 00566650 | StringCopyWithBufferRealloc | copies filename string into struct buffer at this+4 |
| 00566b90 | ConditionalFileHandleCloseWithFlagDispatch | closes previous file handle if open, checks flags |
| 00568620 | sub_568620 | initializes 1024-byte string/buffer for filename |

**Guard conditions:** No early-return guard. If handle (v4, return of sub_534B00) is 0, string copy is skipped but all other assignments still execute; function returns false. If handle is non-zero, string copy proceeds and function returns true.
