# RuntimeObjectServices

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

This packet assembles generic runtime objects around three families. (1) A circular particle-slot buffer: CircularBufferSlotAlloc (0x004CB540) advances a wrap-around write index (this+0x60, capacity this+0x58) into a 108-byte-strided slot buffer (this+0x5C), registers claimed slots in a tracking array (this+0x68, count this+0x64); MultiFieldFree (0x004CB4F0) tears the same structure down (frees this+0x5C and this+0x68 buffers via a 4-byte header adjustment and removes the this+0x54 list node); ParticleColorFadeRenderer (0x004CD8D0) reads the same count/array to write a packed alpha/color into every element's pixel attributes and delegates to sub_4CB5E0 on a zero fade. (2) Particle/HUD render helpers sharing PixelWriteToTextureBuffer (0x00558E10) and vertex emission: ParticleEffectBillboardQuadSetup (0x004CC500), RenderBoundingBoxCorners (0x004CC700), plus the pure math helper AABBOverlapTestWithSlidingResponse (0x004CBF50) and the indexed handle-table dispatch IndexedRenderDispatch (0x004D8A30) -> QuadRenderWithColor (0x004D90D0) in the HUD path. (3) Race/session services: PitProximityDetectionAndNotification (0x004D1730) with its record-lookup twin ClampedScaledIndexLookup (0x004D1D40) share this+0x108/0x10C/0x110 and the ring buffer anchored by dword_8AAE64/dword_83EE60; SessionTelemetryDispatcher (0x004D3740/0x004D37B0) reads flag property 2048 via FlagPropertyGetter, addresses the vehicle arrays unk_5EC6D8/unk_5F070C with a 4656-float (18624-byte) stride, dispatches AI commands via AICommandMessageQueueDispatcher and clears its this+0x14 buffer entry; race render resources are allocated by sub_4D88D0 and released by BatchVTableDispatchAndCleanup (0x004D8950) over the same this+0x10 (25-slot), this+0x74 (3-slot), this+0xC and this+0xD8 slots. UI text layout helpers ComputeCenteredTextPosition (0x004D7F20) and ComputeSizeSubtractedPosition (0x004D7F60) are near twins on the UITextRenderWithScale path, gated by SwitchBasedGlobalLookup. Constructor ObjectInitWithVtable (0x004D4840) installs the vtable off_5ACF08; DelegateWithField4 (0x004D7FE0) and AudioParticleEnvelopeTick (0x004D7FF0) are vtable-chain slots of an unknown dispatcher; StateBlockInitializer (0x004DA820) and RaceEndProgressionGate (0x004DAE00) round out the set. Ownership of every object is LOW; class boundaries here are DERIVED proposals over the packet's shared-field and shared-callee evidence.

## Function roles

