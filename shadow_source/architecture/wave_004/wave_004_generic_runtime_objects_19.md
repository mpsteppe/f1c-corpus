# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

DERIVED proposal for the generic_runtime_objects scope. Four families are proposed: (1) AudioStateInterpolator clusters the frame-path audio/physics interpolation math (cubic Hermite spline evaluation, packed short-quantized state interpolation with Euler rotation and 2048.0 re-quantization, and the sentinel-based field-initialized check against flt_5AD348); (2) InterpolationCoordinateTableBuilder allocates and fills the 16-byte-per-entry bilinear coordinate tables used by vertex stage transformation; (3) GenericRuntimeHelpers provides the strided per-element callback dispatcher and the flag-driven conditional container free; (4) the pixel-surface family models a PixelSurface object (pixel base +0x18, dimension/pitch/stride/count fields at +0x1030..+0x1064) and a SurfaceBlendContext holding source/destination surface pointers, whose methods implement DXT block copy and ten per-format 16/8-bit blend or 2:1 downscale passes (several dispatched as switch cases by COMInterfaceVectorProcessingMethod). Finally DirectXTextureObject groups the destructor-teardown helper and six constructor entry points that all delegate to DirectXTextureCreationWithMipmapChain(this, a2, size, 1) before installing a class vtable. Ownership of every function is UNKNOWN in the packet; class membership here is DERIVED grouping, not confirmed. Equal surface-field offsets recorded under the different extractor bases (obj+0x18 vs this+0x1C, obj+0x1050 vs this+0x1054) are treated as dual-recorded reads of the destination surface, not as independent fields.

## Function roles

