# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Evidence-linked reconstruction of generic runtime object support in the F1 Challenge engine, covering: file-load dispatch onto per-entry vtable receivers (LoadFileAndDispatchToEntries 0x0040BD10); camera-manager initialization and restart (0x0040C920, 0x0040C9E0); the action-driven camera/session state machine and its per-frame branch dispatcher (0x0040CDE0, 0x0040D100) with conditional virtual/audio helpers (0x0040D090) and session-phase-aware action dispatch (0x0040D3C0, 0x0040D410); a shared literal-field struct initializer reused by four callers (0x0040D490); commentary/cinematic director state parsed from config tokens (0x0040D4C0); an audio-gated two-phase state-machine initializer (0x0040DCD0); per-tick engine dispatch with a buffer re-initializer (0x0040E170); collision-shape initialization and mode-dispatch float processing (0x0040E8F0, 0x0040EEC0); a camera-shake/telemetry ring-buffer writer (0x0040F600); and track-object-manager teardown freeing every heap array slot (0x0040FB30). Class ownership of nearly all objects is unresolved; every class and field here is a GUESS proposal grounded in packet evidence, and the camera-mode/action-id value meanings are not independently established.

## Function roles

- `0x0040BD10` **FileDispatchContainer** — Loads a file (clearing the FILE_ATTRIBUTE_READONLY bit via ToggleFileReadOnlyAttributeViaWin32API, then reading with sub_566940 or sub_566A70 depending on a3) and dispatches the loaded data to each entry of the stride-208 array at this[3] (count this[4]) through the per-entry vtable+8 method; returns 0 if at least one entry received data, else 1.
- `0x0040C920` **CameraManager** — Camera-manager initializer: optional debug log gated on StringSplitLoop; resolves the mainview handle into this+0x0; clears six game-state globals (0x5EA500..0x5EA508, 0x5EA550..0x5EA558); loads the scene file, resolves module asset paths and runs the camera config loader; clears the byte flag at this+0x2D; copies this+0x18 into this+0x8 when sub_40C140 fails; returns GlobalFlagSetClear(32, 1). Called by Game_Init.
- `0x0040C9E0` **CameraManager** — Camera-manager restart: optional debug log; re-initializes the camera state machine from the global constant block flt_5EA4E8 via StateInitWithGlobalConstants; resets the stored player/entity id at this+0x38 to -1 and the byte flag at this+0x2E to 0; returns the state-init result.
- `0x0040CDE0` **CameraSessionStateMachine** — Action-driven game state machine: dispatches on action id a2 (cases 0-10 plus default) via jump table 0x0040D050, forwarding camera modes to ViewCameraModeDispatch and triggering AudioSoundEffectController, recording the last action in this[3]; every handled case sets the active state pointer this[2] from the session/camera pointer this[6]; case 5 runs the vtable+0x10 virtual on the active state object plus a guarded child transition; case 3 has a secondary transition gated by the byte at dword_7C54E0+13388 and byte_7CFE88; returns 0 on handled cases, 1 on the default path.
- `0x0040D090` **CameraSessionStateMachine** — Conditionally dispatches the virtual method at vtable+16 on this[2] (when non-null) and, when dword_8AFE88 is non-null, zeros the dwords at offsets 424 and 420 of that global object; returns the last computed result.
- `0x0040D100` **CameraSessionStateMachine** — Per-frame game state branch dispatch: reads the session/camera pointer at this+0x18 and, only when non-zero, switches on the global mode selector dword_7CFDC4 (cases 1-4 plus default) to call ViewCameraModeDispatch and GameActionStateMachine with paired camera-mode/action-id arguments; returns the selected GameActionStateMachine result. Invoked per-frame by sub_40C140, NetCommPlayerSlotSync, sub_4A00A0, sub_4C6B60 and PitTimer.
- `0x0040D3C0` **CameraSessionStateMachine** — Session-phase-aware action dispatcher: gated by the session-active flag dword_7D0350, decodes the session phase via SessionPhaseDecode; when the action id a2 is in [7, 10] it stores the decoded phase at this+0x10 (when <= 5), dispatches GameActionStateMachine(this, a2, 0), sets the activity flag this+0x24 to 1 and runs ReciprocalWithSignCheck on flt_5EA4E8. Called by PitStopReadyCheck.
- `0x0040D410` **CameraSessionStateMachine** — Per-frame session/pit complementary action: decodes the session phase via SessionPhaseDecode; when the decoded phase is in [7, 10] dispatches GameActionStateMachine with the action id read from this+0x10 and a zero argument; unconditionally computes a safe reciprocal on flt_5EA4E8 via SafeDivisionWithZeroGuard (0.5 divisor) and clears the activity flag byte at this+0x24.
- `0x0040D490` **StateInitBlock** — Shared literal-field initializer writing eleven fields at this+0x4..0x2C (all zeroed except the dword at +0x28 set to 1 and the byte at +0x20 written as a single zero byte) and returning 0; no reads, no globals, no callees. Reused by SimpleSetterWithSubCall, RaceCommentaryDirectorSystem, CameraDirectorResetInit and StateMachineInitializer.
- `0x0040D4C0` **CommentaryDirectorState** — Initializes a race commentary/cinematic director state from a configuration data block: resets via StructFieldInit, parses the Type token into the action type at this+0x24 (documented token-to-type map), optional probability/time/iterations/wait tokens into this+0xC/+0x10/+0x14/+0x18/+0x20, and resolves the target entity into this+0x2C (camera name, grid position, driver or commentary topic) with the result code at this+0x28; returns 1 on success and 0 (after re-initializing) on failure. Called by ConditionalDelegation and CinematicEventStateMachine.
- `0x0040DCD0` **TwoPhaseAudioGateStateMachine** — Two-phase state-machine initializer: phase 1 sets the state at this+0x0 to 1, zeroes this+0x84, initializes the sub-struct at +0x88 via StructFieldInit, stops audio channel a2 via AudioChannelStop and stores the result in this+0x84 (a zero stop result blocks and returns 0); phase 2 sets state to 2 and runs CinematicEventStateMachine, returning 1 on a non-zero result or reverting the state to -1 and returning 0 on failure.
- `0x0040E170` **EngineTickObject** — Tick update dispatch: when the sub-struct at this+0x88 is non-null and its field at +0x24 equals 10, runs EngineGuardedInitializer with this+20; reads the sub-struct at this+0x8 and, when the pointer at its +0xAF4 is non-null, invokes that object's vtable method at +0xC; re-initializes the buffer with 10f defaults via BufferInitWith10fDefaults; then tail-calls the camera-director reset init.
- `0x0040E8F0` **CollisionShapeState** — Physics collision-shape initializer: writes the word discriminator a2 at +0x8, zeroes +0x1C, stores a3 at +0x20, fills a local 6-dword float array, stores inverse-mass scalar 2.5 via CollisionInvMassStore, bulk-sets six float constants via F_6FieldBulkSetter, then runs ShortComputation_e770 when a4 is non-zero and returns its result, otherwise returns 0.
- `0x0040EEC0` **CollisionShapeState** — Loads a 7-element float array and dispatches on the mode selector this[7] (offset 0x1C) via the jump table at 0x0040EF54: modes 0-5 store the first element as collision inverse mass via CollisionInvMassStore and bulk-set the remaining six float fields via F_6FieldBulkSetter; mode 6+ returns immediately.
- `0x0040F600` **CameraShakeRingBuffer** — Writes a camera-shake/vehicle-telemetry sample into the fixed ring buffer (432-byte entries, at most 1023; write pointer global dword_8AAE64, count dword_83EE60): reads position, orientation (atan2-derived angles), velocity and angular velocity from the source structure at *(this+0x20), quantizes them into clamped 16-bit words, optionally emits a progress-bar HUD event through the mode switch at this+0x1C (cases 0-5) and returns the last quantized value.
- `0x0040FB30` **TrackObjectManager** — Teardown of a track-object manager: frees every heap array stored at this+0x0..0x68. Simple pointer arrays are freed via FreeWrapper_7bcf using the stored allocation base 4 bytes before each array; 792/808-byte element arrays (0x2C, 0x38, 0x44, 0x50) run ShortComputation_fd70 per element; 36-byte element arrays (0x40, 0x4C, 0x58) are walked with ArrayDestructorIterator and the EmptyStub_aa60 no-op; trailing arrays (0x5C, 0x64, 0x68) are released through ArrayOfObjectsDestructor/ShortComputation_fda0. All freed slots are zeroed. Delegated from DelegationThunk (0x0040E1C0).

