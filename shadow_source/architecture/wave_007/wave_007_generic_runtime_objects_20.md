# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

The packet covers 26 functions across six weakly-related runtime object clusters, all but one with UNKNOWN owners. The 3DNow/MMX cluster provides cubic-Bezier-style interpolation, a partial quaternion product and a normalized cross/perpendicular direction as freestanding packed-float kernels with read-only constant globals. An allocator-descriptor pattern (allocation callback +0x20, release callback +0x24, handle +0x28) backs the resource-buffer alloc/free lifecycle, a 28-byte object allocation with field fill, a generic indirect-dispatch helper and a free wrapper. An MPEG bitstream cluster shares the callee CMpegBase_ProcessHeader and the bitstream-buffer fields at this+0x24A4/0x24F0, plus a vtable I/O read at *(this+0x2D34)+8. A zlib-style codec cluster covers the inflate fast path, a buffered stream read, Adler-32, the deflate longest-match search, and the Huffman tree construction/rank-redistribution/canonical-code-assignment trio. The remainder are orphaned helpers: a global-flag stub trampoline, the fatal-halt handler, a two-global pointer swap, a ROM-to-RAM interleaved table copy, an AVI import thunk and a string-length dispatch. All classes here are synthetic groupings inferred from shared evidence; ownership and most field semantics remain UNKNOWN.

## Function roles