- `0x004FF3A0` **AudioStateInterpolator** — Cubic Hermite (Catmull-Rom style) 3D spline interpolation between endpoints a1/a3 with normalized tangent vectors a2/a4, writing the blended float[3] to the output buffer a6; degenerate cases (zero distance, t==0, t==1) copy an endpoint verbatim.
- `0x004FF680` **AudioStateInterpolator** — Interpolates a packed short-quantized audio/physics parameter state between frames: clamps the delta to [-1.25, 1.25], unpacks position and rate fields, applies Euler rotation (EulerToRotationMatrix, sub_567120) and a gravity term, re-quantizes to 16-bit with scale 2048.0, copies the trailing packed fields and returns 1.
- `0x005001D0` **AudioStateInterpolator** — Shared field-initialized check: returns TRUE when the float field at this+0x1BC differs from the sentinel -9.9999997e37 (flt_5AD348, 0x005AD348), FALSE while it still holds the sentinel. Called by eight per-frame callers including the audio cross-fade path.
- `0x005008C2` **GenericRuntimeHelpers** — Generic strided per-element callback loop: invokes the thiscall callback a4 a3 times, advancing the element pointer a1 by the stride a2 each pass, and returns the last call's result (or a3-1 when the count guard rejects the loop).
- `0x00502EE5` **GenericRuntimeHelpers** — Flag-driven container deallocation dispatcher: flag bit 2 selects the element-array path (NTimeCallbackLoopWithSEH with the FreeWrapper callback 0x00502C1F over the header at this-1, then optionally freeing that header when bit 1 is set), otherwise the first data element at this[0] is freed directly (optionally freeing the block this when bit 1 is set).
- `0x005033A5` **SurfaceBlendContext** — DXT-compressed texture block blit: validates 4-byte alignment of both surfaces, dispatches on the destination pixel-format tag at this+4 (8-byte blocks for 827611204, 16-byte blocks for the DXT3/4/5-style tags 844388420/861165636/877942852/894720068), then copies block rows via qmemcpy; returns 0 on success and -2147467259 on any validation failure.
- `0x00503920` **SurfaceBlendContext** — Downsampling helper averaging each 2x2 block of 16-bit RGB565 source pixels into one destination pixel (mask 0xF81F / 0x7E0, rounding 4098 / 64, shift-right 2); always returns 0.
- `0x00503A70` **SurfaceBlendContext** — Structural twin of 0x00503920 for 16-bit RGB555 source pixels (mask 0x7C1F / 0x3E0, rounding 2050 / 64, shift-right 2); always returns 0.
- `0x00503B94` **SurfaceBlendContext** — Format-25 surface compositing handler: averages each 2x2 16-bit pixel block (two pixels from each of two adjacent source rows) into one destination pixel with masks 0x83E0 / 0x7C1F and rounding 65600 / 2050; 2:1 downscale; always returns 0.
- `0x00503CE3` **SurfaceBlendContext** — Format-26 handler: full-resolution adjacent-row bitplane blend that slides a one-pixel 16-bit window over each row pair with masks 0xF0F0 / 0xF0F and rounding 8224 / 514; always returns 0.
- `0x00503E36` **SurfaceBlendContext** — Format-27 handler: 2x2 box average of 8-bit source pixels (masks 0xE3 / 0x1C, rounding 66 / 8) into one 8-bit destination byte; 2:1 downscale; always returns 0.
- `0x00503F75` **SurfaceBlendContext** — 2x2 box downscale over an 8-bit byte-plane: writes one output byte per 2x2 source block as (a+b+c+d+2)>>2; source advances two rows per output row; always returns 0.
- `0x00504010` **SurfaceBlendContext** — Weighted-average combine of two 16-bit source rows into one destination row (masks 0xE3 / 0xFF1C, rounding 66 / 520, shift-right 2); source and destination each advance one row; always returns 0.
- `0x0050415C` **SurfaceBlendContext** — Structural twin of 0x00503920: 16-bit two-row blend (masks 0xF0F / 0xFFFF00F0, rounding 32 / 514, OR combine); source and destination each advance one row; always returns 0.
- `0x0050427D` **SurfaceBlendContext** — Case-51 compositing handler: 2x2 average of 16-bit surface pixels with byte-channel separation (masks 0xFFFF00FF / 0xFF00, rounding 2 / 512) and XOR combine; always returns 0.
- `0x005043C9` **SurfaceBlendContext** — Case-52 compositing handler: 2x2 average of 8-bit surface pixels with nibble separation (masks 0xF0 / 0xF, rounding 32 / 2) and XOR-dither combine; source advances two row strides per output row; always returns 0.
- `0x005053EC` **InterpolationCoordinateTableBuilder** — Allocates a 16-byte-per-entry bilinear interpolation coordinate table (16*a1 bytes via OperatorNewNhMallocWrapper) and fills each entry with the two adjacent source indices and the two blend weights; fractional coordinate v6 = v15*(a2/a1)-0.5 is transformed by sub_5895A2, with edge clamping/wrapping depending on flag a3.
- `0x00506CCC` **DirectXTextureObject** — Destructor-teardown helper: saves the child/payload pointer at this+0x104C, swaps the object vtable to off_5ADB80, frees the saved child via FreeWrapper_7bcf and returns that function's result.
- `0x0050A7C5` **DirectXTextureObject** — Constructor: delegates to DirectXTextureCreationWithMipmapChain(this, a2, 0x18, 1) for base initialization, installs the vtable off_5ADBA8 at offset 0x0 and returns this.
- `0x0050A8D9` **DirectXTextureObject** — Unconditional texture-object constructor: base init via DirectXTextureCreationWithMipmapChain(this, a2, 0x20, 1), then vtable off_5ADBC8 at this+0x0; returns this.
- `0x0050A8F5` **DirectXTextureObject** — Constructor: base init via DirectXTextureCreationWithMipmapChain(this, a2, 0x20, 1), then vtable off_5ADBD8 at offset 0x0; returns this.
- `0x0050A911` **DirectXTextureObject** — Constructor: base init via DirectXTextureCreationWithMipmapChain(this, a2, 0x10, 1), then vtable off_5ADBE8 at this+0x0; returns this.
- `0x0050AB19` **DirectXTextureObject** — Constructor: base init via DirectXTextureCreationWithMipmapChain(this, a2, 0x10, 1), then vtable off_5ADC18 at this+0x0; returns this.

## Proposed classes

### AudioStateInterpolator

Frame-path interpolation of packed short-quantized audio/physics parameter state: cubic Hermite spline evaluation, Euler-rotated re-quantization with gravity, and sentinel-based field-initialized checks.

Methods: `0x004FF3A0`, `0x004FF680`, `0x005001D0`

- `this+0x00000000` `float output_point_x` (write, UNKNOWN)
- `this+0x00000004` `float output_point_y` (write, UNKNOWN)
- `this+0x00000008` `float output_point_z` (write, UNKNOWN)
- `this+0x000001BC` `float field_set_sentinel_checked` (read, DERIVED)

### InterpolationCoordinateTableBuilder

Builds the 16-byte-per-entry bilinear interpolation coordinate tables (two adjacent source indices plus two blend weights) used during vertex stage transformation.

Methods: `0x005053EC`


### GenericRuntimeHelpers

Shared generic container/runtime helpers: strided per-element callback dispatch and flag-driven conditional container deallocation.

Methods: `0x005008C2`, `0x00502EE5`

- `this+0x00000000` `void* first_data_element` (read, DERIVED)

### PixelSurface

