# MathAndCollision

Scope: `math_and_collision`  
Trust: `DERIVED`

Ten validated functions grouped into five proposed classes. Three spatial nearest-neighbor queries (0x004038E0 strut scan, 0x004039C0 BVH chain walk, 0x00403AA0 tree walk) share the node-field concepts (position +148/+152/+156, plane coefficients +164/+172, links +268/+272, identifier +300) and a common fallback path into 0x004038E0. Two pure matrix/vector helpers (0x00435E00 3x3xvector multiply, 0x00566E40 Euler-to-matrix) operate on a 3x3 row-major matrix block. Three compressed short-int vector codecs (0x004B2420, 0x004B2580, 0x004B2800) decode packed int16 records with documented scale factors (1/2048, 0.02, 1/512). One per-frame physics transform setup (0x004F17D0) copies a rotation matrix plus input vector and computes the product into a vehicle-physics frame buffer at base+0x34B0. One zero-init helper (0x004F2B10) clears 16-dword embedded array blocks. All owners are UnknownObject in the packet; every class grouping is a DERIVED proposal, not a confirmed source name.

## Function roles

- `0x004038E0` **SpatialNearestNeighborQuery** — Nearest-strut query over a strut array (count at this+0x130, base this+0x134, stride 316) with strut-type filtering (a3 == -1 or element type at +300) and a plane-side rejection test (+164/+172 coefficients) that selects the linked collision child at +272; returns 0 when the count is 0.
- `0x004039C0` **SpatialNearestNeighborQuery** — Nearest-node traversal over a linked chain of physics nodes walking +272 child links while the accumulated path length (sum of node+60) stays below 200.0 (flt_59E470); descends on strictly smaller squared distance and early-outs otherwise; called by AISteering.
- `0x00403AA0` **SpatialNearestNeighborQuery** — Spatial tree nearest-neighbor search walking +268 sibling and +272 child chains with identifier checks (+300); when no candidate survives or the optional plane test (a5) rejects it, falls back to SpatialNearestNeighborQueryWithPlaneTest (0x004038E0); used by AI racing-line/steering callers.
- `0x00435E00` **MatrixVectorHelpers** — Pure 3x3 matrix (nine doubles, row-major, this+0x0..0x40) by 3-vector multiply writing the product into a3; returns the input vector pointer a2; no branches, globals, or callees; used by physics solvers.
- `0x004B2420` **PackedShortVectorRecord** — Unpack a compact vector record: copy three raw dwords from this+0x0/+0x4/+0x8 into a2, then convert three int16 values at this+0xC/+0xE/+0x10 to floats by 1/2048 (0.00048828125, flt_59E77C) into a3; returns a3; companion to the packing routine sub_4B2310.
- `0x004B2580` **PackedShortVectorRecord** — Unpack three int16 values from this[15..17] (offsets 0x1E/0x20/0x22) into floats scaled by 0.02 (1/50, flt_59E6EC) writing to output float array a2; returns a2; inverse of the short-vector packing routine on the per-frame physics/audio path.
- `0x004B2800` **PackedShortVectorRecord** — thiscall unpack of a compact 2-component int16 vector: zero a2+4 (Y), scale this[20] (offset 0x28) by 1/512 into a2 (X), scale this[21] (offset 0x2A) by 1/512 into a2+8 (Z); returns a2; per-frame decode for VehiclePhysicsTimeStep and AudioParameterInterpolation.
- `0x004F17D0` **PhysicsFrameTransform** — Copy a 3x3 rotation matrix (0x24 bytes) from a2 into this+0x34B0, copy a 3-component vector from a3 into this+0x3534..0x353C, compute the matrix-by-vector product into this+0x3540..0x3548 and return a pointer to the stored matrix (this+0x34B0); called per frame from VehiclePhysicsTimeStep.
- `0x004F2B10` **EmbeddedArrayBlock** — Zero-initialize a 16-dword (0x40-byte) array this[0]..this[15] at offsets 0x0..0x3C and return the this pointer; no reads, globals, or callees; called from PhysicsDefaultsInitializer and TireModelDataInit to zero embedded 16-element arrays.
- `0x00566E40` **MatrixVectorHelpers** — Convert three Euler angles in a1[0..2] into a row-major 3x3 rotation matrix written to a2[0..8]; pure trigonometric computation with no side effects and no callees.

## Proposed classes

### SpatialNearestNeighborQuery

Nearest-neighbor lookups over spatial strut arrays, BVH node chains, and spatial trees used by AI steering / racing-line code. Shared node concepts (position, plane coefficients, links, identifier) appear across all three methods, but common ownership of the query fields is not proven.

Methods: `0x004038E0`, `0x004039C0`, `0x00403AA0`

