# MathAndCollision

Scope: `math_and_collision`  
Trust: `DERIVED`

Proposes four class boundaries over the 13 validated functions. MatrixMultiplyHelper (DERIVED) groups five 4x4 matrix multiply routines (0x005177B6, 0x00517899, 0x0051EF5E, 0x0052020E, 0x0052050E) that all multiply two 4x4 matrices, return the output pointer a1, and differ only in alias handling (in-place vs stack-temp copy) and SSE vectorization (one variant adds a homogeneous reciprocal and a NULL-on-singular return). VectorBlendHelper (DERIVED) groups the two SSE weighted-vector-sum helpers (0x0051EC40, 0x0051ECA0), which share the same broadcast-weights-and-blend pattern; the normalized variant appends a reciprocal-based homogeneous divide. ArrayFillHelper (DERIVED) groups five primitive fill routines (0x005619F1, 0x00561A15, 0x00561A41, 0x00561A86, 0x00561ACF) that write a constant 16- or 32-bit value into a buffer and return the fill value unchanged; two are called by ClampedPixelSpanFill (0x00553CD0) and sub_553D00 (0x00553D00), and one by sub_553D40 (0x00553D40). FieldBlockCopyHelper (GUESS) holds the single __thiscall method (0x00542400) that copies a 64-byte field block at this+0x15C into a caller destination; its owning class is unknown, and its prose caller RaySphereIntersectionTest has no address evidence. All owners in the packet are UNKNOWN; the classes above are conservative arithmetic-kind groupings, with the unresolved items listing what would be needed to confirm or reject them.

## Function roles

- `0x005177B6` **MatrixMultiplyHelper** — 4x4 matrix multiply with output-alias handling: guards on a3==a1 (second operand aliases output) to take a specialized in-place path, and on a2==a1 to copy a3 to a stack buffer first; general path multiplies rows of a2 by columns of a3 via x87 dot products and returns a1 (the output pointer).
- `0x00517899` **MatrixMultiplyHelper** — 4x4 matrix multiply with output-alias handling: when either input (a2 or a3) aliases the output a1, computes the product into a stack temp buffer and qmemcpy's 64 bytes back into a1; otherwise writes directly. Returns a1. Packet lists no callers; may be a duplicate of 0x005177B6.
- `0x0051EC40` **VectorBlendHelper** — SSE weighted-vector-sum with homogeneous normalization: v3 = a2[0].x * a3[0] + a2[1].x * a3[1] + a3[3], refined reciprocal 1/v3 (rcp plus one refinement step), scale by the refined reciprocal's w-lane, store the low 2 floats of the normalized result to a1 and return a1.
- `0x0051ECA0` **VectorBlendHelper** — SSE weighted-vector-sum: v = a2[0].x * a3[0] + a2[1].x * a3[1] with weights broadcast from the x-lanes of the two a2 dwords; stores the low 2 floats of the result to a1 and returns a1. Blend/interpolation helper with no branches or calls.
- `0x0051EF5E` **MatrixMultiplyHelper** — SSE-vectorized 4x4 matrix multiply: reads the second operand a3 via _mm_loadh_ps at half-vector offsets (a3+1, a3+3, a3+5, a3+7), broadcasts rows of the first operand a2 with _mm_shuffle_ps and multiply-accumulates into row sums, recombines with _mm_unpacklo_ps/_mm_unpackhi_ps, and stores the 4x4 result as sixteen doubles into a1; returns a1.
- `0x0052020E` **MatrixMultiplyHelper** — SIMD 4x4 matrix multiply: left matrix a2 (16 dwords read as four rows of four) multiplied component-wise against four column vectors loaded from a3 via _mm_loadh_ps at a3+1/3/5/7, each row summed into a result vector stored into a1 (eight _mm_storel_ps/_mm_storeh_ps pairs); returns a1.
- `0x0052050E` **MatrixMultiplyHelper** — SSE 4x4 matrix multiply with homogeneous term: computes the product rows, reduces one row product to a scalar homogeneous term v35 (sum of all four lanes of v13*v30), returns NULL when v35 == 0.0, optionally writes v35's bit pattern into *a2 when a2 is non-null, computes a refined reciprocal 1/v35 (estimate plus one Newton-Raphson step), scales the four product rows by it, and stores them into a1 (a float[16] destination); returns a1 on success. No external calls: every intrinsic compiles to an SSE instruction.
- `0x00542400` **FieldBlockCopyHelper** — __thiscall snapshot-copy helper: when the destination a2 is non-null, copies a 64-byte field block read from this+348 (0x15C) into a2 via qmemcpy; void return. The prose caller RaySphereIntersectionTest consumes the copy as a snapshot buffer for a pick test. The this-based block at 0x15C is recorded in prose only; the packet carries no field evidence ref for it.
- `0x005619F1` **ArrayFillHelper** — 16-bit word fill: fills a2 consecutive words starting at byte offset (a4 + 2*a1) with the value a3 and returns a3 unchanged; a1 is a word-index offset. Called by ClampedPixelSpanFill (0x00553CD0).
- `0x00561A15` **ArrayFillHelper** — Strided 16-bit fill: fills a2 words starting at byte offset (a5 + 2*a1) with a3, advancing the write pointer by 2*a4 bytes (a4 words) after each element via a do-while loop (one element written even when a2 is zero); returns a3. Called by sub_553D00 (0x00553D00).
- `0x00561A41` **ArrayFillHelper** — 32-bit value fill over a 2D region using a Bresenham-style error accumulator: stores the fixed 32-bit value a7 into consecutive dwords, advancing to the next row (by a dword row stride) whenever the error term crosses zero; returns a7. No calls or globals; the 32-bit counterpart of the 16-bit fill routines.
- `0x00561A86` **ArrayFillHelper** — Strided dword fill: writes constant a7 and advances per-iteration by a base byte stride (4*a8) plus a conditional extra stride (4*a5) driven by the error-accumulator sign (a1 < 0 adds a3, else adds a4 and extra stride); nine __cdecl arguments, returns a7.
- `0x00561ACF` **ArrayFillHelper** — Dword-array fill: computes the destination as 4*a1 + a4, calls memset32(dest, a3, a2) to fill a2 dwords, and returns a3 unchanged. Called by sub_553D40 (0x00553D40).

