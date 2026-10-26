# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Reconstructs the generic runtime object layer from 23 validated functions. Three DERIVED classes carry the packet's named owners: SceneRenderBatch (0x0054EED0) inserts triangles into a 116-byte-slot batch and shares the this+0x1E0/0x1E4/0x1E8 descriptor region with the GUESS RenderListManager (0x0054F710) and RenderBufferEntryManager (0x0054FAE0); Mesh (0x0054D9F0) computes per-node bounding boxes and an animation-clock blend factor through nested GUESS MeshPart and MeshAnimation records; MeshDataDualFormat (0x00550F70) tears down two storage formats selected by format flags at +0x0; and BinkVideoDecoder (0x00551DD0) drives the four-pointer Bink API global block. One GUESS StringListOwner hosts three structurally identical 24-byte string-node appends (0x00549020, 0x005492F0, 0x005493B0) that differ only in their head offset (0xE8/0xF8/0xFC), with a shared StringNode24 node type. Remaining GUESS classes cover a tree-list mover, a 56-byte frame-node list, a doubly linked list, a triple-float query, a flag-bit clearer, a float-struct table initializer, two forwarding wrappers, a packet payload reader, a working-index setter, a parameter-table consumer, a flag/timer owner, a timer-capped node walker, and a font texture sheet analyzer. Several this+0x1E0/0x1E4/0x1E8 and this+0x13C offsets recur across different classes; common ownership is not proven, so equal offsets on different objects are kept as separate fields.

## Function roles