- `this+0x00000000` `float query_position_x` (read, DERIVED)
- `this+0x00000004` `float query_position_y` (read, DERIVED)
- `this+0x00000008` `float query_position_z` (read, DERIVED)
- `this+0x00000130` `int strut_count` (read, DERIVED)
- `this+0x00000134` `pointer strut_array_base` (read, DERIVED)
- `this+0x000001C8` `unknown field_1C8` (read, GUESS)
- `this+0x000001CC` `unknown field_1CC` (read, GUESS)
- `this+0x000001D0` `unknown field_1D0` (read, GUESS)
- `this+0x000001D8` `unknown field_1D8` (read, GUESS)
- `this+0x000001E0` `unknown field_1E0` (read, GUESS)
- `this+0x00000244` `unknown field_244` (read, GUESS)
- `this+0x00000260` `unknown field_260` (read, GUESS)

### MatrixVectorHelpers

Pure matrix/vector math: 3x3 matrix by vector multiply (doubles) and Euler-angle to rotation-matrix conversion (floats). The shared offsets may hold different element widths; grouping is a DERIVED proposal, not proven common storage.

Methods: `0x00435E00`, `0x00566E40`

- `this+0x00000000` `double (0x00435E00) / float (0x00566E40) matrix_r0c0` (read_write, DERIVED)
- `this+0x00000004` `float matrix_r0c1` (write, DERIVED)
- `this+0x00000008` `double (0x00435E00) / float (0x00566E40) matrix_r0c2` (read_write, DERIVED)
- `this+0x0000000C` `float matrix_r1c0` (write, DERIVED)
- `this+0x00000010` `double (0x00435E00) / float (0x00566E40) matrix_r1c1` (read_write, DERIVED)
- `this+0x00000014` `float matrix_r1c2` (write, DERIVED)
- `this+0x00000018` `double (0x00435E00) / float (0x00566E40) matrix_r2c0` (read_write, DERIVED)
- `this+0x0000001C` `float matrix_r2c1` (write, DERIVED)
- `this+0x00000020` `double (0x00435E00) / float (0x00566E40) matrix_r2c2` (read_write, DERIVED)
- `this+0x00000028` `double matrix_double_5` (read, DERIVED)
- `this+0x00000030` `double matrix_double_6` (read, DERIVED)
- `this+0x00000038` `double matrix_double_7` (read, DERIVED)
- `this+0x00000040` `double matrix_double_8` (read, DERIVED)

### PackedShortVectorRecord

Compressed int16 vector codecs: unpack compact records into floats with documented scales (1/2048, 0.02, 1/512). The three methods read different record layouts; grouping is DERIVED and common ownership of one record struct is unproven.

Methods: `0x004B2420`, `0x004B2580`, `0x004B2800`

- `this+0x00000000` `dword raw_dword_0` (read, DERIVED)
- `this+0x00000004` `dword raw_dword_1` (read, DERIVED)
- `this+0x00000008` `dword raw_dword_2` (read, DERIVED)
- `this+0x0000000C` `int16 short_component_0` (read, DERIVED)
- `this+0x0000000E` `int16 short_component_1` (read, DERIVED)
- `this+0x00000010` `int16 short_component_2` (read, DERIVED)
- `this+0x0000001E` `int16 short_15` (read, DERIVED)
- `this+0x00000020` `int16 short_16` (read, DERIVED)
- `this+0x00000022` `int16 short_17` (read, DERIVED)
- `this+0x00000028` `int16 short_20` (read, DERIVED)
- `this+0x0000002A` `int16 short_21` (read, DERIVED)

### PhysicsFrameTransform

Per-frame vehicle physics transform setup: store a 3x3 rotation matrix, an input vector, and their matrix-by-vector product in a frame buffer at base+0x34B0, returning a pointer to the stored matrix.

Methods: `0x004F17D0`

- `this+0x000034B0` `float rotation_matrix_r0c0` (write, DERIVED)
- `this+0x000034B4` `float rotation_matrix_r0c1` (write, DERIVED)
- `this+0x000034B8` `float rotation_matrix_r0c2` (write, DERIVED)
- `this+0x000034BC` `float rotation_matrix_r1c0` (write, DERIVED)
- `this+0x000034C0` `float rotation_matrix_r1c1` (write, DERIVED)
- `this+0x000034C4` `float rotation_matrix_r1c2` (write, DERIVED)
- `this+0x000034C8` `float rotation_matrix_r2c0` (write, DERIVED)
- `this+0x000034CC` `float rotation_matrix_r2c1` (write, DERIVED)
- `this+0x000034D0` `float rotation_matrix_r2c2` (write, DERIVED)
- `this+0x00003534` `float input_vector_x` (write, DERIVED)
- `this+0x00003538` `float input_vector_y` (write, DERIVED)
- `this+0x0000353C` `float input_vector_z` (write, DERIVED)
- `this+0x00003540` `float output_vector_x` (write, DERIVED)
- `this+0x00003544` `float output_vector_y` (write, DERIVED)
- `this+0x00003548` `float output_vector_z` (write, DERIVED)

