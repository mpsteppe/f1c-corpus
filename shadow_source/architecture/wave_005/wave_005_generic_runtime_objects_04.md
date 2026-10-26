# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Proposal for 31 functions spanning generic runtime objects. The packet proves branch-free global-pair initializers (render float blocks, camera-view-zoom block, audio-state block with tag 92 and value 18000), a family of small conditional field getters/setters and clamped-float setter, a guarded save/restore of a 3-DWORD position, two struct init/teardown helpers sharing SwapAndReinit, a quadratic-surface fit with Gaussian-elimination solve and fallback plus its spatial-hash dispatch companion, a vertex-projection visibility coverage estimator, a scancode-to-ASCII translator with two jump tables, a lazy random-generator init, spline evaluation wrapper, tracking-camera config serialization through a getter chain, UI selection-rectangle rendering with 0.4-factor interpolation, an indexed string-entry registry, config-text emitters, a backslash-to-underscore string normalizer, and a large session struct teardown destroying four lists and two sub-object arrays. All owner types are UNKNOWN at packet level; class membership is GUESS.

## Function roles

- `0x00449A80` **QuadraticSurfaceFit** — Fits a quadratic surface to 6 input points: writes six solved double coefficients to this+0x0..0x2C, builds and sorts three edge vectors at this+0x30..0x50, assembles and solves a 6x6 linear system via Gaussian elimination (0x005677B0) with residual threshold 0.001, falls back to a 3-point solve; on failure logs via DebugLogWrite and returns -1, on success returns 0. Debug gated by StringSplitLoop/DebugLogWrite pairs.
- `0x00449ED0` **QuadraticSurfaceFit** — Builds an 8-DWORD spatial-hash key block from three referenced objects reached through the a2 descriptor, composes two packed hash words, submits the block to ConditionalDispatch_6bd0 (0x00566BD0) with opcode 34, then returns HATPolygonSurfaceFit(this, a2, 1).
- `0x0044A2D0` **VisibilityCoverageEstimator** — Walks a singly linked list of vertex-data nodes (next pointer at node+28), projects each node's three vertex pairs onto a weighted axis, writes 16-byte projection records to a3+8, sorts them via sub_5890AA with comparator sub_44A130, then evaluates coverage via VisibilityFrustumTest (0x0044A170) split by the count midpoint and selects the better-scoring half into `this`.
- `0x0044CAB4` **RenderStateInitializer** — Branch-free render-state initializer: writes 0.0 to global flt_7CD150 and 1065353216 to adjacent global dword_7CD154. No callees, no return.
- `0x0044CC34` **RenderStateInitializer** — Camera-view-zoom initializer: clears flt_7CA3C0[0] to 0.0 and sets dword_7CA3C4 to 1065353216. No arguments, no return.
- `0x0044D2F4` **RenderStateInitializer** — Render-constants initializer: writes decimal 0 into global dword_7CA418 and decimal 1065353216 into adjacent global dword_7CA41C. Zero-argument, void-returning.
- `0x0044E960` **AudioStateInitializer** — Unconditional audio-state initializer: writes tag 92 into dword_7CCA14, zeroes dword_7CCA18 through dword_7CCA24, sets dword_7CCA28 = 18000, returns 0.
- `0x00452780` **SwapReinitInitializedStruct** — Constructor/initializer filling an 11-field region with fixed values: sets this+0x4 = 89, zeroes this+0x0 and this+0x8..this+0x18, calls SwapAndReinit(this+0x4, 89, 0), zeroes this+0x1C..this+0x28, returns this. Invoked by MemoryAllocation_31a0 (0x004531A0) after allocation.
- `0x004527E0` **SwapReinitInitializedStruct** — Collision-property initializer: zeroes the state field at this+0x0, calls SwapAndReinit(this+1, a2, a3) reinitializing the node-property pair at this+0x4, zeroes this+0x1C and this+0x20, and returns the SwapAndReinit result. Called by ShortComputation_30a0 (0x004530A0).
- `0x00455580` **ScancodeAsciiTranslator** — Scancode-to-ASCII keyboard translation: negative scancodes (-128..-1) map to fixed ASCII via jump table 0x00455868; other inputs pass through unchanged when the extended-key flag (a2 & 0x8000) is clear, else a second jump table 0x00455A5C maps extended scancodes with shift state (a2>>10, a2>>11) folded in. Called by TranslateVirtualKey (0x00455B30).
- `0x00456010` **RandomGeneratorState** — Lazy random-generator module init: when byte_7CD1FC is zero, builds a value with sub_5896EE(0), stores it through TLSFieldSetter (0x005884E0), sets the flag to 1; then delegates to the random generator entry (rendered RandLCGRandomNumberGenerator). Invoked by CollisionResponseWithRandomPerturbation (0x00457A00).
- `0x00456040` **RuntimeFieldAccessor** — Getter: copies fields this+0x30 and this+0x34 into caller-supplied output pointers a2 and a3 when non-null; returns a3.
- `0x004560A0` **RuntimeFieldAccessor** — Getter: copies fields this+0x4C and this+0x50 into caller-supplied output pointers a2 and a3 when non-null; returns a3.
- `0x004560C0` **RuntimeFieldAccessor** — Getter: copies struct fields at offsets 0x54 and 0x58 (elements 21 and 22) to caller-provided output pointers a2 and a3, each guarded on its pointer being non-null; returns a3.
- `0x004560E0` **RuntimeFieldAccessor** — Conditional multi-field getter: copies three consecutive dword fields at offsets 0x64, 0x68 and 0x6C into a2, a3 and a4, each write guarded by its pointer being non-null; returns a4.
- `0x00456150` **RuntimeFieldAccessor** — Copies three consecutive DWORDs from source a2 into this at offsets 0x24, 0x28 and 0x2C when a2 is non-null, then returns the third source DWORD a2[2] (or null a2 when the guard fails).
- `0x00456280` **RuntimeFieldAccessor** — Unconditional three-DWORD setter: writes three caller-supplied values into this+0x0, this+0x4 and this+0x8, returns the third value. Called by F_3DSoundEmitter (0x00456170).
- `0x00456FB0` **ClampedFloatState** — Clamped float setter: writes a2 into this+0xAC clamped to the inclusive range [this+0x80, this+0x84]. Called by CameraPositionDefinitions (0x00408870) and CollisionCoefficientApplication (0x00456F70).
- `0x00457B00` **PositionBackupState** — Saves or restores a 3-DWORD position based on activation flag this+0x9C: when flag clear and a2==1, copies position (this+0x18/0x1C/0x20) into saved slot (this+0x90/0x94/0x98) and sets flag; when flag==1 and a2==0, VectorCopy (0x00456130) restores the slot to this+0x0 and clears the flag. Called from CameraShake and CollisionResponseWithRandomPerturbation.
- `0x00457CD0` **TransformSubobjectLifecycle** — Initializer zeroing the seven leading DWORD fields (this+0x0..0x18) and the byte at this+0x1C, then returns the struct pointer. Called from F_3DTransformObjectInit (0x004583B0).
- `0x00457CF0` **TransformSubobjectLifecycle** — Thunk forwarding the incoming __thiscall this-pointer unchanged to UtilityFunction_8020 and returning its integer result. Conditional deallocation plus struct zero-initialization semantics live in the callee. Called from the VTableInitCallChain path (0x004584A0).
- `0x004582C0` **CubicSplineEvaluator** — Guard-protected spline evaluation wrapper: returns 0 immediately when the keyframe array pointer at this[0] is NULL; otherwise sets byte flag this+0x1C to 1 and delegates to CubicSplineInterpolation(this, a2), returning its result.
- `0x00458A60` **TrackingCameraConfigSerializer** — Serializes tracking-camera/shader configuration parameters into string buffer a2: builds a space-padded scratch buffer, collects configuration fields from this, pulls further parameters through a chain of getter helpers (0x00456040, 0x004560E0, 0x00456080, 0x004560A0, 0x004560C0), emits key-value format strings via BufferWriteWithStringLengthCheck (0x00566C30), then a nested block via sub_458190; returns 0.
- `0x0045B660` **CursorSelectionRectangle** — Renders a UI cursor selection rectangle, smoothly interpolating stored bounds toward targets: derives target X from sub_45B5C0 plus offset 0.05 and target Y from a threshold count (0x0045BB00) scaled by 0.035, blends each stored dimension (this+0x324/0x328) toward its target by 0.4 with epsilon-snap, converts to integers, and draws four rectangle edges through the render device pointer dword_8B8DC8.
- `0x0045BA60` **IndexedStringEntryRegistry** — Iterates eight 92-byte struct entries beginning at this+0x3C; each entry's leading string is compared with a2 (case-insensitive via sub_566810 when a3 non-zero, case-sensitive via strcmp when a3 zero) and on a match the entry is reset through PerIndexStructFieldResetter (0x0045B430). No-op when a2 is null or empty.
- `0x0045BF10` **WideObjectZeroInitializer** — Wide-object zero initializer: zeroes dwords at this+0x8 and this+0xC, memsets the 0x28-byte middle region starting at this+0x10, zeroes tail dwords at this+0x38..0x50, returns 0. Possibly invoked during AVIPlayerCleanup (0x0045BED6).
- `0x0045CDE0` **ConfigTextEmitter** — Formats the hardcoded float 1.026 as "%1.3f" into a local stack buffer via StringFormatWithBufferOverflowCheck (0x0058815F), bracketed by two ShortComputation_ce30 (0x0045CE30) passes over the receiver; returns the second pass's result. Parameter a2 unused.
- `0x0045CF30` **StringPathNormalizer** — Iterates a null-terminated ASCII string in place, replacing every backslash (92) with underscore (95); advances using the byte at this+0x1 as lookahead terminator; returns the last character examined. Called by ShortComputation_ce30 (0x0045CE30).
- `0x0045D0D0` **ConfigTextEmitter** — Determines whether a password string is configured (length via ConstantOffsetAccessor (0x00463750) resolving through dword_7CD25C), formats the boolean (1 if non-empty else 0) as "%d" via 0x0058815F, and registers the key/value pair under the password key into the target output via ShortComputation_ce30.
- `0x0045D130` **ConfigTextEmitter** — Formats per-player network score and ping entries into output buffer `this`: reads player count from the game module manager global (dword_7CD25C via 0x00462370), iterates player rows fetched via DataTableRowAccessor (0x00462410), and registers player_%d/score_%d/ping_%d key-value pairs through ShortComputation_ce30 (0x0045CE30); returns the player count.
- `0x0045D730` **SessionStructTeardown** — Teardown of a large session-side struct: destroys three linked lists (heads at this+0x1B758/0x1B770/0x1B780, nodes via +4 next, DestructorWithDoubleFreePattern 0x00418D60) and zeroes each list's four bookkeeping fields; destroys a 104-item 872-byte-stride sub-object array and the linked list at this+0x3FC8 (ConditionalDestructor_46f0 0x004646F0), resets vtable this+0x3FBC to off_59F0CC, destroys a 104-item 140-byte-stride array, frees buffers this+0xBC/0xB4 via FreeWrapper_7bcf, and returns EmptyStub_0170(this+52). Called by sub_45BF70 (0x0045BF70).

