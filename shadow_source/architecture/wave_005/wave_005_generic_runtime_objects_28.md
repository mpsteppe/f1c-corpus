# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Wave 5 generic-runtime-objects packet 28 covers 21 free/member functions in five coherent clusters: (1) locale detection driven by EnumSystemLocalesA callbacks plus codepage-name resolution against a CPInfo-style object; (2) floating-point arithmetic helpers that consume FPU exception bits per control-word mask, restore the FPU control word around float parsing, and set TLS parse/range error codes; (3) local-time to timestamp conversion with a cached DST transition check; (4) CRT low-level file I/O (32 x 36-byte slot table init and per-index flush) and command-line argv parsing; (5) MSVC C++ exception dispatch (exception-record validation, type-descriptor matching, SEH guard-frame dispatch, copy-or-indirect-call helper, global callback dispatcher) plus a slab/buddy block allocator. All structure is proposed as DERIVED/GUESS from the validated IR; owner identity is unknown for every function and no CONFIRMED fact is asserted.

## Function roles

- `0x0058FFEC` **LocaleDetector** — Locale enumeration callback: parse the enumerated locale string, query region/language names, record the best-matching locale id and match-quality flags, stop once region+charset bits are satisfied.
- `0x005901F0` **LocaleDetector** — Locale detection initialization: compute language-string length/charset mode, enumerate system locales via EnumSystemLocalesA with callback sub_590246, clear validation flags.
- `0x00590303` **LocaleDetector** — Region detection initialization: record whether the region string is 3 characters long, enumerate system locales via EnumSystemLocalesA with callback sub_59033A, reset flags when bit 2 is clear.
- `0x005903DA` **CodepageInfoObject** — Resolve codepage/locale display name: extract it directly from a vtable-matching CPInfo object, or query the locale via the dword_8D3FB8 function pointer and extract the name from the result buffer.
- `0x0059045F` **LocaleDetector** — Locale identifier consistency check: query locale info for a masked id and pass when the buffer hex-parses back to the id, when the match flag is zero, or when the language string is not purely alphabetical.
- `0x005919DA` **FloatingPointArithmetic** — FPU exception handler: consume each pending exception bit against the FPU control-word mask, clamp underflow/overflow results, log handled exception types, return TRUE iff all masked bits consumed.
- `0x00591BF1` **FloatingPointArithmetic** — Float parsing wrapper: always restore the FPU control word, branch on a constant-table lookup, clear or set the error code from the input range, return the input double unchanged.
- `0x00591C79` **FloatingPointArithmetic** — Map an input integer to a TLS parse/range error code: input 1 -> 33, inputs 2..3 -> 34, else leave the TLS slot untouched.
- `0x00591CC6` **FloatingPointArithmetic** — Decode a flag byte into an index via priority-ordered bit tests (0x20->5, 0x08->1, 0x04->2, 0x01->3, else 2*(a1&0x02)).
- `0x00591EDF` **LocalTimeStruct** — Convert local date/time to a timestamp with DST adjustment, rejecting years outside 1970..2038 and lazily initializing timezone data.
- `0x0059249B` **LocalTimeStruct** — Daylight Saving Time membership decision for a timestamp, recomputing cached transition dates when the year changes and comparing day-of-year/time-of-day against cached bounds.
- `0x00592891` **CrtFileTable** — Flush file buffers for an open file identified by index: validate the index and slot active flag, enter the per-file critical section, flush via FlushFileBuffers, report failures through TLS slots.
- `0x00592BAD` **CrtCommandLineParser** — Parse the command line into an argv array: lazy CRT init, fetch the module file name, two-pass count/fill via sub_592C46, allocate via MallocWrapperForNhMalloc, store argc/argv globals.
- `0x00592F2C` **CrtFileTable** — Initialize the CRT low-level file-entry table: allocate 32x36-byte slot blocks, copy inherited handles from startup info, fill the first three slots from standard handles, return SetHandleCount.
- `0x005934E1` **CppExceptionRecord** — MSVC C++ exception handler dispatch: validate the exception record, unwind nested records from TLS, binary-search the scope table, dispatch to the matching catch handler.
- `0x0059373E` **CppTypeDescriptor** — Compare two C++ type descriptors: match type names via sub_58FB90 and apply qualifier-flag checks on leading bytes and the match-flag dword.
- `0x00593839` **CppExceptionDispatcher** — SEH-aware multi-argument dispatch wrapper: optional setup, unwind through target or layout frame, virtual-call dispatch loop, then SEH-wrapped CRT-style call; returns a function pointer on success.
- `0x005939F9` **CppExceptionDispatcher** — Dispatch helper: bounded copy or validated indirect call selected by flag bytes, with SEH-frame-offset fixups and bad-pointer guards.
- `0x00593CFD` **CppExceptionDispatcher** — Install a C++ SEH guard frame (scope table stru_5B99A0, handler ScriptFrameProcessor) on the TEB exception list, optionally call the global function pointer off_5E7960, then delegate to SEHWrapperDispatchingToHandlerFunction.
- `0x00593DB8` **CppExceptionDispatcher** — Null-checked global callback dispatcher: invoke dword_8D41B4 with argument a1 when non-null, else return false.
- `0x0059416F` **SlabHeapAllocator** — Slab/buddy heap block allocation: round size to 16 bytes, select a size class, scan slab free bitmaps from the global cursor, allocate/init a fresh slab on demand, unlink/split the block, return the pointer past the header.

