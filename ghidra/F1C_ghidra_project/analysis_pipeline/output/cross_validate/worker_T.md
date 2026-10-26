# Cross-Validation Audit — Worker T

## FUN_0044A4B0 — MISSING

Source: docs/17-physics-collision.md

**Errors:**
- [MISSING_ENTRY] No `## FUN_` or `### FUN_` entry found in docs/17-physics-collision.md

**Corrected entry:**
<!-- target: docs/17-physics-collision.md -->
## FUN_0044A4B0 — BVHTraverseBuildNode

Source: physics_collision.cpp. Traverses collision tree structure, builds output node with minimum distance match.

**Key logic:**
- Takes param_1 (output struct), param_2 (linked list of candidates), param_3 (root node)
- Counts linked list nodes via +0x1c next pointers
- If >2 nodes: computes sampling stride (0xe/stride, clamp 1..stride)
- If 1 node: writes 0xffff to param_1+8
- If 2 nodes: writes 0xfffe to param_1+8
- Samples up to 14 candidates via FUN_0044a450, picks index with minimum distance (local_4)
- Stores selected index as leaf/offset at param_1+8/+10 (short pair)
- For leaf < 8: writes 0 at +8, leaf at +10. For >=8: writes 1 at +8, 14-leaf at +10
- Allocates buffer entry at param_1+0xc using +0x28 * 0x10 + +0x30 offset, increments +0x28 by 2
- Writes vector data to allocated buffer
- Recursively calls self on children

**Recursive:** Calls FUN_0044a4b0 (self) for child branches on left/right

**Calls:** FUN_00566bd0 (memcpy/serialize), FUN_0044a450 (query candidate), FUN_0044a2d0 (distance check), FUN_00449ed0 (process leaf)

**Struct offsets (param_2 linked list):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x1c | NextPtr | Linked list next pointer |
| +0x28 | BufferWriteIndex | Index into output buffer |
| +0x30 | BufferBase | Base address of output buffer |
| +0x34 | NodeData | Node-specific data |

**Moddability:** hardcoded

---

## FUN_0044DA00 — MISSING

Source: docs/17-physics-collision.md

**Errors:**
- [MISSING_ENTRY] No `## FUN_` or `### FUN_` entry found in docs/17-physics-collision.md

**Corrected entry:**
<!-- target: docs/17-physics-collision.md -->
## FUN_0044DA00 — CollisionStateInit

Source: physics_collision.cpp. Initializes collision system global state.

**Key logic:**
- Sets DAT_007ccf18 = 0x2b (43)
- Zeroes DAT_007ccf1c through DAT_007ccf2c (5 consecutive dword fields)

**Globals:**
- `DAT_007ccf18` — collision system state/param (unknown)

**Moddability:** hardcoded

---

## FUN_00475D30 — MISSING

Source: docs/17-physics-collision.md

**Errors:**
- [MISSING_ENTRY] No `## FUN_` or `### FUN_` entry found in docs/17-physics-collision.md

**Corrected entry:**
<!-- target: docs/17-physics-collision.md -->
## FUN_00475D30 — CollisionConfigSync

Source: physics_collision.cpp. Syncs collision configuration when global parameter changes.

**Key logic:**
- Checks if DAT_007cd614 != DAT_007ce250
- If different: updates DAT_007cd614 = DAT_007ce250
- Calls FUN_00455bd0 (recompute/rebuild)
- Calls FUN_00454da0 passing DAT_007cd458, DAT_007cd45c, DAT_007cd2b0, DAT_007cd610 pointers

**Globals:**
- `DAT_007cd614` — current collision config value
- `DAT_007ce250` — new collision config value
- `DAT_008afe90` — float constant for config
- `DAT_007cd458`, `DAT_007cd45c`, `DAT_007cd2b0`, `DAT_007cd610` — config struct fields

**Calls:** FUN_00455bd0, FUN_00454da0

**Moddability:** hardcoded

---

## FUN_00457A00 — MISSING

Source: docs/17-physics-collision.md

**Errors:**
- [MISSING_ENTRY] No `## FUN_` or `### FUN_` entry found in docs/17-physics-collision.md

**Corrected entry:**
<!-- target: docs/17-physics-collision.md -->
## FUN_00457A00 — CollisionParticleJitter

Source: physics_collision.cpp. Applies random jitter velocity to collision particle based on position + random direction.

**Key logic:**
- Calls FUN_00457b00(1) — seed/init
- Reads position from param_1+0x90/+0x94/+0x98 (x/y/z floats)
- Gets 3 random values via FUN_00456010, uses sign bit to set direction ±1.0
- Computes magnitude: fVar2 = param_2 * param_3 * DAT_0059e450
- Clamps magnitude to max (DAT_0059e450)
- Selects Z-direction multiplier: DAT_0059e670 or DAT_0059e43c based on random
- Applies velocity: x += sign0 * mag * param_3, y += sign1 * mag * param_3, z += mag * zMult * param_3
- Calls FUN_00456130 with result (constrain/clamp)

**Globals:**
- `DAT_0059e450` — velocity magnitude multiplier + clamp max
- `DAT_0059e670` — Z-direction coefficient (~1.0)
- `DAT_0059e43c` — alternative Z-direction coefficient

**Calls:** FUN_00457b00, FUN_00456010 (RNG), FUN_00456130

**Moddability:** `configurable` — DAT_0059e450, DAT_0059e670, DAT_0059e43c tune velocity

---

## FUN_0044EA80 — MISSING

Source: docs/17-physics-collision.md

**Errors:**
- [MISSING_ENTRY] No `## FUN_` or `### FUN_` entry found in docs/17-physics-collision.md

**Corrected entry:**
<!-- target: docs/17-physics-collision.md -->
## FUN_0044EA80 — CollisionGlobalInit

Source: physics_collision.cpp. Initializes collision system global array state.

**Key logic:**
- Sets DAT_007ca4e0 = 0x5f (95)
- Zeroes DAT_007ca4e4, DAT_007ca4e8, DAT_007ca4ec, DAT_007ca4f0 (4 consecutive dwords)
- Sets DAT_007ca4f4 = 9000

**Globals:**
- `DAT_007ca4e0` — collision array size/count (95)
- `DAT_007ca4f4` — collision array max value (9000)

**Moddability:** hardcoded

---

## FUN_0044D250 — MISSING

Source: docs/17-physics-collision.md

**Errors:**
- [MISSING_ENTRY] No `## FUN_` or `### FUN_` entry found in docs/17-physics-collision.md

**Corrected entry:**
<!-- target: docs/17-physics-collision.md -->
## FUN_0044D250 — CollisionDeinit

Source: physics_collision.cpp. Deinitialization thunk — calls free/release on collision data.

**Key logic:**
- Calls FUN_00587b3e (free/dealloc) with PTR_LAB_0044d260 (global collision data pointer)

**Calls:** FUN_00587b3e (memory free)

**Moddability:** hardcoded

---

## FUN_0044A070 — MISSING

Source: docs/17-physics-collision.md

**Errors:**
- [MISSING_ENTRY] No `## FUN_` or `### FUN_` entry found in docs/17-physics-collision.md

**Corrected entry:**
<!-- target: docs/17-physics-collision.md -->
## FUN_0044A070 — BVHLeafOverlapTest

Source: physics_collision.cpp. Tests if a point overlaps a bounding volume hierarchy leaf node.

**Key logic:**
- Takes param_1 (BVH leaf node, 7 doubles) and param_2 (query point/result)
- Checks 3 planes at param_1+0x34, +0x40, +0x4c (offset 0x34 + i*0xc, stride 12 bytes)
- Each plane: tests if (point.x * normal.x + point.y * normal.y) < offset
- If any fails: returns 0 (no overlap)
- If all 3 pass: evaluates quadratic form: dVar1 = z²*param_1[1] + param_1[4] + x²*param_1[0] + z*param_1[2] + param_1[3] + param_1[5]
- Compares against param_2[1] (distance threshold)
- If within bounds and abs(dVar1 - param_2[1]) <= param_2[3] AND >= param_2[4]: updates param_2[4] = distance, stores param_1 at param_2+6, returns 1

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x00 | double[6] | Quadratic form coefficients A..F |
| +0x30 | double | Unused in test |
| +0x34 | float[3]×3 | Three plane normals (x,y) + offset |

**Struct offsets (param_2):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x00 | double x | Query point x |
| +0x08 | double | Distance threshold |
| +0x10 | double z | Query point z |
| +0x18 | double | Min distance bound |
| +0x20 | double | Max distance bound (current best) |
| +0x28 | double | Quadratic result |
| +0x30 | double* | Closest leaf pointer |

**Moddability:** hardcoded

---

## FUN_0044EC00 — MISSING

Source: docs/17-physics-collision.md

**Errors:**
- [MISSING_ENTRY] No `## FUN_` or `### FUN_` entry found in docs/17-physics-collision.md

**Corrected entry:**
<!-- target: docs/17-physics-collision.md -->
## FUN_0044EC00 — CollisionArrayInit99

Source: physics_collision.cpp. Initializes collision system array state (size 99).

