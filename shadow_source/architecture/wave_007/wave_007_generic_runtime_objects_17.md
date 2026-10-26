# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Reconstruction of generic runtime objects from 27 validated function IR records. The packet supplies one DERIVED owner (HuffmanDecodeContext for 0x0051AEC2) and labels everything else UNKNOWN. Five PNG-decoder functions (0x00517FD0, 0x00517F58, 0x00517F72, 0x00518BD4, 0x00518FCF) are grouped as one DERIVED-proposed PngDecoderObject: 0x00518FCF reads/writes the flag register at this+0x58 and the control byte at this+0x10C, 0x00518BD4 shares this+0x58, and 0x00517F58/0x00517F72 share this+0x10C with the CRC accumulator at this+0x100 and the flags at this+0x5C/+0x5D. The three row-blit/expand functions (0x0051C099, 0x0051C176, 0x0051C1CD) share this+0x5C (row pitch) and this+0x110 (row count) and are grouped as TrackMapRowBlitter. The two windowed buffer writers (0x00516531, 0x0051664F) access an identical buffer-manager layout at a2 (+0/+4/+8/+12/+16/+24/+28/+32/+33/+34) and dispatch errors through the same error object (a1) at obj+0x14/obj+0x0, so they are grouped as one WriteWindowBufferObject. The two buffer alloc/null-terminate twins (0x00516974, 0x00516990) are grouped as VTableAllocAdapter; the state-machine priority helper 0x00516937 is kept as a separate PriorityDispatchAdapter because it calls vtable slot 0x24 rather than slot 0. HuffmanTreeAlloc (0x0051BA70) is grouped into HuffmanDecodeContext because it stores its sub-context at the same this+0x194 through the same sub-allocator at this+0x4 as 0x0051AEC2. Six stateless helpers (0x00517534, 0x00517EE1, 0x00517F04, 0x00519351, 0x0051935C, 0x0051923D) are split into StatelessHelperFunctions and CRC32TableComputation. State machines are proposed for the PNG flag-register chunk progression, the PNG chunk-type validation gate, and the buffer reprocess/zero-fill window. All owners other than the packet-supplied HuffmanDecodeContext are GUESS proposals; worker agreement cannot establish runtime truth.

## Function roles

