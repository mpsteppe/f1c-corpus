# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Generic runtime object helpers shared by startup, file I/O, string/locale conversion, and resource teardown paths. Two CRT lifecycle anchors frame the group: the entry point (WinMainEntryPoint, 0x0058A19E) bootstraps the process and dispatches to the game main entry, and the exit handler (CRTProcessExitHandler, 0x00589CC6) runs atexit functions and terminate-data cleanup. Around them sit a buffered stream object (write-flush validation and text-mode newline-translating reads), a sorted interval-range search, backward-stepping callback iterators, IEEE-754 double classifiers, a C-runtime subset (strrchr, _allmul), locale-aware string conversion and in-place formatting helpers, file/drive attribute validators, conditional resource-teardown helpers, and a locale resolution/enumeration provider. Ownership is largely unknown from the packet; class boundaries are proposed as DERIVED or GUESS and must not be promoted to CONFIRMED without independent evidence.

## Function roles

- `0x00589CC6` **CRTProcessRuntime** — CRT process-exit/termination handler: runs pre-exit cleanup, honors the terminate-on-exit gate, walks the registered atexit function stack, performs terminate-data range cleanups, and releases the exit critical section.
- `0x0058A19E` **CRTProcessRuntime** — Program entry point: captures OS version, runs guarded CRT/TLS initialization, registers the CRT SEH frame, snapshots command line, environment, and startup info, dispatches to the game main entry, then runs exit cleanup and folds the result through the exception code/record.
- `0x0058A42F` **SEHTrampolineDispatcher** — Builds an SEH exception-handler trampoline frame on the stack, retrieves a TLS-resolved handler, dispatches through vtable offset +104, and conditionally re-links the exception chain.
- `0x0058A02C` **FileStreamObject** — Flushes the buffered write stream; on flush failure returns -1; else tests the +0xD error flag bit 0x40 and validates the +0x10 OS handle, returning -1 when invalid.
- `0x0058A0B6` **FileStreamObject** — Thunk that calls sub_58A0BF with the constant argument 1 and returns its result; downstream semantics unresolved.
- `0x0058C824` **FileStreamObject** — Low-level file-read wrapper with text-mode newline translation: clamps the position counter, queries the cursor, recounts newline bytes over the buffered range when the per-handle lowio entry enables translation, and raises TLS error 22 when a required flag is clear.
- `0x0058A55A` **RangeIntervalTable** — Walks a sorted interval table backwards from a1+0x10 (entry count at a1+0xC) to locate the entry whose lower/upper range contains a3, writing the found and previous indices through a4/a5.
- `0x0058A5F7` **CallbackStepIterator** — Invokes a caller-supplied callback a3 times while stepping a pointer backward by element size a2 from a1 + a3*a2; returns the last callback result.
- `0x0058A677` **CallbackStepIterator** — Iterator dispatch helper: decrements the data pointer by the element size and calls the callback each iteration; used by both stepping-callback loop variants.
- `0x0058A8A3` **FloatClassifier** — Classifies a double via its IEEE-754 exponent/sign fields into small integer categories; NaN/Inf delegate to UtilityFunction_1d2e, subnormal, normal, and signed zero handled directly.
- `0x0058DF5C` **FloatClassifier** — Double classifier wrapper: returns 0 when FloatClassify(a1) intersects mask 0x90, otherwise runs two discarded rounding calls and returns 2.
- `0x0058B050` **CRuntimeLibrary** — C standard-library strrchr implementation: backward scan for the last byte equal to a2, returning its pointer or 0.
- `0x0058C6F0` **CRuntimeLibrary** — MSVC compiler RTL _allmul 64-bit unsigned multiply helper: full 64-bit product path or widened 32x32 fast path.
- `0x0058B077` **LocaleStringFormatter** — strtod-style converter: skips whitespace via the char-type table, parses with the encoding-aware locale parser, handles infinity/NaN/range flags, and sets TLS errno 34 on non-finite results.
- `0x0058BCCF` **LocaleStringFormatter** — In-place formatter that overwrites the first non-digit character with the locale decimal separator and left-shifts the tail by one byte.
- `0x0058C0D0` **LocaleStringFormatter** — Shifts a byte string right by a2 bytes (length + 1 bytes including the NUL) via a block copy, opening insertion space; no-op when a2 is zero.
- `0x0058EEF7` **LocaleStringFormatter** — Character normalization helper: selects a direct lookup-table bit-4 test or the fallback converter by cbMultiByte mode, returning either the uppercased-minus-7 form or the input unchanged.
- `0x0058F6C7` **LocaleStringFormatter** — In-place walk folding ASCII digits to nibble values and left-shifting semicolon separators out of a locale digit-grouping string.
- `0x0058B9FF` **FileAccessValidator** — Drive-path validation: builds a drive-root path from the drive letter and rejects it when GetDriveTypeA reports a type below 2.
- `0x0058BA75` **FileAccessValidator** — File-attribute check: maps INVALID_FILE_ATTRIBUTES through the error lookup, rejects read-only files when the caller reject flag is set, and stores TLS error codes 13 and 5 on rejection.
- `0x0058EF48` **AllocatorResourceTeardown** — Forwards to sub_596888 only when the handle argument is not -1; the -1 sentinel marks an absent handle whose teardown is skipped.
- `0x0058F8EB` **AllocatorResourceTeardown** — Conditionally frees seven pointer fields (offsets +0xC through +0x24) via sub_58AA6F, skipping entirely when the struct is null or when +0xC equals the static sentinel.
- `0x0058EF5F` **IncrementReadLoop** — Increment-and-read loop: increments the counter at a1+0, reads through the buffered byte reader, and continues while the predicate holds; returns the last value read.
- `0x0058F014` **LocaleInfoProvider** — Populates a caller structure with 43 locale-derived string fields via sub_5968F6(1, locale, id, destination), OR-ing per-call statuses into the returned result.
- `0x0058F7C9` **LocaleInfoProvider** — Bulk locale query: fills destination offsets +12 through +47 with LCTYPE-style values and post-processes the +0x1C digit string in place; returns the OR of all query statuses.
- `0x0058FD90` **LocaleInfoProvider** — Resolves and validates a locale from language/region strings: lazy-init of the locale-info function pointer, binary searches of the language/region tables, four resolution helpers, code-page validation, and localized-string fill.
- `0x0058FF65` **LocaleInfoProvider** — Initializes locale-matching state (length-3 language/region markers, charset mode) and dispatches EnumSystemLocalesA with the enumeration callback; validates and clears the result flags.