- `0x005272B5` **Simd3DNowVectorMath** — 3DNow! cubic-Bezier-style interpolation between four packed float control points (a2..a5) parameterized by scalar factor a6: broadcast the factor, derive higher-order weight coefficients with packed multiply/add/difference/sign-flip operations (packed [2.0f,3.0f] scale, 0x8000000000000000 sign flip), blend the first packed element of all four inputs and the full second packed element, scale both results by packed 0.5f, emit EMMS and return the output pointer a1.
- `0x00527393` **Simd3DNowVectorMath** — 3DNow partial quaternion product: packed-multiplies the first component pairs of a2/a3, accumulates a dot-product-like term from the second-pair low dwords, copies the a3 first pair to output a1[0], stores the sign-flipped accumulated value (XOR 0x80000000, global qword_5AF978) into a1[1].high, and clears 3DNow/MMX state with _m_femms at entry and exit.
- `0x005273D6` **Simd3DNowVectorMath** — 3DNow normalized perpendicular/cross direction computed from differences of three input vectors (a2..a4): assemble cross-style perpendicular terms, compute a squared length, normalize with a Newton-refined guarded reciprocal square root against a denormal epsilon threshold, force the output pair to zero at or below the guard, and write the normalized direction pair to a1 with a sign flip on the second lane.
- `0x005276C5` **ResourceBufferAllocator** — Allocate and initialize a resource buffer struct through an allocator object: use the allocation callback at this+0x20 with the handle at this+0x28 to allocate the primary struct (size 64), a secondary fixed buffer (tag 8, size 1440) and a variable buffer (tag 1, size a3); on success store the buffers at v3[9]/v3[10], set v3[0]=0, v3[11]=a3+size, v3[14]=a2, call sub_52765A to reset it and return the struct; on any allocation failure release prior blocks through the callback at this+0x24 and return 0.
- `0x00527EED` **ResourceBufferAllocator** — Reset resource state via sub_52765A(a1, a2, 0), then invoke the indirect release callback (function pointer at a2+0x24, context dword at a2+0x28) three times passing the variable buffer (a1+0x28), the secondary buffer (a1+0x24) and the a1 struct itself, and return 0.
- `0x00529AF8` **ResourceBufferAllocator** — Dispatch through the function pointer at (a5+0x20) with the value at (a5+0x28), 1 and 28; if the returned object is non-null, zero its first dword and store two bytes (offsets +0x10, +0x11) and two dwords (offsets +0x14, +0x18) from a1..a4, then return the object pointer (possibly null).
- `0x0052A090` **ResourceBufferAllocator** — Indirect-call dispatch helper: load the function pointer stored at a2+0x24 and the argument dword at a2+0x28, call the pointer with (arg, a1), and return the callee result; a vtable- or callback-table-style dispatch site.
- `0x0052A5A8` **AudioCodecBasePointerProvider** — Read four global base pointers (dword_5D9418, dword_5D941C, address of unk_5D9420, address of unk_5DA420) into the four caller-provided output parameters and return 0; consumed by the audio-codec initialization caller sub_527752.
- `0x0052C334` **ZlibInflateDecompression** — DEFLATE fast-path decoder (zlib inflate_fast equivalent): decode literal/length and distance Huffman codes from the bit stream, emit literals into the circular output window and copy length-distance matches with wraparound while at least 0x102 window bytes and 0xA bits remain, using the dword_5DA520 bit-mask table and the per-table node layout; write 'invalid distance code'/'invalid literal/length code' into the stream error slot and return 1 (block complete), 0 (ran out of window/input) or -3 (invalid code).
- `0x0052DD50` **CMpegBase** — Decode one MPEG audio frame header from the bitstream: snapshot the bit position to this+0x24A8, read a byte-swapped 32-bit sync word from the buffer at this+0x24A4 (fallback to the default header word at this+0x24F0 when no buffer is set), validate via CMpegBase_ProcessHeader, and on success advance the bit position at this+0x24AC by 8 * frame_size_bytes(this+0x2498) + 32; return 0 on a valid header, -1 otherwise.
- `0x0052DDC0` **CMpegBase** — Read a 4-byte word from the I/O interface object at this+0x2D34 via its vtable read function at slot +8 (args &v3, 4, 0), byte-swap the value and forward it to CMpegBase_ProcessHeader(this, v3); return 0 when the header is accepted, -1 when CMpegBase_ProcessHeader returned -1.
- `0x0052DE00` **CMpegBase** — Read the next MPEG sync word from the buffer pointer at this+0x24A4 (fallback to the default header word at this+0x24F0 when the buffer is null), byte-swap it and pass it to CMpegBase_ProcessHeader; return TRUE (1) when the header is invalid (-1), FALSE (0) when accepted.
- `0x0052E070` **RuntimeUtility** — Conditional trampoline: read the global flag dword_8B0108 and, when it is non-zero, invoke EmptyStub_0170 (an empty stub per its name); no return value and no other side effects.
- `0x0052E520` **RuntimeUtility** — Fatal-halt entry point: invoke the global halt-handler function pointer off_5DA714 (static graph target sub_52E4E0) with the message string aHaltingProgram, then trap with __debugbreak() if the handler returns; return the value produced by the handler call.
- `0x0052E550` **SmallBoundByteArray** — Bounds-checked byte store: write the byte a3 into the receiver byte array at index a2 only when a2 <= 8 (fixed 9-element bound) and always return the original index; used by BufferInitZero as the per-byte fill step of a small fixed-size buffer.
- `0x0052E5A0` **RuntimeUtility** — Straight-line pointer copy: save the current value of dword_8B0110 into the return register, write dword_8B0118 as the first dword of the buffer addressed by dword_8B0110, and return the old pointer; the raw body only proves an old-pointer/new-pointer swap in a two-dword relationship.
- `0x005317C0` **RuntimeUtility** — Copy two fixed-size lookup tables from ROM into a single runtime buffer at unk_8B1924 with an interleaved 32-byte-block pattern: 16*15 blocks of 32 bytes from unk_5B6F0C (offsets j-i, j in {0..896 step 64}, i in {0..30 step 2}), then 16*17 blocks from unk_5B730C (offsets m-k, m in {0..1024 step 64}, k in {0..30 step 2}); call a no-op stub first and return an incidental offset value.
- `0x00534AE0` **RuntimeUtility** — Import thunk for the AVIFileExit AVI library routine: unconditionally forward to the import address table entry __imp_AVIFileExit at 0x0059E04C and return; no parameters and no explicit body beyond the indirection.
- `0x005352B0` **RuntimeUtility** — String-aware dispatch helper: measure the length of the NUL-terminated string a2 via strlen and forward (a1, a2, length) to BufferFillWithTimeout, returning its result; called by ResourceLookupWithDualPath.
- `0x00536560` **ZlibInflateDecompression** — Buffered decompression-stream read: read up to a3 bytes clamped to the available bytes at stream+4, advance the buffer pointer at stream+0 and the total-read counter at stream+8, and when the flag at *(*(stream+28)+24) is clear run consumption bookkeeping through sub_537D10 storing its result at stream+48; return the number of bytes actually read.
- `0x00536900` **ZlibDeflateCompression** — LZ77 longest-match search over a hash chain: read window and chain parameters from the deflate state a1, walk the prev-hash chain from candidate a2, probe candidates with a prefix comparison, extend matches byte-by-byte with an 8-byte unrolled loop, record the best match origin and length in the state, and return the best length clamped to the lookahead.
- `0x00536FF0` **ResourceBufferAllocator** — Single-argument free-style wrapper: forward the pointer a2 to sub_58AA6F and return that callee's result; the first parameter a1 is accepted but not used.
- `0x00537D10` **ZlibInflateDecompression** — Adler-32 checksum (classic zlib): a1 is the rolling 16-bit checksum pair (s1 low word, s2 high word), a2 the input buffer, a3 the byte count; process chunks of at most 5552 bytes with a 16-byte unrolled accumulation loop plus a residual loop, reducing both sums modulo 0xFFF1 after each chunk, and return s1 | (s2 << 16); called by DecompressionStreamRead.
- `0x005383D0` **ZlibDeflateCompression** — Build an optimal Huffman prefix-code tree from a symbol frequency table: collect the non-zero-frequency symbols into a node-index array, synthesize dummy symbols when fewer than 2 remain, heapify and repeatedly combine the two smallest nodes into a parent (summing frequencies, taking max code length + 1), finalize the root, call RankRedistribution to enforce the maximum code length, and return the result of FrequencyTableConstruction which generates the canonical codes.
- `0x005386C0` **ZlibDeflateCompression** — Maximum code-length enforcement pass of deflate-style Huffman tree construction: walk the tree node-index heap to derive each symbol's code length from its parent depth, clamp lengths above the maximum and count the overflow, redistribute the overflow by moving leaves shallower, and recompute every overlong symbol's length down to the limit while accumulating dynamic and static bit costs; invoked by HuffmanTreeConstructor.
- `0x005388D0` **ZlibDeflateCompression** — Deflate-style canonical Huffman code assignment: phase 1 builds a per-length next-code table by advancing a running base code for each length against the symbol-count histogram and doubling; phase 2 walks symbols assigning the next code for each non-zero code length, transforms it through sub_539670, and writes the code word at a1+4*i; returns the last transformed code value.

