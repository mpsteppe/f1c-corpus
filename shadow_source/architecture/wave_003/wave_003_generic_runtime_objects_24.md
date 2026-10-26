# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Proposal for the generic_runtime_objects slice of Wave 3. The functions cluster into two halves around the special-effect lifecycle: (a) objects initialized/consumed during SpecialFX_Init (0x004CF070) — a reaction-effect config (constructor 0x004CA3E0, parser 0x004CA480 mapping reaction tokens to effect-type ids and building the 176-byte renderer sub-object, and deduplicating equality/merge 0x004CAED0), a reaction particle system (0x004CB120, 108-byte-strided particle arrays and weather-noise tables), an unknown effect-list constructor (0x004CDB90), a track surface material loader (0x004CDD80), an effect-field index binder (0x004CEF30), and the weather particle system update (0x004CFCC0); and (b) standalone runtime helpers — a three-field zero stub (0x004D0B00), a spatial distance accumulator (0x004D0B20), a slot-logo loader (0x004D1450), a scoring-gate selector (0x004D1AD0), a race-phase predicate (0x004D21D0), a progress-bar ring-buffer store (0x004D2260) and the post-race results file writer (0x004D24D0). Ownership is largely UNKNOWN at the IR level, so the classes are DERIVED/GUESS proposals; the packet's own naming (MaterialReactionEffectParser, SpecialFX, WeatherParticleSystem, ScoringGateSelector) is preserved where DERIVED.

## Function roles

- `0x004CA3E0` **ReactionEffectConfig** — Constructor/initializer of a special-effect reaction object: writes -1 sentinel markers at +0x0/+0x4, zeroes +0x8 and +0x40, zeroes the +0x50..+0x68 block, returns this. Called once from SpecialFX_Init (0x004CF070) during special-effect object setup.
- `0x004CA480` **ReactionEffectConfig** — Parses a reaction-effect configuration block: maps the 'reaction' token to an effect type id stored at this+4, parses scalar/range fields (scale/growth/growthvel/duration/asdenvelope/power/rampspeed/offsetvel), resolves a waypoint count, and builds a 176-byte renderer sub-object (texture/.MTS/.BMP names, vertex/pixel shader flags, particle flags, chroma/color, blend modes) at this+0x50.
- `0x004CAED0` **ReactionEffectConfig** — Deep structural equality between two reaction-effect configs (this vs a2): compares this+0x4 and the float block 0xC..0x4C, then the sub-object at +0x50; on full match copies a2's larger DWORD into this+0x58 and returns 1. Used by SpecialFX_Init during deduplication.
- `0x004CB120` **ReactionParticleSystem** — Reaction particle system initializer: caches physics constants into globals 0x5D3488..0x5D3494, applies a render-throttle shift to the particle count, builds a 'Reaction%02d' resource name, registers it via sub_559200, allocates a 108-byte-stride particle array plus a secondary index array, and for reaction type 13 fills weather wind-noise spread/direction tables.
- `0x004CDB90` **EffectListConstructor** — Constructor/field initializer: sets head pointer +0x0 to 0, index fields to -1, zeroes +0x8..+0x14, writes float 62.8319 to +0x18, zeroes +0x1C..+0x28 and the +0x2C byte, sets +0x30/+0x34/+0x38 to -1, zeroes +0x3C, memsets +0x40..0x60, clears the +0x60 byte and zeroes +0x64/+0x68; returns this. Called by SpecialFX_Init.
- `0x004CDD80` **TrackSurfaceMaterial** — Track surface material loader invoked from SpecialFX_Init: parses legal flag, base/wet friction, resistance, bump amplitude/wavelength, spring, damper, collision friction, sparks/scraping flags, sink depth and tire-surface sound IDs into a material struct, and resolves a material-name string into the same buffer.
- `0x004CEF30` **EffectFieldIndexBinder** — Walks the global list at dword_8AFE88 (count at list+16); for each index builds a name buffer, resolves it against `this`'s string list, retrieves the indexed element and stamps it with field key 4096. Called from SpecialFX_Init and VehicleGraphicsSceneLoader (0x004DFCE0).
- `0x004CFCC0` **WeatherParticleSystem** — Main weather particle system update: sorts drivers by distance, branches on the enable/packed flag into a wind-spawner path or a subsystem-only refresh, computes wind offset and visibility from camera/session data, and updates emitter children with rotation and scaling.
- `0x004D0B00` **ThreeFieldZeroStub** — Struct field zeroing stub: zeroes this+0x64/+0x6C/+0x74, then delegates a broader zero-init of the struct to sub_4A2220; returns this. Called by sub_4D0110 during a surrounding construction sequence.
- `0x004D0B20` **SpatialDistanceAccumulator** — Iterates a list of elements (count this+0x0, array this+0x4, stride 132); for each valid element (flag at +104) computes the squared 3D distance to the session reference position and, within 32 units, accumulates a2 into element+128 (conditionally subtracting +124) and calls sub_4A2840.
- `0x004D1450` **SlotLogoLoader** — Builds the season+track texture base path, opens a container via sub_53CBC0, and for up to 52 slot entries loads team/driver logo BMP names (Logo%s.bmp, Logo%s%s.bmp, PBOX%02d.bmp) through TextureAdjuster; falls back to the default directory when season/track globals are null.
- `0x004D1AD0` **ScoringGateSelector** — Scans a per-session gate array at this+0x110 (8-byte entries) over a computed index range and selects the highest-priority gate type with priority 3 > 8 > 2 > 0; returns 3 immediately on match, else the best accumulated value or 0.
- `0x004D21D0` **RacePhasePredicate** — Reads the race-phase global dword_7C56A8 and returns 0 when it is 0..4 (inclusive) and 1 otherwise. The LEGACY ABI name 'Race_Phase_Check' suggests a phase-membership predicate, not proven by the packet.
- `0x004D2260` **ProgressBarStore** — Stores two payload integers into the progress-bar ring buffer: reads the write pointer dword_8AAE64, bumps the count dword_83EE60 (guard < 1023) and advances by 432 bytes, loads session time dbl_8AFEA0, encodes a progress-bar event via ProgressBarEventEncode (4,21,8,255,time,1) and writes a1/a2 to buffer[2]/[3]; returns a1.
- `0x004D24D0` **RaceResultsFileWriter** — Writes a race-results text file: allocates a results path, ensures every intermediate directory exists, derives the filename (timestamped for multiplayer, fixed 'RaceResults.txt' for single-player session type 7), writes a metadata header, an optional multiplayer drive-aids block, and one row per finishing driver; frees the path buffer on exit.