- `0x00549020` **StringListOwner** — Appends a 24-byte string node to the string list headed at this+0xE8: walks node next pointers at +0x14 to the tail (or treats the list as empty), allocates 24 bytes via OperatorNewNhMallocWrapper, zero-initializes the node via ShortComputation_8e00, strcpy's the caller string into the node buffer, links the node in, and returns the result of the sub_589901 normalize/register call.
- `0x00549170` **TreeStringListMover** — Walks the node list headed at this+0xE8 advancing through node+0x14; for each node runs RecursiveTreeStringSearch (0x0054BC60) to find a matching child, and when one is found moves it from the source list rooted at *this (LinkedListRemove 0x005452B0) to the target list (DoublyLinkedListAppend 0x005490B0). Returns the last append result.
- `0x005491D0` **FrameNode56List** — Appends a new 56-byte node to the singly linked list headed at this+0xF0 (next pointers at node+0x34). Walks to the tail when the head exists, allocates 56 bytes via OperatorNewNhMallocWrapper, zero-initializes each node via StructZeroInitWithBaseCall (0x0055D200), links it in, and returns the new node (or 0 on allocation failure).
- `0x005492F0` **StringListOwner** — Appends a 24-byte string node to the string list headed at this+0xF8: identical walk/alloc/init/copy/link pattern to 0x00549020, but with a different head offset. Allocates 24 bytes via OperatorNewNhMallocWrapper, initializes via ShortComputation_8e00, strcpy's the string, and returns the result of sub_589901.
- `0x005493B0` **StringListOwner** — Appends a 24-byte string node to the string list headed at this+0xFC: identical walk/alloc/init/copy/link pattern to 0x00549020, with a third head offset. Allocates 24 bytes via OperatorNewNhMallocWrapper, initializes via ShortComputation_8e00, strcpy's the string, and returns the result of sub_589901.
- `0x0054A270` **DoublyLinkedList** — Appends a node a2 to the tail of a doubly linked list headed at this+0x100 (node prev at +0x100, next at +0x104). On a non-empty list it walks to the tail and links a2 after it; on an empty list it sets this+0x100 = a2 and zeroes both a2 links. Returns the previous head, or the new node on an empty list.
- `0x0054B4A0` **TripleFloatQuery** — Triple float field query: writes this[11] (0x2C) to *a2, this[12] (0x30) to *a3 and this[13] (0x34) to *a4 when the corresponding output pointers are non-null, then returns a4. Called by DualMatrixTransformMultiply (0x0054B530) on the frame path.
- `0x0054C190` **FlagBitState** — Clears the low two flag bits (0x2 and 0x4) of the flag dword at this+0x3C by AND-ing with 0xFFFFFFF9. Unconditional thiscall with no callees; dispatched per element by sub_4A3390 and PerElementConditionalActionDispatcher (0x004A34A0) on the frame path.
- `0x0054C2D0` **FloatStructTableInit** — Initializes a 256-entry table of float structs at global unk_8BF740 by calling F_10FloatStructInitializer (0x0053B130) once per entry, advancing 26 DWORDs (104 bytes) per step, then returns the last initializer result.
- `0x0054D9F0` **Mesh** — Computes the axis-aligned bounding box and bounding sphere of a mesh: walks the mesh-node list (head this+0x13C, node processed flag +0x4, next +0x24), and per part (count this+0x118, base this+0x11C) transforms vertices through the global dword_8B8F24 device vtable, accumulates per-axis extrema, dispatches primitive handlers (0x0055E320/0x0055DA50/0x0055D900 and render-flag handler 0x0055EB30), writes eight bbox corners at this+0x1C..0x78, axis centers at this+0xDC/0xE0/0xE4 and sphere radius at this+0x18. The animated path reads blended vertex data through the animation struct at this+0x144, advances its clock (anim+0x8) by the frame delta at dword_8B8F28, clamps to the duration (anim+0x4) by mode (anim+0x0), and interpolates when the blend flag is set.
- `0x0054E0E0` **MeshPartProcessingCallbacks** — Thin stdcall forwarding wrapper with no local logic: forwards a1 and a2 unchanged to ConditionalFieldSetter_0d40. Called by UIElementBitfieldStateSetter (0x0054BDC0), sub_54CA00 (0x0054CA00) and MeshBoundingBoxComputation (0x0054D9F0) as the mesh part begin-processing callback.
- `0x0054E0F0` **MeshPartProcessingCallbacks** — Thin stdcall forwarding wrapper: passes a pointer a1 and a char flag a2 straight to ConditionalBitmaskCleanup and returns its result unchanged. Called by the same three callers as 0x0054E0E0 as the mesh part finish-processing callback.
- `0x0054EED0` **SceneRenderBatch** — Inserts triangles into the scene render-batch slot array: iterates the source triangle list, transforms u16 vertex indices to world positions through the dword_8B8F24 vtable, rejects far triangles, scans batch slots (116-byte/29-dword stride) for a free one, classifies the dominant contact axis, runs F_2D3DTrianglePointTest (0x0054EB40), and fills the winning slot with state, parent pointers, material, contact normal, interpolated position and distance; then notifies consumers via SingleFunctionCallWrapper_9a30 (0x00559A30). Returns the number of triangles inserted.
- `0x0054F710` **RenderListManager** — Iterates a scene render-list descriptor (element count this+0x1E4, element array this+0x1E8, both reached through descriptor pointer this+0x1E0). Elements whose first word equals 2 are only counted; every other element receives two D3D-style transform calls through the dword_8B8F24 vtable slot +4. Returns the number of type-2 elements, or 0 when the count is not positive.
- `0x0054FA90` **NetworkPacketReader** — Reads a 64-byte payload out of a packet buffer for a caller-supplied slot index: loads the packet handle at this[0x1E0], rejects a null handle, an out-of-range index, or an entry whose present flag (bit 0) is clear, then copies the payload from the matched 116-byte entry into the output buffer and returns 1 or 0. Structural twin of the NetworkPacketDataWriter cluster. Called by VehiclePhysicsVelocityAngularVelocityIntegrator (0x00459AE0) and CollisionDetectionSystem (0x004EA970).
- `0x0054FAE0` **RenderBufferEntryManager** — Resets render buffer entries for the next frame: clears the active/dirty flag bit 0 (entry offset 0) and zeroes the status field (entry offset 0x40), either on every entry (when index a2 equals the 0x8000000 bulk sentinel) or on the single entry selected by a2. Entry array and element count come from the descriptor at this+0x1E0..0x1E8.
- `0x0054FC70` **WorkingIndexHolder** — Trivial field setter: stores argument a2 into this[27] (byte offset 0x6C) and returns that same value. Invoked during DirectX mesh vertex-buffer parsing (0x00547B40) and material processing (sub_54CA00, 0x0054CA00) to track the current working index/slot.
- `0x00550F70` **MeshDataDualFormat** — Destructor for loaded mesh data supporting two storage formats selected by flags at this+0x0 (bit 0x1 material-block, bit 0x2 texture/animation-block). Releases per-block sub-allocations (RefcountDecrement 0x005507D0, sub_550810, EmptyStub_7470, ArrayOfStructDestructorWithCountdown 0x00550820, FreeWrapper_7bcf) and frees the top-level strided arrays, returning 0 on every path.
- `0x00551390` **ParameterTableConsumer** — Copies parameter data from a parameter table into per-entity data blocks: clamps the selected data index (this+0x8), iterates the per-entity block array (count this+0x14, base this+0x18, 136-byte stride), and for each block whose first dword is not 255 copies the parameter entry selected by block type and index (a float triplet via sub_53B4C0 plus three dwords) into the block. Sets flag bit 0x10000 at this+0x4 on completion and, when a2 is non-null, clears a bitmask via BitmaskClear (0x0054B330).
- `0x005514A0` **FlagTimerOwner** — Flag-word mutation with a timer restart: replaces this[1] (this+0x4) with (this[1] & 0xFFFE0FFF) | 0x2000, then restarts a timer through TimerStartViaQueryPerformanceCounter using this[0] and returns the timer-start result.
- `0x00551760` **NodeTimerWalker** — Walks a linked list whose head pointer is stored at this+0x13C, following each node's next pointer at node+0x24. For every node whose time-cap pointer at node+0x1C is non-null, calls TimerBasedStateUpdateWithCap (0x005514C0) on that node with this as the second argument. Runs inside SceneNodeStateUpdateWithTransform (0x005569F0).
- `0x00551DD0` **BinkVideoDecoder** — Bink video frame decoder (thiscall): BinkWait/BinkDoFrame/BinkNextFrame on the Bink handle at this+0, advances and wraps the frame index this[1] modulo the total frame count read from the Bink header at *this+8, maps the render-path flag a2[12] through a jump table into a copy-flag word, ORs high bits from a5 (0x20 sets 0x80000000, 0x10 sets 0x60000000), locks a surface via ThunkWithArgReorder (0x00543210), copies the frame with BinkCopyToBuffer, clears bit 0x400 of a2[6], and returns the surface-unlock result (0x00543230).
- `0x00552BA0` **FontTextureSheetAnalyzer** — Analyzes a font texture sheet surface to derive glyph cell layout and rewrite the pixel transparency mask: reads the surface object at this+0x64 (width +0x20, height +0x1C, pitch +0x28, pixel format +0x30, flags +0x18), accesses its 16-bit pixel data via ThunkWithArgReorder, scans for sentinel colors to find horizontal/vertical cell divisions, stores key colors at this+0x28/0x2C/0x30 and cell counts/pitches at this+0x34..0x40, computes the total cell count at this+0x44, builds an 8-byte per-cell lookup table at this+0x6D, walks every pixel rewriting alpha-mask bits (setting the +0x18 surface flag 0x800), and finalizes the surface through ArgumentReorderWrapper_3230 (0x00543230).