- `0x004CB4F0` **ParticleSlotBuffer** — Particle-slot teardown: frees the two heap buffers (this+0x5C, this+0x68, each preceded by a 4-byte header) via FreeWrapper_7bcf and removes the doubly-linked-list node at this+0x54, returning the removal result
- `0x004CB540` **ParticleSlotBuffer** — Circular particle-buffer slot allocation: advances the wrap-around write index (this+0x60, capacity this+0x58), addresses the chosen 108-byte slot in the buffer (this+0x5C), links and tracks it (count this+0x64, array this+0x68), resets it via sub_558A30 and returns the slot pointer
- `0x004CBF50` **OrientedBoxSegmentQuery** — Pure geometry helper: line-segment vs oriented-box overlap test that slides the target endpoint onto the box surface along the first axis when the segment crosses the box
- `0x004CC500` **ParticleQuadRenderer** — Billboard quad vertex writer for a particle sprite: builds a camera-facing unit perpendicular from the particle axis and facing vector, scales it by half the particle size, and writes the four quad corners to the texture buffer via PixelWriteToTextureBuffer
- `0x004CC700` **ParticleQuadRenderer** — Render-context helper (stdcall): combines the box center at this+0x2C/0x30/0x34 with the two argument vectors to emit the four bounding-box corners (ids 0..3) into the texture buffer via PixelWriteToTextureBuffer
- `0x004CD8D0` **ParticleSlotBuffer** — Particle color-fade renderer: when (int)(a2*254.0) is non-zero optionally triggers AIWaypointPathCheckerRenderer and writes the packed alpha/color into all four pixel attributes of every element in the this+0x68 array (count this+0x64); otherwise delegates to sub_4CB5E0
- `0x004CDBF0` **StringTableLookupService** — String-table lookup: copies the base path (*this or the byte_5EA438 fallback) into a local buffer, parses lines/tokens via sub_5897CA with the asc_5D251C delimiter, and returns 1 when a token equals the target a2 (sub_587C20)
- `0x004CE380` **FloatConstantScan** — Constant-table scan on the per-frame tick path (invoked by sub_4EE2D0): iterates entry pointers from this+0x40 (count this+0x3C), selects a candidate float by the entry+4 type id (1 -> a2[10], 5 -> a2[12], else a2[11]), and returns 1 on the first non-zero candidate
- `0x004CF040` **StridedElementIterationDriver** — Strided element iteration: calls sub_4CB5E0 once per element of a 108-byte-strided array (base this+0x14, count this+0x10) and returns the count
- `0x004D1180` **RaceSessionRenderGate** — Session-gated render dispatch: when dword_7C56A4 == 7 and dword_7C56A8 in {2,3,4} forwards the three arguments to SingleFunctionDispatch_10e0 and returns 1, otherwise to RenderCallWithGuard and returns 0
- `0x004D1730` **PitProximityTracker** — Per-frame pit-proximity pass over the active vehicle grid (dword_7C54F0, count dword_5C329C): resets the this+0x110 pit-state array, computes an approach threshold per vehicle, writes pit-state 2 through DistanceProjectionCalc/CRTFtol into the scaled index, raises PitSelectionStateMachine transitions (this+0x114 diff) and logs heartbeat/progress events into the dword_8AAE64/dword_83EE60 ring buffer
- `0x004D1D40` **PitProximityTracker** — Clamped scaled index lookup into the pit-state record array: converts an input scaled by this+0x108 to an index via CRTFtol, clamps to [0, this+0x10C-1], and returns the DWORD at (this+0x110) + 8*index
- `0x004D3740` **SessionTelemetryDispatcher** — Periodic timing dispatch: reads flag property 2048 via FlagPropertyGetter as the vehicle selector, dispatches LapSplitTimeEvent on the unk_5F070C slot and AICommandMessageQueueDispatcher on the unk_5EC6D8 slot (4656-float stride), then clears the this+0x14 buffer entry
- `0x004D37B0` **SessionTelemetryDispatcher** — Session/telemetry update for the current vehicle slot: reads flag 2048 twice (slot index and session-state), dispatches AI commands 5 (active) or 4 (transition/pit) on the vehicle at unk_5EC6D8 + 18624*index, updates the telemetry substate, runs pfnAPC/StateResetOnCondition for the player slot, and rate-limits a progress-bar event to every 3 seconds
- `0x004D4840` **VtableObjectConstructor** — Object constructor: installs the class dispatch vtable off_5ACF08 at this+0x0 and zero-initializes the dword fields at this+0x4, this+0x8 and this+0xC
- `0x004D7F20` **HudTextLayoutHelper** — UI text-layout helper: resolves the owner via SwitchBasedGlobalLookup and, when non-null, measures the text via sub_5531F0 and stores the horizontally centered position a2 - a4/2 into *a3
- `0x004D7F60` **HudTextLayoutHelper** — UI text-layout helper, sibling of 0x004D7F20: measures the text via sub_5531F0 and stores a2 - a4 (extent minus measured size) into *a3
- `0x004D7FE0` **FieldForwardingDelegate** — Thin delegating vtable slot: reads the value at this+0x4 and returns sub_4D8A30(this+0x4) unchanged; dispatched by VTableDispatchChain_7e00
- `0x004D7FF0` **PhaseEnvelopeTicker** — Vtable-chain envelope tick: advances the phase accumulator at this[3] by dbl_8AFE98, normalizes it (CRTFtol, 60.0 wrap), and evaluates a six-segment amplitude envelope calling TimerClockFormat per segment
- `0x004D88D0` **RaceRenderResourcePool** — Race render resource allocation (race init, called from RaceInitWithConstants 0x004D8220): builds the 25-slot object array at this+0x10 gated by IDTypePermissionMatrix(index, dword_7D0410), a 3-slot sub-object array (this+0x74), one conditional object at this+0xC (RangeCheck_93e0) and a fixed-node allocator at this+0xD8
- `0x004D8950` **RaceRenderResourcePool** — Batch release counterpart to 0x004D88D0: walks the 25-slot (this+0x10) and 3-slot (this+0x74) pointer arrays plus the single objects at this+0xC and this+0xD8, dispatching vtable slot 0 on each non-null object with argument 1 and nulling the slot
- `0x004D8A30` **HudRenderDispatch** — Indexed render dispatch over a 5-entry handle table (dword_8AD398..flt_8AD3A8, jump table jpt_4D8A40): indices 1..5 load a global handle, index 5 also renders a colored quad via QuadRenderWithColor, and the shared completion path calls sub_553700 on the device global dword_8B8DC8 when both are non-null
- `0x004D90D0` **HudRenderDispatch** — HUD quad render helper for sub_4D8A30: emits four vertices (triangle strip) via sub_553650, skipped when a2 == 0.0; base Y is 0.0 for slot this+0x8 == -1 else 140.0, scaled from this+0xE4 (width) and this+0xE8 (height) against 1280.0/50.0
- `0x004DA820` **StateBlock** — State-block initialization: zeroes dwords this+0x10/0x18/0x1C/0x20/0x24 and byte this+0x28, sets this+0x14 to 60.0f, and returns 0
- `0x004DAE00` **RaceEndProgressionGate** — Race-end progression gate: returns 1 when the this+0x14 expiration timer has elapsed, 0 while the this+0x1C hold timer is positive, otherwise combines the current vehicle finish state (dword_5F073C[4656*index] via sub_4D1B50(dword_8ACEE0,0)) with the finished count this+0x20 and the player DSQ flag (dword_7C54E8+16484); unconditional 1 when this+0x20 == dword_5C329C

