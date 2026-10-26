# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `GUESS`

Derived architecture proposal for 26 validated functions in scope generic_runtime_objects, all with packet-UNKNOWN owners. The largest defensible cluster is a GUESS MpegStreamDecoder class: the constructor 0x0052E170 stores two interface pointers at +0x2D34/+0x2D38 and installs the RenderObject vtable off_5B4810; DecodeHeader 0x0052DC90 reads a 4-byte sync word through the I/O interface vtable read slot at +8 of the interface at +0x2D34 and processes it via CMpegBase_ProcessHeader (0x0052DA30); MpegBufferFill 0x0052E350 fills the caller output buffer from the internal +0x1244 buffer using frame-size/residual fields (+0x249C/+0x24E8) and reports 'mpeg fail' strings; DeferredDeactivation 0x0052E320 clears the +0x24EC/+0x24F0 pending flag pair; ProcessHeaderFailed 0x0052DE40 and the arithmetic helper 0x0052E080 are thin callers-side helpers shared with the open paths 0x0052E090/0x0052E1D0. A second GUESS cluster is a DEFLATE codec family: InflateDecompressStateMachine 0x00537110 is a zlib-inflate state machine (states 0-9, BFINAL flag at +0x18, bit accumulator at +0x20, error diagnostics at 0x005DA8xx), BitstreamEncoder 0x00537F30/0x00537FE0 implements the matching deflate-side bit writer (shift register +0x16AB, bit count +0x16AD, capacity +0x16A7), CompressionBuffer 0x00536160 copies between source/destination ring sub-buffers, and CodecStateManager 0x00537000/0x00537070/0x00537CE0 performs state-machine reset with callback re-registration and multi-block allocation. The remaining objects (ResourceContainer partial reset, DispatchTableObject, ResourceStateManager, StreamDecoder audio/texture modes, VirtualObjectCleanup, UiElement reset, BigEndianWriter) and four free helpers are kept separate because their field regions and callees do not overlap. No cross-class field merging is asserted: equal offsets on different bases (obj+0x0, this+0x0) are mirrored, not merged.

## Function roles

