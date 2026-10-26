# JpegPngImageDecoding

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

DERIVED reconstruction of an image/JPEG/PNG decoding subsystem. The JPEG side is a stream decoder context (JpegStreamDecoder) that keeps a current marker byte at this+0x178, a callback-refilled byte-stream read-state at this+0x14, a 92-byte per-marker APP dispatch table at this+0x190, and a pointer to a state-dispatched object (StateDispatcher) reached through this+0x0. Seven functions implement marker reading (segment size, byte-stuffed bitstream tokens, SOI validation), the main marker dispatch loop, restart-marker handling, marker classification, and APP-table allocation/initialization. The PNG/row side is a second context (ImageDecodeContext) that parses PNG chunks (signature, chunk-type dispatch, IDAT termination, chunk-state validation), inflates and filters rows, runs pass-aware Huffman post-decoding and an optional callback. A separate FormatStateManager object carries a five-slot vtable, a stored format index plus eight stored format arguments, an access limit/counter pair, and a primary/alternate format-string table range; it is installed by sub_51177C. GuardedCallWithLongjmp is a shared setjmp/longjmp recovery trampoline reused by 15 callers. Owner identities of all these contexts are UNKNOWN at the C++ level; class boundaries here are DERIVED from overlapping offsets and shared callers, with uncertain objects kept in unresolved.

## Function roles

