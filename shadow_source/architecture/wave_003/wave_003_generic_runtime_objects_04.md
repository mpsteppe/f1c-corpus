# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Proposal for the generic_runtime_objects slice of Wave 3. The twenty functions cluster into: (1) a CommentaryOverlayDisplay object (0x4184B0 init, 0x4186F0 per-tick display timer, 0x4189F0 slot-table search-and-reset, 0x418A20 boolean-OR predicate) that owns a 20-entry 8-DWORD slot table at this+0x864, a pending/last-timestamp/active-id display state block at this+0xAE4..0xAEC, an init flag and overlay object at this+0xAF0/0xAF4, and renders through the overlay object's vtable slots +4/+8/+0x18; (2) a DriverTableEntryManager (0x418B70 indexed lookup, 0x418B90 mode-dependent score threshold gate) over the global 5-dword-stride driver table dword_5BF9A0, both serving InsertDriverTableEntry 0x418560; (3) an AIHUDDisplayData reset path (0x418E50) that reinitializes 104 per-driver display entries and hands off to AITargetDriverSelection; and (4) a RaceCommentaryEventEmitter family (0x419C50, 0x41A4A0, 0x41A6B0, 0x41A720, 0x41A940, 0x41AC50, 0x41AFD0, 0x41B190, 0x41B200, 0x41B970, 0x41B980, 0x41C090) that shares one tail: StructInitWithSentinelValues into an 8-field entry, DriverDataTableLookupAndTimeConversion with the chosen event/message code, and InsertDriverTableEntry into flt_5EA618. One function, 0x41AD80 (OvertakingEventTracker), is DERIVED as a member of the CollisionDetectionSystem based on its single caller 0x4EA970, though it emits through the same event table. Field evidence on the vehicle-read offsets +0x39FC/+0x4060/+0x4064/+0x4070/+0x4894/+0x489C is packet-listed with base 'this' but the raw reads are on the a1 vehicle pointer; that base equivalence is inferred, not proven.

## Function roles

