# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Proposes a conservative architecture for 29 generic runtime helper functions. Small GUESS-level classes group functions where packet evidence shows same-receiver thiscall chains (UI render family), shared math roles (Vector3Math), consistent gating on the shared 0x32BC mode counter (VehicleGateDispatcher), or a single dominating behavior (VehicleSurfaceEffectSystem, HudIntensityController). All owners are UNKNOWN at packet level; every field offset is grounded in the packet's raw source, but all semantic names are interpretive. Two cross-cutting contradictions are flagged: offsets 0x34EC/0x34F0/0x34F4 are labeled both half-extents and render-offsets, and the 0x32BC field appears in four receivers whose common ownership is unproven. Eighteen float/jump-table globals flagged by the fact tables but absent from the raw source are recorded in unresolved_evidence_refs rather than asserted.

## Function roles

- `0x004DB110` **VTableDelegateDispatcher** — Trivial thiscall delegation wrapper that invokes VTableDispatchWithFieldClear on the receiver pointer and returns the constant 0, discarding the callee result.
- `0x004DC340` **UiRenderObject** — Alignment selector 0..8 computes an anchored position from base point and extent into two output pointers via the jump table jpt_4DC350; case 0 returns a6, cases 1..8 return a7, default returns the raw selector.
- `0x004DCA80` **UiRenderObject** — Renders a four-corner quad by calling sub_553650 four times with modes 0..3 from the position/extent/delta fields and the parameter id; gated on the enable flag at this+0.
- `0x004DCDA0` **UiRenderObject** — Scales two float arguments by the global multipliers dword_5D6D60 and dword_5D6D64, converts them to integers via CRTFtol, and delegates to TwoFieldSetterUpdate; invoked by UICursorSelectionRectangleRenderWithInterpolatio.
- `0x004DCEE0` **UiRenderObject** — Converts three float arguments to integers (a4 directly, a2/a3 scaled by dword_5D6D60 and dword_5D6D64) and delegates to PositionComputationWithAlignment with the pass-through a5; aligned-position twin of FloatToIntConversionDispatch.
- `0x004DD3A0` **UiRenderObject** — Resolves a font string (argument a7, else this+0x28, else the global byte_5EA438 fallback), queries surface dimensions via SurfaceSizeQuery, and writes width/height through non-null output pointers.
- `0x004DD9F0` **Vector3Math** — Computes the normalized face normal of a triangle via the cross product of the two edge vectors; returns 0 on success and -1 on a degenerate zero-area triangle whose squared cross-product length is at most 0.0.
- `0x004DE5D0` **IndexedStructTable** — Resolves the address of an indexed element: reads the element-array base from the pointer at a1+8 dereferenced at +12, reads a 16-bit index from the table at a1+2*a2, and returns array base plus 48*index.
- `0x004DF0A0` **SortedRenderRecordList** — Builds a 36-byte float record (marker 2 at index 0, scalar argument at index 1, zero tail) and, when the dword at this+0x18 is non-zero, inserts it via SortedArrayInsertWithLRUEviction; otherwise returns the zero read from the gate.
- `0x004DFB00` **ZeroInitStateObject** — Constructor/initializer for a 112-byte object: zeroes 27 of the 28 dword fields spanning 0x0..0x6C and writes the float 0.25 into the dword at offset 0x18; returns 0.
- `0x004E0DB0` **VehicleResetStateInitializer** — Bulk one-time lazy initialization of multiple substructure blocks via LazyInitCallback: two singleton blocks at dword offsets 377 and 394, a 4-iteration loop over 296-dword-strided block pairs, and an 8-iteration loop over 68-dword-strided blocks starting at dword offset 411; invoked from vehicle reset paths.
- `0x004E16C0` **FieldForwardDataObject** — Field-read delegate that forwards three DWORDs (this+0x8/0xC/0x10) and three floats (this+0x14/0x18/0x1C) to sub_54B4D0 and returns its result; called by VehicleTelemetryPositionAccumulator.
- `0x004E21D0` **PackedColorArrayObject** — Packs an ARGB color from an alpha parameter (CRTFtol(a2*254.0+0.5) shifted into the top byte with 0xFFFFFF low bits), writes it into the offset 0x18 field of every element of the packed color-data array, and sets dirty flag bit 0x10000000 on the flag word at a1+0x14.
- `0x004E2CA0` **SceneGraphScaleNode** — Propagates a new scale value to scene-graph children when it changes: computes the old-to-new scale ratio, applies velocity scaling on the primary child node and on a secondary child node when present; called by VehicleRespawnReset and sub_4F0D20.
- `0x004E3090` **SkinningVertexOutputObject** — Deforms a run of skinned vertices through a bone rotation frame built from direction/origin fields, blends each vertex toward its transformed position by a per-vertex weight, and clears the output-buffer dirty flag; gated by a three-level enable check on the bone frame, the bone enable byte and the output buffer.
- `0x004EB430` **VehicleSurfaceEffectSystem** — Per-frame vehicle surface-effect dispatcher invoked from MainGameTickUpdate: resets per-frame accumulators, drains pending effect slots, clears the global contact count, iterates the spatial grid, computes contact forces, normalizes contact data in the global arrays, dispatches by contact type through ModeDispatchWithSwitch and UICameraModeDispatchWithVehicleDataRead, scales effect intensity, and sets the 0x3FF0 surface flag.
- `0x004EC050` **SixFieldDataObject** — Copies six parameters into the six consecutive dword fields at offsets 0x0..0x14 and returns parameter a6; structural twin of CollisionFaceVerticesGather, called from VehicleContactForceAccumulation on the frame path.
- `0x004ED750` **Vector3Math** — 3D vector cross product a1 x a2 stored into the three-float output vector a3, returning a3; pure math helper with no guards, globals or nested calls.
- `0x004EE230` **BrakeBiasStateObject** — Computes a brake-ratio override (ratio cubed times a cooling-effectiveness factor, halved) and substitutes it for each throttle/brake reference channel whose value equals the -789.0 sentinel; other reference values pass through unchanged.
- `0x004EF680` **RideHeightComputeObject** — Computes a ride-height delta: zeroes the first dword of the output, sets the fourth slot to the track Y coordinate this[0x74C], and writes the average pitch component (this[0x3688]-this[0x3708]+this[0x3590]-this[0x3610])*0.5 into the second slot; returns the output pointer.
- `0x004F1AA0` **VehicleGateDispatcher** — Contact/collision gate: when the enable flag at this+0x32BC is zero returns the default value byte_7C9080; otherwise returns true only when the velocity at this+0x3444 lies in [2,4] and either the FPU condition flags are clear or DistanceComparison is false.
- `0x004F1B50` **VehicleGateDispatcher** — Sets the global camera view mode dword_7C74F8 (2 on the enabled path, 0 on the disable path) and, when the internal state flag at this+0x32BC is set, clears the three render-offset fields 0x34EC/0x34F0/0x34F4; used during pit-stop camera transitions.
- `0x004F1C00` **VehicleGateDispatcher** — Gated on the flag at this+0x32BC: when zero, calls VisualStateChange(&dbl_7C7428, a2, 1) and returns its low-byte result; otherwise returns the flag value unchanged.
- `0x004F6F00` **ZeroInitSmallObject** — Constructor/initializer that zeroes the first 0x20 bytes of an unknown object with mixed byte/dword clears (bytes at 0x0 and 0x10, dwords at 0x4/0x8/0xC and 0x14/0x18/0x1C); returns the this pointer and is invoked by sub_4F6F20.
- `0x004F88A0` **HudIntensityController** — Computes a clamped ratio of sub-struct floats (obj+0x39A0 over obj+0x39A4), mixes in two noise-table samples and a random pick, then calls HUDElementConfig to configure an indexed HUD/sound element.
- `0x004F89A0` **HudIntensityController** — Randomized sound/HUD trigger variant: two clamped ratios via RatioComputationWithClamping, two noise samples from the weather-noise table, an LCG pick selecting HUD base index 17/16/15, then HUDElementConfig writes both computed intensities.
- `0x004F9200` **GuardedConfigAccessor** — Guard-conditional accessor: when the global dword_8AFE68 is set, resolves the object for a1 via sub_55BDE0 and returns the dword at offset 16 of that object; otherwise returns the literal default 16.
- `0x004F9240` **CoordinateTableSearcher** — Multi-table coordinate search: snapshots the current table index from dword_8AFE6C, returns -1 when ShortComputation_9150 reports no tables, then iterates table indices via UtilityFunction_9160 and entry indices up to ConditionalDispatch_9190, reading four coordinate values per entry with GlobalGuardedFieldReader; returns the matching entry index or -1.
- `0x004F9B20` **StateFlagPredicate** — Pure predicate that reads the global dword_8AFE7C and returns true when it equals zero; no side effects. Called by CircularBufferRingAdvance, RenderSurfaceFillCopy and StateFlagComputation.