- `0x00511060` **JpegStreamDecoder** — Reads a 2-byte big-endian segment size from the stream, parameterized-dispatches state 90 via the dispatcher, and skips the remaining segment bytes; installed as APP-table slot 3 handler.
- `0x005110FC` **JpegStreamDecoder** — Shared bitstream marker reader: consumes bytes with 0xFF byte-stuffing (0xFF 0x00 escapes, consecutive 0xFF skipped) until a marker byte, accumulating a byte counter at this+0x1E8 and dispatching state 112 through the dispatcher.
- `0x005111D3` **JpegStreamDecoder** — Reads and validates the JPEG SOI marker (0xFF 0xD8); on mismatch dispatches error state 52 with the two unexpected bytes; stores the second byte as the current marker at this+0x178.
- `0x0051126A` **JpegStreamDecoder** — Main JPEG marker dispatch loop mapping the current marker at this+0x178 to decoder states (59/67/84/91 via dispatcher vfuncs) or to per-marker handlers (APP table at this+0x190, COM handler at this+0x19C); resets the marker slot after each dispatch.
- `0x00511457` **JpegStreamDecoder** — Matches the current marker against the expected restart marker ((this+0x190 value)+84 plus 208), dispatching state 97 with the counter value and incrementing the counter modulo 8; delegates mismatches to an alternative stream-object handler.
- `0x005114D5` **JpegStreamDecoder** — Marker classification loop relative to a reference counter: drives decoder states 117 (init) and 96 (per-iteration) through the dispatcher, classifying the marker into expected/skip/acceptable categories and re-reading via the bitstream marker reader on skip.
- `0x005115EE` **JpegStreamDecoder** — Allocates a 92-byte JPEG APP-marker dispatch table via the allocator vfunc at this+0x4, stores it at this+0x190, fills slots (StateReset, CommandDispatchStateMachine, restart-marker, segment-size reader, defaults, APP0/APP14 overrides), then calls StateReset; called from sub_50F632.
- `0x005116A3` **FormatStateManager** — FormatStateManager vfunc slot 1: resource access/release gated by the limit at obj+0x68 and the concurrent count at obj+0x6C, invoking the release callback at obj+0x8 on the indexed or unconditional path.
- `0x005116D4` **FormatStateManager** — FormatStateManager vfunc slot 3: selects a format string by index from the primary/alternate format tables, falls back to the first primary string, and forwards stored arguments to StringFormatWithBufferOverflowCheck (0x58815F) using varargs or va_list form based on a '%s' scan.
- `0x0051176B` **FormatStateManager** — FormatStateManager vfunc slot 4: partial state reset clearing the format index (obj+0x14) and the concurrent access counter (obj+0x6C) on the struct reached through the a1 handle.
- `0x0051177C` **FormatStateManager** — FormatStateManager installer/constructor: fills the five-slot vtable (ArithmeticComparison_166b, ReferenceCountedResourceAccessRelease, VtableDispatchThunk, FormatStringWithArgs, ResettableStateClear), sets the primary format table base (off_5ADE98) and count (119), and clears state slots; called by ImageTextureDecompressor (0x501722).
- `0x0051184F` **GuardedCallbackContext** — Sets three receiver fields from three parameters with remapping (a2 to this+0x48, a3 to this+0x40, a4 to this+0x44), returning the receiver pointer.
- `0x00511869` **GuardedCallbackContext** — Shared guarded callback dispatch trampoline: loads the callback at a1+0x40, invokes it with (a1,a2) when non-null, unwinds through LongjmpMSVCCRT (0x58A770), then dispatches to CallbackDispatch as the return value; reused by 15 callers across stream and buffer code.
- `0x0051189C` **GuardedCallbackContext** — Two-stage buffer/context init: calls sub_5117C8(a1,a2) then GuardedCallWithLongjmp(a1, v3) with a local 80-byte longjmp scratch buffer, propagating the guarded-call result.
- `0x005119E9` **ImageDecodeContext** — PNG chunk parser: validates the 8-byte signature (fetching missing bytes via CallbackDispatchWithNullGuard, comparing with BoundedMemcmpAgainstReference), iterates 4-byte chunk lengths/types dispatching IHDR/PLTE/IEND/gAMA/sRGB/tRNS/unknown to per-chunk handlers, terminates on IDAT, validates chunk-state flags (indexed color requires PLTE before IDAT), and records the IDAT size; longjmp error reporting for signature/PLTE/IHDR violations.
- `0x00511B7C` **ImageDecodeContext** — Image row decode: refills IDAT chunks, inflates rows via sub_517ADC, verifies stream completion, copies pixel-format bytes, computes row geometry, unpacks/filters the row, runs optional post-processing and pass-aware horizontal stretch plus a2/a3 Huffman decode passes, finalizes via sub_519019, and invokes an optional callback at this+0x16C; pass index (this+0x114) drives a 7-way switch.
- `0x0051234D` **ImageDecodeContext** — Selects 1 (single mode) or 7 (multi-session selector) from the byte flag at this+0x113, OR-setting bit 2 of the flags DWORD at this+0x60 for the multi path. Shares offsets 0x113/0x60 with the row-decode pass logic; ownership tentatively assigned to ImageDecodeContext.
- `0x0051249F` **CameraRotationState** — Stores two double camera-rotation parameters as floats (a3 to this+0x130, a2 to this+0x134) and raises bit 5 of the flags byte at this+0x61 when the product deviates from 1.0 by more than 0.05; called from sub_50210E.
- `0x005126D9` **PixelConversionParams** — Pixel bit-depth down-conversion (2/4/8/16 bpp) driven by a parameter block (count, buffer size, mode byte, input bit depth) and a per-channel shift lookup table; skips conversion when the mode byte is 3; called by sub_51389E.
- `0x00512E1A` **IndexedTextureDecodeState** — Two-phase bit-packed indexed texture decoder: phase 1 (guarded on this+0x8 == 3) unpacks 4/2/1-bit planar fields to one byte per pixel and sets this+0x9 = 8; phase 2 (guarded on this+0x9 == 8) looks bytes up in an RGB palette with optional alpha table, recording output format in this+0x8/0xA/0xB and byte count in this+0x4; called by sub_51389E.
- `0x00513BF9` **DataCallbackContext** — Configures a data-read callback: stores the user-data pointer (this+0x54) and read callback (this+0x50); if a write callback was already present at this+0x4C it is cleared and a conflict is reported through CallbackDispatch (0x511887); clears this+0x120 and returns the read callback.

## Proposed classes

### JpegStreamDecoder

JPEG/bitstream stream decoder context. Holds the current marker byte (this+0x178), the callback-refilled byte-stream read-state (this+0x14), the 92-byte per-marker APP dispatch table plus decoder config (this+0x190), the COM handler pointer (this+0x19C), and the state-dispatcher pointer (this+0x0). Marker reading, SOI validation, restart handling, marker dispatch and APP-table setup operate on this object. The concrete C++ type is unknown; ownership is DERIVED from overlapping offsets across the seven functions.

Methods: `0x00511060`, `0x005110FC`, `0x005111D3`, `0x0051126A`, `0x00511457`, `0x005114D5`, `0x005115EE`

