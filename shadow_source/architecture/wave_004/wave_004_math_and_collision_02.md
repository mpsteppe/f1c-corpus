# MathAndCollision

Scope: `math_and_collision`  
Trust: `DERIVED`

Proposal for the math_and_collision slice of Wave 4. The functions fall into three groups. (1) Rotation/orientation math helpers: float 4x4 rotation-matrix construction (0x53B240 Euler build, 0x53B3B0 identity init), quaternion-to-matrix (0x53B4C0), float 3x3 Y-axis rotation with Euler extraction (0x567400), double 3x3 rotation matrices (0x56BD40 Euler, 0x56BDE0 angle-axis Rodrigues, 0x56C020 in-place Rodrigues compose), the two-pair matrix-vector transform (0x56CF70), and the orientation update utility pair (0x541CD0, 0x541D10). (2) Collision: a ray-triangle ride-height query (0x4EFBD0) built on the same 3-vector math (0x4EC020). (3) Containers/checks: a strided-array search with match callback (0x4CEFE0), an indexed dword read for scoring gates (0x4D7BF0), a bounds-checked 271-dword-slot array getter (0x53D890), an audio-side array accessor (0x5414A0), packed-array total-size and index-resolution (0x54E100, 0x54E120), the video 'CUBE' slot check with flag-word building (0x4F9310), the vehicle-physics joint-system helpers (0x56D430 bandwidth reduction, 0x56D880 zero-fill + joint init, 0x5698E0 buffer append) and a small allocate-and-init buffer descriptor (0x587460). Ownership is UNKNOWN for almost every function, so the class grouping is a DERIVED/GUESS proposal; the strongest layout evidence is the 3x3 double matrix (nine doubles at 0x0..0x40 shared by 0x56BD40/0x56BDE0/0x56C020) and the packed-array count/base pair at 0x118/0x11C shared by 0x54E100/0x54E120.

## Function roles

