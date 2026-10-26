## PitCrewMeshLoader_004a2010 — PitCrewMeshLoader

**Summary:** Loads pit crew member meshes into the scene graph. Guards on detail level threshold, allocates mesh resources, walks sub-mesh linked list, appends nodes to actor node list, and builds child index table. Falls back to error logging on allocation failure.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** StringCopyWithReverse (004a21d0), ModeDependentSubsystemCall (004a2770)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | detail level threshold (__int16) compared against global DetailLevel |
| this | 0x64 | R | — | mesh resource handle returned by MeshResourceAllocator |
| this | 0x68 | RW | — | child count after scene graph population |
| this | 0x6C | RW | — | child index table pointer (allocated array) |

**Written-by note (persistence):**
- this 0x68: written once after mesh loading; persists as child count
- this 0x6C: written once after allocation; persists as index table

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005cd14c | aCubeErrorLoadi | R | CubeErrorLoadingString [DERIVED] |
| 005cd174 | aDDevF119992002_2 | R | Str_DDevF119992002 [DERIVED] |
| 007cf884 | dword_7CF884 | R | DetailLevel [DERIVED] (also: ` — detail level (≤1 = load pitcrew meshes) |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |
| 008afe64 | dword_8AFE64 | R | RaceTimeDelta [DERIVED] |
| 008afe88 | dword_8AFE88 | R | CollisionGeometryHandle [DERIVED] (also: ` — global collision geometry handle) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d7a50 | StringSplitLoop | Parses debug string for error logging |
| 004d7aa0 | DebugLogWrite | Writes mesh load error to debug log |
| 0053c5b0 | StringRelocationCopy | Copies error string for reporting |
| 005450e0 | MeshResourceAllocator | Allocates mesh resource by name and size |
| 00545250 | ActorNodeLinkedListAppend | Appends loaded mesh to actor node list |
| 00545930 | LinkedListNodeInsert_5930 | Inserts node into linked list with position |
| 0054a870 | sub_54A870 | Processes mesh node data |
| 0054ba00 | DoublyLinkedListNodeMover | Moves node to front of doubly-linked list |
| 0054c210 | SceneGraphChildCount | Counts children in scene graph branch |
| 0054c230 | LinkedListIndexedAccessor_c230 | Accesses linked list node by index |
| 00587c03 | OperatorNewNhMallocWrapper | Allocates child index table |

**Guard conditions:** If a3 (mesh data pointer) is NULL → returns -1. If global DetailLevel (dword_7CF884) is less than this[0] (detail threshold) → returns 0 (skip mesh). If MeshResourceAllocator fails → logs error via StringRelocationCopy/DebugLogWrite and returns -1. On success, processes sub-mesh linked list, appends to scene graph, and returns 0.