- `0x00511F70` **ResourceContainer** — Partial reset of a large container: pre-processes two caller pointers through ShortComputation_3d2f, releases six unconditional sub-resources (this+0x9C/0xD8/0xDC/0x138/0x174/0x178) and flag-guarded resources (this+0x104 gated on byte+0x5D bit 0x10, this+0x15C gated on bit 0x20) through release callbacks, releases a counted pointer array (base this+0x144, 1 << (8 - byte+0x12C) elements), runs sub_5179A2 on the sub-object at this+0x100, zeroes 0x19C bytes while preserving the first 0x40 bytes and dwords at +0x40/+0x44/+0x48, and returns the preserved dword at +0x48
- `0x00513D3D` **GenericRuntimeObjects** — Calloc-style allocation helper: early-exits returning 0 when a1 is 0, otherwise requests an allocation via AllocAndZeroInit(2) (0x00517E43) and zeroes the first 0x40 bytes of the non-null result with memset before returning it; single recorded caller sub_50210E
- `0x00516883` **DispatchTableObject** — Dispatch-table object initializer: clears the table pointer at this+0x4, calls StubReturning0 (0x0058FB7E) for the slot-11 entry, allocates an 80-byte table via MallocWrapper(a1, 80) (0x00519346), populates slots 0..10 with allocator/cache function pointers (0x00515F23..0x00516853), zeroes slots 13..17, records size 80 at slot 18; on allocation failure calls EmptyStub_7b96 (0x00587B96), writes error constant 53 to obj+0x14 and 0 to obj+0x18, and dispatches the error handler through the vtable at *a1
- `0x00517963` **ResourceStateManager** — Resource-state reset with early-out guards: returns -2 when this or the sub-object pointer at this+0x1C is null; otherwise clears this+0x8/+0x14/+0x18, writes the sub-object first dword to 7 or 0 depending on the condition field at this+0x28, calls sub_52765A with the data pointer at this+0x30, this, and 0, and returns 0; called by sub_5179E0 and sub_519019
- `0x0051A968` **StreamDecoder** — Audio decode-buffer reset: accumulates (decode state +20 at this+0x1A8)/8 into the output total at this+0x1E8 and clears the byte counter; invokes the output-buffer callback at *(this+0x190 + 8) with this; on truthy result and channel count this+0x120 > 0, zeroes the per-channel dword array at this+0x1B4 over this+0x120 entries, copies the reference this+0xFC into this+0x1C4, clears the ready byte at this+0x1AC and returns 1; otherwise returns the callback's falsy result
- `0x0051D166` **StreamDecoder** — Stream-decoder sub-struct init: allocates a 48-byte decoder object through vtable entry 0 of the allocator interface at this+0x4, records it at this+0x19C, seeds its first function pointer with PhysicsObjectStateSetter (0x0051CD3E), clears its +0x8 byte, and computes the streaming-buffer size as this+0x5C times this+0x64 into +0x28; when the mode flag at this+0x110 equals 2 installs the audio path (AudioSampleStream 0x0051CD53 at +0x4, sub_51CF80 0x0051CF80 at +0xC) and allocates the streaming buffer through vtable entry 1 of this+0x4; otherwise installs the texture/palette path (VirtualDispatchWrapper_cdf9 0x0051CDF9, TexturePaletteColorLookup 0x0051CE2A) and leaves the buffer null; finishes via WheelGeometryDataInitialization
- `0x0052803A` **GenericRuntimeObjects** — Thin __cdecl delegation wrapper: ignores its first argument a1 and forwards a2 and a3 to sub_58AB58, returning the callee's result unchanged
- `0x0052D990` **VirtualObjectCleanup** — Guard-based virtual cleanup helper: reads the stored object pointer at this+0x0 and returns 0 if null; otherwise dispatches the object's first vtable entry with argument 1 (virtual destructor/deleter), clears this+0x0 to 0 and returns 1; used as the cleanup stage by object creators 0x00405440, 0x00405630 and ThreadedObjectCreatorWithSEH (0x0052D8D0)
- `0x0052DC90` **MpegStreamDecoder** — DecodeHeader stage of an MPEG media player: when the header-read-needed flag at this+0x2D3C is set, reads a 4-byte sync word through the I/O interface read slot at vtable+8 of *(this+0x2D34), byte-swaps it, and hands it to CMpegBase_ProcessHeader (0x0052DA30); frame size below 4 or a short follow-up read into this+0x24A4 reports the corrupted-header string, clears this+0x24A8 and re-arms this+0x2D3C; failed reads report the waiting-for-CD string (0x005DA65C) and return -1
- `0x0052DE40` **MpegStreamDecoder** — Thin wrapper around CMpegBase_ProcessHeader (0x0052DA30) that returns TRUE (1) when the callee returned -1 (parse/error) and FALSE (0) otherwise; called from CMpegBase_Open (0x0052E090) and CMpegFilePlayer_Open (0x0052E1D0)
- `0x0052E080` **MpegStreamDecoder** — Pure integer arithmetic helper: computes (__int64)a1 * a2 / a3 with a 64-bit intermediate and returns the int-truncated quotient; placed in the MPEG playback path via callers CMpegBase_Open and CMpegFilePlayer_Open
- `0x0052E170` **MpegStreamDecoder** — Render-object constructor: initializes the GameObject base via ObjectVTableInitialization (0x0052D9F0), stores caller-supplied interface pointers at this+0x2D34 and this+0x2D38, then overrides the vtable pointer at this+0x0 with the RenderObject vtable off_5B4810 and returns this; reached from ThreadedObjectCreatorWithSEH (0x0052D8D0)
- `0x0052E320` **MpegStreamDecoder** — Conditional deferred-deactivation helper: when the pending-deactivation flag byte at this+0x24EC is non-zero, clears the 32-bit sync word at this+0x24F0 and the flag byte to 0, then calls Return0Stub (0x0047ABB0) and EmptyStub_0170 (0x004B0170); always returns 0; existing analysis ties it to MPEG decoder re-initialization (DERIVED prose)
- `0x0052E350` **MpegStreamDecoder** — Output-buffer fill for decoded MPEG data: loops while fewer than a3 bytes are produced, tracking the byte residual at this+0x24E8 against the frame size at this+0x249C; on equality decodes a fresh frame into the caller output buffer via sub_52DF10, otherwise decodes into the internal buffer at this+0x1244 and copies the available residual out; decode failures report 'mpeg fail 1/2' strings (0x005DA700/0x005DA6F0) via FileOpWithGlobalBuffer and zero the failed region; finishes by recomputing the byte position at this+0x24B4 from this+0x248C/this+0x24E4/this+0x24E8 and returns the produced byte count; invoked by GuardedFunctionCall (0x0052D970)
- `0x0052E4E0` **GenericRuntimeObjects** — printf-style debug output helper: formats the caller's arguments into a fixed 256-byte stack buffer via SafeStringFormat (0x0058AC95) and emits the result through OutputDebugStringA (0x0059E230); always returns 0
- `0x005357C0` **GenericRuntimeObjects** — Thin forwarding wrapper that re-orders arguments and fixes the callee's second parameter to the constant 15: invokes sub_5356A0 with (a1, 15, a2, a3) and returns the callee's result; called by sub_59B260
- `0x00535E10` **UiElement** — Conditional multi-field reset on the frame path: returns -2 when this, the sub-object pointer at this+0x1C, or the guard pointers at this+0x20/this+0x24 are null; otherwise zeroes this+0x8/+0x14/+0x18, sets this+0x2C to 2 and this+0x30 to 1, resets sub-object fields (v1[5]=0, v1[4]=v1[2], v1[6] clamped to >=0, v1[1] set to 113 or 42 by v1[6], byte at v1+30 cleared), then calls UIElementInitialization (0x00537E40) and sub_536260 on the sub-object; invoked by sub_535C10
- `0x00536130` **BigEndianWriter** — Big-endian short writer: writes the high byte then the low byte of a2 into the byte buffer stored at this+0x8 at a write offset stored at this+0x20, advancing the write offset by 2, and returns the advanced offset; called by sub_535E80
- `0x00536160` **CompressionBuffer** — Buffer copy with size tracking in the compression/decompression pipeline: copies min(source remaining, destination remaining) bytes from the source sub-object (this+0x1C, with total at +0x8, read pointer at +0x10, remaining at +0x14) into the destination write pointer at this+0xC, advancing both pointers, decrementing both remainders, accumulating the total at this+0x14, and reloading the source remaining from its total when it reaches zero
- `0x00536FD0` **GenericRuntimeObjects** — Thin __fastcall delegation wrapper: ignores its first argument a1 (ECX) and forwards a2 and a3 to sub_58AB58, returning the callee's result unchanged
- `0x00537000` **CodecStateManager** — State-machine lifecycle reset that zeroes state slots, restores a saved backup value, and optionally re-registers a callback: optionally writes a1[15] into *a3; when the state code *a1 is 4 or 5 invokes the function pointer at a2+36 with (*(a2+40), a1[3]); state 6 calls IndirectCallViaVTable0x24(a1[1], a2); resets state to 0, restores the backup a1[10] into a1[12]/a1[13] (this+0x30), zeroes a1[7]/a1[8]; if the stored callback a1[14] is non-null calls it with (0,0,0) and stores the result into a1[15] and a2+48, returning it; used by 0x00535620, sub_5357E0, MultiBlockAllocator and TripleVTableCall
- `0x00537070` **CodecStateManager** — Fastcall factory for a multi-block allocator: calls the allocation callback at a1+32 with context *(a1+40) to obtain the header object v6, allocates an 8 x 1440-byte block array stored at v6[9] and a single a3-byte payload block at v6[10] (end address at v6[11]), records a2 at v6[14], zeroes the header word *v6, and calls StateResetWithCallback(v6, a1, 0) to finish; on any failure rolls back through the deallocation callback at a1+36 and returns 0
- `0x00537110` **DeflateInflater** — Core DEFLATE (zlib inflate) decompression state machine driven per-frame by sub_5357E0: switch over states 0-9 (jump tables 0x00537C9C/0x00537CC4) covering stored blocks (LEN/NLEN), fixed and dynamic Huffman, decode-table construction (0x00539F70, 0x0053A4D0, ObjectAllocFieldInit 0x00539830), symbol decode against mask table 0x005DBB90, output via AudioRingBufferCopy (0x0053A660), with error statuses -2/-3/-4 and diagnostics at 0x005DA914/0x005DA8F4/0x005DA8D0/0x005DA8B4; block state at this+0x0, BFINAL at this+0x18, bit accumulator this+0x20, ring limit pointer this+0x28, stream read pointer at obj+0x0
- `0x00537CE0` **CodecStateManager** — Triple vtable dispatch after reset: calls StateResetWithCallback(a1, a2, 0), then invokes the same function pointer stored at a2+36 three times with the object at a2+40 and the arguments a1[10] (this+0x28), a1[9] (this+0x24), and a1 itself; always returns 0
- `0x00537F30` **BitstreamEncoder** — Bitstream accumulation write: ORs (a3 << bitCount) into the shift register at this+0x16AB and raises the bit count at this+0x16AD by 3; when bitCount exceeds 13, flushes the two-byte register to the output buffer (base this+0x8, offset this+0x14), advances the offset by 2, decrements bitCount by 13, and re-anchors the register to (uint16)a3 >> (16 - oldBitCount); always calls ChecksummedBufferWriter(a2, 1) (0x005397A0) and returns its result
- `0x00537FE0` **BitstreamEncoder** — End-of-block bitstream encode: ORs '2 << bitCount' into the shift register at this+0x16AB, accumulating or flushing a two-byte register to the output buffer (base this+0x8, offset this+0x14) by the 13-bit and 9-bit thresholds, re-anchoring the remaining bits; a capacity check on this+0x16A7 may force a second marker write and flush; completes by calling BitStreamWriter (0x00539690) and setting capacity this+0x16A7 to 7

