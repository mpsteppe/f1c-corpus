# Cruntime

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

This subsystem groups CRT-runtime helpers that the validated IR shows as free functions over global state rather than members of an engine object: FPU exception handling and double exponent manipulation (HandleFpuException, SetDoubleExponent, FrexpLike), FPU status word access, command-line setup and tokenization, CRT private-heap selection and sub-allocator initialization (msvcrt heap and a slab/buddy allocator), the structured/C++ exception dispatch path (filter, scope-table unwind, catch-handler dispatch, exception-record validation), a DST transition-date calculator, and a small bit-array helper. All class identity is DERIVED or GUESS; every class here is a synthesis over packet-proven call links and shared globals, not a recovered C++ type. Function boundaries and control flow are well evidenced; object ownership was UNKNOWN for every function in the packet.

## Function roles

- `0x0059070A` **CruntimeFloatingPoint** — CRT floating-point exception handler: classifies the FPU status byte (underflow/overflow/precision), rescales with __FSCALE__ and threshold clamps, records a status code, forwards exception arguments, and dispatches the math error callback.
- `0x00591CA1` **CruntimeFloatingPoint** — Linear search over an 8-byte ID/value constant table returning a pointer to the value DWORD of the matching entry, or NULL at table end.
- `0x00591D05` **CruntimeFloatingPoint** — Rebuilds a double's exponent field by bit manipulation, preserving sign and low mantissa bits while replacing the 11-bit exponent from the argument.
- `0x00591D88` **CruntimeFloatingPoint** — Frexp-style double splitter: writes the base-2 exponent into the caller slot and returns the normalized mantissa, handling zero, subnormals and normals.
- `0x00591E49` **CruntimeFloatingPoint** — Identity pass-through of the 16-bit FPU status word; no transformation occurs.
- `0x00591E57` **CruntimeFloatingPoint** — Reads the 16-bit FPU status word and clears pending FPU exceptions (fnclex), returning the previously captured status word.
- `0x00591E89` **CruntimeFloatingPoint** — Empty no-op stub (void body); statically references two read-only tbyte globals that never appear in the recovered body.
- `0x00592647` **CruntimeCalendar** — Computes DST start/end transition dates from a weekday rule or a fixed-date rule and stores them with millisecond time-of-day into the DST globals, normalizing across the 86400000 ms day boundary.
- `0x00592924` **CruntimeExceptionHandling** — CRT structured-exception filter: searches TLS handler records, maps MSVC exception codes to signal numbers 129-134/138, dispatches handlers, and returns 1 (handled), -1 (continue) or UnhandledExceptionFilter.
- `0x00592A9C` **CruntimeCommandLine** — Lazy-initializes the CRT command-line singleton and returns a pointer past the leading executable-name token (quoted or unquoted), trimmed of whitespace.
- `0x00592C46` **CruntimeCommandLine** — Tokenizes a command-line style string into a flattened argument buffer and an argv-style pointer array with quote (34), backslash escape (92) and whitespace handling, using the character-class table.
- `0x00593115` **CruntimeHeap** — Selects the CRT heap implementation at runtime from OS version, __MSVCRT_HEAP_SELECT/__GLOBAL_HEAP_SELECTED environment variables, and PE linker version fallback, returning the heap type code 1/2/3.
- `0x0059325D` **CruntimeHeap** — Creates the CRT private heap via HeapCreate, stores the selected heap type code, and initializes the matching sub-allocator (msvcrt heap for type 3, slab/buddy for type 2).
- `0x00593446` **CruntimeExceptionHandling** — C++ exception handler dispatch: validates the scope-table magic 0x19930520, branches between SEH-aware dispatch and direct MSVC C++ exception handling, and invokes the handler-table function pointer when present.
- `0x0059379B` **CruntimeExceptionHandling** — Scope-table iteration (unwind) loop from the current try level to a target index, bounds-checking against the table size and invoking cleanup/destructor handlers through sub_593C50.
- `0x005938B4` **CruntimeExceptionHandling** — SEH/C++-exception wrapper that saves and restores TLS slots 27/28 around a wrapped CRT dispatch, validates the C++ exception record, and re-dispatches through SEHWrappedRenderDispatchCall.
- `0x005939CF` **CruntimeExceptionHandling** — Validates a double-indirected pointer as a well-formed C++ exception record header: code 0xE06D7363, NumberParameters 3, magic 0x19930520, and no nested continuation.
- `0x00593BBD` **CruntimeExceptionHandling** — SEH-frame catch-handler dispatch: loads a handler pointer from the handler table behind the exception record and invokes it through the atomic lock/unlock wrapper.
- `0x00593C24` **CruntimeExceptionHandling** — Computes an adjusted frame offset for SEH exception-handler dispatch from a descriptor triple (offset, conditional sub-offset, table index).
- `0x00593DD3` **CruntimeHeap** — Initializes the msvcrt CRT heap sub-allocator: allocates a 320-byte control block, resets free-list/block counters, stores the maximum allocation size and the initial realloc capacity.
- `0x00594478` **SlabHeapAllocator** — Allocates and initializes a new 1MB slab for the custom heap, growing the slab descriptor array when full, and returns the descriptor pointer.
- `0x00594529` **SlabHeapAllocator** — Initializes a newly committed 32KB slab for first use: free-list heads, block-header sentinels, free-list linking, bitmap entries, and size-class bitmask update.
- `0x00594A5E` **SlabHeapAllocator** — Destroys a slab/buddy allocator context: releases the arena, advances the list head, and either resets the static-pool marker or unlinks and frees the context node.
- `0x00594E1A` **SlabHeapAllocator** — Carves a block of a3 bytes from a slab, first via the cursor fast path and then by scanning for a contiguous free run, returning the encoded block handle 16*(block+8)-15*a1.
- `0x005951BE` **CruntimeBitArray** — Tests a 3-DWORD bit array for clear bits from a start index, splitting the index into a DWORD position and an intra-word mask.

