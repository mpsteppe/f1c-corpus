# MathAndCollision

Scope: `math_and_collision`  
Trust: `DERIVED`

14 functions in three clusters. Cluster A: 3DNow!/MMX packed-float math (0x0052692F matrix composition/blend with a null-state jump-table switch and F_4DVectorTransform application, 0x00526CFD 2x2 matrix-vector multiply, 0x00526E7B/0x00526FEB/0x00527578 vector normalize with Newton-refined pfrsqrt and the qword_5AF970 near-zero guard, 0x005274BA weighted vector lerp). Cluster B: float matrix math (0x0055EF88 row-based 4x4 multiply, 0x0053B000 thin forwarding wrapper that ignores its first argument) and an SSE force/torque contribution with an optional accumulator vector at this+0x17C/0x180/0x184 (0x0053BB30). Cluster C: generic utilities (0x0053C1C0 one-time guarded stub-table registration over 42 entries, 0x0053C9C0 flag-array rewrite of bit 0x4000 to 0x400, 0x0054EEC1 five-dword fill, 0x0054FDA0 array copy-with-realloc owning this+0x4C/this+0x50, 0x00592A62 fixed-stride record search). All owners are UNKNOWN; the classes below are grouping proposals, not recovered class identities.

## Function roles

- `0x0052692F` **UnknownObject** — Compose up to three optional transform inputs (a6, a7, a8) into a packed 4x4 matrix, selected by a null-state bitmask jump table (jpt_526969) and normalized via sub_525E9A; then either interpolate the input vector a4 toward the blend weight a5 (MMX reciprocal/scale) or transform a4 directly, applying the composed matrix via F_4DVectorTransform; returns the output vector pointer a3
- `0x00526CFD` **UnknownObject** — 3DNow! 2x2 matrix-vector multiply: duplicate the low and high packed-single lanes of the input vector a2, multiply against the packed pairs at a3[0] and a3[2], sum pairwise into the output m64 at this+0x0, return the output pointer a1
- `0x00526E7B` **UnknownObject** — 3DNow! 2-component vector normalize: lane-wise square, pfacc horizontal sum, pfrsqrt with Newton-Raphson refinement, near-zero guard via pfcmpgt against qword_5AF970, store masked input times refined root to this+0x0, femms at exit, return a1
- `0x00526FEB` **UnknownObject** — 3DNow! 4-component vector normalize over two packed pairs (this+0x0, this+0x8): squared length via pfmul/pfadd/pfacc, pfrsqrt with Newton refinement, qword_5AF970 near-zero guard mask, write both normalized pairs, femms at entry and exit, return a1
- `0x005274BA` **UnknownObject** — 3DNow! weighted linear interpolation between endpoints a3 and a4 by weight vector a2: build the denominator dot(a2, a3 - a4), zero-denominator guard returns null, refined reciprocal forms factor t, lerp the x/y pair into this+0x0 and the z component into the low dword of this+0x8, femms before return
- `0x00527578` **UnknownObject** — 3DNow! 4-component vector normalize (x,y,z,w) used to normalize quaternion/rotation vectors by F_3DNowQuaternionFromAngle and QuaternionTo4x4RotationMatrix: packed squared length, qword_5AF970 threshold guard, qword_5AF950 mask, Newton-refined pfrsqrt, write both normalized pairs to this+0x0/this+0x8
- `0x0053B000` **UnknownObject** — Thin forwarding wrapper over the 4x4 float matrix multiply: ignores the first cdecl argument a1 and forwards a2/a3/a4 unchanged to F_4x4MatrixMultiply_ef88 (0x0055EF88), returning its result verbatim
- `0x0053BB30` **UnknownObject** — SSE force/torque-style contribution: scale three components of a2 (indices 2..4) by scalar a2[5], multiply component-wise by a transform row (a3[21..23]), optionally add an accumulator vector at this+0x17C/0x180/0x184 when a1 is non-null, add a3[29..31], scale every lane by 255.0f, store to the output a4, return a4
- `0x0053C1C0` **UnknownObject** — One-time guarded initialization: latch bit 2 of byte_8B8EE4, then walk the table at dword_8B78A0 backwards in 76-byte (19-dword) steps across exactly 42 entries, calling EmptyStub_7470 on each entry pointer
- `0x0053C9C0` **UnknownObject** — Walk a dword-flag array (base dword_8B5A38, count dword_8B8E30, 33-dword stride) and rewrite every element that has bit 0x4000 set: clear 0x4000 (mask 0xFFFFBBFF) and set 0x400; tail-call SearchPathPrune(this) and return its result
- `0x0054EEC1` **UnknownObject** — Unconditional fill of five consecutive DWORD slots (offsets 0x0..0x10) with the integer value a2; returns the destination pointer
- `0x0054FDA0` **UnknownObject** — Replace the dynamically owned DWORD array on the receiver: free the prior allocation at this+0x4C when non-null (0x00587BCF), allocate a3 DWORDs (0x00587C03), copy a3 elements from source a2 into the new buffer, record the count at this+0x50, return the element count; used during DirectX mesh vertex buffer parsing (0x00547B40)
- `0x0055EF88` **UnknownObject** — Row-based 4x4 float matrix multiply a3 = a1 * a2: exactly four output rows, each computed as four dot products of the current a1 row against the a2 columns (a2[0..15]), advancing both row pointers by 4 floats per iteration; pure math utility with no branches, calls, globals or guards
- `0x00592A62` **UnknownObject** — Linear search over an array of fixed-stride records (3 DWORDs / 12 bytes, identified by the first DWORD): searches for a record whose key equals a1, bounded by the record count in dword_5E7894; returns the matching record pointer, or 0 when not found

