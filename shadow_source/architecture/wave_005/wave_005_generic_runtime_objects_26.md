# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `GUESS`

Thirty-four validated functions grouped into eleven GUESS/DERIVED runtime-object classes plus six UNKNOWN-owner utilities. The strongest clusters are: (1) a TaskBase-like header object (vtable off_5B8C30 at +0, pointer/count at +4, dwords +0x10/+0x14, bytes +0x18/+0x19) serving init, teardown, byte-counter, header-copy and decompression paths; (2) a growable buffer (data +0, capacity +4, stored size +8) used by store/query/realloc; (3) a buffer encoder (cursor +0x400, call counter +0x408, bitmask +0x40C, value +0x410, capacity-controller pointer +0x414) with an overflow handler; (4) a linked list (head/tail/cursor/count) plus its node wrapper (payload +0, flag +8, next-link +4 documented in prose only); and (5) a family of CRT-style guarded static-initialization wrappers. All owners are UNKNOWN in the packet; every class identity, field meaning and the vtable label are DERIVED/GUESS proposals only.

## Function roles

- `0x00586460` **LinkedList** — Destroys a singly-linked list rooted at the list head: walks nodes via the next-link DWORD at node+4; for each node whose flag byte at +8 is set and data pointer at +0 is non-null, runs a callback loop over the data block and frees the block plus the data wrapper through FreeWrapper_7bcf; frees every node wrapper; zeroes the four list-structure DWORDs and returns 0.
- `0x005864E0` **LinkedListNodeWrapper** — Conditional list-node destructor helper (structural twin of 004081E0): reads the flag byte at +8; when set, runs SEH-guarded cleanup on the object pointer at +0 and frees it via FreeWrapper_7bcf; returns the original flag byte.
- `0x00586620` **LinkedListNodeWrapper** — Conditionally dispatches a virtual-destructor-style call: when the flag byte at +8 is non-zero and the vtable pointer at +0 is non-null, calls the first vtable entry with argument 1; returns the flag value.
- `0x00586CA0` **BitmapSelector** — Tests whether any bit is set in a bitmap byte array at this+0x14, using a 4-byte metadata entry selected by index this+0x3C from the table at this+0x1C (start bit position and bit count); returns true when any tested bit is set.
- `0x00586F10` **GuardedStaticInitScaffolding** — Compiler-style guarded one-time static-initialization wrapper: registers the SEH frame on unk_8D3E30, runs the dword_5EA04C one-time guard, and constructs the fixed locale/CEH static objects through vtable-setup/allocation/SEH-frame helpers.
- `0x00587030` **TaskBaseObject** — TaskBase-style object initializer: calls sub_587460(0), writes the four configuration fields (dwords at +0x10 and +0x14, bytes at +0x18 and +0x19), installs the off_5B8C30 vtable at +0, and returns this.
- `0x005870D0` **TaskBaseObject** — Partial cleanup/re-init for a TaskBase-like object: reinstalls the off_5B8C30 vtable at +0, then frees the pointer field at +4 via FreeIfNonNull; returns the free result.
- `0x00587230` **TaskBaseObject** — Adjusts the byte counter at this+0x19: increments when the flag argument is non-zero, decrements (clamped at zero) otherwise; returns the pre-modification value.
- `0x00587250` **TaskBaseObject** — Thin __thiscall scalar wrapper: reads the DWORD member at this+4 through FieldAccessor and returns it plus the constant 11; does not modify the object.
- `0x00587260` **TaskBaseObject** — Capacity-checked buffer writer: validates output capacity via AddConstantWrapper, writes a WORD header, copies a variable-length data block resolved by BufferQueryReturnPtrSizeIfValid, appends trailing fields from +0x10/+0x14/+0x18, and reports the written size through *a3.
- `0x00587370` **TaskBaseObject** — Buffer/header copy initializer: calls BufferWriteWithParams with the source pointer at a2+4, then copies the four header fields (dwords at +0x10/+0x14, bytes at +0x18/+0x19) from a2 to this; returns this.
- `0x00587430` **GuardedStaticInitScaffolding** — Compiler-style guarded one-time static-initialization wrapper: registers the SEH frame on unk_8D3E34, runs the dword_5EA04C one-time guard, and constructs the fixed locale/CEH static objects.
- `0x005874D0` **UnknownObject** — __stdcall allocation wrapper: calls the operator-new/nothrow allocator with size a1, stores the resulting pointer through output parameter a2, and returns whether the allocation succeeded (pointer non-null).
- `0x00587500` **UnknownObject** — Trivial __thiscall field reset: writes zero to the DWORD member at offset +0x8; unconditional side-effect-only write used before callers proceed.
- `0x00587510` **GrowableBuffer** — Growable-buffer store: when the requested size exceeds capacity at +4, frees the old buffer at +0 and allocates a new one; when the buffer is non-null and the size is positive, copies the data and records stored size at +8; returns 1 on both paths.
- `0x00587580` **GrowableBuffer** — Buffer descriptor query: when the capacity/validity field at +0x4 is positive, writes the data pointer at +0 into a2 and the stored size at +8 into a3, returning 1; otherwise zeroes both outputs and returns 0.
- `0x005875C0` **GrowableBuffer** — Grows the buffer by a2 plus the current capacity: allocates the new size via OperatorNewWithResultCheck, copies the currently stored data (+8 bytes) from the old buffer, frees the old block, stores the new pointer at +0; returns 0.
- `0x005876C0` **GuardedStaticInitScaffolding** — Compiler-style guarded one-time static-initialization wrapper: registers the SEH frame on unk_8D3E38, runs the dword_5EA04C one-time guard, and constructs the fixed locale/CEH static objects.
- `0x00587710` **SerializationBufferEncoder** — DWORD setter: stores a2 into the field at this+0x410 and returns the stored value; paired with the getter at 0x00587720.
- `0x00587720` **SerializationBufferEncoder** — Getter: returns the DWORD at this+0x410; no side effects; paired with the setter at 0x00587710.
- `0x00587730` **SerializationBufferEncoder** — Encodes fields from an input object into a growing buffer at this+0x400 with a capacity guard against the field at *(*(this+0x414)+0x80); values over 255 divert to VTableDispatchWithConditionalCall; on the first call records the bitmask at +0x40C and always increments the call counter at +0x408.
- `0x005878A0` **SerializationBufferEncoder** — Overflow handler for the buffer encoder: when the cursor at +0x400 passes the threshold, creates a handler object through the capacity controller's vtable slot at +0x58, initializes it with sub_586800, processes the buffer position, dispatches with the value at +0x410, and resets state via FieldConstantsInitialization before returning.
- `0x00587A90` **GuardedStaticInitScaffolding** — Thread-safe one-time initialization of global locale/CEH objects: installs an SEH handler over unk_8D3E3C, uses the dword_5EA04C guard counter, and constructs the chain of locale/CEH statics inside a critical section.
- `0x00587AC0` **GlobalCleanupStack** — Thread-safe push of an integer onto the global DWORD cleanup stack (base dword_8D5A54, top/next-free dword_8D5A50): enters a critical section, grows the stack when full, writes the value, advances the top, and returns the pushed value (0 on realloc failure).
- `0x00587B97` **CRTFloatConversionTable** — Populates the six CRT float-conversion function-pointer globals off_5E6730..off_5E6744 (two receive CfltcvtCRTFloatConversionDispatch, four receive sub_58BD29/sub_58BD8F/sub_58BCCF/sub_58BD77); returns the dispatch routine.
- `0x00588156` **UnknownObject** — Stub that invokes CRTAmsgExit with the literal code 0x19 and returns its result; legacy ABI label suggests a memory-allocation error exit (not promoted).
- `0x005881F0` **UnknownObject** — Thin forwarding helper: decomposes two 64-bit values into low/high 32-bit halves and forwards all four dwords to sub_588212; returns its result; no local state touched.
- `0x00588F66` **UnknownObject** — Varargs batch dispatcher: when the count argument is positive, iterates the stack varargs calling sub_58FCB0(a1, arg) once per element; returns the last call result.
- `0x00588F8B` **LocaleConfigParser** — Splits a locale string into up to three tokens delimited by '_', '.', ',' into a 136-byte buffer (primary at +0, secondary at +0x40, remainder at +0x80); returns 0 on success, -1 on malformed input or tokens over 63 bytes.
- `0x00589057` **LocaleConfigParser** — Applies parsed locale data: normalizes the compare-string buffer, then conditionally calls BatchFunctionCallOverVarargs for the secondary (+0x40) and tertiary (+0x80) subtokens; returns the tertiary result or the +0x80 pointer.
- `0x00589278` **UnknownObject** — Forwarding wrapper: passes a1, a2, a3 plus the constant 0 as a fourth argument to sub_58928F and returns its int result.
- `0x005894A0` **UnknownObject** — Float pass-through shim: runs the NaN/exponent guard on the incoming double, then forwards the float state to sub_5894BD and returns that result; used by quaternion and rotation math.
- `0x00589BF3` **UnknownObject** — Character-class bit-flag lookup: in single-byte mode returns bit 0x8 from row 0 of the per-character table off_5E69C8 for the given CharType; otherwise delegates to the lookup-table fallback converter with flag 8.
- `0x00589CB5` **UnknownObject** — CRT exit-path entry point: takes a UINT exit code and delegates to sub_589CC6(uExitCode, 1, 0), returning that call's result; used by SEH dispatch/guarded-call wrappers.

