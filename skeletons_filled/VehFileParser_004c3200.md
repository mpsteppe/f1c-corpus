## VehFileParser_004c3200 — Vehicle R-File Parser and File Resolver

**Summary:** Parses a vehicle `.R` definition file (read via fopen), extracting all team/driver/livery/eyepoint/camera data into the vehicle struct, then resolves companion file paths (HDV, INI, GEN, SFX) via FileFinder. Returns 0 on success, -1 if the file cannot be opened.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** VehicleFileLoader (004c3d80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Base directory path pointer; if NULL, falls back to default app directory byte_5EA438 |
| this | 0x38 | R | — | Eyepoint position vector start (output of sub_565870 parsing, also read for camera-target copy) |
| this | 0x3C | R | — | Eyepoint Y component (read to compute default mirror position with −0.08 offset) |
| this | 0x40 | R | — | Eyepoint Z component (read for mirror position default) |
| this | 0x44 | RW | — | Camera target X (copied from eyepoint X on first camera-target parse) |
| this | 0x48 | RW | — | Camera target Y (copied from eyepoint Y) |
| this | 0x4C | RW | — | Camera target Z (copied from eyepoint Z) |
| this | 0x50 | RW | — | Mirror position X (copied from eyepoint X on first mirror-pos parse) |
| this | 0x54 | RW | — | Mirror position Y = eyepoint Y − 0.08 (computed on first mirror-pos parse) |
| this | 0x58 | RW | — | Mirror position Z (copied from eyepoint Z) |
| this | 0xFC | R | — | Description string buffer; checked for emptiness after parse — if empty, auto-generates "#num name" |
| this | 0x3D4 | RW | — | Track-livery linked-list head pointer; new livery nodes are prepended here |

**Written-by note (persistence):**
- this 0x44: once (on first valid eyepoint/camera-target section); survives across section re-reads within same file
- this 0x48: once (same condition as 0x44); survives across section re-reads within same file
- this 0x4C: once (same condition as 0x44)
- this 0x50: once (on first valid mirror-position section, guarded by `!v23` flag)
- this 0x54: once (same condition as 0x50)
- this 0x58: once (same condition as 0x50)
- this 0x3D4: accumulates across multiple track-livery lines — new allocations prepended to linked list; external iteration possible after function returns

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005acb28 | flt_5ACB28 | R | AISteerAngleThreshold [DERIVED] |
| 005bea08 | aDriver_0 | R | sDriver [DERIVED] |
| 005c316c | aEngine | R | ComponentNameEngine [DERIVED] |
| 005c36f0 | aR | R | Token_R [DERIVED] |
| 005c401c | aClasses | R | ClassesString [DERIVED] |
| 005c6810 | aCouldNotOpenS | R | Str_CouldNotOpenS [DERIVED] |
| 005d251c | asc_5D251C | R | IniKeyValueDelim [DERIVED] |
| 005d2e94 | aSfx | R | SfxString [DERIVED] |
| 005d2e9c | aGen | R | GenString [DERIVED] |
| 005d2ea4 | aIni | R | StringDotIni [DERIVED] |
| 005d2eac | aHdv | R | String_Hdv [DERIVED] |
| 005d2eb4 | a4s50s | R | TimeFormat4s50s [DERIVED] |
| 005d2ec0 | aFormatIsTrackl | R | FormatIsTrackL [DERIVED] |
| 005d2f00 | aTracklivery | R | TrackLiveryField [DERIVED] |
| 005d2f0c | aPitcrewlivery | R | PitcrewLiveryString [DERIVED] |
| 005d2f1c | aDefaultlivery | R | DefaultliveryString [DERIVED] |
| 005d2f2c | aTeamworldchamp | R | TeamworldchampString [DERIVED] |
| 005d2f44 | aTeamwins | R | Str_TeamWins [DERIVED] |
| 005d2f50 | aTeampoles | R | StringTeamPoles [DERIVED] |
| 005d2f5c | aTeamstarts | R | TeamStartsString [DERIVED] |
| 005d2f68 | aTeamheadquarte | R | TeamHeadquartersString [DERIVED] |
| 005d2f7c | aTeamfounded | R | TeamFoundedString [DERIVED] |
| 005d2f88 | aFullteamname | R | FullTeamNameStr [DERIVED] |
| 005d2f98 | aManufacturer | R | ManufacturerField [DERIVED] |
| 005d2fa8 | aDescription | R | Description [DERIVED] |
| 005d2fb4 | aTeam_0 | R | String_Team_0 [DERIVED] |
| 005d2fbc | aNumber | R | NumberString [DERIVED] |
| 005d2fc4 | aSteeringwheela | R | SteeringwheelaString [DERIVED] |
| 005d2fd8 | aMirrornorm | R | MirrorNormString [DERIVED] |
| 005d2fe4 | aMirrorpos | R | String_MirrorPos [DERIVED] |
| 005d2ff0 | aCameratarget | R | CameraTargetString [DERIVED] |
| 005d3000 | aEyepoint | R | Eyepoint [DERIVED] |
| 005d300c | aGenstring | R | GenstringField [DERIVED] |
| 005d3018 | aGraphics | R | GraphicsString [DERIVED] |
| 005d3024 | aSounds | R | SoundsString [DERIVED] |
| 005d302c | aHeadphysics | R | HeadphysicsString [DERIVED] |
| 005d3038 | aHdvehicle | R | Str_Hdvehicle [DERIVED] |
| 005d3044 | aDDevF119992002_8 | R | StringDevF119992002_8 [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 008ac388 | unk_8AC388 | R | VehicleFilePathBuffer [DERIVED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004c38d0 | FileINILoader | Reads INI-format config data from the parsed vehicle struct fields into the runtime config system |
| 004c40d0 | FileFinder | Searches for a named file (e.g. .hdv, .ini) in a base directory, writes resolved path to output buffer |
| 004d7a50 | StringSplitLoop | Debug/tracing string-split helper with channel filtering; returns bool for conditional debug logging |
| 004d7aa0 | DebugLogWrite | Writes a formatted debug message to the logging buffer |
| 005651b0 | sub_5651B0 | Parses the current line buffer; returns section type: 0=key-value pair, 1=section header `[...]`, 4=end marker |
| 005654a0 | sub_5654A0 | Extracts a named string value from the current parsed line into a destination buffer |
| 00565870 | sub_565870 | Parses 2−4 float values from the current line (used for 3D vectors, positions, and scalar fields) |
| 00566650 | StringCopyWithBufferRealloc | Copies a string with reallocation (heap); returns the new buffer |
| 00587c03 | OperatorNewNhMallocWrapper | C++ `new` / `malloc` wrapper with exception handling |
| 00587c20 | sub_587C20 | Finds a delimiter character in a string and returns pointer past it (used for key=value and token splitting) |
| 00587ca0 | FileReadUntilNewline | Reads one line from a file handle into a buffer, returns bytes read |
| 00587d02 | FileCloseWithLock | Closes a file handle and releases any associated lock |
| 00587db0 | sub_587DB0 | Opens a file for reading (`fopen`-style), returns file handle; returns NULL on failure |
| 0058815f | StringFormatWithBufferOverflowCheck | `snprintf`-like formatter with buffer-overflow protection |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | == | 0 | Base directory path pointer is NULL |

**Guard interpretation:** When this+0x0 (the base directory path pointer) is NULL, the function substitutes the default application directory `byte_5EA438` for file-resolution operations. PASSES: non-null path — file opened relative to that directory. BLOCKED: null path triggers fallback to default directory; if the file cannot be opened even from default, the function returns −1.
