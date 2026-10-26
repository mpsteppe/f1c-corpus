# GenericRuntimeObjectSupport

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Nineteen runtime object helpers. A DXT/BC colour pipeline converts float RGBA into packed 8-byte blocks: Float3RgbTo16Bit565 (0x00513E80) quantizes a float3 RGB to 16-bit 5:6:5, ColorQuantization (0x00513F7A) optimizes a min/max bound pair for N-level alpha quantization, OBBFittingAndProjection (0x0051427F) fits an oriented bounding box over 16 vertices and refines its projection bounds, DxtBlockCompressor (0x005147EA) and DxtBlockDecompressor (0x00514FEE) encode/decode 4x4 blocks with 5:6:5 endpoints and 2-bit selectors, QuantizationColorSpaceConversion (0x00515303) encodes 4-bit alpha nibbles, and AlphaBlockEncoderWithColorCompression (0x00515417) encodes 3-bit alpha selectors, all sharing FPUControlWordMerger (callee 0x00513E5D) for quantization rounding and delegating color work to 0x005147EA; InitProcessWrapper (0x005158E3) scales a matrix by W then runs the encoder pipeline. A heap family (AllocFromFreeList 0x00515F23, AlignedAllocFromMalloc 0x0051601F) implements an 8-byte-aligned per-category free-list allocator over MallocWrapper (callee 0x00519346) with 16-byte block headers and error reporting via ShortComputation_5f0e (callee 0x00515F0E). validateSurfaceDescriptors (0x005159F5) validates texture surface parameters against fixed limits and recomputes aligned descriptor dimensions via CeilingDivision (callee 0x00515917). AllocateAudioVoiceChannels (0x00515BB0) negotiates audio voice slots per stream descriptor, AllocateAndCopyObjectBuffers (0x00515D26) allocates and copies object buffers through a vtable allocator, and a dispatch-object family (VtableDelegateDispatch 0x00515DB8, SetupArithmeticComparison 0x00515E85, DirectorCameraObjectSetup 0x00515ECD) builds and runs a 24-byte sub-object bound to the UIScreenStateMachine pointer (global 0x00515DF2). SafeDeleteGuardForThunkFUN00517ec8 (0x00513CD3) and ShortComputation_3d2f (0x00513D2F) are teardown/clear helpers called by LargeStructPartialReset, and AlignUp (0x00515927) rounds allocation sizes up to a multiple. Most owning object types are UNKNOWN; every class here is a conservative grouping proposal.

## Function roles

