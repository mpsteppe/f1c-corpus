## sub_4BA1F0_004ba1f0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Init (0042d6b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x8) | 0xF3C | RW | — | [LLM] |
| this | 0x0 | RW | 0 | [LLM] |
| this | 0x8 | R | — | [LLM] |
| this | 0xF9C | R | — | [LLM] |

**Written-by note (persistence):**
- *(this+0x8) 0xF3C: [LLM: once/conditional? does external poke survive?]
- this 0x0: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e0dc | Sleep | R | [LLM] |
| 005d24ac | aPreppingReplay | R | PreppingReplayStr [DERIVED] |
| 005d24bc | aLoadingVcrFile | R | LoadingVcrFileString [DERIVED] |
| 005d24dc | aDDevF119992002_22 | R | DDevF119992002String [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ea43c | dword_5EA43C | R | SetupDirSuffix [DERIVED] |
| 005ec4c0 | byte_5EC4C0 | R | EmptyStringBuffer [DERIVED] |
| 005ec4cc | byte_5EC4CC | RW | MessageDisplayBuffer [DERIVED] (also: ` (byte_5EC4CC) |
| 005ec6d0 | unk_5EC6D0 | R | [LLM] |
| 007ce24d | unk_7CE24D | R | SessionTransitionFlag [DERIVED] |
| 007d0038 | dword_7D0038 | R | ScoringGateFlag [DERIVED] (also: ` — global flag) |
| 007d005c | dword_7D005C | R | SessionCleanupFlag [DERIVED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00404f10 | ConditionalFlagReturn | [LLM] |
| 00423a00 | BinarySearchInStringTable | [LLM] |
| 0042bbd0 | SetPlayerVehicleIndex | [LLM] |
| 0042bc40 | SetPlayerVehicleIndex_bc40 | [LLM] |
| 004a0e70 | SessionTypeGuard | [LLM] |
| 004b86e0 | AngleClampWrap | [LLM] |
| 004b87a0 | QueuePeek | [LLM] |
| 004b97d0 | ThunkToFUN004b7300 | [LLM] |
| 004b9810 | SingleCallWrapper_9810 | [LLM] |
| 004b9820 | WheelForceAccessor | [LLM] |
| 004b9830 | sub_4B9830 | [LLM] |
| 004b9da0 | MenuActionDispatch | [LLM] |
| 004d7a50 | StringSplitLoop | [LLM] |
| 004d7aa0 | DebugLogWrite | [LLM] |
| 005668b0 | ZeroInitSmallStruct | [LLM] |
| 005668d0 | SubCallWithConditionalFieldFree | [LLM] |
| 00566940 | sub_566940 | [LLM] |
| 00566b20 | AudioStreamOpen | [LLM] |
| 00566b90 | ConditionalFileHandleCloseWithFlagDispatch | [LLM] |
| 00566bd0 | ConditionalDispatch_6bd0 | [LLM] |
| 00566c00 | FileWriteWithBackendDispatch | [LLM] |
| 00568540 | FileAttributesExistenceCheck | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | == | 2 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
