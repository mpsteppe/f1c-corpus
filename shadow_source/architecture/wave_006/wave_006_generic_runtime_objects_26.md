# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `GUESS`

Reconstruction of generic runtime objects from 22 validated function IR records. The packet supplies one DERIVED owner (CMpegBase for 0x0052DA30, an MPEG audio frame-header parser); everything else is labeled UNKNOWN and is proposed here as GUESS-level classes. The strongest cross-function groupings are: (1) the DEFLATE/zlib inflate context (0x00527752 outer block state machine + 0x00529B2C inner symbol decode machine) sharing the persistent bit-stream state and circular-window fields this+0x0..0x34 plus the stream flush hook sub_52A5D7; (2) the MPEG audio synthesis transforms (0x0052A6EC / 0x0052AB4E / 0x0052B206) operating on a 64-entry 16-bit subband sample array at this+0x0..0x70; (3) the wave-table-backed audio filter group reading field this+0x11C (+128) that includes the two structural twin codec-transform selector branches on global byte_5D79DC; (4) an SSE/SSE2 packed color-space decode family (0x005289E0 / 0x00528BD0 / 0x00528CC0) on a packed input at this+0x0; (5) a SIMD/3DNow helper cluster with two empty stubs and two packed lower-lane absolute-value twins; and (6) the render/game object lifecycle trio sharing vtable off_5B47E8 and the flag/header at this+0x24EC/0x24F0. Class membership is GUESS unless the packet's DERIVED owner is used; equal offsets on the same base across different classes are never merged without proof.

## Function roles