## Proposed classes

### ParticleSlotBuffer

Owns a circular buffer of 108-byte-strided particle slots with a wrap-around write index, a slot tracking array, capacity/count bookkeeping, a doubly-linked list node, and the teardown and color-fade render passes over its elements.

Methods: `0x004CB540`, `0x004CB4F0`, `0x004CD8D0`

- `this+0x00000054` `void* list_node_ptr` (read_write, DERIVED)
- `this+0x00000058` `int slot_capacity` (read, DERIVED)
- `this+0x0000005C` `void* slot_buffer_base` (read_write, DERIVED)
- `this+0x00000060` `int write_index` (read_write, DERIVED)
- `this+0x00000064` `int slot_count` (read_write, DERIVED)
- `this+0x00000068` `void** slot_tracking_array` (read_write, DERIVED)

### ParticleQuadRenderer

Emits particle-sprite quad geometry into the shared texture buffer through PixelWriteToTextureBuffer: camera-facing billboards for a particle and debug/particle bounding-box corners for a render context.

Methods: `0x004CC500`, `0x004CC700`

- `this+0x00000000` `void* render_handle` (read, DERIVED)
- `this+0x00000010` `float particle_size` (read, DERIVED)
- `this+0x0000002C` `float box_center_x` (read, DERIVED)
- `this+0x00000030` `float box_center_y` (read, DERIVED)
- `this+0x00000034` `float box_center_z` (read, DERIVED)

### OrientedBoxSegmentQuery

Pure geometry helper performing line-segment versus oriented-box overlap tests with a sliding endpoint response; operates on a box descriptor passed by argument (center, orientation matrix, local extents), not on its own fields.

Methods: `0x004CBF50`


### StridedElementIterationDriver

