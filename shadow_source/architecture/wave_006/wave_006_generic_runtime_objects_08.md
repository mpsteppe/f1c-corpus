# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `GUESS`

This packet groups generic runtime objects evidenced only by validated function IR. The dominant pattern is the MSVC scalar-deleting destructor: write the object vtable into this+0, run a common cleanup fragment (usually InitWithVTableCleanup 0x00487250, which itself writes vtable off_5AB968 and delegates to the shared helper sub_485EB0), then free this via FreeWrapper_7bcf when the low bit of the flag argument is set. Eleven such stubs (0x00485510, 0x004855A0, 0x004855D0, 0x00485600, 0x00485630, 0x00485660, 0x004856F0, 0x00485A70, 0x00485B20, 0x00487690, 0x00487F10) plus the three vtable-reset fragments (0x00487250, 0x00487F30, 0x00488B30) are grouped as a pattern family, with the caveat that each installs a distinct vtable constant and grouping is not common-ownership proof. A second family is the UI dispatch/validation control: handlers validate the current value (UIValueValidator), set handler state via sub_487260, handle radio/check changes, perform a secondary validation through vtable slot +0x98, and finalize via sub_486600 (0x00487530, 0x004879E0, 0x00487E10, plus the toggle helper 0x00487D70 and state predicates 0x00487720/0x00487740). A third cluster operates on linked lists: node-freeing destructor 0x004859D0 and two traversals (0x00486600 head +0xCC, 0x00486630 head +0xD0) that call sub_49A5D0 per node. UI layout objects cover scroll clamping (0x00488970, setter 0x00488BC0) and screen-coordinate to list-index conversion (0x00489F40). Text-edit widgets initialize their buffer and flags (0x0048B4F0, 0x0048B7E0). A collision-system cluster shares global dword_8AB6EC (0x0047C940 difference-from-average, 0x0047C9D0 thunk to RangeWidthGetter, 0x0047CA30 timer dispatch into CollisionSystemInit). 0x0047C910 is a standalone constructor installing vtable off_5A6A68. 0x0047EE5C is a free-standing data-block init with no recorded callers. Compatibility contracts capture the scalar-deleting ABI, the dword_8AB6EC protocol, the vtable-slot layout used by UI dispatch, the text-edit buffer layout, and the list-index formula.

## Function roles

