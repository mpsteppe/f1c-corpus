# MediaCodecAndCompressionRuntime

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Proposed MediaCodecAndCompressionRuntime covering three independent runtime areas evidenced in the packet: (1) an audio/video frame decoder sharing one decode-state object across codec dispatch (0x0052DF10), compressed-audio frame decode (0x0052E6F0), Huffman sample rendering (0x00530840), frame decompression dispatch (0x00531250), the float-to-PCM mix stage (0x00531830) and the SIMD polyphase resampler (0x00532AA0), selected in part by the global codec-initialized flag 0x008B0108; (2) a zlib/deflate-style compression stream runtime whose single state object carries the sliding window, hash-chain arrays and the high-offset Huffman encoder state shared by DecompressionBufferFlush (0x00536300), TextBufferDecompressor (0x00536440), the two deflate core loops (0x005365D0/0x00536A70), ScorecardZero (0x00537EC0), HuffmanBitStreamEncoder (0x005381F0), HuffmanSymbolBitPacker (0x00539200) and BitstreamFlushRegister (0x00539690); (3) codec boot initialization over globals 0x008B0108/0x008B0118 (0x0052DF70/0x0052E577/0x0052E6E7), the audio codec context initializer (0x00536260), audio-driver callback registration (0x00534AC0), the Win32 AVI import thunks (0x00534AE6/0x00534AEC) and a placeholder no-op (0x00537EB0). Ownership is largely UNKNOWN; the class grouping is DERIVED from shared field access on a common this object.

## Function roles

- `0x0052DF10` **AudioFrameDecoder** — Codec-type dispatcher: vtable precondition at slot +8, then dispatch on codec-type byte at this+0x2490 to audio decode (0x0052E6F0) or frame decompression (0x00531250); returns -1 when not ready.
- `0x0052DF70` **CodecGlobalStateInit** — Boot-time helper: runs CPUID feature check, stores result into global dword_8B0108, and conditionally performs a ROM table copy when the check succeeds.
- `0x0052E577` **CodecGlobalStateInit** — Zeroes global dword_8B0118[0..2] and writes value 1 at index 0 through a bounds-checked byte setter.
- `0x0052E6E7` **CodecGlobalStateInit** — Constructor-style initializer that installs the global vtable pointer value dword_8B0118 into the object's first DWORD.
- `0x0052E6F0` **AudioFrameDecoder** — Decodes one compressed audio frame from the bitstream into 16-bit PCM: nibble selectors, Huffman-coded VQ (initialized path) or raw selectors with float dequantize (uninitialized path), then resample or mix to PCM output.
- `0x00530840` **AudioFrameDecoder** — Renders Huffman-decoded VQ samples into interleaved 16-bit word output, reading codebook selectors and Huffman bits from the shared bitstream; zero-fills unused mono/stereo slots by subband count.
- `0x00531250` **AudioFrameDecoder** — Frame decompression dispatcher: decodes codebook selectors and delta side-information from the bitstream, then selects hardware-accelerated (0x00530840 + resampler) or software (0x00530050 + mixer) decode/mix path on global dword_8B0108.
- `0x00531830` **AudioFrameDecoder** — Audio mixer output stage converting floating-point MDCT-transformed samples to clamped interleaved 16-bit PCM; advances a 4-bit phase counter and mixes two 16-tap passes against unk_5B666C.
- `0x00532AA0` **AudioFrameDecoder** — MMX-accelerated polyphase audio resampler: phase counter advance, per-channel SIMD transform, and pmaddwd/packssdw convolution against stereo or mono coefficient tables into interleaved 16-bit PCM.
- `0x00534AC0` **AudioDriverInitRegistration** — Audio-driver init registration stub: hands the address of global loc_534AD0 to BooleanToIntConversion (0x00587B3E) and returns 0.
- `0x00534AE6` **AviApiImportThunks** — Import trampoline forwarding pfile to the imported AVIFileRelease through __imp_AVIFileRelease at 0x0059E050.
- `0x00534AEC` **AviApiImportThunks** — Import trampoline forwarding pavi to the imported AVIStreamRelease through __imp_AVIStreamRelease at 0x0059E054.
- `0x00536260` **AudioCodecContext** — Initializes an audio codec context: buffer sizing and zeroing, codec configuration words loaded by codec type, state counters and flags cleared, channel fields forced to 2.
- `0x00536300` **DeflateCompressionStream** — Decompression buffer flush driving an LZSS-style text stream: refills pending input, emits runs via HuffmanBitStreamEncoder, copies with size tracking, and returns a status code keyed on the a2 end-of-data marker.
- `0x00536440` **DeflateCompressionStream** — Refills the compression window, slides it when the read position nears the end (re-basing hash-chain arrays), reads via the vtable stream-reader, and computes the initial hash.
- `0x005365D0` **DeflateCompressionStream** — Deflate core loop: hash-chain insertion, longest-match search, literal or length/distance emission with frequency updates, and flush via HuffmanBitStreamEncoder when the pending buffer fills.
- `0x00536A70` **DeflateCompressionStream** — Deflate compression loop structurally twin to 0x005365D0 with match-quality heuristics and deferred-literal handling.
- `0x00537EB0` **UnknownObject** — Empty no-op placeholder (nullsub_5) referenced from the UI element initialization path; never given a body.
- `0x00537EC0` **DeflateCompressionStream** — Resets per-block frequency/cost accumulators: zeroes three word runs and four dword counters, sets one flag to 1; called by HuffmanBitStreamEncoder.
- `0x005381F0` **DeflateCompressionStream** — Huffman bitstream encoder: skips tree rebuild when the block counter is exhausted, validates the checksum, builds two Huffman trees, packs symbols, flushes full bytes, rebuilds fixed/dynamic code tables, and resets accumulators via ScorecardZero.
- `0x00539200` **DeflateCompressionStream** — Huffman symbol bit packer: serializes pending literal/length/distance symbols into the bitstream via code tables, extra-bit tables and an end-of-block code.
- `0x00539690` **DeflateCompressionStream** — Bitstream shift-register flush: writes full or partial accumulator bytes to the output buffer and returns the remaining bit count.

