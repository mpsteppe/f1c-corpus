# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Reconstructs the generic runtime object layer from 24 validated functions. One DERIVED class StreamWriter (0x00599ED6, 0x0059A01E, 0x0059A103, 0x0059A3A9, 0x0059A948, 0x0059A5FE, 0x00599707) owns the buffered stream/writer layout: ios state at 0x08, codec/facet pointer at 0x38 with vtable slots +0x10 (format conversion) and +0x14 (encode), output buffer object at 0x44 (data +4, capacity +8), and stream/file handle at 0x50; it covers token writes, wide-char reads, putback validation and construction. A DERIVED CodeCvtFacet (0x0059B0F5, 0x0059B208) drives stateful multibyte-to-wide conversion through MultiByteToWideChar with a lead-byte table. A DERIVED FileHandleManager (0x0059B650, 0x0059B760) manages the 36-byte-per-slot open-file table at 0x008D4920. A DERIVED StlExceptionHelpers (0x0059AD49, 0x0059AF17, 0x0059AF68, 0x0059AFFF, 0x0059BACC) constructs std::length_error / std::out_of_range / std::ios_base::failure and the scalar-deleting destructor. A DERIVED CrtOneTimeInitGuard (0x005997CB, 0x00599AD9) guards locale/CEH one-time initialization and its reference-count cleanup. DERIVED GrowableBuffer (0x0059964A) and BitmapAllocation (0x0059B490) grow byte/bit buffers with 32-byte rounding and geometric growth. GUESS LocaleFacetObject (0x0059A2D0, 0x0059A2FE) and TwinPointerOwner (0x0059B390) hold weakly evidenced delegate-dispatch and dual-free behavior. One function (0x00599796) is an empty nullsub with UNKNOWN owner. No defensible state machine is proposed.

## Function roles

