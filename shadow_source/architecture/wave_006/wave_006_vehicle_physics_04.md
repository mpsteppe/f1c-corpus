# VehiclePhysics

Scope: `vehicle_physics`  
Trust: `DERIVED`

Twenty-two functions spanning SIMD matrix/vector math (3DNow!/MMX/SSE), a fixed-point quaternion pipeline with surface-table sampling, two audio sub-band transforms (32-point MDCT and MMX synthesis), the vehicle physics joint/constraint solver batch state, physics-state field accessors, a scene-node update that consumes collision/visibility results, and a composite network/physics destructor chain. None of the owner objects are established (all owner evidence is UNKNOWN or a DERIVED prelabel); the grouping into classes below is a DERIVED proposal justified only by shared field bases, shared global tables, and structural-twin relationships stated in the packet.

## Function roles

- `0x00522A6C` **SimdMatrixMath4x4** — Constructs a 4x4 diagonal scale matrix over eight qword slots from three integer inputs using 3DNow! intrinsics; returns the matrix base pointer. The integer inputs are interpreted as bit patterns of floats by the caller.
- `0x00522CE2` **SimdMatrixMath4x4** — 3DNow!-intrinsic composition of a 4x4 transform from up to six optional packed-float inputs; every null input falls back to an identity component. The inverse-rotation product algorithm matches sub_522B5B. Returns the output matrix pointer.
- `0x0052466C` **SimdMatrixMath4x4** — MMX/3DNow!-intrinsic composition of a 4x4 transform from up to six optional packed-float inputs; structural twin of composeCompositeTransformMatrix3DNow (0x00522CE2) using _m_pswapd/_m_pfpnacc where the twin uses punpck. Returns the output matrix pointer.
- `0x00526B55` **SimdMatrixMath4x4** — Vector transform helper: builds a 4x4 transform into a local array by selecting up to three optional matrix inputs a6/a7/a8 via an 8-case jump-table switch (global 0x00526C88), inverting or composing them with F_4x4MatrixInversion / F_8SIMDMatrixPackedFloatOperation, optionally blending the input vector toward a4, then transforming it through F_4DVectorTransform.
- `0x0052B561` **FixedPointQuaternionTransform** — MMX/3DNow! fixed-point pipeline that multiplies 16 packed 16-bit lanes, performs two rotation passes with lane reordering, then samples a byte-indexed surface lookup table for 8 destination texel slots; flushes MMX state with _m_empty() and returns the final sampled byte.
- `0x00531B50` **Mdct32SubbandTransform** — 32-point Modified Discrete Cosine Transform over 32 input floats: folds samples into a shared static 64-float scratch buffer, runs four staged butterfly passes with a read-only cosine coefficient table, and de-interleaves 32 results into two 256-float sub-band output buffers. Called by the audio mixer path (caller 0x00531830) as the sub-band transform stage.
- `0x00534120` **MmxSubbandSynthesisTransform** — MMX sub-band-synthesis transform for the audio path: splits eight 64-bit input lanes into 16-bit halves, builds per-octave sum/difference terms, applies two banks of 16-row pmaddwd products against constant coefficient tables, folds with psrlqi/paddd, arithmetic-shifts right by 0xE, and stores 16-bit results into two output word buffers. Invoked by the audio resampler (caller 0x00532AA0).
- `0x0053AE00` **SseMatrixVectorTransform** — SSE-accelerated 4x4 matrix transform of a single 3-component integer vector with implicit w=1: copies the four __m128 matrix columns from the argument into the column buffer at *(this+0x30), seeds the working vector buffer at *(this+0x10) with w=1, and computes the four-component dot product per column. Straight-line, no branches, no calls.
- `0x0053AEB0` **SseMatrixVectorTransform** — Batch vertex transform, structural twin of SSEMatrixVectorTransform (0x0053AE00): reads the batch count from a2[2], loops transforming source vertices (12-dword stride) through the 4-column SSE matrix-vector product into a 16-dword-stride output, then continues over the remainder of the source array with a 3-column product into a 5-dword-stride output.
- `0x00540CA1` **PhysicsStateSnapshot** — Stores two consecutive dwords into a physics/vehicle state object: a2 at a3 + 5084 and the return-register value at a3 + 5088, then returns that second value. The __userpurge ABI reuses eax as the second stored value; a4 is unused.
- `0x00556B10` **SceneNodeUpdate** — Updates a scene node's collision and visibility state without setting a full world transform: branches on a node flag bit at this+0x3C, performs transform/bone copies through the scene-manager vtable, runs collision contact detection and AABB visibility classification, then finalizes rendering/material state according to node state flag bits.
- `0x005593C6` **PhysicsStateFieldAccessor** — Unconditionally zeroes dword this[7] (field 0x1C) of the physics-state object; arguments a2 and a3 are unused. No guards, globals, callees, or return value.
- `0x0055EE20` **MatrixTransformVertices** — Transforms an array of 3D position vectors through a 4x4 matrix: stores the vertex count from this+0x8 into global dword_5DC470, then loops over the source vertices (this+0xC, 12-float stride) writing three transformed components per vertex into the output array (this+0x3C, 6-float stride). Called by ThinWrapperDropsA1 (0x0053ACF0).
- `0x00564000` **PhysicsObjectNameCompare** — Resolves a value through helper sub_5644B0 applied to global byte_5EA438 and feeds the same expression to both strcmp operands, then returns the negated comparison when the dword at dword_8D46B4 + 132 is zero. If sub_5644B0 is deterministic the comparison degenerates to zero.
- `0x0056C2C4` **PhysicsStateFieldAccessor** — Single-statement byte flag setter: ORs the char argument a1 into a byte at v3+94 (compound |=). The decompiled frame is flagged positive-sp, v3 is an uninitialized local, so the true base of the byte write is not established by this packet.
- `0x0056EB90` **VehiclePhysicsSolver** — Iterates over a count of 580-byte joint structs referenced by this[1]; zeroes 12 consecutive DWORD work slots (DWORD indexes 77..88) in each, clearing constraint-solver scratch state. Called from PhysicsIntegrationStep on the frame path (caller 0x00441D60).
- `0x0056ECF0` **VehiclePhysicsSolver** — Executes one physics constraint-solver step for the batch: when no virtual solver object is installed it clears the constraint matrix row/column entries, runs the three-pass batch processing transform, transforms the inertia-tensor vector of every wheel body in the joint array (stride 580), reinitializes identity matrices for active batch bodies and constraints, then finishes through the vtable solve virtual or the non-virtual matrix-solve helper at 0x0056CD70.
- `0x0056F060` **VehiclePhysicsSolver** — Batch iteration helper (__thiscall): reads the element count from this+0x0; while positive, iterates that many element slots at base this+0x4 stepping 580 bytes and calls VehiclePhysicsStateCopyTransform on each slot. Called from StateAccumulateDelta (0x00441360). Returns the count read from this+0x0.
- `0x0057BCE0` **NetworkPhysicsCompositeObject** — Destructor for a composite network/physics/IO object: installs the IOOps vtable (off_5B8A68) at this+0x0, tears down the network subsystem, walks eight guard-byte/HANDLE pairs closing each handle when guard and handle are set, destroys interleaved linked-list and buffer sub-objects, swaps in the physics vtable (off_5B8A00) at this+0x940, and chains into sub_583AE0(this) whose result is the return value.
- `0x005986F8` **VehicleSubsystemGlobalThunks** — Parameterless forwarding wrapper (vehicle subsystem): passes the address of global unk_8D4248 as the single argument to a locale-teardown destructor helper and returns the callee's result unchanged.
- `0x0059880B` **VehicleSubsystemGlobalThunks** — Stdcall forwarding thunk (vehicle subsystem): reads global dword_8D4210 as a base pointer, casts it to char*, and forwards it with the four incoming arguments a1..a4 to a vtable-fixup-with-destructor helper, returning its result unchanged.
- `0x005997E1` **VehicleSubsystemGlobalThunks** — Wrapper that returns the result of decrementing the reference count (with dead-object check) of the global physics-state object at 0x008D4438.

