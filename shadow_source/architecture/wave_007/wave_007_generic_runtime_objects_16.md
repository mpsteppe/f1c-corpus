# GenericRuntimeObjectUtilities

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Thirty generic runtime-object functions cluster into a small set of defensible groups. Six functions (BitPackingUnpacking, BitExpandDecompress, PixelFormatExpansion, DecodeBlockCompressedPixels, BitmapDecompression, PixelFormatTo8BitIndexed) all read and write the same format-state byte layout (dword element count at this+0, dword computed byte count at this+4, byte format/phase at this+8, byte bit-depth/state at this+9, byte stride/multiplier at this+0xA, byte output stride at this+0xB) and share the single caller sub_51389E; they form one multi-phase pixel/bit decode state machine. A second cluster decompresses block-compressed texture data (DecompressDxt5AlphaBlock, Bc4Bc5AlphaBlockDecompressor) writing float4 alpha slots (this+0xC, this+0x8C), wrapped by two load-and-clamp validators (FileOpenAndValidate, FileOpenAndValidate_51588C) that share the float4 batch clamp BatchClampToMax. Gated setters guard all writes on two non-null pointers (FlagSetterFloatStore, ByteFlagSetterWithGuard, SetFlagPairWithFloatConstant share one target object via the wrapper; FlagSetterWithGuard and MultiFieldSetterWithFlag show the same gating shape on unproven targets). The remainder are standalone helpers: PNG image descriptor setup, null-guarded callback dispatch, zeroed allocation, CRC32 handle id, RGB565-to-float4 decode, global control-word store, matrix/quantization wrappers, ceiling division, scaled block copy, memset wrapper, UI state-machine vtable binding, and allocated-node factory/insertion. All proposals are DERIVED or GUESS; common object ownership across clustered functions is inferred, not packet-proven.

## Function roles

