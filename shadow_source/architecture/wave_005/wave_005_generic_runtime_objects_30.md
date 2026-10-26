# CrtRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

The packet resolves into five defensible object groups plus import forwarders. (1) CrtLocaleState: code-page resolution (CodePageResolver, mapConstant), locale/code-page state reset (ResetLocaleState), character-type and case-mapping table initialization (CharTypeTableInit), the CRT locale-info getters with cached API detection (LocaleInfoStringGetter, LocaleInfoAnsiGetter), locale-aware collation (LocaleCompareStringAnsi), and the one-time lazy locale initialization guard (LazySingletonInit). (2) CrtStringTable: a case-insensitive key=value token table rooted at dword_8D3E90, populated lazily from a wide-string list at dword_8D3E98 (WideCharMultiByteStringConversionWithAllocLoop) and searched by key or prefix (EnvStringLookupByKey, CaseInsensitiveStringTableLookup). (3) Buffered stream I/O: plain buffered read/write (BufferedReadWithFill, BufferedWriteWithFlush) plus codecvt-facet variants (BufferedCharWriteWithCodecvtConversion, readDecodedChar). (4) CrtDescriptorTable and CrtBufferObject: a 36-byte-stride descriptor flag array (DescriptorFlagSetOrClear) and a reference-counted buffer object (BufferValidateAndResize, ConditionalStringFreeWithLengthCheck). (5) CrtSubsystemRefCountState: a locked global reference counter with zero-reached cleanup dispatch (RefCountDecrementWithCleanup). LocaleStreamObjectConstructSimplified is an MSVC iostream constructor of unknown concrete class. closesocket, inet_addr and sendto are plain Winsock import thunks. Several functions have UNKNOWN ownership (LinearSearchByID, LocaleStreamObjectConstructSimplified, MemoryCopyFromIDLookup, CopySixDwordsFromGlobalSource, delegateCallWithNullGuard) and their object identity is unresolved.

## Function roles

