# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

This packet groups 29 generic runtime-object functions. The strongest evidence clusters are: (1) an AngleNormalizer whose two structural twins wrap/reflect an in-place angle against +/-PI using global constants, both invoked by CollisionResponseFilter; (2) a MovementPath family of four functions sharing the this+0 keyframe-array-pointer / this+4 count / this+8 span / this+0xC..0x18 time+XYZ layout, covering Catmull-Rom interpolation, cumulative arc-length precomputation, buffer release/reset, and text serialization through BufferWriteWithStringLengthCheck; (3) a ParameterResolver whose two methods (enum-to-ID jump table, two-strategy named-parameter/pause-string lookup) share the single caller 0x0046B0C0; (4) a UI value-percent formatter pair (0x00466910, 0x004669A0) fetching the value through virtual vtable calls and rendering '%d%%' via StringFormatWithBufferOverflowCheck + StringCopyWithBufferRealloc; (5) a shared UI constructor family (InitVTableSet 0x004668E0, VtableSetWithInitCall 0x00466980, ConstructorWithVTableAndFloatInit 0x00466A30, ShortComputation_6c40 0x00466C40) around the UIConstructorWithVTableParams base initializer and the +0x100/+0x104/+0x108 fields; (6) network-layer objects: NetworkAuthKeyManager (XOR-decoded 6-byte key registration with four callbacks), NetworkGameListSession (a game-list status state machine with dev-log gate dword_7C569C==5), and NetworkSystemDispatcher (guarded flag set on the network-system pointer at obj+0x1B79C); (7) a LinkedListRegistry whose teardown frees two big lists, a fixed 104-entry static array, and two flag-linked lists (node payload at +0, next at +4, flag byte at +8) and whose merge sort orders the same next-at-+4 node layout by the float key at (data+4); (8) the AVIPlayer releasing its AVIStream/AVIFile handles; and (9) single-purpose helpers (DataTableAccessor, ConstantOffsetGetter, SaturatedByteAccumulator, FloatTierConverter, MenuOptionScreen) plus four ownerless global/object lifecycle stubs. Most class owners are UNKNOWN in the packet; grouping is a GUESS-level proposal grounded in shared field layouts, shared callees, shared vtables, and shared callers.

## Function roles