### EmbeddedArrayBlock

Zero-initialized 16-dword embedded array block inside larger construction objects (physics defaults, tire model data).

Methods: `0x004F2B10`

- `this+0x00000000` `dword dword_0` (write, DERIVED)
- `this+0x00000004` `dword dword_1` (write, DERIVED)
- `this+0x00000008` `dword dword_2` (write, DERIVED)
- `this+0x0000000C` `dword dword_3` (write, DERIVED)
- `this+0x00000010` `dword dword_4` (write, DERIVED)
- `this+0x00000014` `dword dword_5` (write, DERIVED)
- `this+0x00000018` `dword dword_6` (write, DERIVED)
- `this+0x0000001C` `dword dword_7` (write, DERIVED)
- `this+0x00000020` `dword dword_8` (write, DERIVED)
- `this+0x00000024` `dword dword_9` (write, DERIVED)
- `this+0x00000028` `dword dword_10` (write, DERIVED)
- `this+0x0000002C` `dword dword_11` (write, DERIVED)
- `this+0x00000030` `dword dword_12` (write, DERIVED)
- `this+0x00000034` `dword dword_13` (write, DERIVED)
- `this+0x00000038` `dword dword_14` (write, DERIVED)
- `this+0x0000003C` `dword dword_15` (write, DERIVED)

## Compatibility contracts

- **NearestNeighborQuerySemantics** — Nearest-neighbor lookups must preserve the documented selection rules: zero-count early return (strut count at base+0x130 <= 0), strut-type filter (a3 == -1 or equals element type at +300), plane-side rejection selecting the linked +272 child, and the 200.0 accumulated path-length bound for chain traversal.
- **ShortVectorPackingScale** — Compressed int16 vectors must decode with the packet's documented scale factors: 1/2048 for the 3-dword + 3-int16 record, 0.02 for the this[15..17] record, and 1/512 for the 2-component this[20]/this[21] record with the Y output component zeroed.
- **MatrixVectorMultiplyReturnsInput** — The 3x3-by-vector multiply must return the input vector pointer; the Euler conversion must produce a row-major 3x3 rotation matrix with no side effects; MatrixVectorSetup must return a pointer to the stored matrix.

## Unresolved

- Strut/node element layouts (position +148/+152/+156, plane coefficients +164/+172, type +300, linked child +272, sibling link +268, child-select +276, path length +60, stride 316) are DERIVED from the decompilation; the packet carries no field table for these element types and they are not placed as class fields.
- Fields this+0x1C8, +0x1CC, +0x1D0, +0x1D8, +0x1E0, +0x244, +0x260 are listed as read by 0x004038E0 but do not appear in the raw source text; their role is unknown.
- Globals flt_59E440, flt_59E4D8, flt_59E6EC, flt_59E77C are listed as read but do not appear in the raw source text (scale literals are inlined); the globals' own read sites are not visible in this packet.
- Whether node+272 is a child pointer or a sibling link is inferred from existing analysis; not provable from this packet alone.
- The meaning of the 200.0 bound (flt_59E470) as a search radius is DERIVED; the raw source only compares the accumulated path length against it.
- 0x00435E00 reads 8-byte doubles at 8-byte stride while 0x00566E40 writes 4-byte floats at 4-byte stride; shared offsets 0x00-0x20 may belong to distinct storage, so the MatrixVectorHelpers grouping is DERIVED and unproven.
- PackedShortVectorRecord groups three distinct record layouts (0x0..0x10, 0x1E..0x22, 0x28..0x2A) under one base; common ownership of a single record struct is unproven.
- SpatialNearestNeighborQuery groups three functions whose common ownership is unproven: query-position fields (+0/4/8) come from 0x004039C0 only, strut fields (+0x130/+0x134) from 0x004038E0 only, and 0x00403AA0's own use of this-fields is not evidenced by packet operations.
- The role of the output vector written by 0x004F17D0 within the per-frame physics step is not described in the packet.
- Callers (AISteering 0x004270A0, VehiclePhysicsTimeStep 0x004C73F0, AudioParameterInterpolation 0x004FF680, PhysicsDefaultsInitializer 0x004F2B50, TireModelDataInit 0x004F34E0) are known only through evidence refs; no caller-side packet data is available.
- Input angles a1[0..2] of 0x00566E40 are read via pointer arithmetic, not through the this-based field evidence list.
