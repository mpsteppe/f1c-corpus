# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `GUESS`

Reconstruction of generic runtime objects from 24 validated function IR records. The packet labels every owner UNKNOWN, so all class groupings here are DERIVED proposals (shared field clusters plus call edges) or GUESS. SurfaceRenderContext groups five functions around this+0x5C/this+0x64/this+0x1A4/this+0x1BC (0x0051D1DB heightmap counting, 0x0051DC01 palette-grid packed copy, 0x0051E5D7 table-weighted mix, 0x0051E65F three-channel lookup sum, 0x0051E6EC convolution-style checksum accumulation). ColorLutRgbRowConverter groups the two structurally twin RGB converters 0x0051CE2A and 0x0051CF80; the RGBA converter 0x0051C6E1 is kept separate because it reaches its four tables through the sub-object pointer at this+0x1A0 (tables this+0x1A8..0x1B4) while the RGB twins use this+0x19C (tables this+0x1AC..0x1B8), an overlapping but not provably identical pointer path (rule 8). The VQ palette (0x0051DA17), block quantizer (0x0051DB31) and packed-palette copy (0x0051DC01) form a quantization chain via the call edges 0x0051DB31 -> 0x0051D897/0x0051DA17 and 0x0051DC01/0x0051DCAA -> 0x0051DB31; the palette component arrays behind this+0x74 are the only packet-grounded palette fields. The seven SSE math helpers are grouped as one SseMathLibrary sharing the constant globals 0x005D8A30..0x005D8AC0. 0x0051CDF9 and 0x0051EB5A are virtual-dispatch wrappers with unknown callee identity. Contradiction recorded: this+0x19C is read as a polymorphic dispatch sub-object (vtable slot +0xC) by 0x0051CDF9 and as a LUT sub-object (pointers at +0x10..+0x1C) by the RGB twins, and *(*(this+0x1A4)+0x18) is read as a heightmap data base, a palette grid row-pointer base, and an array of table base pointers by different members.

## Function roles

