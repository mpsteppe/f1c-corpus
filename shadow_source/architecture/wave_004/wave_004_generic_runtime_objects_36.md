# CRTRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Twenty-four functions reconstructed as fourteen worker-proposed runtime-object classes, all without confirmed owner objects. CriticalSectionEnterWithLazyInit (0x00595A61) enters a per-slot critical section from a bucketed pool: low 5 bits of the slot index select a 36-byte-stride slot within a bucket read from the dword_8D4920 array, and a zero init counter at +8 triggers double-checked lazy initialization (InitializeCriticalSection at +12) under a global guard. CRTFileOpenCreate (0x00595AF9) is a CRT open/create wrapper around CreateFileA that maps mode flags to access/share/disposition/flags-and-attributes, allocates a descriptor slot via sub_595801, classifies the handle (pipe/console), handles the 0x1A EOF rewind, and reports failure through the TLS error slots. TestFileSlotFlag (0x00596007) bounds-checks the same slot-group table and returns the 0x40 flag byte of a slot as an initialization gate for callers. FileTruncateOrExtend (0x0059797B) truncates via SetEndOfFile or grows by zero-chunk writes, restoring the original file position, and lockedFileIOWrapper (0x0059685F) brackets an inner I/O operation with the stream lock. InitCodePage (0x00596E40) builds the code-page character-class bitmap from a built-in table (unk_5E9B48) or GetCPInfo fallback under critical section 25, and MbStrChrWithDBCS (0x00598569) searches strings combining DBCS lead/trail bytes under the same section. LocaleAwareWideCharToMultiByte (0x00596030) and CallWithRefcountCriticalSection (0x00596716) are reference-count/critical-section-19 wrappers around the locale conversion pair sub_596089/sub_596773; ClassifyCharacterStringType (0x00595DC8) lazily detects the string-API family and classifies via GetStringTypeW/A; LocaleInfoRetrieval (0x005968F6) fetches LCTYPE strings or parses numeric locale data. BoundedStringLengthWithCap (0x005982F8) scans a NUL-terminated string up to a cap, StringAllocCopy (0x00598600) allocates a copy via Strlen + malloc + copy, and EnvStringTableInsert (0x00598323) maintains the case-insensitive environment-string table anchored at dword_8D3E90 with optional forwarding to SetEnvironmentVariableA. CRTHandlerDispatchByCommand (0x00597388) dispatches CRT handler commands to static slots (2/15/21/22) or TLS-resident handlers (4/8/11). RefcountDecrementWithLock (0x00598C88) and NullCheckWithVirtualDispatch (0x00598C70) form a refcounted-object pair; ReferenceCountDecrementWithConditionalFree (0x005993AF) and BufferTruncateRemoveRange (0x00599348) share a refcounted-string-buffer layout (data +4, size +8). ObjectInitWithVTableFlagSet (0x005993EB), EncodingStateObjectInit (0x0059942B), DestructorPattern (0x005992D3), aulldvrm (0x00596100), and MessageBoxWithActivePopup (0x00597234) complete the set. No class-instance boundaries are proven; all ownership is GUESS/DERIVED.

## Function roles