- `0x005125C9` **PixelDecodeState** — Unpacks bit-packed elements (1/2/4-bit depths read from this+0x9) from an input buffer into per-element bytes, then refreshes decode metadata (state to 8, stride 8*multiplier, byte count count*multiplier) on the decode state object.
- `0x00512850` **PixelDecodeState** — One deinterleave step of the bit-expansion state machine: when state byte this+0x9 is 16, deinterleaves the input buffer by factor 2 into contiguous samples, then advances state to 8 and updates output-stride (this+0xB) and byte-count (this+0x4) metadata.
- `0x00512894` **PixelDecodeState** — In-place pixel-format expansion step selected by base-format byte this+0x8 (0 or 2) and bit-depth state byte this+0x9 (8 or 16), expanding the pixel buffer to the next byte-per-pixel width and writing back stride/bytes-per-pixel/expanded count.
- `0x00512ACC` **PixelDecodeState** — Block-compressed pixel decoder: palettized table copies and 16-bit lookups dispatched by format byte this+0x8 and bit-depth byte this+0x9, walking the destination buffer and advancing the result pointer as decode loops consume it.
- `0x00513022` **PixelDecodeState** — Multi-phase bitmap decompressor: phase 0 bit-unpacking (1/2/4-bit) with optional chroma-key pass, phase 2 direct chroma-key conversion; writes completion markers (this+0x8 = 4 or 6) and updates bytes-per-pixel/stride/count metadata.
- `0x00513374` **PixelDecodeState** — Pixel format converter to 8-bit indexed: 15-bit-LUT conversion paths for formats 2 and 6, index remap for format 3; on the LUT paths updates stride (this+0xB), format (this+0x8), bytes-per-pixel (this+0xA) and byte count (this+0x4).
- `0x00513A56` **GatedFlagSetterPair** — Gated single-precision store: when both guard a1 and target a2 are non-null, ORs bit 1 into the dword at a2+8 and stores the float conversion of double a3 at a2+40.
- `0x00513A71` **PngImageInfo** — Populates a PNG-style image descriptor from scalar args (width/height/bit-depth/color-type/flag bytes, row factor, rowbytes); dispatches the aWidthTooLargeT error string via CallbackDispatch and stores rowbytes 0 when width overflows row-size arithmetic.
- `0x00513B12` **GatedObjectSetter** — Gated flag-and-value setter: ORs bit 8 into the dword at a2+8, stores a3 at a2+16 and the 16-bit a4 at a2+20 when a1 and a2 are both non-null.
- `0x00513B36` **GatedFlagSetterPair** — Gated byte-flag setter: ORs the value 8 into the byte at a2+9 and stores the byte a3 at a2+44 when a1 and a2 are both non-null.
- `0x00513B51` **GatedFlagSetterPair** — Gated dual-flag wrapper: when a1 is non-null and the low dword of the packed 64-bit a2 is non-zero, calls ByteFlagSetterWithGuard_3b36(a1, a2, SBYTE4(a2)) then FlagSetterFloatStore(a1, a2, 0.4545499980449677) with the constant from dbl_5AF4C8.
- `0x00513B8A` **GatedObjectSetter** — Gated multi-field setter: conditional dword store at a2+48, 12-byte structure copy from a5 into a2+52..+60 with a4 defaulted to 1, then OR bit 0x10 into the dword at a2+8 and store a4 at a2+22.
- `0x00513BD1` **CallbackDispatcher** — Null-guarded callback dispatch: invokes the callback stored at this+0x50 with forwarded (a1, a2, a3) when non-null; when null routes through GuardedCallWithLongjmp with the 'Call to NULL read function' string (global 0x5AF4D0).
- `0x00513C80` **MemoryAllocationUtilities** — Allocates a3*a2 bytes via sub_517E92 and zero-fills the entire region (split into 0x8000-byte chunks for large sizes); returns the zeroed buffer pointer or NULL on allocation failure.
- `0x00513CD8` **MemoryAllocationUtilities** — Computes a CRC32 value via CRC32Computation(0, 0, 0) and stores it into the animation-handle identifier field at this+0x100, returning the computed value.
- `0x00513D63` **ColorFloat4Utilities** — Decodes one 16-bit RGB 5:6:5 color into four floats: R/B scaled by 0.032258064 (flt_5ACCD4), G scaled by 0.015873017 (flt_5ACCDC), alpha forced to 1.0.
- `0x00513DAF` **ColorFloat4Utilities** — Batch loop over 16 float4 elements: the fourth float (this+0xC) gates zeroing (==0), scaling by 1/alpha clamped to 1.0 (0<alpha<1), or no-op (>=1); returns constant 0.
- `0x00513E5D` **GenericUtilities** — Writes a value (an uninitialized stack local v1 in the raw source; legacy ABI lead names it a merged FPU control word / caller-supplied parameter) into global dword_8B00A0 and returns the same value.
- `0x0051512C` **TextureBlockDecoder** — DXT5/BC3-style block decoder: delegates the colour half to KeyframeQuadInterpolationWithBitPackedSelector (0x514FEE), then unpacks 16 4-bit alpha nibbles scaled by 0.06666667 (flt_5AC108) into float4 alpha slots this+0xC and this+0x8C.
- `0x005151AF` **TextureBlockDecoder** — BC4/BC5-style alpha block decoder: builds an 8-entry float alpha palette from two reference bytes (5- or 7-step interpolation), then unpacks two 24-bit 3-bit selectors into the A slot of 8+8 float4 texels at this+0xC and this+0x8C.
- `0x005152EB` **TexturePipelineWrappers** — Cdecl wrapper: calls TextureFilterAndLayerCompositing(a2, a1, 1) and returns 0 on a non-negative result, otherwise propagates the negative result unchanged.
- `0x00515869` **TextureSurfaceLoader** — Open/parse-then-clamp validator: calls DecompressDxt5AlphaBlock (0x51512C) and only if it succeeds calls BatchClampToMax (0x513DAF); returns 0 when both succeed else propagates the first negative status.
- `0x0051588C` **TextureSurfaceLoader** — Validate-and-clamp wrapper: calls Bc4Bc5AlphaBlockDecompressor (0x5151AF) and only if it succeeds calls BatchClampToMax (0x513DAF); returns 0 when both succeed else propagates the first negative status. Name inferred from the identical control-flow skeleton of a sibling, not from packet evidence.
- `0x005158AF` **TexturePipelineWrappers** — Two-stage conversion delegator: runs MatrixScaleByW (0x513E2D) into a 64-float scratch buffer, then QuantizationColorSpaceConversion (0x515303) on the caller DWORD array; returns 0 when both succeed else the first negative error.
- `0x00515917` **GenericUtilities** — Ceiling integer division (a1 + a2 - 1) / a2; pure arithmetic helper shared by TextureSurfaceValidator, AudioVoiceChannelAllocation and sub_516A1D for size/stride and channel-count rounding.
- `0x00515986` **GenericUtilities** — Copies a3 << 7 bytes (a3 * 128) from a1 into a2 via qmemcpy and returns the byte count; single caller is an audio subband synthesis filterbank.
- `0x005159A8` **GenericUtilities** — Zero-fills a2 bytes at a1 via memset and returns constant 0; used across ring-buffer, offset-validation, compositing, checksum, convolution and codec-mode paths.
- `0x00515EBC` **UIScreenStateMachineBinder** — Reads the sub-object pointer at this+0x18C, writes the global UIScreenStateMachine pointer (0x515DF2) into that sub-object's first dword, and returns the sub-object pointer.
- `0x00515F0E` **AllocatedObjectFactory** — Initializes a freshly allocated sub-object: writes constant 53 to obj+0x14, caller parameter a2 to obj+0x18, then dispatches virtual slot 0 through a1's vtable; called by both allocator paths.
- `0x005161DD` **AllocatedObjectFactory** — Allocates a 0x78-byte list node via MemoryAllocator (0x515F23), initializes it (type byte a3, data a4/a5/a6) and prepends it to the singly-linked list anchored at this+0x44; non-default category a2 triggers a constant-12 init and a virtual dispatch first.