## Proposed classes

### QuadraticSurfaceFit

Fits a quadratic surface to sampled point sets: solves six double coefficients via Gaussian elimination with a 3-point fallback and residual check, and submits spatial-hash key blocks for dispatch.

Methods: `0x00449A80`, `0x00449ED0`

- `this+0x00000000` `double surface_coeff_a` (write, GUESS)
- `this+0x00000004` `double surface_coeff_a_hi` (write, GUESS)
- `this+0x00000008` `double surface_coeff_b` (write, GUESS)
- `this+0x0000000C` `double surface_coeff_b_hi` (write, GUESS)
- `this+0x00000010` `double surface_coeff_c` (write, GUESS)
- `this+0x00000014` `double surface_coeff_c_hi` (write, GUESS)
- `this+0x00000018` `double surface_coeff_d` (write, GUESS)
- `this+0x0000001C` `double surface_coeff_d_hi` (write, GUESS)
- `this+0x00000020` `double surface_coeff_e` (write, GUESS)
- `this+0x00000024` `double surface_coeff_e_hi` (write, GUESS)
- `this+0x00000028` `double surface_coeff_f` (read_write, GUESS)
- `this+0x0000002C` `double surface_coeff_f_hi` (write, GUESS)
- `this+0x00000030` `float edge_vector_0_x` (read_write, GUESS)
- `this+0x00000034` `float edge_vector_0_y` (read_write, GUESS)
- `this+0x00000038` `float edge_vector_0_z` (read_write, GUESS)
- `this+0x0000003C` `float edge_vector_1_x` (read_write, GUESS)
- `this+0x00000040` `float edge_vector_1_y` (read_write, GUESS)
- `this+0x00000044` `float edge_vector_1_z` (read_write, GUESS)
- `this+0x00000048` `float edge_vector_2_x` (read_write, GUESS)
- `this+0x0000004C` `float edge_vector_2_y` (read_write, GUESS)
- `this+0x00000050` `float edge_vector_2_z` (read_write, GUESS)
- `this+0x00000054` `word point_sample_word` (read_write, GUESS)
- `this+0x00000058` `byte point_sample_byte` (write, GUESS)
- `this+0x000000B8` `unknown unresolved_read_field` (read, UNKNOWN)

