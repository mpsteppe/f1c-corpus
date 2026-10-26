# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

The packet describes two object families. Family A (sprite/media) is a runtime container that allocates a PlaybackStateController media buffer (0x005198B3), selects sprite frames (0x00519986), composites visible sprites onto a scan-line buffer (0x005199D5), copies the result into destination buffers (0x00519BB2), batch-processes drawable descriptors with a position-sync spin-wait (0x00519D51), copies validated render-state per object (0x00519EB7), runs the MPEG subband synthesis filterbank (0x00519F9A), and selects the per-frame processing handler (0x0051A4B7). Family B (bitstream) reads bytes with 0xFF escape handling (0x0051A794), decodes Huffman-coded texture sub-blocks (0x0051A9C6), resets decode counters (0x0051AEFC), decodes blocks with extra-bit tables (0x0051AF57), run-length/distance coding (0x0051B154), per-plane visibility bits (0x0051B37D), and signed deltas with rollback (0x0051B45F). Handler selection links the families conceptually through the shared container and the selectProcessingHandler dispatch slot.

## Function roles

- `0x005198B3` **SpriteRenderContext** — Media playback buffer allocation and frame-slot setup: allocates an 80-byte buffer, stamps it with the PlaybackStateController vtable, optionally dispatches playback state 4, gates on audio readiness and state 46, then allocates one frame buffer slot per sub-struct element.
- `0x00519986` **SpriteRenderContext** — Sprite frame value selection into the frame-info output struct: picks the frame from the sprite frame data array based on the animation position versus the frame limit, or pins the value to 1 in multi-frame mode, and zeroes two output fields.
- `0x005199D5` **SpriteRenderContext** — Compositing pass over visible sprites onto the shared scan-line buffer: zeroes the line buffer, polls readiness, dispatches each visible sprite draw callback per element, and advances frame counters with return codes 0/3/4.
- `0x00519BB2` **SpriteRenderContext** — Copy of composited sprite pixel data into destination buffers through per-object sprite descriptors, advancing the animation frame when the copy line reaches the buffer limit.
- `0x00519D51` **DrawableObjectBatchProcessor** — Drawable-batch processing: spin-waits for render-position synchronization via a progress callback, allocates per-slot row buffers from the sub-allocator, and dispatches per-row render calls through a per-slot vtable entry; returns 3/4 as completion codes.
- `0x00519EB7` **SpriteRenderContext** — Validated render-state copy per sprite object descriptor: lazily allocates the destination buffer, skips null/negative entries, copies 5 dwords per object and returns a validation flag.
- `0x00519F9A` **AudioSubbandSynthesisFilterbank** — MPEG audio subband synthesis filterbank: fills the subband input buffer, runs the polyphase synthesis loop per active channel with five scaling/shift-clamp filters and a per-block synthesis callback, then advances the subband block counter.
- `0x0051A4B7` **SpriteRenderContext** — Per-frame processing-handler selection: when the handler-state enable flag is set, chooses AudioSubbandSynthesisFilterbank when the mode byte is nonzero and RenderStateCopyWithValidation succeeds, otherwise DrawableObjectBatchProcessor; zeroes the position counter.
- `0x0051A794` **BitstreamReaderWithEscape** — Bit accumulator refill with 0xFF escape (start-code emulation) handling and a one-shot escape-underflow error signal through the parent context.
- `0x0051A9C6` **HuffmanCodec** — Huffman texture batch decode: conditionally reinitializes via AudioBufferReset, decodes up to this+0x13C sub-blocks into the output descriptor array consulting three lookup globals, and persists bitstream/decode state.
- `0x0051AEFC` **HuffmanCodec** — Consumed-byte counter accumulation and decode-counter reset: adds consumed bytes to an output total, zeroes the byte counter, invokes an indirect callback and, on a nonzero result, resets per-channel counters, a ready flag and a counter field.
- `0x0051AF57` **HuffmanCodec** — Single-block bitstream decode: conditionally resets counters, decodes Huffman symbols per sub-block with short-code and extra-bit threshold/base-offset tables, writes 16-bit output words, and decrements the remaining-block count.
- `0x0051B154` **HuffmanCodec** — Huffman decode with run-length and distance encoding: refreshes the block counter, decodes symbols through a short-symbol table or the symbol decoder, and writes run-length/distance-adjusted words shifted by this+0x174.
- `0x0051B37D` **HuffmanCodec** — Per-plane visibility bit test with bitfield output: reads one bit per plane sub-block from the bitstream, ORs a mask into caller-supplied 16-bit output words, and persists the decode state.
- `0x0051B45F` **HuffmanCodec** — Huffman-coded signed delta decode with sign adjustment over a coefficient range and rollback of modified entries on failure.

