# RuntimeInfrastructure

Scope: `generic_runtime_objects`  
Trust: `GUESS`

Proposed DERIVED grouping of generic runtime utilities and infrastructure state found in the 0x00586ED0-0x00589CA4 range. Four compiler-generated module-initializer thunks (GlobalObjectChainInit) run a shared once-guard and build a fixed cross-wired chain of module-global objects. StreamReader implements fread-style buffered reads over an OS handle with per-character refill and a direct large-read fallback. ThreadLocalState and FormattedOutput wrap TLS access and a critical-section-guarded output sink. SessionManager owns the session buffer/table and the per-index parameter setter with validation rollback; LocaleConfig owns the stored locale buffers, code page, and locale-aware uppercase. CharacterClassification centralizes the character-class table (single-byte vs multi-byte fallback) plus its consumers (IntegerParser uses the same table). TimeUtility converts system time to an internal format with a cached DST flag. BlockPartitioner provides callback-driven byte-block reordering. A thin exit forwarder completes the set. Ownership of every function is UNKNOWN per the packet; the class boundaries are organizational proposals, not proven classes.

## Function roles

- `0x00586ED0` **GlobalObjectChainInit** — SEH-guarded once-only dynamic initializer (first copy): registers a per-frame SEH handler seeded with the read-only byte at 0x008D3E31, runs the shared module init guard, and on the first entry constructs and cross-wires a fixed chain of eight module-global objects; returns the saved incoming ecx.
- `0x005870E0` **TaskBase** — Resets a TaskBase-like struct: delegates initialization of the +0x4 sub-object to SimpleSetter_7500, then unconditionally writes +0x10 and +0x14 to reset values and the bytes at +0x18/+0x19 to 0; returns zero with no guards.
- `0x005873F0` **GlobalObjectChainInit** — SEH-guarded once-only dynamic initializer (pointer-frame sibling copy): same object chain and shared guard as 0x00586ED0, seeded with the read-only byte 0x008D3E35, with guarded construction of dword_8D4210 on non-null and an odd raw-value write into frame slot a1-4.
- `0x00587680` **GlobalObjectChainInit** — SEH-guarded once-only dynamic initializer (third sibling copy): same object chain and shared guard as 0x00586ED0, seeded with the read-only byte 0x008D3E39.
- `0x00587930` **TypedBufferDecoder** — Decodes a count-prefixed typed buffer into per-type handler objects: for each entry fetches the handler from the factory at this+0x414 via vtable slot +0x58, checks the entry type byte against the handler's expected type size, copies the fixed data into the handler at +0x14 and the variable payload into +0x8 via realloc-copy, stamps the config value at +0x4, and dispatches; returns the last dispatch result.
- `0x00587A50` **GlobalObjectChainInit** — Module init thunk: installs an SEH handler for the module exception record, runs the reference-counted once-guard, and on first entry constructs a chain of seven linked global objects (tagged 0..6) with non-null guards, wiring them together at vtable-derived offsets; later entries only bump the guard counter.
- `0x0058806E` **StreamReader** — fread-style buffered read on a stream descriptor: drains buffered bytes via MemoryCopy, refills one character at a time through the filbuf-style underflow refill for small requests, and reads directly from the OS handle rounded down to the buffer size for large requests; reports the element count transferred and ORs EOF (0x10) or error (0x20) flags on failure.
- `0x005884E0` **ThreadLocalState** — Writes the caller-provided value into the dword at TLS block offset +20 and returns the TLS block base pointer; part of a thread-local configuration/state accessor pattern.
- `0x00588821` **FormattedOutput** — Thread-safe formatted output: enters the critical section, saves the buffer state of the output context, formats through sub_58D04D, restores the buffer state, leaves the critical section, and returns the format result.
- `0x00588C7A` **SessionManager** — Sets a session parameter at index a1 from a string: parses, allocates a copy, swaps the session table slot and the 6-byte config entry, updates code-page state for special indices (2 -> CodePage, 1 -> dword_8D3F4C), validates via a per-index callback, and on failure restores the prior state and frees the copy; returns the new session slot or 0.
- `0x00588D95` **SessionManager** — Creates/reinitializes the session structure: lazily allocates an 849-byte buffer when null, clears its first byte, runs the session setup batch, iterates a subsystem setup table appending ';' delimiters and comparing entries, and on mismatch tears the buffer down and returns the fallback pointer.
- `0x00588E4E` **LocaleConfig** — Parses a locale/configuration string: the input "C" is the built-in default locale fast path (zeroes optional outputs, returns the output buffer); otherwise the input is matched against the stored locale compare strings, parsed, validated against the locale data block, committed into the stored locale buffers with the conversion dword updated, and copied out through optional word/dword outputs.
- `0x005891FE` **BlockPartitioner** — Partitions a byte range [a1, a2) into a3-byte blocks by descending boundary scan, selecting the last block start whose callback result is positive and swapping the equal-sized blocks via byteBufferSwap; returns the last swapped block pointer.
- `0x0058924C` **BlockPartitioner** — Swaps a3 bytes between two buffers in place, element by element, advancing both pointers; no-op when the pointers are equal or a3 is zero; returns the advanced source pointer.
- `0x0058928F` **IntegerParser** — strtol-style string-to-integer parser with automatic base detection: skips whitespace, accepts an optional sign, auto-detects base 16 (0x/0X), 8 (leading 0) or 10, accumulates digits through the character-class table, detects overflow against 0xFFFFFFFF, writes errno 34 through the TLS getter on range failure, and optionally reports the end-of-parse pointer.
- `0x005896EE` **TimeUtility** — Converts UTC/local system time to an internal time format, caching the timezone/DST flag and refreshing it only while the cached UTC time components match the current UTC time; optionally writes the result through an output pointer. Free __cdecl utility, not a member function.
- `0x00589AA4` **LocaleConfig** — Locale-aware single-character uppercase: when a locale is configured, classifies the character via the character-class table (or the multi-byte fallback), swaps byte order for two-byte input, and performs the locale uppercase through sub_591FA1; without a locale, falls back to ASCII 'a'-'z' uppercasing.
- `0x00589B70` **CharacterClassification** — Character-class query: tests a character code against the alpha (upper/lower) class bits by masking the per-code classification table entry with 0x103, or delegates to the multi-byte lookup-table conversion fallback with the same mask.
- `0x00589B9E` **CharacterClassification** — Character-class query: tests a character code against the digit class bit by masking the per-code classification table entry with 4, or delegates to the multi-byte lookup-table conversion fallback with the same mask.
- `0x00589BC6` **CharacterClassification** — Character-class high-bit test: returns the 0x80 bit of the per-code classification table entry, or delegates to the multi-byte lookup-table conversion fallback with mask 128.
- `0x00589C1B` **CharacterClassification** — Classifies a character type into a flag mask: returns the char-type flag bits masked with 0x107 from the lookup table, or delegates to the multi-byte lookup-table conversion fallback with the conversion type code 263.
- `0x00589C49` **CharacterClassification** — Character-class query: tests a character code against a broad printable-class bit set by masking the per-code classification table entry with 0x157, or delegates to the multi-byte lookup-table conversion fallback with the same mask.
- `0x00589CA4` **free_function** — Thin __cdecl forwarder: passes the incoming UINT uExitCode through to sub_589CC6(uExitCode, 0, 0) and returns its result; no other logic, fields, or globals are touched.