- `0x00513CD3` **UnknownObject** — Forwarding thunk: passes a1 and lpMem unchanged to target FUN 00517EC8 and returns the callee's result directly. The ABI lead describes the target as a safe-delete guard; called by LargeStructPartialReset as a cleanup/teardown step in a large-struct reset path. The conditional logic inside the target and the meaning of a1 are not established.
- `0x00513D2F` **UnknownObject** — Zero-initializer: memset(a2, 0, 0x40) clearing 16 dwords (64 bytes) of a destination buffer; returns constant 0. Argument a1 is received but unused. Called by LargeStructPartialReset as a struct-buffer clearing step. The type and owner of the a2 buffer are unknown.
- `0x00513E80` **DxtBlockCodec** — Float3 RGB to packed 16-bit 5:6:5: clamps red/green/blue at this+0x0/+0x4/+0x8 to [0,1], quantizes R and B by 31.0 and G by 63.0 with a +0.5 rounding offset, packs (R<<11)|(G<<5)|B; FPU rounding mode set via FPUControlWordMerger before the truncations. Used by DxtBlockCompressor (0x005147EA). The 31.0/63.0 scale globals flt_5ACCD0/flt_5ACCD8 are associated by the fill, not by a write site.
- `0x00513F7A` **DxtBlockCodec** — Iterative colour-bound optimizer: quantizes 16 float samples to N levels (6 or 8) by refining a min/max bound pair through coefficient-table weighted error accumulation, then writes clamped [0,1] bounds to *a1 (min) and *a2 (max) and returns a2. Level count 6 selects coefficient pair unk_5AF5C4/unk_5AF5AC, otherwise unk_5AF58C/unk_5AF56C. FPU rounding via FPUControlWordMerger. Called by AlphaBlockEncoderWithColorCompression.
- `0x0051427F` **DxtBlockCodec** — Fit an oriented bounding box over 16 float4 vertices and refine its projection bounds for quantization to a4 levels: computes the AABB and squared diagonal, accumulates four moment sums, re-orders bounds to the dominant projection axis, then runs up to 8 refinement passes using coefficient tables (a4 == 3 selects unk_5AF60C/unk_5AF600, else unk_5AF5F0/unk_5AF5E0); writes min float3 to a1 and max float3 to a2 and returns a2. FPU rounding via FPUControlWordMerger. Called once by DxtBlockCompressor.
- `0x005147EA` **DxtBlockCodec** — DXT/BC 4x4 block compressor: with alpha handling on, counts transparent pixels (alpha < 0.5 at this+0xC) and writes an all-transparent marker when all 16 qualify; selects a 3- or 4-colour endpoint mode from the transparent count, accumulates per-channel colour sums, quantizes the average to 5:6:5 and error-diffuses residuals (0.4375/0.1875/0.3125/0.0625); fits endpoint candidates via OBBFittingAndProjection, scales them with flt_5D79CC/D0/D4, quantizes each via Float3RgbTo16Bit565, and in the general path decodes and interpolates endpoint colours (0.5 midpoint or 0.3333/0.6666 thirds); a second pass picks 2-bit selectors via dot-product sign and lookup tables unk_5AF628/unk_5AF618 and packs them into a2+4. FPU rounding via FPUControlWordMerger. Returns 0.
- `0x00514FEE` **DxtBlockCodec** — DXT/BC 4x4 block decompressor: decodes the two 16-bit endpoint colours at a2[0] and a2[1] via F_16BitColorToFloat4Decoder, builds a 4-colour palette (1/3 and 2/3 interpolation points when word 0 > word 1) or a transparent 2-colour palette (0.5 midpoint plus zeroed slots otherwise), then expands the 32-bit selector mask at a2+4 into 16 float4 outputs at a1. Returns 0. Called by 0x0051512C and 0x005151AF.
- `0x00515303` **DxtBlockCodec** — BC3/DXT5-style alpha-block encoder: clears the two packed DWORD outputs (a1, a1+4), quantizes 16 alpha samples to 4-bit nibbles (value*15.0+0.5) with error diffusion (0.4375/0.1875/0.3125/0.0625), packs nibbles MSB-first into a1 and a1+4, then delegates the colour half to DxtBlockCompressor and returns its result. FPU rounding via FPUControlWordMerger. Called by 0x005158AF.
- `0x00515417` **DxtBlockCodec** — BC3/BC1-style alpha+colour block encoder with 3-bit selectors: first pass quantizes 16 float alphas to bytes (value*255.0+0.5) via the byte-to-float scale global and stores them with a running max and last value; ColorQuantization derives optimal alpha min/max bounds; a 7-step (8-level) or 5-step (6-level) linear palette is built; fully opaque and single-alpha blocks take marker-byte short paths. Second pass maps each alpha to a palette index and packs 3-bit selectors MSB-first into 48-bit output with error diffusion. The colour half is delegated to DxtBlockCompressor (output at output+8); the FPU control word is saved to global dword_8B00A0 around the color-compression call and restored before return. Sole static caller is InitProcessWrapper (0x005158E3).
- `0x005158E3` **DxtBlockCodec** — Two-stage matrix processing wrapper: MatrixScaleByW(a2, v3) scales the input matrix into a 64-float local buffer; if its return is >= 0, AlphaBlockEncoderWithColorCompression (0x00515417) runs the second stage over the scaled result. Returns 0 on full success, otherwise the failing stage's error code. The scalar a1 role and the 64-float buffer layout are not established.
- `0x00515927` **UnknownObject** — Alignment helper: returns a1 + a2 - 1 - (a1 + a2 - 1) % a2, rounding the sum up to the next multiple of a2. No guard for a2 == 0. Call sites are allocation paths on UI, playback-buffer and audio-decode code (UIListComboBoxConstructor, PlaybackBufferAlloc, MediaAudioDecodeDispatch); byte-count vs alignment-unit argument semantics are unverified.
- `0x005159F5` **TextureSurfaceValidator** — Texture surface validation and alignment: reports oversized dimensions (total width/height at this+0x18/+0x1C beyond 65500), pixel format mismatch (this+0xC0 != 8), oversized sub-surface count (this+0x20 > 10) and out-of-range per-descriptor factors through the object vtable callback with code/detail/limit slots (obj+0x14/+0x18/+0x1C), continuing execution. Two passes over the descriptor array at this+0xC4 (84-byte stride) accumulate max width/height factors into this+0x10C/+0x110 and compute aligned dimensions and strides via CeilingDivision (0x00515917), then refresh the output surface active flag at *(this+0x18C)+0x10 when the tracked count (this+0x120) or the this+0xC8 flag demands it. Returns the output surface state pointer.
- `0x00515BB0` **AudioStreamAllocator** — Audio voice-channel negotiation and allocation: mode this+0x120 == 1 copies a single stream descriptor into the negotiated fields; invalid modes (<= 0 or > 4) are rejected through the object vtable error record (obj+0x14 code 24, obj+0x18 mode, obj+0x1C limit 4); valid multi-stream modes compute per-stream voice totals with CeilingDivision (0x00515917) over this+0x18/0x1C and the max factors, fill each stream descriptor's allocation fields, cap the accumulated voice-slot count (this+0x13C) at 10, and record stream indices into the voice-slot table at this+0x140 onward.
- `0x00515D26` **ObjectBufferPool** — Object-buffer pool allocator/copier: iterates the descriptor array at this+0x124 while the index is below the count at this+0x120; only descriptors whose buffer pointer (descriptor+0x4C) is null are processed. Validates the type id (descriptor+0x10) and source pool slot; invalid types write markers (obj+0x14 = 51, obj+0x18 = type) and run the obj vtable init callback first. Allocates a buffer through the allocator vtable at this+0x4, copies 0x82 bytes from the source pool entry, and stores the buffer into descriptor+0x4C.
- `0x00515DB8` **ScreenStateDispatchObject** — Sequential delegate setup: allocates audio voice channels (0x00515BB0), copies/validates object buffers (0x00515D26), then dispatches two vtable methods through the delegate slots at this+0x194 and this+0x184, and copies the dword at *(this+0x184)+0x4 into the destination pointer stored at *(this+0x18C). Returns the copied value. Invoked by the UI screen state machine at 0x00515DF2. The semantic roles of the two dispatched methods are not resolvable from the packet.
- `0x00515E85` **ScreenStateDispatchObject** — Embedded arithmetic-comparison sub-object setup at this+0x18C: stores the UIScreenStateMachine symbol pointer into sub-object word 0, clears its byte flags at +0x10 and +0x11, sets its active byte at +0x14 to 1, dispatches the object vtable entry at obj+0x10, invokes the first function-table entry at this+0x190, clears the result/completion dword at this+0x8C, and returns the dispatch result. The semantics of the stored pointer and the dispatch result are not defined here.
- `0x00515ECD` **ScreenStateDispatchObject** — Dispatch sub-object factory: allocates a 24-byte sub-object through the allocator vtable at *(this+0x4), stores it at this+0x18C, and initializes it: first dword set to UIScreenStateMachine, offsets +4/+8/+12 set to the function pointers VtableDelegateDispatch (0x00515DB8), ArithmeticComparison_5e85 (0x00515E85) and VtableFunctionPointerWrite (0x00515EBC), byte flags +16/+17 cleared, enable byte +20 set to 1. Returns the initialized sub-object pointer. Known caller is sub_50F632 (0x0050F632).
- `0x00515F23` **HeapFreeListAllocator** — Per-category free-list allocator for a custom heap: aligns the request up to 8 bytes, walks the per-category free list (head at this+0x4 + 4*cat + 48) for a first-fit block, and when none fits allocates a fresh block through MallocWrapper (0x00519346) with chunk budget from dword_5AF8B8/dword_5AF8C0, halving on OOM and erroring through ShortComputation_5f0e. New blocks are chained into the list and the running total at this+0x4C incremented. The found block is carved (free size at +8 shrinks by the request, data offset at +4 advances) and the payload 16 bytes past the block header is returned. Category >= 2 runs a vtable init callback with marker constant 12 at obj+0x14 and the category at obj+0x18.
- `0x0051601F` **HeapFreeListAllocator** — 8-byte-aligned allocation for the same chunked allocator: caches the base from this+0x4, rejects requests over 0x3B9AC9F0 (error code 3 via ShortComputation_5f0e), rounds the size up to the next 8-byte boundary, writes the marker (constant 12 at obj+0x14, category at obj+0x18) and dispatches through the object vtable for category >= 2, allocates size+16 via MallocWrapper (error code 4 on failure), accumulates into the running total at this+0x4C, and links the block into the per-category free list whose head is at this+0x4 + 4*cat + 56. Returns the payload pointer (block + 16 bytes).