- `0x004CEFE0` **SearchStridedArrayContainer** — Searches the strided element array (27 dwords / 108 bytes per element, count at this+0x10, base at this+0x14) for the first element whose second dword equals a2; on match calls the element processor (0x004CD8D0) with the element and a3 and returns its result, otherwise returns the examined count (or 0 when the count is not positive).
- `0x004D7BF0` **ScoringGateArray** — Trivial indexed dword read: returns the array element this[a2] from the caller's dword array with no guards, globals or callees; used as an indexed gate/score lookup by the scoring-gate selection path (caller 0x004D1AD0).
- `0x004EC020` **Vector3** — In-place float vector3 accumulation: adds each component of a2 (a2+0/+4/+8) into the corresponding component of this (this+0/+4/+8) and returns the updated destination pointer; called by vehicle contact-force accumulation, wheel-contact transform and the ray-triangle query on the frame path.
- `0x004EFBD0` **RideHeightSurfaceProbe** — Ray-triangle ride-height query: selects a triangle vertex from a per-index vertex array, transforms it into world space via the 3x3 orientation matrix at 0x34B0..0x34D0 and the position offset at 0x34D4..0x34DC, computes two candidate ray-hit distances (plane intersection and helper-based), takes the larger, clamps to 0.025, and returns rest height (0x34AC) minus the clamped delta; returns the unmodified rest height when the intersection is behind the ray or beyond the clamp threshold.
- `0x004F9310` **VideoCubeCheckController** — Video 'CUBE' resource-slot check: builds a configuration flag word from player-display state (byte_5EC4A4), display mode (dword_5EC4B0 switch: 2/3/4/6/16 map to 0x20/0x100/0x40/0x400/0x100000) and an aux byte (byte_5EC4A6 adds 0x80), stores the caller index at dword_8AFE74, runs the array-slot conditional check (0x0055BFF0), and on failure composes a relocated path string and logs 'CUBE error : %s'; returns 1 early when dword_8AFE68 is zero, else 0.
- `0x0053B240` **FloatRotationMatrix44** — Builds a float 4x4 rotation matrix at this+0x28..0x54 from three Euler angles stored at this+0x10/0x14/0x18, computing sin/cos of each angle and the shared products, with an interrupt-dispatch call preceding each angle store; returns 0.
- `0x0053B3B0` **FloatRotationMatrix44** — Constructor-style initializer: zeroes the 16-dword block at this+0x28, writes 1.0f onto the identity diagonal (this+0x28/0x3C/0x50/0x64), sets the scalar at this+0x0 to 1, and returns 1.0f.
- `0x0053B4C0` **QuaternionOrientation** — Converts the stored quaternion (this+0..0xC) into a 3x3 rotation matrix written to the caller's 11-float output array (stride-4 columns, indices 3 and 7 unused); builds double-precision products of doubled components and returns the output array pointer.
- `0x0053D890` **IndexedTextureArray** — Bounds-checked array element getter: returns a pointer to element a2 of the array rooted at element index 3 (271 dwords per element) only when a2 < count at this+0x8, otherwise 0; used by video/texture code paths.
- `0x005414A0` **AudioBufferArrayContainer** — Array element accessor on the container: loads the base pointer at this+0x114C and, when non-null, computes the element address (index at this+0x1148, 36-byte stride) and delegates (this, element) to the arithmetic handler (0x00540F90).
- `0x00541CD0` **OrientationRotationUtility** — Two-step rotation helper: builds a random rotation matrix from three Euler-angle floats via RandomRotationMatrixFromEulerAngles (0x00541DB0, result ignored), then runs the orientation/rotation matrix update (0x00541D10) and returns its result; widely called from camera, car-selection, scene-loader and sound paths.
- `0x00541D10` **OrientationRotationUtility** — Stores the orientation input vector at this+0x24/0x28/0x2C, transforms it through the 3x3 rotation matrix at this+0x15C..0x184 into this+0x18C/0x190/0x194, writes the constant 1.0f at this+0x198, and returns the raw bit pattern (LODWORD) of a4.
- `0x0054E100` **PackedArrayContainer** — Packed-array total size: sums each entry's size field at +8 over the packed array (count at this+0x118, base at this+0x11C, 64-byte entry stride) and returns the total; returns 0 when the element count is not positive.
- `0x0054E120` **PackedArrayContainer** — Packed-array index lookup: walks cumulative entry sizes (64-byte stride, size field at entry+8) to find which entry contains global index a2, then returns a pointer to the sub-element at offset a2 - entryStart within that entry (sub-element stride 48, payload header at entry+12); returns 0 when the count is non-positive or a2 falls outside every entry's cumulative range.
- `0x00567400` **FloatRotationMatrix33** — Right-multiplies the 3x3 row-major float matrix at this+0x0..0x20 by a rotation about the Y axis by angle a2 (touching only the X/Z column pairs), normalizes via FloatConvertWrapper (0x00588570), then extracts Euler angles into the output buffer a3 (yaw at a3, pitch at a3+4, roll at a3+8) with a gimbal-lock singularity branch on fabs(this[5]) == 1.0.
- `0x005698E0` **VehiclePhysicsJointSystem** — Appends a 132-byte constraint entry to the buffer described by this (entry base this[142] + 132 * this[141]++, count post-incremented), writes metadata a5 at +120 and a3 at +124 plus a byte flag a4 at +128, initializes the matrix block via 0x0056C3A0 at entry offsets 24/48, and returns the new entry base pointer.
- `0x0056BD40` **Double33RotationMatrix** — Builds a row-major 3x3 double rotation matrix at this+0x0..0x40 (nine doubles) from the three Euler angles in a2 using the standard sin/cos composition with precomputed combined terms; purely mathematical, returns the input angle pointer.
- `0x0056BDE0` **Double33RotationMatrix** — Converts the angle-axis vector a2 (three doubles) into a 3x3 rotation matrix at this+0x0..0x40 via Rodrigues' formula, applied only when the squared norm of a2 is positive; when the optional output pointer a3 is non-null extracts Euler angles with a gimbal-lock branch (sine-term magnitude == 1.0).
- `0x0056C020` **Double33RotationMatrix** — Right-multiplies the 3x3 double rotation matrix at this+0x0..0x40 by the Rodrigues matrix built from the axis-angle vector a2; normalizes the axis, derives sin/cos and axis-product terms, and composes each matrix row from the prior row entries; does nothing when the axis squared norm is not positive.
- `0x0056CF70` **MatrixVectorTransformPair** — Applies two independent 3x3 matrix-vector products: loads (matrix block, vector buffer) pointer pairs from this+0x4/0x8 and this+0xC/0x10, writes each product into buffer offsets 3..5 (matrix data read from block+28..+68, dot of matrix columns with buffer[0..2]), and returns the second vector buffer pointer.
- `0x0056D430` **VehiclePhysicsJointSystem** — Bandwidth-reduction pass over the sparse constraint system: sums the three per-type counts (this+0x8/0x10/0x18) into a total size, builds an undirected adjacency list over the constraint endpoint ids read from the three entry arrays (48-byte body entries via this+0xC/0x14, 72-byte wheel/joint entries via this+0x1C), allocates two working edge arrays (0x00587C03), initializes identity/class-tag ordering arrays, then iteratively refines the ordering (class-bucket rotation plus adjacent-node swaps, scored by summed squared position deltas) until no improvement, frees the arrays (0x00587BCF) and writes cumulative offsets back at entry +44 (bodies) and +68 (wheel/joints); returns the total node count.
- `0x0056D880` **VehiclePhysicsJointSystem** — Zero-fills arrays of 8-byte elements behind each pointer in the a2 pointer list (a3 pointers, a3 elements of 8 bytes each per pointer), then calls the joint-struct initializer (0x00568FB0) on each vehicle-physics joint struct in the this[1] array (stride 580), passing a2 as the second argument.
- `0x00587460` **ArrayStructAllocatorDescriptor** — Allocate-and-init helper for a small buffer descriptor ({buffer, count, capacity}): zeroes offsets 0x0/0x4/0x8, allocates a2 elements through the checked allocator (0x005874D0) into offset 0x0 when a2 > 0, records the count at 0x4, and returns the receiver.

