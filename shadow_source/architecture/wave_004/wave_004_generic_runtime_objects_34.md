# CrtRuntime

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

The packet covers the CRT runtime layer embedded in the game binary: a guarded file-descriptor table (dword_8D4920, 36-byte-stride per-slot rows, open count at dword_8D4A20) whose close/seek/read/write operations validate the slot, serialize on a per-slot critical section, and map OS errors to CRT errno through TLS getters; a global pool (dword_8D4A24 / dword_8D5A40) of 56-byte FILE stream objects with an embedded CRITICAL_SECTION and buffer/flags layout; text-mode read/write translation (CRLF folding, Ctrl-Z EOF bit, pushback byte, append seek-to-EOF, LF-to-CRLF expansion); a vfscanf-style formatted-input scanner plus its shared byte-sink and cursor-read helpers; character-encoding conversion with a lookup-table fast path; CRT locale data buffers; standalone strlen and overlap-aware memmove helpers; and a thread-local state object constructor. Ownership of every function is UNKNOWN in the packet; the class groupings below are DERIVED structural groupings of free functions over shared globals and objects.

## Function roles

- `0x0058C331` **CrtFileDescriptorTable** — Close CRT file descriptor: validate slot, enter per-handle critical section, close via HandleCloseWithErrorReporting, map invalid handle to TLS errno 9 / doserrno 0 and return -1
- `0x0058C38E` **CrtFileDescriptorTable** — Handle close helper: resolve OS handle, skip shared stdout/stderr pair and invalid handles, call CloseHandle, clear per-slot open-state byte, map failures to CRT errno via ErrorIDLookupTable
- `0x0058C411` **CrtFileStream** — FILE stream owned-buffer teardown (freebuf): free this+8 when flags at this+0xC have I/O bits (0x83) and ownership bit (8), clear ownership bits (0xFBF7), zero buffer fields at +0/+4/+8
- `0x0058C43C` **CrtStreamPoolManager** — Parse fopen-style mode string into flag/access words seeded from dword_8D41BC, invoke the open path sub_595AF9, increment open count dword_8D3EC8, and fill the open record a4
- `0x0058C5AC` **CrtStreamPoolManager** — Claim an inactive FILE stream slot from the pool dword_8D4A24 under the pool and per-stream critical sections, or allocate a new 56-byte stream with embedded CRITICAL_SECTION at +0x20; reset claimed stream and return it
- `0x0058C674` **CrtCharacterEncoding** — Character-code conversion: 16-bit lookup-table fast path over off_5E69C8 combined with a2, with a one/two-byte conversion fallback through sub_595DC8
- `0x0058C724` **CrtFileDescriptorTable** — Guarded file seek: validate slot index against open-file count and per-slot open flag, enter critical section, seek via FileSeekViaSetFilePointer, leave, return result; invalid path writes TLS errno 9 / doserrno 0 and returns -1
- `0x0058C789` **CrtFileDescriptorTable** — Low-level lseek: resolve OS handle, SetFilePointer with errno mapping (9 = EBADF on invalid handle), clear the per-slot EOF bit (bit 1) on success, return new file pointer
- `0x0058C7FC` **CrtFileStream** — Three-step stream operation wrapper: lock via StreamBufferLockViaCriticalSection, run inner sub_58C824, release via AddressRangeCriticalSectionLeave, return inner result
- `0x0058C9B4` **CrtFileDescriptorTable** — Guarded file read: validate slot index and per-slot active flag bit, enter critical section, read via FileReadWithTextModeTranslation, leave, return bytes read; invalid path writes TLS errno 9 / doserrno 0 and returns -1
- `0x0058CA19` **CrtFileDescriptorTable** — Low-level _read with text-mode translation: per-slot record lookup, EOF/pushback handling, ReadFile, access-denied/broken-pipe/other error mapping, CRLF folding, trailing-CR probe with pushback or rewind, Ctrl-Z EOF bit, return delivered byte count
- `0x0058CC00` **CrtStringAndMemoryHelpers** — Overlap-aware memory copy (memmove-style): backward copy when destination overlaps source, otherwise forward with DWORD-aligned bulk copies and byte-granular remainder; returns destination
- `0x0058D78E` **CrtFormattedIo** — Buffered single-byte stream output sink: decrement remaining-buffer count a2[1], hand exhausted buffers to sub_58CF35, else store at *a2 and advance; track error/count through a3
- `0x0058D7C3` **CrtFormattedIo** — Descending output loop: iterate StreamByteOutputWithBufferManagement over a pointer starting one dword behind a2, terminating on the -1 sentinel at a4, return last accepted pointer
- `0x0058D7F4` **CrtFormattedIo** — Char-by-char output loop with terminator check: feed input bytes through StreamByteOutputWithBufferManagement until the shared status dword at a4 becomes -1
- `0x0058D82C` **CrtFormattedIo** — Advance caller-owned dword pointer slot by 4 bytes and return the 32-bit value just before the advance
- `0x0058D839` **CrtFormattedIo** — Advance caller-owned dword pointer slot by 8 bytes and return the 64-bit value just before the advance
- `0x0058D849` **CrtFormattedIo** — Advance caller-owned pointer slot by 4 bytes and return the signed 16-bit value just before the advance (2-byte read with 4-byte pointer step)
- `0x0058E0B4` **TlsThreadLocalState** — Thread-local state object constructor: install function-pointer block unk_5E7810 at +0x50 and set the dword field at +0x14 to 1, returning the object pointer
- `0x0058E12E` **CrtLocaleRuntime** — Locale/encoding detection: parse input string, choose OEM (512) or ANSI (128) / Unicode-DBCS (0x100) encoding words, store encoding at this+0, consumed byte count at this+4, double at this+0x10
- `0x0058E1B0` **CrtStringAndMemoryHelpers** — strlen: alignment check, byte-wise probe loop, word-wise zero-byte detection trick, per-byte fallback; returns byte length before the first null
- `0x0058E22B` **CrtFileDescriptorTable** — Locked file-write wrapper: validate slot index and per-slot flag bit 0, enter critical section, delegate to FileWriteWithTextTranslation, leave, return result; invalid path writes TLS errno 9 / doserrno 0 and returns -1
- `0x0058E290` **CrtFileDescriptorTable** — Low-level _write with text translation: append-mode seek-to-EOF, binary direct WriteFile or text-mode LF-to-CRLF chunked translation, access-denied/other error mapping, ENOSPC on zero-length write without error
- `0x0058E4D2` **CrtFormattedIo** — vfscanf-style formatted input scanner: integer/float/string/scan-set/%n conversions with width, suppression, length modifiers, charset classification, whitespace skip, and conversion-count/EOF return
- `0x0058EF2E` **CrtFileStream** — Buffered byte read from a FILE stream (fgetc-style): decrement count at this+4, refill via sub_58C255 when exhausted, else return byte at this+0 cursor and advance
- `0x0058F4F2` **CrtLocaleRuntime** — Locale number-formatting buffer init: query locale data for grouping/leading-zero/decimal-separator, strip semicolons from the separator, publish three buffers into off_5E9AC0 and the separator byte into 0x005E6BD8; or allocate empty defaults