## Proposed classes

### ReactionEffectConfig

Reaction special-effect configuration object. Holds the effect-type id at +0x4, scalar/range parameters in the +0xC..0x4C float block, a 176-byte renderer sub-object pointer at +0x50 and a merge priority/version dword at +0x58. Constructed, parsed and deep-compared by three functions that share this layout (the packet tags them UnknownObject / MaterialReactionEffectParser / SpecialFX; the grouping is a DERIVED proposal).

Methods: `0x004CA3E0`, `0x004CA480`, `0x004CAED0`

- `this+0x00000000` `int sentinel_marker` (write, GUESS)
- `this+0x00000004` `int effect_type_id` (read_write, DERIVED)
- `this+0x00000030` `float duration` (read_write, GUESS)
- `this+0x00000034` `float envelope_attack` (read_write, GUESS)
- `this+0x00000038` `float envelope_sustain` (read_write, GUESS)
- `this+0x0000003C` `float envelope_decay` (read_write, GUESS)
- `this+0x00000048` `float rampspeed` (read_write, GUESS)
- `this+0x00000050` `pointer renderer_sub_object` (read_write, DERIVED)
- `this+0x00000058` `int priority_or_version` (read_write, GUESS)
- `*(this+0x50)+0x00000020` `dword particle_flags` (read_write, GUESS)
- `*(this+0x50)+0x00000058` `dword vertex_shader_flags` (read_write, GUESS)
- `*(this+0x50)+0x0000005C` `dword pixel_shader_flags` (read_write, GUESS)
- `*(this+0x50)+0x00000060` `dword color_value` (read_write, GUESS)
- `*(this+0x50)+0x00000064` `word blend_mode_src` (read_write, GUESS)
- `*(this+0x50)+0x00000066` `word blend_mode_dst` (read_write, GUESS)
- `*(this+0x50)+0x00000068` `dword chroma_value` (read_write, GUESS)
- `*(this+0x50)+0x00000070` `char[] texture_filename_bmp` (write, GUESS)
- `*(this+0x50)+0x00000090` `char[] environment_map_bmp` (write, GUESS)

### WeatherParticleSystem

Weather particle system manager updated every frame from GamePostMainLoop and StateTriggerCheck. Owns a list of emitter children (+0x0/+0x4, 60-byte stride), a particle-subsystem array (+0x10/+0x14, 108-byte stride) and a wind-based particle spawner pointer at +0x1C.

