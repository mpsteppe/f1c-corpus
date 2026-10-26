# StreamDecoderRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Fourteen functions form one decoder host object (state at this+0x10, stream at this+0x14, dispatch target at *a1 via this+0x0, runtime function-slot objects at this+0x8/0x17C/0x180/0x18C/0x190) plus three reusable sub-objects: a dispatch target with a state-code/parameter window, a refillable byte stream, and a JPEG frame-header component table. The functions cover object initialization, state-machine dispatch, buffer/stream read processing, and the JPEG/command segment parsers (JFIF APP0, Adobe APP14, Huffman tables, byte-pair commands, slot-table commands, 2-byte tokens, generic JPEG markers). Ownership trust is LOW/UNKNOWN throughout; the class grouping is a DERIVED proposal grounded in shared field bases, shared caller sets, and shared numeric state codes.

## Function roles

- `0x0050F632` **JpegStreamDecoder** — Object initializer: clears status flag this+0x4, performs two conditional vtable dispatches (opcodes 10/19, expected values 61/424) through the dispatch target, memsets the 0x1A8-byte struct while preserving the vtable pointer, sets ready byte this+0xC, calls RenderVTableObjectInit (0x00516883), sub_5115EE (0x005115EE) and DirectorCameraObjectSetup (0x00515ECD), conditionally refreshes global byte_5D79DC via EFLAGSRegisterCheck (0x005159C3) when it equals 2, then sets state this+0x10 to 200 (the init state consumed by the state machine).
- `0x0050F6F7` **JpegStreamDecoder** — JPEG marker handler: dispatches on the marker selector this+0x20 for case 1 (SOI), 3 (SOF0), 4 (SOS) and invalid; validates component descriptors via the frame-header pointer this+0xC4 (single-component layout, or RGB triplet 82/71/66), drives sub-state this+0x24 and mode this+0x28, reports errors (codes 107/110) through the dispatch-target callback obj+0x4, and ends in a common tail that resets/re-initializes decoder counters and quant fields, returning 1.
- `0x0050F86A` **JpegStreamDecoder** — State-machine dispatch driver over the state variable this+0x10: state 200 (init) calls the function slots this+0x190 and this+0x14+8 then advances to 201; state 201 falls through to the shared processing function at this+0x18C; state 202 is terminal (returns 1); states 203..208/210 route directly through this+0x18C; any other state writes opcode 18 plus the state to the dispatch target (obj+0x14/0x18) and dispatches through obj+0x0, returning 0. On a successful processing call (result 1) it invokes handleJpegMarker (0x0050F6F7) and sets state 202.
- `0x0050F904` **JpegStreamDecoder** — State-machine dispatcher for states 205/206/207/210: on 205/206 with flag byte this+0x40 clear it conditionally posts opcode 66 to the dispatch target when the counter this+0x78 is below the limit this+0x60, calls the transition slot *(this+0x17C)+4 and moves to state 210; state 207 also moves to 210; other non-210 states post opcode 18 plus the state and dispatch through obj+0x0. A do-while loop polls the processing object *(this+0x18C); when its completion byte +0x11 is set it invokes the final-dispatch slot *(this+0x14)+0x18 and calls VirtualDispatchConditionalValue (0x00516937), returning 1.
- `0x0050FA0E` **JpegStreamDecoder** — Buffer-processing state machine: when state this+0x10 is not 204 it re-initializes via the init slot *(this+0x17C)+0, resets the counter this+0x78 and sets state 204; while the active flag *(this+0x17C)+0x8 is set it flushes batches at the limit this+0x60 (flush slot *(this+0x17C)+4 then re-init), calls the per-chunk progress callback at this+0x8 with counter/limit in slots +4/+8, and advances through the processing slot *(this+0x180)+4; unchanged counter aborts with 0; completion sets final state 205/206 selected by byte this+0x41.
- `0x0050FAB7` **JpegStreamDecoder** — Stream-buffer read dispatcher: initializes the dispatch target (opcode 18 + source state into obj+0x14/0x18, dispatch through obj+0x0) when state this+0x10 is not 205, primes the secondary callback object this+0x8 with the read position this+0x78 and buffer size this+0x60, advances the read position through the dispatch-object vtable slot 1 (this+0x180 plus 4) until the buffer is exhausted, then signals completion (opcode 119) through the completion handler obj+0x4 with (this, -1) and returns 0.
- `0x0050FB3B` **JpegStreamDecoder** — Multi-state processing state machine: state 202 constructs the object (ObjectConstructor_6f76, 0x00516F76) then either short-circuits to done 207 (early-exit flag this+0x40) or transitions to 203; state 203 runs a dispatch loop through the callback this+0x8 and the processing object *(this+0x18C), incrementing the callback counter *(this+0x8)+4 and extending its limit *(this+0x8)+8 by this+0x118; on result 2 it copies this+0x7C to this+0x84 and hands off to BufferProcessingStateMachine (0x0050FA0E); any other non-203/204 state writes opcode 18 plus the state through the dispatch target (obj+0x14/0x18, obj+0x0) before falling through to BufferProcessingStateMachine.
- `0x0050FF84` **JpegStreamDecoder** — Command-context reset: sets the dispatch-target state code obj+0x14 to 101 and dispatches (obj, 1); overrides to state 60 with a no-arg dispatch when the re-entry flag *(this+0x190)+0x50 is already set; initializes the three 16-byte field arrays near this+0xDA (values 1, 5, 0), resets context fields this+0x24, this+0xFC, bytes this+0x100/0x101/0x106/0x107/0x108 and words this+0x102/0x104, sets the re-entry guard flag *(this+0x190)+0x50 to 1, and returns 1.
- `0x0051030D` **JpegStreamDecoder** — Stream command parser with slot-table lookup: reads a variable-length command (2-byte size header, slot count, per-slot id/parameter pairs, trailer) from the refillable stream this+0x14, validates size against slot count (error state 9), linearly searches the 21-dword slot table at this+0xC4 for each slot id (table-size guard this+0x20, error state 5), stores found entries at this+0x124, publishes per-slot values (states 102/103) and the trailer (state 104) to the dispatch target, resets the completion flag this+0x1E4, increments the command counter this+0x7C and returns 1.
- `0x005105BF` **JpegStreamDecoder** — JFIF (APP0) marker parser: reads the big-endian segment length from the refillable stream this+0x14, consumes 14 header bytes, validates the 'JFIF\0' signature (else state 76), checks the major/minor version (states 88/115), stores density units at this+0x101 and X/Y densities at this+0x102/0x104, mirrors them to the dispatch target (obj+0x18..0x20), drives states 86/89/87 for densities and thumbnail data, then persists the stream position and skips any unconsumed bytes before returning 1.
- `0x005107FB` **JpegStreamDecoder** — Adobe (APP14) marker parser: reads the two-byte segment length from the refillable stream this+0x14, validates the 'Adobe' signature, decodes four big-endian values (DCT encoder version, two flag words, color transform) into the result object (obj+0x18..0x24), records the Adobe marker present at this+0x106 and color transform at this+0x107, sets state 75 (or 77 on short/mismatched segments), then persists the stream position and consumes leftover bytes before returning 1.
- `0x00510975` **JpegStreamDecoder** — Byte-pair command stream decoder: reads a big-endian length, iterates (length - 2)/2 ID/value pairs from the refillable stream this+0x14, reports each pair through the dispatch target (state 78 with parameterized dispatch obj+0x4, state 26 when ID >= 32, state 27 when the low nibble exceeds the high nibble), stores nibble-split values into the this+0xCA/0xDA arrays (and full bytes at this+0xDA+ID for IDs 16..31), persists the stream position and returns 1.
- `0x00510ACC` **JpegStreamDecoder** — JPEG Huffman table (DHT) parser: for each table in the segment reads the table-id byte, dispatches state 79 with (this, 1), reads 16 code-length count bytes (dispatched as state 85 batches through obj+0x18..0x34), validates the symbol count against 256 and the segment length (error state 28), reads the symbols, selects a table slot from the this+0x70/0xA0-area slot arrays (error state 29), lazily allocates the slot buffer via BufferAccessNullTerminate (0x00516990), writes the 17-byte header plus 256 symbols, then persists the stream position and returns 1.
- `0x00510F89` **JpegStreamDecoder** — 2-byte big-endian token parser: reads the size field and requires it to equal exactly 4 (on mismatch sets dispatch state 9 and invokes the obj+0x0 error path); on success sets state 81, stores the parsed value at obj+0x18 and this+0xFC, invokes the vtable entry at obj+0x4 with (this, 1), advances the stream read pointer, decrements the remaining count, and returns 1.

