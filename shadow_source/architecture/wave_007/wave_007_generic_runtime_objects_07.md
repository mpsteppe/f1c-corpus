# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `GUESS`

Reconstruction of generic runtime objects from 42 validated function IR records. The packet supplies UNKNOWN owners for every function and a small set of DERIVED prose labels (ListBoxNode, EditBox, TrackScene, UIElement, UIWidget, NetComm vtables). All class groupings below are GUESS worker proposals. The UI cluster groups functions that read the vtable pointer at this+0x0 and dispatch through vtable slots, but is split where two functions interpret the same this-relative offset differently: 0x004889D0 reads this+0xE0 as a numerator dword while 0x0048FC10 reads this+0xE0 as a referenced-object pointer (recorded as an explicit contradiction), and 0x0048FDB0 writes this+0x30 as a source bounding-box pointer while 0x0048FE30 reads this+0x30 as a sub-object pointer (also a contradiction). The destructor family is kept in three classes by shared cleanup delegate and free behavior: InitWithVTableCleanup users (0x00485540/0x00485570/0x00485690/0x004856C0), sub_485EB0 users with conditional free (0x004858E0/0x00488FB0/0x0048D3F0), and reset-vtable-then-delegate members without free (0x004876B0/0x0048B4E0), plus vtable-install init forwarders (0x00489440/0x0048C9B0/0x0048C9D0), the scalar-deleting destructor 0x0047F3D0 and the lifecycle wrapper 0x0048D680. The two integer setters 0x0048C9E0 and 0x0048CA26 share the write to this+0x4 and are grouped; the trivial byte/dword setters 0x004888F0/0x00488BD0 and the trivial getters 0x00486829/0x00489AA9 are grouped as setter/getter families with the per-method offsets left explicit. State machinery is proposed for the two ShortComputation_6720-driven dispatch functions (0x004875F0, 0x0048DFF0).

## Function roles