Methods: `0x004CFCC0`

- `this+0x00000000` `int emitter_child_count` (read, DERIVED)
- `this+0x00000004` `array emitter_children` (read, DERIVED)
- `this+0x00000010` `int subsystem_count` (read, DERIVED)
- `this+0x00000014` `array subsystem_array` (read, DERIVED)
- `this+0x0000001C` `pointer spawner_ptr` (read, DERIVED)

### ReactionParticleSystem

Reaction particle system: builds a 'Reaction%02d' resource name at +0x50, registers it through sub_559200 (sub-object passed at +0x54), allocates a 108-byte-stride particle array at +0x5C with a secondary index array at +0x68, and for system type 13 (weather noise) fills shared wind-noise spread/direction tables.

Methods: `0x004CB120`

- `this+0x00000000` `int reaction_id` (read, GUESS)
- `this+0x00000004` `int system_type` (read, GUESS)
- `this+0x0000000C` `float param_a` (read, GUESS)
- `this+0x00000010` `float param_b` (read, GUESS)
- `this+0x00000014` `float param_c` (read, GUESS)
- `this+0x00000030` `float frame_interval` (read_write, GUESS)
- `this+0x00000034` `float param_d` (read, GUESS)
- `this+0x00000038` `float param_e` (read, GUESS)
- `this+0x0000003C` `float param_f` (read, GUESS)
- `this+0x00000040` `float inverse_interval` (write, GUESS)
- `this+0x00000050` `char[] name_buffer` (write, GUESS)
- `this+0x00000054` `pointer resource_sub_object` (read, GUESS)
- `this+0x00000058` `int frame_count` (read_write, GUESS)
- `this+0x0000005C` `pointer particle_array` (write, GUESS)
- `this+0x00000060` `int array_pad_a` (write, GUESS)
- `this+0x00000064` `int array_pad_b` (write, GUESS)
- `this+0x00000068` `pointer index_array` (write, GUESS)
- `*(this+0x50)+0x00000024` `int resource_frame_count` (write, GUESS)
- `*(this+0x50)+0x00000028` `float resource_param_a` (write, GUESS)
- `*(this+0x50)+0x0000002C` `float resource_param_b` (write, GUESS)
- `*(this+0x50)+0x00000030` `float resource_param_c` (write, GUESS)

### TrackSurfaceMaterial

Track surface material definition parsed from config entries. Holds base/wet friction (+0x8/+0xC), bump amplitude (+0x14) and bump wave frequency (+0x18), scraping flag (+0x2C), three tire-surface sound IDs (+0x30/+0x34/+0x38), legal flag (+0x60) and sink depth double (+0x64); a material-name string is resolved into the same buffer.

Methods: `0x004CDD80`

- `this+0x00000008` `float base_friction` (read_write, GUESS)
- `this+0x0000000C` `float wet_friction` (read_write, GUESS)
- `this+0x00000014` `float bump_amplitude` (write, GUESS)
- `this+0x00000018` `float bump_wave_frequency` (write, GUESS)
- `this+0x0000002C` `byte scraping_flag` (write, GUESS)
- `this+0x00000030` `int tire_sound_id_a` (write, GUESS)
- `this+0x00000034` `int tire_sound_id_b` (write, GUESS)
- `this+0x00000038` `int tire_sound_id_c` (write, GUESS)
- `this+0x00000060` `byte legal_flag` (write, GUESS)
- `this+0x00000064` `double sink_depth` (write, GUESS)

### EffectFieldIndexBinder

Binds named effect entries into an owning string-list object (`this`) while stamping each with a dual field key 4096. Walks the global list at dword_8AFE88 whose node carries an element count at +16; invoked from both SpecialFX_Init and VehicleGraphicsSceneLoader.

Methods: `0x004CEF30`


### EffectListConstructor

Constructor/initializer for an unknown effect-related object (only caller SpecialFX_Init). Sets a head pointer at +0x0, -1 index sentinels, a rotation constant 62.8319 (2*10*pi) at +0x18, and zeroes the remaining fields through +0x68.

Methods: `0x004CDB90`

- `this+0x00000000` `pointer head_ptr` (write, GUESS)
- `this+0x00000004` `int index_0` (write, GUESS)
- `this+0x00000018` `float rotation_constant` (write, GUESS)
- `this+0x0000002C` `byte flag_byte` (write, GUESS)
- `this+0x00000030` `int index_1` (write, GUESS)
- `this+0x00000034` `int index_2` (write, GUESS)
- `this+0x00000038` `int index_3` (write, GUESS)

