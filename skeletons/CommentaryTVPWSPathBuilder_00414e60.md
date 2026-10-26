## CommentaryTVPWSPathBuilder_00414e60 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SceneListBuilderFromGlobalArray (00415c40)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | [LLM] |
| this | 0x8 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005be860 | aSS | R | PathFormatString [DERIVED] (also: ` â€” format string for path construction) |
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
| 00414900 | FilePathExtensionCheck | [LLM] |
| 00417f60 | TrackNameDisplayIDLookup | [LLM] |
| 0058815f | StringFormatWithBufferOverflowCheck | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