- `0x0047C910` **UIObjectBase** — UI object constructor: calls base UI constructor UIConstructorWithVTableParams, zeroes field +0xFC, installs vtable off_5A6A68, returns this.
- `0x0047C940` **CollisionSystemObject** — Compute float difference: run shared Delegation step on global dword_8AB6EC, then return the caller's double truncated to float minus the lifetime average read by VehicleLifetimeAverageAccessor.
- `0x0047C9D0` **CollisionSystemObject** — Thunk: forwards the address of global dword_8AB6EC to RangeWidthGetter as its single argument; invoked by CollisionSystemInit during collision-system setup.
- `0x0047CA30` **CollisionSystemObject** — Timer-based float dispatch: compute float via ShortComputation_89d0, pass it to CollisionSystemInit, return 0.
- `0x0047EE5C` **Unassigned** — Init from data block: copy 36 bytes from global unk_7D0A30, format the integer via '%d' through the buffer-overflow-checked formatter, conditionally dispatch the formatted buffer via ConditionalCallWrapper, return 0.
- `0x0047F3F0` **BufferResourceObject** — Scalar-deleting destructor: reset vtable to off_5A6E70, free three non-null buffer pointers at +0x219C/+0x2194/+0x218C via FreeWrapper_7bcf, chain to base destructor sub_495300 and return its result; the object teardown path invoked by SimpleGetter.
- `0x00485510` **ScalarDeletingObject** — Scalar-deleting destructor (vtable off_5AB4A0): write vtable, run common cleanup via InitWithVTableCleanup, free this via FreeWrapper_7bcf when flag bit 0 set, return this.
- `0x004855A0` **ScalarDeletingObject** — Scalar-deleting destructor (vtable off_5AB290): write vtable, common cleanup via InitWithVTableCleanup, conditional free, return this.
- `0x004855D0` **ScalarDeletingObject** — Scalar-deleting destructor (vtable off_5AB1E0): write vtable, common cleanup via InitWithVTableCleanup, conditional free, return this.
- `0x00485600` **ScalarDeletingObject** — Scalar-deleting destructor (vtable off_5AB130): write vtable, common cleanup via InitWithVTableCleanup, conditional free, return this.
- `0x00485630` **ScalarDeletingObject** — Scalar-deleting destructor (vtable off_5AB080): write vtable, common cleanup via InitWithVTableCleanup, conditional free, return this.
- `0x00485660` **ScalarDeletingObject** — Scalar-deleting destructor (vtable off_5AAFD0): write vtable, common cleanup via InitWithVTableCleanup, conditional free, return this.
- `0x004856F0` **ScalarDeletingObject** — Scalar-deleting destructor (vtable off_5A9660): write vtable, common cleanup via InitWithVTableCleanup, conditional free, return this.
- `0x004859D0` **ListBufferDestroyer** — Complex destructor: walk linked list rooted at +0x164 freeing each node data (when node flag byte at +0x8 non-zero) and each node, clear list fields +0x164/+0x168/+0x16C/+0x170, free standalone buffer +0x15C when non-null, run ConditionalDualCleanup on sub-objects +0x11C and +0xE0, chain to base destructor sub_485EB0, and free this when flag bit 0 set.
- `0x00485A70` **ScalarDeletingObject** — Scalar-deleting destructor wrapper: run object teardown via ShortComputation_6140, then free this via FreeWrapper_7bcf when flag bit 0 set, return this.
- `0x00485B20` **ScalarDeletingObject** — Scalar-deleting destructor: free sub-resources at +0x17C and +0x174 when non-null, run common cleanup FunctionCallWrapper_9440, free this when flag bit 0 set, return this.
- `0x00486600` **LinkedListCallbackTraverser** — List traversal: iterate singly linked list with head this[51] at +0xCC, advancing via node next pointer at node offset +0x18, invoking sub_49A5D0 once per node; returns 0.
- `0x00486630` **LinkedListCallbackTraverser** — List traversal: iterate linked list with head this[52] at +0xD0, advancing via node next pointer at node offset +0x18, invoking sub_49A5D0 once per node; returns 0.
- `0x00486F00` **UIConditionalRenderWidget** — Guarded conditional rectangle render: when enable flag set and sub-renderer pointer at +0x98 non-null, dispatch four bounds from +0x4/+0x8/+0xC/+0x10 to GuardedSubRectangleRenderDispatch; otherwise return the this pointer byte.
- `0x00487160` **UIOffsetLookupTable** — Indexed offset-pair lookup: guard against boundary from ShortComputation_adb0 with flag at +0xC8, fetch pair via LinkedListIndexedFieldReader, write combined offsets this[3]+v7 and this[1]+v8; returns 0 on guard/reader failure, 1 on success.
- `0x00487250` **VTableCleanupInitFragment** — Vtable-reset-before-cleanup fragment: write vtable off_5AB968 into this+0 then delegate to shared cleanup helper sub_485EB0; used on both construction and destruction paths.
- `0x00487530` **UIValidatedDispatchControl** — Validated UI dispatch: primary validation via UIValueValidator, set handler state via sub_487260(this,1), handle radio/check state via UIRadioCheckStateChangeHandler, secondary validation through vtable slot +0x98, finalize via sub_486600; returns -1 on any failure, 0 on success.
- `0x00487690` **ScalarDeletingObject** — Scalar-deleting destructor: run sub-computation ShortComputation_76b0 on the object, then free this via FreeWrapper_7bcf when flag bit 0 set, return this.
- `0x00487720` **UIValidatedDispatchControl** — Pure predicate over ShortComputation_6720 result: true when the callee result is 1 or 3.
- `0x00487740` **UIValidatedDispatchControl** — Range check: true when ShortComputation_6720 result lies in the inclusive range [2, 3].
- `0x004879E0` **UIValidatedDispatchControl** — Validated UI dispatch init: primary validation via UIValueValidator, state-dependent vtable dispatch StateDependentVTableDispatch_7760(this,1), propagate control state change via UIControlStateChangeHandler, secondary validation through vtable slot +0x98, finalize via sub_486600; returns -1 on failure, 0 on success.
- `0x00487D70` **UIValidatedDispatchControl** — Pointer-based state toggle: retrieve child via vtable slot +0xAC (short-circuit through +0x38 with argument 1 when null), clear via +0x38 with argument 0, compute toggle value from child first dword inverted by flag +0xE4, set state via sub_487260 on change and notify via vtable slot +0x2C with argument 1.
- `0x00487E10` **UIValidatedDispatchControl** — Validated dispatch with value toggle: primary validation via UIValueValidator, set handler state via sub_487260, radio/check handling via UIRadioCheckStateChangeHandler, obtain value pointer through vtable slot +0xAC and toggle it (0<->1) when non-null, secondary validation through vtable slot +0x98, finalize via sub_486600; returns -1 on failure, 0 on success.
- `0x00487F10` **ScalarDeletingObject** — Scalar-deleting destructor: perform base vtable cleanup via VTableSetCleanup, then free this via FreeWrapper_7bcf when flag bit 0 set, return this.
- `0x00487F30` **VTableCleanupInitFragment** — Vtable-reset-before-cleanup fragment: write vtable off_5ABAC8 into this+0 then delegate to shared cleanup helper sub_485EB0 on a destruction path.
- `0x00488970` **ScrollContainer** — Clamp scroll offset at +0xE0: reset to 0 when negative, else clamp so offset + position (vtable slot +0x18) stays within extent (vtable slot +0x20); tail-call the accessor at vtable slot +0xA8 and return its result.
- `0x00488B30` **VTableCleanupInitFragment** — Vtable-reset fragment: write vtable off_5ABC28 into this+0 then delegate to shared helper sub_485EB0 for further initialization or teardown.
- `0x00488BC0` **ScrollContainer** — Trivial setter: store argument a2 into DWORD at offset +0xE0 and return a2; used by ConstructorDualSubInit as a field writer.
- `0x00489F40` **ListLayoutIndexer** — Convert screen y-coordinate to list item index from layout fields: trunc((a2 - 0x13C - 0x134 - 0x4) / 0x158) + 0x14C via CRTFtol, clamped within scroll and (when a3 set) visible-page and total-count bounds; returns -1 when item height not positive or y outside the vertical range.
- `0x0048B4F0` **TextBoxEditWidget** — Initialize edit-box fields: clear string buffer first byte (+0x2F0), point cursor +0x2F4 at buffer start, buffer size +0x2F8=256, char limit +0x300=16, length +0x2E8=0, and set byte flags +0xE0..0xE5, +0x1E7, +0x2EC; returns 0.
- `0x0048B7E0` **TextBoxEditWidget** — Text edit buffer init: store buffer pointer into +0x2F0 and size into +0x2F8, then call virtual slot at vtable+168 (0xA8) with argument 1; guarded on non-null pointer and positive size; returns 0. Called by UITextFieldInitialization.
- `0x0048B910` **UIWidgetForwardWrapper** — Forwarding shim: read DWORD at offset +0x0, return result of widget-visibility toggle called with (*this, a2, this, a2); used by UIEventShortcutHandler and UIActiveStateToggle.
- `0x0048BC70` **UIWidgetForwardWrapper** — Active-focus wrapper: toggle active/focused state via UIActiveStateToggle, then dispatch the virtual method at vtable entry offset 0xAC on this; returns 0.