- `0x00454C20` **ParameterResolver** — Enum-to-ID mapping with default fallthrough: jump-table switch on the enum argument returns 89 for case 1, -1 for a large group of cases, and the original value for anything else
- `0x00454D30` **ParameterResolver** — Two-strategy parameter lookup with fallback: named-parameter path (sub_454350) writes (1, value) to the caller's dword pair, else the pause-string path (PAUSEStringCopier) writes (0, value), else returns 0
- `0x00455F90` **AngleNormalizer** — In-place angle wrap to [-PI, PI]: subtract 2*PI when *this exceeds +PI, add 2*PI when below -PI, using the global constants at 0x0059EFA4/0x0059EFA8
- `0x00455FD0` **AngleNormalizer** — In-place angle normalization: wraps upward by 2*PI below -PI and reflects via (2*PI - *this) above +PI (structural twin of AngleWrap 0x00455F90, differing only in the greater-than-PI branch)
- `0x00457D00` **MovementPath** — Catmull-Rom spline evaluation over the keyframe array at this+0: clamps at both ends (copy first/last keyframe), scans the segment containing the parameter over the 28-byte stride, evaluates four basis polynomials, writes time+X/Y/Z to this[3..6], returns pointer to this[4]
- `0x00457EE0` **MovementPath** — Pre-compute cumulative 3D arc length over the keyframe array: zero the first keyframe's accumulated-distance slot (obj+0x18), add each later keyframe's Euclidean distance, store the total to this+8, and return the array pointer
- `0x00458020` **MovementPath** — Release the heap buffer at this[0]-4 via FreeWrapper_7bcf when non-null, null this[0], and unconditionally zero the remaining record dwords this[1..6] (offsets 0x4..0x18)
- `0x00458190` **MovementPath** — Serialize keyframe (movement path) data as text: pad a scratch buffer, validate a non-null array with at least 4 entries, and emit opening/header/control-point/closing strings into the output buffer via BufferWriteWithStringLengthCheck
- `0x0045BB40` **UnknownObject** — Forwarding wrapper: delegates this unchanged to ShortComputation_b360 (0x0045B360) and returns this; no field access of its own
- `0x0045BB50` **UnknownObject** — this-call delegation thunk: forwards the receiver unchanged to a destructor-with-resource-cleanup routine (unnamed in evidence) and returns its int result
- `0x0045BE50` **UnknownObject** — Global lifecycle initializer: write 0 to dword_7CD208 and -1 to dword_7CD20C, then zero-initialize the structure at dword_7CD208 via WideStructZeroInit (address outside packet) and return its integer result
- `0x0045BEA0` **AVIPlayer** — AVI player teardown: release and null the two AVIStream handles (this+0x3C, this+0x40) and the AVIFile handle (this+0x38), each only while non-null, then delegate to AVIPlayerCleanup and return its result
- `0x0045BF70` **UnknownObject** — Global slot teardown: run per-object teardown on dword_7CD25C[0] when non-null, free the object via FreeWrapper_7bcf keeping the free result, and unconditionally clear the slot to null
- `0x0045CD70` **NetworkAuthKeyManager** — One-time network-auth initializer: guard on the init flag at this[0], clear the 0x8D4680 scratch dwords, XOR-decode the 6-byte key from byte_59F0C4, register with sub_561BF0 passing this[1], the config pointer, four callbacks and a trailing 0; store true in the init flag on success
- `0x0045D2D0` **NetworkGameListSession** — Network game-list session state-machine handler: on request a2==1 set the scene-refresh flag byte_7CD2A0, query the current state via sub_563E70, select and dev-log the matching status message (done/getting/searching/querying) unless session type dword_7C569C==5, copy the selected string into byte_5EC4CC via BinarySearchInStringTable, and resolve it via PathRegistryCallWrapper; other a2 values warn on unknown game list or return a2 unchanged
- `0x00461F90` **NetworkSystemDispatcher** — Conditional dispatch: when the network-system pointer at obj+0x1B79C is non-null and sub_563E70 reports the network/system capable, set a flag on that pointer and return its result; otherwise return the early this result unchanged
- `0x00462410` **DataTableAccessor** — Bounds-checked data-table row accessor: when 0 <= a2 < row count at obj+0x3E14, copy a 140-byte row at table+916+140*a2 into a3 and the per-row scalar at table+15476+4*a2 into *a4, returning 1; otherwise return 0
- `0x00463750` **ConstantOffsetGetter** — Side-effect-free getter: returns *this + 432 (second argument a2 unused)
- `0x00464A10` **SaturatedByteAccumulator** — Saturating 7-bit add on the byte at this+0: mask to 7 bits, add a2, clamp at 127, write back the low 7 bits preserving bit 7, return the clamped sum
- `0x00464A60` **FloatTierConverter** — Store the input dword at this+0x220, select a divisor by a cascading threshold chain (625000/28800/7200/2975 -> 32/20/16/10/6), convert 1.0/divisor/0.005 with CRTFtol, store the resulting byte at this+0x22A and return it
- `0x00465000` **LinkedListRegistry** — Teardown of a large heap object: free two big linked lists (heads obj+0xE5C0 and obj+0xE5B0) via ConditionalFreeByFlagCheck + FreeWrapper_7bcf and zero their four head/trailer/tail/count fields, free a fixed 104-entry static pointer array, free two flag-linked lists (heads obj+0x7C and obj+0x6C; payload at node+0 freed only when the flag byte at node+8 is set, node always freed), zero their four fields each, call EmptyStub_0170, then free the object itself
- `0x00465C70` **LinkedListRegistry** — Recursive ascending merge sort of a singly linked list by the float key at (data pointer + 4) of each node: count nodes, return on null/fewer-than-2, split at the midpoint, sort each half recursively (self), then merge by relinking node next pointers (offset 4) in ascending key order
- `0x004668E0` **UIConfiguredComponent** — Shared UI constructor helper: base initialization via UIConstructorWithVTableParams, then install the vtable pointer off_59F210 into this+0; invoked by a family of UI component constructor stubs
- `0x00466910` **UIValueDisplayFormatter** — Percent-value string formatter: fetch a float pointer via the virtual call at vtable+0xB4, convert *p*100.0+0.5 with CRTFtol, render '%d%%' via StringFormatWithBufferOverflowCheck, and store the result via StringCopyWithBufferRealloc
- `0x00466980` **UIConfiguredComponent** — Constructor helper: base initialization via UIConstructorWithVTableParams, then overwrite the vtable slot at offset 0 with the alternate vtable pointer off_59F2C8 and return this
- `0x004669A0` **UIValueDisplayFormatter** — Percent-value display formatter: fetch the value via the virtual call at vtable+180, normalize by the range width (this+0xF8 minus this+0xF4), scale by 100.0, truncate with CRTFtol, render '%d%%' via StringFormatWithBufferOverflowCheck and store via StringCopyWithBufferRealloc; the flag at this+0xF0 selects signed-int vs float interpretation
- `0x00466A30` **UIConfiguredComponent** — Object constructor: base init via InitVTableSet(this, a3, a4), install vtable off_59F380 at this+0, store float 0.5f at this+0x104, clear the byte at this+0x100, store parameter a2 at this+0x108, return this
- `0x00466C40` **UIConfiguredComponent** — Physics-state computation: call PhysicsStateInitIndexed(byte_7C56C0, this+0x108, this+0x104) then VehicleStatsEstimationDisplay(byte_7C56C0), clear the byte at this+0x100, and return 0
- `0x00467340` **MenuOptionScreen** — Menu option value adjust: compute value +/- 1 from the current value at offset 20 of the option data at this+0x320 (return 0 when null), dispatch through ListSelectionClamp when this+0x32C equals 4 or AIGearSelectionSet otherwise on global byte_7C56C0, then refresh via MenuOptionValueDisplay