- `this+0x00000000` `StateDispatcher* dispatcher_ptr` (read, DERIVED)
- `this+0x00000004` `void*(*)(void*,int,int) allocator_vfunc` (read, DERIVED)
- `this+0x00000014` `ByteStreamReadState* stream_read_state` (read, DERIVED)
- `this+0x00000178` `int current_marker` (read_write, DERIVED)
- `this+0x00000190` `JpegAppDispatchTable* app_dispatch_table` (read_write, DERIVED)
- `this+0x0000019C` `void(*)(void*) com_handler_ptr` (read, DERIVED)
- `this+0x000001E0` `char byte_stuffing_flag` (read, DERIVED)
- `this+0x000001E4` `int restart_marker_counter` (read_write, DERIVED)
- `this+0x000001E8` `int byte_counter` (read_write, DERIVED)

### StateDispatcher

State-dispatched call object reached through the decoder's this+0x0. Receives (state code, arg1, arg2) at obj+0x14/0x18/0x1C and dispatches through vfunc slot 0 (obj+0x0, error/state dispatch) or slot 1 (obj+0x4, parameterized dispatch). Observed state codes: 52, 59, 67, 84, 90, 91, 96, 97, 112, 117. Vfunc targets are caller-supplied and unresolved.

Methods: 

- `obj+0x00000000` `void(*)(void*) vfunc_error_dispatch` (read, DERIVED)
- `obj+0x00000004` `void(*)(void*,int) vfunc_parameterized_dispatch` (read, DERIVED)
- `obj+0x00000014` `int state_code` (write, DERIVED)
- `obj+0x00000018` `int state_arg1` (write, DERIVED)
- `obj+0x0000001C` `int state_arg2` (write, DERIVED)

### ByteStreamReadState

Callback-refilled byte stream read-state pointed to by the decoder's this+0x14. Packet prose: word 0 = current read pointer, word 1 = remaining byte count, word 3 = refill callback, plus 16 = skip callback. Only offset 0x0 has a formal field evidence ref in this packet; the remaining words are unresolved.

Methods: 

- `*(this+0x14)+0x00000000` `unsigned char* read_pointer` (read_write, DERIVED)

### JpegAppDispatchTable

92-byte per-marker dispatch table stored at this+0x190, allocated and filled by JpegAppDispatchTableInit. Slot 0 = StateReset, slot 1 = CommandDispatchStateMachine, slot 2 = restart-marker handler, slot 3 = segment-size reader, slots 4..18 default to StreamingDataReader with slot 4 (APP0) overridden to JPEGMarkerParsing and slot 18 (APP14) to AdobePSDHeaderParser. The table tail also holds decoder config: +0x50 byte-stuffing flag, +0x54 restart counter, +0x58 byte counter (accessed on the outer object as this+0x1E0/0x1E4/0x1E8).

Methods: 

- `*(this+0x190)+0x00000004` `void(*)(void*) slot1_command_dispatch` (read, DERIVED)
- `*(this+0x190)+0x00000008` `void(*)(void*) slot2_restart_marker` (read, DERIVED)
- `*(this+0x190)+0x0000000C` `void(*)(void*) slot3_segment_size_reader` (read, DERIVED)
- `*(this+0x190)+0x00000010` `void(*)(void*) slot4_app0_jfif_handler` (read, DERIVED)
- `*(this+0x190)+0x00000048` `void(*)(void*) slot18_app14_adobe_handler` (read, DERIVED)

### FormatStateManager

Format-string manager object installed by sub_51177C. Five-slot vtable (slots 0..4: ArithmeticComparison_166b, ReferenceCountedResourceAccessRelease, VtableDispatchThunk, FormatStringWithArgs, ResettableStateClear), a stored format index (obj+0x14), eight stored format arguments (obj+0x18..0x34), an access limit/counter pair (obj+0x68/0x6C) used by the resource access/release vfunc, and a primary/alternate format-table range (base obj+0x70, count obj+0x74, alternate start obj+0x78, alternate base obj+0x7C, alternate end obj+0x80). Reached through a pointer-to-pointer handle in 0x116A3/0x116D4/0x1176B (the struct is 'this' in the installer 0x1177C).

Methods: `0x005116A3`, `0x005116D4`, `0x0051176B`, `0x0051177C`