- `0x0047EF3C` **UIValueFormatter** — Formats the global UI percentage slider value flt_7D084C (0.0-1.0) as an integer-percentage string via StringFormatWithBufferOverflowCheck (0x0058815F) with the '%0.0f%%' literal at 0x005C74E0 and value*100.0, dispatches the string through ConditionalCallWrapper (0x0047E940), always returns 0.
- `0x0047F180` **DoublyLinkedList** — Append to a doubly linked list whose header fields are head this[0], tail this[1], extra reference this[2] and count this[3]/+0x0C: when payload a2 is non-null it allocates a 16-byte node via OperatorNewNhMallocWrapper (0x00587C03), stores the payload at node+0 and the byte flag a3 at node+12, links the node onto the tail (or into this[0]/this[2] on the empty-list path), updates the tail and increments the count, and returns 1; returns 0 without modifying the list when a2 is null. Structural twin of DoublyLinkedListAppend.
- `0x0047F210` **UIWidget** — Flag-gated virtual dispatch: reads the byte flag at this+0xC; when non-zero and the vtable pointer at this+0x0 is valid, dispatches virtual function 0 (*(obj+0x0)) with the object pointer and integer 1 and returns its result; otherwise returns the flag value without dispatch.
- `0x0047F3D0` **ScalarDeleteDtorObject** — Scalar deleting-destructor (__thiscall): calls Destructor (0x0047F3F0) on this to run object teardown, then frees the object via FreeWrapper_7bcf (0x00587BCF) only when the a2 flag bit 0 is set; returns this. Matches the MSVC deleting-destructor convention.
- `0x00485540` **SharedCleanupDtorObject** — Destructor-shaped routine: installs the vtable pointer off_5AB3F0 at this+0x0, runs the shared cleanup via InitWithVTableCleanup (0x00487250), and conditionally frees via FreeWrapper_7bcf (0x00587BCF) when the a2 flag has bit 1 set; returns this. The destructor interpretation is DERIVED from existing analysis only.
- `0x00485570` **SharedCleanupDtorObject** — Scalar deleting-destructor: writes the vtable pointer off_5AB340 into this+0x0, calls InitWithVTableCleanup (0x00487250) with this as receiver to run the common destructor/cleanup path, then frees via FreeWrapper_7bcf (0x00587BCF) when the deleting flag a2 has bit 0 set; returns this.
- `0x00485690` **SharedCleanupDtorObject** — Scalar deleting-destructor: writes the vtable pointer off_5A9870 into this+0x0, calls InitWithVTableCleanup (0x00487250) with this as receiver, then frees via FreeWrapper_7bcf (0x00587BCF) when the deleting flag a2 has bit 0 set; returns this.
- `0x004856C0` **SharedCleanupDtorObject** — Scalar deleting-destructor: writes the vtable pointer off_5A9710 into this+0x0, calls InitWithVTableCleanup (0x00487250) with this as receiver, then frees via FreeWrapper_7bcf (0x00587BCF) when the deleting flag a2 has bit 0 set; returns this.
- `0x004858E0` **VTableRestoringDtorObject** — Scalar-deleting-destructor pattern: calls sub_485EB0 (0x00485EB0) unconditionally on this as the destructor body, then frees via FreeWrapper_7bcf (0x00587BCF) when the a2 flag has bit 0 set; returns this.
- `0x00485A90` **DualBufferResourceObject** — Destructor for an object holding two buffer pointers (this+0x184 and this+0x17C): frees each buffer via FreeWrapper_7bcf when non-null, chains to DestructorWithFree (0x00468610) for base-class sub-resource cleanup, then conditionally frees the object itself based on the a2 flag; returns this.
- `0x00486300` **UIStringAccessor** — String accessor (__thiscall): loads the sub-object pointer at this+0xC8 and returns 0 when it is null; otherwise reads the string pointer at sub-object+0x50, falling back to the global byte_5EA438 path when that pointer is null. ABI lead names it UI_String_Accessor_486300.
- `0x00486829` **UIFieldAccessor** — Trivial __thiscall getter: returns the dword field at this+0x84 with no side effects; no guards, calls or global access.
- `0x00486E70` **UIWidget** — UI control hit test (__thiscall): gated on the byte enable flag at this+0x65 (this[101]); when set, retrieves the control's bounding rectangle via the indirect bounds method at vtable+8 (obj+0x8 dispatched through the vtable pointer at this+0x0) and returns 1 when point (a2, a3) lies inside that rectangle, else 0.
- `0x00486ED0` **FreeFunction** — Unconditionally writes the DWORD value 0xFFFFFF (white RGB) to each of the four output locations given by pointers a1, a2, a3, a4, then returns a4; a leaf utility for initializing four UI color values.
- `0x004871F0` **FreeFunction** — Thin thiscall wrapper: forwards the object pointer to sub_487060 (0x00487060) with a constant second argument of 1 and returns its result unchanged; no fields, globals or guards are touched.
- `0x004875F0` **UIStateDispatchWidget** — State-dependent vtable dispatch with unconditional flag clear: computes the state via ShortComputation_6720 (0x00486720), subtracts 2, and dispatches through the vtable slot at obj+0x40 (state 2 -> thiscall (this, 0); state 3 -> stdcall (1)); every path clears the flag at this+0xDC to 0 and returns 0.
- `0x00487640` **UIWidget** — Radio/check-button state handler then virtual dispatch: calls UIRadioCheckStateChangeHandler (0x00487460) on this, then invokes the virtual method at vtable offset 168 (0xA8, field obj+0xA8) through the object's vtable pointer and returns 0.
- `0x004876B0` **ResetVtableThenDelegateObject** — Resets the object's vtable pointer at this+0x0 to &off_5ABA18 (ListBoxNode vtable per existing analysis), then delegates to sub_485EB0 (0x00485EB0) and returns its result; invoked by DestructorWithSubCallConditionalFree (0x00487690) for delegated teardown.
- `0x00487D50` **UIWidget** — Structural twin of VTableDispatch_7640: calls UIControlStateChangeHandler (0x00487960) on this, then invokes the virtual method at vtable offset 168 (0xA8, field obj+0xA8) through the object's vtable pointer and returns 0.
- `0x004888F0` **UIFieldSetter** — Stores the byte parameter a2 into the object field at offset 0xEC (this[236]) and returns a2; a trivial byte/flag setter with no conditional logic, guards, globals or calls.
- `0x004889D0` **UIRatioProgressWidget** — Computes a normalized ratio: invokes the virtual methods at vtable offsets +32 (obj+0x20) and +24 (obj+0x18) on this, forms the range v3 = v2 - v1 as a double, returns 0.0 when the range is non-positive, otherwise returns (double)this[56] / v3 using the dword at this+0xE0 as the numerator; interpreted as a normalized position or progress fraction.
- `0x00488BD0` **UIFieldSetter** — Unconditional setter: stores parameter a2 into this+0xE4 (this[57]) and returns a2; no guards, callees or globals. Consistent with the LEGACY Field_Setter ABI label and the existing 'SecondaryOffsetWriter' analysis.
- `0x00488FB0` **VTableRestoringDtorObject** — Object destructor: swaps the vtable pointer at this+0 to off_5ABCD0 (TrackSceneVTable per existing analysis), calls sub_485EB0 (0x00485EB0) on this for base/cleanup work, and when a2 bit 0 is set frees the object memory via FreeWrapper_7bcf (0x00587BCF); returns this. When bit 0 is clear the object is not deallocated (placement-destructor path).
- `0x00489440` **VTableInitObject** — Vtable-assign + base-init forwarder (__thiscall): writes the vtable pointer off_5ABD78 into field this+0x0, then forwards to sub_485EB0 (0x00485EB0) and returns its result; a constructor fragment that installs the virtual table before base initialization. Its callers include destructor and lifecycle paths (0x004698C0, 0x0047BE90, 0x0047FBA0, 0x00485AE0, 0x00485B20), leaving the constructor/destructor role ambiguous.
- `0x00489AA9` **UIFieldAccessor** — Pure getter: returns the DWORD field this+0x168 (this[90]) with no side effects; raw source corroborates the DERIVED template prelabel 'getter: returns field 0x168, no side effects'.
- `0x0048AA00` **FreeFunction** — Passthrough wrapper: forwards this and arguments a2, a3, a4, a5 to F_2DSurfaceBlitWithViewportClipping (0x0048A240) and always returns 0, discarding the callee result; consistent with the LEGACY Passthrough_Wrapper_Returns_0 ABI label.
- `0x0048B4E0` **ResetVtableThenDelegateObject** — Sets the object's vtable pointer at this+0x0 to &off_5ABED0 (EditBox vtable per existing analysis), then delegates to sub_485EB0 (0x00485EB0) and returns its result; invoked by ConditionalDestructor_0250 (0x00470250).
- `0x0048C9B0` **VTableInitObject** — Lifecycle wrapper for an unknown object: unconditionally calls ShortComputation_c9d0 (0x0048C9D0) as its first stage (the decompiled source shows no receiver argument, so whether it operates on this is not evidenced), then frees via FreeWrapper_7bcf (0x00587BCF) when the a2 flag has bit 0 set; returns this.
- `0x0048C9D0` **VTableInitObject** — Minimal single-assignment initializer: writes the pointer value &off_5AC044 (0x005AC044) to this+0x0, plausibly the object's vtable (UIElementVTable per the skeleton fill, DERIVED prose); invoked by ShortComputation_c9b0 (0x0048C9B0) as its unconditional first stage; void.
- `0x0048C9E0` **NodePayloadSetter** — Trivial __thiscall integer field setter: writes argument a2 into the dword at this+0x4 and returns a2; structural twin of IntegerSetter (00406b30) via cluster_copy; called once by LinkedListNodeAppend (0x0048D2B0).
- `0x0048CA26` **NodePayloadSetter** — Trivial __thiscall integer field setter: writes argument a2 into the dword at this+0x4 and returns a2; structural twin of IntegerSetter (00406b30) via cluster_copy; no callers are present in the packet.
- `0x0048D1A0` **UISelectionList** — List-index stepper: computes the max valid index as count-1 (this+0x328), steps the target index at this+0x338 by +1 when a2==1 (forward) or -1 otherwise (backward), writes the direction flag byte (a2==1) to this+0x33C, wraps the index into [0, count-1] (negative wraps to last, overflow wraps to 0), then invokes the vtable+0x2C update callback with 1 and the vtable+0xBC action dispatch with (direction, new index); returns the dispatch result.
- `0x0048D380` **UISelectionList** — Bounds-checked setter on a container object: returns a2 unchanged; only if 0 <= a2 < item-count (this+0x328) is the selected index at this+0x338 overwritten with a2; the owning object class is unidentified.
- `0x0048D3F0` **VTableRestoringDtorObject** — Destructor restoring the vtable pointer field this+0x0 to off_5AC1D0 (UIWidget vtable per prior analysis), runs shared teardown via sub_485EB0 (0x00485EB0), then conditionally frees the object via FreeWrapper_7bcf (0x00587BCF) when bit 0 of the a2 flag is set; returns this.
- `0x0048D680` **LifecycleTeardownObject** — Short __thiscall lifecycle function: forwards the object to ShortComputation_d6a0 (0x0048D6A0) as its teardown body, then releases the object storage via FreeWrapper_7bcf (0x00587BCF) when the flag byte a2 bit 1 is set; returns this. The flag-gated deallocation matches the scalar-deleting-destructor pattern.
- `0x0048DFF0` **UIStateDispatchWidget** — State machine with virtual dispatch: computes the state via ShortComputation_6720 (0x00486720) and switches on it through the jump table jpt_48DFFE at 0x0048E050; states 1/2/4/5 call the vtable slot at obj+0x40 with arguments 6/7/8/9 (interpreted by DERIVED analysis as scroll up/down/left/right) then the slot at obj+0x9C (refresh); the default path calls only obj+0x9C; always returns 0.
- `0x0048E6A0` **FreeFunction** — Thin __thiscall wrapper: forwards this to LinkedListNodeInsert_66e0 (0x004966E0), ignores its result, and returns 0; called by FunctionCallWrapper_6160 (0x00466160).
- `0x0048EA40` **QuadFieldWriter** — Unconditional thiscall setter storing four arguments into consecutive dword fields of `this` at offsets 0x1C, 0x20, 0x24, 0x28 with argument reordering (a4->0x1C, a5->0x20, a2->0x24, a3->0x28); returns the second argument (a2); no branches, calls or global access.
- `0x0048F330` **UIWidget** — Resets a byte flag at this+0x17F to 0, sets a sentinel dword at this+0x170 to -1, then dispatches through the object's vtable entry at vtable+0x2C (field obj+0x2C, pointer read from this+0x0) with argument 1, returning 0; no branches, unconditional field writes and one indirect call.
- `0x0048FC10` **UICacheSyncWidget** — Cache-sync with final dispatch: reads the referenced-object pointer at this+0xE0; when non-null, compares the external value (packet field fact places the read at field this+0x254, while the raw source dereferences *(this[56] + 372), a discrepancy flagged in unresolved) against the cached value at this+0xE4; on a difference it updates the cache and fires the vtable+0x2C change-notification callback with 1; unconditionally fires the vtable+0xA8 final-dispatch callback with no arguments; returns 0.
- `0x0048FDB0` **ViewportRectObject** — Viewport rectangle size calculation (__thiscall): when the source bounding box a2 is non-null, stores its pointer into this+0x30, then computes one axis extent from a2[4] - a2[3] into this+0xC (clamped to zero) and the other axis extent from a2[2] - a2[1] into this+0x10 (also clamped to zero); returns the second axis extent (or null when a2 is null or that axis is non-positive). Static caller is ObjectNameComparison (0x00477280).
- `0x0048FE30` **ConditionalVirtualDispatchObject** — Conditional virtual double-dispatch on the sub-object at this+0x30: when the sub-object pointer is non-null, invokes its vtable method at offset 0x3C (slot 15) with argument a2, coerces the low byte of that result to the boolean (a2 == 0), then invokes the vtable method at offset 0x38 (slot 14) on the same sub-object with the coerced value and returns its result; the null path returns an uninitialized value.

