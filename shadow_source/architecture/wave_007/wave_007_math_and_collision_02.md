# MathAndCollision

Scope: `math_and_collision`  
Trust: `DERIVED`

Proposal for the math_and_collision slice of Wave 7. The functions fall into six groups. (1) Chunked pointer-index array allocators (0x005160AD element variant, 0x0051613F buffer variant scaled by 2^7) that allocate a 4-byte-per-entry index array via MemoryAllocator (0x00515F23) and fill it by bulk-chunk allocation through MemoryAllocatorWithAlignment (0x0051601F), capping the chunk at min(0x3B9AC9F0 / stride, a4), storing it at this+0x50, and dispatching the shared error path (constant 69 at obj+0x14, vtable call through obj+0x0) when a stride exceeds the 1,000,000,000-byte ceiling; both are consumed by DirectXTextureSurfaceAllocation (0x0051629F). (2) Scalar and SSE vector math writing 3/4-float or __m128 outputs at a1: normalization with a zero-length guard and a table-based fast reciprocal-sqrt approximation (0x005176EC), threshold-gated normalizers with Newton-Raphson refined reciprocal square roots driven by the read-only globals in the 0x008D6000..0x008D6188 region (0x0051EDAE, 0x0051EE7E, 0x0052035E) and the 0x005D8BE0/0x005D8BF0 region (0x0051FC80), weighted blends/interpolations (0x0051EC00, 0x0051F5F0, 0x0051F650, 0x0051F700 with the dword_8B00E0 zero sentinel), and SSE cross-product-like routines applying sign-flip XOR masks (0x0051F0BE, 0x005207CE). (3) SSE matrix math: a 3x3 matrix multiply with XOR masks xmmword_8D6100/60F0/60E0 (0x0051FBF0) and a 4x4-matrix-by-4-vector multiply with an alignment dispatch (0x0052014E). (4) The 3DNow/MMX packed-vector family (0x00520F69, 0x00520FC6, 0x005215DB, 0x0052179F, 0x00521831, 0x0052193C, 0x005262C2) sharing the tiny zero-length threshold literal 0x80000000800000 (associated with qword_5AF970, DERIVED), fallback/scale constants (0x005AF8F0, 0x005AF908) and packed-qword constants in the 0x005AF8F0..0x005AF9E8 region, every helper bracketed by _m_femms; 0x005215DB (slerp) calls F_3DVectorNormalize_8f00 (0x00528F00) and the sub_529700 helper (0x00529700) twice, and is itself called three times by the blend 0x0052179F. (5) 3DNow/MMX 4x4 matrix helpers (0x005261CE, an MMX-flushed stdcall wrapper around 0x00525E9A, and 0x005265DB, a packed-float 4x4 combination shared by callers 0x005267A7/0x0052692F/0x00526B55). (6) Data/utility processors: nearest-neighbor palette vector quantization (0x0051D897, reading count this+0x70 and palette this+0x74 with three component arrays), a vtable-driven virtual-object array fill (0x0051EA5A) and a pure big-endian byte-to-int utility (0x00517F35). Row/column-major conventions, threshold/constant values, and the exact 3DNow lane algebra are unresolved packet-level questions.

## Function roles