- `0x0059964A` **GrowableBuffer** — Grows a buffer object: rounds the requested size at this+0x8 up to a 32-byte boundary, allocates capacity+2 bytes (extra byte carries a boundary marker) via OperatorNewNhMallocWrapper, copies min(old size, new capacity) bytes through MemoryCopy_cc00, releases the old buffer via ReferenceCountDecrementWithConditionalFree, relinks the old buffer data/size/capacity fields and returns the new data pointer. SEH-protected with landing pads at 0x005996A8 and 0x0059D2FC.
- `0x00599707` **StreamWriter** — Backward buffer scan: walks a3 bytes of the buffer at a1 (one-past-end cursor), handing each byte to FileIOWrapperWithLock against the stream object a2; returns 1 when every byte is accepted, 0 on the first -1 sentinel. A residual drain block calling StreamGetcWithUnderflowHandler is unreachable as written. Called by CharValidationAgainstEncodingTableWithLocaleFall (0x00598FD4) and PutbackOrValidateCharWithStreamRead (0x0059A01E).
- `0x00599796` **UnknownObject** — Empty stub (nullsub_121): empty body, no writes, calls or branches; invoked by sub_579FB0 and sub_579FF0 as a no-op hook/placeholder slot.
- `0x005997CB` **CrtOneTimeInitGuard** — One-time locale/CEH static initializer: installs an SEH handler (SEHHandlerInit), guards first call via the dword_5EA04C counter through the enter/leave frame pair sub_59A54D / sub_59A5E9, then constructs a chain of locale/CEH static objects. Deterministic facts also record a read of global unk_8D4438 whose site is absent from the raw body.
- `0x00599AD9` **CrtOneTimeInitGuard** — Reference-count decrement with cleanup: post-decrements the global counter at 0x005EA04C inside the sub_59A54D / sub_59A5E9 frame pair; when the counter reaches zero dispatches StatusCheckWithErrorDispatch cleanup on byte_8D4568, dword_8D4400 and dword_8D4440, returning the last dispatch result.
- `0x00599ED6` **StreamWriter** — Writes a 16-bit token into the buffered stream, returning the token on success, 0 for the 0xFFFF sentinel, -1 on failure. Fast in-memory path via StreamBufferPointerAdjust when the buffered count (*(this+0x20)) fits within the capacity limit (*(this+0x30)). Main path resets/expands the output buffer at this+0x44 (BufferTruncationShrink, BufferAppendWithMemset, BufferBoundaryMarkerCheckSet), invokes the codec's virtual encode slot (*(*(this+0x38)+0x0)+0x14), then reads back the consumed bytes with FileReadWrapperWithLock, with a ThreeStepStreamQuery fallback when the codec at this+0x38 is absent.
- `0x0059A01E` **StreamWriter** — Validates a character for putback or output: on the encoding-table path (length at *(this+0x1C), putback state at *(this+0xC)) matches the char or the 0xFFFF end sentinel, calls PointerOffsetAdjuster and returns the char. Otherwise, with an output device at this+0x50, either runs CharByCharBackwardScanWithValidation over the buffered data (*(this+0x44)+4, capacity *(this+0x44)+8) and truncates the buffer (BufferTruncationShrink, BufferBoundaryMarkerCheckSet), copying this+0x3C into this+0x40, or writes the byte via StreamReadWrapperWithLockUnlock. Returns the char on success, -1 on failure.
- `0x0059A103` **StreamWriter** — Locale-aware wide-character extraction: fast path returns the buffered code unit via StdGninc when buffered count (*(this+0x1C)) is below count + 2*capacity (*(this+0x2C)). Main path drains the stream at this+0x50 byte-by-byte through the conversion buffer at this+0x44 (StreamGetcWithUnderflowHandler, BufferAppendWithMemset, BufferBoundaryMarkerCheckSet), invoking the locale facet's virtual format-conversion slot (*(*(this+0x38)+0x0)+0x10) with the marker pair this+0x3C/this+0x40; on the copy-back result memcpy's 2 bytes from the buffer data (*(this+0x44)+4) when capacity is at least 2. Without a facet it delegates to IOFormatWrapper, mapping -1 to failure.
- `0x0059A2D0` **LocaleFacetObject** — Encoding-check delegate dispatch: reads the delegate pointer at this+0x50; returns 0 when it is NULL or the delegate sub_59BB00(v4, a2, 0, 2*a3) reports failure, otherwise returns this. Structural twin of 0x00599232, differing only in doubling a3.
- `0x0059A2FE` **LocaleFacetObject** — Conditional delegate call: reads this+0x50; when non-zero invokes LockCallUnlockWrapper(this+0x50) and returns -1 when the call reports a negative result, otherwise 0. Structural twin of ConditionalDelegateCallWithNullGuard (0x00599232) per the DERIVED cluster prelabel.
- `0x0059A3A9` **StreamWriter** — Stream object construction: stores the handle parameter at this+0x28, resets the init flag at this+0x2C to 0, writes a single space byte (32) through the stream via SingleByteWriteViaStream storing the 16-bit result at this+0x30, initializes remaining fields via StructFieldInitWithConditionalCall, opens the stream via sub_59A5FE when the stored handle is null (setting bit 2 on the flags word at this+0x4), and finalizes via sub_59A8FA when a3 is non-zero.
- `0x0059A5FE` **StreamWriter** — Checks iostream state bits and throws std::ios_base::failure when error bits are set: masks the state dword at this+0x8 with 7 and combines it with a stored mask; throws immediately via CxxThrowException8 when the byte at this+0xC is set, otherwise selects the message literal (aIosBadbitSet / aIosFailbitSet / aIosEofbitSet), copies the byte at this+0xF into the exception context, writes the message via Strlen + BufferWriteWithNullTerminate, installs the ios_base::failure vftable and throws with its typeinfo. Returns the masked state when no error bits are set.
- `0x0059A948` **StreamWriter** — Struct field initializer: acquires the locale refcount on this+0x8 via LocaleRefcountAcquireUnderLock, then writes the six dword fields at 0x8, 0xC, 0x10, 0x14, 0x18 and 0x1C to 0, 513, 6, 0, 0 and 0; finally returns sub_59A5FE(a2, 0, 0). Called by ObjectInitWithVTableFlagSet (0x005993EB) and StreamCreationWithFlagInit (0x0059A3A9).
- `0x0059AD49` **StlExceptionHelpers** — STL exception construction that throws std::length_error with message 'string too long': installs the SEH frame, builds the message buffer (reference release then BufferWriteWithNullTerminate), constructs the logic_error base via CExceptionInitHandler_ada3, points the throw block at the length_error vftable and throws via CxxThrowException8 with the __TI3?AVlength_error@std@@ typeinfo. The trailing tail call to CExceptionInitHandler_ada3(a2) is unreachable.
- `0x0059AF17` **StlExceptionHelpers** — Exception-throw helper raising std::length_error: initializes the exception vtable via VTableConstructor, throws through CxxThrowException8 with the type-info descriptor at 0x005BB890, then runs ExceptionDestructor cleanup on the saved frame; if the stack record allocation flag bit 0 is set, releases the heap-allocated exception object via FreeWrapper_7bcf before returning it.
- `0x0059AF68` **StlExceptionHelpers** — Constructs and throws std::out_of_range with message 'invalid string position': registers an SEH handler frame, releases the prior stack buffer reference, writes the message (Strlen + BufferWriteWithNullTerminate), initializes the exception object via CExceptionInitHandler_ada3, sets the out_of_range vtable and throws via CxxThrowException8 with the __TI3?AVout_of_range@std@@ typeinfo. The trailing destructor call is the decoded SEH unwind epilogue.
- `0x0059AFFF` **StlExceptionHelpers** — Exception throw wrapper for std::out_of_range: constructs the exception object with a vtable via ObjectInitWithVTable_b038, throws via CxxThrowException8 with the __TI3?AVout_of_range@std@@ typeinfo over a stack buffer, runs the SEH unwind cleanup ExceptionObjectDestructorWithSEH, and when the allocation flag bit is set frees the heap-allocated object via FreeWrapper_7bcf before returning the object pointer.
- `0x0059B0F5` **CodeCvtFacet** — Stateful multibyte-to-wide decode step (cdecl): guards on input bytes/length, writes a null wide char for a zero first byte, defaults locale (dword_8D3F38) and code page (dword_8D3F48) unless an LCID pair is supplied, then drives MultiByteToWideChar (import 0x0059E12C) with flags 9: a resumable path using the cbMultiByte global (0x005E6BD4), a direct single-byte path when off_5E69C8[0][v5] is non-negative, and a lead-byte path returning -2 when more input is needed. On failure stores 42 through TLSOffsetGetter and returns -1. Structural twin of sub_596773 (0x00596773) per cluster note.
- `0x0059B208` **CodeCvtFacet** — Single-byte stream operation (cdecl): returns -1 immediately for the -1 sentinel byte; otherwise materializes the byte, zeroes a local buffer, calls sub_59B092 to transfer one byte and report a WCHAR, returning the WCHAR on success or -1 on failure. Invoked by StreamCreationWithFlagInit (0x0059A3A9) during stream-state initialization.
- `0x0059B390` **TwinPointerOwner** — Dual-pointer free: calls FreeWrapper_7bcf on the pointer at this[0] (offset 0x0), then on the pointer at this[2] (offset 0x8) and returns the second call's result. No guards or branches.
- `0x0059B490` **BitmapAllocation** — Grows a bitmap/buffer allocation when the requested bit capacity (a2 + this+0x10) exceeds 8 * the current byte size (this+0x4): grows geometrically by stride this+0x18 with a hard cap of 128000 bytes, allocates a new buffer via OperatorNewNhMallocWrapper, copies the old contents, frees the old buffer via FreeWrapper_7bcf, and updates this+0x0 and this+0x4. Returns 1 on success/no-growth, 0 only when allocation fails.
- `0x0059B650` **FileHandleManager** — Duplicates the open file handle of slot a1 into a newly allocated slot: validates the slot against the open count and in-use flag, enters the per-file critical section, allocates a free slot index, duplicates the handle via DuplicateHandle (DUPLICATE_SAME_ACCESS), stores it into the new slot, clears the source status flag bit 4 on success, and returns the new slot index, or -1 with a TLS error code (24 on allocation failure, 9 on guard failure) mapped through ErrorIDLookupTable.
- `0x0059B760` **FileHandleManager** — Queries an open file slot (index a1 guarded by the open-file count and slot in-use flag) and fills a caller result buffer with type/size/timestamp information: disk files (GetFileType 1) take the GetFileInformationByHandle path with per-time FILETIME-to-systemtime conversion and compressed datetime via sub_591EDF; character devices (2) and pipes (3) get a minimal header plus an available-data count (PeekNamedPipe for pipes). Failures set TLS error 9 via TLSOffsetGetter, map GetLastError through ErrorIDLookupTable and return -1.
- `0x0059BACC` **StlExceptionHelpers** — Scalar-deleting destructor pattern: unconditionally runs the real destructor TypeInfoDestructor on this, then when the low bit of the deleting-destructor flag a2 is set releases the object itself through FreeWrapper_7bcf(this). Returns this unchanged in both paths.