### VisibilityCoverageEstimator

Projects linked-list vertex data onto a weighted axis, sorts projection records, and evaluates spatial coverage via VisibilityFrustumTest, selecting the better-scoring half.

Methods: `0x0044A2D0`


### RenderStateInitializer

Branch-free startup writes into adjacent render-state global pairs (float/dword zero and one patterns).

Methods: `0x0044CAB4`, `0x0044CC34`, `0x0044D2F4`


### AudioStateInitializer

Unconditional audio-state global block initialization (tag 92, zeroed fields, value 18000).

Methods: `0x0044E960`


### SwapReinitInitializedStruct

Structs whose head region is seeded with a fixed value (89) and whose sub-region is (re)initialized through SwapAndReinit, with trailing dwords zeroed.

Methods: `0x00452780`, `0x004527E0`

- `this+0x00000000` `dword head_state` (write, GUESS)
- `this+0x00000004` `dword seed_value` (write, GUESS)
- `this+0x00000008` `dword sub_region_0` (write, GUESS)
- `this+0x0000000C` `dword sub_region_1` (write, GUESS)
- `this+0x00000010` `dword sub_region_2` (write, GUESS)
- `this+0x00000014` `dword sub_region_3` (write, GUESS)
- `this+0x00000018` `dword sub_region_4` (write, GUESS)
- `this+0x0000001C` `dword trailing_0` (write, GUESS)
- `this+0x00000020` `dword trailing_1` (write, GUESS)
- `this+0x00000024` `dword trailing_2` (write, GUESS)
- `this+0x00000028` `dword trailing_3` (write, GUESS)

