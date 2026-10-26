# MathAndCollision

Scope: `math_and_collision`  
Trust: `DERIVED`

Proposal for the math_and_collision slice of Wave 6. The functions fall into four groups. (1) Scalar 4x4 matrix math and constructors writing a caller float[16] buffer (this+0x0..0x3C): multiply with in-place safety (0x0050CE79), cofactor/adjugate inverse with singular-matrix gate (0x0050D0C2), identity-with-translation (0x0050D507), single-axis rotation builders (0x0050D57F, 0x0050D615, 0x0050D6AC), axis-angle/Rodrigues (0x0050D748) and quaternion-to-matrix (0x0050D85D) constructors. (2) Quaternion-shaped 4-float outputs: matrix-to-quaternion trace-based conversion (0x0050DB5C), rotation-vector-to-quaternion with singular-sine handling (0x0050E055), and matrix-to-axis-angle/4-component conversion with a largest-diagonal branch and LUT (0x0051FD90). (3) SIMD matrix math: SSE quaternion/reflection matrix builders sharing a lazy one-time Newton-Raphson inverse-sqrt constant cache (0x0051F98E, 0x0051FB1E, 0x00520A7E), an SSE constant-row matrix constructor (0x005208FE), and 3DNow/MMX multiply/transpose/identity/quaternion-conversion helpers bracketed by _m_femms (0x0052243A, 0x00522876, 0x00522AB3, 0x00522B22). (4) Data-array processors: an audio-stream element descriptor buffer fill with scaled/modulo sizing and double-buffering (0x00519622, called by AudioStreamBufferFill 0x00519720), a channel-decode-state receiver validator that checks configuration fields and per-sprite channel indices and dispatches vtable error handlers (0x0051AD93), and a symmetric 256-entry offset-table initializer with a vtable allocator call (0x0051DF18, called by 0x0051DFCB). Row/column-major conventions, axis naming (the 0x0050D57F rotation block sits on the middle rows, matching an X-axis rotation despite the Y-axis name), and handedness of the rotation/quaternion conversions are unresolved packet-level questions.

## Function roles