- `0x004184B0` **CommentaryOverlayDisplay** — Owner/initializer of the overlay display object: ShortArrayInit zeroes the leading short array, a do-while loop fills sub-structs from this+0x864 with sentinel defaults advancing 32 bytes per iteration, fields this+0xAF0 and this+0xAF4 are zeroed, EmptyStub_0170 runs, and BufferInitWith10fDefaults fills the trailing buffer region; returns this.
- `0x004186F0` **CommentaryOverlayDisplay** — Per-tick text-overlay display timer: guarded by race-active dword_7D0308, track condition flt_7CF3C8 and the init flag at this+0xAF0, it steps the overlay object at this+0xAF4 via its vtable slot +0x18, manages the pending flag/last-display timestamp/active-id block (this+0xAE4/0xAE8/0xAEC), compacts the slot array, renders the active slot through the overlay object's vtable slot +4 once its per-slot threshold has elapsed, then resets the active slot and compacts again.
- `0x004189F0` **CommentaryOverlayDisplay** — Linear scan of the 20-entry slot table at this+0x864 (8-DWORD stride, first DWORD per entry is an ID); every entry whose ID equals a2 is reset via StructInitWithSentinelValues; returns 1 if any entry matched else 0.
- `0x00418A20` **CommentaryOverlayDisplay** — Boolean OR of two member checks on the same object: evaluates ArraySearchReturningIndex (0x4189F0) first and short-circuits on a nonzero byte result, otherwise evaluates StateCheckedVirtualDispatch (0x4189B0); used by the penalty path with the shared event table object as the receiver.
- `0x00418B70` **DriverTableEntryManager** — Indexed lookup into the global driver data table: returns dword_5BF9A0[5 * a1] when a1 is not the -1 sentinel, otherwise returns a1 unchanged; helper for InsertDriverTableEntry.
- `0x00418B90` **DriverTableEntryManager** — Mode-dependent score threshold gate: dispatches on global dword_7D0308 through jump table jpt_418B9D (0x418BFC) into mode 0 (==0x7FFFFFFF), mode 1 (>=70), mode 2 (>=40), mode 3 (>0) over dword_5BF9A0[5*a1]; any other mode keeps the default result 1.
- `0x00418E50` **AIHUDDisplayData** — Resets per-driver AI HUD display data for all 104 driver slots: writes the -1 driver-ID sentinel, a 0x7FFFFFFF maximum sentinel, zeroed base/timer/flag fields and a -1.0f float sentinel per entry, then calls AITargetDriverSelection for the initial AI target and zeroes three global tracking counters. Gated on race-active dword_7D0308 and non-zero flt_7CF3C8.
- `0x00419C50` **RaceCommentaryEventEmitter** — Per-driver race-finish commentary generator: guarded by race-active/track-condition state, maps the current track name (compared against 17 track-name strings) to a track-specific commentary ID for the player (default 167, else 158), emits generic 261/260 IDs for AI positions 1 and 2-5, and in championship mode 4 emits a close-race/leader-gap commentary ID 159 when the standings head's time exceeds best-lap plus ten times the position gap.
- `0x0041A4A0` **RaceCommentaryEventEmitter** — Display-message helper that emits fixed session event message ID 284: fills a local record via DriverDataTableLookupAndTimeConversion and inserts it into the session event table at flt_5EA618; gated on dword_7D0308 and flt_7CF3C8.
- `0x0041A6B0` **RaceCommentaryEventEmitter** — Display-message helper that emits fixed race message ID 275: guarded like its siblings, it additionally invokes the vtable slot +12 method on the sound/system pointer dword_5EB10C and resets the shared buffer flt_5EA618 to 10.0f defaults before the lookup-and-insert tail.
- `0x0041A720` **RaceCommentaryEventEmitter** — Penalty/incident event handler: compares the driver ID at vehicle+0x4894 against the player vehicle at dword_7C54E8+0x4894; the player path maps penalty name strings (aSpeedingInPitl/aCutTrack/aJumpedStart/aIgnoredBlueFla) to event codes 153/151/155/154 and fires BooleanOROfTwoChecks for flags 123/124/125, while the AI path maps the same names to 256/253/254/252 (suppressed when race phase dword_7C56A8 == 8); both paths build an 8-field entry and insert it into flt_5EA618.
- `0x0041A940` **RaceCommentaryEventEmitter** — Ignored-stop-go-penalty commentary emitter: when the player vehicle (dword_7C54E8) equals the a1 vehicle and a2 matches aIgnoredStopGoP sets event code 149, else (AI path, race phase != 8) sets code 243; both paths run the shared sentinel-init, lookup-and-time-conversion, insert-into-flt_5EA618 tail.
- `0x0041AC50` **RaceCommentaryEventEmitter** — Gear-based event dispatch for AI vehicles during championship weekend (session type dword_7C56A4 == 7, race phase != 8): event type a2 selects the code, 0 -> 208 (generic), 2 -> gear-specific 211-217 from the current gear at this+0x39FC via jump table jpt_41ACE9 (0x41AD60), 3 -> 220 (retirement); builds and appends the entry for vehicles that are neither the player vehicle nor finished.
- `0x0041AD80` **CollisionDetectionSystem** — Per-frame overtaking/passing event tracker invoked from the collision detection system: accepts an overtake when session time dbl_8AFEA0 is more than 2.0 seconds past the last recorded event for both drivers and the passed distance exceeds 1250.0; records time/distance/opponent per driver, emits event 114/115 when the player driver is involved, else 225/226 gated on a weather-noise table lookup, and appends the record to flt_5EA618.
- `0x0041AFD0` **RaceCommentaryEventEmitter** — Repair/service event commentary emitter: when the driver id at dword_7C54E8+0x4894 equals a1+0x4894 maps part index a2 (0-5) onto player event codes 106/107/109/110/108/111 via jump table jpt_41B028 (0x41B154); otherwise (race phase dword_7C56A8 != 8) maps onto AI codes 221/222/223 via jpt_41B0D4 (0x41B16C); both paths insert a sentinel-initialized entry into flt_5EA618.
- `0x0041B190` **RaceCommentaryEventEmitter** — Teammate audio event emitter: when the team/constructor field at player vehicle dword_7C54E8+0x4894 matches the AI entrant a1+0x4894, emits message ID 77 through the lookup-and-insert tail into flt_5EA618; called by sub_49B9A0.
- `0x0041B200` **RaceCommentaryEventEmitter** — Display-message helper that emits fixed session event message ID 74 through the shared driver-data table; guarded by dword_7D0308 and flt_7CF3C8, uses the standard lookup-and-insert tail.
- `0x0041B970` **RaceCommentaryEventEmitter** — Parameterless wrapper that declares a local 8-dword stack buffer, forwards it to StructInitWithSentinelValues and returns that call's result unchanged; no event-table interaction.
- `0x0041B980` **RaceCommentaryEventEmitter** — Team-name display-ID lookup: matches the team-name string at a1+252 against 44 season 1999-2002 team name constants via sub_566810, selecting display IDs 293-336, then runs the standard lookup-and-insert tail into the UI driver table at flt_5EA618; part of the UI team display system, called from UIRenderUpdateChain.
- `0x0041C090` **RaceCommentaryEventEmitter** — Display-message helper emitting fixed message code 514 through the shared driver-data table; guarded by dword_7D0308 and flt_7CF3C8, standard lookup-and-insert tail; sole static caller sub_40DE60.

