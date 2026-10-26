## TerrainIniParser_00460a10 — TerrainIniConfigValidator

**Summary:** Validates terrain INI configuration against scene data by checking 5 criteria: hash checksum, scene file name, terrain.ini match, season path, and full season directory. Returns true only if all 5 conditions match.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** NetCommSessionMessageDispatcher (0045d890)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1B754 | R | — | Season index byte (first byte of season/race pair) |
| this | 0x1B755 | R | — | Race index byte (second byte of season/race pair) |
| this | 0x1B76A | RW | 1 | Flag 1: hash checksum match result |
| this | 0x1B76B | RW | 1 | Flag 2: scene file name match result |
| this | 0x1B76C | RW | 1 | Flag 3: terrain.ini CRC match result |
| this | 0x1B76D | RW | 1 | Flag 4: season path match result |
| this | 0x1B76E | RW | 1 | Flag 5: full season directory match result |

**Written-by note (persistence):**
- this 0x1B76A-0x1B76E: all reset to 0 each call, then conditionally set to 1 per match; persists until next call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005be860 | aSS | R | PathFormatString [DERIVED] — "%s%s" format for path construction |
| 005c5b88 | aTerrainIni | R | TerrainIniString [DERIVED] — "terrain.ini" string constant |
| 005c5d24 | dword_5C5D24 | R | SeasonRacesSuffix1 [DERIVED] |
| 005c5d28 | byte_5C5D28 | R | SeasonRacesSuffix2 [DERIVED] |
| 005ea438 | byte_5EA438 | R | Default application directory (fallback path) |
| 005ec3d8 | dword_5EC3D8 | R | SeasonDir [DERIVED] |
| 007ce5d0 | dword_7CE5D0 | R | CurrentTrackPath [DERIVED] |
| 007d0434 | dword_7D0434 | R | SeasonPath [DERIVED] |
| 008aced8 | dword_8ACED8 | R | TerrainINICRCOffset [DERIVED] — CRC offset constant |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0045c320 | SceneFileMatchByName | Match scene file by name against object's data |
| 00460770 | HashChecksumComputation | Compute hash checksum from season/race index bytes |
| 00587dd0 | sub_587DD0 | Copy string with length limit |
| 0058969d | StringFormatProcessingWithNullTerm | Safe string format with null termination |

**Guard conditions:**
- All 5 flag fields (0x1B76A-0x1B76E) initially zeroed.
- Flag 1: set to 1 if HashChecksumComputation(v5, v4) matches *(a2+8) (hash field in scene data).
- Flag 2: set to 1 if a3 != null AND SceneFileMatchByName succeeds AND a3 equals *(a2+12).
- Flag 3: set to 1 if SceneFileMatchByName("terrain.ini") succeeds AND address at offset matches *(a2+16).
- Flag 4: set to 1 if SceneFileMatchByName(season path) succeeds AND matches *(a2+20).
- Flag 5: set to 1 if SceneFileMatchByName(full season dir path) succeeds AND matches *(a2+24).
- dword_7CE5D0 null → use byte_5EA438 fallback for track path.
- dword_7D0434 null → use byte_5EA438 fallback.
- dword_5EC3D8 null → use byte_5EA438 fallback.
- Return: logical AND of all 5 flags.