## Proposed classes

### DxtBlockCodec

Free-function family for DXT/BC block colour compression, decompression and quantization helpers: float3-to-5:6:5 endpoint quantization (0x00513E80), alpha/colour bound optimization (0x00513F7A), OBB endpoint fitting (0x0051427F), 4x4 block compression with 2-bit colour selectors (0x005147EA), block decompression (0x00514FEE), 4-bit alpha nibble encoding (0x00515303), 3-bit alpha selector encoding (0x00515417) and a matrix-scale wrapper into the pipeline (0x005158E3). All members are __cdecl free functions with no shared this; the RGBA float4 fields this+0x0/+0x4/+0x8/+0xC describe the per-pixel block data consumed by the compressors and emitted by the decompressor. This is a GUESS grouping of a cohesive call family, not a proven original type.

Methods: `0x00513E80`, `0x00513F7A`, `0x0051427F`, `0x005147EA`, `0x00514FEE`, `0x00515303`, `0x00515417`, `0x005158E3`

- `this+0x00000000` `float pixelRed` (read_write, DERIVED)
- `this+0x00000004` `float pixelGreen` (read_write, DERIVED)
- `this+0x00000008` `float pixelBlue` (read_write, DERIVED)
- `this+0x0000000C` `float pixelAlpha` (read_write, DERIVED)