## Proposed classes

### StringNode24

24-byte string-list node: a string buffer plus a next pointer at +0x14. Allocated 24 bytes by the shared allocator, zero-initialized by ShortComputation_8e00, payload written by strcpy, and finalized through sub_589901. The node type is shared by the three string-list append methods.

Methods: 

- `*(this+0xFC)+0x00000014` `StringNode24* next` (read_write, GUESS)

### StringListOwner

Owner object of up to three singly linked string lists headed at this+0xE8, this+0xF8 and this+0xFC, each appending 24-byte StringNode24 nodes. The head offsets differ between the three append methods; whether they are three lists of one object or three sibling object types is not proven, so each head is kept as a separate field. The container pointers at this+0x10C/0x110 (and this+0xFC read as a container in 0x00549020) are recorded separately.

Methods: `0x00549020`, `0x005492F0`, `0x005493B0`

- `this+0x000000E8` `StringNode24* string_list_head_e8` (read_write, GUESS)
- `this+0x000000F8` `StringNode24* string_list_head_f8` (read_write, GUESS)
- `this+0x000000FC` `StringNode24* string_list_head_fc` (read_write, GUESS)
- `this+0x0000010C` `void* string_container_pointer_10c` (read, GUESS)
- `this+0x00000110` `void* string_container_pointer_110` (read, GUESS)

### TreeStringListMover

Moves matching tree nodes between a source list rooted at *this and a target list managed by this. Iterates the node list headed at this+0xE8, searches each node's tree via RecursiveTreeStringSearch, and moves matches with LinkedListRemove/DoublyLinkedListAppend. The target list's container type is not identified.

Methods: `0x00549170`

- `this+0x000000E8` `void* source_list_head` (read, GUESS)
- `this+0x00000000` `void* source_list_root` (read, GUESS)

### FrameNode56List

Singly linked list of 56-byte nodes (next pointer at +0x34), headed at this+0xF0, with a container pointer at this+0x124 through which the node next field is reached. Appends one node via 0x005491D0.

Methods: `0x005491D0`

- `this+0x000000F0` `void* head` (read_write, GUESS)
- `this+0x00000124` `void* container_pointer` (read, GUESS)
- `*(*(this+0x124)+0x34)+0x00000034` `void* node_next` (read_write, GUESS)

### DoublyLinkedList

Doubly linked list with head at this+0x100; nodes carry prev at +0x100 and next at +0x104. Node links are reached through the container pointer at this+0x204. One append method 0x0054A270.

Methods: `0x0054A270`

- `this+0x00000100` `void* head` (read_write, GUESS)
- `this+0x00000204` `void* container_pointer` (read, GUESS)
- `*(*(this+0x204)+0x104)+0x00000104` `void* node_next` (read_write, GUESS)

### TripleFloatQuery

Object exposing three adjacent float fields (this+0x2C/0x30/0x34) through a conditional triple-output query. Whether the triple is a vector, scalar set or something else is not evidenced. One method 0x0054B4A0.

Methods: `0x0054B4A0`

