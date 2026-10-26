# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Proposal for the generic_runtime_objects slice of Wave 3. The functions cluster into: a game/session object controller (0x463E20 entry init, 0x463EF0 mode-dependent state reset, 0x464290 session sync, 0x464670 conditional exit cleanup) sharing a packed obj base (init flag 0x1D0, session state 0x3FC4, network sub-object 0x3FB8, self pointer 0x3FC0, stored argument 0x417C, flag block 0x1B790/0x1B791, secondary network object 0x1B79C); a session-plugin cleanup dispatcher (0x46E170) driving the global dword_7CD8C0; a shared 12-byte linked-list node layout (data/key +0, next +4, free-data flag +8) used by the keyed list (0x464740), the per-frame resource manager (0x4651C0) and the stats pages (0x468A00, 0x469D30, 0x46A560); UI widget base machinery (constructor 0x466D60, action dispatch 0x4670E0); a credits.txt list loader (0x467E40); profile/menu string builders (0x4692B0, 0x46AD50); session-grid state (0x46B9B0 loading-grid message, 0x46C820 qualifying order); the timer/standings UI list (0x46BA20); and the race broadcast/AI-overtake tick (0x46BF10). Small free-standing clamp helpers (0x4646C0 float, 0x464720 byte) round out the set. Ownership is mostly UNKNOWN, so most classes here are GUESS proposals.

## Function roles

