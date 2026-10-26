## CockpitDashboardLEDGaugeSetup_0049ca00 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** NetCommPlayerSlotSync (0045fc50), OnScreen_Init (0049efa0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 1 | [LLM] |
| this | 0x4 | R | — | [LLM] |
| this | 0x8 | R | — | [LLM] |
| this | 0xC | R | — | [LLM] |
| this | 0x10 | RW | — | [LLM] |
| this | 0x14 | RW | — | [LLM] |
| this | 0x18 | R | — | [LLM] |
| this | 0x1C | R | — | [LLM] |
| this | 0x20 | RW | — | [LLM] |
| this | 0x24 | RW | — | [LLM] |
| this | 0x28 | RW | — | [LLM] |
| this | 0x2C | RW | — | [LLM] |
| this | 0x30 | RW | — | [LLM] |
| this | 0x34 | RW | — | [LLM] |
| this | 0x38 | RW | — | [LLM] |
| this | 0x3C | RW | — | [LLM] |
| this | 0x40 | RW | — | [LLM] |
| this | 0x44 | RW | — | [LLM] |
| this | 0x48 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: once/conditional? does external poke survive?]
- this 0x10: [LLM: once/conditional? does external poke survive?]
- this 0x14: [LLM: once/conditional? does external poke survive?]
- this 0x20: [LLM: once/conditional? does external poke survive?]
- this 0x24: [LLM: once/conditional? does external poke survive?]
- this 0x28: [LLM: once/conditional? does external poke survive?]
- this 0x2C: [LLM: once/conditional? does external poke survive?]
- this 0x30: [LLM: once/conditional? does external poke survive?]
- this 0x34: [LLM: once/conditional? does external poke survive?]
- this 0x38: [LLM: once/conditional? does external poke survive?]
- this 0x3C: [LLM: once/conditional? does external poke survive?]
- this 0x40: [LLM: once/conditional? does external poke survive?]
- this 0x44: [LLM: once/conditional? does external poke survive?]
- this 0x48: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c6784 | aSSS_0 | R | sFormatPath [DERIVED] |
| 005ccb58 | off_5CCB58 | R | Ptr_DAT_5CCB58 [DERIVED] |
| 005ccb5c | off_5CCB5C | R | Ptr_FunctionTable3 [DERIVED] |
| 005ccb60 | off_5CCB60 | R | Off5CCB60 [DERIVED] |
| 005ccb64 | off_5CCB64 | R | Unknown_VTable_5CCB64 [DERIVED] |
| 005ccb68 | off_5CCB68 | R | Ptr_VTable_5CCB68 [DERIVED] |
| 005ccb6c | off_5CCB6C | R | VTableFunc_Anim2 [DERIVED] |
| 005ccb70 | off_5CCB70 | R | Unknown_VTable_5CCB70 [DERIVED] |
| 005ccb74 | off_5CCB74 | R | VTableFunc_Anim1 [DERIVED] |
| 005ccb78 | off_5CCB78 | R | DebugCallbackVTable [DERIVED] |
| 005ccb7c | off_5CCB7C | R | VTableOrPtr_5CCB7C [DERIVED] |
| 005ccb80 | off_5CCB80 | R | VtablePtr_5CCB80 [DERIVED] |
| 005ccb88 | off_5CCB88 | R | UIManagerVTable [DERIVED] |
| 005ccb8c | off_5CCB8C | R | VTablePtr3 [DERIVED] |
| 005ccb90 | off_5CCB90 | R | PageJumpTable [DERIVED] |
| 005ccb94 | off_5CCB94 | R | Off_5CCB94 [DERIVED] |
| 005ccb98 | off_5CCB98 | R | Off_5CCB98_UI [DERIVED] |
| 005ccb9c | off_5CCB9C | R | FileDataPtr_5CCB9C [DERIVED] |
| 005ccba0 | off_5CCBA0 | R | VTable_FUN_0049ca00 [DERIVED] |
| 005ccba4 | off_5CCBA4 | R | OffscreenBufferPtr [DERIVED] |
| 005ccba8 | off_5CCBA8 | R | off_5CCBA8 [DERIVED] |
| 005ccbac | off_5CCBAC | R | ScoringConfigTable [DERIVED] |
| 005ccbb0 | off_5CCBB0 | R | VTablePtr_5CCBB0 [DERIVED] |
| 005ccea8 | aSBmp | R | FormatStrBmp [DERIVED] |
| 005cceb0 | aCmapsMas | R | TrackCmapsMas [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec3d8 | dword_5EC3D8 | R | SeasonDir [DERIVED] |
| 005ec428 | dword_5EC428 | R | SeasonName [DERIVED] |
| 008afe64 | dword_8AFE64 | R | RaceTimeDelta [DERIVED] |
| 008afe88 | dword_8AFE88 | R | CollisionGeometryHandle [DERIVED] (also: ` — global collision geometry handle) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0049cd80 | sub_49CD80 | [LLM] |
| 0053cb20 | MemoryAllocation_cb20 | [LLM] |
| 0053cbc0 | sub_53CBC0 | [LLM] |
| 0053ce40 | PhysicsObjectLinkedListRemoval | [LLM] |
| 0053cfe0 | sub_53CFE0 | [LLM] |
| 00545f40 | ValueGetter | [LLM] |
| 00547920 | StringSearchInLinkedList | [LLM] |
| 00548890 | sub_548890 | [LLM] |
| 0058815f | StringFormatWithBufferOverflowCheck | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