- `0x00595A61` **CRTCriticalSectionPool** — Enter the lazily-initialized per-slot critical section for a slot index; resolves bucket base from dword_8D4920[a1 >> 5] plus 36*(a1 & 0x1F) and double-check-initializes the entry under a global guard.
- `0x00595AF9` **CRTFileDescriptorTable** — CRT open/create wrapper: map mode flags to CreateFileA access/share/disposition/flags, allocate a descriptor slot, classify the handle type, optionally rewind the 0x1A EOF marker, and return the descriptor index or -1 with a TLS error.
- `0x00595DC8` **CRTLocaleContext** — Classify character types of a string via GetStringTypeW (Unicode path) or GetStringTypeA (ANSI path) after lazily detecting and caching the string-API family in dword_8D41C0.
- `0x00596007` **CRTFileDescriptorTable** — Bounds-checked test of slot flag bit 0x40 on the slot-group table (dword_8D4920 buckets, 32 slots of 36 bytes); returns 0x40 or 0 and gates per-slot initialization for callers.
- `0x00596030` **CRTLocaleContext** — Thread-safe wide-to-multi-byte conversion wrapper: atomic heap-lock counter (dword_8D5A5C) with optional critical section 19 (guarded by dword_8D5A58) around sub_596089; per-frame path.
- `0x00596100` **CRTMathHelpers** — MSVC CRT __aulldvrm unsigned 64-bit division-with-remainder helper (compiler runtime, not game logic); returns a1 mod a2 with a 64-bit normalization path and a 32-bit-divisor fallback.
- `0x00596716` **CRTLocaleContext** — Reference-counted wrapper forwarding three arguments to sub_596773 under an optional critical section 19, with InterlockedIncrement/Decrement of dword_8D5A5C balancing the counter on the non-flag path.
- `0x0059685F` **CRTFileDescriptorTable** — Locked file-I/O wrapper: acquire the stream lock (StreamBufferLockViaCriticalSection), run the inner sub_596888 forwarding both arguments, release the lock, and return the inner result.
- `0x005968F6` **CRTLocaleContext** — CRT locale-info retrieval: mode 1 fetches an LCTYPE string (stack buffer, grow-to-heap on ERROR_INSUFFICIENT_BUFFER), mode 0 parses raw locale data into a byte accumulator; returns 0 or -1.
- `0x00596E40` **CRTCodePageTables** — Initialize CRT code-page character-class tables: search the built-in table at unk_5E9B48 for the resolved code page, expand class ranges into the 256-byte bitmap, or fall back to GetCPInfo; cache in dword_8D46BC under critical section 25.
- `0x00597234` **CRTMessageBoxHelper** — Show a MessageBoxA parented to the last active popup window; lazily loads user32.dll and caches MessageBoxA/GetActiveWindow/GetLastActivePopup function pointers; returns 0 on load/resolution failure.
- `0x00597388` **CRTExceptionHandlerContext** — Dispatch a CRT handler by command id: static global slots for 2/15/21/22, TLS-resident handler by linear search for 4/8/11; zeroes exception-table entries for id 8 and saves/restores this[0x54]/[0x58].
- `0x0059797B` **CRTFileDescriptorTable** — File-size fix-up (ftruncate-style): save position, seek to end for size, truncate via SetEndOfFile or extend by zero-filled 4096-byte chunks, then restore the original position; reports failure via TLS error slots.
- `0x005982F8` **CRTStringUtility** — Bounded string-length scan: returns the NUL-terminated length up to a2 bytes, or the cap value cast to a pointer when the cap is exhausted without a NUL.
- `0x00598323` **CRTEnvironmentTable** — CRT environment-string table insert for KEY=VALUE: parse at '=', replace/remove/append case-insensitively in the table anchored at dword_8D3E90, grow via the copy helpers, and optionally forward to SetEnvironmentVariableA.
- `0x00598569` **CRTCodePageTables** — DBCS-aware character search: when code-page tables are initialized, under critical section 25 combine DBCS lead/trail bytes (bit 4 of byte_8D47E1) into a 16-bit value compared against a2; otherwise delegate to the fallback.
- `0x00598600` **CRTStringUtility** — Allocate a copy of a string (Strlen + MallocWrapperForNhMalloc(length+1) + sub_58FCA0) with no stored result in this function; used by the environment-table copy path.
- `0x00598C70` **RefCountedObject** — Null-checked release: when this+0 is non-null, obtain the refcount-decrement result and, if non-null, invoke virtual slot 0 on it with argument 1 (thiscall).
- `0x00598C88` **RefCountedObject** — Decrement the refcount dword at a1+4 bracketed by the sub_59A54D/sub_59A5E9 sync helpers; return the object pointer when the count reaches zero, else 0.
- `0x005992D3` **CRTLocaleObject** — Scalar-deleting-destructor pattern: always release owned resources via DestroyLocaleObjectFreeResourcesCallDtor(a2), then conditionally free the object memory with FreeWrapper_7bcf when the low bit of a3 is set; returns a1.
- `0x00599348` **RefCountedStringBuffer** — Remove a byte range from a buffer: free previously held string data, cap the removed count to available data (this[2] - a2), shift the tail left, validate and commit the new size, null-terminate.
- `0x005993AF` **RefCountedStringBuffer** — Reference-counted release: when the a2 flag is set, decrement the byte refcount before this[1]; free the block at 0/-1 sentinel instead; clear this[1], this[2], this[3].
- `0x005993EB` **CRTStateObject** — Object field initializer: zero this+0x2C, store a2 at this+0x28, set the flag byte at this+0x30 to 32, run StructFieldInitWithConditionalCall; null-handle path ORs bit 2 into this+0x4 and calls sub_59A5FE; a3 selects the sub_59A8FA finalization path.
- `0x0059942B` **EncodingStateObject** — Initialize an encoding-state object: store a2 at +0, zero +8 and +C, run the locale encoding init/cleanup pair sub_59A54D/sub_59A5E9, and seed +0x10 from the global dword_8D5A6C; returns this.