## Proposed classes

### MatrixMultiplyHelper

Low-level 4x4 matrix multiplication primitives. Five variants multiply two 4x4 matrices and return the destination pointer a1: 0x005177B6 (x87, in-place alias handling), 0x00517899 (x87, stack-temp alias handling), 0x0051EF5E and 0x0052020E (SSE-vectorized, sixteen-double / sixteen-float output), and 0x0052050E (SSE with a homogeneous scalar term, reciprocal normalization and a NULL result for a zero term). Grouping rests on the shared 4x4-matrix-multiply semantics, the shared return-output-pointer convention, and the canonical ABI-lead names; no shared object or field layout is evidenced.

Methods: `0x005177B6`, `0x00517899`, `0x0051EF5E`, `0x0052020E`, `0x0052050E`


### VectorBlendHelper

SSE weighted-vector-sum / blend helpers. Both build a weighted sum of two scaled vectors whose scalar weights are broadcast from the x-lanes of the a2 dwords and store the low 2 floats of the result to a1: 0x0051ECA0 is the plain two-term blend, and 0x0051EC40 adds an a3[3] additive term plus a reciprocal-based homogeneous divide that normalizes the w-component to approximately 1. Grouping rests on the shared broadcast-weight blend pattern and the shared store-low-2-floats-and-return-a1 convention.

Methods: `0x0051EC40`, `0x0051ECA0`


### ArrayFillHelper

Primitive array fill routines that write a constant 16- or 32-bit value into a buffer and return the fill value unchanged: consecutive-word fill (0x005619F1), word-stride fill (0x00561A15), Bresenham-style 2D dword fill with a row-error accumulator (0x00561A41), strided dword fill with base plus conditional extra stride (0x00561A86), and a memset32 wrapper over a dword array at a computed offset (0x00561ACF). Grouping rests on the shared fill-a-constant-and-return-it pattern and the Bresenham error-accumulator family; callers 0x00553CD0, 0x00553D00 and 0x00553D40 drive the specific buffer layouts.