## Proposed classes

### PackedSIMDVectorNormalize

Three 3DNow! vector-normalize routines (2- and 4-component) sharing the same structure: packed squared length, Newton-refined pfrsqrt, near-zero threshold guard via qword_5AF970, and the mask constant qword_5AF950 in the 4-component variant. Grouping is structural; no class identity is evidenced.

Methods: `0x00526E7B`, `0x00526FEB`, `0x00527578`

- `this+0x00000000` `__m64 packedComponentPair0` (read_write, GUESS)
- `this+0x00000008` `__m64 packedComponentPair1` (read_write, GUESS)

### Matrix4x4Multiply

4x4 float matrix multiply and its forwarding wrapper: 0x0055EF88 implements the row-based multiply, 0x0053B000 is a thin cdecl wrapper that ignores its first argument and forwards three operands to the primitive. The field reads at this+0x0..0xC are attributed to the second matrix's first row (DERIVED from the arithmetic, since the raw source has no this pointer).

Methods: `0x0053B000`, `0x0055EF88`

- `this+0x00000000` `float matrixRowElement0` (read, GUESS)
- `this+0x00000004` `float matrixRowElement1` (read, GUESS)
- `this+0x00000008` `float matrixRowElement2` (read, GUESS)
- `this+0x0000000C` `float matrixRowElement3` (read, GUESS)

### ForceAccumulatorComputation

SSE force/torque-style contribution computation that reads a three-lane accumulator vector at this+0x17C/0x180/0x184 (lane order inferred from the field ordering, not confirmed). The owning object and the meaning of the transform/offset indices in the a3 argument are not evidenced.

Methods: `0x0053BB30`

- `this+0x0000017C` `float forceAccumComponent0` (read, GUESS)
- `this+0x00000180` `float forceAccumComponent1` (read, GUESS)
- `this+0x00000184` `float forceAccumComponent2` (read, GUESS)

### DynamicDwordArrayOwner

Object owning a dynamically allocated DWORD array (pointer at this+0x4C) with an element count at this+0x50, replaced wholesale by 0x0054FDA0 (free prior buffer, allocate, copy). Used to store per-element integer data during DirectX mesh vertex buffer parsing.

Methods: `0x0054FDA0`

- `this+0x0000004C` `unsigned int* dwordArrayPointer` (read_write, GUESS)
- `this+0x00000050` `int dwordArrayCount` (write, GUESS)

### DwordRegionFill

Unconditional fill of five consecutive DWORD slots (offsets 0x0..0x10) with a single integer value at a caller-supplied pointer. Whether the slots form an array versus distinct struct fields is not established; ownership of the destination is unknown.

Methods: `0x0054EEC1`

- `this+0x00000000` `unsigned int dwordSlot0` (write, GUESS)
- `this+0x00000004` `unsigned int dwordSlot1` (write, GUESS)
- `this+0x00000008` `unsigned int dwordSlot2` (write, GUESS)
- `this+0x0000000C` `unsigned int dwordSlot3` (write, GUESS)
- `this+0x00000010` `unsigned int dwordSlot4` (write, GUESS)

## Compatibility contracts

