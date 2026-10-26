# GenericRuntimeObjectFacilities

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Conservative architecture for 45 validated generic runtime-object functions. Dominant patterns: (1) vtable-pointer installation helpers - VTablePointerSetter (0x00599E66) writes the object-literal vtable off_5B9C68 into the receiver slot at this+0x0 and returns this, and three wrappers (0x005997F5, 0x00599822, 0x0059984F) delegate to it with constant 0; (2) fixed-argument construction thunks delegating to shared object-constructor helpers (0x00599B86, 0x00599C58) and a construction-time vtable fixup (0x005998A1) that installs the std::basic_istream<unsigned short> vftable (0x005B9C40); (3) a wide-character stream object (uflow 0x00599D31, buffered reader 0x00599D52, buffered writer 0x00599DD9, WORD fallback read 0x0059A0D5, PointerAdjustment 0x0059A3F3, DoubleIndirectCounterUpdate 0x0059A428) exposing a read buffer this+0x1C / available count this+0x2C and write objects this+0x20 / this+0x30 with double-indirect counters; (4) teardown helpers that run a destructor (SetLocaleVTableAndDestruct 0x00599BE5, CDestructorWithVTableChain 0x00599E71, ObjectDestructorWithRefCountDecrement 0x0059A86C) and conditionally release via FreeWrapper_7bcf (0x00587BCF) when control-argument bit 0 is set; (5) C++ exception throw infrastructure (type-info globals 0x005BB6D8 / 0x005BB668 / 0x005BB900, CxxThrowException8 0x0059BFC3, frame-handler forwarding 0x0059CAA8, message getter 0x0059BFB6); (6) OS filesystem wrappers (0x0059B9F3, 0x0059BA1D) funneling errors through ErrorIDLookupTable (0x0058AF5C); (7) BooleanToIntConversion (0x00587B3E) based stub/callback registration thunks; (8) character case-mapping (0x0059C0AC) and RtlUnwind import forwarding (0x0059B24A). Most owners are UNKNOWN in the packet; class boundaries and field names are DERIVED/GUESS proposals only.

## Function roles

