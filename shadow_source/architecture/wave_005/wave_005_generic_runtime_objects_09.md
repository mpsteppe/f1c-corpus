# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

DERIVED reconstruction of generic runtime objects around 0x00497D20-0x00499E80. Clusters are grounded in the packet field evidence and callee/caller links: (1) a surface loader (0x00497D20) that resolves a base directory from globals dword_5EC400/byte_5EA438, tells a global init object (dword_8AC4C4) to set that base via vtable+0x44, creates a surface via vtable+0x5C, validates via vtable+0x14, and appends an 88-byte {name@+0, handle@+0x50, next@+0x54} node to a list rooted at this+0x10C with counter at this+0x110; (2) a sprite/texture slot registry (0x00498950) scanning up to four entry slots (base this+1407 dwords, 3-dword stride) with name comparison and a global-reset fallback; (3) an intrusive node-list container (0x00498E30, 0x00498E50, 0x00498F40, 0x00499E00) sharing head this+0x48, tail this+0x50, counter this+0x58 and list field this+0x68 with node next at node+72 and an owner back-link at node+80; (4) a virtual-node-list iterator pair (0x00498F80, 0x00498FB0) structurally identical except vtable slot 0x70 vs 0x74, iterating list one from this+0x4C and list two from this+0x94; (5) a dual-list container (0x00498D90, 0x00498DF0) with vtable off_5AC9E8, first-list head this+0x48 and a field-block initializer over this+0x48..0x68 plus zero-fills at 0x6C and 0x94; (6) a render-object registry (0x00499280, 0x00499360) with list head this+0x44, registration counter this+0x54, and a destructor freeing buffers at 0x58/0x60; (7) a centered-scroll registrar (0x004992E0) storing a registered pointer at this+0x4C and computing spans from this+0x54..0x60; (8) a guarded render-surface fill (0x00499050) gated on mode this+0x7C; (9) a typed node list teardown (0x00499580) with nodes {vtable@+0, next@+4, destroy-flag@+0xC}; (10) a rendering-context tree-traversal iterator (0x00499910) with explicit state machine on this+0x0 plus setup helpers (0x00499840, 0x004998E0); (11) a path/string registry entry family (0x004999E0, 0x00499A00, 0x00499A70, 0x00499AB0, 0x00499AE0) sharing layout {+0 string ptr, +4 -1 sentinel, +8 value} and the byte_5EA438 default path; (12) a ten-slot record container (0x00499C50) with active/id records this+0x10..0x5C and its scalar deleting destructor (0x00499CC0); (13) a float-scalar field decrement (0x00499A20); (14) seven structurally identical stdcall delegates (0x00499E10..0x00499E80) forwarding to StringCopyWithBufferRealloc (0x00566650). All owner identities remain UNKNOWN in the packet; class grouping is structural and must not be promoted to CONFIRMED.

## Function roles