- `0x00527752` **InflateDecompressor** — Outer DEFLATE inflate state-machine driver: parses block headers (stored / fixed-Huffman / dynamic-Huffman), builds the fixed and dynamic Huffman tables via helper callees, assembles code-length tables, dispatches through the decode tables, and flushes the circular output window. Operates on the inflate-context object (state this+0x0, length-or-table this+0x4, loop counter this+0x8, work buffer this+0xC, decode bit count this+0x10, decode table this+0x14, bfinal this+0x18, bit count this+0x1C, accumulator this+0x20, max code length this+0x24, window bounds this+0x28/0x2C, capacity this+0x30, cursor this+0x34) and the stream object a2. Returns 1 on stream end, -2 on invalid state, -3 on data errors, -4 on allocation failure.
- `0x0052835F` **AudioDecodeFilterbank** — FIR-style convolution of 8 audio channels (skipping channels 6/4/2) with four weighted 16-bit product pairs (29692/6967/5906/10426) rounded by 4096 and >>13 into lowpass/highpass outputs, then a 2-iteration output loop that looks up 8-bit samples from the wave table at field this+0x11C base + 128 using (sum >> 20) & 0x3FF and writes them through the a4 index array into a5; returns the advanced buffer pointer.
- `0x0052851D` **AudioDecodeFilterbank** — Single-sample wave-table lookup: computes index ((*a3 * coefficient at a2+80 + 4) >> 3) & 0x3FF into the wave table rooted at field this+0x11C plus a +128 offset, writes the looked-up byte to a5 + *a4, and returns it.
- `0x0052855A` **AudioDecodeFilterbank** — Codec transform selector branch: computes the output offset field this+0x11C + 128 and input v6 = a2+80, then forwards the same argument set to AudioCodecMDCTFFTTransform (0x0052AB4E) when global byte_5D79DC is non-zero or to MPEGAudioLayer3IMDCT (0x0052A6EC) when it is zero; returns the selected transform's result directly.
- `0x005285A6` **AudioDecodeFilterbank** — Structural twin of 0x0052855A: branches between QuaternionMultiplySurfaceSample (0x0052B561) and MPEGAudioLayer3IMDCT_b206 (0x0052B206) on the same global byte_5D79DC, with the same field this+0x11C + 128 output offset and a2+80 input read; returns the selected transform's result.
- `0x005285F2` **AudioDecodeFilterbank** — 8-point inverse synthesis filter bank (MDCT-style): an 8-iteration window/rotation loop over the a3 input samples and the a2+0x50 window-coefficient buffer (with a zero-input short circuit to the DC product), then a second 8-iteration loop combining the transformed samples and writing interleaved bytes into a5 via a4-indexed offsets using the field this+0x11C + 128 byte-lookup base (CRTFtol converts the float constant index); returns the last byte written.
- `0x005289E0` **PackedColorSpaceDecoder** — SSE packed RGBA decode: masks the packed input at this+0x0 with xmmword_5D9050 / xmmword_5D9060, dequantizes with the coefficient/bias constants, computes a residual and its square, evaluates two Horner polynomial paths, builds a blend mask from a zero-comparison, and stores the complementary pair into a2/a3; returns a2. Called by QuaternionConstructionTransform (0x0051FEBE).
- `0x00528BD0` **PackedColorSpaceDecoder** — Packed SSE float transform with no memory access: masks a1 with xmmword_5D9140, applies an affine transform, computes a residual and a shuffle-57 cross-lane correction, squares the corrected value, extracts integer bit fields, evaluates a Horner polynomial chain (xmmword_5D90C0..0x005D9080), builds a per-lane mask and performs a final XOR merge folding in sign bits from xmmword_5D9130; returns the packed vector in xmm0. Invoked by SSEVectorMatrixInit (0x0052087E) and SSEMatrixConstructionFrom44Data (0x005208FE).
- `0x00528CC0` **PackedColorSpaceDecoder** — SSE2 packed decode of 4-lane color data into two output __m128 vectors: masks the packed input at this+0x0 with 0x005D9280, applies an affine transform (0x005D9260 / 0x005D9210), computes a residual corrected by four coefficients, squares it, evaluates two Horner polynomial branches, builds a selection mask via bit-field extraction (0x005D91E0 / 0x005D91D0 / 0x005D91C0 and a 0x1E-bit shift), conditionally blends, XORs in carry-derived and input bits (0x005D9270), and stores the complementary pair into a2/a3; returns a2. Packet prose reports a caller at 0x00520E0E (not in the allowed refs).
- `0x00529000` **SIMDPackedMathHelpers** — No-op stub: raw body is `void sub_529000() { ; }` with no instructions, so the legacy ABI lead name Square_Root_Approximation is not exercised by any code here; the twelve read-only dword globals near 0x005D9358..0x005D93B8 listed by static facts are not touched by this empty body and likely belong to an adjacent SIMD constant table.
- `0x00529200` **SIMDPackedMathHelpers** — No-op stub: raw body is `void sub_529200() { ; }` with no instructions; the twelve read-only globals near 0x005D9360..0x005D93EC listed by static facts are not read by this empty body; no callers, callees, fields or guards are recorded.
- `0x005295E0` **SIMDPackedMathHelpers** — Packed-float absolute-value helper for the lower 32-bit lane of a __m64: extracts the lane with _mm_cvtsi64_si32, isolates the sign bit with the mask 0x80000000 and XORs it back off the value. No branches. Used by QuaternionMul3DNow (0x005214AA), F_3DVectorNormalize (0x0052193C) and SIMDQuaternionRotationArithmetic (0x00524553).
- `0x00529700` **SIMDPackedMathHelpers** — Structural twin of PackedFloatingPointMath (0x005295E0) per the cluster_copy prelabel: same lower-lane absolute value of a packed __m64 via sign-bit isolation and XOR. Invoked from SIMDVectorNormalization (0x005215DB), F_3DAudioListenerTransform (0x00521895) and Quaternion3DMath (0x005219E1).
- `0x00529B2C` **InflateDecompressor** — Inner literal/length + distance Huffman decode state machine (cases 0-9): fast-run path via sub_52C334 when the window space is at least 0x102 bytes and at least 0xA bits are buffered, per-symbol table decode through this+0x8 / this+0xC with the dword_5DA520 mask table, length extra-bit consumption via this+0x10 / 0x14 / 0x15 / 0x18, distance decode, wraparound match copy from the circular window (this+0x28..0x2C) into this+0x30 / this+0x34, window flush via sub_52A5D7, and error states writing the aInvalidDistanceCode / aInvalidLitlenCode strings. Part of the zlib-style stream decompressor.
- `0x0052A6EC` **MPEGSubbandTransform** — MPEG Audio Layer 3 IMDCT synthesis filterbank stage: stage-one 8-iteration butterfly over 64 16-bit subband samples (a1/a2 at element indices 0..56 step 8) with fixed integer rotation coefficients, writing 8 rounded ((x + 1024) >> 11) results; stage-two 8-iteration butterfly then four rounds of windowed byte-coefficient lookup into a6 at ((x + 0x20000) >> 18) & 0x3FF, packing four bytes per dword through the a5 + a4[offset] pointer. Invoked by RenderingBranchOnDAT005d79dc (0x0052855A).
- `0x0052AB4E` **MPEGSubbandTransform** — MMX audio codec butterfly stage: a two-iteration packed 16-bit multiply-accumulate butterfly over the a1/a2 sample-pair arrays (this+0x0..0x70) using the read-only qword twiddle table 0x005B0B98..0x005B0C58 (rendered as inline __m64 literals) and >>0xB rounding shifts, packing 8 results into a3[0..14]; an 8-iteration second pass combines the pairs, quantizes them to 8-bit PCM through the a6 lookup table and stores packed bytes to a5 + a4 offsets. Emits EMMS and returns 0.
- `0x0052B206` **MPEGSubbandTransform** — 16-bit variant of the MPEG Layer 3 IMDCT synthesis filterbank, structural twin of 0x0052A6EC: stage-one 8-iteration butterfly over the a1/a3 16-bit inputs with reduced-precision rotation coefficients (362/473/669/277 applied with >> 8) writing pair sums/differences to the a2 output; stage-two 8-iteration windowed byte-coefficient lookups into a6 at (x >> 5) & 0x3FF written through the a5 + a4[offset] pointer. Invoked by RenderModeBranch (0x005285A6).
- `0x0052D970` **MPEGBufferDispatch** — Thin guarded dispatch: reads the function pointer stored at this[0] (offset 0x0); if it is non-null, forwards a2 and a3 to MPEGBuffer through that pointer and returns its result, otherwise returns 0. No callers are listed in the packet.
- `0x0052D9B0` **RenderGameObjectLifecycle** — GameObject constructor: writes the vtable pointer off_5B47E8 into the object header at this+0, reads the flag byte at this+0x24EC; when non-zero calls DeferredDeactivation and returns its result, otherwise returns 0.
- `0x0052D9D0` **RenderGameObjectLifecycle** — MSVC-style scalar deleting destructor shape: calls CConstructor (0x0052D9B0) to run the object's teardown/reset routine, then, if the flag byte a2 has bit 0 set, calls FreeWrapper (0x00587BCF) to release the object memory; always returns this.
- `0x0052D9F0` **RenderGameObjectLifecycle** — Constructor-style initializer for a render/game object: sets the vtable pointer at this+0x0 to global off_5B47E8, clears the byte flag at this+0x24EC and the DWORD at this+0x24F0, and returns this. Packet prose reports a caller RenderObjectConstructor_e170 (0x0052E170, not in the allowed refs).
- `0x0052DA30` **CMpegBase** — Parses a 32-bit MPEG audio frame header into the decoder state object at this: validates the 0xFFF00000 sync-word pattern, extracts layer, bitrate, sampling-rate, channel-mode and flag fields into this+0x24C1..0x24C9, derives the bitrate through dword_5B4764 into this+0x2484/0x2488, the frame-size table entry through word_5B4684 into this+0x2494, the final frame size into this+0x2498, and channel count / PCM samples-per-frame into this+0x24CC/0x24D0; returns 0 on success or -1 on invalid header or on the assert path (off_5DA714/off_5DA718, HaltAssertHandler 0x0052E520).