## Proposed classes

### UiRenderObject

UI/texture rendering descriptor: quad rendering from position/extent/delta fields, float-to-integer position updates that re-render through the quad path, font fallback and surface-size querying, and the alignment selector helper that anchors positions. Membership is inferred from the same-receiver thiscall chain FloatToIntConversionDispatch -> TwoFieldSetterUpdate -> RenderQuadCorners and FloatToIntChainDelegate -> PositionComputationWithAlignment -> RenderQuadCorners; the class identity itself is a guess.

Methods: `0x004DC340`, `0x004DCA80`, `0x004DCDA0`, `0x004DCEE0`, `0x004DD3A0`

- `this+0x00000000` `int enable_flag` (read, DERIVED)
- `this+0x00000008` `float position_x` (read, DERIVED)
- `this+0x0000000C` `float position_y` (read, DERIVED)
- `this+0x00000010` `float position_z` (read, DERIVED)
- `this+0x00000014` `float width_extent` (read, DERIVED)
- `this+0x00000018` `float height_extent` (read, DERIVED)
- `this+0x0000001C` `int parameter_id` (read, DERIVED)
- `this+0x00000020` `float delta_x` (read, DERIVED)
- `this+0x00000024` `float delta_y` (read, DERIVED)
- `this+0x00000028` `void* font_pointer` (read, GUESS)