## Proposed classes

### CRTProcessRuntime

Process lifecycle: entry-point bootstrap that snapshots OS/command-line/environment/startup state and dispatches to the game main entry; CRT exit handler that runs atexit handlers and terminate-data cleanup and releases the exit critical section.

Methods: `0x00589CC6`, `0x0058A19E`


### SEHTrampolineDispatcher

Builds and dispatches SEH exception-guard trampoline frames through a TLS-resolved handler vtable (offset +104) used to protect render/utility call paths.

Methods: `0x0058A42F`


### FileStreamObject

Buffered stream/file object used by the CRT file layer: buffered write-flush validation, text-mode read with newline translation, error/flag state, and the OS file handle.

Methods: `0x0058A02C`, `0x0058A0B6`, `0x0058C824`

- `this+0x00000000` `char* buffer_limit` (read, DERIVED)
- `this+0x00000004` `int position` (read_write, DERIVED)
- `this+0x00000008` `char* buffer_base` (read, DERIVED)
- `*(this+0x8)+0x00000000` `unsigned char buffer_byte` (read, DERIVED)
- `this+0x0000000C` `int translation_flags` (read, DERIVED)
- `this+0x0000000D` `unsigned char error_flags` (read, DERIVED)
- `this+0x00000010` `void* os_handle` (read, DERIVED)
- `this+0x00000018` `int fallback_byte_count_source` (read, GUESS)

### RangeIntervalTable

Owns a sorted interval table (entry count at +0xC, table pointer at +0x10) searched backward to locate the range containing a value.

Methods: `0x0058A55A`

- `this+0x0000000C` `int entry_count` (read, DERIVED)
- `this+0x00000010` `void* table_ptr` (read, DERIVED)

### CallbackStepIterator

Generic backward-stepping callback loop: walks a pointer down a memory range by an element size, invoking a per-element callback and returning the last result.

Methods: `0x0058A5F7`, `0x0058A677`


### FloatClassifier

IEEE-754 double classification helpers returning small integer category codes and divisibility/validity results.

Methods: `0x0058A8A3`, `0x0058DF5C`


### CRuntimeLibrary

A subset of the C runtime library identified by ABI and behavior: strrchr and the MSVC 64-bit multiply helper _allmul.

Methods: `0x0058B050`, `0x0058C6F0`


### LocaleStringFormatter

String/number conversion and in-place formatting sharing the char-type table and multi-byte encoding mode: strtod-style parsing, decimal-separator insertion, string shifting, character normalization, and digit-grouping nibble folding.

Methods: `0x0058B077`, `0x0058BCCF`, `0x0058C0D0`, `0x0058EEF7`, `0x0058F6C7`


### FileAccessValidator

File and drive validation: drive-type checks and file-attribute inspection with error mapping and read-only rejection.

Methods: `0x0058B9FF`, `0x0058BA75`


### AllocatorResourceTeardown

Conditional resource teardown helpers for allocated structures: guarded multi-field frees and handle-sentinel forwarding.

Methods: `0x0058EF48`, `0x0058F8EB`

- `this+0x0000000C` `void* resource_ptr_0` (read, DERIVED)
- `this+0x00000010` `void* resource_ptr_1` (read, DERIVED)
- `this+0x00000014` `void* resource_ptr_2` (read, DERIVED)
- `this+0x00000018` `void* resource_ptr_3` (read, DERIVED)
- `this+0x0000001C` `void* resource_ptr_4` (read, DERIVED)
- `this+0x00000020` `void* resource_ptr_5` (read, DERIVED)
- `this+0x00000024` `void* resource_ptr_6` (read, DERIVED)