- `0x0051C237` **HorizontalPixelFilterSurface** — Horizontal 2x interpolating pixel filter on a surface: iterates row-count rows (this+0x110), reads the input row pointer from the a3 row-pointer array and the output row pointer from (*a4)[i], and writes 2*count output bytes per row using the weighted kernel ((3a+b+2)>>2, (a+3b+1)>>2). The interior run is skipped when the channel count at the a2 argument object +40 differs from 2, so only boundary pixels are emitted for the 2-channel case. Returns a1. The a2+40 channel count is read on an argument object, not on this, and its object type is unknown.
- `0x0051C653` **TwoDimensionalCopySurface** — 2D texture copy with column-wise output placement: reads the column count from this+0x20 and the per-segment byte length from this+0x5C, then for each of a5 output rows copies each column's byte segment (source pointer resolved through the DWORD index table a2) down the output column with a vertical stride equal to the column count. Guarded by a5 >= 1. The index-table content and the meaning of a3 are not established.
- `0x0051C6BE` **TwoDimensionalCopySurface** — Thin delegation wrapper for a 2D rectangular array copy: loads the per-row copy size from this+0x5C and calls F_2DArrayBlockCopy(*a2, a3, a4, 0, a5, *(this+0x5C)), returning the callee's result. No local computation beyond argument marshalling; argument semantics other than the marshalling order are not specified by the packet.
- `0x0051C6E1` **ColorLutRgbaRowConverter** — Per-row pixel blit with four color lookup tables: reads the LUT sub-object pointer at this+0x1A0 (table pointers at this+0x1A8..0x1B4), the row width this+0x5C and the additive base this+0x11C, then for each of a5 rows and each of row_width pixels reads three channel bytes plus an alpha byte, transforms each channel as base + 255 - LUT[channel] - luma (middle channel averaging two tables with a >> 16 blend) and writes four output bytes per pixel. Rows skipped when a5 <= 0; per-row pixel work skipped when the row width is zero.
- `0x0051C813` **PackedPixelBlendOperation** — MMX/SIMD blend loop processing a1>>2 groups of four packed 32-bit pixels from three source buffers (a2, a3, a4): byte-unpacks, bias-subtracts with qword_5D89E8, multiply-accumulates against the coefficient QWORDs qword_5D89F0/0x5D89F8/0x5D8A00, shifts right by 8, packs/masks (qword_8B00C0 zero filler, qword_5D8A08 mask), writes three DWORD results per group at a 12-byte stride, advances all three source pointers by one DWORD and returns the advanced a2 pointer. The exact per-channel transform semantics are not determinable from the packet.
- `0x0051CDF9` **VirtualElementDispatchObject** — Virtual dispatch wrapper processing one element: reads the sub-object pointer at this+0x19C, calls the vtable method at its +0xC (vtable slot 3) with (a1, a2, *a3, a5 + 4 * *a6), then increments *a6 (element index) and *a3 (input pointer) by one and returns the dispatch result. The indirect callee identity and the per-element array role of a5 + 4 * *a6 are unresolved.
- `0x0051CE2A` **ColorLutRgbRowConverter** — Palette-indexed texture color conversion writing one RGB row: reads the LUT sub-object pointer at this+0x19C (table pointers at this+0x1AC..0x1B8), the additive base this+0x11C and the row width this+0x5C, resolves three source byte streams from the a2 array at byte offset 4*a3, and writes 3 output bytes per pixel with two pixels per loop iteration (a1[23] >> 1 iterations) plus one trailing pixel when the row width is odd. No alpha byte is written.
- `0x0051CF80` **ColorLutRgbRowConverter** — Dual-output color conversion structurally twin to TexturePaletteColorLookup (same this+0x19C LUT sub-object, same table offsets +0x1AC..0x1B8, same width/base fields): reads the a0 pointer pair at byte offset 8*a3 and the a1/a2 streams at 4*a3 from the a2 array, and writes 3 output bytes per pixel into each of two destination streams (*a4 and *(a4+4)) using the same table-lookup arithmetic with a >> 16 middle-channel blend. Returns the low byte of the base register.
- `0x0051D1DB` **SurfaceRenderContext** — Increments uint16 counters in a track-surface heightmap grid: for each of a4 row entries decodes a 3-byte-per-cell stream (x = byte[0]>>3, y = byte[1]>>2, z = byte[2]>>3), increments the counter at grid cell (x, z + 32*y) inside the data array reached as *(*(this+0x1A4)+0x18), clamping a wrap to 65535. The inner loop bound is read once from this+0x5C; parameter a3 is unused.
- `0x0051D6D2` **WeightedCentroidGridRegion** — Computes the weighted centroid of non-zero 16-bit pixel values inside the 3D grid region bounded by this[0..5] (minX, maxX, minY, maxY, minZ, maxZ): nested X/Y/Z loops with empty-axis guards accumulate the total weight and the weighted X/Y/Z coordinate sums, then three rounded byte centroids are written to the output a3 at offsets read from the descriptor at a2+116. Returns the Z centroid. The descriptor chains at a2+420 and a2+116 are source-derived, not declared packet fields.
- `0x0051DA17` **VectorQuantizationPalette** — For each palette-index byte from the source array builds a weighted squared color distance against target components a2/a3/a4 using the palette's three component arrays behind this+0x74 (R/G/B at +0x0/+0x4/+0x8), then fills a 128-entry distance buffer (initialized to 0x7FFFFFFF) and a parallel 128-byte index buffer via a 4x8x4 nested block scan, storing the palette index wherever the distance beats the current best. Guarded on a5 > 0; weights 2 (R) and 3 (G) are grounded literals. Called by BitstreamTextureBlockCopy to build per-block best-match index maps.
- `0x0051DB31` **TextureBlockQuantizer** — Bitstream texture block quantize-and-copy helper (__usercall): given a texture object a2 and source block coordinates, loads the destination word-table base reached as *(*(a2+420)+24), quantizes the source region via PaletteVectorQuantizationNearestNeighbor (0x0051D897), derives the per-block index stream via sub_51DA17 (0x0051DA17), and writes the encoded block as 4x8 groups of 4 words (*index + 1), stepping the write cursor 64 bytes per row. Returns the final cursor position. Invoked by 0x0051DC01 and 0x0051DCAA to store a palette-quantized texture block.
- `0x0051DC01` **SurfaceRenderContext** — Copies a grid of packed pixels to a byte output using an RGB 5-6-5 palette lookup: for each of a4 source pixels decomposes three packed bytes into a grid key (v7 = byte0>>3, v9 = byte1>>2, v10 = byte2>>3), resolves the palette cell word at *(*(this+0x1A4)+0x18) + 4*v7 + 2*(v10 + 32*v9), populates an empty (zero) cell via BitstreamTextureBlockCopy (0x0051DB31), and writes (palette index minus 1) to the output. The width from this+0x5C gates the inner column loop; returns a1.
- `0x0051E5D7` **SurfaceRenderContext** — Per-pixel channel mixing via multiple byte lookup tables: for each of a4 pixels reads a source byte row and a destination pixel pointer, then for each output byte (width this+0x5C) sums over each channel (count this+0x64) the table byte at table[channel][source_byte], where the table array base is loaded as *(*(this+0x1A4)+0x18) (context field this+0x1BC), and writes the summed byte. Returns the channel count.
- `0x0051E65F` **SurfaceRenderContext** — Blends 3-channel pixel data by summing three lookup-table reads into a single output byte per source pixel: reads the context pointer this+0x1A4, loads three table base pointers from its +0x18 member (indices 0/4/8), and for each pixel descriptor in the a3 array (a4 total) accumulates LUT0[src0] + LUT1[src1] + LUT2[src2] over this+0x5C bytes into the destination. The ABI label ChecksumCompute_Type0_3Stream (abi:lead) is inconsistent with the three-table lookup-sum body and is recorded unresolved.
- `0x0051E6EC` **SurfaceRenderContext** — Convolution-style checksum/sum accumulator over a set of pixel buffers: for each of a4 output buffers clears the buffer via MemoryZeroFill (0x005159A8) to the row size this+0x5C, then for each of this+0x64 channels accumulates bytes from a source stream (stepped by the channel count) through a lookup table whose base comes from the context object at this+0x1A4 (v4[6] = this+0x1BC), advancing a rolling 4-bit phase at this+0x1D4 (phase-step entries at this+0x1D8) per byte; the phase value is returned.
- `0x0051EB5A` **VirtualFieldWriteDispatcher** — Unconditional wrapper: writes the constant 45 into obj+0x14 (obj is the pointer stored at this+0x0), then calls the first entry of the function-pointer table stored at this+0x0 (obj+0x0) on this and returns its integer result. The meaning of the constant and the identity of the called table entry are unknown.
- `0x0051F160` **SseMathLibrary** — Unconditional 4-component float vector normalization via Newton-Raphson refined reciprocal square root: computes the squared length over all four components, computes 1/sqrt(length), applies the refinement v7 = (dword_5D8A40 - length * v6 * v6) * dword_5D8A30 * v6, scales every input component into the output a1 (this+0x0..0xC) and returns a1. No threshold guard.
- `0x0051F200` **SseMathLibrary** — Hermite cubic interpolation between four input float pairs (a4-a7) using SSE intrinsics: computes t^2 and t^3 from the parameter t (a8), evaluates a cubic basis polynomial from the constant vectors xmmword_5D8A60/0x5D8A80/0x5D8A70/0x5D8A50, blends the four inputs with the resulting basis values and stores the interleaved float-pair result at a3 (returned). Straight-line, unconditional, no callees; the exact coefficient values are not in the packet.
- `0x0051F2C0` **SseMathLibrary** — Pure SSE cubic-spline (Hermite-basis) interpolation: evaluates four cubic weight polynomials at the float parameter a8 from the coefficient vectors xmmword_5D8A80/0x5D8A60/0x5D8A70/0x5D8A50, broadcasts the weights, blends the start control pair a5 and the end control pair a7, and stores the two single-precision results to a3 (returned). The int parameters a4/a6 are unused in the body.
- `0x0051F350` **SseMathLibrary** — Evaluates the four cubic Hermite basis functions at parameter t=a8 using SSE intrinsics and blends four input vectors (a4-a7) with the resulting basis weights; writes the weighted sum to a3 (returned). Coefficients xmmword_5D8A60/0x5D8A80/0x5D8A70/0x5D8A50; the lane-to-basis-function mapping is not established without the constant values.
- `0x0051F400` **SseMathLibrary** — SSE-accelerated cubic spline interpolation: computes t^2 and t^3, evaluates the cubic basis polynomial vector from xmmword_5D8AC0 (t term), xmmword_5D8AB0 (t^2 term), xmmword_5D8A90 (t^3 term) and the bias dword_5D8AA0, blends the four 8-byte control-point pairs a4-a7 and stores the blended pair plus one trailing dword at a3, returning a3. The ABI lead Cubic_Spline_Catmull_Rom_Basis_Evaluation (LEGACY trust) is consistent with, but not evidence for, a Catmull-Rom reading.
- `0x0051F4C0` **SseMathLibrary** — Pure SIMD cubic Bernstein/Bezier polynomial evaluation: combines t, t^2, t^3 against the read-only constants xmmword_5D8AC0, dword_5D8AA0, xmmword_5D8AB0, xmmword_5D8A90 to form a per-lane basis weight vector, then outputs a weighted blend of four control vectors a4..a7 into *a3 (returned). No guards, no callees; the exact Bernstein basis cannot be derived without the constant values.
- `0x0051F560` **SseMathLibrary** — Straight-line SSE evaluation of the four cubic Hermite basis functions at parameter t followed by a weighted blend of two input values (a6, a8) against the tangent basis lanes H10/H11, storing two floats through a4 (returned). Structurally a twin of CubicSpline but only the H10/H11 combination is emitted (the H00/H01 contributions are cancelled by loadh low-half zeroing). Scalar parameters a5/a7 are unused.