- `0x005160AD` **ChunkedArrayAllocator** — Chunked element allocator: allocates a pointer-index array of a4 elements via MemoryAllocator (0x00515F23), then fills it by allocating a4 elements in bulk chunks through MemoryAllocatorWithAlignment (0x0051601F), each chunk at most v5 = min(0x3B9AC9F0 / a3, a4) elements. The chunk size is stored at this+0x50 (base pointer cached from this+0x4). An element size exceeding the 0x3B9AC9F0 allocation ceiling triggers the error path: constant 69 written at obj+0x14 and a vtable dispatch through the object vtable at obj+0x0, passing a1. Returns the pointer-index array; consumed by DirectXTextureSurfaceAllocation (0x0051629F).
- `0x0051613F` **ChunkedArrayAllocator** — Chunked buffer allocator, structural twin of 0x005160AD with element units scaled by 2^7 (128 bytes per buffer): allocates a pointer-index array of a4 entries via MemoryAllocator (0x00515F23), then fills it by allocating a4 buffers in bulk chunks through MemoryAllocatorWithAlignment (0x0051601F), where each buffer is a3*128 bytes and each chunk holds at most v5 = min(0x3B9AC9F0 / (a3 << 7), a4) buffers. The chunk size is stored at this+0x50 and the final chunk is capped to the remaining count. A buffer size exceeding the 0x3B9AC9F0 ceiling triggers the error path: constant 69 at obj+0x14 and a vtable dispatch through the object vtable at obj+0x0. Returns the pointer-index array; consumed by DirectXTextureSurfaceAllocation (0x0051629F).
- `0x005176EC` **VectorMath** — Normalizes the 3-vector a2 into the output a1 (this+0x0/+0x4/+0x8). When the squared length is 0.0, writes an all-zero vector; otherwise, when |1.0 - length^2| exceeds the magic threshold 0x3727C5AC, scales each component by a table-based reciprocal-square-root approximation (table address appears in raw source as 5D79E0h, magic constant -1090519041); else copies a2 into a1 unchanged (length already near 1.0). Returns a1. No calls, globals, or owner evidence in the packet.
- `0x00517F35` **ByteArrayPackingUtility** — Assembles the four bytes at a1[0..3] into a single 32-bit integer by chained left shifts and unsigned byte reads (big-endian: a1[0] is the most significant byte, a1[3] the least). Pure utility with no guards, globals, or calls.
- `0x0051D897` **PaletteVectorQuantizer** — Nearest-neighbor color search over a three-component (R/G/B) palette owned by the object at a1: reads the palette entry count from this+0x70 and the palette structure pointer from this+0x74 (three byte component arrays at palette+0/+4/+8). Computes per-channel weighted squared-distance contributions relative to target values (a3 red, a2 green, a4 blue), tracks the best in-band score (init 0x7FFFFFFF), stores each entry's out-of-band penalty in a local 256-entry array, then writes to the output buffer a5 the index of every palette entry whose stored penalty is <= the best score and returns the number of indices written. Invoked by BitstreamTextureBlockCopy (0x0051DB31).
- `0x0051EA5A` **VirtualObjectArray** — Fills an array of virtual objects through a vtable dispatch: loads the output buffer base from this+0x1A4, computes the size argument v3 = 2 * this+0x5C + 4, and while the element count this+0x64 is positive loops this+0x64 times calling the vtable method at *(this+0x4 + 4) with (a1, 1, v3), storing each result into the buffer at base+68 advancing one DWORD per iteration. Returns the last stored result. Called by CodecModeSelect (0x0051EA90) and ObjectSetupWithBoundsCheck (0x0051EB6E).
- `0x0051EC00` **VectorMath** — SIMD weighted linear combination: computes *a1 = a3[3] + broadcast(low element of a2[0]) * a3[0] + broadcast(low element of a2[1]) * a3[1], storing the resulting 128-bit vector at this+0x0 and returning a1. Straight-line __m128 store with no branching.
- `0x0051EDAE` **VectorMath** — 3-component normalize with squared-length threshold: computes the squared length of a2 and, when it is at least the global threshold dword_8D6000, computes a Newton-Raphson refined reciprocal square root using the read-only globals dword_8D6004 (scale) and dword_8D6008 (subtractive coefficient) and scales each input component into the output a1 (this+0x0/+0x4/+0x8); otherwise writes a zero vector. Returns a1.
- `0x0051EE7E` **VectorMath** — 4-component normalizer with squared-length threshold: computes the squared length over the X/Y/Z components of a2 (W does not participate in the length). When the length reaches the global threshold dword_8D600C, computes a Newton-Raphson refined reciprocal-sqrt (globals dword_8D6010 and dword_8D6014) and writes all four scaled components (including W) into a1 (this+0x0..0xC); below the threshold zeroes all four. Returns a1.
- `0x0051F0BE` **VectorMath** — SSE 3D vector math: loads high-pair floats from three input pointers (a2, a3, a4), performs shuffle/multiply/subtract/add sequences to form a cross-product-like result, applies the sign-flip XOR mask xmmword_5D8A20, and stores the resulting __m128 at a1 (this+0x0). Returns a1. Vector semantics (cross product vs 3x3 matrix product) rest on the canonical name only.
- `0x0051F5F0` **VectorMath** — Three-component vector blend: starts from the 3-vector loaded at a2 (base), adds (a3 - base) scaled by the low element of a5 and (a4 - base) scaled by the low element of a6, then stores the resulting 3-float vector at the output a1 (high two floats at a1, low dword at a1+8 = this+0x8) and returns a1.
- `0x0051F650` **VectorMath** — Full 4-component vector blend: computes a2 + (a3 - a2) * broadcast(low element of a5) + (a4 - a2) * broadcast(low element of a6), stores the result into the output vector a1 (this+0x0) and returns a1.
- `0x0051F700` **VectorMath** — Computes a scalar via horizontal reduction of products between the vector at a4 and the vectors at a5/a6, refines its reciprocal with one Newton-Raphson step, interpolates the base vector at a5 toward the vector at a6 by the refined factor, writes the resulting 3-float vector to the output buffer a3 (high two floats at a3, low dword at a3+8), and returns a3. When the scalar equals the float at global dword_8B00E0 (a zero sentinel) the function returns 0 without producing output.
- `0x0051FBF0` **SseMatrixMath** — Straight-line SSE 3x3 matrix multiply with packed multiplies and sign-flip XOR masks: loads the high double-pair halves of the two input matrices a2/a3 via load-high, splats and shuffles their lanes, XORs the shuffled lanes against the three read-only masks xmmword_8D6100/xmmword_8D60F0/xmmword_8D60E0, accumulates the products, stores the packed result to the output a1 (low half via storel at a1, high half via storeh at a1+4 = this+0x4) and returns a1. The legacy abi name identifies the inputs as rotation matrices; row/column ordering is unresolved.
- `0x0051FC80` **VectorMath** — Unconditionally normalizes a 4-component float vector (a2 -> a1) using a reciprocal square root refined with one Newton-Raphson step driven by two read-only globals: dword_5D8BF0 (subtractive constant) and dword_5D8BE0 (refinement scale). Writes all four components at a1 (this+0x0..0xC) and returns a1. Part of the SSE/vector math library.
- `0x0052014E` **SseMatrixMath** — Multiplies a 4-component vector at a2 by a 4x4 matrix at a3 and stores the resulting 4-vector at a1 (this+0x0). Matrix pointer alignment (a3 & 0xF) selects between unaligned 8-byte half-row loads and aligned __m128 row loads at offsets 0/16/32/48; both branches compute x*row0 + y*row1 + z*row2 + w*row3 (shuffle immediates 0/85/170/255 broadcast x/y/z/w). Returns a1.
- `0x0052035E` **VectorMath** — Conditionally normalizes a 3-component float vector (a2 -> a1): when squared length >= the global threshold dword_8D6180, scales the components by a Newton-Raphson refined reciprocal square root using globals dword_8D6184 (scale) and dword_8D6188 (subtractive constant); otherwise writes 0.0 to all three output components (this+0x0/+0x4/+0x8). Returns a1.
- `0x005207CE` **VectorMath** — Computes the 3D cross product of two vectors loaded from a2 and a3 via SSE load/shuffle/multiply/subtract/add sequences, applies the XOR sign mask xmmword_5D8C20, and stores the resulting __m128 at a1 (this+0x0). The fourth argument a4 participates in the lane shuffle feeding the component products; returns a1. The sign convention (right-hand rule) is asserted by existing analysis, not proven from the mask bytes.
- `0x00520F69` **ThreeDNowVectorMath** — Straight-line 3DNow! packed-vector normalization with a zero-length guard: computes the packed squared length (pfmul + pfacc), compares it against the tiny threshold literal 0x80000000800000 with pfcmpgt, computes a reciprocal square root with pfrsqrt refined by one Newton-Raphson iteration (pfrsqit1/pfrcpit2), masks the components with the comparison result via pand, scales by the refined reciprocal, stores the normalized packed pair to a1 (this+0x0 and this+0x8), and exits the MMX/3DNow state with _m_femms. The threshold constant is associated (DERIVED) with global 0x005AF970.
- `0x00520FC6` **ThreeDNowVectorMath** — 3DNow! conditional 2-float vector normalize with fallback: computes the packed length-squared of the input a1, compares it against the tiny threshold constant 0x80000000800000 (packet global VectorLengthSquaredThreshold 0x005AF970) via pfcmpge, and branches: on fallback writes the packed constant 0xBF8000003F800000 {1.0, -1.0} (packet global SSEZeroThreshold 0x005AF8F0) to a2 and zeroes a3 (both gated on non-null); otherwise refines the reciprocal sqrt with a Newton step, writes normalized components to a2, and when a3 is non-null calls SquareRootApproximation (0x00529000) and writes a scaled component to a3 using the scale constant 0x4000000040000000 (packet global OutputLengthScale 0x005AF908). Returns the branch flag and ends with _m_femms.
- `0x005215DB` **ThreeDNowVectorMath** — 3DNow! vector interpolation between a2 and a3 with parameter a4, writing the result to a1 (this+0x0 and this+0x8): computes the dot product, extracts its sign and magnitude, and branches on |dot|: when |dot| is small enough (<= ~0.9999, threshold literal 0x3F7FFF58) it takes the full path computing 1/sin(theta) via pfrsqrt(1-dot^2) with Newton-Raphson refinement through F_3DVectorNormalize_8f00 (0x00528F00) and the sub_529700 helper (0x00529700, called twice) to build sin-based blend weights; otherwise it uses the simple (1-t, t) weights. The final per-lane products are written to a1->m64_u64 (this+0x0) and a1[1].m64_u64 (this+0x8). Called by MMX3DNowVectorTransform (0x00521712) and F_3DVectorBlend (0x0052179F).
- `0x0052179F` **ThreeDNowVectorMath** — Blends two vector pairs into an output vector using the 3DNow interpolation helper SIMDVectorNormalization (0x005215DB, called three times): first normalizes/combines (a2, a5) into a temporary v8 and (a3, a4) into a temporary v9 under factor a6, then computes a per-lane coefficient 2.0 * (a6 - a6*a6) using the packed constant 0x4000000040000000 (two 2.0f floats, global qword_5AF908), and performs a final SIMDVectorNormalization of v8 and v9 into a1 with that coefficient. Flushes the MMX state with _m_femms before returning a1.
- `0x00521831` **ThreeDNowVectorMath** — 3DNow! vector math helper: negates the packed float vector a2 (sign-bit flips via the packed constants at globals 0x005AF918 and 0x005AF9D0) and scales it by the reciprocal of its squared length. The squared length is accumulated with pfadd/pfmul and lane accumulation (pfacc), inverted with pfrcp plus a Newton-Raphson refinement (pfrcpit1/pfrcpit2), and gated by a threshold comparison (pfcmpgt against the packed constant 0x80000000800000 held in qword_5AF970) so near-zero vectors yield a zeroed output. Output written to a1 (this+0x0 and this+0x8); ends with _m_femms.
- `0x0052193C` **ThreeDNowVectorMath** — 3DNow!/MMX vector normalization: loads the two packed input qwords (x/y and z), accumulates the squared length via pfmul/pfadd and pfacc, approximates and refines the reciprocal square root (pfrsqrt, pfrsqit1, pfrcpit2), forms a packed scale multiplier from the a1 scalar and the refined rsqrt value, calls PackedFloatingPointMath (0x005295E0), then guards whether the scaled magnitude exceeds the small threshold 0x3400000034000000 before applying the scale to the x/y and z components. Writes the normalized vector into a2 (this+0x0 and this+0x8) and returns a2. Reads the packed-qword globals 0x005AF938 and 0x005AF948 as math constants (contents not in packet).
- `0x005261CE` **ThreeDNowMatrix4x4** — Stdcall 3DNow!-oriented wrapper that flushes MMX state (_m_femms), runs the core routine sub_525E9A(a1, a2, a3) (0x00525E9A), flushes MMX state again, and returns the destination pointer a1. The semantics of the wrapped routine (whether it performs a 4x4 matrix multiply) are outside this packet.
- `0x005262C2` **ThreeDNowVectorMath** — MMX/3DNow! 2-component vector normalizer: reads a packed pair at a2, squares both lanes, horizontally adds them (pfacc) into both lanes, computes a reciprocal square-root estimate (pfrsqrt), guards against a near-zero magnitude with a packed compare against the constant 0x80000000800000 (global qword_5AF970), refines the estimate with one Newton-Raphson step (pfrsqit1/pfrcpit2), and writes the masked normalized pair to a1 (this+0x0 and this+0x8). Exits MMX state with _m_femms on entry and before returning a1. Both callers (Media3DNowMathOperation 0x0052156F, SIMDQuaternionRotationArithmetic 0x00524553) use it to normalize a packed pair in place.
- `0x005265DB` **ThreeDNowMatrix4x4** — 3DNow/MMX packed-float routine combining two 4x4 matrices (a4 and a5) into output a3: eight packed-float output lanes built from punpck shuffles and pfadd/pfmul multiply-adds across the a5 lanes, then MMX state flushed with femms and the output pointer returned. Shared helper for quaternion composition, matrix blend and vector-transform callers (0x005267A7, 0x0052692F, 0x00526B55). The operand order of the matrix product (a4 x a5 versus a5 x a4) is unproven.