## Proposed classes

### AudioFrameDecoder

Codec-type-dispatched audio/video frame decode over one shared decode-state object: vtable dispatch and readiness precondition, codec-type select, bitstream buffer and bit cursor, subband count, channel mode/count, 4-bit phase counter and output stride. Methods cover dispatch, compressed-frame decode, Huffman sample rendering, frame decompression dispatch, float-to-PCM mix and SIMD polyphase resample.

Methods: `0x0052DF10`, `0x0052E6F0`, `0x00530840`, `0x00531250`, `0x00531830`, `0x00532AA0`

- `this+0x00000000` `void** vtable_ptr` (read, DERIVED)
- `obj+0x00000008` `void* vtable_precondition_slot` (read, GUESS)
- `this+0x00002490` `uint8_t codec_type` (read, DERIVED)
- `this+0x000024A4` `uint8_t* bitstream_buffer_ptr` (read, DERIVED)
- `this+0x000024A8` `uint32_t bit_cursor` (read_write, DERIVED)
- `this+0x000024B8` `uint16_t subband_count` (read_write, GUESS)
- `this+0x000024BC` `uint8_t phase_counter` (read_write, GUESS)
- `this+0x000024BE` `uint8_t channel_mode_byte` (read, UNKNOWN)
- `this+0x000024C3` `uint8_t codebook_lookup_a` (read, UNKNOWN)
- `this+0x000024C4` `uint8_t codebook_lookup_b` (read, UNKNOWN)
- `this+0x000024CC` `uint8_t channel_count` (read, DERIVED)
- `this+0x000024D0` `uint32_t output_stride` (read, GUESS)

### DeflateCompressionStream

Zlib/deflate-style compression stream runtime over one state object: sliding window and hash-chain arrays, window refill and slide, hash-chain LZ77 longest-match core loops, per-block frequency/cost accumulators, and the high-offset Huffman encoder state (bit accumulator, bit count, output base/cursor, pending-symbol buffers, end-of-block code).

Methods: `0x00536300`, `0x00536440`, `0x005365D0`, `0x00536A70`, `0x00537EC0`, `0x005381F0`, `0x00539200`, `0x00539690`

