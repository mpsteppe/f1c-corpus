# MathAndCollision

Scope: `math_and_collision`  
Trust: `DERIVED`

Reconstructs the math-and-collision layer from 26 validated functions. One DERIVED class CollisionMathUtility (0x004CBDD0) provides the ray-sphere intersection with sliding response over float triplets. Eight GUESS classes capture the defensible groupings: KeyframeArray (0x00457F90 alloc+init, 0x004582E0 deep copy) shares the 28-byte element layout with count at this+0x4 and payload at this+0x0 plus the arc-length precompute callee 0x00457EE0; ScalarDeletingArrayContainer (0x0040AC60, 0x0040B5C0) is the MSVC array-delete pattern over 160/208-byte elements with a2 bit flags (bit1 array, bit0 free); CollisionQueryDispatcher (0x00491C70, 0x00491CB0) allocates a resource-pool node and dispatches traversal against a base object before prepending the node to a list; FixedBucketArray (0x00490B00) constructs a fixed-capacity bucket array with a ZeroInitStateBlock (0x00491330) embedded at this+0x3C; CollisionConfigRegistry (0x00452B10) resolves collision/system config keys against 68 known global addresses; CollisionObjectManager (0x004B4A30) removes type-tagged collision objects and recycles nodes onto a global free list (0x008AB700). Thirteen functions have UNKNOWN owners and are kept unowned; notably the 316-byte-stride sub-object array release (0x004034D0) matches the track waypoint-array pattern seen in the generic_runtime_objects scope but that cross-scope link is outside this packet's evidence. No state-machine model is proposed: the face-edge proximity retry in 0x0044B110 and the tag refresh in 0x004BDB10 are iteration/dispatch, not evidenced transitions.

## Function roles

