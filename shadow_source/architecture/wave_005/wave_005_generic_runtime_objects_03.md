# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `GUESS`

Thirty-two validated functions grouped into eighteen GUESS-level runtime-object classes. The largest group is a family of seventeen adjacent, identical-body config path-registration delegates (normalize trailing backslash, then StringCopyWithBufferRealloc) all called by ConfigIniParser (0x00421CD0); whether they are distinct call sites of one helper or duplicated inline copies is unresolved. The remaining functions split across championship-points comparison, AI flag writing, setup-param lookup, setup-value formatting, container teardown, track-spline extrapolation, numeric tolerance and plane-fit helpers, a physics solver dispatch, a lookup-weighted accumulator splitter, D3D render-state reset, spatial/mesh rotation-structure initialization, shadow-volume extrusion, color packing, triangle intersection, and a registry value query. All owners are UNKNOWN; class identities and field meanings are GUESS proposals only.

## Function roles

- `0x0041FDB0` **ChampionshipPointsComparator** — Compare the receiver's accumulated championship points against a provider-resolved object's points and return true when the difference is at least 16; falls back to a global default string when the provider returns null.
- `0x004218D0` **ConfigPathRegistrationDelegates** — Normalize trailing backslash on the path string then return the result of StringCopyWithBufferRealloc; config path-string registration delegate called by ConfigIniParser.
- `0x004218F0` **ConfigPathRegistrationDelegates** — Normalize trailing backslash on the path string then return the result of StringCopyWithBufferRealloc; config path-string registration delegate called by ConfigIniParser.
- `0x00421910` **ConfigPathRegistrationDelegates** — Normalize trailing backslash on the path string then return the result of StringCopyWithBufferRealloc; config path-string registration delegate called by ConfigIniParser.
- `0x00421950` **ConfigPathRegistrationDelegates** — Normalize trailing backslash on the path string then return the result of StringCopyWithBufferRealloc; config path-string registration delegate called by ConfigIniParser.
- `0x00421990` **ConfigPathRegistrationDelegates** — Normalize trailing backslash on the path string then return the result of StringCopyWithBufferRealloc; config path-string registration delegate called by ConfigIniParser.
- `0x004219B0` **ConfigPathRegistrationDelegates** — Normalize trailing backslash on the path string then return the result of StringCopyWithBufferRealloc; config path-string registration delegate called by ConfigIniParser.
- `0x004219D0` **ConfigPathRegistrationDelegates** — Normalize trailing backslash on the path string then return the result of StringCopyWithBufferRealloc; config path-string registration delegate called by ConfigIniParser.
- `0x004219F0` **ConfigPathRegistrationDelegates** — Normalize trailing backslash on the path string then return the result of StringCopyWithBufferRealloc; config path-string registration delegate called by ConfigIniParser.
- `0x00421A10` **ConfigPathRegistrationDelegates** — Normalize trailing backslash on the path string then return the result of StringCopyWithBufferRealloc; config path-string registration delegate called by ConfigIniParser.
- `0x00421A30` **ConfigPathRegistrationDelegates** — Normalize trailing backslash on the path string then return the result of StringCopyWithBufferRealloc; config path-string registration delegate called by ConfigIniParser.
- `0x00421A50` **ConfigPathRegistrationDelegates** — Normalize trailing backslash on the path string then return the result of StringCopyWithBufferRealloc; config path-string registration delegate called by ConfigIniParser.
- `0x00421A70` **ConfigPathRegistrationDelegates** — Normalize trailing backslash on the path string then return the result of StringCopyWithBufferRealloc; config path-string registration delegate called by ConfigIniParser.
- `0x00421A90` **ConfigPathRegistrationDelegates** — Normalize trailing backslash on the path string then return the result of StringCopyWithBufferRealloc; config path-string registration delegate called by ConfigIniParser.
- `0x00421AB0` **ConfigPathRegistrationDelegates** — Normalize trailing backslash on the path string then return the result of StringCopyWithBufferRealloc; config path-string registration delegate called by ConfigIniParser.
- `0x00421AD0` **ConfigPathRegistrationDelegates** — Normalize trailing backslash on the path string then return the result of StringCopyWithBufferRealloc; config path-string registration delegate called by ConfigIniParser.
- `0x00421AF0` **ConfigPathRegistrationDelegates** — Normalize trailing backslash on the path string then return the result of StringCopyWithBufferRealloc; config path-string registration delegate called by ConfigIniParser.
- `0x0042AC90` **AIStateFlagWrapper** — Compute an AI-state flag value as the global threshold dword_5EA2CC plus the object dword at byte offset 0x4, write it via AIStateFlagSetter, and return the setter's result.
- `0x0042AEB0` **SetupParamResolver** — Linear keyed lookup over five two-dword setup-parameter records starting at byte offset 0x4144; return the paired second dword on match or -1. Called by AICollision.
- `0x0042F2F0` **SetupValueFormatter** — Dispatch vehicle setup-value formatting by value type id (angle, pressure with unit-system branch, length with wheel-type offset, degrees/seconds, single-float, integer count) into 64-byte-strided rows.
- `0x00431BE0` **RuntimeObjectContainer** — Teardown and free a container reachable through global dword_7C73E0: free two singly-linked lists, zero list-head field groups, conditionally free member pointers, then free the container.
- `0x004349A0` **TrackSplineExtrapolator** — Build track-spline extrapolation data: sample consecutive spline points, store midpoints, extrapolate two extension segments, apply fixed offsets, and hand the buffer to sub_457F90 with element count dword_5C329C + 5.
- `0x00435290` **NumericToleranceComparator** — Epsilon-tolerance double comparison: return true when the absolute difference of two doubles is below 0.000000001. Used by the suspension wheel dynamics solver.
- `0x00435390` **CategoryScoringState** — Initialize a 25-dword scoring-state object: field 0x0 = -1 sentinel, field 0x10 = 1072693248, all other fields zeroed; return this. Called once from SuspensionSetupSectionReader.
- `0x004366E0` **BestFitPlaneFitter** — Fit a least-squares plane to a point cloud (28-byte stride, doubles at +0/+8/+16) by accumulating normal-equation sums and solving a 3x4 augmented system via sub_5677B0; write a normalized fallback plane on failed solve.
- `0x0043B930` **PhysicsSolverDispatch** — Dispatch a solver operation-type id to one of six physics helpers (delta-tracking, quadratic spring at offsets 0x1838/0x189C, constraint forces, quadratic, force-torque, spring-damper); unrecognized ids return immediately.
- `0x0043EC00` **RandomWeightedForceSplitter** — Split an input scalar into two lookup-weighted accumulator contributions using a 256-entry table indexed by a wrapping byte counter; both weighted paths always execute.
- `0x004482D0` **D3DRenderState** — Reset/init a D3D render-state struct: zero the handle, release the object pointer at +0x4 through vtable slot 0 when non-null, zero +0x8/+0xC/+0x10, set the state mask at +0x18 to 0xFF7FFFFF.
- `0x00448510` **SpatialMeshRotationState** — Initialize a rotation/quaternion-like structure from a source: copy four dwords, duplicate two source components, zero intermediate fields plus a 0x2C-byte block, set a -1 sentinel, zero trailing dwords.
- `0x00448730` **ShadowVolumeExtruder** — Compute a shadow-volume extrusion offset for collision geometry: detect silhouette edges relative to the light on the triangle array at *(this+0x1C), deduplicate them, sum an angular contribution per edge, clamp and write to *(this+0x10).
- `0x00448EE0` **ColorChannelPacker** — Pack three color-related bytes from an object into one DWORD stored at the output pointer: low byte from +0x19, second byte from BYTE1(this), high 16 bits from the word at +0x1A; return the output pointer.
- `0x004491C0` **TriangleIntersectionTester** — Triangle-pair intersection test: edge half-planes, separating-axis tests on both triangles, then 2D line-segment intersection between the two triangles' edges; return 1 on the first crossing else 0.
- `0x00449A20` **RegistryKeyValueQuery** — Query a registry value for a key formatted by StringFormatWith0x40Size; on success capture and return the value at TotalBytesAvail[7] after releasing the query handle, else return -1.