- `0x005997F5` **VTablePointerSetterSupport** — Parameterless delegation to the vtable-pointer setter: calls VTablePointerSetter (0x00599E66) with the constant argument 0 and returns the call result unchanged. A read of the global unk_8D4510 is recorded but absent from the decompiled expression.
- `0x00599822` **VTablePointerSetterSupport** — Single-call forwarding wrapper that invokes VTablePointerSetter (0x00599E66) with the literal 0 as its only argument and returns the callee's result unchanged. The global unk_8D44B8 is flagged as read by facts but absent from the raw source.
- `0x0059984F` **VTablePointerSetterSupport** — Single-call forwarding wrapper that invokes VTablePointerSetter (0x00599E66) with the literal 0 as its only argument and returns the callee's result unchanged. The global unk_8D45A0 is flagged as read by facts but absent from the raw source.
- `0x0059987C` **ObjectConstructorThunks** — Straight-line thunk that calls CConstructorWithSEH (0x00599C58) with the constant arguments 0 and 1 and returns its result; no branches or local state. The read of dword_8D4478 is recorded by facts but absent from the raw source.
- `0x0059988B` **BooleanToIntRegistrationThunks** — Trivial delegation thunk: reads the global ForwarderToSub5998A1 (0x00599897) and forwards its value as the integer argument to BooleanToIntConversion (0x00587B3E), returning the conversion result directly.
- `0x00599897` **VTableFixupConstruction** — Pure forwarding wrapper: delegates all four arguments (a1, a2, a3, a4) unchanged to the helper VTableFixupDuringConstruction (0x005998A1) and returns the helper's result. The callee has no address in the packet's callee list and the global 0x008D4478 is flagged as read but absent from the raw source.
- `0x005998A1` **VTableFixupConstruction** — thiscall construction-time vtable fixup: reads the object's vtable pointer at this+0x0, reads the vcall-adjustment offset from vtable slot index 1 (byte offset 0x4), writes the std::basic_istream<unsigned short>::vftable pointer (0x005B9C40) into this + that offset, then tail-jumps to 0x599BE5 to continue the constructor chain. Invoked by DestructorConditionalFree (0x0059A352).
- `0x005998C0` **ObjectConstructorThunks** — Thin construction wrapper: returns ObjectConstructorWithVtableSetup(0, 1), forwarding control to the shared object-constructor helper at 0x00599B86.
- `0x005998DB` **VTableSetSubCallBridge** — Thin __stdcall trampoline forwarding a1-a4 to VTableSetSubCall and returning its result unchanged. The VTableSetSubCall callee address is not present in the packet.
- `0x00599904` **ObjectConstructorThunks** — Fixed-argument delegation wrapper: returns ObjectConstructorWithVtableSetup(0, 1), calling the shared object-constructor helper at 0x00599B86.
- `0x00599913` **BooleanToIntRegistrationThunks** — Callback/trampoline registration thunk: returns BooleanToIntConversion((int)ThunkToSub5998E5), converting the thunk address at 0x0059991F into an int argument. Legacy label frames this as a free-callback registration.
- `0x0059991F` **VTableSetSubCallBridge** — Thin __stdcall thunk loading dword_8D4400 as the first VTableSetSubCall argument and forwarding a1-a4. The VTableSetSubCall callee address is not present in the packet.
- `0x00599933` **ObjectConstructorThunks** — Single-call wrapper that invokes ObjectConstructorWithVtableSetup (0x00599B86) with arguments 0 and 1 and returns its result unchanged. The read of dword_8D4440 is flagged by facts but absent from the raw source.
- `0x00599942` **BooleanToIntRegistrationThunks** — Thin forwarding wrapper that casts the code address at 0x0059994E to int, feeds it to BooleanToIntConversion (0x00587B3E) and returns that result. ABI name suggests registering a callback at the thunk address.
- `0x0059994E` **VTableSetSubCallBridge** — Thin __stdcall wrapper loading dword_8D4440 as the first VTableSetSubCall argument and forwarding a1-a4. The VTableSetSubCall callee address is not present in the packet.
- `0x00599BE5` **LocaleTeardownHelper** — thiscall teardown helper: first writes the std::basic_ios<unsigned short> vtable address (0x005B9C50) into this+0x0, then calls ObjectDestructorWithRefCountDecrement on the same object and returns its result. Called by ConditionalFreeWithFlagCheck (0x0059A336).
- `0x00599D31` **WideStreamObject** — Streambuf underflow (uflow) virtual method, 16-bit variant: dispatches the virtual function at vtable offset 0x10 (slot 4) through the object vtable pointer at this+0x0; when that call returns 0xFFFF the function returns -1, otherwise it reads a 16-bit word from the get area via StdGninc (0x0059A418) and returns it.
- `0x00599D52` **WideStreamObject** — Wide-character buffered reader: while the requested count is positive, fast-copies chunks from the read buffer at this+0x1C while the available count at this+0x2C is positive (chunk clamp, then PointerAdjustment 0x0059A3F3), otherwise falls back to one virtual per-character read at vtable slot 5 (vtable at this+0x0); returns the total characters read (obj+0x14), stopping early when a virtual getc returns -1.
- `0x00599DD9` **WideStreamObject** — Buffered wide-character writer: fast path copies chunks from the source to the double-indirect write cursor at this+0x20 while the space value at *(this+0x30) is positive (then DoubleIndirectCounterUpdate 0x0059A428); fallback path writes one character through the virtual single-character write slot (vtable at this+0x0, slot at vtable+4), stopping and returning the current total when that call returns 0xFFFF; returns the total written (obj+0x4).
- `0x00599E66` **VTablePointerSetterSupport** — Core vtable-pointer setter: writes the object-literal vtable address off_5B9C68 into the receiver's vtable slot at this+0x0 and returns the receiver pointer unchanged. The second argument a2 is present in the signature but never referenced in the body.
- `0x0059A0D5` **WideStreamObject** — Buffered WORD read with bounds check and vtable fallback: returns the WORD at the start of the this+0x1C buffer when the pointer is non-null and v2 + 2*(this+0x2C) does not wrap, otherwise reads the vtable at this+0x0, calls the vtable method at offset 0x14 with (this), then the vtable method at offset 0x8 with (this, result) and returns that result.
- `0x0059A336` **LocaleTeardownHelper** — Scalar-deleting-destructor style helper: runs the locale vtable destructor SetLocaleVTableDtor (0x00599BE5) on the receiver, then releases the receiver's memory through FreeWrapper_7bcf (0x00587BCF) only when bit 0 of the flag argument a2 is set, and returns the receiver pointer.
- `0x0059A371` **LocaleTeardownHelper** — Conditional free wrapper: invokes the unmodelled subroutine loc_599D17 with an uninitialized local, then frees the this object via FreeWrapper_7bcf (0x00587BCF) when the low bit of the flag argument a2 is set, and returns this unchanged.
- `0x0059A38D` **LocaleTeardownHelper** — Destructor-style helper under the MSVC __userpurge convention: runs CDestructorWithVTableChain (0x00599E71) on the ebp-delivered argument a2, then releases the ecx-delivered receiver a1 through FreeWrapper_7bcf (0x00587BCF) only when bit 0 of the flag argument a3 is set, and returns a1.
- `0x0059A3F3` **WideStreamObject** — Straight-line buffer pointer adjustment invoked after a stream read or write of a2 units: decrements a remaining-count dword (reached through the pointer stored at this+0x2C) by a2, advances a buffer-position dword (reached through the pointer stored at this+0x1C) by 2*a2 bytes, and returns the pointer stored at this+0x1C. Invoked by StreamCharReaderWithBufferFillGetcFallback (0x00599D52).
- `0x0059A428` **WideStreamObject** — Double-indirect counter update: decrements the dword pointed to by *(this+0x30) (remaining write-buffer space) by a2, then increments the dword pointed to by *(this+0x20) (write-buffer position) by 2*a2, returning the pointer at this+0x20. Invoked by stream_write_chars (0x00599DD9) after chunk consumption.
- `0x0059A535` **BooleanToIntRegistrationThunks** — Argument-free delegation wrapper: reads the global EmptyStub_aa60 (0x0047AA60) and returns BooleanToIntConversion (0x00587B3E) applied to it; pure pass-through with no state on this and no guards.
- `0x0059A6FE` **SimpleObjectAccessors** — thiscall getter returning the pointer stored at this+0x10, falling back to the sentinel global unk_5B9D34 when that pointer is null; likely a string/default-object accessor with an empty sentinel fallback.
- `0x0059A70B` **CppExceptionRuntime** — MSVC exception-throw helper for std::runtime_error: constructs the exception object with ExceptionObjectConstructor (0x0059A781), then raises a C++ exception with CxxThrowException8 (0x0059BFC3) using a local 28-byte throw-parameter frame and the std::runtime_error type-info global at 0x005BB6D8 as the throw descriptor.
- `0x0059A81B` **CppExceptionRuntime** — C++ exception-throw wrapper for std::ios_base::failure: constructs the exception object via sub_59A854 (0x0059A854), throws through CxxThrowException8 (0x0059BFC3) with the ios_base::failure type-info global at 0x005BB668, runs destructor cleanup with SEH vtable reset via DestructorWithSEHVTableReset (0x0059A7DE); when ownership flag bit 0 of the stack buffer is set, the wrapped heap pointer is released through FreeWrapper_7bcf (0x00587BCF) and the pointer is returned.
- `0x0059A854` **CppExceptionRuntime** — Constructs a std::ios_base::failure exception object: calls ExceptionObjectConstructor (0x0059A781) to build the std::runtime_error base, then overwrites the vtable pointer at this+0x0 with the ios_base::failure vtable address held at global 0x005B9CE4, and returns the object pointer. Invoked from ThrowIosBaseFailure (0x0059A81B).
- `0x0059A8BC` **LocaleTeardownHelper** — __userpurge helper that unconditionally runs ObjectDestructorWithRefCountDecrement (0x0059A86C) on a2, then conditionally calls FreeWrapper_7bcf (0x00587BCF) on a1 when the low bit of a3 is set, and returns a1.
- `0x0059AC3F` **LocaleTeardownHelper** — Minimal __thiscall that unconditionally overwrites the object vtable pointer at this+0x0 with the std::locale::facet vftable address (0x005B9D54); consistent with a destructor-time vtable reset.
- `0x0059AD31` **BooleanToIntRegistrationThunks** — Short straight-line thunk that reads global EmptyStub_aa60 (0x0047AA60), passes it cast to int into BooleanToIntConversion (0x00587B3E), and returns the conversion result.
- `0x0059AE07` **CppExceptionRuntime** — Raises a C++ exception of type std::logic_error: the __thiscall receiver is run through CObjectConstructorWithVtable (0x0059AE7D) to install its vtable, then CxxThrowException8 (0x0059BFC3) is invoked with a 28-byte stack buffer as the exception-object payload and the RTTI type_info descriptor for std::logic_error (0x005BB900).
- `0x0059B07A` **BooleanToIntRegistrationThunks** — Trivial wrapper: passes the value of global EmptyStub_aa60 (0x0047AA60) to BooleanToIntConversion (0x00587B3E) and returns its result.
- `0x0059B086` **BooleanToIntRegistrationThunks** — Trivial wrapper: passes the value of global EmptyStub_9796 (0x00599796) to BooleanToIntConversion (0x00587B3E) and returns its result. Legacy ABI label suggests registration of function 0x00599796 via 0x00587B3E.
- `0x0059B24A` **RtlUnwindForwarder** — Pure indirect-jump-through-import forwarding thunk that forwards the four RtlUnwind arguments (TargetFrame, TargetIp, ExceptionRecord, ReturnValue) to the imported ntdll RtlUnwind pointer at 0x0059E1F0. Invoked by GlobalUnwind2 (0x00588864) and SEHUnwindHandler (0x0058A331) during exception unwinding.
- `0x0059B758` **SimpleObjectAccessors** — Trivial getter: returns the dword at offset 0x10 of the object pointer argument a1; no side effects, guards, or control flow. Called from LinkedListNodeInsert (0x00407520); the field is likely a node link, not established by this packet.
- `0x0059B9F3` **OsFileSystemHelpers** — RemoveDirectoryA wrapper with error reporting: calls RemoveDirectoryA (0x0059E210); on success treats LastError as 0, otherwise captures GetLastError() (0x0059E188); a zero error code returns 0 (success), otherwise hands the error to ErrorIDLookupTable (0x0058AF5C) and returns -1 (failure). Invoked by sub_499690 (0x00499690).
- `0x0059BA1D` **OsFileSystemHelpers** — Per-drive current directory setter: changes to the given path (SetCurrentDirectoryA 0x0059E20C), reads the resolved directory (GetCurrentDirectoryA 0x0059E1B0), skips UNC paths, uppercases the drive letter via CharToUpper (0x0059C0AC), sets the '=X:' environment variable (SetEnvironmentVariableA 0x0059E0B0); any failure path reports GetLastError (0x0059E188) through ErrorIDLookupTable (0x0058AF5C) and returns -1. Called by sub_565F80 (0x00565F80).
- `0x0059BFB6` **CppExceptionRuntime** — Exception what()-style getter (__thiscall): returns the string pointer stored at this+0x4 when non-null, otherwise returns the global 'Unknown exception' fallback string (0x005B9DC8).
- `0x0059C0AC` **CharCaseMappingUtility** — Character-to-uppercase case mapping: for 8-bit values uses the CRT ctype flag byte byte_8D47E1 (bit 0x20 = lowercase) and the precomputed uppercase table byte_8D46E0; larger values are reassembled into a wide codepoint and, when byte_8D47E1 marks a lead byte (bit 0x4), locale-aware sub_591FA1 (0x00591FA1) performs the mapping using locale handles dword_8D48E4 and dword_8D46BC; when no mapping applies the input is returned unchanged.
- `0x0059CAA8` **CppExceptionRuntime** — Single-call forwarding wrapper over the MSVC C++ exception handler: passes the address of the global unk_5BAB94 followed by all four of its own arguments to __CxxFrameHandler and returns that call's result unchanged. __CxxFrameHandler has no callee entry or address in the packet.
- `0x0059D6A9` **SimpleObjectAccessors** — Null-checked traversal followed by a stub call: guards on this, reads the list head from this+0x8, walks a singly-linked chain via next pointers at node+0x4 for up to a1 steps, then calls no-op nullsub_9(a1); the node located by the walk is discarded and the real downstream callee is not present in the packet.

