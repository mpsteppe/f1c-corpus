# GenericRuntimeObjects

Scope: `generic_runtime_objects`  
Trust: `DERIVED`

Reconstructs the generic runtime object layer from twenty-five validated functions. Six GUESS classes cover the strongest common-ownership clusters: DirectXTextureSurfaceWrapper (constructor 0x0050AFE2 plus blit-with-color-space 0x0050B47E share the this+0x1030..0x10C0 extent/codec/format cache), DirectXSurfaceNegotiationBuffer (the 84-byte stack value type cleared by 0x00500F3C and torn down by 0x00500F55 in the render-region helpers), DecodedImageSurface (PPM decode output 0x00501E39), PngDecompressionContext (PNG/zlib context init 0x005118E6), ZoneThresholdController (0x004FFFB0), and MultiFieldResetRegion (0x004FC280, embedded at +0x108 inside the object initialized by 0x004FC9C0). PositionTargetState groups 0x004FC9C0, 0x004FAEC0 and 0x004FC910 on overlapping +0x0..+0x14 field regions; this identity is inferred, not proven, and is flagged in unresolved. Two GUESS interfaces capture the D3D surface vtable used by 0x00500BC8 and the shared allocator/free wrappers (0x00587C03 / 0x00587BCF). Fifteen functions (0x004FAEC0 helpers except where classed, threshold classifier, merge sort, wrappers, thunks, resets, destructors) remain UnknownObject where the packet gives no owner evidence. Two state machines are proposed: the PPM header/pixel token state machine and the software-rasterizer sub-pixel occupancy accumulator. No function could be assigned an owner above GUESS; all twenty-five packet owners are UNKNOWN.

## Function roles

