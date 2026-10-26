# MathAndCollision

Scope: `math_and_collision`  
Trust: `DERIVED`

22 functions in three coherent clusters plus a tail of address-clustered utilities. Cluster A: 3DNow! packed-float matrix math (0x00522B5B 3x3 inverse, 0x00523E7A quaternion-to-matrix, 0x005257C0/0x00525E9A determinant-guarded 4x4 inversions, 0x00525AA2 4x4 multiply) written against eight __m64 quads at 0x0..0x38 with homogeneous last row {0,1.0}, sharing packed constants 0x005AF8F0/0x005AF900/0x005AF920/0x005AF990. Cluster B: scene culling (0x00549FB0 sphere-vs-frustum test writing status bits in this+0x4; 0x0054A340 spatial-tree nearest-object query with the shared bounding-sphere layout center +0x7C/0x80/0x84, radius +0x18). Cluster C: vehicle physics constraint math (VehicleConstraintSolver 0x0056A5D0 velocity processing and 0x0056B5D0 sparse stiffness-matrix assembly; 0x00569B70 impulse/momentum subtraction; rotation/Euler helpers 0x005670D0, 0x005674C0, 0x0056C2D0). The remaining eight functions (0x00550820, 0x00563DC0, 0x00563E80, 0x00564AB0, 0x0058DFC1, 0x0058FF0D, 0x0059525D, 0x00595310) are generic utilities; 0x00528F00 has an empty body.

## Function roles

- `0x00522B5B` **UnknownObject** — 3DNow! inverse of the 3x3 rotation submatrix into eight __m64 output quads; homogeneous last row {0,1.0}; whether the result is a true inverse or an adjugate is unresolved
- `0x00523E7A` **UnknownObject** — Multiply two packed-float quaternions (scaled by 0.5) and convert the product to a 4x4 rotation matrix via cofactor/adjugate pattern
- `0x005257C0` **UnknownObject** — Determinant-guarded 4x4 matrix inversion via 3DNow cofactors; optional determinant int output through a2; singular path skips the store and returns nonzero
- `0x00525AA2` **UnknownObject** — 3DNow! 4x4 matrix multiply with a specialized in-place (a2 == a1) path
- `0x00525E9A` **UnknownObject** — 3DNow! 4x4 inverse operator; accumulates a scalar (exposed through a2 when non-null), returns 0 on the invertible path and -1 when the scalar is zero (output untouched)
- `0x00528F00` **UnknownObject** — Empty-body stub in the SIMD vector-normalization path; the nine referenced read-only globals near 0x005D9358 are not exercised by any visible code
- `0x00549FB0` **FrustumCullableObject** — Sphere-vs-frustum visibility test: force-hidden mask short-circuit, sphere-distance prune, six-plane loop, visibility status written into low bits of this+0x4
- `0x0054A340` **SpatialTreeQuery** — Nearest-object query against a bounding-sphere spatial tree with 6-plane frustum acceptance; fallback linear walk of an inline linked list when the tree root is absent; cached result at this+0x1A4
- `0x00550820` **UnknownObject** — Counted-array destructor: backward-destroys 8-byte-stride elements via 0x00550810 then frees the allocation including the count prefix via FreeWrapper_7bcf
- `0x00563DC0` **NetworkSocketContainer** — Close every socket in a network socket array (28-byte stride, handle at entry offset 0, count at this+0x6C)
- `0x00563E80` **UnknownObject** — Bounds-checked array element read: validates index against count query 0x00563E70 and resolves the element via LinearInterpolation 0x005648B0; 0 on out-of-range
- `0x00564AB0` **UnknownObject** — Callback-driven linear scan over up to a3 elements with stride a4; returns first element for which callback a5 returns zero, else 0
- `0x005670D0` **Matrix3x3Util** — Fill a 3x3 rotation matrix (float, 4-byte stride) from two Euler-angle arguments; middle entry forced to zero
- `0x005674C0` **EulerAngleMatrixRotation** — Rotate the first two columns of a 3x3 matrix by an angle and extract Euler angles (pitch, yaw, roll) with a gimbal-lock branch on fabs(center element) == 1.0
- `0x00569B70` **RigidBodyImpulseState** — Subtract an impulse vector from linear momentum (this+0x134/0x13C/0x144) and lever-arm cross-product components from angular momentum (this+0x14C/0x154/0x15C); returns the impulse pointer
- `0x0056A5D0` **VehicleConstraintSolver** — Process joint constraint velocity vectors into a body-id-indexed force buffer at this+0x224 (Matrix3x3VectorMultiply, CrossProductNormalize, traction constants 0x005E5238/0x005E5240)
- `0x0056B5D0` **VehicleConstraintSolver** — Assemble the sparse symmetric constraint stiffness matrix from joint (stride 132) and contact (stride 88) entries into the row-pointer table at this+0x228 using world-space inverse inertia at this+0xEC..0x12C
- `0x0056C2D0` **EulerAngleMatrixRotation** — Rotate columns 1 and 2 of a 3x3 double matrix around the X axis and optionally extract Euler angles (gimbal-lock aware) into a3
- `0x0058DFC1` **UnknownObject** — Startup-only straight-line initializer of four Win32 critical-section globals (0x005E6CC4, 0x005E6CB4, 0x005E6CA4, 0x005E6C84) via InitializeCriticalSection
- `0x0058FF0D` **UnknownObject** — Binary search over 8-byte key/value records using comparator 0x00588410; on hit writes the record value field (base+4) into *a3 and returns the comparator result
- `0x0059525D` **UnknownObject** — Clear one bit in a bit array (word a2/32, bit a2%32), invoke failure handler 0x00595207 if the trailing range was not clear, and zero-fill words beyond the target when before the third word
- `0x00595310` **UnknownObject** — Test whether three consecutive dwords are all zero; return 1 only when the counter reaches 3

