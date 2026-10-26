# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `GUESS`

Reconstruction of generic runtime objects from 47 validated function IR records. No packet owner is named, so all classes are GUESS-level groupings. The strongest cross-function cluster is the CallbackRegistrationTrampoline family (9 functions), all reading a distinct code/data global and forwarding it to BooleanToIntConversion 0x00587B3E; the second is the car lighting bitfield cluster over this+0x30 (0x004B2AA0/0x004B2AE0/0x004B2B60) plus the separate 0xF00 toggle at this+0x2C (0x004B2A10). Three list containers form a second family: the float linked list (0x004B8150, head/count this+0x6C0/0x6CC), the indexed list (0x004C5130, head/iterator/count/index this+0x8/0x10/0x14/0x18), and the merge sort (0x004C6810, node+0x4 next pointers, SceneSortComparator 0x004C5D30). Two vtable-dispatch pairs operate on the globals dword_8AC4C4 (0x004C8180, 0x004C82F0) and dword_8AC4C8 (0x004C8580, 0x004C85A0), all under null guards. Global-block initializers (0x004B21C0, 0x004B41B0) and global-pointer free helpers (0x004B41D0, 0x004C3040) round out the procedural side. Every function's matched node data, call relationships, and field bases are attributed in function_roles; contradictions (packet-listed fields absent from raw source, ABI names that do not match raw semantics, prelabel getters contradicted by raw bodies) are recorded in unresolved.

## Function roles