### ScancodeAsciiTranslator

Maps scancodes to ASCII characters through two jump tables, folding extended-key and shift state.

Methods: `0x00455580`


### RandomGeneratorState

One-time lazy initialization of a TLS-backed random-generator seed, then delegation to an LCG random-number generator entry.

Methods: `0x00456010`


### RuntimeFieldAccessor

Small conditional getter/setter helpers copying one to three consecutive dword fields into caller-supplied output pointers (or from them), each write guarded on pointer non-null.

Methods: `0x00456040`, `0x004560A0`, `0x004560C0`, `0x004560E0`, `0x00456150`, `0x00456280`

- `this+0x00000000` `dword triple_0` (read_write, GUESS)
- `this+0x00000004` `dword triple_1` (read_write, GUESS)
- `this+0x00000008` `dword triple_2` (read_write, GUESS)
- `this+0x00000024` `dword copy_0` (write, GUESS)
- `this+0x00000028` `dword copy_1` (write, GUESS)
- `this+0x0000002C` `dword copy_2` (write, GUESS)
- `this+0x00000030` `dword pair_0` (read, GUESS)
- `this+0x00000034` `dword pair_1` (read, GUESS)
- `this+0x0000004C` `dword pair_high_0` (read, GUESS)
- `this+0x00000050` `dword pair_high_1` (read, GUESS)
- `this+0x00000054` `dword viewport_0` (read, GUESS)
- `this+0x00000058` `dword viewport_1` (read, GUESS)
- `this+0x00000064` `dword triple_high_0` (read, GUESS)
- `this+0x00000068` `dword triple_high_1` (read, GUESS)
- `this+0x0000006C` `dword triple_high_2` (read, GUESS)

### ClampedFloatState

Stores a float value clamped to an inclusive range held in two bound fields.

Methods: `0x00456FB0`

- `this+0x00000080` `float clamp_min` (read, GUESS)
- `this+0x00000084` `float clamp_max` (read, GUESS)
- `this+0x000000AC` `float clamped_value` (read_write, GUESS)

### PositionBackupState