## Proposed classes

### UIValueFormatter

UI value formatter driven by the global percentage slider flt_7D084C (0.0-1.0): formats the value scaled by 100.0 through StringFormatWithBufferOverflowCheck with the '%0.0f%%' literal at 0x005C74E0 and dispatches the string via ConditionalCallWrapper; always returns 0. No owned this fields.

Methods: `0x0047EF3C`


### DoublyLinkedList

Doubly linked list whose header fields sit at this+0x0 (head), this+0x4 (tail), this+0x8 (extra reference also set on the empty-list path) and this+0xC (element count). Append (0x0047F180) allocates a 16-byte node (payload at node+0, byte flag at node+12) via OperatorNewNhMallocWrapper, links the node onto the tail or into the empty-list slots, and returns 1 on success, 0 for null input.

Methods: `0x0047F180`

- `this+0x00000000` `pointer list_head` (read_write, GUESS)
- `this+0x00000004` `pointer list_tail` (read_write, GUESS)
- `this+0x00000008` `pointer extra_reference` (read_write, GUESS)
- `this+0x0000000C` `int element_count` (read_write, GUESS)

### UIWidget

Generic UI control widget family (GUESS grouping): reads its vtable pointer at this+0x0 and dispatches methods through vtable slots (obj+0x0 virtual function 0, obj+0x8 bounds query, obj+0x2C update/notification callback, obj+0xA8 final-dispatch slot). Member functions cover flag-gated virtual dispatch (0x0047F210, gate flag this+0xC), control hit testing (0x00486E70, enable flag this+0x65), radio/check and control-state change handlers with a follow-up vtable+0xA8 dispatch (0x00487640, 0x00487D50), and a field-reset-then-dispatch helper (0x0048F330, sentinel this+0x170, flag this+0x17F). The grouping is a worker proposal: the packet labels every owner UNKNOWN and the functions are linked only by the shared vtable-at-0 + dispatch convention.

