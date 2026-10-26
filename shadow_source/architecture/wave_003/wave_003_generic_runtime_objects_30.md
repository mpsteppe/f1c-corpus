# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

This packet groups 13 generic runtime-object functions into ten defensible classes. Direct3D surface support: DirectXSurfaceBuffer (staging reallocation on format mismatch), VertexColorRenderBuffer (vertex-array render buffer with 16-bit color packing), and DirectXSurfaceFactory (format-code dispatch to ~39 per-code constructors). Audio: NetworkAudioDispatch, three thunks that lazily initialize the shared table then tail-call a global slot. Startup dispatch-table support: OSVersionCapabilities (OS/CPU feature detection), SSEMathDispatchTable, SSEMathDispatchTableAlt, AMD3DNowMathDispatchTable (CPU-guarded with five slot overrides), ScalarMathDispatchTable, and FixedPointLookupTableSet. The four table initializers and the lookup-table allocator are all invoked by sub_50FEA7 during shared-table setup. All class boundaries are DERIVED proposals from validated IR; no ownership is CONFIRMED and slot semantics are inferred from routine names.

## Function roles

- `0x005076FE` **DirectXSurfaceBuffer** — Reallocate the staging surface buffer when the destination surface format (this+0x8) differs from the source surface format (*(*(this+0x8)+0x8)); records the matched format and new buffer pointer, failing with -2147024882 on allocation failure.
- `0x0050A7E1` **VertexColorRenderBuffer** — Allocate and initialize a render buffer: create the DirectX texture, compute the even-aligned vertex count, install the vtable, allocate and construct the 16-byte-stride vertex array, and select the packing field layout from the descriptor format tag.
- `0x0050A92D` **VertexColorRenderBuffer** — Encode per-vertex floating-point RGBA colors into packed 16-bit channel words using YCbCr-like conversion coefficients, guarded by the work and enable flags and clearing the work flag when done.
- `0x0050B8A9` **DirectXSurfaceFactory** — Format/object factory dispatcher: read the format code at *(this+0x8)+0x4, allocate a per-code-sized surface object, store it at this+0x8, and invoke the per-code constructor; unrecognized codes return NULL.
- `0x0050C391` **NetworkAudioDispatch** — Audio-subsystem dispatch thunk: lazily initialize the shared function table via sub_50FEA7(1u), then tail-call the implementation stored in the global slot off_5D7890.
- `0x0050D690` **NetworkAudioDispatch** — Two-argument variant of the audio dispatch thunk: initialize the shared function table via sub_50FEA7(1u), then tail-call the implementation stored in the global slot off_5D7848.
- `0x0050E302` **NetworkAudioDispatch** — Audio subsystem dispatch wrapper: call sub_50FEA7(1u) then perform an indirect call through the global function pointer off_5D787C and return its result.
- `0x0050FDF3` **OSVersionCapabilities** — Detect the OS platform and CPU SIMD feature set via GetVersionExA with CPUID-based fallbacks (Win9x or API failure) and IsProcessorFeaturePresent on NT.
- `0x00516FB0` **SSEMathDispatchTableAlt** — Fill the alternate SSE math dispatch table (33 used dword slots) with SSE math routines; no guards, returns the table pointer.
- `0x005170C0` **SSEMathDispatchTable** — Fill the SSE math dispatch table (34 used dword slots) with SSE math routines; no guards, returns the table pointer.
- `0x005172A5` **AMD3DNowMathDispatchTable** — CPU-guarded fill of the 3DNow/MMX math dispatch table (57 slots) plus alternative overrides on five slots when further feature bits are set; returns the CPU feature flags.
- `0x00517927` **ScalarMathDispatchTable** — Fill the eight-entry scalar math dispatch table (slots 0..7 at offsets 0x0..0x1C) and return the table base pointer.
- `0x0051C5A3` **FixedPointLookupTableSet** — Allocate four 1024-DWORD lookup tables through vtable slot 0 and fill them with arithmetic-progression sequences; returns the pointer one dword past the last written element.

## Proposed classes

### DirectXSurfaceBuffer

Staging surface buffer used during Direct3D texture upload. Holds a destination surface-format descriptor at this+0x8 (source format reached through *(*(this+0x8)+0x8)). From packet prose (offsets not in the allowed field set): the staging buffer pointer is stored at this+0x104C, the recorded matched format at this+0x1048, and the staging width is read from this+0x1058; the buffer is reallocated as 16*width bytes whenever the destination and source formats differ.

