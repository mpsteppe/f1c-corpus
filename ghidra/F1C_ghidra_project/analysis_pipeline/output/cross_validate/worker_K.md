# Cross-Validation Audit — Worker K

## FUN_0054f2f0 — FAIL
Source: docs/17-physics-collision.md

**Errors:**
- [MISSING_GLOBAL] .c references DAT_008b8f24 (physics engine vtable pointer, called as method at +0x20 for edge intersection test) not mentioned in entry

**Corrected entry:**
<!-- target: docs/17-physics-collision.md -->
## FUN_0054f2f0 — Wheel-Triangle Mesh Collision Detection

Source: collision. Tests wheel position against track triangle mesh vertices. On collision, records contact point and pushes wheel away from triangle surface.

**Key logic:**
- Reads wheel position (param_1+0x204) offset 0xe8/0xec/0xf0 (local space)
- Iterates all track mesh vertices (param_3+0x120 count, stride 0x12):
  - Each vertex has: triangle index, 3 vertex indices, center, 3 edge vectors, normal, radius
  - Tests if wheel center is within sphere of (vertex_radius + wheel_radius) from vertex center
- For each nearby vertex: reads sub-triangle data from vertex
- For each triangle edge (param_1+0x1e0 edge count):
  - If not edge type 6 (skip type 6 edges):
    - Computes interpolation along edge via physics engine vtable call (DAT_008b8f24+0x20): uses 0x10 distance threshold
    - If intersection found: calls FUN_0054eb40 for contact resolution
    - Records collision: marks edge as hit (sets piVar3=1), stores collision data:
      - param_2 (material), param_3 (collision group), param_1 (wheel ID)
      - Contact point in world space, impact force, penetration depth
      - Triangle normal (from param_3+300 + triangle_index*0x10)
- Returns count of contacts found (local_38)

**Globals:**
- DAT_008b8f24 — physics engine context vtable pointer (method at +0x20 for edge distance test)

**Calls:** FUN_0054eb40, FUN_00559a30

**Moddability:** hardcoded

## FUN_0051427f — FAIL
Source: docs/17-physics-collision.md

**Errors:**
- [MISSING_GLOBAL] .c references DAT_0059e4e0 (split plane scaling factor) not mentioned in entry
- [MISSING_GLOBAL] .c references PTR_DAT_005ade40 (minimum AABB size threshold for split) not mentioned in entry
- [MISSING_GLOBAL] .c references DAT_005d79bc/c0/c4/c8 (initial AABB min/max constants) not mentioned in entry
- [MISSING_GLOBAL] .c references DAT_005adb14 (integer fmod/rounding constant for negative values) not mentioned in entry

**Corrected entry:**
<!-- target: docs/17-physics-collision.md -->
## FUN_0051427f — BVH Node Split with Separating Plane

Source: likely_bvh_builder.cpp. Splits a set of 16 points into two children at a bounding volume hierarchy node.

**Key logic:**
- Takes 16 3D points from `param_3 + 8` (stride 4 floats)
- Computes AABB of all 16 points, initializing bounds from DAT_005d79bc/c0/c4/c8 constants
- If AABB size < PTR_DAT_005ade40 threshold: skip split, output raw bounds directly
- Selects split plane candidates from `DAT_005af5f0`/`DAT_005af60c` based on `param_4` (mode flag)
- Iterative refinement (up to 8 iterations or convergence):
  - Projects points onto split axis using DAT_0059e4e0 scaling factor
  - Evaluates 4 candidate split planes (SAH heuristic with 4 bins)
  - Updates min/max bounds for each side
- Convergence threshold at `_DAT_005ad1b8` and gradient threshold at `_DAT_005af5dc`
- Outputs min bounds to param_1, max bounds to param_2

**Globals:**
- `DAT_0059e450` — 0.5f (center computation)
- `DAT_005ad1b8` — convergence threshold
- `DAT_005af5dc` — gradient convergence threshold
- `DAT_0059e440` — epsilon (near-zero)
- `DAT_0059e670` — 1.0f (division normalization)
- `DAT_0059e4e0` — split evaluation scaling factor
- `DAT_005adb14` — integer fmod constant for negative value wrapping
- `PTR_DAT_005ade40` — minimum AABB size threshold (skip split below this)
- `DAT_005d79bc`/`c0`/`c4`/`c8` — initial AABB min/max initialization constants (±FLT_MAX)

**Calls:** FUN_00513e5d (helper)

**Moddability:** hardcoded

## FUN_0049B670 — PASS

## FUN_0044e9c0 — FAIL
Source: docs/17-physics-collision.md

**Errors:**
- [WRONG_CONST] Entry claims "zeros 3 fields between" but source shows 4 zeroed fields (0x58, 0x5c, 0x60, 0x64)
- [MISSING_GLOBAL] Source zeroes DAT_007cca58, 5c, 60, 64 but these are not listed in entry's globals section

