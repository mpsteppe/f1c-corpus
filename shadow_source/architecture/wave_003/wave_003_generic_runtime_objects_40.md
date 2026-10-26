# RuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

A heterogeneous set of generic runtime facilities: a shutdown-time mutex-guarded dual-queue drain, six callback-registration stubs delegating to a shared conversion helper, a FILE-layout CRT stream family (close/seek/tell/buffered write), a critical-section-guarded buffered stream primitive family, string and FPU number helpers, a network session parameter configurator, allocation/free dispatch, and CRT error-code mapping.

## Function roles

- `0x00585130` **LockedQueueListOwner** — Drain two mutex-guarded item queues at shutdown: pop-and-dispatch items via vtable slot 0x5C, then drain an embedded singly-linked list under the mutex at this+0x58C with SEH-guarded payload cleanup, releasing the mutex on return.
- `0x00585E60` **CallbackRegistrationDispatcher** — Registration thunk: passes the address of a cleanup routine (sub_585E70) to the shared BooleanToIntConversion helper and returns its integer result.
- `0x00586700` **RenderStateBitmapAllocator** — Seeded init registering five bitmap-allocation tracker entries on member offsets 52..68 of this and finalizing bitmap fields; returns this.
- `0x00586F70` **BitfieldEncoder** — Set or clear a single bit (a2) in the byte array whose base is at this[0]; a3 selects set vs clear; returns the resulting mask byte.
- `0x00586FA0` **BitfieldEncoder** — Encode a run of bits into the buffer at *this using a run descriptor from the array at this+0x8, masked by the caller mask a3; returns 1 on success.
- `0x005871F0` **SharedConfigFieldReader** — Trivial side-effect-free getter returning the dword at byte offset 0x14 of this.
- `0x00587400` **CallbackRegistrationDispatcher** — Registration thunk: passes the address of a static-init routine (sub_587410) to the shared BooleanToIntConversion helper.
- `0x00587440` **CallbackRegistrationDispatcher** — Registration thunk: passes the address of a cleanup routine (sub_587450) to the shared BooleanToIntConversion helper.
- `0x00587690` **CallbackRegistrationDispatcher** — Registration thunk: passes the address of a free-callback routine (sub_5876A0) to the shared BooleanToIntConversion helper.
- `0x005876D0` **CallbackRegistrationDispatcher** — Registration thunk: passes the address of a cleanup routine (sub_5876E0) to the shared BooleanToIntConversion helper.
- `0x00587A60` **CallbackRegistrationDispatcher** — Registration thunk: passes the address of a free-callback routine (sub_587A70) to the shared BooleanToIntConversion helper.
- `0x00587D33` **CrtFileStream** — CRT file close: flush buffered writes, release the stream lock, close the OS handle at +0x10, free the internal buffer at +0x1C, and unconditionally reset the state flags at +0xC.
- `0x00587D7F` **LockedStreamBuffer** — Lock-guarded delegation wrapper: acquire a critical-section state, run the stream operation sub_58C43C while held, release the lock, and return its result.
- `0x00587F90` **CrtFileStream** — CRT seek/tell: validate open state (flags bit 0x83) and seek mode, clear flag bit 0x10, flush, perform the OS seek on the handle at +0x10, and map the result to 0/-1; sets errno 22 on the invalid path.
- `0x005881C0` **StackProbeHelper** — MSVC CRT stack probe (_alloca_probe): walk the stack pointer down in 4096-byte strides touching each page while the allocation size is >= 0x1000, returning via the bare retn pushed by the alloca call site.
- `0x0058850F` **DoubleParseHelper** — Locale-aware string-to-double parser: skip leading whitespace using the character-type table or encoding fallback, call Strlen, then delegate to EncodingLocaleDetectionFromParseResult and return the double at parse-result offset 16.
- `0x005886A7` **CrtFileStream** — Buffered file write over a stream context: block-size selection (default 4096), internal buffer drain, byte alignment, flush, and direct raw-write fallback on the handle at +0x16; sets the 0x20 error flag on failure and returns the fully-written element count.
- `0x005887ED` **VariadicStringFormatHelper** — Variadic wrapper that packs a local argument descriptor with the raw pointer a1, its Strlen length, a1 again, and constant 73, then delegates format/argument handling to sub_58E4D2.
- `0x00588A34` **NetworkSessionParameterConfigurator** — Network session parameter configuration: indexed accessor for session 1..5, LC_-prefixed key=value config-string parsing against a parameter table, or generic tokenized config against the existing session array, all serialized under critical section 19.
- `0x005895A2` **FpuNumberHelper** — FPU helper: classify NaN/Inf inputs by exponent field and payload class, dispatching to math-error or conditional-math paths, and apply MSVC CRTR rounding to normal numbers while saving/restoring the FPU control word.
- `0x0058986E` **FileDeleteHelper** — Delete a file via DeleteFileA and normalize the result to 0 (success) or -1 (failure), capturing GetLastError and dispatching the failure code through the error lookup handler.
- `0x00589898` **LockedStreamBuffer** — Buffered single-character write: decrement the capacity counter at a2[1], take the overflow path through sub_58CF35 when it goes negative, otherwise store the byte at the cursor a2[0], all under a critical-section lock.
- `0x00589A35` **LocaleCharacterNormalizer** — Character uppercase conversion: locale-aware thread-safe path with interlocked ref-counting and optional critical section, or a simple ASCII path subtracting 32 for 'a'..'z'.
- `0x0058A163` **LockedStreamBuffer** — Critical-section-guarded stream write wrapper: acquire the buffer lock, read a flag, perform the write via sub_58D04D, conditionally clear struct fields, release the lock, and return the write result.
- `0x0058A935` **MemoryAllocatorDispatcher** — Single-line allocation wrapper forwarding the requested size plus the global allocation context dword_8D41B0 to NhMalloc.
- `0x0058AA6F` **MemoryAllocatorDispatcher** — NULL-safe deallocation dispatcher: OS-version discriminator selects pool-free (3) or validation (2) paths under critical section 9, with a HeapFree fallback when no owning allocation is reported.
- `0x0058AD08` **CrtFileStream** — CRT stream logical position / remaining-bytes calculator: query the physical file size, clamp the buffered position, adjust for text-mode newline expansion via the per-handle text-mode descriptor, and set errno 22 on invalid mode flags.
- `0x0058AF5C` **CrtErrorLookupTable** — CRT error-code mapper: store the OS code into the _doserrno TLS slot, scan the DWORD-pair error table, and apply range fallbacks to errno 13/8/22.