Methods: `0x0047F210`, `0x00486E70`, `0x00487640`, `0x00487D50`, `0x0048F330`

- `this+0x00000000` `pointer vtable_ptr` (read, GUESS)
- `obj+0x00000000` `pointer virtual_fn_0` (read, GUESS)
- `obj+0x00000008` `pointer bounds_query_method` (read, GUESS)
- `obj+0x0000002C` `pointer update_notify_callback` (read, GUESS)
- `obj+0x000000A8` `pointer final_dispatch_slot` (read, GUESS)
- `this+0x0000000C` `byte dispatch_gate_flag` (read, GUESS)
- `this+0x00000065` `byte hit_test_enable` (read, GUESS)
- `this+0x00000170` `dword selection_sentinel` (write, GUESS)
- `this+0x0000017F` `byte state_byte_flag` (write, GUESS)

### UIStateDispatchWidget

Widget whose action selection comes from ShortComputation_6720 (0x00486720) and which dispatches through the vtable slots at obj+0x40 (command setter) and obj+0x9C (refresh/repaint). 0x004875F0 dispatches slot obj+0x40 with arguments 0/1 for states 2/3 and clears the flag at this+0xDC on every path; 0x0048DFF0 switches on states 1/2/4/5 calling obj+0x40 with 6/7/8/9 and obj+0x9C via the jump table at 0x0048E050. The scroll-direction reading is DERIVED prose.