## Proposed classes

### Simd3DNowVectorMath

Synthetic grouping of the three 3DNow/MMX packed-float kernels in this packet: a cubic-Bezier-style interpolation between four control-point pairs, a partial quaternion product, and a normalized perpendicular/cross direction computed from vector differences. Members share the two-__m64-lane convention at this+0x0/this+0x8, the read-only constant globals in the 0x005AF9xx range and _m_femms state hygiene; the class boundary is inferred from the shared 3DNow intrinsic flavor, not from owner evidence (all owners UNKNOWN).

Methods: `0x005272B5`, `0x00527393`, `0x005273D6`

- `this+0x00000000` `__m64 (packed_float2) first_packed_pair` (read_write, DERIVED)
- `this+0x00000008` `__m64 (packed_float2) second_packed_pair` (read_write, DERIVED)

### ResourceBufferAllocator

Synthetic grouping of the allocator-descriptor callbacks and the resource-buffer lifecycle helpers in this packet. The descriptor carries an allocation callback at +0x20, a release callback at +0x24 and a handle/context dword at +0x28. ResourceBufferAllocInit allocates and initializes a resource buffer through those callbacks, ResourceBufferFreeCleanup releases the buffer through the release slot, allocObjectAndSetFields allocates a 28-byte object through the +0x20 slot and fills five caller-supplied fields, IndirectCallDispatch is the generic release-slot dispatch helper and AllocatorFreeWrapper forwards to sub_58AA6F. The shared layout is evidenced at different bases across call sites (this, a2, a5); merging them is an inference from the consistent callback pattern and is not proven common ownership.