## Proposed classes

### CollisionSystemObject

Cluster of collision-system helpers sharing the global dword_8AB6EC: difference-from-lifetime-average computation, a thunk forwarding the global address to RangeWidthGetter, and a timer-based float dispatch into collision-system initialization. Grouping is pattern-based (shared global and adjacent addresses); object ownership is UNKNOWN.

Methods: `0x0047C940`, `0x0047C9D0`, `0x0047CA30`


### UIObjectBase

Constructor-only fragment: calls the base UI constructor, zeroes a field at +0xFC, and installs vtable off_5A6A68. Class identity UNKNOWN; the +0xFC field semantics (dispatch mode/state) are unproven.

Methods: `0x0047C910`

- `this+0x00000000` `vtable pointer VTablePtr` (write, DERIVED)
- `this+0x000000FC` `int32 (unproven dispatch/state field) DispatchOrStateFlag` (write, GUESS)

### BufferResourceObject

Object holding three buffer pointers at +0x218C/+0x2194/+0x219C with vtable off_5A6E70; its destructor frees each non-null buffer then chains to base destructor sub_495300. Class identity UNKNOWN (existing analysis hints screen-data texture manager, unverified).

Methods: `0x0047F3F0`

- `this+0x00000000` `vtable pointer VTablePtr` (write, DERIVED)
- `this+0x0000218C` `pointer (buffer allocation) BufferPointer1` (read_write, DERIVED)
- `this+0x00002194` `pointer (buffer allocation) BufferPointer2` (read_write, DERIVED)
- `this+0x0000219C` `pointer (buffer allocation) BufferPointer3` (read_write, DERIVED)