- `this+0x00000000` `void** vtable_ptr` (read, DERIVED)
- `obj+0x00000004` `void* vtable_stream_read_slot` (read, GUESS)
- `this+0x00000008` `uint8_t* output_buffer_base` (read, GUESS)
- `this+0x00000014` `uint32_t output_byte_cursor` (read_write, GUESS)
- `this+0x00000022` `uint16_t window_size` (read, DERIVED)
- `this+0x0000002E` `uint8_t* window_base_ptr` (read, DERIVED)
- `this+0x00000032` `uint16_t lookahead_target` (read, GUESS)
- `this+0x00000036` `uint16_t* hash_head_array` (read_write, GUESS)
- `this+0x0000003A` `uint16_t* hash_prev_array` (read_write, GUESS)
- `this+0x0000003E` `uint32_t current_hash` (read_write, GUESS)
- `this+0x00000042` `uint16_t match_offset_adjust_counter` (read, UNKNOWN)
- `this+0x0000004A` `uint32_t hash_mask` (read, GUESS)
- `this+0x0000004E` `uint32_t hash_shift` (read, GUESS)
- `this+0x00000052` `uint32_t bytes_consumed` (read_write, GUESS)
- `this+0x00000062` `uint32_t read_position` (read_write, GUESS)
- `this+0x00000066` `uint32_t slide_offset` (read_write, UNKNOWN)
- `this+0x0000006A` `uint32_t available_byte_count` (read_write, DERIVED)
- `this+0x0000008A` `uint16_t[286] freq_run_286_words` (write, UNKNOWN)
- `this+0x00000400` `uint16_t eob_code_word` (read, GUESS)
- `this+0x00000402` `uint16_t eob_code_length` (read, GUESS)
- `this+0x0000048A` `uint16_t active_flag` (write, UNKNOWN)
- `this+0x0000097E` `uint16_t[30] freq_run_30_words` (write, UNKNOWN)
- `this+0x00000A72` `uint16_t[19] freq_run_19_words` (write, UNKNOWN)
- `this+0x00001693` `uint32_t counter_1693` (write, UNKNOWN)
- `this+0x0000169B` `uint32_t counter_169B` (write, UNKNOWN)
- `this+0x0000169F` `uint32_t counter_169F` (write, UNKNOWN)
- `this+0x000016A3` `uint32_t counter_16A3` (write, UNKNOWN)
- `this+0x000016AB` `uint16_t bit_accumulator` (read_write, DERIVED)
- `this+0x000016AC` `uint8_t bit_accumulator_high` (read_write, GUESS)
- `this+0x000016AD` `uint8_t bit_count` (read_write, DERIVED)

### AudioCodecContext

Small audio codec context object initialized by AudioCodecInit: parameter-derived buffer sizing and zeroing, codec-type-indexed configuration words, state counters/flags, and channel/format fields.

Methods: `0x00536260`

- `this+0x00000022` `uint16_t param_size` (read, GUESS)
- `this+0x00000032` `uint32_t buffer_size` (write, GUESS)
- `this+0x0000003A` `uint8_t* buffer_start` (read_write, GUESS)
- `this+0x00000042` `uint16_t buffer_size_words` (read, GUESS)
- `this+0x0000007A` `uint8_t codec_type` (read, GUESS)
- `this+0x00000076` `uint16_t codec_decode_tab_size` (write, GUESS)
- `this+0x00000082` `uint16_t codec_decode_param_a` (write, GUESS)
- `this+0x00000086` `uint16_t codec_decode_param_b` (write, GUESS)
- `this+0x00000072` `uint16_t codec_mode_tag` (write, GUESS)
- `this+0x00000062` `uint32_t state_counter_c` (write, UNKNOWN)
- `this+0x00000052` `uint32_t state_counter_a` (write, UNKNOWN)
- `this+0x0000006A` `uint32_t state_counter_b` (write, UNKNOWN)
- `this+0x0000005E` `uint16_t state_flag_b` (write, UNKNOWN)
- `this+0x0000003E` `uint16_t state_flag_a` (write, UNKNOWN)
- `this+0x0000006E` `uint16_t channel_format_b` (write, UNKNOWN)
- `this+0x00000056` `uint16_t channel_format_a` (write, UNKNOWN)

### CodecGlobalStateInit

