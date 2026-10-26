# MathAndCollision

Scope: `math_and_collision`  
Trust: `DERIVED`

The math_and_collision scope contains three groups. (1) CollisionPrimitives: stateless math helpers - a ray-sphere quadratic intersection test feeding the vehicle suspension force calculation (0x00401180), a 2D direction projection (0x00423AD0) used in AI/opponent proximity, and an SSE two-point linear interpolation (0x0051F6A0). (2) CollisionModel: a collision-geometry container owning a 316-byte-stride strut array (+0x134, count +0x130), a 28-byte-stride struct array (+0x154) and further buffers (+0x150/+0x158); it supports nearest-neighbor queries over linked nodes and struts (0x00403640), indexed struct copies (0x00403F70), and a destructor-style teardown (0x004045F0) freeing every owned allocation. (3) SparseConstraintSolver: two standalone block LDL^T factorization and substitution-solve kernels (0x0056FA96, 0x00575BBD) operating on global double constraint-matrix workspaces and row-pointer tables, returning 0. All owners are UNKNOWN at the function-IR level; the classes above are DERIVED/GUESS proposals.

## Function roles

- `0x00401180` **CollisionPrimitives** — Ray-sphere quadratic intersection test on six double inputs; returns 1/sqrt(p) penetration-length proxy or 0.0 on any miss; used by the vehicle suspension force calculation
- `0x00403640` **CollisionModel** — Nearest-neighbor spatial query over linked collision nodes (next at +0x110/+0x10C) and the 316-byte-stride strut array (this+0x134, count this+0x130), gated by a signed plane-distance probe; returns closest qualifying node or plane-verified candidate
- `0x00403F70` **CollisionModel** — Read getter: copies two 12-byte (3-dword) blocks out of element a2 of the 28-byte-stride struct array at this+0x154 into a3/a4 and returns a4; called from AI-driver and proximity paths
- `0x004045F0` **CollisionModel** — Destructor-style teardown: frees the three owned buffers (+0x150/+0x154/+0x158), nulls them and writes -1.0f at +0x148, walks the 316-byte-stride element array (+0x134, count from length prefix at base-4) calling per-element release, frees the array allocation, resets +0x130/+0x134/+0x138, returns prior array base; called from Game_Post
- `0x00423AD0` **CollisionPrimitives** — 2D scalar projection of vector a2 onto vector a1 (components x at +0x0, z at +0x8): dot(a1,a2)/dot(a1,a1), returning 0.0 for a zero-length a1; AI/opponent proximity context
- `0x0051F6A0` **CollisionPrimitives** — SSE two-point linear interpolation helper: a1 = a2 + (a3-a2)*a5 + (a4-a2)*a6 on packed two-point vectors (high halves only), storing result into a1 and returning a1
- `0x0056FA96` **SparseConstraintSolver** — Block LDL^T factorization of a sparse dynamics constraint matrix plus substitution solve, carried out entirely on global double workspaces (factor blocks 0x008CFBF0-0x008CFC28 area, diagonals/accumulators 0x008D3A28-0x008D3B60, row blocks via pointer tables 0x008D3988-0x008D3A24); no callees, returns 0
- `0x00575BBD` **SparseConstraintSolver** — Block-structured LDL^T factorization (symmetric-indefinite Cholesky variant) of a global double constraint matrix 0x008D2120..0x008D3978 driven by row-pointer array 0x008D3B68..0x008D3BF0; reciprocal-diagonal pivots, L-column scaling, Schur rank-1 updates, RHS forward elimination and back-substitution writing the final solve entry to 0x008D3870; no parameters, returns 0

## Proposed classes

### CollisionPrimitives

Stateless geometric/vector math primitives: ray-sphere quadratic intersection (suspension contact), 2D direction projection, and SSE two-point linear interpolation. No instance fields, no callees; grouped by shape only (owner identity not proven by the packet).

Methods: `0x00401180`, `0x00423AD0`, `0x0051F6A0`

- `this+0x00000000` `float32 x` (read, GUESS)
- `this+0x00000008` `float32 z` (read, GUESS)

### CollisionModel

Container object owning the collision geometry arrays: a 316-byte-stride element (strut) array at +0x134 with count at +0x130, a 28-byte-stride struct array at +0x154, and further owned buffers at +0x150/+0x158. Supports nearest-neighbor queries over linked nodes and struts, indexed struct reads, and a destructor-style teardown freeing every owned allocation. Name is descriptive; packet reports owner UNKNOWN.

Methods: `0x00403640`, `0x00403F70`, `0x004045F0`

- `this+0x00000130` `int32 strut_count` (read_write, DERIVED)
- `this+0x00000134` `pointer strut_array_base` (read_write, DERIVED)
- `this+0x00000138` `int32 array_reset_state` (write, GUESS)
- `this+0x00000148` `float32 released_sentinel` (write, GUESS)
- `this+0x00000150` `pointer owned_buffer_1` (read_write, GUESS)
- `this+0x00000154` `pointer struct_array_base` (read_write, GUESS)
- `this+0x00000158` `pointer owned_buffer_3` (read_write, GUESS)