## Proposed classes

### TaskBaseObject

Header/config object: vtable pointer at +0 (off_5B8C30, labeled VTable_TaskBase by existing DERIVED analysis), a pointer/count field at +4 freed by the teardown helper, two dwords at +0x10/+0x14 and two bytes at +0x18/+0x19 written by the initializer. Serves init (0x00587030), re-arm-and-free (0x005870D0), byte-counter adjustment (0x00587230), a scalar read wrapper (0x00587250), capacity-checked decompression writing (0x00587260), and buffer/header copying (0x00587370).

Methods: `0x00587030`, `0x005870D0`, `0x00587230`, `0x00587250`, `0x00587260`, `0x00587370`

- `this+0x00000000` `void** vtable` (read_write, DERIVED)
- `this+0x00000004` `void* ptr_or_count_field` (read_write, GUESS)
- `this+0x00000010` `dword config_dword_0` (read_write, DERIVED)
- `this+0x00000014` `dword config_dword_1` (read_write, DERIVED)
- `this+0x00000018` `byte config_byte_0` (read_write, DERIVED)
- `this+0x00000019` `byte counter_byte` (read_write, DERIVED)

### GrowableBuffer

Growable byte buffer described by three members: data pointer at +0, capacity at +4, stored size at +8. MemcpyLikeWithRealloc (0x00587510) stores data, BufferQueryReturnPtrSizeIfValid (0x00587580) queries pointer/size while capacity is positive, and BufferReallocationAndDataCopy (0x005875C0) grows the allocation. Same layout as the buffer encoder's storage is plausible but not proven to be the same struct.

