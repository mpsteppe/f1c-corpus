# RuntimeInfrastructure

Scope: `generic_runtime_objects`  
Trust: `GUESS`

Proposed DERIVED grouping of generic runtime stream and helper functions in the 0x0059BAE8-0x0059D948 range. The bulk of the packet is one shared stream-descriptor object (StreamDescriptor): StreamWriteWChar writes a single WCHAR (wide direct store with 16-bit flush via 0x0059C1E7, or narrow multibyte conversion via sub_596030 with byte-wise flush via sub_58CF35); StreamUngetWChar pushes a WCHAR back through a lazily initialized buffer; StreamReadWChar reads a WCHAR (wide 2-byte read with refill via 0x0059C30E, or narrow 1-2 byte read with lead-byte detection through the off_5E69C8 table and conversion via sub_596716); FputwcCharacterWrite is the 16-bit output twin of sub_58CF35; sub_59C30E reads one 16-bit word with buffer refill via sub_58C9B4; FileSeekWithModeFlagValidation performs mode-validated seeking. All six share the descriptor layout (+0x0 cursor, +0x4 counter, +0x8 buffer base, +0xC flags, +0x10 file handle/index, +0x18 buffer size) and the same file-state descriptor resolution (default unk_5E7898 when index is -1, else dword_8D4920 stride 36). ThreadSafeFileIO wraps the seek operation behind the thread-safe wrapper 0x0059C127 through a DWORD-pair forwarding shim. ExceptionFrameTeardown is the MSVC exception-destructor-and-optionally-free helper. HudFlagSetter computes a byte via an external helper and writes it into the HUD flag cell at dword_5C7530 + 128. Ownership of every function is UNKNOWN per the packet; the class boundaries are organizational proposals, not proven classes.

## Function roles

- `0x0059BAE8` **ThreadSafeFileIO** — cdecl forwarding wrapper: unpacks a DWORD pair from the second argument a2 and forwards a1, a2[0], a2[1] and the literal 0 to ThreadSafeWrapper (0x0059C127), returning its result unchanged. Invoked by sub_59A221 (0x0059A221) as an indirection layer into ThreadSafeWrapper.
- `0x0059BBD9` **StreamDescriptor** — Stream output writer for a single wide character (__cdecl, WCHAR a1 into a stream buffer descriptor at a2). In wide mode (stream mode byte at a2+12 has bit 0x40 set, or the associated file-state descriptor reports a valid state) the WCHAR is stored directly and the cursor advanced by 2, flushing via FputwcCharacterWrite (0x0059C1E7) when the remaining-space counter at a2+4 underflows. In narrow mode the character is converted to a multibyte sequence by sub_596030 (1 or 2 bytes, or -1 on conversion error which sets TLS error 42 and returns -1), written byte-by-byte while decrementing the per-byte counter, flushing via sub_58CF35 on underflow. Returns a1 on success or -1 on any failure.
- `0x0059BCFC` **StreamDescriptor** — Pushes a WCHAR character back into an input stream buffer (analogous to ungetwc). Rejects WEOF (0xFFFF) and invalid stream state, lazily initializes the buffer via MemoryAllocatorInit (0x005957BD), then either stores the character directly (wide mode) or converts it to a multibyte sequence via sub_596030 and pushes the bytes (narrow mode). Mode is selected by a stream flag bit (0x40) or a per-encoding descriptor byte; the descriptor comes from the global default unk_5E7898 or the dword_8D4920 array keyed by stream[4]. On conversion failure it stores error 42 in the TLS slot from TLSOffsetGetter (0x0058AFCF) and returns -1. Only static caller is StreamReadWrapperWithLockUnlock (0x0059BCD2).
- `0x0059BE0C` **StreamDescriptor** — Reads one WCHAR from an input stream. In wide mode (flag bit 6 set at this+0xC) it consumes 2 bytes directly from the buffer at this+0x0, decrementing the remaining-byte counter at this+0x4 by 2 and refilling via sub_59C30E (0x0059C30E) on underflow. In narrow mode it reads 1-2 bytes (via sub_58C255 on underflow, or directly), using the off_5E69C8 character-type table to detect a lead byte that requires a second byte, and converts the byte sequence to a WCHAR with sub_596716. A file-index field this+0x10 equal to -1 selects the default descriptor unk_5E7898; otherwise the file-state array dword_8D4920 (stride 36) is indexed by (index>>5) and (index&0x1F). On read or conversion failure it returns -1, optionally calling FileIOWrapperWithLock (0x0059685F) and storing error code 42 via TLSOffsetGetter (0x0058AFCF). Returns the WCHAR as a 16-bit value on success.
- `0x0059BEFD` **ExceptionFrameTeardown** — MSVC exception-frame teardown helper (__thiscall): runs the standard MSVC exception destructor MSVCExceptionDestructor (0x0059BFA0) on the exception object, then conditionally frees the object via FreeWrapper_7bcf (0x00587BCF) when the flag bit (a2 & 1) is set, and returns the object pointer. Used on the compiler-generated exception cleanup path.
- `0x0059C156` **StreamDescriptor** — File stream seek with mode-flag validation. Reads the mode flags at this+0xC; if (flags & 0x83) is zero or the seek origin a3 exceeds 2 it sets the TLS error slot to 22 (EINVAL) via TLSOffsetGetter (0x0058AFCF) and returns -1. Otherwise it clears bit 0x10 of the flags, optionally (a3==1) adds sub_58C824(a1) to the requested offset for a relative seek, flushes buffered writes with BufferFlushWrite (0x0058A05A), conditionally resets the +0x18 field to 512 or clears the low two flag bits, performs the seek via sub_595F11(this+0x10 handle, offset), and returns 0 on success / -1 on failure. Called by ThreadSafeWrapper (0x0059C127).
- `0x0059C1E7` **StreamDescriptor** — 16-bit twin of the CRT character-output helper sub_58CF35 (FputcCharacterWrite): writes one 16-bit value a1 through the stream object a2, switching read-mode streams to write mode, lazily allocating a stream buffer (skipping the sentinel streams unk_5E6768 / unk_5E6788 when sub_596007 reports them), advancing the write cursor by two, flushing the existing buffer via sub_58E22B when full, and falling back to a direct two-byte write for unbuffered streams. Returns a1 on success and 0xFFFF with error bit 0x20 set on failure.
- `0x0059C30E` **StreamDescriptor** — Reads one 16-bit word from a buffer described by a pointer-array descriptor (a1). Consults a flag/status byte at a1[3] (this+0xC): fails fast on reserved bits, forces the in-progress bit on retry, rewinds to the base buffer (a1[2], this+0x8) when a continue bit is set or allocates through MemoryAllocatorInit (0x005957BD) otherwise, fills the buffer via sub_58C9B4(index at this+0x10, base, size at this+0x18), validates the returned size, conditionally widens the requested read size from 512 to 4096, and returns the next word at the this+0x0 cursor while advancing it, recording usable content size at this+0x4. Structural twin of sub_58C255 per cluster prelabel.
- `0x0059D948` **HudFlagSetter** — Sets a single-byte global flag from a computed value, then forwards the HUD render path. Calls ShortComputation_bad0 (0x0049BAD0) to produce a byte, stores it at dword_5C7530 + 128, and returns the result of the HUD-flag renderer (named in source only) called with that byte, literal 0, and the two original arguments a1/a2.

