# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Proposal for the generic_runtime_objects slice of Wave 2. The functions cluster into: a session director object (0x40D980 init, 0x40DA30 reset, 0x40DE60 event-queue processing) with a nested session/action-dispatch object (0x40D1B0) and a shared phase decoder (0x40CD60); a session-mode setup dispatcher (0x404B60, 0x404970) keyed on global dword_7C569C (2=race, 5=server); linked-string list infrastructure (StringList 0x404E60 and the directory-backed ResourceList 0x404D50); resource identity lookup (0x405050, 0x40BCD0) and a hybrid file-path search list (0x40A680); the audio subsystem (MilesSoundSystem 0x405D70, AudioSystem teardown 0x406E50, AudioResource release 0x405B00, stream volume control 0x406659); and a session loading context (0x411120). View camera reset (0x4064C0), a reciprocal helper (0x408420), a physics struct initializer (0x40EC70), a state/flag guard (0x404F10), and an audio commentary channel query (0x4116C0) round out the set. Ownership is largely UNKNOWN at the function-IR level, so most classes here are GUESS or DERIVED proposals, not confirmed identities.

## Function roles

- `0x00404970` **SessionSetupDispatcher** — Conditional one-shot audio mixer/render setup step: gated on this+0x20 == 1 and on a positive render-fade alpha, runs short arithmetic, sets an index, and initializes the audio mixer device from the scene-name buffer with a fixed 3.0 parameter.
- `0x00404B60` **SessionSetupDispatcher** — Session-mode setup dispatch: main-menu/bitmap reset path, race-mode state-snapshot progress accumulation that triggers RaceModeSetup at a threshold, and server-mode sound plus one-shot audio render dispatch.
- `0x00404D50` **ResourceList** — Directory-backed resource list maintenance: free every node of the linked list at target+0x40 (with nested-buffer cleanup), zero the list control block, then rebuild it by enumerating directory entries through the shared string-list append helper.
- `0x00404E60` **StringList** — Shared string-list append: allocates an owned string buffer and a 12-byte node (data, next, owned-flag), then links it as tail or as head/aux/tail of the control block at (*this)+0x40 and increments the count.
- `0x00404F10` **UIStateFlagGuard** — Shared state/flag guard used by menu and HUD frame paths: evaluates a packed byte field through ByteFieldExtractorWithShift and range-checks (1..2) a dword read through the register-passed object.
- `0x00405050` **ResourceManager** — Resource identity resolution: maps a string to a numeric resource ID via direct name lookup, then a prefix-parsed numeric lookup, then a formatted fallback, writing the result to *a2 and returning success/failure.
- `0x00405B00` **AudioResource** — Audio resource release: invokes the vtable destructor, decrements a shared resource block reference count, frees the block at zero, clears the pointer, and removes the node from a linked-list key lookup.
- `0x00405D70` **MilesSoundSystem** — Open a Miles audio filter by index 0-3: resolve the filter name, enumerate Miles filters until the name matches, then open the matched filter through the config's provider handle and store index/handle/parameter.
- `0x004064C0` **ViewCameraController** — Camera view reset: optionally closes the audio-stream handle, resets three slot entries to default (-1 identifier / 0 flag / default path string), and re-acquires a mutex.
- `0x00406659` **MilesStreamVolumeControl** — Miles audio stream volume control: dispatches through a vtable object; on a non-zero slot+8 result applies AIL_set_stream_volume_levels to the stream, or delegates to a vtable slot+12 method when the volume is zero.
- `0x00406E50` **AudioSystem** — Audio subsystem teardown: walks four linked lists invoking virtual cleanup/release slots and freeing nodes, performs a virtual vtable+0x34 call, closes the wave output handle via AIL_waveOutClose, calls AIL_shutdown, and clears the active flag.
- `0x00408420` **ReciprocalOut** — Reciprocal helper: always writes 1.0f to this+4 and writes either 1.0f/a2 or 1.0f to this+8 depending on the sign of a2.
- `0x0040A680` **FilePathSearchList** — Hybrid file-path list search: checks eight fixed entry slots then walks a variable-length array (base this+0x20, 200-byte stride, count this+0x38), comparing each entry's path string and returning the matching entry pointer.
- `0x0040BCD0` **ResourceManager** — Guarded resource lookup with optional vtable dispatch: aborts on null key or negative first-stage result, runs a second-stage computation, and when a3 is set fires the object's vtable slot at +0x10.
- `0x0040CD60` **SessionPhaseDecoder** — Session phase decoder: when the current session pointer equals the expected pointer, maps the session phase dword (0-4) identity into this+0xC; on mismatch stores fallback 5; returns this+0xC.
- `0x0040D1B0` **SessionActionDispatcher** — Session action dispatch through a three-stage cascade (menu-slot, callback, resource lookups), records the matched object, sets the dispatch flag, decodes the session phase, transitions the game-action state machine, and optionally fires the matched object's vtable slot at +16.
- `0x0040D980` **SessionDirector** — Global data structure initializer: initializes sub-structs at this+0x14 and this+0x4C, stores four global pointers, clears counters/indices and the head flag, sets the 0xA0 threshold and 0x94 sentinel, and returns this.
- `0x0040DA30` **SessionDirector** — Camera director reset/init: clears flags and counters, dispatches any pending session phase, publishes the active vehicle pointer for the stored index, clears the pointer array, and ensures the sub-struct at this+0x88 exists.
- `0x0040DE60` **SessionDirector** — Session event-queue processor running in phase 4: advances timer accumulators, iterates up to 10 queue entries, and dispatches each on action type (2 probabilistic defer/advance, 3 per-sub-type execute, 4 settle/requeue/delegate), returning the session phase.
- `0x0040EC70` **CollisionStructInitializer** — Physics/collision struct initializer: stores a caller value, constant 5, and a caller int; sets collision inverse-mass data and six float fields; optionally runs a follow-up short computation gated on a4.
- `0x00411120` **SessionLoadingContext** — Session/loading cleanup: iterates six batches of 36-byte objects, dispatching each to mode-dependent render/physics handling and skipping batch 4-6 entries whose vehicle state is still live; returns the batch-6 count.
- `0x004116C0` **AudioCommentaryController** — Audio commentary channel query: fills four out-parameters through AudioCommentaryChannelConfiguration and, on success, dispatches two vtable calls (slot 72) on the global commentary object.