## Proposed classes

### LocaleDetector

Detect the system locale that best matches the configured region and language strings, driving EnumSystemLocalesA callbacks and validating candidate locale ids. The detection state (region/lang strings, charset mode, match flags, best id) lives in the global block 0x008D3F98..0x008D3FB8; no object `this` is evidenced.

Methods: `0x0058FFEC`, `0x005901F0`, `0x00590303`, `0x0059045F`


### CodepageInfoObject

A vtable-based object whose display name can be extracted directly (matching vtable off_5B94D0 / module byte_5B94D4); otherwise the locale name is resolved through the dword_8D3FB8 query. Only byte 0 (non-zero marker) of the object layout is evidenced.

Methods: `0x005903DA`

- `this+0x00000000` `u8 first_byte_marker` (read, GUESS)

### FloatingPointArithmetic

Floating-point exception and parse handling: consume pending FPU exception bits against the control-word mask, clamp underflow/overflow, restore the FPU control word around parsing, and map parse/range inputs to TLS error codes. Frame-path per-frame tick helpers.

Methods: `0x005919DA`, `0x00591BF1`, `0x00591C79`, `0x00591CC6`


### LocalTimeStruct

Local-time to timestamp conversion with Daylight Saving Time handling. The timestamp fields (seconds/minutes/hours at 0x0/0x4/0x8, year at 0x14, day-of-year at 0x1C) form one local-time description object; DST transition dates are cached in globals 0x005E77F0..0x005E7808.

Methods: `0x00591EDF`, `0x0059249B`

- `this+0x00000000` `u32 seconds` (read_write, DERIVED)
- `this+0x00000004` `u32 minutes` (read_write, DERIVED)
- `this+0x00000008` `u32 hours` (read_write, DERIVED)
- `this+0x00000014` `u32 year` (read_write, DERIVED)
- `this+0x0000001C` `u32 day_of_year` (read, DERIVED)

### CrtFileTable

CRT low-level file I/O: initialize the 32-slot x 36-byte file-entry table (block array dword_8D4920, open count dword_8D4A20), inherit handles from startup info, wire stdin/stdout/stderr, and flush a file's buffers by index under a per-file critical section. The slot layout (handle at +0, flag byte at +4, byte at +5, dword at +8) is raw-offset evidence and is documented in unresolved rather than asserted as a field layout.

Methods: `0x00592891`, `0x00592F2C`


### CrtCommandLineParser

Parse the process command line into an argv table stored in globals dword_8D3E88 (argv base) / dword_8D3E84 (argc), with the module file name as the default source and a byte-checked override at dword_8D5A44.

Methods: `0x00592BAD`


### CppExceptionRecord

