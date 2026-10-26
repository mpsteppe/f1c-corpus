# MathAndCollision

Scope: `math_and_collision`  
Trust: `DERIVED`

Thirty functions reconstructed around array containers, vector math, and collision processing. Three accessor families share bounds-checked lookup against an inline element count and a data pointer (0x0042DC80/0x0042DCA0 plus structural twin 0x004582A0 on a {+0x0,+0x4} two-dword header; 0x0042DCC0/0x0042DCE0 plus twin 0x004CE8D0 on a {+0x8,+0xC} header). Three collision functions form the scope core: BezierPatchCollisionTessellator (0x0044B370) drives the triangle-mesh adjacency pipeline and HATPolygonSurfaceFit with a permutation-index switch through jump table 0x0044B8F4; CollisionResponseDispatcher (0x00464B40) gates on sensor/flag bytes and dispatches a 6-bit collision type to Euler-angle or arithmetic paths then clears 104 flag fields; ZoneCollisionFrameProcessor (0x004B9000) walks a threshold-sorted node list with a cursor at +0x71C and runs the two-pass message dispatch. VectorMathOps (0x00456110, 0x00456130, 0x0045EB00) copy or scale three-component values at fixed this offsets; FixedPointVectorPacker (0x004B2480) clamps/scales a float vector into int16 slots. Array/aggregate helpers (0x0045C750/0x0045C8B0, plus 0x00411680, 0x0045E5B0, 0x00460C60, 0x004912F0, 0x004CB5E0) initialize, search, or clear fixed-size tables; four single-string or strided-float lookups (0x004328E0, 0x0045B480, 0x0045BB00, 0x00497F90) remain ownerless. Fourteen functions are left ownerless in function_roles because no common-ownership evidence exists.

## Function roles