## Proposed classes

### ChunkedArrayAllocator

Chunked pointer-index array allocator: allocates a 4-byte-per-entry pointer-index array and fills it by allocating elements/buffers in bulk chunks through the allocator pair MemoryAllocator (0x00515F23) and MemoryAllocatorWithAlignment (0x0051601F). The chunk size is capped by the allocator's 1,000,000,000-byte ceiling (0x3B9AC9F0 / stride) and stored at this+0x50; the base pointer is cached from this+0x4. Allocation failure writes constant 69 at obj+0x14 and dispatches the error handler through the object vtable at obj+0x0. The object class behind this+0x0 is not resolvable from this packet.

Methods: `0x005160AD`, `0x0051613F`

- `this+0x00000004` `pointer base_pointer` (read, DERIVED)
- `this+0x00000050` `int chunk_size` (write, DERIVED)
- `obj+0x00000000` `pointer vtable_ptr` (read, DERIVED)
- `obj+0x00000014` `int error_code` (write, DERIVED)

### VectorMath

Scalar and SSE vector math helpers writing 3/4-float or __m128 outputs at a1 (this+0x0/+0x4/+0x8/+0xC): normalization with a zero-length guard and a table-based fast reciprocal-sqrt approximation (0x005176EC), threshold-gated normalizers with Newton-Raphson refined reciprocal square roots against the read-only globals in the 0x008D6000..0x008D6188 region (0x0051EDAE, 0x0051EE7E, 0x0052035E) and the 0x005D8BE0/0x005D8BF0 region (0x0051FC80), weighted blends/interpolations (0x0051EC00, 0x0051F5F0, 0x0051F650, 0x0051F700) and SSE cross-product-like vector routines applying sign-flip XOR masks (0x0051F0BE, 0x005207CE). Threshold and Newton-Raphson constant values are data-only and absent from the packet.