## Proposed classes

### CRTCriticalSectionPool

Bucketed, lazily-initialized critical-section pool keyed by slot index: the low 5 bits select a 36-byte-stride slot inside a bucket, the high bits index the bucket base array dword_8D4920; each entry carries an init counter at +8 and a CRITICAL_SECTION at +12 with double-checked init under a global guard.

Methods: `0x00595A61`


### CRTFileDescriptorTable

CRT file-descriptor table and file I/O: CreateFileA-backed open/create with mode-flag mapping, descriptor-slot allocation (sub_595801) and handle registration (sub_595924), slot flag testing, truncate/extend, and locked stream I/O; slot records live in 36-byte-stride groups reached through the dword_8D4920 bucket array.

Methods: `0x00595AF9`, `0x00596007`, `0x0059797B`, `0x0059685F`


### CRTCodePageTables

CRT code-page character-class tables: build the 256-byte class bitmap (byte_8D47E1) and per-code-page data from the built-in table at unk_5E9B48 or a GetCPInfo fallback, cache the active code page in dword_8D46BC, and provide DBCS-aware string search under critical section 25.

Methods: `0x00596E40`, `0x00598569`


### CRTLocaleContext

Locale-driven string handling: lazy string-API family detection with GetStringTypeW/A classification, MultiByteToWideChar-based conversion, LCTYPE locale-string and numeric retrieval, and thread-safe wide-to-multibyte conversion wrappers (sub_596089/sub_596773) guarded by the reference-count/critical-section-19 mechanism (dword_8D5A58 / dword_8D5A5C).

Methods: `0x00595DC8`, `0x005968F6`, `0x00596030`, `0x00596716`


### CRTStringUtility

Generic bounded string-length scanning and string duplication helpers used on frame paths and by the environment-table copy machinery.

Methods: `0x005982F8`, `0x00598600`


### CRTEnvironmentTable

Case-insensitive environment-string table (KEY=VALUE) anchored at dword_8D3E90 with bucket-end dword_8D3E94 and wide-string list dword_8D3E98; supports insert, remove-on-empty with compaction, growth via the null-terminated-int-array copy helper, and optional forwarding to SetEnvironmentVariableA.

Methods: `0x00598323`


### CRTExceptionHandlerContext

Per-thread CRT handler dispatch context: holds the TLS handler table base at +0x50, transient saved-state fields at +0x54 and +0x58, and dispatches command ids 2/15/21/22 to static global slots and 4/8/11 to TLS-resident handlers with exception-table zeroing for id 8.

Methods: `0x00597388`

- `this+0x00000050` `void* tls_handler_table_base` (read, GUESS)
- `this+0x00000054` `uint32 saved_state_54` (read_write, GUESS)
- `this+0x00000058` `uint32 saved_state_58` (read_write, GUESS)

### RefCountedObject

Refcounted object: counter dword at +0x4 with -1 sentinel, decremented under the sub_59A54D/sub_59A5E9 sync bracketing; reaching zero returns the object pointer so the caller can run its virtual release path.

Methods: `0x00598C70`, `0x00598C88`

- `this+0x00000000` `void* object_ptr` (read, GUESS)
- `this+0x00000004` `int32 refcount` (read_write, GUESS)

### RefCountedStringBuffer

Refcounted string buffer sharing the layout this[1]=data pointer (+4), this[2]=size (+8), this[3]=cleared (+C): supports byte-range removal with tail shift and reference-counted release that frees the block when the header refcount reaches 0 or the -1 sentinel.

Methods: `0x00599348`, `0x005993AF`

- `this+0x00000004` `char* data_ptr` (read_write, GUESS)
- `this+0x00000008` `uint32 size` (read_write, GUESS)
- `this+0x0000000C` `uint32 field_C` (write, GUESS)

### CRTStateObject

Object field initializer with flag-driven state: writes this+0x28 and this+0x30 (flag 32), zeroes +0x2C, ORs bit 2 into the flags at +0x4 on a null-handle path, and selects a finalization path via the a3 argument.