## Proposed classes

### VTablePointerSetterSupport

Vtable-pointer installation for generic runtime objects: the core setter writes an object-literal vtable address into the receiver's this+0x0 slot and returns the receiver; three parameterless wrappers delegate to it with the constant 0.

Methods: `0x00599E66`, `0x005997F5`, `0x00599822`, `0x0059984F`

- `this+0x00000000` `void* vtablePtr` (read_write, DERIVED)

### ObjectConstructorThunks

Fixed-argument construction thunks that delegate to shared object-constructor helpers: three wrappers forward the constants 0 and 1 to ObjectConstructorWithVtableSetup (0x00599B86) and one thunk forwards 0 and 1 to CConstructorWithSEH (0x00599C58); none of the four has local state or guards.

Methods: `0x0059987C`, `0x005998C0`, `0x00599904`, `0x00599933`


### VTableFixupConstruction

Construction-time vtable fixup: the fixup method reads the object vtable and its vcall-adjustment slot, then installs the std::basic_istream<unsigned short> base-class vftable at the adjusted offset; a four-argument forwarder delegates into the fixup.

Methods: `0x005998A1`, `0x00599897`

- `this+0x00000000` `void* vtablePtr` (read, DERIVED)
- `obj+0x00000004` `int32 vcallAdjustOffset` (read, DERIVED)