- `0x0050CE79` **Matrix4x4** — Multiplies two 4x4 float matrices (a2, a3) into the output matrix a1 (this), writing the 16 cells at this+0x0..0x3C. When a1 aliases either operand, the product is computed into a stack temporary and copied back (0x40 bytes) afterward, making the call safe for in-place use; returns a1. Each cell is the dot product of one row of a2 with one column of a3; row/column-major layout and operand order are not established by the packet.
- `0x0050D0C2` **Matrix4x4** — Computes the inverse of a 4x4 matrix read from a3 by the cofactor/adjugate method. Optionally stores the determinant through a2 when a2 is non-NULL. Computes the reciprocal v55 = 1/det and uses ArithmeticComparison_a88f (0x0058A88F) to detect a singular matrix (zero reciprocal); on the invertible path writes the adjugate scaled by v55 into all 16 cells of a1 (this+0x0..0x3C) and returns a1, otherwise returns 0 leaving a1 untouched.
- `0x0050D507` **Matrix4x4** — Fills a 4x4 matrix at a1 (this) with the identity (1.0 at cells this+0x0, +0x14, +0x28, +0x3C) and writes the raw DWORD arguments a2/a3/a4 into the last-column cells this+0x30/+0x34/+0x38; every other cell is zeroed as a float. Returns a1. The translation arguments are stored with raw _DWORD writes while the surrounding cells are float writes; the caller's ABI view of the translation values is not known here.
- `0x0050D57F` **Matrix4x4** — Fills a 4x4 rotation matrix at a1 (this) from angle a2: 1.0 at cells this+0x0 and +0x3C, a 2x2 rotation block {cos,sin;-sin,cos} at cells this+0x14/+0x18/+0x24/+0x28, zeros elsewhere; returns a1. Under a standard row-major layout the block on the middle rows/columns corresponds to a rotation about the first (X) axis, contradicting the canonical Y-axis name; the axis labeling cannot be resolved from this packet alone.
- `0x0050D615` **Matrix4x4** — Fills a 4x4 Y-axis rotation matrix at a1 (this) from angle a2: cos(a2) at this+0x0, -sin(a2) at this+0x8, 1.0 at this+0x14, sin(a2) at this+0x20, cos(a2) at this+0x28, 1.0 at this+0x3C, zeros at the remaining cells; returns a1. Layout matches the Y-axis naming with the identity diagonal element on the middle row/column. Handedness (transpose/negative-angle form) is unverified.
- `0x0050D6AC` **Matrix4x4** — Builds a 4x4 rotation matrix at a1 (this) from angle a2: 2x2 rotation block {cos,sin;-sin,cos} in the top-left cells this+0x0/+0x4/+0x10/+0x14, 1.0 at this+0x28 and this+0x3C, zeros elsewhere; returns a1. The prelabel identifies it as a structural twin (DERIVED) of F_4x4MatrixMultiply (0x50CBB6, outside this packet). cos/sin calls have no callee entries in the packet.
- `0x0050D748` **Matrix4x4** — Builds a 4x4 column-major rotation matrix at a1 (this) from an axis vector a2 (x, y, z) and angle a3 using the Rodrigues formula R = cos(a3)*I + (1 - cos(a3))*n*n^T + sin(a3)*[n]x; translation row/column zeroed and bottom-right cell this+0x3C = 1.0. Calls ThunkTo (0x0050C2B3) mid-function for an unresolved purpose; returns a1.
- `0x0050D85D` **Matrix4x4** — Converts a unit quaternion (a2: x, y, z, w) into a 4x4 column-major rotation matrix at a1 (this) using the standard formula built from 2x/2y/2z and the double products; translation row/column zeroed and bottom-right cell this+0x3C = 1.0; returns a1. The scaling constants are materialized from global 0x0059E800, which the raw source does not name.
- `0x0050DB5C` **Quaternion** — Converts the 3x3 rotation sub-matrix (upper-left of a 4x4 column-major matrix a2) into a unit quaternion written to a1 (this+0x0/+0x4/+0x8/+0xC = x, y, z, w) using the trace-based algorithm: positive trace takes the direct branch computing w from sqrt(trace+1) and x/y/z from off-diagonal differences; trace <= 0 takes a largest-diagonal branch picking the largest diagonal component from sqrt(maxdiag+1) and deriving the other components and w from off-diagonal sums/differences, avoiding numerical instability near 180-degree rotations. Returns a1.
- `0x0050E055` **Quaternion** — Converts a rotation vector a2 (3-vector plus angle magnitude in a2[3]) into a quaternion-shaped output a1 (this+0x0/+0x4/+0x8 vector, this+0xC scalar always 0.0). When angle >= 1.0 the vector part is copied verbatim; otherwise FloatFunctionPassThrough (0x005894A0) runs, sin(angle) is computed, and FloatRangeCheck (0x0050C042) detects a near-singular sine (reported zero) which selects the verbatim path; otherwise the vector part is scaled by angle/sin(angle). Returns a1.
- `0x00519622` **AudioStreamElementBuffer** — Processes an array of element descriptors (pointer at this+0xC4, 84-byte stride) gated by the element count at this+0x20, then performs a bounded data fill into a double-buffered element buffer (pointer at this+0x180). Per element it computes a scaled size v6 = descriptor[0]*descriptor[6] / divisor this+0x114 and a modulo-wrapped data size; on the first element it writes the computed output row size to this+0x1C8; then, when 2*v6 > 0, fills 2*v6 dwords at a target derived from the double-buffer selector this+0x1C0. Returns the element loop counter, or 0 when the count guard blocks. __usercall ABI (this in ESI, result in EAX). Called by AudioStreamBufferFill (0x00519720).
- `0x0051AD93` **ChannelDecodeStateReceiver** — Validates receiver configuration fields this+0x168/0x16C/0x170/0x174 (must be 0/63/0/0; on failure writes error code 118 to obj+0x14 and dispatches the vtable error handler at obj+0x4 with (a1, -1)), then iterates the sprite object array at this+0x124 (count at this+0x120). Per object it reads channel index A at sprite+0x14 and channel index B at sprite+0x18, validates each (index < 4 with a non-null buffer in the this+0xA0 / this+0xB0 regions; on failure writes error code 49 to obj+0x14 and the offending index to obj+0x18, then dispatches the obj+0x0 error handler), copies both channel buffers into per-object decode-state slots via sub_51A5EA (0x0051A5EA), zeroes the decode-state counters at this+0x19C/+0x1A0/+0x1A4/+0x1A8/+0x1AC and the slot array at this+0x1B4, writes this+0x1C4 = this+0xFC, and returns that value. The obj/this alias is inferred, not evidenced.
- `0x0051DF18` **SymmetricOffsetTable** — Allocates and initializes a 256-entry symmetric offset table: reads a context pointer from this+0x1A4, calls an allocator through the vtable at this+0x4 (slot 0, arguments (this, 1, 2044)), advances the returned block by 1020 bytes to center it, stores the centered pointer at context+0x28, then fills 256 signed entries symmetrically about the midpoint in three passes (indices 0..15 count upward against mirrored negatives, 16..47 continue counting upward while the negative side mirrors the positive value advancing only on even iterations, 48..255 mirror the positive value unchanged). Returns the centered buffer pointer for the caller 0x0051DFCB.
- `0x0051F98E` **SseMatrix4x4** — Builds and stores a 4x4 matrix at a1 (this) from a rotation-like basis: the input vector/quaternion a3 is normalized via a Newton-Raphson refined inverse sqrt (with lazy one-time caching of the two refinement constants behind byte_8D46B0 flag bits, sourced from dword_8D60C0/dword_8D60C4 into xmmword_8D4690/xmmword_8D46A0), the normalized axis is sign-flipped with xmmword_5D8B00, and four result rows are formed from shuffle/mask operations against the incoming matrix a2 using masks xmmword_5D8B10/20/30/40. Stores the four rows at this+0x0/+0x10/+0x20/+0x30 with an alignment-aware store path (unaligned storel/storeh pairs when a1 is not 16-byte aligned, aligned __m128 stores otherwise); returns a1. The reflection-vs-rotation semantic rests on the canonical name only.
- `0x0051FB1E` **SseMatrix4x4** — Converts a quaternion (a2) into a 4x4 rotation matrix at a1 (this) using SSE intrinsics: loads the quaternion, extracts components with the bitmask xmmword_5D8BC0, normalizes via a Newton-Raphson refined inverse sqrt using fsqrt and the constants 0x005D8BB0 (scale) and 0x005D8BA0 (subtractive coefficient), scales the products by xmmword_5D8B90, and builds four rows from component products plus additive constants xmmword_5D8B80/70/60/50. Stores the rows at this+0x0/+0x10/+0x20/+0x30; returns a1. The exact component-to-cell mapping of the shuffle patterns is inferred only.
- `0x0051FD90` **Quaternion** — Converts a 3x3 rotation matrix (a2, float[9]) into a 4-component output a1 (this+0x0/+0x4/+0x8 axis-like components, this+0xC scalar). When the matrix trace exceeds the threshold flt_8D611C it takes the trace branch (scalar = sqrt(trace + flt_8D6120) * flt_8D6124 at this+0xC, axis from paired off-diagonal differences scaled by flt_8D6128 / scalar); otherwise it selects the largest diagonal element via the dword_8D6110 index LUT and derives scalar and axis from the corresponding off-diagonal sums and differences with constants flt_8D6130/flt_8D6134/flt_8D6138. No calls. The strict axis-angle vs quaternion w,x,y,z interpretation of the output is not determined by the packet.
- `0x005208FE` **SseMatrix4x4** — Builds a 4x4 matrix at output a1 (this) from four packed input dwords (v6..v9) fed through EmptyStub_8bd0 (0x00528BD0). Row 0 is the masked/shuffled result of AND with xmmword_8D6210 XOR xmmword_8D6200, row 1 is the xmmword_8D61F0 constant, row 2 is a re-shuffle of the masked vector, row 3 is the xmmword_8D61E0 constant; stored at this+0x0/+0x10/+0x20/+0x30; returns a1. SSE math-library helper; the meaning of the input dwords and the constant contents are not documented.
- `0x00520A7E` **SseMatrix4x4** — SSE quaternion-to-rotation-matrix build at a1 (this): reads a quaternion from a3, computes its squared length (mask xmmword_5D8CA0), and when non-zero normalizes it using an approximate inverse sqrt (fsqrt) with a Newton-Raphson refinement that lazily caches two shared constants (dword_8D6220/dword_8D6224 into xmmword_8D4690/xmmword_8D46A0, gated by byte_8D46B0 flag bits). Sign-negates the normalized quaternion with the xmmword_5D8C60 XOR mask, multiplies it against the input matrix a2 using shuffled-component dot products, blends components via AND masks xmmword_5D8C70/80/90, and writes four output rows to a1 at this+0x0/+0x10/+0x20/+0x30 through an alignment-aware store path (unaligned storel/storeh when a1 is not 16-byte aligned, aligned __m128 stores otherwise). Returns a1.
- `0x0052243A` **ThreeDNowMatrix4x4** — 3DNow! 4x4 matrix multiply computing a1 = a2 * a3. Transposes a3 into column-major __m64 halves via punpckldq/punpckhdq, then for each of the eight output __m64 slots at this+0x00..0x38 accumulates the dot product of one a2 row-half against four a3 column-halves using pfmul/pfacc/pfadd. Emits _m_femms at entry and before return to exit MMX/3DNow state. Pure register/vector math with no memory access, guards or callees; returns a1.
- `0x00522876` **ThreeDNowMatrix4x4** — 3DNow!/MMX quaternion-to-matrix conversion: normalizes the input quaternion a2 via F_3DVectorNormalize (0x00527578) into a stack pair (v11/v12), scales packed lanes using v4 = v11 * -2.0 and v5 = v12 * (-2.0, 1.0), duplicates lanes with punpckldq/punpckhdq, and writes the eight __m64 matrix slots at this+0x00..0x38 with pfadd/pfmul combinations that place 1.0 (0x3F800000) identity lanes on the diagonal. Reads four packed qword globals (0x005AF9C0/C8/D8/E0) as identity/matrix constants. Clears MMX/3DNow state with _m_femms on entry and exit; returns a1.
- `0x00522AB3` **ThreeDNowMatrix4x4** — 3DNow! 4x4 matrix transpose writing a1 = transpose(a2): pairs a2's __m64 slots (a2[0] with a2[2], a2[5] with a2[7], a2[1] with a2[3], a2[4] with a2[6]) and interleaves low/high dwords with punpckldq/punpckhdq so each output slot at this+0x00..0x38 receives the transposed pair. Emits _m_femms at entry and before return. Pure register/vector math with no memory access, guards or callees; returns a1. The prelabel marks it as a structural twin of the multiply helper F_4x4MatrixMultiply_243a (0x0052243A), DERIVED only.
- `0x00522B22` **ThreeDNowMatrix4x4** — Builds a 4x4 identity matrix in the eight qword slots of a1 (this) with 3DNow! intrinsics: slots 0 (this+0x0) and 5 (this+0x28) hold the 1.0f constant, slots 2 (this+0x10) and 7 (this+0x38) hold a punpck-reshuffled pair of 1.0f values, and slots 1, 3, 4, 6 (this+0x8/0x18/0x20/0x30) are zeroed, placing ones on the diagonal and zeroes off it. Emits 3DNow femms to flush MMX state. Invoked by F_3DNowVectorTransform (0x00526B55). The packet lists qword_5AF8F0 as referenced but the raw source builds the identity constants inline and never reads it.