## Proposed classes

### Matrix3x3Util

3x3 rotation-matrix fill from Euler angles; plain matrix utility with no class-identity evidence beyond its two suspension/wheel callers.

Methods: `0x005670D0`

- `this+0x00000000` `float m00` (write, DERIVED)
- `this+0x00000004` `float m01` (write, DERIVED)
- `this+0x00000008` `float m02` (write, DERIVED)
- `this+0x0000000C` `float m10` (write, DERIVED)
- `this+0x00000010` `float m11` (write, DERIVED)
- `this+0x00000014` `float m12` (write, DERIVED)
- `this+0x00000018` `float m20` (write, DERIVED)
- `this+0x0000001C` `float m21` (write, DERIVED)
- `this+0x00000020` `float m22` (write, DERIVED)

### EulerAngleMatrixRotation

Column-rotation and Euler-angle extraction on 3x3 double matrices, with a gimbal-lock branch comparing the center-column element against the dbl_59E420 constant and FloatConvertWrapper before angle output. Element layout is an 8-byte double matrix; only the offsets evidenced here are claimed.

Methods: `0x005674C0`, `0x0056C2D0`

- `this+0x00000028` `double matrixEntry2` (read, GUESS)
- `this+0x00000030` `double matrixEntry6` (read, GUESS)
- `this+0x00000038` `double matrixEntry7` (read_write, GUESS)
- `this+0x00000040` `double matrixEntry8` (read_write, GUESS)

### VehicleConstraintSolver

Vehicle physics constraint solver. Processes joint constraint velocity vectors into a body-id-indexed force buffer and assembles the sparse symmetric constraint stiffness matrix from joint/contact entries using the world-space inverse inertia tensor.

Methods: `0x0056A5D0`, `0x0056B5D0`

- `this+0x0000007C` `double angularVelocityX` (read, GUESS)
- `this+0x00000084` `double angularVelocityY` (read, GUESS)
- `this+0x0000008C` `double angularVelocityZ` (read, GUESS)
- `this+0x000000EC` `double invInertia00` (read, DERIVED)
- `this+0x000000F4` `double invInertia01` (read, DERIVED)
- `this+0x000000FC` `double invInertia02` (read, DERIVED)
- `this+0x0000010C` `double invInertia10` (read, DERIVED)
- `this+0x00000114` `double invInertia11` (read, DERIVED)
- `this+0x0000011C` `double invInertia12` (read, DERIVED)
- `this+0x00000124` `double invInertia20` (read, DERIVED)
- `this+0x0000012C` `double invInertia21` (read, DERIVED)
- `this+0x00000224` `double* forceBuffer` (read_write, GUESS)
- `this+0x00000228` `void** sparseRowTable` (read_write, GUESS)
- `this+0x00000234` `int jointCount` (read, DERIVED)
- `this+0x00000238` `void* jointBuffer` (read, DERIVED)
- `this+0x0000023C` `int contactCount` (read, DERIVED)
- `this+0x00000240` `void* contactBuffer` (read, DERIVED)

### RigidBodyImpulseState

Rigid-body linear and angular momentum state modified by impulse subtraction with lever-arm cross-product terms. Field semantics (momentum) are DERIVED from the arithmetic shape and the subtraction twin pattern; the owner is otherwise unknown.