Boot-time initialization over the codec global state (0x008B0108 feature flag, 0x008B0118 vtable/buffer global): CPU feature check, buffer zeroing, and vtable-pointer installation.

Methods: `0x0052DF70`, `0x0052E577`, `0x0052E6E7`

- `this+0x00000000` `void* vtable_slot` (write, GUESS)

### AviApiImportThunks

Straight import trampolines for the Win32 AVI API (avifil32.dll): AVIFileRelease and AVIStreamRelease forwarded through their IAT slots.

Methods: `0x00534AE6`, `0x00534AEC`


### AudioDriverInitRegistration

Audio-driver initialization callback registration stub that forwards the address of the global loc_534AD0 and returns 0.

Methods: `0x00534AC0`


## Compatibility contracts

- **CodecTypeDispatch** — Decode entry 0x0052DF10 must invoke the vtable precondition at slot +8 (via the vtable pointer at this+0) and return -1 when it reports not-ready; then dispatch on the codec-type byte at this+0x2490: 1 selects the compressed-audio frame decoder (0x0052E6F0), 2 selects the frame decompression dispatcher (0x00531250), and any other value returns 0.
- **CodecInitGate** — Global codec-initialized flag 0x008B0108 is written once by 0x0052DF70 from the CPU feature check and then selects the decode strategy in 0x0052E6F0 and 0x00531250: nonzero takes the table/Huffman (hardware) path, zero takes the raw software path. A replacement must preserve this global gate and the path split it drives.
- **HuffmanEncoderStateLayout** — The deflate encoder keeps pending-symbol state, a 16-bit bit accumulator at 0x16AB/0x16AC, a bit count at 0x16AD, an output buffer base at this+0x8 and byte cursor at this+0x14, and the end-of-block Huffman code pair at 0x400/0x402; 0x005381F0, 0x00539200 and 0x00539690 all share this layout.
- **DeflateFlushReturnCodes** — 0x005365D0 and 0x00536A70 return 0 when more input is needed or the output stream is full, otherwise 1 + 2*(a2==4); a2==4 marks end-of-data. 0x00536300 returns 0 or 2 when the buffer status field at *a1+16 is clear and 2*(a2==4)+1 otherwise. A replacement must keep these status semantics.
- **WindowRefillThreshold** — The compression stream refills via 0x00536440 whenever the available byte count at this+0x6A drops below 262 and slides the window (re-basing the hash-chain arrays) when the read position nears the window end; refill continues until 262 bytes are present or the vtable stream-read slot (vtable[1], at obj offset +4) is null.
- **MixerResamplerSharedState** — The float-to-PCM mixer (0x00531830) and the polyphase resampler (0x00532AA0) share the 4-bit phase counter at this+0x24BC and the channel count at this+0x24CC with the decode stages; phase advance and channel stride must be preserved for correct interleaved PCM output.
- **AviImportTrampolines** — AVIFileRelease (0x00534AE6) and AVIStreamRelease (0x00534AEC) forward straight to the load-time IAT imports at 0x0059E050 and 0x0059E054 and must return the imported ULONG result unchanged.

## Unresolved