## Proposed classes

### JpegStreamDecoder

Host state-machine object for stream-based image/command decoding. Holds the decoder state at this+0x10, the refillable byte stream at this+0x14, the dispatch-target pointer at this+0x0, batch counters/limits (this+0x60/0x78/0x7C), the marker/component/JFIF/Adobe context region (this+0x100..0x108), the slot/frame table pointer this+0xC4, trailer and slot records (this+0x120..0x174), and runtime function-slot objects at this+0x8, this+0x17C, this+0x180, this+0x18C and this+0x190. All functions in this packet are assigned to this host as a DERIVED grouping; per-function ownership is UNKNOWN.

Methods: `0x0050F632`, `0x0050F6F7`, `0x0050F86A`, `0x0050F904`, `0x0050FA0E`, `0x0050FAB7`, `0x0050FB3B`, `0x0050FF84`, `0x0051030D`, `0x005105BF`, `0x005107FB`, `0x00510975`, `0x00510ACC`, `0x00510F89`

- `this+0x00000000` `void* dispatcher_target_ptr` (read, DERIVED)
- `this+0x00000004` `int32 status_flag` (write, DERIVED)
- `this+0x00000008` `void* progress_callback_ptr` (read, DERIVED)
- `this+0x0000000C` `uint8 ready_flag` (write, DERIVED)
- `this+0x00000010` `int32 state` (read_write, DERIVED)
- `this+0x00000014` `void* stream_state_ptr` (read_write, DERIVED)
- `this+0x00000018` `int32 stream_bytes_remaining` (read_write, GUESS)
- `this+0x0000001C` `int32 field_0x1C` (unknown, UNKNOWN)
- `this+0x00000020` `int32 stream_refill_or_table_size` (read, GUESS)
- `this+0x00000024` `int32 stream_skip_or_context_dword` (read_write, GUESS)
- `this+0x00000028` `int32 mode` (read_write, DERIVED)
- `this+0x0000002C` `int32 tail_init_0x2C` (write, DERIVED)
- `this+0x00000030` `int32 tail_init_0x30` (write, DERIVED)
- `this+0x00000038` `double tail_double_0x38` (write, DERIVED)
- `this+0x00000040` `uint8 flag_0x40` (read_write, DERIVED)
- `this+0x00000041` `uint8 flag_0x41` (read_write, DERIVED)
- `this+0x00000044` `int32 field_0x44` (write, DERIVED)
- `this+0x00000048` `uint8 tail_byte_0x48` (write, DERIVED)
- `this+0x00000049` `uint8 tail_byte_0x49` (write, DERIVED)
- `this+0x0000004A` `uint8 tail_byte_0x4A` (write, DERIVED)
- `this+0x0000004C` `int32 tail_0x4C` (write, DERIVED)
- `this+0x00000050` `uint8 tail_byte_0x50` (write, DERIVED)
- `this+0x00000054` `int32 tail_0x54` (write, DERIVED)
- `this+0x00000058` `uint8[3] tail_bytes_0x58` (write, DERIVED)
- `this+0x00000060` `int32 batch_limit` (read, DERIVED)
- `this+0x00000074` `int32 tail_0x74` (write, DERIVED)
- `this+0x00000078` `int32 counter` (read_write, DERIVED)
- `this+0x0000007C` `int32 command_counter` (read_write, DERIVED)
- `this+0x00000084` `int32 field_0x84` (write, DERIVED)
- `this+0x00000090` `int32[4] state_dword_0x90` (write, DERIVED)
- `this+0x000000C4` `void* slot_or_frame_table_ptr` (read, GUESS)
- `this+0x000000D8` `int32 field_0xD8` (unknown, UNKNOWN)
- `this+0x000000DA` `uint8[16] nibble_low_array` (read_write, DERIVED)
- `this+0x000000DC` `int32 field_0xDC` (unknown, UNKNOWN)
- `this+0x000000EA` `uint8[16] nibble_high_array` (read_write, DERIVED)
- `this+0x000000FC` `int32 field_0xFC` (read_write, DERIVED)
- `this+0x00000100` `uint8 marker_info_byte_0x100` (read_write, DERIVED)
- `this+0x00000101` `uint8 density_units_0x101` (read_write, DERIVED)
- `this+0x00000102` `uint16 x_density_0x102` (read_write, DERIVED)
- `this+0x00000104` `uint16 y_density_0x104` (read_write, DERIVED)
- `this+0x00000106` `uint8 component_info_0x106` (read_write, DERIVED)
- `this+0x00000107` `uint8 component_id_0x107` (read_write, DERIVED)
- `this+0x00000108` `uint8 field_0x108` (write, DERIVED)
- `this+0x00000118` `int32 limit_increment_0x118` (read, DERIVED)
- `this+0x00000120` `int32 slot_count_0x120` (write, DERIVED)
- `this+0x00000124` `void* slot_entry_ptr_0x124` (write, DERIVED)
- `this+0x00000168` `uint8 trailer_0x168` (write, DERIVED)
- `this+0x0000016C` `uint8 trailer_0x16C` (write, DERIVED)
- `this+0x00000170` `uint8 trailer_0x170` (write, DERIVED)
- `this+0x00000174` `uint8 trailer_0x174` (write, DERIVED)
- `this+0x0000017C` `void* transition_table_ptr` (read, DERIVED)
- `this+0x00000180` `void* data_dispatch_obj_ptr` (read, DERIVED)
- `this+0x00000184` `int32 field_0x184` (unknown, UNKNOWN)
- `this+0x0000018C` `void* processing_obj_ptr` (read, DERIVED)
- `this+0x00000190` `void* state_obj_ptr` (read, DERIVED)
- `this+0x000001E1` `uint8 guard_byte_0x1E1` (read, DERIVED)
- `this+0x000001E4` `uint8 completion_flag_0x1E4` (write, DERIVED)

