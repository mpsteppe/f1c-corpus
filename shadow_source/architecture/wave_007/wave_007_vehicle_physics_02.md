# VehiclePhysics

Scope: `vehicle_physics`  
Trust: `GUESS`

Reconstruction of ten validated function IR records grouped under the vehicle_physics scope. Five functions (0x00526F69, 0x005275DC, 0x0055EEAF, 0x0055EF24) are stateless matrix-vector multiply primitives with no object state; they are proposed as one VectorMatrixTransformKernel class with no fields because the this-relative refs on their bodies are argument buffers, not fields. 0x0053AD80 is the only function whose body reads real object state (working-buffer pointers at this+0x10 and this+0x30); it is kept as its own TransformWorkBufferOwner class with the three copied vector components and three matrix-column slots modeled as derived-base fields. 0x0052804A is a fixed-point IDCT color transform (image/decode work, scope mismatch) reading an output lookup-table pointer at this+0x11C; it is modeled as FixedPointIDCTCodec and the scope mismatch is recorded explicitly. 0x0057BC70 installs the global Physics vtable off_5B8A00 into this+0x0 and is modeled as PhysicsObject. 0x0059982F, 0x0059985C and 0x0059AAA3 are structurally identical thunks that each read a distinct global (0x0059983B, 0x00599868, 0x0059AAAF), cast it to int, forward it to BooleanToIntConversion (0x00587B3E) and return the conversion result; they are grouped as PhysicsStateConversionThunk by their shared callee, with the three globals kept distinct. No state-machine structure is evident. All ten packet owners are UNKNOWN, so every class here is a GUESS proposal and no owner is claimed as CONFIRMED.

## Function roles

- `0x00526F69` **VectorMatrixTransformKernel** — 3DNow 4-component vector-matrix transform (pure matrix multiply, no reciprocal/w-divide step): splats the four floats of a2[0] into paired lanes v4/v6 and a2[1] into v7/v8, accumulates a1[0] from matrix columns a3[0]/a3[2]/a3[4]/a3[6] and a1[1] from a3[1]/a3[3]/a3[5]/a3[7], stores both output quads, emits _m_femms at entry and exit, returns a1. The this-offset refs are argument-buffer slots (a2 input quads and a1 output quads), not object state.
- `0x005275DC` **VectorMatrixTransformKernel** — 3DNow 2x2 linear transform over four packed input pairs: splats the two coefficients of a2[0] into v4/v6 and of a2[1] into v7/v8, computes output[0] = v4*a3[0] + v6*a3[2] + v7*a3[4] + v8*a3[6] and output[1] = v4*a3[1] + v6*a3[3] + v7*a3[5] + v8*a3[7], stores both pairs to a1 (+0x0, +0x8), clears MMX state with _m_femms at entry and exit, returns a1. The ABI name Matrix2x2_3DNow is LEGACY-trusted and names the operation, not an owning class.
- `0x0052804A` **FixedPointIDCTCodec** — Fixed-point inverse discrete cosine transform with per-block color/output transform: an 8-iteration column pass over 16-bit samples (coefficient object from a2 + 80, sample buffer at a3 + 96) writing intermediates to a stack buffer, then a 4-iteration output pass that maps four values through a 1024-entry lookup table based at (*(a1 + 0x11C)) + 128 (index ((value + 0x40000) >> 19) & 0x3FF), writing four bytes per pixel through the caller-supplied offset array a4 into a5; both passes have an all-zero fast path emitting a DC-only value. This is image/decode work rather than vehicle physics; the scope mismatch is recorded.
- `0x0053AD80` **TransformWorkBufferOwner** — SSE-accelerated 3x3 matrix by integer 3-vector transform: loads the output-vector working-buffer pointer from this+0x10 and the matrix-column buffer pointer from this+0x30, copies the three input components (a2[0..2]) into *(this+0x10) at +0x0/+0x4/+0x8 and the three matrix columns (a4[0..2]) into *(this+0x30) at +0x0/+0x10/+0x20, computes the transform as a sum of per-column dot products via SSE shuffle/mul/add (shuffle controls 0/85/170), stores the three result components to a3 and returns the first component.
- `0x0055EEAF` **VectorMatrixTransformKernel** — Float 3-vector transform by a 16-float row-major 4x4 matrix with translation: reads the input vector a1[0..2] (byte offsets 0x0, 0x4, 0x8), computes three dot products against matrix rows adding the translation components a3[12], a3[13], a3[14], stores the result into a2[0..2]. No branches or calls.
- `0x0055EF24` **VectorMatrixTransformKernel** — Float 3-vector transform by a 9-float row-major 3x3 matrix without translation: reads the input vector a1[0..2] (byte offsets 0x0, 0x4, 0x8), computes three dot products against matrix rows a3[0..8], stores the result into a2[0..2]. No branches or calls; the canonical corpus name is F_3x3MatrixFloat3VectorMultiply.
- `0x0057BC70` **PhysicsObject** — Stores the global Physics vtable pointer (off_5B8A00) into the object's first field at this+0x0, completing constructor-style vtable installation; the packet summary names a placement-delete dispatcher as the caller. The concrete object type receiving the vtable is not evidenced.
- `0x0059982F` **PhysicsStateConversionThunk** — Short forwarding wrapper: reads the global PhysicsStateWrapper_983b (the code label at 0x0059983B), casts it to int, passes it as the sole argument to BooleanToIntConversion (0x00587B3E) and returns the conversion result unchanged with no post-processing.
- `0x0059985C` **PhysicsStateConversionThunk** — Trivial delegation thunk: reads the global PhysicsSolverWrapper from 0x00599868 and forwards its value as the integer argument to BooleanToIntConversion (0x00587B3E), returning the conversion result directly. No branches, no local state.
- `0x0059AAA3` **PhysicsStateConversionThunk** — Short straight-line wrapper: reads the global PhysicsStateWrapper_aaaf, passes it cast to int into BooleanToIntConversion (0x00587B3E) and returns the conversion result.

