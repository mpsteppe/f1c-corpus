# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `GUESS`

Reconstruction of generic runtime objects from 40 validated function IR records. The packet supplies UNKNOWN owners for every function except 0x00491680 (owner AxisAlignedBoundingBox, DERIVED) and a small set of DERIVED prose labels. All class groupings below are GUESS worker proposals. The strongest cross-function groupings are: (1) the ShortComputation_6720 state-dispatch family (0x00490330/0x00490390/0x004903F0) which share the state source, the obj+0x40 command slot and the VTableDispatchListIteration tail but differ in group arguments (2/5, 4/1, 1/4) and in the unconditional post slot (obj+0x98 for 0x00490330, obj+0x9C for the other two); (2) the AABB cluster (0x004915A0/0x00491680) sharing the four-__int16 box layout and broadphase callers; (3) the conditional free/teardown helper family (0x00491E60/0x00491E80/0x00499620) all routing through FreeWrapper_7bcf; (4) the two doubly-linked-list appends (0x004966E0/0x004967D0) which are structurally twin but are kept as separate classes because their embedded list headers sit at different this offsets (rule 8). The two twin this+0x44 getters (0x00498F70/0x0049904C) are merged into FieldGetter only as a proposal, with the packet's own warning that equal offsets on unrelated this pointers are not proof of shared class recorded in unresolved. Explicitly unmodeled: the jump-table mappings of the three dispatch functions, the identity of the vtable-slot callees, and the semantics of the desciptor-relative list fields in 0x00490850.

## Function roles

