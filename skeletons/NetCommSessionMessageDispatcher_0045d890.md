## NetCommSessionMessageDispatcher_0045d890 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** TeamRadioNetworkMessageProcessing (0045f710)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1B774) | 0x4 | RW | — | [LLM] |
| *(this+0x3FC8) | 0x0 | R | — | [LLM] |
| *(this+0x3FCC) | 0x4 | RW | — | [LLM] |
| *(this+0x3FD0) | 0x0 | R | — | [LLM] |
| *(this+0x3FD0) | 0x4 | R | — | [LLM] |
| this | 0x0 | R | — | postProcessInput [CONFIRMED] |
| this | 0x10 | RW | 1065353216 → 1.0f | [LLM] |
| this | 0x14 | RW | 1 | [LLM] |
| this | 0x1C | RW | 1089470464 → 7.5f | PhysX [FACT] |
| this | 0x20 | RW | 1 | PhysY [FACT] |
| this | 0x378 | RW | 3 | [LLM] |
| this | 0x380 | RW | 1084227584 → 5.0f | [LLM] |
| this | 0x390 | RW | 1008981770 → 0.01f | [LLM] |
| this | 0x410 | R | — | [LLM] |
| this | 0x3E14 | R | — | [LLM] |
| this | 0x3FB8 | R | — | [LLM] |
| this | 0x3FC4 | R | — | [LLM] |
| this | 0x3FC8 | RW | — | [LLM] |
| this | 0x3FCC | RW | — | [LLM] |
| this | 0x3FD0 | RW | — | [LLM] |
| this | 0x3FD4 | R | — | [LLM] |
| this | 0x1B754 | R | — | [LLM] |
| this | 0x1B755 | R | — | [LLM] |
| this | 0x1B768 | RW | — | [LLM] |
| this | 0x1B769 | RW | — | [LLM] |
| this | 0x1B76A | R | — | [LLM] |
| this | 0x1B76B | R | — | [LLM] |
| this | 0x1B76C | R | — | [LLM] |
| this | 0x1B76D | R | — | [LLM] |
| this | 0x1B76E | R | — | [LLM] |
| this | 0x1B770 | RW | — | [LLM] |
| this | 0x1B774 | RW | — | [LLM] |
| this | 0x1B778 | RW | — | [LLM] |
| this | 0x1B77C | R | — | [LLM] |