- `0x00497D20` **SurfaceLoaderRegistry** — Surface loader: guard null name and null init object (dword_8AC4C4); no-op return 1 when name already loaded (sub_497E80); resolve base dir (dword_5EC400 else byte_5EA438), set it via init object vtable+0x44, build path buffer, create surface via vtable+0x5C (path, 0, 15), validate via vtable+0x14, allocate 88-byte node (OperatorNewNhMallocWrapper 0x00587C03) storing name at +0, handle at +0x50, next at +0x54, append at tail of list head this+0x10C, increment counter this+0x110, free temp buffer, return 1.
- `0x00498950` **SpriteTextureRegistry** — Sprite/texture slot scan: return 0 on null input; scan up to four entry slots (base this+1407 dwords, 3-dword stride) via FloatThresholdCheck (0x00499A50) for active slot, StringPointerDereference (0x0049A2B0) for the entry string, sub_588410 (0x00588410) name comparison; on match return 0; when exactly 3 entries active reset global byte_5EA438 via StringFieldSetter (0x00499A30) and invoke sub_495B60; else StringFieldSetter(a2, this+0xD8) and return its result.
- `0x00498D90` **DualListContainer** — Dual-list destructor: restore vtable off_5AC9E8 at this+0x0; walk first list from head this+0x48 dispatching virtual destructor (vtable slot 0, flag 1) on each node and advancing via node next at +0x48; obtain second-list head via ShortComputation_8f60 (0x00498F60); walk it through StructFieldAccessor (0x00486320) reading next via *(this+0x90)+0x48 and dispatching virtual destructor; return final cleanup result.
- `0x00498DF0` **DualListContainer** — Field-block initializer: set dword fields this+0x48/0x4C/0x50/0x58/0x5C/0x64/0x68 to 0 and this+0x60 to 1; zero-fill 0x28-byte blocks at this+0x6C and this+0x94; return 0; invoked by InitWithVTableParam (0x00498D20) during object setup.
- `0x00498E30` **IntrusiveNodeList** — Trivial list-head getter: return the dword at this+0x48 with no side effects; called by list/tree/UI traversal paths (0x004958D0, 0x004974A0, 0x004976C0, 0x00497890, 0x00498E50, 0x00499870).
- `0x00498E50` **IntrusiveNodeList** — Node insertion into an intrusive list: increment counter this+0x58; store owner back-link at a2+80; run ShortComputation_a9c0 (0x0049A9C0) over cached fields this+0x4/0x8/0xC/0x10; when head FieldGetter_8e30 (0x00498E30) is non-null walk node next at +72 and append a2; empty list sets head this+0x48 and tail this+0x50 to a2; return a2.
- `0x00498F40` **IntrusiveNodeList** — Conditional setter plus virtual dispatch: when a2 is non-zero store it at this+0x50; unconditionally dispatch vtable offset 44 (0x2C) with argument 1 and return its result; callers LinkedListSearchWithAction (0x004974A0) and UtilityFunction_7890 (0x00497890).
- `0x00498F80` **VirtualNodeListIterator** — Two-list virtual iteration: iterate list one from head this+0x4C advancing via StructFieldAccessor (0x00486320); iterate list two from head this+0x94; dispatch virtual method at vtable slot 112 (0x70) on every node of both lists.
- `0x00498FB0` **VirtualNodeListIterator** — Two-list virtual iteration, sibling of 0x00498F80: iterate list one from head this+0x4C and list two from head this+0x94 via StructFieldAccessor (0x00486320); dispatch virtual method at vtable slot 116 (0x74) on every node of both lists.
- `0x00499050` **RenderSurfaceFillDispatch** — Guarded render-surface sub-rectangle fill: read mode at this+0x7C (via sub-structure pointer this+0x54 plus 40 bytes); when mode equals 2 obtain render surface via Accessor (0x00490920) and fill the sub-rectangle via RenderSurfaceFillCopy (0x004918D0), storing the result into the low byte of the returned value; otherwise return mode-minus-2.
- `0x00499140` **VTableParamInitializedObject** — Constructor with base init and vtable override: run base/parent initialization via InitWithVTableParam (0x00498D20) forwarding a2, then overwrite this+0x0 with the derived-class vtable off_5ACA30; return this; invoked by sub_492460.
- `0x00499280` **RenderObjectRegistry** — Object destructor with list walk: swap vtable to off_5ACA74 at this+0x0; walk linked list head this+0x44 dispatching virtual destructor (vtable slot 0, flag 1) on each node while advancing via StructFieldAccessor (0x00486320); free buffers at this+0x58 and this+0x60 via FreeWrapper_7bcf (0x00587BCF) when non-null; return the tail-call result of the raw-source helper; called by ConditionalDestructor_9260.
- `0x004992E0` **CenteredScrollRegistrar** — Object registration with centered scroll: when a2 non-null store it at this+0x4C; when flag a3 set read geometry half-extents from the object at a2+12 fields +28/+32, compute centering deltas from spans this+0x54..0x60 against reference offsets this+0x4/this+0xC, and dispatch via ScrollOffsetUpdateWithConditionalDispatch (0x0049ACC0); return a2.
- `0x00499360` **RenderObjectRegistry** — Object registration into a parent-owned list: store parent this into a2+0x9C; dispatch MultiRegionOffsetAccumulationWithVTableDispatch (0x004869E0) with this+0xC and this+0x4; empty head this+0x44 becomes a2, else walk to tail via StructFieldAccessor (0x00486320) and link via FieldSetterAt0x8c (0x00486330) writing a2 into the tail node's 0x8C field; increment counter this+0x54 on both paths; return a2.
- `0x00499580` **TypedNodeLinkedList** — Typed linked-list teardown: walk node chain from list head this+0x0 via node next at +4; for each node with destroy-flag byte node+0xC set and a valid vtable pointer at node+0x0 dispatch virtual destructor (vtable slot 0, delete flag 1); free every node via FreeWrapper_7bcf (0x00587BCF); zero list fields this+0x0/0x4/0x8/0xC; return the last free result.
- `0x00499840` **RenderTreeTraversal** — Passthrough wrapper: call SmallStructInit (0x00499850) then return the receiver unchanged; invoked from RenderingContextSetup (0x00497750) as a per-render-context init hook.
- `0x004998E0` **RenderTreeTraversal** — State-list setup with fallback: initialize receiver via SmallStructInit (0x00499850); store a2 at dword index 3; when a2 non-zero clear index 0, copy the dword at a2+28 into index 2, zero indices 4 and 5, and fall back to sub_499910 (0x00499910) when the copied dword is zero; return the copied dword (or a2 when zero); called by RenderingContextSetup (0x00497750).
- `0x00499910` **RenderTreeTraversal** — Tree-traversal next-node iterator: state machine on this+0x0 (0 init, 1 sibling-descend, 2 child-iterate) with done flag this+0x4, current item this+0x8, container state this+0xC, parent this+0x10 and child-list head this+0x14; yields the next node each call, advancing sibling next-pointers at item+0x8C and child lists under the parent (child head at parent+0x48, first child at +0x44, sibling at parent+0x4C) with LinkedListNodeTraversal_98c0 (0x004998C0) and LinkedListIteratorAdvance (0x00499870); sets done flag and returns when exhausted; called by RenderingContextSetup (0x00497750) and 0x004998E0.
- `0x004999E0` **PathRegistryEntry** — Registry-entry init: zero this+0x0, set this+0x4 to the -1 sentinel, then delegate to SmallStructInit (0x00499A00); return this; called from LargeStructZeroInit (0x00495190) during a larger construction sequence.
- `0x00499A00` **PathRegistryEntry** — Small struct init: copy the default path string global byte_5EA438 via StringCopyWithBufferRealloc (0x00566650) and zero the dword at this+0x8; return the string-copy result; invoked by sub_495B60 and 0x004999E0.
- `0x00499A20` **FloatScalarState** — Float field decrement: subtract float argument a2 from the field at this+0x8 in place and return void; sole caller sub_495B60.
- `0x00499A70` **PathRegistryEntry** — Data-entry copy with self-assignment guard: return -1 when a2 equals this; read the source string pointer *a2 falling back to default byte_5EA438 when null, copy via StringCopyWithBufferRealloc (0x00566650), copy the value field this+0x8 from a2+0x8; return 0; sole caller sub_495B60.
- `0x00499AB0` **PathRegistryEntry** — Path-registry entry constructor: zero this+0x0, set this+0x4 to -1, copy the string argument a2 via StringCopyWithBufferRealloc (0x00566650), store a3 at this+0x8; return this; invoked by BitmapLoader (0x004979F0).
- `0x00499AE0` **PathRegistryEntry** — Free if non-null: read the pointer at this+0x0; when non-null free it via FreeWrapper_7bcf (0x00587BCF) and return that result, otherwise return the null value unchanged.
- `0x00499C50` **SlotRecordContainer** — Slot-record container constructor: install vtable off_5ACAAC at *this, store the context argument at this+0x4, zero this+0x8/0xC, initialize ten slot records this+0x10..0x5C as (active flag 0, id sentinel -1), zero trailing fields this+0x60..0x78; return this; called by sub_493060.
- `0x00499CC0` **SlotRecordContainer** — Scalar deleting destructor: unconditionally run the real destructor DestructorWithMultipleConditionalFrees (0x00499CE0), then free the object via FreeWrapper_7bcf (0x00587BCF) only when the low bit of the deleting-destructor flag a2 is set; return this unchanged.
- `0x00499E00` **IntrusiveNodeList** — Trivial field getter: return the dword at this+0x68 with no side effects; callers use the field for linked-list bookkeeping.
- `0x00499E10` **StringCopyDelegate** — Thin stdcall forwarding wrapper: forward argument a1 to StringCopyWithBufferRealloc (0x00566650) and return its result verbatim; called by sub_493060 (0x00493060).
- `0x00499E30` **StringCopyDelegate** — Thin stdcall forwarding wrapper, structurally identical to a nearby sibling: forward argument a1 to StringCopyWithBufferRealloc (0x00566650) and return its result; called by sub_493060 (0x00493060).
- `0x00499E40` **StringCopyDelegate** — Thin stdcall forwarding wrapper: forward argument a1 to StringCopyWithBufferRealloc (0x00566650) and return its result; called by sub_493060 (0x00493060); legacy ABI label Path_Registry_Wrapper is not established by the raw source.
- `0x00499E50` **StringCopyDelegate** — Thin stdcall forwarding wrapper: forward argument a1 to StringCopyWithBufferRealloc (0x00566650) and return its result; called by sub_493060 (0x00493060); the delegate target named by the legacy ABI label is absent from the packet and not treated as evidence.
- `0x00499E60` **StringCopyDelegate** — Thin stdcall forwarding wrapper: forward argument a1 to StringCopyWithBufferRealloc (0x00566650) and return its result; called by sub_493060 (0x00493060).
- `0x00499E70` **StringCopyDelegate** — Thin stdcall forwarding wrapper: forward argument a1 to StringCopyWithBufferRealloc (0x00566650) and return its result; called by sub_493060 (0x00493060); legacy ABI label Path_Registry_Wrapper is not established by the raw source.
- `0x00499E80` **StringCopyDelegate** — Thin stdcall forwarding wrapper: forward argument a1 to StringCopyWithBufferRealloc (0x00566650) and return its result; called by sub_493060 (0x00493060); legacy ABI label Delegation_to_Path_Registry is not established by the raw source.

