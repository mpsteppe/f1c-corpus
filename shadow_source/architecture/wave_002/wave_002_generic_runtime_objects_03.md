# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Reconstructs the generic runtime object layer from eighteen validated functions. One DERIVED class, GameStateManager, owns the six game lifecycle functions (0x0042D260, 0x0042D370, 0x0042D5D0, 0x0042D6B0, 0x0042D7A0, 0x0042DB20) around a state field at this+0x0 (values 1/2/3/4/7) and a module-path record at this+0x1C, yielding a DERIVED GameLifecycle state machine. A DERIVED DynamicManager (0x0042C1A0) selects the player vehicle slot and loads vehicle scenes; a DERIVED StringTable (0x00423A00) binary-searches 16-byte entries; a DERIVED GearRatioConfig (0x0042DE10) parses gear-ratio config files. GUESS classes cover a VehicleSessionGate (0x0042AE60), a reusable RuntimeBlock initializer (0x0042E1C0), a large SessionState struct initializer (0x0042E320), a SettingsDirectoryBuilder (0x00432220), a TrackSessionClassList reader (0x00432A70), and a SessionConfig default initializer (0x00432CC0). Three functions (SessionTypeNameLookup 0x0042CE30, SettingsFolderResolver 0x004326A0, IterationCountMap 0x00432E50) are kept unowned. State-machine and compatibility contracts are DERIVED from the field writes and return conventions.

## Function roles

