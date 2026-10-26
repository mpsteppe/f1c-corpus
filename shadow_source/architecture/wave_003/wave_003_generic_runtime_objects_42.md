# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Architecture proposal for the generic_runtime_objects slice of Wave 3 packet 42. The 19 functions are the MSVC runtime-object scaffolding of the game binary. They cluster into: a shared multi-inheritance locale stream construction base (0x599B86 basic_ostream, 0x599C58 basic_istream) that chains a base vtable, a basic_ios vtable and a derived stream vtable and completes the vtable-adjusted subobject via sub_59A8FA; a locale streambuf-family constructor (0x599CB7) acquiring refs on two locale subobjects; a formatted input reader (0x59A221) running a staged file-IO/filter/masked-read pipeline with a 0x18-byte result struct and default-result fallback; the std::runtime_error family (init 0x59A69A, copy 0x59A781, cleanup copies 0x59A728/0x59A7DE) and the std::logic_error family (init 0x59ADA3, copy 0x59AE7D, cleanup copies 0x59AE24/0x59AEDA/0x59AFC2), all sharing the refcounted-string-buffer + MSVCExceptionDestructor pattern and differing only in the final vtable global (0x5B9D28 runtime_error, 0x5B9D7C logic_error); a ref-counted object destructor (0x59A86C) indexed into the global counter array byte_8D463C; the std::locale facet machinery (facet-object constructor 0x59ABCD and facet-array teardown 0x59AC7F); the lazily initialized encoding singleton (0x59AAB9) cached in dword_8D4650 with code page 63 and the encoding-name string; and two identical cleanup-callback registration shims (0x59A541, 0x59AD3D) forwarding global EmptyStub_9796 through BooleanToIntConversion. Ownership at the function-IR level is UNKNOWN for every function, so the class grouping is a DERIVED/GUESS proposal; the strongest evidence is the consistent std vtable globals (0x5B9Cxx stream/facet, 0x5B9Dxx exception) and the uniform MSVC SEH + reference-count call pattern.

## Function roles

