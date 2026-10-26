# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Reconstruction of the generic_runtime_objects scope: 42 validated functions that act as unowned runtime helpers. Behavior and control flow are well evidenced (confidence HIGH for most functions); ownership and field semantics are not (all packet owners are UnknownObject). The dominant structural families are: (1) vtable-managed lifecycle routines that install or re-install a vtable at object+0 and, in destructors, gate a FreeWrapper_7bcf release on the low bit of a deleting flag; (2) singly-linked-list operations sharing a node layout of payload-at+0 and next-at+4, including a recursive merge sort whose comparator reads a 104-entry priority table; (3) a 560-byte-stride slot array with an activation byte and an active-slot counter at +0xE40C; (4) accessors that return a string-pointer field and fall back to the global empty string; (5) stubs that expose a code or data address as an integer. Class groupings below are GUESS proposals on structural similarity; distinct vtable addresses suggest distinct concrete classes that the packet does not name.

## Function roles

- `0x00464F50` **SlotArrayContainer** — Cap-gated division helper: computes min(cap, dividend / max(1, divisor_candidate - 1)); dividend comes from delegate 0x00464EE0, divisor candidate and cap are read from the slot-array region. Invoked from the EntityVisibilityGridManager visibility-grid update path.
- `0x00465150` **UnknownObject** — Tail-call forwarding wrapper: reads the pointer at this+0x0, forwards it together with a2 to the single delegated routine (sub_464D30 in raw source), and returns that routine's value. Called by SessionTypeSetter.
- `0x004652D0` **SlotArrayContainer** — Per-slot activation: computes the activation-byte address as array_base + 560*a2 + 248 (array_base = dword at obj+0), marks the slot active, increments the active-slot count at array_base + 0xE40C; returns the slot pointer when already active, else the container array base. Called by TeamRadioNetworkMessageProcessing.
- `0x00465430` **SlotArrayContainer** — Slot-indexed float store: computes a storage index as 560*a1 + v3 + 140, converts argument a2 via BufferSizeLookup, and stores the value through FloatStoreWithConversion, returning the store result. Called from NetCommPlayerSlotSync (per-player-slot network sync, inferred from ABI lead name).
- `0x00465C30` **SinglyLinkedContainer** — Linked-list front pop: writes the head node's payload (node+0) to the caller out-parameter *a2 and advances the head at *this+0xE5C8 to the node's next pointer (node+4); returns 1 on success, 0 when the list is empty or the head payload is zero. Called by InputCommandDispatchToEntities.
- `0x00465D70` **SinglyLinkedContainer** — Recursive merge sort of a singly-linked list (next pointer at node+4), split at midpoint and merged with a deterministic comparator over a 104-entry priority table at dword_7CD2AC+58384 (top two bits, masked sub-field, low byte with 255 sentinel, table position). Used by EntityVisibilityGridManager for entity ordering.
- `0x00465FF0` **AddressExposingStub** — Address-exposing stub: converts the code pointer of sub_466000 to an integer via BooleanToIntConversion; no state change. Consistent with a callback or registration pattern.
- `0x00466000` **UnknownObject** — Guarded cleanup of a single global allocation: reads dword_7CD460; when non-null frees it via FreeWrapper_7bcf and returns the wrapper result, otherwise returns zero.
- `0x00466050` **AddressExposingStub** — Address-exposing stub: converts the data address unk_466060 to an integer via BooleanToIntConversion; no state change. Mirrors the sibling code-pointer stub.
- `0x00466080` **UnknownObject** — Thin forwarding wrapper: passes this to StringCopyWithBufferRealloc and returns its result. The deterministic facts also record a read of global dword_7CD468 that the raw source text does not show (source/facts contradiction).
- `0x00466110` **UnknownObject** — Side-effect-free byte getter: reads and returns the byte at this+0x3C. No callers recorded in the packet.
- `0x00466160` **UnknownObject** — Angle-ratio computation and store: computes sqrt(this[62]^2 - this[70]^2), stores to this+0x11C; then stores the ratio this[70]/this[62] to this+0x120 through a float-conversion wrapper. Returns 0. Wrappers WrapperReturn0 and FloatConvertWrapper treated as opaque.
- `0x00468090` **VTableManagedObject** — Constructor-style init: calls base initializer 0x00466090, installs vtable off_59F668 at this+0x0, writes sentinel -1 at this+0x128; returns the initialized this pointer.
- `0x004692A0` **UnknownObject** — Thin wrapper forwarding the receiver to PlayerProfileScanner (0x00468EE0) with a literal second argument 0; always returns 0. Consistent with a profile-scan invocation during profile page handling.
- `0x004694B0` **SinglyLinkedContainer** — Indexed filename lookup in a linked list whose head is at this+0x444 and element count at this+0x450 (next pointer at node+4, node+0 points to a string array); copies the resolved string to this+0x344, strips one trailing backslash, returns the buffer. Out-of-range, missing-node, or null-string cases return the shared fallback byte_5EA438.
- `0x0046A270` **VTableManagedObject** — Destructor-style thiscall: installs vtable off_59F878 at this+0x0, conditionally frees the sub-object at this+0x348 via FreeWrapper_7bcf when non-null, then tail-calls LinkedListDestructor(this) and returns its result.
- `0x0046A510` **SeasonDatabaseObject** — Conditional release helper: always runs SeasonDatabaseCleanup (0x0046A530), then frees this via FreeWrapper_7bcf when bit 0 of a2 is set; returns this unchanged.
- `0x0046A530` **SeasonDatabaseObject** — Destructor-style cleanup: resets the vtable at this+0x0 to off_59F938, conditionally frees the sub-object at this+0x174 via FreeWrapper_7bcf when non-null, then returns the result of FunctionCallWrapper_9440(this). Called by ShortComputation_a510.
- `0x0046A970` **SeasonDatabaseObject** — Sets the vtable pointer at this+0x0 to off_59F9E8, then delegates to FunctionCallWrapper_9440(this) and returns its result. Unconditional partial-cleanup step invoked by DestructorWithConditionalFree_a950 (0x0046A950).
- `0x0046AF00` **UnknownObject** — Sequential UI cleanup helper: calls SessionEntryListCleanup (0x0046AE60) then UIListSelectionHandler (0x00489AB0) with arguments 0 and 1 on this; always returns 0.
- `0x0046C030` **ActivationFlagObject** — Unconditional thiscall writing constant 2 into the dword at this+0x174; returns void. Called by sub_4A0250 during setup; treated as a state/counter field initialization.
- `0x0046CB00` **UnknownObject** — Stateless global sign test: returns true when the signed global dword_7CD2B8 is negative, else false. No parameters, no callees, no side effects. Called by DriverTableIndexInitialization.
- `0x0046D360` **UnknownObject** — Conditional virtual dispatch gated by a state check: calls sub_4D24A0 (condition reads global dword_8ACEE0); when it returns 0, dispatches vtable slot 56 (offset +0x38) on this with state 1; always dispatches the same slot with state 0 before returning 0. Two-state notification (active then inactive).
- `0x0046D610` **VTableManagedObject** — Scalar-deleting destructor: invokes the vtable setter VTableSetterSubCall (0x0046D630) on this, then frees the object memory via FreeWrapper_7bcf when deleting flag a2 has bit 0 set; returns this unchanged (MSVC scalar-deleting-destructor convention).
- `0x0046D630` **VTableManagedObject** — VTable setter installing off_59FC08 at this+0x0, then delegating to an init-with-cleanup subcall and forwarding its return value. Invoked by the scalar-deleting destructor 0x0046D610 as its teardown step.
- `0x0046D6A0` **VTableManagedObject** — Scalar-deleting-destructor dispatch helper: unconditionally runs VTableSetInitCall (0x0046D6C0), then frees this via FreeWrapper_7bcf only when a2 bit 0 is set; returns this.
- `0x0046E590` **UnknownObject** — Three-step processing chain: cleans up the global device handle dword_7C73E8 via CleanupWrapper (0x00433EB0), fetches the UI list element at index 0 via UIListIndexedAccessor (0x00487010), sets a path-register field with flag 0x40000000 via PathRegisterFieldSet (0x00498D00); returns 0.
- `0x0046EC10` **ActivationFlagObject** — Name-gated object activation: compares input string a2 with the first element of the global string reference array off_5C666C; on match sets the activation flag byte at this+0x174 to 1, invokes the vtable callback at offset 0x2C with (this, 1), returns 1; on mismatch resets the flag to 0 and returns 0 without dispatch.
- `0x00470170` **VtableDispatchShim** — Thin __thiscall wrapper: reads the vtable at this+0x0, invokes the virtual method at vtable offset 0xA0 (pre-hook), then calls ScreenMenuNavigationController(this) and returns its result. Unconditional.
- `0x004702F0` **VTableManagedObject** — VTable re-assignment: writes vtable pointer off_5A0308 into this+0x0, then calls VTableSetterSubCall_b4e0() and returns its result. Unconditional; likely a re-initialization or mode switch.
- `0x004713E0` **UnknownObject** — UI toggle increment/decrement handler: reads the toggle value through the pointer stored at this+0x320, adjusts by +1 when a2 == 1 else -1, clamps to [0,1], writes back, then calls EditBufferStringUpdate (0x0048B810) with a 32-byte stack buffer and returns its result.
- `0x00472720` **SinglyLinkedContainer** — String-path resolution with fallback: resolves an optional input string into a trimmed token (space scan starting at len-29 when len > 27), inserts the non-empty token via LinkedListInsertWithNodeAllocation (0x00486F30) at position -1; inserts fallback argument a3 when the input is null or resolves to an empty token.
- `0x00473650` **UnknownObject** — Resource check + virtual notify: retrieves a resource object through the GameCommandDispatchInterface vtable (global dword_7CD8C0, virtual slot 28) with resource ID 19; when non-null compares its name (reading +0xAC) with this via ObjectNameComparison (0x00477280); then unconditionally invokes the virtual method at this-vtable offset 172; returns 0.
- `0x00475020` **VTableManagedObject** — Thiscall wrapper: calls VTableSetterWithSubCall (0x00475040) to configure the object, then frees this via FreeWrapper_7bcf when bit 0 of flag a2 is set; always returns this (even when freed). Mirrors the scalar-deleting family with a different setup callee.
- `0x00475120` **SeasonDatabaseObject** — Wrapper that calls SeasonDatabaseObjectInitB (0x00475140) to initialize a sub-object, then frees this via FreeWrapper_7bcf when bit 0 of a2 is set; returns this unchanged.
- `0x00475140` **SeasonDatabaseObject** — Season database object init variant: installs vtable off_5A4370 into this+0x0, then forwards this to FunctionCallWrapper_9440 for further initialization and returns its result. No guards.
- `0x00475CC0` **UnknownObject** — __stdcall helper filling a two-dword output pair from an input position and two range endpoints: when the first dwords of both endpoints are equal the output is hardcoded to (10, 10); otherwise output is (a1, interpolated value) using CRTFtol (0x00587BDC) on the weighted float result. Called by sub_475A90.
- `0x00476050` **VtableDispatchShim** — Vtable dispatch thunk: loads the vtable at this+0x0, dispatches the method pointer at vtable+0x8 with (this, this+0x14, this+0x18) and returns its result.
- `0x00476060` **UnknownObject** — Byte-flag setter (__thiscall): unconditionally writes argument a2 into the byte at this+0x2C and returns a2. No guards, no calls, no global access.
- `0x00476240` **DefaultedStringAccessor** — Accessor returning a widget name string pointer stored at this+0x40; when null, returns the global default string byte_5EA438.
- `0x004765F0` **DefaultedStringAccessor** — Accessor returning a load-path string pointer stored at this+0x04; when null, returns the global default string byte_5EA438.
- `0x00477080` **UnknownObject** — Calls UIDimensionCapture (0x0048EBD0) on this to capture/save UI element dimensions, then clears the byte flag at this+0x17C to 0; always returns 0.

