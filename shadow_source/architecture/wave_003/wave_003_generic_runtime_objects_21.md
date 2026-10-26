# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Proposal for the generic_runtime_objects slice of Wave 3. The set clusters around: a multi-level allocator (0x4BB200) that builds a 4-byte header, a 384-byte payload of 32 x 12-byte slots, and two 12-byte-node lists (block list and slot list), used by the model/scene file loader (0x4B6C90); generic singly-linked list node removal by value (0x4BB6B0) and list destruction (0x4BF640) over a shared 4-dword control block and 12-byte nodes; a HUD penalty/warning message family sharing the same guard fields (this+0x0 penalty-state pointer, this+0x4 driver id, this+0x30 pending flag) in fine display (0x4BBA90), warning handler (0x4BBC60), stop-go penalty handler (0x4BBD60) and disqualification handler (0x4BC0E0), all resolving tokens through the message table (byte_5EC4C0 -> byte_5EC4CC) and rendering on dword_7CD204; a fixed-slot progress-bar event ring buffer (dword_8AAE64 pointer, dword_83EE60 count capped 1023, 432-byte stride, dbl_8AFEA0 time) written by 0x4BBD60/0x4BBF20/0x4BC0E0/0x4BC390 via ProgressBarEventEncode (0x4B33B0); per-frame AI driver race-state update (0x4BCCC0, owner AIDriverController) covering distance projection, pit-lane speed limits, corner-cut and wrong-way detection, and pit-selection through the dword_5EB978 state machine; lap/split timing (0x4BC390); grid alignment/jump-start validation (0x4BC9B0); racing-line mode reset guard (0x4BC240); snapshot field copies (0x4BC320/0x4BC330); a four-dword zeroer (0x4BF630); a conditional secondary-data destructor (0x4BB460); and starting-grid assignment for championship sessions (0x4BFF70). Ownership is UNKNOWN at the function-IR level for most members; classes here are DERIVED/GUESS proposals, not confirmed identities.

## Function roles