### SparseConstraintSolver

Standalone numeric kernel: block LDL^T factorization and substitution solve of sparse dynamics constraint matrices stored in global double workspaces (0x008CFBF0..0x008D3B60 and 0x008D2120..0x008D3978) indexed by global row-pointer arrays. No parameters, no callees, returns 0. Two independent functions grouped by shared algorithm and overlapping global workspace region.

Methods: `0x0056FA96`, `0x00575BBD`


## Compatibility contracts

- **SuspensionRaySphereContact** — Ray-sphere quadratic intersection used by the vehicle suspension force calculation: takes six doubles, returns 0.0 on any miss and 1/sqrt(p) as a penetration-length proxy on hit. Must remain a pure scalar float-returning function with no side effects or callees.
- **CollisionModelOwnedBufferLayout** — The collision container owns pointer buffers at +0x150/+0x154/+0x158 and a 316-byte-stride element array at +0x134 (count +0x130) whose allocation is length-prefixed 4 bytes before the base. Teardown frees each non-null buffer via FreeWrapper_7bcf, runs per-element release (0x004B0170) over the element array, frees the array allocation, nulls the pointers, writes -1.0f at +0x148, clears +0x130/+0x134/+0x138, and returns the prior array base.
- **NearestNeighborQueryResult** — Nearest-neighbor query walks linked collision nodes (next pointers at +0x110/+0x10C) and the strut array (316-byte stride, entries with type field at +0x12C <= 1 distance-tested), using a signed plane-distance probe (0x004FB6D0). Returns a node pointer, preferring the plane-verified candidate when its final signed distance is non-negative.
- **SparseConstraintSolverWorkspace** — Two standalone LDLT solvers factor global double constraint-matrix workspaces (0x008CFBF0..0x008D3B60 and 0x008D2120..0x008D3978) indexed by global row-pointer arrays (0x008D3988..0x008D3A24 and 0x008D3B68..0x008D3BF0); both take no parameters and return 0. A replacement must keep these global buffers and pointer tables byte-compatible.

## Unresolved

- CollisionPrimitives grouping is by shape only (stateless math helpers): the packet assigns each function an UNKNOWN owner and proves no shared class; function 0x00401180 is used by the suspension path while 0x00423AD0 is used by an AI/opponent proximity path and 0x0051F6A0 has no callers.
- CollisionModel name is descriptive; the packet reports owner identity UNKNOWN. Field +0x138 is only observed being reset to 0 in teardown; its live role is unknown.
- CollisionModel node-link offsets +0x110/+0x10C and strut-entry type selector +0x12C are documented in prose (see 0x00403640 unresolved) but not modeled as class fields: the packet provides no allowed evidence ref of the form field:<base>:<offset> for them, so no field entry can satisfy the evidence-ref contract without inventing a ref.
- 0x00401180: roles of the six double inputs (a1..a6) are inferred from call context only; three read-only double globals (dbl_59E420, dbl_59E428, dbl_59E430) flagged by packet facts do not appear in the raw source (possibly compiler-intrinsic support constants).
- 0x00403640: meaning of read-only globals flt_59E440, flt_59E468, flt_59E46C not visible in raw source; the 4x-weighted Z component in the squared-distance score is unexplained; semantics of node link offsets +0x110/+0x10C unknown; type selector at entry+0x12C enum values beyond <= 1 unknown.
- 0x00403F70: element size is 28 bytes but only 24 bytes are copied (remaining 4 bytes unread); array base this+0x154 is read-only here and the meaning of the two output blocks is not established; the DERIVED prelabel 'getter' is too weak (raw source outranks it).
- 0x004045F0: EmptyStub_0170 per-element behavior (release vs no-op) is outside the packet; the 316-byte element struct is undefined; the DERIVED prelabel 'ctor_init' is wrong (this is teardown).
- 0x0051F6A0: a5/a6 passed as unsigned ints and reinterpreted as floats via shuffle (type not determinable); only high halves of each double are used; no caller/callee evidence for what the two-point vectors encode.
- 0x0056FA96: exact role of workspace diagonals 0x008D3A28..0x008D3B60 (RHS vector, D-factor, or solve accumulator) not decidable; whether the final tail is strictly backward substitution or an interleaved block-triangular solve is ambiguous; pointer tables 0x008D3988..0x008D3A24 point at runtime row bases not present in the packet; return 0 contract unconfirmed (no static callers).
- 0x00575BBD: pointer array 0x008D3B68..0x008D3BF0 holds runtime row bases outside this function; numeric immediates are absolute addresses encoded as 32-bit constants (equivalence to named globals is by address match only); block sizes DERIVED from loop bounds, not confirmed; LDL^T vs Cholesky interpretation DERIVED from the reciprocal-diagonal + rank-1-update pattern; exact forward/backward solve split not confirmed.
- The two solver functions share overlapping global workspace regions (0x008D3A28..0x008D3B60 is touched by both) but operate on disjoint matrix buffers; whether they are two phases of one solver, two solver instances, or two independent kernels is not provable from the packet.