## Proposed classes

### SurfaceLoaderRegistry

Loads surfaces/textures by name and registers them in a per-object intrusive list. 0x00497D20 guards on a null name and a null global init object, is idempotent for already-loaded names, resolves the base directory from globals dword_5EC400/byte_5EA438, drives the init object at dword_8AC4C4 through vtable slots 0x44 (set base), 0x5C (create surface), 0x14 (validate), allocates an 88-byte node {name at +0, surface handle at +0x50, next at +0x54}, appends it to the list head this+0x10C and increments the counter at this+0x110. The list traversal field this+0x160 is recorded as read by the analysis table but no read appears in the raw source; it may be a provenance alias.

Methods: `0x00497D20`

- `this+0x0000010C` `ptr loaded_surface_list_head` (read_write, DERIVED)
- `this+0x00000110` `int loaded_surface_count` (read_write, DERIVED)
- `this+0x00000160` `ptr list_base_alias` (read, GUESS)
- `*(*(this+0x160)+0x54)+0x00000054` `ptr surface_node_next` (read, GUESS)

### SpriteTextureRegistry

Scans up to four sprite/texture entry slots on this (base this+1407 dwords, 3-dword stride) comparing a caller-supplied name against each active entry's string. 0x00498950 returns 0 on match or null input; with exactly three active entries it resets the default path global byte_5EA438 and invokes sub_495B60; otherwise it writes this+0xD8 into the target's string field. The entry-slot element structure is not evidenced.

