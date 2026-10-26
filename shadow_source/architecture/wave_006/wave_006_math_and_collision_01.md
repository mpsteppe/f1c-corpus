# MathAndCollisionUtilities

Scope: `math_and_collision`  
Trust: `DERIVED`

This proposal groups 26 validated functions into 25 DERIVED classes for the math_and_collision scope. Zero functions share a proven owner object; the only defensible merge is ObjectContainerWalker (0x00406F90 and 0x00407070), whose sibling passes walk the same array (this+0x48/0x4C) and linked list (this+0x18/0x20) and differ only in the dispatched vtable slots. The two ArrayRemoveByValue lookalikes (0x004BD8C0 vs 0x004BD970) are kept as separate classes because their count/data offsets differ (+0x4/+0x8 vs +0x10/+0x14) and no common ownership is proven. Math helpers (0x0050CBB6, 0x0050CDFF, 0x004ED380, 0x004DD450) carry their own this-relative field layout per the packet's framing. CollisionState (0x00464D30) exposes the richest structure: four linked-list heads plus a 560-byte-stride sensor array. All owner identities, dispatched virtual methods, and the semantic meaning of most fields remain unresolved.

## Function roles

- `0x00404030` **VectorMathHelper** — Pure zero-vector predicate over a two-vector compound: TRUE when any of five tested float components is non-zero, FALSE only when all five are exactly 0.0.
- `0x00406F90` **ObjectContainerWalker** — Container walk dispatching vtable+8 on array entries and vtable+12 on linked-list nodes; returns the final linked-list node pointer.
- `0x00407070` **ObjectContainerWalker** — Sibling container walk dispatching vtable+16 on array entries and vtable+20 on linked-list nodes; alternative processing pass over the same two containers.
- `0x004071F0` **PositionVolumeOwner** — Writes a 3-component position/volume vector at this+0x7C/+0x80/+0x84 and delegates to ShortComputation_7d40 (0x00407D40), returning its result.
- `0x0040A610` **SubObjectArrayOwner** — Indexed sub-object accessor (indices 0..8 over fields this+0x10..this+0x30) dispatched through jump table jpt_40A61B; out-of-range index returns 0.
- `0x00410AD0` **SlotArrayOwner** — Inserts a pointer into the next free slot of a growable pointer array (slot base this+0x8, count this+0x0), writes the previous count into the node, increments the count, and returns the inserted pointer.
- `0x004319C0` **ParameterArrayOwner** — Stores a float into a parameter array at element index a2+1846 and sets the parallel per-element dirty byte at offset a2+7380 to 1; returns a2.
- `0x00464D30` **CollisionState** — Collision/physics state reset: stores the owner pointer, resets the timer, walks and frees four linked lists, reinitializes a 560-byte-stride sensor array, and clears trailing counters.
- `0x0046C7B0` **IndexedArrayManager** — Insert-or-append (stdcall) over one of two 104-entry global arrays selected by a1, using a -1 sentinel for the used count and shifting the tail right for positional inserts.
- `0x00475D90` **CollisionDebugView** — Draws a 2D debug rectangle outline plus a collision-parameter visualization (horizontal bars or center gauge) selected by the parameter selector at this+0x118.
- `0x0047A080` **ParameterClampController** — Retrieves a value via the dword_7CD8C0 dispatch interface (command 8) and, when the enable flag at this+0x100 is set, clamps that value across a global 27-dword-element array.
- `0x00496280` **NoiseTableOwner** — Fills the 16 consecutive floats at this+0x162C with the fixed uniform sequence 0.0, 0.0625, ..., 0.9375, each value passed through sub_5881F0 before being stored.
- `0x004BA980` **ElementArrayOwner** — Allocates a count-prefixed array of 884-byte elements (2 elements when the selector argument is 0, else 0), initializes each element, and stores the element-array pointer into *this.
- `0x004BD8C0` **IntArrayOwnerA** — Swap-removes a value from an integer array (count at +0x4, data at +0x8); returns the removed index or the count when the value is absent.
- `0x004BD970` **IntArrayOwnerB** — Swap-removes a value from an integer array (count at +0x10, data at +0x14); same semantics as 0x004BD8C0 but a distinct object base, kept separate per no proven common ownership.
- `0x004BD9B0` **DynamicIntArray** — Appends a 4-byte element to a growable array; when count equals capacity it grows capacity by 8, reallocates, copies, and frees the old buffer; returns the index at which the element was stored.
- `0x004BDFE0` **GridMatrixOwner** — Clears an 8x8 dword grid (9-dword stride, first cell at this+0x4) and resets the cell counter at this+0x904 to 0; runs per-frame via caller 0x00410980.
- `0x004D7AD0` **SlotArrayInitOwner** — Initializes an interleaved 3-slot DWORD structure with an unconditional 3-iteration loop writing 0 to two fields (this+0x18, this+0x24) and -1 to two earlier fields per iteration.
- `0x004D9290` **IDTypePermissionMatrix** — Jump-table permission predicate over index 0-24 and mode 1-5: mode 1 permits a 12-index subset, mode 2 permits a 17-index subset, modes 3-5 permit every index; modes outside 1-5 are denied.
- `0x004DD450` **FloatVectorInit** — Thin initializer writing 1.0f (1065353216) at this+0x0 and zeroing this+0x4..this+0x10 (a 20-byte block); returns the this pointer unchanged.
- `0x004DFCA0` **DualArrayDestructorLoopFree** — Backward cleanup of an 11-element dual-array structure (187-dword stride from this+2804) via DualArrayDestructor, then a conditional free of the trailing pointer at this+0x90.
- `0x004E3050` **ArrayCleanupOwner** — Cleanup of four cluster storage arrays at a 296-byte stride starting at this+0x1F4: zero the preceding count, free the array when non-null, then zero the pointer.
- `0x004ED380` **AnisoVectorTripleProduct** — Branch-free anisotropic scalar triple product: (a2 x a3) with each component scaled by a per-axis factor at this+0x3528/0x352C/0x3530, dotted with a2, plus a bias term at this+0x3518.
- `0x00508867` **TextureEncode16BitMatrix** — Builds a 16-bit texel word per vertex (low byte BT.709 luminance, high byte alpha, both scaled by 255) into 4x4 tile blocks at this+0x2C over this+0x1058 vertices.
- `0x0050CBB6` **F_4x4MatrixMultiply** — Row-major 4x4 float matrix multiply (a2 * a3 into a1); when a1 aliases either input the product is computed into a stack temporary and copied back; returns a1.
- `0x0050CDFF` **MatrixTranspose4x4** — 4x4 float matrix transpose from a2 into a1: six off-diagonal symmetric pairs swapped unconditionally, diagonal copied only when a1 != a2 (in-place support); returns a1.