- `0x0051623E` **LinkedListNodeAllocatorObject** — Sister to LinkedListNodeAllocAndInsert (005161DD): allocates a 0x78-byte node via MemoryAllocator (0x00515F23), populates it with a4/a5/a6 and the type byte a3, and prepends it to the singly-linked list anchored at this+0x48 (written through the allocator state base this+0x4 + 68). When the category a2 != 1 it first writes constants to the sub-object at obj+0x14/+0x18 and dispatches through the sub-object vtable at obj+0x0 before allocating. Returns the new node pointer.
- `0x00516531` **WriteWindowBufferObject** — Ring-buffer write: validates a [a3, a3+a4) range against capacity (a2+4), max write size (a2+12) and buffer non-null (a2+0); on out-of-window requests repositions the write position (a2+24), dispatches stale regions via sub_51641E (0x0051641E), optionally zero-fills via MemoryZeroFill (0x005159A8), and returns a pointer into the buffer array. Errors 20/68 dispatched through the error object at obj+0x14/obj+0x0.
- `0x0051664F` **WriteWindowBufferObject** — Offset-validated write: sibling of ringBufferWrite running capacity (a2+4), window (a2+24 vs a2+16) and written-bound (a2+28) checks, repositioning via sub_5164A6 (0x005164A6) and zero-filling via MemoryZeroFill (0x005159A8) with the zero-fill flag at a2+32; returns the write pointer. Errors 20/68 dispatched through the error object at obj+0x14/obj+0x0.
- `0x00516937` **PriorityDispatchAdapter** — State-machine priority dispatch helper: calls the virtual method at slot 0x24 of the dispatch object at this+0x4 with (a1, 1), then selects 200 or 100 from the byte flag at this+0xC, stores it at this+0x10 and returns it. Called by StateMachineDispatcher (0x0050F904) and StateMachineDispatch_f9ab (0x0050F9AB).
- `0x00516974` **VTableAllocAdapter** — VTable buffer allocation with null terminator: calls vtable slot 0 of the allocator object at this+0x4 with (this, 0, 130), writes a zero byte at result+128, returns the buffer. Called by MP3HuffmanDecoder (0x00510D60).
- `0x00516990` **VTableAllocAdapter** — Structural twin of VTableAllocNullTerminate: allocates 274 bytes through vtable slot 0 of the allocator at this+0x4 with (this, 0, 274), writes a zero byte at result+273, returns the buffer. Called by sub_510ACC (0x00510ACC).
- `0x00517534` **StatelessHelperFunctions** — 2-element row-vector by 2-column matrix product: out[0] = a2[0]*a3[0] + a2[1]*a3[4], out[1] = a2[0]*a3[1] + a2[1]*a3[5]; returns the output pointer a1. The right operand a3 is read with a 4-float row stride; a3 is left unmodified. Stateless math helper with no evidenced owner object.
- `0x00517EE1` **StatelessHelperFunctions** — Minimal memory copy wrapper: qmemcpy(a2, a3, a4) and returns the destination a2; the first parameter a1 is unused (reserved/stale ABI argument). Single caller sub_511B7C (0x00511B7C).
- `0x00517F04` **StatelessHelperFunctions** — Replicated-byte buffer fill: builds a 4-byte repeating pattern from the fill byte a4, fills the dword-aligned bulk via memset32, then covers the a5 & 3 residual bytes with a scalar memset; returns the destination a3. a2 is unused.
- `0x00517F58` **PngDecoderObject** — CRC-update dispatch: forwards (a1, a2, a3) through CallbackDispatchWithNullGuard (0x00513BD1), then conditionally seeds the CRC32 accumulator at this+0x100 from the data block (a2, a3). The update is skipped when the control byte this+0x10C bit 5 is clear and this+0x5D bit 3 is set, or when bit 5 is set and (this+0x5C & 0x300) == 0x300. Returns this.
- `0x00517F72` **PngDecoderObject** — Animation/state-change check: evaluates flag bytes to decide whether a stored-state comparison runs, always dispatches CallbackDispatchWithNullGuard (0x00513BD1), and returns v2 AND (ByteArrayToInt of the argument-slot bytes != this+0x100). The gate v2 clears only when (this+0x10C bit 0x20 set AND this+0x5C has mask 0x300) OR (bit clear AND this+0x5D has bit 0x8).
- `0x00517FD0` **PngDecoderObject** — Chunk-type header validation: validates four bytes at a2, each must satisfy 0x29 <= v <= 0x7A and not fall in the gap 0x5A < v < 0x61; on the first invalid byte calls DoubleBufferInit(a1, 'invalid chunk type') (0x0051189C, string global 0x005AFB18) and returns its result; returns a2[3] when all four bytes pass.
- `0x00518032` **PngBitStreamUnpacker** — Bit-stream pixel unpacker: unpacks pixel data from *(this+0xDC)+1 into the output a2; when a3 equals 255 the packed block is bulk-copied, otherwise it switches on the bits-per-pixel byte this+0xFB (cases 1, 2, 4, default 8+) and bit-unpacks pixels using a3 as a stencil mask. Pixel count read at this+0xB8.
- `0x00518248` **TextureStretchInfo** — Texture row horizontal stretch: replicates each source pixel by the stride-table factor dword_5AFABC[a3] into the output row a2, switching on bits-per-pixel this+0xB (1/2/4-bit bit-packed paths, >= 8 byte path); updates this+0x0 to the stretched width and this+0x4 to the output byte count ((width*bpp+7)>>3). Returns void.
- `0x00518511` **PngAdaptiveFilterStage** — Row-wise adaptive-filter dispatcher: applies one of four predictor modes (1 extend leading block, 2 add predictor, 3 average, 4 three-sample minimizer) selected by a5 to byte row a3 using predictor row a4 and row descriptor a2 (+4 byte count, +11 bit depth); unrecognized modes report 'Ignoring bad adaptive filter type' via CallbackDispatch (0x00511887, string global 0x005AFB2C) and zero the first output byte. Invoked by sub_511B7C.
- `0x00518BD4` **PngDecoderObject** — PNG IEND chunk handler: reads the image-state flag register at this+0x58; when bit 0 (0x1) and bit 2 (0x4) are set it sets the done bits 0x18, warns through CallbackDispatch (0x00511887) with 'Incorrect IEND chunk length' (global 0x005AFD00) when the chunk length a3 is non-zero, and runs the CRC check sub_518828 (0x00518828) before returning its result; when either flag is clear it calls GuardedCallWithLongjmp (0x00511869) with 'No image in file' (global 0x005AFD1C).
- `0x00518FCF` **PngDecoderObject** — Unknown critical PNG chunk handler: evaluates the chunk against the control byte at this+0x10C via sub_517FD0 (0x00517FD0); when bit 5 (0x20) of that byte is clear it calls DoubleBufferInit (0x0051189C) with 'unknown critical chunk' (global 0x005AFF58), then conditionally sets the done bit 0x8 on the flag register at this+0x58 (only when bit 0x4 is set) and runs the CRC check sub_518828 (0x00518828) before returning.
- `0x0051923D` **CRC32TableComputation** — CRC32 computation over a byte buffer using the 256-entry table at dword_5AFFA0 (global 0x005AFFA0), with an unrolled 8-byte fast path and a byte tail loop. The seed is complemented on entry and the running CRC complemented on return, enabling chained computation. Invoked by AnimationHandleAlloc (0x00513CD8) and 0x00517F58.
- `0x00519351` **StatelessHelperFunctions** — cdecl free forward wrapper: ignores the first argument a1 and forwards lpMem unchanged to sub_58AA6F (0x0058AA6F), returning its result. Called by sub_516772 (0x00516772) and TwoIterationCleanup (0x00516853); deallocation semantics inferred only from the canonical/ABI 'Free' labels.
- `0x0051935C` **StatelessHelperFunctions** — Trivial passthrough: returns its third argument a3 unchanged; a1 and a2 are accepted but never read. Single caller DirectXTextureSurfaceAllocation (0x0051629F).
- `0x00519361` **SurfaceMemoryDelegate** — Surface memory allocation delegate: unconditionally writes the literal 48 into the DWORD at obj+0x14, then dispatches through the object vtable at obj+0x0 (first slot) calling the allocation function with this = a1 and returns its result. Invoked from DirectXTextureSurfaceAllocation (0x0051629F).
- `0x0051A87E` **HuffmanBitstreamSymbolDecoder** — Huffman symbol decoder: extracts an a5-bit code word from the bit accumulator (this+0xC) and remaining-bit count (this+0x18), refilling via sub_51A794 (0x0051A794) when needed; walks the Huffman tree one bit at a time until a table entry is reached, persisting state back to this+0xC/this+0x18. On decode failure writes 114 into vtable slot +0x14 of the parent context (*(*(this+0x1C)+0x0)+0x14) and dispatches the parent vtable slot +0x4 error handler with (parent_context, -1); refill failure returns -1. Called by TextureDecompression (0x0051A9C6), BitstreamDecoder (0x0051AF57), sub_51B154 (0x0051B154) and sub_51B45F (0x0051B45F).
- `0x0051AEC2` **HuffmanDecodeContext** — Huffman decode-context allocator: allocates an 88-byte context through the sub-allocator vtable at *(this+0x4) with (this, 1, 88), stores it at this+0x194, installs vtable methods ArrayProcessingWithValidation (0x0051AD93) and TextureDecompression (0x0051A9C6), zeroes dword slots 13..20 and returns a pointer past the initialized tail. Invoked from caller sub_516C7B.
- `0x0051BA70` **HuffmanDecodeContext** — Huffman-tree context allocator: allocates an 80-byte context through the sub-allocator vtable at *(a1+4) with (a1, 1, 80), stores it at offset 0x194, sets the context vtable entry 0 to sub_51B7CD (0x0051B7CD) and zeroes vtable slots 14..17; then allocates a flat slot_count*256-byte table (slot count at this+0x20) via the same sub-allocator, stores it at this+0x8C, and fills each 256-byte slot with 0xFF while slot_count is positive. Returns the table pointer when the fill loop is skipped, else -1.
- `0x0051C099` **TrackMapRowBlitter** — Track-map pixel-row expansion: reads a per-pixel fill width (byte at v6+140) and a row-repeat count (byte at v6+150) from a secondary structure formed from the pointer at a2+4 plus the self field at this+0x19C; stretches each source byte into a repeated 4-byte pattern for the pixel width, then duplicates each finished row downwards via F_2DArrayBlockCopy (0x0051593F). Iterates a1[68] rows (this+0x110), each a1[23] bytes wide (this+0x5C).
- `0x0051C176` **TrackMapRowBlitter** — Monochrome double-width row blit: copies each source byte twice into consecutive destination bytes per row, iterating the row count at this+0x110 of destination row pointers up to a row-end boundary derived from the row width at this+0x5C. Returns the post-increment row counter.
- `0x0051C1CD` **TrackMapRowBlitter** — Interleaved double-width row blit: doubles each source byte horizontally into every other destination row (stepping the row index by two until the row count at this+0x110), then duplicates the filled row to the adjacent row via F_2DArrayBlockCopy (0x0051593F) using the row width at this+0x5C. Returns the pointer value threaded through the block-copy call.