## Proposed classes

### ResourceContainer

Large container whose partial reset (0x00511F70) releases six unconditional embedded sub-resources, two flag-guarded sub-resources (byte at +0x5D bits 0x10/0x20), and a counted pointer array (base +0x144, element count 1 << (8 - byte +0x12C)) through release callbacks, runs sub_5179A2 on the sub-object at +0x100, then zeroes 0x19C bytes while preserving the head (first 0x40 bytes plus dwords at +0x40/+0x44/+0x48).

Methods: `0x00511F70`

- `this+0x00000040` `int preservedDword_40` (read_write, DERIVED)
- `this+0x00000044` `int preservedDword_44` (read_write, DERIVED)
- `this+0x00000048` `int preservedReturnDword_48` (read_write, DERIVED)
- `this+0x0000005D` `byte releaseFlagByte_5D` (read, DERIVED)
- `this+0x0000009C` `pointer subResourcePtr_9C` (read, DERIVED)
- `this+0x000000D8` `pointer subResourcePtr_D8` (read, DERIVED)
- `this+0x000000DC` `pointer subResourcePtr_DC` (read, DERIVED)
- `this+0x00000138` `pointer subResourcePtr_138` (read, DERIVED)
- `this+0x00000174` `pointer subResourcePtr_174` (read, DERIVED)
- `this+0x00000178` `pointer subResourcePtr_178` (read, DERIVED)
- `this+0x00000104` `pointer guardedResourcePtr_104` (read, DERIVED)
- `this+0x0000015C` `pointer guardedResourcePtr_15C` (read, DERIVED)
- `this+0x00000144` `pointer countedArrayBase_144` (read, DERIVED)
- `this+0x0000012C` `byte arrayExponentByte_12C` (read, DERIVED)