## Proposed classes

### VectorMathHelper

Pure boolean zero-vector predicate over a two-vector compound; returns TRUE when any tested component is non-zero.

Methods: `0x00404030`

- `this+0x00000000` `float vector_a_x` (read, DERIVED)
- `this+0x00000008` `float vector_a_z` (read, DERIVED)

### ObjectContainerWalker

Walks two owned object containers (20-byte-stride pointer array at this+0x48 with count at this+0x4C, and a singly linked list with head at this+0x18 and iterator at this+0x20), dispatching a virtual method per entry; the two sibling passes dispatch different vtable slots (array+8/list+12 vs array+16/list+20).

Methods: `0x00406F90`, `0x00407070`

- `this+0x00000018` `void * linked_list_head` (read, DERIVED)
- `this+0x00000020` `void * linked_list_iterator` (read_write, DERIVED)
- `this+0x00000048` `void * array_base` (read, DERIVED)
- `this+0x0000004C` `int array_count` (read, DERIVED)
- `*(this+0x18)+0x00000000` `void * head_first_dword` (read, GUESS)
- `*(*(this+0x18)+0x0)+0x0000000C` `function * virtual_method_slot_12` (read, GUESS)
- `*(*(this+0x18)+0x0)+0x00000014` `function * virtual_method_slot_20` (read, GUESS)

### PositionVolumeOwner

Writes a 3-component position/volume vector at this+0x7C/+0x80/+0x84 and delegates further processing to ShortComputation_7d40 (0x00407D40), returning its result.

Methods: `0x004071F0`

- `this+0x0000007C` `float position_volume_0` (write, DERIVED)
- `this+0x00000080` `float position_volume_1` (write, DERIVED)
- `this+0x00000084` `float position_volume_2` (write, DERIVED)

### SubObjectArrayOwner

Indexed accessor over nine sub-object slots (this+0x10..this+0x30); indices 0..8 return the slot pointer, out-of-range returns 0; compiled to a switch through jpt_40A61B.

