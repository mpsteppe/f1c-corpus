# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

DERIVED grouping of 18 validated IR functions around one shared surface/texture object (D3DSurface, GUESS grouping) and several small owning types. (1) D3DSurface: the surface wrapper carrying a vtable pointer, pixel format, flags, and a dimension/stride block at 0x1050-0x1068; its processing operations cover surface blit (0x0050099C), pixel copy (0x00504508), staging-buffer copy (0x00504640), overlap transfer (0x00504731), compositing dispatch (0x00504B37), 3D half downscale (0x00504F5A), bilinear/trilinear resampling (0x005054EC, 0x005058D2), vertex-blend buffer construction (0x00506003), and filter-table construction (0x00502F31). These share the 16-byte-element staging-buffer protocol and the vtable+4 fetch / vtable+8 row-write slots. (2) D3DTextureSurfaceCopier (DERIVED, 0x00506559): the lock-copy helper holding control flags at +0, input surface at +4, destination at +8, source at +C; it fills an output descriptor and dispatches surface vtable slots +24/+28/+36/+108/+112. (3) D3D8DebugMuteCache (GUESS, 0x00500EAC): lazily resolves and caches the D3D8 DebugSetMute pointer in globals 0x008B0094/0x008B0090. (4) DualVTableContainer (GUESS, 0x00502BF4): object releasing two vtable children at +0/+4. (5) SlabChildContainer (GUESS, 0x00506FD9): destructor freeing a 2D slab of 8-byte child entries plus two buffers, delegating to VtableSetFreeChild (0x00506CCC). (6) AudioSampleState (GUESS, 0x004FF8F0): packed audio sample-state cross-fade with Hermite position, quaternion orientation, and per-channel blending. Remaining helpers ZeroInit4Ints (0x005064BF) and VTableReleaseClear (0x0050653E) are owner-unknown generic utilities. Packet owner trust is mostly UNKNOWN/LOW; the D3DSurface grouping and the surface vtable slots are the strongest evidence. Equal offsets on different bases (this vs obj) are never merged.

## Function roles