Iterates a caller-owned array of 108-byte-strided elements and invokes sub_4CB5E0 once per element; stores the element count at this+0x10 and the first element pointer at this+0x14.

Methods: `0x004CF040`

- `this+0x00000010` `int element_count` (read, DERIVED)
- `this+0x00000014` `void* element_array_base` (read, DERIVED)

### FloatConstantScan

Scans a table of constant entries (this+0x40, count this+0x3C) on the per-frame tick path, selecting a candidate float from the argument by a per-entry type id, and reports whether any selected value is non-zero.

Methods: `0x004CE380`

- `this+0x0000003C` `int entry_count` (read, DERIVED)
- `this+0x00000040` `void** entry_array` (read, DERIVED)

### StringTableLookupService

Searches a key=value string table for a token equal to a target string, using a default directory fallback when the base-path pointer is null.

Methods: `0x004CDBF0`

- `this+0x00000000` `char* base_path_ptr` (read, DERIVED)

### RaceSessionRenderGate

Selects between a race-dispatch render call and a generic guarded render call based on the session-type and phase globals; observable behavior differs by return value and callee.

Methods: `0x004D1180`


### PitProximityTracker

Runs the per-frame pit-proximity pass over the active vehicle grid, maintains the current/previous pit-state record arrays with scaled index lookup, and emits ring-buffered progress events and pit-selection state transitions.

Methods: `0x004D1730`, `0x004D1D40`

- `this+0x000000B0` `float clamp_bias` (read, DERIVED)
- `this+0x000000D4` `float approach_threshold_scale` (read, DERIVED)
- `this+0x00000108` `float index_scale_factor` (read, DERIVED)
- `this+0x0000010C` `int entry_count` (read, DERIVED)
- `this+0x00000110` `uint32_t* pit_state_array` (read_write, DERIVED)
- `this+0x00000114` `uint32_t* previous_state_array` (read_write, DERIVED)
- `this+0x00000118` `double last_log_timestamp` (read_write, DERIVED)

### SessionTelemetryDispatcher

Dispatches per-vehicle session/telemetry events on a timer or state change: reads flag property 2048 to select a vehicle slot, addresses the per-vehicle arrays unk_5EC6D8/unk_5F070C, queues AI commands, and clears its buffer entry.

Methods: `0x004D3740`, `0x004D37B0`

- `this+0x00000014` `void* buffer_entry` (read_write, DERIVED)

### VtableObjectConstructor

Base-object construction for a class with a dispatch table: installs the vtable pointer at this+0x0 and zero-initializes the following three dword members.

Methods: `0x004D4840`

- `this+0x00000000` `void* vtable_ptr` (write, DERIVED)
- `this+0x00000004` `uint32_t member_04` (write, DERIVED)
- `this+0x00000008` `uint32_t member_08` (write, DERIVED)
- `this+0x0000000C` `uint32_t member_0C` (write, DERIVED)

### HudTextLayoutHelper

Measures text via sub_5531F0 and computes an output position (centered or extent-minus-size) for the scaled UI text render path, gated on a global object lookup.

Methods: `0x004D7F20`, `0x004D7F60`


### FieldForwardingDelegate

Thin vtable-chain delegate that forwards the value at this+0x4 to sub_4D8A30 unchanged.

Methods: `0x004D7FE0`

- `this+0x00000004` `void* forwarded_value` (read, DERIVED)

### PhaseEnvelopeTicker

Advances a phase accumulator and evaluates a six-segment amplitude envelope over a 4.0-unit cycle, emitting amplitude values through TimerClockFormat.

Methods: `0x004D7FF0`

- `this+0x0000000C` `double phase_accumulator` (read_write, DERIVED)

### RaceRenderResourcePool

Allocates and batch-releases a fixed set of render objects: a 25-slot pointer array (this+0x10), a 3-slot pointer array (this+0x74), one conditional single object (this+0xC) and a fixed-node allocator (this+0xD8); release dispatches vtable slot 0 on each object.

Methods: `0x004D88D0`, `0x004D8950`