Methods: `0x0040A610`

- `this+0x00000010` `void * sub_object_slot_0` (read, DERIVED)
- `this+0x00000014` `void * sub_object_slot_1` (read, DERIVED)
- `this+0x00000018` `void * sub_object_slot_2` (read, DERIVED)
- `this+0x0000001C` `void * sub_object_slot_3` (read, DERIVED)
- `this+0x00000020` `void * sub_object_slot_4` (read, DERIVED)
- `this+0x00000024` `void * sub_object_slot_5` (read, DERIVED)
- `this+0x00000028` `void * sub_object_slot_6` (read, DERIVED)
- `this+0x0000002C` `void * sub_object_slot_7` (read, DERIVED)
- `this+0x00000030` `void * sub_object_slot_8` (read, DERIVED)

### SlotArrayOwner

Growable pointer-slot insert: the node pointer is stored at slot this[count] of the array at this+0x8, the previous count is written into the node, and the count at this+0 is incremented.

Methods: `0x00410AD0`

- `this+0x00000000` `int element_count` (read_write, DERIVED)
- `this+0x00000008` `void ** slot_array_base` (read, DERIVED)

### ParameterArrayOwner

Writes a float into a parallel parameter array (element index a2+1846, i.e. byte offset 7384+4*a2) and marks the corresponding per-element dirty byte at offset a2+7380; returns the index a2.

Methods: `0x004319C0`


### CollisionState

Collision/physics tracking object whose reset stores the owner pointer at this+0x0, resets the timer, walks and frees four linked lists (heads at 0x6C, 0x7C, 0xE5B0, 0xE5C0), reinitializes a collision-sensor array (560-byte stride from this+0x8C), and clears trailing list/counter state.

Methods: `0x00464D30`

- `this+0x00000000` `void * owner_ref` (write, DERIVED)
- `this+0x00000060` `float clear_field_24` (write, DERIVED)
- `this+0x00000064` `float scalar_one_field_25` (write, DERIVED)
- `this+0x00000068` `float clear_field_26` (write, DERIVED)
- `this+0x0000006C` `void * linked_list_1_head` (write, DERIVED)
- `this+0x00000070` `void * linked_list_1_trailing` (write, DERIVED)
- `this+0x00000074` `void * linked_list_1_trailing_2` (write, DERIVED)
- `this+0x00000078` `void * linked_list_1_trailing_3` (write, DERIVED)
- `this+0x0000007C` `void * linked_list_2_head` (write, DERIVED)
- `this+0x00000080` `void * linked_list_2_trailing` (write, DERIVED)
- `this+0x00000084` `void * linked_list_2_trailing_2` (write, DERIVED)
- `this+0x00000088` `void * linked_list_2_trailing_3` (write, DERIVED)
- `this+0x0000E40C` `int sensor_state_clear` (write, DERIVED)
- `this+0x0000E5B0` `void * linked_list_3_head` (write, DERIVED)
- `this+0x0000E5B4` `void * linked_list_3_trailing` (write, DERIVED)
- `this+0x0000E5B8` `void * linked_list_3_trailing_2` (write, DERIVED)
- `this+0x0000E5BC` `void * linked_list_3_trailing_3` (write, DERIVED)
- `this+0x0000E5C0` `void * linked_list_4_head` (write, DERIVED)
- `this+0x0000E5C4` `void * linked_list_4_trailing` (write, DERIVED)
- `this+0x0000E5C8` `void * linked_list_4_trailing_2` (write, DERIVED)
- `this+0x0000E5CC` `void * linked_list_4_trailing_3` (write, DERIVED)
- `*(this+0x70)+0x00000004` `void * list_1_node_next` (read, GUESS)
- `*(this+0x80)+0x00000004` `void * list_2_node_next` (read, GUESS)
- `*(this+0xE5B4)+0x00000004` `void * list_3_node_next` (read, GUESS)
- `*(this+0xE5C4)+0x00000004` `void * list_4_node_next` (read, GUESS)

### IndexedArrayManager

Insert-or-append (stdcall) over one of two 104-entry global pointer arrays; a zero selector picks dword_7CD470 and a non-zero selector picks dword_7CD2B8. Scans the -1 sentinel for the used count, appends at the first free slot or shifts the tail right to insert positionally.

Methods: `0x0046C7B0`


### CollisionDebugView