- `this+0x0000002C` `float value_0` (read, GUESS)
- `this+0x00000030` `float value_1` (read, GUESS)
- `this+0x00000034` `float value_2` (read, GUESS)

### FlagBitState

Holder of a flag dword at this+0x3C whose low two bits are cleared per element on the frame path by 0x0054C190. The meaning of the cleared bits is unknown. The owner class is unknown.

Methods: `0x0054C190`

- `this+0x0000003C` `dword flags` (read_write, GUESS)

### FloatStructTableInit

One-shot initializer for a global 256-entry float-struct table at unk_8BF740 with a 26-DWORD stride. Only ever passes the table to F_10FloatStructInitializer. One method 0x0054C2D0; the owning class is unknown.

Methods: `0x0054C2D0`


### Mesh

Mesh object holding render flags (0x14), the output axis-aligned bounding box (corners 0x1C..0x78), axis centers (0xDC/0xE0/0xE4), bounding-sphere radius (0x18), a part array (count 0x118, base 0x11C), a mesh-node list (head 0x13C) and an animation struct pointer (0x144). Computes its bounding box and sphere and drives the animation clock through 0x0054D9F0.

Methods: `0x0054D9F0`

- `this+0x00000014` `dword mesh_flags` (read_write, GUESS)
- `this+0x00000018` `float bounding_sphere_radius` (write, GUESS)
- `this+0x0000001C` `float bbox_min_x` (write, GUESS)
- `this+0x00000020` `float bbox_min_y` (write, GUESS)
- `this+0x00000024` `float bbox_min_z` (write, GUESS)
- `this+0x00000028` `float bbox_corner2_x` (write, GUESS)
- `this+0x0000002C` `float bbox_corner2_y` (write, GUESS)
- `this+0x00000030` `float bbox_corner2_z` (write, GUESS)
- `this+0x00000034` `float bbox_corner3_x` (write, GUESS)
- `this+0x00000038` `float bbox_corner3_y` (write, GUESS)
- `this+0x0000003C` `float bbox_corner3_z` (write, GUESS)
- `this+0x00000040` `float bbox_corner4_x` (write, GUESS)
- `this+0x00000044` `float bbox_corner4_y` (write, GUESS)
- `this+0x00000048` `float bbox_corner4_z` (write, GUESS)
- `this+0x0000004C` `float bbox_corner5_x` (write, GUESS)
- `this+0x00000050` `float bbox_corner5_y` (write, GUESS)
- `this+0x00000054` `float bbox_corner5_z` (write, GUESS)
- `this+0x00000058` `float bbox_corner6_x` (write, GUESS)
- `this+0x0000005C` `float bbox_corner6_y` (write, GUESS)
- `this+0x00000060` `float bbox_corner6_z` (write, GUESS)
- `this+0x00000064` `float bbox_corner7_x` (write, GUESS)
- `this+0x00000068` `float bbox_corner7_y` (write, GUESS)
- `this+0x0000006C` `float bbox_corner7_z` (write, GUESS)
- `this+0x00000070` `float bbox_corner8_x` (write, GUESS)
- `this+0x00000074` `float bbox_corner8_y` (write, GUESS)
- `this+0x00000078` `float bbox_corner8_z` (write, GUESS)
- `this+0x000000DC` `float axis_center_x` (write, GUESS)
- `this+0x000000E0` `float axis_center_y` (write, GUESS)
- `this+0x000000E4` `float axis_center_z` (write, GUESS)
- `this+0x00000118` `dword part_count` (read, GUESS)
- `this+0x0000011C` `void* part_array_base` (read, GUESS)
- `this+0x0000013C` `void* mesh_node_list_head` (read, GUESS)
- `this+0x00000144` `MeshAnimation* animation_struct` (read, GUESS)

### MeshPart

Mesh-node record in the mesh-node list headed at Mesh.0x13C: a processed-flag word at +0x4, a transform stride at +0x18, and the next-node pointer at +0x24.

Methods: 

- `*(this+0x13C)+0x00000004` `dword processed_flag` (read_write, GUESS)
- `*(this+0x13C)+0x00000018` `dword transform_stride` (read, GUESS)
- `*(this+0x13C)+0x00000024` `void* next` (read, GUESS)

### MeshAnimation

Animation clock structure reached through Mesh.0x144: mode at +0x0, duration at +0x4, clock at +0x8 and a blend-offset region index at +0xC. The blend interpolation also reads a field at offset 0x11C inside the blend-offset region (base *(*(this+0x144)+0xC)).

Methods: 

- `*(this+0x144)+0x00000000` `dword mode` (read, GUESS)
- `*(this+0x144)+0x00000004` `float duration` (read, GUESS)
- `*(this+0x144)+0x00000008` `float clock` (read_write, GUESS)
- `*(this+0x144)+0x0000000C` `dword blend_region_index` (read, GUESS)
- `*(*(this+0x144)+0xC)+0x0000011C` `void* blend_region_field` (read, GUESS)