## Proposed classes

### SimdMatrixMath4x4

SIMD/3DNow!/MMX 4x4 matrix construction, composition, inversion-selection and vector transform over eight qword slots (row-major packed float pairs). Slot 7 (0x38) carries the homogeneous 1.0/1.0 packed constant; slots 0x30 and 0x38 double as translation storage. The 8-case dispatch in 0x00526B55 selects among up to three optional matrix inputs.

Methods: `0x00522A6C`, `0x00522CE2`, `0x0052466C`, `0x00526B55`

- `this+0x00000000` `u64_qword matrixSlot0` (read_write, DERIVED)
- `this+0x00000008` `u64_qword matrixSlot1` (read_write, DERIVED)
- `this+0x00000010` `u64_qword matrixSlot2` (read_write, DERIVED)
- `this+0x00000018` `u64_qword matrixSlot3` (read_write, DERIVED)
- `this+0x00000020` `u64_qword matrixSlot4` (read_write, DERIVED)
- `this+0x00000028` `u64_qword matrixSlot5` (read_write, DERIVED)
- `this+0x00000030` `u64_qword matrixSlot6Translation` (read_write, DERIVED)
- `this+0x00000038` `u64_qword matrixSlot7Homogeneous` (read_write, DERIVED)

### FixedPointQuaternionTransform