Methods: `0x005176EC`, `0x0051EC00`, `0x0051EDAE`, `0x0051EE7E`, `0x0051F0BE`, `0x0051F5F0`, `0x0051F650`, `0x0051F700`, `0x0051FC80`, `0x0052035E`, `0x005207CE`

- `this+0x00000000` `float v0` (write, DERIVED)
- `this+0x00000004` `float v1` (write, DERIVED)
- `this+0x00000008` `float v2` (write, DERIVED)
- `this+0x0000000C` `float v3` (write, DERIVED)

### SseMatrixMath

SSE matrix math: a 3x3 matrix multiply with packed multiplies and sign-flip XOR masks (0x0051FBF0, masks xmmword_8D6100/60F0/60E0) and a 4x4-matrix-by-4-vector multiply with an alignment dispatch (0x0052014E), both writing to the output buffer a1 (this+0x0, this+0x4). Row/column ordering and the concrete matrix representation are unresolved.

Methods: `0x0051FBF0`, `0x0052014E`

- `this+0x00000000` `float m00` (write, GUESS)
- `this+0x00000004` `float m01` (write, GUESS)

### ThreeDNowVectorMath

3DNow!/MMX packed-vector math helpers operating on 64-bit packed float pairs at this+0x0 and this+0x8: packed normalization with a shared tiny zero-length threshold (0x00520F69, 0x005262C2), conditional normalize with fallback constants (0x00520FC6), vector interpolation/slerp and blend (0x005215DB, 0x0052179F), negate-and-scale by inverse squared length (0x00521831) and scalar-scaled normalization (0x0052193C). All helpers emit _m_femms on entry/exit and read packed-qword constants in the 0x005AF8F0..0x005AF9E8 region whose values are not present in the packet.