- `0x004FAEC0` **PositionTargetState** — 3D position-delta computation: when the this+0x110 pointer is non-null writes delta = *(this+0x110) - inline triple (this+0/+4/+8) into this+0xC/+0x10/+0x14; else when this+0x10C is non-null writes delta = inline triple - *(this+0x10C); else writes the default (0, 0, -1.0f). Return value is a decompiler artifact.
- `0x004FC280` **MultiFieldResetRegion** — Multi-field state block reset: writes the sentinel -1 at +0x44, clears +0x0 and the three-dword block at +0x10..+0x18, conditionally frees the +0x4C pointer via FreeWrapper_7bcf, clears +0x48/+0x4C/+0x50/+0x70, captures +0x80, frees it via FreeWrapper_7bcf, clears +0x7C/+0x80/+0x84/+0xA4, and returns the captured (or freed) pointer. Invoked on the +0x108 region by StructInitWithFloatDefaults.
- `0x004FC910` **PositionTargetState** — Packed 16-bit decode: unpacks six 16-bit values into six floats (this[0..3] as unsigned scaled by 1/65536 via global 0x005AD290, this[4..5] as signed scaled by 1/128 via global 0x0059E774) and returns the raw signed 16-bit value at input offset 18. Called by CarPositionTargetCheck.
- `0x004FC9C0` **PositionTargetState** — Straight-line structure initializer (returns this): delegates the +0x20 sub-object to sub_4FC850 and the +0x108 region to MultiFieldReset (0x004FC280), seeds a float/dword run (1.0f at +0x0, zeroed +0x4..+0x18, +0x24..+0x3C, +0x40/+0x44), initializes a sentinel WORD block (+0x48..+0x52) and the +0x54..+0x60 dword run, then initializes the range-interpolation table via RangeInterpolationTable (0x004FD6F0).
- `0x004FEAA0` **UnknownObject** — Float-to-status classifier: returns 2 when a1 < 0.61650002, 3 when a1 < 0.69999999, 5 when a1 >= 0.88, and 4 otherwise. Threshold literals likely backed by globals flt_59E6E8, flt_5A0038 and flt_5AD334 (mapping not established).
- `0x004FF2B0` **UnknownObject** — Recursive merge sort of a singly-linked list ordered by a float key: nodes hold a pointer to their key at +0 (compared as **(float**)node) and a next pointer at +4; counts nodes, splits at count/2-1, sorts both halves recursively (self-call), and merges in ascending key order. Called by AudioEventRingBufferProcessing.
- `0x004FF670` **UnknownObject** — Thiscall passthrough wrapper: forwards this to an unenumerated callee and returns this unchanged. The callee has no packet evidence ref; the wrapper's net effect beyond delegation plus identity return is unknown.
- `0x004FFFB0` **ZoneThresholdController** — Zone-threshold comparison and dispatch: classifies the float at a3+4 against the upper threshold this+0xC and the lower threshold this+0x1BC; when v3 <= this+0x1BC no action is taken, when v3 in (this+0x1BC, a2] calls ArithmeticComparison_3a90 with (this+0x1B8, a3), and when a2 < v3 < this+0xC calls it with (this+0x8, a3). Used for zone/region state management; called by NetworkMessageDispatch and sub_4B9000.
- `0x005000C0` **UnknownObject** — Forwarding wrapper for the audio parameter interpolation routine: calls AudioParameterInterpolation(a1, a2, a3, 0.0) and returns its char result unchanged. The constant fourth argument 0.0 is ungrounded in this packet.
- `0x005001F0` **UnknownObject** — Sentinel guard: returns TRUE when the float at this+0xC differs from the FLT_MAX-like sentinel 9.9999997e37 (loaded from the constant pool at 0x005AD34C), i.e. once the field has been written by an initialiser; used as a skip-guard across collision/iteration callers.
- `0x005006D5` **UnknownObject** — stdcall wrapper around render-region negotiation: initializes an 84-byte stack buffer via InitializeSevenDwords (0x00500F3C), calls DirectXSurfaceFormatNegotiation(a1, a2, a3, 0), propagates a negative HRESULT-style result, runs the teardown via ArithmeticComparison_0f55 (0x00500F55), and returns the result. The legacy ABI name Lock_Unlock_Wrapper is not confirmed by any lock operation.
- `0x005008E4` **UnknownObject** — Validated render-region copy: initializes a 21-dword local buffer via 0x00500F3C, guards a1/a4/a5 non-null, negotiates the surface format via DirectXSurfaceFormatNegotiation(a4, a5, a9, 1), copies and bounds-checks a source rectangle (error -2005530516 on failure), performs the copy through NetworkPacketSendReceive, returns 0 on success, and always tears the buffer down via 0x00500F55.
- `0x00500BC8` **UnknownObject** — D3D surface copy/blit across mip levels and cubemap faces: validates the destination surface type via its vtable (+40; 3 = 2D texture, 4 = 3D volume, 5 = cubemap), auto-selects a mip flag from power-of-two dimension checks when a4 is -1, iterates faces (1 for types 3/4, 6 for cubemap) and mip levels, locks each surface via vtable +60, blits with SurfaceBlitOperation (0x0050099C) or Direct3DTextureVertexBufferInit (0x00500B42), releases locks via vtable +8, and returns -2005530516 on NULL/type/mip errors.
- `0x00500F3C` **DirectXSurfaceNegotiationBuffer** — Seven-dword initializer: unconditionally clears the scattered fields this+0x0, +0x4, +0x8, +0x38, +0x3C, +0x4C, +0x50 to 0 and returns this. Shared sub-structure initialization used by LockUnlockWrapper, RenderRegionCopyWithValidation, and DDSTextureSurfaceCreation.
- `0x00501E39` **DecodedImageSurface** — PPM image decoder: validates the P3/P6 signature, parses width/height/max-value tokens (whitespace and comment skipping via 0x00589BF3 / 0x00589B9E), allocates the 4*w*h BGRA pixel buffer via OperatorNewNhMallocWrapper, converts RGB samples normalized by max value into 4-byte BGRA pixels, and writes the result object (format id 22 at +0x0, buffer at +0x4, width +0xC, height +0x10, +0x14, stride +0x30, +0x34, ownership +0x38). Returns 0 on success, -2147467259 or 0x80004005 on invalid input or short data.
- `0x00507079` **UnknownObject** — Software-rasterizer sub-pixel quad accumulation: runs under an SEH frame (0x0058A5D8), advances X/Y accumulation cursors (this+0x8/+0xC), lazily allocates an 8-bytes-per-element slot grid (0x00587C03), derives the slot address from the grid base (stored to this+0x10), lazily allocates a 16-byte-element staging buffer initialized by 0x005008C2 with the 0x005007EC constructor, fills sub-pixel rows from the source surface, copies the incoming 4-dword quad, sets the sub-pixel occupancy bitfield, flushes via the row callback when the bitfield reaches 15 (freeing the staging buffer via FreeWrapper_7bcf or recycling it), and optionally runs DirectXVertexBufferFormatConversion (0x00506CE2).
- `0x005076E2` **UnknownObject** — Classic scalar deleting-destructor pattern: marks the object freed via VtableSetFreeChild (0x00506CCC), and when flag a2 bit 0 is set frees the storage via FreeWrapper_7bcf (0x00587BCF); always returns this. Concrete class is not identifiable.
- `0x0050AFE2` **DirectXTextureSurfaceWrapper** — Texture surface wrapper construction completion: initializes the base via DirectXTextureCreationWithMipmapChain (0x00507496), installs the wrapper vtable off_5ADB90 at this+0x0, maps two source format codes (a2+24 and a2+28) onto +0x1078/+0x107C, derives the combined encoder flag +0x1074, selects per-FourCC bytes-per-pixel and codec function-pointer slots (+0x1080/+0x1084/+0x1088), seeds the -1 sentinel state at +0x10B0/+0x10B4, and computes 4-aligned extents and element counts (+0x108C..+0x10AC).
- `0x0050B47E` **DirectXTextureSurfaceWrapper** — Texture surface blit with color-space conversion: runs under an SEH frame (0x0058A5D8), lazily allocates an intermediate width*256 conversion buffer (0x00587C03) initialized by 0x005008C2 with the 0x005007EC callback, updates cached source width/height when the aligned input changes, blits scanlines through the indirect row-blit callback, copies 16-byte pixels from the conversion buffer to the output pointer this+0x10, and on the decode pass zeroes pixels whose decoded RGBA equals a reference color; returns dword_8B009C on the decode path.
- `0x0050C021` **UnknownObject** — Thunk forwarding a render-object cleanup request to DestructorWithResourceCleanup_b830 and returning its result. The caller at 0x0050C026 and the legacy ABI name identify a render-object destructor entry point, but the owning class is not confirmed.
- `0x0050CBB0` **UnknownObject** — Forwarding thunk: indirectly calls the function pointer held in global off_5D77D4 with no arguments and returns its int result unchanged. The target is assigned elsewhere at runtime.
- `0x0050CDF9` **UnknownObject** — Pure indirection thunk: transfers control to the function held in global off_5D785C and returns its result unchanged, with no stack setup or argument marshalling. Invoked from SkeletonBoneTransformConstruction and sub_55CC20.
- `0x005115C4` **UnknownObject** — Unconditional state reset: zeroes the command counter at this+0x7C, the slot lookup table pointer at this+0xC4, and the current marker byte at this+0x178, then via the sub-object pointer at this+0x190 zeroes the byte-stuffing mode byte (+0x50), the control flag byte (+0x51), and the byte counter (+0x58, flattened to this+0x1E8). Returns the sub-object pointer. The JPEG-decoder reading is existing-analysis prose only.
- `0x0051166B` **UnknownObject** — Unconditional dispatch chain: reads the vtable pointer from this+0x0 and calls its third entry (offset +8) with a1, then chains sub_516959(a1) and UtilityFunction_9ca4(1), and returns the result of an implicit VtableDispatchThunk(a1).
- `0x005118E6` **PngDecompressionContext** — PNG/zlib decompression context initializer: allocates and zero-initializes the context (0x00517E43), installs a setjmp/longjmp error-recovery frame (0x0058A7EC), stores three init parameters via TripleFieldSetter_184f, validates the libpng version string starts with '1' (else raises the incompatible-version error via 0x00511869), configures the 0x2000 window (sub_517E92), registers the read callback sub_513C80 and the safe-delete thunk (+132/+136/+140), initializes the zlib stream (0x00517AC5, version 1.1.3, window 56), routes zlib errors (-6 version, -4/-2 memory, other unknown) to longjmp handlers, and returns the context pointer.