## Proposed classes

### GlobalObjectChainInit

SEH-guarded once-only static initialization. Four compiler-generated module-initializer thunks (three near-identical siblings at 0x00586ED0/0x005873F0/0x00587680 plus the pointer-frame variant 0x00587A50) share a module init guard counter: on the first entry they construct a fixed chain of module-global objects and cross-wire them at vtable-derived offsets with the address of one shared object (unk_8D42A0) and OR flag value 2 into one entry; later entries only bump the guard counter. The identity and runtime type of the constructed objects is not established.

Methods: `0x00586ED0`, `0x005873F0`, `0x00587680`, `0x00587A50`


### TaskBase

Reset/initialization of a TaskBase-like task object. The +0x4 sub-object initialization is delegated to an external setter (SimpleSetter_7500); the dword fields at +0x10 and +0x14 are written to reset values (0 at +0x10, -1 at +0x14) and the bytes at +0x18/+0x19 to 0, with no read-back or guard. The +0x4 sub-object has no matching IR field evidence (it appears only as a callee argument) and its layout is not declared here.

Methods: `0x005870E0`

- `this+0x00000010` `int reset_state_word` (write, GUESS)
- `this+0x00000014` `int reset_marker_word` (write, GUESS)
- `this+0x00000018` `BYTE reset_flag_byte` (write, GUESS)
- `this+0x00000019` `BYTE reset_flag_byte_2` (write, GUESS)