## Proposed classes

### PixelDecodeState

Multi-phase pixel/bit decode state machine: bit unpacking, deinterleave expansion, in-place pixel-format expansion, block-compressed pixel decoding, multi-phase bitmap decompression and 8-bit-index conversion, all driven by the shared format-state byte layout and the single caller sub_51389E.

Methods: `0x005125C9`, `0x00512850`, `0x00512894`, `0x00512ACC`, `0x00513022`, `0x00513374`

- `this+0x00000000` `dword element_count` (read, DERIVED)
- `this+0x00000004` `dword computed_byte_count` (read_write, DERIVED)
- `this+0x00000008` `byte format_or_phase` (read_write, DERIVED)
- `this+0x00000009` `byte bit_depth_or_state` (read_write, DERIVED)
- `this+0x0000000A` `byte stride_or_multiplier` (read_write, DERIVED)
- `this+0x0000000B` `byte output_stride` (read_write, DERIVED)

### GatedFlagSetterPair

Gated flag-and-value setters whose target object is shared: SetFlagPairWithFloatConstant passes the same a2 into both ByteFlagSetterWithGuard and FlagSetterFloatStore, proving common ownership of the target object. The target-object layout (flag dword at a2+0x08, flag byte at a2+0x09, float at a2+0x28) is observed in the function IR but is not declared as class fields because the packet provides no field evidence refs for the a2 base.

Methods: `0x00513A56`, `0x00513B36`, `0x00513B51`


### GatedObjectSetter

Gated field setters with the same guard-and-write shape as GatedFlagSetterPair (both a1 and a2 non-null, OR a flag bit into a2+0x08, store a value) but whose target-object identity is not proven shared with the pair cluster. Observed target offsets (a2+0x08 flag dword, a2+0x10 dword, a2+0x14 word, a2+0x16 word, a2+0x30 dword, a2+0x34 dword, a2+0x38 dword, a2+0x3C word) are not declared as class fields because the packet provides no field evidence refs for the a2 base.

Methods: `0x00513B12`, `0x00513B8A`


### PngImageInfo

PNG-style image-descriptor setup: populates width/height/bit-depth/color-type/flag bytes, derives a row factor and rowbytes, and dispatches the aWidthTooLargeT error string when row-size arithmetic would overflow. The descriptor layout (a2+0x00 width, a2+0x04 height, a2+0x0C rowbytes, a2+0x18 bit depth, a2+0x19 color type, a2+0x1A..0x1C flag bytes, a2+0x1D row factor, a2+0x1E scaled bit depth) is observed in the IR but not declared as class fields because the packet provides no field evidence refs for the descriptor base.

Methods: `0x00513A71`


### CallbackDispatcher

Null-guarded read callback dispatch: invokes the callback stored at this+0x50 with the original arguments, and routes through the guarded longjmp error path when the callback is null.

Methods: `0x00513BD1`