Methods: `0x00569B70`

- `this+0x00000134` `double linearMomentumX` (read_write, GUESS)
- `this+0x0000013C` `double linearMomentumY` (read_write, GUESS)
- `this+0x00000144` `double linearMomentumZ` (read_write, GUESS)
- `this+0x0000014C` `double angularMomentumX` (read_write, GUESS)
- `this+0x00000154` `double angularMomentumY` (read_write, GUESS)
- `this+0x0000015C` `double angularMomentumZ` (read_write, GUESS)

### FrustumCullableObject

Scene object carrying a bounding sphere and visibility status bits, tested against a caller-supplied 6-plane view frustum. Plane data lives in the caller's frustum argument, not on this object.

Methods: `0x00549FB0`

- `this+0x00000004` `unsigned int visibilityFlags` (read_write, GUESS)
- `this+0x00000018` `float boundingRadius` (read, GUESS)
- `this+0x0000007C` `float sphereCenterX` (read, GUESS)
- `this+0x00000080` `float sphereCenterY` (read, GUESS)
- `this+0x00000084` `float sphereCenterZ` (read, GUESS)

### SpatialTreeQuery

Spatial query container that finds the nearest object to a negated query point passing a 6-plane frustum test, walking either a bounding-sphere spatial tree rooted at this+0x2A0 or, when absent, a fallback inline linked list headed at this+0x100; best result cached at this+0x1A4. Inline list nodes and tree children share a bounding-sphere layout (radius +0x18, center +0x7C/0x80/0x84, plane data +0x8C/0x90/0x94).

Methods: `0x0054A340`

- `this+0x00000100` `void* fallbackListHead` (read, GUESS)
- `this+0x00000104` `unsigned int fallbackListEntry` (read, GUESS)
- `this+0x00000118` `float inlineNodeRadius` (read, GUESS)
- `this+0x0000017C` `float inlineNodeCenterX` (read, GUESS)
- `this+0x00000180` `float inlineNodeCenterY` (read, GUESS)
- `this+0x00000184` `float inlineNodeCenterZ` (read, GUESS)
- `this+0x0000018C` `double inlineNodePlaneX` (read, GUESS)
- `this+0x00000190` `double inlineNodePlaneY` (read, GUESS)
- `this+0x00000194` `double inlineNodePlaneZ` (read, GUESS)
- `this+0x000001A4` `void* cachedBestResult` (read_write, GUESS)
- `this+0x000002A0` `void* treeRoot` (read, GUESS)
- `*(this+0x2A0)+0x00000010` `void* treeChildListHead` (read, GUESS)
- `*(*(this+0x2A0)+0x10)+0x0000007C` `float treeChildCenterX` (read, GUESS)
- `*(*(this+0x2A0)+0x10)+0x00000080` `float treeChildCenterY` (read, GUESS)
- `*(*(this+0x2A0)+0x10)+0x00000084` `float treeChildCenterZ` (read, GUESS)
- `*(*(this+0x2A0)+0x10)+0x0000008C` `double treeChildPlaneX` (read, GUESS)
- `*(*(this+0x2A0)+0x10)+0x00000090` `double treeChildPlaneY` (read, GUESS)
- `*(*(this+0x2A0)+0x10)+0x00000094` `double treeChildPlaneZ` (read, GUESS)
- `*(*(this+0x2A0)+0x14)+0x00000014` `void* treeNodeNextSibling` (read, GUESS)
- `*(this+0x204)+0x00000104` `void* inlineNodeNextPtr` (read, GUESS)

### NetworkSocketContainer

Container for a network socket array (base this+0x8, count this+0x6C, 28-byte entries with the handle at entry offset 0) whose teardown closes every socket.

Methods: `0x00563DC0`

- `this+0x00000008` `void* socketArray` (read, GUESS)
- `this+0x0000006C` `int socketCount` (read, GUESS)

## Compatibility contracts