- `0x004BB200` **MultiLevelAllocator** — Multi-level allocator setup on a __thiscall container: allocates a 4-byte header holding a pointer to a 384-byte payload block (32 slots x 12 bytes), registers the block as an in-use 12-byte node at the head of the block-level list (head this+0, tail this+4, back this+8, count this+0xC), then walks the block and chains one free 12-byte slot node per slot into the slot-level list (head this+0x10, tails this+0x14/0x18, count this+0x1C); returns the last allocated slot node for the caller ModelSceneFileLoader.
- `0x004BB460` **SecondaryDataOwner** — Secondary-data destructor: frees the allocation at this+0x4 through FreeWrapper_7bcf when non-null, then frees the object itself through the same wrapper when flag bit 0 of a2 is set; returns this. Called by ModelSceneFileLoader.
- `0x004BB6B0` **SinglyLinkedList** — Singly-linked list node removal by value: walks from head this+0 through node+4 next links comparing each node's first dword to a2; on a match unlinks the node, maintains head this+0, second pointer this+4 and tail this+8, decrements count this+0xC, clears or honors the node flag byte at +8, frees the node's owned data via FreeWrapper_7bcf when flagged, frees the node itself, and returns 1.
- `0x004BBA90` **PenaltyWarningController** — HUD fine/penalty message display: gated on the pending flag this+0x30 and the penalty-state flag obj+0x32C8 (read through this+0); resolves the 'Fined US'/'Penalty' token and the driver name through the message table into byte_5EC4CC, formats the fine amount (CRTFtol) and renders via TextLineWrappingAndRendering; accumulates the fine total at this+0xA4.
- `0x004BBC60` **PenaltyWarningController** — HUD warning message display: gated on the pending-warning flag this+0x30, a non-null a2, and the penalty-state flag obj+0x32C8 (read through *this); resolves the 'Warning' token into byte_5EC4CC, conditionally replaces it with the a2 message, formats '%s %s' into a 192-byte buffer and renders it on the HUD; returns the flag read from this+0x30.
- `0x004BBD60` **PenaltyWarningController** — Stop-go penalty handler: gated on this+0x30; resolves 'Stop Go Penalty' plus driver name through the message table, renders to the HUD text line, records a ring-buffer penalty event (type 4, id 23) carrying driver id this+0x4 and session time, then dispatches the penalty to the vehicle object via sub_41A720.
- `0x004BBF20` **ProgressBarEventWriter** — Emits a progress-bar stage event (type 4, id 24) into the fixed-slot ring buffer via ProgressBarEventEncode with driver id this+0x4 and session time, advancing the write pointer by 432 and capping the count at 1023; returns the stage value at this+0x44.
- `0x004BC0E0` **PenaltyWarningController** — Disqualification handler: when this+0x30 != 3, renders 'Disqualified: <driver>' on the HUD and logs a disqualification event (type 4, id 28) into the ring buffer, then dispatches via sub_41A940; the message path requires a driver-name a2 and a clear penalty-state flag obj+0x32C8. this+0x30 is only read, never written, so the routine cannot re-arm itself.
- `0x004BC240` **RacingLineModeController** — Per-frame racing-line mode guard: when the session-type global dword_7C56A4 is not qualifying (7), reads the object pointer at this+0, and if the object flag byte obj+0x344C is set resets the racing-line mode at this+0x60 from 2 to 1; returns the object pointer.
- `0x004BC320` **SnapshotFieldCopier** — Snapshot field copy: reads the dword at this+0x2C, copies the float at this+0x68 into this+0x28, stores the dword into this+0x24 and returns it; used by multiplayer vehicle placement and netcomm slot-sync paths to preserve a current-state snapshot before an update.
- `0x004BC330` **SnapshotFieldCopier** — Unconditional field copy: reads the int at this+0x24, writes it to this+0x2C and returns the copied value; invoked by MultiplayerVehiclePlacement and RestartGate.
- `0x004BC390` **LapSplitEventProcessor** — Lap/split timing event processor: aborts early when the float at this+0xB0 exceeds 10.0, reads the event-type flag via FlagPropertyGetter(2048) from obj+0x32C8, routes on the event type (0/1/2) against the lap/sector state at this+0xC, computes a split-time delta from this+0x60/0x64, optionally writes encoded event data, allocates a ring-buffer slot, encodes a progress-bar event (type 4, id 8) and finalizes via LapCompletion.
- `0x004BC9B0` **GridAlignmentValidator** — Grid alignment / jump-start validator: dereferences this+0 to the vehicle float base, computes a velocity/acceleration magnitude squared (obj+0x34F8/0x34FC/0x3500) and orientation dot products; in penalty-check mode applies StopGoPenaltyHandler or DisqualificationHandler jump-start penalties when global dword_7CEF84 is set and the penalty-state flag obj+0x32C8 is not already 1; otherwise renders 'not lined up' status messages.
- `0x004BCCC0` **AIDriverRaceStateController** — Per-frame AI driver race-state update (from MainGameTickUpdate): recomputes and wraps the driver's track distance projection, enforces pit-lane speed limits with stop-go penalties and monetary fines, detects corner cutting and wrong-way driving, manages cut-track/blue-flag penalty timers, and drives pit-entry selection based on nearby-vehicle proximity through the dword_5EB978 state machine.
- `0x004BF630` **IntBlockZeroer** — Zero-initializes four consecutive dwords of a __thiscall object at this+0x0/0x4/0x8/0xC and returns this; a pure field writer used at object setup by AI driver count, filter-data loading and generic struct-init paths.
- `0x004BF640` **SinglyLinkedList** — Destroys the singly-linked list rooted at this+0: for each node reads the flag byte at node+8 and the next pointer at node+4, frees the node payload (first dword) via FreeWrapper_7bcf when flagged, then frees the node; afterwards zeroes the four head dwords this+0..0xC and returns a value captured from sub_4BF730.
- `0x004BFF70` **StartingGridAssigner** — Starting-grid assignment for championship sessions (dword_7D0410 in 1..5): the qualifying path gathers per-driver qualifying position and time, sorts ascending by position, and writes grid position and time into 18624-byte-stride vehicle records; the non-qualifying path places the player (random when dword_7D0110 is zero) and fills the remaining vehicles sequentially, skipping the player grid.

## Proposed classes

### MultiLevelAllocator