## Proposed classes

### Matrix4x4

Scalar float[16] 4x4 matrix: the output buffer (modeled as this+0x0..0x3C) written by the multiply, inverse, identity-with-translation and rotation/axis-angle/quaternion constructors. Row/column-major layout is not established by the packet; all sixteen cells are output writes from the functions that build or transform the matrix.

Methods: `0x0050CE79`, `0x0050D0C2`, `0x0050D507`, `0x0050D57F`, `0x0050D615`, `0x0050D6AC`, `0x0050D748`, `0x0050D85D`

- `this+0x00000000` `float m00` (write, DERIVED)
- `this+0x00000004` `float m01` (write, DERIVED)
- `this+0x00000008` `float m02` (write, DERIVED)
- `this+0x0000000C` `float m03` (write, DERIVED)
- `this+0x00000010` `float m10` (write, DERIVED)
- `this+0x00000014` `float m11` (write, DERIVED)
- `this+0x00000018` `float m12` (write, DERIVED)
- `this+0x0000001C` `float m13` (write, DERIVED)
- `this+0x00000020` `float m20` (write, DERIVED)
- `this+0x00000024` `float m21` (write, DERIVED)
- `this+0x00000028` `float m22` (write, DERIVED)
- `this+0x0000002C` `float m23` (write, DERIVED)
- `this+0x00000030` `float m30` (write, DERIVED)
- `this+0x00000034` `float m31` (write, DERIVED)
- `this+0x00000038` `float m32` (write, DERIVED)
- `this+0x0000003C` `float m33` (write, DERIVED)