## Proposed classes

### HorizontalPixelFilterSurface

Surface object exposing the row count at this+0x110 used to bound the per-row horizontal 2x interpolation filter (0x0051C237). The channel-count guard at a2+40 is read on a different argument object and is not part of this class.

Methods: `0x0051C237`

- `this+0x00000110` `int row_count` (read, GUESS)

### TwoDimensionalCopySurface

2D array copy surface holding the column count at this+0x20 and the per-row/per-segment byte length at this+0x5C: 0x0051C653 performs the column-wise blit and 0x0051C6BE delegates to the F_2DArrayBlockCopy service (0x0051593F) using this+0x5C as the copy size. Grouping is proposed from the shared this+0x5C byte-length field.

Methods: `0x0051C653`, `0x0051C6BE`

- `this+0x00000020` `int column_count` (read, GUESS)
- `this+0x0000005C` `int segment_byte_length` (read, GUESS)

### ColorLutRgbaRowConverter

Per-row RGBA pixel converter using four byte lookup tables reached through the LUT sub-object pointer at this+0x1A0 (table pointers at this+0x1A8..0x1B4), with row width this+0x5C and additive base this+0x11C; 0x0051C6E1 writes four output bytes per pixel (three transformed color channels plus a copied source byte). The base + 255 - LUT arithmetic resembles an inverse color-space conversion but is not runtime-confirmed.