- `0x00596D81` **CrtStringTable** — String-table key lookup: searches the key=value token table rooted at dword_8D3E90 for a case-insensitive key match (MbsnbicollCRTStringCollation), returning a pointer to the value just after the '=' separator; lazily builds the table from the wide-string list at dword_8D3E98 when the dword_8D5A48 parse flag allows.
- `0x00596FED` **CrtLocaleState** — Resolves special code-page identifiers to a concrete Windows code page: 0xFFFFFFFE -> GetOEMCP, 0xFFFFFFFD -> GetACP, 0xFFFFFFFC -> stored default CodePage; clears the auto-select flag dword_8D41D4 and sets it to 1 on any special identifier.
- `0x00597037` **CrtLocaleState** — Pure constant-mapping switch: maps input constants 932/936/949/950 to output constants 1041/2052/1042/1028, returning 0 for any other input; no side effects.
- `0x0059706A` **CrtLocaleState** — Unconditional reset of locale/code-page state: zero-fills the 256-byte block at unk_8D47E0 and clears the adjacent locale scalars (dword_8D46BC, unk_8D46C0, unk_8D46C4, unk_8D46C8, dword_8D46CC, dword_8D48E4, unk_8D48E0); always returns 0.
- `0x00597093` **CrtLocaleState** — Builds the CRT character-type and case-mapping tables: on GetCPInfo(dword_8D46BC) success fills the CharType classification array via sub_595DC8 and two case-mapped strings via sub_591FA1, then classifies each character into byte_8D47E1 and byte_8D46E0; on failure runs a hardcoded ASCII-only fallback.
- `0x00597218` **CrtLocaleState** — One-time lazy subsystem initialization: when dword_8D5A4C is zero, calls sub_596E40(-3) to initialize the locale subsystem and sets dword_8D5A4C = 1; subsequent calls are no-ops.
- `0x0059750A` **UnknownObject** — Linear search of an array of 12-byte records for the first record whose ID field at +4 equals the search value; returns the matching record address or 0; element count is held in dword_5E7894.
- `0x00597D3C` **CrtLocaleState** — CRT locale-info getter returning a wide-character string: caches the detected system type in dword_8D4200 (1 = native GetLocaleInfoW, 2 = GetLocaleInfoA plus MultiByteToWideChar conversion); the ANSI path sizes, stack-allocates and converts a buffer; returns 0 on every failure path.
- `0x00597E4F` **CrtLocaleState** — Locale-info getter returning an ANSI/multibyte string: caches the detected system mode in dword_8D4204 (0 = undetected, 1 = wide, 2 = ANSI); mode 2 forwards to GetLocaleInfoA, mode 1 converts a GetLocaleInfoW result via WideCharToMultiByte using the default CodePage when the caller passes 0.
- `0x00597FAC` **CrtStringTable** — Wide-to-multibyte string conversion loop over the list rooted at dword_8D3E98: measures each wide string via WideCharToMultiByte, allocates a buffer via MallocWrapperForNhMalloc, converts, and stores each result via sub_598323; returns 0 when done, -1 on any failure.
- `0x0059801A` **CrtDescriptorTable** — Per-descriptor flag-byte bitfield update in the dword_8D4920 array (36-byte stride, flag byte at +4): command 0x8000 clears bit 0x80, command 0x4000 sets bit 0x80; returns a status encoding the prior bit-0x80 state, or -1 with TLS error code 22 for an unrecognized command.
- `0x0059807B` **CrtLocaleState** — Locale-aware comparison of two bounded ANSI buffers: probes CompareStringW availability on first use and caches the mode in dword_8D4208; mode 2 compares with CompareStringA, mode 1 converts both buffers to wide via MultiByteToWideChar and compares with CompareStringW; returns 0 on any failure.
- `0x005984AA` **CrtStringTable** — Case-insensitive search of the string table rooted at dword_8D3E90 for an entry whose first cchCount1 bytes match under MbsnbicollCRTStringCollation with an '=' or null terminator immediately after the prefix; returns the entry index or its negation when the table is exhausted.
- `0x0059865A` **WinsockApiImports** — Winsock import thunk forwarding to __imp_closesocket (0x0059E2E8); no local logic.
- `0x00598666` **WinsockApiImports** — Winsock import thunk forwarding to __imp_inet_addr (0x0059E2F0); parses a dotted-quad IPv4 string into a binary address.
- `0x00598672` **WinsockApiImports** — Winsock import thunk forwarding to __imp_sendto (0x0059E2F8); sends a datagram.
- `0x00598994` **CrtSubsystemRefCountState** — Decrements the global reference counter dword_5E9EF4 under a lock (sub_59A54D / sub_59A5E9); when the counter reaches zero, dispatches StatusCheckWithErrorDispatch over unk_8D42A0, dword_8D43C8 and dword_8D4210 and returns the last dispatch result; otherwise returns the lock-release result.
- `0x00598A41` **UnknownObject** — MSVC stream object constructor (simplified): registers the SEH handler, conditionally installs the streambuf and std::ios sub-object vftables when the this+0xC construction flag is set, writes the std::ostream vftable, and chains to sub_59A8FA; returns the saved stream pointer.
- `0x00598CF9` **BufferedStream** — Buffered byte read: while the requested count remains, copies from the internal buffer (this+0x1C / this+0x2C) via MemoryCopy_cc00, otherwise calls the vtable index-5 refill/read method at obj+0x14; returns the total bytes read.
- `0x00598D6D` **BufferedStream** — Buffered byte write: while the requested count remains, copies into the internal buffer (this+0x20 / this+0x30) via MemoryCopy_cc00, otherwise calls the vtable index-1 flush/write method at obj+0x4; returns the total bytes written.
- `0x00598DE3` **UnknownObject** — Helper that obtains a 0x18-byte source object via sub_59942B(-1) and bulk-copies it into the caller buffer a1, returning a1; arguments a2-a4 unused.
- `0x00598E07` **UnknownObject** — Same 0x18-byte (6-DWORD) copy helper as MemoryCopyFromIDLookup with a wider unused parameter list; copies the sub_59942B(-1) block into a1 and returns a1.
- `0x00598E9E` **CodecvtStreamBuffer** — Single-character buffered write with optional codecvt facet conversion (vtable slot index 5 of the facet at this+0x38) and device flush via FileReadWrapperWithLock; -1 sentinel returns 0, missing device returns -1, no facet falls back to BufferedCharacterWriteWithOverflowHandling.
- `0x005990AE` **CodecvtBufferedStreamReader** — Buffered read of one decoded character: fast raw path via the group pointer at this+0x1C / length at this+0x2C; otherwise drains bytes from the input stream at this+0x50 through the codecvt facet do_in vtable slot +16 and returns the decoded character, a partially decoded byte, or -1; without a facet returns the next raw byte or -1.
- `0x00599232` **UnknownObject** — Invokes the delegate stored at this+0x50 via sub_59BB00(v4, a2, 0, a3); returns this on success, 0 when the delegate is null or the delegate call reports failure.
- `0x00599560` **CrtBufferObject** — Validates and optionally grows a buffer: data at this+4 with a boundary marker byte at data[-1], requested size taken from the return-address slot; handles overflow via sub_59AD49, marker decrement, cleanup or reallocation via BufferAllocationWithSizeRounding; returns 0 for cleanup/ok paths and 1 when reallocation is required or capacity fits.
- `0x005995E5` **CrtBufferObject** — Conditionally detaches/frees the string buffer at this+4 before modification: only when the metadata byte at data[-1] is non-zero and not -1, calls ReferenceCountDecrementWithConditionalFree, then rewrites the buffer via BufferWriteWithNullTerminate; null buffer or metadata 0/-1 states are no-ops.