### HeapFreeListAllocator

Chunked per-category free-list heap. A context object holds an object/vtable pointer at 0x0, the per-category head-array base at 0x4, and a running allocated-byte total at 0x4C. AllocFromFreeList (0x00515F23) aligns the request to 8 bytes and walks a category free list for a first-fit block, allocating fresh chunks via MallocWrapper (0x00519346) with budget globals dword_5AF8B8/dword_5AF8C0 and erroring through ShortComputation_5f0e; AlignedAllocFromMalloc (0x0051601F) allocates 8-byte-aligned blocks and links them into the category list. Blocks carry a 16-byte header (size at +8, data offset at +4) and payloads are returned 16 bytes past the block base. Category >= 2 runs a vtable init callback with a marker at obj+0x14 and the category at obj+0x18. GUESS grouping; the heap-manager hierarchy behind this+0x0 is not resolvable from the packet.

Methods: `0x00515F23`, `0x0051601F`

- `this+0x00000000` `void* objectPtr` (read, DERIVED)
- `this+0x00000004` `void* categoryHeadArrayBase` (read, DERIVED)
- `this+0x0000004C` `int runningAllocatedBytes` (read_write, DERIVED)
- `obj+0x00000000` `void** vtablePtr` (read, DERIVED)
- `obj+0x00000014` `int categoryInitMarker` (write, DERIVED)
- `obj+0x00000018` `int categoryIndex` (write, DERIVED)

### TextureSurfaceValidator

