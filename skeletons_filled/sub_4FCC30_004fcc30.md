## sub_4FCC30_004fcc30 — Weather/Environment State Initializer

**Summary:** Initializes weather and environment state on game restart: selects weather mode, builds weather parameter tables from file or built-in data, processes audio ring buffer for weather events, seeds noise values, and configures per-race weather flags. Called from Game_Restart.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Restart (0042d7a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 1065353216 → 1.0f | weather state float (race laps or default 1.0f) |
| this | 0x4 | RW | 0 | weather parameter slot 1 (cleared to 0) |
| this | 0x8 | RW | — | weather parameter block (6 floats, temp copied for ring buffer processing) |
| this | 0x14 | RW | 0 | weather state flag (set based on this[11] comparison, 0 or 1) |
| this | 0x1C | RW | 0 | cleanup counter / mode flag (set to 0) |
| this | 0x20 | R | — | weather parameter block read source (copied to this+0x8) |
| this | 0x24 | R | — | weather parameter read from config |
| this | 0x28 | RW | — | weather config slot (copy of this[9]) |
| this | 0x2C | RW | — | weather config value (read for comparison at end) |
| this | 0x30 | RW | — | weather timing parameter (float, from allocated array[1]) |
| this | 0x34 | RW | — | weather timing parameter (float, from allocated array[1]) |
| this | 0x38 | RW | — | stored pointer to weather data array (this[14] = this[15]) |
| this | 0x3C | RW | — | pointer to allocated weather param array (4 floats: [0, 20.0f, modeValue, 0]) |
| this | 0x40 | RW | 1 | initialization complete byte flag (set to 1 after init) |
| this | 0x44 | RW | 18446744073701163007 | weather param constant (-8388609 = 0xFF7FFFFF) |
| this | 0x48 | RW | 0 | word field (cleared to 0) |
| this | 0x4A | RW | 18446744073709551615 | word field (-1, 0xFFFF) |
| this | 0x4C | RW | 18446744073709551615 | word field (-1, 0xFFFF) |
| this | 0x4E | RW | 0 | word field (cleared to 0) |
| this | 0x50 | RW | 32767 | word field (0x7FFF) |
| this | 0x52 | RW | 18446744073709518848 | word field (-32768 = 0x8000) |
| this | 0x104 | RW | — | weather noise float (from noise table lookup, scaled by 0.05) |
| this | 0x1CF | RW | 0 | null terminator byte after race flag string copy (offset 452 + 11 = 463) |

**Written-by note (persistence):**
- this 0x0: set once at game restart — external poke does NOT survive restart
- this 0x4: set once at game restart — external poke does NOT survive restart
- this 0x8: set once at game restart — external poke does NOT survive restart
- this 0x14: set once at game restart — external poke does NOT survive restart
- this 0x1C: set once at game restart — external poke does NOT survive restart
- this 0x28: set once at game restart — external poke does NOT survive restart
- this 0x2C: set once at game restart — external poke does NOT survive restart
- this 0x30: set once at game restart — external poke does NOT survive restart
- this 0x34: set once at game restart — external poke does NOT survive restart
- this 0x38: set once at game restart — external poke does NOT survive restart
- this 0x3C: set once at game restart — external poke does NOT survive restart
- this 0x40: set once at game restart — external poke does NOT survive restart
- this 0x44: set once at game restart — external poke does NOT survive restart
- this 0x48: set once at game restart — external poke does NOT survive restart
- this 0x4A: set once at game restart — external poke does NOT survive restart
- this 0x4C: set once at game restart — external poke does NOT survive restart
- this 0x4E: set once at game restart — external poke does NOT survive restart
- this 0x50: set once at game restart — external poke does NOT survive restart
- this 0x52: set once at game restart — external poke does NOT survive restart
- this 0x104: set once at game restart — external poke does NOT survive restart
- this 0x1CF: set once at game restart — external poke does NOT survive restart

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e448 | flt_59E448 | R | TileSteppingMultiplier [DERIVED] |
| 005d173c | aWeather_1 | R | StrWeather [DERIVED] |
| 005d6f68 | aSweatherTxt | R | StrSWeatherTxt [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec438 | dword_5EC438 | R | WeatherDir [DERIVED] (also: ` — SeasonDir/LoadPath, docs/12) |
| 007c56a0 | dword_7C56A0 | R | MultiplayerFlags [DERIVED] |
| 007cf080 | dword_7CF080 | R | WeatherMode (0-5) [DERIVED] |
| 007cf17c | byte_7CF17C | R | WeatherStateFlag [DERIVED] |
| 008aae70 | dword_8AAE70 | RW | RingBufferCounter (QA/weather noise) [DERIVED] |
| 008ab274 | flt_8AB274 | R | WeatherNoiseTable [DERIVED] (also: � random noise table (docs/12) |
| 008ab6e4 | dword_8AB6E4 | R | ScoringGate [CONFIRMED] |
| 008ac368 | unk_8AC368 | R | VehicleSetupBase [DERIVED] |
| 008acf9c | flt_8ACF9C | R | TotalRaceLaps [DERIVED] |
| 008acfa3 | byte_8ACFA3 | R | RaceFlag_8ACFA3 [DERIVED] |
| 008afe88 | dword_8AFE88 | R | CollisionGeometryHandle [DERIVED] (also: ` — global collision geometry handle) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004c5840 | SeasonRacesSectionFinder | checks if season/race section exists in data for weather mode 1 |
| 004fc550 | sub_4FC550 | applies race flag data read from string comparison into weather state |
| 004fc9a0 | FloatArrayInitializer | initializes a 4-float weather parameter array from allocated memory |
| 004fd6f0 | RangeInterpolationTable | sets up range interpolation table for weather parameters |
| 004fd840 | DualLinkedListDestruction | destroys/clears linked list before initialization |
| 004fde00 | sub_4FDE00 | processes weather mode value for effect setup |
| 004fe350 | sub_4FE350 | loads/parses weather data from linked list search result |
| 004fe7c0 | sub_4FE7C0 | loads weather data from weather.txt file |
| 004feaf0 | AudioEventRingBufferProcessing | processes audio event ring buffer entries, modifies temp weather param block |
| 00543960 | DisplayModeSetter | sets display mode (0x20000 = some init flag) |
| 005679c0 | StringKeyedLinkedListSearch | string-keyed linked list search for "Weather" entry |
| 00587c03 | OperatorNewNhMallocWrapper | heap allocation with new handler (16 bytes for weather array) |
| 00587dd0 | sub_587DD0 | copies race flag string (11 bytes) into weather state |
| 0058815f | StringFormatWithBufferOverflowCheck | formats "%sweather.txt" path string with buffer overflow check |

**Guard conditions:** Early exit if not in multiplayer mode (dword_7C56A0 & 1 == 0) or ScoringGate == 2 — just sets display mode and returns. If WeatherStateFlag (byte_7CF17C) is set, initializes *this from TotalRaceLaps; otherwise defaults to 1.0f. WeatherMode (dword_7CF080) branches: 0 → reads weather.txt file; 1 → tries SeasonRacesSectionFinder + linked list lookup → sub_4FE350; 3/4/5/default → built-in weather params with switch-selected mode values. Final guard: if multiplayer and ScoringGate != 2, compares race flag string and may call sub_4FC550.