The pixel surface object read by the DXT block copy and the blend family: pixel data base at +0x18, surface width/height and row/slice pitches at +0x1030..+0x103C, row offset +0x1040, row stride +0x1050, vertical stride +0x1054, row width +0x1058 and row count +0x105C; pixel elements are 8-bit or 16-bit values inside the pixel buffer.

Methods: 

- `obj+0x00000018` `void* pixel_data_base` (read, DERIVED)
- `obj+0x00001030` `dword surface_width` (read, DERIVED)
- `obj+0x00001034` `dword surface_height` (read, DERIVED)
- `obj+0x00001038` `dword row_pitch` (read, DERIVED)
- `obj+0x0000103C` `dword slice_pitch` (read, DERIVED)
- `obj+0x00001040` `dword row_offset` (read, DERIVED)
- `obj+0x00001050` `dword row_stride` (read, DERIVED)
- `obj+0x00001054` `dword vertical_stride` (read, DERIVED)
- `obj+0x00001058` `dword row_width` (read, DERIVED)
- `obj+0x0000105C` `dword row_count` (read, DERIVED)
- `*(obj+0x18)+0x00000000` `word pixel_element_first` (read, DERIVED)
- `*(obj+0x18)+0x00000001` `byte pixel_element_second_byte` (read, DERIVED)
- `*(obj+0x18)+0x00000002` `word pixel_element_second_word` (read, DERIVED)

### SurfaceBlendContext

The blend/dispatch context holding the source and destination surface pointers at this+0x0 / this+0x4. Each member function implements one pixel-format surface compose/blend/downscale pass; the format-handler members are dispatched as switch cases by COMInterfaceVectorProcessingMethod (0x00504B37).

Methods: `0x005033A5`, `0x00503920`, `0x00503A70`, `0x00503B94`, `0x00503CE3`, `0x00503E36`, `0x00503F75`, `0x00504010`, `0x0050415C`, `0x0050427D`, `0x005043C9`

- `this+0x00000000` `PixelSurface* source_surface` (read, DERIVED)
- `this+0x00000004` `PixelSurface* destination_surface` (read, DERIVED)
- `this+0x0000001C` `void* destination_pixel_data_base` (read, UNKNOWN)
- `this+0x00001054` `dword destination_row_stride` (read, UNKNOWN)

### DirectXTextureObject

DirectX texture-surface object lifecycle: six constructor entry points delegate to DirectXTextureCreationWithMipmapChain(this, a2, size, 1) then install a class vtable at offset 0x0; the teardown helper swaps the vtable to off_5ADB80 and frees the child payload at this+0x104C. The distinct installed vtables imply unresolved subclasses.

Methods: `0x00506CCC`, `0x0050A7C5`, `0x0050A8D9`, `0x0050A8F5`, `0x0050A911`, `0x0050AB19`

- `this+0x00000000` `void* vtable_ptr` (write, DERIVED)
- `this+0x0000104C` `void* child_payload_ptr` (read, DERIVED)

## Compatibility contracts

- **AudioParameterStatePackedLayout** — The packed state interpolated by 0x004FF680 has a fixed layout: header dword at +0x0, last-frame time float at +0x4, trailing header dword at +428, short-quantized position components at +20/+22/+24, byte rate fields at +44/+45/+46, and trailing packed fields through +56; the interpolation delta is clamped to [-1.25, 1.25] and re-quantization uses scale 2048.0.
- **UninitializedSentinelFieldCheck** — The float field at this+0x1BC is considered unset while it equals the sentinel -9.9999997e37 held in flt_5AD348 (0x005AD348); the shared check returns TRUE only when the field differs from the sentinel.
- **PixelSurfaceGeometryLayout** — Pixel surfaces expose pixel data base at +0x18, width +0x1030, height +0x1034, row/slice pitches +0x1038/+0x103C, row offset +0x1040, row stride +0x1050, vertical stride +0x1054, row width +0x1058 and row count +0x105C; the blend and DXT passes rely on these for row bounds and cursor advancement.
- **DXTBlockCopyReturnContract** — The DXT block blit returns 0 on success and HRESULT error -2147467259 (0x80004005) when either surface fails the 4-byte alignment check or the destination pixel-format tag is not an 8-byte (827611204) or 16-byte (844388420, 861165636, 877942852, 894720068) block format.
- **FormatHandlerZeroReturn** — Surface format-handler compose passes (formats 25, 26, 27 and cases 51, 52) always return 0 and have no error path; the 2:1 downscale variants advance the source two row strides per destination row.
- **ConditionalFreeFlagSemantics** — Container deallocation flag bits in 0x00502EE5: bit 2 selects element-array mode (each element freed via the FreeWrapper callback at 0x00502C1F under SEH over the header at this-1), bit 1 frees the container block itself; with bit 2 clear the first data element at this[0] is freed directly and bit 1 additionally frees the container block this.

