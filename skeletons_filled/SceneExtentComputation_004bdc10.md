## SceneExtentComputation_004bdc10 — SceneExtentComputation

**Summary:** Computes bounding box of all scene collision objects by iterating the collision geometry tree, tracking min/max X and Z coordinates. Stores normalized extents (min X, min Z, scale X = 8.0/rangeX, scale Z = 8.0/rangeZ) for rendering. Logs error string if no valid extent found.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Init (0042d6b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x924 | RW | — | min X extent of scene |
| this | 0x928 | RW | — | scale X = 8.0 / (maxX - minX) |
| this | 0x92C | RW | — | min Z extent of scene |
| this | 0x930 | RW | — | scale Z = 8.0 / (maxZ - minZ) |

**Written-by note (persistence):**
- this 0x924: written once after computation; survives as scene extent for rest of session
- this 0x928: written once; survives 
- this 0x92C: written once; survives
- this 0x930: written once; survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e4dc | flt_59E4DC | R | FullResponseThreshold [DERIVED] (also: ` — full response threshold (float) |
| 005d25d0 | aCouldNotGetExt | R | String_CouldNotGetExt [DERIVED] — error message string |
| 005d2604 | aDDevF119992002_23 | R | DebugSourcePath_F1C [DERIVED] — source file path for debug logging |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] — debug output buffer |
| 008afe88 | dword_8AFE88 | R | CollisionGeometryHandle [DERIVED] (also: ` — global collision geometry handle) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d7a50 | StringSplitLoop | retrieves debug string for error message logging |
| 004d7aa0 | DebugLogWrite | writes error log when scene extents are invalid |
| 004dd550 | BoundingBoxComputation | computes AABB of a scene node |
| 005452f0 | AudioNetworkNodeCount | counts nodes in collision geometry tree |
| 00545340 | LinkedListNodeFinder | iterates to Nth node in collision geometry tree |
| 0054fb70 | LinkedListFlagBitExtraction | checks node flags (requires bit 4 clear and node active) |

**Guard conditions:** PASSES when at least one valid node produces non-degenerate bounds (max > min in both X and Z). BLOCKED (error path) when no nodes processed or bounds are degenerate (maxX <= minX or maxZ <= minZ).