## Proposed classes

### CruntimeFloatingPoint

CRT floating-point support: FPU exception classification and rescaling, double exponent manipulation, frexp-style splitting, FPU status-word access, and a constant ID/value table lookup. Grouped by the packet-proven FrexpLike-to-SetDoubleExponent call and shared callers, not by a recovered C++ type.

Methods: `0x0059070A`, `0x00591CA1`, `0x00591D05`, `0x00591D88`, `0x00591E49`, `0x00591E57`, `0x00591E89`


### CruntimeCommandLine

CRT command-line setup and tokenization: skipping the executable-name token and parsing a command line into an argv-style array with quote, backslash and whitespace handling.

Methods: `0x00592A9C`, `0x00592C46`


### CruntimeCalendar

DST transition-date computation: weekday and fixed-date rule evaluation plus millisecond time-of-day normalization against the global DST state.

Methods: `0x00592647`


### CruntimeExceptionHandling

CRT structured and C++ exception dispatch: TLS handler-record filter with exception-code-to-signal mapping, scope-table magic validation and unwind, handler-table dispatch, and exception-record validation. Membership is backed by direct packet-proven call links.

Methods: `0x00592924`, `0x00593446`, `0x0059379B`, `0x005938B4`, `0x005939CF`, `0x00593BBD`, `0x00593C24`

- `this+0x00000000` `uint32 exceptionCode` (read, DERIVED)
- `this+0x00000004` `uint32 exceptionFlags` (read, DERIVED)
- `this+0x00000008` `int32 currentTryLevel` (read_write, DERIVED)
- `this+0x00000010` `uint32 numberParameters` (read, GUESS)
- `this+0x00000014` `uint32 exceptionInformation0` (read, DERIVED)
- `this+0x00000018` `uint32 handlerContext` (read, GUESS)
- `this+0x0000001C` `uint32 handlerTablePtr` (read, DERIVED)
- `*(this+0x1C)+0x00000004` `uint32 catchHandler` (read, GUESS)
- `*(this+0x1C)+0x00000008` `uint32 destructorHandler` (read, GUESS)

### CruntimeHeap

CRT heap management: runtime heap-type selection, private heap creation, and initialization of the selected sub-allocator (msvcrt heap). Membership is backed by the packet-proven CRTHeapAndAllocatorInit-to-CRTHeapSelect and -to-MsvcrtHeapInit calls.

Methods: `0x00593115`, `0x0059325D`, `0x00593DD3`


### SlabHeapAllocator

Custom slab/buddy heap sub-allocator: new-slab allocation with descriptor-array growth, first-use slab initialization (free lists, bitmaps, size-class state), block carving, and context destruction. Field layout is partially mapped and internally inconsistent across the four functions (see unresolved).

Methods: `0x00594478`, `0x00594529`, `0x00594A5E`, `0x00594E1A`