Methods: `0x005076FE`

- `this+0x00000008` `void* destinationSurfaceFormat` (read, DERIVED)
- `*(this+0x8)+0x00000008` `void* sourceSurfaceFormat` (read, DERIVED)

### VertexColorRenderBuffer

Render buffer holding a 16-byte-stride vertex array (this+0x106C) plus the state for packing per-vertex RGBA colors into 16-bit channel words: destination WORD base at this+0x18, source/destination stride products (this+0x1050 * this+0x1074, this+0x1054 * this+0x1080), the processed vertex range (this+0x1070 .. this+0x1078), the work and enable flags (this+0x108C, this+0x1090) and the two pack shift amounts (this+0x1094, this+0x1098). Installs vtable off_5ADBB8 at this+0x0; the descriptor at this+0x8 carries the format tag (0x59565955 selects one 8-vs-zero layout, otherwise the mirrored one). this+0x1088 is written by the allocator but is not in the packet's allowed field set.

Methods: `0x0050A7E1`, `0x0050A92D`

- `this+0x00000000` `void** vtable` (write, DERIVED)
- `this+0x00000008` `void* parentDescriptor` (read, DERIVED)
- `*(this+0x8)+0x00000004` `uint32_t formatTag` (read, DERIVED)
- `this+0x00000018` `void* destinationWordBase` (read, GUESS)
- `this+0x00001050` `uint32_t sourceStrideProduct` (read, GUESS)
- `this+0x00001054` `uint32_t destStrideProduct` (read, GUESS)
- `this+0x0000106C` `float* vertexColorStream` (read_write, DERIVED)
- `this+0x00001070` `int32_t vertexRangeBase` (read_write, DERIVED)
- `this+0x00001074` `uint32_t pitchStride` (read_write, GUESS)
- `this+0x00001078` `int32_t vertexCountBound` (read_write, DERIVED)
- `this+0x0000107C` `uint32_t unresolvedFieldA` (read, UNKNOWN)
- `this+0x00001080` `uint32_t rowStride` (read_write, GUESS)
- `this+0x00001084` `uint32_t unresolvedFieldB` (read, UNKNOWN)
- `this+0x0000108C` `int32_t workFlag` (read_write, DERIVED)
- `this+0x00001090` `int32_t enableFlag` (read_write, DERIVED)
- `this+0x00001094` `int32_t packShiftA` (read_write, DERIVED)
- `this+0x00001098` `int32_t packShiftB` (read_write, DERIVED)

### DirectXSurfaceFactory

Format-code factory for Direct3D surface/object creation. Reads the format code at *(this+0x8)+0x4, allocates a per-code size (4204, 4252 or 4292 bytes) via the shared allocator, stores the created object at this+0x8, and invokes one of ~39 per-code constructors selected through a jump table; unrecognized codes return NULL. Post-construction, when the object's dword at +0x10 is non-null the virtual method at vtable slot 3 (+12) is invoked. Called from D3DContextInit. The this-4 frame tag slot is a local artifact with unknown public meaning.

Methods: `0x0050B8A9`

- `this+0x00000008` `void* inputDescriptor` (read_write, DERIVED)
- `*(this+0x8)+0x00000004` `uint32_t formatCode` (read, DERIVED)

### NetworkAudioDispatch

Dispatch thunks into the network audio subsystem. Each thunk calls sub_50FEA7(1u) to lazily install the shared version-adaptive function table, then tail-calls a dedicated global dispatch slot (off_5D7890 for the six-argument entry, off_5D7848 for the two-argument variant, off_5D787C for the no-argument wrapper). The slot implementations are selected during table installation and are not identified in this packet.

Methods: `0x0050C391`, `0x0050D690`, `0x0050E302`


### OSVersionCapabilities

Detects the OS platform and CPU SIMD feature set that selects which version-adaptive dispatch table gets installed. Uses GetVersionExA with a CPUID-based legacy path (CPUID3DNowDetection for feature 7, sub_50FD4E for SSE feature 6/10) when the platform is Win9x or the API fails, and IsProcessorFeaturePresent for other features on NT.

Methods: `0x0050FDF3`


### SSEMathDispatchTable

