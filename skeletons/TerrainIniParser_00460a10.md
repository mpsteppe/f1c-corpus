## TerrainIniParser_00460a10 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** NetCommSessionMessageDispatcher (0045d890)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1B754 | R | — | [LLM] |
| this | 0x1B755 | R | — | [LLM] |
| this | 0x1B76A | RW | 1 | [LLM] |
| this | 0x1B76B | RW | 1 | [LLM] |
| this | 0x1B76C | RW | 1 | [LLM] |
| this | 0x1B76D | RW | 1 | [LLM] |
| this | 0x1B76E | RW | 1 | [LLM] |

**Written-by note (persistence):**
- this 0x1B76A: [LLM: once/conditional? does external poke survive?]
- this 0x1B76B: [LLM: once/conditional? does external poke survive?]
- this 0x1B76C: [LLM: once/conditional? does external poke survive?]
- this 0x1B76D: [LLM: once/conditional? does external poke survive?]
- this 0x1B76E: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005be860 | aSS | R | PathFormatString [DERIVED] (also: ` â€” format string for path construction) |
| 005c5b88 | aTerrainIni | R | TerrainIniString [DERIVED] (also: ` — "terrain.ini" string constant) |
| 005c5d24 | dword_5C5D24 | R | SeasonRacesSuffix1 [DERIVED] |
| 005c5d28 | byte_5C5D28 | R | SeasonRacesSuffix2 [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec3d8 | dword_5EC3D8 | R | SeasonDir [DERIVED] |
| 007ce5d0 | dword_7CE5D0 | R | CurrentTrackPath [DERIVED] |
| 007d0434 | dword_7D0434 | R | SeasonPath [DERIVED] |
| 008aced8 | dword_8ACED8 | R | TerrainINICRCOffset [DERIVED] (also: ` — CRC offset constant) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0045c320 | SceneFileMatchByName | [LLM] |
| 00460770 | HashChecksumComputation | [LLM] |
| 00587dd0 | sub_587DD0 | [LLM] |
| 0058969d | StringFormatProcessingWithNullTerm | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