- `0x00490190` **FieldGetter** — State-flag zero getter (__thiscall): returns whether the word at field this+0xE0 is zero; used as a state-flag zero check before proceeding by its callers ParameterValueClampingAcrossArray (0x0047A080) and SuspensionFloatClamp (0x0047A290).
- `0x00490330` **StateDispatchObject** — State-dependent vtable dispatch: computes state via ShortComputation_6720 (0x00486720) and switches on it through jump table jpt_49033D (0x00490370); states 0-2 dispatch the vtable slot at obj+0x40 with argument 2, states 3-5 with argument 5, the default path dispatches nothing; then unconditionally calls the vtable slot at obj+0x98, iterates the child dispatch list via VTableDispatchListIteration (0x00490660), and returns 0.
- `0x00490390` **StateDispatchObject** — State-dependent vtable dispatch: computes state via ShortComputation_6720 (0x00486720) and switches on it through jump table jpt_49039D (0x004903D0); states 0-2 dispatch the vtable slot at obj+0x40 with argument 4, states 3-5 with argument 1, the default path dispatches nothing; then unconditionally calls the vtable slot at obj+0x9C, iterates the child dispatch list via VTableDispatchListIteration (0x00490660), and returns 0.
- `0x004903F0` **StateDispatchObject** — State-dependent vtable dispatch (thiscall): computes state via ShortComputation_6720 (0x00486720) and switches on it through jump table jpt_4903FD (0x0049042C); groups 0-2 dispatch the vtable slot at obj+0x40 with argument 1, groups 3-5 with argument 4, any other value skips the vtable dispatch; every path iterates the child dispatch list via VTableDispatchListIteration (0x00490660) and returns 0. Unlike the two siblings it has no unconditional post-dispatch vtable call.
- `0x00490850` **ResourcePoolTeardown** — Tears down a custom memory-pool/allocator subsystem: destroys and frees the allocator handle global dword_7CD9D0 (conditional destructor 0x00491740 then FreeWrapper_7bcf 0x00587BCF), then, when the pool descriptor global dword_7CD9CC is non-null, walks and frees two linked lists rooted in the descriptor (a used list at descriptor offset +16 and a free list at descriptor start), running per-node conditional cleanup helpers ShortComputation_1e60 (0x00491E60) and UtilityFunction_1e80 (0x00491E80), zeroing each list's head fields, and freeing the pool descriptor itself; returns the free-call result, or the descriptor value (0) when dword_7CD9CC was null.
- `0x00491350` **RectangleClipper** — Subtractive rectangle clipping: computes the area of a subject rectangle (this+0 x1, this+2 y1, this+4 / this+6 extents, all __int16) that lies outside a boundary rectangle (a2..a5), splits the space into a 3 by 3 grid, allocates a resource-pool node per surviving cell via ResourcePoolNodeAllocDealloc (0x00490940), copies the metadata word from this+8 into node+8, links the nodes into a singly linked list via the next-pointer at node offset 12, and returns the list head (0 when the subject is entirely inside the boundary).
- `0x004915A0` **AxisAlignedBoundingBox** — AABB containment check: returns 1 when the `this` AABB (x1 this+0, y1 this+2, width this+4, height this+6 as four __int16) lies fully inside the boundary AABB (a2, a3, a4, a5 with a4/a5 as widths); returns 0 otherwise. Called by sub_490D00 (0x00490D00) and CollisionBroadphaseTraversal (0x00491170), placing it in broadphase collision culling.
- `0x00491680` **AxisAlignedBoundingBox** — AABB overlap test: the this box is stored as four __int16 (min X this+0, min Y this+2, X span this+4, Y span this+6); the query box is given as min X, min Y, width and height (a2..a5). Both axes are clamped to the shared interval; the function returns whether the clamped Y span is positive, i.e. whether the boxes overlap. Packet owner is AxisAlignedBoundingBox (DERIVED).
- `0x00491760` **DelegateShimObject** — Single-call delegation shim: reads the object pointer stored at this+0x0, adds 60 bytes to form a _WORD* first argument, then delegates to ShortComputation_16e0 with that pointer plus the four __int16 values a2..a5, returning the __int16 result unchanged.
- `0x00491E60` **ConditionalFreeHelper** — __thiscall teardown helper: frees its own object via FreeWrapper_7bcf (0x00587BCF) when the low bit of the flag argument a2 is set, and always returns this afterwards. Used by ResourceLinkedListTeardown (0x00490850) and MultiListDestruction (0x00490B90) as a per-node cleanup step.
- `0x00491E80` **ConditionalFreeHelper** — Conditional payload free: reads the pointer stored at this+0x0; when it is non-null, treats it as a pointer to the payload of an allocation whose base lies 4 bytes earlier and hands that base to FreeWrapper_7bcf (0x00587BCF); when null, returns null without freeing. Used during resource linked-list teardown (caller 0x00490850).
- `0x00494620` **CallbackRegistrationShim** — Registration shim: passes the address of the LinkedListCleanupDestroy routine (global 0x00494630) to BooleanToIntConversion (0x00587B3E) and returns the integer it produces; most plausibly a one-line callback/registration wrapper.
- `0x00494FA2` **IdentityPassthrough** — Identity passthrough: returns its first argument a1 unchanged. The decompiler flagged the frame as unreliable and deterministic facts record a read of global dword_7CDDFC that the rendered source does not show.
- `0x00495110` **GlobalReader** — Trivial global read: returns the value of dword_8B8DC8 (0x008B8DC8) with no arguments and no side effects; its only recorded caller is UIScrollViewRender (0x00486AC0).
- `0x00495140` **GlobalReader** — Trivial global read: returns the current int value of dword_7CDE20 (0x007CDE20) with no parameters, no writes and no callees; its only known caller is FileLoadWithRetryLoop (0x004F9B70).
- `0x00495920` **TreeWalker** — Single-call wrapper (__stdcall): reads the dword at this+0x44 and passes it straight to TreeWalkerVirtualCallRecurse, returning that callee's result. Called by ShortComputation_58d0 (0x004958D0) to recurse into the child structure held at +0x44.
- `0x00495930` **TreeWalker** — Recursively walks a linked tree of nodes: rejects a NULL root with -1, then for each node invokes a virtual per-node callback (function pointer at vtable offset +160, obj+0xA0), recurses into the child subtree at dword index 36 (this+0x90), advances along the sibling chain (node[35]), and returns 0 after a full traversal.
- `0x00495970` **FieldGetter** — Field getter (__thiscall): returns the dword at this+0x18 (this[6]) unchanged; no writes, callees or guards. Its only known caller is ObjectSearchWithDoubleIteration (0x00495980).
- `0x00495B30` **RenderQueueDrain** — Drains a list by repeatedly invoking sub_495AE0 (0x00495AE0) while the element at this+0x18 (this[6]) is non-null and the permission check ShortComputation_8f70 (0x00498F70) returns exactly 1; exits the loop when the check returns a value other than 1 or the list element becomes null.
- `0x004963C0` **FieldSetter** — Flag setter (__thiscall): unconditionally writes constant 1 to the dword at this+0x28 (this[10]) and returns 0; no guards, callees or globals. Its only known caller is sub_485B90 (0x00485B90).
- `0x004966E0` **DoublyLinkedListB** — Doubly-linked-list append: allocates a 16-byte node via OperatorNewNhMallocWrapper (0x00587C03) with value at +0, next at +4, prev at +8, byte flag at +12; links it after the tail this+0x18E0; on an empty list also sets the head this+0x18DC and a secondary pointer this+0x18E4; updates the tail and increments the node count this+0x18E8. No action is taken when a2 is NULL.
- `0x004967D0` **DoublyLinkedListA** — Doubly-linked-list append: allocates a 16-byte node via OperatorNewNhMallocWrapper (0x00587C03), initializes its payload/next/prev/flag fields, links it after the tail this+0x18D0 (or seeds the head this+0x18CC and a secondary pointer this+0x18D4 on an empty list), updates the tail and increments the count this+0x18D8. A null a2 returns immediately without touching the list.
- `0x00496840` **SummationListCursor** — Iterates a singly linked list seeded from the head pointer at this+0x4 into a cursor at this+0xC, accumulating ShortComputation_58d0 (0x004958D0) of each node's first DWORD until the cursor is null or the node value is zero; advances via the node's next pointer at node+4 and returns the accumulated sum.
- `0x00496E20` **FieldGetter** — Reads the float field at byte offset 0xDC (this[55]) and compares it against the zero threshold flt_59E440 (0x0059E440, ~0.0f), returning BOOL true when the field is positive. Called by UILargeRender (0x00496930); the sign of the field likely indicates an active state.
- `0x00497240` **FieldGetter** — Trivial __thiscall byte getter: returns the byte field at offset 0x25 of this; no side effects, guards, globals or callees. Called by sub_496E90 (0x00496E90).
- `0x004972A6` **FieldSetter** — Trivial __thiscall byte-flag setter: copies the incoming byte parameter a2 into the byte field at offset 0x25 of this and returns the stored value; unconditional write, no guards, globals or callees. Structurally a twin of ByteFieldSetter (00497250), which writes the same offset.
- `0x004980C0` **FieldSetter** — Conditional __thiscall setter: stores the incoming parameter a2 into the dword field at offset 0x30 of this (this[12]) only when a2 is non-zero, and always returns a2 (0 when the write was skipped). No globals or callees. Called by sub_492160 (0x00492160).
- `0x004985D0` **TextMeasureTruncator** — Renders a text string through TextRenderToSurface (0x004983B0) and, when the measured width exceeds the caller's limit a2, truncates the string by nulling trailing characters one at a time and re-measuring until the width fits or the string is fully consumed. Returns 0 when the string is NULL, otherwise the last measured result.
- `0x00498650` **StringFieldSetter** — If the input string a2 is non-NULL and non-empty, copies it into an internal buffer via StringCopyWithBufferRealloc (0x00566650) and stores the three integer parameters a3, a4, a5 into the adjacent fields at this+0x1560, this+0x1564, this+0x1568, returning a3. If a2 is NULL or empty, the body is skipped and the function returns 0.
- `0x00498D00` **PathRegistrationObject** — Setter on an unknown path-registration object: copies the path string a2 into the internal string buffer at this+0x3C via StringCopyWithBufferRealloc (0x00566650), stores the associated integer a3 at this+0x44, and returns the copy result. Invoked by ProcessingDispatch (0x0046E590).
- `0x00498F70` **FieldGetter** — Getter with no side effects: returns the dword at this+0x44 (this[17]) of the object pointed to by `this`. The caller 0x00495B30 reads this field.
- `0x0049904C` **FieldGetter** — Getter with no side effects: returns the dword at this+0x44 (this[17]) of the object pointed to by `this`. Structurally identical to ShortComputation_8f70 but with no known callers and no ABI lead; equal offset 0x44 on an unrelated this pointer is not proof of shared class.
- `0x00499180` **VtableResetDtor** — __thiscall teardown step: writes the vtable pointer off_5ACA30 (0x005ACA30) into this+0x0, then returns the result of the dual list destruction routine on this object. Part of the object teardown sequence initiated by UiDestructorWithConditionalFree (0x00499160).
- `0x00499520` **LinkedListVirtualDispatch** — Iterates a linked list whose head is stored at this+0x44, dispatching a virtual call at vtable offset 0xA4 (attributed by the evidence to the type-info pointer at *(this+0xD0), i.e. slot *(this+0xD0)+0xA4) on each node, then advancing through the node's next pointer at node+0x8C. Terminates on a null node and always returns 0.
- `0x00499620` **ConditionalFreeHelper** — Conditional teardown helper: when the byte flag at this+0xC is non-zero, frees the inner heap block stored at this+0x0 via FreeWrapper_7bcf (0x00587BCF); when bit 0 of a2 is set, frees the container object itself; returns the original this pointer unchanged. Called by sub_495300 during object/container teardown.
- `0x00499660` **Global7CE040Wrapper** — Trivial single-call wrapper: passes the address of global unk_7CE040 (0x007CE040) as the sole argument to sub_4B3DB0 and returns that callee's result unchanged; no branches, no local computation, no own parameters.
- `0x00499670` **CallbackRegistrationShim** — Thin registration wrapper: reads the routine slot NullsubWrapper (global 0x00499680), passes its address cast to an integer to BooleanToIntConversion (0x00587B3E), and returns its result directly. No callers are recorded.
- `0x00499680` **Global7CE040Wrapper** — Trivial single-call wrapper: passes the address of global unk_7CE040 (0x007CE040) as the sole argument to EmptyStub_0170 and returns that callee's result unchanged; no branches, no local computation, no own parameters. This function's own address is the routine slot read by 0x00499670.
- `0x00499BF0` **StructEqualityWrap** — Thiscall wrapper that returns the boolean negation of StructEquality(this, a2) (callee 0x00499BB0); a nonzero return indicates the two structures differ.
- `0x00499C10` **StructSnapshotUpdater** — Struct update plus snapshot: copies six selected DWORD fields from source struct a3 into this (offsets 0x0, 0x4, 0x8, 0xC, 0x1C, 0x20), then copies the full 52-byte (0x34) content of this into the output buffer a2 via qmemcpy (fields not rewritten by a3 keep their prior this values), and returns the buffer pointer a2.

