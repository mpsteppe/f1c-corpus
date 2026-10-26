## SceneTrackFileLoader_0044c0e0 — Scene Track File Loader with Collision Rebuild

**Summary:** Loads a scene/track terrain file (.scn/.hat format), validates freshness via registry timestamp queries, and conditionally rebuilds collision geometry including bounding boxes and directory structure. Handles weather-dependent path selection and creates required directory hierarchy.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SpecialFX_Init (004cf070)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c448c | dword_5C448C | R | weather-dependent string identifier (copied byte-by-byte into path buffer) |
| 005c4494 | aScn_0 | R | ".scn" — scene file extension string for path construction |
| 005c449c | aHat_0 | R | "^" — hat/caret separator field appended during path building |
| 005c44a4 | aHat | R | ".hat" — terrain file extension string |
| 005ea438 | byte_5EA438 | R | default application directory path (fallback when other paths are null) |
| 005ec438 | dword_5EC438 | R | weather/season-specific directory path |
| 007ce5d0 | dword_7CE5D0 | R | current track/scene file path (source for directory extraction and .scn building) |
| 007cfee8 | byte_7CFEE8 | R | weather mode flag — when set, bypasses registry timestamp checks entirely |
| 008acea0 | dword_8ACEA0 | R | unknown (not directly visible in this function's decompiled C) |
| 008b8f24 | dword_8B8F24 | R | D3D device wrapper pointer — gates debug/profile stubs at function entry/exit |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004492b0 | CollisionShapeInit | initialize collision shape data structures |
| 00449340 | PhysicsBufferFree | release physics buffer memory |
| 00449a20 | RegistryKeyQuery | query registry for file timestamp/version to check freshness |
| 0044b910 | BoundingBoxComputationFromTriangles | compute bounding box from triangle mesh data |
| 0044ba40 | CollisionGridRaycast32x32 | perform raycast on 32x32 collision grid |
| 0044bb60 | CollisionGeometryOperationSelector | select and apply collision geometry operation |
| 0044bc50 | sub_44BC50 | save/persist collision geometry data to file |
| 0044be70 | HTreeTerrainFileFormatLoader | load hierarchical tree terrain file format |
| 0044c430 | SinTableInit | initialize sine lookup table for math operations |
| 0044c470 | CollisionTreeNodeCleanup | free and cleanup collision tree node hierarchy |
| 004ceef0 | sub_4CEEF0 | retrieve 256-byte string value (likely from config/registry) |
| 0053ac70 | EmptyStubWithFlagCheck | debug/profile no-op stub gated by D3D device flag |
| 005665b0 | sub_5665B0 | append string to path buffer |
| 00566650 | StringCopyWithBufferRealloc | copy string, reallocating destination buffer if needed |
| 00587bcf | FreeWrapper_7bcf | free allocated memory buffer |
| 00587c03 | OperatorNewNhMallocWrapper | allocate memory with new-handler fallback |
| 00587c20 | sub_587C20 | string comparison/search (strstr-like) — used to find ".scn", ".hat", etc. |
| 00587dd0 | sub_587DD0 | bounded string copy with length limit (strncpy-like) |
| 00589671 | CreateDirectoryAWrapper | create directory (recursive, creates intermediate dirs as needed) |
| 00589901 | sub_589901 | transform/process string (likely case conversion or normalization) |

**Guard conditions:**
1. `dword_8B8F24` (D3D device) → EmptyStubWithFlagCheck: debug stub at entry (non-blocking).
2. `!dword_7CE5D0` (track path null) → use byte_5EA438 fallback: null-guard on track path.
3. `!dword_5EC438` (weather dir null) → use byte_5EA438 fallback: null-guard on weather directory.
4. `!v26` (filename buffer null) → use byte_5EA438 fallback: null-guard on allocated buffer.
5. `byte_7CFEE8` (weather flag set) → goto LABEL_36, skip registry checks: **BLOCKS** timestamp validation; forces collision rebuild in weather mode.
6. `RegistryKeyQuery(filename) >= stored_timestamp` → goto LABEL_36: **BLOCKS** reload when file is already current (timestamp not newer).
7. `RegistryKeyQuery(track_path) >= stored_timestamp` → goto LABEL_36: same freshness check on track path.
8. `sub_587C20(SrcStr, ".scn") == null` → goto LABEL_36: **BLOCKS** when ".scn" extension not found in path string.
9. `RegistryKeyQuery(SrcStr .scn path) >= stored_timestamp` → goto LABEL_36: freshness check on .scn file.
10. `RegistryKeyQuery(v30 256-byte string) >= stored_timestamp` → goto LABEL_36: freshness check on config string.
11. `HTreeTerrainFileFormatLoader succeeds` → enter collision rebuild path (LABEL_36), else skip to raycast only. Collision is rebuilt when any timestamp check indicates newer files OR weather mode is active.