Methods: `0x00498950`

- `this+0x000000D8` `dword default_string_value` (read, GUESS)

### DualListContainer

Object managing two linked lists of polymorphic nodes. 0x00498DF0 initializes the field block this+0x48..0x68 (0x60 set to 1, rest 0) and zero-fills 0x28-byte regions at this+0x6C and this+0x94, and is invoked by InitWithVTableParam (0x00498D20). 0x00498D90 restores vtable off_5AC9E8 and destroys the first list from head this+0x48 (node next at +0x48) and a second list whose head comes from ShortComputation_8f60 (0x00498F60) and whose traversal next pointer is read via *(this+0x90)+0x48. Grouping the two functions as one class is structural and not proven to share an object; the packet does not establish that the two list node layouts are identical.

Methods: `0x00498D90`, `0x00498DF0`

- `this+0x00000000` `ptr vtable_ptr` (read_write, GUESS)
- `this+0x00000048` `ptr list_one_head` (read_write, GUESS)
- `this+0x0000004C` `dword list_one_field` (write, GUESS)
- `this+0x00000050` `ptr list_one_tail` (write, GUESS)
- `this+0x00000058` `dword list_field_0x58` (write, GUESS)
- `this+0x0000005C` `dword list_field_0x5C` (write, GUESS)
- `this+0x00000060` `dword list_field_0x60` (write, GUESS)
- `this+0x00000064` `dword list_field_0x64` (write, GUESS)
- `this+0x00000068` `dword list_field_0x68` (write, GUESS)
- `*(this+0x48)+0x00000000` `ptr list_one_node_vtable` (read, GUESS)
- `*(this+0x90)+0x00000048` `ptr list_two_node_next` (read, GUESS)

### IntrusiveNodeList

Intrusive node-list container: head at this+0x48 (exposed by the trivial getter 0x00498E30), tail/value at this+0x50, node counter at this+0x58 and a bookkeeping dword at this+0x68. 0x00498E50 increments the counter, stores an owner back-link at node+80, runs ShortComputation_a9c0 (0x0049A9C0) over cached fields this+0x4/0x8/0xC/0x10 and appends the node via +72 next-pointers (empty list sets head/tail). 0x00498F40 conditionally stores into this+0x50 and dispatches vtable slot 0x2C with argument 1. 0x00499E00 reads the bookkeeping dword. Node next offset 0x48 and the owner back-link at node+0x50 are shared with sibling containers but common ownership is not proven.