Methods: `0x004875F0`, `0x0048DFF0`

- `this+0x00000000` `pointer vtable_ptr` (read, GUESS)
- `obj+0x00000040` `pointer command_setter_slot` (read, GUESS)
- `obj+0x0000009C` `pointer refresh_slot` (read, GUESS)
- `this+0x000000DC` `dword state_flag` (write, GUESS)

### UIRatioProgressWidget

Widget computing a normalized progress/position fraction: reads two bounds through virtual methods at vtable offsets +24 (obj+0x18) and +32 (obj+0x20), forms the range as a double, returns 0.0 for a non-positive range, otherwise divides the dword at this+0xE0 by the range. Kept separate from UICacheSyncWidget because that function interprets the same offset this+0xE0 as a referenced-object pointer; the overlap is recorded as an explicit contradiction.

Methods: `0x004889D0`

- `this+0x00000000` `pointer vtable_ptr` (read, GUESS)
- `obj+0x00000018` `pointer lower_bound_method` (read, GUESS)
- `obj+0x00000020` `pointer upper_bound_method` (read, GUESS)
- `this+0x000000E0` `dword numerator_dword` (read, GUESS)

### UICacheSyncWidget

Widget holding a cached value at this+0xE4 mirrored from an external value reached through the referenced object at this+0xE0; on a difference it updates the cache and fires the vtable+0x2C change-notification with 1, then unconditionally fires the vtable+0xA8 final dispatch. The external field offset is disputed (packet field fact this+0x254 vs raw source *(this[56]+372) = +0x174 into the referenced object); kept separate from UIRatioProgressWidget because the this+0xE0 interpretation differs.

Methods: `0x0048FC10`

- `this+0x00000000` `pointer vtable_ptr` (read, GUESS)
- `this+0x000000E0` `pointer referenced_object` (read, GUESS)
- `this+0x000000E4` `dword cached_value` (read_write, GUESS)
- `obj+0x0000002C` `pointer change_notify_callback` (read, GUESS)
- `obj+0x000000A8` `pointer final_dispatch_slot` (read, GUESS)

### UISelectionList

Selection list widget holding an item count at this+0x328 and a selected index at this+0x338, with a direction flag byte at this+0x33C. ListIndexStep (0x0048D1A0) steps and wraps the index and fires the vtable+0x2C update callback and the vtable+0xBC action dispatch; BoundsCheckedIndexSetter (0x0048D380) writes the index only when 0 <= a2 < count.

Methods: `0x0048D1A0`, `0x0048D380`

- `this+0x00000000` `pointer vtable_ptr` (read, GUESS)
- `obj+0x0000002C` `pointer update_callback` (read, GUESS)
- `obj+0x000000BC` `pointer action_dispatch_slot` (read, GUESS)
- `this+0x00000328` `int item_count` (read, GUESS)
- `this+0x00000338` `int selected_index` (read_write, GUESS)
- `this+0x0000033C` `byte direction_flag` (write, GUESS)

### UIStringAccessor

String accessor on an unknown UI widget: reads the sub-object pointer at this+0xC8 and returns its string at sub-object+0x50, falling back to the global byte_5EA438 path when that string pointer is null, or 0 when the sub-object is null.

Methods: `0x00486300`