## Proposed classes

### VectorMatrixTransformKernel

Stateless matrix-vector multiply primitives for physics coordinate work: 4D vector by 4x4 matrix via 3DNow without a w-divide (0x00526F69), 2x2 linear transform via 3DNow (0x005275DC), float 3-vector by row-major 4x4 with translation (0x0055EEAF), and float 3-vector by row-major 3x3 without translation (0x0055EF24). No fields are asserted: the this-relative refs on these bodies are argument buffers (input vector, output buffer, coefficient matrix), not object state. Grouping is proposed from the shared multiply-accumulate arithmetic pattern; owner identity is unknown.

Methods: `0x00526F69`, `0x005275DC`, `0x0055EEAF`, `0x0055EF24`


### TransformWorkBufferOwner

Object that owns the scratch transform buffers used by the SSE 3x3 by integer-vector routine 0x0053AD80: an output/vector working-buffer pointer at this+0x10 (three copied vector components at +0x0/+0x4/+0x8) and a matrix-column buffer pointer at this+0x30 (three columns at +0x0/+0x10/+0x20). This is the only class in the packet whose fields are real object state rather than argument buffers; the owning object is unidentified.

Methods: `0x0053AD80`

- `this+0x00000010` `pointer output_vector_buffer_ptr` (read, GUESS)
- `this+0x00000030` `pointer matrix_column_buffer_ptr` (read, GUESS)
- `*(this+0x10)+0x00000000` `int vector_cmp_0` (write, GUESS)
- `*(this+0x10)+0x00000004` `int vector_cmp_1` (write, GUESS)
- `*(this+0x30)+0x00000000` `m128 matrix_col_0` (write, GUESS)
- `*(this+0x30)+0x00000010` `m128 matrix_col_1` (write, GUESS)
- `*(this+0x30)+0x00000020` `m128 matrix_col_2` (write, GUESS)

### FixedPointIDCTCodec

Decode-stage object behind the fixed-point IDCT color transform 0x0052804A: runs an 8-iteration column pass and a 4-iteration output pass with the stated fixed-point butterfly coefficient sets and all-zero fast paths, and maps output values through a 1024-entry lookup table whose base pointer is read from this+0x11C plus 128. Scope note: this is image/video decoding work, not vehicle physics; the class is retained for evidence completeness and the mismatch is explicit.

Methods: `0x0052804A`

- `this+0x0000011C` `pointer output_lut_ptr` (read, GUESS)

### PhysicsObject

Physics object whose vtable pointer is installed into this+0x0 by 0x0057BC70 from the global Physics vtable off_5B8A00, completing constructor-style vtable installation. The concrete type and any further fields are not evidenced by the packet.

Methods: `0x0057BC70`

- `this+0x00000000` `pointer physics_vtable_ptr` (write, GUESS)

### PhysicsStateConversionThunk

Family of stateless delegation thunks that each read a distinct physics-state/flag global, cast it to int, forward it to BooleanToIntConversion (0x00587B3E) and return the conversion result unchanged: 0x0059982F (global PhysicsStateWrapper_983b), 0x0059985C (global PhysicsSolverWrapper_9868), 0x0059AAA3 (global PhysicsStateWrapper_aaaf). Grouped by the shared callee and identical structure; the three globals are kept distinct and are evidence, not fields. Whether the thunks register the globals as callbacks or merely forward state is not determinable from the packet.