- `0x0040FDD0` **UnknownObject** — Destructor of a single object or an array of 198-dword elements selected by flag bits in a2: the array path reads the element count from the header dword at this-1, walks elements backward overwriting each vtable pointer with off_59E720 and calling MultiFieldCleanupDestructor on the sub-object at +0xD4, then returns the header pointer; the single-object path applies the same vtable/sub-object cleanup to this. Flag bit 1 frees the backing block via FreeWrapper_7bcf.
- `0x00411680` **UnknownObject** — Array initializer: fills 537 consecutive word-pairs with (1, 0) via an unconditional do-while countdown and returns the array base.
- `0x0042DC80` **BoundedArrayAccessor** — Bounds-checked element accessor: rejects index a2 when negative or >= count at this+0x0, otherwise returns the dword at (ptr at this+0x4) + 8*a2 (8-byte stride, first element dword).
- `0x0042DCA0` **BoundedArrayAccessor** — Bounds-checked element accessor over the same {count at +0x0, ptr at +0x4} layout: returns the second dword (offset +4) of the 8-byte element when a2 is in [0, count), else 0.
- `0x0042DCC0` **IndexedStrideArrayAccessor** — Bounds-checked element accessor over a {count at +0x8, ptr at +0xC} layout: returns the first dword of the 8-byte element when a2 is in [0, count), else 0.
- `0x0042DCE0` **IndexedStrideArrayAccessor** — Bounds-checked element accessor over a {count at +0x8, ptr at +0xC} layout: returns the second dword (offset +4) of the 8-byte element when a2 is in [0, count), else 0.
- `0x004328E0` **UnknownObject** — First-string getter of a string array reached through this+0: returns this[0][0], falling back to the global byte_5EA438 default string when the first element is null.
- `0x0044B370` **BezierPatchCollisionTessellator** — Bezier patch collision tessellation: initializes a collision shape buffer, packs control-point triangle vertices into cyclic adjacency via TriangleMeshAdjacencyBuilder, computes contact responses, fits HATPolygonSurfaceFit height coefficients per patch, derives a permutation index, and builds the output adjacency under a jump-table switch (0x0044B8F4) over permutation cases, then frees temporaries.
- `0x0044F640` **UnknownObject** — Cursor selector: validates index a2 against the cursor count at this+0xA8 and the handle in slot this[5*a2+12], then calls SetCursor through import global 0x0059E2B0 and records the selection at this+0xAC, returning 1; returns 0 out of range or on a null handle.
- `0x00456110` **VectorMathOps** — Three-dword vector copy: when source a2 is non-null, copies three consecutive dwords into destination offsets +0xC/+0x10/+0x14 and returns the third source dword; a null source returns a2 unchanged.
- `0x00456130` **VectorMathOps** — Three-component vector copy: when source a2 is non-null, copies three consecutive dwords into destination offsets +0x18/+0x1C/+0x20 and returns the third source dword; a null source returns a2 unchanged.
- `0x004582A0` **BoundedArrayAccessor** — Bounded strided-array element pointer: when a2 is in [0, count at this+0x4), returns (ptr at this+0x0) + 28*a2, else 0.
- `0x0045B480` **UnknownObject** — Fixed 8-entry string-array search: compares each entry name at offset 60 with stride 92 against a2 via strcmp; on a match writes 5.0 into the payload float at 92*v2+144 and returns 1, else returns 0 after all 8 entries.
- `0x0045BB00` **UnknownObject** — Strided float scan: counts how many of the first 8 floats (92-byte stride) starting at this+0x90 are > 0.0, capped at 4, and returns that count.
- `0x0045C750` **AggregateArrayInitializer** — Constant-parameterized init wrapper: calls ArrayInitializationLoop (0x0045C8B0) with the constant 1 and returns this unchanged; used during audio channel setup.
- `0x0045C8B0` **AggregateArrayInitializer** — Aggregate initializer: zeroes this+0x0 always and this+0x4..+0x10 when the a2 init flag is non-zero, then loops 104 times calling PerElementArrayReset(this, i) and returns the last call's result.
- `0x0045CBF0` **UnknownObject** — Short lookup and zero check: reads the short at this[a2+2402], converts it to float via ShortToFloatConversion into a3, and returns whether the converted float is non-zero.
- `0x0045E5B0` **UnknownObject** — Sentinel search: walks the DWORD array at this+0x1D4 up to 104 elements and returns the 0-based index of the first -1 (0xFFFFFFFF) sentinel, or -1 when none is found.
- `0x0045EB00` **VectorMathOps** — Vector-scalar multiply: scales the three float components at this+0/+4/+8 by scalar a3, writes them to output a2, and returns a2.
- `0x00460C60` **UnknownObject** — Bulk reinitializer: 104 iterations each writing the -1 sentinel into the DWORD array at this+0x3E18, zero-initing a 140-byte struct element via StructFieldZeroInitWithDefaults, and initing a 218-dword struct element via ThunkWithStructInitSubCalls; returns the last thunk result.
- `0x00464B40` **CollisionResponseDispatcher** — Collision response dispatch: when the sensor float at this+0x71 is below a2+4, or (flag byte at this+0x70 XOR a2+3) & 7 is non-zero, routes the 6-bit collision type ((a2>>18)&0x3F) with value 7 to VehicleOrientationFromEulerAngles and 0 to ArithmeticComparison_3a90, then clears 104 per-byte flag fields via BitFlagSetter.
- `0x004912F0` **UnknownObject** — Forwarding thunk: calls ShortArrayZeroInit (0x00491330) on this and returns this unchanged, usable as a constructor-like init step.
- `0x00497F90` **UnknownObject** — String-array match search: rejects null/empty inputs, copies a2 to a local buffer truncated at the separator from dword_5CC79C, and when the stored count this+0x1514 is positive iterates entries from this+69 (stride 20 elements) via sub_588410, returning 1 on the first match and 0 otherwise.
- `0x004B2480` **FixedPointVectorPacker** — Float-vector to int16 pack: clamps each of the three float components to [-655.34003, 655.34003], scales by 50.0, saturates to 0x7FFF/-32767 out of range, and stores the int16 results at this+0x1E/+0x20/+0x22, returning the third as an int.
- `0x004B9000` **ZoneCollisionFrameProcessor** — Frame pass over zone/collision objects driven by float threshold a2: iterates 104 slots, selects a start node in the threshold-sorted node list via roots at +0x714/+0x718 and cursor at +0x71C (length bound +0x720), runs ascending and descending message-processing passes over child links, then finishes with CollisionFilterAABBCull and LinkedListIteratorWithStateUpdate on the embedded list at +0xF44.
- `0x004BBED0` **AccumulatorArrayOps** — Byte-value accumulator with a four-entry capacity: reads the count at this+0x3C; when full it adds the input byte (a2+8) into the existing slot at this[2*count+15], otherwise it stores a literal 3 type marker at this[2*count+16], the byte at this[2*count+17], and increments the count; then invokes a comparison helper on *this + 13004 and returns its result.
- `0x004BBF70` **AccumulatorArrayOps** — Dequeue/status step over a fixed DWORD-pair array: decrements the entry count at this+0x3C when positive, shifts the remaining pairs (slots at +0x40/+0x44 type/value onward) one slot toward the front, and reports emptiness through ArithmeticComparison_5660 on the parent object at *this + 13004.
- `0x004BC270` **FloatArrayLookup** — Indexed float-array read with a sentinel default: when the array pointer at this+0x8C is non-null and index a2-1 satisfies the capacity bounds at this+0x8 and this+0x88, returns the float at (ptr + 4*(a2-1)); otherwise returns -1.0 (global flt_59E670).
- `0x004CB5E0` **ArrayClearOps** — Array clear: while the element count at this+0x64 is positive, pops the last element, reads its pointer from the base at this+0x68, releases the element handle via sub_558B30, and marks the element invalid with -1; returns the final (zero) count.
- `0x004CE8D0` **IndexedStrideArrayAccessor** — Bounds-checked index into a fixed-stride array: rejects a2 negative or >= the count at this+0x8, else returns (ptr at this+0xC) + 108*a2.