- `this+0x00000050` `pointer callback_function_pointer` (read, DERIVED)

### MemoryAllocationUtilities

Memory allocation and handle-identifier helpers: zero-filled allocation through the allocator sub_517E92, and CRC32-based animation handle identifier derivation.

Methods: `0x00513C80`, `0x00513CD8`

- `this+0x00000100` `dword animation_handle_identifier` (write, DERIVED)

### ColorFloat4Utilities

Float4 (RGBA) color data helpers: 16-bit RGB565 decode into four floats and batch alpha-divide-with-clamp over a 16-element float4 array.

Methods: `0x00513D63`, `0x00513DAF`

- `this+0x00000000` `float red_channel` (read_write, DERIVED)
- `this+0x00000004` `float green_channel` (read_write, DERIVED)
- `this+0x00000008` `float blue_channel` (read_write, DERIVED)
- `this+0x0000000C` `float alpha_channel` (read_write, DERIVED)

### TextureBlockDecoder

Block-compressed texture decoders: DXT5/BC3-style and BC4/BC5-style alpha-block decompression, both delegating the colour half to KeyframeQuadInterpolationWithBitPackedSelector and writing float4 alpha slots at this+0xC and this+0x8C.

Methods: `0x0051512C`, `0x005151AF`

- `this+0x0000000C` `float texel_alpha_slot_first_half` (write, DERIVED)
- `this+0x0000008C` `float texel_alpha_slot_second_half` (write, DERIVED)

### TextureSurfaceLoader

Texture surface load-and-clamp validators: each opens/parses a block via a TextureBlockDecoder method and then clamps the resulting float buffer with BatchClampToMax, returning 0 only when every stage succeeds.

Methods: `0x00515869`, `0x0051588C`


### TexturePipelineWrappers

Thin cdecl delegators over texture pipeline stages: the filter-and-layer-compositing wrapper and the matrix-scale-plus-quantization color conversion delegator, both normalizing non-negative callee results to 0 and propagating negative status.

Methods: `0x005152EB`, `0x005158AF`


### GenericUtilities

Low-level arithmetic and memory helpers with no instance state: global control-word store, ceiling integer division, scaled memory block copy and zero-fill wrapper.

Methods: `0x00513E5D`, `0x00515917`, `0x00515986`, `0x005159A8`


### UIScreenStateMachineBinder

Binds the global UIScreenStateMachine pointer into the first dword of the sub-object referenced at this+0x18C, returning that sub-object.

Methods: `0x00515EBC`

- `this+0x0000018C` `pointer subobject_ptr` (read, DERIVED)
- `*(this+0x18C)+0x00000000` `dword bound_vtable_slot0` (write, DERIVED)

### AllocatedObjectFactory

Allocated-object initialization and node insertion: writes type-tag/category into obj+0x14/+0x18 and dispatches a virtual slot, and allocates/links 0x78-byte nodes into a singly-linked list anchored at this+0x44.

Methods: `0x00515F0E`, `0x005161DD`

- `obj+0x00000000` `dword subobject_vtable_or_type` (read, DERIVED)
- `obj+0x00000014` `dword type_tag_constant` (write, DERIVED)
- `obj+0x00000018` `dword category_or_parameter` (write, DERIVED)
- `this+0x00000044` `pointer list_head_anchor` (read_write, DERIVED)

## Compatibility contracts

- **PixelDecodeStateFieldLayout** — A replacement must preserve the format-state object layout used by all six decode functions: dword element count at +0x0, dword computed byte count at +0x4, byte format/phase at +0x8, byte bit-depth/state at +0x9, byte stride/multiplier at +0xA and byte output stride at +0xB. State bytes are advanced only when the phase guard allows (bit depths 1/2/4 normalize to 8; 16 normalizes to 8 via deinterleave; phases advance to 4/6 completion markers).
- **ChainedStatusCallContract** — Stage functions in the texture pipeline return 0 on success and a negative status code on failure; wrappers and load-and-clamp validators short-circuit on the first negative result and propagate it unchanged, returning 0 only when every chained stage succeeded.
- **CallbackNullGuardErrorString** — Dispatching a null callback must route through the guarded error path with the message global 0x5AF4D0 ('Call to NULL read function') rather than calling through a null pointer.
- **ZeroedAllocationContract** — AllocateZeroed returns a fully zeroed buffer of a3*a2 bytes, or NULL when the allocation fails; buffers larger than 0x8000 bytes are still zeroed in full (split into two memset calls covering the whole region).
- **GatedSetterNullContract** — Gated field setters perform no writes when either the guard argument or the target object is null; when both are non-null they OR a flag bit and store the value into the target object.