### MeshPartProcessingCallbacks

Two thin forwarding wrappers invoked per mesh part as begin/finish processing callbacks by MeshBoundingBoxComputation (0x0054D9F0), UIElementBitfieldStateSetter (0x0054BDC0) and sub_54CA00 (0x0054CA00). 0x0054E0E0 forwards to ConditionalFieldSetter_0d40; 0x0054E0F0 forwards to ConditionalBitmaskCleanup. The targets' identities and a recorded global read of dword_8B78A0 are unresolved.

Methods: `0x0054E0E0`, `0x0054E0F0`


### SceneRenderBatch

Scene render batch holding a descriptor region (this+0x1E0 descriptor, this+0x1E4 count, this+0x1E8 slot array) and a position triple at this+0x204. Inserts world-space triangles into 116-byte slots via 0x0054EED0 on the frame path from SceneBatchRenderCheck (0x0054F5C0).

Methods: `0x0054EED0`

- `this+0x000001E0` `void* render_descriptor_ptr` (read, GUESS)
- `this+0x000001E4` `dword descriptor_count` (read, GUESS)
- `this+0x000001E8` `void* slot_array_ptr` (read, GUESS)
- `this+0x00000204` `float[3] position` (read, GUESS)

### RenderBatchSlot

116-byte (29-dword) slot record in the SceneRenderBatch slot array (base *(this+0x1E8)): state word at +0x00, transform data at +0x18/+0x28/+0x2C/+0x30, parent scene at +0x34, reserved zeros at +0x38/+0x50, op-context at +0x3C, triangle-list pointer at +0x40, material float at +0x44, slot index at +0x48, source triangle pointer at +0x4C, contact normal at +0x58..0x60, interpolated position at +0x64..0x6C, and a Euclidean distance at +0x70.

Methods: 

- `*(this+0x1E8)+0x00000000` `dword state` (read_write, GUESS)
- `*(this+0x1E8)+0x00000018` `float transform_data_0` (read, GUESS)
- `*(this+0x1E8)+0x00000028` `float transform_data_1` (read, GUESS)
- `*(this+0x1E8)+0x0000002C` `float transform_data_2` (read, GUESS)
- `*(this+0x1E8)+0x00000030` `float transform_data_3` (read, GUESS)
- `*(this+0x1E8)+0x00000034` `void* parent_scene` (read, GUESS)
- `*(this+0x1E8)+0x00000038` `void* reserved_0` (write, GUESS)
- `*(this+0x1E8)+0x0000003C` `void* op_context` (write, GUESS)
- `*(this+0x1E8)+0x00000040` `void* triangle_list_ptr` (write, GUESS)
- `*(this+0x1E8)+0x00000044` `float material_float` (write, GUESS)
- `*(this+0x1E8)+0x00000048` `dword slot_index` (write, GUESS)
- `*(this+0x1E8)+0x0000004C` `void* source_triangle` (write, GUESS)
- `*(this+0x1E8)+0x00000050` `void* reserved_1` (write, GUESS)
- `*(this+0x1E8)+0x00000058` `float contact_x` (write, GUESS)
- `*(this+0x1E8)+0x0000005C` `float contact_y` (write, GUESS)
- `*(this+0x1E8)+0x00000060` `float contact_z` (write, GUESS)
- `*(this+0x1E8)+0x00000064` `float interpolated_pos_x` (write, GUESS)
- `*(this+0x1E8)+0x00000068` `float interpolated_pos_y` (write, GUESS)
- `*(this+0x1E8)+0x0000006C` `float interpolated_pos_z` (write, GUESS)
- `*(this+0x1E8)+0x00000070` `float distance` (write, GUESS)

### RenderListManager

Iterates a scene render-list descriptor (descriptor pointer this+0x1E0, element count this+0x1E4, element array this+0x1E8; elements 116 bytes apart with a type word at +0x00). Counts type-2 elements and issues two transform calls per other element through the dword_8B8F24 vtable. Shares the this+0x1E0/0x1E4/0x1E8 descriptor region with SceneRenderBatch and RenderBufferEntryManager; common ownership is not proven.

Methods: `0x0054F710`

- `this+0x000001E0` `void* descriptor_ptr` (read, GUESS)
- `this+0x000001E4` `dword element_count` (read, GUESS)
- `this+0x000001E8` `void* element_array` (read, GUESS)
- `*(this+0x1E8)+0x00000000` `word element_type` (read, GUESS)

### RenderBufferEntryManager

Per-frame render buffer entry reset: clears entry flag bit 0 (offset 0) and the status field (offset 0x40) for one entry or for all entries (index sentinel 0x8000000). Entry array and count come from the descriptor at this+0x1E0..0x1E8. Shares the descriptor region offsets with SceneRenderBatch and RenderListManager.