Methods: `0x00520F69`, `0x00520FC6`, `0x005215DB`, `0x0052179F`, `0x00521831`, `0x0052193C`, `0x005262C2`

- `this+0x00000000` `__m64 packed_pair_lo` (read_write, DERIVED)
- `this+0x00000008` `__m64 packed_pair_hi` (read_write, DERIVED)

### ThreeDNowMatrix4x4

3DNow!/MMX 4x4 matrix helpers: a stdcall wrapper flushing MMX state around the core routine sub_525E9A (0x005261CE) and a packed-float 4x4 combination writing eight output lanes (0x005265DB), both bracketed by _m_femms. The concrete matrix layout equivalence to the scalar/SSE paths is not proven; the output base for 0x005265DB is the caller matrix a3. The wrapped routine 0x00525E9A is outside this packet.

Methods: `0x005261CE`, `0x005265DB`

- `this+0x00000000` `__m64 slot0` (write, GUESS)
- `this+0x00000008` `__m64 slot1` (write, GUESS)

### PaletteVectorQuantizer

Palette-owned nearest-neighbor color search: reads the palette entry count from this+0x70 and the palette structure pointer from this+0x74 (three per-channel byte component arrays at palette+0/+4/+8) and, given per-channel target values and tolerance bands, selects every entry whose out-of-band penalty is within the best in-band score, writing their byte indices to a caller buffer and returning the count. Invoked by BitstreamTextureBlockCopy (0x0051DB31).