### VTableCleanupInitFragment

Three vtable-reset-before-cleanup fragments, each installing a distinct vtable (off_5AB968, off_5ABAC8, off_5ABC28) into this+0 then delegating to the shared cleanup helper sub_485EB0. Appear on both construction and destruction paths; each fragment belongs to its own object and grouping is pattern-based.

Methods: `0x00487250`, `0x00487F30`, `0x00488B30`

- `this+0x00000000` `vtable pointer VTablePtr` (write, DERIVED)

### ScalarDeletingObject

Group of MSVC scalar-deleting-destructor stubs: install the object vtable at this+0, run a common cleanup (usually InitWithVTableCleanup 0x00487250, sometimes a sub-computation such as ShortComputation_6140/ShortComputation_76b0/VTableSetCleanup), then free this via FreeWrapper_7bcf when flag bit 0 is set, returning this. Each method installs a distinct vtable; grouping is pattern-based and is NOT proof of common ownership.

Methods: `0x00485510`, `0x004855A0`, `0x004855D0`, `0x00485600`, `0x00485630`, `0x00485660`, `0x004856F0`, `0x00485A70`, `0x00485B20`, `0x00487690`, `0x00487F10`

- `this+0x00000000` `vtable pointer VTablePtr` (write, DERIVED)
- `this+0x00000174` `pointer (freed sub-resource) SubResourceA` (read, GUESS)
- `this+0x0000017C` `pointer (freed sub-resource) SubResourceB` (read, GUESS)

### ListBufferDestroyer

Destructor of an object owning a singly linked list (head at +0x164; node data pointer at node+0x0, next at node+0x4, flag byte at node+0x8), a standalone buffer at +0x15C, and two sub-objects at +0x11C and +0xE0; it frees the nodes and buffer, clears the list fields, cleans the sub-objects via ConditionalDualCleanup, chains to base destructor sub_485EB0, and conditionally frees itself.

Methods: `0x004859D0`

- `this+0x000000E0` `pointer (sub-object cleaned by ConditionalDualCleanup) SubObjectE0` (read, GUESS)
- `this+0x0000015C` `pointer (freed buffer) StandaloneBufferPtr` (read, GUESS)
- `this+0x00000164` `pointer (linked-list head) ListHead` (read, DERIVED)
- `this+0x00000168` `int32 (list tail/count/state, cleared to 0) ListField168` (write, GUESS)
- `this+0x0000016C` `int32 (list tail/count/state, cleared to 0) ListField16C` (write, GUESS)
- `this+0x00000170` `int32 (list tail/count/state, cleared to 0) ListField170` (write, GUESS)
- `*(this+0x164)+0x00000000` `pointer (node data) NodeDataPtr` (read, DERIVED)
- `*(*(this+0x164)+0x4)+0x00000004` `pointer (next list node) NodeNextPtr` (read, DERIVED)
- `*(this+0x164)+0x00000008` `byte (flag: non-zero frees node data) NodeDataFlagByte` (read, DERIVED)

### LinkedListCallbackTraverser

Object exposing one or more linked lists whose nodes carry a next pointer at +0x18; traverses the list calling sub_49A5D0 once per node. One traversal reads its head at +0xCC, the other at +0xD0; these may be two lists on one object or two objects, and the extractor renders the node base as *(this+0xE4) and *(this+0xE8) respectively.

