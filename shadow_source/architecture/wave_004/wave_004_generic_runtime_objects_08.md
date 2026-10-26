# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

DERIVED reconstruction of generic runtime objects in the 0x0048A000-0x00495000 range. Clusters are grounded in the packet's field evidence and callee/caller links: (1) a HUD-timer base class (0x0048C070) and an extended list-container class (0x0048C9F0, 0x0048CC20) that derives from it; (2) a custom memory-pool allocator state (0x00490920, 0x00490930) plus its pool-object factory (0x00491710); (3) a pool-backed embedded-list container (0x004919C0, 0x00491A40, 0x00491BD0) sharing one list-header layout (head/tail/current/count at *this+0xC/+0x10/+0x14/+0x18) and one node layout ({+0 value, +4 next, +8 ownership flag}) with the flag-gated node free 0x00491E40; (4) a separate by-value linked list (0x00491D30) with head at this+0x0; (5) iterator accessors (0x00491CF0, 0x00491D10) used by RenderDispatchWithIteration; (6) a text/token parser set (0x00491FB0, 0x00492030, 0x00493060) sharing counters at this+0x18C/0x190/0x194/0x1A4 and the global token buffer; (7) render plumbing: surface descriptors (0x00494690), a draw shim (0x00494BF0) and a frame bracket (0x00495020, 0x004950E0) around the shared conditional state at unk_8AFE18 and render-device pointer dword_8B8DC8. All owner identities remain UNKNOWN in the packet; class grouping is structural and must not be promoted to CONFIRMED.

## Function roles

