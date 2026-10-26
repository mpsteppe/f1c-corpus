## NetCommSessionMessageDispatcher_0045d890 — NetSessionMessageDispatchSwitch

**Summary:** Central network session message dispatcher: decodes message type from header bits, then dispatches to sub-handlers for session transitions, player boot/join, terrain validation, track changes, and rendering state updates.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** TeamRadioNetworkMessageProcessing (0045f710)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1B774) | 0x4 | RW | — | linkedListNextPtr (chain pointer in session message linked list) |
| *(this+0x3FC8) | 0x0 | R | — | linkedListHead (head of string/queue linked list at this+0x3FC8) |
| *(this+0x3FCC) | 0x4 | RW | — | linkedListTail (tail pointer, updated on append) |
| *(this+0x3FD0) | 0x0 | R | — | linkedListHead2 (head of second linked list) |
| *(this+0x3FD0) | 0x4 | R | — | linkedListTail2 (tail of second linked list) |
| this | 0x0 | R | — | postProcessInput [CONFIRMED] |
| this | 0x10 | RW | 1065353216 → 1.0f | sessionStateValue (set to 1.0f on session transition case 2, terrain mismatch case 0x2A) |
| this | 0x14 | RW | 1 | sessionReadyFlag (set to 1 on session start) |
| this | 0x1C | RW | 1089470464 → 7.5f | PhysX [FACT] |
| this | 0x20 | RW | 1 | PhysY [FACT] |
| this | 0x378 | RW | 3 | sessionStateCode (set to 3 on case 0x28, 2 on case 0x29) |
| this | 0x380 | RW | 1084227584 → 5.0f | terrainHeightThreshold (set to 5.0f on case 2, used in case 0x2A terrain check) |
| this | 0x390 | RW | 1008981770 → 0.01f | terrainHeightMinClamp (0.01f floor for terrain height delta) |
| this | 0x410 | R | — | playerDataBase (indexed by vehicle ID, each entry 140 bytes for terrain check) |
| this | 0x3E14 | R | — | playerCount (number of players/vehicles; guards terrain height loop) |
| this | 0x3FB8 | R | — | bootedFlag (checked in case 0x20 for self-boot detection) |
| this | 0x3FC4 | R | — | sessionPhase (guards cases: !=3 blocks case 2, !=1 blocks case 6 driver copy, ==1||2 blocks case 0x20) |
| this | 0x3FC8 | RW | — | messageQueueHead (linked list head for queued messages) |
| this | 0x3FCC | RW | — | messageQueueTail (tail pointer) |
| this | 0x3FD0 | RW | — | resourceListHead (head of resource/string linked list) |
| this | 0x3FD4 | R | — | resourceListCount (read for count tracking) |
| this | 0x1B754 | R | — | particleSoundByte0 (read in case 0x23 for ParticleSoundEffectSpawner) |
| this | 0x1B755 | R | — | particleSoundByte1 (read in case 0x23) |
| this | 0x1B768 | RW | — | terrainCheckFlag0 (written from a2+8 in case 0x23) |
| this | 0x1B769 | RW | — | terrainCheckFlag1 (written from a2+9) |
| this | 0x1B76A | R | — | terrainCheckFlag2 (read in case 0x24 for mismatch check loop idx 0) |
| this | 0x1B76B | R | — | terrainCheckFlag3 (loop idx 1) |
| this | 0x1B76C | R | — | terrainCheckFlag4 (loop idx 2) |
| this | 0x1B76D | R | — | terrainCheckFlag5 (loop idx 3) |
| this | 0x1B76E | R | — | terrainCheckFlag6 (loop idx 4) |
| this | 0x1B770 | RW | — | linkedListNodeData (12-byte node allocated via OperatorNewNhMallocWrapper) |
| this | 0x1B774 | RW | — | linkedListRoot (head/tail/count management for message queue) |
| this | 0x1B778 | RW | — | linkedListCount (incremented on append) |
| this | 0x1B77C | R | — | linkedListSentinel (read in case 0x27 for list traversal) |