**Key logic:**
- Sets DAT_007ca3f8 = 99
- Zeroes DAT_007ca3fc, DAT_007ca400, DAT_007ca404, DAT_007ca408 (4 consecutive dwords)
- Sets DAT_007ca40c = 9000

**Globals:**
- `DAT_007ca3f8` — collision array size (99)
- `DAT_007ca40c` — collision max value (9000)

**Moddability:** hardcoded

---

## FUN_0044D430 — MISSING

Source: docs/17-physics-collision.md

**Errors:**
- [MISSING_ENTRY] No `## FUN_` or `### FUN_` entry found in docs/17-physics-collision.md

**Corrected entry:**
<!-- target: docs/17-physics-collision.md -->
## FUN_0044D430 — CollisionSectionDeinit

Source: physics_collision.cpp. Deinitialization thunk for collision section data.

**Key logic:**
- Calls FUN_00587b3e (free/dealloc) with DAT_0044d440 pointer

**Calls:** FUN_00587b3e (memory free)

**Moddability:** hardcoded

---

## FUN_0044FC20 — MISSING

Source: docs/17-physics-collision.md

**Errors:**
- [MISSING_ENTRY] No `## FUN_` or `### FUN_` entry found in docs/17-physics-collision.md

**Corrected entry:**
<!-- target: docs/17-physics-collision.md -->
## FUN_0044FC20 — WheelCollisionClamp

Source: physics_collision.cpp. Clamps and stores wheel collision parameters (spring/damping/rebound).

**Key logic:**
- Clamps param_4 (damping) between DAT_0059e440 and DAT_0059e43c
- Stores at param_1 + 0x20 + param_2 * 4
- Clamps param_3 (rebound) >= DAT_0059e440, stores at param_1 + 0x2f8 + param_2 * 4
- Clamps param_5 (spring) between DAT_0059e440 and DAT_0059e43c, stores at param_1 + param_2 * 4
- Calls FUN_0044f8f0 (recompute) after storing

**Globals:**
- `DAT_0059e440` — zero threshold / min clamp
- `DAT_0059e43c` — max clamp

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x00 + param_2*4 | SpringK | per-wheel spring rate |
| +0x20 + param_2*4 | Damping | per-wheel damping |
| +0x2f8 + param_2*4 | BumpRebound | per-wheel rebound |

**Calls:** FUN_0044f8f0 (recompute derived)

**Moddability:** `configurable` — clamps via physics constants

---

## FUN_0044F070 — MISSING

Source: docs/17-physics-collision.md

**Errors:**
- [MISSING_ENTRY] No `## FUN_` or `### FUN_` entry found in docs/17-physics-collision.md

**Corrected entry:**
<!-- target: docs/17-physics-collision.md -->
## FUN_0044F070 — CollisionFlagFill

Source: physics_collision.cpp. Fills 64 bytes at param_1+0x27c with a repeating byte value.

**Key logic:**
- Writes param_2 byte repeated across 64 dwords (0x100 bytes) at param_1 + 0x27c
- Loop: 64 iterations, each writing 4 copies of param_2

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x27c | byte[256] | Flag/collision array |

**Moddability:** hardcoded

---

## FUN_0044D5B0 — MISSING

Source: docs/17-physics-collision.md

**Errors:**
- [MISSING_ENTRY] No `## FUN_` or `### FUN_` entry found in docs/17-physics-collision.md

**Corrected entry:**
<!-- target: docs/17-physics-collision.md -->
## FUN_0044D5B0 — CollisionQueryDeinit

Source: physics_collision.cpp. Deinitialization thunk for collision query data.

**Key logic:**
- Calls FUN_00587b3e (free/dealloc) with DAT_0044d5c0 pointer

**Calls:** FUN_00587b3e (memory free)

**Moddability:** hardcoded

---

## FUN_0045F390 — MISSING

Source: docs/17-physics-collision.md

**Errors:**
- [MISSING_ENTRY] No `## FUN_` or `### FUN_` entry found in docs/17-physics-collision.md

**Corrected entry:**
<!-- target: docs/17-physics-collision.md -->
## FUN_0045F390 — CollisionDamageTimeout

Source: physics_collision.cpp. Runs collision damage timeout loop for vehicle with state=3.

**Key logic:**
- Only runs if *(int*)(param_1+0x3fc4) == 3 (vehicle collision state)
- Initializes timer from DAT_0059e440 (zero threshold)
- Loop: checks if DAT_0059e440 exceeds threshold via FP compare
- On threshold exceed: calls FUN_0057a5a0, sets local_60 = 4.0 (4-second timeout)
- Calls FUN_0057a610 to check if timeout expired
- If expired: calls damage processing functions and returns 1
- Accumulates delta time via FUN_00568cf0
- Exits when accumulated time >= DAT_0059f118
- On exit: calls FUN_004b0170 (cleanup)

**Globals:**
- `DAT_0059e440` — zero threshold for FP comparison
- `DAT_0059f118` — max accumulated time bound

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x3fc4 | int | Vehicle collision state (3 = damage timeout active) |

**Calls:** FUN_00568ba0, FUN_00568be0, FUN_00568c60, FUN_0057a5a0, FUN_0057a610, FUN_004f9fc0, FUN_0042bda0, FUN_0042cf10, FUN_0045c8b0, FUN_004b0170, FUN_00568cf0

**Moddability:** `configurable` — timeout values via physics thresholds

---

## FUN_0044E780 — MISSING

Source: docs/17-physics-collision.md

**Errors:**
- [MISSING_ENTRY] No `## FUN_` or `### FUN_` entry found in docs/17-physics-collision.md

**Corrected entry:**
<!-- target: docs/17-physics-collision.md -->
## FUN_0044E780 — CollisionArrayInit87

Source: physics_collision.cpp. Initializes collision system array state (size 0x57 = 87).

**Key logic:**
- Sets DAT_007ccfec = 0x57 (87)
- Zeroes DAT_007ccff0, DAT_007ccff4, DAT_007ccff8, DAT_007ccffc (4 consecutive dwords)
- Sets DAT_007cd000 = 9000

**Globals:**
- `DAT_007ccfec` — collision array size (87)
- `DAT_007cd000` — collision max value (9000)

**Moddability:** hardcoded

---

## FUN_0044E0C0 — MISSING

Source: docs/17-physics-collision.md

**Errors:**
- [MISSING_ENTRY] No `## FUN_` or `### FUN_` entry found in docs/17-physics-collision.md

**Corrected entry:**
<!-- target: docs/17-physics-collision.md -->
## FUN_0044E0C0 — CollisionArrayInit69

Source: physics_collision.cpp. Initializes collision system array state (size 0x45 = 69).

**Key logic:**
- Sets DAT_007ccd98 = 0x45 (69)
- Zeroes DAT_007ccd9c through DAT_007ccdac (5 consecutive dwords)

**Globals:**
- `DAT_007ccd98` — collision array size (69)

**Moddability:** hardcoded

---

## FUN_0044FEE0 — MISSING

Source: docs/17-physics-collision.md

**Errors:**
- [MISSING_ENTRY] No `## FUN_` or `### FUN_` entry found in docs/17-physics-collision.md

**Corrected entry:**
<!-- target: docs/17-physics-collision.md -->
## FUN_0044FEE0 — CollisionAccumAdd

Source: physics_collision.cpp. Adds force/torque accumulation to collision impulse buffers.

**Key logic:**
- param_1 is vehicle/collision struct
- param_2 is double[3] linear force vector
- param_3 is double[3] angular torque vector
- Adds param_2 x/y/z to param_1+0x560/+0x568/+0x570 (linear impulse accumulator)
- Adds param_3 x/y/z to param_1+0x578/+0x580/+0x588 (angular impulse accumulator)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x560 | double | Linear impulse X accumulator |
| +0x568 | double | Linear impulse Y accumulator |
| +0x570 | double | Linear impulse Z accumulator |
| +0x578 | double | Angular impulse X accumulator |
| +0x580 | double | Angular impulse Y accumulator |
| +0x588 | double | Angular impulse Z accumulator |

**Moddability:** hardcoded

---

## FUN_0044E060 — MISSING

Source: docs/17-physics-collision.md

**Errors:**
- [MISSING_ENTRY] No `## FUN_` or `### FUN_` entry found in docs/17-physics-collision.md

**Corrected entry:**
<!-- target: docs/17-physics-collision.md -->
## FUN_0044E060 — CollisionArrayInit68

Source: physics_collision.cpp. Initializes collision system array state (size 0x44 = 68).

**Key logic:**
- Sets DAT_007ccd68 = 0x44 (68)
- Zeroes DAT_007ccd6c through DAT_007ccd7c (5 consecutive dwords)

**Globals:**
- `DAT_007ccd68` — collision array size (68)

**Moddability:** hardcoded

---

## FUN_0054EB40 — MISSING

Source: docs/17-physics-collision.md

**Errors:**
- [MISSING_ENTRY] No `## FUN_` or `### FUN_` entry found in docs/17-physics-collision.md

**Corrected entry:**
<!-- target: docs/17-physics-collision.md -->
## FUN_0054EB40 — TrianglePointTest

Source: physics_collision.cpp. Triangle-point overlap test with 6 orientation modes.