Saves/restores a 3-DWORD position into a saved slot, gated by a single activation flag byte.

Methods: `0x00457B00`

- `this+0x00000018` `dword position_x` (read, GUESS)
- `this+0x0000001C` `dword position_y` (read, GUESS)
- `this+0x00000020` `dword position_z` (read, GUESS)
- `this+0x00000090` `dword saved_x` (read_write, GUESS)
- `this+0x00000094` `dword saved_y` (read_write, GUESS)
- `this+0x00000098` `dword saved_z` (read_write, GUESS)
- `this+0x0000009C` `byte backup_flag` (read_write, GUESS)

### TransformSubobjectLifecycle

Lifecycle of a small transform-related sub-object: zero initialization of the leading fields, and a conditional free/zero-init thunk whose behavior lives in UtilityFunction_8020.

Methods: `0x00457CD0`, `0x00457CF0`

- `this+0x00000000` `dword dword_0` (write, GUESS)
- `this+0x00000004` `dword dword_1` (write, GUESS)
- `this+0x00000008` `dword dword_2` (write, GUESS)
- `this+0x0000000C` `dword dword_3` (write, GUESS)
- `this+0x00000010` `dword dword_4` (write, GUESS)
- `this+0x00000014` `dword dword_5` (write, GUESS)
- `this+0x00000018` `dword dword_6` (write, GUESS)
- `this+0x0000001C` `byte flag_or_tag_byte` (write, GUESS)

### CubicSplineEvaluator

Guard-protected evaluation of a keyframe spline: null-guarded keyframe array, active flag, delegation to the spline interpolation implementation.

Methods: `0x004582C0`

- `this+0x00000000` `ptr keyframe_array` (read, GUESS)
- `this+0x0000001C` `byte active_flag` (write, GUESS)

### TrackingCameraConfigSerializer

Serializes tracking-camera/shader configuration parameters into a string buffer, pulling values directly from receiver fields and through a chain of field getters.

Methods: `0x00458A60`

- `this+0x0000000C` `dword config_3` (read, GUESS)
- `this+0x00000010` `dword config_4` (read, GUESS)
- `this+0x00000014` `dword config_5` (read, GUESS)
- `this+0x00000048` `dword config_18` (read, GUESS)
- `this+0x0000005C` `dword config_23` (read, GUESS)
- `this+0x00000090` `dword config_36` (read, GUESS)
- `this+0x00000094` `dword config_37` (read, GUESS)
- `this+0x00000098` `dword config_38` (read, GUESS)

### CursorSelectionRectangle

Renders a UI cursor selection rectangle, interpolating stored width/height toward targets by a fixed factor with epsilon-snap, then drawing four edges through the render device.

Methods: `0x0045B660`

- `this+0x00000324` `float selection_rect_x` (read_write, GUESS)
- `this+0x00000328` `float selection_rect_y` (read_write, GUESS)

### IndexedStringEntryRegistry

Iterates fixed-size entries keyed by a leading string and resets matching entries, with case-sensitive or case-insensitive comparison.

Methods: `0x0045BA60`

- `this+0x0000003C` `ptr string_entry_array` (read, GUESS)

### WideObjectZeroInitializer

Zero initialization of a wide object: scattered head/tail dwords plus a 0x28-byte middle memset.

Methods: `0x0045BF10`

- `this+0x00000008` `dword head_a` (write, GUESS)
- `this+0x0000000C` `dword head_b` (write, GUESS)
- `this+0x00000010` `bytearray middle_region_start` (write, GUESS)
- `this+0x00000038` `dword tail_0` (write, GUESS)
- `this+0x0000003C` `dword tail_1` (write, GUESS)
- `this+0x00000040` `dword tail_2` (write, GUESS)
- `this+0x00000044` `dword tail_3` (write, GUESS)
- `this+0x00000048` `dword tail_4` (write, GUESS)
- `this+0x0000004C` `dword tail_5` (write, GUESS)
- `this+0x00000050` `dword tail_6` (write, GUESS)

### ConfigTextEmitter

Formats booleans/floats/player statistics as key/value text and registers them into an output buffer through the shared ShortComputation_ce30 writer.

Methods: `0x0045CDE0`, `0x0045D0D0`, `0x0045D130`


### StringPathNormalizer

In-place normalization of a null-terminated string buffer, replacing backslashes with underscores.