- `this+0x000000C8` `pointer sub_object` (read, GUESS)

### UIFieldAccessor

Trivial dword getters on unknown objects (GUESS merge of two offsets): returns this+0x84 (0x00486829) and this+0x168 (0x00489AA9) with no side effects. Merged as one class because both are pure single-field reads; the two offsets belong to different objects and must not be assumed to share a base type until owners are proven.

Methods: `0x00486829`, `0x00489AA9`

- `this+0x00000084` `dword dword_field_84` (read, GUESS)
- `this+0x00000168` `dword dword_field_168` (read, GUESS)

### UIFieldSetter

Trivial setters on unknown UI objects (GUESS merge of two offsets): stores a byte into this+0xEC (0x004888F0) and a dword into this+0xE4 (0x00488BD0), each returning the stored argument.

Methods: `0x004888F0`, `0x00488BD0`

- `this+0x000000E4` `dword config_dword` (write, GUESS)
- `this+0x000000EC` `byte byte_flag` (write, GUESS)

### NodePayloadSetter

Integer field setter writing a2 into this+0x4; called from LinkedListNodeAppend (0x0048D2B0), suggesting the field is a list-node payload slot. Two structural twins (0x0048C9E0, 0x0048CA26) both write this+0x4.

Methods: `0x0048C9E0`, `0x0048CA26`

- `this+0x00000004` `dword payload_int` (write, GUESS)

### QuadFieldWriter

Unconditional thiscall setter storing four arguments into consecutive dword fields at this+0x1C/0x20/0x24/0x28 with argument reordering (a4->0x1C, a5->0x20, a2->0x24, a3->0x28), returning a2. The owning class and the meaning of the reordering are unknown.

Methods: `0x0048EA40`

- `this+0x0000001C` `dword field_a` (write, GUESS)
- `this+0x00000020` `dword field_b` (write, GUESS)
- `this+0x00000024` `dword field_c` (write, GUESS)
- `this+0x00000028` `dword field_d` (write, GUESS)

### FreeFunction

Stateless helpers with no owned this fields: SetFourColorsToWhite (0x00486ED0) writes 0xFFFFFF to four output pointers, WrapperToSub487060 (0x004871F0) forwards this with constant 1 to sub_487060, Blit2DSurfacePassthrough (0x0048AA00) forwards to F_2DSurfaceBlitWithViewportClipping and returns 0, and WrapperReturn0 (0x0048E6A0) forwards this to LinkedListNodeInsert_66e0 and returns 0.

Methods: `0x00486ED0`, `0x004871F0`, `0x0048AA00`, `0x0048E6A0`


### SharedCleanupDtorObject

Objects destroyed through the shared cleanup dispatcher InitWithVTableCleanup (0x00487250): each destructor installs its class vtable at this+0x0 (off_5AB3F0, off_5AB340, off_5A9870, off_5A9710), runs the shared cleanup, and frees via FreeWrapper_7bcf when the deleting flag bit is set. The four distinct vtables imply four distinct concrete classes sharing a common teardown path at 0x00487250; grouped here as a family (rule 9) with the concrete identities left unresolved.

Methods: `0x00485540`, `0x00485570`, `0x00485690`, `0x004856C0`

- `this+0x00000000` `pointer vtable_ptr` (write, GUESS)

### VTableRestoringDtorObject

Scalar-deleting destructors that run the shared teardown sub_485EB0 (0x00485EB0) on this and conditionally free via FreeWrapper_7bcf when a2 bit 0 is set: 0x004858E0 (no vtable write evidenced), 0x00488FB0 (restores off_5ABCD0, TrackScene per DERIVED prose), 0x0048D3F0 (restores off_5AC1D0, UIWidget per prior analysis). Concrete classes are unknown.

Methods: `0x004858E0`, `0x00488FB0`, `0x0048D3F0`

- `this+0x00000000` `pointer vtable_ptr` (write, GUESS)

### ResetVtableThenDelegateObject

Objects whose teardown resets the vtable at this+0x0 (off_5ABA18 for 0x004876B0, off_5ABED0 for 0x0048B4E0) and then delegates to sub_485EB0 (0x00485EB0), returning its result; invoked by the destructor wrappers 0x00487690 and 0x00470250. The ListBoxNode/EditBox attributions are DERIVED prose.

Methods: `0x004876B0`, `0x0048B4E0`

- `this+0x00000000` `pointer vtable_ptr` (write, GUESS)

### VTableInitObject