Function-pointer table of SSE math routines (vector sums and normalization, linear/cubic/hermite/bezier/bilinear spline interpolation, Newton-Raphson reciprocal and normalize refinement, 3x3 rotation-matrix multiply, triangle closest-point/normal, vector blend/lerp). Fills 34 used dword slots at offsets 0x0..0xD8. The owning object and dispatch convention are not evidenced.

Methods: `0x005170C0`

- `this+0x00000000` `FunctionPtr dispatchSlot0x00000000` (write, DERIVED)
- `this+0x00000004` `FunctionPtr dispatchSlot0x00000004` (write, DERIVED)
- `this+0x00000008` `FunctionPtr dispatchSlot0x00000008` (write, DERIVED)
- `this+0x0000000C` `FunctionPtr dispatchSlot0x0000000C` (write, DERIVED)
- `this+0x00000010` `FunctionPtr dispatchSlot0x00000010` (write, DERIVED)
- `this+0x00000014` `FunctionPtr dispatchSlot0x00000014` (write, DERIVED)
- `this+0x00000018` `FunctionPtr dispatchSlot0x00000018` (write, DERIVED)
- `this+0x0000001C` `FunctionPtr dispatchSlot0x0000001C` (write, DERIVED)
- `this+0x00000020` `FunctionPtr dispatchSlot0x00000020` (write, DERIVED)
- `this+0x00000024` `FunctionPtr dispatchSlot0x00000024` (write, DERIVED)
- `this+0x00000028` `FunctionPtr dispatchSlot0x00000028` (write, DERIVED)
- `this+0x0000002C` `FunctionPtr dispatchSlot0x0000002C` (write, DERIVED)
- `this+0x00000034` `FunctionPtr dispatchSlot0x00000034` (write, DERIVED)
- `this+0x00000040` `FunctionPtr dispatchSlot0x00000040` (write, DERIVED)
- `this+0x00000044` `FunctionPtr dispatchSlot0x00000044` (write, DERIVED)
- `this+0x00000048` `FunctionPtr dispatchSlot0x00000048` (write, DERIVED)
- `this+0x0000004C` `FunctionPtr dispatchSlot0x0000004C` (write, DERIVED)
- `this+0x00000050` `FunctionPtr dispatchSlot0x00000050` (write, DERIVED)
- `this+0x00000054` `FunctionPtr dispatchSlot0x00000054` (write, DERIVED)
- `this+0x00000058` `FunctionPtr dispatchSlot0x00000058` (write, DERIVED)
- `this+0x00000060` `FunctionPtr dispatchSlot0x00000060` (write, DERIVED)
- `this+0x00000064` `FunctionPtr dispatchSlot0x00000064` (write, DERIVED)
- `this+0x0000006C` `FunctionPtr dispatchSlot0x0000006C` (write, DERIVED)
- `this+0x00000070` `FunctionPtr dispatchSlot0x00000070` (write, DERIVED)
- `this+0x00000078` `FunctionPtr dispatchSlot0x00000078` (write, DERIVED)
- `this+0x0000007C` `FunctionPtr dispatchSlot0x0000007C` (write, DERIVED)
- `this+0x000000BC` `FunctionPtr dispatchSlot0x000000BC` (write, DERIVED)
- `this+0x000000C0` `FunctionPtr dispatchSlot0x000000C0` (write, DERIVED)
- `this+0x000000C4` `FunctionPtr dispatchSlot0x000000C4` (write, DERIVED)
- `this+0x000000C8` `FunctionPtr dispatchSlot0x000000C8` (write, DERIVED)
- `this+0x000000CC` `FunctionPtr dispatchSlot0x000000CC` (write, DERIVED)
- `this+0x000000D0` `FunctionPtr dispatchSlot0x000000D0` (write, DERIVED)
- `this+0x000000D4` `FunctionPtr dispatchSlot0x000000D4` (write, DERIVED)
- `this+0x000000D8` `FunctionPtr dispatchSlot0x000000D8` (write, DERIVED)

### SSEMathDispatchTableAlt

Alternate function-pointer table of SSE math routines, sharing most slot assignments with SSEMathDispatchTable but differing at slots 7, 13, 16, 21, 24, 25, 27, 28 and 44. Fills 33 used dword slots at offsets 0x0..0xD8. Whether the two tables serve different consumers or different CPU variants is not determinable from this packet.