MMX/3DNow! fixed-point pipeline that multiplies 16 packed 16-bit lanes of source data using fixed-point scale constants, performs two rotation passes with lane reordering, then samples a byte-indexed surface lookup table for 8 destination texel slots. The lane-to-component mapping is not grounded; the surface-table entry format is inferred.

Methods: `0x0052B561`

- `this+0x00000000` `u16_lane_pair lane0` (read_write, GUESS)
- `this+0x00000008` `u16_lane_pair lane1` (read_write, GUESS)
- `this+0x00000010` `u16_lane_pair lane2` (read_write, GUESS)
- `this+0x00000018` `u16_lane_pair lane3` (read_write, GUESS)
- `this+0x00000020` `u16_lane_pair lane4` (read_write, GUESS)
- `this+0x00000028` `u16_lane_pair lane5` (read_write, GUESS)
- `this+0x00000030` `u16_lane_pair lane6` (read_write, GUESS)
- `this+0x00000038` `u16_lane_pair lane7` (read_write, GUESS)
- `this+0x00000040` `u16_lane_pair lane8` (read_write, GUESS)
- `this+0x00000048` `u16_lane_pair lane9` (read_write, GUESS)
- `this+0x00000050` `u16_lane_pair lane10` (read_write, GUESS)
- `this+0x00000058` `u16_lane_pair lane11` (read_write, GUESS)
- `this+0x00000060` `u16_lane_pair lane12` (read_write, GUESS)
- `this+0x00000068` `u16_lane_pair lane13` (read_write, GUESS)
- `this+0x00000070` `u16_lane_pair lane14` (read_write, GUESS)
- `this+0x00000078` `u16_lane_pair lane15` (read_write, GUESS)

### SseMatrixVectorTransform

SSE-accelerated 4x4 matrix-vector transform of 3-component vectors with implicit affine w=1, using a per-call working vector buffer at *(this+0x10) and a 16-byte-aligned matrix column buffer at *(this+0x30). The batch twin loops over vertex arrays with distinct output strides.

Methods: `0x0053AE00`, `0x0053AEB0`

- `this+0x00000010` `pointer_to_float4 workingVectorBufferPtr` (read_write, DERIVED)
- `this+0x00000030` `pointer_to_m128x4 matrixColumnBufferPtr` (read_write, DERIVED)
- `*(this+0x10)+0x00000000` `float vectorX` (read_write, DERIVED)
- `*(this+0x10)+0x00000004` `float vectorY` (read_write, DERIVED)
- `*(this+0x30)+0x00000000` `__m128 column0` (read_write, DERIVED)
- `*(this+0x30)+0x00000010` `__m128 column1` (read_write, DERIVED)
- `*(this+0x30)+0x00000020` `__m128 column2` (read_write, DERIVED)
- `*(this+0x30)+0x00000030` `__m128 column3` (read_write, DERIVED)