## Proposed classes

### ChampionshipPointsComparator

Compares the receiver's accumulated championship points against another object's accumulated points and reports whether the difference is at least 16; the compared object is resolved through sub_41F340 with a global default-string fallback (byte_5EA438). Points totals are computed via ChampionshipPointsAccumulator (0x0041F220).

Methods: `0x0041FDB0`


### ConfigPathRegistrationDelegates

Family of adjacent, identical-body __stdcall delegates that normalize a trailing backslash on a path string in place via PathTrailingBackslashNormalizer (0x00421890) and return the result of StringCopyWithBufferRealloc (0x00566650); all are reached from ConfigIniParser (0x00421CD0) when registering path-valued config entries. Whether they are distinct call sites of one helper or duplicated inline copies is unresolved.

Methods: `0x004218D0`, `0x004218F0`, `0x00421910`, `0x00421950`, `0x00421990`, `0x004219B0`, `0x004219D0`, `0x004219F0`, `0x00421A10`, `0x00421A30`, `0x00421A50`, `0x00421A70`, `0x00421A90`, `0x00421AB0`, `0x00421AD0`, `0x00421AF0`


### AIStateFlagWrapper

Computes an AI-state flag value as the global threshold dword_5EA2CC plus the receiver's dword at byte offset 0x4, writes it through AIStateFlagSetter (0x0042AC70), and returns the setter's result unchanged.