## Proposed classes

### FileDispatchContainer

Container holding a stride-208 entry array at +0xC with the entry count at +0x10; each entry exposes a vtable whose slot +8 receives loaded file data. Owner type unknown; the 'camera entry' reading from prior analysis is DERIVED, not proven by this packet.

Methods: `0x0040BD10`

- `this+0x0000000C` `void* entry_array_base` (read, GUESS)
- `this+0x00000010` `int entry_count` (read, GUESS)

### CameraManager

Camera manager: resolved manager handle at +0x0, config-load result at +0x8/+0x18, byte flags at +0x2D/+0x2E and stored player/entity id at +0x38. Initialized by CamManInit (also clearing the six game-state globals 0x5EA500..0x5EA558) and reset by CameraManagerRestart. Owner identity is the camera manager itself; the class grouping rests on the two lifecycle functions writing distinct fields of the same object.

Methods: `0x0040C920`, `0x0040C9E0`

- `this+0x00000000` `DWORD manager_handle` (write, GUESS)
- `this+0x00000008` `DWORD config_result` (read_write, GUESS)
- `this+0x00000018` `DWORD config_load_result` (read_write, GUESS)
- `this+0x0000002D` `BYTE init_byte_flag` (write, GUESS)
- `this+0x0000002E` `BYTE restart_byte_flag` (write, GUESS)
- `this+0x00000038` `int stored_player_entity_id` (write, GUESS)