## Proposed classes

### DirectXTextureSurfaceWrapper

DirectX texture surface wrapper: vtable head (off_5ADB90), source-dimension/pitch reads, two source format-code mappings with a combined encoder flag, per-FourCC bytes-per-pixel and codec function-pointer slots, 4-aligned extents and element-count cache; constructed by 0x0050AFE2 and blitted with optional color-space conversion by 0x0050B47E. Both methods share the this+0x1030..0x10C0 state region.

Methods: `0x0050AFE2`, `0x0050B47E`

- `this+0x00000000` `void* vtable_ptr` (read_write, GUESS)
- `this+0x00000004` `dword codec_case_dword` (read, GUESS)
- `this+0x00001030` `dword source_x_origin` (read, GUESS)
- `this+0x00001034` `dword source_y_origin` (read, GUESS)
- `this+0x00001038` `dword source_width` (read, GUESS)
- `this+0x0000103C` `dword source_height` (read, GUESS)
- `this+0x00001040` `dword source_pitch` (read, GUESS)
- `this+0x00001044` `dword source_depth_extra` (read, GUESS)
- `this+0x00001074` `dword format_needs_encoder` (read_write, GUESS)
- `this+0x00001078` `dword source_format_code_a` (read_write, GUESS)
- `this+0x0000107C` `dword source_format_code_b` (read_write, GUESS)
- `this+0x00001080` `dword bytes_per_pixel` (read_write, GUESS)
- `this+0x00001084` `void* codec_func_slot_a` (read_write, GUESS)
- `this+0x00001088` `void* codec_func_slot_b` (read_write, GUESS)
- `this+0x0000108C` `dword aligned_x_origin` (read_write, GUESS)
- `this+0x00001090` `dword aligned_y_origin` (read_write, GUESS)
- `this+0x00001094` `dword aligned_width` (read_write, GUESS)
- `this+0x00001098` `dword aligned_height` (read_write, GUESS)
- `this+0x0000109C` `dword cached_source_pitch` (read_write, GUESS)
- `this+0x000010A0` `dword cached_source_depth` (read_write, GUESS)
- `this+0x000010A4` `dword element_count_x` (read_write, GUESS)
- `this+0x000010A8` `dword element_count_y` (read_write, GUESS)
- `this+0x000010AC` `dword depth_delta` (read_write, GUESS)
- `this+0x000010B0` `dword negative_sentinel_a` (read_write, GUESS)
- `this+0x000010B4` `dword negative_sentinel_b` (read_write, GUESS)
- `this+0x000010B8` `dword working_slot_a` (read_write, GUESS)
- `this+0x000010BC` `dword working_slot_b` (read_write, GUESS)
- `this+0x000010C0` `dword working_slot_c` (read_write, GUESS)