- `obj+0x00000000` `void(*)(void*) vtable_slot0` (read, DERIVED)
- `obj+0x00000004` `void(*)(void*) vtable_slot1` (read, DERIVED)
- `obj+0x00000008` `void(*)(void*) vtable_slot2` (read, DERIVED)
- `this+0x0000000C` `void(*)(void*) vtable_slot3` (read, DERIVED)
- `this+0x00000010` `void(*)(void*) vtable_slot4` (read, DERIVED)
- `obj+0x00000014` `int stored_format_index` (read_write, DERIVED)
- `obj+0x00000018` `int stored_arg0` (read_write, DERIVED)
- `obj+0x0000001C` `int stored_arg1` (read_write, DERIVED)
- `obj+0x00000020` `int stored_arg2` (read_write, DERIVED)
- `obj+0x00000024` `int stored_arg3` (read_write, DERIVED)
- `obj+0x00000028` `int stored_arg4` (read_write, DERIVED)
- `obj+0x0000002C` `int stored_arg5` (read_write, DERIVED)
- `obj+0x00000030` `int stored_arg6` (read_write, DERIVED)
- `obj+0x00000034` `int stored_arg7` (read_write, DERIVED)
- `obj+0x00000068` `int access_limit` (read, DERIVED)
- `obj+0x0000006C` `int concurrent_access_count` (read_write, DERIVED)
- `obj+0x00000070` `char** primary_format_table_base` (read_write, DERIVED)
- `obj+0x00000074` `int primary_format_table_count` (read_write, DERIVED)
- `obj+0x00000078` `int alternate_range_start` (read, DERIVED)
- `obj+0x0000007C` `char** alternate_table_base` (read, DERIVED)
- `obj+0x00000080` `int alternate_range_end` (read, DERIVED)

### GuardedCallbackContext

Context holding a guarded callback at this+0x40 invoked under setjmp/longjmp recovery (GuardedCallWithLongjmp) before delegation to a common dispatcher. TripleFieldSetter writes the 0x40/0x44/0x48 slot group; DoubleBufferInit runs a first init stage then the guarded call on the same a1. The trampoline is shared by 15 callers across stream/buffer code, so a single owner type is not established.

Methods: `0x0051184F`, `0x00511869`, `0x0051189C`

- `this+0x00000040` `void(*)(void*,void*) guarded_callback` (read_write, GUESS)
- `this+0x00000044` `int set_field_b` (write, GUESS)
- `this+0x00000048` `int set_field_c` (write, GUESS)

### ImageDecodeContext

Image/PNG decode context: PNG chunk parsing, IDAT-chunk row decompression, filtering and pass-aware post-processing. Flag words at this+0x58 (chunk-state flags: IHDR bit0, PLTE bit1, IDAT bit2), 0x5C and 0x60 gate chunk-state validation and decode passes; chunk length at 0xFC and chunk-type tag at 0x10C drive the chunk loop; row buffers/geometry live at 0x64..0x11C; optional post-decode callback at 0x16C. FlagBasedSessionModeSelector shares offsets 0x113/0x60 and is tentatively owned here (GUESS).

Methods: `0x005119E9`, `0x00511B7C`, `0x0051234D`

