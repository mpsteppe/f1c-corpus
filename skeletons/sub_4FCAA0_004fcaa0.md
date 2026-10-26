## sub_4FCAA0_004fcaa0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Init (0042d6b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | RW | 1065353216 → 1.0f | [LLM] |
| this | 0x10 | RW | 18446744073709551615 | [LLM] |
| this | 0x18 | RW | 18446744072627421184 → -1.0f | [LLM] |
| this | 0xA4 | RW | 18446744072627421184 → -1.0f | [LLM] |
| this | 0xA8 | R | — | [LLM] |
| this | 0xB4 | RW | — | [LLM] |
| this | 0xB8 | RW | — | [LLM] |
| this | 0xBC | RW | — | [LLM] |
| this | 0xC0 | RW | 1061158912 → 0.75f | [LLM] |
| this | 0xC4 | RW | 1061158912 → 0.75f | [LLM] |
| this | 0xC8 | RW | 1061158912 → 0.75f | [LLM] |
| this | 0xCC | RW | 1056964608 → 0.5f | [LLM] |
| this | 0xD0 | RW | 1056964608 → 0.5f | [LLM] |
| this | 0xD4 | RW | 1056964608 → 0.5f | [LLM] |
| this | 0xE0 | R | — | [LLM] |
| this | 0xE4 | RW | 1127153664 → 175.0f | [LLM] |
| this | 0xE8 | RW | 1143521280 → 675.0f | [LLM] |
| this | 0xEC | RW | — | [LLM] |
| this | 0xF0 | RW | 0 | [LLM] |
| this | 0xF4 | RW | 1125515264 → 150.0f | [LLM] |
| this | 0xF8 | RW | 1008981770 → 0.01f | [LLM] |
| this | 0x1C4 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0xC: [LLM: once/conditional? does external poke survive?]
- this 0x10: [LLM: once/conditional? does external poke survive?]
- this 0x18: [LLM: once/conditional? does external poke survive?]
- this 0xA4: [LLM: once/conditional? does external poke survive?]
- this 0xB4: [LLM: once/conditional? does external poke survive?]
- this 0xB8: [LLM: once/conditional? does external poke survive?]
- this 0xBC: [LLM: once/conditional? does external poke survive?]
- this 0xC0: [LLM: once/conditional? does external poke survive?]
- this 0xC4: [LLM: once/conditional? does external poke survive?]
- this 0xC8: [LLM: once/conditional? does external poke survive?]
- this 0xCC: [LLM: once/conditional? does external poke survive?]
- this 0xD0: [LLM: once/conditional? does external poke survive?]
- this 0xD4: [LLM: once/conditional? does external poke survive?]
- this 0xE4: [LLM: once/conditional? does external poke survive?]
- this 0xE8: [LLM: once/conditional? does external poke survive?]
- this 0xEC: [LLM: once/conditional? does external poke survive?]
- this 0xF0: [LLM: once/conditional? does external poke survive?]
- this 0xF4: [LLM: once/conditional? does external poke survive?]
- this 0xF8: [LLM: once/conditional? does external poke survive?]
- this 0x1C4: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e444 | flt_59E444 | R | FrameDelta [DERIVED] (also: ` — float 0.016667 (1/60, frame delta) |
| 0059e460 | flt_59E460 | R | AlphaScaleFactor [DERIVED] |
| 005d6f68 | aSweatherTxt | R | StrSWeatherTxt [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec438 | dword_5EC438 | R | WeatherDir [DERIVED] (also: ` — SeasonDir/LoadPath, docs/12) |
| 007cf080 | dword_7CF080 | R | WeatherMode (0-5) [DERIVED] |
| 008afe88 | dword_8AFE88 | R | CollisionGeometryHandle [DERIVED] (also: ` — global collision geometry handle) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004fba10 | sub_4FBA10 | [LLM] |
| 004fd840 | DualLinkedListDestruction | [LLM] |
| 004fd8b0 | sub_4FD8B0 | [LLM] |
| 004fe820 | WeatherConditionsFileWriter | [LLM] |
| 004fefc0 | ClampedReciprocalWithGuard | [LLM] |
| 004ff040 | ValueClampRange | [LLM] |
| 005439f0 | ShortFieldAccessor | [LLM] |
| 00543a30 | GetOrientationAngleValues | [LLM] |
| 00543a60 | FieldGetter_3a60 | [LLM] |
| 0058815f | StringFormatWithBufferOverflowCheck | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