### DirectXSurfaceNegotiationBuffer

Small shared stack value type used by the render-region negotiation helpers: seven scattered DWORDs (this+0x0/+0x4/+0x8/+0x38/+0x3C/+0x4C/+0x50) cleared by InitializeSevenDwords (0x00500F3C) before use and torn down by ArithmeticComparison_0f55 (0x00500F55); the 84-byte local buffer in LockUnlockWrapper and RenderRegionCopyWithValidation.

Methods: `0x00500F3C`

- `this+0x00000000` `dword cleared_dword_0` (write, GUESS)
- `this+0x00000004` `dword cleared_dword_1` (write, GUESS)
- `this+0x00000008` `dword cleared_dword_2` (write, GUESS)
- `this+0x00000038` `dword cleared_dword_3` (write, GUESS)
- `this+0x0000003C` `dword cleared_dword_4` (write, GUESS)
- `this+0x0000004C` `dword cleared_dword_5` (write, GUESS)
- `this+0x00000050` `dword cleared_dword_6` (write, GUESS)

### DecodedImageSurface

Decoded image surface produced by ParseAndDecodePPM (0x00501E39): format id, BGRA pixel buffer, width/height, row stride, and ownership flag; consumed by DirectXSurfaceFormatNegotiation (0x00502A15).

Methods: `0x00501E39`

- `this+0x00000000` `dword format_id` (write, GUESS)
- `this+0x00000004` `void* pixel_buffer_ptr` (write, GUESS)
- `this+0x0000000C` `dword width` (write, GUESS)
- `this+0x00000010` `dword height` (write, GUESS)
- `this+0x00000014` `dword aspect_flag` (write, GUESS)
- `this+0x00000030` `dword row_stride` (write, GUESS)
- `this+0x00000034` `dword reserved_dword` (write, GUESS)
- `this+0x00000038` `dword buffer_owned` (write, GUESS)