Methods: `0x0054FAE0`

- `this+0x000001E0` `void* descriptor_ptr` (read, GUESS)
- `this+0x000001E4` `dword element_count` (read, GUESS)
- `this+0x000001E8` `void* entry_array` (read, GUESS)
- `*(this+0x1E8)+0x00000000` `dword entry_flags` (read_write, GUESS)
- `*(this+0x1E8)+0x00000040` `dword entry_status` (read_write, GUESS)

### NetworkPacketReader

Reads a fixed 64-byte payload from a packet buffer by slot index: the packet handle lives at this[0x1E0], entries are 116 bytes with a present flag (bit 0) at offset 0 and the payload at offset 0x34. One method 0x0054FA90, called by physics and collision consumers.

Methods: `0x0054FA90`

- `this+0x000001E0` `void* packet_handle` (read, GUESS)

### WorkingIndexHolder

Holds a current working index/slot in this[27] (offset 0x6C), written and returned by 0x0054FC70 during DirectX mesh vertex-buffer and material processing. The field's exact meaning is inferred from caller names only.

Methods: `0x0054FC70`

- `this+0x0000006C` `dword working_index` (read_write, GUESS)

### MeshDataDualFormat

Loaded mesh data supporting two storage formats selected by format flags at +0x0 (bit 0x1 material-block format, bit 0x2 texture/animation-block format). Material format holds a block count at +0xC and material array at +0x10; texture format holds a group count at +0x14 and texture group array at +0x18. Torn down by the destructor 0x00550F70.

Methods: `0x00550F70`

- `this+0x00000000` `dword format_flags` (read, DERIVED)
- `this+0x0000000C` `dword material_block_count` (read, GUESS)
- `this+0x00000010` `void* material_array` (read, GUESS)
- `this+0x00000014` `dword texture_group_count` (read, GUESS)
- `this+0x00000018` `void* texture_group_array` (read, GUESS)

### ParameterTableConsumer

Consumes parameter data from a parameter table into per-entity 136-byte data blocks: flags at +0x4, selected data index at +0x8, block count at +0x14, block array at +0x18, parameter-table pointer at +0x1C, entry-table base at +0x2C, table count/aux at +0x30, and block copy slots at +0x4C/0x50/0x54. Copies a float triplet plus three dwords per block via 0x00551390.

Methods: `0x00551390`

- `this+0x00000004` `dword flags` (read_write, GUESS)
- `this+0x00000008` `dword data_index` (read_write, GUESS)
- `this+0x00000014` `dword block_count` (read, GUESS)
- `this+0x00000018` `void* block_array` (read, GUESS)
- `this+0x0000001C` `void* parameter_table_ptr` (read, GUESS)
- `this+0x0000002C` `void* entry_table_base` (read, GUESS)
- `this+0x00000030` `dword table_count_or_aux` (read, GUESS)
- `this+0x0000004C` `dword block_slot_0` (write, GUESS)
- `this+0x00000050` `dword block_slot_1` (write, GUESS)
- `this+0x00000054` `dword block_slot_2` (write, GUESS)

### FlagTimerOwner

Owner of a timer pointer at +0x0 and a flag word at +0x4. 0x005514A0 masks a flag region and sets bit 0x2000, then restarts the timer. Called from 0x005514C0 and 0x00551800.

Methods: `0x005514A0`

- `this+0x00000000` `void* timer_ptr` (read, GUESS)
- `this+0x00000004` `dword flags` (read_write, GUESS)

### NodeTimerWalker

Walks a list headed at this+0x13C and applies a timer-capped state update to nodes with a configured time cap. Nodes carry the cap pointer at +0x1C and the next pointer at +0x24 (base *(this+0x160)). One method 0x00551760, called from SceneNodeStateUpdateWithTransform (0x005569F0).

Methods: `0x00551760`

- `this+0x0000013C` `void* list_head` (read, GUESS)

### TimerNode

Node in the NodeTimerWalker list (base *(this+0x160)): a time-cap pointer at +0x1C and the next-node pointer at +0x24.

Methods: 

- `*(this+0x160)+0x0000001C` `void* time_cap_ptr` (read, GUESS)
- `*(this+0x160)+0x00000024` `void* next` (read, GUESS)

### BinkVideoDecoder

Bink video decoder object: Bink handle at +0x0, wrapped frame index at +0x4, with the total frame count read from the Bink header at *this+8 (obj+0x8). 0x00551DD0 waits/decodes/advances frames and copies the decoded frame into a caller surface using the four-pointer Bink API block at globals 0x0059E340..0x0059E34C and the copy-flag jump table at global 0x00551E94.

Methods: `0x00551DD0`

- `this+0x00000000` `void* bink_handle` (read, DERIVED)
- `this+0x00000004` `dword frame_index` (read_write, GUESS)
- `obj+0x00000008` `dword total_frame_count` (read, GUESS)

