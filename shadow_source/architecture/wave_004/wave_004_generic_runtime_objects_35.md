# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `GUESS`

The packet groups twenty-four validated generic-runtime functions into nine functional clusters. A CRT locale/environment init cluster (code page tables, timezone globals, environment block parse/fetch) populates a small set of observable global surfaces. String, math (float parse with FPE guard, frndint, double classify, FPU control word, __aulldiv) and calendar-time helpers are free-standing CRT-style primitives. Critical-section and error/termination wrappers provide locking and exit plumbing. The largest sub-system is the custom memory allocator: slab block free/coalesce, region-list ownership validation, page-counter trim, and a proximity record lookup, plus a file-slot registry and buffered I/O context init. All owners are UnknownObject in the packet; classes are evidence-grounded functional groupings (GUESS), never confirmed ownership.

## Function roles

- `0x0058F939` **CRTLocaleAndEnvironmentInit** — Initializes the runtime code page character-type and case-mapping tables (dynamic tables built from GetCPInfo, or the static default table), installing the table pointers at 0x005E69C8/0x005E69CC.
- `0x0058FB90` **CRTStringHelpers** — Case-sensitive byte-string comparison (strcmp-like) with an alignment-optimized dword loop and byte/word prologues for misaligned pointers.
- `0x0058FCB0` **CRTStringHelpers** — String append (strcat-like): scans the source for its terminator with an aligned zero-byte probe and copies the destination in aligned DWORDs, returning the original destination pointer.
- `0x0059163B` **CRTRuntimeMath** — Floating-point parse dispatcher with an FPE-flag guard: on dword_5E9AD0 nonzero writes TLS error code 33 and returns the input double unchanged; otherwise delegates to FloatParsingWithErrorHandling.
- `0x0059168F` **CRTRuntimeMath** — Floating-point math dispatch with exception-code decode (BitFlagDecoderViaBitTests) and an FPE guard; the parse path forwards the double to FloatParsingWithErrorHandling, the error path writes a TLS error code and returns the fallback value.
- `0x00591CF3` **CRTRuntimeMath** — x87 frndint rounding helper: rounds the double argument to an integer under the ambient FPU rounding mode; no rounding mode is set or restored here.
- `0x00591D2E` **CRTRuntimeMath** — Classifies a 64-bit double (passed as two 32-bit halves) into +infinity/-infinity/NaN-class/exponent-all-ones codes.
- `0x00591E66` **CRTRuntimeMath** — Identity pass-through of a __int16 argument; named for the FPU control-word query semantics inferred from its float-dispatch callers.
- `0x005921C5` **CRTCriticalSectionRuntime** — Thread-safe lazy initialization of a CRT singleton via double-checked locking on flag dword_8D4078: fast-path return, CS 11 enter, re-check, run sub_5921F3, bump flag, leave.
- `0x005921F3` **CRTLocaleAndEnvironmentInit** — Initializes CRT timezone globals from the TZ environment string (parsing hh:mm:ss and DST designator) or from the Windows GetTimeZoneInformation API; populates bias, DST flag, DST offset and the two name buffers.
- `0x0059247A` **CRTCriticalSectionRuntime** — Critical-section guarded call wrapper: enters CS 11, runs the inner call sub_59249B(a1), leaves CS 11, returns the inner result.
- `0x00592787` **CRTCalendarTime** — Converts a seconds-since-epoch value into a broken-down calendar-time struct in a per-thread (TLS) buffer, handling the four-year leap cycle via the month-length tables at 0x005E9AD4/0x005E9B08.
- `0x00592AF4` **CRTLocaleAndEnvironmentInit** — Parses the CRT environment string block into an array of pointers to individually allocated environment strings (skipping equals-prefixed entries), stores the array at 0x008D3E90, frees the source block, and sets the parsed flag.
- `0x00592DFA` **CRTLocaleAndEnvironmentInit** — Returns a malloc'd copy of the process environment strings block in a single encoding, caching the winning Unicode/ANSI variant in dword_8D41A8; returns NULL on any allocation, fetch, or conversion failure.
- `0x005932BA` **CRTErrorAndTermination** — Conditionally performs error cleanup and exit display: gated on dword_8D3EBC / console flag dword_5E65B4, runs sub_5932F3(0xFC) cleanup, an optional dword_8D41AC callback, and sub_5932F3(0xFF) final exit display.
- `0x00593694` **FontGlyphRenderer** — Font glyph rendering dispatcher driven by an SEH exception-record context: guards on a TLS flag, walks a five-dword-strided glyph range table from a binary interval search, and dispatches each matching range through MultiArgRenderingDispatchWithLayout.
- `0x00593C9C` **CRTErrorAndTermination** — Dispatch wrapper for a registered CRT-style termination handler stored at TLS slot 24 (invoked when non-null), followed by a fixed cleanup sequence, returning the result of the final parameterized call.
- `0x00593E1B` **SlabMemoryAllocator** — Linear search over the 20-byte allocator record array for the first record whose key DWORD (index 3) lies within 0x100000 bytes of the input address.
- `0x00593E46` **SlabMemoryAllocator** — Frees a block in the custom slab buddy allocator: coalesces adjacent free blocks, updates the two-level 64-size-class occupancy bitmaps and per-class free lists, and releases empty slabs and their descriptor backing blocks.
- `0x00594B76` **SlabMemoryAllocator** — Walks the doubly-linked memory-region list rooted at 0x005E7968 to test whether an address is owned and 16-byte-aligned, storing the owning node and page base and deriving a page-relative result.
- `0x00594BCD` **SlabMemoryAllocator** — Accumulates a byte value into a per-page counter of an allocator tracking array and triggers an allocator trim (sub_594AB4(16)) when the counter and the global live-page counter reach their thresholds.
- `0x00594FF0` **CRTRuntimeMath** — MSVC CRT unsigned 64-bit division helper (__aulldiv): normalizes and estimates the quotient for large divisors, falls back to a native 64/32 div when the divisor fits 32 bits.
- `0x005957BD` **FileStreamBufferRuntime** — Initializes a buffered I/O context: increments the file-open counter, allocates a 4096-byte heap buffer (or falls back to a 2-byte inline area), and sets cursor, remaining count, capacity and the backing-mode flags field.
- `0x00595801` **FileStreamBufferRuntime** — Allocates one file slot from a global slot-group registry (groups of 32 slots x 36 bytes), double-checking per-slot critical-section init and growing the group array when all groups are exhausted.