### DecoderDispatchTarget

Dispatch target object reached through *a1 (host field this+0x0). Vtable slots 0..3 and a state-code/parameter message window: callers write a state/operation code to obj+0x14 and parameters to obj+0x18..0x34, then invoke slot 0 (no-arg dispatch) or slot 1 (parameterized dispatch with an extra argument). Slots 2 and 3 (obj+0x8/0xC) exist but are not visibly read or written in the packet bodies.

Methods: 

- `obj+0x00000000` `fnptr vtable_slot0` (read, DERIVED)
- `obj+0x00000004` `fnptr vtable_slot1` (read, DERIVED)
- `obj+0x00000008` `fnptr vtable_slot2` (unknown, GUESS)
- `obj+0x0000000C` `fnptr vtable_slot3` (unknown, GUESS)
- `obj+0x00000014` `int32 state_code` (read_write, DERIVED)
- `obj+0x00000018` `int32 param0` (read_write, DERIVED)
- `obj+0x0000001C` `int32 param1` (read_write, DERIVED)
- `obj+0x00000020` `int32 param2` (read_write, DERIVED)
- `obj+0x00000024` `int32 param3` (read_write, DERIVED)
- `obj+0x00000028` `int32 param4` (write, DERIVED)
- `obj+0x0000002C` `int32 param5` (write, DERIVED)
- `obj+0x00000030` `int32 param6` (write, DERIVED)
- `obj+0x00000034` `int32 param7` (write, DERIVED)