## Proposed classes

### StreamWriter

Buffered stream/writer object: ios state dword at 0x08 masked with 7, flags/state words at 0x04/0x0C/0x10 with literals 513 and 6 plus zeroed 0x14/0x18/0x1C, encoding-table pointer at 0x1C, buffered-count pointer at 0x20, stored handle at 0x28, capacity/init flag at 0x2C, I/O result at 0x30, codec/facet pointer at 0x38 (vtable slots +0x10 format conversion and +0x14 encode), marker pair at 0x3C/0x40, output buffer object at 0x44 (data pointer +4, capacity +8), and stream/file handle at 0x50. Token writes (0x00599ED6), wide-char reads (0x0059A103), putback validation (0x0059A01E), construction (0x0059A3A9, 0x0059A948), state-check/throw (0x0059A5FE) and the backward scan helper (0x00599707).

Methods: `0x00599707`, `0x00599ED6`, `0x0059A01E`, `0x0059A103`, `0x0059A3A9`, `0x0059A5FE`, `0x0059A948`

- `this+0x00000004` `dword flags_word` (read_write, GUESS)
- `this+0x00000008` `dword ios_state` (read_write, DERIVED)
- `this+0x0000000C` `dword flags_or_state_mask` (read_write, GUESS)
- `this+0x0000000F` `byte eh_context_byte` (read, GUESS)
- `this+0x00000010` `dword init_flag_value` (read_write, GUESS)
- `this+0x00000014` `dword reserved_field` (write, GUESS)
- `this+0x00000018` `dword reserved_field_2` (write, GUESS)
- `this+0x0000001C` `void* encoding_table_ptr` (read, GUESS)
- `this+0x00000020` `void* buffered_count_ptr` (read, GUESS)
- `this+0x00000028` `void* stream_handle_stored` (read_write, GUESS)
- `this+0x0000002C` `dword capacity_or_init_flag` (read_write, GUESS)
- `this+0x00000030` `dword io_result_or_capacity` (read_write, GUESS)
- `this+0x00000038` `void* codec_or_facet` (read_write, DERIVED)
- `this+0x0000003C` `dword marker_save` (read_write, GUESS)
- `this+0x00000040` `dword marker_restore` (read_write, GUESS)
- `this+0x00000044` `void* buffer_object` (read_write, DERIVED)
- `this+0x00000050` `void* stream_file_handle` (read_write, DERIVED)
- `*(this+0x1C)+0x00000000` `dword encoding_table_length` (read, GUESS)
- `*(this+0x20)+0x00000000` `dword buffered_byte_count` (read, GUESS)
- `*(this+0x2C)+0x00000000` `dword buffered_capacity` (read, GUESS)
- `*(this+0x30)+0x00000000` `dword capacity_limit` (read, GUESS)
- `*(this+0x38)+0x00000000` `void* codec_vtable` (read, DERIVED)
- `*(this+0x44)+0x00000004` `void* buffer_data_ptr` (read, DERIVED)
- `*(this+0x44)+0x00000008` `dword buffer_capacity` (read, DERIVED)
- `*(this+0xC)+0x00000000` `dword putback_state` (read, GUESS)
- `*(*(this+0x38)+0x0)+0x00000010` `void* format_convert_vslot` (read, DERIVED)
- `*(*(this+0x38)+0x0)+0x00000014` `void* encode_vslot` (read, DERIVED)