MSVC C++ exception record: fields for the exception code, parameter count and the type-info slot, consumed by the exception-handler dispatch 0x005934E1 (nested-record unwinding, scope-table binary search, catch dispatch).

Methods: `0x005934E1`

- `this+0x00000000` `u32 exception_code` (read, DERIVED)
- `this+0x00000010` `u32 number_parameters` (read, DERIVED)
- `this+0x00000014` `u32 type_info_magic` (read, DERIVED)

### CppTypeDescriptor

MSVC C++ type descriptor comparison: leading qualifier flags, a type-name pointer, and the name data behind it, matched via sub_58FB90 with qualifier-compatibility checks.

Methods: `0x0059373E`

- `this+0x00000000` `u8 qualifier_flags` (read, GUESS)
- `this+0x00000004` `char* type_name_ptr` (read, DERIVED)
- `*(this+0x4)+0x00000008` `char[] name_data` (read, DERIVED)

### CppExceptionDispatcher

SEH-wrapped dispatch machinery shared by exception handling and allocator paths: multi-argument dispatch, copy-or-indirect-call with frame-offset fixups, SEH guard-frame installation (scope table stru_5B99A0, handler ScriptFrameProcessor at 0x0058895C), optional global function pointer off_5E7960, and the null-checked global callback dword_8D41B4.

Methods: `0x00593839`, `0x005939F9`, `0x00593CFD`, `0x00593DB8`


### SlabHeapAllocator

Slab/buddy block allocator: 16-byte-rounded allocations from buddy size classes tracked by per-slab two-level free bitmaps, an allocation cursor, and fresh-slab allocation/initialization on demand. Arena state lives in globals dword_8D48EC..dword_8D48FC.

Methods: `0x0059416F`


## Compatibility contracts

- **Locale detection result contract** — A replacement must produce the same matched Locale id (0x008D3F98), best-match id (dword_8D3FB4) and match-quality flags (dword_8D3FB0 / byte_8D3FB1) from the same configured region/language strings and system locale enumeration; enumeration must stop once the region+charset bits are satisfied.
- **FPU exception consumption contract** — A replacement must consume the masked FPU exception bits against the control-word mask, apply the same underflow/overflow clamping (dbl_5E7718/dbl_5E7728 constants, denormalization loop) and return TRUE only when all masked bits were consumed.
- **Local time to timestamp contract** — A replacement must convert local date/time to the same timestamp: reject years outside 1970..2038, use the month-offset table dword_5E9B04, the base dword_5E7758 and the epoch offset 2085978496, and apply the same DST offset (dword_5E7760) under the dword_5E775C flag.
- **CRT lowio file table contract** — A replacement must maintain the same 32-slot x 36-byte file-entry table (block array at 0x008D4920, open count uNumber at 0x008D4A20) with handle -1 sentinel at slot+0, flag byte at slot+4, the first three slots wired to stdin/stdout/stderr, and SetHandleCount reflecting the slot count; per-index flush must report failures through the TLS error slots.
- **Command line argv contract** — A replacement must populate the argv base (0x008D3E88) and argc (0x008D3E84) globals from the module file name (or the byte-checked override dword_8D5A44) and return argc - 1 as the argument count.
- **Slab heap allocation contract** — A replacement allocator must round requested sizes to 16 bytes, write the header/footer sentinel (v27 + 1 at both ends), return the pointer just past the header, and back allocations with the slab descriptor/cursor state at 0x008D48EC..0x008D48FC.
- **C++ exception dispatch contract** — A replacement must recognize the C++ exception code 0xE06D7363 with 3 parameters and the type-info magic 429065504, unwind nested records through TLS slots, and dispatch catch handlers by binary-searching the scope table and comparing type descriptors.

## Unresolved