- `this+0x00000058` `int chunk_state_flags` (read_write, DERIVED)
- `this+0x0000005C` `int init_decompress_flags` (read_write, DERIVED)
- `this+0x00000060` `int feature_flags` (read_write, DERIVED)
- `this+0x00000064` `unsigned char* current_inflate_ptr` (read_write, DERIVED)
- `this+0x00000068` `int active_chunk_remaining` (read_write, DERIVED)
- `this+0x00000070` `unsigned char* output_row_ptr` (write, DERIVED)
- `this+0x00000074` `int rows_remaining` (read_write, DERIVED)
- `this+0x0000007C` `const char* error_message_ptr` (read, DERIVED)
- `this+0x0000009C` `unsigned char* chunk_data_base` (read, DERIVED)
- `this+0x000000A0` `int chunk_data_size` (read, DERIVED)
- `this+0x000000B8` `int pass_threshold` (read, DERIVED)
- `this+0x000000C8` `int bytes_per_row` (read, DERIVED)
- `this+0x000000CC` `int total_row_count` (read, DERIVED)
- `this+0x000000D0` `int samples_per_row` (read, DERIVED)
- `this+0x000000D4` `int pass_bitmask` (read, DERIVED)
- `this+0x000000D8` `int prev_row_size` (read, DERIVED)
- `this+0x000000DC` `unsigned char* row_buffer` (read, DERIVED)
- `this+0x000000F0` `int row_samples` (read_write, DERIVED)
- `this+0x000000F4` `int row_byte_size` (write, DERIVED)
- `this+0x000000F8` `unsigned char pixel_format_byte0` (write, DERIVED)
- `this+0x000000F9` `unsigned char pixel_format_byte1` (write, DERIVED)
- `this+0x000000FA` `unsigned char pixel_format_byte2` (write, DERIVED)
- `this+0x000000FB` `unsigned char pixel_format_byte3` (write, DERIVED)
- `this+0x000000FC` `int current_chunk_length` (read_write, DERIVED)
- `this+0x0000010C` `char[4] chunk_type_tag` (read_write, DERIVED)
- `this+0x00000113` `unsigned char pass_byte_flag` (read, DERIVED)
- `this+0x00000114` `int pass_index` (read, DERIVED)
- `this+0x00000116` `unsigned char color_type_byte` (read, DERIVED)
- `this+0x00000117` `unsigned char bpp_byte1` (read, DERIVED)
- `this+0x00000119` `unsigned char bytes_per_pixel` (read, DERIVED)
- `this+0x0000011A` `unsigned char bpp_byte2` (read, DERIVED)
- `this+0x0000011C` `int signature_bytes_consumed` (read_write, DERIVED)
- `this+0x0000016C` `void*(*)(void*,int,int) post_decode_callback` (read, DERIVED)

### CameraRotationState

Holds two float camera-rotation parameters (this+0x130/0x134) and a flags byte (this+0x61) whose bit 5 records a non-unit rotation-product deviation. Kept as a separate object from ImageDecodeContext despite sharing caller 0x50210E; the invariant meaning is unresolved.

Methods: `0x0051249F`

- `this+0x00000061` `unsigned char rotation_flags` (read_write, GUESS)
- `this+0x00000130` `float rotation_a` (write, GUESS)
- `this+0x00000134` `float rotation_b` (write, GUESS)

### PixelConversionParams

Parameter block for pixel bit-depth conversion (0x5126D9): *a1 element count, a1[1] buffer size, byte +8 mode byte (3 skips conversion; bit 1 planar vs interleaved; bit 2 extra fourth channel), byte +9 input bit depth. Destination buffer and per-channel shift table are passed separately.

Methods: `0x005126D9`

- `this+0x00000000` `int element_count` (read, GUESS)
- `this+0x00000004` `int buffer_size` (read, GUESS)
- `this+0x00000008` `unsigned char mode_byte` (read, GUESS)
- `this+0x00000009` `unsigned char input_bit_depth` (read, GUESS)

### IndexedTextureDecodeState

Two-phase bit-packed indexed texture decode state (0x512E1A): phase marker at +0x8 (3 selects the unpack phase; output format code 6=RGBA / 2=RGB after phase 2), bit depth/state byte at +0x9 (4/2/1 unpacked to 8), output bytes-per-pixel at +0xA (4/3), output stride at +0xB (32/24), pixel count / output byte count at +0x4. Palette stride (2 bytes per index) is inferred from address arithmetic.

Methods: `0x00512E1A`

- `this+0x00000000` `const void* pixel_source` (read, GUESS)
- `this+0x00000004` `int pixel_count` (read_write, GUESS)
- `this+0x00000008` `int format_code` (read_write, GUESS)
- `this+0x00000009` `unsigned char bit_depth_state` (read_write, GUESS)
- `this+0x0000000A` `unsigned char bytes_per_pixel` (write, GUESS)
- `this+0x0000000B` `int output_stride` (write, GUESS)

### DataCallbackContext

Structure with a read-data callback (this+0x50) plus user-data pointer (this+0x54) and an optional write callback (this+0x4C); read/write callback coexistence is rejected via CallbackDispatch. A state field at this+0x120 is cleared on configuration. Owner type unknown; callers are 0x50210E and 0x5118E6.

Methods: `0x00513BF9`

- `this+0x0000004C` `void(*)(void*) write_callback` (read_write, GUESS)
- `this+0x00000050` `void(*)(void*) read_callback` (write, GUESS)
- `this+0x00000054` `void* read_user_data` (write, GUESS)
- `this+0x00000120` `int state_field` (write, GUESS)

