## SceneFileFilterBuilder_004c6330 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GameFilterSetup (00477830)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xC) | 0x4 | RW | 0 | [LLM] |
| this | 0x8 | RW | — | [LLM] |
| this | 0xC | RW | — | [LLM] |
| this | 0x10 | RW | — | [LLM] |
| this | 0x14 | RW | — | [LLM] |
| this | 0x18 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- *(this+0xC) 0x4: [LLM: once/conditional? does external poke survive?]
- this 0x8: [LLM: once/conditional? does external poke survive?]
- this 0xC: [LLM: once/conditional? does external poke survive?]
- this 0x10: [LLM: once/conditional? does external poke survive?]
- this 0x14: [LLM: once/conditional? does external poke survive?]
- this 0x18: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d30c0 | dword_5D30C0 | R | StringCompConstantBlock [DERIVED] |
| 005d30c4 | dword_5D30C4 | R | NetSessionInfo_5D30C4 [DERIVED] |
| 005d30c8 | byte_5D30C8 | R | Byte_NetCheckFlags_30C8 [DERIVED] |
| 005d30cc | dword_5D30CC | R | MessageBoxConfig [DERIVED] |
| 005d30d0 | byte_5D30D0 | R | MPRegionSelectFlags [DERIVED] |
| 005d30d4 | dword_5D30D4 | R | FilterCategoryPat0 [DERIVED] (also: `/etc — filter category name patterns (copied from static data) |
| 005d30d8 | byte_5D30D8 | R | FilterCategoryName [DERIVED] |
| 005d31ec | aFilterProperti | R | FilterPropertiesString [DERIVED] (also: ` — "Filter Properties" string constant) |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 007d0398 | dword_7D0398 | R | PhotoFreeCameraFlag [DERIVED] (also: � photo/free camera mode flag) |
| 007d0410 | dword_7D0410 | R | ChampionshipMode [FACT] (also: RaceMode) |
| 008ac368 | unk_8AC368 | R | VehicleSetupBase [DERIVED] |
| 008ac488 | dword_8AC488 | R | SceneFileCount [DERIVED] |
| 008ac490 | dword_8AC490 | R | SceneArray (stride 0x18c) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004c58a0 | StringCopyWithValidation | [LLM] |
| 004c5c80 | sub_4C5C80 | [LLM] |
| 004c5d30 | SceneSortComparator | [LLM] |
| 004c5e50 | FilterPropertiesListBuilder | [LLM] |
| 004c5fd0 | FilterPropertiesListBuilder_5fd0 | [LLM] |
| 004c6150 | FilterPropertiesListNodeRemover | [LLM] |
| 004c62c0 | ResourceListCleanup_62c0 | [LLM] |
| 004c6810 | MergeSortLinkedList | [LLM] |
| 00566650 | StringCopyWithBufferRealloc | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |
| 00587dd0 | sub_587DD0 | [LLM] |
| 00588410 | sub_588410 | [LLM] |
| 005897ca | sub_5897CA | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