Methods: `0x00516FB0`

- `this+0x00000000` `FunctionPtr dispatchSlot0x00000000` (write, DERIVED)
- `this+0x00000004` `FunctionPtr dispatchSlot0x00000004` (write, DERIVED)
- `this+0x00000008` `FunctionPtr dispatchSlot0x00000008` (write, DERIVED)
- `this+0x0000000C` `FunctionPtr dispatchSlot0x0000000C` (write, DERIVED)
- `this+0x00000010` `FunctionPtr dispatchSlot0x00000010` (write, DERIVED)
- `this+0x00000014` `FunctionPtr dispatchSlot0x00000014` (write, DERIVED)
- `this+0x00000018` `FunctionPtr dispatchSlot0x00000018` (write, DERIVED)
- `this+0x0000001C` `FunctionPtr dispatchSlot0x0000001C` (write, DERIVED)
- `this+0x00000020` `FunctionPtr dispatchSlot0x00000020` (write, DERIVED)
- `this+0x00000024` `FunctionPtr dispatchSlot0x00000024` (write, DERIVED)
- `this+0x00000028` `FunctionPtr dispatchSlot0x00000028` (write, DERIVED)
- `this+0x0000002C` `FunctionPtr dispatchSlot0x0000002C` (write, DERIVED)
- `this+0x00000034` `FunctionPtr dispatchSlot0x00000034` (write, DERIVED)
- `this+0x00000040` `FunctionPtr dispatchSlot0x00000040` (write, DERIVED)
- `this+0x00000044` `FunctionPtr dispatchSlot0x00000044` (write, DERIVED)
- `this+0x00000048` `FunctionPtr dispatchSlot0x00000048` (write, DERIVED)
- `this+0x0000004C` `FunctionPtr dispatchSlot0x0000004C` (write, DERIVED)
- `this+0x00000050` `FunctionPtr dispatchSlot0x00000050` (write, DERIVED)
- `this+0x00000054` `FunctionPtr dispatchSlot0x00000054` (write, DERIVED)
- `this+0x00000058` `FunctionPtr dispatchSlot0x00000058` (write, DERIVED)
- `this+0x00000060` `FunctionPtr dispatchSlot0x00000060` (write, DERIVED)
- `this+0x00000064` `FunctionPtr dispatchSlot0x00000064` (write, DERIVED)
- `this+0x0000006C` `FunctionPtr dispatchSlot0x0000006C` (write, DERIVED)
- `this+0x00000070` `FunctionPtr dispatchSlot0x00000070` (write, DERIVED)
- `this+0x000000B0` `FunctionPtr dispatchSlot0x000000B0` (write, DERIVED)
- `this+0x000000BC` `FunctionPtr dispatchSlot0x000000BC` (write, DERIVED)
- `this+0x000000C0` `FunctionPtr dispatchSlot0x000000C0` (write, DERIVED)
- `this+0x000000C4` `FunctionPtr dispatchSlot0x000000C4` (write, DERIVED)
- `this+0x000000C8` `FunctionPtr dispatchSlot0x000000C8` (write, DERIVED)
- `this+0x000000CC` `FunctionPtr dispatchSlot0x000000CC` (write, DERIVED)
- `this+0x000000D0` `FunctionPtr dispatchSlot0x000000D0` (write, DERIVED)
- `this+0x000000D4` `FunctionPtr dispatchSlot0x000000D4` (write, DERIVED)
- `this+0x000000D8` `FunctionPtr dispatchSlot0x000000D8` (write, DERIVED)

### AMD3DNowMathDispatchTable

CPU-guarded function-pointer table of 3DNow/MMX math routines (matrix multiply/transpose/inverse, quaternion product/composition/rotation, vector normalize/blend/negate, barycentric/cubic/bezier/quadrilinear interpolation, axis-angle and transform-matrix construction). The 57-slot fill runs only when CPU feature bits 0x20 and 0x80 are set; bits 0x100 and 0x200 gate five slot overrides (slots 15, 18, 24, 38, 39) whose fields list both the base and override routines. Returns the CPU feature flags from sub_5171D0.

Methods: `0x005172A5`