## Unresolved

- HermiteSplineInterpolate: the packet labels the three output dword writes with base "this" (offsets 0x0/0x4/0x8) but the function is __fastcall with an explicit output parameter a6, so the "this" base is a packet labeling artifact; the fields are listed under AudioStateInterpolator with UNKNOWN trust for evidence completeness.
- HermiteSplineInterpolate: seven float globals (0x0059E43C, 0x0059E440, 0x0059E450, 0x0059E46C, 0x0059E478, 0x0059E7EC, 0x0059E800) are listed by IDB facts as read but do not appear in the raw source, whose basis math uses only literals; roles unconfirmed.
- HermiteSplineInterpolate: tangents a2/a4 are normalized in place, mutating caller buffers; whether the caller relies on this side effect is not evidenced.
- HermiteSplineInterpolate: the Catmull-Rom reading (as opposed to general Hermite) depends on the caller's tangent construction in AudioSampleCrossFadeInterpolation, which is not in this packet.
- AudioParameterInterpolation: ten globals (0x0059E448, 0x0059E4E8, 0x0059E714, 0x0059E77C, 0x0059E8B4, 0x0059ED50, 0x0059F0C0, 0x005ACCB0, 0x005AD350, 0x005AD354) are not referenced in the raw source; roles unverified.
- AudioParameterInterpolation: the exact element types and layout of the packed state at a2/a3 offsets 8..56 are inferred from decompiled reads and not independently confirmed; semantics of sub_567120 are inferred, not verified.
- FieldCompareConstant: the purpose of field this+0x1BC is caller-specific; the function is called by both audio and collision paths, so its placement on AudioStateInterpolator is a DERIVED grouping rather than a confirmed class membership.
- CallPerElementWithStride: the callback a4 and the object layout behind the strided elements are caller-specific; the thiscall convention implies an implicit this in ecx whose correspondence to the a1 pointer is not shown here; caller names are prelabel labels.
- ConditionalFreeWithFlag: the literal 12 passed to NTimeCallbackLoopWithSEH (element size, stride or count encoding) is unexplained; the container header layout at this-1 is not established; the two container shapes selected by bit 2 are unconfirmed.
- DXTCompressedTextureBlockCopy: the pixel-format tag values are treated as opaque DXT-family identifiers; the DXT1/3/4/5 correspondence is inferred from the 8/16-byte block split; the destination row-stride read has no matching field evidence reference; fields this+0x08, this+0x1C, this+0x1044 and this+0x1064 are listed by extraction but not visible as distinct reads in the raw decompilation.
- Pixel-surface blend family: the pixel-format identifications (RGB565 for 0x00503920, RGB555 for 0x00503A70, RGB332 for 0x00503E36, bitplane for 0x00503CE3, and the byte/nibble channel layouts for 0x0050427D / 0x005043C9) are DERIVED from the channel masks and rounding constants, not independently confirmed.
- Pixel-surface blend family: the extractor dual-records the destination surface accesses (obj+0x18 vs this+0x1C, obj+0x1050 vs this+0x1054); these are treated as the same destination surface read through the context at this+0x4, and fields this+0x1C and this+0x1054 are listed on SurfaceBlendContext with UNKNOWN trust.
- Pixel-surface blend family: fields this+0x08, this+0x1044, this+0x1060 and this+0x1064 appear in packet extraction but have no visible use in the raw pseudocode; their roles are unknown.
- Pixel-surface blend family: whether source and destination share the same PixelSurface object layout is assumed, not proven; the owning class of the surfaces is UnknownObject.
- InterpolationCoordinateTableAllocator: three float globals (0x0059E43C, 0x0059E450, 0x005ADB14) are listed by facts but not in the raw source; per prior analysis they are consumed inside sub_5895A2, not verifiable here.
- InterpolationCoordinateTableAllocator: the store dword_8B0098 = v5 copies an uninitialized stack slot (v14 alias); likely a decompiler artifact of workspace reuse for sub_5895A2; exact intent unknown.
- VtableSetFreeChild: the exact class and ownership semantics of the child object at this+0x104C are unknown; FreeWrapper_7bcf release semantics (plain free vs pooled/aware deallocation) are unknown.
- DirectX texture constructors: the six constructor entry points install distinct vtables (0x005ADBA8, 0x005ADBC8, 0x005ADBD8, 0x005ADBE8, 0x005ADC18) implying distinct derived classes that this packet cannot resolve; argument a2 meaning and the 0x10/0x18/0x20 size literals are defined inside DirectXTextureCreationWithMipmapChain (0x00507496), outside this packet.