## Proposed classes

### SearchStridedArrayContainer

Container owning a strided element array (27 dwords / 108 bytes per element) with an element count at this+0x10 and array base at this+0x14. Searches for the first element whose second dword equals a key and invokes the element processor on a match, returning the matched index or the full count.

Methods: `0x004CEFE0`

- `this+0x00000010` `int element_count` (read, DERIVED)
- `this+0x00000014` `pointer array_base` (read, DERIVED)

### ScoringGateArray

Indexed dword array accessor used by the scoring-gate selection path (caller 0x004D1AD0). Returns element a2 of the caller's array; no bounds checks, no side effects. The semantic meaning of the indexed element depends on the unknown owning object.

Methods: `0x004D7BF0`


### Vector3

Three-component float vector with in-place accumulation. F_3DVectorAddition adds each component of the source into the destination and returns the destination pointer; the component order (X/Y/Z) is not proven.

Methods: `0x004EC020`

- `this+0x00000000` `float x` (read_write, DERIVED)
- `this+0x00000004` `float y` (read_write, DERIVED)
- `this+0x00000008` `float z` (read_write, DERIVED)

### RideHeightSurfaceProbe

Surface-geometry probe that answers the ray-triangle ride-height query against an oriented triangle mesh. Uses the 3x3 orientation matrix at 0x34B0..0x34D0 and the position offset at 0x34D4..0x34DC to transform a selected triangle vertex into world space, computes two candidate ray-hit distances, and returns rest_height (0x34AC) minus the delta clamped to 0.025.

Methods: `0x004EFBD0`

- `this+0x000034AC` `float rest_height` (read, DERIVED)
- `this+0x000034B0` `float orientation_row0_col0` (read, DERIVED)
- `this+0x000034B4` `float orientation_row0_col1` (read, DERIVED)
- `this+0x000034B8` `float orientation_row0_col2` (read, DERIVED)
- `this+0x000034BC` `float orientation_row1_col0` (read, DERIVED)
- `this+0x000034C0` `float orientation_row1_col1` (read, DERIVED)
- `this+0x000034C4` `float orientation_row1_col2` (read, DERIVED)
- `this+0x000034C8` `float orientation_row2_col0` (read, DERIVED)
- `this+0x000034CC` `float orientation_row2_col1` (read, DERIVED)
- `this+0x000034D0` `float orientation_row2_col2` (read, DERIVED)
- `this+0x000034D4` `float position_offset_x` (read, DERIVED)
- `this+0x000034D8` `float position_offset_y` (read, DERIVED)
- `this+0x000034DC` `float position_offset_z` (read, DERIVED)

### VideoCubeCheckController