## Proposed classes

### CommentaryOverlayDisplay

Text-overlay/commentary display controller. Owns a 20-entry 8-DWORD slot table at this+0x864 (each entry's first DWORD is an ID), a display-state block (pending flag, last-display timestamp, active overlay id) at this+0xAE4..0xAEC, an init flag at this+0xAF0 and an overlay object pointer at this+0xAF4 whose vtable exposes a per-tick update slot (+0x18), a render slot (+4) and a ready/busy query slot (+8). Initializes the object and buffer regions, drives the timed display per tick, and resets slots by ID. A boolean-OR predicate over the slot search and a state-check virtual dispatch is grouped here with low confidence because 0x418A20 is invoked with the shared event-table object as its receiver.

Methods: `0x004184B0`, `0x004186F0`, `0x004189F0`, `0x00418A20`

- `this+0x00000864` `array slot_table` (read_write, GUESS)
- `this+0x0000086C` `double slot_threshold` (read, GUESS)
- `this+0x00000AE4` `int pending_flag` (read_write, GUESS)
- `this+0x00000AE8` `double last_display_timestamp` (read_write, GUESS)
- `this+0x00000AEC` `int active_overlay_id` (read_write, GUESS)
- `this+0x00000AF0` `byte init_flag` (read_write, GUESS)
- `this+0x00000AF4` `pointer overlay_object` (read_write, GUESS)
- `this+0x0000135C` `int cooldown_counter` (read_write, GUESS)
- `*(this+0xAF4)+0x00000000` `pointer overlay_vtable` (read, GUESS)
- `*(*(this+0xAF4)+0x0)+0x00000004` `pointer render_slot` (read, GUESS)
- `*(*(this+0xAF4)+0x0)+0x00000008` `pointer ready_query_slot` (read, GUESS)
- `*(*(this+0xAF4)+0x0)+0x00000018` `pointer update_slot` (read, GUESS)

### DriverTableEntryManager

Access and gating logic over the global per-driver driver data table dword_5BF9A0 (5-DWORD stride per driver, with -1 and 0x7FFFFFFF sentinels). Provides indexed element lookup (helper for InsertDriverTableEntry) and a mode-dependent score threshold predicate whose comparison semantics are selected by global dword_7D0308 (modes 0..3).

Methods: `0x00418B70`, `0x00418B90`


### AIHUDDisplayData

Per-driver AI HUD display data container. Holds 104 per-driver display entries beginning at this+0x350 plus per-driver sentinel/counter/flag fields (this+0x4FC, 0x69C, 0x83C) and three global tracking counters (this+0x4F0/0x4F4/0x4F8); a reset path reinitializes every entry and hands the initial AI target selection to AITargetDriverSelection.

Methods: `0x00418E50`

- `this+0x00000350` `array display_entries` (read_write, GUESS)
- `this+0x000004F0` `int tracking_counter_a` (read_write, GUESS)
- `this+0x000004F4` `int tracking_counter_b` (read_write, GUESS)
- `this+0x000004F8` `int tracking_counter_c` (read_write, GUESS)
- `this+0x000004FC` `float per_driver_float_sentinel` (write, GUESS)
- `this+0x0000069C` `int per_driver_counter` (write, GUESS)
- `this+0x0000083C` `byte per_driver_flag` (write, GUESS)

### RaceCommentaryEventEmitter

Family of race-commentary / session-event emitters that share one tail: initialize an 8-field event entry with StructInitWithSentinelValues (0x4144D0), populate it via DriverDataTableLookupAndTimeConversion (0x4144F0) with a literal event/message code and sentinel arguments (-1, -1, -1, -1, -2.0, -2.0), and append it to the shared session event table flt_5EA618 via InsertDriverTableEntry (0x418560). Includes finish commentary (per-driver race-finish, close-race gap), penalty/stop-go incident reporting, gear/retirement events, repair/service events, teammate audio, and fixed display messages (74, 77, 275, 284, 514) plus a team-name display-ID lookup. Vehicle read-only context (gear, finishing position, finish state, penalty count, driver id, related-driver id) is read off the a1 vehicle pointer and packet-listed with base 'this'.

Methods: `0x00419C50`, `0x0041A4A0`, `0x0041A6B0`, `0x0041A720`, `0x0041A940`, `0x0041AC50`, `0x0041AFD0`, `0x0041B190`, `0x0041B200`, `0x0041B970`, `0x0041B980`, `0x0041C090`

- `this+0x000039FC` `int current_gear` (read, GUESS)
- `this+0x00004060` `int finishing_position` (read, GUESS)
- `this+0x00004064` `int finish_state` (read, GUESS)
- `this+0x00004070` `int penalty_count` (read, GUESS)
- `this+0x00004894` `int driver_id` (read, GUESS)
- `this+0x0000489C` `int related_driver_id` (read, GUESS)

### CollisionDetectionSystem

Collision detection system entry point for a per-frame overtaking/passing tracker. 0x41AD80 is DERIVED as a member on the strength of its single caller 0x4EA970; it accepts passing events (session-time cooldown of 2.0 seconds, distance threshold 1250.0), records per-driver event state, and emits player-involved (114/115) or AI (225/226, weather-noise gated) overtake events through the shared session event table.

Methods: `0x0041AD80`


## Compatibility contracts

- **RaceActivityGateContract** — Every commentary/overlay emitter is gated by two globals: dword_7D0308 must be nonzero (race-active/session-active) and flt_7CF3C8 must be nonzero (track-condition state, compared against the ~0.0f constant flt_59E440 in several bodies). A replacement must preserve this gate so events are only emitted during an active session.
- **DriverEventTableContract** — Session event/commentary entries are 8-field structs initialized with sentinel values by StructInitWithSentinelValues (0x4144D0), populated by DriverDataTableLookupAndTimeConversion (0x4144F0) with a literal event/message code, a driver/related-driver index where relevant, and the fixed sentinel arguments (-1, -1, -1, -1, -2.0, -2.0), then appended to the shared table at flt_5EA618 via InsertDriverTableEntry (0x418560).
- **PlayerVehicleIdContract** — The player vehicle is the pointer in global dword_7C54E8. Commentary emitters distinguish player vs AI paths by comparing the driver/team identifier at +0x4894 of the entrant vehicle against the same offset of the player vehicle, and pass +0x489C as the related-driver/context index to the event lookup. The base equivalence between the packet's 'this' and the a1 vehicle pointer is inferred.
- **RacePhaseGateContract** — The race phase dword_7C56A8 == 8 suppresses AI-side commentary emission (penalty, stop-go, repair, overtake paths), and the session type dword_7C56A4 == 7 (championship weekend) gates the gear-specific event dispatch. A replacement should honor these values when deciding whether to emit AI commentary.
- **DriverDataTableStrideContract** — Global dword_5BF9A0 is a per-driver data table with a 5-DWORD record stride (indexed as dword_5BF9A0[5 * driver]) and uses -1 (absent index) and 0x7FFFFFFF (maximum sentinel) as sentinels; a sibling table dword_5BF9AC is indexed at a 5-element stride as flt_5BF9AC[5 * slot].
- **ScoreThresholdModeContract** — Global dword_7D0308 also selects score-threshold semantics in the driver-table gate: 0 tests dword_5BF9A0[5*a1] == 0x7FFFFFFF, 1 tests >= 70, 2 tests >= 40, 3 tests > 0; any other value passes by default.
- **OverlayVtableContract** — The overlay object at this+0xAF4 exposes three vtable slots relied on by the display loop: +0x18 (per-tick update), +4 (render a prepared text array with a count and a 0 argument), and +8 (ready query where a zero return means ready).
- **CommentaryMessageCodeContract** — Event and message codes are fixed literals: player event codes 106-111 (repair parts), 149/243 (ignored stop-go), 151/153/154/155 vs 252-256 (penalties), 158/167 and track-specific 160-177 and gap 159 (finish commentary), 208/211-217/220 (gear/retirement), 221-223 (AI repair), 114/115 vs 225/226 (overtakes), 261/260 (generic podium), 74/77/275/284/514 (fixed messages), and 293-336 (team display ids). Their in-game meaning is DERIVED from the code literals, not independently proven.

## Unresolved

- flt_59E440 is packet-listed as a read global but never appears in the raw decompiled source of most functions; it is likely a zero-comparison float constant folded into the '!= 0.0' guards (only 0x41A720 shows it as a guard operand). Its role is unresolved.
- flt_59E800 and flt_59E820 are packet-listed globals for 0x41AD80 with no appearance in the raw source; no operation could be grounded on them.
- The loop termination in 0x4184B0 reads decompiler variables whose initialization is not visible in the packet; the sub-struct iteration count and sentinel semantics are unclear.
- The owners of most functions are UNKNOWN at the function-IR level; class grouping (CommentaryOverlayDisplay, DriverTableEntryManager, AIHUDDisplayData, RaceCommentaryEventEmitter) is a DERIVED/GUESS proposal. The RaceCommentaryEventEmitter members may in fact be free functions in one commentary module rather than methods of a single class.
- Field evidence on offsets +0x39FC, +0x4060, +0x4064, +0x4070, +0x4894, +0x489C is packet-listed with base 'this' while the raw reads are on the a1 vehicle pointer; the base equivalence is inferred from identical offsets, not proven.
- flt_5EA618 is float-named in the raw source but is used as the object/table argument to BooleanOROfTwoChecks, DriverDataTableLookupAndTimeConversion and InsertDriverTableEntry; its true type and layout are unresolved.
- 0x418A20 (grouped in CommentaryOverlayDisplay) is invoked by penalty paths with flt_5EA618 as its receiver; whether the slot-search object and the event-table object share a class is unproven.
- The vfunc+8 ready semantics (0 = ready) and the vfunc+4 render signature are inferred from call shape only.
- Event/message code semantics (114/115 vs 225/226, which +18588 driver id is overtaker vs overtaken, and the meaning of 208/211-217/220 and 74/77/275/284/514) are inferred from literals and branch structure, not confirmed by a label.
- Jump tables jpt_418B9D (0x418BFC), jpt_41ACE9 (0x41AD60), jpt_41B028 (0x41B154) and jpt_41B0D4 (0x41B16C) implement the mode/gear/part dispatches, but their layouts are not evidenced by the packet.
- sub_566810 is used as a string comparison (track/team names) with an inferred 0-on-match contract; its exact signature is not confirmed.
- The byte flag array at this+2524 (zeroed per loop iteration in 0x418E50) has no packet field reference; it is described in prose only and not represented as a class field.
- The dword_7D0410 global is described as both ChampionshipMode and RaceMode; the exact semantics of the range checks (2..5, ==4) are not fully resolved.
- Standings-node offsets +408 (dword best time) and +432 (byte finished flag) used by 0x419C50 are DERIVED from decompiler output, not independently confirmed.
- 0x41B980 is part of the UI team display system (caller 0x476D70) but shares the emitter tail; whether it is genuinely a commentary emitter or a UI path over the same table is unresolved.
- 0x41B970 is a parameterless wrapper that initializes a discarded local buffer; its purpose and integer return interpretation are unknown.
- The exact meaning of the race phase dword_7C56A8 == 8 and session type dword_7C56A4 == 7 values is caller-context dependent and not defined by this packet.
- Callers 0x42D7A0 (Game_Restart) for 0x418E50 and 0x4A0BA0 (RaceFinishHandler) for 0x419C50 are known only from call-graph evidence; their invocation context is not examined here.