### CameraSessionStateMachine

Game/camera session state machine: active state pointer at +0x8, last action at +0xC, fallback marker at +0x14, session/camera pointer at +0x18, case-5 progression guard words at +0x1C/+0x20, activity flag at +0x24, progression counters at +0x2C/+0x30, plus a phase/action field at +0x10. Dispatches camera modes to ViewCameraModeDispatch and triggers AudioSoundEffectController. Grouping rests on the shared this[2]/this[6] pattern across the dispatch functions; concrete owner identity is unknown.

Methods: `0x0040CDE0`, `0x0040D090`, `0x0040D100`, `0x0040D3C0`, `0x0040D410`

- `this+0x00000008` `void* active_state_ptr` (read_write, GUESS)
- `this+0x0000000C` `int last_action` (write, GUESS)
- `this+0x00000010` `int phase_or_action_field` (read_write, GUESS)
- `this+0x00000014` `int fallback_state_marker` (write, GUESS)
- `this+0x00000018` `void* session_camera_ptr` (read, GUESS)
- `this+0x0000001C` `int progression_guard_a` (read, GUESS)
- `this+0x00000020` `int progression_guard_b` (read, GUESS)
- `this+0x00000024` `int activity_flag` (read_write, GUESS)
- `this+0x0000002C` `int progression_counter_a` (read, GUESS)
- `this+0x00000030` `int progression_counter_b` (read, GUESS)

### StateInitBlock

Shared zero-defaults initialization block written by StructFieldInit across four callers: dwords at +0x4..+0x1C, byte at +0x20, dword at +0x24, sentinel dword at +0x28 (set to 1) and dword at +0x2C. Owner type unknown; the equal offsets belong to possibly distinct concrete objects and are not merged as proven common ownership.

Methods: `0x0040D490`

- `this+0x00000004` `DWORD init_dword_04` (write, GUESS)
- `this+0x00000008` `DWORD init_dword_08` (write, GUESS)
- `this+0x0000000C` `DWORD init_dword_0C` (write, GUESS)
- `this+0x00000010` `DWORD init_dword_10` (write, GUESS)
- `this+0x00000014` `DWORD init_dword_14` (write, GUESS)
- `this+0x00000018` `DWORD init_dword_18` (write, GUESS)
- `this+0x0000001C` `DWORD init_dword_1C` (write, GUESS)
- `this+0x00000020` `BYTE init_byte_20` (write, GUESS)
- `this+0x00000024` `DWORD init_dword_24` (write, GUESS)
- `this+0x00000028` `DWORD init_sentinel_one_28` (write, GUESS)
- `this+0x0000002C` `DWORD init_dword_2C` (write, GUESS)

### CommentaryDirectorState