## Proposed classes

### FieldGetter

Trivial getters on unknown objects (GUESS merge of six offsets, each a different receiver): returns this+0xE0 zero-check (0x00490190), the positive-float check this+0xDC (0x00496E20), the byte at this+0x25 (0x00497240), the dword at this+0x18 (0x00495970) and the dword at this+0x44 (0x00498F70, 0x0049904C). Merged as one class because all are pure single-field reads with no side effects; the offsets belong to different objects and must not be assumed to share a base type until owners are proven.

Methods: `0x00490190`, `0x00496E20`, `0x00497240`, `0x00495970`, `0x00498F70`, `0x0049904C`

- `this+0x000000E0` `word zero_check_state_flag` (read, GUESS)
- `this+0x000000DC` `float positive_float_field` (read, GUESS)
- `this+0x00000025` `byte byte_state_field` (read, GUESS)
- `this+0x00000018` `dword dword_field_18` (read, GUESS)
- `this+0x00000044` `dword dword_field_44` (read, GUESS)

### FieldSetter

Trivial setters on unknown objects (GUESS merge of three offsets, each a different receiver): 0x004963C0 writes 1 to this+0x28, 0x004972A6 copies a byte to this+0x25, and 0x004980C0 stores a dword at this+0x30 only when the argument is non-zero. Each returns its stored/argument value.