Two-level slot allocator. Holds two singly-linked node lists over a 4-byte header whose single dword points to a 384-byte payload block split into 32 x 12-byte slots. The block list (head/tail/back/count) registers the payload block as an in-use node; the slot list (head, two tails, count) chains one free node per slot. Used by the model/scene file loader to grow its object pool.

Methods: `0x004BB200`

- `this+0x00000000` `pointer block_list_head` (read_write, DERIVED)
- `this+0x00000004` `pointer block_list_tail` (write, DERIVED)
- `this+0x00000008` `pointer block_list_back` (write, DERIVED)
- `this+0x0000000C` `int block_list_count` (read_write, DERIVED)
- `this+0x00000010` `pointer slot_list_head` (read_write, DERIVED)
- `this+0x00000014` `pointer slot_list_tail_a` (write, DERIVED)
- `this+0x00000018` `pointer slot_list_tail_b` (write, DERIVED)
- `this+0x0000001C` `int slot_list_count` (read_write, DERIVED)

### SecondaryDataOwner

Small owned-object wrapper holding a secondary allocation at this+0x4. Its destructor frees the secondary data and conditionally frees the object itself based on the delete-flag bit of its argument. The container class identity is unknown; this+0x4 is not merged with any other owner's this+0x4.

Methods: `0x004BB460`

- `this+0x00000004` `pointer secondary_data_ptr` (read_write, GUESS)

### SinglyLinkedList

Generic singly-linked list container with a four-dword control block (head/second/tail/count) and 12-byte nodes holding (data/value, next, flag byte). Supports value-based node removal and full destruction; node payload freeing is governed by the node flag byte.

Methods: `0x004BB6B0`, `0x004BF640`

- `this+0x00000000` `pointer head` (read_write, DERIVED)
- `this+0x00000004` `pointer second_pointer` (read_write, GUESS)
- `this+0x00000008` `pointer tail` (read_write, DERIVED)
- `this+0x0000000C` `int count` (read_write, DERIVED)
- `obj+0x00000000` `pointer data` (read_write, DERIVED)
- `obj+0x00000004` `pointer next` (read_write, DERIVED)
- `obj+0x00000008` `byte flag_byte` (read_write, DERIVED)
- `*(obj+0x4)+0x00000000` `int value` (read, DERIVED)
- `*(obj+0x4)+0x00000004` `pointer next` (read_write, DERIVED)
- `*(obj+0x4)+0x00000008` `byte flag_byte` (read_write, DERIVED)

### PenaltyWarningController

HUD message controller family for race penalties and warnings. All four handlers share the guard fields this+0x0 (penalty-state object pointer), this+0x4 (driver id) and this+0x30 (pending-message flag); they resolve localized tokens and the driver name through the message table into the shared byte_5EC4CC buffer, render to the HUD text line, record ring-buffer penalty events, and accumulate the fine total at this+0xA4.

Methods: `0x004BBA90`, `0x004BBC60`, `0x004BBD60`, `0x004BC0E0`

- `this+0x00000000` `pointer penalty_state_ptr` (read, DERIVED)
- `this+0x00000004` `int driver_id` (read, DERIVED)
- `this+0x00000030` `int pending_flag` (read, DERIVED)
- `this+0x000000A4` `float fine_total` (read_write, DERIVED)

### ProgressBarEventWriter

Writes progress-bar stage events into the fixed-slot event ring buffer (write pointer dword_8AAE64, count dword_83EE60 capped at 1023, 432-byte stride, session time dbl_8AFEA0) and returns the current stage value.

Methods: `0x004BBF20`

- `this+0x00000004` `int driver_id` (read, GUESS)
- `this+0x00000044` `int stage` (read, GUESS)

### RacingLineModeController

Per-frame guard that resets the racing-line display mode outside qualifying sessions: reads the object pointer at this+0, checks its flag byte obj+0x344C, and resets this+0x60 from mode 2 to mode 1.

Methods: `0x004BC240`

- `this+0x00000000` `pointer vehicle_ptr` (read, GUESS)
- `this+0x00000060` `int racing_line_mode` (read_write, DERIVED)

### SnapshotFieldCopier