- `0x004FF8F0` **AudioSampleState** — Cross-fades two packed audio sample states (source A a3 to source B a4) into an output state a5 driven by time a2: clamps into the source range, emits an audio status event (ProgressBarEventEncode 0x004B33B0), picks discrete blend factors when the delta exceeds the 5.0 threshold or the FieldCompareConstant flag, otherwise computes continuous factors; blends position via Hermite/linear, orientation via Euler->quaternion->slerp->Euler, and the packed channels/bitfields per-channel.
- `0x004FFFA0` **UnknownObject** — Thunk stub that unconditionally tail-jumps to shared init routine 0x500170, forwarding the this pointer unchanged; six network/session initialization callers dispatch through it. Target routine is outside this packet.
- `0x0050099C` **D3DSurface** — D3D surface blit between source (a1) and destination (a4): null-guards both, builds source/destination rects from caller rects or the surface descriptor via vtable+0x20, and when no color key applies and the payloads are byte-identical over 0x400 bytes tries the hardware blit path (vtable dispatch, sub_500EAC lock toggle) with a CPU-side lock-copy fallback via D3DTextureSurfaceLockCopy (0x00506559) and NetworkPacketSendReceive (0x0050070D), releasing render resources before returning.
- `0x00500EAC` **D3D8DebugMuteCache** — Lazily resolves the D3D8 DebugSetMute function pointer, preferring retail d3d8.dll and falling back to debug d3d8d.dll (GetModuleHandleA/LoadLibraryA/GetProcAddress), caches it in globals 0x008B0094 (retail) and 0x008B0090 (debug), then invokes it with the mute-state argument a1.
- `0x00502BF4` **DualVTableContainer** — Destructor dispatcher for an object owning two vtable-backed children: if secondary child at this+4 is non-null calls its vtable entry 0 with flag 1, then if primary child at this+0 is non-null calls its vtable entry 0 with flag 1 and returns that result, else returns the stored secondary result.
- `0x00502F31` **D3DSurface** — Builds three size-header-prefixed float filter tables whose dimensions come from context-table pairs at dword indices 1046/1047/1048, gated by options flag bits 16/17/18; allocates a 12-byte-slot refcount array and a 16-byte per-source array, cross-references the second table, allocates/recycles 16-byte float coefficient records through a free list, drives convolution accumulation through the owning object's vtable+4 callback and slot finalization through vtable+8, returning 0 / -2147467259 / -2147024882.
- `0x00504508` **D3DSurface** — Copies pixels between two surfaces after validating matching pixel format (+4), zero source flag field (+0x10), and equal width/height/depth (+0x1058/+0x105C/+0x1060); DXT-compressed destinations delegate to DXTCompressedTextureBlockCopy (0x005033A5), otherwise a nested level/row loop qmemcpy's the per-row byte count (+0x1064) with row/vertical strides (+0x1050/+0x1054). Called by D3DContextInit (0x005063A5).
- `0x00504640` **D3DSurface** — Allocates a staging buffer of 16 bytes per surface-width element, dimension-validates a source/dest surface pair, fills it by walking the dest surface's depth-by-height grid and calling the source vtable slot +4 and dest vtable slot +8 per coordinate, then frees the buffer; returns 0 or -2147467259. Invoked from D3DContextInit.
- `0x00504731` **D3DSurface** — Dual staging-buffer surface transfer with overlap handling: guards on the mode byte at this+8 (must equal 1), allocates two 16-byte-element staging buffers sized from the surfaces' field 1046, copies overlapping rows through both surfaces' vtable slots into the first buffer and non-overlapping/trailing rows through the second surface's slot into the second buffer, frees both and returns 0 or -2147467259.
- `0x00504B37` **D3DSurface** — Interface-gated vector compositing dispatch (COMInterfaceVectorProcessingMethod): validates the header byte at v4+8 (must equal 5) and width/depth fields, normalizes odd dimensions, and dispatches on the header value through the jump table jpt_504C3F (21-30, 40, 50-52) to format-specific handlers, falling back to a generic 2x2 float-vector averaging path over 16-byte staging buffers. Called by D3DContextInit.
- `0x00504F5A` **D3DSurface** — Downscales a 3D (volume) texture by 2x per axis using 8-sample trilinear float averaging (0.125): validates the type tag (byte at +8 == 5) and halved destination dimensions, masks odd source dimensions even, allocates two 16-byte staging buffers, fetches 8 source floats per destination texel through the vtable slot +4 method, averages and writes, frees the buffers. Called by D3DContextInit.
- `0x005054EC` **D3DSurface** — Bilinear 2D texture resample: validates the type tag (byte at +8 == 3), derives construction flags from tag bits 0x20000 and BYTE2 bit 0, builds X/Y coordinate tables via MemoryAllocation_53ec (0x005053EC) from dimension pairs at indices 1046/1047, allocates two staging buffers, resamples every destination texel through vtable slot +4 (fetch) and slot +8 (row), applies weighted interpolation, frees everything. Called by D3DContextInit.
- `0x005058D2` **D3DSurface** — 3D trilinear texture resample: validates the type tag (byte at +8 == 3), derives construction flags from tag bits 0x10000/0x20000/0x40000, builds X/Y/Z coordinate tables via MemoryAllocation_53ec (0x005053EC) from dimension pairs at byte offsets 4184/4188/4192, allocates two staging buffers, resamples every destination texel through vtable slot +4 (fetch) and slot +8 (row) with 3-layer 8-tap weighted interpolation, frees everything. Called by D3DContextInit.
- `0x00506003` **D3DSurface** — Builds a weighted-blend vertex staging pipeline: guards on depth (offset 4192) equalling 1 on both objects, builds two coordinate remap tables via ComplexMemoryAllocationWithFloatComputation (0x00502C28), allocates a 12-byte-stride vertex buffer with refcounts and a free list, builds a 16-byte source contribution table, accumulates weighted source floats into destination vertices through the indirect vtable method, and recycles released slots. Called by D3DContextInit.
- `0x005064BF` **UnknownObject** — Zero-initializes four consecutive dwords of a __thiscall object (offsets 0x0/0x4/0x8/0xC) and returns the unchanged this pointer. Pure field writer with no guards or callees; used by NetworkPacketSendReceive (0x0050070D) and SurfaceBlitOperation (0x0050099C) to zero a setup block.
- `0x0050653E` **UnknownObject** — Releases a stored COM interface pointer by invoking the vtable entry at offset 40 (0x28) on the non-null pointer, then nulls the storage slot and returns 0; no-op when the pointer is already null.
- `0x00506559` **D3DTextureSurfaceCopier** — D3D surface lock-and-copy helper: tears down render resources (0x005064CF), queries the input surface descriptor, validates the optional source rect, probes hardware capability, creates a compatible surface, copies via CopyRects or locks the destination rect (vtable+0x24) with per-format alignment, fills the output descriptor with pitch/format/dimensions/rect, and persists this+0x0 (flags) / this+0x4 (input). Used by NetworkPacketSendReceive (0x0050070D) and SurfaceBlitOperation (0x0050099C) as the CPU blit fallback.
- `0x00506FD9` **SlabChildContainer** — Object destructor: installs the off_5ADB90 vtable, frees a 2D slab of 8-byte child entries via nested loops bounded by dword indices 1060-1064, frees buffers at indices 1070 and 1072, then delegates final cleanup to VtableSetFreeChild (0x00506CCC).