### FontTextureSheetAnalyzer

Analyzes a font texture sheet surface (pointer at this+0x64) to derive glyph cell layout and rewrite pixel transparency: key colors at this+0x28/0x2C/0x30, cell counts at this+0x34/0x38, cell pitches at this+0x3C/0x40, total cell count at this+0x44, and an 8-byte per-cell lookup table at this+0x6D. The surface exposes flags at +0x18, height at +0x1C, width at +0x20, pitch at +0x28 and pixel format at +0x30 (base *(this+0x64)). One method 0x00552BA0.

Methods: `0x00552BA0`

- `this+0x00000028` `word key_color_0` (read, GUESS)
- `this+0x0000002C` `word key_color_1` (read_write, GUESS)
- `this+0x00000030` `word key_color_2` (read, GUESS)
- `this+0x00000034` `dword horizontal_cell_count` (write, GUESS)
- `this+0x00000038` `dword vertical_cell_count` (write, GUESS)
- `this+0x0000003C` `dword horizontal_cell_pitch` (write, GUESS)
- `this+0x00000040` `dword vertical_cell_pitch` (write, GUESS)
- `this+0x00000044` `dword total_cell_count` (write, GUESS)
- `this+0x00000064` `void* surface_ptr` (read, GUESS)
- `this+0x0000006D` `byte[8] cell_lookup_table` (write, GUESS)
- `*(this+0x64)+0x00000018` `dword surface_flags` (read_write, GUESS)
- `*(this+0x64)+0x0000001C` `dword surface_height` (read, GUESS)
- `*(this+0x64)+0x00000020` `dword surface_width` (read, GUESS)
- `*(this+0x64)+0x00000028` `dword surface_pitch` (read, GUESS)
- `*(this+0x64)+0x00000030` `dword surface_pixel_format` (read, GUESS)

## Compatibility contracts