## Proposed classes

### SessionSetupDispatcher

Session-mode setup dispatcher. Detects main-menu/bitmap, race (dword_7C569C == 2), and server (== 5) modes; accumulates clamped race progress against a threshold and triggers RaceModeSetup; plays a session-start sound and dispatches audio mixer setup exactly once.

Methods: `0x00404B60`, `0x00404970`

- `obj+0x00000000` `int state_dword_0` (read_write, GUESS)
- `obj+0x00000004` `int state_dword_1` (read_write, GUESS)
- `obj+0x00000008` `int state_dword_2` (read_write, GUESS)
- `obj+0x0000000C` `int state_dword_3` (read_write, GUESS)
- `obj+0x00000010` `int state_dword_4` (read_write, GUESS)
- `obj+0x00000014` `byte sound_gate` (read, GUESS)
- `obj+0x00000015` `byte audio_dispatched` (read_write, GUESS)
- `obj+0x00000018` `float race_threshold` (read, GUESS)
- `obj+0x0000001C` `float progress` (read_write, GUESS)
- `obj+0x00000020` `int mode_param` (read, GUESS)

### ResourceList

Directory-backed resource list. Holds a rebuild flag and a linked list of owned strings at +0x40..0x4C; frees and rebuilds the list from directory entries, delegating node insertion to StringList.

Methods: `0x00404D50`