### VTableSetSubCallBridge

Thin __stdcall trampolines that forward a1-a4 to the unresolved VTableSetSubCall helper; two of them pre-load a this-like dword global (0x008D4400 / 0x008D4440) as the first argument. The callee address is absent from the packet.

Methods: `0x005998DB`, `0x0059991F`, `0x0059994E`


### BooleanToIntRegistrationThunks

Thunks that present either a code address (0x0059991F, 0x0059994E) or a stub-global value (EmptyStub_aa60 0x0047AA60, EmptyStub_9796 0x00599796, global 0x00599897) as an int argument to BooleanToIntConversion (0x00587B3E) and return the result; nominally registering a callback target or reflecting a global flag. The callee's contract is not in this packet.

Methods: `0x0059988B`, `0x00599913`, `0x00599942`, `0x0059A535`, `0x0059AD31`, `0x0059B07A`, `0x0059B086`


### WideStreamObject

Wide-character (16-bit) buffered stream object: a virtual underflow/reader, a buffered reader with a per-char virtual getc fallback, a buffered writer with a per-char virtual write fallback, a buffered WORD read with a vtable fallback, and two counter-adjustment helpers over the double-indirect read and write counters. Layout: read buffer pointer this+0x1C, available count this+0x2C, write-buffer object pointer this+0x20, write-space object pointer this+0x30; counters are reached double-indirect at *(this+0x1C) / *(this+0x2C) / *(this+0x20) / *(this+0x30).

