## AIWaypointPathCheckerRenderer_004024f0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4CD8D0 (004cd8d0), SpecialFX_Init (004cf070)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(*(*(this+0x134)+0x110)+0x110)+0x110) | 0x110 | R | — | [LLM] |
| *(*(*(*(this+0x134)+0x110)+0x110)+0x110) | 0x118 | R | — | [LLM] |
| *(*(*(this+0x134)+0x110)+0x110) | 0x110 | R | — | [LLM] |
| *(*(*(this+0x134)+0x110)+0x110) | 0x118 | R | — | [LLM] |
| *(this+0x134) | 0x110 | R | — | [LLM] |
| this | 0x134 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e45c | flt_59E45C | R | PhysicsConstant_59E45C [DERIVED] |
| 005be400 | aIncompleteWayp | R | IncompleteWaypointString [DERIVED] |
| 005be41c | aDDevF119992002_14 | R | StrDevicePath [DERIVED] |
| 008acea0 | dword_8ACEA0 | R | ScoringGridBase [DERIVED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |
| 008b8f24 | dword_8B8F24 | R | D3DDeviceWrapperPtr [DERIVED] (also: ` — D3D device wrapper / scene manager singleton vtable (docs/22) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00402220 | sub_402220 | [LLM] |
| 004cefa0 | sub_4CEFA0 | [LLM] |
| 004cf010 | ArraySearchByIDWithCleanup | [LLM] |
| 004d7a50 | StringSplitLoop | [LLM] |
| 004d7aa0 | DebugLogWrite | [LLM] |
| 0053ac70 | EmptyStubWithFlagCheck | [LLM] |
| 00587bdc | CRTFtol | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