## Proposed classes

### InflateDecompressor

DEFLATE/zlib-style inflate context object owning the persistent bit-stream state (bit count this+0x1C, accumulator this+0x20), the per-block decode tables and the circular output-window bounds (this+0x28..0x34). Two functions operate on it: the outer block-level state machine (0x00527752) and the inner literal/length + distance symbol decode machine (0x00529B2C). The context is reentrant: state, bit buffer, input counters and cursor are persisted into the object on the need-more-input path and resumed on the next call. The overlapping views of this+0x4 (remaining length vs table pointer) and this+0x14 (decode table vs byte pair) are flagged in unresolved; the exact struct base per field is not proven.

Methods: `0x00527752`, `0x00529B2C`

- `this+0x00000000` `int state_selector` (read_write, DERIVED)
- `this+0x00000004` `int remaining_length_or_table` (read_write, DERIVED)
- `this+0x00000008` `int loop_counter` (read_write, DERIVED)
- `this+0x0000000C` `pointer work_table_buffer` (read_write, DERIVED)
- `this+0x00000010` `int decode_bit_count` (read_write, DERIVED)
- `this+0x00000014` `pointer decode_table` (read_write, DERIVED)
- `this+0x00000015` `byte code_extra_byte` (read_write, DERIVED)
- `this+0x00000018` `byte bfinal_flag` (read_write, DERIVED)
- `this+0x0000001C` `int bit_count` (read_write, DERIVED)
- `this+0x00000020` `int bit_accumulator` (read_write, DERIVED)
- `this+0x00000024` `int max_code_length` (read, DERIVED)
- `this+0x00000028` `pointer window_start` (read, DERIVED)
- `this+0x0000002C` `pointer window_end` (read, DERIVED)
- `this+0x00000030` `int window_capacity` (read, DERIVED)
- `this+0x00000034` `pointer output_cursor` (read_write, DERIVED)