Methods: `0x004963C0`, `0x004972A6`, `0x004980C0`

- `this+0x00000028` `dword enabled_flag` (write, GUESS)
- `this+0x00000025` `byte byte_flag` (write, GUESS)
- `this+0x00000030` `dword conditional_dword` (write, GUESS)

### StateDispatchObject

State-dependent vtable dispatch family (GUESS grouping): three functions (0x00490330, 0x00490390, 0x004903F0) that compute a state via ShortComputation_6720 (0x00486720), switch on it through their jump tables, dispatch the vtable slot at obj+0x40 with a group-selected argument, then iterate the child dispatch list via VTableDispatchListIteration (0x00490660). They differ in the group arguments (2/5, 4/1, 1/4) and in the unconditional post slot (obj+0x98 for 0x00490330, obj+0x9C for 0x00490390 and 0x004903F0; 0x004903F0 has no post slot). The concrete vtable targets are unknown because every call is indirect.

Methods: `0x00490330`, `0x00490390`, `0x004903F0`

- `this+0x00000000` `pointer vtable_ptr` (read, GUESS)
- `obj+0x00000040` `pointer command_setter_slot` (read, GUESS)
- `obj+0x00000098` `pointer post_dispatch_slot_98` (read, GUESS)
- `obj+0x0000009C` `pointer post_dispatch_slot_9C` (read, GUESS)

### ResourcePoolTeardown

Tears down a custom memory-pool/allocator subsystem driven by the globals dword_7CD9D0 (allocator handle) and dword_7CD9CC (pool descriptor). Destroys/frees the handle, then walks and frees the used list (descriptor offset +16) and free list (descriptor start), running per-node conditional cleanup helpers (0x00491E60, 0x00491E80), zeroing each list's head fields, and freeing the descriptor. No this fields are evidenced; descriptor-relative offsets are raw-source descriptions only.

Methods: `0x00490850`


### RectangleClipper

Subtractive rectangle clipping: computes the area of a subject rectangle (this+0 x1, this+2 y1, this+4 / this+6 extents, __int16) outside a boundary rectangle, splits the space into a 3 by 3 grid, allocates a resource-pool node per surviving cell via ResourcePoolNodeAllocDealloc (0x00490940), copies the metadata word from this+8 into node+8, and links the nodes into a singly linked list via the next-pointer at node offset 12. Returns the list head, or 0 when the subject is fully inside the boundary.

Methods: `0x00491350`

