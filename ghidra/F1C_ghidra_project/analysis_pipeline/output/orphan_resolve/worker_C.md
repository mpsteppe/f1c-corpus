=== ORPHAN CLASSIFICATIONS ===
| address | classification | confidence | evidence | suggested_caller |
|---------|---------------|------------|----------|-----------------|
| 0x004059f0 | game_logic_isolated | MEDIUM | Audio sample reset via Miles Sound System API (_AIL_end_sample_4/_AIL_init_sample_4). Reads sample handle from param_1+0x58/+0x10. No cross-refs found, but references game audio subsystem state. Likely called indirectly during audio resource cleanup. | — |
| 0x0044c620 | game_logic_isolated | MEDIUM | Sets DAT_007ca490=1 (CollisionCellInitCount) and adjacent fields. Pattern: type/size ID + zero init + float constant. Other similar collision init functions (FUN_0044dca0, etc.) suggest an init table array. No cross-refs. | — |
| 0x0044cbc0 | game_logic_isolated | MEDIUM | Sets DAT_007cd188=0x69 (CollisionShape_105) and adjacent fields including 0xbf800000 (-1.0f). Same init-table pattern as sibling functions. | — |
| 0x0044d160 | game_logic_isolated | MEDIUM | Sets DAT_007ccf70=0x6c (CollisionConfigBlock) and adjacent fields, last field = 0x3f800000 (1.0f). Same init-table pattern. | — |
| 0x0044d700 | game_logic_isolated | MEDIUM | Sets DAT_007ccc98=0x16 (CollisionCountInit) and 5 zeroed fields. Same init-table pattern. | — |
| 0x0044dca0 | game_logic_isolated | MEDIUM | Sets DAT_007ccea0=0x32 (CollisionStateBlockType) and 5 zeroed fields. Same init-table pattern. | — |
| 0x0044e240 | game_logic_isolated | MEDIUM | Sets DAT_007cd1d8=0x49 and 5 fields, DAT_007cd1ec=27000. Same init-table pattern with int value. | — |
| 0x0044e7e0 | game_logic_isolated | MEDIUM | Sets DAT_007cd080=0x58, 4 zeroed fields, DAT_007cd094=18000 (CollisionRangeThreshold). Same init-table pattern. | — |
| 0x0044efc0 | vtable_member | MEDIUM | __thiscall struct copy: copies 0x91 dwords (0x244 bytes) from stack to param_1+8, sets param_1+0x278=param_2. Collision struct copy assignment operator. Called via virtual dispatch when copying collision objects. | — |
| 0x004780b0 | game_logic_isolated | HIGH | Queries factory via DAT_007cd8c0+0x1c(0x15) (GameCommandDispatchInterface). Stores result at param_1+0xe0. Same pattern as FUN_00477280 (docs/06+docs/10) which also calls DAT_007cd8c0+0x1c factory. Called during vehicle/physics object setup. | FUN_00477280 (same factory pattern, docs/06) |
| 0x0048d380 | vtable_member | MEDIUM | __thiscall bounds-checked setter. Sets param_1+0x338=param_2 if 0<=param_2<param_1+0x328. Container class index setter, likely virtual method on array/vector-like struct. | — |
| 0x004a40b0 | vtable_member | MEDIUM | Empty stub (1-byte ret). VTable placeholder for interface method not implemented in this class. | — |
| 0x0050c15e | utility_isolated | HIGH | Hermite/cubic spline interpolation. Pure math: computes cubic polynomial from 4 control points + parameter t. References _DAT_0059e450 etc. (float constants). No game logic globals. | — |
| 0x0050d748 | utility_isolated | HIGH | Axis-angle to 4x4 rotation matrix. Pure math: computes sin/cos of angle, constructs 3x3 rotation matrix from unit axis, returns 4x4 homogeneous matrix. Calls thunk_FUN_0050c2a6 (vector normalize). | — |
| 0x0050ff84 | game_logic_isolated | MEDIUM | State init with virtual calls. Uses unaff_ESI (this ptr), calls vtable methods at +0x4 and +0x0. Sets byte array pattern {0,1,5} across 0x10 entries. Sets fields at ESI+0x42, ESI+0x40, ESI+0x101, ESI+0x106, ESI+0x107. Type-specific initialization. | — |
| 0x00528bd0 | vtable_member | MEDIUM | Empty stub (232 bytes? but body is just `return`). VTable placeholder. Size 232 suggests compiler-generated padding for alignment. | — |
| 0x0053bde0 | utility_isolated | HIGH | 4-element dot product with scaling: `result = DAT_0059e440 * param_2[0] + param_1[2]*param_2[1] + param_1[1]*param_2[2] + param_1[0]*param_2[3]`. Pure vector math. | — |
| 0x005608f6 | utility_isolated | HIGH | Surface/pixel copy with color-key transparency handling. Copies 2D regions with optional skip of matching color (DAT_005dd804 = color key). Handles aligned and unaligned copies. No game logic globals (only DAT_005dd804 = color key value). | — |
| 0x00586d70 | utility_isolated | HIGH | Bitmap bit test: reads bitmap bits from texture region, returns mask of set bits. Pure renderer utility. | — |
| 0x0058a947 | entry_point | HIGH | `__nh_malloc` — MSVC CRT allocation (Visual Studio 2003 Release). Called by operator new/new[] internally. Registered in CRT allocation chain. | Any C++ allocation |
| 0x00595733 | entry_point | HIGH | `__amsg_exit(2)` — MSVC CRT runtime error exit. Called by CRT assertion/error handler on fatal errors. | CRT assertion handler |
| 0x00598678 | entry_point | HIGH | `connect()` import thunk to ws2_32.dll. Winsock API import — called by any networking code using connect(). | Any networking code |
| 0x0059aaa2 | vtable_member | MEDIUM | Empty stub (1-byte ret). VTable placeholder. | — |
| 0x0059c9f0 | entry_point | HIGH | SEH unwind handler. Calls FUN_0057b7f0. Registered in exception handling table (.pdata) for automated stack unwinding during C++ exception propagation. | SEH exception frame |
| 0x0059d1a8 | entry_point | HIGH | SEH unwind handler — release locale refcount (calls FUN_00599796 with locale handle DAT_008d4370). Registered in .pdata for locale object cleanup during exception unwinding. | SEH exception frame |
| 0x0059d5bc | entry_point | HIGH | SEH unwind handler — destructs exception object during stack unwinding (calls exception::~exception). Registered in .pdata. | SEH exception frame |