### RefillableByteStream

Byte-stream read state reached through host field this+0x14 (also exposed as embedded host fields this+0x18/+0x20/+0x24). Layout: stream+0x0 buffer read pointer, stream+0x4 bytes remaining, stream+0xC refill callback, stream+0x10 skip/consume callback. Parsers refill through the callback whenever the remaining count hits zero, then persist the advanced read pointer and remaining count back on completion.

Methods: 

- `*(this+0x14)+0x00000000` `uint8* read_ptr` (read_write, DERIVED)
- `*(this+0x14)+0x00000004` `int32 bytes_remaining` (read_write, DERIVED)
- `*(this+0x14)+0x0000000C` `fnptr refill_callback` (read, DERIVED)
- `this+0x00000024` `fnptr skip_callback` (read, GUESS)

### FrameHeaderComponentTable

JPEG frame-header object reached through host field this+0xC4 (used by the JPEG marker handler): three component descriptor fields at +0x0/+0x54/+0xA8 validated for a single-component layout or the RGB triplet 82/71/66.

Methods: 

- `*(this+0xC4)+0x00000000` `uint8 component_descriptor_0` (read, DERIVED)
- `*(this+0xC4)+0x00000054` `uint8 component_descriptor_1` (read, DERIVED)
- `*(this+0xC4)+0x000000A8` `uint8 component_descriptor_2` (read, DERIVED)