Vtable-install + init forwarders: 0x00489440 writes off_5ABD78 into this+0x0 then forwards to sub_485EB0; 0x0048C9B0 calls 0x0048C9D0 then conditionally frees via FreeWrapper_7bcf; 0x0048C9D0 writes off_5AC044 into this+0x0 (void). Grouped on the shared vtable-install-then-forward pattern plus the caller edge 0x0048C9B0 -> 0x0048C9D0; the NetComm/UIElement labels are DERIVED prose.

Methods: `0x00489440`, `0x0048C9B0`, `0x0048C9D0`

- `this+0x00000000` `pointer vtable_ptr` (write, GUESS)

### ScalarDeleteDtorObject

Object destroyed by a scalar deleting-destructor (0x0047F3D0) that runs Destructor (0x0047F3F0) and frees via FreeWrapper_7bcf only when the deleting flag bit 0 is set; returns this. No this fields are evidenced in the destructor itself.

Methods: `0x0047F3D0`


### LifecycleTeardownObject

Object whose lifecycle wrapper (0x0048D680) forwards to the teardown body ShortComputation_d6a0 (0x0048D6A0) and then releases storage via FreeWrapper_7bcf when the flag byte a2 bit 1 is set, returning this.

Methods: `0x0048D680`


### DualBufferResourceObject

Object holding two buffer pointers at this+0x184 and this+0x17C; its destructor (0x00485A90) frees each buffer when non-null, chains to DestructorWithFree (0x00468610) for base-class cleanup, and conditionally frees the object itself based on the a2 flag.

Methods: `0x00485A90`

- `this+0x0000017C` `pointer buffer_a` (read, GUESS)
- `this+0x00000184` `pointer buffer_b` (read, GUESS)

### ViewportRectObject

Layout/viewport object whose size computation (0x0048FDB0) stores the source bounding-box pointer into this+0x30 and the two axis extents into this+0xC and this+0x10 (clamped to non-negative). Kept separate from ConditionalVirtualDispatchObject because that function reads this+0x30 as a sub-object pointer; the offset overlap is recorded as an explicit contradiction.

Methods: `0x0048FDB0`

- `this+0x0000000C` `dword extent_axis_a` (write, GUESS)
- `this+0x00000010` `dword extent_axis_b` (write, GUESS)
- `this+0x00000030` `pointer source_bbox_ptr` (write, GUESS)

### ConditionalVirtualDispatchObject

Object dispatching a conditional double virtual call on the sub-object at this+0x30: slot 15 (obj+0x3C) receives argument a2, its result low byte is coerced to the boolean (a2==0), then slot 14 (obj+0x38) receives the coerced value; the null sub-object path returns an uninitialized value.

Methods: `0x0048FE30`

- `this+0x00000030` `pointer sub_object` (read, GUESS)
- `*(this+0x30)+0x00000038` `pointer slot14_method` (read, GUESS)
- `*(this+0x30)+0x0000003C` `pointer slot15_method` (read, GUESS)

## Compatibility contracts

- **DoublyLinkedListAppendContract** — The append must allocate a 16-byte node when the payload argument is non-null, store the payload at node+0 and the byte flag at node+12, link the node onto the tail (or into the empty-list head/extra slots this+0x0/this+0x8), update the tail this+0x4 and increment the count this+0xC, and return 1; it must return 0 without modifying the list when the payload is null.
- **ScalarDeletingDestructorContract** — Deleting destructors must run the shared teardown (Destructor 0x0047F3F0, InitWithVTableCleanup 0x00487250, or sub_485EB0 0x00485EB0 depending on the class) and free the object memory via FreeWrapper_7bcf (0x00587BCF) only when the a2 deleting flag bit 0 is set, returning this on every path; bit 0 clear selects the placement-delete path that keeps the storage.
- **PercentageDisplayContract** — The formatter must convert the global percentage slider flt_7D084C (0.0-1.0) to an integer percentage (value*100.0) using the '%0.0f%%' literal at 0x005C74E0 through StringFormatWithBufferOverflowCheck (0x0058815F), dispatch the formatted string through ConditionalCallWrapper (0x0047E940), and return 0.
- **UIListIndexStepContract** — The selection list must step the index at this+0x338 by +1 when the direction argument equals 1 (forward) or -1 otherwise, write the direction flag byte (a2==1) to this+0x33C, wrap the index into [0, count-1] using the count at this+0x328, fire the vtable+0x2C update callback with argument 1 and the vtable+0xBC action dispatch with (direction, new index), and return the dispatch result.
- **VtableRestoreTeardownContract** — Vtable-restoring teardown must overwrite this+0x0 with the class vtable pointer (off_5AB3F0/off_5AB340/off_5A9870/off_5A9710/off_5ABCD0/off_5AC1D0 per member) before running the shared cleanup (InitWithVTableCleanup 0x00487250 or sub_485EB0 0x00485EB0) and the conditional free, so the object resumes its class vtable during destruction.
- **UIStringAccessorContract** — The string accessor must return the sub-object's string (sub-object pointer at this+0xC8, string pointer at sub-object+0x50), fall back to the global byte_5EA438 path when that string pointer is null, and return 0 when the sub-object pointer is null.
- **ViewportRectSizeContract** — The viewport size computation must store the source bounding-box pointer into this+0x30 and compute two clamped axis extents (a2[4]-a2[3] into this+0xC, a2[2]-a2[1] into this+0x10, each stored as 0 when the difference is non-positive, otherwise difference+1), returning the second axis extent or null when a2 is null or that axis is non-positive.