## Proposed classes

### SpriteRenderContext

Container object for sprite compositing and media playback: owns a sub-allocator vtable, sprite descriptor arrays, the frame/copy working state at +0x184, frame/position counters and limits, and the per-frame processing-handler selection that dispatches between the audio-synthesis and drawable-batch handlers.

Methods: `0x005198B3`, `0x00519986`, `0x005199D5`, `0x00519BB2`, `0x00519EB7`, `0x0051A4B7`

- `this+0x00000000` `void** vtable` (read, GUESS)
- `this+0x00000004` `SubAllocatorVtable* sub_allocator_vtable` (read, DERIVED)
- `this+0x00000020` `int element_count` (read, DERIVED)
- `this+0x00000049` `char mode_byte` (read, GUESS)
- `this+0x00000080` `int frame_position` (read_write, DERIVED)
- `this+0x00000088` `int frame_counter` (read_write, DERIVED)
- `this+0x0000008C` `int* render_state_source_buffer` (read, DERIVED)
- `this+0x000000C4` `SpriteObjectDescriptor* sprite_object_descriptor_array` (read, DERIVED)
- `this+0x000000C8` `int render_state_enable_flag` (read, DERIVED)
- `this+0x00000114` `int frame_size_factor` (read, DERIVED)
- `this+0x00000118` `int frame_limit` (read, DERIVED)
- `this+0x00000120` `int sprite_count` (read, DERIVED)
- `this+0x00000124` `SpriteDescriptor* sprite_frame_data_array` (read, DERIVED)
- `this+0x00000134` `int line_lower_bound` (read, DERIVED)
- `this+0x0000013C` `int line_buffer_size` (read, DERIVED)
- `this+0x00000180` `void* media_buffer_ptr` (write, DERIVED)
- `this+0x00000184` `FrameProcessingState* frame_copy_state_ptr` (read_write, DERIVED)
- `this+0x0000018C` `void** frame_complete_callback_vtable` (read, DERIVED)
- `this+0x00000194` `void** buffer_readiness_vtable` (read, DERIVED)
- `this+0x00000198` `int scan_position` (read_write, GUESS)
- `this+0x0000019C` `int current_line` (read_write, DERIVED)
- `this+0x000001A0` `int line_limit` (read, DERIVED)
- `this+0x000001A4` `void* line_buffer` (read_write, DERIVED)
- `*(this+0x19C)+0x00000008` `char audio_readiness_flag` (read, DERIVED)
- `obj+0x00000000` `void** buffer_vtable` (write, DERIVED)
- `obj+0x00000014` `int dispatcher_state` (read_write, GUESS)

### DrawableObjectBatchProcessor

Batch processor for drawable sprite descriptors: synchronizes render positions, allocates per-slot row buffers from the sub-allocator, and dispatches per-row render calls through a per-slot vtable entry.

Methods: `0x00519D51`

- `this+0x00000004` `SubAllocatorVtable* sub_allocator_vtable` (read, DERIVED)
- `this+0x00000020` `int sprite_object_count` (read, DERIVED)
- `this+0x0000007C` `int sub_position` (read, DERIVED)
- `this+0x00000080` `int scan_position` (read, DERIVED)
- `this+0x00000084` `int sub_position_limit` (read, DERIVED)
- `this+0x00000088` `int total_position_counter` (read_write, DERIVED)
- `this+0x000000C4` `SpriteObjectDescriptor* descriptor_array` (read, DERIVED)
- `this+0x00000118` `int line_position_limit` (read, DERIVED)
- `this+0x00000184` `FrameProcessingState* frame_info_ptr` (read, DERIVED)
- `this+0x0000018C` `void** progress_callback_vtable` (read, DERIVED)
- `this+0x00000198` `void*** render_dispatch_table` (read, GUESS)