## Compatibility contracts

- **JpegMarkerStateCodes** — The dispatcher object carries (state code, arg1, arg2) at obj+0x14/0x18/0x1C and a two-slot vtable (obj+0x0 error/state dispatch, obj+0x4 parameterized dispatch). Observed state codes: 52 (SOI mismatch), 59/67 (error markers), 84 (marker 217), 90 (segment size read), 91 (markers 1/208..215), 97 (restart marker match), 112 (bitstream marker found), 117/96 (decode-loop init/per-iteration). A replacement must preserve this state-code protocol.
- **JpegMarkerByteStuffing** — The bitstream marker reader treats 0xFF 0x00 as one escaped data byte, skips consecutive 0xFF bytes, and terminates on 0xFF followed by a non-zero non-0xFF marker byte. The accumulated byte counter at this+0x1E8 increases by 1 per ordinary data byte and by 2 per escape. The byte-stuffing flag lives at this+0x1E0.
- **PngChunkStateValidation** — Chunk-state flags at this+0x58 track IHDR (bit 0), PLTE (bit 1) and IDAT (bit 2). Indexed color (color type 3 at this+0x116) requires PLTE before IDAT; violations are reported through the longjmp error path with the 'Missing PLTE before IDAT' (0x5AF318) / 'Missing IHDR before IDAT' (0x5AF334) strings. On success flag bit 2 is set and the IDAT length is stored at this+0xFC.
- **LongjmpErrorReporting** — Fatal signature/decode errors propagate through GuardedCallWithLongjmp (0x511869) with a saved setjmp/longjmp frame. Observed error strings: 'Not a PNG file' (0x5AF350), 'PNG file corrupted by ASCII conversion' (0x5AF378), 'Extra compressed data' (0x5AF388), 'Decompression error' (0x5AF3A0), 'Not enough image data' (0x5AF3B4), invalid-attempt (0x5AF3CC). A replacement must keep this recoverable error path.
- **PngChunkTagDispatch** — The 4-byte chunk-type tag at this+0x10C is dispatched by tag constant: IHDR (0x5AF264), PLTE (0x5AF27C), IEND (0x5AF274), gAMA (0x5AF284), sRGB (0x5AF28C), tRNS (0x5AF294) to per-chunk handlers; IDAT (0x5AF26C) terminates the chunk loop; unknown tags go to a generic handler. A replacement must reproduce this tag routing.
- **FormatTableSelection** — FormatStateManager selects a format string by index from a primary table (base obj+0x70, count obj+0x74) or an alternate range (start obj+0x78, base obj+0x7C, end obj+0x80); a null resolved pointer falls back to the first primary-table string, overriding the stored index argument. A '%s' sequence in the format selects the va_list call form; otherwise the varargs form is used, both reaching StringFormatWithBufferOverflowCheck (0x58815F).
- **StreamRefillCallbackContract** — The stream read-state at this+0x14 has word 0 = current read pointer and word 1 = remaining byte count (formal refs only for word 0); prose adds word 3 = refill callback and plus-16 = skip callback. A refill callback returning false aborts the read with return 0. The marker readers and segment-size reader depend on this contract.
- **ReadWriteCallbackExclusion** — A callback structure may hold either a read callback (this+0x50, with user-data at this+0x54) or a write callback (this+0x4C), not both. Setting a read-data callback while a write callback is present clears the write slot and reports the conflict through CallbackDispatch (0x511887) with the string fragments 0x5AF4EC and 0x5AF520; this+0x120 is cleared and the read callback is returned.
- **ImageDecodePassLookup** — The pass index (this+0x114) drives a 7-way switch of bitmask/threshold checks against this+0xD4 and this+0xB8 and selects per-pass Huffman decode via the lookup tables dword_5AF22C / dword_5AF248 with constants 15/51/85/255. Pass-aware post-decode runs TextureHorizontalStretch then two JPEGHuffmanDecoder passes. The pass semantics (Adam7 interlacing vs per-frame passes) are unresolved.

## Unresolved