### TypedBufferDecoder

Parses a count-prefixed typed buffer into per-type handler objects. Each entry is routed through the handler factory stored at this+0x414, whose vtable slot at +0x58 produces the handler; the entry's type byte is matched against the handler's expected type size, fixed data is copied into the handler at +0x14, the variable-length payload into +0x8 via realloc-copy, and the config value is stamped at +0x4, then the handler is dispatched through a virtual call. The handler-internal offsets (config value +0x4, payload buffer +0x8, fixed data +0x14, type-size field +0x24) are described from prose only and have no matching IR field evidence, so they are not declared as fields.

Methods: `0x00587930`

- `this+0x00000414` `void* handler_factory` (read, GUESS)
- `*(this+0x414)+0x00000058` `funcptr handler_create_slot` (read, GUESS)

### StreamReader

fread-style buffered reader over an OS file handle. Drains the descriptor's internal buffer first, refills one character at a time for small requests, and reads directly from the handle (rounded down to the buffer size) for large requests; reports element counts and sets EOF/error flag bits. The descriptor layout (read pointer at +0x0, buffered byte count at +0x4, flags word at +0xC with EOF bit 0x10 / error bit 0x20 / buffered-stream bits 0x10C, OS file handle at +0x10, buffer size at +0x18) is described from prose only and has no matching IR field evidence, so it is declared in the compatibility contract rather than as fields.

Methods: `0x0058806E`


### ThreadLocalState

Accessor over the per-thread TLS storage block: writes the caller-provided value into the dword at block offset +20 and returns the block base pointer. The +20 slot has no matching IR field evidence (the offset appears only in prose) and its semantic role is unknown.

Methods: `0x005884E0`


### FormattedOutput

Thread-safe formatted output into a shared output context (global 0x005E6768): enters the critical section, saves the buffer state, formats through the format routine, restores the buffer state, and leaves the section. Shared sink for logging/config formatting; callers include WindowsAdminCheck, MediaFileDecodeHeader and MPEGBuffer. The output context has no IR field evidence and is not declared as a field.

Methods: `0x00588821`


### SessionManager

Session configuration. Creates/reinitializes the session buffer by lazily allocating it (dword_5E64F4), running the session setup batch, appending ';'-delimited subsystem setup entries and comparing them against the table bounded by off_5E6500..off_5E6530 (fallback pointer off_5E650C, sentinel default slot unk_5E63E0); and sets named session parameters with per-index validation callbacks (funcs at 0x005E64F8) and rollback, updating code-page state for special indices. The session globals appear only as prose-grounded globals (no IR field evidence), so none are declared as fields.

Methods: `0x00588C7A`, `0x00588D95`


### LocaleConfig

