## sub_4FCC30_004fcc30 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Restart (0042d7a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 1065353216 → 1.0f | [LLM] |
| this | 0x4 | RW | 0 | [LLM] |
| this | 0x8 | RW | — | [LLM] |
| this | 0x14 | RW | 0 | [LLM] |
| this | 0x1C | RW | 0 | [LLM] |
| this | 0x20 | R | — | [LLM] |
| this | 0x24 | R | — | [LLM] |
| this | 0x28 | RW | — | [LLM] |
| this | 0x2C | RW | — | [LLM] |
| this | 0x30 | RW | — | [LLM] |
| this | 0x34 | RW | — | [LLM] |
| this | 0x38 | RW | — | [LLM] |
| this | 0x3C | RW | — | [LLM] |
| this | 0x40 | RW | 1 | [LLM] |
| this | 0x44 | RW | 18446744073701163007 | [LLM] |
| this | 0x48 | RW | 0 | [LLM] |
| this | 0x4A | RW | 18446744073709551615 | [LLM] |
| this | 0x4C | RW | 18446744073709551615 | [LLM] |
| this | 0x4E | RW | 0 | [LLM] |
| this | 0x50 | RW | 32767 | [LLM] |
| this | 0x52 | RW | 18446744073709518848 | [LLM] |
| this | 0x104 | RW | — | [LLM] |
| this | 0x1CF | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: once/conditional? does external poke survive?]
- this 0x4: [LLM: once/conditional? does external poke survive?]
- this 0x8: [LLM: once/conditional? does external poke survive?]
- this 0x14: [LLM: once/conditional? does external poke survive?]
- this 0x1C: [LLM: once/conditional? does external poke survive?]
- this 0x28: [LLM: once/conditional? does external poke survive?]
- this 0x2C: [LLM: once/conditional? does external poke survive?]
- this 0x30: [LLM: once/conditional? does external poke survive?]
- this 0x34: [LLM: once/conditional? does external poke survive?]
- this 0x38: [LLM: once/conditional? does external poke survive?]
- this 0x3C: [LLM: once/conditional? does external poke survive?]
- this 0x40: [LLM: once/conditional? does external poke survive?]
- this 0x44: [LLM: once/conditional? does external poke survive?]
- this 0x48: [LLM: once/conditional? does external poke survive?]
- this 0x4A: [LLM: once/conditional? does external poke survive?]
- this 0x4C: [LLM: once/conditional? does external poke survive?]
- this 0x4E: [LLM: once/conditional? does external poke survive?]
- this 0x50: [LLM: once/conditional? does external poke survive?]
- this 0x52: [LLM: once/conditional? does external poke survive?]
- this 0x104: [LLM: once/conditional? does external poke survive?]
- this 0x1CF: [LLM: once/conditional? does external poke survive?]

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
| 004c5840 | SeasonRacesSectionFinder | [LLM] |
| 004fc550 | sub_4FC550 | [LLM] |
| 004fc9a0 | FloatArrayInitializer | [LLM] |
| 004fd6f0 | RangeInterpolationTable | [LLM] |
| 004fd840 | DualLinkedListDestruction | [LLM] |
| 004fde00 | sub_4FDE00 | [LLM] |
| 004fe350 | sub_4FE350 | [LLM] |
| 004fe7c0 | sub_4FE7C0 | [LLM] |
| 004feaf0 | AudioEventRingBufferProcessing | [LLM] |
| 00543960 | DisplayModeSetter | [LLM] |
| 005679c0 | StringKeyedLinkedListSearch | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |
| 00587dd0 | sub_587DD0 | [LLM] |
| 0058815f | StringFormatWithBufferOverflowCheck | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