**Corrected entry:**
<!-- target: docs/17-physics-collision.md -->
## FUN_0044e9c0 — ConstraintSolverInit3

Initializes constraint solver global state set 3.

**Key logic:**
- Sets DAT_007cca54 = 0x5d (93 — max iterations or constraint count)
- Zeros 4 intermediate fields: DAT_007cca58, 5c, 60, 64
- Sets DAT_007cca68 = 27000 (stabilization factor)

**Globals:**
- `DAT_007cca54` — constraint count/size
- `DAT_007cca58/5c/60/64` — zeroed solver state fields
- `DAT_007cca68` — constraint stabilization factor

**Calls:** none

**Moddability:** hardcoded — solver config

## FUN_0044d190 — PASS

## FUN_0044f5f0 — PASS

## FUN_00494e60 — PASS

## FUN_0044daf0 — PASS

## FUN_0044b040 — PASS

## FUN_0044c8c0 — PASS

## FUN_0044dc70 — PASS

## FUN_0045bf90 — PASS

## FUN_0044ca40 — PASS

## FUN_0044ddf0 — PASS

## FUN_0044d8e0 — PASS

## FUN_0045ca20 — PASS

## FUN_0044d730 — PASS

## FUN_00491280 — PASS

## FUN_00568fb0 — PASS

## FUN_00401c90 — PASS

## FUN_00447f30 — PASS

## FUN_004e2610 — PASS

## FUN_00457d00 — FAIL
Source: docs/18-physics-dynamics.md

**Errors:**
- [WRONG_CONST] Doc claims "Binary searches" but source uses linear search (sequential scan with stride 7 floats, increments by 1)
- [WRONG_CONST] Doc claims "4 control points" but source uses variable count from param_1[1]; search loop goes to param_1[1] - 3 (count - 2 segments)

**Corrected entry:**
<!-- target: docs/18-physics-dynamics.md -->
## FUN_00457d00 — Cubic Hermite Spline Interpolation

Source: math_util. Evaluates a 4-point cubic Hermite/Catmull-Rom spline at parameter t.

**Key logic:**
- Takes param_2 as interpolation parameter t
- If t < epsilon (DAT_0059e440): returns first control point ([0], [1], [2])
- If t >= count-1: returns last control point
- Linearly searches for segment containing t from control point array
- Computes basis functions using Hermite/Catmull-Rom coefficients:
  - h00 = 2t^3 - 3t^2 + 1
  - h10 = t^3 - 2t^2 + t
  - h01 = -2t^3 + 3t^2
  - h11 = t^3 - t^2
- Evaluates: P = P0*h11 + P1*h00 + P2*h10 + P3*h01 (with constant scaling _DAT_0059e450)
- Writes interpolated value to param_1[4], [5], [6] as integers

**Struct offsets (param_1 — control point array, stride 0x1c = 28 bytes):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x00 | ControlPoint[0..N] | Variable count of control points (7 floats each at stride 7) |
| +0x1c | Count | Number of control points |
| +0x08 | CurrentT | Current parameter value (stored) |

**Globals:** _DAT_0059e478, _DAT_0059e7ec, _DAT_0059e800, _DAT_0059e46c, _DAT_0059e450 (basis coefficients)

**Moddability:** hardcoded

## FUN_004320a0 — PASS

## FUN_004499e0 — PASS

## FUN_00432810 — PASS

## FUN_004532d0 — PASS

## FUN_004336d0 — PASS

## FUN_00448e20 — PASS

## FUN_0059d9b5 — PASS

## FUN_005176ec — PASS

## FUN_00569a20 — PASS

## FUN_004c71c0 — PASS

## FUN_004133b0 — PASS

## FUN_004862a0 — PASS

## FUN_00489ba0 — PASS

## FUN_00495580 — PASS

## FUN_00499a70 — PASS

## FUN_005824f0 — PASS

## FUN_0050b47e — PASS

## FUN_00512894 — PASS

## FUN_0051cf80 — PASS

## FUN_0044ee10 — PASS

## FUN_0053d970 — PASS

## FUN_0044fa60 — PASS

## FUN_004a70e0 — PASS

## FUN_00513bd1 — PASS

## FUN_00586700 — PASS

## FUN_00547390 — PASS

## FUN_004b21f0 — PASS

## FUN_00562c90 — PASS

## FUN_004cb540 — PASS

## FUN_00479c00 — PASS

## FUN_0050368a — PASS

## FUN_00587dd0 — FAIL
Source: docs/20-math-utilities.md
**Errors:**
- [WRONG_DESCRIPTION] Doc claims "NOT FOUND / decompiled file missing" but source file exists (0x00587dd0___strncpy.c, MSVC _strncpy, 254 bytes)