=== FULL ENTRIES ===

<!-- target: docs/17-physics-collision.md -->
## FUN_0044c620 — CollisionCellInit

Source: collision_init.cpp. Initializes first collision cell block in global collision state table.

**Key logic:**
- Sets DAT_007ca490 = 1 (cell/item count = 1)
- Zeros 3 adjacent dwords (DAT_007ca494, DAT_007ca498, _DAT_007ca49c)
- Sets _DAT_007ca49c = 0x3f800000 (1.0f — float unit constant)
- Part of collision init function table: each similar function initializes one block with type ID + data

**Globals:**
- DAT_007ca490 — collision cell initial count
- DAT_007ca494–DAT_007ca49c — adjacent cell data fields

**Calls:** none (leaf)

**Moddability:** `hardcoded`

<!-- target: docs/17-physics-collision.md -->
## FUN_0044cbc0 — CollisionShape105Init

Source: collision_init.cpp. Initializes collision shape block with type 0x69 (105).

**Key logic:**
- Sets DAT_007cd188 = 0x69 (105 = collision shape/index ID)
- Zeros 2 adjacent dwords
- Sets _DAT_007cd18c = 0, _DAT_007cd190 = 0xbf800000 (-1.0f), _DAT_007cd194 = 0
- -1.0f suggests a "disabled" or "no-collision" sentinel

**Globals:**
- DAT_007cd188 — collision shape/index 0x69
- _DAT_007cd190 — float sentinel = -1.0f

**Calls:** none (leaf)

**Moddability:** `hardcoded`

<!-- target: docs/17-physics-collision.md -->
## FUN_0044d160 — CollisionConfigBlockInit

Source: collision_init.cpp. Initializes config block with type 0x6C (108).

**Key logic:**
- Sets DAT_007ccf70 = 0x6C (block type/size identifier)
- Zeros 2 adjacent dwords
- Sets last field = 0x3f800000 (1.0f — unit/default float)

**Globals:**
- DAT_007ccf70 — collision configuration block
- _DAT_007ccf7c — float unit constant