- `0x004034D0` **UnknownObject** — Releases a sub-object array referenced by this+0x134: reads the element count from the dword at array_ptr-4, walks the 316-byte-stride elements backward calling the per-element teardown stub 0x004B0170 on each, frees the allocation base (array_ptr-4) via FreeWrapper_7bcf, then zeroes count field this+0x130 and pointer field this+0x134 on both branches. Returns 0.
- `0x0040AC60` **ScalarDeletingArrayContainer** — Scalar-deleting destructor with array path: when a2 & 2, reads the element count from the allocation header at this[-1], walks the 160-byte-stride (40 dword) elements in reverse calling per-element destructor 0x004562A0, optionally frees the allocation base via FreeWrapper_7bcf when a2 & 1, and returns the base pointer; the single-element path runs the destructor once on this.
- `0x0040B5C0` **ScalarDeletingArrayContainer** — Scalar-deleting destructor over an object array: same a2 flag contract (bit1 array path, bit0 free) as 0x0040AC60, but walks 208-byte-stride (52 dword) elements in reverse calling per-element destructor 0x004584A0, frees the base via FreeWrapper_7bcf when flagged, and returns the base pointer; single-element path runs the destructor once.
- `0x00410AF0` **UnknownObject** — O(1) swap-with-last element removal: reads the index from *a2, decrements the element count at this[0], copies the last slot (array base this[2], offset 0x8, plus 4*newcount) over the removed slot, writes the removed index into the first dword of the object now occupying the removed slot, resets *a2 to -1, and returns the removed index. No guards. Called by ConditionalCleanupChain (0x0040F100), StateDependentUpdateDispatch (0x0040F130), LazyInitCallback (0x004E0D00).
- `0x00410B60` **UnknownObject** — Thin indexed delegation wrapper: reads the element index from the input struct at a2+4, computes the element pointer as this+0x10 + 36*index (36-byte stride), and delegates to 0x0040ED10 with that element pointer cast to float*. No branching. Frame path invoked by SceneRenderUpdate (0x004C6D90).
- `0x00410B80` **UnknownObject** — Linear ID search over an array of structs: element count at this+0x3C, search array base at this+0x44 with first element at base+208 and 0x318-byte stride, ID field at element+0x114 compared against a2; on match returns a pointer into the parallel result array at this+0x40 with 36-byte stride; returns 0 when the count is non-positive or no match. Per-frame tick path invoked by CollisionDetectionSystem (0x004EA970).
- `0x0044AF60` **UnknownObject** — Reads a permutation row for a requested axis index a3 (1/2/3) out of an axis-direction table a2 and writes six gathered DWORD coordinates into the caller buffer a1; when a4 is nonzero the row is read transposed. Returns the primary axis index for the requested permutation, or the passthrough a2 when a3 is outside the accepted set.
- `0x0044B110` **UnknownObject** — Proximity-based axis selector for the collision pipeline: packs the input first DWORD as an RGB color identifier via 0x00448EE0, gathers triangle-face vertices via 0x0044AF20, copies the capsule shape into the pipeline buffer via 0x0044B040, then tests each face edge via TriangleProximityTest 0x0044B090. More than one pass returns 0 (ambiguous); zero passes runs a three-way fallback that returns 4 when every edge still passes; a single resolved edge selects a permutation axis (2 or 3) via AxisPermutationMatrixRead 0x0044AF60 and re-validates two edges, retrying the whole selection on failure. Feeds BezierPatchTessellation (0x0044B370).
- `0x00452B10` **CollisionConfigRegistry** — Collision/system config key lookup and re-init: sets this[0]=1 (optimistic matched flag), compares a2 against 68 known global config addresses in an if/else chain, storing the matched global's address in this[7] (offset 0x1C) on equality, otherwise clears this[7] and this[0] and records failure. On a match writes the a3 value into the matched global at +8. Always runs SwapAndReinit 0x00452740 on the trailing field block (count 89), clears this[8] (offset 0x20), and returns 0 on match, -1 on no match. Called by 0x004530A0.
- `0x00457F90` **KeyframeArray** — Allocates and initializes a keyframe array from input 3D position data: guards a2 non-null and a3>=4 (else returns 1), runs utility initializer 0x00458020, stores the keyframe count at this+0x4, allocates 28*a3+4 bytes via OperatorNewNhMallocWrapper 0x00587C03 (4-byte count header plus 28-byte elements), writes the count into the header and the payload pointer at this+0x0, copies a3 DWORD-position triples into the elements, then pre-computes cumulative arc lengths via 0x00457EE0. Returns 0 on success, 1 on invalid input.
- `0x004582E0` **KeyframeArray** — Deep-copies a keyframe array: source described by a2 (pointer at a2[0], count at a2[1]); proceeds only when the pointer is non-null and count>=4. Runs utility initializer 0x00458020, stores the count into this[1] (offset 0x4), allocates 28*count+4 via 0x00587C03, writes the header word and payload pointer into this[0], resolves each source element through StridedArrayElementPointer 0x004582A0 and copies all 7 fields (+0..+20 dwords and +24 float) into the 28-byte destination elements, then recomputes cumulative arc lengths via 0x00457EE0. Returns this. Called by 0x00459330.
- `0x0045B950` **UnknownObject** — Unconditional configuration helper: calls 0x004DCFB0 with the global pointer 0x005C5B50 and parameter set (0x80000000, 0, 0.5, 0.0, 1.0, 1.0, flt_7CD200, 2, 0), then calls 0x004DD010 twice with the identical value 1060320051, and returns the 0x004DCFB0 result.
- `0x0048D0A0` **UnknownObject** — Collision position stepper wrapper: reads a float through the pointer stored at this+0x40 via FloatFieldAccessor 0x00498730, passes it together with this to CollisionPositionStepper 0x0048CB00, then performs a virtual dispatch through vtable entry 43 (offset 0xAC on obj). Linear, always returns 0.
- `0x00490B00` **FixedBucketArray** — Constructor for a fixed-capacity bucket-array struct: zeroes the thirteen state DWORDs at this+0x4..this+0x34 and clears this+0x38, initializes the embedded sub-object at this+0x3C through the thunk 0x004912F0 (forwarding to 0x00491330), stores the requested element count a2 into this+0x0, allocates 16*a2+4 bytes via 0x00587C03, zero-fills every element (four DWORDs), and stores the payload pointer at this+0x8 (or 0 on failure). Returns the struct pointer. Called by ObjectConstructor_1710 (0x00491710).
- `0x00491330` **ZeroInitStateBlock** — Zero-initializer for a short-array region on a _WORD-typed this: zeroes the words at offsets 0x0, 0x2, 0x4, 0x6 and 0x8, and the dword at offset 0xC (covering bytes 12..15). No reads, no globals, no callees; returns 0. Reached through the thunk at 0x004912F0 and called by LinkedListNodePrepend (0x00490AA0); the same zero-init is used for the FixedBucketArray embedded sub-object.
- `0x00491C70` **CollisionQueryDispatcher** — Broadphase query dispatch: forms a base pointer at *this + 12, allocates a resource-pool node via 0x00490940, runs CollisionBroadphaseTraversal 0x00491170 on the base pointer and the new node, prepends the node via LinkedListNodePrepend 0x00490AA0, and returns the traversal result char. Structural twin of 0x00491CB0.
- `0x00491CB0` **CollisionQueryDispatcher** — Query dispatch: forms a base pointer at *this + 28, allocates a resource-pool node via 0x00490940, dispatches 0x00491280 on the base pointer and the new node, prepends the node via LinkedListNodePrepend 0x00490AA0, and returns the dispatch result char. Structural twin of 0x00491C70.
- `0x00494C20` **UnknownObject** — Helper that packs four int arguments into a float vector, runs 2D line-rect clipping against it via 0x00494C80, and only when the clip reports a hit converts the clipped vector back to ints via 0x00553A20, otherwise returns the clip result. Called by UI rectangle-drawing helpers UICursorSelectionRectangleRenderWithInterpolatio (0x0045B660), ConditionalDraw (0x00475C80), F_2DRectangleDrawingWithOutline (0x00475D90), RectangleDrawingWithPattern (0x004972B0).
- `0x004B2C80` **UnknownObject** — Packs a 3D float vector into three signed 16-bit components written at this+0x9, this+0xB and this+0xD, each scaled by 64.0 and clamped (within +/-511.98001 truncate to int16, otherwise saturate to -32767 or 0x7FFF). The vector then feeds the classification pass (0x004B29F0, 0x004B2B90) and the bitfield update (0x004B2980, 0x004B2C20) whose result is returned. Invoked by EntityVisibilityGridManager (0x00465460).
- `0x004B4A30` **CollisionObjectManager** — Removes a collision object node from its type-specific sub-list and recycles it onto a global free list. Maps the top three tag bits (a2[0] >> 29) through the jump table 0x004B4B34 to a sub-list index 0..3, walks the sub-list via next pointers at node+4 until the payload at node+0 equals a2, unlinks the node (updating head at base+0, tail at base+4, pointer at base+8, count at base+12), frees the payload buffer when the flag byte at node+8 is non-zero and the node struct itself via FreeWrapper_7bcf, calls 0x004B47A0, then allocates a fresh 12-byte node pointing at a2 via 0x00587C03 and prepends it to the global free list (head 0x008AB700, empty-list state 0x008AB704/0x008AB708, counter 0x008AB70C). Returns 1 on success, 0 when not found. Called by 0x004B6190.
- `0x004B5E30` **UnknownObject** — __thiscall accumulator: sums 104 consecutive dwords of the receiver's int array starting at dword index 19 (byte offset 0x4C, stride 4) and returns the total. ABI label Sum_Array and the caller signal VehicleForceAerodynamicsComputation suggest a per-vehicle aggregate, but the owning class and the meaning of the 104 quantities are not evidenced in this packet.
- `0x004BAAC0` **UnknownObject** — Conditional array allocation: chooses the element count from the char flag a2 (64 when non-zero, else 32), allocates 12*count bytes via OperatorNewNhMallocWrapper 0x00587C03, initializes each 12-byte element via 0x004B4450 when the allocation succeeded, and stores the array pointer (or 0 on failure) into this+0x0. Returns this. Called by CarPhysicsStateInitializer (0x004B57F0) and 0x004B7860.
- `0x004BD900` **UnknownObject** — Appends one dword value to a dynamic integer array (capacity at this+0xC, count at this+0x10, data buffer pointer at this+0x14). When count equals capacity, grows capacity by 8, allocates a new buffer of 4*new_capacity bytes via 0x00587C03, copies the existing elements, frees the old buffer via FreeWrapper_7bcf (only when non-null), and repoints this+0x14. Stores the value at index count, increments count, and returns the pre-increment count. Called from 0x004BE010.
- `0x004BDB10` **UnknownObject** — Walks the tag list on this (element count at this+0x1C, pointer array at this+0x20 with 4-byte stride) and, for every element whose tag field at element+4 differs from a2, overwrites that tag with a2 and calls UIFocusChange 0x0054F7A0 with the element's UI handle (element+32) and 1. Returns the element count. Per-frame path invoked by SpriteGridRender (0x004BE4E0).
- `0x004CB5A0` **UnknownObject** — Swap-remove of an element from a flat array of pointers: reads the array base from this+0x68, decrements the element count at this+0x64, copies the last element into the removed slot, updates the moved element's own index field (+4 within the pointed-to element), marks the removed element handle invalid (-1), then calls the helper sub_558B30 with *a2 and returns its result.
- `0x004CBDD0` **CollisionMathUtility** — Ray-sphere intersection with sliding response: computes a vector from the ray point advanced by a3 along direction a2 to the sphere center a4, scaled by coefficient dword_5D3488. If the squared length is below threshold flt_5D348C, computes the intersection distance t_hit = sqrt(discriminant) - dot(relative, direction) and, when positive, slides the ray origin a1 forward by t_hit * a2. Operates on float triplets; returns void. Callers 0x004CB860 and 0x004CC1D0.