### AudioSubbandSynthesisFilterbank

MPEG audio subband synthesis filterbank: fills the subband input buffer and runs the polyphase synthesis loop over active channels with a per-block synthesis callback; selected as a per-frame processing handler by SpriteRenderContext.

Methods: `0x00519F9A`

- `this+0x00000004` `SubAllocatorVtable* sub_allocator_vtable` (read, GUESS)
- `this+0x00000020` `int channel_count` (read, DERIVED)
- `this+0x0000007C` `int input_read_position` (read, DERIVED)
- `this+0x00000080` `int scan_position` (read, DERIVED)
- `this+0x00000084` `int input_limit` (read, DERIVED)
- `this+0x00000088` `int block_counter` (read_write, DERIVED)
- `this+0x000000C4` `void* channel_state_array` (read, DERIVED)
- `this+0x00000118` `int block_count_limit` (read, DERIVED)
- `this+0x00000168` `int fill_loop_term` (read, GUESS)
- `this+0x00000184` `void* decoder_working_state` (read, DERIVED)
- `this+0x0000018C` `void** codec_callback_vtable` (read, DERIVED)
- `this+0x00000198` `void* synthesis_callback` (read, GUESS)

### BitstreamReaderWithEscape

Bit accumulator reader that refills a byte buffer through a callback table, handles 0xFF start-code escape sequences, and signals escape-underflow errors once through a parent context.

Methods: `0x0051A794`

- `this+0x00000000` `char* byte_cursor` (read_write, DERIVED)
- `this+0x00000004` `int bytes_remaining` (read_write, DERIVED)
- `this+0x00000008` `int saved_escape_byte` (read_write, DERIVED)
- `this+0x0000000C` `int bit_accumulator` (read_write, DERIVED)
- `this+0x00000018` `int bit_count` (read_write, DERIVED)
- `this+0x0000001C` `void** parent_context_vtable` (read, DERIVED)
- `this+0x00000020` `int error_latch` (read_write, DERIVED)
- `this+0x00000030` `void** refill_table` (read, DERIVED)
- `*(*(this+0x30)+0x0)+0x00000000` `void* refill_function` (read, GUESS)
- `obj+0x00000000` `void** error_vtable` (read, GUESS)

### HuffmanCodec

Huffman-coded bitstream decoder container: block-counter management, per-sub-block symbol decode, run-length/distance and signed-delta variants, and per-plane visibility tests, sharing a decode-state struct at this+0x194 and the global decode lookup tables.

Methods: `0x0051A9C6`, `0x0051AEFC`, `0x0051AF57`, `0x0051B154`, `0x0051B37D`, `0x0051B45F`

- `this+0x00000000` `void** vtable` (read, GUESS)
- `this+0x00000014` `void* read_pointer_record` (read_write, DERIVED)
- `this+0x00000018` `int write_state` (read_write, DERIVED)
- `this+0x000000FC` `int block_count_flag` (read, DERIVED)
- `this+0x00000120` `int channel_count` (read, DERIVED)
- `this+0x0000013C` `int sub_block_count` (read, DERIVED)
- `this+0x00000140` `int* output_descriptor_array` (read_write, DERIVED)
- `this+0x00000168` `int decode_range_start` (read, DERIVED)
- `this+0x0000016C` `int decode_range_end` (read, DERIVED)
- `this+0x00000174` `int output_shift` (read, DERIVED)
- `this+0x00000178` `int saved_scalar` (read_write, GUESS)
- `this+0x00000190` `void* byte_total_record` (read, GUESS)
- `this+0x00000194` `HuffmanDecodeState* decode_state` (read_write, DERIVED)
- `this+0x000001A4` `int bit_accumulator` (read_write, DERIVED)
- `this+0x000001A8` `int bit_count` (read_write, DERIVED)
- `this+0x000001AC` `char ready_flag` (read_write, DERIVED)
- `this+0x000001B4` `int remaining_count` (read_write, DERIVED)
- `this+0x000001B8` `int[0x120] per_channel_counters` (write, DERIVED)
- `this+0x000001BC` `int intermediate_value_a` (read_write, GUESS)
- `this+0x000001C0` `int intermediate_value_b` (read_write, GUESS)
- `this+0x000001C4` `int remaining_block_counter` (read_write, DERIVED)
- `this+0x000001C8` `int block_counter` (read_write, DERIVED)
- `this+0x000001DC` `void* huffman_tree_ptr` (read, DERIVED)
- `this+0x000001E8` `int output_total` (read_write, DERIVED)
- `obj+0x00000004` `void* error_handler_vtable` (read, DERIVED)
- `obj+0x00000014` `int error_slot` (read_write, DERIVED)