- `obj+0x00000024` `byte rebuild_flag` (read_write, GUESS)
- `obj+0x00000040` `pointer list_head` (read_write, GUESS)
- `obj+0x00000044` `pointer list_tail` (write, GUESS)
- `obj+0x00000048` `pointer list_aux` (write, GUESS)
- `obj+0x0000004C` `int list_count` (write, GUESS)

### StringList

Singly-linked list of owned strings. Control block has four dwords at +0x40..0x4C (head, tail, aux, count); nodes are 12 bytes holding a data pointer, a next pointer and an owned-flag byte.

Methods: `0x00404E60`

- `obj+0x00000040` `pointer head` (read_write, DERIVED)
- `obj+0x00000044` `pointer tail` (write, DERIVED)
- `obj+0x00000048` `pointer aux` (write, GUESS)
- `obj+0x0000004C` `int count` (write, DERIVED)
- `*(obj+0x40)+0x00000000` `pointer data` (write, DERIVED)
- `*(*(obj+0x40)+0x4)+0x00000004` `pointer next` (write, DERIVED)
- `*(obj+0x40)+0x00000008` `byte owned_flag` (read, DERIVED)

### UIStateFlagGuard

Shared boolean state/flag guard used by menu and HUD frame paths. Reads a packed byte field via ByteFieldExtractorWithShift and range-checks a dword (1..2) read through the register-passed object; the object base is not independently verifiable.

Methods: `0x00404F10`


### ResourceManager

Resource identity resolution and guarded lookup. Maps strings to numeric resource IDs through name lookup, prefix-parsed numeric lookup, or formatted fallback; also exposes a two-stage guarded lookup with optional vtable callback dispatch.

Methods: `0x00405050`, `0x0040BCD0`

- `this+0x00000000` `pointer vtable` (read, GUESS)

### MilesSoundSystem

Audio subsystem binding to the Miles Sound System (AIL). Opens and enumerates audio filters by index through the imported AIL filter surface and stores per-filter state (index, handle, provider parameter).

Methods: `0x00405D70`

- `this+0x00000054` `pointer config` (read, DERIVED)
- `this+0x000000E4` `pointer provider_handle` (read, DERIVED)
- `this+0x00000060` `int filter_index` (write, DERIVED)
- `this+0x00000064` `pointer filter_handle` (write, DERIVED)
- `this+0x00000068` `int provider_param` (write, DERIVED)

### ViewCameraController

Camera view slot manager. Owns an optional audio-stream handle and three per-slot entries (identifier, flag, default path string); resets them to default and re-acquires a mutex.

Methods: `0x004064C0`

- `this+0x0000000C` `pointer audio_stream_handle` (read, GUESS)
- `this+0x0000001C` `int slot_0_identifier` (write, GUESS)
- `this+0x00000020` `byte slot_0_flag` (write, GUESS)

### MilesStreamVolumeControl

Vtable-dispatched stream volume controller in the audio subsystem. Applies per-channel volume levels through AIL_set_stream_volume_levels or delegates to a stream-control vtable slot when the volume is zero. The ecx-passed object layout is partly a decompiler artifact.

Methods: `0x00406659`

- `this+0x00000000` `pointer vtable` (read, GUESS)

### AudioSystem

Manager for the audio subsystem lifecycle. Owns four linked lists of audio components/resources, a wave-output handle and an active flag; performs ordered teardown through virtual slots and the imported Miles shutdown surface.

Methods: `0x00406E50`