Methods: `0x0042AC90`

- `this+0x00000004` `dword flag_addend` (read, GUESS)

### SetupParamResolver

Linear lookup over five two-dword setup-parameter records starting at byte offset 0x4144 of the receiver: scans the first dword of each record for a key, returns the paired second dword on a match, or -1 after five records. Read-only; called by AICollision (0x004BEF60).

Methods: `0x0042AEB0`

- `this+0x00004144` `record_array[5] of two dwords setup_param_records` (read, GUESS)

### SetupValueFormatter

Formats a vehicle-setup value by value type id: angle in degrees (case 0), pressure with an imperial/metric branch on the unit-system flag at byte offset 0x4 (case 1), lengths with an optional wheel-type offset (cases 2/3/9), degrees/seconds (case 4), single-float (cases 5-8), and integer count (case 10). Rows are 64-byte slots at ((type + 11*group) << 6) + base + 176; formatting goes through StringFormatWithBufferOverflowCheck (0x0058815F) or the SetupValueFormat helpers (0x0042F260/0x0042F180/0x0042F1E0). The unit strings at this+8 and this+40 and the row field layout belong to an unidentified setup/menu object.

Methods: `0x0042F2F0`

- `this+0x00000004` `dword unit_system_flag` (read, GUESS)

### RuntimeObjectContainer

Tears down a container object reachable through the global dword_7C73E0: when non-null, walks and frees two singly-linked lists (heads at +48 and +32, next pointer at node+4), zeroes those four-slot field groups, conditionally frees member pointers at +16/+8/+0, then frees the container itself. On a null global the decompiled path returns an uninitialized result value.

Methods: `0x00431BE0`


### TrackSplineExtrapolator

Builds track-spline extrapolation data: zero-fills a local buffer, samples consecutive track-spline points from the scene via sub_403CD0 (scene base dword_5EA2C0), stores midpoints, extrapolates two Catmull-Rom-style extension segments, negates and applies fixed per-component offsets, then hands the buffer to sub_457F90 with element count dword_5C329C + 5.

Methods: `0x004349A0`


### NumericToleranceComparator

__stdcall double tolerance comparison: returns TRUE when the absolute difference of the two double arguments is below the epsilon constant 0.000000001, i.e. the two values are equal within tolerance. The packet deterministically lists dbl_59EAD8 as the read global backing the epsilon literal (identity DERIVED). Used by the suspension wheel dynamics solver (0x0043F7F0).