## Proposed classes

### CollisionMathUtility

Free-function collision math utilities: ray-sphere intersection with sliding contact response over float triplets.

Methods: `0x004CBDD0`

- `this+0x00000000` `float rayOriginX` (read_write, GUESS)
- `this+0x00000004` `float rayOriginY` (read_write, GUESS)
- `this+0x00000008` `float rayOriginZ` (read_write, GUESS)

### KeyframeArray

Owning holder for a keyframe array: allocates/initializes from position triples and deep-copies from a source array, both building a 4-byte count header plus 28-byte elements and pre-computing cumulative arc lengths.

Methods: `0x00457F90`, `0x004582E0`

- `this+0x00000000` `float* elementArray` (read_write, GUESS)
- `this+0x00000004` `int elementCount` (read_write, GUESS)

### ScalarDeletingArrayContainer

Scalar-deleting destructor pattern over object arrays (two instantiations with 160- and 208-byte elements): a2 bit1 selects the array path (count from the allocation header at this[-1], reverse destruction), bit0 selects whether the allocation is freed; returns the allocation base.

Methods: `0x0040AC60`, `0x0040B5C0`


### CollisionQueryDispatcher

Dispatches a collision/broadphase query: allocates a resource-pool node, runs a traversal or dispatch routine against an owned base object (at *this advanced by a per-method displacement, +12 or +28), and links the node into a shared list.