Methods: `0x00486600`, `0x00486630`

- `this+0x000000CC` `pointer (linked-list head) ListHeadA` (read, DERIVED)
- `this+0x000000D0` `pointer (linked-list head) ListHeadB` (read, DERIVED)
- `*(this+0xE4)+0x00000018` `pointer (next list node) NodeNextA` (read, DERIVED)
- `*(this+0xE8)+0x00000018` `pointer (next list node) NodeNextB` (read, DERIVED)

### UIConditionalRenderWidget

UI widget that conditionally renders a rectangle through a sub-renderer pointer when an enable flag is set: rectangle bounds stored at +0x4/+0x8/+0xC/+0x10 and sub-renderer pointer at +0x98 are dispatched to GuardedSubRectangleRenderDispatch.

Methods: `0x00486F00`

- `this+0x00000004` `float (rectangle bound left) BoundLeft` (read, GUESS)
- `this+0x00000008` `float (rectangle bound right) BoundRight` (read, GUESS)
- `this+0x0000000C` `float (rectangle bound top) BoundTop` (read, GUESS)
- `this+0x00000010` `float (rectangle bound bottom) BoundBottom` (read, GUESS)
- `this+0x00000098` `pointer (sub-renderer/delegate) SubRendererPtr` (read, GUESS)

### UIOffsetLookupTable

Indexed offset-pair lookup table used by UI rendering helpers (rectangle drawing and text-box scrollbar rendering): returns two combined offsets derived from base offsets +0x4 and +0xC plus indexed values fetched through LinkedListIndexedFieldReader, guarded by a boundary helper and a flag at +0xC8.

Methods: `0x00487160`

- `this+0x00000004` `int32 (base offset) BaseOffsetA` (read, DERIVED)
- `this+0x0000000C` `int32 (base offset) BaseOffsetB` (read, DERIVED)
- `this+0x000000C8` `byte (guard flag at index boundary) BoundaryGuardFlag` (read, GUESS)

### UIValidatedDispatchControl

UI control dispatch handlers: validate the current value via UIValueValidator, set handler state via sub_487260, handle radio/check changes, perform a secondary validation through vtable slot +0x98, and finalize via sub_486600. Includes state predicates over ShortComputation_6720 (accepting result 1 or 3; range [2,3]) and a pointer-based state toggle that reads a child through vtable slot +0xAC, sets/clears through +0x38, notifies through +0x2C, and uses flag +0xE4 to invert the toggle comparison.

Methods: `0x00487530`, `0x00487720`, `0x00487740`, `0x004879E0`, `0x00487D70`, `0x00487E10`

- `obj+0x0000002C` `vtable slot (+0x2C, notify with argument 1) NotifyVTableSlot` (read, DERIVED)
- `obj+0x00000038` `vtable slot (+0x38, set/clear with argument 0/1) SetClearVTableSlot` (read, DERIVED)
- `obj+0x00000098` `vtable slot (+0x98, secondary validation) SecondaryValidateVTableSlot` (read, DERIVED)
- `obj+0x000000AC` `vtable slot (+0xAC, value pointer accessor / toggle target) ValueAccessorVTableSlot` (read, DERIVED)
- `this+0x000000E4` `byte (inverts toggle comparison) ToggleInvertFlag` (read, GUESS)

### ScrollContainer

UI scroll container: stores a scroll offset at +0xE0, clamps it against position and extent obtained from vtable slots +0x18 and +0x20, and exposes a virtual accessor at slot +0xA8. A trivial setter writes +0xE0. Ownership DERIVED from existing analysis (scroll interpretation unproven by this packet alone).

Methods: `0x00488970`, `0x00488BC0`

- `this+0x000000E0` `int32 (scroll offset/delta) ScrollOffset` (read_write, GUESS)
- `obj+0x00000018` `vtable slot (+0x18, position accessor) PositionVTableSlot` (read, DERIVED)
- `obj+0x00000020` `vtable slot (+0x20, extent accessor) ExtentVTableSlot` (read, DERIVED)
- `obj+0x000000A8` `vtable slot (+0xA8, tail-call accessor) ResultAccessorVTableSlot` (read, DERIVED)