Methods: `0x0051C6E1`

- `this+0x0000005C` `int row_width` (read, GUESS)
- `this+0x0000011C` `byte additive_base` (read, GUESS)
- `this+0x000001A0` `pointer lut_subobject_ptr` (read, GUESS)
- `this+0x000001A8` `pointer lut_table_0` (read, GUESS)
- `this+0x000001AC` `pointer lut_table_1` (read, GUESS)
- `this+0x000001B0` `pointer lut_table_2` (read, GUESS)
- `this+0x000001B4` `pointer lut_table_3` (read, GUESS)

### PackedPixelBlendOperation

SIMD/MMX pixel blend primitive (0x0051C813) over three packed source buffers using the read-only QWORD constants qword_5D89E8/0x5D89F0/0x5D89F8/0x5D8A00/0x5D8A08 and the zero filler qword_8B00C0. No owned fields on this; the exact per-channel transform (color conversion vs generic 3x3 matrix) is unknown, and the only known caller sub_51C94F is outside the packet.

Methods: `0x0051C813`


### VirtualElementDispatchObject

Object dispatching one element through a vtable method on the sub-object pointed to by this+0x19C: 0x0051CDF9 reads vtable slot 3 (+0xC) of the sub-object and calls it with a per-element pointer argument, then advances an element index and an input pointer. The callee identity and the element-array role of a5 + 4 * *a6 are unresolved.

Methods: `0x0051CDF9`

- `this+0x0000019C` `pointer dispatch_subobject_ptr` (read, GUESS)
- `*(this+0x19C)+0x0000000C` `pointer vtable_slot3_method` (read, GUESS)

### ColorLutRgbRowConverter

Per-row RGB pixel converter pair (structural twins 0x0051CE2A and 0x0051CF80) using four byte lookup tables reached through the LUT sub-object pointer at this+0x19C (table pointers at this+0x1AC..0x1B8), with row width this+0x5C and additive base this+0x11C; both convert two pixels per iteration with a trailing odd pixel and write 3 output bytes per pixel (RGB only, no alpha). 0x0051CF80 additionally writes two independent destination rows.

Methods: `0x0051CE2A`, `0x0051CF80`