- `this+0x00000000` `pointer vtable` (read, GUESS)
- `this+0x00000008` `pointer component_list_head` (read_write, GUESS)
- `this+0x00000010` `pointer component_iterator` (write, GUESS)
- `this+0x00000018` `pointer list_a_head` (read_write, GUESS)
- `this+0x0000001C` `pointer list_a_next` (write, GUESS)
- `this+0x00000020` `int list_a_field3` (write, GUESS)
- `this+0x00000024` `int list_a_field4` (write, GUESS)
- `this+0x00000028` `pointer list_b_head` (read_write, GUESS)
- `this+0x0000002C` `pointer list_b_next` (write, GUESS)
- `this+0x00000030` `int list_b_field3` (write, GUESS)
- `this+0x00000034` `int list_b_field4` (write, GUESS)
- `this+0x00000038` `pointer list_c_head` (read_write, GUESS)
- `this+0x0000003C` `pointer list_c_next` (write, GUESS)
- `this+0x00000040` `int list_c_field3` (write, GUESS)
- `this+0x00000044` `int list_c_field4` (write, GUESS)
- `this+0x00000088` `byte active_flag` (read_write, GUESS)
- `this+0x00000090` `pointer wave_out_handle` (read_write, GUESS)

### AudioResource

Ref-counted audio resource node registered in a keyed linked list. Holds a shared resource block; on release it decrements the block reference count, frees the block at zero, clears the pointer and removes itself from the key lookup.

Methods: `0x00405B00`

- `this+0x00000000` `pointer vtable` (read, GUESS)
- `this+0x0000005C` `pointer resource_block` (read_write, GUESS)
- `this+0x00000060` `int ref_count` (read_write, GUESS)

### FilePathSearchList

Hybrid file-path list. Holds eight fixed entry slots (index 4 is skipped during search) plus a variable-length array of 200-byte path entries; searched by string comparison of each entry's path.

Methods: `0x0040A680`

- `this+0x00000010` `pointer fixed_entry_0` (read, GUESS)
- `this+0x00000014` `pointer fixed_entry_1` (read, GUESS)
- `this+0x00000018` `pointer fixed_entry_2` (read, GUESS)
- `this+0x0000001C` `pointer fixed_entry_3` (read, GUESS)
- `this+0x00000020` `pointer variable_entries` (read, GUESS)
- `this+0x00000024` `pointer fixed_entry_4` (read, GUESS)
- `this+0x00000028` `pointer fixed_entry_5` (read, GUESS)
- `this+0x0000002C` `pointer fixed_entry_6` (read, GUESS)
- `this+0x00000030` `pointer fixed_entry_7` (read, GUESS)
- `this+0x00000038` `int entry_count` (read, GUESS)

### SessionDirector

Central session director object. Holds the session phase/state, a nested session object, timer accumulators, a pending-phase slot, a vehicle index, and the current event queue; publishes the active vehicle pointer and processes session event queues.

Methods: `0x0040D980`, `0x0040DA30`, `0x0040DE60`

- `this+0x00000000` `int session_phase` (read_write, GUESS)
- `this+0x00000004` `pointer session_object` (read_write, GUESS)
- `*(this+0x4)+0x00000024` `byte session_flag` (read_write, GUESS)
- `this+0x0000004C` `array pointer_array` (write, GUESS)
- `this+0x00000084` `int counter_a` (write, GUESS)
- `this+0x00000088` `pointer sub_struct` (read_write, GUESS)
- `this+0x0000008C` `int counter_b` (write, GUESS)
- `this+0x00000090` `int pending_phase` (read_write, GUESS)
- `this+0x00000094` `int vehicle_index` (read_write, GUESS)
- `this+0x00000098` `float timer_b` (read_write, GUESS)
- `this+0x0000009C` `float timer_a` (read_write, GUESS)
- `this+0x000000A0` `byte flag` (read_write, GUESS)
- `this+0x000000A8` `int event_action_type` (read, GUESS)
- `this+0x000000AC` `int event_sub_type` (read, GUESS)

### SessionActionDispatcher

Dispatches an incoming action through a three-stage cascade of lookup objects (menu-slot, callback, resource), records the matched object, decodes the session phase, transitions the game-action state machine, and optionally fires the matched object's vtable slot at +16.

Methods: `0x0040D1B0`

