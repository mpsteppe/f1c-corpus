# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Proposal covers 18 validated functions in the generic_runtime_objects scope. The strongest grouping is a DERIVED Steward object (Steward_Init 0x004D38F0, restart 0x004D3CF0) holding session/restart state, waypoint tables, track polygon nodes, standings sentinels and a helicopter/scaling pointer; restart dispatches a session-type state machine (practice / qualifying-race / pre-race presentation). A DERIVED RaceContext (LoadRaceResources 0x004D8AB0, InitHudRenderResource 0x004D8CF0) shares normalized screen dimensions at +0xE4/+0xE8 and is invoked by RaceInitWithConstants. The remaining functions are small generic objects with unknown or weakly-tied ownership: file/resource handle destructor, XOR-triple-key file decoder feeding a feedback shift-register sink, a sentinel initializer (TireBrandLoader), a texture-surface container destroyer, trace log setup, track-reference finder, float-range classifier, three-way mode mapper, HUD message display, guarded state transition machine, conditional index setter, and a grid-car info renderer. No CONFIRMED claims are made; ownership is LOW confidence throughout.

## Function roles

- `0x004D36D0` **Unknown** — Steward subsystem setup: when StringSplitLoop(2, aDDevF119992002_3, 2330) returns non-zero, writes the 'Entered Steward' debug message via DebugLogWrite into the dword_8AD25C buffer; then registers the Vehicle, Timing and Pitstop subsystems through sub_5599D0/sub_559A00 with TimerFrameRateThrottle and TrackTemperatureDisplay as handler callbacks. Returns the result of the last sub_559A00 registration call. Called by Game_Setup (0042D5D0).
- `0x004D38F0` **Steward** — Track-steward initialization: optionally logs entry, locates light/glow scene nodes, queries the ground height at the track reference position, builds the steering waypoint arrays (count, positions and per-waypoint state) from the track reference speed, resolves pit-in/pit-out/finish/sector polygon scene nodes (setting render flags and logging when missing), places multiplayer starting vehicles according to the mode switch, and finally constructs a helicopter object when the helicopter scene node exists.
- `0x004D3CF0` **Steward** — Resets the race steward/session state machine at game restart. Clears session state bytes, resets two internal arrays, builds session-name and config-key strings, applies configuration overrides from data files (speed, name, duration, race time), then dispatches on the session type (dword_7C56A4): practice (unlimited laps), qualifying/race (time-based with per-session time defaults), or pre-race presentation (camera/state-machine init plus recon-pit / race-phase / init / fallback sub-paths). Ends by 0xFF-resetting a standings block, sorting standings data, and returning a randomized scaled value if the scaling pointer at this+0xA8 is present.
- `0x004D5840` **FileResource** — File/resource handle destructor. If the handle slot *this is non-zero, clears the handle's state through the state-writer sub_587F64, performs a locked read-back on the handle's owned buffer, closes the underlying file handle with FileCloseWithLock, and resets *this to 0. Returns the result of the file close (or the previous *this when the guard failed).
- `0x004D5AF0` **Unknown** — Opens the file path a1 in binary read mode, counts its byte size, writes a 4-byte size header to the output sink sub_4D5BE0, rewinds, then re-reads every byte decoding each one by XOR with a cycling 3-key scheme (keys 0x5C, 0xB4, 0x12) and writes the decoded bytes to the sink. Closes the file and returns the close result. When the open fails, writes four zero bytes to the sink and returns immediately.
- `0x004D5BE0` **FeedbackShiftRegister** — Runs a three-word feedback shift register over each byte of the input buffer, rotating state words at this[3..6], then writes the processed buffer to the file descriptor stored at *this via FileReadWrapperWithLock.
- `0x004D7020` **TireBrandEntry** — Constructor/initializer for a small struct. Clears fields at 0x0, 0xC, 0x14 and 0x18 to zero, writes a -1 sentinel into 0x4 and 0x1C, then runs ArrayBlockCleanup(this) as a final array-reset pass and returns the object pointer. Invoked by TireBrandLoader while building the tire brand table.
- `0x004D7800` **TextureSurfaceContainer** — Destroys a texture-surface container, consistent with the ABI lead Texture_Surface_Destroyer. If the entry count at this+0 is positive, iterates the active entries in the block at this+4 with a 36-byte (0x24) stride calling ArrayBlockCleanup on each. Then unconditionally clears the count at this+0. If the block pointer at this+4 is non-null, reads the allocation capacity from the header at block-4, walks all 36-byte (0x24) slots in reverse calling ArrayBlockCleanup per slot and freeing the sub-pointers at slot+0x18 and slot+0x0 via FreeWrapper_7bcf, frees the block header itself, and finally zeroes this+4. Returns the result of the last free operation. Called by SessionReset and TireBrandLoader during teardown.
- `0x004D7A00` **TraceLog** — Startup trace-log configuration. Checks the command-line arguments for the "notrace" flag via sub_587C20(a2, aNotrace); when the flag is absent, sets this[0] to 3000 and initializes the trace log with TraceLogInit(this); when the flag is present, skips initialization and returns the flag-check result. Called once from GameMainEntry (0045B200).
- `0x004D7B00` **TrackReferenceFinder** — Initializes and fills three track-reference slots. For each slot j in 0..2 it clears the two index dwords (this+4*j and this+4*j+12) to -1, sets a lower value bound (this+24 for slot 0 from flt_5EA404, this+28 hardcoded to 0 for slot 1, this+32 from flt_5EA3F8[2] for slot 2), and sets an upper value bound at this+4*j+36 from flt_5EA3FC[j]. It then scans the track data array dword_8ACFF0 (count dword_8ACFEC, 8-byte entries with a float at +4) and, for entries whose value lies inside the slot's lower/upper bounds, records the bracketing entry indices: the smallest such index into this+4*j and the largest into this+4*j+12. Called once by Game_Restart.
- `0x004D7C10` **FloatRangeClassifier** — Wraps a float a2 into the range [0, this[9]) by repeatedly adding or subtracting the wrap period stored at this+0x24, then classifies the wrapped value against a small descending threshold table rooted at flt_5EA404. Returns the matched segment index (2, 1 or 0), or 0 when the wrapped value exceeds flt_5EA404, or -1 when it exceeds every scanned threshold.
- `0x004D7CC0` **Unknown** — Maps a three-valued input to the next value in a cycle: 0 -> 1, 1 -> 2, 2 -> 0. Any other input returns -1 as an invalid sentinel. Called from AI session-mode transition, consistent with rotating an AI/session state machine through three modes.
- `0x004D8450` **HudMessageDisplay** — Per-tick HUD display manager. Renders the HUD flag overlay first, advances timed HUD messages (message index this+0x0 with a float countdown timer at this+0xDC), expires broadcast messages (index this+0x4), and dispatches the display sub-objects they point at. Then scans an input action map (word_7CB21C, dword_7CB218 entries) to toggle broadcast display (dword_7CF638) and HUD on/off (dword_7CF788), resolving the matching display string through the string table into byte_5EC4CC and rendering it. Ends with a gated audio-device handoff dispatch when this+0xEC is set and the pointer at this+0xD8 is non-null.
- `0x004D8760` **GuardedStateMachine** — Guarded state transition: given a target state id a2 and selector a3, verifies the candidate state object exists (this[a2+4] != 0), authorization passes (dword_7CF638 bypass or Return0Stub_9280(a2)), the move is forward-or-same in the IDToValueMapper ordering, and the ConditionalFlagReturn flag at dword_5EA43C is clear. On success writes 0 or 1056964608 (0.5f) to this[0xDC] per a3, stores the new state id in *this, and dispatches VTableDispatchWithFieldClear into the new object; returns 0. Otherwise returns 1, resetting *this to the -1 sentinel when the target id is itself the sentinel.
- `0x004D8840` **IndexedObject** — Conditional index setter. Copies the argument a2 into the result, then writes it into the dword at this+0x4 (this[1]) only when a2 is -1 or the entry tested at this[a2+29] is nonzero; otherwise this[1] is left unchanged. Always returns the original argument a2. Packet prelabel flags it as a structural twin of IntegerSetter (00406b30).
- `0x004D8AB0` **RaceContext** — Reloads four named resources (globals dword_8AD388/8AD38C/8AD390/8AD394) from a path constructed by joining an override or default base directory with a suffix, then a per-resource name plus a common extension. Each successfully loaded resource is configured with the normalized screen dimensions from this[57] and this[58] at offsets 92 and 96. The first existing resource is released before the reload and the probed path object is removed from the linked list afterwards. Returns the last resource-load result, or 1 when no load runs. Called by RaceInitWithConstants (004d8220).
- `0x004D8CF0` **RaceContext** — HUD render-resource initializer. Takes a resource type a2 in [1,5], releases any existing resource of that type via AudioResourceReleaseByType, then, per type, selects a global handle slot and screen-scaled quad dimensions. If the selected handle is empty, creates a render object with 4 textured quad vertices positioned using normalized screen dimensions this[0xE4]/this[0xE8]. Type 3 additionally allocates a 96-byte zero-filled struct, sets a bit flag at +68, builds a HUD51264.tga texture path from season directory/name globals (with byte_5EA438 fallback), loads the D3D texture, and on texture-load failure destructs and frees the struct and resets the sentinel. Returns 0 on successful creation, 1 for the default path or when a2 is outside [1,5].
- `0x004D9690` **GridCarEntry** — Renders one starting-grid car's on-screen info for owner object 'this': a position-number character (built from this+0x4060 and base byte_5D4AE8), the driver name string (this+0x46F8), the team name string (this+0x46B8), and the qualifying time (this+0x405C) formatted as minutes/seconds '%.2d:%06.3f' via SpatialGridCell, or a placeholder string when the time is negative. Position display is guarded to grid rows 1-25. Returns 1 when 'this' is NULL, otherwise 0.