### SpriteDescriptor

Per-sprite frame descriptor consumed by the compositing and copy passes: type, width, visibility, strides, source offsets and the scan threshold.

Methods: 

- `*(this+0x124)+0x00000004` `int sprite_type` (read, DERIVED)
- `*(this+0x124)+0x0000000C` `int width` (read, DERIVED)
- `*(this+0x124)+0x00000024` `int draw_stride` (read, DERIVED)
- `*(this+0x124)+0x00000030` `char visibility_flag` (read, DERIVED)
- `*(this+0x124)+0x00000034` `int low_source_offset` (read, DERIVED)
- `*(this+0x124)+0x00000038` `int row_count` (read, DERIVED)
- `*(this+0x124)+0x0000003C` `int stride_step` (read, DERIVED)
- `*(this+0x124)+0x00000040` `int row_multiplier` (read, DERIVED)
- `*(this+0x124)+0x00000044` `int high_source_offset` (read, DERIVED)
- `*(this+0x124)+0x00000048` `int scan_threshold` (read, DERIVED)

### SpriteObjectDescriptor

Sprite object descriptor array element (84-byte stride) used by batch draw and render-state copy.

Methods: 

- `*(this+0xC4)+0x0000000C` `int width` (read, DERIVED)
- `*(this+0xC4)+0x0000001C` `int row_stride` (read, DERIVED)
- `*(this+0xC4)+0x00000020` `int element_field` (read, GUESS)
- `*(this+0xC4)+0x00000024` `int row_step` (read, DERIVED)
- `*(this+0xC4)+0x00000030` `char enable_flag` (read, DERIVED)
- `*(this+0xC4)+0x0000004C` `SpriteObjectWordRecord* sprite_object_word_array` (read, DERIVED)

### SpriteObjectWordRecord

Word-array record referenced by each sprite object descriptor at +0x4C; entries are validated non-null before the render-state copy.

Methods: 

- `*(*(this+0xC4)+0x4C)+0x00000000` `unsigned short word_00` (read, GUESS)
- `*(*(this+0xC4)+0x4C)+0x00000002` `unsigned short word_02` (read, GUESS)
- `*(*(this+0xC4)+0x4C)+0x00000004` `unsigned short word_04` (read, GUESS)
- `*(*(this+0xC4)+0x4C)+0x00000010` `unsigned short word_10` (read, GUESS)
- `*(*(this+0xC4)+0x4C)+0x00000012` `unsigned short word_12` (read, GUESS)
- `*(*(this+0xC4)+0x4C)+0x00000020` `unsigned short word_20` (read, GUESS)

### FrameProcessingState

Frame/copy working-state object reachable at this+0x184: holds the selected processing handler, the enable flag, the per-slot allocation index array and the destination render-state buffer.

Methods: 

- `*(this+0x184)+0x0000000C` `void* processing_handler_slot` (read_write, DERIVED)
- `*(this+0x184)+0x00000010` `int enable_flag` (read, DERIVED)
- `*(this+0x184)+0x00000048` `int* allocation_index_array` (read, DERIVED)
- `*(this+0x184)+0x00000070` `void* render_state_buffer` (read_write, DERIVED)

## Compatibility contracts