Video 'CUBE' resource-slot check driven by display/mode globals. Builds a flag word from player-display state (byte_5EC4A4), display mode (dword_5EC4B0) and an aux byte (byte_5EC4A6), stores the caller-supplied index at dword_8AFE74, runs the array-slot conditional check (0x0055BFF0), and on failure composes and logs a relocated 'CUBE error' string through the debug-message buffer.

Methods: `0x004F9310`


### FloatRotationMatrix44

Float 4x4 rotation-matrix construction helpers: builds the matrix at this+0x28..0x54 from three Euler angles (0x53B240) and initializes it to identity with a scalar flag (0x53B3B0, diagonal at 0x28/0x3C/0x50/0x64). The two functions share the 4x4 layout at offset 0x28; the shared-owner claim is GUESS.

Methods: `0x0053B240`, `0x0053B3B0`

- `this+0x00000000` `int scalar_flag` (write, GUESS)
- `this+0x00000010` `float angle_x` (write, DERIVED)
- `this+0x00000014` `float angle_y` (write, DERIVED)
- `this+0x00000018` `float angle_z` (write, DERIVED)
- `this+0x00000028` `float m00` (write, DERIVED)
- `this+0x0000002C` `float m01` (write, DERIVED)
- `this+0x00000030` `float m02` (write, DERIVED)
- `this+0x00000034` `float m03` (write, DERIVED)
- `this+0x00000038` `float m10` (write, DERIVED)
- `this+0x0000003C` `float m11` (write, DERIVED)
- `this+0x00000040` `float m12` (write, DERIVED)
- `this+0x00000044` `float m13` (write, DERIVED)
- `this+0x00000048` `float m20` (write, DERIVED)
- `this+0x0000004C` `float m21` (write, DERIVED)
- `this+0x00000050` `float m22` (write, DERIVED)
- `this+0x00000054` `float m23` (write, DERIVED)
- `this+0x00000064` `float identity_extra_diagonal` (write, DERIVED)

### QuaternionOrientation

Quaternion orientation storage (four floats at this+0..0xC). QuaternionToRotationMatrix converts it to a 3x3 rotation matrix written to a caller-supplied 11-float output array with stride-4 column spacing (indices 3 and 7 unused).

Methods: `0x0053B4C0`

- `this+0x00000000` `float w` (read, DERIVED)
- `this+0x00000004` `float x` (read, DERIVED)
- `this+0x00000008` `float y` (read, DERIVED)
- `this+0x0000000C` `float z` (read, DERIVED)

### IndexedTextureArray

Bounds-checked getter for a container's element array rooted at element index 3 with 271 dwords per element and count at offset 0x8. Returns a pointer to element a2 or 0 when a2 >= count. Used by video/texture code paths including VidMan_Enter and D3D texture creation.

Methods: `0x0053D890`

- `this+0x00000008` `int element_count` (read, DERIVED)

### AudioBufferArrayContainer

Container holding a 36-byte-stride element array (base at this+0x114C, index at this+0x1148). ArrayElementAccessor resolves the indexed element address and delegates (this, element) to the arithmetic handler (0x00540F90). Structural twin of the AudioBufferClear function at 0x541470 per cluster-copy prelabel evidence.

Methods: `0x005414A0`

- `this+0x00001148` `int element_index` (read, DERIVED)
- `this+0x0000114C` `pointer array_base` (read, DERIVED)

### OrientationRotationUtility

Orientation/rotation update helpers. OrientationRotationMatrixUpdate (0x541D10) stores an input vector at 0x24/0x28/0x2C, rotates it through the 3x3 matrix at 0x15C..0x184, writes the result at 0x18C/0x190/0x194 and a homogeneous 1.0 at 0x198. RotationMatrixRandomEulerUpdate (0x541CD0) combines a random-Euler matrix build (0x541DB0) with the orientation update. The two functions' this-pointers are not proven identical.

Methods: `0x00541CD0`, `0x00541D10`