### Vector3Math

Pure 3D vector math helpers: normalized triangle normal from cross product of edge vectors, and the raw 3-float cross product a1 x a2. Both read/write three consecutive float components at offsets 0x0/0x4/0x8 which the packet notes are output-vector components, not input class members.

Methods: `0x004DD9F0`, `0x004ED750`

- `this+0x00000000` `float component_x` (read_write, DERIVED)
- `this+0x00000004` `float component_y` (read_write, DERIVED)
- `this+0x00000008` `float component_z` (read_write, DERIVED)

### IndexedStructTable

Resolves the address of a fixed-size element (stride 48) within an indexed structure table by combining a double-dereferenced array base with a 16-bit table index; used by sub_4DE610 and sub_4DF110. Record layout is unevidenced.

Methods: `0x004DE5D0`


### SortedRenderRecordList

Builds a 36-byte float record and conditionally inserts it into a sorted list with LRU eviction; the insert is gated on the flag at this+0x18. The record marker and list semantics are DERIVED from the callee name, not an independently verified contract.

Methods: `0x004DF0A0`

- `this+0x00000018` `int insert_enable_flag` (read, DERIVED)

### ZeroInitStateObject

Constructor body for a 112-byte object: zeroes 27 of 28 dword fields spanning 0x0..0x6C and writes the float 0.25 into the dword at offset 0x18. The 0.25f coefficient is likely consumed elsewhere; object identity unknown.