- `0x0048A3B0` **UiStateObject** — Byte setter: stores input byte into this+0xE0 and returns the stored value.
- `0x0048B8F0` **TextFieldSizer** — Bounded setter: writes dword a2 to this+0x2F8 only when a2 < 0x100; returns 0.
- `0x0048C070` **HudTimer** — HUD timer constructor: base-init via 0x0048B420, install vtable off_5ABF88, set flags +0x304/+0x305 and counters +0x30C..+0x318.
- `0x0048C9A0` **UiElementNode** — Unconditional vtable-array node initializer: write vtable off_5AC044 at this+0x0, zero this+0x4.
- `0x0048C9F0` **TimerListContainer** — Extended object constructor: run base init sub_48C070(this,0), zero +0x31C..+0x328, override vtable to off_5AC048, list-node setup via 0x0048D230.
- `0x0048CC20` **TimerListContainer** — Linked-list size calculation: walk list at this+0x31C via iterator +0x324, track dimension maxima at +0x32C/+0x330 seeded to 5.
- `0x0048E670` **ResourceObject** — Destructor: restore vtable off_5AC540, call ResourceCleanup (0x0048E890), guardedly free handle at this+0xE0 via FreeWrapper_7bcf, chain to base destructor.
- `0x0048E750` **ViewportRectObject** — Guarded viewport rectangle setup: read bounds +0x4/+0x8/+0xC/+0x10, scale via sub_542200, conditional-init/compare/reset on unk_8AFE18/dword_8AFE64, restore viewport, update camera projection (0x00541B70), write bounds out.
- `0x00490160` **UiStateObject** — Boolean state setter with virtual dispatch: invert boolean at this+0xE0, dispatch vtable slot 0x2C with argument 1, return its result.
- `0x00490920` **MemoryPoolAllocator** — Accessor: call CustomMemoryPoolAllocatorInit (0x004906E0) and return dword index 1 (offset 4) of the returned object.
- `0x00490930` **MemoryPoolAllocator** — Accessor: call CustomMemoryPoolAllocatorInit (0x004906E0) and return the head dword of the returned object.
- `0x00491300` **RectRecordInitializer** — Rect/AABB record initializer: store four shorts at +0x0/+0x2/+0x4/+0x6 and zero the dword at +0xC.
- `0x00491710` **MemoryPoolAllocator** — Pool object factory: allocate 76 bytes via OperatorNewNhMallocWrapper (0x00587C03), construct via sub_490B00, store result at this+0x0 (0 on allocation failure).
- `0x004918D0` **BroadphaseRegionUpdater** — Broadphase region update: entry guard on extents, timer predicate sub_4F9B20(&unk_8AFE18) selects full bucket sweep vs single ring-bucket update via CollisionBroadphaseBuilder (0x00490EE0).
- `0x004919C0` **PoolListContainer** — Pool-node append: request node via ResourcePoolNodeAllocDealloc (0x00490940), wrap in a 12-byte list node, append to the embedded list at *this+0xC..+0x18.
- `0x00491A40` **PoolListContainer** — Unlink a node whose value matches the reference node's content; reparent content via LinkedListNodePrepend (0x00490AA0), relink, decrement count, free node and (flag-gated) value.
- `0x00491BD0` **PoolListContainer** — Destroy embedded list: reparent every value via LinkedListNodePrepend (0x00490AA0), free each node (flag-gated value free), zero the four list sentinels.
- `0x00491CF0` **RenderListIterator** — List follower: copy pointer field obj+0x1C into iterator obj+0x24, return its first dword when non-null.
- `0x00491D10` **RenderListIterator** — List iterator advance: step the node at obj+0x24 to its +4 next link, return the current node's first dword.
- `0x00491D30` **ValueLinkedList** — Remove the first node whose value field matches a2; update head/tail/cached-end/count, optionally clear the +8 flag, free payload and node.
- `0x00491E40` **ListNode** — Flag-gated data free: free the object pointer at this+0x0 via FreeWrapper_7bcf only when the byte flag at this+0x8 is set.
- `0x00491FB0` **TextWidgetParser** — Read a line and count tokens: LineInputReader(256) via 0x005351D0, classify token via sub_5651B0(&unk_7CD9D8), increment counters at +0x18C/+0x190.
- `0x00492030` **TextWidgetParser** — Nesting-token balance scanner: skip to delimiter asc_5CC4F8, match open/close tokens (asc_5CC4F8/asc_5CC4F4) via sub_587C20 keeping a balance counter, then decrement this[0x194].
- `0x00493060` **TextWidgetParser** — UI widget property parser: validate property string (0x0049A210), init sub-object from this+0x1A4 (0x00499C50), iterate tokens via sub_491FB0 and dispatch sound/font/size/offset/frame handlers.
- `0x00494690` **RenderSurfaceManager** — Render-surface initialization: build S/B/A buffer descriptors (96 bytes, dword_7CDE04/0x10/0x1C), configure via sub_54FEC0, cache +84 sub-pointer, construct texture handles (0x00553980), install UV corners (0x00553650).
- `0x00494BF0` **RenderDrawShim** — Delegation shim: drop a1, forward a2..a6 unchanged to RenderDrawOperationWithClipping (0x00543440), return its result.
- `0x00495020` **RenderFrameSequence** — Multi-step frame sequence: ConditionalInit(&unk_8AFE18), render via sub_553700(dword_8B8DC8), StateFlagComputation(0) via 0x004F9B30, then ConditionalStateReset.
- `0x004950E0` **RenderFrameSequence** — Minimal render frame wrapper: ConditionalInit(&unk_8AFE18), render via sub_553700(dword_8B8DC8), ConditionalStateReset.

## Proposed classes

### UiStateObject

UI object exposing a boolean/byte state at this+0xE0 and a vtable. One setter writes the byte and returns it; another inverts the boolean state and then always virtual-dispatches the method at vtable slot 0x2C with argument 1. The semantic link between the state flag and the dispatched method is not confirmed.

Methods: `0x0048A3B0`, `0x00490160`

- `this+0x00000000` `ptr vtable_ptr` (read, GUESS)
- `this+0x000000E0` `byte boolean_state` (read_write, DERIVED)
- `obj+0x0000002C` `fn_ptr vtable_dispatch_slot` (read, GUESS)