## Proposed classes

### CrtFileStream

MSVC CRT FILE-layout buffered stream object: close, seek/tell, position query, and buffered block writes over the OS handle at +0x10, with state flags at +0xC and internal buffer at +0x0.

Methods: `0x00587D33`, `0x00587F90`, `0x0058AD08`, `0x005886A7`

- `this+0x00000000` `unsigned char* bufferEnd` (read_write, DERIVED)
- `this+0x00000004` `int bufferedPosition` (read_write, DERIVED)
- `this+0x00000008` `unsigned char* readPtr` (read, DERIVED)
- `this+0x0000000C` `unsigned int flags` (read_write, DERIVED)
- `this+0x0000000D` `unsigned char flagLowByte` (read, GUESS)
- `this+0x00000010` `HANDLE osHandle` (read_write, DERIVED)
- `this+0x00000018` `unsigned int bufferSize` (read, DERIVED)
- `this+0x0000001C` `void* bufferToFree` (write, DERIVED)
- `*(this+0x8)+0x00000000` `unsigned char readPtrByte` (read, GUESS)

### LockedStreamBuffer

Critical-section-guarded buffered stream primitive family: single-byte buffered writes with overflow handling, locked write wrappers, and lock-guarded delegation over a shared buffer-control object.

Methods: `0x00589898`, `0x0058A163`, `0x00587D7F`


### LockedQueueListOwner

Owner object holding an embedded singly-linked node list (head/tail/iterator/count at +0x57C..+0x588) guarded by a mutex handle at +0x58C with timeout at +0x590; drains queued items during shutdown, dispatching each via its vtable slot at offset 0x5C and releasing the mutex on return.

