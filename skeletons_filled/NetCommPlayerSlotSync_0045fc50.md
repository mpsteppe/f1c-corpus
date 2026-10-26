## NetCommPlayerSlotSync_0045fc50 — Network Player Slot Synchronization

**Summary:** Synchronizes multiplayer player slots: detects joining/leaving players, loads vehicle resources (VehGen scene, physics, cockpit HUD), updates the active vehicle pointer array, displays join/leave messages, and plays sound effects.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SessionScoringUpdate (004643c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x3FCC) | 0x0 | R | — | LinkedListNode_StringPtr (filename string in linked list node) |
| *(this+0x3FCC) | 0x4 | R | — | LinkedListNode_Next (next pointer in linked list) |
| *(this+0x3FCC) | 0x8 | R | — | LinkedListNode_Flag (byte at +8, checked for free) |
| this | 0x0 | R | — | postProcessInput [CONFIRMED] |
| this | 0x374 | R | — | SyncInProgress (byte guard: non-zero skips entire function — prevents re-entry) |
| this | 0x410 | R | — | SlotArrayField (offset from slot base used in ConditionalFieldSetter / FieldCopy) |
| this | 0x411 | R | — | SlotArrayFieldByte (byte at slot base + 0x411 used in ShortComputation_5430) |
| this | 0x3E14 | R | — | ActiveSlotCount (this[3973] — number of active player slots to iterate) |
| this | 0x3FC4 | R | — | SessionMode (this[4081]: 1=race, 2=qualifying — controls sound playback and path trimming) |
| this | 0x3FC8 | RW | — | LinkedPathListHead (this[4082]: head of linked list of session file paths) |
| this | 0x3FCC | RW | — | LinkedPathListTail (this[4083]: tail pointer, updated on removal) |
| this | 0x3FD0 | RW | — | LinkedPathListIterator (this[4084]: current node in linked list walk) |
| this | 0x3FD4 | R | — | LinkedPathListCount (this[4085]: number of entries, decremented on removal) |