## Proposed classes

### VTableManagedObject

Structural umbrella (GUESS) for objects whose lifecycle installs a vtable at +0x0 and whose teardown re-installs a vtable and may conditionally release memory via FreeWrapper_7bcf when the deleting-flag bit 0 is set. Observed vtable tables differ (off_59F668, off_59F878, off_59FC08, off_5A0308), so this likely spans several distinct concrete classes the packet does not name.

Methods: `0x00468090`, `0x004702F0`, `0x0046D630`, `0x0046D610`, `0x0046D6A0`, `0x00475020`, `0x0046A270`

- `this+0x00000000` `void** vtable_pointer` (read_write, GUESS)
- `this+0x00000128` `int init_sentinel` (write, GUESS)
- `this+0x00000348` `void* freeable_sub_object` (read, GUESS)

### SeasonDatabaseObject

Structural umbrella (GUESS) for season-database-style objects: vtable installed at +0x0 (off_59F938 / off_59F9E8 / off_5A4370), a sub-object at +0x174 freed when non-null, and a common tail delegate FunctionCallWrapper_9440. Two thin wrappers (0x0046A510, 0x00475120) pair each cleanup/init variant with a conditional free of the enclosing object.

Methods: `0x0046A530`, `0x0046A970`, `0x00475140`, `0x0046A510`, `0x00475120`