### DispatchTableObject

Object holding a function dispatch table: initializer 0x00516883 clears the table pointer at +0x4, allocates an 80-byte table via MallocWrapper(a1, 80), fills slots 0..10 with allocator/cache function pointers (0x00515F23..0x00516853), stores the StubReturning0 result at slot 11, zeroes slots 13..17 and records size 80 at slot 18; on allocation failure it reports error code 53 (obj+0x14) through the vtable at *a1.

Methods: `0x00516883`

- `this+0x00000000` `pointer vtablePtr` (read, DERIVED)
- `this+0x00000004` `pointer tablePtr` (read_write, DERIVED)
- `obj+0x00000014` `int errorCode_14` (write, DERIVED)
- `obj+0x00000018` `int errorZero_18` (write, DERIVED)

### ResourceStateManager

Resource-state holder reset with early-out guards (0x00517963): returns -2 when this or the sub-object at this+0x1C is null, otherwise clears counters +0x8/+0x14/+0x18, writes the sub-object first dword to 7 or 0 by the condition field at +0x28, and delegates to sub_52765A with the data pointer at +0x30.

Methods: `0x00517963`

- `this+0x00000008` `int stateField_08` (write, DERIVED)
- `this+0x00000014` `int stateCounter_14` (write, DERIVED)
- `this+0x00000018` `int stateCounter_18` (write, DERIVED)
- `this+0x0000001C` `pointer subObjectPtr` (read, DERIVED)
- `this+0x00000028` `int conditionField_28` (read, DERIVED)
- `this+0x00000030` `pointer dataPtr_30` (read, DERIVED)

### StreamDecoder