### TextFieldSizer

Setter that stores an unsigned dword into this+0x2F8 only when the value is below 0x100 (clamped), always returning 0. Prose in the packet proposes the field is a buffer-size/max-edit-length limit for text fields, but the owner class is not identified and one recorded caller (EngineTemperatureDebugDisplay) does not fit that reading, so the field may be reused across owner contexts.

Methods: `0x0048B8F0`

- `this+0x000002F8` `dword max_edit_length` (write, GUESS)

### HudTimer

Base HUD timer widget. The constructor delegates to the base initializer 0x0048B420 with six zero arguments, installs the HUD-timer vtable off_5ABF88, stores a parameter at this+0x308, enables two byte flags at +0x304/+0x305 and initializes counters at +0x30C..+0x318. The meaning of the parameter (timer ID/interval/callback) and the field roles are not independently confirmed.

Methods: `0x0048C070`

- `this+0x00000000` `ptr vtable_ptr` (write, GUESS)
- `this+0x00000304` `byte flag_0x304` (write, GUESS)
- `this+0x00000305` `byte flag_0x305` (write, GUESS)
- `this+0x00000308` `dword timer_param` (write, GUESS)
- `this+0x0000030C` `dword field_0x30C` (write, GUESS)
- `this+0x00000310` `dword field_0x310` (write, GUESS)
- `this+0x00000314` `dword field_0x314` (write, GUESS)
- `this+0x00000318` `dword field_0x318` (write, GUESS)

### TimerListContainer

Object derived from HudTimer that owns an embedded linked list. The extended constructor runs the base constructor sub_48C070(this,0), zeroes four extended fields at +0x31C..+0x328, overrides the vtable to off_5AC048 and performs list-node setup through 0x0048D230. The size method walks the list rooted at this+0x31C via the iterator at +0x324 and tracks two dimension maxima at +0x32C/+0x330 (seeded to 5, feeding child offsets 28/32). The child-struct semantics and the base value 5 are ungrounded.

Methods: `0x0048C9F0`, `0x0048CC20`

- `this+0x00000000` `ptr vtable_ptr` (write, GUESS)
- `this+0x0000031C` `ptr list_head` (read_write, DERIVED)
- `this+0x00000320` `dword ext_field_0x320` (write, GUESS)
- `this+0x00000324` `ptr walk_iterator` (read_write, DERIVED)
- `this+0x00000328` `dword ext_field_0x328` (write, GUESS)
- `this+0x0000032C` `dword dimension_max_a` (read_write, DERIVED)
- `this+0x00000330` `dword dimension_max_b` (read_write, DERIVED)

### UiElementNode

Unconditional vtable-array node initializer: writes the UIElement vtable off_5AC044 at this+0x0 and zeroes the next dword at this+0x4, returning this. Likely part of linked-list node setup by LinkedListNodeAppend (0x0048D2B0); receiver class identity is unknown.

Methods: `0x0048C9A0`

- `this+0x00000000` `ptr vtable_ptr` (write, GUESS)
- `this+0x00000004` `dword zeroed_field_0x4` (write, GUESS)

### ResourceObject

Object owning a resource handle at this+0xE0. The destructor restores the vtable to off_5AC540 for safe virtual dispatch during teardown, calls ResourceCleanup (0x0048E890), frees the handle at +0xE0 via FreeWrapper_7bcf when it is nonzero, then chains to a base destructor and returns its result. Type and lifetime contract of the handle beyond the nonzero guard are unknown.

Methods: `0x0048E670`

- `this+0x00000000` `ptr vtable_ptr` (write, GUESS)
- `this+0x000000E0` `ptr resource_handle` (read_write, DERIVED)

### ViewportRectObject