## Proposed classes

### Steward

Race steward/session object: session-type dispatch and reset (restart), track initialization (waypoint table, ground height, track polygons, helicopter) (Steward_Init).

Methods: `0x004D38F0`, `0x004D3CF0`

- `this+0x000000A8` `void* scaling_or_helicopter_ptr` (read_write, DERIVED)
- `this+0x000000AC` `int lap_count` (read_write, DERIVED)
- `this+0x000000B0` `int session_time_accum` (read_write, DERIVED)
- `this+0x000000B4` `float time_lower_bound` (read_write, DERIVED)
- `this+0x000000B8` `float race_time` (read_write, DERIVED)
- `this+0x000000BC` `float laps_per_session` (read_write, DERIVED)
- `this+0x000000C0` `uint8_t session_state` (read_write, DERIVED)
- `this+0x000000C1` `uint8_t flag_byte` (read_write, GUESS)
- `this+0x000000C2` `uint8_t flag_byte_2` (read_write, GUESS)
- `this+0x000000CE` `uint8_t name_terminator` (write, GUESS)
- `this+0x000000D0` `float session_duration` (read_write, DERIVED)
- `this+0x000000D4` `float session_speed` (read_write, DERIVED)
- `this+0x000000D8` `float sentinel_float` (read_write, DERIVED)
- `this+0x000000F8` `void* scene_node_handle` (read, DERIVED)
- `this+0x00000100` `float ground_height` (read_write, DERIVED)
- `this+0x00000104` `uint8_t flag_byte_3` (read_write, GUESS)
- `this+0x00000108` `float waypoint_density` (read_write, DERIVED)
- `this+0x0000010C` `int waypoint_count` (read_write, DERIVED)
- `this+0x00000110` `float* waypoint_table` (read_write, DERIVED)
- `this+0x00000114` `int* waypoint_state` (read_write, DERIVED)
- `this+0x00000118` `float sentinel_float_2` (read_write, GUESS)
- `this+0x0000011C` `int session_lap_count` (read_write, GUESS)
- `this+0x00000120` `int dword_state` (read_write, GUESS)
- `this+0x00000190` `int16_t standings_sentinel` (read_write, GUESS)
- `this+0x00000192` `uint8_t standings_sentinel_byte` (read_write, GUESS)
- `this+0x00000194` `void* pit_in_polygon` (write, DERIVED)
- `this+0x00000198` `void* pit_out_polygon` (write, DERIVED)
- `this+0x0000019C` `void* finish_polygon` (write, DERIVED)
- `this+0x000001A0` `void* sector1_polygon` (write, DERIVED)
- `this+0x000001A4` `void* sector2_polygon` (write, DERIVED)