Methods: `0x00435290`


### CategoryScoringState

Constructor-like initializer for a 25-dword scoring-state object at `this`: field 0x0 is set to -1, field 0x10 to the decimal literal 1072693248, and all other fields 0x0..0x60 to 0. No reads, no globals, no branches; returns this. Called once from SuspensionSetupSectionReader (0x00435410).

Methods: `0x00435390`

- `this+0x00000000` `dword sentinel_value` (write, GUESS)
- `this+0x00000004` `dword field_04` (write, GUESS)
- `this+0x00000008` `dword field_08` (write, GUESS)
- `this+0x0000000C` `dword field_0C` (write, GUESS)
- `this+0x00000010` `dword field_10` (write, GUESS)
- `this+0x00000014` `dword field_14` (write, GUESS)
- `this+0x00000018` `dword field_18` (write, GUESS)
- `this+0x0000001C` `dword field_1C` (write, GUESS)
- `this+0x00000020` `dword field_20` (write, GUESS)
- `this+0x00000024` `dword field_24` (write, GUESS)
- `this+0x00000028` `dword field_28` (write, GUESS)
- `this+0x0000002C` `dword field_2C` (write, GUESS)
- `this+0x00000030` `dword field_30` (write, GUESS)
- `this+0x00000034` `dword field_34` (write, GUESS)
- `this+0x00000038` `dword field_38` (write, GUESS)
- `this+0x0000003C` `dword field_3C` (write, GUESS)
- `this+0x00000040` `dword field_40` (write, GUESS)
- `this+0x00000044` `dword field_44` (write, GUESS)
- `this+0x00000048` `dword field_48` (write, GUESS)
- `this+0x0000004C` `dword field_4C` (write, GUESS)
- `this+0x00000050` `dword field_50` (write, GUESS)
- `this+0x00000054` `dword field_54` (write, GUESS)
- `this+0x00000058` `dword field_58` (write, GUESS)
- `this+0x0000005C` `dword field_5C` (write, GUESS)
- `this+0x00000060` `dword field_60` (write, GUESS)

### BestFitPlaneFitter

Fits a least-squares plane to a2 points at a1 (28-byte stride, doubles at offsets +0/+8/+16) by accumulating normal-equation sums and solving the resulting 3x4 augmented system via sub_5677B0; on a failed solve writes a normalized fallback plane. Exact output layout (a3/a4 written via dword stores) is unresolved.

Methods: `0x004366E0`


### PhysicsSolverDispatch

Dispatches on a solver operation-type id (a2) and routes a scalar argument (a3) to one of six physics solver functions: delta-tracking update (case 3, 0x0043BB00), quadratic spring at object offsets 0x1838 and 0x189C (cases 9/10, 0x00436470), constraint-force solve (case 14, 0x0043BA20), quadratic evaluation (case 27, 0x0043BB30), quadratic force/torque (case 28, 0x0043BB80), and spring-damper (case 29, 0x0043BBD0). Unrecognized ids return immediately. Called per-frame by ConditionalMathDispatch.

Methods: `0x0043B930`


### RandomWeightedForceSplitter

Draws a pseudo-random weight v3 from a 256-entry lookup table (flt_8AAE74) indexed by a wrapping byte counter (dword_8AAE70, post-incremented), then splits the input scalar a2 into two weighted contributions: v3 * a2 to ClampedSpringIntegrator (0x0043E980) and (1.0 - v3) * a2 to DoubleAccumulatorClamp (0x0043EA70). The 1.0 base constant is read from dbl_59E420. No branches; both paths always execute.

Methods: `0x0043EC00`


### D3DRenderState

D3D render-state struct reset/init: zeroes the handle dword at +0x0; when the object pointer at +0x4 is non-null, releases it through the first entry of its vtable (vtable0(this+0x4, 1)) and clears the pointer; zeroes the dwords at +0x8, +0xC and +0x10; sets the state mask at +0x18 to 0xFF7FFFFF (clears bit 23); returns the release result. Invoked by ObjectConstructor (0x00448120) and Steward_Post (0x004D4600).