- `this+0x0000005C` `int row_width` (read, GUESS)
- `this+0x0000011C` `byte additive_base` (read, GUESS)
- `this+0x0000019C` `pointer lut_subobject_ptr` (read, GUESS)
- `this+0x000001AC` `pointer lut_table_0` (read, GUESS)
- `this+0x000001B0` `pointer lut_table_1` (read, GUESS)
- `this+0x000001B4` `pointer lut_table_2` (read, GUESS)
- `this+0x000001B8` `pointer lut_table_3` (read, GUESS)

### SurfaceRenderContext

Raster processing context shared by five functions (0x0051D1DB heightmap counting, 0x0051DC01 palette-grid packed copy, 0x0051E5D7 table-weighted mix, 0x0051E65F three-channel lookup sum, 0x0051E6EC convolution-style checksum accumulation): row width this+0x5C and channel count this+0x64 bound the inner loops, and the context pointer this+0x1A4 dereferences at +0x18 to a data array that is read as a heightmap grid base (0x0051D1DB), a palette grid row-pointer base (0x0051DC01), or an array of byte lookup-table base pointers (0x0051E5D7/0x0051E65F/0x0051E6EC; absolute offset this+0x1BC). 0x0051E6EC additionally persists a rolling 4-bit phase at this+0x1D4 (phase-step entries at this+0x1D8). The different interpretations of the +0x18 member are not proven to be the same allocation.

Methods: `0x0051D1DB`, `0x0051DC01`, `0x0051E5D7`, `0x0051E65F`, `0x0051E6EC`

- `this+0x0000005C` `int row_width` (read, GUESS)
- `this+0x00000064` `int channel_count` (read, GUESS)
- `this+0x000001A4` `pointer context_ptr` (read, GUESS)
- `*(this+0x1A4)+0x00000018` `pointer context_data_array` (read, GUESS)
- `this+0x000001BC` `pointer table_array_base` (read, GUESS)
- `*(*(this+0x1A4)+0x18)+0x00000000` `pointer table_ptr_0` (read, GUESS)
- `*(*(this+0x1A4)+0x18)+0x00000004` `pointer table_ptr_1` (read, GUESS)
- `*(*(this+0x1A4)+0x18)+0x00000008` `pointer table_ptr_2` (read, GUESS)
- `this+0x000001D4` `int phase_counter` (read_write, GUESS)
- `this+0x000001D8` `int phase_step_entries` (read, GUESS)

### WeightedCentroidGridRegion

Object exposing a 3D bounding region as six WORD bounds this[0..5] (minX, maxX, minY, maxY, minZ, maxZ); 0x0051D6D2 computes the weighted centroid of non-zero 16-bit pixels inside the region and writes three rounded byte centroids to an output buffer at descriptor offsets read from a2+116. The physical grid dimensions, the 64-byte row stride and the coordinate proxies (8*x+4, 4*y+2, 8*z+4) are taken from the raw source without independent confirmation.

Methods: `0x0051D6D2`

- `this+0x00000000` `word min_x` (read, GUESS)
- `this+0x00000004` `word max_x` (read, GUESS)
- `this+0x00000008` `word min_y` (read, GUESS)
- `this+0x0000000C` `word max_y` (read, GUESS)
- `this+0x00000010` `word min_z` (read, GUESS)
- `this+0x00000014` `word max_z` (read, GUESS)

### VectorQuantizationPalette

Palette object backing nearest-color distance evaluation: this+0x74 points to a palette structure whose three byte component arrays (R/G/B) sit at +0x0/+0x4/+0x8; 0x0051DA17 builds weighted squared-distance maps over a 4x8x4 block for the caller 0x0051DB31. Weights 2 (R) and 3 (G) are grounded literals. The 128-entry block scan and the 128/288/512 position strides encode a tiled sub-position layout that the raw source alone does not reveal.

Methods: `0x0051DA17`

- `this+0x00000074` `pointer palette_ptr` (read, GUESS)
- `*(this+0x74)+0x00000000` `pointer pal_red_array` (read, GUESS)
- `*(this+0x74)+0x00000004` `pointer pal_green_array` (read, GUESS)
- `*(this+0x74)+0x00000008` `pointer pal_blue_array` (read, GUESS)

### TextureBlockQuantizer

Texture object helper that quantizes a source block to nearest palette colors and writes the encoded block into a destination word table: 0x0051DB31 (__usercall) follows the a2 texture object's +420 pointer to a structure whose +24 field holds the table, calls PaletteVectorQuantizationNearestNeighbor (0x0051D897) and sub_51DA17 (0x0051DA17), and writes 4x8 groups of 4 words (*index + 1) at a 64-byte row step. Called by 0x0051DC01 and 0x0051DCAA. The a2+420/+24 path has no packet field evidence refs (source-derived only).