## Proposed classes

### LinkedListNodeAllocatorObject

Allocator object owning the allocator state base at this+0x4 (list head reachable through it at +68, packet-anchored as this+0x48) and a sub-object reachable through this+0x0's vtable; allocates 120-byte linked-list nodes via MemoryAllocator (0x00515F23) and prepends them to the list. For non-default categories it writes a constant (12) and the category into the sub-object (obj+0x14/+0x18) and dispatches the sub-object vtable slot 0.

Methods: `0x0051623E`

- `this+0x00000000` `pointer subobject_vtable_ptr` (read, GUESS)
- `this+0x00000004` `pointer allocator_state_base` (read, GUESS)
- `this+0x00000048` `pointer list_head` (write, GUESS)
- `obj+0x00000000` `pointer subobject_vtable` (read, GUESS)
- `obj+0x00000014` `int category_constant_slot` (write, GUESS)
- `obj+0x00000018` `int category_slot` (write, GUESS)

### WriteWindowBufferObject

Windowed write-validated buffer manager accessed at a2 by ringBufferWrite (0x00516531) and OffsetValidationWithBufferUpdate (0x0051664F): buffer base +0, capacity +4, element stride +8, max write size +12, window length +16, write position +24, written bound +28, zero-fill flag +32, pending-reprocess flag +33, reprocess-allowed flag +34. Validation failures and reprocess-denied errors are dispatched through the error object a1 by writing the error code (20 or 68) to obj+0x14 and invoking the obj+0x0 vtable slot. Both siblings access the same offset set and error pattern, so they are grouped as one class. The buffer-manager offsets (buf+0 base, +4 capacity, +8 element stride, +12 max write size, +16 window length, +24 write position, +28 written bound, +32 zero-fill flag, +33 pending-reprocess flag, +34 reprocess-allowed flag) are carried in prose only because the packet supplies no field:<base>:<offset> evidence references for them; they are not declared as class fields.

