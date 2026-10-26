## NetCommPlayerSlotSync_0045fc50 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SessionScoringUpdate (004643c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x3FCC) | 0x0 | R | — | [LLM] |
| *(this+0x3FCC) | 0x4 | R | — | [LLM] |
| *(this+0x3FCC) | 0x8 | R | — | [LLM] |
| this | 0x0 | R | — | postProcessInput [CONFIRMED] |
| this | 0x374 | R | — | [LLM] |
| this | 0x410 | R | — | [LLM] |
| this | 0x411 | R | — | [LLM] |
| this | 0x3E14 | R | — | [LLM] |
| this | 0x3FC4 | R | — | [LLM] |
| this | 0x3FC8 | RW | — | [LLM] |
| this | 0x3FCC | RW | — | [LLM] |
| this | 0x3FD0 | RW | — | [LLM] |
| this | 0x3FD4 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x3FC8: [LLM: once/conditional? does external poke survive?]
- this 0x3FCC: [LLM: once/conditional? does external poke survive?]
- this 0x3FD0: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c329c | dword_5C329C | RW | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 005c5ce4 | aDDevF119992002_1 | R | SourceDevPathStr [DERIVED] |
| 005c5d30 | aSS_2 | R | Str_DriverSettingsSuffix [DERIVED] |
| 005c5e94 | aUnsettingSlotI | R | UnsettingSlotIString [DERIVED] |
| 005c5eb4 | aUnloadingSlotI | R | UnloadingSlotString [DERIVED] |
| 005c5ee0 | aLeftTheGame | R | LeftTheGameString [DERIVED] |
| 005c5ef0 | aHasEnteredTheG | R | HasEnteredTheGString [DERIVED] |
| 005c5f08 | aSlotIsTaggedAs | R | Str_SlotIsTaggedAs [DERIVED] |
| 005c5f2c | aLoadingSlotInd | R | StringLoadingSlotInd [DERIVED] |
| 005ea510 | dword_5EA510 | R | SessionManager [DERIVED] |
| 005ec4c0 | byte_5EC4C0 | R | EmptyStringBuffer [DERIVED] |
| 005ec4cc | byte_5EC4CC | RW | MessageDisplayBuffer [DERIVED] (also: ` (byte_5EC4CC) |
| 005ec6d0 | unk_5EC6D0 | R | [LLM] |
| 005ec6d8 | unk_5EC6D8 | R | VEH[0].0x0 = postProcessInput [CONFIRMED] |
| 005ef9a0 | dword_5EF9A0 | R | VEH[0].0x32C8 [LLM: field purpose] |
| 007c54d8 | byte_7C54D8 | R | VehicleArrayEnd [DERIVED] |
| 007c54dc | dword_7C54DC | RW | CurrentPlayerIndex [CONFIRMED] |
| 007c54e0 | dword_7C54E0 | W | postProcessInput [CONFIRMED] (also: unknown (near PlayerVehiclePtr +0x8)) |
| 007c54e4 | dword_7C54E4 | R | CurrentVehicleIndex [DERIVED] |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |
| 007c569c | dword_7C569C | R | SessionType5 (5=server) [DERIVED] (also: ` — SessionType5 (guards dev logging) |
| 007c73e8 | dword_7C73E8 | R | DeviceIdentityHandle1 [DERIVED] |
| 007cd204 | dword_7CD204 | R | ResourceDispatch_007CD204 [DERIVED] |
| 007cd2a8 | dword_7CD2A8 | R | Unknown_Menu_Struct_7CD2A8 [DERIVED] |
| 007ce058 | dword_7CE058 | R | Unknown_UI_Singleton [DERIVED] (also: ` — UI context object) |
| 008ac494 | byte_8AC494 | R | SceneArrayFirstSceneName [DERIVED] |
| 008acee0 | dword_8ACEE0 | R | ForceFeedbackBase [CONFIRMED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040d100 | GameStateBranchDispatch | [LLM] |
| 00423a00 | BinarySearchInStringTable | [LLM] |
| 0042bbd0 | SetPlayerVehicleIndex | [LLM] |
| 0042bc40 | SetPlayerVehicleIndex_bc40 | [LLM] |
| 0042bc80 | BuildActiveVehiclePointerArray | [LLM] |
| 00433870 | PhysicsSubsystemStep | [LLM] |
| 0045bd10 | TextLineWrappingAndRendering | [LLM] |
| 0045c030 | sub_45C030 | [LLM] |
| 0045c850 | PerElementArrayReset | [LLM] |
| 00460cb0 | ClearPlayerSlots | [LLM] |
| 00461530 | FlagBitTest | [LLM] |
| 00462330 | IDLookupInArray | [LLM] |
| 00465430 | ShortComputation_5430 | [LLM] |
| 0049ca00 | CockpitDashboardLEDGaugeSetup | [LLM] |
| 004bc2f0 | ConditionalFieldSetter | [LLM] |
| 004bc320 | FieldCopy | [LLM] |
| 004c6980 | SetDriverName | [LLM] |
| 004c69e0 | PathFilenameExtractor | [LLM] |
| 004c6c40 | VehgenScnFileLoader | [LLM] |
| 004c6d90 | SceneRenderUpdate | [LLM] |
| 004c6e80 | sub_4C6E80 | [LLM] |
| 004c7b20 | TwoCallDelegation | [LLM] |
| 004c8de0 | SoundEffectLoadPlay | [LLM] |
| 004d1030 | LoopOverTwoParallelArrays | [LLM] |
| 004d7a50 | StringSplitLoop | [LLM] |
| 004d7aa0 | DebugLogWrite | [LLM] |
| 004e0ed0 | AudioSoundEffectController | [LLM] |
| 004ef5a0 | SessionStateTransition | [LLM] |
| 004fffa0 | ThunkWithStructInitSubCalls | [LLM] |
| 00566650 | StringCopyWithBufferRealloc | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |
| 00587dd0 | sub_587DD0 | [LLM] |
| 0058815f | StringFormatWithBufferOverflowCheck | [LLM] |
| 00588410 | sub_588410 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x3E14 | > | 0 | [LLM] |
| this | 0x3FC4 | != | 1 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
