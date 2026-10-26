## FileScanner_0045c240 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DriverEntrantSetupEntry (00462550)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x4)+0x0) | 0x0 | R | — | [LLM] |
| *(*(this+0x4)+0x4) | 0x4 | R | — | [LLM] |
| *(this+0x4) | 0x0 | R | — | [LLM] |
| *(this+0x4) | 0x8 | R | — | [LLM] |
| this | 0x0 | RW | — | [LLM] |
| this | 0x1 | RW | — | [LLM] |
| this | 0x4 | RW | 0 | [LLM] |
| this | 0x8 | RW | 0 | [LLM] |
| this | 0xC | RW | 0 | [LLM] |
| this | 0x10 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: once/conditional? does external poke survive?]
- this 0x1: [LLM: once/conditional? does external poke survive?]
- this 0x4: [LLM: once/conditional? does external poke survive?]
- this 0x8: [LLM: once/conditional? does external poke survive?]
- this 0xC: [LLM: once/conditional? does external poke survive?]
- this 0x10: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c5b88 | aTerrainIni | R | TerrainIniString [DERIVED] (also: ` — "terrain.ini" string constant) |
| 005c5b94 | aHdv_0 | R | HDVString [DERIVED] |
| 005c5b9c | aGdb | R | GdbField [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec3d8 | dword_5EC3D8 | R | SeasonDir [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0045c0c0 | sub_45C0C0 | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |
| 005884ed | RandLCGRandomNumberGenerator | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