- `0x00599B86` **LocaleIosStreamBase** — basic_ostream-family object constructor with SEH and multi-inheritance vtable-chain setup: registers the frame handler, saves the ecx-passed this, gates the base/basic_ios chain on the guard field at this+0xC, writes the base vtable (0x5B9C54), clears v3[10], sets v3[1] to the basic_ios vftable (0x5B9C50), writes the basic_ostream vftable (0x5B9C48) at this + *(*(this)+4), completes the vtable-adjusted subobject via sub_59A8FA and returns this.
- `0x00599C58` **LocaleIosStreamBase** — basic_istream-family locale object constructor with SEH and multi-inheritance vtable-chain setup: registers the frame handler, saves the ecx-passed this, gates the locale base chain on the guard field at this+0xC, writes the locale base vtable (0x5B9C5C), clears v3[11], sets v3[2] to the basic_ios vftable (0x5B9C50), writes the basic_istream vftable (0x5B9C40) at this + *(*(this)+4), completes the vtable-adjusted subobject via sub_59A8FA and returns this.
- `0x00599CB7` **LocaleStreambuf** — Locale streambuf-family constructor: registers the SEH frame, acquires reference counts on two locale subobjects (DWORD words 13 and 19) via LocaleRefcountAcquireUnderLock, sets the base vtable to basic_streambuf (0x5B9CA0), initializes the self-referential pointer ring via sub_59A4C9, installs the final vtable off_5B9C68, passes the buffer argument read at this+0x8 into ObjectInitWithBufferDataPointerAssignment and returns this; the frame state byte a1-4 steps 0/1/2 as construction progresses.
- `0x0059A221` **FormattedInputReader** — Formatted input read with buffer setup and fallback: captures the stream pointer at this+0x50, runs the staged read pipeline (FileIOForwardingWrapper, optional filter sub_587F64, masked string-stream read sub_58801D), on any failure builds a default result via sub_59942B(&a3,-1), on success sets this+0x40 to a7 when the buffer object at this+0x44 exists and resets it via BufferTruncationShrink, assembles a 0x18-byte result struct and copies it into output buffer a2.
- `0x0059A541` **CleanupCallbackRegistry** — Zero-argument cleanup-callback registration shim: reads global EmptyStub_9796 (0x00599796) and forwards it to BooleanToIntConversion (0x00587B3E), returning that helper's integer result unchanged; no local logic beyond the argument forwarding.
- `0x0059A69A` **RuntimeErrorExceptionObject** — std::runtime_error exception-object initializer: registers the SEH frame, seeds the embedded string buffer from global byte_5EA438 via StringCopyConstructor, copies the first byte of the caller buffer (this+0x8) into the object at +0xC, releases the previous refcounted sub-object at +0xC via ReferenceCountDecrementWithConditionalFree, processes the caller buffer with sub_59A9CA and installs the std::runtime_error vtable (0x5B9D28).
- `0x0059A728` **RuntimeErrorExceptionObject** — std::runtime_error exception-object cleanup: registers the SEH frame, stashes the ecx-passed object pointer, resets the vtable to std::runtime_error (0x5B9D28), clears the frame state byte, decrements the embedded sub-object refcount at v1+3 with free flag 1 via ReferenceCountDecrementWithConditionalFree, marks the frame released and chains MSVCExceptionDestructor (0x59BFA0).
- `0x0059A781` **RuntimeErrorExceptionObject** — std::runtime_error exception-object copy constructor: registers the SEH frame, reads the source object pointer from this+0x8, allocates and copies the source string via StrlenAllocCopyConstructorPattern, transfers the source flag byte from source+0xC into the new object at +0xC, releases the refcount at new+3, copies a subrange of the source buffer via sub_59A9CA and installs the std::runtime_error vtable (0x5B9D28). Called from CThrowWithException and sub_59A854.
- `0x0059A7DE` **RuntimeErrorExceptionObject** — std::runtime_error exception-object destructor, structurally identical to 0x0059A728: registers the SEH frame, resets the vtable to std::runtime_error (0x5B9D28), decrements the embedded sub-object refcount at v1+3 with free flag 1, marks the frame released and chains MSVCExceptionDestructor (0x59BFA0). Called by CExceptionThrowWrapper.
- `0x0059A86C` **RefCountedObject** — Object destructor with ref-count decrement: installs the vtable pointer off_5B9D3C, reads the ref-count index v1[9] (offset 0x24), decrements byte_8D463C[v1[9]] and calls sub_59A980 for full cleanup when the count reaches zero or the index is null, then null-checks and dispatches the pointer at this+0x20 via sub_598C70. Invoked from 0x0059A8BC.
- `0x0059AAB9` **EncodingFacetSingleton** — Lazy initialization of the encoding singleton stored in dword_8D4650, called from LocaleRefcountAcquireUnderLock: skips when the singleton is already set; on first call allocates a 40-byte object, constructs it via ObjectConstructorWithVTableAndStringInit, stores it into dword_8D4650, evaluates the constructed-object guard, writes code page identifier 63 at object+16, copies the string at dword_5B9D44 into object+24, links the singleton into dword_8D464C/dword_8D4648 and increments the reference count with CounterIncrementThreadSafe, then returns dword_8D4650.
- `0x0059ABCD` **LocaleFacetObject** — std::locale::facet-derived object constructor: registers the SEH frame, sets the reference count at +0x4 to 1, installs the std::locale::facet vtable (0x5B9D54), copies two caller flag bytes into +0x14 and +0x18, zeroes the range +0x8..+0x10, re-initializes the embedded refcounted string buffer at +0x18 from global word_5C406C, then overrides the vtable with off_5B9D4C and returns the object.
- `0x0059AC7F` **LocaleFacetObject** — Teardown of an object holding an array of facet pointers: registers the SEH frame, installs the facet-container vtable off_5B9D4C, iterates the facet array (array at this+0x8, count at this+0xC) from last slot to first, decrementing each non-null facet refcount via RefcountDecrementWithLock and conditionally destroying facets that reached zero, frees the array allocation via sub_58AA6F, releases the string buffer at this+6 and restores the vtable to std::locale::facet (0x5B9D54). Called by ExceptionDestructorWithConditionalFree (0x0059AC63).
- `0x0059AD3D` **CleanupCallbackRegistry** — Zero-argument free-callback registration shim, byte-identical wrapper to 0x0059A541: reads global EmptyStub_9796 (0x00599796) and forwards it to BooleanToIntConversion (0x00587B3E), returning that helper's integer result unchanged.
- `0x0059ADA3` **LogicErrorExceptionObject** — std::logic_error exception-object initializer: registers the SEH frame, seeds the embedded string buffer from global byte_5EA438 via StringCopyConstructor, copies the first byte of the caller buffer (this+0x8) into the object at +0xC, releases the previous refcounted sub-object at +0xC, copies a subrange from the caller buffer into the object's string buffer via sub_59A9CA and installs the std::logic_error vtable (0x5B9D7C).
- `0x0059AE24` **LogicErrorExceptionObject** — SEH-guarded destructor wrapper for a std::logic_error exception object: sets up the SEH frame (landing pad 0x0059D574), resets the vtable to std::logic_error (0x5B9D7C), releases the internal string buffer via ReferenceCountDecrementWithConditionalFree(v1+3, 1), toggles the frame guard flag from 0 to -1 and chains MSVCExceptionDestructor (0x59BFA0).
- `0x0059AE7D` **LogicErrorExceptionObject** — std::logic_error exception-object copy constructor: installs the SEH frame, reads the source pointer from this+0x8, allocates and copies the source string via StrlenAllocCopyConstructorPattern, transfers the source flag byte from source+0xC into the new object at +0xC, drops the reference on the new object's string buffer, rebuilds it via sub_59A9CA over the full subrange and installs the std::logic_error vtable (0x5B9D7C). Called by CThrowWithException_ae07, VTableConstructor and ObjectInitWithVTable_b038.
- `0x0059AEDA` **LogicErrorExceptionObject** — SEH-guarded destructor wrapper for a std::logic_error exception object: sets up the SEH frame (landing pad 0x0059D59C), resets the vtable to std::logic_error (0x5B9D7C), releases the internal string buffer via ReferenceCountDecrementWithConditionalFree(v1+3, 1), toggles the frame guard flag from 0 to -1 and chains MSVCExceptionDestructor (0x59BFA0).
- `0x0059AFC2` **LogicErrorExceptionObject** — SEH-guarded destructor wrapper for a std::logic_error exception object: sets up the SEH frame (landing pad 0x0059D5C4), resets the vtable to std::logic_error (0x5B9D7C), releases the internal string buffer via ReferenceCountDecrementWithConditionalFree(v1+3, 1), toggles the frame guard flag from 0 to -1 and chains MSVCExceptionDestructor (0x59BFA0).