Global locale and code-page state plus locale-aware text utilities: parsing and committing named locales into the stored locale buffers (unk_5E63E4, unk_5E6468), single-character uppercase through the configured locale (locale handle dword_8D3F38), and the code page / code-page parameter globals (0x008D3F48, 0x008D3F4C) updated by the session parameter setter for special indices. The locale globals appear only as prose-grounded globals (no IR field evidence), so none are declared as fields.

Methods: `0x00588E4E`, `0x00589AA4`


### BlockPartitioner

Byte-block partitioning and reordering: a descending boundary scan selects block starts by an external positive-returning callback and swaps equal-sized blocks through the byte-level swap primitive. The block units may be bytes or larger elements depending on the caller's interpretation.

Methods: `0x005891FE`, `0x0058924C`


### IntegerParser

strtol-like string-to-integer parsing with automatic base detection, whitespace/sign handling, character-class digit accumulation, overflow detection (errno 34 via the TLS getter) and optional end-pointer reporting. Shares the character-class table with CharacterClassification.

Methods: `0x0058928F`


### TimeUtility

System-time handling: converts UTC/local system time to an internal time format, caching the timezone/DST flag (dword_8D3E58) while the cached UTC time components (xmmword_8D3E60 with byte components 8D3E62/8D3E66/8D3E68/8D3E6A) match the current UTC time. The internal time format (epoch base, units) is produced by an external converter. The cache globals have no IR field evidence and are not declared as fields.

Methods: `0x005896EE`


### CharacterClassification

Character classification queries (alpha, digit, high-bit, printable, char-type flags) that select a single-byte classification-table path (table off_5E69C8) or a multi-byte lookup-table conversion fallback depending on the encoding mode global cbMultiByte (0x005E6BD4). The table masks (0x103, 0x107, 0x157, 0x80, 4) are DERIVED from usage, not named. The table globals have no IR field evidence and are not declared as fields.

Methods: `0x00589B70`, `0x00589B9E`, `0x00589BC6`, `0x00589C1B`, `0x00589C49`


## Compatibility contracts

- **fread_element_count_contract** — BufferedFileRead must return the number of elements actually transferred, (requested_total - remaining) / element_size; a completed request returns the requested element count, and a zero-byte request returns 0 without touching the stream. On failure it must OR flag 0x10 (EOF) or 0x20 (error) into the descriptor flags word at +0xC.
- **buffered_stream_descriptor_layout** — Stream descriptor layout consumed by StreamReader: +0x0 read pointer, +0x4 buffered byte count, +0xC flags word (bit 0x10 EOF, 0x20 error, buffered-stream bits 0x10C), +0x10 OS file handle, +0x18 buffer size. Buffered reads drain the internal buffer before touching the handle and fall back to a direct handle read rounded down to the buffer size for large requests.
- **once_only_static_initialization** — Static module initializers must construct the linked global object chain exactly once per process. The shared module init guard counter makes the first entry build the chain and later entries only bump the counter, while a per-frame SEH handler is registered with a read-only seed byte.
- **strtol_parse_contract** — StringToIntegerWithBaseDetection behaves like strtol: skips whitespace, accepts an optional sign, auto-detects base 16 (0x/0X), 8 (leading 0) or 10, reports overflow via errno 34 (ERANGE) through the TLS offset getter, writes the end-of-parse pointer through the optional out-parameter, and rejects bases outside [0, 36] or equal to 1.
- **locale_c_default_fast_path** — LocaleStringParser treats the input "C" (0x43 then NUL) as the built-in default locale: it zeroes the optional word/dword outputs and returns the output buffer without consulting the stored locale buffers; a null input returns null.
- **time_conversion_cache** — SystemTimeToInternalTimeConvert caches the timezone/DST flag and refreshes it only when the cached UTC time components no longer match the current UTC time; the actual conversion is delegated to an internal time formatter. Cache state lives in dword_8D3E58 (flag) and the cached UTC copy.
- **formatted_output_locking** — FormattedOutputWithCriticalSection must hold the critical section around the entire buffer-save / format / buffer-restore sequence so concurrent callers cannot interleave writes to the shared output context.
- **session_parameter_index_semantics** — SessionParameterSetter dispatches on index a1: index 1 updates the global code-page parameter and index 2 updates the global code page; validation failure restores the prior session slot, config entry, code page and frees the new copy; the sentinel default slot pointer is never freed.