## Proposed classes

### CRTStringHelpers

Free-standing byte-string primitives: aligned strcmp-like comparison and strcat-like append with a zero-byte DWORD probe.

Methods: `0x0058FB90`, `0x0058FCB0`


### CRTRuntimeMath

CRT-style math helpers: floating-point parse dispatchers with FPE guards and TLS error codes, x87 frndint rounding, double special-value classification, an FPU control-word query, and the unsigned 64-bit division helper __aulldiv.

Methods: `0x0059163B`, `0x0059168F`, `0x00591CF3`, `0x00591D2E`, `0x00591E66`, `0x00594FF0`


### CRTLocaleAndEnvironmentInit

CRT one-time locale and environment initialization: code page character-type/case-mapping tables, timezone globals (TZ string or Windows API), environment block parse and fetch, guarded by lazy critical sections.

Methods: `0x0058F939`, `0x005921F3`, `0x00592AF4`, `0x00592DFA`


### CRTCalendarTime

Seconds-since-epoch to broken-down calendar-time conversion using per-thread buffer caching and four-year leap-cycle month tables.

Methods: `0x00592787`


### CRTCriticalSectionRuntime

Lazy-critical-section plumbing: double-checked singleton init on a global flag and a fixed critical-section guarded call wrapper, both using the lazily initialized critical section id 11.

Methods: `0x005921C5`, `0x0059247A`


### CRTErrorAndTermination

Error and process-termination plumbing: gated error cleanup with optional callback and final exit display, and a dispatch wrapper for a registered TLS termination handler followed by a fixed cleanup sequence.

Methods: `0x005932BA`, `0x00593C9C`


### FontGlyphRenderer

Font glyph rendering dispatcher driven by an SEH exception-record context; guards on a TLS flag and walks a five-dword glyph range table, dispatching each matching range to the layout renderer.

Methods: `0x00593694`


### SlabMemoryAllocator

Custom slab buddy allocator: block free/coalesce with two-level 64-size-class occupancy bitmaps and per-class free lists, region-list ownership validation, per-page accounting with threshold trim, and a proximity record lookup over the 20-byte descriptor array.

Methods: `0x00593E1B`, `0x00593E46`, `0x00594B76`, `0x00594BCD`

- `this+0x00000000` `uint32_t allocatorLowerBitmap` (read_write, DERIVED)
- `this+0x00000004` `uint32_t allocatorUpperBitmap` (read_write, DERIVED)
- `this+0x0000000C` `uint8_t* slabBase` (read, DERIVED)
- `this+0x00000010` `uint32_t* slabBitmapArray` (read, GUESS)

### FileStreamBufferRuntime

File/stream infrastructure: buffered I/O context initialization (heap buffer with inline fallback) and a global file-slot registry that hands out flat slot indices from lazily allocated 32-slot groups.

Methods: `0x005957BD`, `0x00595801`

- `this+0x00000000` `uint8_t* cursor` (read_write, DERIVED)
- `this+0x00000004` `uint32_t remainingBytes` (read_write, DERIVED)
- `this+0x00000008` `uint8_t* bufferBase` (read_write, DERIVED)
- `this+0x0000000C` `uint32_t backingFlags` (read_write, DERIVED)
- `this+0x00000018` `uint32_t capacity` (read_write, DERIVED)

## Compatibility contracts