## Proposed classes

### LocaleIosStreamBase

Shared multi-inheritance vtable-chain construction for the locale stream objects. A guard field at this+0xC gates the base/basic_ios chain; the derived stream vtable (basic_ostream 0x5B9C48, basic_istream 0x5B9C40) is then written at this + *(*(this)+4) (the vtable-adjustment offset) and sub_59A8FA completes the adjusted subobject. Both constructors share the identical MSVC pattern and differ only in the base vtable (0x5B9C54 ostream / 0x5B9C5C locale-istream) and the cleared dword slot (v3[10] / v3[11]).

Methods: `0x00599B86`, `0x00599C58`

- `this+0x0000000C` `byte vtable_chain_guard` (read, DERIVED)

### LocaleStreambuf

Locale streambuf-family constructor. Acquires references on two locale subobjects (DWORD words 13 and 19), installs the basic_streambuf vtable (0x5B9CA0), initializes the self-referential pointer ring via sub_59A4C9, installs the final locale-storage vtable off_5B9C68 and passes the this+0x8 buffer argument into ObjectInitWithBufferDataPointerAssignment. The construction-state frame byte a1-4 steps 0/1/2 for MSVC EH partial-construction unwinding.

Methods: `0x00599CB7`

- `this+0x00000008` `pointer buffer_arg` (read, GUESS)

### FormattedInputReader

Formatted input reader holding a stream pointer (+0x50), a buffer object (+0x44) and the current result pointer (+0x40). Runs a staged read pipeline (file-I/O forwarding sub_59BAE8, optional filter sub_587F64, masked string-stream read sub_58801D); on any failure builds a default result via sub_59942B and on success sets +0x40 and resets the buffer via BufferTruncationShrink, then copies the 0x18-byte result struct into the caller's output buffer.

Methods: `0x0059A221`

- `this+0x00000050` `pointer stream` (read, GUESS)
- `this+0x00000044` `pointer buffer_object` (read, GUESS)
- `this+0x00000040` `pointer result_buffer` (read_write, GUESS)

### CleanupCallbackRegistry