## Unresolved

- Common ownership of the PixelDecodeState object across the six decode functions is inferred from a shared byte layout and the single caller sub_51389E, not proven by the packet; equal offsets on distinct `this` bases must not be treated as identical fields without runtime evidence.
- SetFlagPairWithFloatConstant's a2 is described as a packed 64-bit flag/value yet is passed as the target object pointer to ByteFlagSetterWithGuard and FlagSetterFloatStore; the object identity and the SBYTE4(a2) guard-byte semantics are unresolved.
- Identity of the a2 target objects is unproven across the gated setter cluster; only the {ByteFlagSetterWithGuard, FlagSetterFloatStore} pair is shown to share one a2 via SetFlagPairWithFloatConstant.
- Globals flt_59E460, flt_59E7E8, flt_5AD210 and flt_5ADB14 are listed by packet facts for Bc4Bc5AlphaBlockDecompressor but appear nowhere in its raw source (inline literals 0.0039215689/0.2/0.14285715 used instead); the globals cannot be tied to those constants from this packet alone. flt_5ADB14 is likewise absent from DecompressDxt5AlphaBlock's raw source.
- MergeFPUControlWordWithParamIntoGlobal's input value v1 is an uninitialized local in the decompiled body; the value stored into global dword_8B00A0 and the FPU-control-word mechanism are unresolved.
- Format selector values (this+0x8 in {0, 2, 4, 6}) and bit-depth values (this+0x9 in {1, 2, 4, 8, 16}) are DERIVED from switch structure, not independently confirmed as channel layouts.
- PixelFormatTo8BitIndexed's remap path (format 3) does not update the state fields the LUT paths write; the 5-byte-per-pixel layout of the format-6 path is not resolved.
- setupPngImageInfo flag-byte semantics (a6/a7/a8/a9) and the row-factor derivation are unresolved; the row-factor field naming is GUESS.
- BatchClampToMax's un-premultiply-alpha-with-clamp interpretation and its constant 0 return are DERIVED readings of the numeric operations, not packet-declared facts.
- Meaning of the phase values 4 and 6 in BitmapDecompression beyond completion-marker writes is not established; reachability of its sub-state 16 paths through normal flow is unclear because the unpacking phase sets sub-state to 8.
- The sub-object virtual callback dispatched at obj+0x0 in the AllocatedObjectFactory paths is unidentified; the 0x78-byte list node field layout in LinkedListNodeAllocAndInsert has no named semantics in the packet.
- LinkedListNodeAllocAndInsert writes the list head through (v6 + 64) where v6 = this+0x4, while packet facts name this+0x44 as the anchor; the equivalence of the two views is not proven here.
- AnimationHandleAlloc's zero-initialized CRC32Computation(0, 0, 0) call and the meaning of the this+0x100 handle field are interpretations; the object owning this+0x100 is unidentified.
- The exact byte-interleave pattern of each PixelFormatExpansion branch and the tail-write variant selected by its a4 sign flag are not fully resolved from source:raw.
- GatedFlagSetterPair target-object field layout is observed in the function IR (flag dword at a2+0x08, flag byte at a2+0x09, float at a2+0x28) but cannot be declared as class fields: the packet provides no field evidence refs for the a2 base, so any declared field would be an invented evidence reference.
- GatedObjectSetter target-object offsets (a2+0x08 flag dword, a2+0x10 dword, a2+0x14 word, a2+0x16 word, a2+0x30 dword, a2+0x34 dword, a2+0x38 dword, a2+0x3C word) are observed in the function IR but are not declared as class fields for the same reason: no a2-base field evidence refs exist in the packet.
- PngImageInfo descriptor layout (width a2+0x00, height a2+0x04, rowbytes a2+0x0C, bit depth a2+0x18, color type a2+0x19, flag bytes a2+0x1A..0x1C, row factor a2+0x1D, scaled bit depth a2+0x1E) is observed in the function IR but not declared as class fields; the packet carries no field evidence refs for the descriptor base.