- `this+0x00000000` `FunctionPtr dispatchSlot0x00000000` (write, DERIVED)
- `this+0x00000004` `FunctionPtr dispatchSlot0x00000004` (write, DERIVED)
- `this+0x00000008` `FunctionPtr dispatchSlot0x00000008` (write, DERIVED)
- `this+0x0000000C` `FunctionPtr dispatchSlot0x0000000C` (write, DERIVED)
- `this+0x00000010` `FunctionPtr dispatchSlot0x00000010` (write, DERIVED)
- `this+0x00000014` `FunctionPtr dispatchSlot0x00000014` (write, DERIVED)
- `this+0x00000018` `FunctionPtr dispatchSlot0x00000018` (write, DERIVED)
- `this+0x0000001C` `FunctionPtr dispatchSlot0x0000001C` (write, DERIVED)
- `this+0x00000020` `FunctionPtr dispatchSlot0x00000020` (write, DERIVED)
- `this+0x00000024` `FunctionPtr dispatchSlot0x00000024` (write, DERIVED)
- `this+0x00000028` `FunctionPtr dispatchSlot0x00000028` (write, DERIVED)
- `this+0x0000002C` `FunctionPtr dispatchSlot0x0000002C` (write, DERIVED)
- `this+0x00000030` `FunctionPtr dispatchSlot0x00000030` (write, DERIVED)
- `this+0x00000034` `FunctionPtr dispatchSlot0x00000034` (write, DERIVED)
- `this+0x00000038` `FunctionPtr dispatchSlot0x00000038` (write, DERIVED)
- `this+0x0000003C` `FunctionPtr dispatchSlot0x0000003C` (write, DERIVED)
- `this+0x00000040` `FunctionPtr dispatchSlot0x00000040` (write, DERIVED)
- `this+0x00000044` `FunctionPtr dispatchSlot0x00000044` (write, DERIVED)
- `this+0x00000048` `FunctionPtr dispatchSlot0x00000048` (write, DERIVED)
- `this+0x0000004C` `FunctionPtr dispatchSlot0x0000004C` (write, DERIVED)
- `this+0x00000050` `FunctionPtr dispatchSlot0x00000050` (write, DERIVED)
- `this+0x00000054` `FunctionPtr dispatchSlot0x00000054` (write, DERIVED)
- `this+0x00000058` `FunctionPtr dispatchSlot0x00000058` (write, DERIVED)
- `this+0x0000005C` `FunctionPtr dispatchSlot0x0000005C` (write, DERIVED)
- `this+0x00000060` `FunctionPtr dispatchSlot0x00000060` (write, DERIVED)
- `this+0x00000064` `FunctionPtr dispatchSlot0x00000064` (write, DERIVED)
- `this+0x00000068` `FunctionPtr dispatchSlot0x00000068` (write, DERIVED)
- `this+0x0000006C` `FunctionPtr dispatchSlot0x0000006C` (write, DERIVED)
- `this+0x00000070` `FunctionPtr dispatchSlot0x00000070` (write, DERIVED)
- `this+0x00000074` `FunctionPtr dispatchSlot0x00000074` (write, DERIVED)
- `this+0x00000078` `FunctionPtr dispatchSlot0x00000078` (write, DERIVED)
- `this+0x0000007C` `FunctionPtr dispatchSlot0x0000007C` (write, DERIVED)
- `this+0x00000080` `FunctionPtr dispatchSlot0x00000080` (write, DERIVED)
- `this+0x00000084` `FunctionPtr dispatchSlot0x00000084` (write, DERIVED)
- `this+0x00000088` `FunctionPtr dispatchSlot0x00000088` (write, DERIVED)
- `this+0x0000008C` `FunctionPtr dispatchSlot0x0000008C` (write, DERIVED)
- `this+0x00000090` `FunctionPtr dispatchSlot0x00000090` (write, DERIVED)
- `this+0x00000094` `FunctionPtr dispatchSlot0x00000094` (write, DERIVED)
- `this+0x00000098` `FunctionPtr dispatchSlot0x00000098` (write, DERIVED)
- `this+0x0000009C` `FunctionPtr dispatchSlot0x0000009C` (write, DERIVED)
- `this+0x000000A0` `FunctionPtr dispatchSlot0x000000A0` (write, DERIVED)
- `this+0x000000A4` `FunctionPtr dispatchSlot0x000000A4` (write, DERIVED)
- `this+0x000000A8` `FunctionPtr dispatchSlot0x000000A8` (write, DERIVED)
- `this+0x000000AC` `FunctionPtr dispatchSlot0x000000AC` (write, DERIVED)
- `this+0x000000B0` `FunctionPtr dispatchSlot0x000000B0` (write, DERIVED)
- `this+0x000000B4` `FunctionPtr dispatchSlot0x000000B4` (write, DERIVED)
- `this+0x000000B8` `FunctionPtr dispatchSlot0x000000B8` (write, DERIVED)
- `this+0x000000BC` `FunctionPtr dispatchSlot0x000000BC` (write, DERIVED)
- `this+0x000000C0` `FunctionPtr dispatchSlot0x000000C0` (write, DERIVED)
- `this+0x000000C4` `FunctionPtr dispatchSlot0x000000C4` (write, DERIVED)
- `this+0x000000C8` `FunctionPtr dispatchSlot0x000000C8` (write, DERIVED)
- `this+0x000000CC` `FunctionPtr dispatchSlot0x000000CC` (write, DERIVED)
- `this+0x000000D0` `FunctionPtr dispatchSlot0x000000D0` (write, DERIVED)
- `this+0x000000D4` `FunctionPtr dispatchSlot0x000000D4` (write, DERIVED)
- `this+0x000000D8` `FunctionPtr dispatchSlot0x000000D8` (write, DERIVED)
- `this+0x000000DC` `FunctionPtr dispatchSlot0x000000DC` (write, DERIVED)
- `this+0x000000E0` `FunctionPtr dispatchSlot0x000000E0` (write, DERIVED)