Texture surface descriptor validator and dimension aligner. Validates total width/height (this+0x18/+0x1C) against 65500, pixel format (this+0xC0) against 8, sub-surface count (this+0x20) against 10, and each descriptor's width/height factors (base *(this+0xC4), stride 84) against [1,4], reporting every failure through the object vtable callback with a code/detail/limit record (obj+0x14/+0x18/+0x1C) while continuing execution. Two passes over the descriptor array accumulate maximum factors into this+0x10C/+0x110 and compute aligned dimensions, strides and flags via CeilingDivision (0x00515917), then refresh the output surface active flag at *(this+0x18C)+0x10 when the tracked count (this+0x120) or the this+0xC8 flag demands it. Returns the output surface state pointer. The packet names this owner DERIVED.

Methods: `0x005159F5`

- `this+0x00000000` `void* objectPtr` (read, DERIVED)
- `this+0x00000018` `int totalWidth` (read, DERIVED)
- `this+0x0000001C` `int totalHeight` (read, DERIVED)
- `this+0x00000020` `int subSurfaceCount` (read, DERIVED)
- `this+0x000000C0` `int expectedPixelFormat` (read, DERIVED)
- `this+0x000000C4` `unsigned char* descriptorArray` (read, DERIVED)
- `this+0x000000C8` `unsigned char outputRefreshFlag` (read, DERIVED)
- `this+0x0000010C` `int maxWidthFactor` (read_write, DERIVED)
- `this+0x00000110` `int maxHeightFactor` (read_write, DERIVED)
- `this+0x00000114` `int outputPixelFormat` (write, DERIVED)
- `this+0x00000118` `int alignedHeightDivisor` (write, DERIVED)
- `this+0x00000120` `int trackedOutputSurfaceCount` (read, DERIVED)
- `this+0x0000018C` `void* outputSurfaceStatePtr` (read, DERIVED)
- `*(this+0xC4)+0x0000000C` `int heightFactor` (read, DERIVED)
- `*(this+0xC4)+0x0000001C` `int alignedWidth` (write, DERIVED)
- `*(this+0xC4)+0x00000020` `int alignedHeight` (write, DERIVED)
- `*(this+0xC4)+0x00000024` `int descriptorPixelFormat` (write, DERIVED)
- `*(this+0xC4)+0x00000028` `int strideWidth` (write, DERIVED)
- `*(this+0xC4)+0x0000002C` `int strideHeight` (write, DERIVED)
- `*(this+0xC4)+0x00000030` `unsigned char strideValidFlag` (write, DERIVED)
- `*(this+0xC4)+0x0000004C` `unsigned char descriptorDirtyFlag` (write, DERIVED)
- `obj+0x00000000` `void** vtablePtr` (read, DERIVED)
- `obj+0x00000014` `int errorCode` (write, DERIVED)
- `obj+0x00000018` `int errorDetail` (write, DERIVED)
- `obj+0x0000001C` `int errorLimit` (write, DERIVED)

### AudioStreamAllocator

Audio voice-channel negotiation and allocation object. Holds the stream mode/count (this+0x120), the stream-descriptor pointer list (this+0x124), negotiated channel totals (this+0x134/+0x138), the accumulated voice-slot count (this+0x13C) and the voice-slot stream-index table (this+0x140 onward). Mode 1 copies a single stream directly into the negotiated fields; invalid modes and voice-cap overflow (limit 10) are reported through the object vtable error record (obj+0x14/+0x18/+0x1C). Multi-stream modes fill each stream descriptor's allocation fields (base *(this+0x124)) using CeilingDivision (0x00515917). GUESS grouping; the descriptor type behind this+0x124 is unknown.

Methods: `0x00515BB0`

