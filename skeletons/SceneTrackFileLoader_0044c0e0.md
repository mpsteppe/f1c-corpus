## SceneTrackFileLoader_0044c0e0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SpecialFX_Init (004cf070)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c448c | dword_5C448C | R | StringWeather [DERIVED] |
| 005c4494 | aScn_0 | R | ScnFileExtension [DERIVED] |
| 005c449c | aHat_0 | R | HatField [DERIVED] |
| 005c44a4 | aHat | R | Path_HatExtension [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec438 | dword_5EC438 | R | WeatherDir [DERIVED] (also: ` — SeasonDir/LoadPath, docs/12) |
| 007ce5d0 | dword_7CE5D0 | R | CurrentTrackPath [DERIVED] |
| 007cfee8 | byte_7CFEE8 | R | Unknown_Byte_WeatherFlag [DERIVED] |
| 008acea0 | dword_8ACEA0 | R | ScoringGridBase [DERIVED] |
| 008b8f24 | dword_8B8F24 | R | D3DDeviceWrapperPtr [DERIVED] (also: ` — D3D device wrapper / scene manager singleton vtable (docs/22) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004492b0 | CollisionShapeInit | [LLM] |
| 00449340 | PhysicsBufferFree | [LLM] |
| 00449a20 | RegistryKeyQuery | [LLM] |
| 0044b910 | BoundingBoxComputationFromTriangles | [LLM] |
| 0044ba40 | CollisionGridRaycast32x32 | [LLM] |
| 0044bb60 | CollisionGeometryOperationSelector | [LLM] |
| 0044bc50 | sub_44BC50 | [LLM] |
| 0044be70 | HTreeTerrainFileFormatLoader | [LLM] |
| 0044c430 | SinTableInit | [LLM] |
| 0044c470 | CollisionTreeNodeCleanup | [LLM] |
| 004ceef0 | sub_4CEEF0 | [LLM] |
| 0053ac70 | EmptyStubWithFlagCheck | [LLM] |
| 005665b0 | sub_5665B0 | [LLM] |
| 00566650 | StringCopyWithBufferRealloc | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |
| 00587c20 | sub_587C20 | [LLM] |
| 00587dd0 | sub_587DD0 | [LLM] |
| 00589671 | CreateDirectoryAWrapper | [LLM] |
| 00589901 | sub_589901 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