- `this+0x00000000` `void** vtable_pointer` (read_write, GUESS)
- `this+0x00000174` `void* freeable_sub_object` (read, GUESS)

### SlotArrayContainer

Structural umbrella (GUESS) for functions sharing a 560-byte-stride slot array: container base pointer at +0x0, per-slot activation byte at element+248, active-slot count dword at base+0xE40C, and slot-indexed arithmetic (560*a1+140). Owner object and the exact array are not identified by the packet.

Methods: `0x004652D0`, `0x00464F50`, `0x00465430`

- `obj+0x00000000` `void* container_base_pointer` (read, GUESS)
- `obj+0x0000E40C` `int active_slot_count` (read_write, GUESS)

### SinglyLinkedContainer

Structural umbrella (GUESS) for functions operating on singly-linked nodes (payload at node+0, next at node+4) whose head lives in the containing object. Observed heads: list at *obj+0xE5C8 (front-pop) and filename list at this+0x444 with count at this+0x450; the merge-sort takes the head as an argument. The 104-entry priority table (dword_7CD2AC+58384) drives sort order.

Methods: `0x00465C30`, `0x00465D70`, `0x004694B0`, `0x00472720`

- `obj+0x0000E5C8` `void* pop_list_head` (read_write, GUESS)
- `this+0x00000444` `void* filename_list_head` (read, GUESS)
- `this+0x00000450` `int filename_list_count` (read, GUESS)