- **StringListNode24Layout** — String-list nodes are 24-byte allocations with the next pointer at +0x14 and a string buffer written by strcpy after ShortComputation_8e00 zero-init; the node is finalized through sub_589901 (0x00589901) whose result becomes the append function's return value. A replacement must allocate exactly 24 bytes, walk the +0x14 chain, and return the normalize/register result.
- **RenderBatchSlotLayout** — Scene render-batch slots are 116-byte (29-dword) records: state word at +0x00, parent scene at +0x34, op-context at +0x3C, triangle-list pointer at +0x40, material float at +0x44, slot index at +0x48, source triangle at +0x4C, contact normal at +0x58..0x60, interpolated position at +0x64..0x6C and distance at +0x70. Occupied slots carry state value 1; state value 6 is skipped by the inserter. The same 116-byte stride and type word at +0x00 drive the render-list iteration.
- **MeshBoundingBoxOutput** — ComputeMeshBoundingBox writes the eight bounding-box corners at this+0x1C..0x78, the three axis center coordinates at this+0xDC/0xE0/0xE4 and the bounding-sphere radius (sqrt of sum of half-extent squares) at this+0x18. A replacement rendering or culling consumer relies on this exact output layout.
- **MeshDataDualFormatStorage** — Loaded mesh data selects its storage format by flags at +0x0: bit 0x1 selects the material-block format (block count at +0xC, array at +0x10) and bit 0x2 selects the texture/animation-block format (group count at +0x14, array at +0x18). The destructor must release both layouts and return 0 on every path.
- **BinkFramePipeline** — The Bink decoder drives a four-function API block at globals 0x0059E340 (wait), 0x0059E344 (do-frame), 0x0059E348 (next-frame) and 0x0059E34C (copy-to-buffer). Frame index advances as (index+1) mod total-frame-count read from the Bink header at *handle+8. A replacement executable must reproduce the wait/decode/advance/copy ordering and the copy-flag assembly (jump-table base ORed with 0x80000000/0x60000000 from the a5 flag bits 0x20/0x10).
- **RenderBufferBulkClearSentinel** — Render-buffer entry clear uses the index value 0x8000000 as a bulk sentinel: passing it clears every entry (each entry's flag bit 0 at +0x00 and status at +0x40), otherwise only the single selected entry is cleared. The descriptor (pointer at this+0x1E0, count at this+0x1E4, array at this+0x1E8) must be preserved.

## Unresolved

- StringListOwner: this+0xFC is read as the list head by appendStringCopyNode (0x005493B0) but as a read-only container pointer by appendStringNode (0x00549020); the packet does not prove whether these are three lists of one object or three sibling object types, so the heads are kept as separate fields.
- StringNode24: the exact semantics of sub_589901 (0x00589901) - normalization vs registration - are not grounded in this packet.
- FrameNode56List: the container field at this+0x124 does not appear in the raw source; parameter a2 of 0x005491D0 is unused, and whether the head at this+0xF0 and the node next at +0x34 are separate allocations or one object is not established.
- DoublyLinkedList: the node layout (prev at +0x100, next at +0x104) is inferred from raw-source offsets 256/260 only; the container pointer this+0x204 is an existing-analysis interpretation not directly expressed in the raw body.
- TripleFloatQuery: the three adjacent fields (0x2C/0x30/0x34) are likely a contiguous triple, but whether they are floats, vectors or scalars is not evidenced.
- FlagBitState: the meaning of the two cleared flag bits (which state they reset) is not evidenced; the field at this+0x3C is reported recalculated every frame by a fill, but that persistence claim is not independently verified here.
- FloatStructTableInit: the purpose of the 256-entry table at unk_8BF740 and the significance of the 26-DWORD stride are unknown.
- Mesh: the two physics globals (0x0059E440, 0x0059E450) are attributed by the packet but do not appear in the visible raw source; the device vtable at dword_8B8F24 and the frame-delta source at dword_8B8F28 have external, unrecoverable contracts.
- Mesh: the flag bits controlling static vs blended vertex paths, primitive dispatch, and clock clamping are not named; the vertex data layout at part+12 and destination buffer at part+32 is inferred from the copy pattern; the full animation-frame layout behind this+0x144 is not established.
- MeshPartProcessingCallbacks: the global read of dword_8B78A0 recorded in the fact table is absent from both raw wrapper bodies and is unexplained; the identity and owner of ConditionalFieldSetter_0d40 / ConditionalBitmaskCleanup are outside this packet.
- SceneRenderBatch: this+0x1E4 and this+0x2EC/0x2F0/0x2F4 are not visible in the raw source (the latter possibly a scene camera-position triplet); global flt_59E440 is folded out of the raw source and is likely a float bias/epsilon; the dword_8B8F24 service identity is unresolved.
- SceneRenderBatch/RenderListManager/RenderBufferEntryManager/NetworkPacketReader: all read this+0x1E0/0x1E4/0x1E8 but treat them as different descriptor types (render descriptor, element count/array, packet handle). Equal offsets on different objects are kept as separate fields; common ownership is not proven.
- RenderListManager: the second parameter a2 is unused; the two indirect calls through dword_8B8F24 slot +4 have no callee entries; the meaning of the 29-dword element stride and the this+69 context pointer is unresolved.
- NetworkPacketReader: this+0x1E4 and this+0x1E8 are not exercised in the raw decompiled source; the present-flag bit 0 and the 116-byte entry layout beyond +0x34 are inferred; the 64-byte payload type and packet-buffer ownership model are not established.
- RenderBufferEntryManager: the raw source reaches the entry array through the descriptor's +8 pointer while this+0x1E8 is modeled as the array; the 0x8000000 bulk sentinel and the status field at +0x40 semantics are not established.
- WorkingIndexHolder: the stored field meaning (material slot index vs vertex processing counter) is DERIVED from caller names only.
- MeshDataDualFormat: exact element semantics of sub_550810 (0x00550810) and ArrayOfStructDestructorWithCountdown (0x00550820) are not grounded; the allocator header convention (element count at allocation minus 4) is inferred.
- ParameterTableConsumer: the parameter table layout (pointer this+0x1C, entry-table base at +0x2C, count at +0x30, 44-byte per-type entries at base +40, 32 dwords per data index) is inferred from index arithmetic; sub_53B4C0's copy width and the block slot meanings (+4..+12, +52..+60) are not established.
- FlagTimerOwner: TimerStartViaQueryPerformanceCounter is referenced only by name in the raw source and is absent from the packet callees; the meaning of flag bit 0x2000 and the region cleared by mask 0xFFFE0FFF is unknown.
- NodeTimerWalker: the node base is labelled *(this+0x160) by the packet but the raw source only shows node offsets reached from the walk pointer; the time-cap pointer at +0x1C semantics are not established. this+0x13C is also the mesh-node-list head in Mesh, but common ownership is not proven.
- BinkVideoDecoder: the render-path flag enum behind a2[12] and the a5 flag semantics (0x10/0x20) are undocumented; the jump-table case to copy-flag mapping (cases 5-8 to 9/10/1/5) is inferred from decompiler structure only.
- FontTextureSheetAnalyzer: the key colors (this+0x28/0x2C/0x30), cell layout fields (this+0x34..0x40) and the 8-byte cell-record at this+0x6D are DERIVED from pixel-scan behavior; the roles of ThunkWithArgReorder/ArgumentReorderWrapper_3230 are inferred; whether the final mask-clear on key_color_1 (this+0x2C) is intentional or residual is unresolved.
- MeshAnimation: the animation-mode state machine is modeled with only three states from mode-guard evidence; the exact transition semantics and reset behavior beyond the clock clamp are not fully grounded.