- `this+0x0000000C` `void* single_object` (read_write, DERIVED)
- `this+0x00000010` `void** object_array_25` (read_write, DERIVED)
- `this+0x00000074` `void** object_array_3` (read_write, DERIVED)
- `this+0x000000D8` `void* fixed_node_allocator` (read_write, DERIVED)

### HudRenderDispatch

HUD quad rendering: an indexed dispatch over a 5-entry global handle table that renders a colored quad on index 5 and emits the quad vertices through sub_553650 on the device.

Methods: `0x004D8A30`, `0x004D90D0`

- `this+0x00000008` `int participant_slot` (read, DERIVED)
- `this+0x000000E4` `float quad_width_factor` (read, DERIVED)
- `this+0x000000E8` `float quad_height_factor` (read, DERIVED)

### StateBlock

A small state block whose initializer zeroes its fields and sets a default rate/scale value of 60.0f; the meaning of the 60.0f default and the object's callers are unknown.

Methods: `0x004DA820`

- `this+0x00000010` `uint32_t member_10` (write, DERIVED)
- `this+0x00000014` `float rate_default_60` (write, DERIVED)
- `this+0x00000018` `uint32_t member_18` (write, DERIVED)
- `this+0x0000001C` `uint32_t member_1C` (write, DERIVED)
- `this+0x00000020` `uint32_t member_20` (write, DERIVED)
- `this+0x00000024` `uint32_t member_24` (write, DERIVED)
- `this+0x00000028` `uint8_t member_28` (write, DERIVED)

### RaceEndProgressionGate

Race-end flow control combining timer and finish-state conditions: expiration and hold timers plus a finished-count threshold against the vehicle count and the player DSQ flag.

Methods: `0x004DAE00`

- `this+0x00000014` `float expiration_timer` (read, DERIVED)
- `this+0x0000001C` `float hold_timer` (read, DERIVED)
- `this+0x00000020` `int finished_count` (read, DERIVED)

## Compatibility contracts

- **CircularParticleSlotAllocation** — A replacement must maintain the circular particle-slot buffer with a 108-byte slot stride, where capacity (this+0x58), buffer base (this+0x5C), write index (this+0x60), allocation count (this+0x64) and slot tracking array (this+0x68) satisfy the allocation and teardown contract; the free path must honor the 4-byte allocation header preceding the this+0x5C buffer (freed at pointer - 4).
- **PitProximityStateArray** — A replacement must keep the 8-byte-record pit-state array at this+0x110 (count this+0x10C) indexed by distance scaled with this+0x108 and clamped to [0, count-1], the previous-state array at this+0x114 for transition detection, and pit-state value 2 marking 'approaching pit'.
- **TelemetryRingBuffer** — A replacement must preserve the progress-bar event ring buffer anchored by dword_8AAE64/dword_83EE60 with 432-byte entries capped at 1023, fed by ProgressBarEventEncode; the pit-proximity pass emits heartbeat events (...,4,10,...) and per-vehicle packed events (...,4,11,...), and the session telemetry path emits (...,3,7,...) events rate-limited to every 3 seconds.
- **SessionGatedRenderDispatch** — A replacement must reproduce the session-gated render dispatch: when dword_7C56A4 == 7 and dword_7C56A8 is 2, 3 or 4 the render call takes the race-dispatch branch and returns 1; otherwise it takes the generic guarded render branch and returns 0.
- **VehicleArrayAddressing** — A replacement must address the per-vehicle slot arrays unk_5EC6D8 and unk_5F070C with a 4656-float (18624-byte) stride using a slot index read from flag property 2048 via FlagPropertyGetter, and dispatch AI commands through AICommandMessageQueueDispatcher with command ids 4 (transition) and 5 (active).

## Unresolved

