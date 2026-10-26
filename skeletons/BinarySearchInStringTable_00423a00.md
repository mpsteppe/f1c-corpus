## BinarySearchInStringTable_00423a00 — BinarySearchInStringTable

**Summary:** Binary search in a sorted string table (16-byte entries: key pointer at +0, value pointer at +8). On match copies value string to output buffer (returns 0); on miss copies input key to output buffer (returns -1). Null entry pointers fall back to a default directory path string.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_423890 (00423890), AIShiftPattern (0042b8d0), sub_42BDD0 (0042bdd0), sub_42D140 (0042d140), sub_42D210 (0042d210), MessageStringFormatter (0042ec00), sub_42ED70 (0042ed70), StringCopyWithReturn (0042f140), VehicleSetupValueFormatter (0042f470), VehicleStatsEstimationDisplay (00430f00), SettingsCopySetupFileCopy (00432220), PlayerNameSetup (004326e0), BrakeBiasAdjustmentControl (00447d00), sub_45D2D0 (0045d2d0), NetCommSessionMessageDispatcher (0045d890), SessionSynchronizer (0045f950), NetCommPlayerSlotSync (0045fc50), YouHaveBeenBootedHandler (00461d20), AutoJoinRetryLoop (004637a0), PlayerProfileScanner (00468ee0), ProfileIconBmpLoader (004692b0), MessageNameBufferUpdate (0046ad50), KeyBindingUIPressKeyOrController (0046b0c0), sub_46B9B0 (0046b9b0), ProfileAlreadyExistsPageHandler (0046cb50), MultiplayerSessionJoinHandler (0046de10), sub_475150 (00475150), DriverCareerStatsHTMLWriter (0047dd10), VehicleNameToMessageBuffer (0047f010), LoadAndProcessMessageBuffer (0047f0a0), UILargeRenderDispatcher (00488be0), MediaBufferPlaybackManager (0048d9d0), sub_492A40 (00492a40), UIMessageDispatch (00494f10), sub_496E90 (00496e90), BitmapDraw (004980d0), BitmapDraw_81f0 (004981f0), BitmapDrawWithAlpha (004982c0), TextRenderToSurface (004983b0), sub_49BB40 (0049bb40), sub_49BCD0 (0049bcd0), sub_49BDE0 (0049bde0), sub_49BF80 (0049bf80), sub_49C140 (0049c140), sub_49C370 (0049c370), sub_49C4E0 (0049c4e0), SeasonNameLookup (0049c600), sub_49C700 (0049c700), EventRoundNameLookup (0049c830), sub_49C8F0 (0049c8f0), TrackPositionNameFormatter (0049d320), BrakeWaterTemperatureHUDDisplay (0049db80), sub_49F1C0 (0049f1c0), PitRepairStatusDisplay (004a58b0), RenderScreenSave (004b40a0), sub_4B7500 (004b7500), sub_4B7DE0 (004b7de0), sub_4B9FD0 (004b9fd0), sub_4BA1F0 (004ba1f0), sub_4BA460 (004ba460), sub_4BBA90 (004bba90), WarningHandler (004bbc60), StopGoPenaltyHandler (004bbd60), DisqualificationHandler (004bc0e0), LapCompletion (004bc4e0), sub... (line truncated to 2000 chars)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | count of entries in the string table (upper bound for binary search) |
| this | 0x8 | R | — | pointer to the 16-byte-entry array (key ptr at +0, value ptr at +8) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | default fallback string used when an entry's pointer is null |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If this[1] (entry count) <= 0, skips search entirely — copies input key directly to output buffer and returns -1 (no data to search).