Commentary/cinematic director state parsed from a config data block: config pointer at +0x4, probability at +0xC, time at +0x10, time mode at +0x14, iterations at +0x18, wait flag byte at +0x20, action type at +0x24, result code at +0x28 and resolved target entity at +0x2C. Embeds a StateInitBlock-shaped region (+0x4..+0x2C) that StructFieldInit re-initializes before parsing; owner type unknown.

Methods: `0x0040D4C0`

- `this+0x00000004` `void* config_data_ptr` (write, GUESS)
- `this+0x0000000C` `float probability` (write, GUESS)
- `this+0x00000010` `float time` (write, GUESS)
- `this+0x00000014` `int time_mode` (write, GUESS)
- `this+0x00000018` `int iterations` (write, GUESS)
- `this+0x00000020` `BYTE wait_flag` (write, GUESS)
- `this+0x00000024` `int action_type` (write, GUESS)
- `this+0x00000028` `int result_code` (write, GUESS)
- `this+0x0000002C` `int target_entity` (write, GUESS)

### TwoPhaseAudioGateStateMachine

Two-phase state-machine initializer: phase state at +0x0 (1 = stopping audio, 2 = cinematic init, -1 = error), audio-stop result at +0x84 and sub-struct pointer at +0x88. Phase 1 stops the audio channel before phase 2 runs CinematicEventStateMachine. Owner type unknown; the numeric state meanings are DERIVED from control flow only.

Methods: `0x0040DCD0`

- `this+0x00000000` `int state` (read_write, GUESS)
- `this+0x00000084` `int audio_stop_result` (read_write, GUESS)
- `this+0x00000088` `void* substate_ptr` (read, GUESS)

### EngineTickObject

Per-tick engine object: sub-struct pointer at +0x8 (whose field at +0xAF4 holds a dispatchable object exposing a vtable slot +0xC) and a second sub-struct pointer at +0x88 (whose field at +0x24, when equal to 10, gates EngineGuardedInitializer on this+20). Its buffer is re-initialized via BufferInitWith10fDefaults. Owner type unknown.

Methods: `0x0040E170`

- `this+0x00000008` `void* engine_substruct_ptr` (read, GUESS)
- `this+0x00000088` `void* flag10_substruct_ptr` (read, GUESS)

### CollisionShapeState

Physics collision-shape state: word discriminator at +0x8, subtype/mode selector at +0x1C and external data pointer at +0x20. Initialized by StructInitWithFloatConstantsAndSubCalls and mode-dispatched by SwitchBasedFloatProcessing; both delegate inverse-mass and six-float bulk storage to the shared collision helpers CollisionInvMassStore and F_6FieldBulkSetter.

Methods: `0x0040E8F0`, `0x0040EEC0`

- `this+0x00000008` `WORD type_discriminator` (read_write, GUESS)
- `this+0x0000001C` `int mode_selector` (read_write, GUESS)
- `this+0x00000020` `void* data_ptr` (write, GUESS)

### CameraShakeRingBuffer

Camera-shake / vehicle-telemetry ring-buffer writer: header word at +0x8, active flag byte at +0xA, event mode at +0x1C and source-data pointer at +0x20. Writes 432-byte quantized entries (at most 1023) into the global ring buffer (write pointer 0x008AAE64, entry count 0x0083EE60) and optionally emits HUD progress-bar events. Owner type unknown.

Methods: `0x0040F600`

- `this+0x00000008` `WORD header_word` (read, GUESS)
- `this+0x0000000A` `BYTE active_flag` (read_write, GUESS)
- `this+0x0000001C` `int event_mode` (read, GUESS)
- `this+0x00000020` `void* source_data_ptr` (read, GUESS)

### TrackObjectManager

Track-object manager torn down by GraphicsResourceDestructor: total count and capacity at +0x0/+0x4, a combined array pointer at +0x8, then per-category count-plus-pointer triples covering vehicle, dspoly, non-DSP, cone, post, sign, wheel, wing and part arrays of 36/792/808-byte elements. The per-slot category pairing is DERIVED from prior analysis and is not independently confirmed by this packet; the single pointer array at +0x8 is freed directly (no -4 base adjustment) while every other array is freed through its stored base.

Methods: `0x0040FB30`