### TransitionFunctionTable

Runtime transition table reached through host field this+0x17C: init function (+0), flush/transition function (+4) and active flag (+8). Functions are assigned elsewhere at runtime.

Methods: 

- `*(this+0x17C)+0x00000000` `fnptr init_function` (read, DERIVED)
- `*(this+0x17C)+0x00000004` `fnptr flush_function` (read, DERIVED)
- `*(this+0x17C)+0x00000008` `uint8 active_flag` (read, DERIVED)

### DataDispatchObject

Runtime dispatch object reached through host field this+0x180 with a single visible function slot at +4 (the four-argument data-processing call). Function is assigned elsewhere at runtime.

Methods: 

- `*(this+0x180)+0x00000004` `fnptr process_function` (read, DERIVED)

### ProcessingFunctionObject

Runtime processing object reached through host field this+0x18C: processing function (+0), dispatch flag (+0x10) and completion byte (+0x11).

Methods: 

- `*(this+0x18C)+0x00000000` `fnptr process_function` (read, DERIVED)
- `*(this+0x18C)+0x00000010` `uint8 dispatch_flag` (read, DERIVED)
- `*(this+0x18C)+0x00000011` `uint8 completion_flag` (read, DERIVED)

### ReentryStateObject

Runtime state object reached through host field this+0x190 with a single visible flag at +0x50 (re-entry guard).

Methods: 

- `*(this+0x190)+0x00000050` `uint8 reentry_flag` (read_write, DERIVED)

### ProgressCallbackObject

Runtime progress callback object reached through host field this+0x8: vtable slot 0 (+0), a counter (+4) and a limit (+8). The counter/limit pair is incremented/extended by the state machines; callback semantics external.

Methods: 

- `*(this+0x8)+0x00000000` `fnptr vtable_slot0` (read, DERIVED)
- `*(this+0x8)+0x00000004` `int32 counter` (read_write, DERIVED)
- `*(this+0x8)+0x00000008` `int32 limit` (read_write, DERIVED)

## Compatibility contracts