### ActivationFlagObject

Structural umbrella (GUESS) for functions sharing the state/activation field at this+0x174: name-matching activation (byte flag 0/1 plus vtable callback at slot 0x2C) and a setup that writes the dword 2. The byte-flag versus dword-2 semantic conflict at +0x174 is unresolved; these may be distinct classes.

Methods: `0x0046EC10`, `0x0046C030`

- `this+0x00000000` `void** vtable_pointer` (read, GUESS)
- `this+0x00000174` `unsigned char activation_state` (read_write, GUESS)

### AddressExposingStub

Stubs (GUESS) that expose a code or data address as an integer through BooleanToIntConversion (0x00587B3E) with no state change, consistent with callback registration or address comparison.

Methods: `0x00465FF0`, `0x00466050`


### DefaultedStringAccessor

Accessors (GUESS) returning a string-pointer field of the receiver and falling back to the global default string byte_5EA438 when null.

Methods: `0x00476240`, `0x004765F0`

- `this+0x00000004` `char* load_path` (read, GUESS)
- `this+0x00000040` `char* name_field` (read, GUESS)

### VtableDispatchShim

Thin __thiscall shims (GUESS) that dispatch through a vtable slot with receiver-forwarded arguments and return the call result.

Methods: `0x00476050`, `0x00470170`