- `this+0x00000000` `int total_count` (read_write, GUESS)
- `this+0x00000004` `int capacity` (read_write, GUESS)
- `this+0x00000008` `void* combined_array_ptr` (read_write, GUESS)
- `this+0x0000000C` `int vehicle_count` (read_write, GUESS)
- `this+0x00000010` `void* vehicle_array_ptr` (read_write, GUESS)
- `this+0x00000014` `int dspoly_count` (read_write, GUESS)
- `this+0x00000018` `void* dspoly_array_ptr` (read_write, GUESS)
- `this+0x0000001C` `int nondsp_count` (read_write, GUESS)
- `this+0x00000020` `void* nondsp_array_ptr` (read_write, GUESS)
- `this+0x00000024` `int cone_count` (read_write, GUESS)
- `this+0x00000028` `void* cone_small_array_ptr` (read_write, GUESS)
- `this+0x0000002C` `void* cone_large_array_ptr` (read_write, GUESS)
- `this+0x00000030` `int post_count` (read_write, GUESS)
- `this+0x00000034` `void* post_small_array_ptr` (read_write, GUESS)
- `this+0x00000038` `void* post_large_array_ptr` (read_write, GUESS)
- `this+0x0000003C` `int sign_count` (read_write, GUESS)
- `this+0x00000040` `void* sign_small_array_ptr` (read_write, GUESS)
- `this+0x00000044` `void* sign_large_array_ptr` (read_write, GUESS)
- `this+0x00000048` `int wheel_count` (read_write, GUESS)
- `this+0x0000004C` `void* wheel_small_array_ptr` (read_write, GUESS)
- `this+0x00000050` `void* wheel_large_array_ptr` (read_write, GUESS)
- `this+0x00000054` `int wing_count` (read_write, GUESS)
- `this+0x00000058` `void* wing_small_array_ptr` (read_write, GUESS)
- `this+0x0000005C` `void* wing_large_array_ptr` (read_write, GUESS)
- `this+0x00000060` `int part_count` (read_write, GUESS)
- `this+0x00000064` `void* part_small_array_ptr` (read_write, GUESS)
- `this+0x00000068` `void* part_large_array_ptr` (read_write, GUESS)

## Compatibility contracts