- Owner identity is unknown for every function in this packet; all classes are reconstruction proposals over free functions sharing state, not proven original C++ classes.
- The locale detection state block 0x008D3F98..0x008D3FB8 is asserted by the packet as individual globals; no struct common-ownership evidence exists, so no class field layout is proposed for it.
- dword_8D3FB8 is invoked as a function pointer with an inferred calling convention and message ids 11 and 4100 uninterpreted; its GetLocaleInfoA identity is GUESS only.
- The dword_8D3FB0 flag bit semantics (0x300 region+charset, bit 0 partial, bit 1 close) are inferred from branch structure, not a documented enum.
- The CPInfo/CodepageInfoObject layout beyond byte 0 and the exact roles of byte_5B94D4 (module handle) and off_5B94D0 (vtable) are inferred from two membership-test call sites.
- Meaning of TLS error codes 33 and 34 and the consumer of the TLS slot written by SetErrorCodeBasedOnInputRange is not established; the slot is recalculated per frame so external pokes do not persist.
- The index returned by DecodeBitFlags (0-5) and the semantics of each input flag bit have no enum or constant evidence.
- The epoch/era offset constant 2085978496 in LocalTimeToTimestamp is unexplained.
- The a7 (explicit DST force vs auto) semantics and the cooperation between dword_5E775C and CriticalSectionGuardedCall are DERIVED, not packet-proven.
- The mapping of the TIME_ZONE_INFORMATION DaylightDate/StandardDate members onto the byte globals 0x008D400C..0x008D401A and 0x008D4060..0x008D406E is not proven by the packet.
- The sub_592647 argument contract (daylight flag, absolute-date flag, year, month, day, day-of-week, hour, minute, second, millisecond) is inferred from call sites only.
- The CRT file-table slot layout (36-byte stride, handle at slot+0, flag byte at slot+4, byte at slot+5, dword at slot+8) and the descriptor array base used by FlushFileByIndex are raw-offset reads without named-struct evidence; the array base is named dword_8D4920 in raw source but has no allowed-global entry in this packet, so no field layout is asserted.
- The per-slot flag bits (0x1 inherited, 0x8 pipe, 0x40, 0x80) are DERIVED from CRT conventions, not proven by the packet.
- Roles of globals dword_8D3E84 (argc), dword_8D3E88 (argv base) and dword_8D3EA0 (argv pointer) are DERIVED from context; dword_8D5A44 is tested as a byte pointer but declared as an int.
- The scope-table layout (bounds at a5+4, ranges at a7) in CppExceptionHandlerCall is not statically resolvable; TLS slots 27/28 (nested record/continuation) semantics are inferred.
- The function named FontGlyphRender in the raw source acts as a fallback/catch-all handler here; the name/role mismatch is unresolved.
- In CppTypeDescriptorMatch the qualifier bit meanings (2/1/8 in leading bytes, 1/2 in the match dword) are inferred as const/volatile-style compatibility, not documented.
- In MultiArgRenderingDispatchWithLayout the a2 frame/layout role (counter at a2[2]), the literal 256, and the layout argument at a6+12 are caller-defined/unknown; whether it is genuinely rendering-specific or a generic SEH wrapper is unresolved.
- In CopyOrIndirectCallDispatch the a3/a4 flag-byte ownership (shared vs per-descriptor), sub_58B130's copy semantics and the interlocked indirect-call helpers are inferred from callee names.
- In SEHGuardedFunctionPointerCall the purpose of off_5E7960 and the semantics of a5 are caller-determined; the TEB-relative byte globals are compiler SEH bookkeeping writes.
- Where dword_8D41B4 is registered (assigned) is not covered by this packet.
- In SlabHeapAllocateBlock the -1 sentinel meaning, the 20-byte descriptor layout, and the identities of lpMem / dword_8D48F8 (arena base / slab count) are read from decompilation without a struct definition; dword_8D48F4 reset semantics are inferred from the guard condition.
- The constant-table lookup semantics of IDToValueTableLookupInConstantTable (0x00591CA1) and the exact role of StubReturning0 (0x0058FB7E) are not established.
- global:0x005B8CC8 (DoubleZero) is flagged by packet facts but appears nowhere in the raw decompiled source; its role here is unverifiable.
- The ten 0xFF00000000005455..0x5466 and other 0xFF0000000000xxxx byte globals flagged as accessed are likely mis-decoded members or compiler SEH bookkeeping writes; they do not appear in the raw source and remain unverified.