Methods: `0x004482D0`

- `this+0x00000000` `dword handle` (write, GUESS)
- `this+0x00000004` `pointer released_object_ptr` (read_write, GUESS)
- `this+0x00000008` `dword field_08` (write, GUESS)
- `this+0x0000000C` `dword field_0C` (write, GUESS)
- `this+0x00000010` `dword field_10` (write, GUESS)
- `this+0x00000018` `dword render_state_mask` (write, GUESS)
- `*(this+0x4)+0x00000000` `function_pointer vtable_release_slot0` (read, GUESS)

### SpatialMeshRotationState

Initializes a rotation/quaternion-like structure from a source a2: copies the four input dwords into this[0..3], duplicates a2[1] and a2[2] into this[4] and this[5], zeroes this[6] and the 0x2C-byte block from this+7 via memset, sets the sentinel this[18] to -1, zeroes the trailing five dwords this[19..23], and returns 0. Invoked by SpatialTreeInsertion (0x004485D0) and TriangleMeshAdjacencyBuilder (0x004493A0).

Methods: `0x00448510`

- `this+0x00000000` `dword component_0` (write, GUESS)
- `this+0x00000004` `dword component_1` (write, GUESS)
- `this+0x00000008` `dword component_2` (write, GUESS)
- `this+0x0000000C` `dword component_3` (write, GUESS)
- `this+0x00000010` `dword duplicated_axis_1` (write, GUESS)
- `this+0x00000014` `dword duplicated_axis_2` (write, GUESS)
- `this+0x00000018` `dword field_18` (write, GUESS)
- `this+0x00000048` `dword sentinel_value` (write, GUESS)
- `this+0x0000004C` `dword field_4C` (write, GUESS)
- `this+0x00000050` `dword field_50` (write, GUESS)
- `this+0x00000054` `dword field_54` (write, GUESS)
- `this+0x00000058` `dword field_58` (write, GUESS)
- `this+0x0000005C` `dword field_5C` (write, GUESS)

### ShadowVolumeExtruder

Computes a shadow-volume extrusion offset for collision geometry. Gated on the element count/type selector at *(this+0x18) being in 2..11, it walks the triangle array at *(this+0x1C), detects silhouette edges relative to the light (facing test with ratio 0.7), deduplicates them into a local edge table, then sums an angular extrusion contribution per edge. The accumulated factor is clamped and written to the offset field at *(this+0x10) relative to the base position fields *(this+0)/+4/+0xC.

Methods: `0x00448730`

- `this+0x00000000` `scalar base_position_x` (read, GUESS)
- `this+0x00000004` `scalar base_position_y` (read, GUESS)
- `this+0x0000000C` `scalar base_position_z` (read, GUESS)
- `this+0x00000010` `scalar extrusion_offset` (read_write, GUESS)
- `this+0x00000018` `dword element_selector` (read, GUESS)
- `this+0x0000001C` `pointer triangle_array_ptr` (read, GUESS)
- `*(this+0x1C)+0x00000000` `pointer vertex0_ptr` (read, GUESS)
- `*(this+0x1C)+0x00000004` `dword edge_partner0` (read, GUESS)
- `*(this+0x1C)+0x00000008` `pointer vertex1_ptr` (read, GUESS)
- `*(this+0x1C)+0x0000000C` `dword edge_partner1` (read, GUESS)
- `*(this+0x1C)+0x00000010` `pointer vertex2_ptr` (read, GUESS)
- `*(this+0x1C)+0x00000014` `dword edge_partner2` (read, GUESS)
- `*(this+0x1C)+0x00000018` `word flags_word` (read, GUESS)
- `*(this+0x1C)+0x00000019` `byte flag_byte` (read, GUESS)
- `*(this+0x1C)+0x0000001A` `word edge_id_word` (read, GUESS)
- `*(this+0x1C)+0x0000001C` `dword aux_data` (read, GUESS)
- `*(*(this+0x1C)+0x0)+0x00000000` `scalar vertex_x` (read, GUESS)
- `*(*(this+0x1C)+0x0)+0x00000008` `scalar vertex_z` (read, GUESS)
- `*(*(this+0x1C)+0x0)+0x0000000C` `scalar vertex_w_or_z2` (read, GUESS)