### ScalarMathDispatchTable

Eight-entry math dispatch table (slots 0..7 at offsets 0x0..0x1C) populated with Vec2AffineTransform, sub_517569, sub_517653, F_44MatrixMultiply, F_44MatrixMultiply_7899, Mat2x2Mul, sub_5175F4 and VectorNormalize. Called from sub_50FEA7.

Methods: `0x00517927`

- `this+0x00000000` `FunctionPtr dispatchSlot0x00000000` (write, DERIVED)
- `this+0x00000004` `FunctionPtr dispatchSlot0x00000004` (write, DERIVED)
- `this+0x00000008` `FunctionPtr dispatchSlot0x00000008` (write, DERIVED)
- `this+0x0000000C` `FunctionPtr dispatchSlot0x0000000C` (write, DERIVED)
- `this+0x00000010` `FunctionPtr dispatchSlot0x00000010` (write, DERIVED)
- `this+0x00000014` `FunctionPtr dispatchSlot0x00000014` (write, DERIVED)
- `this+0x00000018` `FunctionPtr dispatchSlot0x00000018` (write, DERIVED)
- `this+0x0000001C` `FunctionPtr dispatchSlot0x0000001C` (write, DERIVED)

### FixedPointLookupTableSet

Object owning a sub-struct at this+0x1A0 that holds four 1024-DWORD lookup tables (at sub-struct offsets 0x8/0xC/0x10/0x14). The tables are allocated through vtable slot 0 at *(this+0x4) with allocator arguments (this, 1, 1024), then filled in a single loop with arithmetic-progression sequences: table 0 ascending (v9 += 91881 stored as v9 >> 16), table 1 ascending (v8 += 116130 stored as v8 >> 16), table 2 marching downward from global unk_5B6900 (v4 -= 46802), table 3 descending (i -= 22554).

Methods: `0x0051C5A3`

- `this+0x00000004` `void** vtable` (read, DERIVED)
- `*(this+0x4)+0x00000000` `FunctionPtr allocatorSlot0` (read, DERIVED)
- `this+0x000001A0` `void* lookupSubStruct` (read, DERIVED)
- `*(this+0x1A0)+0x00000008` `uint32_t* table0` (write, DERIVED)
- `*(this+0x1A0)+0x0000000C` `uint32_t* table1` (write, DERIVED)
- `*(this+0x1A0)+0x00000010` `uint32_t* table2` (write, DERIVED)
- `*(this+0x1A0)+0x00000014` `uint32_t* table3` (write, DERIVED)

## Compatibility contracts