Stream decoder with a per-mode payload path: 0x0051D166 allocates a 48-byte decoder sub-struct through the allocator interface at +0x4 and installs the audio-sample path (mode flag +0x110 == 2) or the texture/palette path; 0x0051A968 resets the decode-buffer state (accumulates pending bytes at +0x1A8 into the output total at +0x1E8, invokes the output-buffer callback, zeroes the per-channel array at +0x1B4, restores the reference at +0x1C4 from +0xFC). Grouping inferred from adjacent field regions and shared decode-state semantics; common ownership not proven.

Methods: `0x0051A968`, `0x0051D166`

- `this+0x00000004` `pointer allocatorInterface` (read, GUESS)
- `this+0x0000005C` `int bufferSizeTerm_5C` (read, GUESS)
- `this+0x00000064` `int bufferSizeTerm_64` (read, GUESS)
- `this+0x00000110` `int modeFlag_110` (read, GUESS)
- `this+0x0000019C` `pointer decoderSubStructPtr` (write, GUESS)
- `*(this+0x4)+0x00000000` `pointer vtableAllocEntry0` (read, GUESS)
- `*(this+0x4)+0x00000004` `pointer vtableBufferAllocEntry1` (read, GUESS)
- `this+0x000000FC` `int referenceValue_FC` (read, DERIVED)
- `this+0x00000120` `int channelCount` (read, DERIVED)
- `this+0x00000190` `pointer outputBufferPtr` (read, DERIVED)
- `this+0x00000194` `int outputBufferField_194` (read, DERIVED)
- `this+0x00000198` `unknown unusedField_198` (unknown, UNKNOWN)
- `this+0x000001A8` `int pendingByteCount` (read_write, DERIVED)
- `this+0x000001AC` `byte readyByte` (write, DERIVED)
- `this+0x000001B4` `array perChannelArray` (write, DERIVED)
- `this+0x000001C4` `int decodeStateField_1C4` (write, DERIVED)
- `this+0x000001E8` `int outputTotal` (read_write, DERIVED)

### VirtualObjectCleanup

Guard-based virtual cleanup/destructor helper (0x0052D990): returns 0 when the stored object pointer at this+0x0 is null, otherwise dispatches the object's first vtable entry with argument 1, clears this+0x0 and returns 1; used as the cleanup stage of object-creation paths 0x00405440, 0x00405630 and ThreadedObjectCreatorWithSEH (0x0052D8D0).

Methods: `0x0052D990`

- `this+0x00000000` `pointer objectSlot` (read_write, DERIVED)
- `obj+0x00000000` `pointer objectVtablePtr` (read, DERIVED)
- `*(obj+0x0)+0x00000000` `pointer vtableDispatchEntry` (read, DERIVED)

### MpegStreamDecoder

MPEG media-stream decoder/render object: constructor 0x0052E170 initializes the GameObject base via ObjectVTableInitialization, stores the I/O and secondary interface pointers at +0x2D34/+0x2D38 and installs the RenderObject vtable off_5B4810; 0x0052DC90 decodes the 4-byte sync-word header through the I/O read slot at vtable+8 of *(this+0x2D34) with CMpegBase_ProcessHeader and the header-read-needed flag at +0x2D3C; 0x0052DE40/0x0052E080 are thin helpers on the open path; 0x0052E320 clears the pending-deactivation flag pair at +0x24EC/+0x24F0; 0x0052E350 fills the caller output buffer from the internal +0x1244 buffer using frame-size/residual fields and the 'mpeg fail' diagnostics. Class ownership is GUESS, inferred from the shared +0x2D3x interface region and +0x24xx decode-buffer region.

Methods: `0x0052DC90`, `0x0052DE40`, `0x0052E080`, `0x0052E170`, `0x0052E320`, `0x0052E350`

- `this+0x00000000` `pointer vtablePtr` (write, GUESS)
- `this+0x00002D34` `pointer ioInterfacePtr` (read_write, GUESS)
- `this+0x00002D38` `pointer secondaryInterfacePtr` (write, GUESS)
- `this+0x00002D3C` `byte headerReadNeededFlag` (read_write, GUESS)
- `*(this+0x2D34)+0x00000000` `pointer ioVtablePtr` (read, GUESS)
- `*(*(this+0x2D34)+0x0)+0x00000008` `pointer ioReadFunc` (read, GUESS)
- `this+0x0000248C` `int bufferSize_248C` (read, GUESS)
- `this+0x00002498` `int processedFrameSize` (read, GUESS)
- `this+0x0000249C` `int frameSize` (read_write, GUESS)
- `this+0x000024A4` `byte_array rawHeaderBuffer` (write, GUESS)
- `this+0x000024A8` `int frameSizeField_24A8` (write, GUESS)
- `this+0x000024B4` `int bytePosition` (write, GUESS)
- `this+0x000024E4` `int frameCount` (read_write, GUESS)
- `this+0x000024E8` `int byteResidual` (read_write, GUESS)
- `this+0x000024EC` `byte pendingDeactivationFlag` (read_write, GUESS)
- `this+0x000024F0` `int syncWord` (write, GUESS)