## Proposed classes

### VectorMathOps

Three-component vector helpers on a target struct: two three-dword copy entry points (destinations +0xC and +0x18) and a scalar multiply (source at +0x0). The this-role differs per method (destination vs source), so the grouping is thematic.

Methods: `0x00456110`, `0x00456130`, `0x0045EB00`

- `this+0x00000000` `float source_vec_x` (read, GUESS)
- `this+0x00000004` `float source_vec_y` (read, GUESS)
- `this+0x00000008` `float source_vec_z` (read, GUESS)
- `this+0x0000000C` `float copy_slot_a_x` (read_write, GUESS)
- `this+0x00000010` `float copy_slot_a_y` (read_write, GUESS)
- `this+0x00000014` `float copy_slot_a_z` (read_write, GUESS)
- `this+0x00000018` `float copy_slot_b_x` (read_write, GUESS)
- `this+0x0000001C` `float copy_slot_b_y` (read_write, GUESS)
- `this+0x00000020` `float copy_slot_b_z` (read_write, GUESS)

### FixedPointVectorPacker

Packs a three-component float vector into three clamped int16 slots at +0x1E/+0x20/+0x22 using scale 50.0 and saturation bounds 0x7FFF/-32767.

Methods: `0x004B2480`

- `this+0x0000001E` `int16 packed_vec_x` (write, GUESS)
- `this+0x00000020` `int16 packed_vec_y` (write, GUESS)
- `this+0x00000022` `int16 packed_vec_z` (write, GUESS)

### BoundedArrayAccessor

Bounds-checked element accessor over a two-dword header. 0x0042DC80/0x0042DCA0 read the count at +0x0 and the data pointer at +0x4 with 8-byte stride; the cluster twin 0x004582A0 reads the same two header dwords in the reverse role assignment (pointer at +0x0, count at +0x4) with 28-byte stride.

Methods: `0x0042DC80`, `0x0042DCA0`, `0x004582A0`

- `this+0x00000000` `dword count_or_ptr` (read, GUESS)
- `this+0x00000004` `dword ptr_or_count` (read, GUESS)

### IndexedStrideArrayAccessor

Bounds-checked element accessor over a {count at +0x8, data pointer at +0xC} header. 0x0042DCC0/0x0042DCE0 return first/second dwords of 8-byte elements; the cluster twin 0x004CE8D0 returns the element pointer with a 108-byte stride from the same header layout.

Methods: `0x0042DCC0`, `0x0042DCE0`, `0x004CE8D0`

- `this+0x00000008` `int element_count` (read, GUESS)
- `this+0x0000000C` `const void* element_ptr` (read, GUESS)

### BezierPatchCollisionTessellator

Tessellates Bezier patch control points into a collision triangle mesh: builds cyclic adjacency, computes contact responses, fits HAT surface coefficients, and assembles the output adjacency under a permutation-index jump table. Operates on local buffers rather than an owning this layout.

Methods: `0x0044B370`


### CollisionResponseDispatcher

Collision response routing: gates on a sensor float at +0x71 and a flag byte at +0x70, dispatches a 6-bit collision type to Euler-angle or arithmetic paths, then clears 104 per-byte flag fields.

Methods: `0x00464B40`

- `this+0x00000070` `unsigned char collision_flag_byte` (read, GUESS)
- `this+0x00000071` `float sensor_float` (read, GUESS)