- `this+0x00000008` `pointer matched_object` (read_write, GUESS)
- `*(this+0x8)+0x00000000` `pointer vtable` (read, GUESS)
- `*(*(this+0x8)+0x0)+0x00000010` `pointer dispatch_slot` (read, GUESS)
- `this+0x00000018` `pointer menu_slot_dispatch` (read, GUESS)
- `this+0x0000001C` `pointer callback_lookup` (read, GUESS)
- `this+0x00000020` `pointer resource_lookup` (read, GUESS)
- `this+0x0000002C` `byte dispatch_flag` (write, GUESS)

### SessionPhaseDecoder

Decodes the current game-session phase. Compares the current session pointer against an expected pointer and maps the session phase dword (identity 0-4) into a stored phase, with fallback 5 on mismatch.

Methods: `0x0040CD60`

- `this+0x00000008` `pointer expected_session` (read, GUESS)
- `this+0x0000000C` `int decoded_phase` (read_write, GUESS)
- `this+0x00000018` `pointer current_session` (read, GUESS)
- `this+0x0000004C` `int phase` (read, GUESS)

### SessionLoadingContext

Session/loading context holding six batches of 36-byte objects (count plus base pointer per batch). Dispatches each object to mode-dependent render/physics handling; batches 4-6 skip entries whose associated vehicle state is still live.

Methods: `0x00411120`

- `this+0x00000024` `int batch1_count` (read, DERIVED)
- `this+0x00000028` `pointer batch1_base` (read, DERIVED)
- `this+0x00000030` `int batch2_count` (read, DERIVED)
- `this+0x00000034` `pointer batch2_base` (read, DERIVED)
- `this+0x0000003C` `int batch3_count` (read, DERIVED)
- `this+0x00000040` `pointer batch3_base` (read, DERIVED)
- `this+0x00000048` `int batch4_count` (read, DERIVED)
- `this+0x0000004C` `pointer batch4_base` (read, DERIVED)
- `this+0x00000054` `int batch5_count` (read, DERIVED)
- `this+0x00000058` `pointer batch5_base` (read, DERIVED)
- `this+0x00000060` `int batch6_count` (read, DERIVED)
- `this+0x00000064` `pointer batch6_base` (read, DERIVED)

### ReciprocalOut

Small two-float out-struct helper: writes 1.0f at +4 and either 1.0f/a2 or 1.0f at +8 depending on the sign of a2. Likely a scratch output struct, not a real class.

Methods: `0x00408420`

- `this+0x00000004` `float one` (write, GUESS)
- `this+0x00000008` `float reciprocal` (write, GUESS)

### CollisionStructInitializer

Initializer for an unknown physics/collision struct: stores a caller value, a constant 5, and a caller int; sets collision inverse-mass data and six float fields; optionally runs a follow-up short computation.

Methods: `0x0040EC70`

- `this+0x00000008` `int16 field_a` (write, GUESS)
- `this+0x0000001C` `int constant_5` (write, GUESS)
- `this+0x00000020` `int field_b` (write, GUESS)

### AudioCommentaryController

Global audio-commentary channel configuration object (at dword_8AC4C4). Queries channel parameters through AudioCommentaryChannelConfiguration and applies them via a vtable slot at offset 72. The canonical name 'SceneGraphQuery' does not match the audio-commentary body.

Methods: `0x004116C0`


## Compatibility contracts