**Written-by note (persistence):**
- *(this+0x1B774) 0x4: [LLM: once/conditional? does external poke survive?]
- *(this+0x3FCC) 0x4: [LLM: once/conditional? does external poke survive?]
- this 0x10: [LLM: once/conditional? does external poke survive?]
- this 0x14: [LLM: once/conditional? does external poke survive?]
- this 0x1C: [LLM: once/conditional? does external poke survive?]
- this 0x20: [LLM: once/conditional? does external poke survive?]
- this 0x378: [LLM: once/conditional? does external poke survive?]
- this 0x380: [LLM: once/conditional? does external poke survive?]
- this 0x390: [LLM: once/conditional? does external poke survive?]
- this 0x3FC8: [LLM: once/conditional? does external poke survive?]
- this 0x3FCC: [LLM: once/conditional? does external poke survive?]
- this 0x3FD0: [LLM: once/conditional? does external poke survive?]
- this 0x1B768: [LLM: once/conditional? does external poke survive?]
- this 0x1B769: [LLM: once/conditional? does external poke survive?]
- this 0x1B770: [LLM: once/conditional? does external poke survive?]
- this 0x1B774: [LLM: once/conditional? does external poke survive?]
- this 0x1B778: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0045e4f0 | jpt_45D8D8 | R | [LLM] |
| 0045e528 | byte_45E528 | R | [LLM] |
| 0045e554 | jpt_45DEEF | R | [LLM] |
| 0059e0dc | Sleep | R | [LLM] |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e444 | flt_59E444 | R | FrameDelta [DERIVED] (also: ` — float 0.016667 (1/60, frame delta) |
| 0059e448 | flt_59E448 | R | TileSteppingMultiplier [DERIVED] |
| 0059e87c | flt_59E87C | R | TimeStepMultiplier [DERIVED] |
| 0059f094 | flt_59F094 | R | PhysicsConstant_59F094 [DERIVED] |
| 0059f0ac | dword_59F0AC | R | NetTimeoutInterval [DERIVED] (also: ` — float constants) |
| 0059f0b0 | dword_59F0B0 | R | StateAssignmentValue [DERIVED] |
| 0059f0b8 | flt_59F0B8 | R | NetSyncTimeout [DERIVED] (also: ` — float constants (timeout/default) |
| 0059f108 | flt_59F108 | R | Flt_Unknown_Physics3 [DERIVED] |
| 005be860 | aSS | R | PathFormatString [DERIVED] (also: ` â€” format string for path construction) |
| 005c329c | dword_5C329C | R | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 005c5b88 | aTerrainIni | R | TerrainIniString [DERIVED] (also: ` — "terrain.ini" string constant) |
| 005c5ce4 | aDDevF119992002_1 | R | SourceDevPathStr [DERIVED] |
| 005c5d0c | aSSS_2 | R | SSSFormatString [DERIVED] |
| 005c5d18 | aMismatch | R | MismatchString [DERIVED] |
| 005c5d24 | dword_5C5D24 | R | SeasonRacesSuffix1 [DERIVED] |
| 005c5d28 | byte_5C5D28 | R | SeasonRacesSuffix2 [DERIVED] |
| 005c5d2c | byte_5C5D2C | R | NetMessageBufferSize [DERIVED] |
| 005c5d30 | aSS_2 | R | Str_DriverSettingsSuffix [DERIVED] |
| 005c5d38 | aWasRemovedFrom | R | WasRemovedFromString [DERIVED] |
| 005c5d54 | aYouHaveBeenBoo | R | StrYouHaveBeenBoo [DERIVED] |
| 005c5d6c | aNextTrack | R | NextTrackField [DERIVED] |
| 005c5d78 | aReceivedServer | R | String_ReceivedServer [DERIVED] |
| 005c5dac | aNextSession | R | NextSessionString [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec3d8 | dword_5EC3D8 | R | SeasonDir [DERIVED] |
| 005ec4c0 | byte_5EC4C0 | R | EmptyStringBuffer [DERIVED] |
| 005ec4cc | byte_5EC4CC | RW | MessageDisplayBuffer [DERIVED] (also: ` (byte_5EC4CC) |
| 005ec6d8 | unk_5EC6D8 | R | VEH[0].0x0 = postProcessInput [CONFIRMED] |
| 005f0774 | flt_5F0774 | R | VEH[0].0x409C = bestLap [CONFIRMED] |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |
| 007c569c | dword_7C569C | R | SessionType5 (5=server) [DERIVED] (also: ` — SessionType5 (guards dev logging) |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |
| 007c9574 | flt_7C9574 | R | Vehicle_UnknownDWORD [DERIVED] |
| 007cd204 | dword_7CD204 | R | ResourceDispatch_007CD204 [DERIVED] |
| 007cd25c | dword_7CD25C | R | GameModuleManager [DERIVED] |
| 007ce24d | unk_7CE24D | R | SessionTransitionFlag [DERIVED] |
| 007ce254 | byte_7CE254 | R | DisableHUDFlag [CONFIRMED] |
| 007ce5d0 | dword_7CE5D0 | R | CurrentTrackPath [DERIVED] |
| 007d0434 | dword_7D0434 | R | SeasonPath [DERIVED] |
| 007d1044 | byte_7D1044 | R | MessageDisplayFlags [DERIVED] (also: ` — flags for message display) |
| 007d10d4 | byte_7D10D4 | R | SessionFlagByte [DERIVED] |
| 007d2e50 | dword_7D2E50 | RW | SessionMsgCount [DERIVED] (also: ` — session message counter) |
| 0083ee54 | dword_83EE54 | RW | SessionDataOffset (stride 0x1b0) [DERIVED] |
| 008ac388 | unk_8AC388 | R | VehicleFilePathBuffer [DERIVED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |
| 008aff00 | byte_8AFF00 | W | SessionReadyFlag [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00423a00 | BinarySearchInStringTable | [LLM] |
| 00434030 | DoublyLinkedListAppend | [LLM] |
| 0045bc50 | StringCopyWithFormatQuery | [LLM] |
| 0045bd10 | TextLineWrappingAndRendering | [LLM] |
| 0045ca20 | TerrainSurfaceRoughnessHeightSampling | [LLM] |
| 0045e5b0 | ArraySearchFor1Sentinel | [LLM] |
| 0045e5d0 | ShortComputation_e5d0 | [LLM] |
| 0045e5f0 | ArrayScanForMatch | [LLM] |
| 0045eb50 | NodeIDToPlayerNameLookup | [LLM] |
| 0045ebd0 | LinkedListPurgeByThreshold | [LLM] |
| 00460520 | NetComm_SetSelfAsReady | [LLM] |
| 00460710 | ConditionalRenderStateUpdate | [LLM] |
| 004607a0 | ParticleSoundEffectSpawner | [LLM] |
| 00460a10 | TerrainIniParser | [LLM] |
| 00461470 | ThunkToFUN00461480 | [LLM] |
| 00461530 | FlagBitTest | [LLM] |
| 00462250 | TextureCreationWrapper | [LLM] |
| 00462300 | SingleFunctionDispatch | [LLM] |
| 00462460 | DriverDataCopyByID | [LLM] |
| 004a0e70 | SessionTypeGuard | [LLM] |
| 004b0170 | EmptyStub_0170 | [LLM] |
| 004b33b0 | ProgressBarEventEncode | [LLM] |
| 004b3a90 | ArithmeticComparison_3a90 | [LLM] |
| 004c40b0 | ConditionalDispatch_40b0 | [LLM] |
| 004d7a50 | StringSplitLoop | [LLM] |
| 004d7aa0 | DebugLogWrite | [LLM] |
| 00566650 | StringCopyWithBufferRealloc | [LLM] |
| 0057a660 | DualVirtualDispatchWrapper | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |
| 00587dd0 | sub_587DD0 | [LLM] |
| 0058815f | StringFormatWithBufferOverflowCheck | [LLM] |
| 00588410 | sub_588410 | [LLM] |
| 0058969d | StringFormatProcessingWithNullTerm | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x3E14 | <= | 0 | [LLM] |
| this | 0x3FC4 | != | 3 | [LLM] |
| this | 0x3FC4 | != | 1 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
