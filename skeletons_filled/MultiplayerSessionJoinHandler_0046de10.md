## MultiplayerSessionJoinHandler_0046de10 — MultiplayerSessionJoinHandler

**Summary:** Handles multiplayer session join flow — validates the session with a countdown timer, transitions all vehicles through session state cleanup, resets the vehicle array, configures the session, and navigates to the client team selection screen; on validation failure, displays an error page and returns -1.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x40)+0x0) | 0x1C | R | — | virtual method at vtable index 7 (field getter / validator) |
| *(this+0x40) | 0x0 | R | — | pointer to session data object (base for vtcall dispatch) |
| obj | 0x38 | R | — | session state value (read via SessionStateCheck, compared to 3) |
| this | 0x0 | R | — | vtable pointer (used for virtual method dispatch at offset 56) |
| this | 0x40 | R | — | pointer to session data / game object (used throughout join flow) |
| this | 0xE4 | RW | 0 | join countdown timer (float, decremented each tick; set to 0 on completion/failure) |

**Written-by note (persistence):**
- this 0xE4: write-once per join attempt — external poke persists until next join cycle

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
| 005ec6d0 | unk_5EC6D0 | R | session initialization data / array base pointer |
| 005ec6e4 | unk_5EC6E4 | R | VEH[0].0xC — start of per-vehicle state array (iterated for state transitions) |
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
| 00423a00 | BinarySearchInStringTable | searches for a string in a table and copies the match to output buffer |
| 0042bc80 | BuildActiveVehiclePointerArray | rebuilds the active vehicle pointer array after vehicle count reset |
| 00461550 | FAILWRONGDESCRIPTION | retrieves session description / fail description into a buffer |
| 00461900 | SessionConfigWriteback | writes session configuration back to storage |
| 00461cd0 | SessionStateCheck | returns the current session state (3 = ready/active) |
| 00462d30 | EnumToEnumTranslator | translates an enum value through a lookup table using the game module manager |
| 00462da0 | sub_462DA0 | retrieves a description string from the translated enum result |
| 004630d0 | UniqueID | validates / retrieves a unique session identifier |
| 0046e170 | ShortComputation_e170 | performs a short computation / state update before session transition |
| 00489940 | FieldGetter | reads a field value from a struct (returns signed int, checked < 0) |
| 00489cb0 | StateCleanupNotification | notifies and cleans up old state before session transition |
| 00497940 | LookupDispatch | dispatches to a UI page / screen by lookup key |
| 00498730 | FloatFieldAccessor | returns a float value used to decrement the join countdown timer |
| 004a0af0 | sub_4A0AF0 | operates on the critical section / session data object |
| 004b0170 | EmptyStub_0170 | no-op cleanup stub (releases the description buffer) |
| 004b1600 | PathPathRegistryWriter | writes path registry / config file path setting |
| 004d7a50 | StringSplitLoop | conditional debug logging gate — returns true if debug verbosity level matches |
| 004d7aa0 | DebugLogWrite | writes a debug log message with a format string |
| 004ef5a0 | SessionStateTransition | transitions a single vehicle through session state (called in loop for all vehicles) |
| 00566650 | StringCopyWithBufferRealloc | copies a string into a reallocated buffer |

**Guard conditions:** The join flow is gated by a composite error flag `v3`:
- If `*(this+0xE4) > 0.0f` (countdown timer active), the timer is decremented and `v3` is set (error path enabled if timer expires or other conditions fail).
- If the virtual method call at `*(*(this+0x40)+0x1C)` returns a value whose `FieldGetter` result is `< 0`, `v3` is set (validation failure).
- When `v3` is true, the error path is taken: translates the error, displays the join failure page, and returns -1.
- When `v3` is false, the success path proceeds: checks `SessionStateCheck == 3`, transitions all vehicles, resets state globals, and navigates to team selection.