## Proposed classes

### ParameterResolver

Resolves configuration/parameter values: maps an enum argument to an internal ID via a jump table (89 for case 1, -1 for a large group of cases, else pass-through) and resolves parameters through two ordered strategies (named-parameter lookup sub_454350, then pause-string PAUSEStringCopier), writing a (flag, value) dword pair to the caller.

Methods: `0x00454C20`, `0x00454D30`


### AngleNormalizer

Normalizes an in-place floating-point angle at this+0 to the range [-PI, PI] against the global +PI and 2*PI constants; one method wraps by subtracting 2*PI above +PI while the other reflects via (2*PI - value).

Methods: `0x00455F90`, `0x00455FD0`

- `this+0x00000000` `float angle` (read_write, DERIVED)

### MovementPath

Keyframe/movement-path object holding a keyframe array pointer at this+0 and its count at this+4, with a span/total-length slot at this+8 and a time+X/Y/Z output block at this+0xC..0x18. Evaluates the spline at a parameter (Catmull-Rom basis over the 28-byte keyframe stride), pre-computes cumulative 3D arc length, releases and resets the underlying buffer, and serializes the control points to a text buffer.

Methods: `0x00457D00`, `0x00457EE0`, `0x00458020`, `0x00458190`

- `this+0x00000000` `float* keyframe_array_ptr` (read_write, DERIVED)
- `this+0x00000004` `int keyframe_count` (read_write, DERIVED)
- `this+0x00000008` `float total_span_or_length` (read_write, GUESS)
- `this+0x0000000C` `float current_time_param` (read_write, DERIVED)
- `this+0x00000010` `float interpolated_x` (write, DERIVED)
- `this+0x00000014` `float interpolated_y` (write, DERIVED)
- `this+0x00000018` `float interpolated_z` (write, DERIVED)

### KeyframeElement

28-byte keyframe record (7 floats: 3D position at elements 0..2 plus tangent/control and time fields). The accumulated 3D distance is stored at element offset +0x18; the offsets +0x1C/+0x20/+0x24/+0x34 (second keyframe position/distance relative to the array base) are an interpretation from the analysis fill, not independently evidenced.

Methods: 

- `obj+0x00000018` `float accumulated_distance` (read_write, DERIVED)
- `obj+0x0000001C` `float second_keyframe_x` (read, GUESS)
- `obj+0x00000020` `float second_keyframe_y` (read, GUESS)
- `obj+0x00000024` `float second_keyframe_z` (read, GUESS)
- `obj+0x00000034` `float second_keyframe_distance` (read, GUESS)

### AVIPlayer