### UiElement

UI-element-style object reset on the frame path (0x00535E10): validates this, the sub-object at this+0x1C and the guard pointers at +0x20/+0x24 (return -2 on any null), resets state fields +0x8/+0x14/+0x18, sets +0x2C to 2 and +0x30 to 1, resets sub-object fields (including the 113/42 selector keyed on +0x34 and the byte clear at +0x3A), then initializes the sub-object via UIElementInitialization and sub_536260. Name is DERIVED from the UIElementInitialization callee; owner is not proven.

Methods: `0x00535E10`

- `this+0x00000008` `int state_08` (write, DERIVED)
- `this+0x00000014` `int state_14` (write, DERIVED)
- `this+0x00000018` `int state_18` (write, DERIVED)
- `this+0x0000001C` `pointer subObjectPtr` (read, DERIVED)
- `this+0x00000020` `pointer guardPtr_20` (read, DERIVED)
- `this+0x00000024` `pointer guardPtr_24` (read, DERIVED)
- `this+0x0000002C` `int stateField_2C` (write, DERIVED)
- `this+0x00000030` `int flagField_30` (write, DERIVED)
- `this+0x00000034` `int selectField_34` (read, DERIVED)
- `this+0x0000003A` `byte subObjectByte_3A` (write, DERIVED)

### BigEndianWriter

Big-endian serialization helper (0x00536130): writes the two bytes of a value high-byte-first into the byte buffer stored at this+0x8 at a write offset stored at this+0x20, advancing that offset by 2 and returning it.

Methods: `0x00536130`

- `this+0x00000008` `pointer outputBufferPtr` (read, DERIVED)

### CompressionBuffer

Buffer pipeline object in the compression/decompression path (0x00536160): copies min(source remaining, destination remaining) bytes from the source sub-object at this+0x1C into the destination write pointer at this+0xC, advancing pointers, decrementing remainders and accumulating the copied total at +0x14; the source remaining reloads from its total when it reaches zero. Fields +0x24/+0x2C/+0x30/+0x38 are listed in the packet field facts but are not referenced by the raw body.

Methods: `0x00536160`

- `this+0x0000000C` `pointer destWritePtr` (read_write, DERIVED)
- `this+0x00000010` `int destRemaining` (read_write, DERIVED)
- `this+0x00000014` `int totalCopied` (read_write, DERIVED)
- `this+0x0000001C` `pointer sourceObjectPtr` (read, DERIVED)
- `this+0x00000024` `unknown field_24` (unknown, UNKNOWN)
- `this+0x0000002C` `unknown sourceReadPtrField_2C` (unknown, UNKNOWN)
- `this+0x00000030` `unknown sourceRemainingField_30` (unknown, UNKNOWN)
- `this+0x00000038` `unknown field_38` (unknown, UNKNOWN)

### CodecStateManager

Codec state/callback manager for the DEFLATE family: 0x00537000 resets the state machine (state code at +0x0, backup value at +0x28 restored to +0x30, slots +0x7/+0x8 zeroed) and re-registers the callback from a caller-owned slot layout (a2+36/+40/+48); 0x00537070 is a fastcall multi-block allocator factory that allocates an 8 x 1440-byte block array and a payload block through the allocator interface embedded in a1 and calls StateResetWithCallback(v6, a1, 0); 0x00537CE0 performs a triple dispatch through the same a2+36 slot after reset.

Methods: `0x00537000`, `0x00537070`, `0x00537CE0`

- `this+0x00000000` `int stateCode` (read_write, DERIVED)
- `this+0x00000024` `int stateField_24` (read, DERIVED)
- `this+0x00000028` `int backupValue_28` (read, DERIVED)
- `this+0x00000030` `int restoredBackup_30` (write, DERIVED)

### DeflateInflater