- **DecoderStateVariableContract** — A replacement decoder must keep the current state as an int32 at host+0x10 and preserve the numeric state codes: 200 init, 201 process, 202 done, 203 dispatch loop, 204 buffer processing, 205/206 completion variants selected by byte host+0x41, 207 early exit, 210 post-transition terminal. Entry conditions and transitions are the observable contract of functions 0x0050F86A, 0x0050F904, 0x0050FA0E, 0x0050FAB7 and 0x0050FB3B.
- **DispatchTargetStateCodeProtocol** — A replacement must preserve the dispatch-target convention: state/operation code at obj+0x14, parameters at obj+0x18..0x34, vtable slot 0 (obj+0x0) for no-arg dispatch and slot 1 (obj+0x4) for parameterized dispatch. Error codes observed: 5, 9, 26, 27, 28, 29, 77, 107, 110; success/progress codes: 10, 18, 19, 60, 61, 66, 75, 76, 78, 79, 81, 85, 86, 87, 88, 89, 101, 102, 103, 104, 115, 119.
- **RefillableStreamContract** — Replacement parsers must read from a stream state with the buffer read pointer at stream+0x0, the bytes-remaining count at stream+0x4, the refill callback at stream+0xC and the skip/consume callback at stream+0x10, and must persist the advanced read pointer and remaining count back on completion (big-endian multi-byte reads).
- **JpegMarkerDispatchContract** — The decoder recognizes JPEG markers 1 (SOI), 3 (SOF0) and 4 (SOS) on the marker selector this+0x20, validates component descriptor layouts via the frame-header pointer this+0xC4 (single component or RGB triplet 82/71/66), drives sub-state this+0x24 / mode this+0x28, and reports component errors with codes 107 and 110 through the dispatch-target callback.
- **JfifAdobeMarkerContract** — Replacement JPEG segment parsers must handle JFIF APP0 segments (density flag at this+0x100, density units at this+0x101, X/Y density words at this+0x102/0x104; states 76/86/87/88/89/115) and Adobe APP14 segments (DCT encoder version, two flag words and color transform published at obj+0x18..0x24; Adobe presence at this+0x106 and color transform at this+0x107; states 75/77).

## Unresolved

- The object types behind a1/this and the obj dispatch target are UNKNOWN in every packet function; the JpegStreamDecoder grouping and the sub-object classes are DERIVED proposals, not proven identities.
- field:this:0x00000020 reads as a refill callback in the embedded-stream model (0x005105BF, 0x005107FB) but as a slot-table size guard in 0x0051030D; the two readings conflict and are unresolved.
- field:this:0x000000C4 reads as a JPEG frame-header pointer in 0x0050F6F7 and as a 21-dword slot-table base in 0x0051030D; unresolved whether one object is reused.
- field:this:0x00000024 reads as the stream skip/consume callback (stream+0x10) in 0x005107FB but is reset to 0 as a context DWORD by 0x0050FF84.
- 0x0050F632 performs render/camera setup (RenderVTableObjectInit 0x00516883, sub_5115EE 0x005115EE, DirectorCameraObjectSetup 0x00515ECD) and an EFLAGSRegisterCheck refresh of global byte_5D79DC; those calls are not explained by the stream-decoder role and may indicate a distinct render/bitmap object constructed during image decompression.
- Meaning of the vtable configuration protocol in 0x0050F632 (a2 != 61, a3 != 424, opcodes 10/19) is undocumented.
- The dispatch state codes (normal 10/18/19/60/61/66/75/76/78/79/81/85/86/87/88/89/101/102/103/104/115/119; errors 5/9/26/27/28/29/77/107/110) are DERIVED from control flow, not from any naming source.
- The composite state chart (200->201->202, 202->203/207, 203->204, 204->205/206, 205/206/207->210) is DERIVED by joining per-function transitions; a single coherent chart is not directly evidenced.
- The concrete functions behind the runtime slots at this+0x8, this+0x17C (+0/+4/+8), this+0x180 (+4), this+0x18C (+0/+0x10/+0x11) and this+0x190 (+0x50) are assigned elsewhere at runtime and are not evidenced here.
- The slot-table layout at this+0xC4 (21-dword stride, first-dword id key) and the meaning of entry dwords beyond 5/6 are empirical from the 0x0051030D body.
- The Huffman slot-table offsets derived from &this[28+...]/&this[40+...] in 0x00510ACC have no packet field references.
- obj+0x8 and obj+0xC (dispatch vtable slots 2/3), and this+0x1C, this+0x18, this+0xD8, this+0xDC, this+0x184 and the stream offset stream+0x18 are referenced statically but do not appear in the visible decompiled bodies; their roles are unknown.
- Semantics of the 0x0050F6F7 component-info bytes (this+0x100/0x106/0x107) and the marker meanings (1=SOI, 3=SOF0, 4=SOS) are DERIVED, not independently confirmed.
- The four-argument data-processing call (this, 0, &this+0x78, 0) and the thumbnail width/height byte mapping in 0x005105BF are DERIVED from usage.
- obj+0x0 (the error-code/result field of the callback object) is part of the vtable-call object but is not itself referenced in the visible source.