Methods: `0x00599D31`, `0x00599D52`, `0x00599DD9`, `0x0059A0D5`, `0x0059A3F3`, `0x0059A428`

- `this+0x00000000` `void* vtablePtr` (read, DERIVED)
- `this+0x0000001C` `unsigned char* readBufferPtr` (read_write, DERIVED)
- `this+0x0000002C` `int32 availableCount` (read_write, DERIVED)
- `this+0x00000020` `void* writeBufferObjPtr` (read_write, DERIVED)
- `this+0x00000030` `void* writeSpaceObjPtr` (read_write, DERIVED)
- `*(this+0x1C)+0x00000000` `int32 bufferPosition` (read_write, DERIVED)
- `*(this+0x2C)+0x00000000` `int32 remainingCount` (read_write, DERIVED)
- `*(this+0x20)+0x00000000` `int32 writePosition` (read_write, DERIVED)
- `*(this+0x30)+0x00000000` `int32 writeRemaining` (read_write, DERIVED)
- `obj+0x00000004` `int32 charsWrittenTotal` (read_write, DERIVED)
- `obj+0x00000008` `void* vtableSlot2` (read, GUESS)
- `obj+0x00000010` `void* vtableSlot4` (read, GUESS)
- `obj+0x00000014` `void* runningTotalOrVtableSlot5` (read_write, GUESS)

### LocaleTeardownHelper

Locale/stream object teardown and conditional-free helpers: run a destructor-style teardown (basic_ios vtable install 0x005B9C50, locale::facet vftable reset 0x005B9D54, ObjectDestructorWithRefCountDecrement, CDestructorWithVTableChain) and then release the receiver through FreeWrapper_7bcf (0x00587BCF) only when bit 0 of a control argument is set.

Methods: `0x00599BE5`, `0x0059A336`, `0x0059A371`, `0x0059A38D`, `0x0059A8BC`, `0x0059AC3F`

