## ParticleSoundEffectSpawner_004607a0 — AssetPathDataFileResolver

**Summary:** Resolves asset paths and data file sizes for particle/sound effects based on season and race index bytes. Computes hash checksums, builds season and track paths, queries data file sizes, and creates output texture.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** NetCommSessionMessageDispatcher (0045d890)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1B768 | R | — | Season index byte (first byte of season/race pair) |
| this | 0x1B769 | R | — | Race index byte (second byte of season/race pair) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005be860 | aSS | R | PathFormatString [DERIVED] — "%s%s" format for path construction |
| 005c5d24 | dword_5C5D24 | R | SeasonRacesSuffix1 [DERIVED] |
| 005c5d28 | byte_5C5D28 | R | SeasonRacesSuffix2 [DERIVED] |
| 005ea438 | byte_5EA438 | R | Default application directory (fallback path) |
| 005ec3d8 | dword_5EC3D8 | R | SeasonDir [DERIVED] |
| 007ce5d0 | dword_7CE5D0 | R | CurrentTrackPath [DERIVED] |
| 007ce64c | dword_7CE64C | R | GameFilterDataPath [DERIVED] |
| 007d0434 | dword_7D0434 | R | SeasonPath [DERIVED] |
| 008ac388 | unk_8AC388 | R | VehicleFilePathBuffer [DERIVED] |
| 008acea0 | dword_8ACEA0 | R | ScoringGridBase [DERIVED] |
| 008aced8 | dword_8ACED8 | R | TerrainINICRCOffset [DERIVED] — CRC offset constant |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0045c3c0 | TwoByteFieldSetter | Set two-byte field on data object |
| 0045c3d0 | ParserDispatchWrapper | Parse/dispatch data file content |
| 0045c400 | sub_45C400 | Check and retrieve data file path/size |
| 0045c650 | DataFileCheckSizeQuery | Query data file size, returns nonzero if file exists |
| 00460770 | HashChecksumComputation | Compute hash checksum from two bytes (season/race) |
| 00462250 | TextureCreationWrapper | Create output texture |
| 004b33b0 | ProgressBarEventEncode | Encode progress event |
| 004c40b0 | ConditionalDispatch_40b0 | Conditional dispatch for path resolution |
| 004ceef0 | sub_4CEEF0 | Initialize string buffer |
| 00587dd0 | sub_587DD0 | Copy string with length limit |
| 0058815f | StringFormatWithBufferOverflowCheck | Safe string format with overflow check |
| 005884ed | RandLCGRandomNumberGenerator | LCG random number generator for hash randomization |

**Guard conditions:**
- dword_7CE64C (GameFilterDataPath) null → use byte_5EA438 (default path) as fallback.
- ConditionalDispatch_40b0 returns 0 → skip data file sub-check, set v26 = 0.
- sub_45C400 fails → set v26 = 0.
- ParserDispatchWrapper fails → set v27 = 0.
- dword_7CE5D0 (CurrentTrackPath) null → use byte_5EA438 fallback.
- While stripping extension from path: exit if v8 <= v20 (empty path).
- dword_7D0434 (SeasonPath) null → use byte_5EA438 fallback.
- dword_5EC3D8 (SeasonDir) null → use byte_5EA438 fallback.
- DataFileCheckSizeQuery returns 0 → set size fields to 0.