**Key logic:**
- param_1: case value 0-5 selecting triangle orientation (XY, XZ, YZ planes)
- param_2: int[3] — three triangle vertex pointers
- param_3: float[3] — query point
- For cases 0-5: performs 2D edge cross-product tests against triangle vertices
- Case 0 (XY, CCW): tests all 3 edges with sign >= DAT_0059e440, returns 1 if inside
- Case 1 (XY, CW): tests all 3 edges with sign <= -DAT_0059e440
- Case 2 (XZ, CCW): projects onto XZ plane with same test
- Case 3 (XZ, CW): XZ plane, clockwise orientation
- Case 4 (YZ, CCW): uses FUN_0054ee90 for edge distance, all tests must be >= threshold
- Case 5 (YZ, CW): all edge distances must be <= -threshold
- Default: returns 1 (inside)

**Globals:**
- `DAT_0059e440` — zero threshold for edge test

**Calls:** FUN_0054ee90 (edge distance calc)

**Moddability:** hardcoded

---

## FUN_0056ECF0 — MISSING

Source: docs/18-physics-dynamics.md

**Errors:**
- [MISSING_ENTRY] No `## FUN_` or `### FUN_` entry found in docs/18-physics-dynamics.md

**Corrected entry:**
<!-- target: docs/18-physics-dynamics.md -->
## FUN_0056ECF0 — DynamicsSolverStep

Source: physics_dynamics.cpp. Executes one solver step: clears matrices, processes constraints/joints.

**Key logic:**
- Takes param_1 (dynamics solver context struct)
- If param_1[0xc] (callback pointer) NULL: zeroes matrix arrays at param_1[10] (size param_1[8]×8) and param_1[0xb] (size param_1[8]×8)
- Else: calls vtable callback at +0x1c on callback object
- Calls FUN_0056ec00 (solver init)
- Loops param_1[0] times calling FUN_0056a240 (iterative solve)
- Processes 3 constraint groups from param_1[3], param_1[5], param_1[7]:
  - Group 1 (param_1[3], stride 0x30): checks flag byte at +0x2c, if bit 0 set, frees 3 consecutive indices via FUN_0056ec70
  - Group 2 (param_1[5], stride 0x30): checks flag byte at +0x2c, frees 2 consecutive indices using +0x7c offset
  - Group 3 (param_1[7], stride 0x48): checks flag at +0x44, frees single index
- If callback exists: calls vtable at +0x14 on callback
- Else: calls FUN_0056cd70 (update solver matrices)

**Calls:** FUN_0056ec00, FUN_0056a240, FUN_0056ec70 (repeated), FUN_0056cd70

**Moddability:** hardcoded

---

## FUN_00441F00 — MISSING

Source: docs/18-physics-dynamics.md

**Errors:**
- [MISSING_ENTRY] No `## FUN_` or `### FUN_` entry found in docs/18-physics-dynamics.md

**Corrected entry:**
<!-- target: docs/18-physics-dynamics.md -->
## FUN_00441F00 — WheelTorqueDistribute

Source: physics_dynamics.cpp. Computes wheel torque distribution for 4 wheels using chassis velocity + suspension force.

**Key logic:**
- If all 4 torque params == 0: sets flag at param_1+0x1724 = 0 and returns
- Sets param_1+0x1724 = 1 (active)
- For each wheel (0..3): computes 3D transform from suspension geometry
  - Reads pointer at param_1+0x15f0 (chassis dynamics), gets rotation matrix at +0x4c/+0x54/+0x5c
  - Transforms lever arm at +0x1660/+0x1668/+0x1670
  - Translates by chassis position at +0x14/+0x1c/+0x24 (from +0x4/+0xc/+0x14 offset)
  - Computes torque contribution using velocity at param_1+0x15f4 and DAT_0059ed58
  - Sums with previous integrated torque from param_1+0x16f0 and param_1+0x1720
  - Sets param_1[0x1748 + i*8] (6 doubles = quaternion) from computed transform

**Globals:**
- `DAT_0059e440` — zero threshold (used to check all-zero input)
- `DAT_0059ed58` — velocity scaling constant

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x15f0 | int* | Chassis dynamics pointer |
| +0x15f4 | double | Chassis velocity |
| +0x1660 | double[3] | Wheel lever arm X (per wheel, stride 0x18) |
| +0x16f0 | double | Previous wheel torque (per wheel, stride 8) |
| +0x1720 | double | Integrated torque offset (per wheel, stride 8) |
| +0x1724 | byte | Wheel torque active flag |
| +0x1748 | double[6] | Output quaternion/transform (per wheel, stride 0x18) |

**Calls:** FUN_00448da0, FUN_00448de0, FUN_00448480

**Moddability:** hardcoded

---

## FUN_0043D8DE — MISSING

Source: docs/18-physics-dynamics.md

**Errors:**
- [MISSING_ENTRY] No `## FUN_` or `### FUN_` entry found in docs/18-physics-dynamics.md

**Corrected entry:**
<!-- target: docs/18-physics-dynamics.md -->
## FUN_0043D8DE — DynamicsStateInit

Source: physics_dynamics.cpp. Initializes vehicle dynamics state fields to a given value.

**Key logic:**
- Takes unaff_EBX (this/vehicle pointer) and param_1 (fill value)
- Fills large block of offset fields with param_1:
  - +0x1ef0 through +0x1f34 (0x48 bytes, 18 consecutive dwords)
  - +0x30/0x34/0x38/0x3c (wheel state)
  - +0xb4 through +0x13c (0x8c bytes, 35 consecutive dwords)
  - Sets +0x34 = 3 (special constant)
- Total: ~56 dword fields reset to param_1

**Moddability:** hardcoded

---

## FUN_004E58D0 — MISSING

Source: docs/18-physics-dynamics.md

**Errors:**
- [MISSING_ENTRY] No `## FUN_` or `### FUN_` entry found in docs/18-physics-dynamics.md

**Corrected entry:**
<!-- target: docs/18-physics-dynamics.md -->
## FUN_004E58D0 — AerodynamicForceCalc

Source: physics_dynamics.cpp. Computes aerodynamic force contributions (drag/lift) applied to vehicle body.

**Key logic:**
- fVar1 = *(param_1+0x3514) * DAT_0059ed50 (speed scaling)
- Computes base forces from 3 axes using velocity at +0x34b0/+0x34bc/+0x34c8 (spring strut) and +0x34b4/0x34c0/0x34cc, +0x34b8/0x34c4/0x34d0
- Multiplies by DAT_0059e440 (zero threshold / drag coeff) and fVar1
- Computes velocity residual: target velocity at +0x34f8/0x34fc/0x3500 minus drag from +0x3a58/0x3a5c/0x3a60 dampers
- Applies directional correction: if velocity positive subtracts, if negative adds force
- Accumulates forces to +0x354c/+0x3550/+0x3554 (force accumulator)
- Special case for Z-negative: applies cross-term from +0x3a70/+0x3a74 to Y-accumulator and +0x3558

**Globals:**
- `DAT_0059ed50` — speed scaling factor
- `DAT_0059e440` — zero threshold / drag coefficient

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x34b0–0x34d0 | float[9] | Suspension/strut force matrix (3×3) |
| +0x34f8–0x3500 | float[3] | Target body velocity |
| +0x3514 | float | Speed input |
| +0x354c–0x3554 | float[3] | Force accumulator |
| +0x3558 | float | Cross-term torque |
| +0x3a58–0x3a60 | float[3] | Damper coefficients |
| +0x3a64–0x3a74 | float[5] | Aero coefficients per axis |

**Moddability:** `configurable` — coefficients DAT_0059ed50, DAT_0059e440

---

## FUN_00434820 — MISSING

Source: docs/18-physics-dynamics.md

**Errors:**
- [MISSING_ENTRY] No `## FUN_` or `### FUN_` entry found in docs/18-physics-dynamics.md

**Corrected entry:**
<!-- target: docs/18-physics-dynamics.md -->
## FUN_00434820 — DynamicsModuleInit

Source: physics_dynamics.cpp. Initializes dynamics module, checks hardware capabilities.

**Key logic:**
- Calls FUN_00434860 (internal init)
- Calls FUN_0040c870 (hardware/capability check), stores at param_1 + 8
- Calls FUN_004348b0 (subsystem validation)
- If FUN_004348b0 == 0 (failure): calls FUN_0040cde0(5, 1) (error reporting), sets *param_1 = 1 (error flag), returns 0
- Returns 1 on success

**Calls:** FUN_00434860, FUN_0040c870, FUN_004348b0, FUN_0040cde0

**Moddability:** hardcoded

---

## FUN_00431BD0 — MISSING

Source: docs/18-physics-dynamics.md

**Errors:**
- [MISSING_ENTRY] No `## FUN_` or `### FUN_` entry found in docs/18-physics-dynamics.md

**Corrected entry:**
<!-- target: docs/18-physics-dynamics.md -->
## FUN_00431BD0 — DynamicsModuleDeinit

Source: physics_dynamics.cpp. Deinitialization thunk for dynamics module.

**Key logic:**
- Calls FUN_00587b3e (free/dealloc) with LAB_00431be0 pointer

**Calls:** FUN_00587b3e (memory free)

**Moddability:** hardcoded

---

## FUN_00438CC0 — MISSING