- `this+0x00000024` `float orientation_input_x` (write, DERIVED)
- `this+0x00000028` `float orientation_input_y` (write, DERIVED)
- `this+0x0000002C` `float orientation_input_z` (write, DERIVED)
- `this+0x0000015C` `float rot_row0_col0` (read, DERIVED)
- `this+0x00000160` `float rot_row1_col0` (read, DERIVED)
- `this+0x00000164` `float rot_row2_col0` (read, DERIVED)
- `this+0x0000016C` `float rot_row0_col1` (read, DERIVED)
- `this+0x00000170` `float rot_row1_col1` (read, DERIVED)
- `this+0x00000174` `float rot_row2_col1` (read, DERIVED)
- `this+0x0000017C` `float rot_row0_col2` (read, DERIVED)
- `this+0x00000180` `float rot_row1_col2` (read, DERIVED)
- `this+0x00000184` `float rot_row2_col2` (read, DERIVED)
- `this+0x0000018C` `float result_x` (write, DERIVED)
- `this+0x00000190` `float result_y` (write, DERIVED)
- `this+0x00000194` `float result_z` (write, DERIVED)
- `this+0x00000198` `float homogeneous_w` (write, DERIVED)

### PackedArrayContainer

Packed array container with element count at 0x118, base pointer at 0x11C and 64-byte entry stride. PackedArrayTotalSize sums each entry's size field at +8; PackedArrayIndexLookup walks cumulative entry sizes to resolve a global index into a sub-element (48-byte sub-element stride, payload header at entry+12).

Methods: `0x0054E100`, `0x0054E120`

- `this+0x00000118` `int element_count` (read, DERIVED)
- `this+0x0000011C` `pointer array_base` (read, DERIVED)
- `this+0x00000124` `int cursor_offset` (read, GUESS)

### FloatRotationMatrix33

Float 3x3 row-major rotation matrix (elements at 0x0..0x20) supporting in-place Y-axis right-multiplication and Euler extraction. RotationMatrixY rotates the X/Z column pairs by a Y angle, normalizes via FloatConvertWrapper, and writes yaw/pitch/roll to the output buffer, handling the gimbal-lock singularity.

Methods: `0x00567400`

- `this+0x00000000` `float m00` (read_write, DERIVED)
- `this+0x00000004` `float m01` (read_write, GUESS)
- `this+0x00000008` `float m02` (read_write, DERIVED)
- `this+0x0000000C` `float m10` (read_write, DERIVED)
- `this+0x00000010` `float m11` (read, DERIVED)
- `this+0x00000014` `float m12` (read_write, DERIVED)
- `this+0x00000018` `float m20` (read_write, DERIVED)
- `this+0x0000001C` `float m21` (read_write, GUESS)
- `this+0x00000020` `float m22` (read_write, DERIVED)

### VehiclePhysicsJointSystem

Helper cluster of the vehicle-physics joint system (caller VehiclePhysicsJointSystemLoader 0x0056D930). SparseMatrixBandwidthReduce (0x56D430) computes a bandwidth-reducing ordering over the three constraint endpoint arrays and writes cumulative offsets back into the entries; ZeroFillArraysAndCallInitRoutineRepeatedly (0x56D880) zero-fills pointer arrays and initializes the joint structs; BufferEntryAppendWithMatrixInit (0x5698E0) appends 132-byte constraint entries and initializes a matrix block. The three functions operate on distinct sub-objects of the loader context; the distinct field bases below respect that and equal offsets across bases are not merged.

Methods: `0x0056D430`, `0x0056D880`, `0x005698E0`

- `this+0x00000008` `int body_a_count` (read, DERIVED)
- `this+0x0000000C` `pointer body_a_entries` (read, DERIVED)
- `this+0x00000010` `int body_b_count` (read, DERIVED)
- `this+0x00000014` `pointer body_b_entries` (read, DERIVED)
- `this+0x00000018` `int wheel_joint_count` (read, DERIVED)
- `this+0x0000001C` `pointer wheel_joint_entries` (read, DERIVED)
- `this+0x00000000` `int joint_struct_count` (read, DERIVED)
- `this+0x00000004` `pointer joint_struct_array` (read, DERIVED)
- `this+0x00000234` `int entry_count` (read_write, DERIVED)
- `this+0x00000238` `pointer entry_array_base` (read, DERIVED)

### Double33RotationMatrix

Double-precision 3x3 row-major rotation matrix (nine doubles at this+0x0..0x40) with construction from Euler angles (0x56BD40), from an angle-axis vector via Rodrigues' formula (0x56BDE0), and in-place right-multiplication by a Rodrigues rotation (0x56C020). Used on vehicle-physics orientation paths. 0x56BDE0 optionally extracts Euler angles into a caller-supplied output buffer with a gimbal-lock branch.

Methods: `0x0056BD40`, `0x0056BDE0`, `0x0056C020`

