## FrontendScreenLoadingDisplayHandler_00476250 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x40) | 0x1C | R | — | [LLM] |
| this | 0x40 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005be860 | aSS | R | PathFormatString [DERIVED] (also: ` â€” format string for path construction) |
| 005c7130 | aGameFilter | R | GameFilterString [DERIVED] (also: ` — "Game Filter" string constant) |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec3d8 | dword_5EC3D8 | R | SeasonDir [DERIVED] |
| 007cd8bc | String1 | R | LocaleTestStringA [DERIVED] |
| 007cd8c0 | dword_7CD8C0 | R | GameCommandDispatchInterface [DERIVED] (also: ` — game command dispatch interface pointer) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00476f90 | SingleFunctionDispatch_6f90 | [LLM] |
| 0048f590 | LinkedListIndexedAccessor_f590 | [LLM] |
| 00566650 | StringCopyWithBufferRealloc | [LLM] |
| 00567a00 | StructZeroInit_7a00 | [LLM] |
| 00567a30 | LinkedListDestructorWithInnerFree | [LLM] |
| 00567f40 | AudioFileLoadDecode | [LLM] |
| 005681f0 | ConditionalDispatch_81f0 | [LLM] |
| 0058969d | StringFormatProcessingWithNullTerm | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