## Proposed classes

### CrtLocaleState

Holds the CRT locale/code-page runtime state: the stored default code page, the auto-select flag, cached Win32 locale-API detection modes, the character-type/case tables, and the one-time initialization flag; provides code-page resolution, table building, locale-info getters and collation over this state.

Methods: `0x00596FED`, `0x00597037`, `0x0059706A`, `0x00597093`, `0x00597218`, `0x00597D3C`, `0x00597E4F`, `0x0059807B`


### CrtStringTable

A case-insensitive key=value token string table rooted at dword_8D3E90, populated lazily from the wide-string list at dword_8D3E98 and guarded by the dword_8D5A48 parse flag; provides key lookup, prefix lookup and the wide-to-multibyte table builder.

Methods: `0x00596D81`, `0x00597FAC`, `0x005984AA`


### CrtSubsystemRefCountState

A locked global reference counter (dword_5E9EF4) for a CRT-like locale/exception-management subsystem; when the counter reaches zero it dispatches StatusCheckWithErrorDispatch over three subsystem globals.

Methods: `0x00598994`


### BufferedStream

A buffered byte stream object: internal read buffer (this+0x1C / this+0x2C) and write buffer (this+0x20 / this+0x30), with vtable fallbacks at index 5 (read/refill) and index 1 (write/flush) for the unbuffered path.

Methods: `0x00598CF9`, `0x00598D6D`

- `this+0x00000000` `void** vftable` (read, UNKNOWN)
- `this+0x0000001C` `char* readBufferPtr` (read_write, GUESS)
- `this+0x0000002C` `unsigned int readRemaining` (read_write, GUESS)
- `this+0x00000020` `char* writeBufferPtr` (read_write, GUESS)
- `this+0x00000030` `unsigned int writeRemaining` (read_write, GUESS)

### CodecvtStreamBuffer

Buffered output stream with an optional codecvt encoding-conversion facet (this+0x38): single-character writes are buffered at this+0x20/this+0x30, converted through the facet vtable conversion entry (slot index 5) when present, and flushed to the output device at this+0x50 via FileReadWrapperWithLock.

Methods: `0x00598E9E`

- `this+0x00000020` `char* writeBufferPtr` (read_write, GUESS)
- `this+0x00000030` `unsigned int writeRemaining` (read, GUESS)
- `this+0x00000038` `void* codecvtFacet` (read, GUESS)
- `this+0x00000040` `void* conversionState` (read, GUESS)
- `this+0x00000044` `void* streamBuffer` (read, GUESS)
- `this+0x00000050` `void* outputDevice` (read, GUESS)