- **DirectXSurfaceFormatDispatch** — A replacement must accept a format code at descriptor+0x4, allocate a per-code-sized surface object, keep it at descriptor+0x8, run its per-code constructor, return NULL for unrecognized codes, and invoke the vtable slot-3 (+12) virtual when the constructed object's +0x10 dword is non-null.
- **StagingSurfaceFormatMatch** — A replacement must reallocate the staging buffer (16*width bytes) whenever the destination surface format (this+0x8) differs from the source format (*(*(this+0x8)+0x8)), record the matched format, return 0 on success and -2147024882 when allocation fails.
- **NetworkAudioDispatchSlot** — Audio callers dispatch through version-adaptive slots; a replacement must initialize the shared function table (sub_50FEA7 semantics) before invoking the slot implementation stored at off_5D7890 / off_5D7848 / off_5D787C.
- **SIMDMathDispatchTables** — A replacement must install the SSE, SSE-alt, 3DNow/MMX and scalar function-pointer tables with the slot-to-routine assignments captured in the class fields. The 3DNow fill is gated on CPU feature bits 0x20/0x80, with five slot overrides gated on bits 0x100/0x200.
- **VertexColorPackLayout** — Vertex-color packing must run only while both the work flag (this+0x108C) and enable flag (this+0x1090) are set, then clear the work flag; the two pack shift amounts are held at this+0x1094 and this+0x1098.
- **OSFeatureDetection** — A replacement must reproduce the GetVersionExA / CPUID / IsProcessorFeaturePresent based platform and CPU-feature detection that drives dispatch-table selection.
- **FixedPointLookupTables** — A replacement must allocate four 1024-DWORD lookup tables through vtable slot 0 (allocator arguments (this, 1, 1024)) and fill them with the four arithmetic-progression sequences described in the FixedPointLookupTableSet responsibility.

## Unresolved

- TextureCopyRealloc (0x005076FE): the role of parameter a2 is not observable; the a1/ebp __userpurge frame-pointer convention is only partially recoverable; the staging width at this+0x1058 and the staging element layout are inferred, not evidenced.
- RenderBufferVertexAllocator (0x0050A7E1): the global loc_59C578 is listed but absent from the raw source; the semantics of the base count / derived even count window and of the format tag 0x59565955 are unknown; the mirrored 8/0 field assignments and this+0x1088 are inferred.
- VertexColorPackRGBto16 (0x0050A92D): which conversion-coefficient global backs which constant is not provable from the packet; fields this+0x107C and this+0x1084 are accessed per the extractor but their roles are unknown.
- DirectXTextureSurfaceFactory (0x0050B8A9): the ~39 constructed object class types are unknown (callee names are semantic proposals only); global loc_59C71A's concrete role is not visible; the this-4 frame tag slot has unknown public meaning; the broader Direct3D device/surface creation relationship is unconfirmed.
- NetworkAudioSend thunks (0x0050C391, 0x0050D690, 0x0050E302): the indirect slot implementations are not identified; the callee entries callee:0x0050C391 / callee:0x0050D690 are self-loop artifacts, not recursive calls; the two-argument variant's relationship to the other thunks is unestablished; the float argument a2's meaning (volume/pan/time) is unknown.
- OSVersionDetection (0x0050FDF3): the byte_FF..5370..5374 globals are decompiler artifacts of szCSDVersion[16] pointer arithmetic, not real module globals; the sub_50FD4E bit-4 vs bit-8 mask semantics are inferred; the v1/v4 dual flag on Win9x is not fully resolved.
- SSE/SSE-alt table initializers (0x005170C0, 0x00516FB0): the owning object and dispatch convention are not evidenced; slot roles are inferred from routine names; whether the two tables serve different consumers or CPU variants is not determinable.
- Init3DNowMathFunctionTable (0x005172A5): sub_5171D0 is not decomposed, so the meanings of feature bits 0x20/0x80/0x100/0x200 are unknown; whether the five override routines are faster variants or semantically different operations is unknown.
- FunctionTableInit (0x00517927): the unnamed entries sub_517569, sub_517653 and sub_5175F4 have unknown math semantics; the owning class is unknown and the table base is received as argument a1.
- TableInitWithArithmeticProgression (0x0051C5A3): the vtable-slot-0 allocator at *(this+0x4) is unresolved; the intended semantic content of the four arithmetic sequences (fixed-point >>16 values, pointer-derived values from unk_5B6900) is unknown (existing analysis guesses wheel/suspension data, unconfirmed); the sub-struct owner type is unknown; the loop trip count is derived from the progression bounds, not a packet literal.