Methods: `0x00516531`, `0x0051664F`

- `obj+0x00000000` `pointer error_vtable` (read, GUESS)
- `obj+0x00000014` `int error_code_slot` (write, GUESS)

### PriorityDispatchAdapter

State-machine priority-dispatch helper object: holds the dispatch object at this+0x4 whose vtable slot 0x24 is invoked with (a1, 1), the byte flag at this+0xC selecting 200 vs 100, and the result dword at this+0x10. Called by StateMachineDispatcher (0x0050F904) and StateMachineDispatch_f9ab (0x0050F9AB). Owner identity not established.

Methods: `0x00516937`

- `this+0x00000004` `pointer dispatch_object_ptr` (read, GUESS)
- `*(this+0x4)+0x00000024` `pointer virtual_slot_0x24` (read, GUESS)
- `this+0x0000000C` `byte priority_flag` (read, GUESS)
- `this+0x00000010` `int priority_result` (write, GUESS)

### VTableAllocAdapter

Vtable-based buffer allocator adapter (structural twins 0x00516974 and 0x00516990): calls vtable slot 0 of the allocator object at this+0x4 with (this, 0, size) (130 or 274 bytes), writes a zero byte at result+size-1 as a null terminator, and returns the buffer. Consumed by MP3HuffmanDecoder (0x00510D60) and sub_510ACC (0x00510ACC).

Methods: `0x00516974`, `0x00516990`

- `this+0x00000004` `pointer allocator_ptr` (read, GUESS)
- `*(this+0x4)+0x00000000` `pointer allocator_vtable_slot0` (read, GUESS)

### StatelessHelperFunctions

Low-level stateless helper functions with no proven instance state: 2x2 float matrix-vector product (0x00517534), byte memcpy wrapper (0x00517EE1), replicated-byte buffer fill (0x00517F04), free forward wrapper to sub_58AA6F (0x00519351) and third-argument passthrough (0x0051935C). Grouped by shape (no this fields, single-purpose); owner identity is not established.

Methods: `0x00517534`, `0x00517EE1`, `0x00517F04`, `0x00519351`, `0x0051935C`


### CRC32TableComputation

Bitwise table-driven CRC32 over a byte buffer using the 256-entry table at dword_5AFFA0 (0x005AFFA0): complement-in seed, unrolled 8-byte fast path plus byte tail loop, complement-out return, enabling chained computation (previous result passed as next seed). Stateless; no instance fields. Invoked by AnimationHandleAlloc (0x00513CD8) and the PngDecoderObject CRC update (0x00517F58).

Methods: `0x0051923D`


### PngDecoderObject