### IncrementReadLoop

Driver loop that increments a caller-owned counter and reads through a buffered byte reader while a predicate holds.

Methods: `0x0058EF5F`

- `this+0x00000000` `int counter` (read_write, DERIVED)

### LocaleInfoProvider

Locale resolution and retrieval: bulk locale-field queries, language/region binary-search resolution, code-page validation, localized-string fill, and system locale enumeration dispatch.

Methods: `0x0058F014`, `0x0058F7C9`, `0x0058FD90`, `0x0058FF65`

- `this+0x00000000` `char const* language_string` (read, GUESS)
- `this+0x00000040` `char const* region_string` (read, GUESS)
- `this+0x0000001C` `char* digit_grouping_string` (read_write, GUESS)

## Compatibility contracts

- **ProcessExitContract** — A replacement executable must: mark exiting via dword_8D3EAC = 1, honor dword_8D3EB0 as the hard-terminate gate (TerminateProcess), walk registered exit functions between dword_8D5A50 (top) and dword_8D5A54 (bottom), run the terminate-data range cleanups, and finish by releasing the exit critical section.
- **StrtodContract** — String-to-double conversion must skip leading whitespace, write the end pointer past the parsed number into the optional out parameter, and set TLS errno 34 (ERANGE) on non-finite results, returning plus/minus infinity via dbl_5E9990 or 0.0 for NaN/range failure.
- **StrrchrContract** — Must implement standard strrchr: return a pointer to the last byte equal to the searched byte, or 0 when absent, scanning back from the terminating NUL.
- **FileStreamContract** — The buffered stream object must expose: limit at +0x0, position counter at +0x4, buffer base at +0x8, translation/flag word at +0xC, error byte at +0xD (bit 0x40 write-error, bit 0x20 translation state), OS handle at +0x10, and fallback byte-count source at +0x18.
- **TextModeReadContract** — Text-mode reads must translate newlines per the per-handle lowio entry dword_8D4920, recount newline bytes over the buffered range, and raise TLS error 22 when the required 0x80 flag is clear.
- **LocaleResolutionContract** — Locale resolution must produce the output triple a2[0] = locale id, a2[1] = language id, a2[2] = code page, and when requested fill localized strings at a3 and a3 + 64; success returns 1, any failure returns 0.

## Unresolved

- The exact caller-level meaning of the a2/a3 gate arguments to the exit handler and the semantics of UtilityFunction_9d7d cleanup over the two data ranges are not established.
- The atexit-stack layout (top dword_8D5A50, bottom dword_8D5A54) is inferred from the pointer-walk arithmetic.
- The object behind the first-argument pointer is unproven for most functions; field:this:0x00000000 is reused across different structures (stream limit, string head, language string, loop counter) and the packet does not prove common ownership.
- The meaning of bit 0x40 (write error) at stream +0xD and the invalid-handle semantics of sub_592891 are inferred from branch structure only.
- The purpose of the constant argument 1 in the thunk sub_58A0B6 and the downstream behavior of sub_58A0BF are unknown.
- sub_589CB5 is a documented callee of the entry point but is reached through the SEH/exception path, not visible in the raw body.
- The vtable layout at the TLS handler +104 and the trampoline slot meanings in SEHExceptionHandlerTrampolineSetup are DERIVED from decompiler SEH scaffolding.
- The 20-byte interval entries in RangeIntervalTable beyond the +4/+8 bounds are unknown; ascending sort is implied by the backward walk but not proven.
- Whether callee 0x0058A6D5 is the callback invoked by the stepping loop or an SEH handler is unconfirmed.
- FloatClassify return-code meaning depends on UtilityFunction_1d2e, unexamined here; caller-side mapping in 0x0058DF5C is not established.
- The exact locale value behind each LCTYPE-style code in the bulk query is not established; the sub_5968F6 mode flag (1 vs 0) distinguishes two query variants whose semantics are unresolved.
- The digit-class contract of sub_58B465 (return value 101) and the bit-4 char-type-table flag are inferred from loop conditions.
- The FF.. TEB/KUSER_SHARED_DATA bytes and the read-only globals dbl_5B8CC8 and dbl_5B8E48 (assumed divisor 2.0) are not referenced directly by the decompiled statements.
- Semantics of the four locale resolution helpers (sub_590303, sub_5903C0, sub_58FF65, sub_5901F0) and the validation flag bits 0x100/0x200/0x7 in dword_8D3FB0 are not established.
- word_8D3F92 and word_8D3F94 labels (Unknown_Word_CRC, CodePageShareMemHandle) are DERIVED from the index and unverified.
- The text-mode read raw-source excerpt is truncated; the fallback byte-count source at +0x18 tail, the final subtraction, and the return computation are not evidenced.
- sub_58AA6F identity as a free routine and sub_596888 teardown semantics are assumed from call context only.
- The 8-byte record layouts of the 64-entry language table off_5E72D0 and the 22-entry region table off_5E7218 are not recovered.