- `this+0x00000000` `double m00` (read_write, DERIVED)
- `this+0x00000008` `double m01` (read_write, DERIVED)
- `this+0x00000010` `double m02` (read_write, DERIVED)
- `this+0x00000018` `double m10` (read_write, DERIVED)
- `this+0x00000020` `double m11` (read_write, DERIVED)
- `this+0x00000028` `double m12` (read_write, DERIVED)
- `this+0x00000030` `double m20` (read_write, DERIVED)
- `this+0x00000038` `double m21` (read_write, DERIVED)
- `this+0x00000040` `double m22` (read_write, DERIVED)

### MatrixVectorTransformPair

Applies two independent 3x3 matrix-vector products: each pair loads a matrix block pointer and a vector buffer pointer from the receiver and writes the product into the buffer at offsets 3..5. The pointed-to matrix/vector buffer layouts (block+28 header plus nine doubles) are not evidenced in the packet.

Methods: `0x0056CF70`

- `this+0x00000004` `pointer matrix_block_1` (read, DERIVED)
- `this+0x00000008` `pointer vector_buffer_1` (read, DERIVED)
- `this+0x0000000C` `pointer matrix_block_2` (read, DERIVED)
- `this+0x00000010` `pointer vector_buffer_2` (read_write, DERIVED)

### ArrayStructAllocatorDescriptor

Small buffer descriptor ({buffer, count, capacity}) with allocate-and-init: zeroes the three leading dwords, allocates a2 elements via the checked allocator (0x005874D0) into offset 0x0 when a2 > 0, and records the count at 0x4. The third dword at 0x8 is zeroed but never otherwise touched.

Methods: `0x00587460`

- `this+0x00000000` `pointer buffer` (write, DERIVED)
- `this+0x00000004` `int count` (write, DERIVED)
- `this+0x00000008` `int capacity_reserved` (write, GUESS)

## Compatibility contracts

- **RideHeightClampContract** — The ray-triangle ride-height query (0x004EFBD0) returns rest_height at object+0x34AC when the intersection is behind the ray (negative delta), and rest_height minus the delta clamped to a maximum of 0.025 when within range. A replacement must preserve the 0.025 clamp constant and the negative-delta miss behavior.
- **EulerExtractionOutputLayoutContract** — Euler-extraction helpers write their outputs with fixed layouts: 0x00567400 writes yaw/pitch/roll as floats at a3+0/+4/+8; 0x0056BDE0 writes to a3+0/+8/+16 as doubles with the negated sine term at a3+0. Both apply a gimbal-lock special case when the sine-term magnitude equals 1.0 (roll zeroed / computed from atan2).
- **PackedArrayGeometryContract** — The packed array holds element count at this+0x118 and base pointer at this+0x11C with a 64-byte entry stride; each entry carries a size field at +8, a payload header at +12, and 48-byte sub-elements. Global indices resolve by cumulative entry sizes. Both 0x54E100 and 0x54E120 depend on this geometry.
- **Double33MatrixLayoutContract** — Vehicle-physics orientation code relies on a row-major 3x3 double rotation matrix at offsets 0x0..0x40, written by the Euler-angle builder (0x56BD40), the angle-axis/Rodrigues builder (0x56BDE0) and the in-place Rodrigues compose (0x56C020). A replacement must keep the nine doubles at those offsets.
- **CubeCheckFlagWordContract** — The video CUBE slot check builds a flag word: base 1 or 2 from byte_5EC4A4==0; display mode dword_5EC4B0 adds 0x20 (mode 2), 0x100 (mode 3), 0x40 (mode 4), 0x400 (mode 6), 0x100000 (mode 16); aux byte_5EC4A6 adds 0x80. The array-slot conditional check (0x0055BFF0) with the dword_5D6D60/5D6D64/5D6D68 array globals and the 'CUBE error : %s' log through dword_8AD25C are part of the contract.
- **Matrix44FloatLayoutContract** — Float 4x4 matrix at this+0x28, built from three Euler angles (0x53B240 writes the twelve non-trivial elements at 0x28..0x54 plus zero row-four elements) or initialized to identity (0x53B3B0 writes 1.0f on the diagonal at 0x28/0x3C/0x50/0x64 and a scalar 1 at this+0x0).
- **RotationMatrixYContract** — Y-axis right-multiplication on a 3x3 float row-major matrix (0x00567400) touches only the X/Z column pairs at (0,0/0,2), (1,0/1,2), (2,0/2,2); the Y column is unchanged, then FloatConvertWrapper normalizes the matrix before Euler extraction.
- **QuaternionToMatrixOutputContract** — QuaternionToRotationMatrix (0x53B4C0) reads w/x/y/z at this+0..0xC and writes the 3x3 result into a caller-provided 11-float array with stride-4 columns (indices 3 and 7 unused); callers 0x551210 and 0x551390 consume this layout.