PNG chunk-stream decoder object: flag register at this+0x58 (bits: 0x1 IHDR seen, 0x4 IDAT seen, 0x8/0x18 done), flags register at this+0x5C (0x300 mask) and low flag byte at this+0x5D (bit 0x8), CRC accumulator at this+0x100, and control byte at this+0x10C (bit 0x20 select). Owns chunk-type validation (0x00517FD0), CRC/state update (0x00517F58), state-change check (0x00517F72), the IEND handler (0x00518BD4) and the unknown-critical-chunk handler (0x00518FCF). Grouping is DERIVED-proposed from shared this+0x58 (0x00518BD4/0x00518FCF), shared this+0x10C (0x00518FCF with 0x00517F58/0x00517F72), and the call edges 0x00518FCF -> 0x00517FD0 and 0x00518BD4/0x00518FCF -> 0x00518828 -> 0x00517F58/0x00517F72.

Methods: `0x00517F58`, `0x00517F72`, `0x00517FD0`, `0x00518BD4`, `0x00518FCF`

- `this+0x00000058` `int image_state_flag_register` (read_write, DERIVED)
- `this+0x0000005C` `int flags_register` (read, DERIVED)
- `this+0x0000005D` `byte low_flag_byte` (read, DERIVED)
- `this+0x00000100` `int crc_accumulator` (read_write, DERIVED)
- `this+0x0000010C` `byte control_byte` (read, DERIVED)

### PngBitStreamUnpacker

Pixel-unpacking stage over a packed bit stream: source data pointer at this+0xDC (dereferenced at +1, implying a one-byte header prefix), pixel count at this+0xB8, and bits-per-pixel byte at this+0xFB selecting 1/2/4/8+ unpacking widths. Invoked by sub_511B7C on the PNG row/image decode path. Ownership of the this object is not established.

Methods: `0x00518032`

- `this+0x000000B8` `int pixel_count` (read, GUESS)
- `this+0x000000DC` `pointer source_data_ptr` (read, GUESS)
- `*(this+0xDC)+0x00000001` `byte source_data_prefix` (read, GUESS)
- `this+0x000000FB` `byte bits_per_pixel` (read, GUESS)

### TextureStretchInfo

Texture row-stretch info object: source width at this+0x0 (updated to the stretched width on completion), output byte count at this+0x4, and bits-per-pixel byte at this+0xB selecting the 1/2/4-bit packed paths or the >= 8 byte path. The stretch factor comes from the global stride table dword_5AFABC[a3]. Invoked by sub_511B7C on the texture row decode path; owner identity not established.

Methods: `0x00518248`

- `this+0x00000000` `int source_width` (read_write, GUESS)
- `this+0x00000004` `int output_byte_count` (write, GUESS)
- `this+0x0000000B` `byte bits_per_pixel` (read, GUESS)

### PngAdaptiveFilterStage

Stateless PNG-style adaptive-filter row stage: applies predictor modes 1 (extend leading block), 2 (add predictor), 3 (average) and 4 (three-sample minimizer) to a byte row a3 using predictor row a4 and a row descriptor a2 whose +4 field holds the byte count and whose +11 field holds the bit depth (bytes-per-pixel = (depth+7)>>3). Unrecognized modes report through CallbackDispatch (0x00511887). Invoked by sub_511B7C. The row descriptor layout (byte count at +4, bit depth at +11) is carried in prose only because the packet supplies no field:<base>:<offset> evidence for base a2.

Methods: `0x00518511`


### HuffmanDecodeContext

Owner of Huffman sub-contexts (packet-supplied DERIVED owner for HuffmanCtxAlloc 0x0051AEC2): holds the sub-allocator vtable pointer at this+0x4 (slot 0 called with (owner, 1, size)), the stored sub-context pointer at this+0x194, and for the tree variant the slot count at this+0x20 and the flat slot_count*256-byte table pointer at this+0x8C. HuffmanCtxAlloc installs vtable methods ArrayProcessingWithValidation (0x0051AD93) and TextureDecompression (0x0051A9C6) and zeroes dword slots 13..20; HuffmanTreeAlloc installs sub_51B7CD (0x0051B7CD), zeroes vtable slots 14..17 and fills each 256-byte table slot with 0xFF. Both store at this+0x194 through the same this+0x4 sub-allocator, so they are grouped into one class; the tree-allocator ownership attribution is proposed.

Methods: `0x0051AEC2`, `0x0051BA70`

- `this+0x00000004` `pointer sub_allocator_ptr` (read, DERIVED)
- `*(this+0x4)+0x00000000` `pointer sub_allocator_vtable_slot0` (read, GUESS)
- `this+0x00000020` `int huffman_slot_count` (read, GUESS)
- `this+0x0000008C` `pointer huffman_table_ptr` (write, GUESS)
- `this+0x00000194` `pointer sub_context_ptr` (write, DERIVED)