### AudioDecodeFilterbank

Shared wave-table-backed audio decode/filter group reading the output-buffer base field this+0x11C (+128 offset). Includes the FIR-style channel convolution, the single-sample lookup, the two structural twin codec-transform selector branches on global byte_5D79DC, and the 8-point inverse synthesis filter. Membership of 0x0052855A / 0x005285A6 is grounded in the identical field-this+0x11C output offset and the same branch flag; it is a GUESS merge because the owners of the a2+80 / a3+48 / a4 / a5 pointer arguments are unknown.

Methods: `0x0052835F`, `0x0052851D`, `0x0052855A`, `0x005285A6`, `0x005285F2`

- `this+0x0000011C` `pointer wave_table_base` (read, DERIVED)

### MPEGSubbandTransform

MPEG audio frequency-domain synthesis transforms that operate on a 64-entry 16-bit subband sample array (fields this+0x0..0x70 at 0x10 stride read as element indices 0..56 step 8): the Layer 3 IMDCT synthesis filterbank (0x0052A6EC) and its 16-bit variant (0x0052B206), plus the MMX packed butterfly (0x0052AB4E) using the read-only qword twiddle table 0x005B0B98..0x005B0C58. The fields listed are element offsets of the caller-supplied subband input array, not proven members of one owning object; the grouping is a GUESS synthesis.

Methods: `0x0052A6EC`, `0x0052AB4E`, `0x0052B206`

- `this+0x00000000` `int16 subband_sample_index_0` (read, GUESS)
- `this+0x00000010` `int16 subband_sample_index_8` (read, GUESS)
- `this+0x00000020` `int16 subband_sample_index_16` (read, GUESS)
- `this+0x00000030` `int16 subband_sample_index_24` (read, GUESS)
- `this+0x00000040` `int16 subband_sample_index_32` (read, GUESS)
- `this+0x00000050` `int16 subband_sample_index_40` (read, GUESS)
- `this+0x00000060` `int16 subband_sample_index_48` (read, GUESS)
- `this+0x00000070` `int16 subband_sample_index_56` (read, GUESS)

### PackedColorSpaceDecoder

SSE/SSE2 packed color-space decode family: mask the packed input at this+0x0, affine dequantization, residual-square Horner polynomial chains, per-lane mask build and XOR blend merge, storing complementary output vector pairs. Grouping of the three functions is a GUESS merge on the shared packed-input pattern and the adjacent constant-table neighborhoods; common ownership is not proven by the packet.

Methods: `0x005289E0`, `0x00528BD0`, `0x00528CC0`

- `this+0x00000000` `__m128 packed_input` (read, GUESS)

### SIMDPackedMathHelpers