**Calls:** none (leaf)

**Moddability:** `hardcoded`

<!-- target: docs/17-physics-collision.md -->
## FUN_0044d700 — CollisionCount22Init

Source: collision_init.cpp. Initializes count block with type 0x16 (22).

**Key logic:**
- Sets DAT_007ccc98 = 0x16 (22 = count/type ID)
- Zeros 5 adjacent dwords (DAT_007ccc9c through _DAT_007cccac)

**Globals:**
- DAT_007ccc98 — collision count init (22)
- DAT_007ccc9c–_DAT_007cccac — zeroed fields

**Calls:** none (leaf)

**Moddability:** `hardcoded`

<!-- target: docs/17-physics-collision.md -->
## FUN_0044dca0 — CollisionState32Init

Source: collision_init.cpp. Initializes state block with type 0x32 (50).

**Key logic:**
- Sets DAT_007ccea0 = 0x32 (50 = state block type)
- Zeros 5 adjacent dwords (DAT_007ccea4–_DAT_007cceb4)

**Globals:**
- DAT_007ccea0 — collision state block type 0x32
- DAT_007ccea4–_DAT_007cceb4 — zeroed fields

**Calls:** none (leaf)

**Moddability:** `hardcoded`

<!-- target: docs/17-physics-collision.md -->
## FUN_0044e240 — CollisionAntiRollInit

Source: collision_init.cpp. Initializes block with type 0x49 (73) and int value 27000.

**Key logic:**
- Sets DAT_007cd1d8 = 0x49 (73 = block type)
- Zeros 3 adjacent dwords
- Sets DAT_007cd1ec = 27000 (collision range/force limit)
- 27000 suggests a force threshold or distance limit

**Globals:**
- DAT_007cd1d8 — block type 0x49
- DAT_007cd1ec — limit value 27000

**Calls:** none (leaf)

**Moddability:** `hardcoded`

<!-- target: docs/17-physics-collision.md -->
## FUN_0044e7e0 — CollisionRangeThresholdInit

Source: collision_init.cpp. Initializes block with type 0x58 (88) and range 18000.

**Key logic:**
- Sets DAT_007cd080 = 0x58 (88 = block type)
- Zeros 4 adjacent dwords
- Sets DAT_007cd094 = 18000 (collision range threshold, matches DAT_007CD0DC = CollisionRangeThreshold in docs/12)

**Globals:**
- DAT_007cd080 — block type 0x58
- DAT_007cd094 — range threshold 18000

**Calls:** none (leaf)

**Moddability:** `hardcoded`

<!-- target: docs/17-physics-collision.md -->
## FUN_0044efc0 — CollisionStructCopy

Source: collision_copy.cpp. Copy constructor or assignment operator for collision struct.

**Key logic:**
- __thiscall: param_1 = this, param_2 = source struct reference
- Sets param_1+0x278 = param_2 (store reference)
- Copies 0x91 dwords (0x244 bytes) from stack (source) to param_1+8
- 0x91 × 4 = 580 bytes of data copied — large collision data block

**Struct offsets:**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x8 | CollisionData | 0x244 bytes, start of copied data |
| +0x278 | SourceRef | stored source reference |

**Calls:** none (leaf, memcpy-like loop)

**Moddability:** `hardcoded`

<!-- target: docs/10-vehicle-physics.md -->
## FUN_004780b0 — PhysicsObjectFactoryQuery

Source: setup.cpp. Queries game object factory for physics/vehicle resource handle.

**Key logic:**
- Calls virtual method at `*DAT_007cd8c0 + 0x1c` with argument 0x15 (21 — resource type ID)
- If result non-null: stores at param_1 + 0xe0
- Returns 0
- Same factory pattern as FUN_00477280, FUN_00476ec0 (docs/06, docs/09)

**Globals:**
- DAT_007cd8c0 — GameCommandDispatchInterface (factory/manager object with vtable)

**Calls:** Virtual dispatch: (*DAT_007cd8c0 + 0x1c)(0x15)

**Moddability:** `hardcoded` — resource type 0x15

<!-- target: docs/20-math-utilities.md -->
## FUN_0048d380 — BoundsCheckedIndexSetter

Source: container.cpp. Virtual setter method on indexed container class.