Methods: `0x00587510`, `0x00587580`, `0x005875C0`

- `this+0x00000000` `void* data_ptr` (read_write, DERIVED)
- `this+0x00000004` `dword capacity` (read_write, DERIVED)
- `this+0x00000008` `dword stored_size` (read_write, DERIVED)

### SerializationBufferEncoder

Encodes input-object fields into a growable buffer at +0x400 with a call counter at +0x408, a first-call bitmask at +0x40C, a stored value at +0x410 (getter/setter pair), and a pointer at +0x414 to a capacity-controller sub-struct. AppendFieldsToBuffer (0x00587730) writes fields; handleBufferOverflow (0x005878A0) diverts when the capacity cap is reached.

Methods: `0x00587710`, `0x00587720`, `0x00587730`, `0x005878A0`

- `this+0x00000400` `byte* buffer_cursor` (read_write, DERIVED)
- `this+0x00000408` `dword call_counter` (read_write, DERIVED)
- `this+0x0000040C` `dword first_call_bitmask` (read, GUESS)
- `this+0x00000410` `dword stored_value` (read_write, DERIVED)
- `this+0x00000414` `void* capacity_controller_ptr` (read, DERIVED)

### BufferCapacityController

Sub-struct referenced from SerializationBufferEncoder.+0x414: carries a vtable at +0 (whose slot at +0x58 creates the overflow handler object) and a capacity field at +0x80 read by the encoder's capacity guard. No direct methods are evidenced; the object is reached only through vtable dispatch.

Methods: 

- `*(this+0x414)+0x00000000` `void** vtable` (read, GUESS)
- `*(this+0x414)+0x00000080` `dword capacity` (read, GUESS)

### LinkedList

Linked-list structure rooted at this[0]: head pointer at +0, tail at +4, cursor at +8 and element count at +0xC. The only method destroys the list: it walks nodes via the +4 next link, conditionally tears down each node's data block, frees every node wrapper through FreeWrapper_7bcf, and zeroes all four structure DWORDs.