### HuffmanBitstreamSymbolDecoder

Bitstream object decoding one Huffman-coded symbol: bit accumulator at this+0xC, remaining-bit count at this+0x18, and parent-context pointer at this+0x1C whose vtable (*(this+0x1C)+0x0) provides the error-code slot at +0x14 (written with literal 114 on decode failure) and the error handler at slot +0x4 (dispatched with (parent_context, -1)). Refills through sub_51A794 (0x0051A794). Called by TextureDecompression (0x0051A9C6), BitstreamDecoder (0x0051AF57), sub_51B154 and sub_51B45F.

Methods: `0x0051A87E`

- `this+0x0000000C` `int bit_accumulator` (read_write, GUESS)
- `this+0x00000018` `int remaining_bit_count` (read_write, GUESS)
- `this+0x0000001C` `pointer parent_context_ptr` (read, GUESS)
- `*(this+0x1C)+0x00000000` `pointer parent_vtable` (read, GUESS)
- `*(*(this+0x1C)+0x0)+0x00000014` `int parent_error_code_slot` (write, GUESS)
- `*(*(this+0x1C)+0x0)+0x00000004` `pointer parent_error_handler_slot` (read, GUESS)

### TrackMapRowBlitter

Track-map / image row-expansion blitter sharing row pitch at this+0x5C and row count at this+0x110: pixel-fill expansion with vertical row duplication via F_2DArrayBlockCopy (0x0051593F) plus a secondary structure pointer at this+0x19C (0x0051C099), and the two double-width row blits (monochrome 0x0051C176, interleaved 0x0051C1CD). All three read the same this+0x5C and this+0x110 fields, so they are grouped as one class; owner identity is not established.

Methods: `0x0051C099`, `0x0051C176`, `0x0051C1CD`

- `this+0x0000005C` `int row_pitch` (read, GUESS)
- `this+0x00000110` `int row_count` (read, GUESS)
- `this+0x0000019C` `pointer secondary_structure_ptr` (read, GUESS)

### SurfaceMemoryDelegate

Surface memory allocation delegate: unconditionally writes the literal 48 into the DWORD at obj+0x14 (surface stride/pitch per existing analysis), then dispatches through the object vtable at obj+0x0 (first slot) calling the allocation function with this = a1 and returns its result. Invoked from DirectXTextureSurfaceAllocation (0x0051629F). Object type behind the vtable is unknown.

Methods: `0x00519361`

- `obj+0x00000000` `pointer vtable_slot0` (read, GUESS)
- `obj+0x00000014` `int surface_stride` (write, GUESS)

## Compatibility contracts