Methods: `0x0059982F`, `0x0059985C`, `0x0059AAA3`


## Compatibility contracts

- **PhysicsVTableInstallationContract** — Object construction must install the global Physics vtable pointer off_5B8A00 into field this+0x0 via the vtable-install step 0x0057BC70; the packet summary indicates the step is invoked from a placement-delete dispatcher (0x005831B0, prose-only, not an evidence ref). The concrete receiving type is unknown.
- **BooleanStateConversionContract** — The physics wrapper thunks must read their designated global (0x0059983B, 0x00599868, or 0x0059AAAF), cast the value to int, pass it as the sole argument to BooleanToIntConversion (0x00587B3E), and return the conversion result unchanged with no post-processing.
- **MatrixVectorTransformContract** — Transform primitives must preserve five forms: 4D vector by 4x4 matrix accumulate without a w-divide over the 8-slot coefficient matrix (0x00526F69); 2x2 linear transform over four packed input pairs via 3DNow with column pairing (0,2,4,6) vs (1,3,5,7) (0x005275DC); SSE 3x3 by integer-3 with working buffers at this+0x10/this+0x30 and shuffle broadcasts 0/85/170 (0x0053AD80); float 3-vector by row-major 4x4 adding translation components a3[12..14] (0x0055EEAF); float 3-vector by row-major 3x3 without translation (0x0055EF24).
- **FixedPointIDCTColorTransformContract** — The fixed-point IDCT must run an 8-iteration column pass (skipping the v51 == 4 iteration) and a 4-iteration 32-byte-record output pass, both with the stated butterfly coefficient sets (15137/6270 first stage; 8697/11893/1730/17799/20995/7373/4926/4176 second stage) and all-zero fast paths, and map the four output values through the 1024-entry lookup table based at (*(this+0x11C)) + 128 with index ((value + 0x40000) >> 19) & 0x3FF. Out of scope for vehicle physics.

## Unresolved

- Scope mismatch: 0x0052804A is a fixed-point IDCT color transform (image/video decode work), not vehicle physics; it is retained for evidence completeness and its prelabel template classification as a getter of field 0x11C was rejected because the raw source shows the IDCT body.
- All ten packet owners are UNKNOWN; every class in this proposal is a GUESS (or DERIVED for the shared-callee and shared-arithmetic groupings) and no owner is promoted to CONFIRMED.
- For 0x00526F69 and 0x005275DC the packet maps both input quads (a2[0], a2[1]) and output quads (a1[0], a1[1]) onto the same this offsets 0x0 and 0x8; because a1 and a2 are separate bases these are not merged into one field (rule 8).
- The exact column-major layout of the 8-slot coefficient matrix in 0x00526F69 is inferred from the multiply-accumulate order, not verified against a consumer; whether a3 in 0x005275DC packs four 2-component vectors or two 4-component vectors is not recoverable from the function alone.
- The row-major 4x4 / 3x3 interpretation of a3 in 0x0055EEAF and 0x0055EF24 is DERIVED from the arithmetic; the prelabel cluster_copy link to Vector3ScalarMultiply (0045eb00) was not adopted because the raw bodies are matrix-by-vector products with translation (4x4) and without (3x3).
- The owning object of the working buffers this+0x10 and this+0x30 in 0x0053AD80 is unidentified; the shuffle control constants 0, 85, 170 encode component broadcast but their row/column ordering of the 3x3 matrix is DERIVED, not stated in evidence.
- 0x0057BC70's concrete object type receiving the Physics vtable off_5B8A00 is not evidenced; the caller named in the packet summary (0x005831B0) is prose-only and not an allowed evidence ref.
- The globals 0x0059983B, 0x00599868 and 0x0059AAAF are code labels or state flags per the legacy ABI names; whether the thunks register those labels as callbacks or merely forward a boolean state through BooleanToIntConversion is not determinable from this packet, and the three globals are kept distinct.
- The IDCT sample-buffer layout (a3 + 96), the coefficient object (from a2 + 80), the 1024-entry table semantics, and the output color/byte ordering of the four pixels are unknown; the 32-byte record stride is inferred from the second loop.
- No state-machine structure is evident in this packet; state_machines is empty.
- Equal offsets on different bases (e.g. this+0x0 used by 0x0057BC70 as a vtable field and by 0x0055EEAF/0x0055EF24 as an input-vector component) are never merged without packet proof of common ownership (rule 8).