Small snapshot/field-copy helper on a __thiscall object: copies the dword state pair (this+0x24 <-> this+0x2C) and the float pair (this+0x68 -> this+0x28); used by multiplayer placement and netcomm slot-sync paths to preserve a current-state snapshot before an update.

Methods: `0x004BC320`, `0x004BC330`

- `this+0x00000024` `int state_prev` (read_write, DERIVED)
- `this+0x0000002C` `int state_current` (read_write, DERIVED)
- `this+0x00000028` `float float_prev` (write, DERIVED)
- `this+0x00000068` `float float_current` (read, DERIVED)

### LapSplitEventProcessor

Processes lap/split timing events. Routes the event-type flag (read from the vehicle penalty-state field obj+0x32C8 via FlagPropertyGetter) against the current lap/sector state at this+0xC, computes split-time deltas from this+0x60/0x64, optionally writes encoded event data, records a progress-bar event into the ring buffer and finalizes the lap/split via LapCompletion.

Methods: `0x004BC390`

- `this+0x00000000` `pointer parent_ptr` (read, GUESS)
- `this+0x00000004` `int driver_id` (read, GUESS)
- `this+0x00000008` `int event_param` (read, GUESS)
- `this+0x0000000C` `int lap_sector_state` (read, DERIVED)
- `this+0x00000060` `int split_mode` (read, DERIVED)
- `this+0x00000064` `float previous_split` (read, DERIVED)
- `this+0x000000B0` `float ride_height_threshold` (read, DERIVED)

### GridAlignmentValidator

Validates grid alignment and jump-start violations for a vehicle: dereferences this+0 to the vehicle float base, computes velocity/acceleration magnitude and orientation dot products, applies stop-go or disqualification jump-start penalties (gated by global dword_7CEF84 and the penalty-state flag obj+0x32C8), and renders 'not lined up' status messages.

Methods: `0x004BC9B0`

- `this+0x00000000` `pointer vehicle_ptr` (read, GUESS)
- `obj+0x000032C8` `int penalty_state_flag` (read, GUESS)
- `obj+0x000034F8` `float velocity_x` (read, GUESS)
- `obj+0x000034FC` `float velocity_y` (read, GUESS)
- `obj+0x00003500` `float velocity_z` (read, GUESS)
- `obj+0x000034C4` `float orientation_col_a` (read, GUESS)
- `obj+0x000034D0` `float orientation_col_b` (read, GUESS)
- `obj+0x000034DC` `float orientation_col_c` (read, GUESS)

### AIDriverRaceStateController

Per-frame AI driver race-state and penalty controller (owner AIDriverController, DERIVED per packet). Tracks the driver's wrapped track distance, enforces pit-lane speed limits (stop-go or monetary fine), detects corner cutting and wrong-way driving with accumulators and thresholds, manages cut-track/blue-flag timers, and drives pit-entry selection from nearby-vehicle proximity through the dword_5EB978 pit-selection state machine.

Methods: `0x004BCCC0`

- `this+0x00000000` `pointer vehicle_context_ptr` (read, DERIVED)
- `this+0x00000004` `int driver_id` (read, DERIVED)
- `this+0x00000008` `int lap` (read, DERIVED)
- `this+0x0000000C` `int rival_lap` (read, GUESS)
- `this+0x00000014` `float track_distance` (read_write, DERIVED)
- `this+0x0000002C` `int candidate_field` (read, GUESS)
- `this+0x00000060` `int cut_track_flag` (read_write, GUESS)
- `this+0x000000A8` `byte pit_lane_flag` (read_write, DERIVED)
- `this+0x000000AC` `float speed_penalty_acc` (read_write, DERIVED)
- `this+0x000000B0` `float wrong_way_acc` (read_write, DERIVED)
- `this+0x000000B4` `byte corner_cut_active` (read_write, DERIVED)
- `this+0x000000B8` `int corner_lap_snapshot` (read, GUESS)
- `this+0x000000BC` `int corner_segment_snapshot` (read, GUESS)
- `this+0x000000C0` `int corner_projection_snapshot` (read, GUESS)
- `this+0x000000C4` `float corner_gained_distance` (read, GUESS)
- `this+0x000000C8` `float corner_time_acc` (read_write, DERIVED)
- `this+0x000000CC` `float corner_severity` (read_write, DERIVED)
- `this+0x000000D0` `int cut_count` (read_write, DERIVED)
- `this+0x000000D4` `int blue_flag_flag` (read_write, DERIVED)
- `this+0x000000D8` `int pit_candidate_index` (read_write, DERIVED)
- `this+0x000000DC` `float blue_flag_timer` (read_write, DERIVED)