Methods: `0x004DFB00`

- `this+0x00000000` `dword field_00` (write, DERIVED)
- `this+0x00000004` `dword field_04` (write, DERIVED)
- `this+0x00000008` `dword field_08` (write, DERIVED)
- `this+0x0000000C` `dword field_0C` (write, DERIVED)
- `this+0x00000010` `dword field_10` (write, DERIVED)
- `this+0x00000014` `dword field_14` (write, DERIVED)
- `this+0x00000018` `float coefficient_quarter` (write, DERIVED)
- `this+0x0000001C` `dword field_1C` (write, DERIVED)
- `this+0x00000020` `dword field_20` (write, DERIVED)
- `this+0x00000024` `dword field_24` (write, DERIVED)
- `this+0x00000028` `dword field_28` (write, DERIVED)
- `this+0x0000002C` `dword field_2C` (write, DERIVED)
- `this+0x00000030` `dword field_30` (write, DERIVED)
- `this+0x00000034` `dword field_34` (write, DERIVED)
- `this+0x00000038` `dword field_38` (write, DERIVED)
- `this+0x0000003C` `dword field_3C` (write, DERIVED)
- `this+0x00000040` `dword field_40` (write, DERIVED)
- `this+0x00000044` `dword field_44` (write, DERIVED)
- `this+0x00000048` `dword field_48` (write, DERIVED)
- `this+0x0000004C` `dword field_4C` (write, DERIVED)
- `this+0x00000050` `dword field_50` (write, DERIVED)
- `this+0x00000054` `dword field_54` (write, DERIVED)
- `this+0x00000058` `dword field_58` (write, DERIVED)
- `this+0x0000005C` `dword field_5C` (write, DERIVED)
- `this+0x00000060` `dword field_60` (write, DERIVED)
- `this+0x00000064` `dword field_64` (write, DERIVED)
- `this+0x00000068` `dword field_68` (write, DERIVED)
- `this+0x0000006C` `dword field_6C` (write, DERIVED)

### VehicleResetStateInitializer

Bulk one-time lazy initialization of many substructure blocks of a single owning object, invoked from vehicle reset paths (VehicleRespawnReset and VehicleResetClear). Block offsets (dword indices 377, 394, 98+-68, 98+296k, 411+68k) are grounded only in raw pointer arithmetic.

Methods: `0x004E0DB0`


### FieldForwardDataObject

Small data-binding object whose six fields (three DWORDs then three floats, offsets 0x8..0x1C) are forwarded to sub_54B4D0 by a field-read delegate; used by the vehicle telemetry path.

Methods: `0x004E16C0`

- `this+0x00000008` `int first_dword` (read, DERIVED)
- `this+0x0000000C` `int second_dword` (read, DERIVED)
- `this+0x00000010` `int third_dword` (read, DERIVED)
- `this+0x00000014` `float first_float` (read, DERIVED)
- `this+0x00000018` `float second_float` (read, DERIVED)
- `this+0x0000001C` `float third_float` (read, DERIVED)

### PackedColorArrayObject

Owner of a packed color-data array whose element count and index lookup go through PackedArrayTotalSize and PackedArrayIndexLookup; a color-alpha update packs an ARGB value into every element and marks the update via flag bit 0x10000000 on the word at this+0x14.

Methods: `0x004E21D0`

- `this+0x00000014` `dword dirty_flag_word` (read_write, DERIVED)

### SceneGraphScaleNode

Scene-graph node that stores the current scale at this+0x970 and holds a child-node pointer at this+0x4; on a scale change it propagates the old-to-new ratio to the primary child and, when present, a secondary child read from the primary child's +0x44 field.

Methods: `0x004E2CA0`