- `0x00463E20` **GameSessionController** — Game entry initializer called from Game_Enter: initializes an audio-stream descriptor with defaults and links it into the game object, copies the instance handle and a word global, formats the title string '%s %.3f', and on a successful stack-buffer copy predicate records the init flag (obj+0x1D0), the game self pointer (obj+0x3FC0) and a vtable-query result (obj+0x417C); returns the network replay buffer init result.
- `0x00463EF0` **GameSessionController** — Mode-dependent session state reset: when the init flag at obj+0x1D0 is not 1, resets the session state field obj+0x3FC4 to 0; when the global init guard byte_7CE260 is clear and dword_7D0410 equals 5 (championship mode), clamps the player count into dword_7D0A44 and the vehicle count into dword_7D0990; returns the object pointer.
- `0x00464290` **GameSessionController** — Multiplayer session synchronization: while the session state at obj+0x3FC4 is non-zero, either resets arrays/player slots (running collision detection at state 3) or performs one-time initialization of the session sub-objects (loop over 218-byte slots at (*this)[4192]); states 1/2 configure a byte field on the sub-object at obj+0x3FB8, other states set retry timeouts and clear accumulated fields; runs final array initialization and returns the threaded result byte.
- `0x00464670` **GameSessionController** — Conditional two-part cleanup of network-object state on game exit: when the pointer at obj+0x3FB8 is non-zero, calls the vtable method at offset 0x7C with the stored argument (obj+0x417C), validates the pointer and zeroes the slot; then resets the flag block at this+0x1B790 and, when the pointer at obj+0x1B79C is non-zero, runs network cleanup on it and zeroes it.
- `0x004646C0` **ClampUtilities** — Free-standing float clamp: clamps the float at this->offset 0 into the inclusive range [a2, a3], writing the violated bound and leaving the value unchanged when it already lies within range.
- `0x00464720` **ClampUtilities** — Free-standing byte clamp: clamps the byte at a1 into the inclusive range [a2, a3] and returns the pre-clamp value; the decompiler comma-operator expression (a2 = a3, result > a3) is a codegen artifact for selecting the violated bound.
- `0x00464740` **KeyedLinkedList** — Removes a node whose key equals a2 from a singly-linked list (head this[0], tail this[1], newest/tail-tracker this[2], count this[3]), relinking around the match, advancing the tracked newest pointer and the tail when needed, decrementing the count, and conditionally freeing the node's embedded data block (guarded by the flag byte at node+8) and the node itself; returns 1 on success, 0 when a2 is null, the list is empty, or the key is not found.
- `0x004651C0` **ResourceManager** — Per-frame resource-manager cleanup: computes the frame timestep from the high-resolution timer, clamps it to [0.001, 1.0], stores it at obj+0x60, drains and frees two singly linked lists headed at obj+0x6C and obj+0x7C (freeing each node's embedded data pointer when the node+8 flag byte is 0), clears the list-head dwords, zeroes a 104-entry flags array at dword offset 62 (obj+0xF8, stride 140 dwords), resets the float accumulator at obj+0xE40C and returns the manager pointer.
- `0x00466D60` **UIWidgetBase** — UI widget base initializer shared by 33 UI/widget constructor paths: calls sub_48C070(a2), zeroes six state fields at this+0x31C through this+0x330, installs the vtable pointer off_59F438 at this+0x0 and returns this.
- `0x004670E0` **UIWidgetBase** — Action dispatcher on a UI object: computes an action index from this+0x334 minus 236 and, when at most 0xB1, jumps through byte_46713C (base jpt_4670FC) to invoke the dword_7CD8C0 vtable+28 method with argument 14 (case 0) or 11 (case 1), running ObjectNameComparison on a non-zero dispatch, or returning 0 (case 2 and fall-through).
- `0x00467E40` **CreditsList** — Credits list loader: builds the full path to 'credits.txt' (override pointer dword_5EC408 or default byte_5EA438), opens it via AudioStreamOpen, reads it line-by-line into a 256-byte buffer, truncates each line at the delimiter asc_5C30B0, and appends a 12-byte list node (string-node pointer, next, flag) to the singly linked list at this+0xF8..0x104; returns the stack-struct cleanup helper result.
- `0x00468A00` **CareerStatsPage** — Resets the career-mode driver stats page: copies a cached flag (byte_7CFF32 into byte_7CFF30), invokes a vtable method at obj+0x3C with argument 0, builds the world-championships page, frees and clears the stat list at this+0x44..0x50, reinstates 13 stat keys via LinkedListInsertWithNodeAllocation, runs state cleanup, invokes a second vtable-dispatched init and sub_468BF0, and returns 0.
- `0x004692B0` **PlayerProfileManager** — Profile icon loader: builds the path to 'ProfileIcon.bmp' from the settings directory (dword_5EC440, falling back to byte_5EA438) and a profile filename retrieved from a linked list, trims trailing backslashes, resolves the icon name through the string table into byte_5EC4CC, removes the linked-list entry matching the built path, and triggers a profile rescan via PlayerProfileScanner; returns 0.
- `0x00469D30` **CareerStatsPage** — Tears down the career-mode player stats display: frees the stat list rooted at this+0x44, clears the list bookkeeping fields, reinstates three stat keys (aCircuit, aExperienceLaps, aBestLap), runs state cleanup, rebuilds the player stats page via sub_469900, resets a flag via ByteSetterAt0xe0 and returns 0.
- `0x0046A560` **CareerStatsPage** — Career/season standings statistics menu builder: prepares local string buffers, runs state cleanup, frees the four-entry list group anchored at this+0x44, re-seeds the list control with nine stat keys, and emits nine formatted menu items pairing a UI-list label (index 0..8) with a career-scoring value from the dword_7D2DD4..7D2DF8 block (integer items for indices 0,1,4,5,6,7,8; one-decimal float items for indices 2,3); returns the last menu-item result.
- `0x0046AD50` **MenuDisplayStringBuilder** — Menu display-string builder: retrieves the module pointer for index a1 from the ppvOut array and the action name from the dword_7D1B08 table (stride 7), copies the module name into the shared display buffer byte_5EC4CC when present in the string table, concatenates module and action path into the caller's output buffer, and optionally creates a UI menu item when the a3 flag is set; returns the flag.
- `0x0046B9B0` **SessionGridController** — Loading-grid message setup: runs state cleanup, resets the state/session field at this+0x178 to -1, and in championship mode (dword_7D0410 == 5) verifies the Loading Grid string in the string table, copies it into the display buffer byte_5EC4CC and creates a UI menu item; otherwise returns the earlier cleanup result.
- `0x0046BA20` **TimerStandingsList** — Refreshes a timer/standings UI list: with a2 non-zero forces a full rebuild (state cleanup, then for each grid slot v11 = 1..104 locates the vehicle whose position field equals v11 in dword_7C54F0, skipping retired vehicles, and creates a menu item with the vehicle number formatted as '%d'); with a2 zero updates item text incrementally per slot, routing to the full rebuild on a missing item or a text mismatch.
- `0x0046BF10` **RaceBroadcastController** — Race broadcast / AI overtake update tick: derives a race-time budget (flt_8ACF94 - flt_8ACF90 for session types 1..6, unbounded 1.0e9 for qualifying type 7), acquires a session lock, drains AI overtake events applying session updates, and in qualifying dispatches a sound-system vtable call, re-initializes an audio buffer and triggers race commentary; releases the lock and returns the scratch-buffer teardown result.
- `0x0046C820` **SessionGridController** — Resets the qualifying-order arrays: when the selector byte at this+0x174 is non-zero, copies the qualifying-score field (+18580) of every live vehicle in dword_7C54F0 into dword_7CD2B8 and fills the remainder of the 104-slot array with -1; otherwise calls sub_497AD0 on the scene object at this+0x40 and fills dword_7CD470 with -1; every path sets this+0x178 to -1 and returns -1.
- `0x0046E170` **SessionPluginDispatcher** — Session-plugin cleanup dispatch: on the global session/plugin object dword_7CD8C0 invokes its vtable slot at +28 with argument 36 then 35, passing each non-null returned object to StateCleanupNotification; returns the second notification result, or the second vtable call result when null.

## Proposed classes

### GameSessionController

Game/session object controller for the entry, setup and exit paths. Reached through this[0] (obj base); owns the init flag, session state, network sub-object pointer with stored argument and self pointer, the session sync byte, retry/active fields, and the exit-time flag block with a secondary network object. Game_Enter/Game_Setup/Game_Restart/GameExit drive these methods.

Methods: `0x00463E20`, `0x00463EF0`, `0x00464290`, `0x00464670`

- `obj+0x00000010` `float timeout_value` (write, DERIVED)
- `obj+0x00000014` `byte active_flag` (write, DERIVED)
- `obj+0x00000028` `byte sync_byte` (read_write, DERIVED)
- `obj+0x000001D0` `int init_flag` (read_write, DERIVED)
- `obj+0x00000380` `int accumulated_a` (read_write, GUESS)
- `obj+0x00000388` `int accumulated_b` (read_write, GUESS)
- `obj+0x00000390` `float retry_delta` (write, DERIVED)
- `obj+0x00003FB8` `pointer network_sub_object` (read_write, DERIVED)
- `obj+0x00003FC0` `pointer self_pointer` (write, DERIVED)
- `obj+0x00003FC4` `int session_state` (read_write, DERIVED)
- `obj+0x0000417C` `pointer stored_argument` (read, DERIVED)
- `obj+0x0001B790` `byte flag_block_a` (read, GUESS)
- `obj+0x0001B791` `byte flag_block_b` (read, GUESS)
- `obj+0x0001B79C` `pointer secondary_network_object` (read_write, DERIVED)

### SessionPluginDispatcher

Dispatches state-cleanup notifications on the global session/plugin object dword_7CD8C0 through its vtable slot at +28, passing notification identifiers (36, 35) and forwarding the returned objects to StateCleanupNotification. The concrete class behind dword_7CD8C0 is unknown.

Methods: `0x0046E170`


### ClampUtilities

Two small free-standing value clamps: FloatClamp clamps the float at the pointer operand into [a2, a3]; ByteClamp clamps a byte at a1 into [a2, a3] and returns the pre-clamp value. Not a real owning class; grouped as shared utilities.

Methods: `0x004646C0`, `0x00464720`

- `this+0x00000000` `float value` (read_write, GUESS)

### LinkedListNode

Shared 12-byte singly-linked-list node layout used by the keyed list, the per-frame resource manager lists and the stats pages: a data/key pointer at +0, a next pointer at +4 and a free-data flag byte at +8. Node identity is established by the identical layout across three independent list walks in this packet.

Methods: 

- `*(obj+0x6C)+0x00000000` `pointer data_or_key` (read, DERIVED)
- `*(*(obj+0x6C)+0x4)+0x00000004` `pointer next` (read_write, DERIVED)
- `*(obj+0x6C)+0x00000008` `byte free_data_flag` (read, DERIVED)

### KeyedLinkedList

Singly-linked list keyed by node data/key, with control dwords at this[0..3] (head, tail, newest/tail-tracker, count). Removes a node by key, relinking around it, maintaining the tracked newest pointer and the tail, decrementing the count and freeing the node (and its embedded data block when flagged).

Methods: `0x00464740`

- `this+0x00000000` `pointer head` (read_write, DERIVED)
- `this+0x00000004` `pointer tail` (read_write, DERIVED)
- `this+0x00000008` `pointer newest` (read_write, DERIVED)
- `this+0x0000000C` `int count` (read_write, DERIVED)

### ResourceManager

Per-frame resource manager. Stores the clamped frame timestep, manages two singly linked lists of nodes (heads at obj+0x6C and obj+0x7C, cleared to four zero dwords each after draining), zeroes a 104-entry flags array at dword offset 62 (obj+0xF8, stride 140 dwords; described from the raw source text only, no packet field ref) and holds a float accumulator at obj+0xE40C. Called each frame by the team-radio network message processing path.

Methods: `0x004651C0`

- `obj+0x00000060` `float frame_timestep` (write, DERIVED)
- `obj+0x0000006C` `pointer list_a_head` (read_write, DERIVED)
- `obj+0x00000070` `pointer list_a_field1` (write, GUESS)
- `obj+0x00000074` `pointer list_a_field2` (write, GUESS)
- `obj+0x00000078` `pointer list_a_field3` (write, GUESS)
- `obj+0x0000007C` `pointer list_b_head` (read_write, DERIVED)
- `obj+0x00000080` `pointer list_b_field1` (write, GUESS)
- `obj+0x00000084` `pointer list_b_field2` (write, GUESS)
- `obj+0x00000088` `pointer list_b_field3` (write, GUESS)
- `obj+0x0000E40C` `float accumulator` (read_write, DERIVED)

### UIWidgetBase

Base for UI widgets/controls. Shared by a constructor (33 UI/widget caller paths) that zeroes six state fields at this+0x31C..0x330 and installs vtable off_59F438, and by an action dispatcher that reads the action-id field at this+0x334 and routes through a jump table to the dword_7CD8C0 dispatch interface. Same-object identity across the two methods is not proven; the field adjacency is suggestive only.

Methods: `0x00466D60`, `0x004670E0`

- `this+0x00000000` `pointer vtable` (read_write, DERIVED)
- `this+0x0000031C` `int state_field_199` (write, DERIVED)
- `this+0x00000324` `int state_field_201` (write, DERIVED)
- `this+0x00000328` `int state_field_202` (write, DERIVED)
- `this+0x0000032C` `int state_field_203` (write, DERIVED)
- `this+0x00000330` `int state_field_204` (write, DERIVED)
- `this+0x00000334` `int action_id` (read, DERIVED)

### CreditsList

Loads the credits text file into a singly linked list of string nodes. Control block at this+0xF8..0x104 (head, tail, current, count); list nodes hold a string-node pointer, a next pointer and a byte flag. Builds the file path from an override or default directory.

Methods: `0x00467E40`

- `this+0x000000F8` `pointer head` (read_write, DERIVED)
- `this+0x000000FC` `pointer tail` (read_write, DERIVED)
- `this+0x00000100` `pointer current` (read_write, GUESS)
- `this+0x00000104` `int count` (read_write, DERIVED)

### CareerStatsPage

Career/season statistics menu page. Owns a vtable, a stat list control block at this+0x44..0x50 (head, tail, count, capacity) and a vtable dispatch slot at obj+0x3C. Frees/rebuilds the list with varying stat-key sets (world-championships driver stats, player stats display, standings display), runs state cleanup and formats career-scoring globals into menu items.

Methods: `0x00468A00`, `0x00469D30`, `0x0046A560`

- `this+0x00000000` `pointer vtable` (read, GUESS)
- `obj+0x0000003C` `function_pointer vtable_slot_60` (read, GUESS)
- `this+0x00000044` `pointer list_head` (read_write, DERIVED)
- `this+0x00000048` `pointer list_tail` (read_write, DERIVED)
- `this+0x0000004C` `int list_count` (read_write, DERIVED)
- `this+0x00000050` `int list_capacity` (read_write, GUESS)

### PlayerProfileManager

Player-profile path management. Builds file paths for profile resources (e.g. ProfileIcon.bmp) from the settings directory with a default-directory fallback, resolves resource names through the shared string table, removes stale linked-list entries matching a path and triggers profile rescans.

Methods: `0x004692B0`


### MenuDisplayStringBuilder

Builds display strings for menu entries from an action index: resolves a module pointer and an action name from index tables, normalizes them through the shared string table into byte_5EC4CC and concatenates them into a caller buffer, optionally creating a UI menu item.

Methods: `0x0046AD50`


### SessionGridController

Session grid state controller for championship mode. Holds the session identifier field at this+0x178 (reset to -1) and a mode-selector byte at this+0x174; builds the loading-grid menu message and resets the qualifying-order arrays (vehicle-score copy or scene-object path).

Methods: `0x0046B9B0`, `0x0046C820`

- `this+0x00000040` `pointer scene_object` (read, DERIVED)
- `this+0x00000174` `byte selector_byte` (read, DERIVED)
- `this+0x00000178` `int session_identifier` (read_write, DERIVED)

### TimerStandingsList

Timer/standings UI list that shows grid order. Supports a full rebuild (per grid slot, find the vehicle by position, create a menu item with its number) and an incremental text-update path that falls back to the full rebuild on a missing item or text mismatch. Owner label is carried DERIVED from the packet.

Methods: `0x0046BA20`


### RaceBroadcastController

Race broadcast / AI overtake runtime controller. Derives a race-time budget from the session type, acquires and releases the session lock around an AI-overtake event drain that applies session updates, and finalizes qualifying (sound-system vtable dispatch, audio-buffer reinit, race commentary).

Methods: `0x0046BF10`

- `this+0x00000040` `pointer session_sub_object` (read, DERIVED)

## Compatibility contracts

- **GameSessionObjectLayoutContract** — The session/game object reached through this[0] carries: an init flag at +0x1D0 (1 after successful entry init, else 0), a session state at +0x3FC4, a network sub-object pointer at +0x3FB8 with a stored argument at +0x417C and a self pointer at +0x3FC0, a sync byte at +0x28, retry/active fields at +0x10/+0x14/+0x390, accumulated fields at +0x380/+0x388, and an exit-time flag block at +0x1B790 with a secondary network object at +0x1B79C. A replacement must preserve these offsets for game entry, session sync and exit cleanup.
- **SessionSyncStateContract** — Session state at obj+0x3FC4: 0 is inactive; state 3 runs collision detection; states 1/2 select the sub-object byte-field configuration path (writing 0 when dword_7C56A4 == 7 or (byte_7D105C set and dword_7C56A4 == 5), otherwise 1); other non-zero values set retry timeouts (obj+0x10 = 5.0, obj+0x14 = 1, obj+0x390 = 0.01) and clear the accumulated fields.
- **ChampionshipModeContract** — Global dword_7D0410 == 5 selects championship mode: it gates the player/vehicle count clamping (into dword_7D0A44 from dword_7D0A4C/dword_7D0A50, and dword_7D0990 from dword_7D0998/dword_7D099C) and the Loading Grid message menu-item path.
- **SessionTypeBudgetContract** — Global dword_7C56A4 is the session type: types 1..6 compute a race-time budget flt_8ACF94 - flt_8ACF90; type 7 (qualifying) uses an effectively unbounded 1.0e9 budget and, on finalization, invokes the sound-system vtable+12 when dword_5EB10C is non-null, re-initializes an audio buffer at flt_5EA618 and triggers race commentary.
- **CareerScoringDisplayContract** — The standings menu formats nine career-scoring globals in the block dword_7D2DD4..7D2DF8: integer format (aSSI, global 0x5C6858) for indices 0,1,4,5,6,7,8 (dword_7D2DD4, 7D2DD8, 7D2DEC, 7D2DE0, 7D2DE8, 7D2DF0, 7D2DE4) and one-decimal float format (aSS1f, global 0x5C684C) for indices 2,3 (flt_7D2DF4, flt_7D2DF8).
- **SharedDisplayBufferContract** — byte_5EC4CC is a shared display/name buffer and byte_5EC4C0 the string-table base used by the profile-icon loader, the message-name builder and the loading-grid path; BinarySearchInStringTable resolves names into byte_5EC4CC.
- **VehicleGridAccessContract** — Active vehicle pointers are held in dword_7C54F0 with count dword_5C329C; per-vehicle fields used here are position (+16480), slot state (+13000, -1 retired/inactive) and number/qualifying score (+18580). The timer standings list and qualifying-order reset depend on this layout. The per-vehicle offsets are read from the raw source text and corpus knowledge, not from packet field references, so they carry GUESS-grade evidence.

## Unresolved

- Owners of most functions are UNKNOWN at the function-IR level; the class grouping here is a DERIVED/GUESS proposal, not a confirmed identity. Only 0x0046BA20 carries a DERIVED owner (TimerStandingsList) in the packet.
- The four functions grouped as GameSessionController share the obj base (dereferenced this[0]) and overlapping packed offsets (0x1D0, 0x3FB8, 0x3FC0, 0x3FC4, 0x417C, 0x1B790, 0x1B791, 0x1B79C); common ownership is inferred from offset reuse across Game_Enter/Game_Setup/Game_Restart/GameExit, not proven.
- UIWidgetBase groups 0x00466D60 (constructor installing vtable off_59F438) with 0x004670E0 (action dispatch reading this+0x334); same-object identity is not proven, though 0x334 is immediately adjacent to the constructor's zeroed 0x31C..0x330 block.
- 0x0046BF10 and 0x0046C820 both read a pointer at this+0x40 (passed to sub_496880 vs sub_497AD0); the equal offset on separate classes is not evidence of shared object ownership.
- CreditsTxtParser packet metadata flags this+0x104 as read-only while the body executes ++this[65]; the discrepancy between the increment and the R label is unresolved.
- The stat-list rebuild counts differ across the three stats functions: 0x00468A00 reinstates 13 keys (with a duplicated aExperienceLaps insertion and an extra aCircuit/aBestLap pair beyond the base ten), 0x00469D30 reinstates only three keys, and 0x0046A560 seeds nine keys; whether the differences are intentional is unresolved.
- The 8-byte string node layout (v4[0] = 0, v4[1] = -1) in CreditsTxtParser and the discarded return of StringCopyWithBufferRealloc have no packet-explained meaning.
- The semantics of the per-node flag byte (+8) and of the LinkedListNodeRemoval node field at +0xC (packet-listed but never written in this body) are unresolved.
- dword_5EC440 (settings directory) and byte_5EA438 (default application directory) are DERIVED readings from existing analysis, not independently confirmed by this packet.
- Packet-listed globals absent from the raw decompiled bodies: flt_59E43C, flt_59E600, flt_59F0A0, flt_59F0B8, aD_1 (0x5C3280), dword_5EB978, byte_7CE498; their roles are unresolved.
- The follow-up init routine sub_562AC0 / off_5E4DFC in 0x00464290 and the NetworkCleanup routine in 0x00464670 appear only descriptively and have no evidence entries in this packet.
- Per-vehicle offsets 16480 (position), 13000 (slot state, -1 retired) and 18580 (number / qualifying score) are inferred from corpus knowledge and the raw source text, not proven by packet field references.
- The qualifying (session type 7) audio-buffer reinit and race-commentary sequence in 0x0046BF10 is semantically inferred from callee names, not documented.
- Why a timer/standings text mismatch or missing item routes to the full rebuild path instead of a local repair (0x0046BA20) is unresolved.
- The mapping between the nine UIListIndexedAccessor indices and the nine inserted stat keys in 0x0046A560 is not evidenced.
- The meaning of the dword_7CD8C0 vtable+28 method and of the notification identifiers 35/36 passed by 0x0046E170 is unknown; the first StateCleanupNotification return value is discarded.
- The vtable slot at obj+0x3C (byte offset 60) dispatched by 0x00468A00 is identified only by raw offset, not by a named method.