### PngDecompressionContext

PNG/zlib decompression context allocated and configured by PngReadContextInit (0x005118E6): libpng version check, setjmp error-recovery frame, 0x2000 window size, read-callback trio (+132/+136/+140), zlib stream at +100, and zlib/longjmp error routing.

Methods: `0x005118E6`

- `this+0x00000000` `byte version_string_byte` (read, GUESS)

### ZoneThresholdController

Zone/region state controller: classifies an incoming float (a3+4) against an upper threshold (+0xC) and a lower threshold (+0x1BC) and dispatches ArithmeticComparison_3a90 on either the +0x8 or +0x1B8 target pointer, blocking values at or below the lower threshold.

Methods: `0x004FFFB0`

- `this+0x00000008` `void* upper_zone_target` (read, GUESS)
- `this+0x0000000C` `float upper_threshold` (read, GUESS)
- `this+0x000001BC` `float lower_threshold` (read, GUESS)

### PositionTargetState

Position/interpolation target state: inline origin triple (+0/+4/+8), delta (+0xC/+0x10/+0x14), optional reverse/forward end pointers (+0x10C/+0x110), a small initialized sub-object (+0x20), scalar and sentinel-WORD default runs (+0x24..+0x60), and an embedded MultiFieldReset region (+0x108). Initialized by StructInitWithFloatDefaults and consumed by Compute3DPositionDelta and UnpackPacked16BitToFloats. Identity across the three functions is inferred from overlapping field regions, not proven.

Methods: `0x004FC9C0`, `0x004FAEC0`, `0x004FC910`

- `this+0x00000000` `float origin_x` (write, GUESS)
- `this+0x00000004` `float origin_y` (write, GUESS)
- `this+0x00000008` `float origin_z` (write, GUESS)
- `this+0x0000000C` `float delta_x` (write, GUESS)
- `this+0x00000010` `float delta_y` (write, GUESS)
- `this+0x00000014` `float delta_z` (write, GUESS)
- `this+0x00000018` `dword zero_dword_1` (write, GUESS)
- `this+0x00000020` `void* sub_object_ptr` (write, GUESS)
- `this+0x00000024` `dword zero_dword_2` (write, GUESS)
- `this+0x00000028` `dword zero_dword_3` (write, GUESS)
- `this+0x0000002C` `dword zero_dword_4` (write, GUESS)
- `this+0x00000030` `dword zero_dword_5` (write, GUESS)
- `this+0x00000034` `dword zero_dword_6` (write, GUESS)
- `this+0x00000038` `dword zero_dword_7` (write, GUESS)
- `this+0x0000003C` `dword zero_dword_8` (write, GUESS)
- `this+0x00000040` `dword zero_dword_9` (write, GUESS)
- `this+0x00000044` `dword zero_dword_10` (write, GUESS)
- `this+0x00000048` `word sentinel_word_0` (write, GUESS)
- `this+0x0000004A` `word sentinel_word_1` (write, GUESS)
- `this+0x0000004C` `word sentinel_word_2` (write, GUESS)
- `this+0x0000004E` `word sentinel_word_3` (write, GUESS)
- `this+0x00000050` `word sentinel_word_4` (write, GUESS)
- `this+0x00000052` `word sentinel_word_5` (write, GUESS)
- `this+0x00000054` `dword zero_dword_11` (write, GUESS)
- `this+0x00000058` `dword zero_dword_12` (write, GUESS)
- `this+0x0000005C` `dword zero_dword_13` (write, GUESS)
- `this+0x00000060` `dword zero_dword_14` (write, GUESS)
- `this+0x0000010C` `void* reverse_start_ptr` (read, GUESS)
- `this+0x00000110` `void* forward_end_ptr` (read, GUESS)

### MultiFieldResetRegion

Embedded state block reset by MultiFieldReset (0x004FC280): -1 sentinel at +0x44, zeroed header and tail fields, two conditionally-freed owned buffers (+0x4C and +0x80) released through FreeWrapper_7bcf, and cleared byte flags. Embedded at +0x108 inside the object initialized by StructInitWithFloatDefaults.