Methods: `0x0051D897`

- `this+0x00000070` `int palette_entry_count` (read, DERIVED)
- `this+0x00000074` `pointer palette_ptr` (read, DERIVED)
- `*(this+0x74)+0x00000000` `byte_array red_component_array` (read, DERIVED)
- `*(this+0x74)+0x00000004` `byte_array green_component_array` (read, DERIVED)
- `*(this+0x74)+0x00000008` `byte_array blue_component_array` (read, DERIVED)

### VirtualObjectArray

Object holding an array of virtual objects created through a vtable dispatch: element count at this+0x64, a size argument computed from this+0x5C, a vtable pointer at this+0x4 (method slot +4) and an output buffer base at this+0x1A4. Each element is produced by calling the vtable method with (a1, 1, size) and stored into the buffer at base+68 advancing one DWORD per iteration. The invoked vtable method and the class owning the metadata are unknown.

Methods: `0x0051EA5A`

- `this+0x00000004` `pointer vtable_ptr` (read, DERIVED)
- `this+0x0000005C` `int size_arg_factor` (read, DERIVED)
- `this+0x00000064` `int element_count` (read, DERIVED)
- `this+0x000001A4` `pointer output_buffer_ptr` (read, DERIVED)

### ByteArrayPackingUtility

Big-endian byte-to-integer packing utility: assembles the four unsigned bytes at this+0x0..0x3 into a single 32-bit integer. No calls, guards, or globals; a pure leaf utility.