Draws a 2D debug rectangle outline and a collision-parameter visualization (horizontal bars or a center gauge line) driven by the selector at this+0x118 and by global collision-configuration values.

Methods: `0x00475D90`

- `this+0x00000118` `int collision_parameter_selector` (read, DERIVED)

### ParameterClampController

When the enable flag byte at this+0x100 is set, retrieves a value through the this vtable (slot +0xB4) after fetching a source object through the dword_7CD8C0 dispatch interface (command 8), then clamps the value across a global array of 27-dword elements from unk_7D1448 up to flt_7D17A8.

Methods: `0x0047A080`

- `this+0x00000000` `void * vtable_ptr` (read, DERIVED)
- `this+0x00000100` `bool enable_flag` (read, DERIVED)
- `obj+0x000000B4` `function * vtable_value_getter_slot` (read, DERIVED)

### NoiseTableOwner

Fills the 16 consecutive floats at this+0x162C with the fixed uniform sequence 0.0, 0.0625, ..., 0.9375, each value passed through sub_5881F0 before being stored.

Methods: `0x00496280`

- `this+0x0000162C` `float[16] uniform_step_table` (write, DERIVED)

### ElementArrayOwner

Allocates a count-prefixed array of 884-byte elements (2 elements when the selector argument is 0, else 0), initializes each element, and stores the element-array pointer into *this (0 on allocation failure).

Methods: `0x004BA980`

- `this+0x00000000` `void * array_ptr` (write, DERIVED)

### IntArrayOwnerA

Swap-remove of a value from an integer array whose element count is at +0x4 and data pointer at +0x8; returns the removed index or the count when the value is absent.

Methods: `0x004BD8C0`

- `this+0x00000004` `int element_count` (read_write, DERIVED)
- `this+0x00000008` `int * data_ptr` (read_write, DERIVED)

### IntArrayOwnerB

Swap-remove of a value from an integer array whose element count is at +0x10 and data pointer at +0x14; same swap-remove semantics as IntArrayOwnerA but a distinct object base kept separate because no common ownership is proven.

Methods: `0x004BD970`

- `this+0x00000010` `int element_count` (read_write, DERIVED)
- `this+0x00000014` `int * data_ptr` (read_write, DERIVED)

### DynamicIntArray

Growable array of 4-byte elements tracking capacity at +0x18, count at +0x1C, and buffer pointer at +0x20; append grows capacity by exactly 8 when full, reallocates through OperatorNewNhMallocWrapper, copies, frees the old buffer, and returns the stored index.

Methods: `0x004BD9B0`

- `this+0x00000018` `int capacity` (read_write, DERIVED)
- `this+0x0000001C` `int element_count` (read_write, DERIVED)
- `this+0x00000020` `int * buffer_ptr` (read_write, DERIVED)

### GridMatrixOwner

Per-frame clear of an 8x8 dword grid stored at a 9-dword stride starting at this+0x4, followed by a reset of the cell counter at this+0x904 to 0; invoked by caller 0x00410980.

Methods: `0x004BDFE0`

- `this+0x00000004` `int * grid_cell_base` (write, DERIVED)
- `this+0x00000904` `int cell_count` (write, DERIVED)

### SlotArrayInitOwner

Initializes an interleaved 3-slot DWORD structure: an unconditional 3-iteration loop writes 0 to two fields (this+0x18, this+0x24) and -1 to two earlier fields per iteration.

Methods: `0x004D7AD0`

- `this+0x00000018` `int slot_field_a` (write, DERIVED)
- `this+0x00000024` `int slot_field_b` (write, DERIVED)

### IDTypePermissionMatrix

Jump-table permission predicate over index 0-24 and mode 1-5: mode 1 permits a 12-index subset {1,3,6,7,9,10,11,12,20,21,22,23}, mode 2 permits a 17-index subset {0,1,6,7,8,9,10,11,12,13,14,15,16,17,18,19,24}, modes 3-5 permit every index 0-24; modes outside 1-5 are denied.

Methods: `0x004D9290`


### FloatVectorInit

Initializer writing a 20-byte block: 1.0f (1065353216) at this+0x0 and zeros at this+0x4, +0x8, +0xC, +0x10; returns the this pointer unchanged.

Methods: `0x004DD450`

- `this+0x00000000` `float value_one` (write, DERIVED)
- `this+0x00000004` `float component_1` (write, DERIVED)
- `this+0x00000008` `float component_2` (write, DERIVED)
- `this+0x0000000C` `float component_3` (write, DERIVED)
- `this+0x00000010` `float component_4` (write, DERIVED)