### CodeCvtFacet

Locale code page facet performing stateful multibyte-to-wide conversion: drives MultiByteToWideChar (import 0x0059E12C) with flags 9, a resumable state dword, the lead-byte table at 0x005E69C8 and the cbMultiByte global at 0x005E6BD4, with locale/code page defaults at 0x008D3F38 / 0x008D3F48. Step 0x0059B0F5 performs the decode; 0x0059B208 performs a single-byte stream transfer through the shared driver sub_59B092.

Methods: `0x0059B0F5`, `0x0059B208`


### FileHandleManager

Manager of the open-file slot table at 0x008D4920 (36-byte entries, in-use flag bit 0 of the byte at +4) with count at 0x008D4A20 and per-slot critical sections: duplicates a slot handle (0x0059B650) and queries slot type/size/timestamp into a caller buffer (0x0059B760), mapping failures through TLS errors and ErrorIDLookupTable.

Methods: `0x0059B650`, `0x0059B760`


### StlExceptionHelpers

STL exception-construction helpers: build and throw std::length_error ('string too long') and std::out_of_range ('invalid string position') through CxxThrowException8 with the RTTI descriptors at 0x005BB890 / 0x005BB9B8 / 0x005BB668, construct the logic_error base via CExceptionInitHandler_ada3, and provide the scalar-deleting destructor (0x0059BACC) honoring the deleting flag low bit. All are compiler-runtime scaffolding rather than long-lived game objects.