### TraceLog

Trace-log configuration object; holds the trace buffer setting and is initialized by TraceLogInit.

Methods: `0x004D7A00`

- `this+0x00000000` `int trace_buffer_setting` (write, DERIVED)

### FileResource

Open file/resource handle wrapper with locked state write/read-back and close; teardown used by wheel dynamics, telemetry and internal loaders.

Methods: `0x004D5840`

- `this+0x00000000` `void* handle` (read_write, DERIVED)

### FeedbackShiftRegister

Three-word feedback shift-register transform over input bytes, written to an owned file descriptor; the byte sink of the XOR file decoder.

Methods: `0x004D5BE0`

- `this+0x00000000` `void* fd` (read, DERIVED)
- `this+0x0000000C` `dword state_a` (read_write, DERIVED)
- `this+0x00000010` `dword state_b` (read_write, DERIVED)
- `this+0x00000014` `dword state_c` (read_write, DERIVED)
- `this+0x00000018` `dword accumulator` (read_write, DERIVED)

### TireBrandEntry

Small struct entry constructed with zero fields and -1 sentinels; built while TireBrandLoader assembles the tire brand table. Owner identity is inferred only from the caller.

Methods: `0x004D7020`

- `this+0x00000000` `dword field_0` (write, GUESS)
- `this+0x00000004` `dword sentinel_neg1` (write, GUESS)
- `this+0x0000000C` `dword field_c` (write, GUESS)
- `this+0x00000014` `dword field_14` (write, GUESS)
- `this+0x00000018` `dword field_18` (write, GUESS)
- `this+0x0000001C` `dword sentinel_neg1_2` (write, GUESS)