### DualArrayDestructorLoopFree

Backward cleanup of an 11-element dual-array structure (187-dword stride, first element at this+2804) via DualArrayDestructor, followed by a conditional free of the trailing pointer at this+0x90 through FreeWrapper_7bcf.

Methods: `0x004DFCA0`

- `this+0x00000090` `void * trailing_heap_ptr` (read_write, DERIVED)

### ArrayCleanupOwner

Cleanup of four cluster storage arrays at a 296-byte (74-dword) stride starting at this+0x1F4: zero the count field preceding each pointer, free the array when non-null, then zero the pointer; invoked from VehicleResetClear.

Methods: `0x004E3050`

- `this+0x000001F4` `void * cluster_array_ptr_0` (read_write, DERIVED)

### AnisoVectorTripleProduct

Branch-free anisotropic scalar triple product: the cross product a2 x a3 has each component scaled by a per-axis factor at this+0x3528/+0x352C/+0x3530, is dotted with a2, and a bias term at this+0x3518 is added; part of an anisotropic force/spring computation.

Methods: `0x004ED380`

- `this+0x00003518` `float bias_term` (read, DERIVED)
- `this+0x00003528` `float anisotropic_scale_x` (read, DERIVED)
- `this+0x0000352C` `float anisotropic_scale_y` (read, DERIVED)
- `this+0x00003530` `float anisotropic_scale_z` (read, DERIVED)

### TextureEncode16BitMatrix

Builds a 16-bit texel word per vertex (low byte BT.709 luminance of RGB at a4+8/+4/+0 scaled by 255, high byte alpha at a4+12 scaled by 255, both added to the tile value at +4*(v4&3)) into a 4x4 tile block at this+0x2C over this+0x1058 vertices; optionally converts the vertex format first.

Methods: `0x00508867`

- `this+0x0000002C` `int * tile_base` (read, DERIVED)
- `this+0x00001048` `int format_conversion_flag` (read, DERIVED)
- `this+0x00001058` `int vertex_count` (read, DERIVED)

### F_4x4MatrixMultiply

Row-major 4x4 float matrix multiply (a2 * a3 into a1); each output element is the dot product of one row of a2 with one column of a3; when a1 aliases a2 or a3 the product is computed into a 0x40-byte stack temporary and copied back via qmemcpy; returns a1.

Methods: `0x0050CBB6`

- `this+0x00000000` `float matrix_cell_r0c0` (write, DERIVED)
- `this+0x00000004` `float matrix_cell_r0c1` (write, DERIVED)
- `this+0x00000008` `float matrix_cell_r0c2` (write, DERIVED)
- `this+0x0000000C` `float matrix_cell_r0c3` (write, DERIVED)
- `this+0x00000010` `float matrix_cell_r1c0` (write, DERIVED)
- `this+0x00000014` `float matrix_cell_r1c1` (write, DERIVED)
- `this+0x00000018` `float matrix_cell_r1c2` (write, DERIVED)
- `this+0x0000001C` `float matrix_cell_r1c3` (write, DERIVED)
- `this+0x00000020` `float matrix_cell_r2c0` (write, DERIVED)
- `this+0x00000024` `float matrix_cell_r2c1` (write, DERIVED)
- `this+0x00000028` `float matrix_cell_r2c2` (write, DERIVED)
- `this+0x0000002C` `float matrix_cell_r2c3` (write, DERIVED)
- `this+0x00000030` `float matrix_cell_r3c0` (write, DERIVED)
- `this+0x00000034` `float matrix_cell_r3c1` (write, DERIVED)
- `this+0x00000038` `float matrix_cell_r3c2` (write, DERIVED)
- `this+0x0000003C` `float matrix_cell_r3c3` (write, DERIVED)

### MatrixTranspose4x4

Row-major 4x4 float matrix transpose from a2 into a1: the six off-diagonal symmetric pairs are unconditionally swapped via temporaries; the four diagonal elements (+0x00, +0x14, +0x28, +0x3C) are copied only when a1 != a2, giving in-place support; returns a1.

Methods: `0x0050CDFF`

