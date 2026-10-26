## sub_4CEEF0_004ceef0 — BuildTerrainIniPath

**Summary:** Constructs the file path to terrain.ini by formatting season and track directory paths into a string buffer. Falls back to default application directory if either directory global is null.

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
| 0058815f | StringFormatWithBufferOverflowCheck | safe string formatting with buffer overflow guard |

**Guard conditions:** If dword_5EC420 (track dir) is null → fall back to byte_5EA438 (default dir). If dword_5EC3D8 (season dir) is null → fall back to byte_5EA438.