### Vehicle

Shared-layout proposal for the vehicle/object read through the penalty controllers and validators: carries the penalty-state flag at +0x32C8 (offset 13000, gates HUD penalty messages), a session/pit-lane flag at +0x344C, velocity/acceleration at +0x34F8..0x3500, orientation-matrix columns at +0x34C4/0x34D0/0x34DC, position at +0x34E0..0x34E8, and the vehicle data block pointer at +0x3AA8. Multiple owners read overlapping subsets, so this is a shared-layout grouping, not a confirmed single class.

Methods: 

- `obj+0x000032C8` `int penalty_state_flag` (read, GUESS)
- `obj+0x0000344C` `byte session_flag` (read, DERIVED)
- `obj+0x000034C4` `float orientation_col_a` (read, GUESS)
- `obj+0x000034D0` `float orientation_col_b` (read, GUESS)
- `obj+0x000034DC` `float orientation_col_c` (read, GUESS)
- `obj+0x000034E0` `float position_x` (read, GUESS)
- `obj+0x000034E4` `float position_y` (read, GUESS)
- `obj+0x000034E8` `float position_z` (read, GUESS)
- `obj+0x000034F8` `float velocity_x` (read, GUESS)
- `obj+0x000034FC` `float velocity_y` (read, GUESS)
- `obj+0x00003500` `float velocity_z` (read, GUESS)
- `obj+0x00003AA8` `pointer data_block_ptr` (read, DERIVED)

### VehicleDataBlock

Track geometry / segment data block reached through the vehicle's +0x3AA8 pointer. Holds the segment direction vector (+0x0/4/8), position-referenced fields (+0x20/24/28), track half-widths (+0x68/6C), boundary vectors (+0xA4/A8/AC), a direction-block pointer (+0x110) and a further field (+0x12C). Referenced only by the AI driver race-state controller.

Methods: 

- `*(obj+0x3AA8)+0x00000000` `float seg_dir_x` (read, GUESS)
- `*(obj+0x3AA8)+0x00000004` `float seg_dir_y` (read, GUESS)
- `*(obj+0x3AA8)+0x00000008` `float seg_dir_z` (read, GUESS)
- `*(obj+0x3AA8)+0x00000020` `float track_pos_a` (read, GUESS)
- `*(obj+0x3AA8)+0x00000024` `float track_pos_b` (read, GUESS)
- `*(obj+0x3AA8)+0x00000028` `float track_pos_c` (read, GUESS)
- `*(obj+0x3AA8)+0x00000068` `float half_width_a` (read, GUESS)
- `*(obj+0x3AA8)+0x0000006C` `float half_width_b` (read, GUESS)
- `*(obj+0x3AA8)+0x000000A4` `float boundary_a` (read, GUESS)
- `*(obj+0x3AA8)+0x000000A8` `float boundary_b` (read, GUESS)
- `*(obj+0x3AA8)+0x000000AC` `float boundary_c` (read, GUESS)
- `*(obj+0x3AA8)+0x00000110` `pointer direction_block_ptr` (read, DERIVED)
- `*(obj+0x3AA8)+0x0000012C` `float corner_snapshot` (read, GUESS)

### TrackDirectionBlock

Direction vector block reached through VehicleDataBlock +0x110. Its three floats at +0x0/4/8 are used to project the wrong-way displacement during the wrong-way check.

Methods: 

- `*(*(obj+0x3AA8)+0x110)+0x00000000` `float dir_x` (read, GUESS)
- `*(*(obj+0x3AA8)+0x110)+0x00000004` `float dir_y` (read, GUESS)
- `*(*(obj+0x3AA8)+0x110)+0x00000008` `float dir_z` (read, GUESS)

### IntBlockZeroer

Zeroes the first four dwords of a __thiscall object and returns this. Used at setup time by AI driver count, filter-data loading and generic struct-init paths; the owner class is unknown.

