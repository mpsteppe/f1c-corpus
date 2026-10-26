## MultiplayerSessionJoinHandler_0046de10 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x40)+0x0) | 0x1C | R | — | [LLM] |
| *(this+0x40) | 0x0 | R | — | [LLM] |
| obj | 0x38 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x40 | R | — | [LLM] |
| this | 0xE4 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0xE4: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 005c329c | dword_5C329C | W | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 005c6590 | aClientTeamSele | R | StrClientTeamSelect [DERIVED] |
| 005c6824 | aDDevF119992002_28 | R | SourceFile_DEvF1 [DERIVED] |
| 005c6c8c | aMaxPlayersD | R | MaxPlayersField [DERIVED] |
| 005c6ca4 | aHumanOppD | R | Format_HumanOppD [DERIVED] |
| 005c6cbc | aAiOppD | R | String_AiOppD [DERIVED] |
| 005c6cd4 | aSceneBaseS | R | SceneBaseSString [DERIVED] |
| 005c6cec | aSessionNameS | R | SessionNameSString [DERIVED] |
| 005c6d08 | aJoinSessionWas | R | JoinSessionWasString [DERIVED] |
| 005c6d48 | aJoinFailurePag | R | s_DebugJoinFailurePage [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec4c0 | byte_5EC4C0 | R | EmptyStringBuffer [DERIVED] |
| 005ec4cc | byte_5EC4CC | RW | MessageDisplayBuffer [DERIVED] (also: ` (byte_5EC4CC) |
| 005ec6d0 | unk_5EC6D0 | R | [LLM] |
| 005ec6e4 | unk_5EC6E4 | R | VEH[0].0xC [LLM: field purpose] |
| 007c54e4 | dword_7C54E4 | R | CurrentVehicleIndex [DERIVED] |
| 007c5690 | byte_7C5690 | W | InitStateFlag [DERIVED] |
| 007c569c | dword_7C569C | R | SessionType5 (5=server) [DERIVED] (also: ` — SessionType5 (guards dev logging) |
| 007c56a0 | dword_7C56A0 | W | MultiplayerFlags [DERIVED] |
| 007cd25c | dword_7CD25C | R | GameModuleManager [DERIVED] |
| 007cd468 | dword_7CD468 | R | Unk_Setup_Flag [DERIVED] |
| 007ce24c | unk_7CE24C | R | CriticalSection [DERIVED] (also: ` — Session data object) |
| 007ce498 | byte_7CE498 | R | AutoLoadConfigFile [DERIVED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00423a00 | BinarySearchInStringTable | [LLM] |
| 0042bc80 | BuildActiveVehiclePointerArray | [LLM] |
| 00461550 | FAILWRONGDESCRIPTION | [LLM] |
| 00461900 | SessionConfigWriteback | [LLM] |
| 00461cd0 | SessionStateCheck | [LLM] |
| 00462d30 | EnumToEnumTranslator | [LLM] |
| 00462da0 | sub_462DA0 | [LLM] |
| 004630d0 | UniqueID | [LLM] |
| 0046e170 | ShortComputation_e170 | [LLM] |
| 00489940 | FieldGetter | [LLM] |
| 00489cb0 | StateCleanupNotification | [LLM] |
| 00497940 | LookupDispatch | [LLM] |
| 00498730 | FloatFieldAccessor | [LLM] |
| 004a0af0 | sub_4A0AF0 | [LLM] |
| 004b0170 | EmptyStub_0170 | [LLM] |
| 004b1600 | PathPathRegistryWriter | [LLM] |
| 004d7a50 | StringSplitLoop | [LLM] |
| 004d7aa0 | DebugLogWrite | [LLM] |
| 004ef5a0 | SessionStateTransition | [LLM] |
| 00566650 | StringCopyWithBufferRealloc | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