### CodecvtBufferedStreamReader

Buffered input stream with an optional codecvt decoding facet (this+0x38): consumes bytes from the input stream at this+0x50 through the facet do_in vtable slot +16, with a fast raw-byte path through the group pointer at this+0x1C / length at this+0x2C.

Methods: `0x005990AE`

- `this+0x0000001C` `char* groupHeadPtr` (read, GUESS)
- `this+0x0000002C` `unsigned int groupLength` (read, GUESS)
- `this+0x00000038` `void* codecvtFacet` (read, GUESS)
- `this+0x0000003C` `unsigned int savedPosition` (read_write, GUESS)
- `this+0x00000040` `void* conversionState` (read_write, GUESS)
- `this+0x00000044` `void* streamBuffer` (read, GUESS)
- `this+0x00000050` `void* inputStream` (read, GUESS)

### CrtDescriptorTable

A per-handle descriptor/file-state array rooted at dword_8D4920 with a 36-byte element stride and a flag byte at +4; DescriptorFlagSetOrClear toggles the bit-0x80 flag for a descriptor index.

Methods: `0x0059801A`


### CrtBufferObject

A reference-counted buffer object: data pointer at this+4 with a boundary marker byte at data[-1], size at this+8 and capacity at this+12; supports validate/resize with reference release and conditional detach/free before modification.

Methods: `0x00599560`, `0x005995E5`

- `this+0x00000004` `char* dataPtr` (read_write, GUESS)
- `this+0x00000008` `unsigned int size` (read_write, GUESS)
- `this+0x0000000C` `unsigned int capacity` (read, GUESS)

## Compatibility contracts

- **CrtLocaleStateGlobals** — A replacement executable must preserve the fixed-address locale/code-page state globals at 0x8D3F48 (default code page), 0x8D41D4 (auto-select flag), 0x8D4200/0x8D4204/0x8D4208 (cached Win32 locale-API modes), 0x8D46BC/0x8D46C0/0x8D46CC/0x8D48E4 (locale scalars), the 256-byte blocks at 0x8D46E0/0x8D47E0/0x8D47E1 (case/char-type tables), and the init flag at 0x8D5A4C.
- **StringTableWireFormat** — The token table at 0x8D3E90 is a null-terminated array of char* entries; each entry is a key=value string where the '=' separator at the key length is matched case-insensitively, and the value is the substring after '='. The wide source list at 0x8D3E98 supplies the table, gated by the parse flag at 0x8D5A48.
- **StreamVtableMethodIndices** — Buffered read/write streams expect vtable method at obj+0x14 (index 5) to refill/read and obj+0x4 (index 1) to flush/write; codecvt facets are invoked at vtable slot +16 (do_in) and slot +14 (conversion entry point). A replacement stream must keep these slot indices.
- **DescriptorArrayStride** — The descriptor/file-state array at 0x8D4920 has a 36-byte element stride with the flag byte at element offset +4, indexed as base + 36*(idx & 0x1F) + 4 for descriptor index idx; command values 0x8000 (clear bit 0x80) and 0x4000 (set bit 0x80) are the supported operations.
- **BufferMetadataByteLayout** — Reference-counted buffers store the data pointer at object +4, the boundary/refcount metadata byte at data[-1], size at +8 and capacity at +12; metadata states 0 and -1 (0xFF) mean no release is performed.
- **WinsockImportForwarding** — closesocket/inet_addr/sendto are thin stdcall forwards to the Winsock imports at 0x59E2E8/0x59E2F0/0x59E2F8; a replacement must resolve the same imports and preserve the forwarding call shape.
- **RefCountTeardownContract** — The subsystem reference counter at 0x5E9EF4 is guarded by a lock (acquire 0x59A54D, release 0x59A5E9); reaching zero triggers StatusCheckWithErrorDispatch over the globals 0x8D42A0/0x8D43C8/0x8D4210 as teardown.

## Unresolved

