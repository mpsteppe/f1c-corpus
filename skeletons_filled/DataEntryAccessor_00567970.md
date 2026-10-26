## DataEntryAccessor_00567970 — GetDataEntryPathOrDefault

**Summary:** Returns the custom data entry path stored at this[6] if non-null, otherwise falls back to the default application directory (byte_5EA438). Simple accessor with null check.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** RaceCommentaryDirectorSystem (0040d4c0), sub_424080 (00424080), sub_429960 (00429960), SettingsCopySetupFileCopy (00432220), AISettingsFileResolver (00433890), sub_468BF0 (00468bf0), ResultsPageBuilder (00469fb0), sub_47D800 (0047d800), DriverCareerStatsHTMLWriter (0047dd10), RaceLapsStringLoadOnTrigger (0047e3f4), sub_4B1190 (004b1190), sub_4BE760 (004be760), sub_4BF6A0 (004bf6a0), sub_4C02D0 (004c02d0), SeasonScoring (004c0910), SessionConfigReader (004c11e0), SeasonScoringInfoUpdater (004c2a80), StringCopyWithValidation (004c58a0), DriverAbbreviationNameFormatter (004c6a10), NationalityDriverInfoLoader (004c78f0), PitStopOrderLoader (004d12c0), sub_4D1450 (004d1450), Steward_Restart (004d3cf0), HUDVenue (004d99e0), sub_4FE350 (004fe350), ConditionalDispatch_81f0 (005681f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x18 | R | — | custom data entry path string pointer (null = use default) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Checks this[6] (offset 0x18) against null. If null: returns default path byte_5EA438 (blocks custom path). If non-null: returns custom path (passes through).