Owns AVI playback handles: an AVIFile interface at this+0x38 and two AVIStream interfaces at this+0x3C/+0x40. Its teardown releases each non-null handle and nulls it, then delegates to AVIPlayerCleanup.

Methods: `0x0045BEA0`

- `this+0x00000038` `void* avifile_handle` (read_write, DERIVED)
- `this+0x0000003C` `void* stream_primary_handle` (read_write, DERIVED)
- `this+0x00000040` `void* stream_secondary_handle` (read_write, DERIVED)

### NetworkAuthKeyManager

One-time network-auth initializer. A byte init flag at this+0 guards repeated registration; the configuration pointer at this+4 is forwarded to sub_561BF0 together with a 6-byte XOR-decoded key (byte_59F0C4 each byte XOR 0x3E) decoded into the 0x8D4680 scratch region and four callback function pointers.

Methods: `0x0045CD70`

- `this+0x00000000` `byte init_flag` (read_write, DERIVED)
- `this+0x00000004` `void* config_ptr` (read, DERIVED)

### NetworkGameListSession

Network session that tracks the game-list update state machine. On a get-game-list request it raises the global scene-refresh flag byte_7CD2A0, queries the current state via sub_563E70, selects and (unless session type dword_7C569C==5) dev-logs the matching status string, copies the selected message into byte_5EC4CC through BinarySearchInStringTable, and resolves it via PathRegistryCallWrapper.

Methods: `0x0045D2D0`


### NetworkSystemDispatcher

Guarded forwarder of a network-system pointer: when the pointer at obj+0x1B79C is non-null and the network/system reports capability via sub_563E70, sets a flag on that pointer and returns the flag result.

Methods: `0x00461F90`

- `obj+0x0001B79C` `void* network_system_ptr` (read, DERIVED)

### DataTableAccessor

Bounds-checked reader of a fixed-size data table: holds the table object pointer at this+0 and reads the row count from the object at obj+0x3E14. A row (140 bytes, stride 140 starting at table+916) is copied into the caller buffer and a parallel per-row scalar (4 bytes per row at table+15476) is written to a dword output.

Methods: `0x00462410`

- `this+0x00000000` `void* table_obj_ptr` (read, DERIVED)
- `obj+0x00003E14` `int row_count` (read, DERIVED)

### ConstantOffsetGetter

Side-effect-free getter returning the dword at this+0 plus the constant 432; the second argument is unused.

Methods: `0x00463750`

- `this+0x00000000` `dword base_value` (read, DERIVED)

### SaturatedByteAccumulator

Saturating 7-bit byte accumulator at this+0: adds an increment, clamps the sum at 127, and writes back only the low 7 bits, preserving bit 7 as an independent flag bit.

Methods: `0x00464A10`

- `this+0x00000000` `byte accumulator_byte` (read_write, DERIVED)

### FloatTierConverter

Stores an input dword at this+0x220 and converts it to a byte at this+0x22A through a cascading tier chain: the divisor is chosen by thresholds (>=625000 -> 32.0, >=28800 -> 20.0, >=7200 -> 16.0, >=2975 -> 10.0, else 6.0), and 1.0/divisor/0.005 is truncated with CRTFtol.

Methods: `0x00464A60`

- `this+0x00000220` `dword stored_value` (write, DERIVED)
- `this+0x0000022A` `byte converted_byte` (read_write, DERIVED)

### LinkedListRegistry

Large registry object owning multiple linked lists over a common node layout {data/payload at node+0, next at node+4, flag byte at node+8}: two big lists (heads obj+0xE5C0 and obj+0xE5B0, each with four head/trailer/tail/count fields), a fixed 104-entry static pointer array, and two flag-linked lists (heads obj+0x7C and obj+0x6C). Its teardown frees every node (and payloads when the flag byte is set) and zeroes all list fields; its sort orders the next-at-+4 node layout ascending by the float key at (data+4).

Methods: `0x00465000`, `0x00465C70`