- `this+0x00000000` `__int16 subject_x1` (read, GUESS)
- `this+0x00000002` `__int16 subject_y1` (read, GUESS)
- `this+0x00000004` `__int16 subject_x_extent` (read, GUESS)
- `this+0x00000006` `__int16 subject_y_extent` (read, GUESS)
- `this+0x00000008` `__int16 metadata_word` (read, GUESS)

### AxisAlignedBoundingBox

Axis-aligned bounding box primitive storing four __int16 values at this+0/0x2/0x4/0x6 (min X, min Y, span X, span Y). 0x004915A0 (AABB containment, owner UNKNOWN in the packet) returns whether the this box lies fully inside a boundary AABB; 0x00491680 (AABB overlap, packet owner DERIVED AxisAlignedBoundingBox) clamps both axes to the shared interval and returns whether both clamped spans are positive. Both sit in broadphase collision culling via callers 0x00490D00 and 0x00491170.

Methods: `0x004915A0`, `0x00491680`

- `this+0x00000000` `__int16 min_x` (read, GUESS)
- `this+0x00000002` `__int16 min_y` (read, GUESS)
- `this+0x00000004` `__int16 span_x` (read, GUESS)
- `this+0x00000006` `__int16 span_y` (read, GUESS)

### DelegateShimObject

Single-call delegation shim: reads the object pointer stored at this+0x0, adds 60 bytes to form a _WORD* first argument, and delegates to ShortComputation_16e0 with that pointer plus four __int16 arguments, returning the __int16 result. Identity and layout of the object behind `this` are unknown; the callee is not evidenced in the packet.

Methods: `0x00491760`

- `this+0x00000000` `pointer target_object_ptr` (read, GUESS)

### ConditionalFreeHelper

Family of conditional-free teardown helpers (GUESS grouping of three distinct mechanisms, each routing through FreeWrapper_7bcf 0x00587BCF): 0x00491E60 frees its own object when flag bit 0 of a2 is set; 0x00491E80 frees the allocation base (stored pointer minus 4) when this+0x0 is non-null; 0x00499620 frees the inner block at this+0x0 when the byte flag at this+0xC is non-zero and the container itself when bit 0 of a2 is set. Grouped because all are per-node/container cleanup steps used during teardown; each member reads a different subset of fields.

Methods: `0x00491E60`, `0x00491E80`, `0x00499620`

- `this+0x00000000` `pointer inner_or_payload_ptr` (read, GUESS)
- `this+0x0000000C` `byte ownership_flag` (read, GUESS)

### CallbackRegistrationShim

Registration shims (GUESS grouping): 0x00494620 passes the address of the LinkedListCleanupDestroy routine (global 0x00494630) to BooleanToIntConversion (0x00587B3E); 0x00499670 reads the routine slot NullsubWrapper (global 0x00499680) and passes its address cast to int to the same callee. Both return the callee result. Whether 0x00587B3E truly converts bool-to-int or is a callback-registration wrapper is unverified.

Methods: `0x00494620`, `0x00499670`


### IdentityPassthrough

Identity passthrough returning its first argument a1 unchanged. The frame is flagged unreliable by the decompiler and deterministic facts record a read of global dword_7CDDFC that the rendered source does not show, so the true body is uncertain.

Methods: `0x00494FA2`


### GlobalReader

Trivial global readers (GUESS merge of two distinct globals): 0x00495110 returns dword_8B8DC8 (consumed by UIScrollViewRender) and 0x00495140 returns dword_7CDE20 (consumed by FileLoadWithRetryLoop). Pure reads with no parameters or side effects; writers are not in this packet.

Methods: `0x00495110`, `0x00495140`


### TreeWalker

Recursive tree walk (GUESS grouping of two receivers not proven to share a base type): 0x00495920 reads the child pointer at this+0x44 and forwards it into the recursive walk; 0x00495930 walks a linked tree of nodes, invoking a virtual per-node callback at vtable offset +160 (obj+0xA0), recursing into the child subtree at this+0x90 and advancing along the sibling chain, returning 0 after a full traversal (-1 for a NULL root).

Methods: `0x00495920`, `0x00495930`

- `this+0x00000044` `pointer child_root_ptr` (read, GUESS)
- `this+0x00000000` `pointer node_vtable_ptr` (read, GUESS)
- `obj+0x000000A0` `pointer per_node_callback` (read, GUESS)
- `this+0x00000090` `pointer child_subtree_ptr` (read, GUESS)

### RenderQueueDrain

Drains a list: repeatedly calls sub_495AE0 (0x00495AE0) to process the element at this+0x18 while it is non-null and the guard ShortComputation_8f70 (0x00498F70) returns exactly 1; exits when the guard returns another value or the list empties. The element type and the meaning of the guard value are not evidenced.

Methods: `0x00495B30`