### Mdct32SubbandTransform

32-point Modified Discrete Cosine Transform folding 32 samples through four staged butterfly passes into two 256-float sub-band output buffers. Uses a shared static 64-float scratch buffer (flt_8B5924..0x8B5A20) and a read-only cosine coefficient table (0x005B772C..0x005B77A4); the transform is therefore not re-entrant by construction.

Methods: `0x00531B50`

- `this+0x00000000` `float_subband outputSlot0` (write, GUESS)
- `this+0x00000040` `float_subband outputSlot1` (write, GUESS)
- `this+0x00000080` `float_subband outputSlot2` (write, GUESS)
- `this+0x000000C0` `float_subband outputSlot3` (write, GUESS)
- `this+0x00000100` `float_subband outputSlot4` (write, GUESS)
- `this+0x00000140` `float_subband outputSlot5` (write, GUESS)
- `this+0x00000180` `float_subband outputSlot6` (write, GUESS)
- `this+0x000001C0` `float_subband outputSlot7` (write, GUESS)
- `this+0x00000200` `float_subband outputSlot8` (write, GUESS)
- `this+0x00000240` `float_subband outputSlot9` (write, GUESS)
- `this+0x00000280` `float_subband outputSlot10` (write, GUESS)
- `this+0x000002C0` `float_subband outputSlot11` (write, GUESS)
- `this+0x00000300` `float_subband outputSlot12` (write, GUESS)
- `this+0x00000340` `float_subband outputSlot13` (write, GUESS)
- `this+0x00000380` `float_subband outputSlot14` (write, GUESS)
- `this+0x000003C0` `float_subband outputSlot15` (write, GUESS)
- `this+0x00000400` `float_subband outputSlot16` (write, GUESS)

### MmxSubbandSynthesisTransform

MMX sub-band synthesis for the audio resampler path: splits eight 64-bit input lanes into 16-bit halves, computes per-octave sum/difference terms, applies two banks of 16-row pmaddwd products against constant coefficient tables (unk_8D7200 rows, qword_8D7000 qwords), folds each 32-bit accumulation with psrlqi/paddd, arithmetic-shifts right by 0xE, and stores 16-bit results into two output word buffers.

Methods: `0x00534120`

- `this+0x00000000` `u16_wordBuffer outputWordSlot0` (write, GUESS)
- `this+0x00000020` `u16_wordBuffer outputWordSlot1` (write, GUESS)
- `this+0x00000040` `u16_wordBuffer outputWordSlot2` (write, GUESS)
- `this+0x00000060` `u16_wordBuffer outputWordSlot3` (write, GUESS)
- `this+0x00000080` `u16_wordBuffer outputWordSlot4` (write, GUESS)
- `this+0x000000A0` `u16_wordBuffer outputWordSlot5` (write, GUESS)
- `this+0x000000C0` `u16_wordBuffer outputWordSlot6` (write, GUESS)
- `this+0x000000E0` `u16_wordBuffer outputWordSlot7` (write, GUESS)
- `this+0x00000100` `u16_wordBuffer outputWordSlot8` (write, GUESS)
- `this+0x00000120` `u16_wordBuffer outputWordSlot9` (write, GUESS)
- `this+0x00000140` `u16_wordBuffer outputWordSlot10` (write, GUESS)
- `this+0x00000160` `u16_wordBuffer outputWordSlot11` (write, GUESS)
- `this+0x00000180` `u16_wordBuffer outputWordSlot12` (write, GUESS)
- `this+0x000001A0` `u16_wordBuffer outputWordSlot13` (write, GUESS)
- `this+0x000001C0` `u16_wordBuffer outputWordSlot14` (write, GUESS)
- `this+0x000001E0` `u16_wordBuffer outputWordSlot15` (write, GUESS)
- `this+0x00000200` `u16_wordBuffer outputWordSlot16` (write, GUESS)

### PhysicsStateSnapshot

