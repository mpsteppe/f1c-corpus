## SeasonRacesSectionWriter_004c5ae0 — Build season races file path, load section data

**Summary:** Constructs a file path by taking the default directory prefix, appending the input path, stripping the extension, and adding a suffix from global constants. Then loads/creates the season races audio channel data for that file.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** TrackFilePathBuilder (004c51a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c5d24 | dword_5C5D24 | R | SeasonRacesSuffix1 [DERIVED] |
| 005c5d28 | byte_5C5D28 | R | SeasonRacesSuffix2 [DERIVED] |
| 005d31c8 | aSeasonraces | R | ParamKey_SeasonRaces [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 008ad3b4 | dword_8AD3B4 | R | GameDataDir [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00567f40 | AudioFileLoadDecode | Load and decode audio file at constructed path |
| 00567fb0 | FileDataProcessor | Create new data channel entry for season races if not already loaded |
| 00568210 | AudioChannelStop | Retrieve existing season races data channel by name key |
| 00587dd0 | sub_587DD0 | Copy and normalize path string into buffer with size limit |

**Guard conditions:** If `AudioChannelStop("seasonraces")` returns existing data channel, use it directly. Otherwise, call `FileDataProcessor` to create a new one. No early-exit guard — always constructs the file path suffix.
