# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `GUESS`

Proposal for the generic_runtime_objects wave_002 packet 06. SessionManager (DERIVED from the packet's own owner label on 0x004643C0; extended at GUESS to the other session functions via the shared session-object fields obj+0x3FC4/obj+0x3FB8/obj+0x37C and the session globals dword_7CD25C/dword_7C56A0/unk_7CE24C) runs the per-frame session update, the auto-join retry loop, the session-type setup, the Game_Post flag setter, the end-condition check and the multiplayer join handler. NetworkObjectDispatcher (GUESS) creates and sends texture/data objects over the shared network-comm interface at obj+0x3FB8 via the 0x0057A6xx/0x0057A9xx send wrappers. ProfileListManager (GUESS) owns the icon/path linked list at this+0x444..+0x450, scanning player-profile icons, resolving the a2-th filename and loading setup files through the list owner sub-object at this+0x40. ConfigCommandObject (GUESS) is the command-binding config object destroyed at 0x00466A70. ProfileIconManager (GUESS) copies ProfileIcon.bmp and reloads the scene. GameModeRouter (GUESS) and PathModeRouter (GUESS) dispatch on dword_7D0410 and this+0x168 respectively. SessionSetupScreen (GUESS) groups the two session-mode UI parameter initializers sharing this+0x320. SessionFlagUIRow (GUESS) is the UI component constructor selecting one of six session-state pointers. ComponentObject (GUESS) and LinkedListNode (GUESS) capture the shared vtable-dispatch sub-object at this+0x40 and the uniform data/next/flag node layout. Contradictions are recorded in unresolved: obj+0xE4 is read as a source directory by 0x0046CD20 but as a float countdown timer by 0x0046DE10; the GlobalFlagBasedStateSetter target region falls outside declared fields; and several packet globals marked read never appear in their raw bodies.

## Function roles

- `0x00462250` **NetworkObjectDispatcher** — Creates a texture/data COM object through the vtable at interface+0x60 on the network comm interface at obj+0x3FB8, sets or overrides the object type, derives send code and flag from the type selector (1->code 1, 2->code 2 flag 1, else code 0), computes the send payload length as ((flag_word>>8)&0x3FF)+8, dispatches the object through the send wrapper (returns 1 when the dispatch returns zero), and releases the temporary object.
- `0x004637A0` **SessionManager** — Multiplayer auto-join retry loop gated on the auto-join byte at obj+0xC6: selects championship mode from dword_7D0410 clamped against dword_7D041C/dword_7D0418, runs a QPC-timed retry loop polling session state; on ready (SessionStateCheck(this)==3) builds the session descriptor, requests a unique ID, writes path/session config, resets every stride-4656 vehicle slot via SessionStateTransition(-1,0), zeroes the vehicle count, rebuilds the active-vehicle pointer array and dispatches client team-select (returns 1); on timeout or unrecoverable state logs and returns 0.
- `0x00463F70` **SessionManager** — Initializes the game session type and network configuration: reads the session discriminant at obj+0x3FC4 through the base pointer at this+0, delegating to sub_45ECD0 when zero; otherwise selects online mode (dword_7C56A0=3) versus offline mode (2), builds the network-communication strings from the session name and path defaults when byte_7CE260 is clear, marks the session active (obj+0x28=1, obj+0x3FD8=8, obj+0x3FD9=0), maps dword_7D0E50 through the jump table to a clamped size, copies online-mode configuration, calls CollisionInvDistanceStore, clears obj+0x30, initializes flags and returns sub_45ECD0. Called from Game_Init (0042d6b0).
- `0x004643C0` **SessionManager** — Per-frame session lifecycle/scoring update: when the session phase id at obj+0x3FC4 is nonzero, adds the frame delta (dbl_8AFE98) to the obj+0x388 elapsed accumulator (or to obj+0x384 on the network-setup states), runs a network-comm-gated block gated on obj+0x3FB8 (player-slot sync, collision timestep/iteration, grid/track-opening timers, ServerOK request via obj+0x28, track-open signal via obj+0x29) or a comm-not-ready countdown at obj+0x37C, always advances the secondary accumulator at obj+0x384, drains the session-state dispatch list at obj+0x1B770, conditionally dispatches a string payload and hands the object to the mouse input handler.
- `0x00464600` **SessionManager** — Session flag setter called from Game_Post: when the init guard byte_7CE260 is clear it builds the track configuration name into byte_7CE498, conditionally runs a short computation and a guarded init on the object at *this, calls the single-function wrapper with the dword at obj+0x3FB8, then reads the object state bytes at obj+0xC5 and obj+0xC6 and sets the persistent session flag byte_7CE25F to 1 if either is nonzero; the flag is never cleared here.
- `0x00466A70` **ConfigCommandObject** — Destructor for a config/command-binding object: copies the stored command-binding handle from the global table dword_7C7368 using this+0x108 as the index into this+0x104, resets the shared string buffer byte_5EA438, optionally reports the vehicle statistics in byte_7C56C0 when the scene-destroyed flag byte_7C7064 is clear, frees the linked list rooted at this+0x44 (nodes with data at node+0, next at node+4, flag byte at node+8), clears head/tail/count at this+0x44/+0x48/+0x4C/+0x50 and reinserts the aCustom_0 sentinel default entry.
- `0x00468EE0` **ProfileListManager** — Rebuilds the player-profile icon list: destroys the existing node chain at this+0x444 (nodes with data at +0, next at +4, flag at +8), sets the settings directory from dword_5EC440 or the byte_5EA438 default, iterates directory entries, formats 'dir+name' paths, strips each to its directory, appends the icon filename refreshed via BinarySearchInStringTable against aProfileiconBmp, loads icons via sub_497AD0 with aProfileiconDft fallback, appends (icon node, path node) pairs to the list, finalizes head/cursor and returns SetupFileLoadAndFinalize(this).
- `0x004693E0` **ProfileListManager** — Resolves the a2-th filename from the linked list rooted at this+0x444 under the element-count guard at this+0x450: walks node next pointers (node+4), copies the leaf string (node+0 dereferenced) into the buffer at this+836, truncates at the first '.' and returns a pointer past the last '\' for the bare filename; bounds failures, null nodes or empty leaves return byte_5EA438.
- `0x00469630` **ProfileListManager** — Loads a setup file: obtains an index/token via GuardedAccessor, retrieves the setup filename from the list owner sub-object at this+0x40 through FilenameFromLinkedList, returns 0 on an empty name, copies and strips the extension, normalizes paths, resolves the season path global dword_7D0434 (or the default), dispatches the file-copy check, looks the combined path up via ObjectIDLookupAcross9Arrays, loads and decodes the audio file, retrieves two sub-objects from this[16] via vtable slot 28 (args 29 and 2), processes the first via sub_470190, finalizes the second and returns 1.
- `0x0046CD20` **ProfileIconManager** — Copies the profile icon bitmap into a destination path built from this[57] (byte offset 0xE4) or the byte_5EA438 default plus the appended 'ProfileIcon.bmp' literal: removes any stale linked-list node keyed by the destination, verifies the source via sub_497AD0, isolates the filename, copies with CopyFileA (fail-if-exists), dispatches scene reload through the dword_7CD8C0 command interface (command 17 -> scene-name accessor and track config loader; command 45 -> vtable+56 call), copies data-path strings via StringCopyWithBufferRealloc, calls sub_4B0770(0) and returns 0.
- `0x0046D0D0` **SessionManager** — Session end-condition checker: ORs qualifying-DSQ-not-disabled with sub_4D24A0 or session-type compatibility, qualifying-finished with its state set, race-laps-complete (dword_8ACF8C-1), a full-grid all-finished scan, and a phase/time condition into a boolean flag, then delivers it to the session object through the vtable callback at offset 56 on *this; returns 0.
- `0x0046D6D0` **GameModeRouter** — Game-mode state router: updates the sound system via an indirect vtable call on dword_5EB10C when present, initializes the flt_5EA618 buffer, then switches on dword_7D0410 via jump table jpt_46D704: modes 1-3 dispatch the circuit-selection prompt, mode 4 chains a session-scene init and dispatches the resume prompt, mode 5 (only when SessionStateCheck(dword_7CD25C) returns 3) sets up a multiplayer session (UI lookup on this+0x40, entrant setup, config writeback, conditional season/track scene load, sets dword_5CC9E8); returns -1 on handled modes and 0 on the default.
- `0x0046DE10` **SessionManager** — Handles the multiplayer session join flow: decrements the countdown timer at this+0xE4 each tick while positive, polls the session object reached through this+0x40 via its vtable slot 28 (arg 34) and checks the FieldGetter result for a negative value; on validation failure it formats the session-id buffer, resolves and displays the join-failure page and returns -1; on success it runs the diagnostic logging block, walks every stride-4656 vehicle slot calling SessionStateTransition(-1,0), zeroes the vehicle count, rebuilds the active-vehicle pointer array, sets reconnect flags (byte_7C5690=1, dword_7C56A0=2), dispatches client team-select and returns 0.
- `0x0046E7F0` **PathModeRouter** — Path-processing loop with a final conditional branch: strips one directory component per iteration from the dword_7C73E0 path string until it is empty, then branches on this+0x168: when zero it reads a settings setup file from the path and returns its result; otherwise it retrieves UI text via UIScreenTextAccessor(this) and runs PathNormalizerFileEnumeration on the path with that text, returning its result.
- `0x0046FE80` **SessionFlagUIRow** — UI component constructor: runs the base UIComponentInit5, zeroes field 0xEC, sets field 0xF0 to -1, installs the vtable off_5A01A0 at offset 0x0, then selects one of six session-state pointers by index a2 (1-6) into field 0xE8 (unk_7CEB64, unk_7CEB7C, unk_7CEB94, unk_7CEBAC, byte_7CEBC4, unk_7CEBDC) or null for out-of-range; returns the initialized object.
- `0x00470960` **SessionSetupScreen** — Session-setup screen parameter initializer: stores the current RaceMode (dword_7D0410) at this+0x324 and a pointer to the UI index global dword_7CEAA4 at this+0x320, formats the indexed UI list item text into a local buffer, pushes it into the edit buffer, then resolves an object of type 19 through the dispatch interface at dword_7CD8C0 and compares its name against this when it exists; returns 0.
- `0x00470F20` **SessionSetupScreen** — Computes a session-mode table address as 36*dword_7D0410+8188032 and stores it at this+0x338, stores the mode value dword_7D0410 at this+0x320, then when the address is non-null dereferences it, fetches the indexed UI list item, formats it into a stack buffer and returns the result of EditBufferStringUpdate on that buffer; returns the null address immediately otherwise.

## Proposed classes

### SessionManager

Owns the session object: the phase discriminant, elapsed accumulators, countdown timer, network-comm interface, config bytes and the session-state dispatch list, and drives the per-frame update, auto-join retry, session-type setup, Game_Post flag setter, end-condition check and multiplayer join flows. Membership of 0x004637A0/0x00463F70/0x00464600/0x0046D0D0/0x0046DE10 is GUESS-level from the shared session-object fields and session globals; 0x004643C0 is DERIVED by the packet.

Methods: `0x004637A0`, `0x00463F70`, `0x004643C0`, `0x00464600`, `0x0046D0D0`, `0x0046DE10`

- `obj+0x00000028` `uint8_t serverOKRequestedFlag` (read, GUESS)
- `obj+0x00000029` `uint8_t serverOpenTrackPendingFlag` (read, GUESS)
- `obj+0x00000030` `uint32_t sessionSetupClearFlag` (write, GUESS)
- `obj+0x00000038` `int32_t sessionState` (read, GUESS)
- `obj+0x000000C5` `uint8_t sessionStateByteA` (read, GUESS)
- `obj+0x000000C6` `uint8_t autoJoinEnabledByte` (read, GUESS)
- `obj+0x0000037C` `float sessionCountdownTimer` (read_write, GUESS)
- `obj+0x00000384` `float secondaryElapsedAccumulator` (read_write, GUESS)
- `obj+0x00000388` `float sessionElapsedAccumulator` (read_write, GUESS)
- `obj+0x00003FC4` `int32_t sessionPhaseDiscriminant` (read, DERIVED)
- `obj+0x00003FD8` `uint8_t sessionConfigFlagByte` (write, GUESS)
- `obj+0x00003FD9` `uint8_t sessionConfigFlagClear` (write, GUESS)
- `obj+0x0001B770` `SessionDispatchListNode* sessionStateDispatchList` (read, GUESS)
- `obj+0x0001B774` `void* dispatchListTail` (unknown, UNKNOWN)
- `obj+0x0001B778` `void* dispatchListBookkeeping` (unknown, UNKNOWN)
- `obj+0x0001B77C` `void* dispatchListCount` (unknown, UNKNOWN)

### NetworkObjectDispatcher

Creates and dispatches texture/data objects over the network through the shared comm interface stored at obj+0x3FB8: creates the COM object via the interface vtable, sets/overrides its type, computes the send payload length and dispatches via the send wrappers (0x0057A6xx), releasing the temporary object.

Methods: `0x00462250`

- `this+0x00000000` `void* objBasePointer` (read, GUESS)
- `obj+0x00003FB8` `void* networkCommInterface` (read, DERIVED)

### ConfigCommandObject

Config/command-binding object: stores a command-binding handle looked up from the global table dword_7C7368 and owns a singly-linked node list of custom commands that is freed and re-seeded with a sentinel default entry on destruction.

Methods: `0x00466A70`

- `this+0x00000044` `LinkedListNode* commandListNodeHead` (read_write, GUESS)
- `this+0x00000048` `LinkedListNode* commandListNodeTail` (read_write, GUESS)
- `this+0x0000004C` `LinkedListNode* commandListNodeCursor` (write, GUESS)
- `this+0x00000050` `uint32_t commandListNodeCount` (write, GUESS)
- `this+0x00000104` `int32_t commandBindingHandle` (write, GUESS)
- `this+0x00000108` `int32_t commandBindingIndex` (read, GUESS)

### ProfileListManager

Owns the player-profile icon/path linked list at this+0x444..+0x450 and the setup-file list owner sub-object at this+0x40: scans profile icons from the settings directory, resolves the a2-th filename from the list, and loads setup files through the list owner. Membership of 0x004693E0 and 0x00469630 is GUESS-level from the shared list fields and the call chain 0x00469630 -> 0x004693E0.

Methods: `0x00468EE0`, `0x004693E0`, `0x00469630`

- `this+0x00000040` `ComponentObject* setupListOwnerComponent` (read, GUESS)
- `this+0x00000444` `LinkedListNode* iconPathListHead` (read_write, DERIVED)
- `this+0x00000448` `LinkedListNode* iconPathListTail` (read_write, GUESS)
- `this+0x0000044C` `LinkedListNode* iconPathListCursor` (read_write, GUESS)
- `this+0x00000450` `uint32_t iconPathListCount` (read_write, GUESS)

### ProfileIconManager

Copies the profile icon bitmap file into the managed ProfileIcon.bmp destination, removes the stale list node, reloads the scene/track configuration through the command interface and refreshes data-path strings. Single-method GUESS class; the source directory is read from this+0xE4, an offset also interpreted as a countdown timer by 0x0046DE10 (see unresolved).

Methods: `0x0046CD20`

- `this+0x000000E4` `char* sourceDirectoryPath` (read, GUESS)

### GameModeRouter

Routes the game-mode switch on dword_7D0410: circuit-selection prompts for modes 1-3, session-scene init plus resume prompt for mode 4, and multiplayer session setup for mode 5. GUESS class; the owner object is UNKNOWN in the packet and the UI-dispatch character is retained.

Methods: `0x0046D6D0`

- `this+0x00000040` `ComponentObject* targetComponent` (read, GUESS)

### PathModeRouter

Processes the module-callback-table path global dword_7C73E0 by stripping directory components, then branches on this+0x168 between a settings-setup-file read and a UI-text-driven path normalization/file enumeration.

Methods: `0x0046E7F0`

- `this+0x00000168` `int32_t modeSelect` (read, DERIVED)

### SessionFlagUIRow

UI component that selects one of six session-state pointer targets by index into field 0xE8; installs the off_5A01A0 vtable and initializes fields 0xEC/0xF0. GUESS class derived from the constructor-only packet body.

Methods: `0x0046FE80`

- `this+0x00000000` `void* vtablePointer` (write, GUESS)
- `this+0x000000E8` `void* sessionStateTarget` (write, DERIVED)
- `this+0x000000EC` `int32_t flagField` (write, GUESS)
- `this+0x000000F0` `int32_t initMinusOne` (write, GUESS)

### SessionSetupScreen

Session-setup screen parameter initializer: stores the current race/session mode and UI index into this+0x320/+0x324, computes and stores the session-mode record table address at this+0x338, and drives the indexed UI list item into the edit buffer. Membership of 0x00470F20 is GUESS-level from the shared this+0x320 field and the identical UIListIndexedAccessor/format/edit-buffer call chain.

Methods: `0x00470960`, `0x00470F20`

- `this+0x00000320` `int32_t modeOrListIndex` (read_write, DERIVED)
- `this+0x00000324` `int32_t raceModeSnapshot` (write, GUESS)
- `this+0x00000338` `void* sessionModeTableAddr` (read_write, GUESS)

### ComponentObject

Polymorphic sub-object reached through the parent's this+0x40 slot (and through the parent object base this+0x0 in the vtable-callback case): exposes a vtable whose slot 28 (byte offset 0x1C) is a dispatch/factory method invoked with an argument that selects the requested object or command (args 34, 29, 2, 17, 24, 45, 19 across the packet).

Methods: 

- `*(this+0x40)+0x00000000` `void* vtablePointer` (read, GUESS)
- `*(this+0x40)+0x0000001C` `void* dispatchMethodSlot28` (read, GUESS)
- `*(*(this+0x40)+0x0)+0x0000001C` `void* dispatchMethodSlot28Target` (read, GUESS)

### LinkedListNode

Uniform singly-linked node layout shared by the profile icon/path list and the config command list: data pointer at +0, next pointer at +4, flag byte at +8. Fields are kept per-base because the packet proves the layout only through distinct pointer expressions: the profile list inner node base *(*(this+0x444)+0x4), its leaf string base *(*(*(this+0x444)+0x4)+0x0), the profile tail base *(this+0x448), the config head base *(this+0x44) and the config tail base *(this+0x48). The class-level merge across these bases is GUESS, justified by the uniform node description in the packet.

Methods: 

- `*(*(this+0x444)+0x4)+0x00000000` `char* innerData` (read, GUESS)
- `*(*(this+0x444)+0x4)+0x00000004` `LinkedListNode* next` (read, GUESS)
- `*(*(*(this+0x444)+0x4)+0x0)+0x00000000` `char* leafString` (read, GUESS)
- `*(this+0x44)+0x00000000` `void* configData` (read, GUESS)
- `*(this+0x448)+0x00000004` `LinkedListNode* tailNext` (read_write, GUESS)
- `*(this+0x48)+0x00000004` `LinkedListNode* configTailNext` (read_write, GUESS)

### SessionDispatchListNode

Node of the session-state dispatch list rooted at obj+0x1B770: the head node carries its payload at +0 and a state byte at +8 (cleared before unlink); the packet only evidences the +0 payload field.

Methods: 

- `*(obj+0x1B770)+0x00000000` `char* payload` (read, GUESS)

## Compatibility contracts

- **SessionPhaseByteContract** — The session object field at obj+0x3FC4 holds the session phase/state id: 0 means no active session (SessionScoringUpdate returns immediately, SessionTypeSetter delegates to sub_45ECD0), values 1 and 2 select the network-setup update path (frame delta accumulated into obj+0x384, comm-gated block), and any other value selects the active path (elapsed into obj+0x388). A replacement must preserve this encoding.
- **NetworkCommInterfaceContract** — The network comm interface pointer at obj+0x3FB8 is used through the send wrappers 0x0057A6xx/0x0057A9xx/0x0057A750: texture/data objects are created via the interface vtable, typed, dispatched and released, and a dispatch returning zero is reported as success (return 1). The session functions gate their per-frame comm block on the same interface.
- **VehicleSlotResetContract** — Both the auto-join retry loop and the multiplayer join handler reset the session by walking every vehicle slot from unk_5EC6E4 with stride 4656 to dword_7C54E4, calling SessionStateTransition(-1,0) on each, then zeroing the vehicle count dword_5C329C, setting byte_7C5690=1 and dword_7C56A0=2, rebuilding the active-vehicle pointer array via 0x0042BC80 and dispatching the client team-select page (aClientTeamSele).
- **ProfileIconListContract** — The profile icon list is a singly-linked list rooted at this+0x444 with tail this+0x448, cursor this+0x44C and count this+0x450; nodes carry a data pointer at +0, a next pointer at +4 and a flag byte at +8, and list nodes pair an icon node with a path/string node. FilenameFromLinkedList resolves the a2-th entry by walking node+4, copying the leaf string into the this+836 buffer, stripping the extension at the first '.' and returning the bare filename past the last backslash.
- **CommandDispatchInterfaceContract** — The dword_7CD8C0 command interface dispatches through its vtable slot 28 with an argument selecting the command/object: 17 (scene name accessor + track config loader after icon copy), 24 (season/track scene load in the multiplayer mode path), 45 (a per-command-object vtable+56 call) and type 19 (object whose name is compared against the session-setup screen). Concrete targets are indirect and must be preserved by the replacement dispatch layer.
- **SessionStateValueContract** — SessionStateCheck (0x00461CD0) on the session object global dword_7CD25C returns 3 to signal 'ready to join/active'; the auto-join loop, the game-mode multiplayer path and the join handler all gate their session setup on that exact value, and the join handlers also require a valid UniqueID from 0x004630D0 before resetting vehicle slots.

## Unresolved

- All packet owners except SessionScoringUpdate (SessionManager, DERIVED) are UNKNOWN in the packet; SessionManager membership of 0x004637A0/0x00463F70/0x00464600/0x0046D0D0/0x0046DE10 and all other class assignments (NetworkObjectDispatcher, ConfigCommandObject, ProfileListManager, ProfileIconManager, GameModeRouter, PathModeRouter, SessionFlagUIRow, SessionSetupScreen, ComponentObject, LinkedListNode, SessionDispatchListNode) are GUESS-level proposals, not packet owner labels.
- Conflict on this+0xE4: 0x0046CD20 reads it as a source directory path (ProfileIconManager), while 0x0046DE10 reads it as a float countdown timer decremented per frame (MultiplayerSessionJoinHandler). Common ownership of this+0xE4 across those two functions is not established; the two readings may be different enclosing objects.
- The GlobalFlagBasedStateSetter target region (*this + 28132) in 0x00463F70 falls outside the declared field offsets and has no mapped field name; its byte offset is not tied to a packet field ref.
- Packets mark several globals as read that never appear in their raw decompiled bodies and are therefore unaccounted: flt_59E5FC, aD_1/dword_5C3280, unk_5EC6D0 and dword_7CD8C0 for AutoJoinRetryLoop; dword_59F0A8, dword_7CD2A8, byte_7CE498, unk_7D0EAC and unk_7D0EB4 for SessionTypeSetter; flt_59E440 for SessionScoringUpdate and MultiplayerSessionJoinHandler; dword_7CD468 for the join handler; global 0x005BE860, 0x007CE498 and 0x008AD3B4 for SetupFileLoadAndFinalize; and callee FreeWrapper_7bcf plus globals 0x007CE498/0x007CE630 for CopyProfileIconBMP (the free wrapper is reached only indirectly there).
- SessionScoringUpdate reads obj+0x1B774/0x1B778/0x1B77C per the packet but no read/write of them appears in the decompiled body; they are listed as SessionManager fields with access 'unknown' and trust UNKNOWN rather than forcing a meaning.
- MouseInputHandler is invoked at the end of 0x004643C0 in the raw source but has no packet callee evidence ref; it could not be bound beyond source:raw.
- The StringLengthCheckDispatch operand at obj+112528 (byte offset 0x1B790) has no packet field evidence ref; the packet field at 0x1B77C is 20 bytes earlier and is not the same offset.
- The vtable-callback attribution of field:obj:0x00000038 in 0x0046D0D0 is ambiguous: the op is an indirect call (*(*this + 56))(this, flag), while the field ref names obj+0x38 (the session state field also gating 0x0046DE10); the two readings are kept but their equivalence is unproven.
- The this+0x40 sub-object (ComponentObject) is dereferenced as a vtable component by 0x0046D6D0 (UI lookup), 0x0046DE10 (session poll) and 0x00469630 (setup-file list owner). This suggests one enclosing class, but common ownership is not proven and the offset is kept per-base per the field rule.
- ProfileListManager's this+0x40 field is declared there while GameModeRouter also dereferences this+0x40; the same base/offset in two classes is recorded here rather than merging, because the packet does not prove they are the same enclosing object.
- The list-node bases *(this+0x444) offset +4 (profile next) and *(this+0x448) offset +4 (tail next) versus the config-list bases *(this+0x44)/*(this+0x48) are merged into one LinkedListNode class at GUESS; the packet only evidences the exact pointer expressions declared as fields.
- The 16312 (0x3FB8) interface offset and the exact object type created by 0x00462250 are not derivable from that function alone; the 0x57A6xx create/dispatch/release sequence is the only lock.
- GameModeRouter's dword_7D0410 mode meaning, the SessionStateCheck return-3 semantics beyond 'ready', the identities of dword_5EB10C/dword_7CD25C/dword_7CD8C0 and the dword_7D0E50 dispatch values are unconfirmed.
- The six session-state target globals unk_7CEB64..unk_7CEBDC are opaque; whether they are flag bytes or structs is not evidenced.
- SessionSetupScreen's this+0x338 stores 36*dword_7D0410+8188032, implying a session-mode record table (36-byte stride), but the record layout is not evidenced and the role of the this+0x320/0x324/0x338 fields beyond setup is unknown.
- dword_8ACF8C is assumed a lap count in the end-condition machine; whether it is a lap count or another race total is unresolved from 0x0046D0D0 alone, as are the vehicle-state offset roles (+13000, +16444, +16484).
- 0x0046E7F0 names its settings-read callee SettingsSetupFileRead in the raw source, but the packet callee list has no matching entry, so its address cannot be pinned from this packet.
- The guard:0 vs guard:1 recording in 0x00468EE0 differs from the raw head test at this+0x444; the cursor offset association is a DERIVED reading.
- Exact path-format string literals (aPlr_0, aProfileiconBmp, aCustom_0, aJoinSessionWas and the other diagnostic literals) have content not established by this packet; only their address globals are cited.