Methods: `0x0051DB31`


### VirtualFieldWriteDispatcher

Wrapper object that writes a constant into a sub-object field and dispatches through a function-pointer table: 0x0051EB5A stores 45 at obj+0x14 (obj = *this), then calls the first table entry at obj+0x0 with this and returns its result. The constant's meaning (flag/parameter for the callee) and the identity of the called table entry (constructor, notification or update) are unknown.

Methods: `0x0051EB5A`

- `this+0x00000000` `pointer obj_ptr` (read, GUESS)
- `obj+0x00000000` `pointer function_table` (read, GUESS)
- `obj+0x00000014` `int constant_field_45` (write, GUESS)

### SseMathLibrary

Standalone SSE/float math helper set (0x0051F160..0x0051F560): 4-component Newton-Raphson normalization (0x0051F160, constants dword_5D8A30/dword_5D8A40) and six straight-line cubic-spline/basis evaluators (0x0051F200, 0x0051F2C0, 0x0051F350, 0x0051F400, 0x0051F4C0, 0x0051F560) sharing the read-only SSE coefficient globals xmmword_5D8A50..0x5D8AC0. All are unconditional, guard-less, callee-less and return their output pointer; the exact numeric basis (Hermite vs Catmull-Rom vs Bezier) cannot be derived without the constant values. The 0x0051F160 output vector overlaps offsets this+0x0..0xC that WeightedCentroidGridRegion reads as region bounds; the overlap is a decompiler-`this` artifact and is not evidence of a shared type (rule 8).

Methods: `0x0051F160`, `0x0051F200`, `0x0051F2C0`, `0x0051F350`, `0x0051F400`, `0x0051F4C0`, `0x0051F560`

- `this+0x00000000` `float out_x` (write, GUESS)
- `this+0x00000004` `float out_y` (write, GUESS)
- `this+0x00000008` `float out_z` (write, GUESS)
- `this+0x0000000C` `float out_w` (write, GUESS)

## Compatibility contracts

- **RasterContextIndirectionContract** — Any replacement of the raster context must resolve the data/table array through this+0x1A4 dereferenced at +0x18 (absolute field this+0x1BC): the member is read as a heightmap data base by 0x0051D1DB, as a palette grid row-pointer base by 0x0051DC01, and as an array of byte lookup-table base pointers (indices 0/4/8) by 0x0051E5D7/0x0051E65F/0x0051E6EC. The row width this+0x5C and channel count this+0x64 must gate the corresponding inner loops.
- **ColorLutRowConversionContract** — The row pixel converters must read the row width this+0x5C, the additive base this+0x11C and four byte lookup-table pointers, and write per-pixel output: the RGBA variant (0x0051C6E1, tables this+0x1A8..0x1B4) writes 4 bytes per pixel including a copied source byte; the RGB twins (0x0051CE2A, 0x0051CF80, tables this+0x1AC..0x1B8) write 3 bytes per pixel with two pixels per loop iteration and a trailing odd pixel. The two table-pointer paths are not proven to be the same allocation and must not be merged (rule 8).
- **PaletteBlockQuantizationContract** — 0x0051DB31 must quantize the source block via PaletteVectorQuantizationNearestNeighbor (0x0051D897) and sub_51DA17 (0x0051DA17), then write the encoded block as 4x8 groups of 4 words (*index + 1), stepping the word-table cursor 64 bytes per row; the palette component arrays used by 0x0051DA17 are read behind this+0x74 (R/G/B at +0x0/+0x4/+0x8). The destination word table is reached through the a2 texture object's +420 pointer's +24 field.
- **WeightedCentroidContract** — 0x0051D6D2 must iterate the 3D region bounded by this[0..5] (minX, maxX, minY, maxY, minZ, maxZ), skipping empty axes, accumulate the total weight and the weighted X/Y/Z coordinate sums of non-zero 16-bit pixels, normalize each with round-half-up division by the total weight, and write three rounded byte centroids to the output base a3 at the offsets read from the descriptor at a2+116; the Z centroid is also returned.
- **SseMathHelperContract** — The spline/basis helpers (0x0051F200, 0x0051F2C0, 0x0051F350, 0x0051F400, 0x0051F4C0, 0x0051F560) are pure straight-line evaluations of a cubic basis at the scalar parameter t with the read-only coefficient globals xmmword_5D8A50..0x005D8AC0, blending control inputs and returning the output pointer a3; 0x0051F160 normalizes a 4-component vector via a Newton-Raphson refined reciprocal square root using dword_5D8A30/dword_5D8A40 and writes the four scaled components to the output (this+0x0..0xC). No callees and no side effects beyond the output write.