Thin cleanup/free callback registration shims. Both bodies (0x59A541, 0x59AD3D) are identical zero-argument wrappers that read the global stub EmptyStub_9796 (0x00599796) and forward it to BooleanToIntConversion (0x00587B3E). No object state is held; the class is a grouping of two binary-identical forwarding functions.

Methods: `0x0059A541`, `0x0059AD3D`


### RuntimeErrorExceptionObject

std::runtime_error exception-object lifecycle: initializer (0x59A69A) seeds the embedded string from byte_5EA438, copy constructor (0x59A781) copies the source object at this+0x8, and two cleanup copies (0x59A728, 0x59A7DE) reset the vtable to 0x5B9D28, release the embedded refcounted sub-object at v1+3 and chain MSVCExceptionDestructor. All four functions share the identical MSVC pattern with sub_59A9CA / ReferenceCountDecrementWithConditionalFree.

Methods: `0x0059A69A`, `0x0059A728`, `0x0059A781`, `0x0059A7DE`

- `this+0x00000008` `pointer source_ptr` (read, DERIVED)
- `*(this+0x8)+0x00000000` `byte source_first_byte` (read, GUESS)
- `*(this+0x8)+0x0000000C` `byte source_flag_byte` (read, GUESS)

### LogicErrorExceptionObject

std::logic_error exception-object lifecycle: initializer (0x59ADA3) seeds the embedded string from byte_5EA438, copy constructor (0x59AE7D) copies the source object at this+0x8, and three SEH-guarded destructor copies (0x59AE24, 0x59AEDA, 0x59AFC2) reset the vtable to 0x5B9D7C, release the embedded refcounted sub-object at v1+3 and chain MSVCExceptionDestructor. Structurally the same MSVC pattern as the runtime_error family; only the final vtable global differs.

Methods: `0x0059ADA3`, `0x0059AE24`, `0x0059AE7D`, `0x0059AEDA`, `0x0059AFC2`

- `this+0x00000008` `pointer source_ptr` (read, DERIVED)
- `*(this+0x8)+0x00000000` `byte source_first_byte` (read, GUESS)
- `*(this+0x8)+0x0000000C` `byte source_flag_byte` (read, GUESS)

### RefCountedObject

Object with a vtable pointer (off_5B9D3C installed on destruction) and a ref-count index at v1[9] (offset 0x24) into the global counter array byte_8D463C. Its destructor decrements the counter and triggers full cleanup via sub_59A980 at zero or null index, then null-checks and virtual-dispatches the pointer at this+0x20. Concrete type and layout beyond these slots are unknown.

Methods: `0x0059A86C`


### EncodingFacetSingleton

Lazily initialized locale encoding singleton cached in dword_8D4650 and reached from the locale refcount-acquire path (caller 0x00598C1C). On first use it allocates and constructs a 40-byte locale facet object, writes code page identifier 63 at object+16, copies the encoding-name string at dword_5B9D44 into object+24, links the singleton into dword_8D464C / dword_8D4648 and increments its reference count. The constructed object's concrete type is not evidenced.

Methods: `0x0059AAB9`


### LocaleFacetObject

std::locale::facet-derived object with a reference count at +0x4, a facet-pointer array region at +0x8 (count at +0xC) and an embedded refcounted string buffer at +0x18. The constructor installs the facet vtable (0x5B9D54), seeds the buffer from word_5C406C and overrides the vtable with off_5B9D4C; the teardown iterates the facet array releasing each facet (RefcountDecrementWithLock plus conditional destroy), frees the array, releases the buffer and restores the facet vtable. The this+0x8 slot doubles as a caller-argument byte in the constructor and the facet-array pointer in the teardown.

Methods: `0x0059ABCD`, `0x0059AC7F`

- `this+0x00000008` `pointer facet_array_or_arg` (read_write, GUESS)
- `this+0x0000000B` `byte flag_byte_arg` (read, GUESS)
- `this+0x0000000C` `int facet_count` (read, GUESS)

## Compatibility contracts

