## TrackSurfaceMaterialLoader_004cdd80 — TrackSurfaceMaterialParser

**Summary:** Parses track surface material properties (friction, wet modifier, bump amplitude/wavelength, spring, damper, collision friction, sound type IDs, scraping flag, sink depth, materials string) from config entries and populates a surface material definition struct. Part of the track special-effects / physics surface system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SpecialFX_Init (004cf070)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | pointer to material data source (read for float-value lookups, v4 = this+8) |
| this | 0xC | RW | — | friction coefficient — base friction from config, then adjusted by subtracting wet modifier |
| this | 0x14 | RW | — | bump amplitude — parsed from config, then scaled by 0.25 |
| this | 0x18 | RW | — | bump wave frequency — computed as 2*PI / wavelength (wavelength clamped to min 3.0) |
| this | 0x2C | RW | — | scraping flag — boolean set from scraping sound config (non-zero = scraping enabled) |
| this | 0x30 | RW | 11 | left tire surface sound ID — set from material type string match (default 11 = rumble) |
| this | 0x34 | RW | 21 | center tire surface sound ID — set from material type string match (default 21 = rumble) |
| this | 0x38 | RW | 27 | right tire surface sound ID — set from material type string match (default 27 = rumble) |
| this | 0x60 | RW | 1 | legal surface flag — set to 1 when legal property != "true" (0 = legal, 1 = illegal/off-track) |
| this | 0x64 | RW | — | sink depth — double value from config, depth surface sinks into (e.g. gravel trap depth) |

**Written-by note (persistence):**
- this 0xC: once during material load; base friction written unconditionally, then wet-adjusted conditionally
- this 0x14: once conditionally (when BumpAmp config entry exists); scaled in-place, no other writes
- this 0x18: once conditionally (when BumpWaveLen entry exists); computed from wavelength, no other writes
- this 0x2C: once conditionally (when Scraping config entry exists); set from boolean, no other writes
- this 0x30: once conditionally (when Sound material-type string matches); no other writes in function
- this 0x34: once conditionally (when Sound material-type string matches); no other writes in function
- this 0x38: once conditionally (when Sound material-type string matches); no other writes in function
- this 0x60: once conditionally (when Legal config entry exists and != "true"); no other writes in function
- this 0x64: once conditionally (when Sink config entry exists); no other writes in function

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e478 | flt_59E478 | R | SteeringCenterBoost [DERIVED] |
| 0059e7f8 | flt_59E7F8 | R | AntiRollMixingFactor [DERIVED] |
| 0059ed28 | dbl_59ED28 | R | PhysicsMinDeltaThreshold [DERIVED] |
| 005c596c | aTrue | R | sTrue [DERIVED] |
| 005d3838 | aMaterials | R | MaterialsString [DERIVED] |
| 005d3844 | aGuardrail | R | Str_Guardrail [DERIVED] |
| 005d3850 | aSolidwall | R | StringSolidWall [DERIVED] |
| 005d385c | aTirewall | R | TirewallString [DERIVED] |
| 005d3868 | aRumble | R | RumbleString [DERIVED] |
| 005d3870 | aGravel | R | GravelString [DERIVED] |
| 005d3878 | aGrass | R | GrassStr [DERIVED] |
| 005d3880 | aDirt | R | DirtString [DERIVED] |
| 005d3888 | aSound | R | SoundField [DERIVED] |
| 005d3890 | aSink | R | SinkKeyword [DERIVED] |
| 005d3898 | aScraping | R | String_Scraping [DERIVED] |
| 005d38a4 | aSparks | R | SparksString [DERIVED] |
| 005d38ac | aCollfrict | R | CollfrictString [DERIVED] |
| 005d38b8 | aDamper | R | DamperString [DERIVED] |
| 005d38c0 | aSpring_0 | R | String_Spring [DERIVED] |
| 005d38c8 | aBumpwavelen | R | BumpWaveLenString [DERIVED] |
| 005d38d4 | aBumpamp | R | BumpAmp [DERIVED] |
| 005d38dc | aResistance | R | ResistanceField [DERIVED] |
| 005d38e8 | aWet | R | WetString [DERIVED] |
| 005d38ec | off_5D38EC | R | VTablePtr5 [DERIVED] |
| 005d38f0 | aLegal | R | LegalString [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004cdc70 | sub_4CDC70 | reads a named float property from material config data; returns 1 if found, writes float to output |
| 005654a0 | sub_5654A0 | string equality check — tests if a token matches a keyword (used to find "Materials" token) |
| 00565520 | sub_565520 | reads a named string property from config; writes string to output buffer |
| 00565760 | sub_565760 | reads a named integer/boolean property from config; returns value via output pointer |
| 00566650 | StringCopyWithBufferRealloc | copies the materials string with buffer management (final step, stores cleaned materials list) |
| 00588410 | sub_588410 | case-insensitive string comparison (used to check if legal == "true") |
| 00589901 | sub_589901 | string trim/normalize — removes spaces and commas from materials string |

**Guard conditions:** No top-level guard — function always processes. The legal flag at top: if `sub_565520(aLegal, ...)` succeeds AND the value is NOT "true" (via `!sub_588410`), set `this+0x60 = 1`. If legal value IS "true", flag stays at default. The Sound material-type dispatch (strcmp chain) is gated by `sub_565520(aSound, ...)` returning non-zero — if no Sound config entry exists, sound IDs stay at defaults (11, 21, 27). Each `sub_4CDC70` call handles missing properties gracefully (returns 0, field unchanged).