- **FrameStepReturnCodes** — Compositing and batch-processing entry points return 0 (partial line/copy), 3 (next sprite frame) and 4 (frame sequence complete); callers must not treat a nonzero return as an error and must re-invoke the entry point to continue.
- **DecoderFailureReturnZero** — Bitstream readers and Huffman decoders return 1 on success and 0 on refill/decoder/counter failure; callers propagate the zero and abort the current frame decode.
- **MediaBufferLayout** — The media buffer is 80 bytes, allocated through sub-allocator entry 0, holds its vtable at offset 0 (PlaybackStateController, global 0x0051984B) and one frame-buffer slot per descriptor element beginning 8 bytes in; the final slot index is returned to the caller.
- **RenderStateRecordLayout** — The render-state copy writes 5 dwords per sprite object into a destination buffer at *(this+0x184)+0x70 with a 24-byte destination stride and a 256-byte source stride; a validation flag is returned when any copied dword is non-zero.

## Unresolved

- The sprite/media functions (0x005198B3, 0x00519986, 0x005199D5, 0x00519BB2, 0x00519EB7, 0x0051A4B7) are grouped into one container (SpriteRenderContext) on the shared this+0x4/0x20/0xC4/0x184/0x80/0x88/0x118 layout, but 0x00519D51 carries the packet's DERIVED owner DrawableObjectBatchProcessor and 0x00519F9A is dispatched under the label AudioSubbandSynthesisFilterbank; whether these are one class or several tightly-coupled classes sharing a container is not proven by this packet.
- 0x00519EB7's packet prose names its invoker ProtocolStateHandler while 0x0051A4B7 is named selectProcessingHandler; both are grouped under SpriteRenderContext here, and the ProtocolStateHandler label is not otherwise evidenced.
- this+0x198 is read as a draw-dispatch table (0x00519D51 and CompositingPass), as the scan/copy position (CompositingPass, CompositingCopy), and as an output frame value (SpriteFrameSelector); the three readings are not reconciled.
- Sprite descriptor field +0x30 is read as a visibility/enable byte in the raw source, but the packet field table lists it as an offset; the byte interpretation is DERIVED and the two readings conflict (also for SpriteObjectDescriptor +0x30, labeled 'Y stride in buffer' elsewhere).
- The descriptor fields used in the frame-size calculation of 0x005198B3 (the fields eight and twenty-four bytes below *(this+0xC4)+0x24) have no packet field references.
- The frame-size factor (this+0x114 + 2) and the dispatcher state values 4 and 46 written by MediaBufferAllocAndSetup are not interpreted by the packet.
- The refill table is modeled by deterministic fields as this+0x30 (entries 0x0/0x4/0xC) but the raw source resolves it through parent+0x14 double indirection; the two models are not reconciled.
- The 5-dword render-state record (24-byte destination stride) and the 84-byte sprite descriptor layout are not defined by the packet.
- 0x00519F9A's decoder scalar fields (this+0x24, 0xD0, 0xE0, 0xE4, 0xE8, 0xF4, 0x110, 0x19D, 0x1CC, 0x1F4) and the *(this+0x110) word offsets are listed by the fact extractor but not used by the visible raw body; their roles require the channel-state/decoder layout to be confirmed.
- The Huffman table layout (direct short-code table at tree+212, per-symbol table at tree+1236) is inferred from index expressions only; the organization of the five lookup globals (which length/distance/output table each serves) is not grounded.
- The block decoders use different remaining-block counters inside the decode state (0x0051A9C6 reads this+0x1C4 while the others read this+0x1C8); the decode-state sub-struct at this+0x194 is shared by usage but its layout is not packet-defined.
- BitstreamReaderWithEscape's a1 record (this+0x0/0x4/0x8/0xC/0x18) may alias the caller's stack read-state record rather than the container object; the parent-context relationship (this+0x1C versus this+0x30) is unresolved.
- The per-slot word loaded from a2[slot] in 0x00519D51 and its role as the v16 render argument are unconfirmed, and the a2 per-sprite base-offset array layout of CompositingPass is caller-defined.
- 0x0051AEFC's read-only field this+0x198 is listed by the fact extractor but never referenced in the function body; the indirect callback target at *(this+0x190+8) is not statically resolvable.