- `this+0x00000004` `void* scene_graph_child` (read, DERIVED)
- `this+0x00000970` `float current_scale` (read_write, DERIVED)
- `*(this+0x4)+0x00000044` `void* secondary_child` (read, DERIVED)

### SkinningVertexOutputObject

Output side of the skinning path: holds the output vertex buffer at this+0x8E4 and the buffer header at this+0x8F8 whose dirty flag is cleared after the deform pass.

Methods: `0x004E3090`

- `this+0x000008E4` `void* output_buffer_ptr` (read, DERIVED)
- `this+0x000008F8` `void* output_buffer_header` (read, DERIVED)

### VehicleSurfaceEffectSystem

Per-frame vehicle surface-effect and contact dispatcher: holds per-frame accumulators, the active-effect slot list, the body rotation matrix and position, contact damping and reference-position state, pending-effect slots, and surface flags. Dispatches contact types 0..6 and 9..10 into effect, camera and telemetry consumers.

Methods: `0x004EB430`

- `this+0x000000A4` `float accumulator_a` (write, DERIVED)
- `this+0x000000A8` `float scale_factor` (write, DERIVED)
- `this+0x000000AC` `float accumulator_c` (write, DERIVED)
- `this+0x000000B0` `float accumulator_d` (write, DERIVED)
- `this+0x000000B4` `float accumulator_e` (write, DERIVED)
- `this+0x000006E8` `void* sprite_object` (read, DERIVED)
- `this+0x00001070` `int active_effects_flag` (read_write, DERIVED)
- `this+0x00001074` `EffectSlot[17] active_effect_slots` (write, GUESS)
- `this+0x000032BC` `int mode_counter` (read, DERIVED)
- `this+0x000034AC` `float speed_state` (read, DERIVED)
- `this+0x000034B0` `float rotation_m00` (read, DERIVED)
- `this+0x000034B4` `float rotation_m01` (read, DERIVED)
- `this+0x000034B8` `float rotation_m02` (read, DERIVED)
- `this+0x000034BC` `float rotation_m10` (read, DERIVED)
- `this+0x000034C0` `float rotation_m11` (read, DERIVED)
- `this+0x000034C4` `float rotation_m12` (read, DERIVED)
- `this+0x000034C8` `float rotation_m20` (read, DERIVED)
- `this+0x000034CC` `float rotation_m21` (read, DERIVED)
- `this+0x000034D0` `float rotation_m22` (read, DERIVED)
- `this+0x000034D4` `float body_position_x` (read, DERIVED)
- `this+0x000034D8` `float body_position_y` (read, DERIVED)
- `this+0x000034DC` `float body_position_z` (read, DERIVED)
- `this+0x000034EC` `float extent_x` (read, GUESS)
- `this+0x000034F0` `float extent_y` (read, GUESS)
- `this+0x000034F4` `float extent_z` (read, GUESS)
- `this+0x00003514` `float contact_damping` (read, DERIVED)
- `this+0x00003A9C` `void* reference_position_ptr` (read, DERIVED)
- `this+0x00003B75` `byte surface_touched_flag` (write, GUESS)
- `this+0x00003B78` `byte pending_slot_byte0` (read, GUESS)
- `this+0x00003B79` `byte pending_slot_byte1` (read, GUESS)
- `this+0x00003B88` `dword pending_slot_dword0` (read, GUESS)
- `this+0x00003B8C` `dword pending_slot_dword1` (read, GUESS)
- `this+0x00003B90` `dword pending_slot_dword2` (read, GUESS)
- `this+0x00003FF0` `byte surface_dot_flag` (write, GUESS)
- `obj+0x000048BC` `int external_object_flag_word` (read, DERIVED)
- `*(this+0x3A9C)+0x00000000` `float reference_position_x` (read, DERIVED)
- `*(this+0x3A9C)+0x00000004` `float reference_position_y` (read, DERIVED)
- `*(this+0x3A9C)+0x00000008` `float reference_position_z` (read, DERIVED)