## Proposed classes

### CrtFileDescriptorTable

CRT file-descriptor table layer: validates slot indices against the open-file count, guards per-slot critical sections, and implements close/seek/read/write with OS-error-to-errno mapping through TLS getters.

Methods: `0x0058C331`, `0x0058C38E`, `0x0058C724`, `0x0058C789`, `0x0058C9B4`, `0x0058CA19`, `0x0058E22B`, `0x0058E290`


### CrtFileStream

The pooled FILE stream record: cursor/count/base/flags/handle layout with an embedded critical section, owned-buffer teardown, buffered byte reads, and locked operation wrappers.

Methods: `0x0058C411`, `0x0058C7FC`, `0x0058EF2E`

- `this+0x00000000` `char* ptr` (read_write, DERIVED)
- `this+0x00000004` `int count` (read_write, DERIVED)
- `this+0x00000008` `char* base` (read_write, DERIVED)
- `this+0x0000000C` `unsigned short flags` (read_write, DERIVED)
- `this+0x00000010` `int handle` (write, DERIVED)

### CrtStreamPoolManager

Global FILE stream pool: claims inactive slots from dword_8D4A24 or allocates new 56-byte streams under the pool critical sections, and parses fopen mode strings into open records.

Methods: `0x0058C43C`, `0x0058C5AC`


### CrtCharacterEncoding

Character-code conversion via a 16-bit lookup table fast path over off_5E69C8, with a one/two-byte multi-byte conversion fallback through sub_595DC8.

Methods: `0x0058C674`


### CrtFormattedIo

Formatted I/O internals: the vfscanf-style input scanner plus shared stream byte-sink and cursor-read helpers used by the format engine around the shared caller sub_58D04D.

Methods: `0x0058D78E`, `0x0058D7C3`, `0x0058D7F4`, `0x0058D82C`, `0x0058D839`, `0x0058D849`, `0x0058E4D2`

- `this+0x00000000` `void** cursorSlot` (read_write, GUESS)

### CrtStringAndMemoryHelpers

Standalone C string/memory helpers: strlen byte-length computation and overlap-aware memmove-style copy.

Methods: `0x0058CC00`, `0x0058E1B0`


### TlsThreadLocalState

Per-thread TLS/locale state object: installs a function-pointer block and sets a state flag during thread-local setup.

Methods: `0x0058E0B4`

- `this+0x00000050` `void* vtableBlock` (write, DERIVED)
- `this+0x00000014` `int initFlag` (write, GUESS)

### CrtLocaleRuntime

CRT locale initialization: encoding detection from locale strings and locale number-formatting buffer setup (grouping, leading-zero, decimal separator).