- `this+0x00000000` `float matrix_cell_r0c0` (read_write, DERIVED)
- `this+0x00000004` `float matrix_cell_r0c1` (read_write, DERIVED)
- `this+0x00000008` `float matrix_cell_r0c2` (read_write, DERIVED)
- `this+0x0000000C` `float matrix_cell_r0c3` (read_write, DERIVED)
- `this+0x00000010` `float matrix_cell_r1c0` (read_write, DERIVED)
- `this+0x00000014` `float matrix_cell_r1c1` (read_write, DERIVED)
- `this+0x00000018` `float matrix_cell_r1c2` (read_write, DERIVED)
- `this+0x0000001C` `float matrix_cell_r1c3` (read_write, DERIVED)
- `this+0x00000020` `float matrix_cell_r2c0` (read_write, DERIVED)
- `this+0x00000024` `float matrix_cell_r2c1` (read_write, DERIVED)
- `this+0x00000028` `float matrix_cell_r2c2` (read_write, DERIVED)
- `this+0x0000002C` `float matrix_cell_r2c3` (read_write, DERIVED)
- `this+0x00000030` `float matrix_cell_r3c0` (read_write, DERIVED)
- `this+0x00000034` `float matrix_cell_r3c1` (read_write, DERIVED)
- `this+0x00000038` `float matrix_cell_r3c2` (read_write, DERIVED)
- `this+0x0000003C` `float matrix_cell_r3c3` (read_write, DERIVED)

## Compatibility contracts

- **CollisionStateListAndSensorReset** — CollisionState::Reset (0x00464D30) must empty and null-terminate the four linked lists at this+0x6C/+0x7C/+0xE5B0/+0xE5C0 and reinitialize the collision-sensor array (560-byte stride starting at this+0x8C) via CollisionSensorInit (0x00464A40); a replacement must be able to free per-list nodes through the same free wrapper and reset the timer.
- **GrowableIntArrayAppend** — Appending to the dynamic integer array (0x004BD9B0) when count equals capacity must grow capacity by exactly 8 elements, reallocate through OperatorNewNhMallocWrapper, copy the existing elements, free the old buffer, and return the previous count as the new element's index.
- **IndexedArraySentinelInsert** — The two 104-entry insert-or-append arrays (dword_7CD470 / dword_7CD2B8) use -1 as the free-slot sentinel; positional inserts shift the tail right one slot, appends write the first free slot, and a full array returns 0. A replacement must preserve the sentinel convention, the 104-entry bound, and the shift behavior.
- **Matrix4x4InPlaceSupport** — F_4x4MatrixMultiply (0x0050CBB6) must tolerate an output buffer that aliases either input (temporary-then-copy), and MatrixTranspose4x4 (0x0050CDFF) must support in-place transposition by copying the diagonal only when a1 != a2.
- **IDTypePermissionPredicate** — The permission predicate (0x004D9290) accepts index 0-24 under mode 1-5 with fixed per-mode permitted subsets (mode 1: 12 indices; mode 2: 17 indices; modes 3-5: all indices); modes outside 1-5 are denied. A replacement must reproduce the exact index subsets.

## Unresolved