### Quaternion

Quaternion-shaped 4-float output buffer (this+0x0/+0x4/+0x8 vector, this+0xC scalar): produced by the matrix-to-quaternion conversion (0x0050DB5C), the rotation-vector-to-quaternion conversion (0x0050E055, scalar always written 0.0), and the matrix-to-axis-angle/4-component conversion (0x0051FD90). Whether the output is strictly w,x,y,z and its handedness are unresolved.

Methods: `0x0050DB5C`, `0x0050E055`, `0x0051FD90`

- `this+0x00000000` `float q0` (write, DERIVED)
- `this+0x00000004` `float q1` (write, DERIVED)
- `this+0x00000008` `float q2` (write, DERIVED)
- `this+0x0000000C` `float q3_scalar` (write, DERIVED)

### SseMatrix4x4

SSE matrix/rotation builders writing four __m128 rows at this+0x0/+0x10/+0x20/+0x30: quaternion/axis-based matrix construction (0x0051F98E, 0x0051FB1E, 0x00520A7E) and a constant-row matrix constructor fed through EmptyStub_8bd0 (0x005208FE). The quaternion/axis builders share a lazy one-time Newton-Raphson inverse-sqrt constant cache gated by byte_8D46B0 and use read-only-data masks whose values are not present in the packet.