### ThreeFieldZeroStub

Small struct-field zeroing stub: unconditionally zeroes this+0x64/+0x6C/+0x74, then delegates a broader zero-initialization of the remaining struct memory to sub_4A2220. Called by sub_4D0110 in a construction sequence.

Methods: `0x004D0B00`

- `this+0x00000064` `int field_a` (write, GUESS)
- `this+0x0000006C` `int field_b` (write, GUESS)
- `this+0x00000074` `int field_c` (write, GUESS)

### SpatialDistanceAccumulator

Per-frame spatial helper: iterates a 132-byte-stride element list (count +0x0, array +0x4), reads each valid element's position through TripleFieldQuery, and within a 32-unit squared-distance threshold accumulates a parameter into element+128 (conditionally subtracting element+124) before dispatching sub_4A2840.

Methods: `0x004D0B20`

- `this+0x00000000` `int element_count` (read, GUESS)
- `this+0x00000004` `array element_array` (read, GUESS)

### SlotLogoLoader

Loads team/driver logo textures: builds a season+track base path, opens a container through sub_53CBC0, and for up to 52 indexed string entries loads Logo%s.bmp / Logo%s%s.bmp / PBOX%02d.bmp variants via TextureAdjuster, with a default-directory fallback.

Methods: `0x004D1450`


### ScoringGateSelector

Selects the highest-priority scoring/penalty gate over an index range of a per-session gate array at this+0x110 (8-byte entries). Priority order 3 > 8 > 2 > 0; returns 3 immediately on match. Called by AISessionModeTransition and PitSelectionStateMachine.

Methods: `0x004D1AD0`

- `this+0x00000110` `array gate_array` (read, GUESS)

### RacePhasePredicate

Predicate over the global race-phase variable dword_7C56A8: returns 0 when the phase is 0..4 (inclusive) and 1 otherwise. The LEGACY ABI name 'Race_Phase_Check' suggests the semantic but the packet does not prove it.

Methods: `0x004D21D0`


### ProgressBarStore

Writes progress-bar events into a global ring buffer: reads the write pointer at dword_8AAE64, optionally bumps the count dword_83EE60 (guard < 1023) and advances by 432 bytes, then encodes a progress-bar event with the session time dbl_8AFEA0 and stores the two payload arguments.

Methods: `0x004D2260`


### RaceResultsFileWriter

Post-race results writer invoked by Steward_Post (0x004D4600). Creates the results directory tree, derives the output filename (timestamped for multiplayer, fixed 'RaceResults.txt' for single-player session type 7), and writes header metadata, an optional multiplayer drive-aids block and one row per finishing driver from the results records.

Methods: `0x004D24D0`


## Compatibility contracts

- **ReactionTokenEnumContract** — The 'reaction' config token string maps to an effect type id stored at this+0x4: dust=0, whitesmoke=1, bluesmoke=2, blacksmoke=3, flames=4, spray=5, skid=6, softskid=7, wetskid=8, groove=9, wetgroove=10, particle=11, spark=12, rain=13. Unknown tokens take the warning path.
- **RacePhaseGlobalContract** — Global race-phase dword_7C56A8: membership in {0,1,2,3,4} yields return value 0 from the predicate (0x004D21D0), any other value yields 1. The phase-to-meaning mapping itself is not evidenced.
- **ScoringGatePriorityContract** — Gate selection priority over the this+0x110 array entries: 3 outranks 8 outranks 2; 0 means none selected. Range bounds come from ShortComputation_7bf0 (start) and ArrayAccessAt0xcIndex4 (inclusive end).
- **RaceResultsFileContract** — Single-player races write a fixed 'RaceResults.txt' only when session type dword_7C56A4 == 7; multiplayer writes a timestamped '%d_%0.2d_%0.2d_%0.2d_%0.2d_%0.2d.txt' filename and additionally emits a local-settings/drive-aids block. The results directory is created under the base directory (dword_5EC438 or the default byte_5EA438).
- **ProgressBarRingBufferContract** — Progress-bar events are appended to a global ring buffer: the write pointer lives at dword_8AAE64, entries advance by 432 bytes, the entry count at dword_83EE60 is incremented only while below 1023, and each event is encoded with the session time dbl_8AFEA0 via ProgressBarEventEncode.
- **SessionManagerDispatchContract** — Both the weather update (0x004CFCC0) and the distance accumulator (0x004D0B20) obtain camera/session reference data by virtual dispatch through the SessionManager global dword_5EA510 (VirtualDispatchHelper 0x0040C870). A replacement must preserve that dispatcher surface.
- **ParticleSubsystemStrideContract** — Weather particle subsystems and reaction particle arrays use a 108-byte element stride; emitter children use a 60-byte stride; the distance-accumulator list uses a 132-byte stride. Any replacement iterating these arrays must preserve the strides.
- **DriverResultsRecordLayoutContract** — Per-driver results records (reached via the dword_7C54F0 vehicle pointer array, count dword_5C329C) expose: lap-count dword at +8, status dword at +48, best time float at +104, race time float at +132, total-fines float at +164, qualifying time float at +16476 and position dword at +16480. Values are DERIVED from read/write context.