## Proposed classes

### StreamDescriptor

Buffered CRT-style stream object over an OS file handle. Holds the read/write cursor at +0x0, the remaining/space byte counter at +0x4, the buffer base at +0x8, the mode/state flag word at +0xC, the OS file handle or file index at +0x10 and the buffer size at +0x18. Methods implement single-WCHAR write, unget and read (each selecting a wide direct path or a narrow multibyte-converted path from the same descriptor state), buffered 16-bit word refill, 16-bit character output, and mode-validated seeking. A per-handle file-state descriptor is resolved from the default unk_5E7898 when the +0x10 index is -1, else from the dword_8D4920 descriptor array (stride 36, mode byte at +4). Flag-bit semantics and the descriptor's exact structure beyond the evidenced offsets are not established by the packet.

Methods: `0x0059BBD9`, `0x0059BCFC`, `0x0059BE0C`, `0x0059C156`, `0x0059C1E7`, `0x0059C30E`

- `this+0x00000000` `BYTE* buffer_cursor` (read_write, DERIVED)
- `this+0x00000004` `int remaining_bytes` (read_write, DERIVED)
- `this+0x00000008` `BYTE* buffer_base` (read, DERIVED)
- `this+0x0000000C` `WORD mode_flags` (read_write, DERIVED)
- `this+0x00000010` `int file_handle_or_index` (read, DERIVED)
- `this+0x00000018` `DWORD buffer_size` (read, DERIVED)
- `obj+0x00000000` `WORD buffered_word` (read, GUESS)

### ThreadSafeFileIO

Thread-safe file-I/O indirection layer. A cdecl forwarding wrapper unpacks a DWORD pair from its second argument and forwards it with a literal zero to the thread-safe serialization wrapper (0x0059C127); the mode-validated seek (0x0059C156) is one of the operations run under that wrapper. The wrapper's exact contract is not established by the packet.

Methods: `0x0059BAE8`


### ExceptionFrameTeardown

MSVC exception-frame teardown helper. Runs the standard MSVC exception destructor on the exception object and, when a flag bit is set, releases the object's allocation, then returns the object pointer unchanged (the MSVC destructor-wrapper convention). The concrete exception/object type is not evidenced.

Methods: `0x0059BEFD`


### HudFlagSetter

Computes a single byte via an external helper (ShortComputation_bad0, 0x0049BAD0), writes it into the HUD flag cell at dword_5C7530 + 128, and forwards to the HUD-flag renderer with the original arguments. The renderer is named in the raw source but carries no callee-address evidence in the packet.

Methods: `0x0059D948`


## Compatibility contracts