- **PackedVectorNormalizeLayout** — The 3DNow! normalize routines read and write a 2- or 4-component vector as one or two packed float pairs at this+0x0 and this+0x8, and share the near-zero squared-length threshold bound to global qword_5AF970 (and the mask qword_5AF950 in 0x00527578). A replacement must preserve the packed-lane layout and the guard semantics that null degenerate/zero-length vectors.
- **MatrixComposeSwitchBehavior** — 0x0052692F selects between one and three optional transform inputs via a null-state bitmask jump table (eight cases) at jpt_526969, composes and normalizes them through sub_525E9A and F_8SIMDMatrixPackedFloatOperation, and applies the composed matrix via F_4DVectorTransform; when the blend-weight pointer is non-null it interpolates the input vector toward the weight instead of transforming directly. A replacement must preserve the eight-case null-state composition semantics and the returned output pointer.
- **Matrix4x4MultiplyRowLayout** — 0x0055EF88 multiplies row-based 4x4 float matrices (four 4-float rows), reading rows of a1 against columns of a2 (a2[0..15]) and writing four rows to a3; the field reads at this+0x0..0xC are attributed to the second matrix's first row (DERIVED). The wrapper 0x0053B000 ignores its first argument and must forward exactly three operands to the primitive.
- **ForceAccumulatorLayout** — 0x0053BB30 reads a three-lane accumulator vector at this+0x17C/0x180/0x184 on the receiver (added only when a1 is non-null) and the transform/offset index ranges 21..23 and 29..31 of the a3 argument, and scales the output by 255.0f. A replacement force/torque contribution must preserve those input layouts, the null-accumulator skip, and the output scaling.
- **DwordArrayOwnershipContract** — 0x0054FDA0 owns a DWORD array at this+0x4C with an element count at this+0x50 and replaces it in place: free the prior buffer (0x00587BCF) when non-null, allocate 4*count bytes (0x00587C03), copy count elements from the source array, and store the new count at this+0x50; returns the copied count (0 when count is zero).

## Unresolved

- Ownership is UNKNOWN for all 14 functions; every class in this proposal is a structural grouping (GUESS), not a recovered class identity, and no owner evidence beyond abi:lead / function refs is present in the packet.
- 0x0052692F: the MMX blend math is only partially readable; the exact meaning of the three constant literals mapped to qword_5AF980/0x005AF988/0x005AF998 is not proven, sub_525E9A's exact transform (matrix vs quaternion) is not established, the relationship between the MMX vector arguments a1/a2 and the packed matrix output is not explicit, and the jump-table case contents at jpt_526969 are not in the packet.
- The read-only global qword_5AF8F0 (0x005AF8F0) is flagged by the fact store for 0x005274BA but absent from the decompiled source, which inlines the constant 1065353216 (1.0f); the global-to-constant mapping is not verifiable here.
- 0x005274BA: the exact geometric meaning of the weight vector a2 lanes is derived from lane shuffles, not documented, and the upper dword of this+0x8 is never written (the caller's use of the residual fourth component is unknown).
- Normalize lane order (x,y)/(z,w) within the packed pairs is not recoverable from any single function; the split is assumed, not confirmed.
- 0x0053BB30: static facts list flt_59E440 (0x0059E440) and flt_59FEC8 (0x0059FEC8) as read globals but neither appears in the raw function text; the 255.0f constant may be an inlined load from one of them. The a3 index semantics (21..23 and 29..31) and the lane-3 stack residue of the constructed __m128 are unproven.
- 0x0053C1C0: EmptyStub_7470 is a decompiler-named stub whose per-entry call purpose (register/construct/teardown) is not evidenced, and the layout of the 42-entry table behind dword_8B78A0 (element type, 19-dword stride) is not described by the packet.
- 0x0053C9C0: SearchPathPrune is called in the raw source but the packet's callee list is empty, so its target address and identity are not confirmed; the purpose of the flag rewrite (clear 0x4000, set 0x400) and the 33-dword element stride layout are unknown, and its connection to the caller VertexBufferResourceAllocation (0x00543FA0) is unexplained.
- 0x0054EEC1: whether the five DWORD slots form an array versus distinct struct fields cannot be established from this function alone.
- 0x0054FDA0: the class owning the this pointer is unknown; the per-element integer data stored during mesh vertex buffer parsing has no established meaning.
- 0x0055EF88: matrix storage layout (row-major vs column-major for a2) and the calling semantic role of the a3 destination are not confirmed beyond the arithmetic; the field reads at this+0x0..0xC are attributed to a2 by DERIVED arithmetic, not by a this pointer in the source.
- 0x00592A62: record layout beyond the key DWORD (the other two DWORDs per 12-byte stride are never touched) and how the record count in dword_5E7894 is maintained are unknown.
- Equal byte offsets on different 'this' bases are not merged: this+0x0 is the packed-single output of the normalize/lerp/2x2-multiply helpers, the first destination slot of the five-dword fill, and the second matrix's first row element of the 4x4 multiply; no common ownership is proven among these bases.