**Written-by note (persistence):**
- *(this+0x1B774) 0x4: conditional on message receipt — external poke survives until next matching message overwrites
- *(this+0x3FCC) 0x4: conditional on message receipt — survives until next list append
- this 0x10: conditional on message receipt (case 2, 0x2A) — survives until next write
- this 0x14: conditional on message receipt (case 2) — survives until next write
- this 0x1C: conditional on message receipt (case 5) — survives until next write
- this 0x20: conditional on message receipt (case 2, 5) — survives until next write
- this 0x378: conditional on message receipt (case 0x28, 0x29) — survives until next write
- this 0x380: conditional on message receipt (case 2) — survives until next write
- this 0x390: conditional (decremented in case 0x2A) — survives between messages
- this 0x3FC8: conditional on message receipt — survives until next list mutation
- this 0x3FCC: conditional on message receipt — survives until next list mutation
- this 0x3FD0: conditional on message receipt — survives until next list mutation
- this 0x1B768: conditional on message receipt (case 0x23) — survives until next write
- this 0x1B769: conditional on message receipt (case 0x23) — survives until next write
- this 0x1B770: conditional on message receipt — survives until next list mutation
- this 0x1B774: conditional on message receipt — survives until next list mutation
- this 0x1B778: conditional on message receipt — survives until next list mutation

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0045e4f0 | jpt_45D8D8 | R | switch jump table for message type dispatch |
| 0045e528 | byte_45E528 | R | jump table secondary entries |
| 0045e554 | jpt_45DEEF | R | jump table for terrain mismatch inner switch |
| 0059e0dc | Sleep | R | Win32 Sleep import (1000ms delay used after session guard) |
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
| 00423a00 | BinarySearchInStringTable | Searches string table for token, copies match to buffer byte_5EC4CC |
| 00434030 | DoublyLinkedListAppend | Appends node to doubly-linked list at this+28124 |
| 0045bc50 | StringCopyWithFormatQuery | Copies/formats query string into result buffer |
| 0045bd10 | TextLineWrappingAndRendering | Renders text message via resource dispatch with color |
| 0045ca20 | TerrainSurfaceRoughnessHeightSampling | Samples terrain height at world position, returns height in float |
| 0045e5b0 | ArraySearchFor1Sentinel | Searches array for sentinel value, returns index |
| 0045e5d0 | ShortComputation_e5d0 | Short computation on found index and value |
| 0045e5f0 | ArrayScanForMatch | Scans array for matching entry |
| 0045eb50 | NodeIDToPlayerNameLookup | Resolves node/player ID to player name string |
| 0045ebd0 | LinkedListPurgeByThreshold | Purges linked list entries beyond threshold |
| 00460520 | NetComm_SetSelfAsReady | Sets self as ready in network communication |
| 00460710 | ConditionalRenderStateUpdate | Updates conditional render state |
| 004607a0 | ParticleSoundEffectSpawner | Spawns particle/sound effect based on byte flags |
| 00460a10 | TerrainIniParser | Parses terrain.ini for mismatch validation |
| 00461470 | ThunkToFUN00461480 | Thunk/jump to driver data function |
| 00461530 | FlagBitTest | Tests a bit flag at (v70-124) with mask 1 |
| 00462250 | TextureCreationWrapper | Creates texture resource with given parameters |
| 00462300 | SingleFunctionDispatch | Returns current player's node ID |
| 00462460 | DriverDataCopyByID | Copies driver data by vehicle ID into buffer |
| 004a0e70 | SessionTypeGuard | Guards session type check (returns true if type matches) |
| 004b0170 | EmptyStub_0170 | Empty/no-op stub function |
| 004b33b0 | ProgressBarEventEncode | Encodes progress bar event with timing data |
| 004b3a90 | ArithmeticComparison_3a90 | Performs arithmetic comparison on session data |
| 004c40b0 | ConditionalDispatch_40b0 | Conditional dispatch returning pointer or null |
| 004d7a50 | StringSplitLoop | Splits string on delimiter, returns match result |
| 004d7aa0 | DebugLogWrite | Writes formatted debug log message |
| 00566650 | StringCopyWithBufferRealloc | Copies string into buffer with reallocation |
| 0057a660 | DualVirtualDispatchWrapper | Calls virtual method dispatch (this+4078 vtable) |
| 00587c03 | OperatorNewNhMallocWrapper | Allocates memory via operator new (nh_malloc wrapper) |
| 00587dd0 | sub_587DD0 | Copies up to N bytes from source to dest buffer |
| 0058815f | StringFormatWithBufferOverflowCheck | snprintf-style format into buffer with overflow check |
| 00588410 | sub_588410 | Compares two byte strings for match |
| 0058969d | StringFormatProcessingWithNullTerm | String format processing with null terminator |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x3E14 | <= | 0 | playerCount (case 0x2A skips terrain height loop if no players) |
| this | 0x3FC4 | != | 3 | sessionPhase (case 2 body only runs if sessionPhase==3) |
| this | 0x3FC4 | != | 1 | sessionPhase (case 6 driver data copy only runs if sessionPhase!=1; case 0x20 blocked if ==1 or ==2) |

**Guard interpretation:** this+0x3E14 (playerCount) <= 0: BLOCKS terrain height sampling loop (no vehicles to check). this+0x3FC4 (sessionPhase) != 3: BLOCKS case 2 session transition logic (only runs in phase 3). this+0x3FC4 != 1: BLOCKS case 6 driver data path formatting (skips when phase 1). Case 0x20 is blocked when sessionPhase is 1 or 2.