## Unresolved

- General: every owner in the packet is UNKNOWN, so all class groupings here are GUESS worker proposals; equal offsets on different this bases or across different classes are never merged without packet proof of common ownership (rule 8); the vtable attributions (ListBoxNode off_5ABA18, EditBox off_5ABED0, TrackScene off_5ABCD0, UIElement off_5AC044, UIWidget off_5AC1D0, NetComm off_5ABD78) are DERIVED prose, not packet evidence.
- CONTRADICTION: UIRatioProgressWidget (0x004889D0) reads this+0xE0 as a numerator dword while UICacheSyncWidget (0x0048FC10) reads this+0xE0 as a referenced-object pointer and this+0xE4 as a cached value; the two functions are kept as separate classes.
- CONTRADICTION: ViewportRectObject (0x0048FDB0) writes this+0x30 as a source bounding-box pointer while ConditionalVirtualDispatchObject (0x0048FE30) reads this+0x30 as a sub-object pointer; the two functions are kept as separate classes.
- 0x004875F0: the same vtable slot (byte offset 64, obj+0x40) is invoked with two different calling conventions and argument shapes (thiscall (this, 0) for state 2 vs stdcall (1) for state 3); this is either a decompiler artifact or a genuine dual-prototype usage that cannot be resolved statically from this packet.
- 0x0048FC10: the external value placement is disputed - the packet field fact lists the read at field this+0x254 while the raw source dereferences *(this[56] + 372), which is +0x174 into the referenced object; the external field location is unresolved.
- 0x0048DFF0: the jump table jpt_48DFFE at 0x0048E050 is not modeled; the mapping of states 1/2/4/5 to scroll directions and of arguments 6-9 to commands is DERIVED prose, not independently proven.
- The identities of FreeWrapper_7bcf (0x00587BCF) and OperatorNewNhMallocWrapper (0x00587C03) as heap free/allocate wrappers are DERIVED from the call patterns, not proven by the packet.
- 0x0047F180: the semantics of the extra this[2] field (set to the node on the empty-list path) and of the node byte flag a3 stored at node+12 are unknown.
- 0x00486300: field this+0x118 appears in the packet field list but is not referenced by the raw decompiled source; its role in this function is unknown.
- 0x004889D0: global 0x0059E440 is listed in the packet but the raw source compares the range against the immediate 0.0 and never reads that global; its role in this function is unknown.
- 0x0047EF3C: global flt_59E6F8 appears in the packet's global list but is not referenced by the raw source of this function; existing analysis notes it is referenced elsewhere in the same compilation unit.
- 0x0048C9B0: whether ShortComputation_c9d0 (0x0048C9D0) operates on this (e.g. setting this's vtable) or on a separate object is not evidenced, because the call in the decompiled source carries no receiver argument.
- 0x0048D380: no caller context explains why the original argument is returned rather than the stored value.
- 0x0048EA40: the argument-reordering rationale and the semantics of the four fields (offsets 0x1C/0x20/0x24/0x28) are unknown; no caller or constructor evidence is available.
- 0x0048AA00: why the wrapper returns constant 0 instead of the callee result is not established by the packet.
- 0x0048FE30: the null path returns an uninitialized value; the semantics of vtable slots 14 and 15 and of argument a2 are unknown.
- 0x00485A90: the meaning of the two buffer pointers at this+0x17C/this+0x184 and the owning class are unknown; only their conditional-free lifecycle is evidenced.
- 0x0047F210: the meaning of the integer argument 1 passed to the virtual call and the semantics of the byte flag at this+0xC are unknown.
- 0x00489440: whether this fragment is a pure constructor step or is also exercised on destructor paths (its callers include destructors) is ambiguous without the callers' own source.