Source: docs/18-physics-dynamics.md

**Errors:**
- [MISSING_ENTRY] No `## FUN_` or `### FUN_` entry found in docs/18-physics-dynamics.md

**Corrected entry:**
<!-- target: docs/18-physics-dynamics.md -->
## FUN_00438CC0 — GearRatiosApply

Source: physics_dynamics.cpp. Applies gear ratio configuration from globals to vehicle struct.

**Key logic:**
- Reads 11 byte values from DAT_007ce6f4, DAT_007ce73c, etc. (gear ratio table globals)
- Stores to param_1+0x72 through +0x7c (11 gear ratio slots)
- Reads DAT_007ce874 (flag) and DAT_007ce88c (flag):
  - If DAT_007ce874 == 0: stores -(DAT_007ce88c != 0) & 2 at param_1+0x80 (reverse gear)
  - Else: stores (DAT_007ce88c != 0) * 2 + 1 at param_1+0x80
- Loops 11 elements, calls FUN_004b15d0(i) for each — if returns 0, clears gear at param_1+0x72+i
- If gear[2] (index 2) or gear[8] (index 8) non-zero: forces gear[1] = 2
- If gear[3] (index 3) non-zero: forces gear[4] (index 4) = 1
- Computes final drive ratio: param_1+0x9c = DAT_007ce934 * DAT_0059eb98 (double)

**Globals:**
- `DAT_007ce6f4`, `DAT_007ce73c`, `DAT_007ce7f0`, `DAT_007ce8a4` — gear ratio bytes
- `DAT_007ce850`, `DAT_007ce784`, `DAT_007ce7cc`, `DAT_007ce6ac` — gear ratio bytes
- `DAT_007ce718`, `DAT_007ce760`, `DAT_007ce7a8` — gear ratio bytes
- `DAT_007ce874`, `DAT_007ce88c` — reverse gear flags
- `DAT_007ce934` — final drive ratio coefficient
- `DAT_0059eb98` — final drive ratio multiplier

**Calls:** FUN_004b15d0 (gear validation)

**Moddability:** `configurable` — reads gear ratio globals from setup

---

## FUN_00449700 — MISSING

Source: docs/18-physics-dynamics.md

**Errors:**
- [MISSING_ENTRY] No `## FUN_` or `### FUN_` entry found in docs/18-physics-dynamics.md

**Corrected entry:**
<!-- target: docs/18-physics-dynamics.md -->
## FUN_00449700 — DynamicsJacobianUpdate

Source: physics_dynamics.cpp. Updates Jacobian matrix entries for constraint solver.

**Key logic:**
- If param_1[3] != 0: calls FUN_00448da0 (begin update)
- If param_1[4] != 0: calls FUN_00448da0 (begin update)
- For each element (0..*param_1): reads 3 pointers at param_1[2] + i*0x20 (stride 32 bytes)
  - Computes velocity delta: (*ptr3 + *ptr2) * DAT_0059e880 (stored at *ptr3+4)
  - Same for second and third pairs
- If param_1[4] != 0: calls FUN_00448de0 (end update)
- For each element: calls FUN_00448480 on pointer pairs (3 pairs per element)

**Globals:**
- `DAT_0059e880` — Jacobian scaling factor

**Calls:** FUN_00448da0, FUN_00448de0, FUN_00448480

**Moddability:** hardcoded

---

## FUN_004319C0 — MISSING

Source: docs/18-physics-dynamics.md

**Errors:**
- [MISSING_ENTRY] No `## FUN_` or `### FUN_` entry found in docs/18-physics-dynamics.md

**Corrected entry:**
<!-- target: docs/18-physics-dynamics.md -->
## FUN_004319C0 — DynamicsFlagSet

Source: physics_dynamics.cpp. Sets a dynamics flag/field indexed by param_2.

**Key logic:**
- param_1: vehicle struct
- param_2: index
- Stores param_3 at param_1 + 0x1cd8 + param_2 * 4 (flag array entry)
- Sets byte at param_1 + 0x1cd4 + param_2 = 1 (active flag)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x1cd4 | byte[?] | Active flags per index |
| +0x1cd8 | int[?] | Values per index |

**Moddability:** hardcoded

---

## FUN_00436470 — MISSING

Source: docs/18-physics-dynamics.md

**Errors:**
- [MISSING_ENTRY] No `## FUN_` or `### FUN_` entry found in docs/18-physics-dynamics.md

**Corrected entry:**
<!-- target: docs/18-physics-dynamics.md -->
## FUN_00436470 — SpringForceEval

Source: physics_dynamics.cpp. Evaluates spring force from quadratic coefficients.

**Key logic:**
- param_1: spring coefficient struct (6 doubles)
- param_2: displacement (double)
- Computes: out_X = param_2 * coeff[1] + param_2² * coeff[2] + coeff[0] (stored at +0x34)
- Computes: out_Y = param_2 * coeff[4] + param_2² * coeff[5] + coeff[3] (stored at +0x3c)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x00 | double | Constant term X |
| +0x08 | double | Linear term X |
| +0x10 | double | Quadratic term X |
| +0x18 | double | Constant term Y |
| +0x20 | double | Linear term Y |
| +0x28 | double | Quadratic term Y |
| +0x34 | double | Result X |
| +0x3c | double | Result Y |

**Moddability:** hardcoded

---

## FUN_0043FF3D — MISSING

Source: docs/18-physics-dynamics.md

**Errors:**
- [MISSING_ENTRY] No `## FUN_` or `### FUN_` entry found in docs/18-physics-dynamics.md

**Corrected entry:**
<!-- target: docs/18-physics-dynamics.md -->
## FUN_0043FF3D — ConstraintSolverSolve

Source: physics_dynamics.cpp. Main constraint solver — iterates to solve contact/joint constraints with line search.

**Key logic:**
- Complex iterative solver (600+ lines) with constraint types 0/1/2 from param_1+0x1e14
- Computes time step scaling from ST0 * DAT_0059ed10
- Three constraint groups (iVar11=0,1,2) each with different DOF layout:
  - Group 0: 2 bodies, reads from +0x368 stride 0x464
  - Group 1: 4 bodies, reads from +0x360 stride 0x464
  - Group 2: mixed 2+2 bodies
- For each group: computes Jacobian entries for each constrained DOF
- Checks if unaff_EBX (contact type flag) from FUN_00435290
- Inner loop: iterates constraint violations, computes lambda corrections
- Line search: finds min/max of 4 constraint lambda values using DAT_0059e430 bounds
- Accumulates position corrections: temp = temp + lambda * correction
- Detects convergence (all violations resolved) or contact breaking
- Applies impulses to body velocities at +0x14c/+0x154/+0x15c using mass matrix
- Computes contact force/torque distribution
- Uses DAT_0059ed20, DAT_0059ed08 for force scaling based on constraint type
- Uses FUN_005677b0 (timing/profiling marker)

**Globals:**
- `DAT_0059e430` — zero threshold / clamp bound
- `DAT_0059ed10` — time step scaling
- `DAT_0059ed20` — force scaling (groups 0,2)
- `DAT_0059ed08` — force scaling (group 1)

**Calls:** FUN_00435290, FUN_005677b0

**Moddability:** `configurable` — thresholds via physics constants

---

## FUN_004E3050 — MISSING

Source: docs/18-physics-dynamics.md

**Errors:**
- [MISSING_ENTRY] No `## FUN_` or `### FUN_` entry found in docs/18-physics-dynamics.md

**Corrected entry:**
<!-- target: docs/18-physics-dynamics.md -->
## FUN_004E3050 — ConstraintDataFree

Source: physics_dynamics.cpp. Frees 4 constraint data arrays in a vehicle struct.

**Key logic:**
- Loops 4 times with stride 0x4a * 4 (0x128 bytes between entries)
- For each iteration: zeroes piVar1[-1], frees *piVar1 if non-null via FUN_00587bcf, sets *piVar1 = 0
- Stride 0x4a * 4 = 296 bytes between entries in array

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x1f4 | int | Count/flag 0 (offset = 500 - 4) |
| +0x1f8 | int* | Data pointer 0 (offset = 500) |
| +0x320 | int | Count/flag 1 |
| +0x324 | int* | Data pointer 1 |
| +0x448 | int | Count/flag 2 |
| +0x44c | int* | Data pointer 2 |
| +0x570 | int | Count/flag 3 |
| +0x574 | int* | Data pointer 3 |

**Calls:** FUN_00587bcf (memory free)

**Moddability:** hardcoded

---

## FUN_004A3820 — MISSING

Source: docs/18-physics-dynamics.md

**Errors:**
- [MISSING_ENTRY] No `## FUN_` or `### FUN_` entry found in docs/18-physics-dynamics.md

**Corrected entry:**
<!-- target: docs/18-physics-dynamics.md -->
## FUN_004A3820 — WheelSteeringUpdate

Source: physics_dynamics.cpp. Computes wheel steering angles from input and geometry.

**Key logic:**
- Reads steering input *param_2, subtracts DAT_005acaf4 (steering offset)
- Computes scaled values: input * DAT_0059e450, input * DAT_0059e7f8, input * DAT_0059e7fc
- Loops through wheels (param_1+0xc count, stride 0x78):
  - For each wheel: reads sub-element count at +0x70, loops sub-elements (stride 0x1c)
  - Calls FUN_004a1fd0 to update steering geometry
  - Computes steering delta = (new_pos - old_pos) + base_pos