- Twenty-three globals are flagged as read by packet facts but never appear in the raw decompiled bodies of these functions: the 0x0059Exxx physics/format constant family (flt_59E43C, flt_59E440, flt_59E450, flt_59E46C, flt_59E478, flt_59E5FC, flt_59E670, flt_59E7E8, flt_59E7EC, flt_59E800, flt_59E828, flt_59E8A4, flt_59E8E4, flt_59E8EC, flt_59E940, flt_59E9C0, flt_59F118) plus flt_5ACCE8, flt_5ACEE8, flt_5ACF40, flt_5ACF44, dword_8AFE88 and dword_8AD298; their association with these functions is suspect and they are listed in unresolved_evidence_refs rather than adopted into the model.
- The 4-byte allocation header preceding the this+0x5C buffer (freed at pointer - 4) has an unknown layout; the counter/flag fields this+0x58 and this+0x64 cleared before each free are semantically unresolved.
- Vehicle-struct relative offsets used by PitProximityDetectionAndNotification and RaceEndProgressionGate (+16484 state, +15016 pit/session data, +13388, +13560/+13564/+13568 velocity, +12 distance, player +16480/+16484) lie outside this object's field table; their meanings come only from raw source text.
- The telemetry ring-buffer entry layout (432-byte stride, 1023 cap, word/dword packing in ProgressBarEventEncode) is not defined by this packet.
- Equal offsets on distinct this bases are reused across classes and do not prove common ownership: this+0x04 (VtableObjectConstructor zeroed member vs FieldForwardingDelegate forwarded value), this+0x0C (zeroed member vs RaceRenderResourcePool single object vs PhaseEnvelopeTicker phase accumulator), this+0x10 (StateBlock zeroed member vs RaceRenderResourcePool object array vs StridedElementIterationDriver count vs ParticleQuadRenderer particle size), this+0x14 (SessionTelemetryDispatcher buffer entry vs StateBlock 60.0f default vs RaceEndProgressionGate expiration timer), this+0x60 (ParticleSlotBuffer write index vs ParticleQuadRenderer render parameter).
- ParticleQuadRenderer grouping (billboard setup + bounding-box corners) rests on a shared PixelWriteToTextureBuffer callee and shared emitter callers; the two methods do not share this-fields, so the class boundary is GUESS.
- sub_4CB5E0's behavior (element initialization/update) is unknown; it is both the fallback of ParticleColorFadeRenderer and the per-element callee of RepeatedCallLoop, but whether both operate on the same element type is unproven.
- Whether ParticleSlotBuffer.slot_count (this+0x64) is a plain counter or a link token is inferred from its use both as the value written into the slot link word and as the tracking-array index.
- The type-id semantics in FloatComparisonWithConstantsTable (type 1 -> a2[10], type 5 -> a2[12], else a2[11]) and the meaning of the a2 float fields are inferred from prior particle analysis, not proven in this scope.
- The vtable dispatch slots DelegateWithField4 and AudioParticleEnvelopeTick are targets of VTableDispatchChain_7e00, but the owner class, the second TimerClockFormat argument (1/0) and the 60.0 wrap divisor are unknown; the audio/particle 'envelope' interpretation derives from legacy naming.
- The structural-twin relationship of ClampedScaledIndexLookup to a ring-buffer access sibling is DERIVED from a cluster prelabel and not independently confirmed.
- The three sub-object slots at this+0x74 are written by the allocator but have no packet field entries; the conditional creation of the this+0xC object via RangeCheck_93e0 is unresolved.
- The session-state enumeration at flag 2048 (value -11 = transition/pit vs otherwise = active) and the flag-property 2048 identity are not independently confirmed.
- The handle-table globals dword_8AD398..flt_8AD3A8 are presumed contiguous but only the individual reads are evidenced; flt_8AD3A8 doubles as handle and color argument; sub_553700's render contract is unestablished.
- The a2 == 0.0 path of QuadRenderWithColor returns an uninitialized value in the decompiled form; the mapping of geometry constants (0.0, 140.0, 1280.0, 50.0) to the flagged read globals cannot be determined from this packet.
- RaceEndProgressionGate's caller sub_4DA840 and frame-path membership are recorded in packet prose but the caller reference is not in allowed_evidence_refs, so it is not cited here.
- The exact meaning of the a1/third argument inside the sub_5531F0 text-measure calls and whether the ComputeSizeSubtractedPosition result is right-aligned or a remaining size are not distinguishable from the raw source.