Object holding a rectangle (bounds at +0x4/+0x8/+0xC/+0x10) and a child-object pointer at +0x40. Its single method, guarded by (child+0x38)==2 and by the two dword flags at +0xE8/+0xEC, scales the rectangle to viewport offsets, configures the viewport via sub_542200, drives a conditional-init/compare/reset sequence over globals unk_8AFE18 and dword_8AFE64, restores the full viewport, updates the camera projection (0x00541B70) and writes the bounds out. Packet guard-table field this+0x78 does not appear in the raw source.

Methods: `0x0048E750`

- `this+0x00000004` `int rect_left` (read, GUESS)
- `this+0x00000008` `int rect_top` (read, GUESS)
- `this+0x0000000C` `int rect_right` (read, GUESS)
- `this+0x00000010` `int rect_bottom` (read, GUESS)
- `this+0x00000040` `ptr child_object_ptr` (read, DERIVED)
- `this+0x000000E8` `dword enable_flag_0xE8` (read, GUESS)
- `this+0x000000EC` `dword enable_flag_0xEC` (read, GUESS)

### MemoryPoolAllocator

Shared custom memory-pool allocator state and its factory. The factory 0x00491710 allocates a 76-byte object via OperatorNewNhMallocWrapper (0x00587C03), constructs it through sub_490B00 and stores the result at this+0x0 (0 on failure); it is called by CustomMemoryPoolAllocatorInit (0x004906E0). The two accessors call the same init routine and read the head dword and dword-index-1 of the returned pool object. Field meanings are unnamed in the packet.

Methods: `0x00490920`, `0x00490930`, `0x00491710`

- `this+0x00000000` `ptr pool_object_ptr` (write, DERIVED)
- `obj+0x00000000` `int head_state` (read, GUESS)
- `obj+0x00000004` `int index1_field` (read, GUESS)

### RectRecordInitializer

Trivial struct initializer: writes four short arguments into the word-aligned layout at +0x0/+0x2/+0x4/+0x6 and zeroes the dword at +0xC. Called by RenderDispatchWithIteration (0x004993D0) to initialize a per-item rectangle/AABB record; whether the four shorts are rect or AABB coordinates is inferred from caller context only.

Methods: `0x00491300`

- `this+0x00000000` `short coord0` (write, GUESS)
- `this+0x00000002` `short coord1` (write, GUESS)
- `this+0x00000004` `short coord2` (write, GUESS)
- `this+0x00000006` `short coord3` (write, GUESS)
- `this+0x0000000C` `dword zeroed_dword` (write, GUESS)

### BroadphaseRegionUpdater

Dispatches broadphase collision updates for a screen-region AABB. Entry guard returns 0 for non-positive extents; a race-phase timer predicate sub_4F9B20(&unk_8AFE18) selects either a full sweep over the bucket array (count at *this[0], 16-byte stride, base at (*this)[2]) or a single ring-bucket update (index at (*this)[1]); each element is handed to CollisionBroadphaseBuilder (0x00490EE0). The 16-byte broadphase element's first three dwords form the substructure head. this is an int** header; only the +0 count is captured in field evidence.

Methods: `0x004918D0`

- `this+0x00000000` `int bucket_count` (read, DERIVED)
- `obj+0x00000000` `dword substructure_dword0` (read, GUESS)
- `obj+0x00000004` `dword substructure_dword1` (read, GUESS)
- `obj+0x00000008` `dword substructure_dword2` (read, GUESS)

### PoolListContainer

Container for an embedded singly-linked list located at *this+0xC (head), +0x10 (tail), +0x14 (current marker), +0x18 (count), with node layout {+0 value, +4 next, +8 ownership flag}. Append (0x004919C0) pulls a node from the resource pool (0x00490940), wraps it in a 12-byte node (0x00587C03) and appends to head/tail/current/count. Unlink-by-content (0x00491A40) reparents the value via LinkedListNodePrepend (0x00490AA0), relinks predecessor/successor and frees flag-gated payloads. Destruction (0x00491BD0) reparents all values then frees every node and zeros the four sentinels. All three are called by sub_496E90.