### ListLayoutIndexer

Converts a screen y-coordinate into a list item index from layout fields (vertical bounds +0x4/+0x8, total item count +0x94, column offset +0x134, horizontal offset +0x13C, scroll offset +0x14C, item height +0x158, visible count +0x164) using CRTFtol truncation and clamping. Field roles mostly DERIVED from existing analysis; the formula itself is directly evidenced.

Methods: `0x00489F40`

- `this+0x00000004` `int32 (vertical range start) VerticalStart` (read, DERIVED)
- `this+0x00000008` `int32 (vertical range end) VerticalEnd` (read, DERIVED)
- `this+0x00000094` `int32 (total item count) TotalItemCount` (read, GUESS)
- `this+0x00000134` `int32 (column offset) ColumnOffset` (read, GUESS)
- `this+0x0000013C` `int32 (horizontal offset) HorizontalOffset` (read, GUESS)
- `this+0x0000014C` `int32 (scroll offset) ScrollOffset` (read, DERIVED)
- `this+0x00000158` `int32 (item height) ItemHeight` (read, DERIVED)
- `this+0x00000164` `int32 (visible page count) VisiblePageCount` (read, GUESS)

### TextBoxEditWidget

UI text edit-box object: string buffer pointer at +0x2F0, cursor/position pointer at +0x2F4, buffer size +0x2F8 (set to 256), character limit +0x300 (16), length/counter +0x2E8, and byte flags at +0xE0..0xE5, +0x1E7 and +0x2EC; buffer-set notification dispatched through vtable slot +0xA8. Exact flag semantics inferred from the edit-box interpretation in existing analysis.

Methods: `0x0048B4F0`, `0x0048B7E0`

- `*(this+0x2F0)+0x00000000` `byte (first char of string buffer) BufferFirstByte` (write, DERIVED)
- `obj+0x000000A8` `vtable slot (+0xA8, buffer-set notification) BufferSetNotifyVTableSlot` (read, DERIVED)
- `this+0x000000E0` `byte (display/behavior flag) FlagE0` (write, GUESS)
- `this+0x000000E1` `byte (enabled flag) FlagE1` (write, GUESS)
- `this+0x000000E2` `byte (display/behavior flag) FlagE2` (write, GUESS)
- `this+0x000000E3` `byte (enabled flag) FlagE3` (write, GUESS)
- `this+0x000000E4` `byte (enabled flag) FlagE4` (write, GUESS)
- `this+0x000000E5` `byte (behavior flag) FlagE5` (write, GUESS)
- `this+0x000001E7` `byte (alternate buffer first byte / behavior flag) Flag1E7` (write, GUESS)
- `this+0x000002E8` `int32 (length/counter) TextLength` (write, GUESS)
- `this+0x000002EC` `byte (behavior flag) Flag2EC` (write, GUESS)
- `this+0x000002F0` `pointer (string buffer) BufferPtr` (read_write, DERIVED)
- `this+0x000002F4` `pointer (cursor/current position) CursorPtr` (write, GUESS)
- `this+0x000002F8` `int32 (buffer size, 256) BufferSize` (read_write, DERIVED)
- `this+0x00000300` `int32 (character limit, 16) CharLimit` (write, DERIVED)

### UIWidgetForwardWrapper

Thin UI widget wrappers: a forwarding shim that reads the DWORD at +0x0 and forwards to a widget-visibility toggle with reordered arguments, and an active/focus toggle that dispatches vtable slot +0xAC. The shim's target UIWidgetVisibilityToggle is not in the packet callee list, so its behavior is unproven.

Methods: `0x0048B910`, `0x0048BC70`

- `this+0x00000000` `dword (vtable or type id, passed to visibility toggle) TypeOrVTableDword` (read, GUESS)
- `obj+0x000000AC` `vtable slot (+0xAC, virtual dispatch) DispatchVTableSlot` (read, DERIVED)

## Compatibility contracts