**Globals:**
- `DAT_005acaf4` — steering input offset/center
- `DAT_0059e450` — steering angle scale 1
- `DAT_0059e7f8` — steering angle scale 2
- `DAT_0059e7fc` — steering angle scale 3

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x0c | int | Wheel count |
| +0x10 | int* | Wheel array base |
| +0x70 (per wheel) | int | Sub-element count |
| +0x74 (per wheel) | byte* | Sub-element data (stride 0x1c) |

**Calls:** FUN_004a1fd0 (steering geometry update)

**Moddability:** `configurable` — steering scales via globals

---

## FUN_00569AD0 — MISSING

Source: docs/18-physics-dynamics.md

**Errors:**
- [MISSING_ENTRY] No `## FUN_` or `### FUN_` entry found in docs/18-physics-dynamics.md

**Corrected entry:**
<!-- target: docs/18-physics-dynamics.md -->
## FUN_00569AD0 — AngularMomentumUpdate

Source: physics_dynamics.cpp. Updates angular momentum with torque and cross-product.

**Key logic:**
- Adds param_3 (torque vector) to angular momentum at +0x134/+0x13c/+0x144
- Computes cross product: param_3 × param_2 (torque × force)
- Adds cross product result to angular impulse accumulator at +0x14c/+0x154/+0x15c

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x134 | double | Angular momentum X |
| +0x13c | double | Angular momentum Y |
| +0x144 | double | Angular momentum Z |
| +0x14c | double | Angular impulse accumulator X |
| +0x154 | double | Angular impulse accumulator Y |
| +0x15c | double | Angular impulse accumulator Z |

**Moddability:** hardcoded

---

## FUN_004C9D60 — MISSING

Source: docs/19-renderer.md

**Errors:**
- [MISSING_ENTRY] No `## FUN_` or `### FUN_` entry found in docs/19-renderer.md

**Corrected entry:**
<!-- target: docs/19-renderer.md -->
## FUN_004C9D60 — ParticleSpawnInit

Source: renderer/particle.cpp. Initializes particle position, velocity, rotation, and color with random jitter.

**Key logic:**
- Uses DAT_008aae70/DAT_008ab274 (random ring buffer) for all random values
- Computes 4 cumulative positions at param_1+0x10/+0x14/+0x18/+0x1c using jittered params * random coeffs
- If first segment length == 0: sets param_1+0x20 = 0, else computes inverse
- Same for last segment at +0x24
- Generates random color at +0x28 (float) + DAT_005ace90, stored as RGBA int at +0x60
- Random alpha at +0x68
- Generates random 3D direction vector at +0x48/+0x4c/+0x50, normalizes it
- Final random value stored at +0x54 (rand() & 0xf)

**Globals:**
- `DAT_008aae70` — random ring buffer counter
- `DAT_008ab274` — random value array
- `DAT_0059e7e8` — random scale factor
- `DAT_0059e86c` — color random scale
- `DAT_005ace90` — color offset
- `DAT_0059e440` — zero threshold
- `DAT_0059e43c` — 1.0 constant

**Moddability:** `configurable` — random coefficients tune particle spread

---

## FUN_004155D0 — MISSING

Source: docs/19-renderer.md

**Errors:**
- [MISSING_ENTRY] No `## FUN_` or `### FUN_` entry found in docs/19-renderer.md

**Corrected entry:**
<!-- target: docs/19-renderer.md -->
## FUN_004155D0 — RenderListFindByName

Source: renderer/object.cpp. Searches render list for an object by name string.

**Key logic:**
- param_1: render context with linked list of objects at +0x20, count at +0x2c
- param_2: name string to find
- Walks linked list @ param_1+0x20 (each node: [0]=data, [1]=next)
- For each node: calls FUN_00588410(strcmp) on name from node data, default DAT_005ea438 if null
- Returns index of matching node, or -1 if not found

**Calls:** FUN_00588410 (string compare)

**Moddability:** hardcoded

---

## FUN_00488B40 — MISSING

Source: docs/19-renderer.md

**Errors:**
- [MISSING_ENTRY] No `## FUN_` or `### FUN_` entry found in docs/19-renderer.md

**Corrected entry:**
<!-- target: docs/19-renderer.md -->
## FUN_00488B40 — FontCharCompare

Source: renderer/font.cpp. Compares two wide-character strings (UTF-16), triggers reload if different.

**Key logic:**
- param_1: font context with string pointer at +0x2c
- param_2: new wide string to compare
- Compares character-by-character (2-byte stride) against existing string (default DAT_005ea438 if null)
- If strings differ: calls FUN_00566650 (copy/free), then vtable +0x2c callback(1) to reload
- Returns 0 on success, 0xffffffff if param_2 is null

**Calls:** FUN_00566650, vtable +0x2c callback

**Moddability:** hardcoded

---

## FUN_0048D6B0 — MISSING

Source: docs/19-renderer.md

**Errors:**
- [MISSING_ENTRY] No `## FUN_` or `### FUN_` entry found in docs/19-renderer.md

**Corrected entry:**
<!-- target: docs/19-renderer.md -->
## FUN_0048D6B0 — FontTextureReload

Source: renderer/font.cpp. Reloads font texture from current character set.

**Key logic:**
- Calls FUN_00495790 (get current charset), stores at param_1[0x3b]
- If charset non-null: reads string at +0xc0, calls FUN_00488B40 to compare/load
- Triggers vtable +0x2c callback(1) for texture update

**Calls:** FUN_00495790, FUN_00488B40, vtable +0x2c

**Moddability:** hardcoded

---

## FUN_00497D20 — MISSING

Source: docs/19-renderer.md

**Errors:**
- [MISSING_ENTRY] No `## FUN_` or `### FUN_` entry found in docs/19-renderer.md

**Corrected entry:**
<!-- target: docs/19-renderer.md -->
## FUN_00497D20 — SceneObjectRegister

Source: renderer/scene.cpp. Registers a new scene object, adding to loaded object list.

**Key logic:**
- param_1: filename string to load
- Calls FUN_00497e80 (check if already loaded)
- If DAT_008ac4c4 (scene manager) non-null: calls vtable +0x44 to set path
- Builds path struct (local_18) with DAT_005ea438 as base
- Calls FUN_00566650 to copy filename into path
- Calls vtable +0x5c on manager to create object (0xf = type)
- If object created: calls new (0x58 bytes), copies filename, stores pointer chain
- Increments loaded count at unaff_EDI+0x110
- Cleans up old memory at unaff_ESI via FUN_00587bcf

**Globals:**
- `DAT_008ac4c4` — scene manager pointer
- `DAT_005ec400` — base path
- `DAT_005ea438` — default empty path

**Calls:** FUN_00497e80, FUN_00566650, FUN_00587bcf, operator_new

**Moddability:** hardcoded

---

## FUN_0057E280 — MISSING

Source: docs/19-renderer.md

**Errors:**
- [MISSING_ENTRY] No `## FUN_` or `### FUN_` entry found in docs/19-renderer.md

**Corrected entry:**
<!-- target: docs/19-renderer.md -->
## FUN_0057E280 — VideoPlaybackTick

Source: renderer/video.cpp. Updates video playback timer, triggers frame decode.

**Key logic:**
- Decrements timer at param_1[0x2aa] by param_2 (delta time)
- If timer <= 0: resets timer to 0x3e000000 (small positive), calls FUN_00585d20 (playback)
- If mutex handle at param_1[0x2b6] exists: calls WaitForSingleObject
- Calls vtable +0xa4 for frame count
- For each frame: calls FUN_0057b780 (decode init), vtable +0xac (decode frame)
- If frame type flags indicate keyframe: calls FUN_00587220 (check state), FUN_005871f0 + FUN_00585870 (render)
- Calls FUN_0057b7f0 (decode cleanup)
- Calls FUN_0057e3a0 (end of frame)
- Releases mutex if held

**Calls:** FUN_00585d20, WaitForSingleObject, FUN_0057b780, FUN_00587220, FUN_005871f0, FUN_00585870, FUN_0057b7f0, FUN_0057e3a0, ReleaseMutex

**Globals:** `DAT_0059e440` — zero threshold for timer

**Moddability:** hardcoded

---

## FUN_0051629F — MISSING

Source: docs/19-renderer.md

**Errors:**
- [MISSING_ENTRY] No `## FUN_` or `### FUN_` entry found in docs/19-renderer.md

**Corrected entry:**
<!-- target: docs/19-renderer.md -->
## FUN_0051629F — TextureMemoryAlloc

Source: renderer/texture.cpp. Allocates texture memory across all mip/format chains.

**Key logic:**
- param_1: texture context with surface chains at +0x40 (uncompressed) and +0x44 (compressed*0x80)
- First pass: computes total memory (iVar4) and max width (iVar3) from linked lists (stride 9, [0]=handle, [1]=width, [2]=height, [3]=bpp)
- Calls FUN_0051935c to allocate shared memory pool
- Calculates tile size: local_8 = max(1, min(allocated/total, 1000000000))
- For each surface: allocates via FUN_005160ad (uncompressed) or FUN_0051613f (compressed ×0x80)
- Sets surface[4] = actual allocated size, surface[5] = format from +0x4c
- Marks allocated surfaces with flag at +0x21=0, +0x22=1 (if tiled)