### SixFieldDataObject

Small object whose six consecutive dword fields are written by F_6FieldStructInit from six call parameters; called from VehicleContactForceAccumulation. Semantic meaning of each value is unknown.

Methods: `0x004EC050`

- `this+0x00000000` `dword field_00` (write, DERIVED)
- `this+0x00000004` `dword field_04` (write, DERIVED)
- `this+0x00000008` `dword field_08` (write, DERIVED)
- `this+0x0000000C` `dword field_0C` (write, DERIVED)
- `this+0x00000010` `dword field_10` (write, DERIVED)
- `this+0x00000014` `dword field_14` (write, DERIVED)

### BrakeBiasStateObject

Holds brake-bias inputs and three throttle/brake reference channels; ThrottleBrakeOverride computes a cubic brake-ratio override scaled by a cooling factor and substitutes it for any reference channel still holding the -789.0 sentinel.

Methods: `0x004EE230`

- `this+0x00003994` `float brake_bias_numerator` (read, DERIVED)
- `this+0x00003998` `float brake_bias_denominator` (read, DERIVED)
- `this+0x00003570` `float brake_cooling_factor` (read, DERIVED)
- `this+0x0000077C` `float output_channel_0` (write, DERIVED)
- `this+0x00000790` `float output_channel_1` (write, DERIVED)
- `this+0x000007A4` `float output_channel_2` (write, DERIVED)
- `this+0x00003D48` `float reference_channel_0` (read, DERIVED)
- `this+0x00003D4C` `float reference_channel_1` (read, DERIVED)
- `this+0x00003D50` `float reference_channel_2` (read, DERIVED)

### RideHeightComputeObject

Holds per-corner ride-height offsets and the track Y coordinate; RideHeightDeltaCompute combines them into a small output vector for the suspension/render path.

Methods: `0x004EF680`

- `this+0x0000074C` `float track_y` (read, DERIVED)
- `this+0x00003590` `float ride_height_corner_a` (read, DERIVED)
- `this+0x00003610` `float ride_height_corner_b` (read, DERIVED)
- `this+0x00003688` `float ride_height_corner_c` (read, DERIVED)
- `this+0x00003708` `float ride_height_corner_d` (read, DERIVED)

### VehicleGateDispatcher

Family of dispatchers all gated on the mode counter at this+0x32BC: VelocityThresholdCheck returns a shared default or a velocity/distance conjunction, CameraModeSetter sets the global camera view mode and clears render offsets, and ConditionalBufferCall forwards to VisualStateChange when the counter is zero. Common ownership of the four receivers is DERIVED from usage, not proven.

Methods: `0x004F1AA0`, `0x004F1B50`, `0x004F1C00`

- `this+0x000032BC` `int mode_counter` (read, DERIVED)
- `this+0x00003444` `float velocity` (read, DERIVED)
- `this+0x000034EC` `float render_offset_0` (write, GUESS)
- `this+0x000034F0` `float render_offset_1` (write, GUESS)
- `this+0x000034F4` `float render_offset_2` (write, GUESS)

### ZeroInitSmallObject

Constructor body that zeroes the first 0x20 bytes of an unknown object using mixed byte (0x0, 0x10) and dword (0x4/0x8/0xC, 0x14/0x18/0x1C) clears; returns the this pointer.

Methods: `0x004F6F00`

- `this+0x00000000` `byte flag_byte` (write, DERIVED)
- `this+0x00000004` `dword dword_field_04` (write, DERIVED)
- `this+0x00000008` `dword dword_field_08` (write, DERIVED)
- `this+0x0000000C` `dword dword_field_0C` (write, DERIVED)
- `this+0x00000010` `byte flag_byte_10` (write, DERIVED)
- `this+0x00000014` `dword dword_field_14` (write, DERIVED)
- `this+0x00000018` `dword dword_field_18` (write, DERIVED)
- `this+0x0000001C` `dword dword_field_1C` (write, DERIVED)