Methods: `0x005276C5`, `0x00527EED`, `0x00529AF8`, `0x0052A090`, `0x00536FF0`

- `this+0x00000020` `fnptr (alloc(handle, tag, size)) allocation_callback` (read, DERIVED)
- `this+0x00000024` `fnptr (release(handle, ptr)) release_callback` (read, DERIVED)
- `this+0x00000028` `dword (context/handle) allocator_handle` (read, DERIVED)

### AudioCodecBasePointerProvider

Single-function provider helper that reads four global base pointers (dword_5D9418, dword_5D941C, unk_5D9420, unk_5DA420) into a caller-supplied output block during audio-codec initialization by sub_527752. Trust DERIVED comes from the packet owner evidence; the semantics of the four globals (decode table, heap, atlas, buffer) are inferred from the caller and not directly evidenced.

Methods: `0x0052A5A8`

- `this+0x00000000` `void** (output parameter) out_base_pointer_0` (write, DERIVED)

### CMpegBase

Synthetic grouping of the MPEG audio bitstream/header-processing helpers that delegate to the shared callee CMpegBase_ProcessHeader (0x0052DA30): a frame-header decode with bit-position bookkeeping, a word read through a vtable I/O interface, and a next-sync-word predicate. The 'this' object carries the bitstream buffer pointer (+0x24A4), the bit position snapshot and position (+0x24A8/+0x24AC), the frame size in bytes (+0x2498), a default header word (+0x24F0) and an I/O interface pointer (+0x2D34) whose vtable slot +8 is a read function. The class boundary is inferred from the shared fields and callee; ownership is UNKNOWN and the Network* ABI leads are LEGACY-trust naming, not proof of a network class.

Methods: `0x0052DD50`, `0x0052DDC0`, `0x0052DE00`

- `this+0x00002498` `dword frame_size_bytes` (read, GUESS)
- `this+0x000024A4` `ptr (bitstream buffer) bitstream_buffer` (read, GUESS)
- `this+0x000024A8` `dword (bits) bit_position_snapshot` (read_write, GUESS)
- `this+0x000024AC` `dword (bits) bit_position` (read_write, GUESS)
- `this+0x000024F0` `dword default_header_word` (read, GUESS)
- `this+0x00002D34` `ptr (vtable object) io_interface` (read, GUESS)
- `*(this+0x2D34)+0x00000008` `fnptr (vtable slot +8) read_function_slot` (read, GUESS)

### ZlibInflateDecompression

Synthetic grouping of the DEFLATE decompression-side helpers: the inflate_fast fast-path decoder (using the dword_5DA520 bit-mask table and the invalid-distance/invalid-literal error strings), a buffered decompression-stream read that clamps to available bytes and runs consumption bookkeeping through sub_537D10, and the Adler-32 checksum that DecompressionStreamRead consumes. The boundary is inferred from the shared zlib inflate context and the callee relationship; owners are UNKNOWN and the inflate/stream struct layouts are caller-defined.

Methods: `0x0052C334`, `0x00536560`, `0x00537D10`


### ZlibDeflateCompression

Synthetic grouping of the DEFLATE compression-side helpers: the hash-chain longest-match search, the Huffman tree constructor, the maximum-length rank redistribution (gen_bitlen equivalent) and the canonical code assignment (gen_codes equivalent). The shared descriptor ('this') carries the symbol frequency table base (+0x0), the maximum symbol index (+0x4), a tree-state block pointer (+0x8) and the symbol count (+0x14). The zlib interpretation is DERIVED from the structural match to deflate and the callee names; owners are UNKNOWN and the deeper state-object roles are not independently proven.