- **wchar_stream_write_contract** — StreamWriteWChar must return the written WCHAR on success and -1 on any failure. On multibyte conversion error it must store error code 42 in the TLS slot returned by TLSOffsetGetter. Buffer flushing is delegated to FputwcCharacterWrite (0x0059C1E7) in wide mode and to sub_58CF35 in narrow mode.
- **wchar_stream_unget_contract** — StreamUngetWChar must reject WEOF (0xFFFF) and invalid stream state, lazily initialize the stream buffer via MemoryAllocatorInit when absent, push the WCHAR either directly (wide mode) or as a converted multibyte sequence (narrow mode), and store TLS error 42 on conversion failure. Returns the pushed WCHAR on success, -1 on failure.
- **wchar_stream_read_contract** — StreamReadWChar must return the WCHAR as a 16-bit value on success and -1 on EOF, read, or conversion failure. Wide mode refills via sub_59C30E on underflow; narrow mode reads bytes via sub_58C255, detects lead bytes through the off_5E69C8 character-type table, and converts the byte sequence with sub_596716.
- **stream_descriptor_layout** — Stream descriptor layout consumed by the stream methods: +0x0 read/write cursor, +0x4 remaining/space byte counter, +0x8 buffer base, +0xC mode/state flag word (bit 0x40 wide mode, bit 0x20 error, bit 0x10 read/EOF, buffered-stream markers 0x10C), +0x10 OS file handle or file index, +0x18 buffer size. A file index of -1 selects the default descriptor unk_5E7898; otherwise dword_8D4920 is indexed by (index>>5) and (index&0x1F) with stride 36 and a mode byte at +4.
- **seek_mode_validation_contract** — Stream seek must validate the mode flags (mask 0x83 non-zero) and the seek origin (<= 2), storing TLS error 22 (EINVAL) via the TLS offset getter on failure. On success it clears flag bit 0x10, flushes buffered writes via BufferFlushWrite before seeking, optionally adds the position-query result of sub_58C824 for a relative seek, and performs the seek through the handle at +0x10 via sub_595F11.
- **msvc_exception_teardown_contract** — Exception teardown must run the standard MSVC exception destructor on the object and, when the free flag bit is set, release the object's allocation, returning the object pointer unchanged (the MSVC destructor-wrapper convention).
- **hud_flag_cell_write** — The HUD flag cell at dword_5C7530 + 128 is written as a single byte computed by an external helper; the following HUD-flag render call receives that byte, a literal 0, and the two original arguments.

## Unresolved

- The meaning of the packed DWORD pair in a2 (and the literal 0) and the operation ThreadSafeWrapper (0x0059C127) performs are not established by the packet.
- The exact contract of sub_596030 (return codes beyond -1/1/2 and how the multibyte sequence is produced) is not established from the packet alone.
- The file-state descriptor array dword_8D4920 (stride 36, mode byte at +4) and the default descriptor unk_5E7898 layout are DERIVED from the indexing arithmetic only, not confirmed.
- The stream buffer descriptor internal structure (cursor/counter split at v2[0]/v2[1] and the +0x18 reset to 512 as a buffer size) is inferred from usage, not confirmed.
- Stream flag-bit meanings (0x82, 0x40, 0x10, 0x10C, 0x108, 0x83, 0xFC, 0x400, 0x80) are unverified; the roles of fields a2[1], a2[2], a2[6] in FputwcCharacterWrite are inferred, a2 being an opaque stream object not in the packet field list.
- The off_5E69C8 lead-byte/character-type table and the DBCS/code-page semantics of the narrow-mode conversion are inferred (DERIVED), not confirmed.
- In FileSeekWithModeFlagValidation v8 is read in the success test before any assignment in the decompiled body; the exact success/error discriminator (likely the return of sub_595F11) is not settled, and the role of sub_58C824 as a position query is inferred.
- The return expression HIWORD(a1) in StreamReadWChar is a Hex-Rays artifact of __cdecl frame reuse; the concrete register path carrying the WCHAR result is not grounded.
- In sub_59C30E the flag-bit semantics (0x83/0x40/0x2/0x20/0x1/0x10C/0x82/0x8) and the flag high-byte bits are unknown; the purpose of sub_58C9B4, the descriptor index at +0x10, and the dword_8D4920 descriptor table is unknown. The structural-twin relation to sub_58C255 is DERIVED from cluster prelabel and not independently confirmed.
- ExceptionDestructorWithFlag's concrete exception/object type and the free-flag semantics beyond bit 0 are not evidenced.
- HUDFlagRendererSecondary has no callee address evidence in the packet (named in the raw source only); the meaning of the byte stored at dword_5C7530 + 128 is not derivable from this packet.
- The class groupings (StreamDescriptor, ThreadSafeFileIO, ExceptionFrameTeardown, HudFlagSetter) are DERIVED organizational proposals; per-function ownership is UNKNOWN in the packet and equal offsets on different this-pointers were not merged.
- The caller relationship of the seek to ThreadSafeWrapper (0x0059C127) and the flush relationship of StreamWriteWChar to sub_59BBD9's buffer path are noted only as unresolved caller evidence; the callers are not analyzed.