DEFLATE (zlib inflate) decompression state machine (0x00537110) driven per-frame by sub_5357E0: switch over states 0-9 handling stored blocks, fixed/dynamic Huffman, decode-table construction and symbol decoding, with output via AudioRingBufferCopy and -2/-3/-4 error statuses carrying diagnostic strings. Block state at +0x0, BFINAL flag at +0x18, bit accumulator at +0x20, table parameter at +0x24, ring-buffer limit pointer at +0x28, stream read pointer at obj+0x0.

Methods: `0x00537110`

- `this+0x00000000` `int blockState` (read_write, DERIVED)
- `this+0x00000004` `int lengthCountWord` (read_write, DERIVED)
- `this+0x00000008` `int codeLengthBuildCounter` (read_write, DERIVED)
- `this+0x00000018` `int bfinalFlag` (read_write, DERIVED)
- `this+0x00000020` `int bitAccumulator` (read_write, DERIVED)
- `this+0x00000024` `int tableParam_24` (read, DERIVED)
- `this+0x00000028` `pointer ringBufferLimitPtr` (read, DERIVED)
- `obj+0x00000000` `pointer inputReadPointer` (read, DERIVED)

### BitstreamEncoder

DEFLATE-side bitstream encoder: 0x00537F30 accumulates three bits per call into the shift register at +0x16AB with bit count at +0x16AD and flushes a two-byte register to the output buffer (base +0x8, offset +0x14) past a 13-bit threshold; 0x00537FE0 appends an end-of-block marker and enforces a capacity check at +0x16A7. Both report through the checksummed buffer writer (0x005397A0) / bitstream writer (0x00539690).

Methods: `0x00537F30`, `0x00537FE0`

- `this+0x00000008` `pointer outputBufferBase` (read, DERIVED)
- `this+0x00000014` `int outputBufferOffset` (read_write, DERIVED)
- `this+0x000016A7` `int capacity` (read_write, DERIVED)
- `this+0x000016AB` `int shiftRegister` (read_write, DERIVED)
- `this+0x000016AC` `byte shiftRegisterHighByte` (read_write, DERIVED)
- `this+0x000016AD` `byte bitCount` (read_write, DERIVED)

## Compatibility contracts

- **MpegHeaderDecodeFlow** — DecodeHeader (0x0052DC90) must read a 4-byte big-endian sync word through the I/O read slot at vtable+8 of *(this+0x2D34), pass the byte-swapped value to CMpegBase_ProcessHeader (0x0052DA30), treat processed frame sizes below 4 as corrupted, and re-arm the header-read flag at this+0x2D3C while clearing the frame-size field at this+0x24A8 on corruption recovery. A replacement executable must preserve this header/flag protocol and the waiting-for-CD / corrupted-header diagnostics.
- **MpegIoInterfaceLayout** — The render object stores its I/O interface at this+0x2D34 and a secondary interface at this+0x2D38 (constructor 0x0052E170); the I/O interface's vtable must expose a 4-byte/byte-count read function at slot +8 relative to the vtable pointer. A replacement must preserve both slot locations and the +8 read slot.
- **StreamDecoderAllocatorVtable** — The stream decoder (0x0051D166) reaches its allocator through the interface stored at this+0x4 and calls vtable entry 0 with (this, 1, 48) to allocate the decoder sub-struct and entry 1 to allocate the streaming buffer of size this+0x5C * this+0x64; mode flag this+0x110 == 2 selects the audio path. A replacement must keep the allocator interface at +0x4, the two vtable entry slots, and the mode value 2.
- **DeflateBlockContract** — The DEFLATE family must preserve the inflate block format (stored LEN/NLEN, fixed and dynamic Huffman, code-length ordering table 0x005B7C60, mask table 0x005DBB90) with the BFINAL flag at this+0x18 driving the final block path, and the matching deflate bit writer must accumulate 3 bits per symbol call and flush a two-byte register past the 13-bit threshold (shift register this+0x16AB, bit count this+0x16AD, capacity this+0x16A7).
- **LargeStructPartialResetPreservation** — The partial reset (0x00511F70) zeroes 0x19C bytes of the container while preserving the first 0x40 bytes and the dwords at +0x40/+0x44/+0x48, and releases six unconditional sub-resources plus two flag-gated resources (release flag byte at +0x5D, bits 0x10 and 0x20) and a counted pointer array (base +0x144, count 1 << (8 - byte +0x12C)). A replacement must preserve the preservation mask and the release gating.
- **CodecStateCallbackContract** — StateResetWithCallback (0x00537000) dispatches state codes 4/5 through the caller's function pointer at a2+36 with (*(a2+40), a1[3]) and state 6 through vtable+0x24, then resets the state code to 0, restores the backup at this+0x28 into this+0x30, and re-registers the stored callback at a1[14] with (0,0,0) storing its result at a1[15] and a2+48. The a2+36/+40/+48 slot layout is a caller-owned contract a replacement must preserve.