## Unresolved

- 0x0051C237 (PixelBlendFilterHorizontal): the channel count at a2+40 is read on an argument object, not on this, and has no packet field evidence; the filter kernel weights (3-1/1-3) and the 2-channel special case are DERIVED from the shift-divide arithmetic; the a3/a4 row-pointer array layout is DERIVED from the dereference pattern; the owning class exposing this+0x110 is unidentified.
- 0x0051C653 (F_2DBlitTextureCopy): the role of a3 (4*a3 initial source byte offset) and the content of the DWORD index table a2 are unknown; the transposed column-wise output placement is DERIVED from the address arithmetic; the returned pointer has no caller contract in the packet.
- 0x0051C6BE (F_2DCopyDelegation): the semantics of a2/a3/a4/a5 and the 0 literal parameter are not specified by the packet; the owner type has no vtable or constructor evidence.
- 0x0051C6E1 (PixelBlitWithColorLookupTable): the exact color-space meaning of the four lookup tables and the base + 255 - table arithmetic is not runtime-confirmed; the meaning of the copied alpha byte and the semantic role of a3 are unknown.
- 0x0051C813 (PackedPixelBlend): the per-channel transform and the byte layout of the six QWORD constants are unknown; the only known caller sub_51C94F is outside the packet.
- 0x0051CDF9 (VirtualDispatchWrapper_cdf9): vtable slot 3 callee identity is indirect and not statically resolvable; the element-array role of a5 + 4 * *a6 is DERIVED from the increment pattern.
- 0x0051CE2A (TexturePaletteColorLookup): palette/color-space semantics, the source-stream layout of a2, and the reason RGB output writes no alpha byte are unresolved.
- 0x0051CF80 (YuvToRgbColorSpaceConverter): the legacy ABI label suggests YUV-to-RGB conversion but is not runtime-confirmed; the meaning of the two destination rows and the interleaved a2[0] pointer pair is unknown; the return value is only the low byte of the base register.
- 0x0051D1DB (TrackSurfaceHeightmapIncrement): the owner of the heightmap sub-struct and the caller populating the a2 row entries are unknown; v5 (this+0x5C) is read once before the outer loop so per-entry differing pixel counts are not supported; parameter a3 is unused; the (x, z + 32*y) grid geometry is inferred from the shift masks.
- 0x0051D6D2 (WeightedCentroidCompute): the descriptor layouts at a2+420 and a2+116 are source-derived, not declared packet fields; the physical grid dimensions, coordinate proxies (8*x+4, 4*y+2, 8*z+4) and 64-byte row stride are raw-source literals without independent evidence; the purpose of returning the Z centroid is unknown.
- 0x0051DA17 (VQBlockErrorBufferFill): the exact meaning of target components a2/a3/a4 is inferred; the 4x8x4 block scan with strides 128/288/512 encodes a tiled sub-position layout the raw source alone does not reveal; the palette object behind this+0x74 is an unknown class; weights 2 (R) and 3 (G) are grounded literals but their perceptual rationale is undocumented.
- 0x0051DB31 (BitstreamTextureBlockCopy): identity of a2 (a texture/palette manager whose +420 field reaches a +24 word table) is unknown and has no packet field evidence refs; the 32-scaled source window and 4x8x4 word write pattern semantics are unclear; the meaning of the sub_51DA17 return value v5 and the +1 index offset are unknown.
- 0x0051DC01 (PackedPixelCopyWithPaletteLookup): the owner object type is unidentified (empty packet owner evidence); the minus-one transform on the stored palette index is not derivable; the 32-column-per-row inference from 2*(v10 + 32*v9) is arithmetic-based; the relation between the a4 pixel count and the width field this+0x5C is not explicit.
- 0x0051E5D7 (TableWeightedMix): the buffer roles of a2 and a3 are ambiguous; the object pointed to by this+0x1A4 whose +0x18 field holds the table array is unidentified; why the function returns the channel count is unknown; width this+0x5C as an output-byte-per-pixel count is unverified; the lookup tables are opaque bytes.
- 0x0051E65F (ThreeChannelLookupSumBlend): the ABI label ChecksumCompute_Type0_3Stream (abi:lead) is inconsistent with the three-table lookup-sum body; the exact role of this+0x5C is inferred; the a3 descriptor layout is not defined. This is the only packet-declared unresolved evidence ref.
- 0x0051E6EC (ChecksumComputeType1): whether the table accumulation is a checksum or an image convolution is inferred from structure only; whether v4[6] (this+0x1BC) is one shared table base or per-channel table storage is not settled; the relation between the a3 output-buffer stride and the row size this+0x5C is not defined.
- 0x0051EB5A (writeFieldThenCallVirtual): the owner object type and the class owning the function-pointer table are unknown; the meaning of the constant 45 written at obj+0x14 and the identity of the first table entry are unknown.
- 0x0051F160 (Vec4NormalizeNewtonRaphson): the read-only globals dword_5D8A30 and dword_5D8A40 have no documented values or ownership; the caller context is not provided by the packet.
- 0x0051F200 (SSEHermiteCubicInterp): the exact coefficient values at xmmword_5D8A50/60/70/80 are not present; the interleaved float-pair output layout is unconfirmed; no callers or frame path found.
- 0x0051F2C0 (SSECubicSplineInterpolation): the float values of the four coefficient vectors are absent so the specific Hermite/cubic basis cannot be confirmed; a3/a5/a7 are declared double* but consumed as single-precision pairs; the unused int parameters a4/a6 are unexplained.
- 0x0051F350 (SSECubicHermiteBasisFunctionEvaluation): coefficient values are absent so the lane-to-basis-function (h00/h10/h01/h11) mapping is not established; no callers or frame path found.
- 0x0051F400 (CubicSpline): the dword written at a3+8 (v11 element [0], lower lanes zeroed by loadh) may be intentional or vestigial; the spline basis is not proven (the LEGACY ABI lead is only consistent with Catmull-Rom); the __userpurge register arguments a1/a2 have an unknown caller contract.
- 0x0051F4C0 (SSECubicBezierBernsteinPolynomialEvaluation): the numeric values of the four constants are absent so the exact Bernstein basis cannot be derived; whether a4..a7 are true control points in order is assumed from the shuffle masks 0/85/170/255.
- 0x0051F560 (HermiteSplineBasis): the four SSE constant globals have no packet values so the Hermite-basis identification is DERIVED from the cubic polynomial shape and structural twin only; a6/a8 are declared const double* but consumed as two float lanes; only the H10/H11 lanes are emitted (H00/H01 cancelled by loadh low-half zeroing) - whether that is intentional tangent-only interpolation is unknown; scalar parameters a5/a7 and the a1/a2/a3 __userpurge register arguments are unused/artifacts.
- CONTRADICTION (this+0x19C): 0x0051CDF9 reads the sub-object at this+0x19C as a polymorphic dispatch object (vtable slot 3 at +0xC) while 0x0051CE2A/0x0051CF80 read the same this-base offset as a LUT sub-object (table pointers at +0x10..+0x1C). The two readings are consistent with a single polymorphic object carrying both a vtable and LUT fields, but the packet does not prove it, so VirtualElementDispatchObject and ColorLutRgbRowConverter are kept as separate classes (rule 8).
- CONTRADICTION (LUT pointer range): ColorLutRgbaRowConverter reaches its four tables through the sub-object pointer at this+0x1A0 (tables this+0x1A8..0x1B4) while ColorLutRgbRowConverter uses this+0x19C (tables this+0x1AC..0x1B8); the two pointer paths overlap in the 0x1AC..0x1B4 range but are not proven to be the same allocation and are kept as separate classes (rule 8).
- CONTRADICTION (*(this+0x1A4)+0x18): SurfaceRenderContext members interpret the +0x18 member of the context object as a heightmap data base (0x0051D1DB), a palette grid row-pointer base (0x0051DC01) and an array of lookup-table base pointers (0x0051E5D7/0x0051E65F/0x0051E6EC); the readings are consistent with a generic array-of-pointers field but the allocations are not proven identical.
- CONTRADICTION (this+0x0..0xC): WeightedCentroidGridRegion reads these offsets as a 3D bbox while SseMathLibrary (0x0051F160) writes them as a normalized output vector; both are decompiler-`this` argument artifacts, not evidence of a shared type (rule 8).
- General: every owner in this packet is packet-labeled UNKNOWN, so every class here is a DERIVED proposal or GUESS; worker proposals cannot be promoted to CONFIRMED/FACT without independent static or runtime evidence; equal offsets on different bases or on different sub-object pointer paths are never merged into a shared type without packet proof of common ownership (rule 8).