- Ownership of the string table (dword_8D3E90) and wide list (dword_8D3E98) is unknown; the table container shape is ambiguous (flat array vs linked list) and the dword_8D5A48 parse flag semantics are inferred.
- The locale init dispatcher sub_596E40 is not a packet function; LazySingletonInit's -3 literal and its dispatch to ResetLocaleState/CharTypeTableInit are inferred from caller evidence.
- Semantics of the code-page identifiers 0xFFFFFFFE/0xFFFFFFFD/0xFFFFFFFC and of mapConstant's input/output constant pairs are unknown without the caller 0x00596E40.
- The identity and role of dword_8D41D4 consumers, of the stored default CodePage source, and of the cleanup targets unk_8D42A0/dword_8D43C8/dword_8D4210 are unevidenced.
- CharTypeTableInit reads the flagged global byte_FF0000000000547C which never appears in the raw body; caller frame-path membership is NOT_FOUND.
- LocaleStreamObjectConstructSimplified builds an MSVC iostream (streambuf + std::ios + std::ostream vftables) but the concrete class hierarchy and the meaning of the this+0xC construction flag are unconfirmed.
- The codecvt facet types are unverified; the do_in/conversion vtable call shapes match std::codecvt-like facets but the concrete facet class is not identified, and the codecvt conversion state at this+0x40 is untyped.
- Semantics of the flag bit 0x80 and the status encoding (base 0x8000 plus prior-bit 0xC000) in DescriptorFlagSetOrClear are inferred; the descriptor array struct (36-byte stride) is DERIVED from index arithmetic.
- LinearSearchByID's record layout beyond the ID at +4 is unevidenced; dword_5E7894's writer/initialization and the array base the caller sub_597388 passes are unknown.
- MemoryCopyFromIDLookup and CopySixDwordsFromGlobalSource both rely on sub_59942B(-1) to select a 0x18-byte source block; the meaning of the -1 key and the source identity are unevidenced.
- BufferValidateAndResize recovers the requested size from the stack return-address slot; the 0x1F capacity threshold, the -1 marker sentinel meaning and sub_59AD49's overflow handling are unresolved.
- delegateCallWithNullGuard's owner object and the meaning of sub_59BB00's constant 0 argument and return value are unknown.
- The BufferedWriteWithFlush/BufferedReadWithFill stream class and the identities of the vtable index-1/index-5 methods are caller/constructor supplied and unknown here.
- The packet globals global:0x0058895C, global:0x005B9B68, global:0x005B9B78, global:0x005B9B88 and global:0x005B9C38 never appear in any raw body; the six high-address byte globals (0xFF00000000001692/1695/1699/169B, 0xFF0000000000547A/547C) carry impossible non-image addresses; all are treated as stale extraction/join artifacts.
- GetOEMCP/GetACP (0x0059E088/0x0059E08C) and the other API globals are import-thunk or function-pointer references; the packet does not distinguish between the two.
- CrtLocaleState per-global state is evidenced as module globals, not fields of a single this-object: default code page dword_8D3F48, auto-select flag dword_8D41D4, cached Win32 locale-API modes dword_8D4200/dword_8D4204/dword_8D4208, locale scalars dword_8D46BC/unk_8D46C0/dword_8D46CC/dword_8D48E4, the 256-byte character/type tables byte_8D46E0/unk_8D47E0/byte_8D47E1, and the one-time init flag dword_8D5A4C. The packet gives no common-ownership proof across these globals, so no field layout is asserted.
- CrtStringTable state (entry list dword_8D3E90, wide source list dword_8D3E98, parse flag dword_8D5A48) is global-backed with no common-ownership proof; documented here instead of declared as fields.
- CrtSubsystemRefCountState state (reference counter dword_5E9EF4, cleanup targets unk_8D42A0/dword_8D43C8/dword_8D4210) is global-backed with no common-ownership proof; documented here instead of declared as fields.
- CrtDescriptorTable state (per-handle descriptor array dword_8D4920, 36-byte element stride, flag byte at element +4) is global-backed; the array base has no allowed field reference in this packet, so no field layout is asserted beyond the raw index arithmetic.
