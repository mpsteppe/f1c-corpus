## ProcessDriverEntries_004b8da0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ConditionalMultiPathDispatcher (004ba180)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x40) | 0x0 | R | — | [LLM] |
| this | 0x40 | R | — | [LLM] |
| this | 0x48 | RW | — | [LLM] |
| this | 0x4C | R | — | [LLM] |
| this | 0xF38 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x48: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c329c | dword_5C329C | RW | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec6d0 | unk_5EC6D0 | R | [LLM] |
| 005ec6d8 | unk_5EC6D8 | R | VEH[0].0x0 = postProcessInput [CONFIRMED] |
| 007c54d8 | byte_7C54D8 | R | VehicleArrayEnd [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042bc80 | BuildActiveVehiclePointerArray | [LLM] |
| 004b50c0 | UtilityFunction_50c0 | [LLM] |
| 004c6980 | SetDriverName | [LLM] |
| 004c69e0 | PathFilenameExtractor | [LLM] |
| 004c6c40 | VehgenScnFileLoader | [LLM] |
| 004c6d90 | SceneRenderUpdate | [LLM] |
| 004c6e80 | sub_4C6E80 | [LLM] |
| 004c7b20 | TwoCallDelegation | [LLM] |
| 004ef5a0 | SessionStateTransition | [LLM] |
| 00566650 | StringCopyWithBufferRealloc | [LLM] |
| 00588410 | sub_588410 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x40 | == | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