- `0x00423A00` **StringTable** — StringTable binary search: reads entry count from this+0x4 and table base from this+0x8; searches 16-byte entries (key ptr +0, value ptr +8) with strcmp, copies the matched value string into output buffer a3 (returns 0), or copies the input key a2 into a3 (returns -1) on miss/empty table; null key/value pointers fall back to the default string at byte_5EA438.
- `0x0042AE60` **VehicleSessionGate** — Vehicle session gate for the overtaking path: returns 0 when global session type dword_7C56A4 != 5, and returns 0 when this+0x4094 == 2 (lap 2) while this+0x454C != 1 (not called to the box); otherwise returns 1. Invoked per-frame from Overtaking (0x0042AF70).
- `0x0042C1A0` **DynamicManager** — DynamicManager init, called once from Game_Init (0x0042D6B0): scans the static vehicle array (0x005EF9A0, 4656-byte stride) to pick the player slot, registers it via SetPlayerVehicleIndex (0x0042BBD0/0x0042BC40) with an all-slots-occupied fallback to slot 0, gates formation-lap AI setup (0x004C01A0 vs default 0x004BFF70) on session type, rebuilds the active vehicle pointer array (0x0042BC80), drives the loading progress bar while loading vehicle scenes (0x004C6C40), sets up the player name, and loads AI driver names from config when the vehicle driver-name field is null.
- `0x0042CE30` **UnknownObject** — Session type id to display-string lookup: a2 non-zero selects the short-name switch table (jpt_42CE63), a2 zero the long-name table (jpt_42CE39); maps ids 0-4 to Testday/Practice1-4 long or short strings, ids 5/6/7 to shared Qualify/Warmup/Race strings, and out-of-range ids to the Unknown string (0x005C307C).
- `0x0042D260` **GameStateManager** — GameStateManager file loader: records the module path into this+0x1C via UtilityFunction_8a60(7, this+28), resolves the base directory (dword_5EC408, fallback byte_5EA438) into byte_5EC4C0, initializes the random noise table (0x004B3BD0), loads tire brands (0x004D7660), scene files (0x004C52C0) and vehicle files (0x004C3D80); returns 1 when the scene (0x008AC488) or vehicle (0x008AC390) count is not positive, 0 on full success.
- `0x0042D370` **GameStateManager** — GameStateManager Enter: sets the game-entered state this+0x0 = 1, logs entry, then enters OS manager (0x004A18D0), game files (0x0042D260), video (0x004FA000), special FX (0x004CEE90), dynamics (0x0042C130), player files (0x004B1820); builds/decodes the audio config path from the season dir and retries with the track DB name; loads .rcd and .pit files via DirectoryEntryIterator; enters sound (0x004C8A20), input (0x00455BF0), on-screen (0x0049EF40), and module hook (0x00463E20); returns 1 on any checked subsystem failure.
- `0x0042D5D0` **GameStateManager** — GameStateManager setup: writes this+0x0 = 2 (setup/loading phase), logs entry, then initializes player-file helper (0x004F9160), hardware input (0x00455C60), scoring gate (0x004BA1E0), options (0x004A0EB0), special FX (0x004CEEC0), steward (0x004D36D0), dynamics (0x0042C170), sound (0x004C8AB0), on-screen (0x0049EF70), session sub-object (0x004A1830), video (0x004FA2F0), player file (0x004B1870), and module manager (0x00463EF0); Options_Setup and PlayerFile_Setup return 1 to signal early-abort failure.
- `0x0042D6B0` **GameStateManager** — GameStateManager init orchestrator: writes this+0x0 = 3 (init phase), logs entry, then initializes scoring gate (0x004BA1F0), video (0x004FA320, abort on failure), scene extent (0x004BDC10), physics/setup (0x004FCAA0), AI database (0x004040A0), session transition flag (0x004B0170), steward (0x004D38F0), hardware input (0x00455D50), special FX (0x004CF070), dynamics (0x0042C1A0), camera (0x0040C920), sound (0x004C8AE0), renderer (0x004B4030), session buffer (0x004A40E0), on-screen (0x0049EFA0), session UI (0x004A1830), and session type (0x00463F70); returns 0 on success.
- `0x0042D7A0` **GameStateManager** — GameStateManager restart orchestrator: writes this+0x0 = 4 (restart/loading), logs entry, then invokes the restart/reset entry point of synchronization (0x00464290), sound (0x004C8B20), memory zeroing (0x004A40F0, 0x004A0FB0), steward (0x004D3CF0), engine block (0x004FCC30), heightfield collision (0x00404250), special FX (0x004CFC90), hardware input (0x00455DA0), dynamics (0x0042C3B0), camera (0x0040C9E0), renderer (0x004B4060), on-screen (0x0049F000), scoring (0x004BA460), video (0x004FA640), session (0x004A1830), player file (0x004B18D0), HUD (0x00418E50), and log (0x004D7B00).
- `0x0042DB20` **GameStateManager** — GameStateManager Exit: writes this+0x0 = 7 (exiting), logs entry, then shuts down sound (0x004C8D00), special FX (0x004CFFF0), scene/session stubs (0x004B0170), hardware input (0x00455F00), dynamics (0x0042CA70), scoring gate (0x004BA770), on-screen (0x0049F120), video (0x004FAD00), module manager (0x00464670), and session (0x0042D350); returns CloseHandle(hObject).
- `0x0042DE10` **GearRatioConfig** — GearRatioConfig file reader: opens a2 in read mode (0x00587DB0), frees prior state via ScoreSlotDeallocator (0x0042DDD0), scans the file for the [GearRatios] and [FinalDrive] sections counting ratio tokens into this+0x0 and this+0x8, allocates 8-byte-per-entry buffers this+0x4 and this+0xC, rewinds, and fills the buffers with ratio value pairs (plus a bevel scalar via this+0x10/this+0x14) and arranges each buffer via sub_5890AA; returns the file-close result.
- `0x0042E1C0` **RuntimeBlock** — RuntimeBlock initializer: zeroes the seven leading dword fields (this+0x0..+0x18), sets the byte flag at this+0x1C to 1, clears the bytes at this+0x1D and this+0x1E, and returns this; used as the StructInitializer for 64-byte sub-blocks by session, dynamics, and loop initializers.
- `0x0042E320` **SessionState** — SessionState struct initializer: zeroes the leading dword, sets header fields +0x68 = 0 and +0x6C = -1 and +0x70 = 0, runs two StructInitializer passes over 64-byte blocks (44 entries from this+176, then 55 from this+2992), initializes a small data structure at dword index 1628 (0x0042DC60), sets byte counters +0x19A4/+0x19A5 to 1, zeroes +0x1988/+0x1989 and the six-dword block +0x198C..+0x19A0, runs sub_42ED70, clears bytes at +0x1B26 in 128-byte steps, sets floats +0x1CA8..+0x1CB4 to 0.5f, finishes with PenaltyStructInit (0x0042E400), and returns this.
- `0x00432220` **SettingsDirectoryBuilder** — SettingsDirectoryBuilder: scans the scene setup array (dword_8AC488 entries, 0x18C stride from dword_8AC490), resolves and capitalizes each scene folder name, creates the directory tree (0x00589671), and when directory creation failed or a config mismatch is detected builds 128-byte vehicle config entries (.svm paths) added via AddVehicleConfigEntryToLinkedList (0x00433B60), freeing temporaries and terminating the accumulated path; returns a success flag.
- `0x004326A0` **UnknownObject** — Settings section resolver: when SeasonRacesSectionFinder (0x004C5840) recognizes this as a season/races section and StringKeyedLinkedListSearch (0x005679C0) finds a matching entry in the list rooted at off_5C3FA4[0], returns the DataEntryAccessor result; otherwise returns the section pointer unchanged.
- `0x00432A70` **TrackSessionClassList** — Track session-class list reader: iterates entries via sub_5651B0, matching each against vtable types off_5C3F8C, off_5C3F90, off_5C3F94, off_5C3F98; a match on off_5C3F94 (UI-widget vtable) wraps the string into a handle stored at this+0x10 (0x00587F59); loop continuation gated by ConditionalDispatchBasedOnFlag (0x00566CC0); returns 1 when a2 or *a2 is null, else 0.
- `0x00432CC0` **SessionConfig** — SessionConfig default initializer: copies the default application-directory string into byte_5EA438 three times via StringCopyWithBufferRealloc (0x00566650) and sets the field at this+0x10 to the literal 7; unconditional, returns the final copy result.
- `0x00432E50` **UnknownObject** — Pure AI iteration-count decision: returns 7 when a1 < 3, 5 when 3 <= a1 <= 5, and 7 when a1 > 5; callers (AISettingsFileLoader, AISettingsFileResolver, LookUpVehicleConfigEntry, AddVehicleConfigEntryToLinkedList) compare the result to 5 to select qualifying vs race AI config entries.