## Unresolved

- Most owners are UNKNOWN at the function-IR level; the class grouping above is a DERIVED/GUESS proposal, not confirmed identity. In particular the packet tags 0x004CA3E0 UnknownObject, 0x004CA480 MaterialReactionEffectParser and 0x004CAED0 SpecialFX, yet all three share the same this+0x4/+0x50/+0x58 layout; the ReactionEffectConfig grouping follows that shared layout, not the divergent tags.
- The 176-byte renderer sub-object (base *(this+0x50)) is only partially covered by named fields: chroma at +104 and the blend-mode words at +100/+102 have no dedicated field evidence (they are described from the pixel/destblend/srcblend operations only).
- The two sub-object strcmp comparisons in equalsAndMergeGreater (0x004CAED0) operate at offsets absent from the extracted field evidence; their exact offsets are unproven.
- The return-value contract of ReactionEffectConfigParser (0x004CA480: presence of the final 'srcblend' token) with caller SpecialFX_Init (0x004CF070) is not resolved.
- Read-only float globals flagged by deterministic facts but absent from the raw bodies (flt_59E43C, flt_59E440, flt_59E46C, flt_59E478, flt_59E7F8, flt_59E8B4, flt_59E8EC, flt_59E920, flt_59E9C0, flt_59EAE0, flt_5ACE9C, flt_5ACEA0, flt_5ACEA4, flt_5ACED4, flt_5ACEE4, dword_5CC79C, byte_5CC7A0, aMts, byte_5CD5F0, dword_8AD3B4, dword_8AFE64, dword_8AFE88, dword_8AD264) may belong to another function or a stale xref merge.
- sub_559200 (callee 0x00559200) semantics are unknown beyond returning truthy on the successful registration path; the resource sub-object passed as `this + 84` (offset 0x54) has no field entry in the packet.
- sub_53CBC0 (container open) vs the PhysicsObjectLinkedListRemoval teardown relationship in loadSlotLogos is inferred, not evidenced; whether a non-zero return is an error code is unproven.
- The weather wind-noise spread/direction tables written into the flt_8ACAA4 / unk_8AC828 regions are semantically inferred from layout only; the packet marks those addresses read-only (rw=R) while the function writes through them.
- The dword_8AFE88 list node +16 count field and the 4096 field-setter key in IndexedEffectFieldSetter (0x004CEF30) have no field evidence refs; their semantics derive only from callee names and call context.
- The meaning of the 0..4 phase values in sub_4D21D0 (Race_Phase_Check) and which membership yields 0 vs 1 is not evidenced; the ABI name is LEGACY.
- ProgressBarEventEncode parameters (4, 21, 8, 255, 1) semantics are not derivable from the packet; the ring-buffer entry is written even when the capacity guard (count < 1023) fails.
- The driver results record offsets in WriteRaceResultsFile (0x004D24D0) are DERIVED from use context only; no struct definition is available. The many globals at 0x7CE5D0-0x7D0E98 listed for this function do not appear in the raw text and likely derive from the skeleton prose layer.
- In F_3DDistanceCheckAccumulate (0x004D0B20) the decompiler carry/borrow flags from the squared-distance compare gate the subtraction of element+124 from the accumulator; the exact conditional semantics are unresolved, as are the meanings of element fields +4/+104/+124/+128 and sub_4A2840.
- The waypoint-count resolution (aNumwaypoints vs sub_587ECE fallback, stored at this+0x58) and the material-name normalization grammar in TrackSurfaceMaterialLoader are DERIVED from code, not confirmed.