Methods: `0x00536900`, `0x005383D0`, `0x005386C0`, `0x005388D0`

- `this+0x00000000` `dword[] (frequencies) symbol_freq_table` (read, DERIVED)
- `this+0x00000004` `dword max_symbol_index` (read, DERIVED)
- `this+0x00000008` `ptr (tree-state block) tree_state_block` (read, DERIVED)
- `this+0x00000014` `dword symbol_count` (read, DERIVED)

### SmallBoundByteArray

A tiny fixed-size byte array exposed as a __thiscall receiver with a single bounds-checked byte store (index <= 8), used by BufferInitZero to fill individual bytes of a small buffer without allowing out-of-range writes. The enclosing object layout and member semantics are not available from this packet.

Methods: `0x0052E550`

- `this+0x00000000` `byte[9] byte_array` (read_write, GUESS)

### RuntimeUtility

Catch-all grouping of the remaining generic runtime helpers with no owner evidence: a conditional global-flag trampoline to a no-op stub, the fatal-halt handler with the global function pointer off_5DA714, a two-global pointer swap (dword_8B0110/dword_8B0118), a ROM-to-RAM interleaved table copy (unk_5B6F0C/unk_5B730C into unk_8B1924), an AVI import thunk and a string-length dispatch to BufferFillWithTimeout. The boundary is a synthesis of unrelated orphaned helpers, not an attested class.

Methods: `0x0052E070`, `0x0052E520`, `0x0052E5A0`, `0x005317C0`, `0x00534AE0`, `0x005352B0`


## Compatibility contracts

- **MPEGHeaderValidationReturnContract** — CMpegBase_ProcessHeader (0x0052DA30) is used by all three MPEG helpers with a 0/-1 return convention: 0 means a valid header, -1 invalid. NetworkPacketSend returns the same 0/-1, NetworkColorIsDefault returns TRUE exactly when the header is invalid (-1), and BitstreamMpegHeaderDecode only advances the bit position when the result is not -1. A replacement must preserve this return convention and the -1 sentinel meaning.
- **MPEGFrameBitAdvanceContract** — On a valid frame header BitstreamMpegHeaderDecode snapshots the bit position to this+0x24A8 and advances the position at this+0x24AC by 8 * frame_size_bytes(this+0x2498) + 32 bits. A replacement must reproduce this bit accounting so subsequent frame reads stay aligned to the stream.
- **InflateFastPathHandoffContract** — InflateFastDecode is entered only when the output window has at least 0x102 bytes free and the input has at least 0xA bits buffered; it returns 1 (block complete), 0 (needs the slow path / more input or window space) or -3 (invalid code) and persists the bit accumulator, bit count, input pointer/counters and output cursor into the inflate context a5 and stream a6. A replacement decoder must preserve this entry precondition, the state-persist handoff and the invalid-code error-string behavior.
- **AllocationCallbackContract** — The allocator descriptor exposes allocate at +0x20 (called with handle, tag and size, returning a pointer or null) and release at +0x24 (handle, pointer). ResourceBufferAllocInit returns 0 and frees already-allocated blocks through release on any allocation failure, and ResourceBufferFreeCleanup releases in order the variable buffer, the secondary buffer, then the struct itself. A replacement allocator must honor the null-return-on-failure and the release order.
- **Adler32ChecksumContract** — The checksum routine implements standard Adler-32: the seed is a rolling pair (s1 low 16 bits, s2 high 16 bits), input is processed in chunks of at most 5552 (NMAX) bytes with per-chunk modulo-65521 reduction of both sums, and the result is s1 | (s2 << 16). A replacement must match the chunking and modulus to reproduce identical checksums.

## Unresolved