## FUN_00594ab4 — FAIL
Source: docs/20-math-utilities.md
**Errors:**
- [WRONG_CATEGORY] Doc describes as pure math utility but function accesses globals PTR_LOOP_005e796c, DAT_008d41b8 (OS memory management, VirtualFree loop)

## FUN_0058bc68 — FAIL
Source: docs/20-math-utilities.md
**Errors:**
- [WRONG_CATEGORY] Doc describes as math comparison but function reads globals _DAT_005b8c80, _DAT_005b8d48, _DAT_005b8d50 (not a pure function)

## FUN_0055eba0 — FAIL
Source: docs/20-math-utilities.md
**Errors:**
- [WRONG_DESCRIPTION] Doc says "thunk — compares two paths, returns 0 or 1" (5 bytes). Source is 366 bytes: 3D vector math with SQRT, DAT_008b8f24, DAT_0059e43c/DAT_0059e450. Completely wrong description.

## FUN_0059325d — FAIL
Source: docs/20-math-utilities.md
**Errors:**
- [WRONG_DESCRIPTION] Doc says "CRT _ftol2 — float-to-long rounding". Source shows CRT heap init: HeapCreate, HeapDestroy, FUN_00593115, DAT_008d4904/DAT_008d4908. Wrong description.

## FUN_00592f2c — PASS

## FUN_00589901 — PASS

## FUN_00586670 — PASS

## FUN_00589057 — PASS

## FUN_005835f0 — PASS

## FUN_00465150 — PASS

## FUN_0052e530 — PASS

## FUN_00534ae0 — PASS

## FUN_004527e0 — PASS

## FUN_0047a800 — PASS

## FUN_00495890 — PASS

## FUN_004baac0 — PASS

## FUN_00500f3c — PASS

## FUN_0053c6a0 — PASS

## FUN_00591cf3 — PASS

## FUN_0059d208 — PASS

## FUN_004613e0 — PASS

## FUN_00486720 — PASS

## FUN_004a5660 — PASS

## FUN_004d8720 — PASS

## FUN_00516fb0 — PASS

## FUN_00568a60 — PASS

## FUN_00599707 — PASS

## FUN_004889d0 — PASS

## FUN_0050c78c — PASS

## FUN_00591e49 — PASS

## FUN_00407e10 — PASS

## FUN_004649f0 — PASS

## FUN_0048a3b0 — PASS

## FUN_004a3440 — PASS

## FUN_004d5840 — PASS

## FUN_00510f89 — PASS

## FUN_0057a8e0 — PASS

## FUN_0046fdc0 — PASS

## FUN_00411ab0 — PASS

## FUN_00488b30 — PASS

## FUN_004a1d50 — PASS

## FUN_004d10e0 — PASS

## FUN_0050d97e — PASS

## FUN_005473d0 — PASS

## FUN_0050c021 — PASS

## FUN_00415650 — PASS

## FUN_00473650 — PASS

## FUN_00495010 — PASS

## FUN_004b9810 — PASS

## FUN_004f8a70 — PASS

## FUN_0055bfd0 — PASS

## FUN_00596c20 — PASS

## FUN_0040e8f0 — PASS

## FUN_0046d6c0 — PASS

## FUN_00554e90 — PASS

## FUN_00586070 — PASS

## FUN_0045d530 — PASS

## FUN_005813e0 — PASS

## FUN_0057fb90 — PASS

## FUN_0057b8c0 — PASS

## FUN_0057b910 — PASS

## FUN_00581e80 — PASS

## FUN_0050fab7 — PASS

## FUN_0047c0a0 — FAIL
Source: docs/20-math-utilities.md
**Errors:**
- [WRONG_DESCRIPTION] Doc claims "Sqrt Approximation / Distance Calc". Source shows string copy from FUN_00489920() to global DAT_007cd880. No sqrt, no distance math.

## FUN_0047a210 — FAIL
Source: docs/20-math-utilities.md
**Errors:**
- [WRONG_DESCRIPTION] Doc claims "Function Call Wrapper". Source shows constructor: calls FUN_004668e0(0, 0x3f800000), sets vtable PTR_FUN_005a6068, writes byte at +0x40. Not a trivial wrapper.

## FUN_004999e0 — FAIL
Source: docs/20-math-utilities.md
**Errors:**
- [WRONG_DESCRIPTION] Doc claims "Function Call Wrapper". Source shows initializer: sets [0]=0, [1]=0xffffffff, calls FUN_00499a00(). Initializer, not trivial wrapper.

## FUN_004902a0 — PASS

## FUN_004b2aa0 — PASS

## FUN_004dc660 — PASS

## FUN_0051613f — PASS

## FUN_005568b0 — PASS

## FUN_00559390 — PASS

## FUN_00491600 — PASS