Methods: `0x00491C70`, `0x00491CB0`

- `this+0x00000000` `void* queryBase` (read, GUESS)

### FixedBucketArray

Constructor for a fixed-capacity bucket-array struct: zeroes a thirteen-dword state block (0x4..0x34 plus 0x38), initializes an embedded ZeroInitStateBlock sub-object at 0x3C, stores the element count at 0x0, and allocates a zero-filled 16-byte-per-element payload at 0x8.

Methods: `0x00490B00`

- `this+0x00000000` `int elementCount` (read_write, GUESS)
- `this+0x00000004` `dword[13] stateBlock` (write, GUESS)
- `this+0x00000008` `dword* elementArrayPayload` (read_write, GUESS)
- `this+0x0000003C` `ZeroInitStateBlock embeddedSubObject` (read_write, GUESS)

### ZeroInitStateBlock

Zero-initializer for a 16-byte short/dword state region: words 0x0..0x8 and dword 0xC. Used both for the FixedBucketArray embedded sub-object (via thunk 0x004912F0) and by LinkedListNodePrepend (0x00490AA0).

Methods: `0x00491330`

- `this+0x00000000` `word word0` (write, GUESS)
- `this+0x00000002` `word word1` (write, GUESS)
- `this+0x00000004` `word word2` (write, GUESS)
- `this+0x00000006` `word word3` (write, GUESS)
- `this+0x00000008` `word word4` (write, GUESS)
- `this+0x0000000C` `dword tailDword` (write, GUESS)