Methods: `0x005993EB`

- `this+0x00000028` `uint32 field_28` (write, GUESS)
- `this+0x0000002C` `uint32 field_2C` (write, GUESS)
- `this+0x00000030` `uint8 state_flag` (write, GUESS)
- `this+0x00000004` `uint32 flags` (read_write, GUESS)

### EncodingStateObject

Encoding-state object initializer: stores the argument at +0, zeroes +8 and +C, runs the locale encoding init/cleanup pair sub_59A54D/sub_59A5E9 on the argument, and seeds +0x10 from the global dword_8D5A6C.

Methods: `0x0059942B`

- `this+0x00000000` `uint32 arg` (write, GUESS)
- `this+0x00000008` `uint32 field_8` (write, GUESS)
- `this+0x0000000C` `uint32 field_C` (write, GUESS)
- `this+0x00000010` `uint32 locale_seed` (write, GUESS)

### CRTLocaleObject

Locale object resource-release/destruction pattern: always releases owned resources via DestroyLocaleObjectFreeResourcesCallDtor, then conditionally frees the object memory when the delete flag low bit is set.

Methods: `0x005992D3`


### CRTMathHelpers

MSVC compiler runtime helpers emitted into the executable; aulldvrm is the unsigned 64-bit division-with-remainder primitive used by unknown callers.

Methods: `0x00596100`


### CRTMessageBoxHelper

One-time lazy loader/resolver of user32.dll MessageBoxA/GetActiveWindow/GetLastActivePopup with cached function-pointer globals; shows a message box parented to the last active popup window.

Methods: `0x00597234`


## Compatibility contracts

- **CRTFileDescriptorContract** — CRT file open/create must map mode flags to CreateFileA access/share/disposition/flags, allocate a descriptor slot in the group table (36-byte stride, dword_8D4920 buckets), classify the handle type, apply the 0x1A EOF rewind, and support truncate/extend that preserves file position; failures report through the TLS error slots (TLSOffsetGetter / TLSOffsetGetter_afd8).
- **LocaleAndCodePageContract** — String classification (GetStringTypeW/A with lazy API-family detection cached in dword_8D41C0), wide-to-multibyte conversion using the active code page, LCTYPE locale retrieval, and code-page class-table init (built-in table at unk_5E9B48 or GetCPInfo fallback, cached in dword_8D46BC) must be preserved for a replacement that keeps CRT behavior.
- **EnvironmentTableContract** — The environment-string table anchored at dword_8D3E90 (bucket end dword_8D3E94, wide-string list dword_8D3E98) must support case-insensitive KEY=VALUE insert, remove-on-empty, and forwarding to SetEnvironmentVariableA when the flag is set.
- **LazyInitCriticalSectionContract** — The bucketed lazy-init critical-section pool must preserve the 32-slot / 36-byte-stride bucketing keyed by slot index, the per-entry init counter at +8 and CRITICAL_SECTION at +12, and double-checked init under the global guard; enter/leave ordering is relied on by file, locale, code-page, and handler paths.
- **CRTHandlerDispatchContract** — Handler dispatch must keep command ids 2/15/21/22 bound to the static slots (dword_8D41E8/EC/F0/F4) and ids 4/8/11 resolved through the TLS table (this+0x50) by linear search, with the id-8 exception-table zeroing bounded by dword_5E7888 + dword_5E788C.

## Unresolved