- 0x0052DF10: the concrete decoder object class and the exact precondition checked by the vtable slot at +8 are unknown; the meaning of the a2 input depends on the caller MPEGBuffer context.
- 0x0052DF70: the identity and target address of the ROM data table copy helper are absent from the callee evidence; which CPU feature bit the check tests and what dword_8B0108 records beyond a codec-initialized flag are not evidenced.
- 0x0052E577 / 0x0052E6E7: global dword_8B0118 is used as a zeroable buffer by 0x0052E577 but as a vtable pointer value by 0x0052E6E7; the contradictory uses are unresolved. BoundsCheckedByteSetter has no callee entry, and no callers of 0x0052E6E7 are evidenced.
- 0x0052E6F0: three read-only globals (0x005B4798, 0x005B47A0, 0x005B47A8) are flagged by the packet facts but do not appear in the raw source; the exact compressed-audio codec variant and bit layout are unconfirmed; mono/stereo block stride (128 vs 64) is not reconciled.
- 0x00530840: the codebook selector table a6 and the a2 scale table layouts are caller-defined; input bitstream endianness and sign handling in the Huffman bit reads are inferred; the jpt_530C9D and jpt_530EF8 zero-fill ordering is reconstructed from the switch body.
- 0x00531250: globals 0x005B4790, 0x005B47A0, 0x005B47B8 and 0x005B47D0 are read per static facts but absent from the visible body; Huffman/quantization bit semantics (6/12/18 bits) are codec-internal; whether the a2 output stride is bytes or samples is unconfirmed.
- 0x00531830: the meaning of the 4-bit phase counter at 0x24BC and the exact owning object are unresolved; the AudioMixer owner label is DERIVED from the legacy ABI name only, not runtime-proven; the unk_5B666C coefficient layout and the return-value contract for the two callers are not demonstrated.
- 0x00532AA0: the mono convolution reads a family of contiguous coefficient tables around unk_5B6F0C..5B72A4 but only unk_5B730C is listed; the stereo tap count (68) and the 0x10 pmulhw shift are unverified; treating the channel count as a signed count is DERIVED.
- 0x00534AC0: the callee BooleanToIntConversion is a legacy label whose real behavior is unknown; loc_534AD0 is only known as a data location whose address is forwarded.
- 0x00534AE6 / 0x00534AEC: why the game routes the AVI releases through manual import trampolines rather than direct IAT slots is unknown; the avifil32.dll implementations are outside this binary.
- 0x00536260: the meaning of the two fields forced to 2 (0x6E, 0x56) is not established; the codec lookup tables carry no per-entry semantics; the memset is a CRT call with no callgraph entry.
- 0x00536300: field semantics at a1+12, a1+34, a1+82, a1+98, a1+106 and the status flag at *a1+16 are named only by offset; the a2==4 end-of-data meaning is inferred; the compressed-text container owning a1 is unknown.
- 0x00536440: the inflate stage and window/hash-chain field semantics are DERIVED from the decompiled layout, not type- or runtime-confirmed; the concrete object behind the vtable is unknown; the qmemcpy slide direction is inferred; the return value meaning is unresolved.
- 0x005365D0 / 0x00536A70: the canonical/ABI names describe inflate/decompression but the raw code performs deflate COMPRESSION (hash-chain insertion, longest-match search, length/distance emission); the naming discrepancy is unresolved. The many state offsets are treated as opaque with no field evidence refs; the byte_5B82F8/5B83F8/5B84F8 table semantics are DERIVED.
- 0x00537EB0: why a call site in UIElementInitialization (0x00537E40) dispatches to an empty stub is unknown; the intended behavior was never implemented or inlined elsewhere.
- 0x00537EC0: the class owner is unknown; the word runs, the four dword counters at 0x1693/0x169B/0x169F/0x16A3 and the flag at 0x48A are unnamed; ScorecardZero is a LEGACY-trust ABI label, not a confirmed source symbol.
- 0x005381F0: the packet lists a read of global unk_5B7E00 that the raw source does not render; the tree arrays at a1+2830/2842 and the bit accumulator/cursor roles at a1+5803/5805 are interpretations from the analysis fill; the a2 gate and the a1+28 block-type encoding (2 = compressed) are inferred from deflate semantics.
- 0x00539200: the canonical name (HuffmanBitStreamDecoder) and the caller name (HuffmanBitStreamEncoder) disagree about encode vs decode while the raw body clearly writes bits; offsets a1+5771/5779/5783 and a1+5803/5805 are unnamed state slots; the byte_5B82F8/5B83F8 short/long base split is DERIVED.
- 0x00539690: the bit ordering (MSB-first vs LSB-first) of the accumulator at 0x16AB/0x16AC is undetermined; output-buffer ownership and capacity at this+0x8 are caller-provided; the partial-flush policy is a design detail not further constrained.
- AudioFrameDecoder groups the legacy AudioMixer and AudioResampler ABI names with the decode methods on one shared-state class; the packet only DERIVED the AudioMixer owner label, and whether mix/resample are distinct objects is unresolved.
- Offsets 0x22, 0x32, 0x3A, 0x42, 0x52, 0x62 and 0x6A appear in both the AudioCodecContext and the DeflateCompressionStream objects without proven common ownership; they are kept as separate fields per the no-merge rule.