Writes a two-dword state snapshot pair into a physics/vehicle state object at offsets +5084 and +5088. The __userpurge ABI passes the second value through the return register. The offsets are not packet-listed field refs and the owning class is unidentified.

Methods: `0x00540CA1`


### SceneNodeUpdate

Scene-node collision/visibility update without a full world transform: flag-bit dispatch at this+0x3C, transform and bone copies through the scene-manager vtable behind global 0x008B8F24, collision contact detection and AABB visibility classification, and mesh dirty-flag finalization according to node state flag bits.

Methods: `0x00556B10`

- `this+0x0000003C` `u8_flags nodeFlagByte` (read, GUESS)
- `this+0x00000204` `u8_transform transformSource` (read, GUESS)

### PhysicsStateFieldAccessor

Reads and writes individual state fields of a physics-state object. 0x005593C6 unconditionally zeroes dword 0x1C; 0x0056C2C4 OR-accumulates a flag byte into an unverified base (v3+94, frame flagged positive-sp).

Methods: `0x005593C6`, `0x0056C2C4`

- `this+0x0000001C` `dword stateField` (write, GUESS)

### MatrixTransformVertices

Transforms a count of 3D position vectors (source at this+0xC, 12-float stride) through a 4x4 matrix into a 6-float-stride output (this+0x3C). Vertex count is stored into global dword_5DC470 before the loop.

Methods: `0x0055EE20`

- `this+0x00000008` `dword vertexCount` (read, GUESS)
- `this+0x0000000C` `pointer_to_float3x12 sourceVertices` (read, GUESS)
- `this+0x0000003C` `pointer_to_float6stride outputVertices` (read, GUESS)

### PhysicsObjectNameCompare

Resolves a value through helper sub_5644B0 applied to global byte_5EA438 and feeds the same expression to both strcmp operands; the returned comparison is negated when a flag dword at global object 0x8D46B4 + 132 is zero. If the helper is deterministic the comparison degenerates to zero.

Methods: `0x00564000`


### VehiclePhysicsSolver

Vehicle physics joint/constraint solver batch state: count and element-array pairs over 580-byte (0x244) joint elements, batch and constraint identity reinitialization, constraint-matrix row/column clearing, the three-pass batch processing transform, wheel-body inertia-tensor transforms, and the per-element work-field clearing run on the frame path. An optional virtual solver (this+0x30) overrides the non-virtual matrix-solve helper at 0x0056CD70.

Methods: `0x0056EB90`, `0x0056ECF0`, `0x0056F060`

- `this+0x00000000` `dword elementCount` (read_write, DERIVED)
- `this+0x00000004` `pointer_to_580byte_elements elementsArray` (read, DERIVED)
- `this+0x00000008` `dword batch1Count` (read, GUESS)
- `this+0x0000000C` `pointer batch1Array` (read, GUESS)
- `this+0x00000010` `dword batch2Count` (read, GUESS)
- `this+0x00000014` `pointer batch2Array` (read, GUESS)
- `this+0x00000018` `dword constraintCount` (read, GUESS)
- `this+0x0000001C` `pointer constraintArray` (read, GUESS)
- `this+0x00000020` `dword matrixRowCount` (read, GUESS)
- `this+0x00000028` `pointer matrixColumns` (read, GUESS)
- `this+0x0000002C` `pointer matrixRowEntries` (read, GUESS)
- `this+0x00000030` `pointer_to_vtable solverVtable` (read, GUESS)
- `*(this+0x30)+0x00000014` `vtable_entry solveMethod` (read, GUESS)
- `*(this+0x30)+0x0000001C` `vtable_entry clearMatrixMethod` (read, GUESS)

### NetworkPhysicsCompositeObject

Composite network/physics/IO object: installs the IOOps vtable (off_5B8A68) at this+0x0, tears down the network subsystem, closes eight guard-byte/HANDLE resource pairs (4-byte stride, guard byte at handle+8), destroys interleaved linked-list and buffer sub-objects, swaps in the physics vtable (off_5B8A00) at this+0x940, and chains into final cleanup.

Methods: `0x0057BCE0`

