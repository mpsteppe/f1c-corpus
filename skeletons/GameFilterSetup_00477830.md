## GameFilterSetup_00477830 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0xF0)+0x0) | 0x0 | R | — | [LLM] |
| *(this+0xF0) | 0x0 | R | — | [LLM] |
| *(this+0xF4) | 0x4 | R | — | [LLM] |
| this | 0xF0 | RW | 0 | [LLM] |
| this | 0xF4 | RW | 0 | [LLM] |
| this | 0xF8 | RW | 0 | [LLM] |
| this | 0xFC | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0xF0: [LLM: once/conditional? does external poke survive?]
- this 0xF4: [LLM: once/conditional? does external poke survive?]
- this 0xF8: [LLM: once/conditional? does external poke survive?]
- this 0xFC: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c6a04 | aDfcariconBmp | R | UI_CarIconBitmap [DERIVED] |
| 005c7130 | aGameFilter | R | GameFilterString [DERIVED] (also: ` — "Game Filter" string constant) |
| 005c7150 | dword_5C7150 | R | GameFilterString [DERIVED] |
| 005c7154 | dword_5C7154 | R | Renderer_ShaderFlag_5C7154 [DERIVED] |
| 005c7158 | word_5C7158 | R | word_5C7158 [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 008ac368 | unk_8AC368 | R | VehicleSetupBase [DERIVED] |
| 008ad3b4 | dword_8AD3B4 | R | GameDataDir [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004761c0 | UIObjectInit | [LLM] |
| 00477ba0 | SceneListSearchByPath | [LLM] |
| 0048ebd0 | UIDimensionCapture | [LLM] |
| 0048f5d0 | DoublyLinkedListAppend_f5d0 | [LLM] |
| 0048f640 | UIViewportLayoutCalculator | [LLM] |
| 0048fc80 | StructFieldCopy_fc80 | [LLM] |
| 00497ad0 | sub_497AD0 | [LLM] |
| 004c55b0 | TrackSceneLoader | [LLM] |
| 004c5920 | TrackNameReader | [LLM] |
| 004c62c0 | ResourceListCleanup_62c0 | [LLM] |
| 004c6330 | SceneFileFilterBuilder | [LLM] |
| 004c6780 | LinkedListRandomAccess | [LLM] |
| 00566650 | StringCopyWithBufferRealloc | [LLM] |
| 005681f0 | ConditionalDispatch_81f0 | [LLM] |
| 005871f0 | ReadFieldAtOffset0x14 | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