Methods: `0x0045CF30`

- `this+0x00000000` `byte string_chars` (read_write, GUESS)
- `this+0x00000001` `byte lookahead_terminator` (read, GUESS)

### SessionStructTeardown

Teardown of a large session-side struct: destroys four linked lists and two arrays of 104 sub-objects, resets a sub-object vtable, and frees two dynamic buffers.

Methods: `0x0045D730`

- `this+0x000000B4` `ptr dynamic_buffer_a` (read, GUESS)
- `this+0x000000BC` `ptr dynamic_buffer_b` (read, GUESS)
- `this+0x00003FBC` `ptr subobject_vtable` (write, GUESS)
- `this+0x00003FC8` `dword list4_head` (write, GUESS)
- `this+0x00003FCC` `dword list4_next` (write, GUESS)
- `this+0x00003FD0` `dword list4_tail` (write, GUESS)
- `this+0x00003FD4` `dword list4_count` (write, GUESS)
- `this+0x0001B758` `dword list1_head` (write, GUESS)
- `this+0x0001B75C` `dword list1_next` (write, GUESS)
- `this+0x0001B760` `dword list1_tail` (write, GUESS)
- `this+0x0001B764` `dword list1_count` (write, GUESS)
- `this+0x0001B770` `dword list2_head` (write, GUESS)
- `this+0x0001B774` `dword list2_next` (write, GUESS)
- `this+0x0001B778` `dword list2_tail` (write, GUESS)
- `this+0x0001B77C` `dword list2_count` (write, GUESS)
- `this+0x0001B780` `dword list3_head` (write, GUESS)
- `this+0x0001B784` `dword list3_next` (write, GUESS)
- `this+0x0001B788` `dword list3_tail` (write, GUESS)
- `this+0x0001B78C` `dword list3_count` (write, GUESS)

## Compatibility contracts

- **RenderStateGlobalInitValues** — Replacement must initialize the render-state global pairs at startup: flt_7CD150 = 0.0 with dword_7CD154 = 1065353216 (0x3F800000); flt_7CA3C0[0] = 0.0 with dword_7CA3C4 = 1065353216; dword_7CA418 = 0 with dword_7CA41C = 1065353216.
- **AudioStateBlockInit** — Audio-state global block must be initialized as: dword_7CCA14 = 92 (tag), dword_7CCA18 through dword_7CCA24 = 0, dword_7CCA28 = 18000.
- **SpatialHashDispatchOpcode34** — ComputeSpatialHashKey builds an 8-DWORD key block (two packed hash words) and submits it to ConditionalDispatch_6bd0 with opcode 34 before delegating to the surface fit; replacement must preserve the key layout and the dispatch opcode.
- **QuadraticSurfaceFitResult** — HATPolygonSurfaceFit writes six double coefficients at this+0x0..0x2C from a 6-point solve, falls back to a 3-point solve when residuals exceed 0.001, logs through DebugLogWrite, and returns 0 on success / -1 on failure; Gaussian elimination at 0x005677B0 solves both the 6x6 and 3x3 systems.
- **ScancodeToAsciiTables** — TranslateScancodeToAscii must preserve the negative-scancode jump table at 0x00455868 and the extended-key jump table at 0x00455A5C, the extended-key flag bit (a2 & 0x8000), and the shift-state bits a2>>10 and a2>>11 folded into the result.
- **SelectionRectangleInterpolation** — RenderSelectionRectangleWithInterpolation blends the stored dimensions this+0x324/0x328 toward targets by factor 0.4 with an epsilon-snap rule, converts to integers, and draws four edges through the render device pointer dword_8B8DC8.
- **SessionStructTeardownOrder** — StructTeardownCleanup must destroy four linked lists (nodes via +4 next pointers), two arrays of 104 sub-objects (872-byte and 140-byte strides), reset the sub-object vtable this+0x3FBC to off_59F0CC, and free the buffers at this+0xB4 and this+0xBC; the destruction order and stride layout must be preserved.

## Unresolved