### TextureSurfaceContainer

Container of 36-byte texture-surface slots with an entry count and a capacity-prefixed block; teardown frees slots and the block header.

Methods: `0x004D7800`

- `this+0x00000000` `int entry_count` (read_write, DERIVED)
- `this+0x00000004` `void* block` (read_write, DERIVED)

### TrackReferenceFinder

Stores three track-reference slots (lower/upper value bounds and bracketing track-entry indices) built from the global track data array.

Methods: `0x004D7B00`

- `this+0x00000018` `float slot0_lower_bound` (read_write, DERIVED)
- `this+0x0000001C` `dword slot1_lower_bound` (write, DERIVED)

### FloatRangeClassifier

Wraps a value into a period and classifies it against a descending threshold table into a segment index; used by AI/session and pit-selection callers on the frame path.

Methods: `0x004D7C10`

- `this+0x00000024` `float wrap_period` (read, DERIVED)

### HudMessageDisplay

Per-tick HUD message/broadcast/visibility display manager; owns the active message index, broadcast index, HUD state index, message timer and audio-device handoff pointer/flag.

Methods: `0x004D8450`

- `this+0x00000000` `int active_message_index` (read_write, DERIVED)
- `this+0x00000004` `int broadcast_index` (read_write, DERIVED)
- `this+0x00000008` `int hud_state_index` (read_write, DERIVED)
- `this+0x000000D8` `void* audio_handoff_ptr` (read, DERIVED)
- `this+0x000000DC` `float message_timer` (read_write, DERIVED)
- `this+0x000000EC` `uint8_t audio_handoff_flag` (read, DERIVED)

### GuardedStateMachine

State machine with id-indexed state objects; transitions require existence, authorization, forward-or-same ordering and a clear conditional flag, then dispatch into the new state object.

Methods: `0x004D8760`

- `this+0x00000000` `int current_state_id` (read_write, DERIVED)
- `this+0x000000DC` `float transition_field` (write, DERIVED)

### IndexedObject

Small object holding a single stored index (this+0x4) that is conditionally updated; the guard array at this[a2+29] and the class identity are unknown.

Methods: `0x004D8840`

- `this+0x00000004` `int stored_index` (read_write, DERIVED)

### RaceContext

Race resource owner: normalized screen dimensions at +0xE4/+0xE8 drive both race-resource loading and HUD render-resource quad scaling. Both methods are invoked by RaceInitWithConstants.

Methods: `0x004D8AB0`, `0x004D8CF0`

- `this+0x000000E4` `float screen_width_norm` (read, DERIVED)
- `this+0x000000E8` `float screen_height_norm` (read, DERIVED)

### GridCarEntry

Starting-grid car entry rendered by the grid HUD: grid start position, qualifying time and (raw-source-only) driver/team name buffers.

Methods: `0x004D9690`

- `this+0x0000405C` `float qualifying_time` (read, DERIVED)
- `this+0x00004060` `int grid_start_position` (read, DERIVED)

## Compatibility contracts