- `obj+0x0000006C` `node* flaglist2_head` (read_write, DERIVED)
- `obj+0x00000070` `node* flaglist2_tail` (read_write, DERIVED)
- `obj+0x00000074` `int flaglist2_count` (read_write, DERIVED)
- `obj+0x00000078` `int flaglist2_capacity` (read_write, DERIVED)
- `obj+0x0000007C` `node* flaglist1_head` (read_write, DERIVED)
- `obj+0x00000080` `node* flaglist1_tail` (read_write, DERIVED)
- `obj+0x00000084` `int flaglist1_count` (read_write, DERIVED)
- `obj+0x00000088` `int flaglist1_capacity` (read_write, DERIVED)
- `obj+0x0000E5B0` `node* biglist2_head` (read_write, DERIVED)
- `obj+0x0000E5B4` `node* biglist2_tail` (read_write, DERIVED)
- `obj+0x0000E5B8` `int biglist2_count` (read_write, DERIVED)
- `obj+0x0000E5BC` `int biglist2_capacity` (read_write, DERIVED)
- `obj+0x0000E5C0` `node* biglist1_head` (read_write, DERIVED)
- `obj+0x0000E5C4` `node* biglist1_tail` (read_write, DERIVED)
- `obj+0x0000E5C8` `int biglist1_count` (read_write, DERIVED)
- `obj+0x0000E5CC` `int biglist1_capacity` (read_write, DERIVED)
- `obj+0x00000004` `node* node_next` (read, DERIVED)
- `*(obj+0x80)+0x00000004` `node* flaglist1_node_next` (read, DERIVED)
- `*(obj+0x70)+0x00000004` `node* flaglist2_node_next` (read, DERIVED)
- `this+0x00000008` `node* merge_cursor_ptr` (read_write, DERIVED)
- `*(this+0x8)+0x00000004` `node* merge_midpoint_next` (read_write, DERIVED)

### UIConfiguredComponent

UI/component object family built on the UIConstructorWithVTableParams base initializer with per-variant vtable installs (off_59F210, off_59F2C8, off_59F380). A configuration block sits at +0x100 (cleared flag byte) / +0x104 (float, default 0.5f) / +0x108 (integer/ID parameter); the compute method feeds those into PhysicsStateInitIndexed + VehicleStatsEstimationDisplay on the byte_7C56C0 working buffer.

Methods: `0x004668E0`, `0x00466980`, `0x00466A30`, `0x00466C40`

- `this+0x00000000` `void** vtable` (write, DERIVED)
- `this+0x00000100` `byte dirty_flag_byte` (read_write, DERIVED)
- `this+0x00000104` `float ratio_float` (read_write, DERIVED)
- `this+0x00000108` `int index_or_id` (read_write, DERIVED)

### UIValueDisplayFormatter

Formats a value as a percentage string. The value is fetched through a virtual call on the object's own vtable (slot +0xB4 in one method, slot +180 in the other), normalized by a range, scaled to a percent, truncated with CRTFtol, rendered as '%d%%' via StringFormatWithBufferOverflowCheck, and persisted via StringCopyWithBufferRealloc. A signedness flag at this+0xF0 selects int vs float interpretation; the range bounds live at this+0xF4/+0xF8.

Methods: `0x00466910`, `0x004669A0`

- `this+0x00000000` `void** vtable` (read, DERIVED)
- `obj+0x000000B4` `func* (vtable slot 180) percent_value_getter_slot` (read, DERIVED)
- `this+0x000000F0` `dword signed_flag` (read, DERIVED)
- `this+0x000000F4` `float range_min` (read, DERIVED)
- `this+0x000000F8` `float range_max` (read, DERIVED)

### MenuOptionScreen

Menu screen option object whose entry reads an option-data pointer at this+0x320, a selection index at this+0x324, a parameter at this+0x328, and a type discriminator at this+0x32C; an adjuster increments/decrements the option value and dispatches through ListSelectionClamp (type 4) or AIGearSelectionSet against the byte_7C56C0 working buffer, then refreshes the displayed text.

Methods: `0x00467340`

- `this+0x00000320` `void* option_data_ptr` (read, DERIVED)
- `this+0x00000324` `int selection_index` (read, DERIVED)
- `this+0x00000328` `int parameter` (read, DERIVED)
- `this+0x0000032C` `int type_field` (read, DERIVED)

## Compatibility contracts