- dword_8D4920 is a read-only array of bucket base pointers (derived stride); its allocation size and element count are unknown.
- Guard slot 17 and the 36-byte stride in CriticalSectionEnterWithLazyInit are exactly as decompiled; the 12-byte header plus the platform CRITICAL_SECTION layout is not confirmed by packet evidence.
- The meaning of the per-slot index a1 (existing analysis suggests CRT file descriptors, DERIVED tier) is not established by this packet alone.
- Semantics of the byte_FF00000000005450/5451/5452 globals (reported written by CRTFileOpenCreate but absent from the reconstructed body) are unknown.
- The descriptor-slot flag byte at slot+4: only bit 0x40 is observed; the other flag bits and the full 36-byte slot record type are unknown.
- Exact meaning of the a4 attribute byte bit 0x80 relative to dword_8D3E70 (binary/text mode) in CRTFileOpenCreate is inferred, not confirmed.
- Semantics of dword_8D5A58 (locale-thread refcount, DERIVED name) and dword_8D5A5C (heap-lock counter, DERIVED name) and the purpose of critical section slot 19 are not confirmed.
- The real work of sub_596773 (behind CallWithRefcountCriticalSection) and sub_596888 (behind lockedFileIOWrapper) is outside this packet.
- Meaning of the return value of sub_596089 (00496089) is not grounded.
- The single caller of aulldvrm (sub_58D04D) is not analyzed; the division operands are unknown.
- The role of the globals 0x0058895C (ScriptFrameProcessor) and 0x005B99C8 (stru_5B99C8) referenced by ClassifyCharacterStringType is not visible in the reconstructed body.
- The exact meaning of a7 in ClassifyCharacterStringType (drives conversion flags 9 vs 1, likely MB_PRECOMPOSED vs MB_ERR_INVALID_CHARS) is inferred, not confirmed.
- The byte_FF00000000001692/1695/1699/169B globals are 64-bit-address artifacts whose purpose is unknown.
- Mode-0 digit parsing of LocaleInfoRetrieval (leading zeros, sign handling, terminating condition at word_8D41CC), the off_5E69C8 classification-table layout, and the per-mode a4 output contract are inferred from the loop shape.
- In InitCodePage, the per-entry data-block fields copied from unk_5E9B4C and the meaning of the locale constant in dword_8D48E4 are not derivable from this function alone; the zero-handler sub_59706A and finalizer sub_597093 semantics are not established; the FF0547A/FF0547C globals are 64-bit-address artifacts.
- The purpose of the MessageBoxWithActivePopup error/notice path (caller sub_5932F3 context) is not established; the string literals at 0x005B9B08/1C/2C/38 have no resolved symbol names in the raw source.
- In CRTHandlerDispatchByCommand, the semantic meaning of command ids (2=onexit, 15=atexit, 21=signal, 22=exception, 4/8/11=per-thread cleanup, per the corpus fill) is DERIVED; the role of critical-section index 1, the sentinel handler value 1, the TLS table layout at this[20], and whether dword_5E788C is a count or limit are not confirmed; sub_589CB5(3u) semantics and the 12-byte exception-record size are unknown.
- In FileTruncateOrExtend, BitfieldManager flag 0x8000 semantics, the distinction between the two TLS error slots, and sub_58E290 write semantics are not established.
- The cap-exceeding return of BoundedStringLengthWithCap is the integer a2 cast to a pointer; the caller comparison contract is inferred.
- In EnvStringTableInsert, the precise helper purpose of sub_58FCA0, the negative-lookup insertion convention (v10 < 0 encodes -v10), and the object types behind dword_8D3E90 / dword_8D3E98 are inferred, not documented.
- In StringAllocCopy, what sub_58FCA0 copies into and where the allocated buffer is stored is unknown; a1 is declared _DWORD* yet passed to Strlen.
- The byte_8D47E1 classification-table layout (bit 4 as the DBCS lead-byte flag) and the meaning of critical-section index 25 are DERIVED, not proven.
- The concrete class behind NullCheckWithVirtualDispatch and the method invoked through virtual slot 0 are only determinable at runtime; the relationship to the structural twin ConditionalFreeWithBit0Flag (00404F70) is not semantically proven.
- The exact roles of sub_59A54D and sub_59A5E9, the meaning of the -1 refcount sentinel, and the nature of the 4-byte stack object in RefcountDecrementWithLock are unknown.
- In DestructorPattern, the meaning of a2 (passed via ebp) and the exact behavior of FreeWrapper_7bcf are not established; the a3 low-bit check resembles the MSVC scalar-deleting-destructor free flag but is not independently confirmed.
- The owning class of the RefCountedStringBuffer layout (data +4, size +8) is unknown; whether the refcount header is allocated with the data block is not visible.
- In ObjectInitWithVTableFlagSet, the identity of the owner object, the meaning of bit 2 at this+0x4, the sub_59A5FE null-handle path, the sub_59A8FA finalization path, and the this+0x30 flag-byte value 32 are unknown.
- In EncodingStateObjectInit, the sub_59A54D/sub_59A5E9 calls take the address of a local copy of a2 rather than the stored field; the meaning of dword_8D5A6C and the roles of 0x005B9CD8 / 0x005B9CDC are unresolved.
- The buffer object type behind BufferTruncateRemoveRange's this[1]/this[2] and the meaning of the second argument 0 to sub_599560 are not established.