## Unresolved

- All 26 packet owners are UnknownObject/UNKNOWN; every class here is a GUESS grouping. MpegStreamDecoder (0x0052Dxxx-0x0052E3xx) is inferred from the shared +0x2D3x interface region and +0x24xx decode-buffer region plus the constructor's vtable override; StreamDecoder (0x0051A968 + 0x0051D166) is inferred from adjacent field regions; neither common ownership is proven by a single function.
- Equal offsets on different bases are mirrored, not merged (rule: a field is identified by base + offset): obj+0x0 is the inflate stream read pointer in DeflateInflater and the stored-object vtable in VirtualObjectCleanup; this+0x0 is the vtable in DispatchTableObject/MpegStreamDecoder, the state code in CodecStateManager/DeflateInflater, and the object slot in VirtualObjectCleanup.
- Packet field this+0x24 in StateResetWithCallback (0x00537000) is recorded as read but is not visible in the raw decompiled body; its purpose is unknown. It is also the a1[9] argument passed by TripleVTableCall (0x00537CE0).
- Field this+0x198 in AudioBufferReset (0x0051A968) is read per the packet field table but absent from the raw source body; its role is unresolved.
- Fields this+0x24/+0x2C/+0x30/+0x38 in BufferCopyWithSizeTracking (0x00536160) are listed in the deterministic field facts but are not referenced by the raw body; the packet notes the existing-analysis names source read pointer / remaining size but cannot resolve them against the sub-object at this+0x1C.
- ResourceResetWithCounter (0x00517963) has an ambiguous guard offset: the packet guard entry records this+0x28 but the raw null-check operates on the sub-object pointer at this+0x1C; this+0x28 reads as the 7/0 selection condition instead. The guard's recorded offset is uncertain.
- InflateDecompressStateMachine (0x00537110) shows a conflict between existing-analysis field purposes (this+0x8 'bit accumulator', this+0x18 'bit count', this+0x20 'allocation size') and raw-source usage (this+0x8 code-length build counter, this+0x18 BFINAL flag, this+0x20 bit accumulator); raw-source usage was preferred.
- The 0x00537070 allocator interface slots a1+32 (alloc), a1+36 (free) and a1+40 (context) are DERIVED from the indirect-call pattern and are not backed by a packet field list; the a2+36/+40/+48 slot layout in 0x00537000/0x00537CE0 is a caller-owned structure.
- The decoder sub-struct offsets (v1) in 0x0051D166 are not packet fields; their layout is only partially visible. The audio vs texture/palette distinction is inferred from the mode guard at this+0x110, not independently documented.
- The write-offset field at +0x20 of the BigEndianWriter object (0x00536130) is not a packet field (only buffer pointer +0x8 is evidenced); the +0x20 offset is mentioned in prose only.
- The vtable off_5B4810 layout and size are not in the packet; the 80-byte dispatch table's slot 12 is never written in 0x00516883 and is left as allocated.
- MpegBufferFill's ABI owner tag MPEG_Buffer is LEGACY trust and is not a CONFIRMED owner; the MPEG context of DeferredDeactivation (0x0052E320) is DERIVED prose.
- The constants 113/42 in 0x00535E10 and the 7/0 counter value in 0x00517963 have no documented meaning; the 0x0051A968 division by 8 does not establish byte-per-sample vs a fixed block size.
- Delegation wrappers (0x0052803A, 0x00536FD0) ignore their first argument a1; its purpose is unknown. ArgumentReorderWrapper (0x005357C0) injects the constant 15 into sub_5356A0 whose meaning (channel/mode/flag) is unevidenced.
- The destructive-head risk applies to the counted array release in 0x00511F70 (count 1 << (8 - byte +0x12C)) only in the sense that the exact array element stride and object lifetimes behind the release callbacks are not evidenced.
- The jump tables 0x00537C9C/0x00537CC4 and the code-length order table 0x005B7C60 are structural evidence; the code-length repeat semantics in state 5 of 0x00537110 are read from raw source, not cross-confirmed.