- **CodePageTableSlots** — The runtime keeps the code page character-type and case-mapping table pointers installed at global slots 0x005E69C8 (table pointer stored at 0x005E69C8[0]) and 0x005E69CC, with the static default table word_5E69D2 for the static path. The per-slot role assignment (which slot is the type table versus the case-mapping table) is not proven.
- **TimezoneGlobalSurface** — CRT timezone init writes observable globals: 0x005E7758 (GMT bias in seconds, from 60*Bias or the parsed TZ offset), 0x005E775C (DST-active flag; also used to store the TZ DST designator character), 0x005E7760 (DST offset in seconds, 60*(DaylightBias-StandardBias)), and the multi-byte timezone name buffers 0x005E77E4/0x005E77E8. A replacement must populate these same globals for the CRT timezone surface.
- **EnvironmentStringsFormat** — The runtime exposes the process environment as a malloc'd copy in the CRT double-NUL-terminated block format (GetEnvironmentStringsBlock) and as a parsed pointer array at 0x008D3E90 built by CRTEnvironmentParseInit, whose entries are individually allocated strings; equals-prefixed entries are skipped, consistent with the CRT hidden-variable convention.
- **SlabHeapBlockLayout** — The slab buddy allocator stores, 4 bytes before each block, a header DWORD whose bit 0 marks the block in use; blocks live in 0x8000-byte slabs, size classes 0..63 (class = (size>>4)-1), with two-level occupancy bitmaps (allocator level at this+0x0/this+0x4, per-slab in the descriptor array) and doubly-linked free lists per class. Descriptor records are 20 bytes, arrayed at 0x008D48FC with count 0x008D48F8. Layout is derived from pointer arithmetic, not an authoritative struct.
- **FileSlotRegistry** — File slots are handed out as flat indices from groups of 32 slots x 36 bytes; the group-pointer array at 0x008D4920 grows by 32-slot groups and the total slot count at 0x008D4A20 doubles as the array end sentinel. Each slot carries an in-use flag byte at +4, an init counter at +8, and an embedded critical section at +12.

## Unresolved

- All packet owners are UnknownObject; the nine class boundaries are functional groupings derived from shared globals and callees, never proven C++ ownership.
- The `this` base in the packet is the decompiler's generic pointer label. field:this:0x00000000 appears in unrelated functions (string-compare byte reads, calendar-time input seconds, buffered-I/O cursor, allocator lower bitmap) with no proof of common ownership; rule 8 is honored by keeping them as distinct per-class fields and not merging.
- field:this:0x00000010 is used by SlabHeapFreeCoalesceBlock as the per-slab bitmap array but by AllocatorPageCounterAndTrim as the page base; same base+offset label, likely distinct objects. The ref is placed on the slab field and the page-counter meaning is left unresolved.
- field:this:0x00000001 (string-comparison/append byte reads) has no defensible class-level placement and is listed in unresolved_evidence_refs.
- Whether 0x005E69C8 holds the character-type table and 0x005E69CC the case-mapping table (or vice versa) is not proven.
- Semantics of sub_595DC8 (SBCS byte-map conversion) and sub_596A2E (wide case-mapping build) are assumed from call shape only.
- Globals 0x008D400E, 0x008D401C, 0x008D4062 and 0x008D4070 are per-byte views of the TIME_ZONE_INFORMATION region; their precise member assignment is not visible in the decompiled C.
- The 0xFF00000000005xxx and 0xFF000000000016xx evidence refs are decompiler artifacts of byte reads through TZ string pointers and TEB/TLS bytes; their provenance is unresolved.
- dword_8D4078 is incremented (a counter) rather than set to a constant; the reason is not answered by the packet.
- The slab allocator descriptor sub-structure (flags at desc+4/desc+8, backing pointer at desc+12, arrays at desc+16/desc+20) is inferred from pointer arithmetic, not an authoritative struct definition.
- AllocatorPageCounterAndTrim: the meaning of marker 241 and why the counter threshold is 240 are unexplained; the allocator-context interpretation is DERIVED, not confirmed.
- FontGlyphRender: the TLS flag at index 26, the five-dword glyph range-table layout, and the layout indirection (i[4] + 16*i[3]) are structural only; the underlying glyph table structure is unknown.
- SEHWrapperDispatchingToHandlerFunction: the purpose of each fixed cleanup call and the semantics of the TLS slot-24 handler are unknown; the referenced globals 0x0058895C and 0x005B9988 are not visible in the raw source body.
- aulldiv is a compiler runtime helper (MSVC __aulldiv), not game logic; its single caller context is unanalyzed.
- CRTEnvironmentParseInit: sub_58FCA0 has no explicit source argument in the pseudocode; the equals-prefix skip follows CRT convention but is not evidenced by the packet alone.
- ErrorCleanupAndExitDisplay: what sub_5932F3 modes 0xFC (cleanup) and 0xFF (final exit) do internally, and the identity of the dword_8D41AC callback, are unknown.
- The 36-byte calendar-time struct layout and the +4 weekday offset in SecondsToCalendarTime are unverified from this function alone.