- `this+0x00000018` `int totalWidth` (read, DERIVED)
- `this+0x0000001C` `int totalHeight` (read, DERIVED)
- `this+0x0000010C` `int maxWidthFactor` (read, DERIVED)
- `this+0x00000110` `int maxHeightFactor` (read, DERIVED)
- `this+0x00000120` `int modeOrStreamCount` (read, DERIVED)
- `this+0x00000124` `void** streamDescriptorList` (read, DERIVED)
- `this+0x00000130` `int[4] negotiationRegion` (write, DERIVED)
- `this+0x00000134` `int negotiatedWidth` (write, DERIVED)
- `this+0x00000138` `int negotiatedHeight` (write, DERIVED)
- `this+0x0000013C` `int voiceSlotCount` (read_write, DERIVED)
- `this+0x00000140` `int voiceSlotStreamIndex` (write, DERIVED)
- `this+0x00000144` `int voiceSlotStreamIndexNext` (write, DERIVED)
- `this+0x00000148` `int voiceSlotStreamIndexNext2` (write, DERIVED)
- `this+0x00000158` `int voiceSlotStreamIndex4` (write, DERIVED)
- `this+0x0000015C` `int voiceSlotStreamIndex5` (write, DERIVED)
- `this+0x00000160` `int voiceSlotStreamIndex6` (write, DERIVED)
- `this+0x00000164` `int voiceSlotStreamIndex7` (write, DERIVED)
- `this+0x00000168` `int voiceSlotStreamIndex8` (write, DERIVED)
- `*(this+0x124)+0x00000008` `int blockAlign` (read, DERIVED)
- `*(this+0x124)+0x0000000C` `int sampleCount` (read, DERIVED)
- `*(this+0x124)+0x0000001C` `int dataSize` (read, DERIVED)
- `*(this+0x124)+0x00000020` `int samplesTotal` (read, DERIVED)
- `*(this+0x124)+0x00000024` `int multiplier` (read, DERIVED)
- `*(this+0x124)+0x00000034` `int allocatedBlockAlign` (write, DERIVED)
- `*(this+0x124)+0x00000038` `int allocatedSampleBlock` (write, DERIVED)
- `*(this+0x124)+0x0000003C` `int voiceCount` (write, DERIVED)
- `*(this+0x124)+0x00000040` `int allocatedBytes` (write, DERIVED)
- `*(this+0x124)+0x00000044` `int sampleRemainder` (write, DERIVED)
- `*(this+0x124)+0x00000048` `int sampleRemainder2` (write, DERIVED)
- `obj+0x00000000` `void** vtablePtr` (read, DERIVED)
- `obj+0x00000014` `int errorCode` (write, DERIVED)
- `obj+0x00000018` `int errorDetail` (write, DERIVED)
- `obj+0x0000001C` `int errorLimit` (write, DERIVED)

### ObjectBufferPool

Object-buffer pool initializer/copier. Iterates the descriptor array at this+0x124 (count at this+0x120); each descriptor whose buffer pointer (base *(this+0x124) +0x4C) is null is validated by type id (+0x10). When the type id is >= 4 or the source pool entry is null, init markers are written (obj+0x14 = 51, obj+0x18 = type) and the obj vtable init callback runs first. A 130-byte buffer is then allocated through the allocator vtable at this+0x4 and 0x82 bytes are copied from the source pool entry into the descriptor's buffer slot (+0x4C). GUESS grouping; the type-id semantics and pool layout at this+144 are unknown.

Methods: `0x00515D26`

- `this+0x00000000` `void* objectPtr` (read, DERIVED)
- `this+0x00000004` `void** allocatorVtable` (read, DERIVED)
- `this+0x00000120` `int descriptorCount` (read, DERIVED)
- `this+0x00000124` `void** descriptorArray` (read, DERIVED)
- `*(this+0x124)+0x00000010` `int typeId` (read, DERIVED)
- `*(this+0x124)+0x0000004C` `void* bufferPtr` (write, DERIVED)
- `*(this+0x4)+0x00000000` `void* allocatorEntry0` (read, DERIVED)
- `obj+0x00000000` `void** vtablePtr` (read, DERIVED)
- `obj+0x00000014` `int initCode` (write, DERIVED)
- `obj+0x00000018` `int initTypeId` (write, DERIVED)

### ScreenStateDispatchObject