## Proposed classes

### GameStateManager

Game lifecycle state object: a state field at +0x0 written 1 (Enter), 2 (Setup), 3 (Init), 4 (Restart) and 7 (Exiting), plus a module-path record at +0x1C; its methods orchestrate the fixed enter/setup/init/restart/exit sequence over every engine subsystem and load game assets.

Methods: `0x0042D260`, `0x0042D370`, `0x0042D5D0`, `0x0042D6B0`, `0x0042D7A0`, `0x0042DB20`

- `this+0x00000000` `dword game_state` (read_write, DERIVED)
- `this+0x0000001C` `dword module_path_record` (write, GUESS)

### DynamicManager

Dynamics manager: selects the player vehicle slot from the static vehicle array, configures AI driver count and setup (default vs formation-lap), rebuilds the active vehicle pointer array, and drives vehicle-scene loading progress; init is called once from Game_Init.

Methods: `0x0042C1A0`


### StringTable

Sorted string table for string-keyed lookups: entry count at +0x4, table base at +0x8, 16-byte entries (key pointer +0, value pointer +8); binary-searched to copy the matched value into an output buffer.

Methods: `0x00423A00`

- `this+0x00000004` `dword entry_count` (read, DERIVED)
- `this+0x00000008` `dword table_base` (read, DERIVED)

### VehicleSessionGate

Vehicle-owned session gate used by the overtaking path: reads lap-of-run at +0x4094 and call-to-box at +0x454C and the global session type to decide whether overtaking logic may proceed.

Methods: `0x0042AE60`

- `this+0x00004094` `dword lap_of_run` (read, GUESS)
- `this+0x0000454C` `dword call_to_box` (read, GUESS)

### GearRatioConfig

Gear-ratio configuration object: gear count at +0x0 and gear buffer at +0x4, final-drive count at +0x8 and final-drive buffer at +0xC, plus a bevel scalar pair at +0x10/+0x14; populated by a two-pass config file reader.

Methods: `0x0042DE10`

- `this+0x00000000` `dword gear_count` (read_write, DERIVED)
- `this+0x00000004` `void* gear_buffer` (read_write, DERIVED)
- `this+0x00000008` `dword final_drive_count` (read_write, DERIVED)
- `this+0x0000000C` `void* final_drive_buffer` (read_write, DERIVED)

### RuntimeBlock

Generic runtime block: seven leading dword fields zeroed on init, an enabled/initialized byte flag at +0x1C set to 1, and two cleared bytes at +0x1D/+0x1E; used as the 64-byte StructInitializer sub-block by session, dynamics, and loop initializers.

Methods: `0x0042E1C0`

