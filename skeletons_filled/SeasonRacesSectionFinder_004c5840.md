## SeasonRacesSectionFinder_004c5840 — SeasonRacesSectionFinder

**Summary:** Returns a string-keyed linked list search result for the "SeasonRaces" section using either a provided key or the current scene's data offset; guarded by a name lookup check.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_424080 (00424080), sub_429960 (00429960), SettingsCopySetupFileCopy (00432220), SettingsFolderResolver (004326a0), AISettingsFileResolver (00433890), sub_468BF0 (00468bf0), ResultsPageBuilder (00469fb0), sub_47D800 (0047d800), RaceLapsStringLoadOnTrigger (0047e3f4), sub_4B1190 (004b1190), sub_4BE760 (004be760), sub_4C0260 (004c0260), sub_4C02D0 (004c02d0), SessionConfigReader (004c11e0), StringCopyWithValidation (004c58a0), Steward_Restart (004d3cf0), HUDVenue (004d99e0), sub_4FCC30 (004fcc30)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d31c8 | aSeasonraces | R | ParamKey_SeasonRaces [DERIVED] |
| 008ac48c | dword_8AC48C | R | CurrentSceneIndex [DERIVED] (also: ` — module list index) |
| 008ac490 | dword_8AC490 | R | SceneArray (stride 0x18c) [DERIVED] |
| 008ad3b4 | dword_8AD3B4 | R | GameDataDir [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00568210 | AudioChannelStop | check/lookup "SeasonRaces" name token |

**Guard conditions:** BLOCKED (returns 0) when AudioChannelStop("SeasonRaces") returns 0 (name not found/active). If a1 is non-zero, uses it as search key; if a1 is zero but dword_8AC490 is set, computes search key from scene array offset.