- **movement_path_record_layout** — MovementPath holds the keyframe array pointer at this+0, the keyframe count at this+4, a span/total-length slot at this+8, and a time+X/Y/Z output block at this+0xC..0x18. Buffer release frees the block at this[0]-4 and zeroes this[1..6]; spline evaluation returns a pointer into this[4].
- **keyframe_28byte_stride** — Keyframes are 28-byte records (7 floats): the accumulated 3D distance of a keyframe lives at element offset +0x18, and the second keyframe occupies offsets 0x1C/0x20/0x24/0x34 relative to the array base (position and distance). The basis interpolation reads four consecutive keyframes.
- **linked_list_node_layout** — Nodes managed by LinkedListRegistry use {data/payload at node+0, next at node+4, flag byte at node+8}. The merge sort orders nodes by the float key at (data+4); the teardown frees a node's payload only when the flag byte at node+8 is non-zero and always frees the node itself. List containers keep four fields (head, trailer/tail, tail/count, count/capacity) at their heads (obj+0x6C/+0x7C/+0xE5B0/+0xE5C0).
- **network_auth_key_registration** — One-time network-auth registration: the init flag at this[0] guards repeated calls; the 6-byte key stored XOR-obfuscated in byte_59F0C4 is decoded (each byte XOR 0x3E) into the 0x8D4680..0x8D468C scratch region and passed to sub_561BF0 together with the config pointer at this[4] and four callback function pointers.
- **game_list_status_display** — The game-list handler raises the global scene-refresh flag byte_7CD2A0 on a get-game-list request, selects the status string matching the sub_563E70 state, suppresses dev-log output for session type dword_7C569C==5, copies the selected message into byte_5EC4CC via BinarySearchInStringTable, and resolves it via PathRegistryCallWrapper.
- **avi_handle_cleanup** — AVIPlayer owns an AVIFile handle at this+0x38 and two AVIStream handles at this+0x3C/+0x40; each is released only while non-null and nulled afterwards, then teardown delegates to AVIPlayerCleanup.
- **ui_value_percent_format** — UI value display formatters fetch the value through a virtual call on the object's vtable (slot +0xB4 or +180), normalize/scale it to a percent, truncate with CRTFtol, render '%d%%' via StringFormatWithBufferOverflowCheck, and persist the result via StringCopyWithBufferRealloc.
- **saturated_byte_accumulator** — The byte at this+0 is a 7-bit accumulator with bit 7 preserved as an independent flag: adds the increment, clamps the sum at 127, and writes back only the low 7 bits.

## Unresolved