- **MilesSoundSystemContract** — The executable relies on imported Miles Sound System entry points: set_stream_volume_levels at 0x59E378, shutdown at 0x59E394, waveOutClose at 0x59E3A4, enumerate_filters at 0x59E3B0, open_filter at 0x59E3B4, and mem_free_lock at 0x59E3CC. A replacement must supply equivalent behavior or preserve the import surface.
- **SessionModeEnumContract** — Global dword_7C569C selects session mode: 2 = race mode (snapshot/compare five state dwords, clamped progress accumulation, RaceModeSetup at threshold) and 5 = server mode (session-start sound plus one-shot audio render dispatch). A main-menu/bitmap path is gated by global dword_7CD8C0.
- **SessionPhaseDecodeContract** — The session phase dword (session+0x4C) maps identity 0-4 onto the stored phase; when the current session pointer mismatches the expected pointer the decoder stores fallback 5. Callers rely on the returned this+0xC value.
- **SessionEventActionContract** — Event-queue entries dispatch on action type 2/3/4 and sub-types 2-12, driving session phase transitions including advance to phase 5 (car selection) and termination at phase -1. Timing uses the global double dbl_8AFE98 accumulators and per-entry timer/delay/probability fields.
- **ActiveVehiclePointerContract** — On reset, the director publishes the active vehicle for the stored index: dword_7C54F0[index] is read and the index is written to dword_7C54DC while the pointer is written to dword_7C54E0.

## Unresolved

- The owners of most functions are UNKNOWN at the function-IR level; the class grouping above is a DERIVED/GUESS proposal, not a confirmed identity.
- flt_59E440, flt_59E450, flt_59E43C, flt_59E6E0, dword_5EA4E8, dword_5EA510 and dword_8AD298 are packet-listed globals absent from the raw decompiled bodies; their roles are unresolved.
- byte_8AC494 is listed as an accessed global by 0x404B60 but does not appear in its raw source; only 0x404970 evidences it as the mixer scene-name buffer.
- The 0x40D1B0 call into SessionPhaseDecode passes an uninitialized ecx-aliased register; the intended no-argument call is a DERIVED reading.
- MilesStreamVolumeControl's v2+4 volume float and v2+12 stream pointer are tainted by a decompiler saved-return-address artifact, so the exact value passed to AIL_set_stream_volume_levels cannot be trusted.
- The vtable slot +12 stream-control call versus the AIL_set_stream_volume_levels import path (mute vs level-set) is inferred, not documented.
- Field offset 0xE4 is read through the config sub-object in 0x405D70 but packet-listed as field:this:0xE4; the exact object relationship is unresolved. Session+0x4C is likewise packet-listed as field:this:0x4C in 0x40CD60.
- The five compared state dwords (obj+0x0..0x10) and the progress accumulator semantics in 0x404B60 are not established by the packet.
- Semantics of the StringList aux dword (+0x48) and the node byte flag (+8) / -1 buffer prefill are unknown.
- The ViewCameraReset loop touches three slots but only the first slot (this+0x1C/0x20) has field evidence; later slots are not independently evidenced.
- Field this+0x34 in 0x40A680 (dword index 13) is flagged by packet facts but never referenced in the raw source.
- Field obj+0x34 in 0x406E50 is a packet-listed read with no visible use in the decompiled body.
- Fields this+0x28, 0x94, 0xB0, 0xB4 in 0x40DE60 do not appear in the decompiled body; their event-timing roles are unresolved.
- The jump tables jpt_40CD70 (0x40CDBC) and the 0x40DF5A/0x40E006 tables (0x40E130/0x40E15C) implement the phase and event dispatches, but individual target addresses are not evidenced.
- Why batches 1-3 dispatch unconditionally while batches 4-6 are vehicle-conditioned in 0x411120 is unproven; possibly distinct render vs physics object pools.
- The vehicle strides 18624 and the 296-byte subrecords / 17-element state groups in 0x411120 are read-only observations from guard arithmetic, not claimed field offsets.
- 0x4116C0's canonical name SceneGraphQuery does not match its audio-commentary body; the mismatch is unresolved.
- The sub_588410 comparison semantics (0 meaning equal) and sub_566810 prefix-check behavior are inferred from branch usage, not independently evidenced.
- The audio mixer init path (0x4C85D0/0x4C8830) and the RaceModeSetup target (0x404890) are callable callees not present in this packet, so their internal contracts are out of scope.