Methods: `0x00585130`

- `this+0x00000000` `void** vtable` (read, GUESS)
- `obj+0x0000005C` `void* queueDispatchMethod` (read, GUESS)
- `this+0x0000057C` `void* listHead` (read_write, DERIVED)
- `this+0x00000580` `void* listTail` (read_write, DERIVED)
- `this+0x00000584` `void* listIterator` (read_write, DERIVED)
- `this+0x00000588` `int listCount` (read_write, DERIVED)
- `this+0x0000058C` `HANDLE mutexHandle` (read_write, DERIVED)
- `this+0x00000590` `unsigned int mutexTimeout` (read, DERIVED)
- `*(this+0x57C)+0x00000000` `void* nodeData` (read_write, GUESS)
- `*(this+0x57C)+0x00000004` `void* nodeNext` (read_write, GUESS)
- `*(this+0x57C)+0x00000008` `unsigned char nodeFlagByte` (read, GUESS)
- `*(this+0x57C)+0x0000000C` `int nodeCount` (read_write, GUESS)

### CallbackRegistrationDispatcher

Family of registration stubs that cast a routine code address to int and delegate registration to the shared BooleanToIntConversion helper; the routines being registered (cleanup, static-init, free-callback) are opaque to this family.

Methods: `0x00585E60`, `0x00587400`, `0x00587440`, `0x00587690`, `0x005876D0`, `0x00587A60`


### RenderStateBitmapAllocator

Seeded initialization for a render-state object that registers bitmap-allocation tracker entries on member offsets 52..68 with mode flags and finalizes bitmap fields; the field layout behind those offsets is not evidenced.

Methods: `0x00586700`


### BitfieldEncoder

Bitfield utilities over a byte array: single-bit set/clear and multi-bit run encoding driven by a run-descriptor array.

Methods: `0x00586F70`, `0x00586FA0`

- `this+0x00000000` `unsigned char* byteArrayBase` (read, DERIVED)
- `this+0x00000008` `unsigned short* runDescriptorArray` (read, DERIVED)

### SharedConfigFieldReader

Trivial getter for the dword at offset 0x14 of an unidentified object read across AI, network, sound and game-filter paths; only the offset is evidenced, the owning type and field meaning are unknown.

Methods: `0x005871F0`

- `this+0x00000014` `int unknownValue` (read, GUESS)

### StackProbeHelper

MSVC CRT _alloca_probe: touches 4096-byte stack strides so OS guard pages fire during large-frame growth, returning via the bare retn pushed by the alloca call site.

Methods: `0x005881C0`


### DoubleParseHelper

Locale-aware string-to-double parsing: whitespace skip with encoding-aware character classification, Strlen, then locale parse-result extraction.

Methods: `0x0058850F`

- `this+0x00000000` `const char* inputString` (read, DERIVED)

### VariadicStringFormatHelper

Variadic wrapper that packs a pointer/length descriptor and a constant, delegating format and argument handling to sub_58E4D2.

Methods: `0x005887ED`


### NetworkSessionParameterConfigurator

Network session parameter configuration: indexed accessor for session 1..5, LC_-prefixed key=value config-string parsing against a parameter table, or generic tokenized config against the existing session array, serialized under critical section 19.

Methods: `0x00588A34`


### FpuNumberHelper

FPU numeric helper: NaN/Inf classification and dispatch plus normal-number rounding while preserving the FPU control word.

Methods: `0x005895A2`


### FileDeleteHelper

Win32 file-deletion wrapper normalizing DeleteFileA results to 0 (success) / -1 (failure) with GetLastError capture and error lookup dispatch.

Methods: `0x0058986E`


### LocaleCharacterNormalizer

Character uppercase conversion: locale-aware thread-safe path with interlocked ref-counting and optional critical section, or a fast ASCII path.

Methods: `0x00589A35`


### MemoryAllocatorDispatcher

Central allocation entry points: sized allocation forwarded to NhMalloc with the allocation-context global, and NULL-safe deallocation dispatched by an OS-version discriminator with a HeapFree fallback.

Methods: `0x0058A935`, `0x0058AA6F`