- **FileDispatchLoadContract** — LoadFileAndDispatchToEntries (0x0040BD10) must clear the file's read-only attribute via ToggleFileReadOnlyAttributeViaWin32API, load the file through sub_566940 or sub_566A70 depending on a3, dispatch the loaded data to every entry of the stride-208 array at this+0xC (count this+0x10) through the per-entry vtable+8 method, close the file handle, free the temp-struct fields, and return 0 if at least one entry received data (1 on the early-out, skip and no-entry-dispatched paths).
- **CamManagerInitContract** — CamManInit (0x0040C920) must clear the six game-state globals 0x005EA500..0x005EA508 and 0x005EA550..0x005EA558, resolve the mainview handle into this+0x0, load the scene file, resolve module asset paths, run the camera config loader, clear this+0x2D, copy this+0x18 into this+0x8 when sub_40C140 fails, and return GlobalFlagSetClear(32, 1).
- **CameraManagerRestartContract** — CameraManagerRestart (0x0040C9E0) must re-initialize the camera state machine from the global constant block flt_5EA4E8, reset the stored player/entity id at this+0x38 to -1 and the byte flag at this+0x2E to 0, and return the state-init result.
- **GameActionDispatchContract** — DispatchGameAction (0x0040CDE0) must dispatch the action id a2 through the jump table 0x0040D050 (cases 0-10 plus default), forwarding the derived camera mode to ViewCameraModeDispatch and triggering AudioSoundEffectController, set the active state pointer this[2] from the session/camera pointer this[6] on every handled case, record a2 into this[3], run the case-5 virtual vtable+0x10 dispatch plus its guarded child transition, honor the case-3 secondary transition gated by the byte at dword_7C54E0+13388 and byte_7CFE88, and return 0 on handled cases or 1 on the default path.
- **PerFrameCameraBranchContract** — GameStateBranchDispatch (0x0040D100) must return without dispatching when the pointer at this+0x18 is null; otherwise it must switch on the global mode selector dword_7CFDC4 and for each case call ViewCameraModeDispatch then GameActionStateMachine with the documented camera-mode/action-id pairs (case 1: (1,1), case 2: (0,0), case 3: (3,3), case 4: (3,5), default: (2,2)), returning the selected GameActionStateMachine result.
- **SessionPhaseActionContract** — SessionPhaseActionDispatch (0x0040D3C0) must run only while the session-active flag dword_7D0350 is non-zero; when the action id a2 is in [7, 10] it must decode the session phase, store the phase at this+0x10 when it is <= 5, dispatch GameActionStateMachine(this, a2, 0), set the activity flag this+0x24 to 1 and run ReciprocalWithSignCheck on flt_5EA4E8.
- **CommentaryDirectorParseContract** — RaceCommentaryDirectorSystem (0x0040D4C0) must parse the Type token into the action type at this+0x24 using the documented token-to-type map (aScriptEnd->0, aWait->12, aGridwalk->11, aFlyOver->10, aCommentaryStop->9, aCommentaryStar->8, aCameraSetLast->7, aCameraReleaseC->6, aCameraAcquireC->3, aCameraTargetSe->2, aCameraSelect->5, no match->4), parse the optional probability/time/iterations/wait tokens into this+0xC/+0x10/+0x14/+0x18/+0x20, resolve the target entity into this+0x2C (camera name, grid position, driver or commentary topic), and return 1 on success or 0 on failure after re-initializing via StructFieldInit.
- **TwoPhaseAudioGateInitContract** — StateMachineInitializer (0x0040DCD0) must run a two-phase initialization: phase 1 sets state this+0x0 to 1, zeroes this+0x84, initializes the sub-struct at +0x88 via StructFieldInit, stops audio channel a2 via AudioChannelStop storing the result in this+0x84 and returns 0 when the stop failed; phase 2 sets state to 2 and runs CinematicEventStateMachine, returning 1 on a non-zero result or reverting the state to -1 and returning 0 on failure.
- **TickUpdateDispatchContract** — TickUpdateDispatch (0x0040E170) must run EngineGuardedInitializer with this+20 when the sub-struct at this+0x88 is non-null and its field at +0x24 equals 10, invoke the vtable+0xC method on the object at *(this+0x8)+0xAF4 when that pointer is non-null, re-initialize the buffer via BufferInitWith10fDefaults, and tail-call the camera-director reset init.
- **CollisionShapeInitContract** — StructInitWithFloatConstantsAndSubCalls (0x0040E8F0) must write the word discriminator a2 at +0x8, zero +0x1C, store a3 at +0x20, fill a local 6-dword float array, store inverse-mass scalar 2.5 via CollisionInvMassStore, bulk-set six float constants via F_6FieldBulkSetter, then run ShortComputation_e770 when a4 is non-zero and return its result (0 when a4 is zero).
- **CameraShakeRingBufferContract** — CameraShakeRingBufferWrite (0x0040F600) must write a quantized sample into the global ring buffer (write pointer 0x008AAE64, count 0x0083EE60, 432-byte entries, at most 1023), encoding orientation angles scaled/clamped to 16-bit words (entry+19/+21/+23), velocity (entry+25/+27/+29) and angular velocity (entry+31/+33/+35), and must route the mode field at this+0x1C through cases 0-5 to the HUD progress-bar encoder 0x004B33B0.
- **TrackObjectTeardownContract** — GraphicsResourceDestructor (0x0040FB30) must free every heap array at this+0x0..0x68: simple pointer arrays via FreeWrapper_7bcf using the stored allocation base 4 bytes before each array, 792/808-byte element arrays via per-element ShortComputation_fd70, 36-byte element arrays via ArrayDestructorIterator with the no-op stub, trailing arrays via ArrayOfObjectsDestructor/ShortComputation_fda0, and then zero all freed slots.

## Unresolved