- `this+0x00000000` `void* vtablePtr` (read_write, DERIVED)

### CppExceptionRuntime

MSVC C++ exception throw infrastructure for the generic runtime: throw helpers construct exception objects (std::runtime_error, std::ios_base::failure, std::logic_error), raise them through CxxThrowException8 (0x0059BFC3) with type-info globals (0x005BB6D8 / 0x005BB668 / 0x005BB900), install vtable overrides (ios_base::failure vtable 0x005B9CE4), run SEH teardown, forward to the frame handler with the scope-table global 0x005BAB94, and read the exception message at this+0x4 with a global fallback.

Methods: `0x0059A70B`, `0x0059A81B`, `0x0059A854`, `0x0059AE07`, `0x0059BFB6`, `0x0059CAA8`

- `this+0x00000000` `void* vtablePtr` (read_write, DERIVED)
- `this+0x00000004` `const char* messagePtr` (read, DERIVED)

### OsFileSystemHelpers

Filesystem operations reached through IAT pointers with a shared error-reporting funnel: RemoveDirectoryA wrapper and per-drive current-directory setter both report failures through ErrorIDLookupTable (0x0058AF5C) and return -1; the per-drive setter also uses CharToUpper (0x0059C0AC) for the drive letter.

Methods: `0x0059B9F3`, `0x0059BA1D`


### SimpleObjectAccessors

Minimal accessors over generic runtime objects: a this+0x10 getter with a global sentinel fallback, a trivial dword-at-offset-0x10 getter used as a node-link reader, and a null-checked list-head traversal that walks node+0x4 next links before a stub call.

Methods: `0x0059A6FE`, `0x0059B758`, `0x0059D6A9`

- `this+0x00000010` `void* storedObjectPtr` (read, DERIVED)
- `this+0x00000008` `void* listHeadPtr` (read, DERIVED)
- `*(this+0xC)+0x00000004` `void* nextLinkPtr` (read, DERIVED)

### RtlUnwindForwarder

Pure indirect-jump thunk forwarding the four RtlUnwind arguments to the imported ntdll RtlUnwind pointer at 0x0059E1F0; invoked by the two SEH unwind paths (0x00588864, 0x0058A331).

Methods: `0x0059B24A`


### CharCaseMappingUtility

Locale-aware character-to-uppercase mapping using CRT ctype tables (byte_8D47E1 flags, byte_8D46E0 uppercase table) for the 8-bit path and the locale helper sub_591FA1 (0x00591FA1) with locale handles dword_8D48E4 / dword_8D46BC for the multibyte path.

Methods: `0x0059C0AC`


## Compatibility contracts

- **VTablePointerSetterContract** — VTablePointerSetter (0x00599E66) writes the object-literal vtable address off_5B9C68 into the receiver slot at this+0x0 and returns the receiver unchanged; three wrappers (0x005997F5, 0x00599822, 0x0059984F) invoke it with the constant 0. A replacement must preserve the this+0x0 vtable write and the receiver-return convention.
- **WideStreamBufferLayout** — The wide-character stream object exposes a read buffer pointer at this+0x1C, an available/remaining count at this+0x2C, a write-buffer object pointer at this+0x20 and a write-space object pointer at this+0x30; counters are reached double-indirect at *(this+0x1C), *(this+0x2C), *(this+0x20), *(this+0x30). PointerAdjustment (0x0059A3F3) decrements the count and advances the position by 2 units per wide character; DoubleIndirectCounterUpdate (0x0059A428) mirrors this on the write path.
- **ExceptionTypeDescriptorGlobals** — C++ throw helpers raise through CxxThrowException8 (0x0059BFC3) with 28-byte stack payloads and type-info descriptors at 0x005BB6D8 (std::runtime_error), 0x005BB668 (std::ios_base::failure) and 0x005BB900 (std::logic_error); exception objects carry a message pointer at this+0x4 (fallback 'Unknown exception' literal 0x005B9DC8) and a vtable at this+0x0. A replacement must preserve the throw ABI, the type-info globals and the message-field offset.
- **IatForwardingThunks** — RemoveDirectoryA, GetLastError, GetCurrentDirectoryA, SetCurrentDirectoryA, SetEnvironmentVariableA and RtlUnwind are reached through read-only IAT pointers at 0x0059E210, 0x0059E188, 0x0059E1B0, 0x0059E20C, 0x0059E0B0 and 0x0059E1F0 respectively; a replacement must keep these import-slots resolvable.
- **ConditionalFreeFlagSemantics** — Teardown helpers gate the FreeWrapper_7bcf (0x00587BCF) call on bit 0 of a control argument (0x0059A336 a2, 0x0059A371 a2, 0x0059A38D a3, 0x0059A8BC a3, and the ownership bit in ThrowIosBaseFailure 0x0059A81B); the bit selects the free-after-teardown ownership path. A replacement must reproduce the free-gating behavior.
- **LocaleVtableResets** — Objects are transitioned between vtables at construction/teardown by writing the vtable address into offset 0: std::basic_istream<unsigned short> vftable 0x005B9C40 at 0x005998A1, std::basic_ios<unsigned short> vtable 0x005B9C50 at 0x00599BE5, std::locale::facet vftable 0x005B9D54 at 0x0059AC3F. A replacement must preserve vtable-install-at-offset-0 semantics.