**Key logic:**
- __thiscall: param_1 = this, param_2 = index
- Checks: 0 <= param_2 < *(param_1 + 0x328) (count/bounds)
- If valid: stores param_2 at param_1 + 0x338 (current/active index)

**Struct offsets (param_1 — container):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x328 | ElementCount | upper bound for index |
| +0x338 | CurrentIndex | stored active/selected index |

**Calls:** none (leaf)

**Moddability:** `hardcoded`

<!-- target: docs/20-math-utilities.md -->
## FUN_0050c15e — HermiteSplineInterpolation

Source: math_spline.cpp. Hermite/cubic spline interpolation between 4 control points.

**Key logic:**
- Input: param_1-Point5 = control points, param_6 = interpolation parameter t in [0,1]
- Computes cubic Hermite basis functions from t, t², t³
- Mixes 4 control points using Hermite basis: H00(t), H10(t), H01(t), H11(t)
- Scales result by DAT_0059e450 (global constant)
- Output: param_1[0] = x, param_1[1] = y (2D spline)

**Globals:**
- _DAT_0059e450 — global scale (0.5f halving)
- _DAT_0059e800, _DAT_0059e478, _DAT_0059e7ec, _DAT_0059e46c — Hermite basis coefficients

**Calls:** none (leaf)

**Moddability:** `hardcoded`

<!-- target: docs/20-math-utilities.md -->
## FUN_0050d748 — AxisAngleToRotationMatrix

Source: math_transform.cpp. Converts axis-angle representation to 4x4 homogeneous rotation matrix.

**Key logic:**
- Input: param_2 = unit axis (3 floats), param_3 = angle in radians
- Computes cos(angle), sin(angle)
- Rodrigues' rotation formula: R = I + sin(θ)[k]× + (1-cos(θ))(k⊗k)
- Output: 4x4 matrix (16 floats) at param_1, with homogeneous row [0,0,0,1]
- Calls thunk_FUN_0050c2a6 for vector normalization

**Calls:** thunk_FUN_0050c2a6 (vector normalize)

**Moddability:** `hardcoded`

<!-- target: docs/20-math-utilities.md -->
## FUN_0053bde0 — Scaled4ElementDotProduct

Source: math_vector.cpp. Computes dot product of two 4-element vectors with zero-threshold scaling.

**Key logic:**
- Computes: `DAT_0059e440 * param_2[0] + param_1[2]*param_2[1] + param_1[1]*param_2[2] + param_1[0]*param_2[3]`
- DAT_0059e440 = ZeroThreshold (~0.0f) — scales first term near zero
- Non-standard element ordering (2,1,0): likely quaternion or plane equation dot product

**Globals:**
- DAT_0059e440 — ZeroThreshold (physics clamp constant)

**Calls:** none (leaf)

**Moddability:** `hardcoded`

<!-- target: docs/19-renderer.md -->
## FUN_00586d70 — BitmapBitRegionTest

Source: renderer_bitmap.cpp. Tests set bits in a bitmap texture region, returns mask.

**Key logic:**
- Reads width from param_1+0x1c, offset from param_1+0x38
- Iterates over uVar2 pixels in a row
- For each pixel: checks if bit at (pixel index) >> 3 in bitmap data at param_1+0x14 is set
- Returns bitmask of set pixel positions as uint

**Struct offsets (param_1 — bitmap):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x14 | BitmapData | byte array of bitmap bits |
| +0x1c | Width | width in pixels |
| +0x38 | Offset | row/scanline offset into data |

**Calls:** none (leaf)

**Moddability:** `hardcoded`

<!-- target: docs/20-math-utilities.md -->
## FUN_005608f6 — SurfaceCopyWithColorKey

Source: gfx_copy.cpp. 2D surface copy with optional color-key transparency (skip matching pixels).

**Key logic:**
- Copies 2D region: param_7 = width per row, param_8 = row count, param_4/param_6 = stride adjustments
- If DAT_005dd804 == 0xFFFF AND aligned (width*2 & 7 == 0): fast aligned 8-byte copy path
- Else: per-pixel copy with color-key test — skips pixels where value == DAT_005dd804 (transparent color)
- Returns concatenated params

**Globals:**
- DAT_005dd804 — color key value (0xFFFF = transparent sentinel)

**Calls:** none (leaf, inline copy)

**Moddability:** `hardcoded`