### ZoneCollisionFrameProcessor

Per-frame pass over a zone/collision scene: maintains a threshold-sorted node list with two roots (+0x714/+0x718), a cursor (+0x71C), and a length bound (+0x720), runs ascending/descending message passes over node child links, then culls and resumes iteration on the embedded list at +0xF44.

Methods: `0x004B9000`

- `this+0x00000714` `void* list_root_a` (read, GUESS)
- `this+0x00000718` `void* list_root_b` (read, GUESS)
- `this+0x0000071C` `void* list_cursor` (read_write, GUESS)
- `this+0x00000720` `int list_length_bound` (read, GUESS)
- `this+0x00000F30` `float threshold_float_a` (read, GUESS)
- `this+0x00000F34` `float threshold_float_b` (read, GUESS)

### AccumulatorArrayOps

Fixed-capacity DWORD-pair accumulator: entry count at +0x3C, pair slots starting at +0x40 (type/value), a parent-object pointer at +0x0, and a dequeue/status entry point that shifts pairs and reports through ArithmeticComparison_5660.

Methods: `0x004BBED0`, `0x004BBF70`

- `this+0x00000000` `void* parent_ptr` (read, GUESS)
- `this+0x0000003C` `int entry_count` (read_write, GUESS)
- `this+0x00000040` `dword slot0_type` (read_write, GUESS)
- `this+0x00000044` `dword slot0_value` (read_write, GUESS)
- `this+0x00000048` `dword slot1_type` (read_write, GUESS)
- `this+0x0000004C` `dword slot1_value` (read_write, GUESS)

### FloatArrayLookup

Indexed float-array read with two capacity bounds (+0x8, +0x88), a data pointer at +0x8C, and a -1.0 sentinel return for null or out-of-range access.

Methods: `0x004BC270`

- `this+0x00000008` `int capacity_a` (read, GUESS)
- `this+0x00000088` `int capacity_b` (read, GUESS)
- `this+0x0000008C` `const float* data_ptr` (read, GUESS)

### ArrayClearOps

Releases a flat pointer array: element count at +0x64, array base at +0x68; pops from the back, releases each element handle via sub_558B30, and marks the element invalid with -1.

Methods: `0x004CB5E0`

- `this+0x00000064` `int entry_count` (read_write, GUESS)
- `this+0x00000068` `void** data_ptr` (read, GUESS)

### AggregateArrayInitializer

Aggregate/array initialization: zeroes the head fields (+0x0 always, +0x4..+0x10 under an init flag) and runs a fixed 104-iteration per-element reset loop; the wrapper entry point parameterizes the init flag with the constant 1.

Methods: `0x0045C750`, `0x0045C8B0`

- `this+0x00000000` `dword head_dword` (write, GUESS)
- `this+0x00000004` `dword tail_dword_a` (write, GUESS)
- `this+0x00000008` `dword tail_dword_b` (write, GUESS)
- `this+0x0000000C` `dword tail_dword_c` (write, GUESS)
- `this+0x00000010` `dword tail_dword_d` (write, GUESS)

## Compatibility contracts

- **BoundedArrayLookupContract** — Bounds-checked element lookup over an inline count-plus-pointer container: an index a2 is rejected when negative or >= the stored count and returns 0; a valid index returns one dword of the strided element, with the returned dword position (first vs second) fixed per accessor. A replacement must preserve the [0, count) contract, the return-0 out-of-range behavior, and the returned dword position.
- **VectorCopyReturnContract** — A three-component vector copy writes the three source dwords into a destination struct at fixed offsets and returns the third source dword as a pointer-sized value; a null source skips the copy and returns the source pointer. Callers consume the return value, so a replacement must preserve both the fixed offsets and the return value.
- **CollisionTypeDispatchContract** — Collision response is gated on (sensor float at +0x71 < a2+4) or ((flag byte at +0x70 XOR a2+3) & 7) non-zero, dispatches a 6-bit collision-type field extracted as (a2 >> 18) & 0x3F with value 7 routing to Euler-angle orientation and value 0 to the arithmetic-comparison path, then clears 104 per-byte flag fields. A replacement must preserve the gate, the type-field extraction, the two dispatch targets, and the 104-flag clear.
- **SentinelScanContract** — A free/unset slot search scans a 104-element DWORD table for the -1 (0xFFFFFFFF) sentinel and returns its 0-based index, or -1 when the table contains no sentinel within the window. A replacement must use -1 both as the per-element sentinel and as the not-found return.
- **FixedPointVectorPackContract** — Float-vector to int16 packing clamps each component to [-655.34003, 655.34003], scales by 50.0, truncates to int16, and saturates to 0x7FFF (above the upper bound) or -32767 (below the lower bound); the three results are stored at +0x1E/+0x20/+0x22 and the third is returned sign-extended. A replacement must preserve the clamp bounds, scale, saturation values, field placement, and return value.