- `this+0x00000000` `pointer_to_vtable ioOpsVtable` (write, GUESS)
- `this+0x00000940` `pointer_to_vtable physicsVtable` (write, GUESS)
- `this+0x00000AF4` `win32_handle handleSlot1` (read_write, GUESS)
- `this+0x00000AFC` `u8_guard guardByte1` (read, GUESS)
- `this+0x00000B10` `win32_handle handleSlot2` (read_write, GUESS)
- `this+0x00000B18` `u8_guard guardByte2` (read, GUESS)
- `this+0x00000B2C` `win32_handle handleSlot3` (read_write, GUESS)
- `this+0x00000B34` `u8_guard guardByte3` (read, GUESS)
- `this+0x00000B3C` `win32_handle handleSlot4` (read_write, GUESS)
- `this+0x00000B44` `u8_guard guardByte4` (read, GUESS)
- `this+0x00000B68` `win32_handle handleSlot5` (read_write, GUESS)
- `this+0x00000B70` `u8_guard guardByte5` (read, GUESS)
- `this+0x00000B94` `win32_handle handleSlot6` (read_write, GUESS)
- `this+0x00000B9C` `u8_guard guardByte6` (read, GUESS)
- `this+0x00000BC0` `win32_handle handleSlot7` (read_write, GUESS)
- `this+0x00000BC8` `u8_guard guardByte7` (read, GUESS)
- `this+0x00000BEC` `win32_handle handleSlot8` (read_write, GUESS)
- `this+0x00000BF4` `u8_guard guardByte8` (read, GUESS)

### VehicleSubsystemGlobalThunks

Thin forwarding shims of the vehicle subsystem that operate on module globals (0x008D4210, 0x008D4248, 0x008D4438), passing them to vtable-fixup, locale-teardown, and reference-count decrement helpers whose absolute addresses are not evidenced in the packet.

Methods: `0x005986F8`, `0x0059880B`, `0x005997E1`


## Compatibility contracts

- **Matrix4x4EightQwordLayout** — A 4x4 transform matrix is eight qword slots at base+0x0..0x38 (row-major packed float pairs). Slot 7 (base+0x38) carries the homogeneous packed constant 0x3F8000003F800000; slots base+0x30 and base+0x38 double as translation storage. 0x00522A6C, 0x00522CE2 and 0x0052466C depend on this layout; a replacement must preserve the packed-pair representation and the packed identity constant.
- **SseBufferPointerSlots** — SSE matrix-vector transforms require a working vector buffer pointer at this+0x10 (four floats, w seeded to 1.0f / 1065353216) and a matrix column buffer at this+0x30 (four __m128 columns). 0x0053AE00 and 0x0053AEB0 depend on both buffers being valid for the transform.
- **VehicleJointElementStride580** — Vehicle physics joint/work elements are 580 bytes (0x244) each, reached through the element array at this+0x4 with count at this+0x0; DWORD indexes 77..88 are per-element constraint-solver scratch cleared every frame, and each element's transform is copied by VehiclePhysicsStateCopyTransform. A replacement must preserve the 580-byte stride and the 12-slot work region.
- **StaticScratchNonReentrantTransform** — Transform32PointMDCT (0x00531B50) uses a shared static 64-float scratch buffer (flt_8B5924..0x8B5A20) and a read-only cosine coefficient table (0x005B772C..0x005B77A4); it is not re-entrant and cannot be interleaved with itself on the audio path.
- **GuardedHandleResourcePairPattern** — The composite network/physics/IO object exposes eight resource pairs at 4-byte stride where the Win32 HANDLE sits 8 bytes before its guard byte; a slot is closed (CloseHandle) and zeroed only when both the guard byte and the handle are set. Replacement teardown must preserve this pairing and the guard semantics.

## Unresolved