- All packet owners are UNKNOWN; every class grouping above is a GUESS proposal grounded in shared field layouts (identical base+offset), shared callees, shared vtable installs, and shared callers, not a proven static type.
- MovementPath this+0x8 has a dual role across methods: CatmullRomSplineInterpolate reads it as the total time span (upper clamp bound) while KeyframeArcLengthPrecompute writes it as the total accumulated path length; whether these are the same quantity is unresolved. The final read at byte offset 28*i-60 in KeyframeArcLengthPrecompute is ambiguous (not the last keyframe's +0x18 slot).
- The KeyframeElement obj+0x1C/+0x20/+0x24/+0x34 offsets (second keyframe fields) are extracted relative to a separate obj base and the raw source reaches the keyframe array only through this[0]; the packet does not prove obj and this[0] point to the same array, so this identification is an interpretation, not independently evidenced.
- The six Catmull-Rom coefficient globals (0x0059E440, 0x0059E450, 0x0059E46C, 0x0059E478, 0x0059E7EC, 0x0059E800) are not individually mapped to the floating-point literals; 0x0059E440 and 0x0059E450 are also absent from the FormatValueAsPercentString raw body.
- byte_454C58 (0x00454C58), read-only data adjacent to the EnumToIDMapping jump table, has an unclear role.
- global aMovementpath (0x005C5AA8) is listed for MovementPathSerialize but does not appear in the decompiled body; its role (likely a 'MovementPath' name tag) is unconfirmed.
- The semantic meaning of the enum-to-ID mapping in 0x00454C20 (which enum is consumed, what ID 89 and -1 signify) is not established.
- WideStructZeroInit (called by 0x0045BE50) and sub_45D730 (per-object teardown in 0x0045BF70) have no callee evidence entries; their addresses are unknown.
- The -1 sentinel written to dword_7CD20C by GlobalStateInitializer likely marks an uninitialized index but its meaning is unconfirmed; the object managed through global slot dword_7CD25C is unknown.
- NetworkAuthKeyInit: the exact 8-argument contract of sub_561BF0, the roles of the four callback globals (DebugFloatFormatString, SceneTextureApply, BooleanParameterFormatDispatch, NetworkScorePingDisplay), and why the key is XOR-obfuscated are not grounded beyond this call site.
- GameListStateUpdateHandler: dword_7CD25C is listed as read but absent from the raw body (likely consumed by a callee); the meaning of a2 and of the a2==2 early-return path, and the literal log line numbers (239/244/249/254/266), are unestablished.
- ConditionalNetworkSystemDispatch: SetFlagIfPointerNonNull appears in the raw source but has no callee entry (likely a macro/inlined helper); the identity of the network system object at obj+0x1B79C is unknown.
- DataTableRowAccessor: the per-row scalar array at 15476 and the data-array base offsets 916/15476 are not individually tagged as fields; their semantics are unresolved.
- ConstantOffsetAccessor: the meaning of the constant 432 (member offset versus arithmetic addend) and the unused second argument are unresolved.
- SaturatedByteAdd: the purpose of the preserved bit 7 flag bit is caller-dependent and unresolved here.
- FloatStoreWithConversion: the exact mapping of threshold/divisor literals to the seven named constant globals is not evidenced (raw source shows only the literals); the speed/RPM tier reading is DERIVED prior analysis, not confirmed by this packet.
- ComprehensiveLinkedListCleanup: the fixed 104-entry static pointer array (walked from v1+14734 backward 140 dwords) has no field evidence ref; the node payload at +0 and flag byte at +8 have no allowed field evidence refs either and are described only from the raw control flow; the loop guards are recorded against count fields obj+0x74/obj+0x84 while the raw source loops test the head pointers obj+0x6C/obj+0x7C (relationship unconfirmed); EmptyStub_0170's role is unknown; the returned result when *this is null is uninitialized.
- MergeSortAscendingOnLinkedList: the payload record behind each node's data pointer is unidentified; the sentinel field at this+0x8 doubles as split-termination write and merge-tail terminator; the caller EntityVisibilityGridManager's entity record layout is outside this packet.
- InitVTableSet: the meaning of a2/a3 is delegated to UIConstructorWithVTableParams; the vtable off_59F210 dispatch contents are outside the packet.
- FormatValueAsPercentString: globals flt_59E450 and flt_59E6F8 are listed but absent from the raw body; the byte_5EA438 prefix-byte semantics are unknown.
- VtableSetWithInitCall: the relationship between off_59F2C8 and the default vtable installed by UIConstructorWithVTableParams is unknown.
- SetupValueDisplayFormatter_69a0: the concrete target of the virtual call at vtable+180 is an indirect call with no static callee evidence; the attribution of flt_59E6F8 to the 100.0 constant is DERIVED.
- ConstructorWithVTableAndFloatInit: the meaning of parameter a2 (index/ID per the DERIVED fill) is unverified; the class behind off_59F380 is unknown.
- ShortComputation_6c40: global byte_7C56C0 (labelled SessionNameBuffer in prior analysis) is treated as a physics-state working buffer; its real identity/layout is DERIVED only, and the +0x104/+0x108 field types come from decompiler casts without independent structure evidence.
- MenuOptionValueAdjust: field this+0x334 is listed in the packet but never referenced in the raw source; the option-data structure at this+0x320 (value at offset 20) and the meaning of the type value 4 are unidentified.
- VTableInitConditionalResourceFree (0x0045BB50): DestructorWithResourceCleanup is named only in the raw source with no callee entry; no caller or vtable slot is recorded, and the ABI name VTable_Init_Conditional_Resource_Free is a legacy label, not independent evidence.
- GlobalStateInitializer and TeardownGlobalPointerSlot are left ownerless (UnknownObject): the two operate on distinct globals (0x7CD208 vs 0x7CD25C) and no shared-object evidence links them.
- The UIValueDisplayFormatter and UIConfiguredComponent groupings may be one UI component class with overridden vtables rather than two classes; the percent formatters touch the vtable at this+0 while the constructor family touches +0x100/+0x104/+0x108, and no packet evidence proves either relationship.
- The 28*i-60 final read in KeyframeArcLengthPrecompute, the total span/length dual-use of this+8, and the two PI constant write sites (0x0059EFA4/0x0059EFA8) are outside this packet's evidence.