- `0x004B21C0` **GlobalBlockInitializer** — GlobalBlockInitPointerBlock: straight-line initializer that clears dword_83EE60 (0x0083EE60) to zero and points the three adjacent pointer globals dword_8AAE64/8AAE68/8AAE6C at unk_83EE64 (the slot immediately after dword_83EE60), then returns &dword_83EE60. Purpose of the three-pointer block (likely a small cursor or linked-list block whose head is dword_83EE60) is unknown; callers are not evidenced so the init-time vs runtime nature of the reset is unverified.
- `0x004B21D0` **CallbackRegistrationTrampoline** — CallbackRegistrationTrampoline21d0: reads the DebugPrintNullWrapper function pointer at global 0x004B21E0, casts it to int, passes it to BooleanToIntConversion (0x00587B3E) and returns the conversion result. The wrapped routine's behavior and the registration intent (carried only by the LEGACY ABI name) have no callee/field evidence in this packet.
- `0x004B21E0` **EmptyStubInvoker** — EmptyStubInvoker21e0: single-call void wrapper invoking EmptyStub_0170() with no arguments and no use of its result. The packet's read-evidence global dword_83EE60 is not referenced by this body and is recorded as unresolved (likely an unrelated static fact).
- `0x004B2A10` **CarFlagFieldOwner** — CarFlagBitsToggle: builds a 16-bit selector with high byte (a2+1) and low byte zero, then toggles the 0xF00 bits of the dword at this+0x2C that intersect the selector, storing and returning the result. Prelabel marks it a structural twin of CarFlagByteSetter (0x00476060); caller SetupCarLightingAndRender (0x004C71C0) is consistent with a car flag/lighting-update role but does not identify the owner object.
- `0x004B2AA0` **LightingBitfieldOwner** — LightingBitfieldSetClearByIndex: writes the low bit of a3 into bit position a2 of the 32-bit word at this+0x30 (mask 1<<a2), preserving other bits, and returns the unchanged this pointer. Structural twin of ConditionalSetter0x30 (0x004980C0); bit a2's meaning is caller-supplied (SetupCarLightingAndRender drives it).
- `0x004B2AE0` **LightingBitfieldOwner** — LightingBitfieldXorSetter: masked XOR setter for the 3-bit window (bits 28-30, mask 0x70000000) of the word at this+0x30; writes a2's low three bits into the window preserving all other bits, and returns the isolated masked result (old window XOR a2's three low bits). Meaning of the three-bit value is caller-supplied.
- `0x004B2B60` **LightingBitfieldOwner** — LightingBitfieldSetter: writes a2 into the 15-bit window (bits 15-29, mask 0xFFC07FFF) of the word at this+0x30, preserving bits 0-14 and 30-31, and returns the combined value. Whether the surrounding bits carry independent flags is not established here.
- `0x004B3D40` **FlagHandlerDelegationThunk** — FlagHandlerForwardByteFlag: forwards the address of the global byte flag byte_8AB678 (0x008AB678) to the named handler sub_4B3DB0 (absent from the packet callee list, so no address) and returns its result. Shares the byte_8AB678 flag with the EmptyStub family, suggesting a shared flag-guarded callback path; the flag's meaning is unidentified.
- `0x004B3D50` **CallbackRegistrationTrampoline** — CallbackRegistrationTrampoline3d50: reads the code address of the nullsub wrapper at global 0x004B3D60 and passes it to BooleanToIntConversion (0x00587B3E), returning the integer result. No registration state is written in this body; the registration interpretation is ABI-name only (LEGACY).
- `0x004B3D60` **EmptyStubInvoker** — EmptyStubInvoker3d60: trivial void wrapper invoking EmptyStub_0170() with no arguments and no use of its result. The packet's byte_8AB678 read-evidence is not reachable from this body (it presumably occurs inside the callee stub or reflects an IDB cross-reference) and is recorded as unresolved.
- `0x004B3D70` **FloatComparator** — FloatComparator: three-way float comparator returning 1 when *a1 > (double)*a2, 0 when *a1 >= *a2 (covers equality), and -1 otherwise. The first operand is anchored to field this+0x0 per the packet; the second operand *a2 has no field entry. Signature fits a sort/ordering callback but no callers are recorded. The DERIVED getter prelabel conflicts with the raw comparator body; raw source outranks it.
- `0x004B41B0` **GlobalBlockInitializer** — GlobalBlockInitComparisonBlock: linear initializer that calls ArithmeticComparison_9780(&dword_8AB6EC) (callee unaddressed), zeroes the adjacent globals dword_8AB6E4 (0x008AB6E4) and unk_8AB6E8, and returns &dword_8AB6E4. The packet lists dword_8AB6E4 with rw=R although the raw source writes it to 0; the rw classification and the write conflict (unresolved). dword_8AB6EC has no packet global entry.
- `0x004B41C0` **CallbackRegistrationTrampoline** — CallbackRegistrationTrampoline41c0: reads the code address of sub_4B41D0 (global 0x004B41D0) and passes it to BooleanToIntConversion (0x00587B3E), returning the integer result. sub_4B41D0 is referenced only as a code address here; its behavior is outside this packet.
- `0x004B41D0` **GlobalPointerFreeHelper** — GlobalPointerFreeHierarchy: conditional teardown of the object pointed to by global dword_8AB6EC: when the pointer is non-null, destroys the UI widget hierarchy rooted at it (DestroyUIWidgetHierarchy, unaddressed) and frees the captured pointer via FreeWrapper_7bcf (0x00587BCF), returning the free result; the null branch returns an uninitialized local per the decompiler. The packet global entry dword_8AB6E4 is not touched by this body (stale/misaligned entry, unresolved).
- `0x004B8150` **FloatLinkedList** — FloatLinkedListGetByIndex: returns the float payload at the given index of a linked list whose head is this+0x6C0 and element count this+0x6CC. Guards on index in [0, count), walks next pointers (node+4), dereferences the reached node's first dword as the payload pointer, and returns the -1.0 sentinel (global 0x0059E670 assumed) for an out-of-range index, null node, or null payload. Tail pointer this+0x6C8 is not read here. Sole caller Passthrough (0x004B9D90).
- `0x004B97D0` **IndirectThis0ForwardingThunk** — IndirectThis0ForwardThunkGameDataFileIO: dereferences the object's first dword (this+0x0) and forwards it together with a2/a3 to GameDataFileIO, returning the BOOL result. The DERIVED getter prelabel ('returns field 0x0') is contradicted by the raw delegated-call body; raw source wins. Callers sub_4BA1F0 and sub_4BA460 are not available here.
- `0x004B9800` **IndirectThis0ForwardingThunk** — IndirectThis0ForwardDispatchBufferPool: dereferences this+0x0 and passes the loaded pointer to BufferPoolAllocatorInitialization (named only in raw source, unaddressed), returning its result unchanged. No null guard on the dereferenced pointer; single caller sub_4BA460.
- `0x004B9860` **TimestepFactorSetterOwner** — TimestepFactorSetter: dereferences this+0x0 to obj, writes a2 into obj+0x9AC, then maps a2 (0-4) onto five float-constant bit patterns at obj+0xF7C (1042983595, 1040187392, 1036831949, 1034594987, 1026206379); an a2 outside 0-4 writes only the index field and returns a2. Timestep interpretation is DERIVED from prior analysis, not confirmed. Single caller sub_4BA460 (0x004BA460).
- `0x004B9D90` **IndirectThis0ForwardingThunk** — IndirectThis0ForwardPassthrough: dereferences the object pointer at this+0x0 and forwards the pointed-to object together with a2 to LinkedListFloatAccessor (0x004B8150); returns void. No other reads, writes, guards or state changes. Prelabel marks it a structural twin of 0x00404F70, unconfirmed.
- `0x004B9F89` **FieldF8CGetterOwner** — FieldF8CGetter: trivial getter returning the DWORD at this+0xF8C (offset 3980 from the __usercall argument a1). No side effects, guard or callees; the semantic role of field 0xF8C is not grounded in this packet.
- `0x004BA790` **DoublePointerFieldAccessorOwner** — DoublePointerAccessor: reads the pointer stored at this+0x8 and returns the DWORD it points to, or 0 when that pointer is null. No side effects. Caller CollisionObjectListManagement (0x004B4B50) suggests list-node usage but that link is not proven by this packet.
- `0x004BB3D0` **NodeDataFreeOwner** — NodeDataFree: node-data teardown. Reads the byte flag at this+0xC (returned in every path); when it is non-zero and the primary data pointer at this+0x0 is non-null, frees the secondary pointer at obj+0x4 first (if non-null), then the primary block, both via FreeWrapper_7bcf (0x00587BCF). Never frees the node buffer itself (unlike structural twin 0x004BA900), which the caller GameDataFileIO may own. Data-block layout (primary/secondary) is unknown.
- `0x004BB800` **TwoFieldZeroingOwner** — TwoFieldZeroInit: writes 0 to this[12] (offset 0x30) and this[41] (offset 0xA4) and returns 0. Reached from VehgenScnFileLoader (0x004C6C40), so the target object is created/initialized along the vehicle-gen scene-file load path; the owning class and the purpose of the two zeroed fields are unknown.
- `0x004BC2E8` **StateFieldSetterOwner** — StateFieldToOne: unconditional setter writing the literal 1 to the state/mode field this+0x60 (element this[24]). No parameters beyond this, no guards, no callees, no return value. The state semantics of the value 1 (which state machine, which enum) are not grounded in this packet.
- `0x004BD7A0` **AudioMixerChannelInitWrapper** — AudioMixerChannelInitWrapper: single-function-call wrapper passing the audio mixer channel state in global dword_8AB710 (0x008AB710) to the callee named AudioMixerChannelInit (no packet address) and returning that callee's result. No local computation; the type/layout of dword_8AB710 is unknown.
- `0x004BD7B0` **CallbackRegistrationTrampoline** — CallbackRegistrationTrampolineUnregister: casts the address of the data global unk_4BD7C0 (0x004BD7C0) to int and passes it to BooleanToIntConversion (0x00587B3E), returning the result. The ABI-name callback-unregistration intent is unverified; the body shows only a read path and no callers are recorded.
- `0x004C2C10` **CounterIncrementOwner** — CounterIncrement: bumps the 32-bit field at this+0x34 (this[13]) by one in place and returns void; invoked by sub_4A0760 (0x004A0760). The packet classifies field 0x34 as read-only (rw=R) although the raw source performs an in-place read-modify-write, and the prelabel labels it a no-side-effect getter; both are contradicted by the raw source, which outranks them.
- `0x004C2FA0` **FlagHandlerDelegationThunk** — FlagHandlerDelegation2fa0: forwards the address of the untyped global unk_8AC388 (0x008AC388) to the named handler sub_4B3DB0 (absent from the packet callee list) and returns its result. The callee's behavior and the global's content are unknown.
- `0x004C2FB0` **CallbackRegistrationTrampoline** — CallbackRegistrationTrampoline2fb0: casts the address of sub_4C2FC0 (global 0x004C2FC0) to int and passes it to BooleanToIntConversion (0x00587B3E), returning the result. No callers recorded; the purpose of passing a code address into a boolean-to-int helper is unknown.
- `0x004C2FF0` **CallbackRegistrationTrampoline** — CallbackRegistrationTrampoline2ff0: reads the callback address at global 0x004C3000 (R) and passes it to BooleanToIntConversion (0x00587B3E), returning the conversion result. No unresolved items remain in the packet.
- `0x004C3000` **GlobalComparisonForwarder** — GlobalComparisonForward: reads the global dword at 0x008AC36C and forwards it as the single argument to the named callee ArithmeticComparison_4930 (no packet address), returning that int result unchanged. The meaning of the compared quantity and the comparison semantics are not recoverable from this function alone.
- `0x004C3020` **FlagHandlerDelegationThunk** — FlagHandlerDelegation3020: forwards the address of the untyped global unk_8AC368 (0x008AC368) as the single argument to the named handler sub_4B3DB0 and returns its void* result verbatim. Matches the LEGACY ABI label Delegation_Thunk_4c3020; why it is a delegation thunk rather than a plain call is not determinable here.
- `0x004C3030` **CallbackRegistrationTrampoline** — CallbackRegistrationTrampoline3030: reads the callback address at global 0x004C3040 (R) and passes it to BooleanToIntConversion (0x00587B3E), returning the conversion result. No unresolved items remain in the packet.
- `0x004C3040` **GlobalPointerFreeHelper** — GlobalPointerFreeClear: if the global pointer dword_8AC490 is non-zero, frees it through FreeWrapper_7bcf (0x00587BCF) and clears the global to null, returning the free result; otherwise returns the stored value. The packet global entry 0x008AC368 does not appear in this raw source (address discrepancy unresolved); purpose of the allocation behind dword_8AC490 is unknown.
- `0x004C3890` **StringKeyComparator** — StringKeyComparator: derives a comparison key from the object at offset 116 on each side via sub_587ECE (0x00587ECE) and returns whether the calling object's derived key is strictly less than the other object's key, as a BOOL. Offset 116 is a dword index per the Hex-Rays rendering; the key-derivation helper's semantics are unknown. Caller context (VehicleDataLoader, 0x004C4240) suggests a vehicle-data string comparison but no object type evidence exists.
- `0x004C5130` **IndexedLinkedList** — IndexedListAccessor: returns the data value at position index (this+0x18) of a singly linked list whose head is this+0x8 and count this+0x14. In-range access walks the list to the indexed node and returns the value pointed to by the node's first dword; out-of-range access resets the iterator this+0x10 to the head and returns the first element's value (or 0 when the list is empty). Node payload type unconfirmed; caller TrackSceneConfigLoader (0x00477680) is external context.
- `0x004C6810` **LinkedListMergeSort** — LinkedListMergeSort: top-down merge sort for a singly-linked list whose next pointers are at node+0x4. Counts nodes, recursively sorts both halves after a midpoint split (terminating the left half by zeroing the midpoint's next), and merges the halves using SceneSortComparator (0x004C5D30) ordering. Returns the new head, or the input unchanged for null or short lists. Caller SceneFileFilterBuilder (0x004C6330) suggests scene-filter list use (DERIVED).
- `0x004C7C30` **GlobalRegionZeroInitializer** — GlobalRegionZeroInit: one-call wrapper that zero-initializes four consecutive dwords at the global flt_8AC4B0 (0x008AC4B0) via the named helper ZeroInit4Ints (no packet address) and returns the resulting pointer. Whether flt_8AC4B0 is an actual float value or a reinterpreted dword region is unknown.
- `0x004C7C40` **CallbackRegistrationTrampoline** — CallbackRegistrationTrampolineUnregister2: reads the PhysicsVectorGetter callback address at global 0x004C7C50 (R) and passes it to BooleanToIntConversion (0x00587B3E), returning the conversion result. No unresolved items remain in the packet.
- `0x004C7C70` **GlobalListContainer** — GlobalListContainerReset: resets the global container/list object at byte_8AC494 (0x008AC494) by writing 0 into seven consecutive dwords (byte_8AC494 through unk_8AC4A8) and the literal 1120403456 into unk_8AC4AC, then returns the container base pointer. The first write clears the container head pointer; the trailing literal's meaning (e.g. a float bit pattern) is not provable from this packet alone. Sister 0x004C7C90 destroys the same object.
- `0x004C7C80` **CallbackRegistrationTrampoline** — CallbackRegistrationTrampoline7c80: casts the address of the stub sub_4C7C90 (global 0x004C7C90) to int and passes it to BooleanToIntConversion (0x00587B3E), returning the result. The ABI name Free_Callback_Registration_4c7c80 is not corroborated by packet evidence.
- `0x004C7C90` **GlobalListContainer** — GlobalListContainerDestroy: destroys the global container/list object at byte_8AC494 (0x008AC494) by calling ListDestructorWithSubFree on it (callee unaddressed) and returns that call's integer result. Forms the reset/destroy pair with 0x004C7C70 for the byte_8AC494 container; element type unknown.
- `0x004C7DD0` **FieldFourZeroingOwner** — FieldFourZero: writes 0 into the DWORD field at offset +0x4 of the receiver object (this[1]) unconditionally; used as a state/reset flag clear during an audio restart sequence (caller Sound_Restart 0x004C8B20). The receiver class and whether +0x4 is genuinely a sound-related state flag are not established from this packet.
- `0x004C8180` **GlobalVTableObjectDispatcher** — GlobalVTableDispatchSlot40: when the global object pointer dword_8AC4C4 (0x008AC4C4) is non-null, dispatches an indirect __thiscall through vtable offset +40 (slot index 10) passing (dword_8AC4C4, 0, 0, 0) and returns its result; the null path returns an uninitialized local per the decompiler. Invoked from sub_4A0250 (0x004A0250) and Sound_Post (0x004C8CA0). Object type and slot meaning unknown.
- `0x004C82F0` **GlobalVTableObjectDispatcher** — GlobalVTableDispatchCameraView: when dword_8AC4C4 is non-null, calls the vtable method at offset 56 with argument 2 and the vtable method at offset 4 with hWnd (global 0x007CE2DC); a non-zero offset-4 return clears dword_8AC4C4 to null, otherwise the vtable methods at offsets 44 (argument 1065353216) and 52 (argument dword_7CF230) are called. Legacy ABI label Camera_View_System_Dispatch is uncorroborated; the only static caller is Sound_Enter (0x004C8A20). Method argument meanings unknown.
- `0x004C8580` **GlobalQueryDispatchPair** — GlobalVTableQueryGuard: boolean predicate returning true only when dword_8AC4C8 (0x008AC4C8) is non-null and the indirect __thiscall through its vtable offset +8 (slot index 2, this = dword_8AC4C8) returns non-zero. Consumed by FileLoadWithRetryLoop (0x004F9B70) where it appears to gate a follow-up action. The +8 slot's query role is inferred from its boolean use.
- `0x004C85A0` **GlobalQueryDispatchPair** — GlobalVTableDispatchQueryAction: two-stage guarded virtual dispatch on dword_8AC4C8: when the object pointer is non-null, calls the vtable offset +8 __thiscall (this = dword_8AC4C8) as a query; if that returns non-zero, invokes the vtable offset +16 __thiscall (slot index 4) as the action. Paired with VTableMethodGuard (0x004C8580) on the same object; consumed by FileLoadWithRetryLoop (0x004F9B70).

## Proposed classes

### GlobalBlockInitializer

Procedural linear initializers (no instance fields) that reset a small contiguous global block and hand its base address to the caller: 0x004B21C0 clears dword_83EE60 and points three adjacent pointer globals at unk_83EE64; 0x004B41B0 calls ArithmeticComparison_9780(&dword_8AB6EC) and zeroes dword_8AB6E4/unk_8AB6E8. The two blocks are unrelated globals grouped only by the identical init-return pattern.

Methods: `0x004B21C0`, `0x004B41B0`


### CallbackRegistrationTrampoline

Family of single-call wrappers (9 functions) that read a code address or data-global address from a distinct global slot, cast it to int, and pass it as the single argument to BooleanToIntConversion (0x00587B3E), returning the conversion result. None writes registration state; the register/unregister interpretation rests on the LEGACY ABI names only. Each trampoline reads its own global slot (0x004B21E0, 0x004B3D60, 0x004B41D0, 0x004BD7C0, 0x004C2FC0, 0x004C3000, 0x004C3040, 0x004C7C50, 0x004C7C90).

Methods: `0x004B21D0`, `0x004B3D50`, `0x004B41C0`, `0x004BD7B0`, `0x004C2FB0`, `0x004C2FF0`, `0x004C3030`, `0x004C7C40`, `0x004C7C80`


### EmptyStubInvoker

Trivial void wrappers (2 functions) that invoke the named stub EmptyStub_0170 with no arguments and no use of its result. EmptyStub_0170 has no callee evidence in the packet; each wrapper carries an unrelated packet read-evidence global (0x0083EE60 / 0x008AB678) that its body never touches.

Methods: `0x004B21E0`, `0x004B3D60`


### CarFlagFieldOwner

Object with a 32-bit flag/lighting word at this+0x2C whose 0xF00 bits are toggled by 0x004B2A10 with a (a2+1)<<8 selector. Structural twin of CarFlagByteSetter (0x00476060) per the prelabel; driven by SetupCarLightingAndRender (0x004C71C0). The semantics of the 0xF00 bits are unknown.

Methods: `0x004B2A10`

- `this+0x0000002C` `int flag_word` (read_write, DERIVED)

### LightingBitfieldOwner

Object with a 32-bit bitfield word at this+0x30 manipulated by three methods: single-bit set/clear by index (1<<a2, 0x004B2AA0), a 3-bit window in bits 28-30 set by masked XOR (mask 0x70000000, 0x004B2AE0), and a 15-bit window in bits 15-29 set with mask 0xFFC07FFF (0x004B2B60). All three are driven by SetupCarLightingAndRender (0x004C71C0); the meaning of each window is caller-supplied and unknown.

Methods: `0x004B2AA0`, `0x004B2AE0`, `0x004B2B60`

- `this+0x00000030` `int bitfield_word` (read_write, DERIVED)

### FlagHandlerDelegationThunk

Forwarders (3 functions) that pass the address of a global flag/state block (byte_8AB678, unk_8AC388, unk_8AC368) as the single argument to the same named handler sub_4B3DB0 and return its result. sub_4B3DB0 is named only in raw source text and carries no packet address; the globals are untyped.

Methods: `0x004B3D40`, `0x004C2FA0`, `0x004C3020`


### FloatComparator

Comparator object: 0x004B3D70 returns 1 when *a1 > *a2, 0 when *a1 >= *a2, -1 otherwise, comparing the two operand floats promoted to double. The first operand is anchored to this+0x0; the second operand has no packet field entry. Signature fits a sort/ordering callback but no callers are recorded.

Methods: `0x004B3D70`

- `this+0x00000000` `float first_operand_float` (read, DERIVED)

### GlobalPointerFreeHelper

Teardown helpers (2 functions) that conditionally release a global pointer through FreeWrapper_7bcf (0x00587BCF): 0x004B41D0 destroys a UI widget hierarchy rooted at the global before freeing and returns the free result; 0x004C3040 frees and clears its global to null, returning the free result. The null branches differ (uninitialized local vs stored value).

Methods: `0x004B41D0`, `0x004C3040`


### FloatLinkedList

Linked list of float payloads owned by an unknown object: head pointer at this+0x6C0, tail pointer at this+0x6C8 (not read by the accessor, recorded for completeness), and element count at this+0x6CC. The accessor (0x004B8150) walks to the indexed node and returns the float pointed to by the node's first dword, or the -1.0 sentinel (global 0x0059E670 assumed) on failure.

Methods: `0x004B8150`

- `this+0x000006C0` `pointer list_head` (read, DERIVED)
- `this+0x000006C8` `pointer list_tail` (read, GUESS)
- `this+0x000006CC` `int element_count` (read, DERIVED)
- `*(this+0x6C0)+0x00000000` `pointer payload_ptr` (read, DERIVED)

### IndirectThis0ForwardingThunk

Dispatch thunks (3 functions) that dereference the object pointer stored at this+0x0 and forward the pointed-to object (with extra arguments) to a delegated callee: GameDataFileIO (0x004B97D0), BufferPoolAllocatorInitialization (0x004B9800), and LinkedListFloatAccessor 0x004B8150 (0x004B9D90). All are straight-line thiscall forwarders with the same this+0x0 indirection; the object type behind this+0x0 is unknown.

Methods: `0x004B97D0`, `0x004B9800`, `0x004B9D90`

- `this+0x00000000` `pointer target_object_ptr` (read, DERIVED)

### TimestepFactorSetterOwner

Object reached through a this+0x0 indirection holding a timestep index at obj+0x9AC and a timestep factor at obj+0xF7C (five float-constant bit patterns selected by index 0-4). The setter (0x004B9860) always writes the index and conditionally the factor constant; the timestep interpretation is DERIVED from prior analysis. Single caller sub_4BA460.

Methods: `0x004B9860`

- `this+0x00000000` `pointer indirect_object_ptr` (read, DERIVED)
- `obj+0x000009AC` `int timestep_index` (write, DERIVED)
- `obj+0x00000F7C` `float timestep_factor` (write, DERIVED)

### FieldF8CGetterOwner

Object exposing a DWORD at this+0xF8C through a trivial read-only getter (0x004B9F89). No side effects; the semantic role of field 0xF8C is not grounded in this packet.

Methods: `0x004B9F89`

- `this+0x00000F8C` `int field_dword` (read, DERIVED)

### DoublePointerFieldAccessorOwner

Object with a pointer field at this+0x8 that is dereferenced once and returned, or 0 when null (0x004BA790). No side effects. Caller CollisionObjectListManagement (0x004B4B50) suggests list-node usage but that link is not proven.

Methods: `0x004BA790`

- `this+0x00000008` `pointer target_ptr` (read, DERIVED)

### NodeDataFreeOwner

Node record holding a teardown flag byte at this+0xC, a primary data pointer at this+0x0, and a secondary data pointer at the data block's +0x4 (base obj). The free method (0x004BB3D0) releases the secondary then the primary block through FreeWrapper_7bcf (0x00587BCF) only when the flag is set and the primary is non-null; the node buffer itself is never freed here.

Methods: `0x004BB3D0`

- `this+0x00000000` `pointer primary_data_ptr` (read, DERIVED)
- `this+0x0000000C` `byte teardown_flag` (read, DERIVED)
- `obj+0x00000004` `pointer secondary_data_ptr` (read, DERIVED)

### TwoFieldZeroingOwner

Object whose initializer (0x004BB800) zeroes two DWORD fields at this+0x30 and this+0xA4 and returns 0. Reached from VehgenScnFileLoader (0x004C6C40), so it is created along the vehicle-gen scene-file load path; purpose of the two fields is unknown.

Methods: `0x004BB800`

- `this+0x00000030` `int zeroed_field` (write, DERIVED)
- `this+0x000000A4` `int zeroed_field` (write, DERIVED)

### StateFieldSetterOwner

Object with a state/mode field at this+0x60 that an unconditional setter (0x004BC2E8) writes to the literal 1. Which state machine and which enum value 1 denotes are unknown.

Methods: `0x004BC2E8`

- `this+0x00000060` `int state_field` (write, DERIVED)

### AudioMixerChannelInitWrapper

Single-method wrapper (0x004BD7A0) passing the audio mixer channel state stored in global dword_8AB710 to a callee named AudioMixerChannelInit (no packet address) and returning its result. The global's type/layout and the callee's contract are unknown.

Methods: `0x004BD7A0`


### CounterIncrementOwner

Object with a counter field at this+0x34 that is incremented in place by 0x004C2C10 (read-modify-write, void). The raw increment contradicts the packet's rw=R classification and the no-side-effect getter prelabel; the counter's meaning is unknown. Invoked by sub_4A0760 (0x004A0760).

Methods: `0x004C2C10`

- `this+0x00000034` `int counter_field` (read_write, DERIVED)

### GlobalComparisonForwarder

Single-method forwarder (0x004C3000) reading the global dword at 0x008AC36C and forwarding it as the single argument to the named ArithmeticComparison_4930 (no packet address), returning the int result. The compared quantity and comparison semantics are unknown.

Methods: `0x004C3000`


### StringKeyComparator

Comparator object whose ordering method (0x004C3890) derives a key from the object at offset 116 on each side via sub_587ECE (0x00587ECE) and returns whether this side's key is strictly less than the other's. The key-derivation helper's semantics and the object type are unknown; caller context suggests vehicle-data string comparison.

Methods: `0x004C3890`


### IndexedLinkedList

Indexed singly-linked list object: head pointer at this+0x8, iterator cursor at this+0x10, element count at this+0x14, and the access index at this+0x18. Nodes hold a data pointer at +0; the accessor (0x004C5130) walks to the indexed node on in-range access, and resets the iterator to the head (returning the first element's value or 0) on out-of-range access. Caller TrackSceneConfigLoader (0x00477680).

Methods: `0x004C5130`

- `this+0x00000008` `pointer list_head` (read, DERIVED)
- `this+0x00000010` `pointer iterator_cursor` (read_write, DERIVED)
- `this+0x00000014` `int element_count` (read, DERIVED)
- `this+0x00000018` `int access_index` (read, DERIVED)
- `*(this+0x8)+0x00000000` `pointer data_ptr` (read, DERIVED)

### LinkedListMergeSort

Merge-sort routine (0x004C6810, recursive) over a singly-linked list whose next pointers are at node+0x4. It counts nodes, splits at the midpoint, recurses on both halves, and merges with SceneSortComparator (0x004C5D30) ordering, returning the new head (or the input for null/short lists). List node type unknown; only the +0x4 next pointer is evidenced. Caller SceneFileFilterBuilder (0x004C6330).

Methods: `0x004C6810`

- `*(this+0x4)+0x00000004` `pointer next_ptr` (read_write, DERIVED)

### GlobalRegionZeroInitializer

Single-method wrapper (0x004C7C30) that zero-initializes four consecutive dwords at the global flt_8AC4B0 via the named helper ZeroInit4Ints (no packet address) and returns the region pointer. Whether flt_8AC4B0 is a float or a reinterpreted dword region is unknown.

Methods: `0x004C7C30`


### GlobalListContainer

Global container/list object rooted at byte_8AC494 with a reset method (0x004C7C70) that zeroes seven consecutive dwords (through unk_8AC4A8), writes the literal 1120403456 into unk_8AC4AC, and returns the base pointer, and a destroy method (0x004C7C90) that calls ListDestructorWithSubFree on the same base. Element type and the trailing literal's meaning are unknown.

Methods: `0x004C7C70`, `0x004C7C90`


### FieldFourZeroingOwner

Object with a DWORD at this+0x4 that an unconditional setter (0x004C7DD0) clears to 0; used as a state/reset flag during an audio restart sequence (caller Sound_Restart 0x004C8B20). Receiver class and the field's sound-flag meaning are not established from this packet.

Methods: `0x004C7DD0`

- `this+0x00000004` `int reset_flag` (write, DERIVED)

### GlobalVTableObjectDispatcher

Dispatchers over the global object pointer dword_8AC4C4 (2 functions): 0x004C8180 dispatches vtable slot +40 with (this,0,0,0) under a null guard; 0x004C82F0 (Legacy ABI Camera_View_System_Dispatch) calls vtable slots 56 (arg 2), 4 (hWnd), and, unless the offset-4 call returns non-zero (which clears the global to null), slots 44 (arg 1065353216) and 52 (arg dword_7CF230). Object type and slot meanings unknown; callers are sound/audio paths (sub_4A0250, Sound_Post, Sound_Enter).

Methods: `0x004C8180`, `0x004C82F0`


### GlobalQueryDispatchPair

Pair of predicates/dispatchers over the global object pointer dword_8AC4C8 (2 functions): 0x004C8580 returns the truthiness of the vtable +8 __thiscall under a null guard; 0x004C85A0 runs the vtable +8 call as a query and, when it is non-zero, dispatches the vtable +16 call as the action. Both are consumed by FileLoadWithRetryLoop (0x004F9B70). Object type and the query/action slot meanings are inferred.

Methods: `0x004C8580`, `0x004C85A0`


## Compatibility contracts

- **LightingBitfieldLayout** — The word at this+0x30 packs a 15-bit value in bits 15-29 (set with mask 0xFFC07FFF by 0x004B2B60), a 3-bit value in bits 28-30 (set with mask 0x70000000 by 0x004B2AE0), and single-bit flags settable/clearable by index (1<<a2 by 0x004B2AA0); the word at this+0x2C toggles the 0xF00 bits with a (a2+1)<<8 selector (0x004B2A10). A replacement driving car lighting/flag state must preserve these window masks and selectors.
- **FloatLinkedListAccessContract** — getFloatByIndex (0x004B8150) must read the list head at this+0x6C0, guard the index against the element count at this+0x6CC, walk the node next pointers, dereference the reached node's first dword as the payload pointer, and return the -1.0 sentinel (global 0x0059E670) for an out-of-range index, null node, or null payload.
- **IndexedLinkedListAccessContract** — ListIndexedAccessor (0x004C5130) must keep head this+0x8, iterator cursor this+0x10, element count this+0x14 and access index this+0x18; in-range access walks the list and returns the value pointed to by the reached node's first dword; out-of-range access resets the iterator to the head and returns the first element's value or 0 for an empty list.
- **LinkedListMergeSortContract** — MergeSortLinkedList (0x004C6810) must sort a singly-linked list whose next pointers are at node+0x4 using SceneSortComparator (0x004C5D30) ordering, splitting at the midpoint (terminating the left half), recursing on both halves, and returning the new head or the input unchanged for null/short lists.
- **GlobalListContainerResetDestroyContract** — The container rooted at byte_8AC494 is reset by 0x004C7C70 (seven consecutive dwords zeroed through unk_8AC4A8 plus the literal 1120403456 written to unk_8AC4AC, returning the base pointer) and destroyed by 0x004C7C90 via ListDestructorWithSubFree; the reset-then-destroy pairing on the same global base must be preserved.
- **GlobalVTableDispatchContract** — The objects behind globals dword_8AC4C4 and dword_8AC4C8 expose vtable slots dispatched only when the pointer is non-null: dword_8AC4C4 slots 40 (args 0,0,0), 56 (arg 2), 4 (hWnd), 44 (arg 1065353216) and 52 (arg dword_7CF230), with a non-zero slot-4 return clearing the global to null; dword_8AC4C8 slots 8 (query) and 16 (action). A replacement must preserve these null guards and slot offsets.
- **CallbackRegistrationContract** — Nine trampolines read a code or data address from a distinct global slot (0x004B21E0, 0x004B3D60, 0x004B41D0, 0x004BD7C0, 0x004C2FC0, 0x004C3000, 0x004C3040, 0x004C7C50, 0x004C7C90) and pass it to BooleanToIntConversion (0x00587B3E), returning the conversion result. A replacement must preserve each slot's read and the single 0x00587B3E call.
- **GlobalPointerFreeContract** — Global-pointer teardown must free through FreeWrapper_7bcf (0x00587BCF) only validated pointers: 0x004B41D0 destroys the UI widget hierarchy rooted at the global before freeing and returns the free result; 0x004C3040 clears its global to null after the free; 0x004BB3D0 frees the secondary (obj+0x4) before the primary (this+0x0) only when the flag at this+0xC is set, and returns the original flag value.

## Unresolved

- 0x004B21C0 InitPointerBlock: purpose of the three pointer globals dword_8AAE64/8AAE68/8AAE6C all pointing at unk_83EE64 (likely a small cursor/linked-list block whose head is dword_83EE60) is unknown; callers are unevidenced, so the init-time vs runtime nature of the reset is unverified.
- 0x004B21D0 CallbackRegistration_21d0: the identity and purpose of DebugPrintNullWrapper are unknown; the callback-registration intent is carried only by the LEGACY ABI name and no caller evidence is recorded.
- 0x004B21E0 CallEmptyStub: EmptyStub_0170 is named in the raw source but has no callee evidence in the packet; the packet-listed global dword_83EE60 read is not present in the body and is likely an unrelated static fact.
- 0x004B2A10 ToggleCarFlagBits: semantics of the 0xF00 bits of this+0x2C are unknown; the car-flag/lighting interpretation and the structural-twin relation to CarFlagByteSetter (0x00476060) rest on the prelabel, not packet evidence; the SetupCarLightingAndRender (0x004C71C0) caller relationship does not identify the owner object.
- 0x004B2AA0 BitfieldSetClearByIndex: which lighting/render flag bit a2 selects is caller-supplied (SetupCarLightingAndRender drives it) and not recoverable here; the identity of the +0x30 bitfield owner is unknown.
- 0x004B2AE0 BitfieldXorSetter: meaning of the three-bit value a2 written into bits 28-30 of +0x30 is caller-supplied and unknown; whether the returned masked result is consumed or ignored by caller 0x004C71C0 is unknown.
- 0x004B2B60 BitfieldSetter: meaning of the 15-bit value a2 (which lighting/render parameter) is caller-supplied and unknown; whether bits 0-14 and 30-31 of +0x30 carry independent flags is not established.
- 0x004B3D40 ForwardToByteFlagHandler: callee sub_4B3DB0 has no packet callee entry, so the handler behavior is unknown; byte_8AB678 is only address-taken and the flag it guards is unidentified.
- 0x004B3D50 CallbackRegistration_3d50: the purpose of BooleanToIntConversion (0x00587B3E) is not established; the ABI label names a registration of 0x004B3D60 but no registration side effect is visible in the body.
- 0x004B3D60 InvokeEmptyStub: EmptyStub_0170 is unaddressed in the packet; byte_8AB678 is listed as read yet never referenced by the body (presumably read inside the callee or reflecting an IDB cross-reference).
- 0x004B3D70 CompareFloats: only field this+0x0 is evidenced; the second operand *a2 has no packet field entry and its offset is unanchored; no callers are recorded so the comparator use site is unknown; the DERIVED getter prelabel conflicts with the raw comparator body (raw source wins).
- 0x004B41B0 ResetComparisonGlobalBlock: dword_8AB6EC is passed to ArithmeticComparison_9780 but has no packet global entry; the packet lists dword_8AB6E4 with rw=R although the raw source writes it to 0 (classification/write conflict); the callee's side effect on dword_8AB6EC is outside the packet.
- 0x004B41C0 FunctionCallWrapper_41c0: the identity and behavior of sub_4B41D0 are not established; it is referenced only as a code address; the purpose of BooleanToIntConversion is unknown.
- 0x004B41D0 DestroyAndFreeGlobalHierarchy: the packet's global entry dword_8AB6E4 is not touched by this body (stale/misaligned entry); the null branch returns an uninitialized result per the decompiler; the contracts of DestroyUIWidgetHierarchy and FreeWrapper_7bcf are not described in the packet.
- 0x004B8150 getFloatByIndex: global flt_59E670 is assumed to hold the -1.0 sentinel but the raw source inlines -1.0, so its exact value is not packet-evidenced; whether the node's first dword is a payload pointer or an aliased value is unconfirmed; this+0x6C8 (tail) is not read here; the sentinel's semantics (missing-data vs error) are unknown.
- 0x004B97D0 ThunkToGameDataFileIO: GameDataFileIO's contract and the meaning of a2/a3 are not described in the packet; caller contexts sub_4BA1F0/sub_4BA460 are not available.
- 0x004B9800 DispatchToBufferPoolAllocatorInit: BufferPoolAllocatorInitialization is named only in the decompiled source with no packet address; there is no null guard on the dereferenced pointer; the object type behind this+0x0 is unknown.
- 0x004B9860 StateTimestepFactorSetter: the object behind this+0x0 is untyped; the 0x9AC/0xF7C timestep interpretation is DERIVED from prior analysis, not confirmed; the constant bit patterns are float literals as compiled with no IEEE-754 decode asserted.
- 0x004B9D90 Passthrough: the role of LinkedListFloatAccessor (0x004B8150) is not established; the identity of the object at this+0x0 and whether a2 is an index, flag, or length are unknown; the structural-twin relation to 0x00404F70 is unconfirmed.
- 0x004B9F89 GetFieldF8C: the owning class of this and the semantic role of field 0xF8C are not grounded in this packet.
- 0x004BA790 DoublePointerFieldAccessor: the target object behind the this+0x8 pointer is unknown; the CollisionObjectListManagement (0x004B4B50) caller suggests list-node usage but that link is not proven.
- 0x004BB3D0 NodeDataFree: owner class and the data-block layout (primary/secondary pointers) are unknown; whether obj+0x4 belongs to the same object as this is not proven (equal-offset reading only); why the node buffer itself is not freed here (unlike twin 0x004BA900) is unresolved - the caller GameDataFileIO may own it.
- 0x004BB800 ZeroTwoFields: owning class and the purpose of the two zeroed fields (0x30, 0xA4) are unknown; only that the function is reached from VehgenScnFileLoader (0x004C6C40).
- 0x004BC2E8 SetStateToOne: the state semantics of field 0x60 (which state machine, which enum value 1 denotes) are not grounded; no static callers or callees.
- 0x004BD7A0 AudioMixerChannelInit: the callee AudioMixerChannelInit is named only in raw source with no address; the type/layout of dword_8AB710 (single value vs struct) is unknown.
- 0x004BD7B0 CallbackUnregistration: BooleanToIntConversion receives a data-global address rather than a value - what it does with the pointer is unknown; no callers are recorded so the registration target and the role of unk_4BD7C0 cannot be established.
- 0x004C2C10 IncrementFieldAt0x34: packet classifies field 0x34 as read-only (rw=R) although the raw source performs an in-place read-modify-write; the no-side-effect getter prelabel contradicts the raw increment (raw source wins); the counter's meaning requires caller context not present in the packet.
- 0x004C2FA0 DelegationWrapper: callee sub_4B3DB0 appears only as a name with no address; the type, size and content of unk_8AC388 are unknown.
- 0x004C2FB0 RegistrationWrapper: the purpose of passing the sub_4C2FC0 code address into BooleanToIntConversion is unclear; no callers are recorded; whether sub_4C2FC0 is a function whose address is taken or a mutable data pointer is not resolvable from the raw source.
- 0x004C2FF0 CallbackRegistration_2ff0: BooleanToIntConversion's contract is not established by this packet.
- 0x004C3000 ForwardComparisonResult: ArithmeticComparison_4930 is named only in raw source with no packet address; the meaning of dword_8AC36C and the comparison semantics are not recoverable from this function alone.
- 0x004C3020 DelegationThunk_3020: the delegated routine sub_4B3DB0 and the semantics of unk_8AC368 are not described in the packet; whether this is a receiver/method indirection thunk rather than a plain call is not determinable.
- 0x004C3030 CallbackRegistration_3030: BooleanToIntConversion's contract is not established by this packet.
- 0x004C3040 FreeGlobal8AC490: the packet globals list names global:0x008AC368, which does not appear in the raw source that operates on dword_8AC490 and FreeWrapper_7bcf - the address discrepancy is unresolved; the allocation behind dword_8AC490 is unknown.
- 0x004C3890 CompositeStringCompare: offset 116 is a dword index per Hex-Rays rendering; the byte field it selects is not named; the semantics of sub_587ECE (key derivation) are unknown; the VehicleDataLoader (0x004C4240) caller suggests a vehicle-data string comparison but no object type evidence exists.
- 0x004C5130 ListIndexedAccessor: the node's first dword is dereferenced as a pointer before returning, implying nodes store a pointer to the value; the exact payload type is unconfirmed; abi:lead provides only the legacy name with no prototype; caller 0x00477680 (TrackSceneConfigLoader) is external context.
- 0x004C6810 MergeSortLinkedList: list node type unknown; only the +0x4 next pointer is evidenced; SceneSortComparator semantics (scene order and name) come from prior analysis, not this packet; the SceneFileFilterBuilder (0x004C6330) caller suggests scene-filter list use (DERIVED).
- 0x004C7C30 ZeroInitGlobal8AC4B0: ZeroInit4Ints is invoked by the raw source but absent from the packet callees; whether flt_8AC4B0 is an actual float value or a reinterpreted dword region is unknown.
- 0x004C7C40 Callback_Unregistration_4c7c40: BooleanToIntConversion's contract is not established by this packet.
- 0x004C7C70 ResetListContainer: the semantic role of each zeroed field and of the literal 1120403456 at the trailing field is not established; the identity of the container at byte_8AC494 is unknown; the unk_8AC498..unk_8AC4AC fields are unnamed adjacent globals.
- 0x004C7C80 FreeCallbackRegistration_7c80: the semantic role of passing the sub_4C7C90 function address to BooleanToIntConversion is unclear; the ABI name Free_Callback_Registration_4c7c80 is not corroborated.
- 0x004C7C90 DestroyListContainer: ListDestructorWithSubFree has no callee entry, so its address and behavior are not evidenced; the identity and element type of the container at byte_8AC494 are unknown.
- 0x004C7DD0 ZeroFieldAtFour: the receiver object class and the semantic meaning of the zeroed +0x4 field (candidate: state/reset flag) are not established; whether +0x4 is genuinely sound-related depends on Sound_Restart (0x004C8B20), which is not evidenced here.
- 0x004C8180 VirtualCallOnDAT008ac4c4: the object type behind dword_8AC4C4 is unknown, so the vtable layout and the meaning of offset +40 (slot 10) cannot be named; the null path returns an uninitialized local; the three zero arguments after this are unexplained.
- 0x004C82F0 CameraViewSystemDispatch: object type at dword_8AC4C4 is unknown; every call is an indirect vtable dispatch; the Legacy ABI label Camera_View_System_Dispatch is uncorroborated; the semantics of the method arguments 2, 1065353216 and dword_7CF230 are unknown.
- 0x004C8580 VTableMethodGuard: object type behind dword_8AC4C8 is unknown, so the vtable layout and the meaning of offset +8 (slot 2) cannot be named; the query role of the +8 slot is inferred from its boolean use and is not independently documented.
- 0x004C85A0 VTableDispatchViaGlobal: object type behind dword_8AC4C8 is unknown, so the vtable layout and the meanings of offsets +8 (query) and +16 (action) cannot be named; the query/action roles are inferred from the call nesting.
- General: no evidence in the packet establishes runtime truth; every class in this proposal is a GUESS grouping over UNKNOWN packet owners, and equal byte offsets on unrelated this pointers are never merged unless a base expression links them. The raw source outranks any contradictory prelabel in every case where the two conflict.