- **WriteWindowBufferContract** — The windowed write-validated buffer must keep buffer base at buf+0, capacity at buf+4, element stride at buf+8, max write size at buf+12, window length at buf+16, write position at buf+24, written bound at buf+28, zero-fill flag at buf+32, pending-reprocess flag at buf+33 and reprocess-allowed flag at buf+34. A write must validate the range against capacity and max size (error code 20 via obj+0x14 + obj+0x0 vtable dispatch on failure), reposition out-of-window requests (dispatching sub_51641E/sub_5164A6), raise error 68 when reprocess is disallowed, advance the written bound to the range end, zero-fill the gap when the flag is set (element size from buf+8), and return a pointer into the element array at the target index.
- **PngChunkTypeValidationContract** — A four-byte PNG chunk-type header is valid only when every byte satisfies 0x29 <= v <= 0x7A and no byte falls in the gap 0x5A < v < 0x61; on the first invalid byte the decoder must report 'invalid chunk type' through DoubleBufferInit (0x0051189C) and return its result. The validation runs against the control byte at this+0x10C before unknown-critical-chunk handling.
- **PngImageStateAndIendContract** — The PNG decoder must track image-present flags in the register at this+0x58 (bit 0 IHDR seen, bit 2 IDAT seen, done bits 0x8/0x18). The IEND handler must require bits 0x1 and 0x4 set (else GuardedCallWithLongjmp 'No image in file' via 0x00511869), set the done bits 0x18, warn 'Incorrect IEND chunk length' via CallbackDispatch when the chunk length is non-zero, and run the CRC error check sub_518828 before returning. Unknown critical chunks must set done bit 0x8 only when bit 0x4 is set.
- **AdaptiveFilterContract** — The row adaptive-filter stage must honor four predictor modes on the byte row using the row descriptor a2 (+4 byte count, +11 bit depth): 1 extends the leading block across the row, 2 adds the predictor row, 3 averages with the predictor (half-precision for the leading block), 4 applies a three-sample minimizer. Unrecognized modes must report 'Ignoring bad adaptive filter type' through CallbackDispatch (0x00511887) and zero the first output byte.
- **VTableAllocatorContract** — Any consumer of the sub-allocator at this+0x4 must call its vtable slot 0 with (owner, flag, size) and must treat the returned buffer as owned by the caller: the buffer alloc twins null-terminate at size-1 (result+128 for 130 bytes, result+273 for 274 bytes), and the Huffman allocators pass (this, 1, 88) / (this, 1, 80) / (this, 1, slot_count<<8). Slot-0 argument semantics beyond 'size' are caller-side contracts.
- **HuffmanContextAllocationContract** — The Huffman owner stores its sub-context at this+0x194. The decode-context allocator must install vtable methods ArrayProcessingWithValidation (0x0051AD93) and TextureDecompression (0x0051A9C6) and zero dword slots 13..20; the tree-context allocator must install sub_51B7CD (0x0051B7CD), zero vtable slots 14..17, allocate a flat slot_count*256-byte table (slot count at this+0x20) stored at this+0x8C, and fill each 256-byte slot with 0xFF while the count is positive.
- **TrackMapRowExpansionContract** — The track-map/row-expansion blitter reads the row count at this+0x110 and the row pitch at this+0x5C. 0x0051C099 must expand each source byte into a repeated 4-byte pattern for the per-pixel fill width and duplicate finished rows downward via F_2DArrayBlockCopy; the monochrome and interleaved blits (0x0051C176, 0x0051C1CD) must write each source byte twice into the destination rows, with the interleaved variant duplicating every other row via F_2DArrayBlockCopy.
- **HuffmanSymbolDecodeErrorContract** — The Huffman symbol decoder must persist the bit accumulator to this+0xC and the remaining bit count to this+0x18, refill through sub_51A794 when fewer bits are buffered than requested (returning -1 on refill failure), and on a decode failure write the literal 114 into the parent-context vtable slot at +0x14 and dispatch the parent vtable slot +0x4 error handler with (parent_context, -1) before returning 0.

## Unresolved