Convenience grouping of 3DNow/SIMD math helpers, two of which are empty stubs (0x00529000, 0x00529200) whose legacy ABI names and adjacent constant tables cannot be matched to code; the two remaining are structurally identical packed lower-lane absolute-value helpers (0x005295E0, 0x00529700). All constant-table globals near 0x005D92D8..0x005D9414 are context from the calling routines, not read by the bodies.

Methods: `0x00529000`, `0x00529200`, `0x005295E0`, `0x00529700`


### CMpegBase

MPEG audio decoder state object (packet-supplied DERIVED owner for 0x0052DA30). Holds the parsed frame-header fields: the layer index at this+0x2490, the derived bitrate and frame-size values at this+0x2484/0x2488/0x2494/0x2498, the per-field flag bytes at this+0x24C1..0x24C9, the channel count at this+0x24CC and PCM samples-per-frame at this+0x24D0. The only packet method parses a 32-bit MPEG audio frame header.

Methods: `0x0052DA30`

- `this+0x00002484` `int bitrate_value` (write, DERIVED)
- `this+0x00002488` `int bitrate_denominator` (write, DERIVED)
- `this+0x00002490` `int layer_index` (write, DERIVED)
- `this+0x00002494` `int frame_size_table_entry` (write, DERIVED)
- `this+0x00002498` `int frame_size` (write, DERIVED)
- `this+0x000024BD` `byte sampling_rate_flag_alt` (write, DERIVED)
- `this+0x000024BE` `byte sampling_rate_flag` (read_write, DERIVED)
- `this+0x000024BF` `byte bitrate_index_offset` (write, DERIVED)
- `this+0x000024C1` `byte emphasis_flag` (write, DERIVED)
- `this+0x000024C2` `byte copyright_flag` (write, DERIVED)
- `this+0x000024C3` `byte bitrate_index` (read, DERIVED)
- `this+0x000024C4` `byte bitrate_index_adjusted` (write, DERIVED)
- `this+0x000024C5` `byte protection_flag` (read_write, DERIVED)
- `this+0x000024C6` `byte channel_mode` (write, DERIVED)
- `this+0x000024C7` `byte mode_extension` (write, DERIVED)
- `this+0x000024C8` `byte original_flag` (write, DERIVED)
- `this+0x000024C9` `byte emphasis_alt` (write, DERIVED)
- `this+0x000024CC` `int channel_count` (write, DERIVED)
- `this+0x000024D0` `int pcm_samples_per_frame` (write, DERIVED)

### MPEGBufferDispatch

Thin guarded MPEG-buffer dispatch object: holds a function pointer at this+0x0 that, when non-null, is the target of the MPEGBuffer (0x0052E350) call forwarding a2/a3; when null the function returns 0. The stored pointer may be an optional or lazily-bound callback binding.

Methods: `0x0052D970`

- `this+0x00000000` `pointer buffer_callback_ptr` (read, GUESS)

### RenderGameObjectLifecycle

Render/game object lifecycle trio sharing the vtable off_5B47E8 installed at this+0x0 and the control flag/header at this+0x24EC/0x24F0: a constructor (0x0052D9B0), a scalar-deleting destructor that runs CConstructor plus a conditional FreeWrapper release (0x0052D9D0), and a vtable-initializing initializer (0x0052D9F0). Membership is a GUESS merge: equal offsets on the same base with no packet proof of common ownership, and 0x0052D9D0's named callee is CConstructor even though the surrounding shape is the classic conditional-free destructor pattern.

Methods: `0x0052D9B0`, `0x0052D9D0`, `0x0052D9F0`

- `this+0x00000000` `pointer vtable_ptr` (read_write, GUESS)
- `this+0x000024EC` `byte active_flag` (read_write, DERIVED)
- `this+0x000024F0` `int header_word` (write, DERIVED)

## Compatibility contracts