Methods: `0x00586460`

- `this+0x00000000` `node* head` (read_write, DERIVED)
- `this+0x00000004` `node* tail` (write, GUESS)
- `this+0x00000008` `node* cursor` (write, GUESS)
- `this+0x0000000C` `dword count` (write, GUESS)

### LinkedListNodeWrapper

Wrapper node reachable from the linked list: a payload/object pointer at +0 (also used as a vtable pointer for the destructor dispatch), a flag byte at +8 that gates whether the payload is destroyed, and a next-link DWORD at +4 evidenced only in the destroyer's walk (0x00586460). The payload teardown either runs SEH-guarded cleanup (0x005864E0) or dispatches the first vtable entry with argument 1 (0x00586620).

Methods: `0x005864E0`, `0x00586620`

- `this+0x00000000` `void* payload_or_vtable_ptr` (read_write, GUESS)
- `this+0x00000008` `byte flag_byte` (read, DERIVED)

### BitmapSelector

Bitmap query helper: reads a bitmap byte array at +0x14 and a 4-byte metadata table at +0x1C (each entry: start bit position and bit count), selects an entry by index +0x3C, tests the range of bits, and reports whether any bit is set. What state the bitmap encodes is unresolved.

Methods: `0x00586CA0`

- `this+0x00000014` `byte* bitmap_bytes` (read, GUESS)
- `this+0x0000001C` `uint32* metadata_table` (read, GUESS)
- `this+0x0000003C` `dword element_index` (read, GUESS)

### GuardedStaticInitScaffolding

Compiler-style guarded one-time static-initialization wrappers: register an SEH frame against the exception-handler table (unk_8D3E30/34/38/3C), run the dword_5EA04C one-time guard, and construct the fixed chain of locale/CEH static objects (unk_8D4510, unk_8D44B8, unk_8D45A0, dword_8D4478, byte_8D4568, dword_8D4400, dword_8D4440, dword_8D446C) through vtable-setup, allocation and SEH-frame-setup helpers. No stable `this` fields are evidenced; state lives in globals.

Methods: `0x00586F10`, `0x00587430`, `0x005876C0`, `0x00587A90`


### CRTFloatConversionTable

CRT function-pointer table at off_5E6730..off_5E6744 holding the float-conversion routine pointers: slot +0 and +0x14 both receive CfltcvtCRTFloatConversionDispatch (0x0058C07F), slot +4 sub_58BD29, slot +8 sub_58BD8F, slot +0xC sub_58BCCF and slot +0x10 sub_58BD77. Populated once by InitCRTFloatConversionFunctionPointers (0x00587B97). Modeled as a global table, so the six slots are recorded in evidence refs rather than as `this`-base fields.

Methods: `0x00587B97`


### LocaleConfigParser

Locale string configuration: LocaleTokenSplitter (0x00588F8B) splits a locale string on '_', '.', ',' into up to three tokens in a 136-byte buffer (primary at +0, secondary at +0x40, remainder at +0x80), and LocaleDataApply (0x00589057) applies the parsed subtokens through BatchFunctionCallOverVarargs. The delimiter set is evidenced by the inline literal '_.,' and the packet global asc_5B8C7C.

Methods: `0x00588F8B`, `0x00589057`


### GlobalCleanupStack

Thread-safe global DWORD stack for cleanup values: base pointer stored in dword_8D5A54 and top/next-free pointer in dword_8D5A50. PushIntOntoCleanupStack (0x00587AC0) enters the critical section (sub_589D6B/sub_589D74), grows the block via sub_58B5D4 when full, writes the value and advances the top. Modeled as a global object, so the two pointer globals are recorded in evidence refs rather than as `this`-base fields. A matching pop path is not in this packet.

Methods: `0x00587AC0`


## Compatibility contracts