## Unresolved

- Most function owners are UNKNOWN in the packet; the class boundaries proposed here are inferred from shared this-field offsets and shared callees/callers, not proven. Per rule 8, equal offsets on different bases (this+0x0 vtablePtr across five classes, this+0x10 across two classes, obj:0x4 in both VTableFixupConstruction and WideStreamObject) were kept on their own bases and not merged.
- The VTableSetSubCall helper is referenced by three trampolines (0x005998DB, 0x0059991F, 0x0059994E) but has no callee address in the packet; its identity and behavior are not derivable here. The two this-like globals 0x008D4400 / 0x008D4440 loaded as its first argument are likely receiver pointers but unconfirmed.
- The globals 0x008D4478, 0x008D44B8, 0x008D4510, 0x008D4568, 0x008D45A0 are flagged by deterministic facts as read by various wrapper functions but are absent from the raw decompiled source of all of them; whether the reads belong to callee paths or are decompiler-collapsed side effects is unresolved.
- The shared object-constructor helpers ObjectConstructorWithVtableSetup (0x00599B86) and CConstructorWithSEH (0x00599C58) are callees only; the meaning of the constant arguments 0 and 1 (constructor context index vs flag) is not resolvable from this packet.
- Inside WideStreamObject, the field at obj+0x14 is used as a running read-total in 0x00599D52 but as a vtable-call slot in 0x0059A0D5; the two interpretations conflict and the field's true role is unresolved. The available-count read is spelled (2 * *this[11]) >> 1 rather than *this[11]; the byte-versus-word unit intent behind that expression is not proven.
- ObjectDestructorWithRefCountDecrement is named in raw sources (0x00599BE5, 0x0059A8BC) but its callee address is only evidenced for 0x0059A8BC (0x0059A86C); the 0x00599BE5 invocation has no callee entry, and ExceptionCleanupWithDestructorCall / loc_599D17 / nullsub_9 appear in raw sources with no callee evidence at all.
- ExceptionMessageGetter (0x0059BFB6) reads this+0x4 and the wide stream / constructor thunks read this+0x0; the vehicle-struct name index labels this+0x0 as postProcessInput in one place, but that label does not apply to these objects' vtable slots.
- Whether 0x0059991F and 0x0059994E are jump-thunks to a shared target or data cells is not resolvable from this packet; the BooleanToIntConversion (0x00587B3E) contract (bool-to-int narrowing vs address cast) is opaque without the callee.
- The 28-byte exception-object payload layout used by CxxThrowException8 throws (0x0059A70B, 0x0059A81B, 0x0059AE07) is not recovered, and the role of unk_5BAB94 as a __CxxFrameHandler func-info/scope table is inferred only from the ABI.
- CharToUpper (0x0059C0AC) leaves the meaning of the 0x200u flag passed to sub_591FA1, the role of dword_8D46BC (locale vs LANGID), and the distinction between locale handles dword_8D48E4 / dword_8D46BC unconfirmed.
- NullCheckedCallWrapper (0x0059D6A9) discards the list node located by its walk and calls only no-op nullsub_9(a1); the packet field base '*(this+0xC)' does not align literally with the raw source's head read this[2], so the exact base of the next-link field is ambiguous.