UI screen-state dispatch object family built around the UIScreenStateMachine data pointer (global 0x00515DF2). A 24-byte sub-object at this+0x18C is allocated through the allocator vtable at *(this+0x4) and initialized with the state-machine pointer and three function pointers: VtableDelegateDispatch (0x00515DB8), SetupArithmeticComparison (0x00515E85) and VtableFunctionPointerWrite (0x00515EBC). VtableDelegateDispatch runs the audio/object-buffer setup steps (callees 0x00515BB0, 0x00515D26) and two gated vtable method dispatches (slots this+0x194 and this+0x184), copying a result dword into *(this+0x18C); SetupArithmeticComparison arms an embedded sub-object and dispatches its virtual init (obj+0x10). The factory is called by sub_50F632 and the state machine invokes the delegate. GUESS grouping; the semantics of the stored pointers are not established.

Methods: `0x00515DB8`, `0x00515E85`, `0x00515ECD`

- `this+0x00000000` `void* objectPtr` (read, DERIVED)
- `this+0x00000004` `void** allocatorVtable` (read, DERIVED)
- `this+0x0000008C` `int resultCompletionDword` (write, DERIVED)
- `this+0x00000184` `void* delegateSlotB` (read, DERIVED)
- `this+0x0000018C` `void* subObjectPtr` (read, DERIVED)
- `this+0x00000190` `void* functionTableEntry` (read, DERIVED)
- `this+0x00000194` `void* delegateSlotA` (read, DERIVED)
- `*(this+0x184)+0x00000000` `void* delegateMethodB` (read, DERIVED)
- `*(this+0x184)+0x00000004` `int resultSourceDword` (read, DERIVED)
- `*(this+0x18C)+0x00000000` `void* stateMachineDataPtr` (write, DERIVED)
- `*(this+0x18C)+0x00000010` `unsigned char flagByte0` (write, DERIVED)
- `*(this+0x18C)+0x00000011` `unsigned char flagByte1` (write, DERIVED)
- `*(this+0x18C)+0x00000014` `unsigned char enableByte` (write, DERIVED)
- `*(this+0x190)+0x00000000` `void* functionPtr` (read, DERIVED)
- `*(this+0x194)+0x00000000` `void* delegateMethodA` (read, DERIVED)
- `*(this+0x4)+0x00000000` `void* allocatorEntry0` (read, DERIVED)
- `obj+0x00000000` `void** vtablePtr` (read, DERIVED)
- `obj+0x00000010` `void* virtualInit` (read, DERIVED)

## Compatibility contracts

- **DxtBlockByteLayout** — A compressed 4x4 block is 8 bytes: two 16-bit 5:6:5 endpoint colours (a2[0], a2[1]) followed by a 32-bit 2-bit-per-pixel selector mask (a2+4). The compressor writes the endpoint words and then the selector mask; the decompressor reads them and expands to 16 float4 pixels. A replacement must preserve the 8-byte block layout, the 5:6:5 channel bit ordering and the selector bit order.
- **AlphaSelectorPacking** — Alpha blocks encode 16 pixels with 3-bit selectors packed MSB-first into 48 bits of output, with marker-byte short paths for fully opaque, fully transparent and single-alpha blocks. The colour half is delegated to the block compressor into the colour block at output+8. A replacement must preserve the selector packing and the short-path markers.
- **FourBitAlphaNibblePacking** — The nibble encoder packs 16 alpha samples as 4-bit nibbles MSB-first into two DWORD outputs (a1, a1+4) before delegating the colour half to the block compressor. A replacement must preserve the nibble ordering and the two-DWORD output layout.
- **CeilingDivisionAlignContract** — CeilingDivision (callee 0x00515917) is the shared ceil-division primitive used to align texture surface dimensions (total times factor over 8 times max factor) and to negotiate audio channel totals. A replacement must reproduce its integer rounding so aligned dimensions and strides match the original layout.
- **TextureSurfaceLimits** — Surface validation enforces total dimensions <= 65500, sub-surface count <= 10, per-descriptor width/height factors within [1,4] and pixel format == 8; each failure is reported through the object vtable callback with a numeric code/detail/limit record and execution continues. A replacement must preserve the limits and the report-and-continue semantics.
- **ChunkedBlockHeaderLayout** — Allocated blocks carry a 16-byte header with the size field at +8 and the data offset at +4; the payload returned to callers is 16 bytes past the block base, and the free list is per-category with the head array based at this+0x4. A replacement must preserve the header layout, the +16 payload offset and the per-category free-list invariant.
- **VoiceSlotCapAndErrorRecord** — Audio voice negotiation caps the total voice-slot count at 10 and reports invalid modes or overflow through the vtable error record (obj+0x14 code / obj+0x18 detail / obj+0x1C limit). A replacement must keep the cap and the error-report path.