- `this+0x00000018` `pointer queue_element_ptr` (read, GUESS)

### TextMeasureTruncator

Renders a text string through TextRenderToSurface (0x004983B0) and truncates it by nulling trailing characters until the measured width fits the caller's limit a2 or the string is emptied; returns 0 for a NULL string. No owned this fields evidenced; the render object is the receiver.

Methods: `0x004985D0`


### StringFieldSetter

Guarded string + three-integer setter: if the input string is non-NULL and non-empty, copies it into an internal buffer via StringCopyWithBufferRealloc (0x00566650) and stores three integer arguments into the adjacent fields at this+0x1560, this+0x1564, this+0x1568, returning the first; otherwise returns 0. The buffer base this+0x1558 is derived from the callee call, not present in the packet field list.

Methods: `0x00498650`

- `this+0x00001560` `int int_field_1560` (write, GUESS)
- `this+0x00001564` `int int_field_1564` (write, GUESS)
- `this+0x00001568` `int int_field_1568` (write, GUESS)

### PathRegistrationObject

Setter on an unknown path-registration object: copies the path string a2 into the internal buffer at this+0x3C via StringCopyWithBufferRealloc (0x00566650), stores the associated integer a3 at this+0x44, and returns the copy result. Invoked by ProcessingDispatch (0x0046E590).

Methods: `0x00498D00`

- `this+0x00000044` `int associated_int` (write, GUESS)

### VtableResetDtor

Teardown step that resets the object's vtable pointer at this+0x0 to off_5ACA30 (0x005ACA30), then returns the result of a dual list destruction routine on this; part of the object teardown sequence initiated by UiDestructorWithConditionalFree (0x00499160). The identity of the dual list destruction routine is not recorded in the packet callee list.

Methods: `0x00499180`

- `this+0x00000000` `pointer vtable_ptr` (write, GUESS)

### LinkedListVirtualDispatch

Iterates a linked list whose head is at this+0x44, dispatching a virtual call at vtable offset 0xA4 on each node (the evidence attributes the slot to the type-info pointer at *(this+0xD0)) and advancing via the node's next pointer at node+0x8C; terminates on a null node and returns 0. The relationship between the node's own vtable and the this+0xD0 type-info pointer is unresolved.

Methods: `0x00499520`

- `this+0x00000044` `pointer list_head` (read, GUESS)
- `this+0x000000D0` `pointer type_info_ptr` (read, GUESS)
- `*(this+0xD0)+0x000000A4` `pointer node_dispatch_slot_A4` (read, GUESS)

### Global7CE040Wrapper

Trivial single-call wrappers (GUESS merge): 0x00499660 calls sub_4B3DB0 and 0x00499680 calls EmptyStub_0170, each passing the address of the global unk_7CE040 (0x007CE040) as the sole argument and returning the callee's result unchanged. The callees are not in the packet callee list, so their signatures are unknown. 0x00499680's own address is the routine slot read by 0x00499670.

Methods: `0x00499660`, `0x00499680`


### StructEqualityWrap

Thiscall wrapper returning the boolean negation of StructEquality(this, a2) (callee 0x00499BB0). The semantics of StructEquality and the structure layout of this/a2 are outside this packet.

Methods: `0x00499BF0`


### StructSnapshotUpdater

Struct update plus snapshot: copies six selected DWORD fields from a source struct into this (offsets 0x0, 0x4, 0x8, 0xC, 0x1C, 0x20), then qmemcpy's the full 52-byte updated this into an output buffer and returns the buffer pointer. Source and destination struct types are unidentified.

Methods: `0x00499C10`

- `this+0x00000000` `dword field_00` (write, GUESS)
- `this+0x00000004` `dword field_04` (write, GUESS)
- `this+0x00000008` `dword field_08` (write, GUESS)
- `this+0x0000000C` `dword field_0C` (write, GUESS)
- `this+0x0000001C` `dword field_1C` (write, GUESS)
- `this+0x00000020` `dword field_20` (write, GUESS)

### DoublyLinkedListA

Doubly linked list whose embedded header sits at this+0x18CC (head), this+0x18D0 (tail), this+0x18D4 (secondary pointer also set on the empty-list path) and this+0x18D8 (count). Append (0x004967D0) allocates a 16-byte node (payload/next/prev/flag at +0/+4/+8/+12) via OperatorNewNhMallocWrapper, links it after the tail, seeds the head and secondary pointer on an empty list, and increments the count; a null payload returns immediately. Kept separate from DoublyLinkedListB because the two headers sit at different this offsets and the packet proves no common owner (rule 8).

Methods: `0x004967D0`

- `this+0x000018CC` `pointer list_head` (read_write, GUESS)
- `this+0x000018D0` `pointer list_tail` (read_write, GUESS)
- `this+0x000018D4` `pointer secondary_pointer` (write, GUESS)
- `this+0x000018D8` `int element_count` (read_write, GUESS)