Methods: `0x004919C0`, `0x00491A40`, `0x00491BD0`

- `this+0x00000000` `ptr struct_base_ptr` (read, DERIVED)
- `obj+0x0000000C` `ptr list_head` (read_write, DERIVED)
- `obj+0x00000010` `ptr list_tail` (read_write, DERIVED)
- `obj+0x00000014` `ptr list_current` (read_write, DERIVED)
- `obj+0x00000018` `int list_count` (read_write, DERIVED)

### ListNode

Shared node teardown helper. Reads the ownership flag byte at this+0x8 and, when set and the object pointer at this+0x0 is non-null, releases that pointer through FreeWrapper_7bcf (0x00587BCF), returning the wrapper's low byte. Used by ResourcePoolNodeAllocDealloc (0x00490940), sub_490D00, sub_57DE30 and sub_57E570. The +8 flag is inferred to mean value ownership from the free guard.

Methods: `0x00491E40`

- `this+0x00000000` `ptr value_ptr` (read, DERIVED)
- `this+0x00000008` `byte owns_data_flag` (read, GUESS)

### RenderListIterator

Iterator primitives over a render list used by RenderDispatchWithIteration (0x004993D0). The follower reads the pointer field obj+0x1C, copies it into the iterator field obj+0x24 and returns the pointed-to first dword. The reader advances the node at obj+0x24 to its +4 next link and returns the current node's first dword (0 when null). Node +0/+4 field roles (value/next) are inferred.

Methods: `0x00491CF0`, `0x00491D10`

- `obj+0x0000001C` `ptr source_pointer` (read, DERIVED)
- `obj+0x00000024` `ptr current_node` (read_write, DERIVED)
- `*(obj+0x1C)+0x00000000` `dword pointed_value` (read, GUESS)
- `*(obj+0x24)+0x00000004` `ptr node_next` (read, DERIVED)

### ValueLinkedList

Singly-linked list with the head at this+0x0, tail at this+0x4, a cached-end pointer at this+0x8 and a count at this+0xC; nodes are {+0 value, +4 next, +8 flags}. Removal walks from the head comparing each node's value to a2, unlinks the match, fixes head/tail/cached-end/count, optionally clears the node flag byte when a3 is 0, frees the data payload when the flag is set, frees the node and returns 1 (0 when not found or a2 null). The relationship between tail pointers tracked at obj+0x4 and this+0x4 needs an external layout check.

Methods: `0x00491D30`

- `this+0x00000000` `ptr list_head` (read_write, DERIVED)
- `this+0x00000004` `ptr list_tail` (read_write, DERIVED)
- `this+0x00000008` `ptr cached_end` (read_write, GUESS)
- `this+0x0000000C` `int list_count` (read_write, DERIVED)
- `*(obj+0x4)+0x00000000` `dword node_value` (read, DERIVED)
- `*(obj+0x4)+0x00000004` `ptr node_next` (read, DERIVED)
- `*(obj+0x4)+0x00000008` `byte node_flags` (read, GUESS)

### TextWidgetParser

Text/token and widget-property parser sharing per-object counters at this+0x18C (line counter), +0x190 (special-token counter), +0x194 (nesting depth) and a sub-object pointer at +0x1A4, all driven from the global token buffer (unk_7CD9D8 / unk_7CDB70). 0x00491FB0 reads lines via LineInputReader (0x005351D0) and classifies tokens via sub_5651B0; 0x00492030 skips to a delimiter and matches open/close tokens (asc_5CC4F8/asc_5CC4F4) through sub_587C20 keeping a balance counter; 0x00493060 validates a property string (0x0049A210), initializes the +0x1A4 sub-object and dispatches sound/font/size/offset/frame property tokens. Owner class is unknown; token grammar and token-type meanings are unproven.

Methods: `0x00491FB0`, `0x00492030`, `0x00493060`