**Calls:** FUN_0051935c, FUN_00519361, FUN_005160ad, FUN_0051613f

**Moddability:** hardcoded

---

## FUN_0052E350 — MISSING

Source: docs/19-renderer.md

**Errors:**
- [MISSING_ENTRY] No `## FUN_` or `### FUN_` entry found in docs/19-renderer.md

**Corrected entry:**
<!-- target: docs/19-renderer.md -->
## FUN_0052E350 — MpegBitstreamRead

Source: renderer/mpeg.cpp. Reads MPEG bitstream data into decode buffer.

**Key logic:**
- param_1: MPEG decoder context
- param_2: input buffer
- param_3: bytes to read
- If buffer size at +0x249c == remaining at +0x24e8: calls FUN_0052df10 (decode full buffer)
  - On failure: zeroes buffer and logs "mpeg_fail_1" via FUN_00588821
  - Increments decoded count at +0x24e4
- Else: copies from internal ring buffer at +0x1244 (offset by +0x24e8)
  - If decode needed at buffer end: calls FUN_0052df10, zeros on failure, logs "mpeg_fail_2"
  - Copies (param_3 - iVar4) bytes, updates +0x24e8
- Returns total bytes read
- Updates +0x24b4 = (decoded_count - 1) * stride + remaining

**Calls:** FUN_0052df10, FUN_00588821 (log)

**Moddability:** hardcoded

---

## FUN_0051C6E1 — MISSING

Source: docs/19-renderer.md

**Errors:**
- [MISSING_ENTRY] No `## FUN_` or `### FUN_` entry found in docs/19-renderer.md

**Corrected entry:**
<!-- target: docs/19-renderer.md -->
## FUN_0051C6E1 — YUVtoRGBConvert

Source: renderer/colorspace.cpp. Converts YUV pixel data to RGBA using lookup tables.

**Key logic:**
- param_1: render context with +0x1a0 (YUV tables ptr), +0x5c (width), +0x11c (brightness)
- param_2: int[4] — {out_ptr, src_ptr, uv_ptr, ??}
- param_3: line offset
- param_5: row count
- For each pixel: reads Y, U, V components from source
- Computes RGBA: R = table[U][brightness - Y], G = table[V+Y][brightness - Y], B = table[V][brightness - Y], A = source mapping
- Writes 4 bytes per pixel (RGBA)
- Uses separate tables from iVar9/iVar10/iVar11/iVar6 for each component

**Moddability:** hardcoded

---

## FUN_004B6190 — MISSING

Source: docs/19-renderer.md

**Errors:**
- [MISSING_ENTRY] No `## FUN_` or `### FUN_` entry found in docs/19-renderer.md

**Corrected entry:**
<!-- target: docs/19-renderer.md -->
## FUN_004B6190 — PolygonSortSelect