Methods: `0x0051F98E`, `0x0051FB1E`, `0x005208FE`, `0x00520A7E`

- `this+0x00000000` `__m128 row0` (write, GUESS)
- `this+0x00000010` `__m128 row1` (write, GUESS)
- `this+0x00000020` `__m128 row2` (write, GUESS)
- `this+0x00000030` `__m128 row3` (write, GUESS)

### ThreeDNowMatrix4x4

3DNow!/MMX 4x4 matrix helpers operating on eight __m64 slots at this+0x00..0x38: multiply (0x0052243A), quaternion-to-matrix (0x00522876), transpose (0x00522AB3) and identity construction (0x00522B22). Every helper emits _m_femms on entry and before return. The 3DNow path is a separate representation of the 4x4 matrix whose layout equivalence to the scalar/SSE paths is not proven.

Methods: `0x0052243A`, `0x00522876`, `0x00522AB3`, `0x00522B22`

- `this+0x00000000` `__m64 slot0` (write, DERIVED)
- `this+0x00000008` `__m64 slot1` (write, DERIVED)
- `this+0x00000010` `__m64 slot2` (write, DERIVED)
- `this+0x00000018` `__m64 slot3` (write, DERIVED)
- `this+0x00000020` `__m64 slot4` (write, DERIVED)
- `this+0x00000028` `__m64 slot5` (write, DERIVED)
- `this+0x00000030` `__m64 slot6` (write, DERIVED)
- `this+0x00000038` `__m64 slot7` (write, DERIVED)

### AudioStreamElementBuffer

Audio-stream element buffer processor (called by AudioStreamBufferFill 0x00519720): iterates an element descriptor array (pointer this+0xC4, 84-byte stride, count this+0x20), computes per-element scaled and modulo-wrapped sizes against the divisor this+0x114, records the output row size at this+0x1C8, and performs a bounded dword fill into a double-buffered element buffer (this+0x180) selected via this+0x1C0. The three-plane buffer indirection semantics are not fully established.

Methods: `0x00519622`

- `this+0x00000020` `int element_count` (read, DERIVED)
- `this+0x000000C4` `pointer descriptor_array_ptr` (read, DERIVED)
- `this+0x00000114` `int size_divisor` (read, DERIVED)
- `this+0x00000180` `pointer element_data_ptr` (read, DERIVED)
- `this+0x000001C0` `int double_buffer_selector` (read, GUESS)
- `this+0x000001C8` `int output_row_size` (write, GUESS)