- 0x0051623E (AllocLinkedListNodeInsertHead2): the 120-byte node field layout (offsets 0, 4, 8, 12, 32, 34, 36) has no named semantics; the identity of the virtual callback dispatched through the sub-object vtable (obj+0x0) is unknown; the list head is written through (this+0x4)+68 while the packet names this+0x48 as the anchor, and the equivalence of the two views is not proven; whether the this+0x48 list is distinct from the this+0x44 list in 005161DD is not established by this packet.
- 0x00516531 (ringBufferWrite) and 0x0051664F (OffsetValidationWithBufferUpdate): the buffer manager struct at a2 is typed only through raw offsets and its enclosing class is unestablished; error codes 20 and 68 and the a5-flag semantics are DERIVED, not independently evidenced; sub_51641E/sub_5164A6 internal dispatch semantics (flag 1 vs 0) are not visible in this packet; the element pointers are indexed as 4-byte dwords, so the true element stride is assumed from that indexing.
- 0x00516937 (VirtualDispatchConditionalValue): the method at vtable slot 0x24 and the meaning of its argument 1 are unknown; the 200/100 result values as a dispatch priority is DERIVED; owner object identity is not established.
- 0x00516974 / 0x00516990: the allocator contract at this+0x4 (argument semantics of 0 and the size, buffer ownership) is not evidenced beyond the raw vtable call.
- 0x00517534 (Mat2x2Mul): the full matrix width/layout of the right operand a3 (read at elements 4 and 5) is not established from the body; the packet operations reference field:this:0x00000000 and field:this:0x00000004 against the output pointer, which are decompiler base mislabels rather than evidence of instance fields.
- 0x00517EE1 (MemoryCopy): the first parameter a1 is unused and may be a stale/reserved ABI argument; source/destination types and data meaning are caller-supplied (single caller sub_511B7C).
- 0x00517F04 (MemsetWithByteFill): a2 is unused by the decompiled body; the destination object and element type are caller-supplied; the two callers (AudioBufferSizeCalc, sub_519019) are not evidenced in this packet.
- 0x00517F58 (CRC32UpdateBlock): the CRC32Computation operation appears in the raw source but has no packet callee record, so no callee evidence is asserted for it; the exact semantics of the skip flag combinations (this+0x5D bit 3, this+0x5C bits 8-9) are unknown.
- 0x00517F72 (AnimationStateCheck): both (int)&a1 arguments are the stack address of the parameter slot, so the four bytes assembled by ByteArrayToInt equal the pointer value a1 itself - whether the intended input is the pointer value or a decompiler artifact is unconfirmed; the flag-bit semantics and the write site of this+0x100 are outside this function.
- 0x00518032 (BitStreamPixelUnpacker): the source buffer is always dereferenced at +1 (one-byte header prefix whose content is uncharacterized); the a3 stencil-mask interpretation and the final return value have no confirmed semantics.
- 0x00518248 (TextureHorizontalStretch): the meaning of the stride-table index a3 and the dword_5AFABC entries is unconfirmed; the precomputed mask values (32639, 16191, 3855) in the bit-packed loops are unconfirmed; whether a full texture or a single row is stretched is unconfirmed.
- 0x00518511 (ApplyAdaptiveFilter): the row descriptor a2 (+4 byte count, +11 bit depth) full layout and owner class are unknown; the four modes resemble PNG-style predictors (Sub/Up/Average/Paeth-like) but the exact family and bit-depth scaling are unverified; case 4's three-sample minimizer is median-like but not provably a standard Paeth predictor.
- 0x00518BD4 (PngIendChunkHandler): the exact meaning of flag bits 0 and 2 at this+0x58 (interpreted as IHDR/IDAT seen) is DERIVED; GuardedCallWithLongjmp's abort/longjmp contract is not visible in this function; the origin and meaning of a2 are not established.
- 0x00518FCF (UnknownCriticalChunkHandler): the bit 5 (0x20) skip-error-dispatch semantics at this+0x10C is DERIVED; sub_517FD0's exact role is inferred from the call site; a2's origin and meaning are not established.
- 0x0051923D (CRC32Computation): the CRC polynomial and the initialization of dword_5AFFA0 are external to this function; the ABI record labels it CRC32_Computation with LEGACY trust and a null prototype - treated as supporting evidence only.
- 0x00519351 (FreeMemoryWrapper): whether sub_58AA6F actually deallocates lpMem is inferred only from the canonical/ABI 'Free' labels; the unused a1 argument's purpose is unknown.
- 0x0051935C (returnThirdArgument): why a1 and a2 are accepted but unused is unknown (stub or tail of a larger interface); how the returned a3 is used by DirectXTextureSurfaceAllocation is not inferable here.
- 0x00519361 (SurfaceMemoryAllocate): the vtable target at index 0 is not statically resolvable; the meaning of the 48 value (surface stride vs pitch) is DERIVED; the object type behind the vtable is unknown.
- 0x0051A87E (HuffmanArithmeticBitstreamSymbolDecoder): the Huffman table object a4 layout (threshold at a4+4*a5+68, tables at a4+4*v12+140 and a4+4*v12, base at a4+208) is not part of the deterministic field list; the parent-context vtable slot +0x4 error handler identity and the meaning of the -1 argument are unknown; the meaning of the literal 114 is unknown.
- 0x0051AEC2 (HuffmanCtxAlloc): the meaning of the 88-byte size and the two installed vtable methods relative to a specific Huffman codec is not established; which object owns the sub-allocator vtable at this+0x4 is unknown.
- 0x0051BA70 (HuffmanTreeAlloc): the exact structure of the Huffman-tree context and table is unknown; the allocator uses cdecl through a vtable slot whose signature is a caller-side contract; return value differs by path (table pointer when slot_count <= 0, else -1).
- 0x0051C099 (TrackMapPixelFill): the object behind a2+4 and the control bytes at v6+140 / v6+150 are unnamed; when v21 == 0 the inner loop never advances v19, so per-source-byte consumption and the v19 < v12 bound could diverge; whether self fields +0x5C/+0x110 belong to the same object as the secondary structure at a2+4 is not established.
- 0x0051C176 (monochromeDoubleWidthRowBlit) and 0x0051C1CD (interleaveDoubleWidthRowBlit): owner object type is unknown (no caller evidence in the packet); the returned value is a post-increment counter / threaded pointer whose caller contract is unknown; the row-width/row-count field semantics are DERIVED from loop structure; the interleave rationale is structural inference.
- General: equal offsets on different this bases or on different classes are never merged into a shared type without packet proof of common ownership (rule 8). HuffmanTreeAlloc (0x0051BA70) shares this+0x194 and this+0x4 with HuffmanCtxAlloc (0x0051AEC2) and is grouped into HuffmanDecodeContext, but the tree-allocator owner attribution is a proposal. PngDecoderObject, TrackMapRowBlitter, WriteWindowBufferObject and all other clusters are DERIVED-proposed; worker agreement cannot create runtime truth.