### ColorChannelPacker

Packs three color-related bytes from an input object into one DWORD and stores it at the caller-provided output pointer, returning that output pointer. The low byte comes from field +0x19, the second byte from BYTE1(this) (the second byte of the this pointer value itself, likely a decompiler artifact of a mis-typed field access), and the high 16 bits from the word at +0x1A. Used on mesh/vertex color setup paths.

Methods: `0x00448EE0`

- `this+0x00000019` `byte color_low_byte` (read, GUESS)
- `this+0x0000001A` `word color_high_word` (read, GUESS)

### TriangleIntersectionTester

Triangle-pair intersection test. Computes edge half-planes of the first triangle into a 72-byte stack buffer via TriangleEdgeHalfPlaneComputation (0x00448F00), then tests separating axes via SATSeparatingAxisTest (0x00448FC0) in both directions; when neither triangle pair is separated, tests 2D line-segment intersections between the two triangles' edges with F_2DLineSegmentIntersection (0x00449000). Returns 1 (intersecting) on the first edge crossing, else 0.

Methods: `0x004491C0`


### RegistryKeyValueQuery

Queries a value associated with a key string formatted by StringFormatWith0x40Size (0x00595AE2); formatting failure returns -1. Otherwise sub_59B760 fills a stack buffer with registry query results; on failure the handle is released via sub_58C331 and -1 is returned, and on success the captured value at TotalBytesAvail[7] is returned after releasing the handle. Called from SceneTrackFileLoader (0x0044C0E0).

Methods: `0x00449A20`


## Compatibility contracts

- **ConfigPathStringRegistrationContract** — Replacement must preserve in-place trailing-backslash normalization followed by a realloc-capable string copy for path strings registered by the config parser; the returned buffer identity must match StringCopyWithBufferRealloc semantics.
- **SetupValueFormatRowLayoutContract** — Replacement must index vehicle-setup value rows with the 64-byte stride ((type + 11*group) << 6) + base + 176 and route value type ids 0..10 through the documented formatting paths (angle, pressure with unit-system branch, length, degrees/seconds, single-float, integer count).
- **PhysicsSolverOpcodeContract** — Replacement must keep the solver operation-type id routing (3, 9, 10, 14, 27, 28, 29) so per-frame dispatch reaches delta-tracking, quadratic-spring, constraint-force, quadratic, force-torque, and spring-damper helpers.
- **ShadowVolumeSilhouetteGeometryContract** — Shadow-volume extrusion depends on the triangle-entry layout (vertex pointers at +0/+8/+0x10, edge-partner references at +0x4/+0xC/+0x14, flags at +0x18) and the 0.7 silhouette facing ratio.

## Unresolved