- `this+0x00000000` `dword dword_0` (write, GUESS)
- `this+0x00000004` `dword dword_1` (write, GUESS)
- `this+0x00000008` `dword dword_2` (write, GUESS)
- `this+0x0000000C` `dword dword_3` (write, GUESS)
- `this+0x00000010` `dword dword_4` (write, GUESS)
- `this+0x00000014` `dword dword_5` (write, GUESS)
- `this+0x00000018` `dword dword_6` (write, GUESS)
- `this+0x0000001C` `byte enabled_flag` (write, GUESS)
- `this+0x0000001D` `byte cleared_byte_0` (write, GUESS)
- `this+0x0000001E` `byte cleared_byte_1` (write, GUESS)

### SessionState

Large session-state structure: header dwords (+0x0, +0x68, +0x6C = -1, +0x70), two arrays of 64-byte RuntimeBlock sub-blocks, a small data structure at dword index 1628, byte counters +0x19A4/+0x19A5, a zeroed block +0x1988..+0x19A0, a per-128-byte cleared field +0x1B26, four 0.5f floats +0x1CA8..+0x1CB4, and penalty state initialized by PenaltyStructInit.

Methods: `0x0042E320`

- `this+0x00000000` `dword leading_dword` (write, GUESS)
- `this+0x00000068` `dword header_dword_a` (write, GUESS)
- `this+0x0000006C` `dword header_dword_neg1` (write, GUESS)
- `this+0x00000070` `dword header_dword_b` (write, GUESS)
- `this+0x00001988` `byte counter_byte_a` (write, GUESS)
- `this+0x00001989` `byte counter_byte_b` (write, GUESS)
- `this+0x0000198C` `dword zeroed_block_0` (write, GUESS)
- `this+0x00001990` `dword zeroed_block_1` (write, GUESS)
- `this+0x00001994` `dword zeroed_block_2` (write, GUESS)
- `this+0x00001998` `dword zeroed_block_3` (write, GUESS)
- `this+0x0000199C` `dword zeroed_block_4` (write, GUESS)
- `this+0x000019A0` `dword zeroed_block_5` (write, GUESS)
- `this+0x000019A4` `byte active_byte_a` (write, GUESS)
- `this+0x000019A5` `byte active_byte_b` (write, GUESS)
- `this+0x00001B26` `byte cleared_field_1b26` (write, GUESS)
- `this+0x00001CA8` `float half_float_0` (write, GUESS)
- `this+0x00001CAC` `float half_float_1` (write, GUESS)
- `this+0x00001CB0` `float half_float_2` (write, GUESS)
- `this+0x00001CB4` `float half_float_3` (write, GUESS)

### SettingsDirectoryBuilder

Settings/scene directory builder: reads the source path pointer at obj+0x0, resolves and capitalizes scene folder names against the string-keyed list, creates directory trees, and on failure builds vehicle config entries (.svm) added to a linked list.

Methods: `0x00432220`

- `obj+0x00000000` `void* source_path_ptr` (read, GUESS)

### TrackSessionClassList

Track session-class entry list: iterates entries matching them against four vtable types; a UI-widget vtable match stores the wrapped string handle at this+0x10.

Methods: `0x00432A70`

- `this+0x00000010` `dword ui_widget_string_handle` (write, GUESS)

### SessionConfig

Session configuration object: holds a config flag/counter default of 7 at +0x10 and a default application-directory string buffer; default-initialized unconditionally.

Methods: `0x00432CC0`

- `this+0x00000010` `dword config_flag_default` (write, GUESS)

## Compatibility contracts