Methods: `0x0059AD49`, `0x0059AF17`, `0x0059AF68`, `0x0059AFFF`, `0x0059BACC`


### CrtOneTimeInitGuard

CRT-style one-time initialization guard: a negative-to-positive transition of the dword_5EA04C counter selects the first-call construction path inside the enter/leave frame pair sub_59A54D / sub_59A5E9, constructing the locale/CEH static object chain (byte_8D4568, dword_8D4400, dword_8D4440, plus a read of unk_8D4438) and, on the reference-count zero path, dispatching StatusCheckWithErrorDispatch cleanup over the same objects.

Methods: `0x005997CB`, `0x00599AD9`


### GrowableBuffer

Growable buffer object whose requested size/capacity is tracked at this+0x8: 0x0059964A rounds the requested size to a 32-byte boundary, allocates via OperatorNewNhMallocWrapper, copies the old contents, releases the old buffer and relinks the buffer fields. The old buffer sub-object layout (data +4, size +8, capacity +12) is visible in raw access but not registered field evidence.

Methods: `0x0059964A`

- `this+0x00000008` `dword requested_size_or_capacity` (read_write, DERIVED)

### BitmapAllocation

Bitmap/buffer allocation object: data buffer at this+0x0, byte size at this+0x4, base bit capacity at this+0x10 and geometric growth stride at this+0x18. 0x0059B490 grows the allocation (hard cap 128000 bytes), copying old contents and freeing the old buffer. Caller BitmapAllocationTracker (0x0059B5C0) is known but outside the packet.

Methods: `0x0059B490`

- `this+0x00000000` `void* buffer_ptr` (read_write, DERIVED)
- `this+0x00000004` `dword byte_size` (read_write, DERIVED)
- `this+0x00000010` `dword bit_capacity_base` (read, DERIVED)
- `this+0x00000018` `dword growth_stride` (read, DERIVED)

### LocaleFacetObject

Weakly evidenced delegate-dispatch object holding a delegate pointer at this+0x50: 0x0059A2D0 forwards an encoding check with a doubled length through sub_59BB00; 0x0059A2FE conditionally invokes LockCallUnlockWrapper. Both are claimed structural twins of 0x00599232 by the cluster prelabel.

Methods: `0x0059A2D0`, `0x0059A2FE`

- `this+0x00000050` `void* delegate_ptr` (read, GUESS)

### TwinPointerOwner

Object owning two sub-object pointers (this+0x0 and this+0x8) released in order by FreeWrapper_7bcf in 0x0059B390; the second call's result is returned. The concrete type and whether the frees are unconditional is not established.

Methods: `0x0059B390`

- `this+0x00000000` `void* first_owned_ptr` (read, GUESS)
- `this+0x00000008` `void* second_owned_ptr` (read, GUESS)

## Compatibility contracts

- **BufferedStreamObjectLayout** — A buffered stream object exposes: an ios state dword at +0x08 masked with 7, flag/state literals written at +0x0C (513) and +0x10 (6) with +0x14/+0x18/+0x1C zeroed by the field initializer, a codec/facet pointer at +0x38 whose vtable dispatches format conversion at slot +0x10 and encode at slot +0x14, an output buffer object at +0x44 (data pointer +4, capacity +8), and a stream/file handle at +0x50. A replacement must preserve this layout and the 0xFFFF end-sentinel semantics used by token writes and character reads.
- **IosExceptionReporting** — When the masked stream state (this+0x08 & 7) is non-zero the object throws std::ios_base::failure, selecting the message literal by bit (badbit aIosBadbitSet, failbit aIosFailbitSet, else aIosEofbitSet) and throwing through CxxThrowException8 with the ios_base::failure RTTI descriptor at 0x005BB668.
- **StlExceptionThrowContract** — std::length_error('string too long') and std::out_of_range('invalid string position') are thrown via CxxThrowException8 with the RTTI descriptors at 0x005BB890 and 0x005BB9B8 and vftables at 0x005B9D5C / 0x005B9D8C; replacement code that reports these failures must use the same exception types and messages.
- **FileSlotTableContract** — Open files live in a slot table at 0x008D4920 with 36-byte entries (indexed slot>>5 / slot&0x1F) guarded by per-slot critical sections and counted at 0x008D4A20; the entry in-use flag is bit 0 of the byte at +4 and status bit 4 is cleared on successful duplicate. Queries fill a caller buffer with type/size/timestamp fields (block-size or attribute words at +6, sizes/timestamps at +20/+24/+28/+32).
- **MultibyteToWideContract** — Multibyte-to-wide conversion uses MultiByteToWideChar flags 9 with a resumable state dword, the lead-byte table at 0x005E69C8, the cbMultiByte global at 0x005E6BD4 and locale/code page defaults at 0x008D3F38 / 0x008D3F48; failure stores 42 in the TLS errno slot and returns -1, and the returns 0/1/cbMultiByte/-2 encode consumption states a replacement must preserve.
- **DeleteFlagAbiContract** — Scalar-deleting destructors (0x0059BACC and the conditional-free helpers) run the real destructor body first and free the object allocation only when the low bit of the deleting flag argument is set; a replacement must honor the MSVC deleting-destructor flag convention.