Methods: `0x0058E12E`, `0x0058F4F2`

- `this+0x00000000` `unsigned short encodingWord` (write, DERIVED)
- `this+0x00000004` `int consumedByteCount` (write, DERIVED)
- `this+0x00000010` `double parsedDouble` (write, DERIVED)

## Compatibility contracts

- **CRTFileDescriptorSlotContract** — A replacement must preserve: slot-index validity against the open-file count, per-slot open flag bit 0 in the 36-byte-stride handle table, per-slot critical-section serialization for close/seek/read/write, and the TLS errno 9 / doserrno 0 write on invalid handles.
- **FILEStreamBufferOwnership** — FILE stream teardown must free the owned buffer only when flags carry I/O bits ((flags & 0x83) != 0) and the ownership bit ((flags & 8) != 0), then clear the ownership bits (mask 0xFBF7) and zero the buffer fields at +0/+4/+8.
- **TextModeReadWriteTranslation** — Text-mode I/O must fold CRLF to LF on read, set the Ctrl-Z EOF bit (0x02) unless bit 0x40 is set, handle trailing-CR pushback or -1 rewind, expand LF to CRLF on write in chunks, and seek to end-of-file when the append flag (bit 0x20) is set.
- **FormattedInputScanning** — Formatted input must support integer, float, string, scan-set and %n conversions with width limits, assignment suppression, length modifiers, charset classification, and return the conversion count or -1 on EOF with no conversions.
- **LocaleEncodingWordValues** — Locale/encoding detection must produce encoding words 512 (OEM), 128 (ANSI/SBCS) and 0x100 (Unicode/DBCS, OR-able), and locale init must publish the decimal separator first byte to the global at 0x005E6BD8 with the init flag at 0x005E6BDC set to 1.

## Unresolved

- Every function owner in the packet is UNKNOWN; the class groupings are DERIVED structural groupings of free functions over shared globals/objects, not proven original C++ classes.
- The 56-byte pooled stream record is not proven to be the CRT FILE object; its layout matches the descriptor layout seen in neighboring stream functions, and merging fields of 0x0058C411/0x0058C5AC/0x0058EF2E into one CrtFileStream base is a DERIVED interpretation.
- AllocateStreamStructure documents an embedded CRITICAL_SECTION at stream +0x20 and a dword field at index 7 (+0x1C) that is reset to 0, but those offsets are not modeled as class fields because the packet carries no field:this evidence refs for 0x1C or 0x20.
- sub_58C824, the inner locked operation of the streamLockedThreeStepWrapper (0x0058C7FC), is not in the packet; what it performs under the lock is unestablished.
- sub_58D04D, the shared caller of the byte-sink helpers (0x0058D78E/0x0058D7C3/0x0058D7F4) and the cursor-read helpers (0x0058D82C/0x0058D839/0x0058D849), is not in the packet; the printf/scanf-engine role is inferred from the call graph only.
- The 36-byte stride and +4 flag-byte layout of the handle table dword_8D4920 is taken from raw source arithmetic; the row structure beyond the flag byte is unproven.
- TLS error codes (9 = EBADF, 28 = ENOSPC) and the ErrorIDLookupTable (0x0058AF5C) mapping are CRT conventions assumed from behavior, not evidenced in the packet.
- Locale encoding constants 512 (OEM) / 128 (ANSI) / 0x100 (Unicode/DBCS) are caller-visible; concrete code-page interpretations live outside the packet.
- CharacterEncodingConvertViaLookupTableFallback (0x0058C674) combines a2 via bitwise AND with table entries and the high word of CharType; the caller contract for a2 is not in the packet, so semantics stays MEDIUM.
- LocaleDataBufferInit (0x0058F4F2) has a naming conflict: the ABI legacy name suggests an audio codec role while the raw source shows CRT locale number-formatting initialization; the raw-source interpretation is preferred.
- FormattedInputScanFromIO (0x0058E4D2) lists callee AmsgExitRuntimeError (0x00595733) in the packet but it is absent from the raw decompiled source; likely a fatal/abort path not represented in this decompilation.
- field:this offsets +1 and +2 are decompiler dereference artifacts (tail-copy and strlen byte probes), not real object fields.
- word_5BEB48 is listed among the packet globals but is never referenced by the raw source of these functions; its role here is unknown.
- The cursor-read helpers 0x0058D82C/0x0058D839/0x0058D849 operate on caller-owned pointer slots (a1), not a class instance field; modeling them under CrtFormattedIo is a GUESS grouping.
- Whether StreamBufferLockViaCriticalSection (0x0058C1B1) and AddressRangeCriticalSectionLeave (0x0058C203) guard the same underlying critical section is inferred from naming, not proven here.
- Semantics of sub_595DC8 (7-argument conversion helper) and sub_595A1F (OS-handle resolution) are unproven beyond the roles inferred from their callers.
