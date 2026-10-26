## AIWaypointPathCheckerRenderer_004024f0 — AIWaypointPathDebugRender

**Summary:** Iterates over linked waypoint nodes starting from this+308's linked list (via +272 next pointers), renders debug visualization for each edge. Computes vertex colors based on surface grip (multiplied by -254, clamped to alpha), draws colored contact patches (sub_402220 + sub_4CEFA0) and white wireframe edges. Validates the linked list does not exceed 12000 elements (cycle detection). If no nodes, logs "Incomplete waypoint path" debug message.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4CD8D0 (004cd8d0), SpecialFX_Init (004cf070)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(*(*(this+0x134)+0x110)+0x110)+0x110) | 0x110 | R | — | nested pointer chain to D3D/scene context |
| *(*(*(*(this+0x134)+0x110)+0x110)+0x110) | 0x118 | R | — | nested pointer chain to D3D/scene context |
| *(*(*(this+0x134)+0x110)+0x110) | 0x110 | R | — | nested pointer chain to D3D/scene context |
| *(*(*(this+0x134)+0x110)+0x110) | 0x118 | R | — | nested pointer chain to D3D/scene context |
| *(this+0x134) | 0x110 | R | — | intermediate pointer dereference |
| this | 0x134 | R | — | root pointer to scene/D3D context |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e45c | flt_59E45C | R | PhysicsConstant_59E45C [DERIVED] |
| 005be400 | aIncompleteWayp | R | IncompleteWaypointString [DERIVED] |
| 005be41c | aDDevF119992002_14 | R | StrDevicePath [DERIVED] |
| 008acea0 | dword_8ACEA0 | R | ScoringGridBase [DERIVED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |
| 008b8f24 | dword_8B8F24 | R | D3DDeviceWrapperPtr [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00402220 | sub_402220 | computes wheel contact position and suspension height |
| 004cefa0 | sub_4CEFA0 | renders a debug line/primitive between two 3D points |
| 004cf010 | ArraySearchByIDWithCleanup | prepares render buffers by ID (9=colored, 10=white wireframe) |
| 004d7a50 | StringSplitLoop | splits debug string for logging when waypoint list is empty |
| 004d7aa0 | DebugLogWrite | writes "Incomplete waypoint path" to debug log |
| 0053ac70 | EmptyStubWithFlagCheck | stub with flag (2 for setup, 1 for flush) |
| 00587bdc | CRTFtol | converts float to int (for color computation) |

**Guard conditions:** If this+308's linked list pointer (v3) is NULL, logs "Incomplete waypoint path". If linked list length exceeds 12000 (cycle detection), aborts. PASSES: iterates each edge, renders both colored contact patch (if either endpoint has non-white color) and white wireframe edge, then flushes.
