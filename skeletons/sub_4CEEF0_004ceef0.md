## sub_4CEEF0_004ceef0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SceneTrackFileLoader (0044c0e0), ParticleSoundEffectSpawner (004607a0), SpecialFX_Init (004cf070), TelemetryDataDump (004d4a80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d3930 | aSSterrainIni | R | STerrainIniString [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec3d8 | dword_5EC3D8 | R | SeasonDir [DERIVED] |
| 005ec420 | dword_5EC420 | R | TrackDir [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058815f | StringFormatWithBufferOverflowCheck | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