- `this+0x0000018C` `int line_counter` (read_write, DERIVED)
- `this+0x00000190` `int special_token_counter` (read_write, DERIVED)
- `this+0x00000194` `int nesting_depth` (read_write, DERIVED)
- `this+0x000001A4` `ptr sub_object` (read, GUESS)

### RenderSurfaceManager

Video-manager initialization that builds three render surfaces (S-buffer 256x256, B-buffer 1024x1024, A-buffer 512x512). Each allocates a 96-byte descriptor (OperatorNewNhMallocWrapper + StructInitWithZeroFill via 0x0054FE10) stored in the dword_7CDE04/0x10/0x1C globals, configures it through sub_54FEC0 with the name token and dimensions, caches the +84 sub-object pointer into dword_7CDE08/0x14/0x20, and constructs a texture handle via ObjectConstructorWithAllocationAndSubInit (0x00553980) into dword_7CDE0C/0x18/0x24. When a construction returns 0, four UV-corner entries are installed via sub_553650 using the screen dimensions from dword_5D6D60/dword_5D6D64. Which buffer each token names and the +84 sub-pointer meaning are inferred.

Methods: `0x00494690`


### RenderDrawShim

Trivial forwarding stub over the render routine: accepts six arguments, drops the first and forwards a2..a6 unchanged to RenderDrawOperationWithClipping (0x00543440), returning that call's result verbatim. The unused first argument and the transitive shape are consistent with an indirection/dispatch shim; its purpose is not evidenced.

Methods: `0x00494BF0`


### RenderFrameSequence

Frame brackets around a render step driven by the shared conditional/timing state at unk_8AFE18 and the render-device pointer dword_8B8DC8. Both sequences call ConditionalInit(&unk_8AFE18) (0x004F9F00), perform the render/draw operation via sub_553700(dword_8B8DC8), then reset the conditional state (0x004F9F30). The multi-step variant additionally computes internal state flags via StateFlagComputation(0) (0x004F9B30) between render and reset.

Methods: `0x00495020`, `0x004950E0`


## Compatibility contracts

- **EmbeddedListLayout** — A replacement must preserve the embedded-list header relative to *this: head at obj+0xC, tail at obj+0x10, current marker at obj+0x14, count at obj+0x18, and node layout {+0 value, +4 next, +8 ownership flag} where the +8 flag gates whether the value is freed during unlink/destruction.
- **FlagGatedNodeFree** — Node teardown frees the object pointer at this+0x0 through FreeWrapper_7bcf only when the byte flag at this+0x8 is set; the flag therefore encodes value ownership and must be honored by any replacement node/pool implementation.
- **TeardownVtableRestore** — Destruction restores the vtable pointer at this+0x0 to off_5AC540 before virtual cleanup, calls ResourceCleanup, and frees the handle at this+0xE0 only when nonzero; a replacement destructor must follow the same ordering and guarded free.
- **HudTimerBaseInit** — The HUD timer constructor must call the base initializer 0x0048B420 with six zero arguments, install the vtable off_5ABF88, store the parameter at this+0x308, enable the byte flags at +0x304/+0x305 and initialize counters at +0x30C..+0x318.
- **RenderSurfaceDescriptors** — The render-surface initialization writes 96-byte surface descriptors into dword_7CDE04/0x10/0x1C, caches the sub-object pointer at descriptor+84 into dword_7CDE08/0x14/0x20, and stores the texture-handle construction results in dword_7CDE0C/0x18/0x24; these globals must keep their pairing and the +84 sub-pointer role in a replacement.
- **BroadphaseBucketArray** — The broadphase updater reads a header whose first dword (this+0x0) is the bucket count, with the array base at (*this)[2] and a ring index at (*this)[1]; elements are 16 bytes whose first three dwords form the substructure consumed by CollisionBroadphaseBuilder (0x00490EE0). A replacement must keep this bucket access discipline.
- **LineTokenReader** — The token reader 0x00491FB0 reads a line (256-byte input via 0x005351D0), returns 0 at end of input, increments counters at this+0x18C/+0x190 and continues for classified token types 1, 3 or 4, stopping on type 2 or types >= 5; a replacement text parser must reproduce this continuation contract.
- **WidgetPropertyTokenSet** — parseWidgetProperties dispatches the widget property token set (sound click/release/focus/lostfocus/drag, size, secondary offset, offset pair, font/font1/font2/font3, frame) read from the global token buffer; a replacement UI parser must honor the same token names and handler pairing.