- HATPolygonSurfaceFit: read globals dbl_59E880, dbl_59EA08 and dword_8ACEA0 are reported by deterministic facts but do not appear in the decompiled text; field this+0xB8 is read per facts but its use is not visible. The (this[21]+100) subtracted value and the 1.0 dword-split lagrange terms are inferred from Gaussian-elimination structure.
- ComputeSpatialHashKey: the semantic meaning of the three referenced objects and the spatial-hash layout of the packed words is not established; v13 (word at a2+26) is stored but never read afterwards.
- ComputeAxisProjectionCoverage: flt_59E450 (DegreesToRadians) has no visible reference in the raw text; the a4/a5 projection-weight semantics, the VisibilityFrustumTest coverage result meaning, and the a6 in-place-recompute-vs-copy meaning are DERIVED from the skeleton, not proven by raw source.
- RenderStateFloatInitialization/CameraViewZoomInitializer/InitRenderConstantsZeroOne: the decimal 1065353216 is preserved as-is; interpreting it as the bit pattern of float 1.0 is not evidenced. Consumers of the written globals are not identified.
- AudioStateInit: the semantic role of each 0x7CCA14-region global is not recoverable from the packet; existing analysis labels (AudioStatePtr, CollisionMiscFloat, UIElementState) are all DERIVED and not part of this packet's evidence. No static callers are recorded.
- StructInitWithFixedValues: the object type owning the 11-field region is unknown; the meaning of fixed value 89 and the contract of SwapAndReinit are unresolved.
- StructInitWithSubCall: SwapAndReinit's swap-and-reinit contract at this+0x4, the forwarded arguments a2/a3, and the role of the trailing zeroed fields are unresolved.
- RuntimeFieldAccessor: the getter helpers operate on possibly different receiver objects; five of them (0x00456040, 0x004560A0, 0x004560C0, 0x004560E0 and 0x00456080) are also used by TrackingCameraConfigSerialize, but shared ownership is structural inference, not proven.
- ClampedFloatState: the meaning of the clamped quantity and its bounds (this+0x80/0x84/0xAC) is not determinable from this function alone.
- PositionBackupState: the meaning of the two activation states and the base position written by VectorCopy depend on the callers CameraShake and CollisionResponseWithRandomPerturbation, whose bodies are not in the packet.
- TransformSubobjectLifecycle: UtilityFunction_8020 is not in the packet, so the conditional free/zero-init behavior of the 0x00457CF0 thunk is unverified; whether 0x00457CD0 and 0x00457CF0 share an object type is not proven.
- CubicSplineEvaluator: the call target CubicSplineInterpolation is named in raw source but has no address in the packet; semantics of the 0x1C flag and the a2 parameter are unresolved.
- TrackingCameraConfigSerialize: globals aFalse (0x005C5798), aTrue (0x005C596C) and byte_5EA438 (0x005EA438) are listed as packet globals but are not referenced directly in the function body; the mapping of format strings to configuration values is DERIVED only.
- CursorSelectionRectangle: what sub_45B5C0 computes, the render-helper chain semantics, and the int/float aliasing of this[201]/this[202] (0x324/0x328) are not established; several attributed globals (0x0059E440, 0x0059E448, 0x0059E8C8, 0x0059F078, 0x0059F088, 0x007CDE00) do not appear in the raw text.
- IndexedStringEntryRegistry: sub_566810 is assumed to be a case-insensitive string comparison but its contract is not visible; the 92-byte entry layout and what PerIndexStructFieldResetter zeroes are not in the packet.
- WideObjectZeroInitializer: whether this is a constructor or a reset invoked during AVIPlayerCleanup (0x0045BED6) is unknown.
- DebugFloatFormatString: five read-only globals flagged by packet facts (0x0059F090, 0x005C5B68, 0x005C5BC4, 0x005C5BCC, 0x005C5BD4) appear nowhere in the raw source; the receiver object type and parameter a2 are unknown.
- NetworkScorePingDisplay: where v11 (score) and v12 (ping) are populated relative to the DataTableRowAccessor output buffer is not evidenced; global aD_1 (0x005C3280) is not referenced by any visible operation.
- SessionStructTeardown: the two sub-object array geometries (872-byte and 140-byte strides, both 104 items) are derived from pointer arithmetic; EmptyStub_0170 and ConditionalDestructor_46f0 semantics (and why list 4 uses a constant-argument destructor while lists 1-3 pass the node pointer) are not established; the identity of the buffers at this+0xBC/0xB4 is unknown.
- SaveOrRestorePositionByActivationState: the state machine proposed here (CLEAR/SAVED) is a DERIVED reading of the flag-gated save/restore logic, not a proven event-driven machine.