- **GameLifecycleStateField** — A replacement executable must keep a game-state field at the game object's +0x0 that is written 1 on Enter (Game_Enter), 2 on Setup (GameSetup), 3 on Init (Game_Init), 4 on Restart (Game_Restart) and 7 on Exit (GameExit), with GameMainEntry (0x0045B200) driving the lifecycle.
- **StringTableLookup** — A sorted string table must expose entry count at +0x4 and table base at +0x8 with 16-byte entries (key pointer +0, value pointer +8); a binary-search lookup must copy the matched value string into the output buffer (return 0) or the input key (return -1), substituting the default string at byte_5EA438 for null pointers.
- **VehicleSessionGateRule** — The overtaking path must be gated: return 0 when the global session type (dword_7C56A4) is not 5, and return 0 when the vehicle is on lap 2 (this+0x4094 == 2) without a pit call (this+0x454C != 1); otherwise return 1.
- **DynManPlayerSlotSelection** — Dynamic manager init must scan the static vehicle slot array (0x005EF9A0, 4656-byte stride) for the first empty slot and register it as the player vehicle, falling back to slot 0 when all 104 slots are occupied; the active vehicle pointer array must be rebuilt and vehicle scenes loaded with a progress bar.
- **GameFileLoadReturnContract** — Game file loading must return 1 (failure) when the loaded scene count (0x008AC488) or loaded vehicle count (0x008AC390) is not positive, and 0 on the full-success path where both scene and vehicle files loaded.
- **GearRatioConfigLayout** — Gear-ratio config parsing must populate gear count at +0x0 and gear buffer at +0x4, and final-drive count at +0x8 and buffer at +0xC, from the [GearRatios] and [FinalDrive] sections of the config file with 8 bytes per ratio entry.
- **SessionStateInitPattern** — Session-structure initialization must set header +0x68 = 0, +0x6C = -1, +0x70 = 0, run 44 then 55 StructInitializer passes over 64-byte blocks, set byte counters +0x19A4/+0x19A5 to 1, zero the +0x1988..+0x19A0 block, set floats +0x1CA8..+0x1CB4 to 0.5f, and finish with PenaltyStructInit.
- **AIIterationCountDecision** — The AI iteration-count decision must return 7 for a1 < 3 and a1 > 5, and 5 for 3 <= a1 <= 5; callers compare the result to 5 to select qualifying vs race AI config entries.

## Unresolved

- SessionTypeNameLookup (0x0042CE30), SettingsFolderResolver (0x004326A0) and IterationCountMap (0x00432E50) have UNKNOWN owners; no packet evidence constrains their owning classes.
- Field names callToBox (this+0x454C) and lapOfRun (this+0x4094) come from the skeleton fill and are not established by this packet.
- byte_5EA438 is treated as a default fallback string, but its actual content is not evidenced.
- The 16-byte string-table entry layout (key pointer at +0, value pointer at +8) is DERIVED from the decompiled arithmetic; no formal struct definition is in the packet.
- Session type mask values 3 and 4 for dword_7D0410 gate different AI-setup branches; the exact enum is not in the packet.
- The distinction between sub_4BFF70 (default AI setup) and sub_4C01A0 (formation-lap AI setup) is DERIVED from the existing analysis fill, not the raw listing.
- Game lifecycle state transitions are DERIVED from the field writes; GameMainEntry (0x0045B200) drives the game state machine but the exact transition ordering is not proven.
- GearRatioConfig: the bevel scalar written via sub_565760(aBevel, this+4, this+5) lands at this+0x10/+0x14, which are beyond the four packet-documented fields.
- SessionState: the identities of the two StructInitializer arrays (44 then 55 entries of 64 bytes) are not stated by packet facts.
- SessionState: byte fields 0x19A4/0x19A5 and the zeroed six-dword block 0x198C-0x19A0 and the 0.5f float group 0x1CA8-0x1CB4 remain semantically unnamed.
- TrackSessionClassList: the four vtable globals off_5C3F8C/5C3F90/5C3F94/5C3F98 are only compared, never dereferenced; their object types are not evidenced.
- TrackSessionClassList: the post-break flow (StringCopyWithBufferRealloc followed by the loop-tail check) does not store a second result, so the fall-through after a vtable match is not fully resolved.
- SettingsDirectoryBuilder: helpers sub_5665B0, sub_568620, sub_588410, sub_566810 and sub_568B00 are opaque; the 0x18C (396) scene-entry stride is inferred from the loop advance literal.
- GameFileLoader: semantics of the UtilityFunction_8a60(7, this + 28) call and the meaning of constant 7 are unknown; this + 0x1C has no other field record in the packet.
- dword_5EC408 as an override path pointer and dword_8AC488/dword_8AC390 as counts are carried over from existing analysis prose, not proven by raw evidence.
- Globals flagged by packet facts but absent from the raw decompiled bodies: flt_59E8A4/flt_59E9D0/flt_59E9D4 (DynMan_Init), dword_7C73E8/byte_7CE498 (DynMan_Init, SettingsCopySetupFileCopy), aSS (0x005BE860), unk_5EC6D0, dword_7D0438, dword_8AD3B4 (Game_Enter/GameSetup/Game_Init), byte_42DC20 (GearRatioConfigFileReader).
- GameExit: the final StringSplitLoop/DebugLogWrite pair references string literals (aDDevF119992002_19, aEnteredOsmanEx) not listed among the packet globals.
- Game_Restart: ownership of this and the exact meaning of the state value 4 are not established; the caller GameMainEntry (0x0045B200) drives the game state machine.
