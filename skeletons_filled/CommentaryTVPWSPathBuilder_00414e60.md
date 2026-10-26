## CommentaryTVPWSPathBuilder_00414e60 — CommentaryTrackTvPathBuilder

**Summary:** Builds and validates commentary track file paths in "tv" subdirectory with Country/B/Circuit/E extensions, looking up track display IDs via TrackNameDisplayIDLookup for existing files.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SceneListBuilderFromGlobalArray (00415c40)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | String pointer for scene/track name directory; fallback to byte_5EA438 if null |
| this | 0x8 | R | — | Index or ID field passed as second argument to TrackNameDisplayIDLookup |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005be860 | aSS | R | PathFormatString [DERIVED] (also: ` — format string for path construction) |
| 005c23b8 | aSSSTvS | R | String_SSSTvS [DERIVED] |
| 005c23e8 | aCircuite | R | String_Circuite [DERIVED] |
| 005c23f4 | aCircuitb | R | CircuitBString [DERIVED] |
| 005c2400 | aCountrye | R | CountryeString [DERIVED] |
| 005c240c | aCountryb | R | CountryBString [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ea5e8 | dword_5EA5E8 | R | MemoryCleanupList3 [DERIVED] |
| 005ec3d8 | dword_5EC3D8 | R | SeasonDir [DERIVED] |
| 005ec420 | dword_5EC420 | R | TrackDir [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00414900 | FilePathExtensionCheck | Checks if constructed file path with extension exists; returns 0 on success |
| 00417f60 | TrackNameDisplayIDLookup | Looks up track name display ID for found commentary files |
| 0058815f | StringFormatWithBufferOverflowCheck | Safe string formatting for path construction with buffer overflow check |

**Guard conditions:** this[0] checked for null; fallback to byte_5EA438. dword_5EC420 and dword_5EC3D8 checked for null; fallback to byte_5EA438. No early return — each FilePathExtensionCheck failure only skips TrackNameDisplayIDLookup for that variant. Function always returns 0.