### HudIntensityController

Per-frame HUD/sound intensity computation: reads a sub-struct pointer at this+0x0, takes a clamped ratio of the sub-struct floats at obj+0x39A0 and obj+0x39A4, mixes weather-noise samples from the global table with an LCG pick, and configures an indexed HUD element via HUDElementConfig.

Methods: `0x004F88A0`, `0x004F89A0`

- `this+0x00000000` `void* sub_struct_ptr` (read, DERIVED)
- `obj+0x000039A0` `float intensity_numerator` (read, DERIVED)
- `obj+0x000039A4` `float intensity_denominator` (read, DERIVED)

### GuardedConfigAccessor

Guard-conditional global accessor: reads a dword at offset 16 of an object resolved via sub_55BDE0 only when the global dword_8AFE68 is set, otherwise returning the literal default 16.

Methods: `0x004F9200`


### CoordinateTableSearcher

Searches multiple coordinate tables for a 4-tuple match: manages the current table index global dword_8AFE6C, iterates tables through the table-selection helper chain and entries through the entry-count helper, reading four coordinates per entry and returning the matching entry index or -1.

Methods: `0x004F9240`


### StateFlagPredicate

Pure predicate over the global dword_8AFE7C returning true when it equals zero; the state-flag interpretation is inferred from a caller name and is DERIVED, not proven.

Methods: `0x004F9B20`


### VTableDelegateDispatcher

Trivial thiscall wrapper that forwards the receiver to VTableDispatchWithFieldClear and returns the constant 0; the actual dispatch and field-clear semantics live in the callee.

Methods: `0x004DB110`


## Compatibility contracts

- **AlignmentSelectorReturnContract** — AlignmentPositionSwitch accepts an alignment selector in 0..8 and writes anchored coordinates through two output pointers; it returns the a6 pointer for selector 0, the a7 pointer for selectors 1..8, and the raw selector value for the default branch. A replacement must reproduce the per-case write order and return convention to keep callers such as ScaledTextureRender and TextRenderDispatcher working.
- **TriangleNormalContract** — ComputeTriangleNormal writes a normalized face normal into the 3-float output pointer and returns 0 for a valid triangle; for a degenerate triangle whose squared cross-product length is at most 0.0 it returns -1. Callers (AnimationPlaybackSequence 0x0044ACB0, sub_4DE610, sub_4DF110) rely on the 0/-1 return convention.
- **BrakeReferenceSentinelContract** — ThrottleBrakeOverride replaces any throttle/brake reference channel equal to the -789.0 sentinel stored at global 0x005AD1F8 with the computed brake-bias override value; any other reference value passes through unchanged into the three output channels.
- **CameraViewModeGlobalContract** — The pit-stop camera path stores the active view mode in the global dword_7C74F8 (2 on the enabled path, 0 on the disable path) and, when the internal mode flag at this+0x32BC is set, clears the three render-offset fields 0x34EC/0x34F0/0x34F4 to 0.
- **VehicleSurfaceEffectFrameOrder** — VehicleSurfaceEffectUpdateDispatch (invoked from MainGameTickUpdate 0x0042C690) runs once per frame: it resets per-frame accumulators, drains four pending effect slots, clears the contact count global 0x008ADAF8, iterates the spatial grid 0x008AB710, accumulates and normalizes contact data in the global arrays 0x008AD400/0x008AD404/0x008AD428/0x008AD42C, dispatches by contact type, and sets the 0x3FF0 surface flag from a body-to-contact dot threshold. A replacement must preserve this ordering and the global array/count layout.
- **FontFallbackContract** — TwoOutputPassthrough resolves its font argument as a7, else this+0x28, else the global byte_5EA438 fallback, then queries the surface size through SurfaceSizeQuery and writes width and height through non-null output pointers.
- **GateReturnDefaultContract** — The gate-dispatcher family conditions on the mode counter at offset 0x32BC: VelocityThresholdCheck returns the shared default byte_7C9080 when the counter is zero, and ConditionalBufferCall returns the counter unchanged when it is non-zero instead of dispatching to VisualStateChange.