## Unresolved

- StreamWriter: only 0x00599ED6 carries a DERIVED owner label (StreamWriter); the other six methods have UNKNOWN owners and are grouped onto one class by shared field layout. The grouping is a proposal, not proof of a single C++ type.
- StreamWriter: the buffer-object layout behind this+0x44 (data pointer +4, capacity +8) is visible in raw dword-indexed access but not covered by registered field evidence; the per-field names are GUESS semantics on a DERIVED layout.
- StreamWriter: this+0x50 is overloaded across classes - StreamWriter treats it as a stream/file handle while LocaleFacetObject treats it as a delegate pointer; they are kept as distinct bases.
- StreamWriter: the virtual encode slot (vtable +0x14) and format-conversion slot (+0x10) targets are indirect and their concrete implementations are absent from the packet callee list.
- CrtOneTimeInitGuard: 0x005997CB reads global 0x008D4438 per deterministic facts but the reference site is absent from the raw body; the SEH payload role is unresolved.
- CrtOneTimeInitGuard: whether sub_59A54D / sub_59A5E9 form an SEH frame pair or a critical-section enter/leave pair is unproven.
- CrtOneTimeInitGuard: whether 0x005997CB and the sibling one-time initializer are distinct copies or a thunk into shared construction is unresolved at this trust level.
- StreamWriter: 0x00599ED6 is listed as reading global 0x005B9C38 which does not appear in the raw body; its role is unknown.
- CodeCvtFacet: field:this:0x00000000 as the lpWideCharStr output is a decompiler-signature naming inference, not confirmed.
- BitmapAllocation: the origin of the 128000 (0x1F400) growth cap and the exact meaning of a2 / this+0x10 are inferred from the caller contract (BitmapAllocationTracker), not confirmed.
- FileHandleManager: the result buffer field meanings in 0x0059B760 differ by file type (+6 word is block size for devices, attribute/permission bits for disk files); the 13 TLS-slot refs (0xFF00000000005394..0xFF000000000054C4) are unresolved, and the slot-array index expression is derived.
- StreamWriter: IosStateCheckThrow combines the masked state against a stored mask dword that is not visible in the decompiled text; register v4 is used before initialization in the Hex-Rays output (SEH frame base).
- LocaleFacetObject: both 0x0059A2D0 and 0x0059A2FE are claimed as structural twins of 0x00599232 by the cluster prelabel; the twin relationships are not independently confirmed, and sub_59BB00's return/argument semantics are unknown.
- EmptyStub 0x00599796: the purpose of the two call sites (sub_579FB0 / sub_579FF0) is not visible in this packet; the stub may be an intentional no-op or an unimplemented hook.
- StlExceptionHelpers: the throw helpers' stack-frame slots (a1-13, a1-32, a1-60) follow the caller's exception-buffer convention and are not resolvable from these functions alone.
- StlExceptionHelpers: 0x0059AF17 and 0x0059AFFF return exception-object pointers after a non-returning throw; the exact reachable destructor/free path is compiler-generated scaffolding.
- GrowableBuffer: the old buffer sub-object layout (data +4, size +8, capacity +12) is visible in raw source but not covered by registered field evidence; whether this+0x8 holds the requested size, the new allocation pointer, or both across phases is ambiguous.
- TwinPointerOwner: the first FreeWrapper result is discarded while the second is returned; whether this is meaningful is not evident, and whether the frees are unconditional is hidden inside FreeWrapper_7bcf.