- **UniformDeallocationPrimitive** — FreeWrapper_7bcf (0x00587BCF) is the single deallocation primitive used for linked-list node wrappers, node data blocks, and growable buffers; a replacement must route all these frees through one equivalent free function.
- **GrowableBufferDescriptor** — A growable buffer holds a data pointer at +0, capacity at +4 and stored size at +8; BufferQueryReturnPtrSizeIfValid (0x00587580) is the validity/query gate (positive capacity yields pointer+size), MemcpyLikeWithRealloc (0x00587510) is the store path, and BufferReallocationAndDataCopy (0x005875C0) is the growth path.
- **TaskBaseObjectHeader** — TaskBase-style objects carry the off_5B8C30 vtable at +0, a pointer/count at +4, and header fields +0x10/+0x14/+0x18/+0x19; ObjectInitWithVTableSetup (0x00587030) writes them and SetVtablePointerAndCallInit (0x005870D0) reinstalls the vtable before freeing the +4 field. The VTable_TaskBase identity is DERIVED-only.
- **SerializationBufferCapacityProtocol** — The buffer encoder appends fields at cursor +0x400 under a capacity cap read from the controller sub-struct at +0x414 (field +0x80); when the cap is reached, handleBufferOverflow (0x005878A0) creates a handler through the controller vtable slot at +0x58 and resets state via FieldConstantsInitialization.
- **CRTStaticInitGuard** — One-time initialization of the locale/CEH statics is guarded by the dword_5EA04C counter (negative on first call, incremented afterwards), bracketed by the critical-section helpers sub_59A54D/sub_59A5E9, and covered by the SEH handler tables unk_8D3E30..3C.
- **ThreadSafeCleanupStack** — The global cleanup stack (base dword_8D5A54, top dword_8D5A50) is mutated only inside a critical section (enter 0x00589D6B / leave 0x00589D74) and grows through sub_58B5D4; the top pointer is recomputed from the preserved element count after a reallocation.

## Unresolved

- Every `this` object owner is UNKNOWN in the packet; all class identities in this proposal are DERIVED/GUESS-level labels for otherwise unnamed receivers.
- The class identity behind the off_5B8C30 vtable is unverified; the VTable_TaskBase label is DERIVED from existing analysis and not packet-confirmed.
- GrowableBuffer: whether the +0/+4/+8 layout is the same struct across 0x00587510, 0x00587580 and 0x005875C0 is a GUESS merge; the packet only proves identical field roles on the same `this` base.
- The +0x8 offset is ambiguous across classes: it is a list cursor DWORD in LinkedList but a node flag byte in LinkedListNodeWrapper, on distinct object types that share the `this` base name; the merge is a hypothesis. The node next-link at +4 has no packet field evidence (raw-source only), so it is documented in class prose, not as a field.
- Identity and purpose of the six locale/CEH static objects (unk_8D4510, unk_8D44B8, unk_8D45A0, dword_8D4478, byte_8D4568, dword_8D4400, dword_8D4440, dword_8D446C) and of the dword_5EA04C guard counter are unresolved; the CRT one-time-initializer reading is inferred from the guard pattern.
- BufferCapacityController: the concrete class behind the sub-struct at +0x414, the +0x58 vtable-slot handler factory, and the nested object at v6+0x48 (vtable method at +0x0C) have no independently named evidence.
- The semantics of the literal arguments (0, 13, 0, 1) passed to sub_586800 by handleBufferOverflow are unknown.
- DecompressionDecode: the meaning of the three trailing fields (+0x10/+0x14/+0x18) appended after the copied data block is unknown; the relationship between AddConstantWrapper's return and the header word is unclear; the reported size (*a3 = cursor - dst + 1) off-by-one convention is not explained.
- The meaning of the tested bit 0x8 in off_5E69C8[0][CharType] and the row-0 layout of the per-character lookup table are unresolved.
- LocaleConfigParser: whether asc_5B8C7C is a duplicate of the inline '_.,' delimiter literal or an alternate is not verifiable from this packet; the exact token semantics of the three slots depend on caller sub_588E4E.
- The role of the two locale globals word_5BEB48 and word_5CC214 (present in packet globals, absent from the decompiled text) is unresolved.
- PushIntOntoCleanupStack callers: the pop path and the semantics of BooleanToIntConversion (0x00587B3E), the single known caller, are outside this packet.
- ForwardTwoInt64Args: sub_588212's semantics and why callers (random/noise/audio-pitch/wheel paths) need the two 64-bit inputs are unconfirmed.
- The count passed to NTimeCallbackLoopWithSEH by the list destroyer is read from the 4 bytes preceding the data block base; that offset is not in the packet field evidence, and the 1048-byte entry size plus EmptyStub_0170 callback semantics are unknown.
- CRT exit stubs: the meaning of exit code 0x19 in raiseCrtExit and of the fixed trailing arguments (1, 0) in sub_589CC6 are not established; whether 0x00589CB5 is the C exit() or _exit() path is not resolvable from the packet.