## Proposed classes

### D3DSurface

Direct3D surface/texture wrapper carrying a vtable pointer, pixel format, flags, and a dimension/stride block at 0x1050-0x1068 (width/height/depth reachable as both byte offsets 4184/4188/4192 and dword indices 1046/1047/1048). Its processing operations share the 16-byte-element staging-buffer protocol and the vtable slot +4 (fetch) / slot +8 (row-write) contract. Packet owner is DERIVED for blitSurface only; the rest of the methods have UnknownObject owners, so the grouping is GUESS beyond the shared layout evidence.

Methods: `0x0050099C`, `0x00502F31`, `0x00504508`, `0x00504640`, `0x00504731`, `0x00504B37`, `0x00504F5A`, `0x005054EC`, `0x005058D2`, `0x00506003`

- `obj+0x00000000` `void** vtable_ptr` (read, DERIVED)
- `obj+0x00000004` `uint32_t pixel_format` (read, DERIVED)
- `obj+0x00000010` `uint32_t surface_flags` (read, DERIVED)
- `obj+0x00000018` `uint32_t copy_loop_field` (read, GUESS)
- `obj+0x00000020` `void* descriptor_vtable_slot` (read, DERIVED)
- `obj+0x00001050` `uint32_t row_stride` (read, DERIVED)
- `obj+0x00001054` `uint32_t vertical_stride` (read, DERIVED)
- `obj+0x00001058` `uint32_t width` (read, DERIVED)
- `obj+0x0000105C` `uint32_t height` (read, DERIVED)
- `obj+0x00001060` `uint32_t depth_level_count` (read, DERIVED)
- `this+0x00000000` `void* source_surface_ptr` (read, DERIVED)
- `this+0x00000004` `void* destination_surface_ptr` (read, DERIVED)
- `this+0x00000008` `uint8_t transfer_mode_byte` (read, GUESS)
- `this+0x00000010` `uint32_t source_surface_flags` (read, GUESS)
- `this+0x00000018` `uint32_t source_copy_loop_field` (read, GUESS)
- `this+0x0000001C` `uint32_t read_unused_field` (read, GUESS)
- `this+0x00001054` `uint32_t source_vertical_stride` (read, DERIVED)
- `this+0x00001058` `uint32_t source_width` (read, DERIVED)
- `this+0x0000105C` `uint32_t source_height` (read, DERIVED)
- `this+0x00001060` `uint32_t source_depth_level_count` (read, DERIVED)
- `this+0x00001064` `uint32_t source_row_byte_count` (read, DERIVED)
- `this+0x00001068` `uint32_t source_trailing_field` (read, GUESS)

### D3DTextureSurfaceCopier

The lock-and-copy helper behind the CPU blit fallback: holds control flags at +0, the input surface pointer at +4, the created destination surface at +8 and the source surface at +C, tears down render resources, queries descriptors, creates a compatible surface and locks/copies through surface vtable slots +24/+36/+108/+112, filling an output descriptor with pitch, format, dimensions and rect.

Methods: `0x00506559`

- `this+0x00000000` `uint32_t control_flags` (read_write, DERIVED)
- `this+0x00000004` `void* input_surface_ptr` (read_write, DERIVED)
- `this+0x00000008` `void* destination_surface` (write, DERIVED)
- `this+0x0000000C` `void* source_surface` (read, DERIVED)

### AudioSampleState

Packed audio sample-state buffer used by the cross-fade routine: carries a start time, a float position, quantized Euler words, auxiliary/scalar channels, a bitfield channel and trailing payload words. The packed channel layout is only observable through raw arithmetic in the packet (offsets +8/+12/+16 position, +20/+22/+24 Euler words, +38..+50 scalar channels, +52/+56 payload words), with no dedicated field evidence refs; no fields are asserted.

Methods: `0x004FF8F0`


### D3D8DebugMuteCache

Lazily resolves and caches the D3D8 DebugSetMute function pointer from retail d3d8.dll (cached at 0x008B0094) or debug d3d8d.dll (cached at 0x008B0090), then invokes it with the mute-state argument. Module-global cache, not an instance object; the cached pointers are tracked as globals rather than class fields.

Methods: `0x00500EAC`