### CollisionConfigRegistry

Resolves a collision/system config key against 68 known global config addresses, stores the matched address, writes a value into the matched global's +8 field, and reinitializes a trailing 89-element field block.

Methods: `0x00452B10`

- `this+0x00000000` `int matchedFlag` (read_write, GUESS)
- `this+0x0000001C` `int matchedGlobalAddress` (read_write, GUESS)
- `this+0x00000020` `int clearedField` (write, GUESS)
- `this+0x00000024` `dword[89] trailingBlockStart` (read_write, GUESS)

### CollisionObjectManager

Collision object lifecycle: removes a type-tagged object node from its sub-list (selected by the top three tag bits via jump table 0x004B4B34) and recycles it onto the global free list (head 0x008AB700, empty-list state 0x008AB704/0x008AB708, counter 0x008AB70C) with 12-byte nodes (data+0, next+4, flag+8).

Methods: `0x004B4A30`


## Compatibility contracts

- **KeyframeArrayLayout** — The keyframe array is allocated as a 4-byte count header followed by 28-byte elements; the count is stored both in the header and at this+0x4, the payload pointer at this+0x0, and construction is guarded to a count of at least 4 with an allocation of 28*count+4 bytes. Cumulative arc lengths are recomputed after both allocation/init and deep copy.
- **ScalarDeletingArrayFlagContract** — The array-delete helpers 0x0040AC60 and 0x0040B5C0 share a flag contract on a2: bit1 selects the array path (element count read from the allocation header at this[-1], elements destroyed in reverse), bit0 selects whether the backing allocation is freed; the array path returns the allocation base pointer.
- **CollisionConfigKeyRegistry** — Config key resolution compares a2 against 68 known global config addresses, stores the matched global's address at this+0x1C, writes the a3 value into the matched global at +8, reinitializes a trailing 89-element field block, and returns 0 on match / -1 on no match.
- **CollisionObjectFreeListContract** — A global free list of 12-byte collision nodes (data+0, next+4, flag+8) lives at 0x008AB700 (head) with empty-list state at 0x008AB704/0x008AB708 and a counter at 0x008AB70C. Type-tagged sub-lists are selected by the top three bits of the payload dword via the jump table at 0x004B4B34; node removal maintains head/tail/pointer/count at the sub-list base and frees the payload buffer when the node+8 flag is set.
- **RaySphereIntersectionContract** — Ray-sphere intersection with sliding response uses the coefficient global 0x005D3488 and the threshold global 0x005D348C; on a hit the ray origin slides forward along the direction by t_hit. Whether the threshold is the sphere radius squared or a penetration tolerance is unproven.

## Unresolved