## Unresolved

- Semantics of the constructed global object chain and why each entry is cross-wired with the address of unk_8D42A0 are not grounded by the packet; the constructor helpers are external and the constructed globals have no packet evidence references.
- Purpose of the shared module init guard counter beyond the first-vs-subsequent entry distinction is unknown; the routine exists in several near-identical copies sharing that counter.
- sub_59A54D / sub_59A5E9 SEH frame helper roles are inferred only from call position.
- The odd write of the raw value of dword_8D4210 into frame slot a1-4 in the pointer-frame variant (0x005873F0) is recorded as-is; its role is unclear.
- The global 0x005E6768 is used both as a vtable chain seed in the static initializers and as the output context for FormattedOutputWithCriticalSection; whether these are the same object is not established.
- Purpose of the sub-object at this + 0x4 and what SimpleSetter_7500 initializes is unknown; the reset values (-1 at +0x14, 0 at the others) are caller-context dependent.
- The concrete type of the handler factory at this+0x414 and the handler objects it returns is unknown; only the vtable slot at +0x58 and the per-entry contract are evidenced.
- The type-size encoding (field36 >> 3) + ((field36 & 7) != 0) and the buffer/field roles at handler offsets 4, 8, 20 and 36 are unverified; the semantic of the config value written to every handler is unknown.
- The stream descriptor may be a CRT FILE or a custom stream object; the sub_58C9B4 read contract beyond returning -1 / 0 / positive is not evidenced.
- The semantic role of the dword field at TLS block offset +20 is unknown; only its offset and write behavior are evidenced.
- The callee StubReturning0 (0x0058FB7E) is listed for SessionParameterSetter but never appears in the raw source; its connection to that path is unknown.
- The parallel arrays dword_8D3F30 and the 6-byte config region at 9256820 are named only in the raw source; their structure and role are not independently evidenced.
- Globals asc_5B8C74 (format specifier) and asc_5C30AC (delimiter) are flagged read but never appear in the raw source; off_5E64FC is flagged read but the raw iteration begins at off_5E6500.
- The exact role and content layout of the stored locale buffers unk_5E6468/unk_5E63E4 and the word_8D3E4C-to-dword_8D3E50 conversion value (a numeric locale identifier or code page) are not defined.
- The internal time format produced by sub_591EDF (epoch base, units) is unknown from this function.
- The off_5E69C8 character-class table bit semantics (masks 0x103, 0x107, 0x157, 0x80, 4, 8) and sub_591FA1's exact conversion behavior (assumed LCMapString wrapper, arguments 0x200, 3, 0, 1) are inferred, not proven.
- Whitespace and digit bit meanings inside the off_5E69C8 type table are inferred from usage; the caller flag bits (unsigned/sign/overflow/parsed-digits) are DERIVED from the guard arithmetic; sub_589A35 is assumed to be an uppercase/hex conversion.
- The meaning of the sentinel unk_5E63E0 compared against the old session slot pointer is not evidenced.
- The class groupings (GlobalObjectChainInit, TaskBase, TypedBufferDecoder, StreamReader, ThreadLocalState, FormattedOutput, SessionManager, LocaleConfig, BlockPartitioner, IntegerParser, TimeUtility, CharacterClassification) are DERIVED organizational proposals; per-function ownership is UNKNOWN in the packet and equal offsets on different this-pointers were not merged.
- The decompiler-artifact byte reads (0xFF00000000005455..0xFF00000000005467) from the cached UTC time are recorded only in unresolved evidence.