### ChannelDecodeStateReceiver

Receiver object whose decode state (pointed at by this+0x194) is validated and reset per sprite: configuration guard fields at this+0x168/0x16C/0x170/0x174 must be 0/63/0/0, the sprite object array (this+0x124, count this+0x120) supplies per-sprite channel indices, the channel buffers live in the this+0xA0/0xB0 regions, and the vtable at this+0x0 (also modeled as the obj base for the error-path fields obj+0x4/0x14/0x18) dispatches error handlers on validation failure. Decode-state counters this+0x19C..0x1AC and the slot array this+0x1B4 are zeroed each pass; this+0x1C4 records the receiver reference this+0xFC.

Methods: `0x0051AD93`

- `this+0x00000000` `pointer vtable_ptr` (read, DERIVED)
- `this+0x000000FC` `int receiver_ref_value` (read, GUESS)
- `this+0x00000120` `int object_count` (read, DERIVED)
- `this+0x00000124` `pointer object_array_ptr` (read, DERIVED)
- `this+0x00000168` `int config_guard0` (read, DERIVED)
- `this+0x0000016C` `int config_required_value` (read, DERIVED)
- `this+0x00000170` `int config_guard1` (read, DERIVED)
- `this+0x00000174` `int config_guard2` (read, DERIVED)
- `this+0x00000194` `pointer decode_state_ptr` (read, DERIVED)
- `this+0x0000019C` `int decode_state_counter0` (write, GUESS)
- `this+0x000001A0` `int decode_state_counter1` (write, GUESS)
- `this+0x000001A4` `int decode_state_counter2` (write, GUESS)
- `this+0x000001A8` `int decode_state_counter3` (write, GUESS)
- `this+0x000001AC` `byte decode_state_byte` (write, GUESS)
- `this+0x000001B4` `int_array decode_state_slot_array` (write, GUESS)
- `this+0x000001C4` `int receiver_ref_copy` (write, GUESS)
- `obj+0x00000000` `pointer obj_vtable_ptr` (read, DERIVED)
- `obj+0x00000004` `pointer error_handler_vtable_slot` (read, GUESS)
- `obj+0x00000014` `int error_code` (read_write, GUESS)
- `obj+0x00000018` `int error_channel_index` (read_write, GUESS)

### ChannelSpriteObject

Sprite object element of the array at this+0x124: carries two channel indices at sprite+0x14 and sprite+0x18 that the receiver validates (must be < 4 with non-null buffers in the this+0xA0/0xB0 regions) before copying each channel buffer into per-object decode-state slots. No packet function is attributed as a method of this object; it is a data record only.

Methods: 

- `*(this+0x124)+0x00000014` `int channel_index_a` (read, DERIVED)
- `*(this+0x124)+0x00000018` `int channel_index_b` (read, DERIVED)

### SymmetricOffsetTable

Initializes a 256-entry symmetric signed offset table for the caller 0x0051DFCB: reads the context pointer from this+0x1A4, allocates a 2044-byte block through the vtable at this+0x4 (slot 0), centers the block by advancing 1020 bytes, stores the centered pointer at context+0x28, and fills the table symmetrically about the midpoint in three counting passes. The concrete allocator behind the vtable is not named in the packet.

Methods: `0x0051DF18`

- `this+0x00000004` `pointer allocator_vtable_ptr` (read, DERIVED)
- `this+0x000001A4` `pointer context_ptr` (read, DERIVED)
- `*(this+0x4)+0x00000000` `pointer allocator_slot0` (read, GUESS)
- `*(this+0x1A4)+0x00000028` `pointer centered_buffer_ptr` (write, DERIVED)

## Compatibility contracts