- 0x004034D0: the 316-byte element stride, the header word at array_ptr-4, and the per-element teardown stub 0x004B0170 are not semantically established; the stride and the 0x130/0x134 array bookkeeping match the track waypoint-array pattern seen in the generic_runtime_objects scope (TrackWaypointDatabase), but that cross-scope link is outside this packet's evidence and is not promoted here.
- 0x0040AC60 / 0x0040B5C0: the identity of the per-element destructors (0x004562A0, 0x004584A0) and the element types (160-byte vs 208-byte stride) are unproven; the legacy ABI labels (abi:lead) do not independently establish ownership.
- 0x00410AF0: legacy ABI name is Linked_List_Node_Removal but the source performs array swap-remove, not an unlink; the owner back-reference written into the removed object's first dword is inferred.
- 0x00410B60: the 36-byte element stride and the a2 input struct layout are arithmetic evidence only; the delegated callback 0x0040ED10 semantics are out of scope.
- 0x00410B80: the semantic names of the search array (this[17]/0x44), result array (this[16]/0x40) and ID field (0x114) are inferred from prior analysis, not proven in this scope.
- 0x0044AF60: the axis-direction table a2 (4-byte row pointers, 8-byte row elements) and whether the six gathered values are vertex coordinates or direction components depend on callers outside the packet.
- 0x0044B110: the exact loop bound of the per-edge proximity while loop is not restored by the decompiler; whether the returned index selects a response axis or a normal permutation depends on caller BezierPatchTessellation (0x0044B370); the no-edge-pass fallback retry state is an unconfirmed edge case.
- 0x00452B10: the 68 globals are only known by address; the meaning of writing a3 into the matched global's +8 field and of the SwapAndReinit count parameter (89) are defined by the callee, not here.
- 0x0045B950: the semantics of the 0x004DCFB0 parameter set (0x80000000 and float literals) and of the shared value 1060320051 are unknown.
- 0x0048D0A0: the transform applied by FloatFieldAccessor (0x00498730) and the meaning of the float at this+0x40 (time, force or scale input) are not independently confirmed; the vtable entry 43 dispatch implies an object with a virtual interface not defined here.
- 0x00490B00: the embedded sub-object at this+0x3C and the meaning of the thirteen zeroed state dwords are not identified; this+0x4 is zeroed here but the skeleton names it a counter/index without corroboration.
- 0x00491330: the dword write at 0xC overlaps the word slots beyond 0x8; whether the region is an array of shorts with a trailing dword or an aliased view is not decided; the thunk 0x004912F0 is a forwarder, listed as a caller rather than a distinct consumer.
- 0x00491C70 / 0x00491CB0: the object at *this and the +12/+28 displacements are unidentified; the a2..a5 allocator arguments are opaque; whether the traversal callee stores into or only reads the allocated node is not shown.
- 0x00494C20: the roles of a5 and a6 (forwarded, never consumed) and the exact coordinate mapping of the four packed ints are undocumented.
- 0x004B2C80: the three read-only globals (flt_59E708, flt_59E70C, flt_59E710) are flagged as read but never appear in the raw decompiled source; the skeleton's threshold names (SoundVolumeLowThreshold, FFBMinThreshold, FFB_SaturationThreshold) are not verifiable from this packet.
- 0x004B4A30: the semantic role of each sub-list (indices 0..3), the meaning of tag bits [31:29], the behavior for unhandled tags (default index -1), the roles of 0x008AB704/0x008AB708, and the payload flag byte at node+8 are unresolved.
- 0x004B5E30: the meaning of the 104 summed dwords (which per-vehicle quantities they aggregate) is not determinable; the packet prelabel describing a single-field getter does not match the actual 104-element sum loop; the caller signal VehicleForceAerodynamicsComputation is DERIVED only.
- 0x004BAAC0: the 12-byte element stride, the 64/32 counts, and WrapperPassThrough (0x004B4450) semantics are unknown.
- 0x004BD900: the owning object is unknown; the growth step (8) and element stride (4) are read from raw source only.
- 0x004BDB10: the guard term !(v10|v11) reads uninitialized registers (x87 artifact); the effective condition is element[1] != a2; parameters a3..a5 are declared but unused; the element layout (tag+4, UI handle+32) is reachable only through the element pointer.
- 0x004CB5A0: the helper sub_558B30 has no callee entry in the packet, so its address and semantics are not confirmed; there is no bounds check on the removed index; the helper relationship is described in text only.
- 0x004CBDD0: global flt_59E440 is listed as a read but never appears in the raw source; the a3 advance-amount semantics are inferred; whether dword_5D3488 is a restitution coefficient is DERIVED only.