- **InflateContextStateContract** — A replacement inflater must preserve the reentrant context layout: the state selector at this+0x0 (0..8 valid, >9 invalid and returns -2), the per-block length/table slot this+0x4, loop counter this+0x8, work-table buffer this+0xC, decode bit count this+0x10, decode table this+0x14, bfinal flag this+0x18, bit count this+0x1C, bit accumulator this+0x20, max code length this+0x24, circular window bounds this+0x28/0x2C, window capacity this+0x30 and output cursor this+0x34, and must persist bit state, input counters and cursor on the need-more-input path; return values are 1 on stream end, -2 on invalid state, -3 on data/bitstream errors and -4 on allocation failure.
- **InflateStreamObjectContract** — The inflate stream object (a2) is indexed by raw-source dword fields: a2[0] the input read pointer, a2[1] the remaining input count, a2[2] the consumed-byte counter, a2[6] the error-string slot written by the invalid-block-type / invalid-stored-lengths / too-many-length-or-distance-symbols / invalid-bit-length-repeat paths, a2[8]/a2[9] the allocator/deallocator function pointers (the allocator is invoked as a2[8](a2[10], count, 4) for the code-length work table), and a2[10] the owner argument. A replacement stream driver must keep these slots.
- **MPEGFrameHeaderContract** — The MPEG frame-header parser must validate the 0xFFF00000 sync word (returning -1 otherwise), extract the layer to this+0x2490, the channel/mode/flag bytes to this+0x24C1..0x24C9, the bitrate index to this+0x24C3 and the adjusted bitrate index to this+0x24C4, derive the bitrate through dword_5B4764 into this+0x2484/0x2488, the frame-size table entry through word_5B4684 into this+0x2494, the final frame size into this+0x2498, and channel count / PCM samples-per-frame into this+0x24CC/0x24D0; the assert path for a zero bitrate index returns -1 through the off_5DA714/off_5DA718 function pointers (HaltAssertHandler 0x0052E520).
- **AudioSynthesisWindowLookupContract** — The audio decode output stage reads bytes from a wave table rooted at field this+0x11C plus a +128 offset, indexed by a fixed transform of the accumulator ((value + round) >> shift) & 0x3FF with variant rounding/shift pairs (+0x80000 >> 20, +4 >> 3, +0x20000 >> 18, x >> 5), and writes interleaved output through the caller-supplied a4 offset array into the a5 buffer. applyFIRConvolution, lookupAudioSample, AudioSynthesisFilter8Point and both IMDCT variants all share this pattern.
- **CodecModeSelectorContract** — The global flag byte_5D79DC selects between two audio codec transforms at the 0x0052855A and 0x005285A6 dispatch sites: non-zero routes to AudioCodecMDCTFFTTransform (0x0052AB4E) / QuaternionMultiplySurfaceSample (0x0052B561), zero to MPEGAudioLayer3IMDCT (0x0052A6EC) / MPEGAudioLayer3IMDCT_b206 (0x0052B206). A replacement must preserve this flag-gated two-way dispatch and the shared argument convention (a3, input, scratch, a4, a5, field-this+0x11C + 128).
- **RenderGameObjectLifecycleContract** — The render/game object lifecycle must install the vtable off_5B47E8 at this+0x0, gate deferred deactivation on the flag byte at this+0x24EC and clear the dword at this+0x24F0 during initialization; the scalar-deleting destructor runs the CConstructor routine (0x0052D9B0) and, when the deletion flag's bit 0 is set, releases the object through FreeWrapper (0x00587BCF), returning this unchanged.

## Unresolved