Methods: `0x004FC280`

- `this+0x00000000` `dword header_dword` (write, GUESS)
- `this+0x00000010` `dword block_dword_0` (write, GUESS)
- `this+0x00000044` `dword sentinel` (write, GUESS)
- `this+0x00000048` `dword adjacent_dword_0` (write, GUESS)
- `this+0x0000004C` `void* owned_buffer_a` (read_write, GUESS)
- `this+0x00000050` `byte flag_byte_a` (write, GUESS)
- `this+0x00000070` `dword far_dword` (write, GUESS)
- `this+0x0000007C` `dword adjacent_dword_1` (write, GUESS)
- `this+0x00000080` `void* owned_buffer_b` (read_write, GUESS)
- `this+0x00000084` `byte flag_byte_b` (write, GUESS)
- `this+0x000000A4` `dword tail_dword` (write, GUESS)

## Compatibility contracts

- **PpmDecodeSurfaceContract** — Decoding a PPM image must validate the P3/P6 magic, parse width/height/max-value tokens, allocate the 4*w*h BGRA pixel buffer (via 0x00587C03), and fill the output object: format id 22 at +0x0, buffer pointer at +0x4, width +0xC, height +0x10, +0x14 = 1, row stride 4*width at +0x30, +0x34 = 0, ownership flag 1 at +0x38.
- **PngReadContextInitContract** — Initializing a PNG/zlib context must allocate and zero-init the block, install a setjmp frame, store three init parameters, require the libpng version string to start with '1', configure a 0x2000 window, register the read callback sub_513C80 and safe-delete thunk (+132/+136/+140), initialize the zlib stream (version 1.1.3, window 56), copy +112/+116, finalize via sub_513BF9, and route zlib errors -6/-4/-2/other to longjmp handlers.
- **TextureSurfaceFormatMappingContract** — Completing a texture surface wrapper must install vtable off_5ADB90, map the source format codes (a2+24 to +0x1078, a2+28 to +0x107C; 1->0, 2->1, else 3), derive +0x1074 = (0x1078 != 3) OR (0x107C != 3), select per-FourCC bytes-per-pixel and codec function-pointer slots (+0x1080/+0x1084/+0x1088), seed the -1 sentinel state (+0x10B0/+0x10B4), compute 4-aligned extents and element counts (+0x108C..+0x10AC), and zero the working slots (+0x10B8..+0x10C0).
- **TextureSurfaceBlitColorSpaceContract** — Blitting a texture surface with color-space conversion must lazily allocate the width*256 conversion buffer (via 0x00587C03), initialize its 16-byte rows (0x005008C2 with the 0x005007EC constructor), re-run the scanline row-blit when the aligned source width/height differ from the cached values, copy 16-byte pixels to the output pointer this+0x10, and on the decode pass zero pixels whose decoded RGBA equals the reference color.
- **MultiFieldResetContract** — Resetting the multi-field block must write -1 at +0x44, clear +0x0 and the three-dword block +0x10..+0x18, conditionally free +0x4C via FreeWrapper_7bcf, clear +0x48/+0x4C/+0x50/+0x70, capture +0x80, free it via FreeWrapper_7bcf, clear +0x7C/+0x80/+0x84/+0xA4, and return the captured (or freed) pointer.
- **ZoneThresholdDispatchContract** — Zone dispatch must classify the float at a3+4 against the lower threshold this+0x1BC and the upper threshold this+0xC: v3 <= this+0x1BC is blocked; v3 in (this+0x1BC, a2] calls ArithmeticComparison_3a90 with (this+0x1B8, a3); a2 < v3 < this+0xC calls it with (this+0x8, a3).

## Unresolved