- Owner objects and classes of nearly all functions here are unknown; every class grouping is a GUESS resting on shared this-field access patterns, not proven common ownership.
- The vtable+8 dispatch target of LoadFileAndDispatchToEntries (0x0040BD10) is an indirect call with no static callee in the packet; the prior 'camera entry' reading is DERIVED, not proven.
- The difference between sub_566940 and sub_566A70 (the a3-dependent loaders in 0x0040BD10) is unconfirmed beyond the branch itself.
- Globals dword_8AFE64 and dword_8AFE88 are flagged read-only by packet facts but absent from the raw decompiled bodies of CamManInit; dword_8AFE88 is only actually used in VirtualDispatchConditionalAudio (0x0040D090, offsets +420/+424), and dword_8AFE64 has no located use in this packet.
- The exact semantics of the byte flags this+0x2E and this+0x38 in CameraManagerRestart (0x0040C9E0) are not evidenced beyond the restart-reset behavior.
- The meaning of the byte at dword_7C54E0 + 13388 and its interaction with byte_7CFE88 in the case-3 secondary transition is unknown.
- The identity and semantics of sub_40D080 (guard predicate in the case-5 path) and of the vtable+0x10 virtual dispatched in case 5 of DispatchGameAction (0x0040CDE0) are unknown.
- The exact meaning of the camera mode values (0-8) passed to ViewCameraModeDispatch is unverified; why case 4 of GameStateBranchDispatch reuses camera mode 3 with action id 5 is not explained by the packet.
- The ReciprocalWithSignCheck call in SessionPhaseActionDispatch (0x0040D3C0) has no callee address in the packet; what SafeDivisionWithZeroGuard (0x00408450) writes through flt_5EA4E8 with a 0.5 divisor is unresolved.
- The first argument to GameActionStateMachine in ShortComputation_d410 (0x0040D410) is an uninitialized register in the decompilation; the real receiver is not established.
- StructFieldInit (0x0040D490) is reused by four callers (SimpleSetterWithSubCall, RaceCommentaryDirectorSystem, CameraDirectorResetInit, StateMachineInitializer) but the shared target type is not established; whether the single-byte write at +0x20 overlaps an adjacent dword-sized field is unresolved.
- CONTRADICTION: TickUpdateDispatch (0x0040E170) gates EngineGuardedInitializer on *(this+0x88)+0x24 == 10, while StructFieldInit writes that same offset to 0; the +0x88 sub-struct is therefore not evidently a StateInitBlock-typed object, or the flag is set by another writer before the tick.
- sub_588410 token-match semantics (string containment vs equality), sub_58850F (float) and sub_587ECE (integer) config-entry parse formats, and SingleFunctionCallWrapper_7f59's position-value conversion in RaceCommentaryDirectorSystem are unverified.
- The vehicle-array fields at offsets 16480 and 18580 used with dword_7C54F0 and dword_7C54E8 are unlabeled; the array base dword_7C54F0 is the vehicle array anchor from the corpus.
- Action type 1 is not produced by the RaceCommentaryDirectorSystem token chain (assigned types are 0 and 2..12), so its dispatch path is unreachable through normal parsing; this+0x2C is both a gated result field and the resolved target-entity id.
- The numeric state values (1/2/-1) of TwoPhaseAudioGateStateMachine are DERIVED from control flow, not independently established.
- The CameraDirectorResetInit tail-call target of TickUpdateDispatch (0x0040E170) has no callee evidence record in the packet; its address is not recoverable from this packet.
- The six float constants bulk-set by F_6FieldBulkSetter in StructInitWithFloatConstantsAndSubCalls are preserved from raw source without IEEE-754 interpretation; the distinct mode behaviors 0-5 of SwitchBasedFloatProcessing are not visible per case.
- The correspondence between the extracted *(this+0x20) field offsets and the source-data quantities in CameraShakeRingBufferWrite is DERIVED; the individual roles of the float/double constants at 0x0059E420..0x0059E71C are not confirmed.
- The ring buffer written by 0x0040F600 (globals 0x008AAE64/0x0083EE60) is owned elsewhere; the HUD bar id 29 and vehicle-id read dword_7C54F0[dword_7C54E4]+18580 semantics are not established here.
- ArrayOfObjectsDestructor (0x0040FDD0) and ShortComputation_fda0 (0x0040FDA0) are invoked with the constant argument 3 while the guarded object slots (0x5C, 0x64, 0x68) are not passed; the decompiled raw source shows the constant, so the true argument was likely folded away.
- CONTRADICTION: field this+0x8 of TrackObjectManager is freed directly without the -4 base adjustment applied to every other array slot.
- The per-slot category pairing (vehicle/dspoly/non-DSP/cone/post/sign/wheel/wing/part) of TrackObjectManager is DERIVED from existing analysis; no static owner is confirmed by this packet.
