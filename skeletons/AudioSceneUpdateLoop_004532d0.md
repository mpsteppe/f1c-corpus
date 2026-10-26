## AudioSceneUpdateLoop_004532d0 — Process audio scenes for collision parameters

**Summary:** Iterates over audio/scene configurations (up to count at 0xD80), reading HUD state data from a global array (unk_7D1448) and calling CollisionParameterClampAndStore for 8 sub-elements per scene. Processes two data regions (at offsets 0xD88 and 0x1184) for each scene. Called during HWInput_Init.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** HWInput_Init (00455d50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xD80 | R | — | Scene count — number of audio/scene configurations to process |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007d1448 | unk_7D1448 | R | HUDStateArray [DERIVED] — scene HUD data source (864 bytes per scene, 27-float sub-element stride) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0044fc20 | CollisionParameterClampAndStore | Clamps and stores collision/force-feedback parameter for each sub-element |

**Guard conditions:** BLOCKED if count at 0xD80 <= 0 → skip processing. Otherwise iterates 1 or 2 scenes based on count value.