Methods: `0x00517F35`

- `this+0x00000000` `byte byte0` (read, DERIVED)
- `this+0x00000001` `byte byte1` (read, DERIVED)
- `this+0x00000002` `byte byte2` (read, DERIVED)
- `this+0x00000003` `byte byte3` (read, DERIVED)

## Compatibility contracts

- **ChunkedAllocatorErrorConvention** — When the per-element/buffer size exceeds the allocator's 1,000,000,000-byte ceiling (0x3B9AC9F0 / stride <= 0), the chunked allocators write constant 69 at obj+0x14 and dispatch the error handler through the object vtable at obj+0x0, passing a1; the call produces no chunk. The error-code and vtable-dispatch convention is shared by the element and buffer variants.
- **ChunkedAllocatorLayoutContract** — The pointer-index array holds a4 entries of 4 bytes each; each chunk holds v5 = min(0x3B9AC9F0 / stride, a4) elements of a3 bytes (element variant) or a3*128-byte buffers with 32*a3 advance (buffer variant); the computed chunk size is stored at this+0x50 (base pointer cached from this+0x4) and the final chunk is capped to the remaining count.
- **ThresholdNormalizeZeroContract** — Threshold-gated vector normalizers (0x0051EDAE, 0x0051EE7E, 0x0052035E) must write an all-zero output when the squared length is below the threshold global and scale by the Newton-Raphson refined reciprocal square root otherwise; the threshold/coefficient globals (0x008D6000..0x008D6188) are read-only process constants a replacement must preserve.
- **ThreeDNowZeroLengthGuardContract** — 3DNow/MMX packed normalizers must treat squared lengths at or below the tiny threshold 0x80000000800000 as zero and AND-mask the output to zero so a division by a near-zero length is avoided; the threshold constant is shared across 0x00520F69, 0x00520FC6, 0x00521831 and 0x005262C2 (its association with global 0x005AF970 is DERIVED).
- **ThreeDNowStateDisciplineContract** — 3DNow/MMX helpers must emit _m_femms on entry and before return so x87/SSE code that runs after a call is not left in MMX mode; a pure stdcall wrapper (0x005261CE) may bracket the whole call, while leaf helpers (0x005215DB, 0x00520FC6, 0x00521831, 0x0052193C, 0x005262C2) flush around their own body.
- **SlerpBranchThresholdContract** — VectorSlerpInterpolate (0x005215DB) uses sin-based blend weights while |dot| stays below the near-parallel threshold ~0.9999 (literal 0x3F7FFF58) and the simple (1-t, t) weights otherwise; the parameter t is folded into 64-bit lanes via cvtsi32_si64. The two-stage blend 0x0052179F combines pair-wise intermediates with a 2.0*(a6 - a6*a6) coefficient.
- **PaletteNearestNeighborSelectionContract** — The nearest-neighbor palette search reads the entry count from this+0x70 and the component-array structure pointer from this+0x74 (three byte arrays at palette+0/+4/+8); the output buffer receives the byte index of every palette entry whose out-of-band penalty is <= the best in-band score, and the function returns the count written.