- **ScalarDeletingDestructorABI** — Scalar-deleting destructors take a char flag; when bit 0 is set they must deallocate this (FreeWrapper_7bcf) and return this, otherwise memory is retained (embedded or member object). A replacement executable must reproduce this convention on every object that exposes one of these stubs.
- **SharedGlobal_8AB6EC_Protocol** — Global dword_8AB6EC is shared by collision-system helpers: Delegation (0x004B9CE0) must run before VehicleLifetimeAverageAccessor (0x004B9CB0) reads the lifetime average; RangeWidthGetter (0x004B9C80) receives the global's address via the thunk; and CollisionSystemInit (0x0047C960) is reached with a computed float argument. A replacement must preserve this sequence and the global's lifetime-average/range-width role.
- **VTableSlotOffsets_UIObjects** — UI dispatch controls rely on fixed vtable slot offsets: +0x98 secondary validation, +0xAC value pointer accessor/toggle target, +0x38 set/clear, +0x2C notify, +0x18 position and +0x20 extent on the scroll container, and +0xA8 buffer-set notification / result accessor. A replacement object graph must keep these slot offsets stable.
- **TextEditBufferLayout** — Text edit object layout: buffer pointer at +0x2F0, cursor pointer at +0x2F4, buffer size +0x2F8 (256), character limit +0x300 (16), length/counter +0x2E8, and byte flags at +0xE0..0xE5, +0x1E7, +0x2EC; buffer init stores pointer and size then notifies through vtable slot +0xA8.
- **ListLayoutIndexFormula** — Screen y-coordinate to list item index: index = trunc((a2 - this[0x13C] - this[0x134] - this[0x4]) / this[0x158]) + this[0x14C] via CRTFtol, clamped up to scroll offset and (when a3 set) down to visible-page and total-item-count bounds; returns -1 when item height <= 0 or a2 outside [this[0x4], this[0x8]].
- **InitFromDataBlockFormat** — 0x0047EE5C copies a 36-byte block from global unk_7D0A30, formats an integer using the '%d' format string at global 0x005C3280 through the buffer-overflow-checked formatter, and conditionally dispatches the formatted buffer via ConditionalCallWrapper (0x0047E940). A replacement must preserve this copy-format-dispatch sequence and the trigger semantics internal to ConditionalCallWrapper.

## Unresolved

- Object owners are mostly UNKNOWN (trust UNKNOWN in the packet); class groupings are pattern-based GUESS proposals and are not common-ownership proofs. In particular the eleven scalar-deleting destructors each install a distinct vtable constant and are grouped only by shared shape.
- The shared cleanup helper sub_485EB0 is invoked by many fragments, but whether it continues construction or performs teardown is unresolved; it is identified only by the raw-source name.
- The three vtable-reset fragments install distinct vtables (off_5AB968, off_5ABAC8, off_5ABC28); their relationship to the scalar-deleting destructors' base-class chain is unresolved.
- Field semantics for most offsets (dispatch flags, list fields at +0x168/+0x16C/+0x170, layout fields, edit-box flags) are DERIVED/GUESS from existing analysis and not runtime-proven.
- UIValueValidator, ConditionalCallWrapper and the widget-visibility toggle behavior are internal to their callees and not evidenced in this packet; the toggle target UIWidgetVisibilityToggle is not in the packet callee list.
- In 0x00487D70 the decompiler local used for change detection is uninitialized in the raw source, so the exact trigger condition for the state-set branch cannot be determined.
- The relationship between the extractor's node bases *(this+0xE4) / *(this+0xE8) and the traversal cursor in 0x00486600 / 0x00486630 is unproven.
- 0x0047EE5C has no recorded callers; the meaning of the 36-byte unk_7D0A30 data block and the parsed integer is unresolved.
- Base destructor sub_495300 (chained from 0x0047F3F0) and its contract are outside this packet.
- The float interpretation of constructor parameter 1065353216 (1.0) in 0x0047C910 comes from skeleton prose only.
- Whether the deliberate truncation of the double argument to float in 0x0047C940 is intentional precision loss or a decompiler artifact is unknown.
- The scroll/list-layout interpretation of the 0x00488970 / 0x00489F40 objects is DERIVED from existing analysis and unverified.