## Unresolved

- All 29 packet functions declare an UnknownObject/UNKNOWN owner; no class in this proposal is proven to match a real C++ type. Class names and member groupings are GUESS-level synthesis over packet evidence, and the subsystem boundary is the pipeline's deterministic generic_runtime_objects bucket.
- Field offsets 0x34EC/0x34F0/0x34F4 are read as half-extents by VehicleSurfaceEffectUpdateDispatch but cleared as render-offset fields by CameraModeSetter. The packet supplies two different labels for the same offsets; either they are two roles of one field on a shared object or two unrelated objects coincidentally sharing offsets. Not resolvable from this packet.
- The mode counter at offset 0x32BC appears in VehicleSurfaceEffectUpdateDispatch, VelocityThresholdCheck, CameraModeSetter and ConditionalBufferCall with consistent gating semantics, but common ownership of the four receivers is DERIVED from usage, not proven. Equal offsets on unrelated this pointers do not prove identical fields or classes.
- Eighteen float/jump-table globals flagged by the fact tables never appear in the raw source bodies: the contact-dispatch jump tables at 0x004EBC20/0x004EBC30/0x004EBC3C and the float literals 0x0059E43C, 0x0059E440, 0x0059E444, 0x0059E448, 0x0059E450, 0x0059E478, 0x0059E7EC, 0x0059E7F8, 0x0059E800, 0x0059E868, 0x0059E874, 0x0059E908, 0x005ACEC4, 0x005AD1E0, 0x005AD1E4, 0x005AD1E8. They likely back inlined constants, but which literal each supplies cannot be tied from this packet, so they are recorded in unresolved_evidence_refs rather than asserted.
- The 36-byte record built by ConditionalRenderCall (marker 2 at index 0, scalar at index 1, zero tail) and the semantics of SortedArrayInsertWithLRUEviction come from the callee name and a DERIVED cluster prelabel, not an independently verified contract.
- The element stride 48 in IndexedStructFieldCompute implies a fixed-size record array, but the record layout, the pointer double-dereference at a1+8 then +12, and the 16-bit index table semantics are unevidenced.
- The global multipliers dword_5D6D60 / dword_5D6D64 (possibly screen or resolution scale factors) and the producer of the -789.0 sentinel value are not established by this packet.
- ComputeTriangleNormal and F_3DCrossProduct both store three floats at offsets 0x0/0x4/0x8; the packet notes these are output-vector components in the raw source, not members of an input class. The Vector3Math grouping is GUESS.
- The reference position pointer at this+0x3A9C is dereferenced unconditionally after the null-guarded PositionChangeMonitor call; the monitor's guarantee of a non-null pointer is not provable from this packet.
- The sub-struct behind *this in HudIntensityController (ratio fields at obj+0x39A0/0x39A4 and extra data at obj+12) has an unknown type, and the HUD index mapping (12/13/14 or 15/16/17) to concrete elements is unknown.
- MultiSystemStructInitializer's block offsets (dword indices 377, 394, 98+-68, 98+296k, 411+68k) are grounded only in raw pointer arithmetic; the semantic identity of each substructure block is unresolved.
- Several packets list read-only float globals for functions whose raw bodies contain no direct global reference (for example the 0.0/1.0 literals in SkinningVertexDeform), so constant folding of those globals is plausible but not directly evidenced.
- The C0/C2 FPU condition-flag source feeding VelocityThresholdCheck is an earlier float compare not present in this packet, and byte_7C9080 is a shared default-return value whose wider meaning is external to this packet.