- All `this` object owners are UNKNOWN in the packet; every class identity in this proposal is a GUESS-level label for an otherwise unnamed receiver.
- The seventeen config path-registration delegates (0x004218D0..0x00421AF0) expose an identical body; whether they are distinct call sites of one helper or duplicated inline copies is not resolvable from the packet alone.
- StringCopyWithBufferRealloc return semantics (buffer ownership, allocated size, new allocation vs borrowed buffer) are not evidenced by this packet.
- ChampionshipPointsComparator: semantics and return type of sub_41F340 (provider resolution) are unknown; the meaning of the >= 16 threshold and the -1 accumulator argument is not established; the content/purpose of the global byte_5EA438 default string is unknown; despite the legacy Timing ABI name, the arithmetic uses championship points and the domain mapping is uncertain.
- AIStateFlagWrapper: that the computed value is a call-to-box flag and that dword_5EA2CC is an overtake-distance threshold is DERIVED from existing analysis; AIStateFlagSetter's internal guard behavior (values greater than 1) is not visible in this packet.
- SetupParamResolver: the meaning of the key a2 and the returned paired value is caller-dependent; only the record-start field (this+0x4144) is evidenced and the receiver type is not identified.
- SetupValueFormatter: the unit strings at this+8 and this+40, the this+4 unit flag, and the row field layout (+0, +8, +20) belong to an unidentified setup/menu object; the exact role of the wheel-type offsets in case 2 is not established; the string globals aD_1/a1fS/aDS are mapped by naming only.
- RuntimeObjectContainer: DoublePointerFree and FreeWrapper_7bcf are named in the raw source but have no callee-address evidence; the null-global path returns an uninitialized result; whether dword_7C73E0 is a singleton owner or a general pointer is not established; the purpose of the double free per node is unknown.
- TrackSplineExtrapolator: the five read-only float globals (0x0059E450, 0x0059E7F8, 0x0059E7FC, 0x0059E8F8, 0x0059EAD0) are read but their use is not visible in the decompiled source text; the fixed adjustment constants and the geometric meaning of the two extension segments are DERIVED; the roles of v22/v25 are not fully resolved.
- NumericToleranceComparator: dbl_59EAD8 as the storage for the folded epsilon literal is a DERIVED identity; the exact tolerance use inside the suspension solver is not evident from this function alone.
- CategoryScoringState: object class and field meanings are unknown; the purpose of the -1 sentinel at 0x0 and the nonzero literal at 0x10 is not known; the caller is SuspensionSetupSectionReader (0x00435410).
- BestFitPlaneFitter: dbl_59E420 is read but does not appear in the decompiled source (folded x87 constant); the a3/a4 output layout is ambiguous (long double* written via dword stores); the plane-fit interpretation rests on the canonical/ABI name only.
- PhysicsSolverDispatch: the semantic meaning of each operation-type id is not established; object offsets 6200/6300 (0x1838/0x189C) in cases 9/10 are not backed by a packet field entry; the dispatch semantics supplied by the caller ConditionalMathDispatch (0x004F1860) are not analyzed here.
- RandomWeightedForceSplitter: v2 is declared but never assigned before being passed to DoubleAccumulatorClamp (decompiler artifact); whether flt_8AAE74 is a trig/sine lookup or a general noise table is inferred; the packet does not disambiguate whether the audio or force subsystem label is authoritative.
- D3DRenderState: the identity of the vtable method invoked at this+0x4 slot 0 is unknown; the semantics of clearing bit 23 of the render-state mask are not further attested; when the pointer at this+0x4 is null the result is read before assignment; the concrete class is unknown.
- SpatialMeshRotationState: the source structure a2 layout and the meaning of duplicating a2[1]/a2[2] into this[4]/this[5] are inferred; the purpose of the -1 sentinel at this+0x48 and the 0x2C-byte zero block is unknown; the quaternion/rotation label for offsets 0x0-0x14 is DERIVED.
- ShadowVolumeExtruder: the double globals (0x0059E420, 0x0059E430, 0x0059E830, 0x0059E880, 0x0059EC60, 0x0059EF18, 0x0059EF20, 0x0059EF28) are read but materialize as folded FP constants (0.7, 0.15, 0.025) and their per-step roles are not evidenced; the triangle entry at +0x1C role is not visible in the control flow; whether *(this+0x10) is written as a double is unresolved.
- ColorChannelPacker: the second channel taken from BYTE1(this) is unusual for a struct read and may be a decompiler artifact; exact per-channel color meaning is not established; class identity is unknown.
- TriangleIntersectionTester: the triangle vertex layout and the 2*index stride imply pointer pairs but the exact struct layout is unknown; the 72-byte half-plane buffer format is not determined; the owning collision object is unknown.
- RegistryKeyValueQuery: the exact roles of sub_59B760 (query execution) and sub_58C331 (handle release) are inferred from control flow only; the meaning of TotalBytesAvail[7] and the buffer layout are unknown; which registry key/value is queried and how SceneTrackFileLoader consumes the result are unverified.