## Unresolved

- Owners of fourteen functions are unknown and left as UnknownObject: 0x0040FDD0 (array destructor; element-count header at this-1 and the 53-dword sub-object at +0xD4 are unproven), 0x00411680 (537 word-pair (1,0) table), 0x004328E0 (string array), 0x0044F640 (cursor manager), 0x0045B480 (8-entry string/payload table), 0x0045BB00 (strided float scan), 0x0045CBF0 (short array lookup), 0x0045E5B0 (sentinel search), 0x00460C60 (bulk reinit), 0x004912F0 (short-array zero thunk), 0x00497F90 (string match search).
- The bounded array accessors split into two header layouts (count@+0x0/ptr@+0x4 vs count@+0x8/ptr@+0xC) with three element strides (8, 28, 108); 0x004582A0 reads the +0x0/+0x4 dwords in the reverse role assignment to 0x0042DC80/0x0042DCA0. The cluster prelabels call them structural twins, but common ownership of these layouts is not proven by the packet.
- The three collision functions are proposed as separate single-method classes because they operate on distinct object layouts (local tessellation buffers, a +0x70/+0x71 responder struct, a +0x714/+0x71C zone list struct); the shared scope and overlapping collision callee graph are thematic, not ownership evidence.
- VectorMathOps groups three helpers whose this-role differs: 0x00456110/0x00456130 use this as the destination struct, while 0x0045EB00 uses this as the read-only source vector and writes to a2. Common ownership is unproven.
- The sub_44B110-derived permutation index (0..4) driving the jump table 0x0044B8F4 and the case semantics of the 0x0044B370 output switch are inferred from the switch body, not externally corroborated.
- The 104-element network-session table identity behind 0x0045E5B0 and 0x00460C60 (sentinels at +0x1D4 and +0x3E18, plus parallel 140-byte and 218-dword struct arrays) is not established; the -1 sentinel choice is caller-owned.
- Semantic meanings of payloads are caller-dependent and not evidenced: the (1,0) word pairs, the 5.0 payload float in 0x0045B480, the >0.0 threshold and 4-cap in 0x0045BB00, the 92-byte slice layout, the 20-byte cursor-slot stride in 0x0044F640, and the 104 per-byte flag fields in 0x00464B40.
- Read-only globals flagged by packet facts but absent from the decompiled bodies are unexplained: flt_59E440 (0x0045BB00, 0x0045CBF0), flt_59E828/flt_5ACC98/flt_5ACC9C (0x004B2480), dword_59F07C (0x0045B480).
- strcmp is called by the 0x0045B480 scan loop but is absent from the packet callee list; the comparison helper invoked through *this + 13004 by 0x004BBED0 is absent from the packet callee list, so neither has a callee evidence ref.
- The element structures behind 0x004CB5E0 (handle at v5[0], invalid marker at v5[1]) and 0x00497F90 (20-dword entries, separator character in dword_5CC79C, prefix vs exact match) are not defined by the functions themselves.
- Callers of several functions are unexamined and would resolve ownership: GraphicsResourceDestructor (0x0040FB30), VehicleSetupValueFormatter (0x0042F470), CarSelectionStateMachine (0x00434460), SteeringInterpolationCameraFollow (0x00434D60), BufferAllocCopy (0x004582E0), sub_44F4E0 (0x0044F4E0), SynchronizeWithServer (0x00464290), sub_465300 (0x00465300), sub_4B3400 (0x004B3400).
- The 13004-byte offset from *this in 0x004BBED0/0x004BBF70 reaches an unidentified comparison base in a parent container object.
- Whether the threshold-sorted structure in 0x004B9000 is a strict binary tree or a doubly-linked sorted list is not fully resolvable; the message tag interpretation (0x20000000 mask, 6-bit subtype, low-byte slot index) is recovered from raw source only.
- All classes are worker-proposed names for groupings of functions with unknown original ownership; they are DERIVED/GUESS proposals and must not be treated as recovered source types.