- `this+0x00000000` `void** vtable_pointer` (read, GUESS)
- `this+0x00000014` `void* dispatch_arg_14` (read, GUESS)
- `this+0x00000018` `void* dispatch_arg_18` (read, GUESS)

## Compatibility contracts

- **ScalarDeletingDestructorConvention** — Destructor-family functions in this scope take a deleting flag in a2: when bit 0 is set the object memory is released through FreeWrapper_7bcf, otherwise the object is kept; the function returns the this pointer in both cases (MSVC scalar-deleting-destructor convention). A replacement must preserve this flag gating and the returned-pointer semantics.
- **VtablePointerAtObjectOffsetZero** — Objects in this scope keep their active vtable pointer at byte offset 0x0; constructor/init and teardown routines install or re-install vtables there. Observed tables: off_59F668, off_59F878, off_59F938, off_59F9E8, off_59FC08, off_5A0308, off_5A4370.
- **SinglyLinkedNodeLayout** — List nodes carry a payload pointer at node+0 and the next-node pointer at node+4; a zero payload is treated as invalid (front pop returns failure) and a null next terminates the list. List heads are stored in the containing object (observed at *obj+0xE5C8 and this+0x444, with count at this+0x450).

## Unresolved

- Concrete owning classes of all 42 functions are unproven; the packet leaves every owner UnknownObject. Class groupings (VTableManagedObject, SeasonDatabaseObject, SlotArrayContainer, SinglyLinkedContainer, ActivationFlagObject, AddressExposingStub, DefaultedStringAccessor, VtableDispatchShim) are GUESS proposals on structural similarity and must be verified before reuse.
- The distinct vtable addresses (off_59F668, off_59F878, off_59F938, off_59F9E8, off_59FC08, off_5A0308, off_5A4370) most likely indicate distinct concrete classes, not one class; the packet does not connect any vtable to a type name.
- Field this+0x174 is read with conflicting semantics: SeasonDatabaseCleanup frees it as a sub-object pointer, while SetField174ToTwo writes the dword 2 and ObjectNameMatchingActivation uses it as a 0/1 activation byte. This may be two classes or a union at one offset; unresolved.
- The 560-byte-stride slot array's owning object, the semantic roles of the a2 index and the divisor/cap fields, and the source/facts R-W classification contradiction on the +0xE40C counter and the activation byte in 0x004652D0 are unresolved.
- Delegates named only in the raw source with no packet callee entry cannot be resolved: sub_464D30 (0x00465150), LinkedListDestructor (0x0046A270), FunctionCallWrapper_9440 (0x0046A530/0x0046A970/0x00475140), InitWithVTableCleanup (0x0046D630), ScreenMenuNavigationController (0x00470170), VTableSetterSubCall_b4e0 (0x004702F0).
- The read of global dword_7CD468 recorded for 0x00466080 is absent from the raw source text; a deterministic-facts versus raw-source contradiction (the material ref is carried in unresolved_evidence_refs).
- Priority-table values at dword_7CD2AC+58384 and how the packed-key fields (top two bits, masked sub-field, low byte with 255 sentinel) map to visual sort order are not derivable from this packet.
- The base pointer v3 in 0x00464F50 is uninitialized in the decompiled view; the reads at +58380 and +684+560*a2 cannot be attributed to a verified object.
- The vtable-slot offsets 0x8, 0x2C, 0x38, 0xA0, 0xA0/0xAC and slot-172 dispatch targets are resolved only as offsets; the callback identities are unknown.