- **XorTripleKeyFileDecode** — Files consumed by FileReadXORDecodeTripleKey are prefixed with a 4-byte little-endian size header; payload bytes are XOR-decoded with a cycling 3-key scheme (0x5C, 0xB4, 0x12) and streamed to the byte sink. A replacement must reproduce the decode and header emission.
- **RuntimeSubsystemRegistration** — Game_Setup registers vehicle/timing/pitstop subsystems through a two-callee registration API; timing and pitstop take a handler callback (TimerFrameRateThrottle, TrackTemperatureDisplay). A replacement must preserve registration order and callback semantics.
- **SessionTypeDispatch** — Steward restart dispatches on dword_7C56A4: 0 = practice (unlimited laps), 1-6 = qualifying/race with per-session time defaults, 7 = pre-race presentation. A replacement must honor these values and the per-session time defaults.
- **TrackReferenceSlotIndex** — TrackReferenceFinder scans the global track data array (dword_8ACFF0, count dword_8ACFEC, 8-byte entries, compared float at +4) to record bracketing min/max entry indices per reference slot. A replacement must reproduce the array layout.
- **HudRenderHandleSlots** — HUD render resources of types 1-5 are stored in fixed global handle slots (0x008AD398..0x008AD3A8); type 3 additionally owns a 96-byte struct (dword_8AD3AC) with a D3D texture. A replacement must preserve the slot/type contract.
- **StewardWaypointTableLayout** — The steward waypoint table (this+0x110) uses 8-byte entries with the position float at +4, count at +0x10C, and a parallel per-waypoint state array at +0x114. A replacement must reproduce the stride and the two-array pairing.

## Unresolved

- Offset 0xA8 is read as a float* by restart (RandomScaledValue argument) but written as a helicopter object pointer by Steward_Init; both methods are in the Steward class, so the field is either a polymorphic pointer or the two `this` objects are distinct. Conflict unresolved.
- GridCarEntry driver-name (0x46F8) and team-name (0x46B8) string buffers appear in the raw source only; no allowed field evidence reference exists, so no field entries were created for them.
- The sub-object pointer arrays in HudMessageDisplay based at this+16, this+116 and this+12 (indexed by this+0x0, this+0x4, this+0x8) are not exposed as packet fields; their exact layout is unresolved.
- The type-3 HUD struct is tracked by global dword_8AD3AC rather than an object field; ownership and lifetime are unclear.
- Semantics of sub_5599D0 / sub_559A00 registration and their handler-callback arguments are inferred, not confirmed.
- Meaning of the StringSplitLoop debug-gate arguments (scene path, line number) is not established.
- Ten restart-path globals (flt_59E468, dbl_59E9C8, flt_59F118, dbl_59FB48, dbl_5ACF00, byte_5C3300, asc_5D433C, aDDF, unk_8AC368, dword_8AD3B4) are packet-listed but absent from the raw source; likely data-region/jump-table neighbors. No operation attributed.
- sub_42D140 parameter semantics (5=practice, 0=qual/race, 2=UI phase, 3=init, 4=fallback) are inferred from usage, not CONFIRMED.
- Contracts of sub_4C29F0, sub_4D2DD0, sub_587DD0, sub_587ECE, sub_58850F, sub_53CBC0, sub_53CFE0 and the string-format helpers are not CONFIRMED.
- The per-waypoint state write in Steward_Init uses register v7, uninitialized in the decompiler output; the state-array index is ambiguous.
- Meaning of the waypoint array layout (8-byte stride, position at +4) and the ShortComputation_0f00 per-waypoint computation are not established.
- The track data entry layout (8-byte stride, compared value at +4) and the exact role of the bracketing index pairs in TrackReferenceFinder are inferred, not independently proven.
- The remaining TrackReferenceFinder slot offsets (this+24, this+28, this+32, index dwords) are reachable only through the raw source text.
- The 1056964608 (0.5f) value written to offset 0xDC and the a3 selector semantics in GuardedStateMachine are caller-defined.
- The meaning of the stored index at this+0x4 and the guard array element this[a2+29] in IndexedObject is unknown.
- Semantics of the sub_553650 vertex arguments (UV ordering, v4 sentinel values 0x80000000/-1), the +68 bit flag on the type-3 struct, and MaskedFieldSetter(0,192) on loaded resources are unresolved.
- Whether the four race resources (dword_8AD388..8AD394) are audio, render or other object types is unresolved; existing analysis labels them music/audio handles at DERIVED tier only.
- Global flt_59E440 is a zero-threshold global in the skeleton but its role in FloatRangeIndexLookup is unconfirmed.
- Global dword_5ACF34 is packet-listed but absent from the raw source of both HudMessageDisplay and GuardedStateMachine.
- The object pointed to by dword_5EA528 and its +52 state field (compared against 1) belong to an external object not described by this packet.
- The three underlying enum meanings of RotateThreeWayMode are unknown; whether -1 is consumed as an error or a no-op by the caller is not established.
- The name buffer at Steward+195 has no packet field entry; only its terminator byte at this+0xCE is evidenced.