Methods: `0x00498E30`, `0x00498E50`, `0x00498F40`, `0x00499E00`

- `this+0x00000000` `ptr vtable_ptr` (read, GUESS)
- `this+0x00000004` `dword cached_field_a` (read, GUESS)
- `this+0x00000008` `dword cached_field_b` (read, GUESS)
- `this+0x0000000C` `dword cached_field_c` (read, GUESS)
- `this+0x00000010` `dword cached_field_d` (read, GUESS)
- `this+0x00000048` `ptr list_head` (read_write, DERIVED)
- `this+0x00000050` `ptr list_tail` (read_write, DERIVED)
- `this+0x00000058` `int node_count` (read_write, DERIVED)
- `this+0x00000068` `dword bookkeeping_field` (read, GUESS)
- `obj+0x0000002C` `fn_ptr virtual_dispatch_slot` (read, GUESS)

### VirtualNodeListIterator

Iterates two intrusive lists of polymorphic nodes and dispatches a virtual method on every node. 0x00498F80 dispatches vtable slot 112 (0x70); the structurally identical sibling 0x00498FB0 dispatches vtable slot 116 (0x74). List one is rooted at this+0x4C and list two at this+0x94, both advanced via StructFieldAccessor (0x00486320) until a null node. The identity of the dispatched method (existing analysis labels it render/draw, DERIVED, unproven) and the node layout are unresolved.

Methods: `0x00498F80`, `0x00498FB0`

- `this+0x0000004C` `ptr list_one_head` (read, DERIVED)
- `this+0x00000050` `ptr list_two_base` (read, GUESS)
- `this+0x00000094` `ptr list_two_head` (read, DERIVED)
- `*(this+0x4C)+0x00000070` `fn_ptr list_one_vtable_slot_112` (read, DERIVED)
- `*(this+0x4C)+0x00000074` `fn_ptr list_one_vtable_slot_116` (read, DERIVED)
- `*(this+0x94)+0x00000000` `ptr list_two_node_vtable` (read, DERIVED)
- `*(*(this+0x94)+0x0)+0x00000070` `fn_ptr list_two_vtable_slot_112` (read, DERIVED)
- `*(*(this+0x94)+0x0)+0x00000074` `fn_ptr list_two_vtable_slot_116` (read, DERIVED)

### RenderSurfaceFillDispatch

Guarded render-surface sub-rectangle fill (0x00499050): reads the mode value at this+0x7C reached through the sub-structure pointer at this+0x54 plus 40 bytes; when the mode equals 2 it obtains the render surface via Accessor (0x00490920) and fills the sub-rectangle via RenderSurfaceFillCopy (0x004918D0), storing the fill result into the low byte of the returned value. Callers are render-path functions; the owning render object is unknown.

Methods: `0x00499050`

- `this+0x00000054` `ptr sub_structure_ptr` (read, GUESS)
- `this+0x0000007C` `int render_mode` (read, DERIVED)

### VTableParamInitializedObject

Object whose constructor (0x00499140) runs the shared base/parent initializer InitWithVTableParam (0x00498D20) and then overrides this+0x0 with the derived-class vtable off_5ACA30, returning this. The class identity implied by the vtable and the behavior of the base initializer are outside this packet.

Methods: `0x00499140`

- `this+0x00000000` `ptr vtable_ptr` (write, GUESS)

### RenderObjectRegistry