## Unresolved

- All function owners are UNKNOWN in the packet; every class name here is a DERIVED grouping proposal, not an identified type.
- HudTimer (0x0048C070): semantics of parameter a2 (timer ID/interval/callback) and the roles of +0x304/+0x305 flags and +0x314/+0x318 fields are not independently confirmed; the vtable off_5ABF88 is not inspected.
- TimerListContainer (0x0048C9F0, 0x0048CC20): the meaning of the four zeroed extended fields (+0x31C..+0x328), the argument 0 passed to sub_48C070, the child-struct offsets 28/32 and the extra 2 in dimension one, and the base value 5 for the maxima are ungrounded; LinkedListDestructionWithVTableCall (0x0048D230) is named destructively but invoked during construction.
- ViewportRectangleRenderSetup (0x0048E750): the packet guard table lists the outer guard as this+0x78 == 2 but the raw source checks (child at this+0x40)+0x38 == 2; field:this:0x00000078 and the globals flt_5A68E8/flt_5A68EC are listed in evidence but do not appear in the raw text. The semantics of unk_8AFE18/dword_8AFE64 in the init/compare/reset sequence are unknown.
- BooleanFlagSetterVirtualCall (0x00490160): the virtual target at vtable slot 0x2C is not statically resolvable and the link between the boolean state and the dispatched method is unconfirmed.
- MemoryPoolAllocator: the pool object fields at head and index 1 are unnamed; why both allocator-pool and linked-list paths read them is unknown.
- PoolListContainer: the meaning of the a2-a5 AABB extents, the pool-node resource type, and the destination list receiving reparented values via LinkedListNodePrepend are not identified; the +8 flags-byte semantics are inferred from the free guard only.
- ValueLinkedList (0x00491D30): the relationship between the tail pointers tracked at obj+0x4 and this+0x4 needs an external layout check.
- RenderListIterator (0x00491CF0, 0x00491D10): the exact nature of the pointer at obj+0x1C and the node +0/+4 field roles (value/next inferred, not confirmed).
- TextWidgetParser: token-type meanings (1/3/4 continue vs 2/5+ stop), the nesting-token grammar of asc_5CC4F8/asc_5CC4F4, the role of the this[0x194] decrement, sub_587C20 hash semantics, and size/offset units are unproven; unk_7CD9D8 is listed but does not appear in the 0x00493060 raw body.
- RenderSurfaceManager: which buffers aAbuf/aBbuf/aSbuf name, the ObjectConstructorWithAllocationAndSubInit parameter meanings (2, 48/16, 64), the descriptor+84 sub-pointer role (likely a D3D surface), and whether sub_553650 writes texture-coordinate data into descriptors or a shared UV table are unconfirmed; dword_8AFE64 is listed as a global but never appears in the raw function text.
- RenderFrameSequence: dword_7CDE24 is listed as read by 0x00495020 (packet R evidence) but never appears in its raw body; dword_8B8DC8 is only labelled a render-device pointer by existing analysis; the trailing ConditionalStateReset has no recorded callee address.
- RenderDrawShim (0x00494BF0): the purpose of the dropped first argument a1 and why the indirection stub exists are not evidenced.
- Cluster relation of ByteSetterAt0xe0 to SimpleSetter_8bc0 (cluster representative 0x00488BC0) is structural only; shared-field semantics are not confirmed.