- **MatrixEightPackedQuadLayout** — 3DNow matrix routines read and write a 4x4 matrix as eight 64-bit packed-float quads at byte offsets 0x0..0x38, with slot 6 zeroed and slot 7 holding the homogeneous row {0, 1.0}. A replacement must preserve this eight-quad layout for both the SIMDMatrixMath set and any consumer of the produced inverse/multiply output.
- **SingularMatrixInverseReturnContract** — The 4x4 inversions (0x005257C0, 0x00525E9A) skip writing the output matrix when the accumulated determinant/scalar is zero, return 0 on the invertible path and a nonzero value (0x00525E9A returns -1) on the singular path, and write the determinant/scalar into the optional out-pointer a2 only when a2 is non-null.
- **BoundingSphereLayout** — Culling and spatial-query objects share a bounding-sphere layout: radius at +0x18, sphere center at +0x7C/+0x80/+0x84, and 6-plane frustum coefficients at +0x8C/+0x90/+0x94. The shared offsets across the culling test, the spatial-tree children and the inline list nodes are the observable contract a spatial rewrite must preserve.
- **FrustumVisibilityStatusBits** — Sphere-vs-frustum visibility is recorded in the low status bits of the flags dword at this+0x4 (force-hidden mask 0x50 short-circuits to culled; bit semantics for visible/culled/partial/sphere-culled are inferred from branch structure, not independently confirmed). Callers of 0x00549FB0 must observe the same bit contract.
- **ConstraintMatrixRowPointerIndexing** — The constraint solver indexes the sparse symmetric stiffness matrix by body id through the row-pointer table at this+0x228, accumulating inverse-inertia-weighted 3x3 blocks for joint (stride 132) and contact (stride 88) entries with add/subtract selected by the sign byte. A replacement solver must reproduce this body-id row-pointer indexing and block accumulation.

## Unresolved

- The packet mixes genuine math-and-collision work with eight address-clustered generic utilities (counted-array destructor 0x00550820, socket teardown 0x00563DC0, array read 0x00563E80, array scan 0x00564AB0, critical-section init 0x0058DFC1, binary search 0x0058FF0D, bit-clear 0x0059525D, zero check 0x00595310). These are grouped by address proximity, not subsystem affinity; their owner objects are unknown.
- 0x00528F00 has an empty body ('void sub_528F00() { ; }'); the nine read-only globals 0x005D9358..0x005D93B8 it is reported to reference (DERIVED as SIMD math coefficient tables) are not exercised by any visible code and the canonical name F_3DVectorNormalize_8f00 cannot be confirmed.
- 0x00522B5B: whether the 3x3 routine computes a true inverse or an adjugate/cofactor result without a final division is not established; the packed lane layout of the inverse across the eight __m64 slots is inferred from punpck order, not verified against a consumer.
- Read-only qword 0x005AF8F0 is reported by deterministic facts but the decompiled bodies render the constant inline (packed -1.0f/1.0f); the exact global-to-constant mapping is not established.
- 0x0054A340: the read-only global dbl_59E430 is listed as read but does not appear in the raw pseudocode (constant may be folded into the FLT_MAX sentinel 9.9999997e37), and the residual CPU-status-flag guard (c0/c3) gating the cached-result early return cannot be reconstructed into a source-level comparison.
- 0x00549FB0: the frustum argument a2 layout (bounding radius at a2[2], sphere offset at a2[9..11], plane block at a2+65) is caller-defined; the visibility-flag bit semantics beyond the force-hidden 0x50 mask are inferred from the branch structure.
- VehicleConstraintSolver: the exact packing of the 3x3 block within each per-body row block, the force-buffer stride and the two double slots per body, and the add-versus-subtract sign-byte semantics (shared/opposed body frame) are inferred, not proven.
- 0x00523E7A: exact quaternion convention (component order and sign convention of the encoded a2/a3 operands) is not pinned down.
- Ownership is unknown for most functions; only Matrix3x3Util and VehicleConstraintSolver carry a DERIVED owner in the packet, and the GUESS classes EulerAngleMatrixRotation, RigidBodyImpulseState, FrustumCullableObject, SpatialTreeQuery and NetworkSocketContainer are grouping proposals, not recovered class identities.
- Equal byte offsets on different 'this' bases are not merged unless common ownership is proven: e.g. +0x7C/+0x84 are the culling sphere center on FrustumCullableObject but angular-velocity doubles on VehicleConstraintSolver, and +0x104 is the fallback-list entry on SpatialTreeQuery but invInertia[1][0] on VehicleConstraintSolver.
- 0x00569B70: the interpretation of this+0x134..0x15C as linear/angular momentum and of a2 as a lever-arm vector is DERIVED from the arithmetic shape and the structural-twin prelabel, not from packet field names; the mixed cross-product sign convention is unexplained.
- 0x00525E9A: the field R/W classification (0x0 RW, 0x8..0x38 R) recorded by the extractor does not match the unconditional writes to all eight output qwords; the discrepancy is kept as-is.
- The trailing stub call target of 0x00550820 and the 28-byte socket entry tail (bytes 4..27) of 0x00563DC0 are not described by the packet.