### DoublyLinkedListB

Doubly linked list whose embedded header sits at this+0x18DC (head), this+0x18E0 (tail), this+0x18E4 (secondary pointer also set on the empty-list path) and this+0x18E8 (count). Append (0x004966E0) allocates a 16-byte node (value/next/prev/flag at +0/+4/+8/+12) via OperatorNewNhMallocWrapper, links it after the tail, seeds the head and secondary pointer on an empty list, and increments the count; a null payload takes no action. Kept separate from DoublyLinkedListA because the two headers sit at different this offsets and the packet proves no common owner (rule 8).

Methods: `0x004966E0`

- `this+0x000018DC` `pointer list_head` (read_write, GUESS)
- `this+0x000018E0` `pointer list_tail` (read_write, GUESS)
- `this+0x000018E4` `pointer secondary_pointer` (write, GUESS)
- `this+0x000018E8` `int element_count` (read_write, GUESS)

### SummationListCursor

Iterates a singly linked list seeded from the head pointer at this+0x4 into a cursor at this+0xC, accumulating ShortComputation_58d0 (0x004958D0) of each node's first DWORD until the cursor is null or the node value is zero; advances via the node's next pointer at node+4 and returns the accumulated sum.

Methods: `0x00496840`

- `this+0x00000004` `pointer list_head` (read, GUESS)
- `this+0x0000000C` `pointer iteration_cursor` (read_write, GUESS)

## Compatibility contracts

- **StateDispatchContract** — A state-dispatched object must compute its state via ShortComputation_6720 (0x00486720), switch on the state through its jump table, dispatch the vtable slot at obj+0x40 with the group-selected argument (2/5, 4/1 or 1/4 depending on the member), call the unconditional post-dispatch vtable slot (obj+0x98 for 0x00490330, obj+0x9C for 0x00490390 and 0x004903F0) where present, iterate the child dispatch list via VTableDispatchListIteration (0x00490660) on every path, and return 0.
- **ResourcePoolTeardownContract** — Pool teardown must destroy and free the allocator handle (global dword_7CD9D0) when non-null, then, when the pool descriptor (global dword_7CD9CC) is non-null, walk and free the used list at descriptor offset +16 and the free list at descriptor start, running per-node cleanup via the helpers 0x00491E60 and 0x00491E80, zero each list's head fields, free the descriptor itself, and return the free-call result (or 0 when the descriptor was null).
- **AABBBoundsContract** — An AABB is stored as four __int16 at this+0 (min X), this+2 (min Y), this+4 (span X), this+6 (span Y); a query/boundary box is given as (min X, min Y, width, height) with a4/a5 used as widths. Containment (0x004915A0) requires the top-left inside and bottom-right not beyond the boundary; overlap (0x00491680) requires both clamped axis spans to be positive.
- **RectangleClippingContract** — Subtractive clipping must compute the subject rectangle area (this+0/0x2/0x4/0x6) outside a boundary rectangle (a2..a5), split the space into a 3 by 3 grid, allocate one resource-pool node per surviving cell via ResourcePoolNodeAllocDealloc (0x00490940), copy the subject metadata word from this+8 into node+8, link the nodes into a singly linked list via the next-pointer at node offset 12, and return the list head (0 when the subject is fully inside the boundary).
- **DoublyLinkedListAppendContract** — Append must, when the payload argument is non-null, allocate a 16-byte node via OperatorNewNhMallocWrapper (0x00587C03) with payload at node+0, next at +4, prev at +8 and a byte flag at +12, link the node after the tail, seed the head and a secondary pointer on an empty list, update the tail and increment the count, and take no action for a null payload. The two observed embedded headers are 0x18CC-0x18D8 (DoublyLinkedListA) and 0x18DC-0x18E8 (DoublyLinkedListB); the packet does not prove they are the same class (rule 8).
- **ConditionalFreeContract** — Conditional-free teardown helpers must release storage via FreeWrapper_7bcf (0x00587BCF) only when the gating condition holds and must return the receiver unchanged: 0x00491E60 frees its own object when flag bit 0 of a2 is set; 0x00491E80 frees the allocation base (stored pointer at this+0x0 minus 4) when that pointer is non-null; 0x00499620 frees the inner block at this+0x0 when the byte flag at this+0xC is non-zero and the container itself when bit 0 of a2 is set.
- **StringTruncationContract** — Text rendering with truncation must measure the string via TextRenderToSurface (0x004983B0), and when the measured width exceeds the caller's limit a2, null out trailing characters one at a time and re-measure until the width fits or the string is emptied; it must return 0 when the input string is NULL.