Source: renderer/polygon.cpp. Selection sort for polygon rendering order (painter's algorithm).

**Key logic:**
- Loops 4 render layers (local_74 = 0..3)
- For each layer: collects up to 12 visible polygons via FUN_004b4840 and FUN_004b68c0
- If poly count >= DAT_005acd38 threshold: runs selection sort
- Sorts by depth using FUN_004b6360 comparator
- Calls FUN_004b4a30 to render sorted polygons
- DAT_005ef9a0[param_2 * 0x1230] gate check skips if -1

**Globals:**
- `DAT_005ef9a0` — layer enable flags
- `DAT_005acd38` — minimum poly count threshold for sorting

**Calls:** FUN_004b68c0, FUN_004b4840, FUN_004b4800, FUN_004b6360, FUN_004b4a30

**Moddability:** `configurable` — threshold via DAT_005acd38

---

## FUN_005383D0 — MISSING

Source: docs/19-renderer.md

**Errors:**
- [MISSING_ENTRY] No `## FUN_` or `### FUN_` entry found in docs/19-renderer.md

**Corrected entry:**
<!-- target: docs/19-renderer.md -->
## FUN_005383D0 — HuffmanTreeBuild

Source: renderer/huffman.cpp. Builds Huffman decoding tree from frequency data.

**Key logic:**
- param_1: symbol frequency array (0x1446 = count, 0x144a = 0x23d max nodes)
- param_2: int[3] — {symbols, output, frequency}
- Initializes leaf nodes from non-zero frequency symbols
- Pads to at least 2 leaf nodes by duplicating first if needed
- Runs heap-based Huffman tree construction:
  - Uses FUN_005385e0 (heap sift-down) for priority queue
  - Repeatedly extracts 2 min-frequency nodes, merges, inserts back
  - Tracks depth at +0x144e
  - Builds parent links at symbol+2
- Writes final Huffman codes via FUN_005386c0
- Calls FUN_005388d0 for table generation

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x1446 | int | Leaf node count |
| +0x144a | int | Max node index (0x23d) |
| +0x144e | byte[?] | Tree depth per node |
| +0xb32 | — | Code table output |
| +0xb52 | int[?] | Heap/node array |

**Calls:** FUN_005385e0, FUN_005386c0, FUN_005388d0

**Moddability:** hardcoded

---

## FUN_0050E9E6 — MISSING

Source: docs/19-renderer.md

**Errors:**
- [MISSING_ENTRY] No `## FUN_` or `### FUN_` entry found in docs/19-renderer.md

**Corrected entry:**
<!-- target: docs/19-renderer.md -->
## FUN_0050E9E6 — ColorTransformBlend

Source: renderer/colorspace.cpp. Applies color transform with blending and color keying.

**Key logic:**
- param_1: output float[3] color
- param_2: color transform matrix
- param_3: int[6] — {x, y, w, h, src_w, src_h} sizing
- param_4/5/6: optional blend matrices (3x3 each)
- Selects blend source via bitmask of non-null param_4/5/6:
  - 0: identity matrix (diagonal 1.0)
  - 1-7: multiplies selected matrices via thunk_FUN_0050cba3
- Applies transform via thunk_FUN_0050c5b0
- If param_3 non-null: applies color keying:
  - X: x + w * (color[0] + 1.0) * scale
  - Y: y + h * (1.0 - color[1]) * scale
  - Z: (src_h - src_w) * color[2] + src_w

**Globals:**
- `DAT_0059e43c` — 1.0 constant
- `DAT_0059e450` — scale factor
- `DAT_005adb14` — 65536.0 (int-to-float for fixed-point)

**Calls:** thunk_FUN_0050cba3 (matrix multiply), thunk_FUN_0050c5b0 (transform apply)

**Moddability:** hardcoded

---

## FUN_00561970 — MISSING

Source: docs/19-renderer.md

**Errors:**
- [MISSING_ENTRY] No `## FUN_` or `### FUN_` entry found in docs/19-renderer.md

**Corrected entry:**
<!-- target: docs/19-renderer.md -->
## FUN_00561970 — BitmapFillRect

Source: renderer/bitmap.cpp. Fills a rectangular region with a 16-bit color value.

**Key logic:**
- param_1: line direction (negative = reverse stride)
- param_2: row count
- param_3/4: step values (positive/non-negative)
- param_5: row stride
- param_6: column start
- param_7: fill color (uint16)
- param_8: buffer base
- Fills rows of 16-bit pixels with specified color

**Moddability:** hardcoded

---

## FUN_00556040 — MISSING

Source: docs/19-renderer.md

**Errors:**
- [MISSING_ENTRY] No `## FUN_` or `### FUN_` entry found in docs/19-renderer.md

**Corrected entry:**
<!-- target: docs/19-renderer.md -->
## FUN_00556040 — TextureConfigUpdate

Source: renderer/texture.cpp. Updates texture configuration from render state.

**Key logic:**
- param_1: texture object (array of ints)
- param_2: render state struct
- Checks flags at param_2+0x19c & 0xe0000:
  - If 0: disables texture (param_1[0x53c]=0), calls vtable +200 with 0x1c
  - If non-zero: extracts 24-bit ID from shorts at +0x188/+0x18a/+0x18c
    - If ID changed: calls vtable+200(0x22, ID) to set texture
  - Syncs 4 float params: +0x194, +0x198, +0x190, +400 (UV scale/offset)
  - Maps flags (0x20000→3, 0x40000→1, 0x80000→2)
  - Checks param_1[0x4ea] & 0x4000 for texture type, calls vtable+200 with appropriate command

**Calls:** vtable +200 (set parameter)

**Moddability:** hardcoded

---

## FUN_005076E2 — MISSING

Source: docs/19-renderer.md

**Errors:**
- [MISSING_ENTRY] No `## FUN_` or `### FUN_` entry found in docs/19-renderer.md

**Corrected entry:**
<!-- target: docs/19-renderer.md -->
## FUN_005076E2 — RenderObjectDestructor

Source: renderer/object.cpp. Render object destructor with optional memory free.

**Key logic:**
- Calls FUN_00506ccc (base destructor)
- If param_2 & 1: calls FUN_00587bcf (operator delete) on param_1

**Calls:** FUN_00506ccc, FUN_00587bcf

**Moddability:** hardcoded

---

## FUN_004FC170 — MISSING

Source: docs/19-renderer.md

**Errors:**
- [MISSING_ENTRY] No `## FUN_` or `### FUN_` entry found in docs/19-renderer.md

**Corrected entry:**
<!-- target: docs/19-renderer.md -->
## FUN_004FC170 — ObjectTintColorUpdate

Source: renderer/object.cpp. Updates tint color for an object and its associated meshes/effects.

**Key logic:**
- Computes uVar1 = ROUND(param_2 * DAT_0059fec8) * 0x10101 (RGB from float 0..1)
- If tint changed: collects up to 16 render node pointers:
  - Base object at param_1[0]
  - Shadow object at param_1[4]
  - Nodes from param_1[0x12] count array at param_1[0x13]
  - Nodes from param_1[0x1f] count array at param_1[0x20]
- For each node: updates color via particle system
  - Calls FUN_0054c230(0) then FUN_0054e100 + FUN_0054e120 to iterate sub-objects
  - Sets each sub-object's +0x18 color: (original & 0xff000000) | uVar1
  - Clears bit at +0x14 & 0xefffffff (update flag)

**Globals:**
- `DAT_0059fec8` — tint intensity scale

**Calls:** FUN_0054c230, FUN_0054e100, FUN_0054e120

**Moddability:** `configurable` — tint scale via DAT_0059fec8

---

## FUN_0053EAD0 — MISSING

Source: docs/19-renderer.md

**Errors:**
- [MISSING_ENTRY] No `## FUN_` or `### FUN_` entry found in docs/19-renderer.md

**Corrected entry:**
<!-- target: docs/19-renderer.md -->
## FUN_0053EAD0 — TextureObjectRelease

Source: renderer/texture.cpp. Releases texture object and associated resources.

**Key logic:**
- Calls FUN_0053f270(0) (release shared state)
- If param_1[0x54b] non-null: calls FUN_0053f6e0 then FUN_00557470 + FUN_00587bcf to free
- Same for param_1[0x549] and param_1[0x54a] (3 texture layers)
- If param_1[0x440] (D3D interface) non-null: calls vtable+8 release, zeros pointer

**Calls:** FUN_0053f270, FUN_0053f6e0, FUN_00557470, FUN_00587bcf

**Moddability:** hardcoded

---

## FUN_0048D3A0 — MISSING

Source: docs/19-renderer.md

**Errors:**
- [MISSING_ENTRY] No `## FUN_` or `### FUN_` entry found in docs/19-renderer.md

**Corrected entry:**
<!-- target: docs/19-renderer.md -->
## FUN_0048D3A0 — FontCharMapInit

Source: renderer/font.cpp. Initializes font character map object.

**Key logic:**
- Calls FUN_00485e30 and FUN_004883a0 (base init)
- Sets param_1[0x3d] = param_2 (char set ID)
- Sets *(param_1+0x3c) = 0 (flags)
- Sets *(param_1+0xf1) = 0 (unknown byte)
- Sets *param_1 = vtable PTR_FUN_005ac118
- Sets param_1[0x3e] = param_3 (texture ID)

**Calls:** FUN_00485e30, FUN_004883a0

**Moddability:** hardcoded

---

## FUN_00557630 — MISSING

Source: docs/19-renderer.md

**Errors:**
- [MISSING_ENTRY] No `## FUN_` or `### FUN_` entry found in docs/19-renderer.md

**Corrected entry:**
<!-- target: docs/19-renderer.md -->
## FUN_00557630 — TextureFlagCheck

Source: renderer/texture.cpp. Checks texture flags and triggers async load if needed.

**Key logic:**
- Reads flags at param_1+0x20
- If flag & 8 (uncompressed): checks & 0x400 (load needed)
  - If load needed: calls FUN_0047abb0
- If !flag & 8 (compressed): checks & 0x400
  - If load needed: calls FUN_00558990
- If load function returns 0: clears flag & 0xfffffbff, returns 0
- If load succeeds: returns 0xffffffff

**Calls:** FUN_00558990, FUN_0047abb0

**Moddability:** hardcoded

---

## FUN_0049E760 — MISSING

Source: docs/19-renderer.md

**Errors:**
- [MISSING_ENTRY] No `## FUN_` or `### FUN_` entry found in docs/19-renderer.md

**Corrected entry:**
<!-- target: docs/19-renderer.md -->
## FUN_0049E760 — RandomDrawConditional

Source: renderer/effect.cpp. Conditional draw based on random parity check.

**Key logic:**
- Calls __ftol (float-to-int), checks if result is even (bit 0 clear)
- If even: calls FUN_00543440 with color 0xffff0000 (red)

**Calls:** __ftol, FUN_00543440

**Moddability:** hardcoded

---

## FUN_005619AF — MISSING

Source: docs/19-renderer.md

**Errors:**
- [MISSING_ENTRY] No `## FUN_` or `### FUN_` entry found in docs/19-renderer.md

**Corrected entry:**
<!-- target: docs/19-renderer.md -->
## FUN_005619AF — BitmapFillRectStrided

Source: renderer/bitmap.cpp. Fills a rectangular region with stride-aware addressing.

**Key logic:**
- Similar to FUN_00561970 but uses param_8 as output stride instead of fixed 1
- Fills rows of 16-bit pixels with specified color at param_9 + param_6 * 2
- Supports forward/backward line stepping via param_1 sign

**Moddability:** hardcoded

---

## FUN_00479600 — PASS

Existing entry verified correct.

---

## Batch Math Utilities (3970-3999) — MISSING

All in docs/20-math-utilities.md. No existing `## FUN_` entries. See subagent output files for full entries:

### FUN_00563870 — FileReadMultipart
### FUN_00595135 — BitRemap
### FUN_00582780 — RingBufferInit
### FUN_00583430 — LinkedListRemove
### FUN_0058928F — strtol_base
### FUN_005890AA — qsort_partition
### FUN_0056068E — ColorSpaceConvert565
### FUN_005959A0 — CloseHandleById
### FUN_005033A5 — D3DTextureCopyRect
### FUN_00404F70 — ObjectDeinitFree
### FUN_004B9F70 — WeatherEffectStateInit
### FUN_0054FCA0 — FieldSetInt
### FUN_00404460 — AudioPlaybackStateMachine
### FUN_00466A30 — SomeObjectConstructor
### FUN_00486710 — GetFlagAtOffset100
### FUN_004A0010 — RegisterInitCallback
### FUN_004D4A20 — DelegateTo4D4A50
### FUN_00513C38 — MemoryCompare
### FUN_0054FCB0 — SetOffset80
### FUN_00561ACF — MemsetWords
### FUN_0040FB00 — ObjectInitZero
### FUN_00471540 — SessionManagerConstructor
### FUN_00497250 — SetByteAtOffset25
### FUN_004BB6B0 — LinkedListRemoveNode
### FUN_00500F55 — RecursiveTreeDestructor
### FUN_0053C6B0 — StringCopy
### FUN_00599475 — Gninc (MSVC streambuf)
### FUN_0045B3E0 — DestructorWithDealloc
### FUN_004B2A10 — BitfieldSetNibble
### FUN_0053D450 — DelegateTo55C9C0

Detailed entries in: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\cross_validate\batch_math_1.md
And: %USERPROFILE%\Desktop\F1C_ghidra_project\analysis_pipeline\output\cross_validate\batch_math_2.md

---

## Batch Math Utilities (4000-4111) — MISSING

All in docs/20-math-utilities.md. No existing `## FUN_` entries. See subagent output files.

### FUN_0057BCC0 — DestructorWithDealloc
### FUN_0041FB10 — SessionTypeDetector
### FUN_00476D70 — VtableDispatchProcessor
### FUN_004972B0 — RectangleBorderDraw
### FUN_004BAC40 — LinkedListSortedInsert
### FUN_004F87C0 — EffectParameterSetter
### FUN_00543210 — ReorderedParamDelegate
### FUN_0059AD31 — RegisterTeardownCallback
### FUN_0047CA30 — RandomDrivenProcess
### FUN_0045BEA0 — AVICleanupDestructor
### FUN_00495970 — GetIntAtOffset24
### FUN_004BA180 — MenuStateDispatch
### FUN_004F2B10 — ZeroInit16Words
### FUN_005265DB — Matrix4x4MultiplySSE
### FUN_0056C740 — Matrix3x3MultiplyDouble
### FUN_0059D290 — UnwindHandler
### FUN_0045D4C0 — TwoCharStringCheck
### FUN_004861A0 — ConditionalArrayOps
### FUN_0049D3F0 — ColorSelectRender
### FUN_004CE820 — StructInit_15elems
### FUN_0051EA5A — FillFromVtable
### FUN_005997CB — Wrapper_00599958
### Unwind_0059D4D8 — UnwindHandler
### FUN_00457CD0 — ZeroInit_7elems
### FUN_0047B1B0 — ObjectResetAndCall
### FUN_00499DA0 — RecursiveTreeDelete
### FUN_004C2C40 — ExponentialMovingAverage
### FUN_00501992 — DXTTextureDecompress
### FUN_0053BDE0 — Dot4Scaled
### FUN_0058A65F — ConditionalDelegate
### FUN_0059B5C0 — BitArrayAlloc
### FUN_004BBF70 — RingBufferShift
### FUN_00567940 — FreeTwoPtrs
### FUN_00410AF0 — RemoveSwapArray
### FUN_0046FF40 — Destructor_VtableFree
### FUN_00491680 — RectIntersectClamp
### FUN_004B3DB0 — IdentityPassthrough
### FUN_004DD4C0 — FreeSinglePtr
### FUN_005179A2 — CallbackInvoker
### FUN_0055C2A0 — ListAppend
### FUN_0058BEF0 — CharPosRender
### FUN_0059525D — BitArrayClearAndQuery
### FUN_005179E0 — AllocatorSetup
### FUN_004F8C00 — AuthCheck
### FUN_004B5040 — BufferInit
### FUN_004988D0 — FindAndDelete
### FUN_00478690 — ConditionalVtableCall
### FUN_00421A90 — DoubleDelegate
### FUN_004D5C50 — StaticInit_4d5c60
### FUN_0050F6F7 — StateMachineRender
### FUN_005491D0 — LinkedAllocNode
### FUN_0059163B — ConditionalMathDispatch
### FUN_0059A418 — Streambuf_Gninc (MSVC)
### FUN_00410B60 — Wrapper_0040ed10
### FUN_00471B20 — Constructor_InitDefaults
### FUN_00491EE0 — AudioDeviceInit
### FUN_004B52A0 — BucketListRehash
### FUN_004E0D70 — ConditionalRelease
### FUN_0051AD93 — AudioChannelValidate
### FUN_005676C0 — FloatFloorSplit
### FUN_0058A935 — MSVC_malloc
### FUN_0041ED20 — FieldGetter_Indexed
### FUN_00475570 — ConditionalSystemUpdate
### FUN_004963C0 — FlagSetter_28
### FUN_004BA820 — ZeroInit_4elems
### FUN_004F6B80 — StaticInit_4f6b90
### FUN_0052803A — AllocDelegate
### FUN_0057A160 — Constructor_VtableSet
### FUN_005830C0 — AllocWithException
### FUN_00423060 — FieldGetter_c4
### FUN_00479320 — OverlapDetect
### FUN_00498D70 — Destructor_CondFree

Full details in batch_math_1.md and batch_math_2.md

---

## Audio/Network Functions (4112-4121) — MISSING

All in docs/21-audio-network-internals.md. No existing `## FUN_` entries.

### FUN_00560FE0 — AudioPanningUpdate

Source: audio/mixer.cpp. Updates 3D audio panning based on listener position and orientation.

**Key logic:**
- Reads position from param_1+0x18 chain (+0x138→+0x40→+0x230→+0x28)
- Computes panning angle using fpatan with DAT_005b8998 and DAT_005dd848
- Branches on flag at param_1+0x24 & 4 for primary/secondary path
- If sub-flag at +0x13c == 0: calls FUN_0054b420 (direct pan), else FUN_0054b950 (surround pan)
- Calls FUN_00541d10, FUN_00541b70(0xe), FUN_00541a70 for DSP apply
- Recursive call to self if param_1+0x2c or +0x34 non-null

**Calls:** FUN_0055c9b0, FUN_00542560, FUN_005457c0, FUN_0055d590, FUN_00542050, FUN_005423c0, FUN_0054b420, FUN_0054b950, FUN_00541d10, FUN_00541b70, FUN_00541a70, FUN_0055c070, FUN_00540240

**Globals:** DAT_005b8998, DAT_005dd848

---

### FUN_0057BCE0 — VideoPlaybackCleanup

Source: network/video.cpp. Video playback object destructor — closes handles and releases subsystems in reverse order.

**Key logic:**
- Sets vtable to PTR_LAB_005b8a68
- Closes 8 handles (mutexes/events) at offsets +0x2fb, +0x2f0, +0x2e5, +0x2da, +0x2cf, +0x2cb, +0x2c4, +0x2bd
- Calls cleanup functions in sequence: FUN_0057e530, FUN_0057fbe0, FUN_00582dc0, FUN_00582ce0, FUN_00582a10, FUN_00582650, FUN_00581a80 (×2), FUN_005819c0, FUN_00582310 (×2), FUN_00581880, FUN_005822b0, FUN_00499ae0, FUN_00583ae0
- Returns vtable to PTR_LAB_005b8a00 at end

---

### FUN_00580DE0 — VideoFrameDecode

Source: network/video.cpp. Decodes a video frame with mutex synchronization and async I/O.

**Key logic:**
- Uses SEH exception handling
- Calls vtable+0xd0 to validate/decode frame
- Calls vtable+0x58 to get buffer, FUN_00586800 for DMA setup
- Uses mutex at param_1[0x2b6] with WaitForSingleObject
- Walks linked list of frame buffers at param_1+0x2b2 (doubly-linked, stride 3 ints)
- On keyframe (FUN_00587220 returns 2): sets frame flag, calls FUN_0057b6c0
- Removes matching buffer from list, releases via vtable destructor
- Calls FUN_00587200/FUN_00587230 for buffer processing loop
- After decode: calls FUN_00585d20 (playback state check)
- On state 4: reinitializes buffer via FUN_00586a00

**Calls:** FUN_005871f0, FUN_00587220, FUN_0057b6c0, FUN_00587bcf, FUN_00587200, FUN_00587230, WaitForSingleObject, ReleaseMutex, FUN_00585d20, FUN_00586800, FUN_00586a00, FUN_0057d8d0, FUN_0057b780, FUN_0057b7f0

---

### FUN_00513482 — AudioSampleGenerator

Source: audio/synth.cpp. Generates audio samples using frequency-domain synthesis.

**Key logic:**
- If param_1+0x130 (sample rate) != 0:
  - If +0x117 (quality) < 9: generates 256 samples via linear fill
  - Else: computes bit allocation from +0x150-0x153 (4-byte quality flags)
  - Allocates quantization tables via FUN_00517e92
  - Uses sub-band coding with 8 - bVar2 bit shift
  - Two modes based on +0x60 flags & 0x480:
    - Mode 0: direct sample allocation with __ftol + FUN_005881f0
    - Mode 1: sample-and-hold with quantization + Huffman-like packing
  - Fills remaining table with 0xffff sentinel values

**Calls:** FUN_00517e92, FUN_005881f0, __ftol

**Globals:** DAT_0059e430

---

### FUN_004C7CA0 — NetworkLobbyScan

Source: network/lobby.cpp. Scans for network game sessions and builds lobby list.

**Key logic:**
- If DAT_008acfcc (network active) != 0: calls FUN_0054c110(7, 0x1000) (broadcast query)
- Iterates through available sessions from DAT_008afe88
- For each session: calls FUN_0054c150 (alloc 0x1000 buffer), FUN_004c9a50 (create session object)
- Calls FUN_004c8f80 to validate session
- Allocates linked list node (0xc bytes) to store session pointer
- Manages doubly-linked list at +0xc in session struct

**Globals:** DAT_008acfcc, DAT_008afe88

**Calls:** FUN_0054c110, FUN_005452f0, FUN_00545340, FUN_0054c150, FUN_004c9a50, FUN_004c8f80, operator_new

---

### FUN_00582110 — NetworkSocketInit

Source: network/socket.cpp. Initializes network socket address structure.

**Key logic:**
- Sets sockaddr_in struct: AF_INET (2), address 0 (INADDR_ANY), port 0
- Calls htonl/htons for network byte order
- Initializes second address struct similarly
- Calls FUN_0057b530 (socket init)
- Zeroes 10 dword fields, sets param_1[8] = 0xffffffff, zeros rest

**Calls:** htonl, htons, FUN_0057b530

---

### FUN_00598672 — sendto (WinSock wrapper)

Source: network/socket.cpp. Direct thunk to Winsock sendto().

**Key logic:**
- Thunk to sendto() system call

---

### FUN_0057A420 — NetworkDeviceCreate

Source: network/device.cpp. Creates network device instance.

**Key logic:**
- Validates param_2[0] (device index) in range [0,1]
- Allocates 0xbf8-byte block via operator_new
- Calls FUN_0057ba10 to initialize device from config
- On failure: calls vtable+0x44(1) cleanup, zeros output param_1

**Calls:** operator_new, FUN_0057ba10

---

### FUN_00406750 — AudioStreamRelease

Source: audio/stream.cpp. Releases audio stream and playback resources.

**Key logic:**
- If param_1+0xc (stream handle) != 0: calls AIL_close_stream, zeros handle
- If param_1+0x5c (timer ID) != -1: calls FUN_00406a70 (timer release)
- Calls FUN_004080b0 to check remaining resources
- If resources remain: calls FUN_00405630 (cleanup)

**Calls:** AIL_close_stream, FUN_00406a70, FUN_004080b0, FUN_00405630

---

### FUN_0050E302 — NetworkCallbackDispatch

Source: network/callback.cpp. Dispatches network callback.

**Key logic:**
- Calls FUN_0050fea7(1) (set callback state)
- Calls indirect function pointer from DAT_005d787c

**Calls:** FUN_0050fea7, (*DAT_005d787c)() indirect

---