Object-registration container whose destructor (0x00499280) swaps the vtable to off_5ACA74, walks the list head this+0x44 dispatching the virtual destructor on each node, and frees buffers at this+0x58 and this+0x60; the registration method (0x00499360) stores the parent back-link into a2+0x9C, dispatches MultiRegionOffsetAccumulationWithVTableDispatch (0x004869E0) with this+0xC and this+0x4, links the new object into the list rooted at this+0x44 (tail via StructFieldAccessor, link write via FieldSetterAt0x8c into the tail node's 0x8C field) and increments the counter at this+0x54. Field semantics for this+0x4/0xC and the node layout supplied by the callees are not established in this packet.

Methods: `0x00499280`, `0x00499360`

- `this+0x00000000` `ptr vtable_ptr` (read_write, GUESS)
- `this+0x00000004` `int offset_ref_x` (read, GUESS)
- `this+0x0000000C` `int offset_ref_y` (read, GUESS)
- `this+0x00000044` `ptr registered_list_head` (read_write, DERIVED)
- `this+0x00000054` `int registered_count` (read_write, GUESS)
- `this+0x00000058` `ptr buffer_a` (read_write, GUESS)
- `this+0x00000060` `ptr buffer_b` (read_write, GUESS)
- `*(this+0x44)+0x00000000` `ptr node_vtable_ptr` (read, GUESS)
- `*(*(this+0x44)+0x0)+0x00000000` `fn_ptr node_virtual_destructor_slot` (read, GUESS)

### CenteredScrollRegistrar

Registers an object pointer at this+0x4C and, when the a3 flag is set, computes a centered scroll offset from the registered object's geometry (half-extents at a2+12 fields +28/+32) and the spans this+0x54..0x60 against reference offsets this+0x4/this+0xC, dispatching it through ScrollOffsetUpdateWithConditionalDispatch (0x0049ACC0). The span interpretation is DERIVED from the arithmetic, not confirmed; the a3 flag semantics are unresolved.

Methods: `0x004992E0`

- `this+0x00000004` `int reference_offset_x` (read, GUESS)
- `this+0x0000000C` `int reference_offset_y` (read, GUESS)
- `this+0x0000004C` `ptr registered_object` (write, DERIVED)
- `this+0x00000050` `ptr scroll_sub_struct` (read, GUESS)
- `this+0x00000054` `int span_field_a` (read, GUESS)
- `this+0x00000058` `int span_field_b` (read, GUESS)
- `this+0x0000005C` `int span_field_c` (read, GUESS)
- `this+0x00000060` `int span_field_d` (read, GUESS)

### TypedNodeLinkedList

Generic linked-list teardown (0x00499580) over nodes of the form {vtable at +0, next at +4, destroy-flag byte at +0xC}. Walks the chain from head this+0x0; for each node with the destroy flag set and a valid vtable pointer, dispatches the virtual destructor at vtable slot 0 with delete flag 1; frees every node via FreeWrapper_7bcf; zeroes list fields this+0x0/0x4/0x8/0xC; returns the last free result. The semantics of the zeroed fields beyond container reset are unknown.

Methods: `0x00499580`

- `this+0x00000000` `ptr list_head` (read_write, DERIVED)
- `this+0x00000004` `dword list_field_0x4` (read_write, GUESS)
- `this+0x00000008` `dword list_field_0x8` (read_write, GUESS)
- `this+0x0000000C` `dword list_field_0xC` (read_write, GUESS)
- `obj+0x00000000` `ptr node_vtable_ptr` (read, GUESS)
- `obj+0x0000000C` `byte node_destroy_flag` (read, GUESS)
- `*(obj+0x0)+0x00000000` `ptr node_vtable_guard_value` (read, GUESS)
- `*(obj+0x4)+0x00000004` `ptr node_next` (read, DERIVED)
- `*(*(obj+0x0)+0x0)+0x00000000` `fn_ptr node_virtual_destructor_slot` (read, GUESS)

### RenderTreeTraversal

Rendering-context tree-traversal infrastructure. 0x00499840 is a passthrough wrapper delegating to SmallStructInit (0x00499850). 0x004998E0 sets up a state list with a fallback to the iterator. 0x00499910 is a state-machine iterator that yields tree nodes one call at a time: state this+0x0 (0 init, 1 sibling-descend, 2 child-iterate), done flag this+0x4, current item this+0x8, container state this+0xC, parent this+0x10, child-list head this+0x14; siblings advance along item+0x8C and child lists are reached via parent+0x48/+0x4C. The concrete container/node classes are unidentified; state-machine and layout facts are DERIVED.

Methods: `0x00499840`, `0x004998E0`, `0x00499910`

- `this+0x00000000` `int traversal_state` (read_write, DERIVED)
- `this+0x00000004` `byte done_flag` (read_write, DERIVED)
- `this+0x00000008` `ptr current_item` (read_write, DERIVED)
- `this+0x0000000C` `ptr container_state` (read_write, DERIVED)
- `this+0x00000010` `ptr parent` (read, DERIVED)
- `this+0x00000014` `ptr child_list_head` (read_write, DERIVED)
- `*(this+0x8)+0x0000008C` `ptr item_sibling_next` (read, DERIVED)
- `*(this+0x10)+0x00000048` `ptr parent_child_list` (read, DERIVED)
- `*(this+0x10)+0x0000004C` `ptr parent_sibling` (read, DERIVED)
- `*(this+0x14)+0x00000044` `ptr child_head_first_node` (read, DERIVED)
- `*(*(this+0x10)+0x48)+0x00000044` `ptr child_node_next` (read, DERIVED)
- `*(this+0xC)+0x00000004` `ptr container_sibling_head` (read, DERIVED)
- `*(this+0xC)+0x0000000C` `dword container_state_slot` (read_write, DERIVED)
- `*(*(this+0xC)+0x4)+0x00000000` `ptr first_sibling` (read, DERIVED)
- `*(*(*(this+0xC)+0x4)+0x0)+0x0000004C` `ptr first_sibling_link` (read, DERIVED)

### PathRegistryEntry

Path/string registry entry with the shared layout {+0 string pointer, +4 -1 empty sentinel, +8 value}. 0x00499AB0 builds an entry from a path string and an identifier, 0x004999E0 zeroes +0 and sets the -1 sentinel before delegating to SmallStructInit (0x00499A00), which copies the default path global byte_5EA438 and zeroes +8. 0x00499A70 copies an entry with a self-assignment guard and a byte_5EA438 fallback for null source strings. 0x00499AE0 frees the +0 pointer when non-null. The string-copy destination buffer offset and the meaning of the +8 value are not evidenced in this packet.

Methods: `0x004999E0`, `0x00499A00`, `0x00499A70`, `0x00499AB0`, `0x00499AE0`

- `this+0x00000000` `ptr path_string_ptr` (read_write, DERIVED)
- `this+0x00000004` `int empty_sentinel` (read_write, DERIVED)
- `this+0x00000008` `dword value_field` (read_write, DERIVED)

### FloatScalarState

Object exposing a float field at this+0x8 that is decremented in place by 0x00499A20 (argument a2 subtracted, no guards, no callees). Sole caller sub_495B60. The purpose of the scalar (timer, temperature, fuel, etc.) is not confirmed. Kept separate from PathRegistryEntry because this+0x8 is a float here while it is a dword value there; common ownership is unproven.

Methods: `0x00499A20`

- `this+0x00000008` `float float_field` (read_write, GUESS)

### SlotRecordContainer

Container of ten slot records. The constructor (0x00499C50) installs vtable off_5ACAAC at *this, stores a constructor-context argument at this+0x4, zeroes this+0x8/0xC, initializes each of the ten records spanning this+0x10..0x5C as (active flag 0, id sentinel -1) and zeroes the trailing fields this+0x60..0x78, returning this. 0x00499CC0 is the scalar deleting destructor pattern paired by adjacency: it runs the real destructor 0x00499CE0 and frees storage only when the deleting flag bit 0 is set. The pairing is structural/adjacency-based GUESS; the semantics of the slot records are unresolved.

Methods: `0x00499C50`, `0x00499CC0`

- `this+0x00000000` `ptr vtable_ptr` (write, GUESS)
- `this+0x00000004` `dword context_arg` (write, GUESS)
- `this+0x00000008` `dword field_0x8` (write, GUESS)
- `this+0x0000000C` `dword field_0xC` (write, GUESS)
- `this+0x00000010` `byte slot00_active` (write, GUESS)
- `this+0x00000014` `int slot00_id` (write, GUESS)
- `this+0x00000018` `byte slot01_active` (write, GUESS)
- `this+0x0000001C` `int slot01_id` (write, GUESS)
- `this+0x00000020` `byte slot02_active` (write, GUESS)
- `this+0x00000024` `int slot02_id` (write, GUESS)
- `this+0x00000028` `byte slot03_active` (write, GUESS)
- `this+0x0000002C` `int slot03_id` (write, GUESS)
- `this+0x00000030` `byte slot04_active` (write, GUESS)
- `this+0x00000034` `int slot04_id` (write, GUESS)
- `this+0x00000038` `byte slot05_active` (write, GUESS)
- `this+0x0000003C` `int slot05_id` (write, GUESS)
- `this+0x00000040` `byte slot06_active` (write, GUESS)
- `this+0x00000044` `int slot06_id` (write, GUESS)
- `this+0x00000048` `byte slot07_active` (write, GUESS)
- `this+0x0000004C` `int slot07_id` (write, GUESS)
- `this+0x00000050` `byte slot08_active` (write, GUESS)
- `this+0x00000054` `int slot08_id` (write, GUESS)
- `this+0x00000058` `byte slot09_active` (write, GUESS)
- `this+0x0000005C` `int slot09_id` (write, GUESS)
- `this+0x00000060` `dword field_0x60` (write, GUESS)
- `this+0x00000064` `dword field_0x64` (write, GUESS)
- `this+0x00000068` `dword field_0x68` (write, GUESS)
- `this+0x0000006C` `dword field_0x6C` (write, GUESS)
- `this+0x00000070` `dword field_0x70` (write, GUESS)
- `this+0x00000074` `dword field_0x74` (write, GUESS)
- `this+0x00000078` `dword field_0x78` (write, GUESS)

### StringCopyDelegate

Family of seven structurally identical thin stdcall forwarding wrappers (0x00499E10, 0x00499E30, 0x00499E40, 0x00499E50, 0x00499E60, 0x00499E70, 0x00499E80), each taking a single argument a1 and returning the result of StringCopyWithBufferRealloc (0x00566650) verbatim. All are called by sub_493060 (0x00493060), which is external to this packet. The wrapper family is likely used to expose distinct callable entry points over the same helper; the purpose is unresolved.

Methods: `0x00499E10`, `0x00499E30`, `0x00499E40`, `0x00499E50`, `0x00499E60`, `0x00499E70`, `0x00499E80`


## Compatibility contracts

- **SurfaceLoadIdempotency** — A replacement executable must reproduce 0x00497D20 return semantics: 0 for a null surface name, a null init object, or a failed surface creation; 1 when the name was already loaded (no-op) or after a successful load and registration.
- **SurfaceInitObjectDispatch** — The init object referenced by global dword_8AC4C4 must expose vtable slot +0x44 (set the load base directory), vtable slot +0x5C (create a surface from a path buffer with the two literal arguments 0 and 15) and vtable slot +0x14 (report created-surface validity).
- **DeletingDestructorFlag** — Virtual destructor vtable slot 0 takes a delete flag. Scalar deleting destructor 0x00499CC0 unconditionally runs the real destructor 0x00499CE0 and frees the object via FreeWrapper_7bcf only when the low bit of the flag is set; list teardown (0x00499280, 0x00499580) dispatches vtable slot 0 with delete flag 1 on every node.
- **RegistryEntrySentinel** — Path/string registry entries reserve +4 as the -1 empty/invalid sentinel, hold a string pointer at +0 and a value at +8, and copy the default path global byte_5EA438 into the entry buffer when the source string is null; 0x00499A70 rejects self-assignment with -1.
- **TreeTraversalIteratorContract** — The iterator 0x00499910 yields one tree node per call in state order 0 (init), 1 (sibling-descend), 2 (child-iterate), returning to state 1 after each successful sibling advance; when exhausted it sets the done flag at this+0x4 and the following call clears the current item and returns immediately.

## Unresolved

- All owning class identities are UNKNOWN in the packet; the class grouping above is structural and must not be promoted to CONFIRMED.
- this+0x54 is read as a scroll-span component in 0x004992E0 (CenteredScrollRegistrar) but as a registration counter in 0x00499360 (RenderObjectRegistry); whether both functions operate on the same object is unproven, so they are modeled as separate classes.
- this+0x8 is a dword value in PathRegistryEntry (0x00499A70, 0x00499AB0) but a float in 0x00499A20 (FloatScalarState); the two classes are kept separate and the relationship is unknown.
- The identity of all vtable dispatch targets is dynamic and unresolved: off_5AC9E8, off_5ACA30, off_5ACA74, off_5ACAAC, vtable slots 0x70/0x74/0x2C/0x44/0x5C/0x14, and the virtual destructor slot 0.
- DualListContainer groups 0x00498D90 with 0x00498DF0 on structural grounds (shared list fields around 0x48, both reachable from the 0x00498D20 init family); the packet does not prove they share an object.
- SlotRecordContainer pairs 0x00499CC0 with 0x00499C50 by adjacency and complementarity (constructor plus scalar deleting destructor); the real destructor 0x00499CE0 is external to the packet.
- SpriteTextureEnumeration's entry-slot array (base this+1407 dwords, 3-dword stride) has no evidenced element structure, and the meaning of the value written from this+0xD8 is unknown.
- sub_493060 (0x00493060), the common caller of the seven StringCopyDelegate wrappers and of 0x00499C50, is external to the packet; the purpose of the wrapper family (distinct callable entry points over StringCopyWithBufferRealloc) is not established.
- The byte_5EA438 default path global and the byte_5EA438 reset in 0x00498950 share the name with the path buffer base used by 0x00497D20; their identity as the same global is consistent with the evidence but not proven to be a single path register.
- MultiFieldStructInit's zero-fill regions at this+0x6C and this+0x94 have no packet field entries of their own; the 0x28-byte blocks are represented only by the raw assignment operations.