### DualVTableContainer

Object owning two vtable-backed children released in destructor order (secondary child at +4 first, primary child at +0 second) by calling vtable entry 0 with the delete flag 1; returns the primary result or the secondary result when the primary is null.

Methods: `0x00502BF4`

- `this+0x00000000` `void* primary_child_ptr` (read, DERIVED)
- `this+0x00000004` `void* secondary_child_ptr` (read, DERIVED)

### SlabChildContainer

Object whose destructor installs the off_5ADB90 vtable, frees a 2D slab of 8-byte child entries bounded by dword indices 1060-1064 (byte offsets 0x1090-0x10A0), frees buffers at indices 1070 (0x10B8) and 1072 (0x10C0), and delegates final cleanup to VtableSetFreeChild (0x00506CCC). Slab-dimension and child-array offsets are observable only through raw arithmetic (dword indices 1060-1072); only the vtable slot has a dedicated field evidence ref, so only it is asserted as a field.

Methods: `0x00506FD9`

- `this+0x00000000` `void** vtable_ptr` (write, DERIVED)

## Compatibility contracts

- **SurfaceCopyDimensionContract** — Surface pixel copies require matching pixel format (+4), zero source flag field (+0x10), and equal width/height/depth (+0x1058/+0x105C/+0x1060) between source and destination; the strided row-copy layout (row stride +0x1050, vertical stride +0x1054, per-row byte count +0x1064) is what a replacement must reproduce for uncompressed surfaces. Mismatch returns -2147467259.
- **StagingBufferElementContract** — The staging-buffer transfers, compositing, downscale, resample and vertex/filter-table builders all allocate 16-byte elements through OperatorNewNhMallocWrapper (0x00587C03), construct them via sub_5008C2 with element constructor sub_5007EC (0x005007EC), and free them with FreeWrapper_7bcf (0x00587BCF); element count scales with the surface width/height/depth dimensions.
- **D3D8DebugMuteLazyBinding** — DebugSetMute is resolved lazily: probe retail d3d8.dll (name at 0x005ADB24), fall back to debug d3d8d.dll (name at 0x005ADB40), resolve the export by name (0x005ADB30) and cache the pointers in 0x008B0094 (retail) / 0x008B0090 (debug) so later calls skip DLL resolution. A replacement must preserve the DLL-name strings, cache globals and the (retail-then-debug) resolution order.
- **LockCopyOutputDescriptor** — D3DTextureSurfaceLockCopy (0x00506559) fills the output descriptor with pitch, format, dimensions, the four rect coordinates, the extra a4/a6 values and 1-valued marker fields; it locks the destination rect with flags 1 (or 65537 when blitting a surface onto itself) after per-format (DXT 4-byte, odd 2-byte) rect alignment. A replacement blit fallback must honor this descriptor shape.
- **DualChildDestructor** — An object owning two vtable-backed children releases the secondary child at +4 first and the primary child at +0 second, each through vtable entry 0 with the delete flag 1, returning the primary result (or the secondary result when the primary is null). A replacement owning object must preserve this release order.
- **ThunkForwardingContract** — 0x004FFFA0 is a pure thunk that unconditionally tail-jumps to the shared init routine 0x500170, forwarding the this pointer unchanged; six network/session initialization callers depend on this forwarding and on the target routine taking this as its first argument.
- **CompositingFormatDispatch** — CompositingDispatch (0x00504B37) selects a format-specific handler from the header value through the jump table jpt_504C3F: 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 40, 50, 51, 52; a non-negative handler result is success and failure falls back to the generic 2x2 float-vector averaging path. A replacement must reproduce the same header-to-handler mapping.

## Unresolved