- Inflate context base (0x00527752 / 0x00529B2C): the inflate-context object is a 14-dword object with two overlapping views (persistent bit state this+0x0..0x20 vs per-block table/bit fields this+0x4..0x24); the raw-source dword indexing of a1 and the fact-table hex offsets agree arithmetically but the struct layout (union/overlay) is not proven. The inner machine additionally mixes stream-object offsets (bit count this+0x1C, bit buffer this+0x20, window bounds this+0x28/0x2C) with inner decoder-state offsets (this+0x4..0x18), so the exact struct base per field is not established.
- Inflate error strings (0x00527752): the error-string globals are matched to their literal text by IDA prefix names (aInvalidBlockTy/aInvalidStoredB/aTooManyLengthO/aInvalidBitLeng) plus inlined string literals; the exact global-address to string-text pairing was not independently cross-checked here. The a3 flush-style third argument is threaded into sub_52A5D7 unchanged; its semantic (flush vs finish) is not derivable from this packet.
- The inflate decode-table entry layout (8 bytes: bit length at +1, symbol value at +4), the dword_5DA520 bit-mask table and the dword_5B06E8 19-entry HCLEN order permutation are inferred from raw-source byte indexing; the table contents are not dumped in the packet.
- Callee contracts for the inflate helpers (sub_52A5D7 window flush, sub_529B2C inner decode, sub_52A426 code-length tree builder, sub_52C334 fast decode, 0x0052A090 IndirectCallDispatch, 0x00529AF8 FieldSetterWithVTableAlloc vtable layout) are caller-side and unverified; callee:0x0052E4E0 appears in the CMpegBase callee record but has no visible direct call in the raw source (sub_52E4E0 is listed in unresolved_evidence_refs).
- Audio filter group (0x0052835F / 0x0052851D / 0x0052855A / 0x005285A6 / 0x005285F2): a2+80, a3+48, the a4 index array and a5 buffer are reads/writes on caller-supplied pointers whose owner objects are unknown; the lowpass/highpass accumulator split (v14+v13 vs v13-v14) and the channel-skip pattern (6/4/2) are DERIVED, not grounded; the meaning of the +128 wave-table offset and of byte_5D79DC (DERIVED from branch position, no writer evidence) are unresolved.
- MPEGSubbandTransform (0x0052A6EC / 0x0052AB4E / 0x0052B206): the field offsets this+0x0..0x70 are element indices (0..56 step 8) of a caller-supplied 64-entry 16-bit subband sample array, not proven members of one owning object; the twiddle/rotation constants 0x005B0B98..0x005B0C58 and the MPEG synthesis window table (a6) provenance are not resolvable from these functions alone; ABI prototypes are legacy (abi:lead); the 16-bit variant's prelabel is a DERIVED cluster-copy of 0x0052A6EC and its coefficient/scale differences are observed, not independently proven.
- PackedColorSpaceDecoder (0x005289E0 / 0x00528BD0 / 0x00528CC0): the grouping is a GUESS merge on the shared packed-input read at this+0x0 and adjacent constant tables; the 0x005D8F30..0x005D9280 xmmword constants carry only prose names (dequantization/polynomial coefficients) and their numeric contents and exact roles are unverified; which packed lane feeds the zero-comparison blend (v14) and the final XOR operands is ambiguous due to stack-aliased __m128 temporaries; which lane maps to which output channel is not derivable. The caller at 0x00520E0E and the caller at 0x0052E170 are packet prose not present in the allowed refs.
- SIMDPackedMathHelpers (0x00529000 / 0x00529200 / 0x005295E0 / 0x00529700): 0x00529000 and 0x00529200 are empty no-op bodies whose legacy ABI names (Square_Root_Approximation) are unexercised; the read-only globals near 0x005D92D8..0x005D9414 are static-fact context from the calling 3DNow routines and do not belong to the bodies; grouping the empty stubs with the two packed absolute-value helpers is a GUESS convenience.
- RenderGameObjectLifecycle (0x0052D9B0 / 0x0052D9D0 / 0x0052D9F0): the equal offset this+0x0 is shared with other classes on the same base without packet proof of common ownership; the DeferredDeactivation call target inside 0x0052D9B0 has no callee evidence (its address is unknown); FreeWrapper_7bcf (0x00587BCF) allocator provenance is outside these functions; the named callee of the deleting destructor is CConstructor even though the surrounding control flow is the classic scalar-deleting pattern.
- MPEGBufferDispatch (0x0052D970): the semantic of the stored pointer at this[0] (optional vs lazily-bound callback binding) and the MPEGBuffer argument semantics of a2/a3 are unknown; the packet lists no callers.
- CMpegBase (0x0052DA30): the deterministic guard record flags this+0x24BE != 0 while the raw-source branch condition reads this+0x24BD (the two offsets differ by one byte) and the exact flag selected by the extraction is not fully reconciled; the semantic labels of the individual flag bytes (protection/copyright/original/emphasis) are DERIVED prose from the existing fill, not proven by this packet.
- General: no packet evidence establishes runtime truth; every class here except CMpegBase (DERIVED) is a GUESS proposal, and equal offsets on the same base across different classes are not proof that the fields or objects are identical.