## Unresolved

- The heap-manager hierarchy behind the chunked allocators (the object at this+0x0 with the vtable dispatch on error and the obj+0x14 constant-69 convention) is not resolvable from this packet.
- The 128-byte unit multiplier (a3 << 7, 32*a3 advance) in the buffer variant 0x0051613F is only evidence of buffer granularity; the concrete buffer type and the caller's (0x0051629F) use of the returned pointer-index arrays are not determined.
- The 'this' base conflates distinct pointers across these functions (output buffers a1/a2/a3, input vector pointers, heap-manager objects, palette/array owners); the proposed field-to-parameter assignments are DERIVED from the raw source indexing, not proven by fact tables alone.
- The fast path of 0x005176EC uses a table-based reciprocal-square-root approximation (table address 5D79E0h, magic constants 0x3727C5AC, 0x3F000000, -1090519041) whose numeric accuracy and edge-case behavior are only verifiable at runtime; the legacy ABI name Vector_Normalize is uncorroborated by an owner or caller.
- Exact per-channel weighting (4 red / 9 green / 1 blue) and tolerance bands (24/28/24) in 0x0051D897 are decompiler artifacts of un-simplified products; the selection rule compares each entry's out-of-band penalty against the best in-band score, whose semantic is not fully confirmed.
- The vtable method invoked by 0x0051EA5A (slot +4 at this+0x4) is unknown; the store offset +68 within the output buffer has no independent evidence ref; the return value is undefined when the element count this+0x64 <= 0.
- The semantic purpose of the weighted combination in 0x0051EC00 (matrices vs quaternions vs blend weights) is unknown; the packet prelabel linking it as a structural twin of FloatClamp (0x004646C0) is DERIVED and not relied on.
- Newton-Raphson coefficients and thresholds (globals 0x008D6000..0x008D6188, 0x005D8BE0/0x005D8BF0, 0x008B00E0, and the packed-qword region 0x005AF8F0..0x005AF9E8) are data-only; their runtime values are not present in the packet, and several flagged globals (0x005AF938/948/988/9D0/9E8) do not appear by name in the raw decompiled text.
- SSE sign-flip/permutation masks (xmmword_5D8A20, xmmword_5D8C20, xmmword_8D60E0/60F0/6100) are read as constants but their byte values are not in the packet; cross-product vs 3x3-matrix-product semantics of 0x0051F0BE and the right-hand-rule sign convention of 0x005207CE rest on canonical names, not proven.
- Row/column ordering of the matrix operands (0x0051FBF0, 0x0052014E, 0x005265DB) and whether W participates in the squared length of the 4-component normalizers (it does not in 0x0051EE7E, only in scaling) are unresolved.
- The exact contributions of callees 0x00528F00 (F_3DVectorNormalize_8f00), 0x00529700 (sub_529700, called twice) and 0x005295E0 (PackedFloatingPointMath) to the 3DNow interpolation/normalization formulas are not visible in this packet; the semantics of the wrapped core 0x00525E9A are outside this packet.
- Whether the packed 3DNow pairs represent 2D, 3D or 4D quantities, whether a3 may alias a4/a5 in 0x005265DB, and whether the vector-helpers' output buffers may alias their inputs are not determined by these functions alone.
- The meaning of the a3 scaled-component output of 0x00520FC6 and the a1 high-lane scalar in 0x0052193C (unit normalization vs scale-to-target-magnitude) are caller-level conventions not evidenced here.
- The register-passed __m128 values a1 and a2 of 0x0051F700 are consumed only as movehl sources; their required contents and the exact lane algebra of its two horizontal reductions are not pinned.