- **InPlaceMatrixMultiplySafe** — The 4x4 matrix multiply output may alias either input operand; the product must be computed into a temporary and copied back (0x40 bytes) so in-place use is safe.
- **SingularMatrixInverseContract** — Matrix inverse returns 0 and leaves the output buffer untouched when the determinant reciprocal is zero (singular matrix, gated by ArithmeticComparison_a88f); the determinant is optionally written through a non-null output argument before the singularity check.
- **SseInverseSqrtCacheInitialization** — The two Newton-Raphson inverse-sqrt constants must be initialized exactly once per process, gated by the flag bits of byte_8D46B0, before first use; subsequent calls reuse the cached values. Both 0x0051F98E and 0x00520A7E read the same cache, so a replacement must preserve this shared one-time initialization.
- **ThreeDNowStateDiscipline** — 3DNow/MMX matrix helpers must emit _m_femms on entry and before return so x87/SSE code that runs after a call is not left in MMX mode.
- **ReceiverConfigurationContract** — The receiver is accepted only when configuration fields this+0x168/0x16C/0x170/0x174 are 0/63/0/0; rejection writes error code 118 to obj+0x14 and dispatches the vtable error handler at obj+0x4. Per-object channel indices must be < 4 with non-null buffers, otherwise error code 49 is written and the obj+0x0 handler is dispatched.
- **RotationHandednessConvention** — Rotation matrices, axis-angle and quaternion conversions encode a specific but undocumented handedness/sign convention (sin/-sin placement, e.g. -sin at element (2,1) in 0x0050D57F vs -sin at element (0,2) in 0x0050D615). A replacement must reproduce the observed element placement exactly; the packet cannot distinguish row-major from column-major or left- from right-handed.

## Unresolved

- Storage layout (row-major vs column-major) of the float[16] matrices is not established; the a2*a3 vs a3*a2 operand order of 0x0050CE79 depends on it.
- 0x0050D57F (YAxisRotationMatrix) places its rotation block on the middle rows/columns, which matches an X-axis rotation under a standard row-major layout; the axis naming cannot be resolved from this packet alone.
- Sign conventions (sin/-sin placement) and handedness of the rotation and quaternion conversions (0x0050D57F, 0x0050D615, 0x0050D6AC, 0x0050D85D, 0x0050DB5C, 0x0051FD90) are unverified.
- cos/sin/fsqrt have no callee entries in the packet, so the concrete math library routines are not identified.
- Purpose of the ThunkTo call (0x0050C2B3) inside 0x0050D748 is unknown and not resolvable from the packet.
- global:0x0059E800 (read by 0x0050D85D) is not named in the raw source; it is likely a compiler-materialised float constant, value not grounded by the packet.
- The off-diagonal index arithmetic in the largest-diagonal branch of 0x0050DB5C needs review against the raw source before relying on it.
- Globals flt_59E43C, flt_59E440, flt_59E450, flt_59E7F8 are attributed to 0x0050DB5C, and flt_59E43C to 0x0050E055, by skeleton xref data but are not read in their raw bodies.
- Semantics of the three-plane buffer indirection and the exact data-fill meaning in 0x00519622 are not fully established; the descriptor sub-fields (descriptor+12/+36/+44) are not enumerated as this-object fields.
- In 0x0051AD93 the channel buffer arrays (this+0xA0/0xB0 regions) and the per-object decode-state destination arrays (state+52/state+68) have no field evidence refs; the obj/this alias is inferred, not evidenced.
- The concrete allocator behind the vtable call at this+0x4 slot 0 of 0x0051DF18 is not named; the asymmetric counting rule in the second symmetric-fill pass is reproduced literally but its semantic intent is undocumented.
- The semantic label 'reflection/orientation' for 0x0051F98E rests on the canonical name; the runtime values of the masks xmmword_5D8B00/10/20/30/40 and the SSE constants of 0x0051FB1E / 0x00520A7E / 0x005208FE are data-only and not present in the packet.
- Exact component-to-cell mapping of the shuffle patterns in the SSE quaternion/matrix builders is inferred, not recovered.
- Output semantics of 0x0051FD90 (strict axis-angle vs quaternion w,x,y,z) and the concrete values of flt_8D6120/24/28/30/34/38 and the dword_8D6110 LUT are not determined by the packet.
- Contents of the packed qword globals 0x005AF9C0/C8/D8/E0 read by 0x00522876, and the unverified role of qword_5AF8F0 in 0x00522B22, are not present in the packet.
- No callers are recorded for most matrix math functions, so their use sites in the larger 3D math library are unknown; the shared lazy cache suggests a singleton SSE math library, which is unproven by these functions alone.