- The three read-only globals qword_5AF8E0/qword_5AF8F0/qword_5AF900 are flagged as read by 0x00522CE2 and 0x0052466C but do not appear by name in the raw decompiled source (constants render inline); their mapping to 0x3F800000 / 0x3F8000003F800000 / 1065353216 is not established.
- The 3DNow! blend constants at 0x005AF980/0x005AF988/0x005AF998 in 0x00526B55 are identified only as read packed-float constants; the weighting scale semantics are caller-determined.
- The fixed-point quaternion sampler's read-only globals 0x005B0C70..0x005B0C90 do not appear in the decompiled body; their relationship to the inline immediates (0x16A0000016A, 0x11500000115, 0x1D9000001D9, 0xFD630000FD63) is not determinable.
- The lane-to-component mapping of the two-pass fixed-point transform in 0x0052B561 is not grounded in the raw source; the surface-table format (byte per entry at a6, indexed with a 0x3FF mask) is inferred.
- The 8-case jump-table dispatch of 0x00526B55 (global 0x00526C88) selects among a6/a7/a8 matrix inputs; their semantics (parent/child/inverse transforms) are caller-determined.
- The exact mapping between the inline floating-point coefficient literals and the read-only globals 0x005B772C..0x005B77A4 is not recoverable; the table is consumed as the cosine coefficient set. The 64 scratch floats are shared static storage, so the MDCT is not re-entrant.
- The mapping between field:this offsets and the a1/a2 word indices in 0x00534120 is not resolvable from this packet; the purpose of the returned qword_8D7000 pointer is unknown.
- SSE working-buffer slot *(this+0x10):0x4 is packet-flagged read-only while the decompiled source both reads and writes the Y component through it; the owning class layout and why the transform is split across two buffers is not established.
- The two distinct vertex transforms in 0x0053AEB0 use different output strides (16 dwords then 5 dwords); the destination layout and the relationship between matrices a3 and a4 are not established.
- PhysicsStateStoreTwoInts (0x00540CA1): the meaning of the dword pair at +5084/+5088 and the identity of the state object are not named in this packet.
- Scene node 0x00556B10: the a3 node-state offsets (flags at +20, contact data, AABBs, count at +280, entries at +284) are inferred from usage; dword_8B8F28 role is unknown; the state flag bit meanings (0x20000000, 0x4, 0x8, 0x20, 0x2000000, 0x100, 0x100000, 0x10000000, 0x400) are inferred from branch context only.
- clearPhysicsStateField (0x005593C6): arguments a2/a3 are unused and the meaning of field 0x1C (state/counter per the existing analysis fill) is not grounded in packet evidence.
- MatrixTransformVertices (0x0055EE20): fields this+0x10/0x14/0x40/0x44 are packet-flagged but never referenced in the decompiled source; the two spare floats of the 6-float output stride are undefined.
- PhysicsObjectNameCompare (0x00564000): identity and determinism of helper sub_5644B0 are unknown (if deterministic, both strcmp operands are identical); the type and role of the object at dword_8D46B4 and its offset-132 flag are unknown.
- PhysicsStateFlagSetter (0x0056C2C4): the decompiler reports a positive sp value; the frame is mangled, v3 is an uninitialized local, and the real base of the byte write (v3+94) is unknown.
- ZeroFillVehiclePhysicsJointWorkFields (0x0056EB90): the element struct type and the semantic names of DWORD slots 77..88 are not established; stride 580 and the joint-solver-work-area purpose are carried from existing analysis.
- PhysicsConstraintSolverStep (0x0056ECF0): the flag bit 0 at +44 (batch bodies) versus +68 (constraints) is inferred from the identity-reinit pattern only; the body index indirection (+8 pointer then +48 or +124) is followed mechanically from the decompiled reads.
- NetworkPhysicsDestructorChain (0x0057BCE0): the owning class is unidentified; the repeated guard-byte/HANDLE pairs suggest a generated or templated member pattern; SEH_57BCE0 (0x0059C990) is registered but does not appear in the raw source.
- PhysicsStateWrapper (0x005986F8) and PhysicsThunk (0x0059880B): the callees are named in the raw source but carry no address evidence here; the meaning of globals 0x008D4248 and 0x008D4210 is unknown.
- decrementPhysicsStateRefCount (0x005997E1): the absolute address of RefCountDecrementWithCheck is absent from the packet; whether this wrapper is a static-exit trampoline or a live-method call site is unresolved.