- `this+0x00000004` `uint32 stateFlags` (read_write, GUESS)
- `this+0x00000008` `uint32 freeBlockBitmask` (read_write, GUESS)
- `this+0x0000000C` `uint32 slabBase` (read, GUESS)
- `this+0x00000010` `uint32 metadataPtr` (read, GUESS)
- `this+0x00000053` `uint8 sizeClassRefCount` (read_write, GUESS)
- `obj+0x00000000` `uint8 blockSizeHeader` (read_write, GUESS)
- `obj+0x00000001` `uint8 firstPayloadByte` (read, GUESS)

### CruntimeBitArray

Bit-array helper testing whether a bit range is clear across a 96-bit (3-DWORD) array; the 3-DWORD width and the caller contract are inferred.

Methods: `0x005951BE`


## Compatibility contracts

- **CrtFloatingPointExceptionContract** — A replacement executable must preserve FP exception classification (status -1 underflow / -2 overflow / 8 precision), __FSCALE__ rescaling with the 1536.0 / -1536.0 constants, denormal and max-double threshold clamps, the enable/disable gate on the math-error flag, and dispatch of the math error callback when the handler is active.
- **CrtCommandLineParsingContract** — Command-line processing must skip the leading executable token (quoted or unquoted), trim leading whitespace, and tokenize a command line into an argv-style array handling double quotes (34), backslash escapes (92), space/tab delimiters (32/9), and the character-class table bit semantics.
- **CrtHeapSelectionContract** — A replacement must create the CRT private heap (handle stored at 0x008D4904), select the heap type code 1/2/3 stored at 0x008D4908 from OS version, __MSVCRT_HEAP_SELECT / __GLOBAL_HEAP_SELECTED environment variables, and the PE linker version, and initialize the matching sub-allocator (msvcrt heap init or slab/buddy init).
- **CrtSehCppExceptionDispatchContract** — The SEH/C++ exception path must preserve the MSVC C++ exception signature (code 0xE06D7363, magic 0x19930520, NumberParameters 3), the TLS handler-record search, the exception-code-to-signal mapping (129-134 and 138) via TLS[22], the scope-table unwind loop, and the handler table behind exception record +0x1C, with CrtExceptionFilter returning 1 (handled) or -1 (continue search).
- **SlabHeapDataLayoutContract** — A replacement of the slab/buddy allocator must reproduce the observed data layout: 1MB slabs via VirtualAlloc, 20-byte descriptors in the array at 0x008D48FC (capacity 0x008D48E8, count 0x008D48F8), 0x41C4-byte bitmap blocks, 64 free-list heads per size class, one-byte block-size headers, and the encoded block handle 16*(block+8)-15*a1. Layout details beyond these are unresolved.
- **CrtDstTransitionDateContract** — DST transition dates must be computed for the weekday rule (a2 == 1) and the fixed-date rule, with results stored into the start globals (year/day at 0x005E77F0/0x005E77F4, time at 0x005E77F8) and the end globals (year/day at 0x005E7800/0x005E7804, time at 0x005E7808), including the 86400000 ms day-boundary rollover that adjusts the stored day by one.

## Unresolved