**Written-by note (persistence):**
- this 0x3FC8: one-shot init/build — external poke does NOT persist (linked list managed per-sync cycle)
- this 0x3FCC: one-shot init/build — external poke does NOT persist
- this 0x3FD0: one-shot init/build — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c329c | dword_5C329C | RW | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 005c5ce4 | aDDevF119992002_1 | R | Source dev file path string (logging/debug format) |
| 005c5d30 | aSS_2 | R | Driver settings suffix string |
| 005c5e94 | aUnsettingSlotI | R | "Unsetting slot" debug message string |
| 005c5eb4 | aUnloadingSlotI | R | "Unloading slot" debug message string |
| 005c5ee0 | aLeftTheGame | R | "left the game" display message string |
| 005c5ef0 | aHasEnteredTheG | R | "has entered the game" display message string |
| 005c5f08 | aSlotIsTaggedAs | R | "Slot is tagged as" debug message string |
| 005c5f2c | aLoadingSlotInd | R | "Loading slot" debug message string |
| 005ea510 | dword_5EA510 | R | SessionManager [DERIVED] |
| 005ec4c0 | byte_5EC4C0 | R | EmptyStringBuffer [DERIVED] |
| 005ec4cc | byte_5EC4CC | RW | MessageDisplayBuffer [DERIVED] (also: ` (byte_5EC4CC) |
| 005ec6d0 | unk_5EC6D0 | R | VehicleArrayBase (start of per-vehicle data array) |
| 005ec6d8 | unk_5EC6D8 | R | VEH[0].0x0 = postProcessInput [CONFIRMED] |
| 005ef9a0 | dword_5EF9A0 | R | VEH[0].0x32C8 — AIEnableFlag (checked for -1 = inactive slot) |
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
| 0040d100 | GameStateBranchDispatch | Branch dispatch based on game state after player slot set |
| 00423a00 | BinarySearchInStringTable | Search for string in table and copy to buffer (used for join/leave messages) |
| 0042bbd0 | SetPlayerVehicleIndex | Set current player to a specific vehicle index (fallback path) |
| 0042bc40 | SetPlayerVehicleIndex_bc40 | Set player vehicle index for newly joined slot |
| 0042bc80 | BuildActiveVehiclePointerArray | Rebuild active vehicle pointer array after slot changes |
| 00433870 | PhysicsSubsystemStep | Initialize physics subsystem for newly joined vehicle |
| 0045bd10 | TextLineWrappingAndRendering | Display wrapped text line (join/leave messages) in orange color |
| 0045c030 | sub_45C030 | Reset per-slot UI/cockpit data |
| 0045c850 | PerElementArrayReset | Reset per-element array for a slot index |
| 00460cb0 | ClearPlayerSlots | Clear player slot data (called after slot removals) |
| 00461530 | FlagBitTest | Test bit 2 of slot field (determines if slot is active/occupied) |
| 00462330 | IDLookupInArray | Look up vehicle ID in array (checks if slot matches current player) |
| 00465430 | ShortComputation_5430 | Post-load computation for vehicle slot (sound/audio setup) |
| 0049ca00 | CockpitDashboardLEDGaugeSetup | Initialize cockpit dashboard LED gauges for new player |
| 004bc2f0 | ConditionalFieldSetter | Set slot field conditionally |
| 004bc320 | FieldCopy | Copy field data (slot metadata) |
| 004c6980 | SetDriverName | Set driver name string on vehicle struct |
| 004c69e0 | PathFilenameExtractor | Extract filename from full path string |
| 004c6c40 | VehgenScnFileLoader | Load VehGen scene file for a vehicle slot |
| 004c6d90 | SceneRenderUpdate | Update scene rendering for newly loaded vehicle |
| 004c6e80 | sub_4C6E80 | Unload/cleanup vehicle slot resources |
| 004c7b20 | TwoCallDelegation | Delegate two calls for vehicle setup (slot name + driver) |
| 004c8de0 | SoundEffectLoadPlay | Play sound effect (0=join, 1=enter, 2=leave) |
| 004d1030 | LoopOverTwoParallelArrays | Iterate over two parallel arrays (force feedback setup) |
| 004d7a50 | StringSplitLoop | Split/parse debug string for logging |
| 004d7aa0 | DebugLogWrite | Write debug log message with formatted string |
| 004e0ed0 | AudioSoundEffectController | Control audio sound effect per vehicle slot |
| 004ef5a0 | SessionStateTransition | Transition session state for a vehicle slot |
| 004fffa0 | ThunkWithStructInitSubCalls | Thunk function with struct init sub-calls for slot setup |
| 00566650 | StringCopyWithBufferRealloc | Copy string with buffer reallocation (driver name) |
| 00587bcf | FreeWrapper_7bcf | Free allocated memory (linked list node cleanup) |
| 00587dd0 | sub_587DD0 | Copy/update per-slot data block |
| 0058815f | StringFormatWithBufferOverflowCheck | Format join/leave display message string |
| 00588410 | sub_588410 | String comparison (returns true if strings differ) |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x3E14 | > | 0 | ActiveSlotCount — PASSES: if >0, iterate player slots for join detection |
| this | 0x3FC4 | != | 1 | SessionMode — BLOCKED: skip sound playback if session mode is 1 (race), only play sounds in mode 2 |

**Guard interpretation:** Top-level guard `this+0x374 != 0` blocks re-entry (sync already in progress). Main loop iterates `ActiveSlotCount` slots, checking each via FlagBitTest(slot-60, 2) for active flag. Active slots with non-empty name and valid vehicle data trigger join processing (load scene, physics, cockpit, force feedback). After join loop, a second pass over all vehicle array entries detects departed players (slot not in active list, vehicle still loaded) and unloads them — trimming linked path list, transitioning session state to -1, and updating current player index if needed. VehicleCount is decremented and pointer array rebuilt after removals.