## FUN_0054b420 — PASS

## FUN_00401000 — PASS

## FUN_0045d510 — PASS

## FUN_00486340 — PASS

## FUN_0049d4c0 — PASS

## FUN_004c8fc0 — PASS

## FUN_0050b3ed — PASS

## FUN_00541ca0 — PASS

## FUN_005986b2 — PASS

## FUN_00564530 — PASS

## FUN_00566f40 — PASS

## FUN_0051641e — PASS

## FUN_004bafc0 — PASS

## FUN_00499e10 — PASS

## FUN_0047bcf0 — PASS

## FUN_00457f90 — PASS

## FUN_004be010 — PASS

## FUN_004fc910 — PASS

## FUN_00536e90 — PASS

## FUN_00587220 — PASS

## FUN_0057a070 — PASS

## FUN_0059d328 — PASS

## FUN_004615f0 — PASS

## FUN_00487220 — PASS

## FUN_0049f6a0 — PASS

## FUN_004ca430 — PASS

## FUN_0050c15e — PASS

## FUN_00543920 — PASS

## FUN_0059baa3 — PASS

## FUN_00406ba0 — PASS

## FUN_00463e00 — PASS

## FUN_00489480 — PASS

## FUN_004a21d0 — PASS

## FUN_004d47a0 — PASS

## FUN_0050e0d3 — PASS

## FUN_00547920 — PASS

## FUN_0059c8a4 — PASS

## FUN_0040ac40 — PASS

## FUN_00466270 — PASS

## FUN_0048d360 — PASS

## FUN_004b1a70 — PASS

## FUN_004d91e0 — PASS

## FUN_005158e3 — PASS

## FUN_005528b0 — PASS

## FUN_00583210 — PASS

## FUN_004560a0 — PASS

## FUN_0048b950 — PASS

## FUN_004a40c0 — PASS

## FUN_004d7020 — PASS

## FUN_0051189c — PASS

## FUN_0054bda0 — PASS

## FUN_005884e0 — PASS

## FUN_004d4800 — PASS

## FUN_00553620 — PASS

## FUN_0059ae07 — PASS

## FUN_00517f35 — PASS

## FUN_00403f70 — PASS

## FUN_00466300 — PASS

## FUN_0048d3f0 — PASS

## FUN_004b1c20 — PASS

## FUN_004d9f80 — PASS

## FUN_00513b51 — PASS

## FUN_0054fc70 — PASS

## FUN_0052d8c0 — PASS

## FUN_00418a20 — PASS

## FUN_00474900 — PASS

## FUN_00495790 — PASS

## FUN_004b9d90 — PASS

## FUN_004effd0 — PASS

## FUN_00522ce2 — PASS

## FUN_00567d00 — PASS

## FUN_004184b0 — PASS

## FUN_0059c68e — PASS

## FUN_004047d0 — PASS

## FUN_0059c478 — PASS

## FUN_00566e20 — PASS

## FUN_0059d0a7 — PASS

## FUN_00457cf0 — PASS
Source: docs/17-physics-collision.md

**Errors:**
- [MISSING_GLOBAL] .c references DAT_008b8f24 (physics engine vtable pointer, called as method at +0x20 for edge intersection test) not mentioned in entry

**Corrected entry:**
<!-- target: docs/17-physics-collision.md -->
## FUN_0054f2f0 — Wheel-Triangle Mesh Collision Detection

Source: collision. Tests wheel position against track triangle mesh vertices. On collision, records contact point and pushes wheel away from triangle surface.

**Key logic:**
- Reads wheel position (param_1+0x204) offset 0xe8/0xec/0xf0 (local space)
- Iterates all track mesh vertices (param_3+0x120 count, stride 0x12):
  - Each vertex has: triangle index, 3 vertex indices, center, 3 edge vectors, normal, radius
  - Tests if wheel center is within sphere of (vertex_radius + wheel_radius) from vertex center
- For each nearby vertex: reads sub-triangle data from vertex
- For each triangle edge (param_1+0x1e0 edge count):
  - If not edge type 6 (skip type 6 edges):
    - Computes interpolation along edge via physics engine vtable call (DAT_008b8f24+0x20): uses 0x10 distance threshold
    - If intersection found: calls FUN_0054eb40 for contact resolution
    - Records collision: marks edge as hit (sets piVar3=1), stores collision data:
      - param_2 (material), param_3 (collision group), param_1 (wheel ID)
      - Contact point in world space, impact force, penetration depth
      - Triangle normal (from param_3+300 + triangle_index*0x10)
- Returns count of contacts found (local_38)

**Globals:**
- DAT_008b8f24 — physics engine context vtable pointer (method at +0x20 for edge distance test)

**Calls:** FUN_0054eb40, FUN_00559a30

**Moddability:** hardcoded