- All owners are UNKNOWN except AudioCodecBasePointerProvider (DERIVED, per packet); every class in this proposal is a synthetic grouping inferred from shared 3DNow flavor, shared callees, or shared descriptor layout, not an attested object.
- The allocator descriptor offsets (+0x20/+0x24/+0x28) are evidenced at different bases across call sites (this in 0x005276C5, a2 in 0x00527EED/0x0052A090, a5 in 0x00529AF8); equal offsets on these bases are not proof of a single common class, and the exact base binding per call site is ambiguous.
- The per-global mapping of qword_5AF900/qword_5AF910/qword_5AF920/qword_5AF968 to the folded __m64 literals (packed [2.0f,3.0f], 0.5f, sign-flip mask) is not recoverable from the packet; globals 0x005AF970/0x005AF980 (claimed roles: squared-length threshold / SIMD constant) do not appear in the raw source text and are unconfirmed.
- The exact per-lane weight-coefficient formula of the cubic-Bezier kernel (0x005272B5) is not fully derived from the packed shuffle/sign-flip sequence; the cubic Bezier intent is inferred from the instruction structure and the canonical name only.
- For 0x00527393 the binding of the immediate sign-flip 0x80000000 to global qword_5AF978 follows the existing-analysis name MMX_QuatInitConst_AF978 [DERIVED] and is not stated in the raw source.
- The CMpegBase layout roles (frame size, bit position fields, default header word) are grounded in the skeleton fill but unproven at runtime; the Network* ABI leads are LEGACY-trust naming and do not establish a network class; the identity of the I/O object at this+0x2D34 is unknown.
- The inflate context (a5) and stream (a6) struct layouts in InflateFastDecode are caller-defined; the exact base alignment across the inflate callers is not proven by this packet.
- The deflate state field roles (offsets 34/42/46/54/98/102/106/110/114/130/134 in 0x00536900 and the a1+2866/2898/5190/5194/5198/5787/5791 regions in 0x005383D0) are DERIVED from the structural match to zlib deflate_state; canonical zlib names are not evidenced by this packet.
- The packet lists descriptor fields this+0x0C, this+0x10 and this+0x18 for 0x005386C0 but the raw source body contains no direct access to a2[3]/a2[4]/a2[6]; the existing-analysis mapping of those offsets is ungrounded prose and they remain unaccounted.
- sub_539670 (called by 0x005388D0) identity is unknown; bit reversal to produce canonical code order is a GUESS from the deflate context, not evidenced.
- The histogram read target in 0x005388D0 resolves only DERIVED to count[len-2] for the first iterations; the off-by-one vs the standard bl_count[len-1] formula is unresolved.
- DecompressionStreamRead's sub_537D10 result stored at stream+48, the flag at *(*(stream+28)+24), and whether stream+8 is a total-read counter are unproven; whether sub_537D10 is the Adler-32 routine in that context is caller-side.
- The Adler32Checksum field:this:0x00000000 prelabel is a misclassification: a1 is a passed-in checksum seed value, not a struct field access.
- EmptyStub_0170 (callee 0x004B0170), referenced by 0x0052E070 and 0x005317C0, has unknown behavior and may be a placeholder elided in the shipped binary.
- CopyAudioBufferPointer's callee 0x00587B3E (BooleanToIntConversion) and global 0x0052E5C0 are listed in the packet but unused in the function body; likely a mis-attributed boundary or the fall-through target after the short function.
- The packet labels unk_8B1924 read (rw=R) although the raw source writes it as the copy destination; the rw classification is inconsistent with source:raw. The semantic purpose of the de-interleaved table contents (audio/DSP coefficient transpose) is DERIVED prose.
- The meaning of the allocation tags 1 and 8 and the sizes 64 and 1440, and of the stored ResourceBuffer fields v3[11]/v3[14], is not in the packet.
- GetAudioCodecBasePointers global semantics (decode table, heap, atlas, buffer) are inferred from the caller sub_527752 and not directly evidenced.
- No callers are evidenced for the SIMD kernels, ConditionalEmptyStubCall, HaltAssertHandler, LargeTableCopyFromROMData, StringLengthDispatch or the MPEG helpers, so their consumption contexts and call frequency are unconfirmed.