## Unresolved

- Every function's owning object type is UNKNOWN per the packet; DxtBlockCodec, HeapFreeListAllocator, AudioStreamAllocator, ObjectBufferPool and ScreenStateDispatchObject are GUESS groupings of shared call/field patterns, and only TextureSurfaceValidator is named by the packet (DERIVED).
- SafeDeleteGuardForThunkFUN00517ec8 (0x00513CD3) and ShortComputation_3d2f (0x00513D2F) are free cleanup/teardown helpers invoked by LargeStructPartialReset; their owning object is unknown, the 'safe-delete' semantics of thunk target 0x00517EC8 are name-derived only, and target 0x00517EC8 has no allowed evidence ref in this packet.
- The mapping from folded float literals (255.0, 0.5, 31.0, 63.0, 0.4375, 0.1875, 0.3125, 0.0625, 0.0039215689, 0.14285715, 0.2) to the many read-only globals flagged by the packet is not proven by any write site; the globals without an evidenced role are listed in unresolved_evidence_refs.
- The exact DXT variant (DXT1 vs DXT3/5) and the role of the a2+4 field (selector bitmask vs alpha data) in DxtBlockCompressor and DxtBlockDecompressor are inferred from the bit packing, not independently confirmed.
- The ABI lead name 'Texture_Filter_and_Layer_Compositing' conflicts with the concrete DXT/BC block-compression reading of 0x005147EA; the ABI name is carried by the packet with LEGACY trust only.
- Equal offsets on this+0x18/+0x1C/+0x10C/+0x110/+0x120/+0x124/+0x18C appear across TextureSurfaceValidator, AudioStreamAllocator and ObjectBufferPool; the packet does not prove these are the same object, so each class keeps its own field entries (rule 8).
- The opaque vtable error dispatcher (obj+0x0) and the allocator (this+0x4) targets are caller-supplied; their identities and side effects are unknown. The error slots obj+0x14/+0x18/+0x1C are interpreted as code/detail/limit from literal usage only.
- The 0x00515ECD dispatch sub-object is allocated with size 24 and initialized with the UIScreenStateMachine data pointer plus three function pointers (VtableDelegateDispatch, SetupArithmeticComparison, VtableFunctionPointerWrite); the semantics of these pointers and of the dispatch result copied into *(this+0x18C) are not established.
- AlignUp (0x00515927) has no guard for a2 == 0, and the byte-count vs alignment-unit argument semantics are unverified; the UI/playback/audio caller names come from the ABI lead and are unconfirmed.
- The coefficient-table pairs used by ColorQuantization and OBBFittingAndProjection (globals 0x005AF56C..0x005AF60C) have unknown numeric meaning; the quantization interpretation of the vertex projection is DERIVED, not stated by the packet.
- In OBBFittingAndProjection the max-bound output (a2, float3) is written in the raw source but has no packet field evidence; only the min-bound writes map to this+0x0/+0x4/+0x8, and the FPU compare-flag locals are uninitialized in the Hex-Rays listing.
- Loop-counter v16 initialization in QuantizationColorSpaceConversion is not visible (loaded from register v3), and the MSB-first nibble ordering is DERIVED from the shift/pack expression; control-flow confidence is MEDIUM there.
- Field this+0x16C is flagged by the packet but referenced by no reconstructed body; it may belong to a following stream slot or a neighboring member and is carried in unresolved_evidence_refs.
- Whether the descriptor stride fields at +0x28/+0x2C are byte or pixel strides, and the per-descriptor width-factor range check (referenced in source but without a packet field ref for +0x8), are unresolved.
- InitProcessWrapper (0x005158E3) buffers a matrix in a 64-float local and delegates to the encoder pipeline; the scalar a1 role and the exact transform are not established by this packet.