## Unresolved

- Ownership is UNKNOWN for nearly every function in the packet; the class grouping is a DERIVED/GUESS proposal, not a confirmed identity set.
- The physics constants flt_59E440 and flt_59E87C referenced by 0x004EFBD0 are not consumed by its visible raw source; they are likely used inside RideHeightDelta (0x004EF680) or the signed-distance helper (0x004EFEE0).
- The a2 input structure of 0x004EFBD0 is only partially mapped: offsets 20 and 36..56 are read but their field names and the per-index vertex array layout are unknown.
- flt_59E43C (0x0059E43C) is flagged as a read global by packet facts for 0x0053B4C0 but appears nowhere in its raw source.
- dbl_5B8960 (0x005B8960) is a read-only double not consumed by the visible raw source of 0x0053B240; possibly a degree/radian constant.
- dbl_59E428 (0x0059E428) is recorded by deterministic facts as a NaN sentinel referenced by 0x0056BDE0 but is not observable in the raw source.
- dword_8AFE64 is flagged as a read global by packet facts for 0x004F9310 but never appears in its raw decompiled source.
- The strided element types are unknown: 27-dword slots (0x004CEFE0), 271-dword slots (0x0053D890), 36-byte slots (0x005414A0) and 8-byte slots (0x0056D880) have no identified element structures.
- Fields this+0x18..0x68 of 0x0056CF70 are pipeline-derived offsets into the pointed-to matrix/vector buffers; the raw source dereferences only through this[1..4], so the header-plus-nine-doubles mapping is not independently grounded.
- The column-major reading of the 3x3 matrix-vector product in 0x0056CF70 (output component n is the dot of matrix column n) is inferred from the index pattern, not proven.
- The three VehiclePhysicsJointSystem functions operate on distinct sub-objects of the loader context; equal offsets across the different this-bases (e.g. 0x8 in bandwidth_ctx vs the joint init context) are not claimed identical.
- SparseMatrixBandwidthReduce's exact ordering algorithm (Cuthill-McKee-like rotation versus plain swap search) is DERIVED from loop structure; the +4/+12 endpoint-id fields and the +44/+68 write-back slots depend on the constraint entry layout owned by VehiclePhysicsJointSystemLoader, which is not in this packet.
- The InterruptDispatch (0x0058957A) calls in 0x0053B240, once per angle, cannot be distinguished as a caller threading contract or a decompiler artifact.
- Whether the identity-matrix memset block at 0x28..0x64 in 0x0053B3B0 is a row-major 4x4 and whether this+0x0 is a scalar/flag is DERIVED and not proven by the packet.
- The output buffer layout of 0x0053B4C0 skips indices 3 and 7; the unused slots are not written and their meaning is undefined.
- The Euler angle order and intrinsic/extrinsic convention in 0x0056BD40 and 0x0053B240 cannot be established from the packet alone.
- OrientationRotationUtility's two functions (0x541CD0, 0x541D10) are grouped under one class, but their this-pointers are not proven identical; the wide caller set (camera, car selection, scene loading, sound) is noted in packet prose without allowed caller refs.
- Return-value oddities are unexplained: 0x00541D10 returns the raw LODWORD of a4, 0x0053B3B0 returns the 1.0f constant, 0x0056BD40 returns the angle pointer, 0x0056C020 returns nothing on a non-positive axis norm.
- The a2 argument of 0x005698E0 is never referenced in its decompiled body; its intended role (base/index argument) is unknown.
- The exact values of dbl_59E420/dbl_59E430 are not in the packet (existing analysis DERIVEs 1.0 and a zero sentinel); they are constant-folded in the raw source.
- Whether a3 in 0x00587460 is an element count or a byte size, and the element size assumed by OperatorNewWithResultCheck, are external to the function.