## Unresolved

- General: every owner in the packet is UNKNOWN except 0x00491680 (AxisAlignedBoundingBox, DERIVED), so all class groupings here are GUESS worker proposals; equal offsets on different this bases are never merged without packet proof of common ownership (rule 8).
- The two doubly-linked-list appends (0x004966E0, 0x004967D0) are structurally twin but kept as separate classes because their embedded headers sit at different this offsets (0x18CC-0x18D8 vs 0x18DC-0x18E8); whether they are two embedded lists of one class or two unrelated classes is unprovable from this packet.
- 0x00498F70 and 0x0049904C are structurally identical this+0x44 getters; they are merged into FieldGetter only as a proposal, and the packet's own warning stands: equal offset 0x44 on an unrelated this pointer is not proof that the objects share the class of the structurally identical getter.
- 0x00491760: the callee ShortComputation_16e0 is named in the raw source but has no packet callee evidence ref; its identity is not independently confirmed.
- 0x00494FA2: deterministic facts mark global dword_7CDDFC as read but the rendered decompilation is only `return a1;`; the compiler-flagged unreliable frame means the true body is uncertain.
- 0x00495920: TreeWalkerVirtualCallRecurse is named in the raw source text but has no packet callee evidence ref; its address and identity are not independently confirmed.
- 0x00495930: the packet lists a read at this+0x118 that is not present in the raw source (the raw source advances the walk via dword index 35); its role here is unknown.
- 0x00496840: the field at this+0x10 is listed in evidence but never accessed by this function.
- 0x00499520: the purpose of the read-only field this+0x15C is unknown; the dispatch base is ambiguous - the raw decompile dereferences the node's own vtable (*node + 164) while the field evidence attributes vtable slot 0xA4 to base *(this+0xD0).
- 0x00499660 / 0x00499680: the callees sub_4B3DB0 and EmptyStub_0170 are not listed in the packet callees; their signatures and behavior are unknown here, and the purpose of passing global unk_7CE040 is unknown.
- 0x004966E0: on allocation failure the NULL node is still linked into the list and the count is still incremented; whether the list tolerates a NULL node is unconfirmed; the read-side purpose of this+0x18E4 and the meaning of the node byte flag at node+12 are unknown.
- 0x004967D0: the same allocation-failure latent-bug pattern applies; the read-side purpose of field 0x18D4 is not visible within this function.
- 0x00490850: node layout semantics (first dword resource/vtable pointer, +4 next, +8 flag) are inferred from raw source only with no packet field evidence; the exact meaning of the ShortComputation_1e60(1) argument is unknown; no static callers exist in the packet.
- 0x00491350: whether this+4/this+6 are extents or absolute right/bottom coordinates is ambiguous from source:raw; the meaning of the metadata word copied from this+8 into each output node is unknown; exact node layout beyond the next-pointer at offset 12 and metadata at offset 8 is unknown.
- 0x00498650: the semantic meaning of the three integer fields 0x1560/0x1564/0x1568 is unknown; the string buffer base this+0x1558 is not represented in the packet field list; no callers exist in the packet.
- 0x00498D00: the object type and purpose of the registered path are unknown; the meaning of the stored integer a3 at this+0x44 is caller-defined.
- 0x00499C10: source and destination struct types are not identified; only six of the twelve DWORD slots inside the 0x34-byte region are explicitly rewritten from a3; the purpose of returning the snapshot buffer pointer a2 is unknown without callers.
- 0x00494620 / 0x00499670: whether callee 0x00587B3E truly converts boolean-to-int or is a callback-registration wrapper is unverified; whether the routine arguments (0x00494630, 0x00499680) are function pointers or plain data is unresolved.
- 0x00495B30: the element type behind this+0x18 and the exact semantics of the 1 return value from ShortComputation_8f70 are not evidenced.
- 0x00490190: the exact meaning of the flag at this+0xE0 (enabled/active/visible) and whether it is an enum vs a boolean are outside this packet.
- 0x00496E20: the exact value of flt_59E440 (~0.0f) is DERIVED from the fill, not proven here; the semantic meaning of the positive float at +0xDC is not established.
- 0x00499BF0: the semantics of StructEquality (0x00499BB0) and the exact structure layout of this/a2 are outside this packet.
- 0x004915A0: the caller sub_490D00 (0x00490D00) is unnamed; its role in the collision flow is unknown; whether a4/a5 are widths or absolute coordinates depends on the caller contract (the containment math uses them as widths).
- 0x00499180: the identity and address of the called dual list destruction routine are not recorded in the packet's callee list.
- 0x004985D0: a3 is treated as both an output width pointer and, after the first call, the string source for re-measurement; the exact parameter contract (single string vs separate width output) is not fully resolved.