Methods: `0x004BF630`

- `this+0x00000000` `int dword_0` (write, DERIVED)
- `this+0x00000004` `int dword_1` (write, DERIVED)
- `this+0x00000008` `int dword_2` (write, DERIVED)
- `this+0x0000000C` `int dword_3` (write, DERIVED)

### StartingGridAssigner

Assigns starting grid positions and times for championship sessions (dword_7D0410 in 1..5). The qualifying path gathers and sorts per-driver qualifying results (via 0x4C0260/0x4C02D0) then writes grid/time into 18624-byte-stride vehicle records; the non-qualifying path places the player from dword_7D0110 or a random draw and fills the remaining vehicles sequentially.

Methods: `0x004BFF70`


## Compatibility contracts

- **ProgressBarEventRingBufferContract** — A fixed-slot event ring buffer is exposed through globals: write pointer dword_8AAE64, slot count dword_83EE60 capped at 1023, 432-byte stride per entry, session time from dbl_8AFEA0. Events are encoded via ProgressBarEventEncode (0x4B33B0) with type 4 and ids 23 (stop-go penalty), 24 (progress stage), 8 (lap split) and 28 (disqualification); the payload stores a float delta at +8, an event-type word at +12 and a parameter word at +14.
- **PenaltyStateFlagContract** — The penalty-state flag at obj+0x32C8 (byte offset 13000 of the penalty-state/vehicle object, read through the controller's this+0) gates every HUD penalty/warning message: a clear flag permits the message; a set flag (value 1 blocks jump-start re-penalty) suppresses it. The same flag selects the lap/split event type via FlagPropertyGetter bit 2048.
- **PenaltiesEnabledContract** — Global dword_7CEF84 is the master switch for applying race penalties: stop-go penalties, monetary fines, corner-cut and wrong-way penalties and blue-flag enforcement all check it before acting. A replacement must preserve this gate to reproduce penalty behavior.
- **SessionTypeContract** — Global dword_7C56A4 encodes the session type; value 7 (qualifying) disables racing-line reset and selects fixed stop-go penalties instead of fines, while dword_7C56A8 != 5 gates pit-selection logic. Threshold comparisons and branch meanings are DERIVED from branch structure, not named constants.
- **VehicleRecordStrideContract** — Vehicle records are laid out at 18624-byte stride (count from dword_5C329C; bases include unk_5EC6D0, unk_5F0CF8, unk_5F070C, unk_5F0734). Grid position is written at dword index 9, qualifying time as float at index 10, and the player grid at byte offset 16472 (with sentinel -1082130432 at 16476) on the vehicle at dword_7C54E8. These offsets are IDB-normalized reads from 0x4BFF70.
- **ChampionshipGridGateContract** — Grid assignment runs only when dword_7D0410 (championship mode) is in 1..5. The qualifying-session path runs when dword_7D0110 equals a second display/session field (spelled dword_7D011C in raw source, absent from the packet global list); otherwise the random/sequential placement path runs.
- **MultiLevelAllocationLayoutContract** — The multi-level allocator exposes: a 4-byte header whose single dword points to a 384-byte payload block split into 32 x 12-byte slots; 12-byte nodes holding (data pointer, next pointer, flag byte); a block list (head this+0, tail this+4, back this+8, count this+0xC) and a slot list (head this+0x10, tails this+0x14/0x18, count this+0x1C). Block nodes are marked in-use (flag 1), slot nodes free (flag 0).
- **MessageStringTableContract** — Localized message tokens are resolved through the string table at byte_5EC4C0 into the shared buffer byte_5EC4CC: aFinedUs (0x5D255C), aPenalty (0x5D2548), aWarning (0x5D2568), aStopGoPenalty (0x5D2574), aDisqualified (0x5D2588), aNotLinedUp (0x5D2598), aWrongWay (0x5D25B0), aLapWillNotCoun (0x5D25BC), plus driver names. Rendered through TextLineWrappingAndRendering on dword_7CD204; format strings '%s %s' and '%s%d %s' via StringFormatWithBufferOverflowCheck.

## Unresolved

- The owners of most functions are UNKNOWN at the function-IR level; the class grouping above is a DERIVED/GUESS proposal, not a confirmed identity.
- The 12-byte node flag-byte semantics (in-use vs free) and the two-list (block list + slot list) design of the multi-level allocator are not documented in the packet.
- 0x4BB460's this+0x4 is a secondary data pointer, distinct from MultiLevelAllocator's this+0x4 (block-list tail); per rule 8 the equal offset is not merged across owners.
- The role of the SinglyLinkedList second pointer at this+0x4 (head/cursor/tail ambiguity) is not fully determined; only the head this+0 and tail this+0x8 show clear behavior in 0x4BB6B0.
- Why 0x4BB6B0 frees the node's data directly while its structural twin 0x4BA830 performs an EmptyStub_0170() call is unresolved.
- The pending-message flag this+0x30 is only read by the penalty/warning handlers (0x4BBA90/0x4BBC60/0x4BBD60/0x4BC0E0); the writer that sets it (including the value 3 for 'disqualified') is elsewhere.
- Globals aSS_2 (0x5C5D30) and aSDS (0x5D2554) are packet-listed as referenced but appear nowhere in the raw decompiled bodies; their roles are not verifiable.
- The meaning of the byte_7D0B10 flag (which message flavor 'Fined US' vs 'Penalty' is emitted) is not documented inside the function.
- The obj+0x32C8 penalty-state flag versus driver-name-field binding is taken from the skeleton fill, not from the raw function code.
- The StopGoPenaltyHandler third-argument literal 10 and the render-call literals (3, 16909060) have no named meaning in the raw source.
- dbl_59EB48 is packet-listed for 0x4BC390 but the raw source compares the literal 10.0, so the ride-height-threshold binding is not verifiable.
- The default (unlisted) switch case of the 0x4BC390 event-type selector falls through to sub_4BC340 with no state check; the meaning of a2 values outside 0..2 is unstated.
- The 0x4BC9B0 threshold literals (1.0, 5.0625, 1.5, 0.75, 3.0625, 1.25, 0.85, 225.0, 400.0) have no named constants in the raw source; the flt_ constants packet-listed for it are not visible in the raw body.
- In 0x4BCCC0 the packet-listed callees FloatRangeIndexLookup (0x4D7C10) and AISessionModeTransition (0x4193A0) are not visible in the raw body and cannot be placed; the many flt_/dbl_ float constants and dword_8AD264 are likely folded into FPU immediates by Hex-Rays.
- In 0x4BCCC0 the field base expressions (obj / *(obj+0x3AA8) / *(*(obj+0x3AA8)+0x110)) are IDB-normalized; their correspondence to the raw pointer arithmetic (v3/v5/v34) is approximate. The obj+0x344C read is treated as the pit-lane/session flag at context+13388, conflicting with an existing-analysis label ('segment normal'); the raw reading was favored.
- The obj+0x34F8/0x34FC/0x3500 field refs in 0x4BCCC0 have no clear anchor in the decompiled source and are left unresolved, though the same offsets are used as velocity/acceleration in 0x4BC9B0.
- The 0x4BCCC0 this+0x60 guard (guard:1, != 2) is tied to cut-track / pit-proximity flag semantics only approximately.
- At the ring-buffer cap (dword_83EE60 >= 1023) the write pointer is reused instead of advancing; the semantics of the 1023 cap are unresolved.
- The purpose and side effects of sub_4BF730 (called first by 0x4BF640, its return passed through) are unknown.
- In 0x4BFF70 the qualifying/random branch compares dword_7D0110 against a second display/session field spelled dword_7D011C in the raw source, which is absent from the packet global list.
- The exact VEH field semantics behind the unk_5F070C and unk_5F0734 writes (grid position vs qualifying time) follow the existing analysis and are not independently confirmed.
- The event ids/type-4 constants and the 432-byte ring-buffer stride have no in-packet documentation.
- Semantics of the a3 flag in 0x4BC9B0 (emit 'not lined up' status message) are inferred, not proven; exact UI/status semantics unknown.
- The vehicle float magnitude-squared reading of obj+0x34F8/0x34FC/0x3500 in 0x4BC9B0 is labeled velocity/acceleration by the fill; the transform is not proven.