- All twenty-five packet functions carry owner trust UNKNOWN; every class and interface above is a GUESS grouping, not a confirmed owner.
- PositionTargetState identity across 0x004FC9C0 / 0x004FAEC0 / 0x004FC910 is inferred from the overlapping +0x0..+0x14 field regions (origin triple, delta, packed-16-bit outputs); the packet does not prove common ownership.
- 0x004FC9C0 writes this+0x48..+0x52 as WORDs while 0x004FC280 zeroes this+0x48/+0x4C/+0x50 as DWORDs; the two are modelled as different objects (outer object vs the +0x108 embedded region) but the field overlap at the same base offsets is unresolved.
- The MultiFieldReset target at this+0x108 inside the StructInit object has no packet field evidence ref; the +0x108 embedding is stated from raw control flow only.
- 0x004FAEC0 return value is a decompiler artifact (LODWORD of a stored float); whether the inline triple is a stored position or a reference depends on caller sub_402690, outside this packet.
- 0x004FC910 six decoded components (color/luminance vs position/normal) and the sentinel-WORD block meaning in 0x004FC9C0 are inferred from scale globals and literal patterns only.
- 0x004FEAA0 status codes 2-5 are unnamed; the mapping of the threshold literals 0.61650002 / 0.69999999 / 0.88 to globals flt_59E6E8, flt_5A0038, flt_5AD334 is not established.
- 0x004FF2B0 node layout is unusual: +0 holds a pointer to the float key in a separate storage area; caller AudioEventRingBufferProcessing semantics are outside this function.
- 0x004FF670 forwards to a callee absent from the packet callee table; the wrapper's net effect is unknown beyond delegation plus identity return.
- 0x004FFFB0 this+8 and this+0x1B8 (dispatch targets) and a3+4 have no packet field evidence refs; the a2 boundary semantics are inferred from the guards.
- 0x005000C0 constant fourth argument 0.0 to AudioParameterInterpolation is ungrounded; single caller sub_4B9AC0 is not analyzed.
- 0x005001F0 owner of the +0xC sentinel field and who writes the sentinel are unknown; 9.9999997e37 as an unset marker versus a real max-float value cannot be distinguished here.
- 0x005006D5 / 0x005008E4: the semantics of the 84-byte/21-dword buffer and the F_7FieldInitializer/ArithmeticComparison_0f55 pair are external; the HRESULT-style reading of the negotiation result is inferred, and the legacy Lock_Unlock_Wrapper name is not confirmed by any lock operation.
- 0x005008E4 role of a2/a3 in NetworkPacketSendReceive is caller-supplied and not identifiable.
- 0x00500BC8 D3D interface identities behind vtable slots +40/+52/+56/+60/+8 are inferred from the guard values; the composition of the flag constants 5 / 0 / 524292 is not confirmed.
- 0x00500F3C scattered cleared fields (+0x0/+0x4/+0x8/+0x38/+0x3C/+0x4C/+0x50) with untouched gaps have an unknown layout purpose.
- 0x00501E39 ASCII channel-assembly bit layout is reconstructed as BGRA from raw arithmetic only; format id 22 / stride / ownership consumers are not visible in this function.
- 0x00507079 high state-array indices (state[1036]..state[1072]) lie beyond the four declared fields; the SEH jump label loc_59C548 is unverifiable from this packet.
- 0x005076E2 concrete class is unidentifiable; FreeWrapper_7bcf deallocation semantics (plain free vs operator delete vs refcount release) are not established.
- 0x0050AFE2 FourCC literals (827611204, 844388420, 861165636, 877942852, 894720068) are not resolved to named pixel formats; the roles of the +0x1084/+0x1088 codec slots (encoder/decoder vs error-check) are unconfirmed.
- 0x0050B47E device/surface object offsets (+4148..+4280) are not exposed as packet field evidence; six globals (loc_59C58C, flt_59E450, flt_5ACCD0..flt_5ACCDC) do not appear in the raw decompiled source text.
- 0x0050C021 resources released by DestructorWithResourceCleanup_b830 are outside this packet; the render-object destructor owner class is unconfirmed.
- 0x0050CBB0 / 0x0050CDF9 runtime targets off_5D77D4 / off_5D785C are assigned elsewhere; callee prototypes are unknown.
- 0x005115C4 the JPEG-decoder interpretation comes from existing analysis prose only; whether the sub-object at +0x190 is a genuinely offset-embedded object or a separate heap allocation is unresolved.
- 0x0051166B VtableDispatchThunk is called and returned but is absent from the packet callee table; the purpose of the dispatch chain is undocumented.
- 0x005118E6 context offsets +100/+112/+116/+132/+136/+140/+156/+160 are the primary state but are not exposed as packet field evidence; the exact longjmp trigger contract (ConditionalCall_7ec8) is not fully visible.