Methods: `0x005619F1`, `0x00561A15`, `0x00561A41`, `0x00561A86`, `0x00561ACF`


### FieldBlockCopyHelper

Snapshot-copy method on an unidentified object: 0x00542400 copies the 64-byte field block at this+348 (0x15C) into a caller-provided destination when non-null. The packet prose names its caller RaySphereIntersectionTest but gives no address, and the packet supplies no field evidence ref, so the owning class, the field identity, and the semantics of the copied block are unresolved; no class field is asserted.

Methods: `0x00542400`


## Compatibility contracts

- **MatrixMultiplyReturnsOutputPointer** — All 4x4 matrix multiply variants must return the destination pointer a1 in eax (or NULL for 0x0052050E when its homogeneous term is zero); callers that chain the return value depend on this convention.
- **InPlaceAliasSafeMatrixProduct** — A 4x4 multiply invoked with either input matrix aliasing the output buffer must still produce the correct product; the implementations guarantee this either through a specialized in-place path (0x005177B6) or by computing into a stack temp buffer and copying back (0x00517899).
- **SingularResultNullSignal** — SSEMatrix4x4Multiply (0x0052050E) must return NULL when its homogeneous scalar term v35 is 0.0; callers must treat a NULL return as a singular result distinct from a valid destination pointer, and when a2 is non-null the function writes the v35 bit pattern into *a2.
- **FillRoutinesReturnFillValue** — The array fill helpers (0x005619F1, 0x00561A15, 0x00561A41, 0x00561A86, 0x00561ACF) must return the fill value unchanged; callers may use the return as the stored value without re-reading the buffer.
- **SnapshotCopyGuardOnNullDestination** — StructFieldArrayCopy (0x00542400) must copy the 64-byte block at this+0x15C only when the destination is non-null; a null destination must leave the source state untouched.

## Unresolved

- Owner identity is UNKNOWN for all 13 functions in the packet; the classes MatrixMultiplyHelper, VectorBlendHelper, ArrayFillHelper are DERIVED arithmetic-kind groupings and FieldBlockCopyHelper is a GUESS container, none of which are proven C++ types.
- Row-major vs column-major and float vs double element layout of the 4x4 matrices is unresolved: a3 is read at 32-bit granularity via _mm_loadh_ps at half-vector offsets while the outputs of 0x0051EF5E and 0x0052020E are stored as doubles, so the caller-side element packing is ambiguous.
- Operand order (a2*a3 vs a3*a2) for 0x0051EF5E, 0x0052020E and 0x0052050E is not proven; 0x0052050E loads only one explicit matrix operand (a3), so its exact multiplication operands are unresolved.
- Whether 0x00517899 is a distinct function or a compiler-generated duplicate of 0x005177B6 is unknown; the packet lists no callers for it.
- Semantic meaning of the homogeneous term v35 and the *a2 bit-pattern output in 0x0052050E (candidate determinant or perspective w) is not derivable from this function alone; the purpose of shuffle masks 136/221/177/78 is inferred as a standard SSE transpose, not stated.
- The owning class of 0x00542400 and the meaning/layout of its 64-byte field block at this+0x15C are unknown; the packet names the caller RaySphereIntersectionTest in prose only and gives no address evidence.
- memset32 called by 0x00561ACF has no address or identity evidence; the exact callee is unresolved.
- The Bresenham-style error-accumulator fills (0x00561A41, 0x00561A86) have undocumented stride semantics: whether the a5/a8 strides are pixel/row offsets or generic array strides, and the roles of a3 vs a4 as the two error-accumulator increments, are inferred only.
- The purpose of the a3[3] additive term in 0x0051EC40 (position offset vs bias) and why only the low 2 floats are stored (discarded z/w lanes) are not established.
- Whether the two vectors a3[0]/a3[1] in 0x0051ECA0 are basis/edge vectors or segment endpoints depends on the caller and is unresolved.
- The specialized in-place path of 0x005177B6 (a3==a1, a2!=a1) reads column elements of a3 from the output buffer while writing rows in place; its arithmetic is assumed equivalent to the general path but not proven.