- JpegStreamDecoder / StateDispatcher / ByteStreamReadState / ImageDecodeContext / FormatStateManager are UNKNOWN C++ types; class boundaries are DERIVED from overlapping offsets, and the concrete owners are not evidenced.
- Identity and semantics of the dispatcher obj+0x0 / obj+0x4 vfunc targets and of the stream-state skip callback (plus 16) are caller-supplied; the refill callback backing store is not defined in this packet.
- State-code semantics (52, 59, 67, 84, 90, 91, 96, 97, 112, 117) and the dispatch arguments (-1, 1, 3, 4) depend on the dispatcher contract, which is outside this packet's evidence.
- Marker 217 (state 84) returns 2 while other paths return through the loop or 0/1; the return-value contract (0/1/2) across callers is not established.
- The APP-table walk for markers 224..239 at (this+0x190 + 4*marker - 880) references entries not statically known; per-APP-handler behavior is unresolved. Slot 0 (StateReset) has no formal field ref in the packet.
- The reader-config object at this+0x190 doubles as dispatch base and byte-stuffing flag holder; whether it is a dedicated config struct or a shared context is unresolved.
- Restart-marker counter naming: the fill claims this+0x1E4, the raw source addresses (this+0x190 value)+84; reconcilable as the table tail (+0x54) but not independently confirmed.
- Marker-distance arithmetic in the 201..205 range leaves the 204-to-sub_510975 and 205-or-above-to-error routes overlapping; this suggests decompiler structure, not distinct semantic states.
- Decode-loop states 117/96 and the marker categories in 0x5114D5 are DERIVED from branch structure only; the category-2 'skip' reading is not independently confirmed.
- PNG per-chunk handler internals (0x517F58, 0x5188B4, 0x518AAA, 0x518BD4, 0x518C1E, 0x518D29, 0x518E18, 0x518FCF) are separate functions not analyzed in this packet.
- Whether the pass-index switch (0..6) implements Adam7 interlacing or per-frame Huffman passes is unresolved; the meanings of per-pass constants 15/51/85/255 and the dword_5AF22C/dword_5AF248 tables are unknown.
- Bit meanings of the ImageDecodeContext flag words (this+0x58 bits, this+0x60 bit 1, this+0x5C bits) are inferred from usage, not confirmed.
- The function pointer returned by DecodeRowData (stored at this+0x16C) and its relationship to the a2/a3 arguments is unresolved.
- FormatStateManager: obj+0x68 limit meaning (max index vs max concurrent holders), the obj+0x6C counter (increments but never decrements here), and the varargs vs va_list call-form distinction (inferred from the '%s' check only).
- GuardedCallWithLongjmp names CallbackDispatch but no callee evidence ref exists for it; the longjmp recovery context and the meaning of longjmp value 1 are unknown; the trampoline is shared by 15 callers so a single owner type is ambiguous.
- sub_51177C slot 29 holds the literal 119 (count vs pointer ambiguity); off_5ADE98 contents and whether cleared slots 0x14/0x68/0x6C/0x78/0x7C/0x80 are state fields or unused vtable padding are unresolved.
- TripleFieldSetter parameter-to-offset remapping (a2->0x48, a3->0x40, a4->0x44) has no semantic explanation; GuardedCallbackContext ownership is GUESS.
- StoreCameraRotationState: the meaning of the guarded 1.0-product invariant and what bit 5 of this+0x61 gates downstream is not established.
- ConvertPixelBitDepth: depth-4 shift binding is a union alias of v19[0] making channel binding ambiguous; the return value (EAX low byte) meaning and the a2 layout (planar vs interleaved) are unresolved.
- BitpackedIndexedToRgbaDecompressor: the class owning the phase/format state object is unknown; the palette 2-byte-per-index stride is inferred from address arithmetic.
- The 80-byte buffer passed by DoubleBufferInit to GuardedCallWithLongjmp is most plausibly longjmp state but its internal layout is not verifiable in this packet.
- SetReadDataCallback and its CallbackDispatch (0x511887) exact wording/dispatch semantics are not defined; the DataCallbackContext owner type is unknown.
- FlagBasedSessionModeSelector naming ('session mode') conflicts with its evidence (offsets 0x113/0x60 shared with row-decode pass logic); ownership by ImageDecodeContext is GUESS.
- Fields this+0x18, this+0x20, this+0x24, this+0x28 are listed as packet fields but never accessed by any analyzed raw body; their roles (cached buffer pointer, table entry count, limit) are speculative and unconfirmed.