- Owner object types are unknown for every function in this packet; all class boundaries are DERIVED single-function groupings except ObjectContainerWalker, whose two sibling passes share the same field layout.
- ZeroVectorCheck: global flt_59E440 (ZeroThreshold) is referenced in the facts but the raw source compares against the literal 0.0; its exact role is not resolvable from this packet.
- ZeroVectorCheck: the meaning of the tested component layout (a1 skipping +0x4) depends on the caller's data structure, which this packet does not establish.
- ObjectContainerWalker / ArrayLinkedListVirtualDispatchIterator: the identity of the dispatched virtual methods (vtable+8/+12 and vtable+16/+20) is unknown; fields this+0x24 and this+0x28 have no source-level reference in either function.
- ObjectContainerWalker: the head/node field layout (first dword, vtable slots +12/+20, next at +4) is GUESS; equal offsets across different walked objects are kept on separate bases.
- SetPositionVolumeVector: semantics of parameters a2/a3 and of the delegated computation at 0x00407D40 are unresolved; the position/volume reading of the three copied components is unverified.
- SubObjectArrayAccessor: the meaning of the nine sub-object slots (this+0x10..this+0x30) and the owning object type are not identifiable; the legacy ABI label carries no semantic information.
- ArraySlotInsert: no growth or capacity handling is present here; whether the slot array at this+0x8 is pre-allocated or resized by a separate path is not visible in this packet.
- ParameterArraySetterWithDirtyFlag: the float array base at element 1846 (byte offset 7384) and the dirty byte array at offset 7380 are parallel arrays without an independently proven layout; the owning object is unknown.
- CollisionStateReset: the four packet guards (guard:0..guard:3, fields 0x74/0x84/0xE5B8/0xE5C8 == 0) are the trailing list-state fields cleared after each walk; the raw source tests the traversal pointer for null, so the guard-to-loop mapping is a reconstruction choice, not packet-stated.
- CollisionStateReset: the linked-list node layout (next at node+4, flag byte at node+8, payload at node+0) is inferred from the uniform walk/free pattern and is not independently evidenced.
- CollisionStateReset: the sensor do/while loop's iteration bound is obscured by the decompiler variables v10/v11; only the start (this+0x8C) and the 560-byte stride are visible.
- CollisionStateReset: the semantics of the input value stored at this+0x0 (existing-analysis label postProcessInput, CONFIRMED in the fill) are not independently reproduced here.
- IndexedArrayInsertWithShift: the element semantics of the two selected 104-entry arrays and the meaning of the values they hold are not documented; why selector 0 picks dword_7CD470 while non-zero picks dword_7CD2B8 is unknown.
- CollisionDebugRectangleDraw: globals flt_59E440 and flt_59E450 are listed as referenced in the deterministic facts but do not appear in the raw decompiled text; their role is unresolved.
- CollisionDebugRectangleDraw: the semantic meaning of the selector values mapped to flt_7CD45C/flt_7CD2B0/flt_7CD610 is inherited from existing analysis, not independently verified here.
- ParameterValueClampingAcrossArray: the element structure of the unk_7D1448 array is unknown beyond a 27-dword stride; the reading of the third and fourth dwords as clamp bounds is inferred from the comparison order only.
- ParameterValueClampingAcrossArray: the dword_7CD8C0 interface identity, the object type returned by command 8, and what the vtable slot +0xB4 value represents are unknown.
- FloatArrayInitUniform: the ABI lead name implies randomization but the source writes a fixed uniform sequence; sub_5881F0's contract and the role of global flt_59E9E0 are unknown.
- AllocateElementArrayWithHeader: the element type, the meaning of the 884-byte element size, the a2 selector semantics (2 vs 0 elements), and the behavior of PassthroughWrapper_f670 are not evidenced here.
- ArrayRemoveByValue (both 0x004BD8C0 and 0x004BD970): the identity of the owning objects is unknown, and whether swap-remove preserves array order is unstated.
- DynamicArrayAppendWithRealloc: the owning class is unknown; the capacity growth step of exactly 8 elements is a fixed source literal, not a configurable policy.
- MatrixClear: why the 8x8 grid uses a 9-dword stride (one extra dword per row) is unresolved; the owner class is unknown.
- InitializeSlotArray: the full slot layout is unknown (the packet names only this+0x18 and this+0x24); no static callers are recorded.
- IDTypePermissionMatrix: the semantic meaning of index a1 (0-24) and mode a2 (1-5) is not confirmed; the 'race mode' interpretation in prior analysis is DERIVED, and the jump-table dispatch globals are not independently verified.
- FloatVectorInit: the concrete owner type of the 20-byte block is unknown; the float-vector reading (1.0f followed by zeroed components) is DERIVED from the literal pattern.
- DualArrayDestructorLoopFree: the 11 dual-array element types and the 748-byte element layout are not defined; what the trailing pointer at this+0x90 owns is unknown.
- ArrayCleanup: the owning class and the layout of the four cluster storage arrays are unknown; the count field zeroed at *(v1-1) is not independently evidenced by the packet.
- AnisoVectorTripleProduct: the meaning of the anisotropic scale factors (0x3528/0x352C/0x3530) and the bias term (0x3518) depends on the owning object, unknown here.
- TextureEncode16BitMatrix: globals flt_59FEC8, flt_5ADB18, flt_5ADB1C, flt_5ADB20 are flagged as read in the facts but do not appear in the raw source, which uses inline float literals; the BT.709 weighting and 255.0 scale are inline, the 16-byte vertex stride is DERIVED, and the exact DXT format encoded is unstated.
- F_4x4MatrixMultiply / MatrixTranspose4x4: no owner class or static callers are in the packet; both operate on raw 16-float buffers. The cluster_copy prelabel (structural twin relationship to 0x005087A2 and each other) is DERIVED, not proven.