- In AudioSampleCrossFadeInterpolation the exact roles of sub_567010 and sub_567580 (Euler round-trip and quaternion interpolation) are DERIVED from caller/callee names only, and the float constants behind the 5.0 threshold, the 14981.386 rejection and the scale factors are grouped per operation without individual ownership.
- The audio packed channel block (four byte + four short auxiliary channels, scalar channels at +38/+40/+42/+44/+45/+46/+48/+50, the bitfield channel, payload words at +52/+56) is described in raw source but has no authoritative struct; the AudioSampleState fields are GUESS placements.
- In blitSurface the exact meaning of arguments a7/a8 (color-key parameters), the vtable blit/unlock entry offsets after the +32 descriptor query, and whether the hardware path and the CPU fallback produce identical output for all surface formats are unresolved.
- In DebugSetMuteLazyInit which DLL-name string literal lives at 0x005ADB24 (aD3d8dDll) versus 0x005ADB40 (ModuleName) is not resolved from raw source, and the exact mute-enable semantics of argument a1 are inferred from the debugger-API name.
- In DualVTableDestructor the identity of the two child object types and their vtable layouts is unknown; the value 1 passed to vtable entry 0 is a likely-delete flag whose meaning is unconfirmed.
- In filterTableInit the dimension indices 1046/1047/1048 into the context tables, the options flag bits 16/17/18, and the vtable+4 / vtable+8 callback signatures have no authoritative meaning; the LEGACY abi label 'Direct3D_Vertex_Buffer_Index_Buffer_Builder' conflicts with the observed filter-table semantics and was not adopted.
- In SurfacePixelCopy the compressed-format flag (obj+0xC), palette fields (obj+0x14, obj+0x30) and the read-but-unused this[2] (this+0x8), source+0x1C and source+0x1068 fields are not established; call frequency via D3DContextInit is unknown.
- In CopySurfaceViaStagingBuffer the exact operations of the source vtable slot +4 and dest vtable slot +8, and whether +4184/+4188/+4192 are width/height/depth or another dimension triple, are inferred from the allocation size and loop bounds, not confirmed.
- In SurfaceOverlapTransfer which of the two surfaces (this+0 vs this+4) is the source and which the destination is not certain; the 16-byte element stride and the 1046/1047/1048 field semantics are inferred from the loop structure.
- In CompositingDispatch the concrete struct layout of v5, the header value v14 as a format/pixel-type enum, the byte flag at v5+10, and the caller-frame addressing (a2 - 44 etc.) are unresolved; the width/depth fields at +4184/+4188/+4196/+4200 are grounded in arithmetic only.
- In Downscale3DTextureHalfTrilinear the meaning of offsets 4196 and 4200 (adjusted when a source width is masked even) and the four __usercall register arguments passed to the vtable fetch method are unresolved; the both-equal-1 dimension exceptions may be a mipmap-with-depth-1 special case.
- In ResampleTextureBilinear the tag bits 0x20000 and BYTE2 bit 0 that drive coordinate-table construction, the destination row stride, the -1 sentinels used to reuse buffer slices, and the precise role of the vtable slot +8 call are unresolved.
- In ResampleTextureTrilinear3D the tag bits 0x10000/0x20000/0x40000, whether the four interpolated channels are RGBA floats, and the -1 sentinel slice reuse are unresolved.
- In CreateVertexBlendBufferWithFreelist the identity of the two objects at v1[0]/v1[1], the meaning of the depth field at offset 4192, the indirect vtable methods at *(*(*v2)+4) and *(*(*v2[1])+8), and the remap-table entry layout (dword count header plus paired dword records) are unresolved.
- ZeroInit4Ints (0x005064BF) and VTableReleaseClear (0x0050653E) have unknown owners; the four zeroed dwords span network-packet and surface-blit callers, and the identity of the vtable+40 (0x28) method (Release vs Unlock vs other) is not confirmed.
- In D3DTextureSurfaceLockCopy the surface vtable method identities at offsets 32, 28, 12, 36, 108, 112 (GetDesc, CreateCompatibleSurface, CopyRects, LockRect), the meaning of the unk_5AD4C0/unk_5AD4D0 descriptor buffers and a3[4] bit 26, and the exact DXT/odd-aligned format codes are not established; the sub_500EAC(1)/sub_500EAC(0) pairing is DERIVED as a likely global lock/unlock guard.
- In ComplexDestructorWithLoop the exact storage layout of the freed 8-byte child entries (first dword unused, second dword a heap pointer) and the full behavior of VtableSetFreeChild (0x00506CCC) are inferred; the SEH jump targets' roles are not visible in the decompiled bodies.
- Field bases `this` and `obj` recur across different functions for the same numeric offsets (notably +0, +4, +8, +0x1058-0x1068); per rule, equal offsets on different bases are never merged and common ownership of the dimension/stride block is supported only by the packet's cross-referencing of dword indices 1046/1047/1048.
- CompositingDispatch references jpt_504C3F via global 0x00504F3A; the enumerated header values 21-30, 40, 50-52 are DERIVED from the jump table shape and are not confirmed as a documented format enum.
- All staging-buffer, downscale, resample and vertex/filter-table functions install a structured exception handler via SEHHandlerInit (0x0058A5D8); the exception landing-pad labels (loc_59C432, loc_59C450, loc_59C496, loc_59C4BE, loc_59C4DC, loc_59C4FA, loc_59C522, loc_59C534) are recorded in unresolved_evidence_refs and their roles are not described.