### CrtErrorLookupTable

CRT error-code mapper: stores doserrno, scans the DWORD-pair error table, applies range fallbacks to errno 13/8/22, and writes the mapped errno into the TLS slot.

Methods: `0x0058AF5C`


## Compatibility contracts

- **CrtFileStreamLayout** — Replacement must preserve the CRT FILE-layout stream object: buffer end at +0x0, buffered position at +0x4, read pointer at +0x8, state flags at +0xC (bits 0x83 open/writeable, 0x108 write-back, 0x10C buffered, 0x20 error), low flag byte at +0xD, OS handle at +0x10, buffer size at +0x18, freeable buffer pointer at +0x1C.
- **CrtErrnoMapping** — Error-code semantics: invalid stream operations set errno 22 (EINVAL); ErrorIDLookupTable stores the OS code in the _doserrno TLS slot and maps it with range fallbacks 0x13..0x24 -> errno 13, 0xBC..0xCA -> errno 8, otherwise errno 22.
- **MutexGuardedDrainSemantics** — The shutdown drain treats WaitForSingleObject results 0 (WAIT_OBJECT_0) and 128 (WAIT_ABANDONED) as access granted, and always releases the mutex at +0x58C on the return path when the handle is non-null.
- **SizedAllocationEntryPoints** — Allocation goes through MallocWrapperForNhMalloc(size) forwarding to NhMalloc(size, dword_8D41B0); deallocation through FreeMemoryDispatched dispatches on dword_8D4908 (3 = pool-free pair, 2 = heap-region validation) with a HeapFree(hHeap, 0, lpMem) fallback and a NULL-safe early return.

## Unresolved

- Identity and semantic target of the vtable method at offset 0x5C (+92) that DrainTwoListsWithMutexCleanup_B dispatches per drained queue item are unknown.
- The first-drain queue behind sub_584E30 is not structurally identified; the meaning of its nonzero return and of the popped value is unknown, and whether it shares the embedded list at this+0x57C is unresolved.
- The node payload layout (node[0] data, node[1] next, node+8 flag byte) is inferred from decompiler output and has no dedicated evidence references in the packet.
- The semantic role of SEHGuardedFunctionWithExceptionHandling (0x005867B0) on drained node payloads (cleanup callback vs notification) is unknown.
- Whether treating WaitForSingleObject result 128 (WAIT_ABANDONED) as access granted is intentional behavior is unconfirmed.
- The meaning of the bitmap-allocation mode flags 1, 8, 2, 16 passed to BitmapAllocationTracker, and the render-state field layout behind member offsets 52..68, are unknown.
- The consumer of BitSetClearOperation's branch-dependent returned mask (mask vs ~mask) is not identified.
- The meaning of the constant 73 and the exact descriptor layout consumed by sub_58E4D2 in the variadic formatting wrapper are unknown; whether a2 is a format string or an output buffer depends on the callee.
- The exact conditions under which the generic network-config parse path reaches the final sub_588D95 session initialization are inferred from goto-woven control flow, not proven.
- Semantics of the FPU dispatch constants 8 and 11, and of UtilityFunction_1d2e classification values beyond 1..2 vs 3, are unknown.
- The interlocked counter dword_8D5A5C and flag dword_8D5A58 (thread/critical-section bookkeeping) and the literal critical-section identifier 19 are inferred, not confirmed.
- The exact roles of the flag bits 0x108/0x10C/0x20, the 0x400/0x200 window logic, and the condition setting buffer size +0x18 to 512 in the stream paths are observed but semantically unconfirmed.
- The meaning of the allocation-context global dword_8D41B0 and the NhMalloc contract (alignment, failure behavior, ownership) are outside this packet.
- Semantics of the OS-version discriminator pair sub_593E1B/sub_593E46 and of MemoryRegionValidationHeapLookup/CounterThreshold are not evidenced by this packet.
- The meaning of field 0x14 read by SharedConfigFieldReader, and its owning object type, are unidentified.
- The object type of the LockedStreamBuffer control structure beyond the cursor a2[0] and capacity counter a2[1] is not evidenced.