- **ExceptionObjectVtableContract** — Exception objects carry a std-family vtable at +0x0. Construction installs the std::runtime_error vtable (0x5B9D28) or the std::logic_error vtable (0x5B9D7C); teardown resets the vtable to the same identity before releasing the embedded refcounted sub-object at +0xC (via ReferenceCountDecrementWithConditionalFree with free flag 1) and chaining MSVCExceptionDestructor (0x59BFA0). A replacement executable must preserve both distinct vtable identities and the teardown ordering.
- **StreamMultiInheritanceVtableContract** — The ostream/istream locale objects use a multi-inheritance vtable layout: the base vtable pointer sits at +0x0 (0x5B9C54 ostream base / 0x5B9C5C locale base), the basic_ios vftable (0x5B9C50) occupies the second slot, and the derived stream vftable (basic_ostream 0x5B9C48 / basic_istream 0x5B9C40) is written at this + *(*(this)+4), where the value read from the vtable is the multi-inheritance vtable-adjustment offset; sub_59A8FA then completes the adjusted subobject. A replacement must preserve this chain layout and the guard semantics of the field at +0xC.
- **EncodingFacetSingletonContract** — The locale encoding singleton is cached in dword_8D4650, linked into dword_8D464C and dword_8D4648, and observable as a 40-byte object holding code page identifier 63 at +16 and the encoding-name string (from dword_5B9D44) at +24, with its reference count incremented thread-safely. The singleton is created on first use from the locale refcount-acquire path (caller 0x00598C1C).
- **FormattedInputResultContract** — Formatted input produces a 0x18-byte result struct copied into the caller's output buffer a2. The result is assembled from the masked string-stream read output (v15/v16), this[16] (+0x40) and a status field cleared to 0; on any pipeline failure a default/fallback result is built by sub_59942B(&a3, -1). A replacement must preserve the 0x18-byte result layout and the fallback-on-failure semantics.

## Unresolved

- Ownership is UNKNOWN at the function-IR level for every function in this packet; the class grouping is a DERIVED/GUESS proposal, not a confirmed identity.
- Global dword_5B9C38 (SetupConstantValue) is flagged as read by 0x59A221, 0x59A69A, 0x59A781, 0x59ADA3 and 0x59AE7D but never appears in their raw decompiled bodies; its role (likely a setup constant for one of the callees) is unplaceable from this packet.
- SEH continuation 0x0059D537 (teardown 0x59AC7F) and SEH landing pad 0x0059D588 (copy constructor 0x59AE7D) are packet-listed globals whose unwind-time role is not evidenced.
- The two locale subobject offsets in 0x599CB7 (DWORD words 13 and 19) are derived from the raw source text only; the packet types no field for them.
- The guard field at this+0xC is read as a re-init gate by the stream constructors (0x599B86, 0x599C58) and as a facet count by the teardown (0x59AC7F); whether these are the same semantic field across different objects is unproven.
- The construction-state frame byte a1-4 stepped 0/1/2 in 0x599CB7 (and the 0/-1 guard toggles in the exception destructors) is inferred from MSVC SEH partial-construction conventions, not documented.
- The this+0x8 slot in LocaleFacetObject is a caller-argument byte in the constructor but the facet-array pointer in the teardown; the union interpretation is DERIVED from the teardown's raw dword indices (v2[2], v2[3]) and not independently confirmed.
- sub_59A9CA argument semantics (the 0 and -1 / 0xFFFFFFFF literals) depend on its callee, which is outside this packet.
- sub_59A8FA (SubobjectCompleter) and its exact contract for completing the vtable-adjusted stream subobject are unresolved.
- RefcountDecrementWithLock (0x598C88) is listed as a callee of 0x59AAB9 but absent from its raw body; it is presumed to belong to the SEH unwind/refcount-release path on failed construction.
- The 'if (&dword_8D4648)' test in 0x59AAB9 always evaluates true since it takes the address of a global; its intent is not evidenced.
- v3 (the new exception object pointer) is uninitialized in the decompiler output of 0x59A781 / 0x59AE7D; the allocation happens outside the function.
- The nature of EmptyStub_9796 (0x00599796) - callable address or plain data - is not resolved; it is passed as an integer to BooleanToIntConversion.
- The relationship in 0x59A86C between the object's ref-count index v1[9] (+0x24) and the global counter array byte_8D463C, and the purpose of the null-checked virtual dispatch on this+0x20, are unresolved.
- 0x59A541 and 0x59AD3D are byte-identical wrapper bodies with no caller evidence in this packet; the objects whose cleanup they register are unknown.
- The frame slots (a1-16, a1-20, a1-4) consumed by the SEH landing pads in the exception constructors/destructors are inferred from MSVC conventions, not proven.