- HandleFpuException: which of the six FP constant globals (0x005B94E0..0x005B9508) holds each literal (1536.0, -1536.0, thresholds) is DERIVED, not individually proven; the identity of the math error callback sub_596175 and the meaning of the forwarded exception-argument DWORDs are not established.
- HandleFpuException: the field:this refs (this+0x8/+0xC/+0x10/+0x14) are __usercall frame slots, not an object structure.
- IDToValueTableLookupInConstantTable: meaning of the ID/value pairs in the constant table at 0x005E7640 and the consumer of the returned value pointer are not established.
- SetDoubleExponent: the scaling interpretation (true binary exponent becomes a2-1) is DERIVED from the bit layout; the purpose of call site 0x00591D88 is unknown; the legacy ABI name is not runtime-confirmed.
- FrexpLike: the read-only global dbl_5B8CC8 is statically referenced but does not appear in the recovered raw source; its role is unknown.
- ShortComputation_1e49 / FPUStatusWordRead: the fnstsw/fnstcw provenance of the 16-bit status word is outside the recovered bodies; why caller 0x00591727 routes through an identity stub is unknown.
- EmptyStub_1e89: empty body; the tbyte globals 0x005E7740 and 0x005E774C are statically referenced but never read in the recovered body.
- CommandLineSkipExecutableName: exact single-character behavior of ThreeArgCallWrapper is unknown; whether dword_8D5A44 points into a static buffer or a heap copy is unresolved; the caller's use of the returned pointer is not established.
- CommandLineTokenParser: byte_8D47E1 bit-4 semantics are inferred from usage; the argv contract of caller 0x00592BAD is outside the packet; this+0x0/this+0x1 are input-cursor facts, not struct fields.
- CRTHeapSelect: the PE-header globals 0xFF00000000005370 (written) and 0xFF00000000005371/0xFF00000000005374 (read) are not in the raw decompiled source; the byte-vs-major-version mapping is DERIVED; CallWrapperWith0's heap-implementation mapping and several unnamed callees are unknown.
- CRTHeapAndAllocatorInit: the exact meaning of the heap type codes 1, 2 and 3 beyond the packet's control flow is not established.
- CppExceptionHandlerDispatch: the scope-table layout (magic at a5[0], flags at a5[1]/a5[3]) is inferred from the checks, not packet-confirmed; the role of sub_5934E1 in cleanup is unknown.
- SEHAwareVirtualCallDispatchLoop: the scope-table unwind interpretation is DERIVED; the flag literal 259 passed to sub_593C50 is unexplained; the compiler SEH TEB globals cannot be tied to explicit operations from the raw source.
- SEHWrapperAroundCRTFunctionCall: the role of the dword preceding a2 (a2-4) is unknown beyond save/restore; the TLS byte globals 0xFF0000000000169x are unaccounted for in the raw body.
- SEHWrappedRenderDispatchCall: the exact handler-table layout behind record+0x1C is inferred; the meaning of the handler-context value at +0x18 depends on the caller's catch-handler convention.
- SEHFrameOffsetCalculationHelper: the structure of descriptor a2 (offset/sub-offset/table-index) and the meaning of the double-indirect read are not evidenced; caller 0x005939F9's use of the result is unknown.
- CrtExceptionFilter: the seven exception codes appear only as negative decimal literals; the TLS[20]/TLS[21]/TLS[22] slots and the 12-byte handler-state entry layout have no field facts; dword_5E7888/dword_5E788C roles as exception-entry and handler counts are DERIVED, not proven.
- MsvcrtHeapInit: the named roles (free-list count, block counter, cursor, max size, realloc capacity) for the dword_8D48xx globals are DERIVED from the init pattern, not independently proven.
- SlabHeapAllocateNewSlab: the 20-byte descriptor layout and the semantics of the 0x41C4-byte bitmap are inferred from surrounding allocations; import stubs (VirtualAlloc, HeapReAlloc, HeapFree, HeapAlloc) are treated as read-only globals by packet facts.
- SlabHeapInitBitmapAndFreeLists: semantics of the two bitmap entries at descriptor+68 and descriptor+196 are inferred; the 516-byte descriptor row layout is only partially mapped; the slab address encoding (v3 << 15) is unconfirmed.
- SlabBuddyAllocatorDestroy: the allocator type is unknown; the obj-vs-this double-list-base pattern leaves unclear which structure owns the arena and which owns the neighbor nodes; the static sentinel off_5E7968 and the marker dword_5E7978 are inferred from the branch shape.
- SlabSubAllocatorCarveBlock: the return encoding 16*(block+8)-15*a1 is an opaque handle; the capacity budget a2 and the a1+248 slab-end bound are not fully explained; one-byte size headers cap blocks at 255 bytes.
- CheckIfBitRangeIsClearAcrossDwords: the literal mask ~(-1 << (31 - a2%32)) tests the LOW bits of the starting DWORD while the ABI name suggests a from-bit-position high-range check; whether this is a real quirk or the check is meant to cover a different range is unresolved; the 3-DWORD width is inferred.
- CONTRADICTION: slab functions access distinct layouts at overlapping this offsets. SlabHeapInitBitmapAndFreeLists treats this+0x4 as a state-flags byte and this+0x10 as a descriptor-array pointer, while SlabBuddyAllocatorDestroy treats this+0x4 as the next list node and this+0x10 as the arena base, and SlabSubAllocatorCarveBlock treats this+0x0/this+0x4 as cursor/remaining bytes. Same base plus byte offset, conflicting field identity; allocator-context versus slab-descriptor common ownership is not proven.
- CONTRADICTION: the exception record is accessed via base this in the dispatchers (0x00593446, 0x005938B4, 0x00593BBD) and via base obj in FileMagicNumberValidator at the same offsets (0x0/0x10/0x14/0x1C) with the same magic checks; common ownership is strongly implied by identical checks and offsets but not packet-proven, so the two bases are not merged into one field set.
- Class groupings (CruntimeFloatingPoint, CruntimeCommandLine, CruntimeCalendar, SlabHeapAllocator, CruntimeBitArray) are synthesis over packet-proven call links and shared globals; no runtime confirmation exists and no packet evidence names a concrete C++ type.
