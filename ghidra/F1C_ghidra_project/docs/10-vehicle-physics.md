# Vehicle Physics - hdvehicle, Suspension, Scene
## FUN_004f2c60 - Per-Wheel Brake/Suspension Data Loader
### FUN_004f2c60 — Per-Wheel Brake/Suspension Data Loader

Triggered by the string `"BrakeFailure"` as a section header — but the function loads the entire brake and suspension block for one wheel corner. Called 4× by `FUN_004f4270`.

**Wheel struct offsets (relative to wheel base pointer):**

| Offset | Field | Notes |
|--------|-------|-------|
| +0x00 | BumpTravel | |
| +0x08 | ReboundTravel | |
| +0xb0 | BrakeTorque | |
| +0xb8 | BrakeOptimumTemp | **+273.15 K offset applied at load** (same as OilTemp) |
| +0xf0 | BrakeWearRate | |
| +0xf8 | BrakeFailure (min) | |
| +0x100 | BrakeFailure (max) | |

Suspension sub-fields also loaded: BumpStop, Rebound, Camber, Pressure, RideHeight, Packer, Spring, Dampers, BrakeDisc, BrakePad ranges.

BrakeOptimumTemp is stored in Kelvin internally. The `.svm` value (Celsius) has +273.15 added at load, matching the same pattern as `LifetimeOilTemp`.

---

## FUN_004dfce0 - Vehicle Graphics Scene Loader
### FUN_004dfce0 — Vehicle Graphics Scene Loader

Source: vehgfx.cpp [ida:fact] (vehicle geometry file). Loads `.gen` vehicle scene file and maps
mesh names to scene node indices. NOT physics — graphics/scene setup only.

Mesh name → struct offset mapping (param_1, int-indexed):

| Offset | Mesh Name |
|--------|-----------|
| +0x51 | LFTIRE |
| +0x62 | LFSPINDLE |
| +0x9b | RFTIRE |
| +0xac | RFSPINDLE |
| +0xe5 | LRTIRE |
| +0xf6 | LRSPINDLE |
| +0x12f | RRTIRE |
| +0x140 | RRSPINDLE |
| +0x179 | FWING (front wing) |
| +0x18a | RWING (rear wing) |
| +0x19b–+0x247 | DEBRIS0–7 (8 debris meshes, stride 0x11) |
| +0x223 | COCKPIT |
| +0x224 | SUSPENSION |
| +0x225 | HELMET |
| +0x226 | (unnamed, DAT_005c674c) |
| +0x227 | (unnamed, DAT_005d4d64) |
| +0x228 | WHEEL |
| +0x229 | RAINLIGHT |
| +0x22a | BRAKELIGHT |
| +0x22b | HEADLIGHT |
| +0x22c | BACKFIRE |

Also reads `TREAD`, `TREADMED`, `TREADLOW` texture names into globals
(`DAT_008ad3ec`, `DAT_008ad3f0`, `_DAT_008ad3f4`).

**Not moddable.** Documents vehicle scene structure only.

---

## hdvehicle.cpp - Full Module Analysis (4 new functions)
### hdvehicle.cpp — Full Module Analysis (4 new functions)

#### FUN_00439210 — Vehicle Physics Initializer (889 lines)

Source: `hdvehicle.cpp`. Core vehicle physics setup. Computes:
1. Inertia tensor from wheel positions and masses
2. Mass distribution (center of mass, principal axes)
3. Wheel position vectors relative to CoG
4. Suspension geometry initialization
5. Tire compound application (calls FUN_0043da10)
6. Steering geometry (calls FUN_0043b040)
7. Aero/drag setup (calls FUN_004390a0)

**Vehicle struct offsets (param_1):**
| Offset | Field |
|--------|-------|
| +0x1f00 | vehicle data pointer (→ +0x8c8 = wheel array, stride 0x4a×4 bytes) |
| +0x1d4 | physics body pointer |
| +0x15f0 | main body pointer |
| +0x141c | attached/aero body pointer |
| +0x3ec | wheel struct array (stride 0x464, 4 wheels) |
| +0x15ac | suspension body count |
| +0x15b0 | suspension body array |
| +0x15b4 | suspension link count (stride 0x30) |
| +0x15b8 | suspension link array |
| +0x15bc | steering link count (stride 0x48) |
| +0x15c0 | steering link array |
| +0x15c4 | steering bar count (stride 0x48) |
| +0x15c8 | steering bar array |
| +0x15f4 | total mass |
| +0x15fc | center of mass (3 doubles) |
| +0x1614–0x1624 | CoG offset (3 doubles) |
| +0x1428–0x1430 | aero data |
| +0x1448 | front aero downforce |
| +0x1450 | rear aero downforce |
| +0x1dfc | reference position (3 doubles) |

**Physics body struct (at body pointer):**
| Offset | Field |
|--------|-------|
| +0x04 | position (3 doubles: x, y, z) |
| +0x1c–0x5c | orientation matrix (3×3 doubles) |
| +0xac | mass |
| +0xb4 | 1/mass (reciprocal) |
| +0xbc–0xcc | inertia diagonal |

**Globals used:**
- `DAT_007ce958` — tire model mode flag (nonzero = alternate grip scaling)
- `DAT_007c569c` — session type (5 = dedicated server, suppresses warnings)
- `_DAT_0059e880` = 0.5 (halving constant)
- `_DAT_0059ea58` = gravity constant
- `_DAT_0059e420` = 1.0

**Not directly moddable** (physics sim core), but documents the vehicle
struct layout for cross-referencing with other functions.

#### FUN_0043af50 — Suspension Bar Lookup

Helper for FUN_00439210. Finds suspension bar by name, returns 3D position vector
via matrix transform of bar attachment point.

#### FUN_0043b040 — Front Steering Geometry Setup

Source: `hdvehicle.cpp`. Only supports independent 5-link front suspension.
Sets up steering links for FL (fl_steering) and FR (fr_steering) wheels.

Reads steering bar names, finds matching links in steering bar array
(param_1 + 0x15c8, stride 0x48), computes steering geometry vectors.

Assert: "Sorry, only support independent 5-link front suspensions right now"
if steering link count != 8 (4 per side).

#### FUN_0043da10 — Tire Compound → Per-Wheel Physics Application

Source: `hdvehicle.cpp`. Applies tire compound data (from .tbc via FUN_004d7570)
to per-wheel physics struct. This is where .tbc compound fields become physics values.

**Per-wheel physics struct base:** `param_1 + wheel_index × 0x464 + 0x28c`

| Offset | Field | Source | Transform |
|--------|-------|--------|-----------|
| +0x20c | tire grip param 1 | compound +0x24 | raw |
| +0x210 | tire grip param 2 | compound +0x24 | raw |
| +0x214 | tire grip param 3 | compound +0x28 | raw |
| +0x218 | tire grip param 4 | compound +0x2c | raw |
| +0x21c | camber factor 1 | compound[6] | × _DAT_0059ec68 |
| +0x224 | camber factor 2 | compound[6] | × _DAT_0059ec60 |
| +0x22c | load sensitivity | computed | FUN_004d6ae0 |
| +0x234 | grip multiplier | compound +0x48 | raw |
| +0x238 | grip multiplier 2 | compound +0x4c | raw |
| +0x278 | tire radius min | compound +0x00 | raw |
| +0x280 | tire width | compound[0] - compound[2] | computed |
| +0x288 | tire radius max | compound +0x08 | raw |
| +0x290 | tire width 2 | compound[1] - compound[3] | computed |
| +0x2d8 | slip curve 1 ptr | compound +0x130 | FUN_004d75d0 lookup |
| +0x2dc | slip curve 2 ptr | compound +0x138 | FUN_004d75d0 lookup |
| +0x2e0 | slip curve 3 ptr | compound +0x140 | FUN_004d75d0 lookup |
| +0x2e4 | load normalization | computed | 1.0 / (sum × _DAT_0059ec58) |
| +0x2f4 | optimum camber | compound[0x13] | raw |
| +0x2fc | camber sensitivity | compound[0x15] | × _DAT_0059ec50 |
| +0x304 | camber factor | computed | _DAT_0059e898 / camber (if camber > 0) |
| +0x30c | camber slope | computed | _DAT_0059e890 / (max_camber - opt_camber) |
| +0x334 | optimum temp | compound[0x23] | + _DAT_0059eac8 (273.15 K) |
| +0x34c–0x378 | camber sensitivity table | hardcoded | 0x8f5c28f6 / 0x40767dc2 pattern |
| +0x384 | base grip | compound +0x38 | raw |
| +0x388 | grip factor | compound +0x3c | raw |
| +0x38c | sens factor | compound +0x40 | raw |
| +0x390 | sens factor 2 | compound +0x44 | raw |
| +0x394–0x398 | wear init | 0 / 1.0 | hardcoded |
| +0x3cc | wear rate | compound[0x1c] | × DAT_007d0c60 × load_norm |

**Globals:**
- `DAT_007ce958` — tire model mode (nonzero → scales grip by _DAT_0059ec48)
- `DAT_007d0c60` — global tire wear multiplier (runtime)
- `_DAT_0059eac8` = 273.15 (C→K)
- `_DAT_0059e898` = 90.0 (camber angle limit, degrees)
- `_DAT_0059e890` = related camber constant

**Moddability:** Documents how .tbc compound fields map to physics.
The `DAT_007d0c60` global tire wear multiplier is a runtime variable that scales
all tire wear — potentially set by game options or difficulty.

---

## FUN_00435410 - Suspension Setup Section Reader

Source: vehload.cpp or hdvehicle.cpp. Reads suspension section from setup file.

**Suspension fields read:**
- SpringParams — spring rate parameters
- SpringCollLen — spring coil/collapsed length
- SpringBody — spring body attachment
- SpringHead — spring head attachment
- SpringDir — spring direction vector
- FREEDAMPING — free damping coefficient
- NORMAL — normal damping coefficient
- SLIDING — sliding friction coefficient

**Struct (param_1, relative to wheel base):**
Multiple 8-byte double values read per field. Provides per-corner suspension tuning data.

Not moddable — suspension fine-tuning data from setup file.

---

## FUN_00438da0 - Vehicle Physics Body Name Mapping

Source: hdvehicle.cpp. Maps physics body names to vehicle struct offsets using FUN_0056ead0 (scene node name lookup).

**Body name to struct offset mapping:**
| Body Name | Vehicle Struct Offset |
|-----------|----------------------|
| fl_steering | param_1+0x1630 |
| fr_steering | param_1+0x1644 |
| fl_wheel | param_1+1000 (0x3e8) |
| fl_spindle | param_1+0x3ec |
| fr_wheel | param_1+0x84c |
| fr_spindle | param_1+0x850 |
| rl_wheel | param_1+0xcb0 |
| rl_spindle | param_1+0xcb4 |
| rr_wheel | param_1+0x1114 |
| rr_spindle | param_1+0x1118 |
| rear_axle | param_1+0x141c |
| fuel_tank | param_1+0x1d4 |
| driver_head | param_1+0x1e8 |

Also allocates suspension body array (param_1+0x162c, stride 0x30, count from param_1+0x15ac) and main body pointer (param_1+0x15f0).

---

## FUN_004f3240 - Suspension Force Validation

Source: vehload.cpp [ida:fact]. Validates suspension/damage force direction per axis. Called 6 times per wheel corner (2 directions × 3 axes).

For each axis direction (param_3 0-5), validates that force is applied in the correct direction:
- param_3 0: +x force when moving in +x (must be > 0)
- param_3 1: +x force when moving in -x (must be < 0)
- param_3 2: +y force when moving in +y (must be > 0)
- param_3 3: +y force when moving in -y (must be < 0)
- param_3 4: +z force when moving in +z (must be > 0)
- param_3 5: +z force when moving in -z (must be < 0)

Reads 3 doubles at stride 0x18: force_x, force_y, force_z (or similar linear/damper coefficients).

If validation fails and not dedicated server (DAT_007c569c != 5): displays assert warning via FUN_004d7a50.

Not moddable — physics data validation only.

---

## FUN_004f3090 - Fender/Aero Setup Section Reader

Source: vehload.cpp. Reads fender flare aero setup per wheel.

**Fields read:**
- FenderCenter — center position (3 doubles)
- FenderDragParams — drag coefficient params (3 doubles)
- FenderLiftParams — lift coefficient params (3 doubles)
- FenderSideways — sideways force coefficient (single double)
- FenderFlareRange / FenderFlareSetting — range/setting pair

Sets param_1[0] = 1 (fender active) if FenderCenter is present.

**Fender struct (param_1):**
| Offset | Field |
|--------|-------|
| +0x00 | active flag |
| +0x04–0x14 | Drag params (3 doubles) |
| +0x1c–0x2c | Lift params (3 doubles) |
| +0x34 | Sideways coefficient |
| +0x3c–0x4c | Center position (3 doubles) |
| +0x54 | Flare setting |

---

## FUN_0056d930 — Vehicle Physics Joint System Loader

Source: physics/scene file parser (vehgf or physics module). Reads a text-format file containing BODY, JOINT, HINGE, BAR, and JOINT_HINGE sections. Allocates arrays of body, joint, hinge, and bar structs, populating body name, position, orientation, and inertia data.

**Key logic:**
- First pass: counts BODY/JOINT/HINGE/BAR/JOINT_HINGE tokens in file
- Allocates four parallel arrays: bodies (stride 0x244), joints (stride 0x30), hinges (stride 0x30), bars (stride 0x48)
- Second pass: parses each section:
  - **BODY**: reads name string, position (3 doubles), orientation quaternion (4 doubles), inertia tensor (3 doubles for diagonal + 3 for off-diagonal), transform matrix
  - **JOINT/HINGE**: reads `negbody` (negative body ref), `posbody` (positive body ref), `inertia` (joint inertia override), name string, position, orientation
  - **BAR**: reads same fields as JOINT + additional spring/damper params
- Resolves body references: searches named bodies, validates no duplicate names, links +0x22c (joint count), +0x234 (hinge count), +0x23c (bar count) per body
- Post-process: calls FUN_00569860/FUN_005698e0/FUN_00569990 on each joint/hinge/bar to compute derived spring/damper/tension values
- Final: allocates and initializes constraint matrix (size param_1[8]), solves via iterative solver (FUN_00579f89)

**Struct offsets (param_1 header):**
| Offset | Field |
|--------|-------|
| +0x00 | Body count |
| +0x04 | Body array pointer (stride 0x244) |
| +0x08 | Joint count |
| +0x0c | Joint array pointer (stride 0x30) |
| +0x10 | Hinge count |
| +0x14 | Hinge array pointer (stride 0x30) |
| +0x18 | Bar count |
| +0x1c | Bar array pointer (stride 0x48) |
| +0x20 | Constraint count |
| +0x24 | Constraint matrix pointer |
| +0x28 | Constraint row stride pointer |
| +0x2c | Solver object pointer |

**Body struct (+0x00 in array, stride 0x244):**
| Offset | Field |
|--------|-------|
| +0x00 | Name string pointer |
| +0x04–0x1c | Position quaternion (4 doubles) |
| +0x20–0x34 | Inertia diagonal (3 doubles) |
| +0x38–0x48 | Inertia off-diagonal (3 doubles) |
| +0x4c–0x64 | Transform matrix (4x4?) |
| +0x22c | Joint reference count |
| +0x234 | Hinge reference count |
| +0x23c | Bar reference count |
| +0x228 | (per-body data pointer) |
| +0x224 | (per-body aux pointer) |

**Joint/Hinge struct (stride 0x30):**
| Offset | Field |
|--------|-------|
| +0x00 | Name string pointer |
| +0x04 | Negative body pointer |
| +0x08 | Derived value (spring/tension) |
| +0x0c | Positive body pointer |
| +0x10 | Derived value (spring/tension) |
| +0x14–0x28 | Position/orientation (6 doubles) |
| +0x2c | Joint index / link counter |

**Calls:** FUN_0056e970 (init), FUN_0058986e (error log), FUN_00534b00 (file open), FUN_005351d0 (tokenizer next), FUN_005651b0 (line read), FUN_00587c20 (token match), FUN_00565520 (field parse), FUN_00565aa0 (vector parse), FUN_00588410 (string compare), FUN_00568e30/FUN_00568e70 (body init), FUN_005691d0/FUN_00569280 (matrix ops), FUN_005697f0 (body finalize), FUN_00569860/FUN_005698e0/FUN_00569990 (joint/hinge/bar solver), FUN_0056d430 (constraint count), FUN_0056cf70/FUN_0056d020/FUN_0056d2d0 (sub-system solve), FUN_0056d880 (matrix init), FUN_00579f89 (iterative solver), FUN_0056c830 (matrix factor), FUN_005355a0 (close file)

**Moddability:** No — internal physics engine joint system, no file fields.

---

## FUN_0043b590 — Steering Geometry Computation

Source: hdvehicle or suspension module. Computes steering geometry parameters for front wheels (left and right). Uses suspension control arm positions to derive steering angles and wheel alignment.

**Key logic:**
- Reads suspension hardpoint positions via FUN_0043af50:
  - `fl_steering` (left front steering axis, param_1 + 0x3ec)
  - `fr_steering` (right front steering axis, param_1 + 0x850)
- Computes steering rack displacement via FUN_004361d0
- Reads rack travel + ratio from param_2 + 0x1430/0x1438/0x1444
- Computes effective steering ratio:
  - If travel ≤ 0: disables steering (sets +0x8c/+0x90 = 0)
  - Otherwise: ratio = 1.0 / travel
- Computes steering ratio reduction (param_2[0x1440] - 1 gears)
- Reads fore/upper and fore/lower control arm positions:
  - Left: `fl_fore_upper` (`param_1 + 0x3ec`), `fl_fore_lower`
  - Right: `fr_fore_upper` (`param_1 + 0x850`), `fr_fore_lower`
- Computes control arm vectors and normalizes
- Computes scrub radius and steering axis inclination (camber gain) via cross products
- Stores results:
  - param_1 + 0x1634–0x1638: left steering axis direction
  - param_1 + 0x1648–0x164c: right steering axis direction
  - param_1 + 0x163c: left scrub radius / camber gain
  - param_1 + 0x1650: right scrub radius / camber gain
  - param_1 + 0x8c–0x90: steering ratio (if enabled)
  - param_1 + 0x84–0x88: steering ratio reduction
  - param_1 + 0x94: steering angle max
  - param_1 + 0xa4–0xa8: flags

**Struct offsets (param_1):**
| Offset | Field |
|--------|-------|
| +0x3ec | Left wheel suspension data pointer |
| +0x850 | Right wheel suspension data pointer |
| +0x8c | Steering ratio (double) |
| +0x84 | Steering ratio reduction (double) |
| +0x94 | Max steering angle |
| +0xa4–0xa8 | Flags |
| +0x1630 | Left rack position pointer |
| +0x1634–0x1638 | Left steering axis (double pair) |
| +0x1644 | Right rack position pointer |
| +0x1648–0x164c | Right steering axis (double pair) |
| +0x163c | Left scrub radius / camber gain |
| +0x1650 | Right scrub radius / camber gain |

**Struct offsets (param_2):**
| Offset | Field |
|--------|-------|
| +0x1430 | Steering rack travel intercept |
| +0x1438 | Steering rack travel slope |
| +0x1440 | Steering reduction gear count |
| +0x1444 | Speed-sensitive steering multiplier |

**Calls:** FUN_0043af50 (suspension hardpoint reader), FUN_004361d0 (rack displacement)

**Moddability:** No — pure physics geometry, no file fields.

---

## FUN_00430f00 — Vehicle Stats Estimation Display (ACCEL/TOP SPEED/CORNERING)

Source: vehicle setup screen. Computes and formats estimated acceleration, top speed, and cornering performance values for the vehicle setup display. Uses physics simulation (FUN_00430a50, FUN_00430750) to compute estimates based on current aero/engine/tire setup.

**Key logic:**
- Copies label strings to `DAT_005ec4cc` (MessageBuffer) for display
- Clears 3 format buffers at param_1 + 0x1b26, +0x1b26+0x80, +0x1b26+0x100
- If `DAT_007d0474` (metric/imperial flag) == 0: 
  - Uses scale factor 100, conversion constant 0x40465a1c (≈44.7 MPH→km/h?)
  - Label "EST. ACCEL" from DAT_005c3f64
- If `DAT_007d0474` != 0:
  - Uses scale factor 150, conversion constant 0x4044d555 (≈44.0?)
  - Label "EST. ACCEL (mph)" from DAT_005c3f68
- Formats `"%s (0-%d %s)%s"` with label, max value, unit, category
- Iterates acceleration simulation loop calling FUN_00430a50 repeatedly until velocity exceeds threshold
- Writes formatted 0-60/0-100 time with `"%.2f %s"` format
- Writes `"EST. TOP SPEED"` label and computed top speed value
- Computes top speed by iterating FUN_00430a50 until acceleration ≈ 0
- Calls FUN_00430750(0, 0x4052c000 ≈ 74.5) to estimate cornering G-force
- Writes `"EST. CORNERING"` label and G-force value
- All writes via FUN_0058815f to param_1 buffer offsets (+0x19a6 through +0x1c26)

**Globals used:**
- `DAT_007d0474` — metric/imperial flag

**Calls:** FUN_00430a50 (acceleration simulation), FUN_00430750 (cornering simulation), FUN_00423a00 (string copy), FUN_0058815f (format/print)

**Moddability:** No — display-only vehicle stats estimation, no file fields.

---

## FUN_00449a80 — HAT Polygon Surface Fit (Gaussian Elimination)

Source: htree.cpp [ida:fact]. Solves a 6-coefficient quadratic surface fit over 3 control points for HAT (Height Above Terrain) polygon mesh generation. Used to compute terrain height maps for track surfaces.

**Key logic:**
- Reads 3 control point groups (each with 6 float parameters: x, y, z, value, flags)
- Computes edge vectors between points (cross/dot for orientation)
- Bubble-sorts edge lengths to order control points by distance
- Builds 6x6 linear system (Gaussian elimination matrix) from point positions and values
- Solves for 12 coefficients (a0–a5, b0–b5) defining the surface polynomial
- On first failure: retries with relaxed constraints
- On second failure: returns identity (zero coefficients) and logs warning
- Validates fit error per point against threshold (`_DAT_0059ea08`)

**String refs:**
- `"Gaussian elimination for HAT poly failed once"` (warning, first retry)
- `"Gaussian elimination for HAT poly failed twice"` (error, identity fallback)

**Calls:** FUN_004ce8d0 (type conversion), FUN_005677b0 (Gaussian solver)

**Moddability:** No — terrain mesh generation math, no file fields.

---

## FUN_0059d822 / FUN_0059d8ab — Gear 7–10 Setup Field Readers

Source: `vehload.cpp`. Two functions reading Gear7Setting through Gear10Setting fields.

- **FUN_0059d822** (16 lines): Reads Gear7/8/9/10Setting field names via FUN_00565760 (field name registration/validation), then calls FUN_004f61d6.
- **FUN_0059d8ab** (16 lines): Reads same fields via FUN_0042e1f0 (setup adjustment reader) with range [0, 0x3ff00000), same pattern as Gear1–6Setting in existing docs.

**Setup fields:**
| Field | Range |
|-------|-------|
| Gear7Setting | [0, 0x3ff00000) |
| Gear8Setting | [0, 0x3ff00000) |
| Gear9Setting | [0, 0x3ff00000) |
| Gear10Setting | [0, 0x3ff00000) |

**Calls:** FUN_00565760 (field name read), FUN_0042e1f0 (setup adjust read), FUN_004f61d6 (post-process), FUN_004f6300 (post-process)

**Moddability:** Yes — **moddable field.** Gear7–10Setting extend the known setup field list. These are `.svm` or setup file fields for extra gear ratios (6-speed + reverse was standard F1, gear 7–10 may be unused or for future/alternate gearing). Range [0, 0x3ff00000) matches gear 1–6 pattern.

---

## FUN_0044be70 — HTree Terrain File Format Loader

Source: `htree.cpp`. Reads a compiled terrain height/vertex file with header `"Ver 0.06 This file is automatically generated"`.

**Format:**
1. 46-byte header: checks for version string at offset 0
2. 8 chars: field A (param_1+2)
3. 8 chars: field B (param_1+4)
4. 8 chars: field C (param_1+6)
5. 8 chars: field D (param_1+8)
6. 4 bytes: vertex count (local_70, stride 0x5c)
7. 4 bytes: face count (local_74, stride 0x10)
8. 4 bytes: edge count (local_78, stride 0x10)

**Allocations:**
- Vertex array: `operator_new(vertex_count * 0x5c)` → param_1[0]
- Face array: `operator_new(face_count * 0x10 + 4)` → param_1[1], stride 0x10, constructor FUN_0044a430
- Edge array: `operator_new(edge_count * 0x10)` → local_4, each edge: 4 bytes + 8 bytes + 4 bytes

If face_count > 0, calls FUN_0044a700 for face processing.

**Calls:** FUN_005668b0 (file open), FUN_00566b20 (file check), FUN_00566c00 (binary read), FUN_0044a430 (face constructor), FUN_0044a700 (face processor), FUN_00587bcf (free), FUN_00566b90 (close), FUN_005668d0 (file cleanup)

**Moddability:** No — compiled terrain binary format loader, no file fields.

---

## FUN_0040b850 — Main View / Tracking Camera Scene Loader

Source: camera/scene module. Reads MAINVIEW and TRACKINGCAM camera definitions from scene file. Same pattern as FUN_00408e20 but for two fixed camera types.

**Key logic:**
- Opens scene file, reads up to 0x80 (128) camera definitions via FUN_004585e0
- Each definition is a 0xd0 (208) byte camera struct
- Allocates camera array: `operator_new(count * 0xd0 + 4)`, stride 0xd0
- Calls FUN_00459330 per camera for post-init setup
- Struct +0x04: camera count from FUN_00544f50
- Struct +0x0c: camera array pointer
- Struct +0x10: camera count
- Struct +0x14: current index (0 on init)

**Calls:** FUN_005881c0 (init), FUN_005668b0 (open file), FUN_00544f50 (camera count), FUN_00566b20 (check file), FUN_00566cc0 (tokenizer), FUN_005651b0 (line read), FUN_00565520 (field read), FUN_004585e0 (camera init), FUN_004583b0 (camera alloc), FUN_00459330 (camera setup), FUN_005668d0 (close)

**Moddability:** No — camera system setup.

---

## FUN_00447d00 — Brake Bias Adjustment Control

Source: vehicle setup / driver controls (setup.cpp or similar). Driver-adjustable brake bias control with HUD display. Increments/decrements brake bias index and displays `"%s %4.1f:%4.1f"` format.

**Key logic:**
- param_2 < 0: decrements brake bias index, clamped to 0
- param_2 > 0: increments brake bias index, clamped to max (param_1+0x157c)
- Computes actual bias: `index * slope + intercept` at param_1 + 0x1564
- Displays via FUN_0045bd10: `"BRAKE BIAS %4.1f:%4.1f"` (rear:front split)

**Struct offsets (param_1):**
| Offset | Field |
|--------|-------|
| +0x1564 | Computed brake bias (double) |
| +0x156c | Bias intercept (double) |
| +0x1574 | Bias slope (double) |
| +0x157c | Max bias index (int) |
| +0x1580 | Current bias index (int) |

**Calls:** FUN_0045bdf0 (clear display), FUN_00423a00 (string copy), FUN_0058815f (format), FUN_0045bd10 (HUD write)

**Moddability:** Yes — **moddable field.** Brake bias is a setup field (.svm or setup file). Confirms bias is computed as `index * slope + intercept` with display format showing rear:front split. Slope and intercept could be mod-controlled for varied brake behavior.

---

## FUN_0042f470 — Vehicle Setup Value Formatter

Source: setup/garage UI. Formats vehicle setup parameter values for display in the garage setup screen. Dispatches by param_2 index to format each setup type (gears, suspension, alignment, etc.).

**Key logic:**
- Setup parameter array at param_1 + 0xbb0, stride 0x40 per entry, indexed by param_2
- Each entry: base (double at +0x00), multiplier (double at +0x08), count (int at +0x10), value (int at +0x14), format name (string at +0x18), flags at +0x1c
- **case 0:** Unknown/empty parameter — displays "Unknown [name]"
- **case 1–2:** Ratio format `"%.1f/%.1f"` (e.g., gear ratios)
- **case 3:** Steering lock — formats as `"X turns"` from rotation angle
- **case 4, 0x34–0x36:** Gear ratio display — formats with count-dependent precision, handles `"bevel"` gear string, auto/manual flag at param_1 + 4
- **case 5–6:** Speed format `"%.2f %s"` or `"%.3f %s"` (kph/mph)
- **case 7–8:** Float format with unit string
- **case 9–10:** Speed/distance with auto/manual variant
- **case 0xb–0xc, 0x22:** Float format with unit string
- **case 0xd–0xf, 0x15:** Delegates to FUN_0042f260 (short format)
- **case 0x11–0x1a:** Delegates to FUN_0042f1e0 — percentage format
- **case 0x1b–0x1c:** Integer format with unit; conditional on flag at +0x198c
- **case 0x1d:** Conditional display — angle or index-based
- **case 0x1e, 0x26, 0x28:** Direct string display
- **case 0x20–0x21, 0x23–0x25:** Integer format (angle deg)
- **case 0x27:** Time format `"%d.%03d"` (ms → sec.ms)
- **case 0x29, 0x33:** Raw string display from value pointer
- **case 0x2a:** **Bevel gear ratio** — computes ratio via FUN_0042dcc0/FUN_0042dce0, formats as `"-- / -- [gearName] -- --"` or `"%.2f/1"` if flag at param_1 + 0x198c bit 4 set
- **case 0x2b–0x32:** Complex angle/ratio format with FUN_0042dc80/FUN_0042dca0/FUN_0042dd00 — formats as `"-- / -- / --"` or `"%.2f / %.2f"`

**Struct offsets:**
| Offset | Field | Notes |
|--------|-------|-------|
| +0xbb0 | SetupParamArray | Array of 64-byte setup parameter entries |
| +0x1884 | GearCount | Number of gears for ratio display |
| +0x1984 | Some gear counter 1 | Used in bevel ratio compute |
| +0x1980 | Some gear counter 2 | Used in bevel ratio compute |
| +0x198c | SetupFlags bitmask | bit 0 = auto flag, bit 1 = gear mode, bit 2 = bevel ratio mode |
| +0x1989 | AutoSetupFlag | Controls case 5–6 display format |
| +0x58 | CarName/SetupName | Display name string |
| +0x28 | UnitName | Unit string (e.g., "mm", "deg") |
| +0x18 | SpeedUnit | Speed unit string (e.g., "kph") |

**Calls:** FUN_0042f180 (simple format), FUN_0042f1e0 (percentage format), FUN_0042f260 (short format), FUN_00423a00 (string copy), FUN_0058815f (format/print), FUN_004d7880 (tire brand lookup), FUN_004d7570 (tire data), FUN_0042dcc0/FUN_0042dce0 (bevel gear ratio), FUN_0042dc80/FUN_0042dca0/FUN_0042dd00 (angle/ratio compute)

**Moddability:** No — display-only formatting. However the setup parameter array (+0xbb0) is read by setup file loaders — any mod changes to setup values would be displayed through this function.

---

## FUN_0042fd00 — Vehicle Setup File Writer

Source: garage.cpp [ida:fact]. Writes all vehicle setup parameters to a text-format setup file. Called when saving a custom setup from the garage UI.

**Key logic:**
- Opens file via FUN_005668b0/FUN_00566940 (write mode)
- On failure: logs "Failed to open %s for writing" and returns -1
- Writes section headers and values using FUN_00566c30 for each parameter:
  - `[Notes]`: driver notes string at +0x68 (chunked at 0x80 bytes)
  - `Symmetric`, `CGRightSetting`, `CGRearSetting`, `WedgeSetting`, `TireCompoundSetting`, `FuelSetting`
  - `NumPitstopsSetting`, `Pitstop1-3Setting`
  - `[LEFTFENDER]` / `[RIGHTFENDER]`: `FenderFlareSetting`
  - `[FRONTWING]`: `FWSetting`, `[REARWING]`: `RWSetting`
  - `[BODYAERO]`: `RadiatorSetting`, `BrakeDuctSetting`
  - `[SUSPENSION]`: 12 front/8 rear suspension parameters (anti-sway, toe-in, caster, track bar, 3rd spring/packer/bump/rebound)
  - `[CONTROLS]`: `SteerLockSetting`, `RearBrakeSetting`, `BrakePressureSetting`, `HandbrakePressSetting`
  - `[ENGINE]`: `RevLimitSetting`, `EngineMapSetting`, `EngineBrakeMapSetting`
  - `[DRIVELINE]`: `FinalDriveSetting`, `ReverseSetting`, `Gear%dSetting` for gears 1–8 (only if gear name non-empty at +0x08 per gear, stride 0x40)
  - `DiffPumpSetting`, `DiffPowerSetting`, `DiffCoastSetting`, `DiffPreloadSetting`
  - Per-wheel sections `[FRONTLEFT]` / `[FRONTRIGHT]` / `[REARLEFT]` / `[REARRIGHT]` (stride 0x2c0 per wheel): `CamberSetting`, `PressureSetting`, `PackerSetting`, `SpringSetting`, `RideHeightSetting`, `SlowBumpSetting`, `FastBumpSetting`, `SlowReboundSetting`, `FastReboundSetting`, `BrakeDiscSetting`, `BrakePadSetting`
  - `[BASIC]`: `Downforce`, `Balance`, `Ride`, `Gearing` (float), `Custom` (bool)
  - Closes file via FUN_00566b90/FUN_005668d0

**Struct offsets (param_1 = vehicle setup object):**
| Offset | Field | Type |
|--------|-------|------|
| +0x68 | Notes | string |
| +0x19a5 | Symmetric | byte |
| +0xc04 | CGRightSetting | int |
| +0xc44 | CGRearSetting | int |
| +0xc84 | WedgeSetting | int |
| +0xbc4 | TireCompoundSetting | int |
| +0xcc4 | FuelSetting | int |
| +0x1884 | NumPitstopsSetting | int |
| +0x18c4 / +0x1904 / +0x1944 | Pitstop1-3Setting | int |
| +0xe04 / +0xe44 | FenderFlareSetting L/R | int |
| +0x1284 / +0x12c4 | FWSetting / RWSetting | int |
| +0x1304 / +0x1344 | RadiatorSetting / BrakeDuctSetting | int |
| +0xd04–+0xdc4 | AntiSway, ToeIn L/R | int |
| +0xe84–+0xf44 | Caster, TrackBar L/R | int |
| +0xf84–+0x1244 | Front/Rear 3rd spring/packer/bump/rebound (L+R) | int |
| +0x1444 | SteerLockSetting | int |
| +0x1384 / +0x13c4 / +0x1404 | RearBrake / BrakePressure / HandbrakePress | int |
| +0x1584 / +0x15c4 / +0x1604 | RevLimit / EngineMap / EngineBrakeMap | int |
| +0x1644 / +0x1684 | FinalDriveSetting / ReverseSetting | int |
| +0x16c4..+0x1cc4 | Gear settings (8 entries × 0x40 = 0x200, each: +0x08=enable flag) | struct |
| +0x1484..+0x1544 | DiffPump / DiffPower / DiffCoast / DiffPreload | int |
| +0x104 per wheel (stride 0x2c0) | CamberSetting | int |
| +0x144 per wheel | RideHeightSetting | int |
| +0x184 per wheel | PackerSetting | int |
| +0x1c4 per wheel | SpringSetting | int |
| +0x204 per wheel | SlowBumpSetting | int |
| +0x244 per wheel | FastBumpSetting | int |
| +0x284 per wheel | SlowReboundSetting | int |
| +0x2c4 per wheel | FastReboundSetting | int |
| +0x304 per wheel | BrakeDiscSetting | int |
| +0x344 per wheel | BrakePadSetting | int |
| +0x1ca8 / +0x1cac / +0x1cb0 / +0x1cb4 | Downforce/Balance/Ride/Gearing | float |
| +0x19a4 | Custom | byte |

**Calls:** FUN_005668b0 (file open), FUN_00566940 (file status check), FUN_00566c30 (section/value write), FUN_00566b90 (file close), FUN_005668d0 (cleanup), FUN_004d7a50/FUN_004d7aa0 (error logging)

**Moddability:** Yes — defines the full set of vehicle setup fields written to setup files. Every field here is a potential mod target in `.svm` or setup files.

---

## FUN_00432220 — SettingsCopy Setup File Copy

Source: vehicle setup/garage module. Copies vehicle setup settings between setup objects or files. Iterates all available setups and writes/compares them.

**Key logic:**
- Reads source setup name from param_1 via FUN_00566650
- Iterates DAT_008ac488 (setup count) entries, stride 0x18c
- For each setup:
  - Gets setup name via FUN_004326a0
  - Uses FUN_00423a00 to copy name to message buffer
  - If `DAT_007d03f8` flag set: compares setup name against DAT_007ce5ec (filter), skips non-matching
  - If current entry is empty or filtered: iterates available setups via FUN_005679c0 (searches for "SettingsCopy" string)
  - Writes setup to game data directory via path construction and FUN_00566650
  - If filtered match: calls FUN_00433b60 to copy setup data
  - Calls FUN_00568b00 to finalize write
- Returns 1 if any setup was processed, 0 if none

**Strings:** SettingsCopy

**Closely related to:** FUN_00432180 (Settings read/apply), FUN_00431db0 (setup UI)

**Moddability:** Yes — setup copy mechanism used when applying randomized settings across vehicles.

---

## FUN_00432180 — Settings Setup File Read

Source: vehicle setup/garage. Reads a vehicle setup file from disk and applies it. Copies "Settings" string to buffer and calls FUN_00431db0 to initialize the setup UI.

**Key logic:**
- Reads profile path via FUN_004b0220 (up to 512 chars)
- Appends "Settings" string + path separator to form settings file path
- Calls FUN_00566650 to register path
- Calls FUN_00431db0 to load and display setup values
- Returns 1 on success

**Strings:** Settings

**Calls:** FUN_004b0220 (path read), FUN_00566650 (path registry), FUN_00431db0 (setup UI init)

**Moddability:** Yes — settings file read path used when loading randomized vehicle setups.

---

## FUN_00431aa0 — Setup Date/Angle Display Format

Source: vehicle setup/garage. Formats a vehicle setup date or angle value for display using `%3d/%3d/%3d %s` or `%d %s` format.

**Key logic:**
- Reads 3 float values from param_1 at stride (param_2 × 3 + 0x73b) × 4
- Subtracts base offset (_DAT_0059eac8) from each
- If unit system == 1 (imperial): applies conversion (subtract _DAT_0059eac0, multiply by _DAT_0059eab8, subtract _DAT_0059eab0)
- If unit system == 0 (metric): ROUND to integer
- For field index 3: formats as `%3d/%3d/%3d %s` (date/angle triple)
- For other indices: formats as `%d %s` with unit string from PTR_DAT_005c3f70

**Strings:** %3d/%3d/%3d %s

**Unit conversion globals:** _DAT_0059eac8 (base offset), _DAT_0059eac0, _DAT_0059eab8, _DAT_0059eab0 (imperial conversion factors)

**Moddability:** Yes — display formatting for date/angle setup fields (e.g., camber, caster).

---

## FUN_00431950 — Setup Integer Format "%d %s"

Source: vehicle setup/garage. Formats a single float setup value as integer with unit string.

**Key logic:**
- Subtracts base offset _DAT_0059eac8 from input float
- If unit system == 1 (imperial): applies imperial conversion factors
- Selects unit string from DAT_005c3738 (imperial) or DAT_005c3734 (metric)
- Rounds and formats as `%d %s`

**Strings:** %d %s

**Unit strings:** DAT_005c3738 (imperial), DAT_005c3734 (metric)

**Moddability:** Yes — display format for integer setup fields.

---

## FUN_004319e0 — Setup Float Format "%.3f %s / %.2f %s"

Source: vehicle setup/garage. Formats a setup float value with `.3f` or `.2f` precision depending on unit system.

**Key logic:**
- Reads float at param_1 + 0x1cd8 + param_2 × 4
- Multiplies by _DAT_0059ea20 (conversion factor)
- If unit system == 0 (metric): formats as `%.3f %s` with unit from param_1+0x18
- If unit system == 1 (imperial): formats as `%.2f %s` (multiplied by additional _DAT_0059ea18)

**Strings:** %.3f %s, %.2f %s

**Moddability:** Yes — display format for high-precision setup fields.

---

## FUN_0042f2f0 — Setup Value Format Dispatcher

Source: vehicle setup/garage. Dispatches formatting of a single setup field value based on field type (11 cases: 0–10). Handles display, offsets, and unit conversion.

**Key logic:**
- Base struct at param_1, stride (param_2 × 11 + param_3) × 0x40 + 0xb0
- Case dispatch:
  - Case 0: Double-value with multiplier, formats as `%.1f %s`
  - Case 1: Double-value, if metric → formats as `%d %s` (rounded), if imperial → applies _DAT_0059ea28 factor, formats as `%.1f %s`
  - Case 2: Calls FUN_0042f260 with offset -0.5 (param_2==1) or +0.5 (param_2==2) or 0
  - Case 3,9: Calls FUN_0042f260 with 0 offset
  - Case 4: Calls FUN_0042f180
  - Case 5–8: Calls FUN_0042f1e0
  - Case 10: Formats as `%d` (value + 1, raw int)
- Unit string from param_1+0x28 (case 0), param_1+8 (case 1), param_1+0x48 (cases 5–8), param_1+0x38 (case 4)

**Strings:** %.1f %s, %d %s

**Moddability:** Yes — central dispatcher for formatting all setup value types in the garage UI.

---

## FUN_0042f260 — Setup Value Format with Offset

Source: vehicle setup/garage. Format a setup field value with optional offset addition. Supports both `%.1f` and `%.3f` precision.

**Key logic:**
- Computes base value: `int_value * double_multiplier + double_base`
- If param_3 offset non-zero: adds `cgr_setting * cg_reference * wedge_value * offset`
- If metric: formats as `%.1f %s` (multiplied by _DAT_0059ea20)
- If imperial: formats as `%.3f %s` (additionally multiplied by _DAT_0059ea18)
- Unit string from param_1+0x18

**Strings:** %.1f %s, %.3f %s

**Conversion factors:** _DAT_0059ea20, _DAT_0059ea18 (metric ↔ imperial)

**Moddability:** Yes — formatting for setup fields with CG/Wedge offset adjustment.

---

## FUN_0042f1e0 — Setup Value Format "%.1f %s / %d %s"

Source: vehicle setup/garage. Format a setup field value with metric/imperial branching.

**Key logic:**
- Computes base: `int_value * double_multiplier + double_base`
- If metric: formats as `%d %s` (rounded), unit from param_1+0x48
- If imperial: formats as `%.1f %s` (multiplied by _DAT_0059ea10), unit from param_1+0x48

**Strings:** %.1f %s, %d %s

**Conversion factor:** _DAT_0059ea10

**Moddability:** Yes — formatting for setup fields with integer display in metric.

---

## FUN_0042f180 — Setup Value Format "%d %s"

Source: vehicle setup/garage. Format a setup field value with compound unit conversion as integer.

**Key logic:**
- Computes base: `int_value * double_multiplier + double_base`
- Multiplies by _DAT_0059ea08
- If imperial: additionally multiplies by _DAT_0059ea00
- Rounds and formats as `%d %s`, unit from param_1+0x38

**Strings:** %d %s

**Conversion factors:** _DAT_0059ea08, _DAT_0059ea00

**Moddability:** Yes — formatting for setup fields requiring compound unit conversion.

---

## FUN_00433ed0 — Validate Vehicle Configuration File

Source: vehicle_loader.cpp. Checks if vehicle description file exists.

**Key logic:**
- Calls FUN_0042bc10 for config check
- Looks up vehicle file from DAT_007c54e8+0x4898
- Sets DAT_007c56c4 = CostDisplayMode
- Opens file, falls back to default path on failure

**Calls:** FUN_0042bc10

**Moddability:** no

---

## FUN_00438690 — Physics Collision Damage & DNF Detection

Source: physics_damage.cpp. Computes collision impulse, detects DNF.

**Key logic:**
- Computes impact severity from velocity * damageMult
- Directional damage weighting from suspension/body coefficients
- If suspension > body: normal damage. Else: reduces energy, checks angular deviation
- If damage exceeds max: triggers DNF via FUN_0041b200
- Sets ReasonCode +0x4068 = 5 on first AI found

**Calls:** FUN_004388d0, FUN_0041b200, FUN_005697a0

**Moddability:** configurable — damage thresholds

---

## FUN_00443c07 — Vehicle Speed Limiter & Gear Threshold Control

Source: vehicle.cpp. Manages speed limiting, gear change thresholds, traction control.

**Key logic:**
- Computes delta from accumulator, records shift event
- Handles upshift/downshift: throttle, engine braking
- Tire grip limiting, torque reduction blend
- Race phase check for pit limiter
- Traction control decay, ring buffer modulation

**Calls:** FUN_004ef4f0, FUN_004f87c0, FUN_00447160, FUN_00447e00, FUN_004471f0, FUN_0058957a, FUN_00447b10

**Moddability:** data-driven via struct offsets

---

## FUN_00443f71 — Vehicle Target Speed Blending

Source: vehicle.cpp. Blends speed toward target using ABS, grip, TC.

**Key logic:**
- Applies decay toward target speed
- Tire grip limiting, torque reduction
- Race phase pit limiter check
- Traction control, ring buffer modulation

**Calls:** Same as FUN_00443c07

**Moddability:** speed blending rate, grip curves

---

## FUN_00451720 — Driver Input Controller

Source: ai.cpp. Processes inputs (AI/human) into throttle/brake/steering/clutch.

**Key logic:**
- DAT_007c56ac toggles AI mode
- Loops 4 channels: throttle, brake, steering, clutch
- AI path uses shift logic globals
- Human path uses manual throttle/blend
- Pit speed limiter, FFB steering with self-centering

**Globals:** DAT_007c56ac, DAT_007c54e0, DAT_007d1358, DAT_007d1fd8, DAT_007d2164, DAT_007d2140, DAT_007d208c, DAT_007d1ffc, DAT_007d2458, DAT_007d247c

**Moddability:** AI shift points, throttle curves, FFB strength

---

## FUN_004a6db0 — VehicleControlEnabled

Source: vehicle_physics. Checks suspension damage and finish state.

**Key logic:**
- Check 4 suspension corners for broken components
- If not all broken: check finish state != 1 and != 3
- If OK: call FUN_004d21d0

**Struct offsets:** +0x834/0x874 (SuspFL), +0x95c/0x99c (SuspFR), +0xa84/0xac4 (SuspRL), +0xbac/0xbec (SuspRR), +0x4064 (FinishState)

**Calls:** FUN_004d21d0

**Moddability:** medium — override via DAT_007ce814

---

## FUN_004b3ba0 — IterateVehicles

Source: renderer/vehicle. Calls function on every vehicle.

**Key logic:**
- Loops VehicleCount times, calls FUN_004c77d0 each iteration

**Moddability:** low — loop wrapper

---

## FUN_004ea970 — Collision Detection System

Source: physics. 13-point collision detection with wheel overlap.

**Key logic:**
- Iterates 13 collision points, transforms by matrix
- Checks all other vehicles: wheel-by-wheel overlap test
- Distance-based repulsion with normalized vector
- Collision response: relative velocity, friction, restitution
- Calls FUN_0041ad80 for penalty/contact reporting
- Calls FUN_004ed420 for damage calculation

**Calls:** FUN_0054fa90, FUN_004ea010, FUN_00410b80, FUN_00547390, FUN_004ed420, FUN_005694e0, FUN_0041ad80, FUN_0054fae0

**Moddability:** collision positions, radius, restitution

---

## FUN_004ec1a0 — Collision/Spark/Particle Effects

Source: physics. Processes impact forces, produces visual/audio feedback.

**Key logic:**
- Computes impact force, clamped by thresholds
- Four effect groups: proximity spark, second contact, 8 contact points, wheel scraping
- Lock/unlock effect, ring buffer for spark data
- Threshold comparison for intensity

**Calls:** FUN_004efae0, FUN_004ed1c0, FUN_004ed1f0, FUN_004ed220, FUN_004b33b0, FUN_004a56b0, FUN_004ed250, FUN_00411330, FUN_00442060

**Moddability:** effect thresholds, spark color/intensity

---

## FUN_004ee150 — Engine Wear/Failure Simulation

Source: physics. Only active when EngineWearMode 1 or 2.

**Key logic:**
- Runs 4 iterations (cylinders)
- Computes failure probability from +0x1330/0x1338 (wear params)
- In race session (7) with mode 2: divides by total laps
- If probability <= threshold: store failure time. Else: FLT_MAX

**Struct offsets:** param_1+0x3d64 (4 floats output), param_2+0x1330/0x1338 (wear params)

**Calls:** FUN_0053ac70, FUN_004b3ce0

**Moddability:** wear probability, failure threshold, cylinder count

---

## FUN_00442060 — SteeringGeometryUpdate

Source: vehicle_physics. Updates steering/suspension geometry per wheel corner.

**Key logic:**
- Computes steering angle: `param_3 * _DAT_0059ed78`
- Calculates per-wheel (param_2: 0=FL, 1=FR, 2=RL, 3=RR) steering offset:
  - Front wheels (0,3): add sin(random) × steering
  - Rear wheels (1,2): subtract
- Clamp to max steering angle (±0.22 radians ≈ 12.6°)
- Compute cos(random) × steering for caster offset
- Calls FUN_00441450 for geometry refresh
- Iterates 0x15bc suspension components:
  - Matches corners by wheel ID (param_1+0x15c0 entries, stride 0x30)
  - Applies steering rotation to wheel position and orientation
  - Transforms by local rotation matrix at param_2+0x1c/0x34/0x4c
  - Special handling at offset 0x60 and 0x90: uses param_1+0x141c if set
- Accumulates steering angle at param_1+0x1e0
- If accumulated angle > `_DAT_0059ed60` and ReasonCode == 0: sets ReasonCode=4 (steering damage)

**Struct offsets:** param_1+0x15c0 (suspension component array), param_1+0x15bc (count), param_1+0x141c (alternate geometry), param_1+0x1e0 (accumulated steering angle), *param_1→+0x4068 (ReasonCode)

**Globals:** DAT_008aae70, DAT_008aae74 (random ring buffer)

**Calls:** FUN_00441450, FUN_00435e00, FUN_004388d0, FUN_0056d020

**Moddability:** `configurable` — max steering angle, steering damage threshold

---

## FUN_004471f0 — SuspensionVibration

Source: vehicle_physics. Computes suspension vibration force.

**Key logic:**
- Checks if suspension compression (`+0x1c5c`) < reference (`+0x1c84`)
- Sets vibration flag at param_1+0x1c59
- If param_2 == 0 and compressed: computes random vibration:
  - Draws from ring buffer, applies `random × weight + base + offset`
  - Stores at param_1+0x1d10
- If param_2 != 0 and compressed: copies reference to current (resets)

**Calls:** no non-library calls beyond ring buffer

**Moddability:** vibration weight, offset constants

---

## FUN_00447c70 — VisualStateChange

Source: vehicle_physics. Notifies renderer of visual state change (suspension/ride height).

**Key logic:**
- Checks if state at param_1+0x1c58 changed from previous
- Updates stored state
- If vehicle exists (param_1+0x1f00 != 0) and param_3 == 0:
  - Draws 2 random values from ring buffer
  - Calls FUN_004f87c0 with type 0x28, sub-type 2, computed volume/pan

**Globals:** DAT_008aae70, DAT_008aae74, DAT_008ab274

**Calls:** FUN_004f87c0 (sound/event dispatch)

**Moddability:** state change threshold, sound volume constants

---

## FUN_004e0800 — VehicleRespawnReset

Source: vehicle_physics. Resets vehicle state on respawn/restart.

**Key logic:**
- Clears flag at param_1+0x25d
- If param_1[0x229] != 0: clears audio buffer via FUN_005506a0
- Sets random respawn timer offset at param_1[0x253]
- Calls FUN_004e0db0 for scene setup
- If param_2 == 0 (normal respawn):
  - If team ID (13000) is 0 or 1: allocates particle slot, spawns effect via FUN_004b33b0
- If param_2 != 0: calls FUN_004e3890 (extended reset)
- Sets flags at param_1+0x25b and +0x96d
- Calls FUN_004e0ed0 for audio/sound reset
- Clears effect at +0x979
- Calls FUN_004e2ca0 with intensity 1.0
- Zeros 7 effect accumulator slots (param_1[0x24d..0x251], +0x252)
- Sets damage timer indices to -1, stores max timer value from `DAT_007cf740`
- If effects active (param_1[0x226]): resets all via FUN_00551810
- Clears 17 damage animation slots (stride 7) if flag at +0x263 set

**Globals:** DAT_007cf740, DAT_0083ee60, DAT_008aae64, DAT_008aae70, DAT_008aae74

**Calls:** FUN_005506a0, FUN_004e0db0, FUN_004b33b0, FUN_004e3890, FUN_004e0ed0, FUN_004e2ca0, FUN_00551810

**Moddability:** respawn timer range, damage timer max, particle slot allocation

---

## FUN_004e5f60 — SuspensionAndWheelPhysics

Source: vehicle_physics. Main suspension/wheel physics integration — 4 corners, tire forces, chassis forces.

**Key logic:**
- Reads 4 suspension corner states from param_1+0x8b8 (stride 0x4a words, 0x128 bytes)
- Copies to local work buffer, applies velocity/steering corrections from param_3+0x54a..0x564
- Applies PID-style correction for steering/lean targets
- Writes corrected values back to param_1+0x8b8 and param_1+0x358c (stride 0xf8)
- **Chassis force computation:**
  - Reads longitudinal/lateral weight transfer from param_2+0xbf0/0xbf8/0xc04
  - Computes 4-corner chassis load distribution (matrix at +0x3674, stride 0x3e)
  - Weight distribution: `1.0 - fwd_fraction, fwd_fraction` cross-multiplied
  - Computes roll/pitch torques at +0x4024
- **Position update:**
  - Sets body position/rotation from param_3+0x40/0x48/0x50/0x58 and param_1+0x358c..0x3684
  - Reads DAT_007c8a24/0x2c/0x34 for vehicle offset if param_1+0x32bc == 0 (no collision)
- **Tire force calculation (4 corners):**
  - Reads tire model params from param_2+0x1b8 (stride 0x58) and param_3+0x1400 (stride 0x21 doubles)
  - Aggregates longitudinal/lateral/aligning forces per corner
  - Computes slip angles, friction circle
  - Stores per-corner force outputs at param_1+0x35ac (stride 0x3e)
- **Brake/grip factor:**
  - Per-corner brake force at +0x3784/0x3594, normalized by ABS difference
  - Computes brake bias (front/rear split) from param_2+0xcc4
- **Fuel system:**
  - Fuel mass from DAT_007d0b64 (FuelMult) × param_3+0x674 × DAT_007d01e8
  - Calls FUN_004a5330
- **Steering geometry output:**
  - Writes steering angle + reciprocal
  - Writes caster/camber angles from param_3+0x48/0x50/0x58
- **Gear ratio final drive:**
  - Reads from param_2+0x1440
  - Writes primary inertia + gear ratio at +0x3960/+0x1038
- **Differential/anti-roll:**
  - Computes from param_2+0xcf8/0xd38
  - Writes heave/roll stiffness at +0x3974
- **Ride height/springs:**
  - Reads spring rates from param_3+0x684/0x1374
  - Writes inverse ride rate
- **Engine inertia/drag:**
  - Reads from param_2+0x1578
- **SCR/Traction control:**
  - Reads param_3+0x13c4 for active control bits
  - Generates 8 random values via FUN_0042ed00
- **Downforce vectors:**
  - Front/rear wing downforce at +0x3a30/+0x3a44
  - Reads param_2+0x1338/0x1378
- **Aerodynamic balance:**
  - Computes 4-corner aero load distribution
- **Suspension geometry (13 points):**
  - Computes pushrod/rocker geometry for 13 hardpoints (8 suspension + 4 wheel + 1 reference)
  - Applies roll/pitch corrections, collision offsets
  - Computes bump stop, damper velocities
  - Stores final positions at param_1+0x3ab8..0x3ac0 (stride 0xc)
- **Final integration:**
  - Computes center of mass offset
  - Writes body position at param_1+0x1c/0x20/0x24
  - Calls FUN_004ee150 for engine wear simulation
  - Random seed at +0x4020 via _rand()

**Globals:** DAT_007d0b64 (FuelMult), DAT_007c8a24/0x2c/0x34 (vehicle offset), DAT_008aae70, DAT_008aae74 (random)

**Calls:** FUN_004d7880, FUN_004f1a60, FUN_004d7570, FUN_004d6ae0, FUN_004e2540, FUN_004a5330, FUN_004f6850, FUN_004f6880, FUN_004f68b0, FUN_004f6950, FUN_004f69e0, FUN_004f6a50, FUN_004f3190, FUN_0042ed00, FUN_0054b420, FUN_004dd7c0, FUN_004e9bd0, FUN_004ee150, FUN_0059d9d7, FUN_0054f830, FUN_0059da3a, _rand

**Moddability:** `configurable` — all suspension, aero, tire, and fuel parameters read from setup

---

## FUN_004efa40 — VehicleClimbAdjust

Source: vehicle_physics. Adjusts vehicle climb/ride-height for ground clearance.

**Key logic:**
- If param_1+0x32bc == 0 (no collision): delegates to FUN_004471f0
- If param_2 == 0: sets random bump value at +0x39b8 from ring buffer
- If param_2 != 0 and +0x3994 < +0x399c: copies upper bound to current

**Struct offsets:** +0x32bc (collision enabled), +0x39b8 (bump value), +0x3994 (current height), +0x399c (target height)

**Globals:** DAT_008aae70, DAT_008ab274

**Calls:** FUN_004471f0

**Moddability:** bump offset range, height clamp limits

---

## FUN_004efae0 — TireScrubReset

Source: vehicle_physics. Resets tire scrub/wear accumulation when not active.

**Key logic:**
- If EngineWearMode (`DAT_007cea5c`) != 0:
  - If param_1+0x32bc == 0: delegates to FUN_00447280
  - If tire wear accumulator at +0x3d64 > 0: resets to 0 (clears accumulated wear)

**Struct offsets:** +0x32bc (collision enabled), +0x3d64 (tire wear accumulator)

**Globals:** DAT_007cea5c (EngineWearMode)

**Calls:** FUN_00447280

**Moddability:** N/A — conditional reset

---

## FUN_0042ad20 — Fuel Multiplier Value

Source: fuel.cpp. Returns fuel multiplier value. If DAT_007d0b64 (FuelMult) is non-zero, returns ftol-converted result. Otherwise returns 100.

**Key logic:**
- Checks DAT_007d0b64 global
- If set: converts float to int
- Default: 100

**Globals:** DAT_007d0b64 (FuelMult)

---

## FUN_0042ad50 — Fuel/Weight Limit Check

Source: fuel.cpp. Checks if fuel consumption exceeds remaining allocation. Compares current season points (+0x403c) and fuel used (+0x4040) against remaining fuel weight at +0x3984 and consumption rate at +0x3448.

**Key logic:**
- Returns 1 if fuel multiplier disabled (DAT_007d0b64 == 0)
- Computes: (raceDistance - seasonPoints) - fuelUsed * _DAT_0059e98c < remainingFuel * consumptionRate - _DAT_0059e458
- If true: allow fueling, return 1
- Otherwise: deny, return 0

**Struct offsets:**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x403c | SeasonPoints | int, current race points |
| +0x4040 | FuelUsed | int, fuel consumed so far |
| +0x3984 | RemainingFuelWeight | float |
| +0x3448 | FuelConsumptionRate | float |

**Globals:** DAT_007d0b64 (FuelMult), DAT_008acf8c (RaceTotalDistance), _DAT_0059e98c, _DAT_0059e458

**Moddability:** fuel consumption thresholds

---

## FUN_0049b8d0 — Speed Multiplier

Source: vehicle_speed.cpp. Returns player vehicle speed at +0x39a0 times _DAT_0059ea38.

**Globals:** DAT_007c54e0 (PlayerVehiclePtr), _DAT_0059ea38

---

## FUN_0049b8f0 — Engine/Rev Value Accessor

Source: vehicle_access.cpp. Returns value at PlayerVehiclePtr+0x39fc.

**Globals:** DAT_007c54e0 (PlayerVehiclePtr)

---

## FUN_0049b900 — Speed Magnitude (Rounded)

Source: vehicle_math.cpp. Computes SQRT(x²+y²+z²) of velocity vector at +0x34f8/+0x34fc/+0x3500. Multiplies by _DAT_005acaf4.

**Globals:** DAT_007c54e0 (PlayerVehiclePtr), _DAT_005acaf4

---

## FUN_0049b950 — Speed Magnitude (Alternate)

Source: vehicle_math.cpp. Same SQRT computation as 0049b900 but multiplies by _DAT_0059f128.

**Globals:** DAT_007c54e0 (PlayerVehiclePtr), _DAT_0059f128

---

## FUN_0049ba30 — Gear Range Check

Source: vehicle_gear.cpp. Returns 1 if current gear at +0x3450 is 1-3, else 0.

**Struct offsets:** +0x3450 (current gear)

**Globals:** DAT_007c54e0 (PlayerVehiclePtr)

---

## FUN_0049ba50 — Fuel/Weight Computation

Source: vehicle_fuel.cpp. Computes fuel-related value. Uses DAT_007d0b64 (FuelMult) multiplied by _DAT_0059e448. Reads fuel mass at +0x398c and remaining fuel at +0x3984.

**Globals:** DAT_007c54e0 (PlayerVehiclePtr), DAT_007d0b64 (FuelMult), _DAT_0059e448

---

## FUN_0049ba90 — Pit/State Flag Check

Source: vehicle_state.cpp. Returns true if value at PlayerVehiclePtr+0x4070 > 0.

**Globals:** DAT_007c54e0 (PlayerVehiclePtr)

---

## FUN_0049bab0 — Disqualification Check

Source: vehicle_state.cpp. Returns true if FinishState at +0x4064 == 3 (DSQ).

**Struct offsets:** +0x4064 (FinishState)

**Globals:** DAT_007c54e0 (PlayerVehiclePtr)

---

## FUN_0049bb20 — Vehicle Flag Check

Source: vehicle_state.cpp. Returns flag at PlayerVehiclePtr+0x4108.

**Globals:** DAT_007c54e0 (PlayerVehiclePtr)

---

## FUN_0049d070 — Steering Wheel Animation

Source: vehicle_anim.cpp. Renders steering wheel animation. Reads team ID at +13000. Checks speed at +0x39a0. Uses player vehicle flags (+0x10→+0x54). Calls FUN_00543440 and FUN_0049e4e0 for animation/audio.

**Globals:** DAT_007c54e0 (PlayerVehiclePtr), DAT_007c9081

**Calls:** FUN_00543440, FUN_0049e4e0

---

## FUN_0049d280 — Wheel Rotation Animation

Source: vehicle_anim.cpp. Drives 4 wheel rotation animations. Checks all 4 corner pointers non-null. Checks vehicle audio flags at +0xf90 or +0xf7c. Processes 4 bits from FUN_0049b7a0 result to trigger wheel rotation effects.

**Globals:** DAT_007c54e0 (PlayerVehiclePtr)

**Calls:** FUN_0049b7a0, FUN_0049e4e0

---

## FUN_0049e4e0 — Audio/Effect Trigger

Source: vehicle_audio.cpp. Triggers audio/effect. If player vehicle at +0xf90 or +0xf7c non-null, calls FUN_005506a0 to play sound/effect.

**Globals:** DAT_007c54e0 (PlayerVehiclePtr)

**Calls:** FUN_005506a0

---

## FUN_004db170 — Steering/Ackermann Computation

Source: vehicle_steer.cpp. Computes steering geometry and Ackermann angles. Processes float math for wheel angles.

---

## FUN_004e09e0 — Vehicle Reset/Clear

Source: vehicle_reset.cpp. Resets vehicle scene state. Checks DAT_008afe88 flag. Calls FUN_004e0db0, FUN_00545150, FUN_00411570 for scene setup. Clears vehicle effects.

**Globals:** DAT_008afe88

**Calls:** FUN_004e0db0, FUN_00545150, FUN_00411570, FUN_004e38d0, FUN_004e3050, FUN_004dfa50, FUN_004b33b0

---

## FUN_004f1630 — Tire Name Accessor

Source: tire_name.cpp. Returns tire name string. Calls FUN_004d7570 with value at param_1+0x3970. Dereferences result for string pointer.

**Calls:** FUN_004d7570

---

## FUN_004f34e0 — Tire Model Data Init

Source: tire_init.cpp. Large tire model data initializer (1830 bytes). Sets up tire compound parameters. Calls sub-initializers FUN_004f3040, FUN_004f31f0, FUN_004f2b10. Initializes many fields to default -1/0 values across the tire model struct.

**Calls:** FUN_004f3040, FUN_004f31f0, FUN_004f2b10

---

## FUN_004b6a10 — Vehicle Force/Aerodynamics Computation

Source: vehicle_forces.cpp. Computes vehicle force/aero parameters. Processes float inputs (param_3, param_4). Iterates through vehicle data structures performing math operations.

---

## FUN_0049e570 — Suspension Corner Check

Source: vehicle_susp.cpp. Checks suspension corner at param_1*0x128+0x834 from PlayerVehiclePtr. If corner active and flag at +0x40 set, calls FUN_0049e670. Otherwise calls FUN_0049e760.

**Struct offsets:** Corner stride 0x128 starting at +0x834

**Globals:** DAT_007c54e0 (PlayerVehiclePtr)

**Calls:** FUN_0049e670, FUN_0049e760

---

## FUN_004326e0 — Player Name Setup

Source: player_setup.cpp. Initializes player name from message buffer DAT_005ec4cc. Searches name list via FUN_00423a00. If name not in list, copies empty string. Finds index by iterating linked list. Calls FUN_00432980 with matched name.

**Key logic:**
- Calls init functions (FUN_00432180, FUN_00432220, FUN_004326d0)
- Gets name from DAT_005ec4cc via FUN_004326a0
- Searches player name table via FUN_00423a00
- Iterates linked list to find matching index
- Calls FUN_00432980 with player name

**Globals:** DAT_005ec4cc (MessageBuffer), DAT_005ea438

**Calls:** FUN_00432180, FUN_00432220, FUN_004326d0, FUN_004326a0, FUN_00423a00, FUN_00588410, FUN_00566650, FUN_00432980

---

## FUN_0043f7f0 — Suspension/Wheel Dynamics Solver (Constraint-Based)

Source: wheel_dynamics.cpp. Semi-implicit Euler integration with constraint solving for wheel suspension and contact forces. Computes spring, damper, and ground-contact forces per wheel.

**Key logic:**
- Input: param_1 (vehicle/wheel struct), param_2 (timestep dt)
- Random noise via FUN_00438930 (grip variation, local_270[1..4])
- Table interpolation at param_1+0x1cfc: linear interpolate spring/damper curves from float table (stride 8 bytes: [x0, y0], [x1, y1]) — stores result at param_1+0x1d00, +0x1d04
- Non-linear spring: `local_240` = computed spring force from deflection + velocity across lookup table
- Solver mode at param_1+0x1e14 (0, 1, 2) selects wheel grouping:
  - 0: Two wheels (axle pair — likely front or rear)
  - 1: Four wheels (full vehicle)
  - 2: Two wheels with alternate force routing
- Per-wheel arrays at stride 0x464 (1124 bytes), fields: +0x348, +0x360, +0x368, +0x7ac, +0x7c4, +0xc10, +0xc28, +0xc30, +0x1074, +0x108c
- Constraint solve: computes candidate timesteps `dStack_2c0` (from velocity constraint) and `dStack_2b8` (from position/penetration constraint); selects minimum stable timestep
- Jacobian computation at adStack_1f0 (lines 648-673): negative ratio of bias/effective mass for each wheel
- Force output: applied to param_1+0x15f0 (wheel force accumulator struct) at offsets +0x14c, +0x154, +0x15c (force components)
- Sub-stepping: if computed timestep < dt, runs remaining time in a loop (goto LAB_00440210)
- Error handlers: FUN_0059d7b5/FUN_0059d928 — division-by-zero or constraint failure

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x1e38 | WheelDeflection | current suspension position |
| +0x1c5c | WheelVelocity | derived velocity state |
| +0x1cfc | SpringCurveTable | pointer to (x,y) float table for non-linear spring |
| +0x1d00 | SpringForce | interpolated spring force (float) |
| +0x1d04 | DamperForce | interpolated damper force (float) |
| +0x1e14 | SolverMode | 0=2wheel, 1=4wheel, 2=2wheel_alt |
| +0x1e18 | Stiffness | spring rate |
| +0x1e20 | DampingRebound | rebound damping coefficient |
| +0x1e28 | DampingBump | bump/compression damping coefficient |
| +0x1e30 | BiasForce | preload/bias force |
| +0x1e50 | BiasState | accumulated bias/integral term |
| +0x1ef0 | SolverErrorFlag | constraint failure flag |
| +0x1e58 | ForceScale | overall force scaling factor |
| +0x15f0 | WheelForceTarget | pointer to force accumulator struct |
| +0x141c | AltForceTarget | alternate force output target |

**Per-wheel arrays (stride 0x464):**
| Base offset | Field |
|-------------|-------|
| +0x348 | Position (double) |
| +0x360 | Force |
| +0x368 | Constraint state |
| +0x7ac | Force2 |
| +0x7c4 | Inertia |
| +0xc10 | Velocity |
| +0xc28 | Mass |
| +0xc30 | Inertia2 |
| +0x1074 | Bias |
| +0x108c | Bias2 |

**Calls:** FUN_00438930 (rng), FUN_005895a2 (sqrt/math), FUN_00435290 (comparison gate), FUN_005677b0 (cholesky/matrix solve), FUN_0059d7b5 (error handler), FUN_0059d928 (error handler)

**Moddability:** configurable (spring/damper curves via table, stiffness/damping as floats)

## FUN_004b0ef0 ? Vehicle Setup Configuration

Source: likely setup.cpp. Selects one of 6 vehicle setups and copies associated parameters.

**Key logic:**
- param_2: 1-6 (setup slot)
- Copies from setup arrays at stride 0x24 (36 bytes per setup) to runtime struct
- 12 parameter groups transferred (gearing, diffs, suspension, etc.)
- Clamps copied values between stored min/max bounds
- Sets mode: param_2==1 ? mode 1, param_2==2 ? mode 7
- Calls FUN_004b1190(0xbf800000) to finalize

**Calls:** FUN_0047f1f0 (copy), FUN_00464720, FUN_004646c0, FUN_004b1190

**Moddability:** configurable

<!-- target: docs/21-audio-network-internals.md -->

## FUN_004b0c00 ? Vehicle Setup Default Copy

Source: likely setup.cpp. Copies default vehicle setup values to runtime struct from template at 0x496c-0x49a4.

**Key logic:**
- Copies 13 parameter blocks from template (stride 4 bytes) to runtime (various offsets)
- Clamps gearing (0x275c) and speed (0x2858) between stored min/max
- Initial diff lock (0x248c) with inbound check
- Same pattern as FUN_004b0ef0 but from template instead of setup slot

**Calls:** FUN_0047f1f0, FUN_00464720, FUN_004646c0

**Moddability:** configurable

<!-- target: docs/18-physics-dynamics.md -->

## FUN_0045a8e0 � Vehicle Body Position Update

Source: Unknown. Updates vehicle world position with suspension travel check and orientation computation.

**Key logic:**
- Compares input throttle/ride height against min/max travel limits
- Accesses DAT_007d0ab0 as ride height tolerance/offset
- Computes position (3 doubles at +0x36, +0x38, +0x3a) output as floats
- Uses fpatan (atan2) on quaternion/rotation components at +0x40, +0x42, +0x44, +0x46, +0x48, +0x4c
- Checks velocity magnitude thresholds (+0x50, +0x52, +0x54, +0x56, +0x58)
- Checks dot product of two orientation vectors (+0x70-0x8c range) for stability
- Resets state and calls FUN_00569280 when motion below threshold (settled)

**Calls:** FUN_00569280 (state reset), FUN_0054b3b0, FUN_0054c030, FUN_0054b4d0, FUN_00588570, FUN_00459ae0

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_00458df0 � Object/Camera Target Positioning

Source: Unknown. Computes world position and yaw orientation for a follow camera or attached object.

**Key logic:**
- Adds input offset (param_2) to base position (param_1+0xc/0x10/0x14)
- Normalizes resulting direction vector (reciprocal sqrt)
- Computes yaw via fpatan2 of x/z components
- Checks flag at +0x74 bit 0: if set, applies camera shake via FUN_00456040
- Clamps FOV/zoom ratio at +0x38/+0x3c
- If +0xa4 > 0: calls FUN_004584c0 for offset adjustment
- Calls FUN_00456130 for final camera transform

**Calls:** FUN_00456040, FUN_004584c0, FUN_00456130, FUN_00588570

**Moddability:** hardcoded
| 0x005215db | 69 | renderer | SIMD Newton-Raphson reciprocal sqrt approximation used in decompression vtable | no | -- |
| 0x00410f60 | 92 | game_logic | command dispatch indexing arrays (stride 0x318/0x328) calling render position function | no | -- |
| 0x0052835f | 76 | audio | 4-tap FIR filter with wavetable lookup for audio synthesis/resampling | no | -- |
### FUN_004a2840 — Parameter Interpolation

Float-keyed piecewise linear parameter interpolation with dispatch. Evaluates input against threshold table, interpolates, dispatches result to registered targets.

**Key logic:**
- Struct: +0x6c (entry array ptr), +0x70 (entry count), +0x74 (float table ptr), +0x44 (current value), +0x68 (dispatch target count)
- Each table entry: stride 7 floats [lo_thresh, hi_thresh, slope_mult, val_lo, val_hi, ?, ?]
- Below lo: sets current to val_lo, dispatches val_lo via FUN_00551210
- Above hi: sets current to val_hi, dispatches val_hi
- Between thresholds: linear interpolation `(hi_val - lo_val) * (input - lo_thresh) * slope + lo_val`, dispatches result
- If input matches existing breakpoint: returns early

**Calls:** FUN_00551210 (parameter dispatch)

**Moddability:** hardcoded
| 0x004af220 | 72 | game_logic | race mode parameter configurator (cases 1-4) with clamp to bounds | no | -- |
| 0x004c6810 | 92 | game_logic | recursive merge sort on linked list with custom comparator | no | -- |
| 0x005692a0 | 49 | physics_math | inertia tensor/moment of inertia matrix computation from mass distributions | no | -- |
| 0x0040ef70 | 81 | game_logic | camera mount position/rotation update with 13-float parameter set | no | -- |
| 0x0043e770 | 70 | collision | wheel collision contact flag management with contact list traversal | no | -- |

### FUN_0043E770 — Wheel Collision Contact Flag Setter

Sets collision contact flags on vehicle struct based on wheel-pair contact matching.

**Key logic:**
- Computes per-wheel base: param_2 × 0x464 + 0x28c + param_1
- Checks collider at +0x160 (zero = inactive):
  - Inactive: marks +0x1c4=1; iterates arrays at +0x15b4 (stride 0x30) and +0x15bc (stride 0x30) — if wheel ID matches contact pair (+4/+0xc), sets bit 0 at offset +0x2c
  - Active: marks +0x200=1; iterates array at +0x15c4 (stride 0x48) — if wheel ID matches, sets bit 0 at offset +0x44
- Uses param_1+0x141c as reference ID for contact matching

**Struct offsets (vehicle struct):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x141c | CollisionRefID | Reference ID for contact matching |
| +0x15b4 | ContactCount1 | Count of contacts in first array |
| +0x15b8 | ContactArray1 | Array of contact entries (stride 0x30) |
| +0x15bc | ContactCount2 | Count of contacts in second array |
| +0x15c0 | ContactArray2 | Array of contact entries (stride 0x30) |
| +0x15c4 | ContactCount3 | Count of contacts in third array |
| +0x15c8 | ContactArray3 | Array of contact entries (stride 0x48) |

**Calls:** none

**Moddability:** hardcoded
| 0x00441bb0 | 57 | dynamics | rigid body torque accumulation from suspension forces with inertia terms | no | -- |
| 0x0051e2ba | 82 | renderer | resource decompression output filler with stride-division pattern | no | -- |
| 0x004c2e20 | 84 | game_logic | recursive merge sort on linked list comparing floats at second dword | no | -- |
| 0x005418e0 | 63 | renderer | camera object initializer with default FOV/clip plane values and name copy | no | -- |
### FUN_004414d0 — WheelDataCopy

Physics state backup and stepping with wheel state copy. See docs/18-physics-dynamics.md for full entry.

**Key logic:**
- Copies 4× wheel state blocks (stride 0x119*4 bytes each)
- Transfers +0x1c5c/0x1c60 → +0x1c64/0x1c68 (frame history backup)
- Transfers +0x1e38/0x1e3c → +0x1e40/0x1e44 (secondary state)
- Copies per-wheel suspension data across 4 wheels
- Iterates linked state array: copies 12 dwords per entry from +0x134/+0x14c
- Calls integration stepping sequence

**Calls:** FUN_0043f7f0, FUN_0056ecf0, FUN_0056ee40, FUN_0056f020, FUN_00441450

**Moddability:** hardcoded
| 0x0054f5c0 | 65 | collision | proximity check between two physics objects with distance threshold | no | -- |

=== FULL ENTRIES ===
<!-- target: docs/17-physics-collision.md -->

## FUN_004b5c50 — Vehicle Instance List Builder

Source: unknown. Builds a linked list of vehicle instances by iterating the vehicle array (0x48c0 stride, 104 entries).

**Key logic:**
- Iterates by +0x48c0 per step (vehicle struct size), 104 iterations
- Each step advances a node pointer chain
- If current node is empty and vehicle at offset 13000 is not -1 (active):
  - Allocates new object, creates list node, calls per-vehicle init
  - Sets parameter at +0x84 from DAT_008afea0
  - Appends to linked list, increments count

**Calls:** FUN_004baa50 (alloc), FUN_004baf10 (init), FUN_004bb0c0 (finish init), FUN_004b51e0 (vehicle update), FUN_004b5120 (vehicle active check), FUN_004ba830 (object query)

**Moddability:** hardcoded

---

<!-- target: docs/21-audio-network-internals.md -->

## FUN_00401340 — Vehicle Suspension Force Calculation

Source: unknown. Calculates wheel suspension forces for one vehicle's wheels.

**Key logic:**
- Iterates over `local_80` wheels (from param_1+0x130 if param_2==0 else 1)
- Each wheel struct is 0x13c bytes stride
- Reads body position at offsets +0x94, +0x98, +0x9c (local body coords)
- Reads collision contact point at +0x110
- Reads suspension geometry at +0x10c
- Computes world-space suspension forces using cross products
- Writes results to +0x70, +0x74 (lateral force), +0x78, +0x7c, +0x80 (longitudinal/vertical forces)
- Uses FUN_00401180 (atan2?) to compute angles
- Uses FUN_0044c4c0 and FUN_0044c550 (transform helpers, likely matrix/vector ops)

**Struct offsets (per wheel, stride 0x13c):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x70 | lateralForce | lateral suspension force output |
| +0x74 | longForce | longitudinal suspension force output |
| +0x78-0x80 | springForce | spring/damper forces (3 floats) |
| +0x94-0x9c | bodyAttach | body attachment point (x,y,z) |
| +0x10c | suspGeom | suspension geometry index/ptr |
| +0x110 | contactPtr | collision contact surface pointer |
| +0x130 | numWheels | wheel count for this vehicle |
| +0x134 | wheelArray | wheel struct array pointer |

**Globals:**
- `DAT_0059e440` — 0.0 (zero constant)
- `_DAT_0059e43c` — 1.0 (or reciprocal constant)
- `_DAT_0059e438` — 0.5? (used in normalization)

**Calls:** FUN_0044c4c0 (matrix transform), FUN_0044c550 (vector transform), FUN_00401180 (angle computation)

**Moddability:** hardcoded

<!-- target: docs/10-vehicle-physics.md -->

## FUN_004e3d00 — Wheel Spring/Damper Force and Steering

Source: unknown. Computes spring force, damper force, and steering deflection for one vehicle wheel.

**Key logic:**
- Reads wheel state from param_1[0x0e-0x38] (38+ float array per wheel)
- Computes local suspension axes from param_1[0x0e-0x10] (wheel orientation vectors)
- Branch on param_1[0x0f] (suspension type: <=_DAT_005ad168 = double-wishbone/McPherson, >0x2f=1.0 = rigid axle, else general)
- Computes spring force from ride height (param_1[0x11]) with bumpstop at param_1[0x2b]
- Spring: param_1[0x13] = (rideHeight * param_1[0x2a] + 1.0) * param_1[0x27] * rideHeight
- Damping: param_1[0x14] = 1.0 (enabled flag), scaling from param_1[0x25]
- Steering geometry: transforms wheel deflection using param_1[0x2f]/param_1[0x30] (caster/camber?)
- Stores output velocities at param_1[0x36-0x38] (3-component velocity)
- Threshold checks against param_1[0x31-0x32] (previous hit position) to prevent re-collision

**Struct offsets (param_1 as wheel float array):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x0e-0x10 | suspAxis | suspension axis vectors (3 floats x 3?) |
| +0x0f | suspType | suspension type enum (0=dbl-wishbone, 1=rigid) |
| +0x10 | wheelNormal | wheel normal direction |
| +0x11 | rideHeight | current ride height (travel) |
| +0x12 | springK | spring constant (hardcoded 5.0) |
| +0x13 | springForce | computed spring force |
| +0x14 | dampingEnabled | damping enabled flag |
| +0x15 | damperForce | damper force accumulator |
| +0x16 | bumpForce | bump stop force |
| +0x24 | wheelRadius | wheel radius |
| +0x25 | dampingFactor | damping coefficient |
| +0x27 | springRate | spring rate multiplier |
| +0x2a | progressiveRate | progressive spring rate |
| +0x2b | bumpStopTravel | bump stop engagement travel |
| +0x2c-0x2e | camber/caster | alignment angles |
| +0x2f | steerCaster | caster angle cosine |
| +0x30 | steerKingpin | kingpin angle |
| +0x31-0x32 | lastContact | previous contact position (x,z) |
| +0x36-0x38 | wheelVel | output wheel velocity (world space) |

**Globals:**
- `DAT_0059e440` — 0.0
- `_DAT_0059e43c` — 1.0
- `_DAT_005ad168` — suspension type threshold (double-wishbone limit)
- `_DAT_005ad178` — caster angle threshold
- `_DAT_005ad148` — contact proximity threshold
- `_DAT_005ad16c`, `_DAT_005ad170` — track/camber factors
- `_DAT_0059e7f8`, `_DAT_0059e7fc` — bump damping constants

**Calls:** None (pure math)

**Moddability:** `configurable` via spring/damper parameters

<!-- target: docs/08-file-formats.md -->

## FUN_0046a9c0 — Controller Shifter Mapping

Source: Unknown. Maps controller input actions to transmission shift commands via global action arrays.

**Key logic:**
- Reads action at param_1+0x200 via FUN_0046a980
- Writes action pair to global arrays DAT_007d1b08 / DAT_007d1b0c indexed by param_1+500
- If first action != 1 (button press?), returns immediately
- Switch maps 30+ action value pairs (iVar3/iVar2) representing gear shifts:
  - Cases 1-12: gear up/down pairs for gears 1-6 (iVar1=0, iVar2=0-5)
  - Cases 0x1e-0x29: up/down pairs for gears 1-6 (iVar1=1 alternate mapping)
  - Cases 0x66-0x6d: additional controller mappings (iVar1=0-1, iVar2=6-7)
- After mapping, scans DAT_007d1b08/DAT_007d1b0c arrays for matching action
- Sets flag at DAT_007d1490[(iVar2 + iVar1*8) * 0x1b] = 0x3f000000 (0.5f)

**Globals:**
- `DAT_007d1b08` — global action type array
- `DAT_007d1b0c` — global action value array
- `DAT_007d1490` — global action active flags

**Calls:** FUN_0046a980

**Moddability:** configurable (input mapping tables)

<!-- target: docs/19-renderer.md -->

## FUN_004f15da — Physics Timestep / Lap Completion Gate

Writes float from ST0 to *(in_EAX-4). If param_1 > *(unaff_ESI + 0x39f8) (lap threshold): if DAT_007d01c4 bit 2 set: scales +0x3984 via random from FUN_005881f0. Sets +0x3bf4. Calls FUN_004e8010(0). Else: calls FUN_0059d9b5.

<!-- target: docs/10-vehicle-physics.md -->

## FUN_004f8250 — Object Destructor (Vtable Chain)

If *param_1 non-null: calls vtable[8/4] and vtable[0x18/4] methods. Then calls vtable[0] destructor(1). Zeroes *param_1.

<!-- target: docs/06-session-race-logic.md -->

## FUN_004fae70 — Signed Index Table Lookup (Clamped ±7)

Converts via __ftol. If result < _DAT_0059e430: negates. Clamps abs to 7. Reads from param_1+0xcc (negative) or +0xec (positive) at clamped index ×4.

<!-- target: docs/18-physics-dynamics.md -->

## FUN_004faec0 — 3D Position Delta Computation

Source: unknown | Confidence: high
Computes 3D vector from current position to target (or from target to current).

**Key logic:**
- If target ptr at param_1[0x44] exists: delta = target - current (3 components)
- Else if reference at param_1[0x43] exists: delta = current - reference
- Else: delta = (0, 0, -1) — default fallback

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x00..02 | CurrentPos | Current position (3 floats) |
| +0x0c..0e | Delta | Computed delta (3 floats) |
| +0x10c (0x43*4) | RefPtr | Reference position pointer |
| +0x110 (0x44*4) | TargetPtr | Target position pointer |

**Used by system:** docs/10-vehicle-physics.md — position tracking

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00423ca0 — Short Computation / Vehicle Physics Steering Torque

Source: vehicle physics | Confidence: high
Computes steering torque or wheel force vector using lateral/longitudinal forces. Reads coefficients from vehicle struct and computes signed magnitude.

**Key logic:**
- Reads vehicle pointer from *param_1
- Computes fVar3 = param_2² + param_4² (squared lateral+longitudinal)
- If fVar3 != 0 (DAT_0059e440=~0.0f):
  - Computes fVar4 = (param_2 * vehicle+0x34f8 + param_4 * vehicle+0x3500) / fVar3 (normalized projection onto reference vector)
- Computes fVar2 = sqrt(fVar4² × (param_2² + param_4²)) with sign from fVar4
- Stores param_1[6] = (int)(fVar2 - param_5) (torque/force minus bias)
- Second projection: fVar4 = (param_2 * vehicle+0x3500 - param_4 * vehicle+0x34f8) / fVar3 (perpendicular)
- Computes signed sqrt for param_1[4] (orthogonal component)

**Struct offsets (param_1 — output):**
| Offset | Field | Type | Notes |
|--------|-------|------|-------|
| +0x10 | OutputA | float | param_1[4] — orthogonal result |
| +0x18 | OutputB | float | param_1[6] — primary result |

**Vehicle struct (*param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x34f8 | RefCoeffX | Reference vector X component |
| +0x3500 | RefCoeffY | Reference vector Y component |

**Globals:**
- `DAT_0059e440` — zero threshold (~0.0f)

**Used by system:** docs/10-vehicle-physics.md — Steering/force computation with vector projection and signed magnitude.

**Algorithm family:** vehicle physics math

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_004594d0 — Struct Init with Float Constants (Physics Params)

Source: unknown | Confidence: medium
Initializes a struct with specific physics-related float constants.

**Key logic:**
- Zeros fields at +0x04 through +0x18, +0x24, +0x28, +0x30, +0x38, +0x50, +0xc0, +0xc4, +0xc8, +0xcc, +0xd0
- Sets sentinel/max values at +0x1c and +0x20 = 0x7f7fffff (FLT_MAX)
- Sets +0x2c = 0x40700000 (3.75f), +0x34 = 0x40500000 (3.25f)
- Sets +0x3c = 0x3fe00000 (1.75f), +0x40 = 0xd2f1a9fc, +0x44 = 0x3f50624d (0.813f)
- Sets +0x48 = 0xd2f1a9fc, +0x4c = 0x3f40624d (0.752f)
- Constants suggest vehicle physics/tire parameters

**Struct offsets (param_1):**
| Offset | Value | Float | Notes |
|--------|-------|-------|-------|
| +0x1c | 0x7f7fffff | FLT_MAX | Max bound |
| +0x20 | 0x7f7fffff | FLT_MAX | Max bound |
| +0x2c | 0x40700000 | 3.75f | Physics parameter |
| +0x34 | 0x40500000 | 3.25f | Physics parameter |
| +0x3c | 0x3fe00000 | 1.75f | Physics parameter |
| +0x40 | 0xd2f1a9fc | -4.19e8f | Large negative |
| +0x44 | 0x3f50624d | 0.813f | Coefficient |
| +0x48 | 0xd2f1a9fc | -4.19e8f | Large negative |
| +0x4c | 0x3f40624d | 0.752f | Coefficient |

**Used by system:** docs/10-vehicle-physics.md — physics/tire parameter struct initialization

**Moddability:** configurable — values appear to be tuneable physics constants

<!-- target: docs/20-math-utilities.md -->

## FUN_004780b0 — Physics/Vehicle Object Reference Store

Source: unknown | Confidence: medium
Calls virtual method to get a resource by ID (0x15), stores result in struct field.

**Key logic:**
- Calls virtual method at vtable+0x1c on global `DAT_007cd8c0` with arg 0x15
- If result non-null: stores at `param_1 + 0xe0`
- Returns 0

**Globals:**
- `DAT_007cd8c0` — global object with vtable

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0xe0 | void* | Stored resource pointer |

**Used by system:** docs/10-vehicle-physics.md — physics resource reference storage

**Moddability:** hardcoded

<!-- target: docs/08-file-formats.md -->

## FUN_004e2540 — Wheel Suspension/Tire State Init

Source: unknown | Confidence: medium
Per-wheel setup: computes offset, stores velocity/damping, inits tire model.

**Key logic:**
- Computes index into per-wheel array: `param_2 * 0x128 + 0xd4 + param_1`
- Computes velocity = `param_3 - position` (at +0x48, +0x4c, +0x50)
- Stores velocity at offset +0x74 and +0xb8
- Stores params at +0xfc, +0xf8, +0xc4, +0xcc
- Calls FUN_005670d0 for additional init
- Copies 9 ints from +0xd0 to +0x8c (stride: fixed 9 iterations)
- Calls FUN_00567340

**Struct offsets (param_1):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x48 | float | Position X |
| +0x4c | float | Position Y |
| +0x50 | float | Position Z |

**Calls:** FUN_005670d0, FUN_00567340

**Used by system:** docs/10-vehicle-physics.md — per-wheel suspension/tire initialization

**Moddability:** configurable — param_2-6 are caller-supplied

### FUN_005692a0 — 3x3 Inertia Tensor Transform

Double-precision 3x3 symmetric matrix multiply for inertia tensor rotation: R * I * R^T.

**Key logic:**
- Reads 3x3 symmetric matrix from six double pairs at offsets +0x1c/+0xd4, +0x24/+0xdc, +0x2c/+0xe4, +0x34, +0x3c, +0x44, +0x4c, +0x54, +0x5c
- Computes nine output elements of transformed inertia tensor
- Stores result to +0xec through +0x12c (6 doubles + 8 singles from copy)
- Writes final diagonal term at offset 300 (0x12c) as sum-of-squares

**Struct offsets (param_1):**
| Offset | Type | Field |
|--------|------|-------|
| +0x1c/+0xd4 | double[2] | Row 0 scale pair |
| +0x24/+0xdc | double[2] | Row 1 scale pair |
| +0x2c/+0xe4 | double[2] | Row 2 scale pair |
| +0x34/+0x3c/+0x44 | double[3] | Cross terms |
| +0x4c/+0x54/+0x5c | double[3] | Cross terms |
| +0xec–+0xfc | double[3] | Output row 0 |
| +0x104/+0x108 | float[2] | Copy of output row 0 part |
| +0x10c/+0x114 | double[2] | Output rows 1-2 |
| +0x11c/+0x120/+0x124/+0x128 | float[4] | Output copies |
| +0x12c | double | Diagonal term |

**Calls:** none (pure math leaf function)

**Moddability:** hardcoded

<!-- target: docs/18-physics-dynamics.md -->

### FUN_0040ef70 — Physics State Vector Conversion

Source: Unknown. Mode-switched state vector processing — converts float vectors to double, calls transform/math functions, copies results back. Already fully documented in docs/18-physics-dynamics.md (FUN_0040ef70).

**Key logic:**
- Switch on mode at param_1+0x1c (cases 0/1/2/3/4/5, paired into 0/2/4 and 1/3/5)
- Sets output values at target buffer +0x20 and +0x24
- Copies 6 float values to target buffer, converts to double for sub-calls
- Calls FUN_0054b4d0 (6-float transform), FUN_005691d0, FUN_00569280 (math functions)
- Copies 6 more floats to param_2+0x19
- Calls FUN_0040f0d0

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x1c | Mode | processing mode 0-5 |
| +0x20 | DataPtr | target data struct pointer |

**Globals:**
- `DAT_0059e6f8` — offset value added in mode processing

**Calls:** FUN_0054b4d0 (6-float transform), FUN_005691d0, FUN_00569280, FUN_0040f0d0

**Moddability:** hardcoded

**Note:** See full entry in docs/18-physics-dynamics.md

### FUN_004D6AE0 — Vehicle Suspension Force Helper

Simple double-precision multiply-accumulate for suspension/damper force computation.

**Key logic:**
- Computes: ((+0x118 + DAT_0059eac8) × param_2 × DAT_0059eb40 × (+0x40)) + (+0x38)
- Structure at param_1 is a physics vehicle/component instance with offsets +0x38, +0x40, +0x118 as double-precision fields

**Calls:** none

**Moddability:** hardcoded

<!-- target: docs/10-vehicle-physics.md -->

### FUN_004d75d0 — Tire Slip Curve Name Lookup

Linear search through tire brand's slip curve array for a matching name string. Used to resolve curve references from vehicle setup files.

**Key logic:**
- param_1 = tire manager struct: +0x8 = curve count, +0xc = pointer array (stride 0x18)
- param_2 = curve name string to find
- Iterates curves, calls FUN_00588410 (strcmp equivalent) to compare names
- Falls back to DAT_005ea438 if curve pointer is NULL
- Returns pointer to matching curve entry (base + index × 0x18), or 0 on failure
- On failure: logs "Tire brand doesn't have curve name %s" warning

**Globals:**
- `DAT_005ea438` — fallback directory/file path pointer

**Calls:** FUN_00588410 (string compare), FUN_004d7a50 (debug logging), FUN_004d7aa0 (trace output)

**Moddability:** `configurable` — curve names from tire brand .svm files

<!-- target: docs/10-vehicle-physics.md -->

### FUN_00441bb0 — Rigid Body Torque Accumulation

Computes cross-product torque from suspension forces and accumulates into body angular velocity.

**Key logic:**
- Reads body A pointer at param_1+0x15f0, body B pointer at param_1+0x1d4
- Gets orientation matrix via FUN_00435e00(param_1+0x1bc)
- Computes inertia scaling factor: `SQRT(damping * stiffness) * scale` from body fields at +0xac, param_1+0x1d8, +0x1e0
- Computes cross-product torque for X, Y, Z axes from force offset × force vectors using orientation matrix rows
- Applies linear spring/damper forces from offset terms
- Accumulates into body angular velocity at +0x134, +0x13c, +0x144
- Calls FUN_00569b70 (numerical integration) to step state

**Struct offsets (body struct):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x14 | PositionOffset | double, 3rd component |
| +0x6c | ForceTermY | double |
| +0x74 | ForceTermZ | double |
| +0x7c | OrientationRowX | double |
| +0x84 | OrientationRowY | double |
| +0x8c | OrientationRowZ | double |
| +0x100 | SpringOffset | double |
| +0x134 | AngularVelAccumX | double |
| +0x13c | AngularVelAccumY | double |
| +0x144 | AngularVelAccumZ | double |

**Calls:** FUN_00435e00 (orientation matrix extract), FUN_00569b70 (numerical integration)

**Moddability:** `hardcoded`

### FUN_005215DB — SIMD Vector Normalization (RSQRT)

Computes vector normalization using SIMD reciprocal square root approximation. Takes two input vectors (param_2, param_3), computes normalized result into param_1 using Newton-Raphson refinement.

**Key logic:**
- Calls FastExitMediaState() — saves FPU/MMX state for SIMD operations
- Computes dot product of param_2 and param_3 via PackedFloatingMUL + ADD
- Computes reciprocal square root of param_4 using Newton-Raphson iteration:
  - PackedFloatingReciprocalSQRAprox for initial approximation
  - PackedFloatingReciprocalIter1/Iter2 for refinement
  - FloatingReciprocalAprox for accuracy
- Applies sign handling via DAT_005af9d0 mask
- Performs final multiplication: result × param_2 and result × param_3 → stored in param_1[0:1]
- Calls FastExitMediaState() to restore FPU/MMX state

**Globals:**
- `DAT_005af988` — SIMD constant (used in reciprocal computation)
- `DAT_005af9d0` — SIMD sign mask (bitwise AND for sign correction)
- `DAT_005af9e8` — SIMD comparison threshold for iteration gating

**Calls:** FastExitMediaState, PackedFloatingMUL, PackedFloatingADD, PackedFloatingSUB, PackedFloatingAccumulate, PackedFloatingCompareGE, PackedFloatingReciprocalSQRAprox, PackedFloatingReciprocalIter1/Iter2, FloatingReciprocalAprox, FUN_00528f00, FUN_00529700

**Moddability:** `hardcoded` — SIMD math leaf function, uses constants

<!-- target: docs/10-vehicle-physics.md -->

### FUN_0051E2BA — Image Buffer Stride Fill

Fills a destination buffer with repeated pattern data using stride-based division. Processes pixel/byte array with inner loops over rows and columns, computing fill values from position and iteration index.

**Key logic:**
- Reads unaff_ESI[0x69] as source struct pointer, reads unaff_ESI[0x19] as dimension count
- Branch on unaff_ESI[0x19] == 3: sets pattern mode to 0x5d, copies 3 source values to dest header
- Branch else: sets pattern mode to 0x5e
- Calls virtual function via vtable dispatch: (**(code **)(*unaff_ESI + 4))()
- Allocates working buffer via virtual call on unaff_ESI[1]+8
- Nested loop: iterates over dimensions (unaff_ESI[0x19] count), computing fill value `(iVar1/2 + iVar8) / iVar1` for each cell
- Writes computed byte values into destination buffer at calculated offsets
- Stores result pointer and byte count back to source struct at +0x10 and +0x14

**Struct offsets (unaff_ESI):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x00 | VTablePtr | Virtual method table |
| +0x04 | SecondaryPtr | Secondary object with vtable at +8 |
| +0x14 | ModeValue | Pattern mode (0x5d or 0x5e) |
| +0x18 | ByteCount | Bytes to process |
| [+0x19]×4 | DimensionCount | Number of dimensions for stride loop |

**Calls:** FUN_0051e1ef, virtual dispatch via vtable

**Moddability:** `hardcoded` — pixel processing utility

### FUN_00410F60 — SceneNodeDecoder

Decodes packed scene node command and dispatches vertex transform. Reads 6-bit opcode from param_2 header to select data source array, then transforms vertex positions.

**Key logic:**
- Extracts 6-bit opcode from param_2[0] >> 0x12 & 0x3f
- Cases 1-6 select different array sources from param_1 struct (+0x24/+0x2c through +0x60/+0x68)
- Validates index from param_2[2] against array bounds
- Computes data pointer as `index * stride + 0xd0 + base`
- When pointer non-null, calls FUN_0054b4d0 with decoded vertex data (position + normal) scaled by DAT_0059e780 (VertexScaleFactor) and DAT_0059e77c (unknown render scale)
- Byte extraction from packed fields at param_2 offsets +0xa, +0xe, +0x12, +0x13, +0x15, +0x17

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x24 | Size1 | Bounds check for case 1/3/5 arrays |
| +0x2c | BasePtr1 | Data array base for case 1 |
| +0x30 | Size2 | Bounds for case 2 |
| +0x38 | BasePtr2 | Data array base for case 2 |
| +0x3c | Size3 | Bounds for case 3 |
| +0x44 | BasePtr3 | Data array base for case 3 |
| +0x48 | Size4 | Bounds for case 4 |
| +0x50 | BasePtr4 | Data array base for case 4 |
| +0x54 | Size5 | Bounds for case 5 |
| +0x5c | BasePtr5 | Data array base for case 5 |
| +0x60 | Size6 | Bounds for case 6 |
| +0x68 | BasePtr6 | Data array base for case 6 |

**Globals:** DAT_0059e780 (VertexScaleFactor), DAT_0059e77c

**Calls:** FUN_0054b4d0 (scene transform, docs/19)

<!-- target: docs/10-vehicle-physics.md -->

### FUN_0052835F — VectorTransformDSP

Fixed-point vertex transform or DSP mixing function. Performs SIMD-like multiply-accumulate on short arrays with bit manipulation and table lookup.

**Key logic:**
- Reads params from param_1+0x11c (base offset +0x80) and param_2+0x50, param_3+0x30
- First loop (8 iterations): checks short arrays at incrementing offsets; when all zero, uses simple multiply; otherwise computes weighted sum with fixed-point coefficients (0x1b37, -0x1712, 0x73fc, -0x28ba)
- Second loop (2 iterations): writes results to param_4 + param_5, using computed index into lookup table at base offset
- Scaling constants: 0x8000, 0x1000, 0xd (13-bit), 0x14 (20-bit) shift patterns indicate fixed-point math

**Globals:** DAT_0059e780 (VertexScaleFactor)

**Calls:** none (leaf function, no subroutine calls)

<!-- target: docs/10-vehicle-physics.md -->

### FUN_004AF220 — TireCompoundClamp

Clamps tire compound selection for vehicle. Selects compound based on mode at +0x1b34 and clamps within allowed range.

**Key logic:**
- Switch on param_1+0x1b34 (mode selector 1-4):
  - Case 1: sets compound at +0xd98 = 12, compound index +0x1170 = 0
  - Case 2: sets compound at +0xd98 = 14, compound index +0x1170 = 1
  - Case 3: sets compound at +0xd98 = 16, compound index +0x1170 = 2
  - Case 4: sets compound at +0xd98 = 16, compound index +0x1170 = 3
- For each case, clamps +0xd98 between lower bound +0xda0 and upper bound +0xda4
- After selection, clamps compound index (+0x1170) between +0x1178 (min) and +0x117c (max)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x1170 | CurrentFrontCompoundIndex | docs/13 — per docs/13 tire compound |
| +0x1178 | PitStopCount/MinCompound | Lower bound for compound index |
| +0x117c | MaxCompound | Upper bound for compound index |
| +0xd98 | CompoundSelector | Intermediate compound value |
| +0xda0 | CompoundMin | Lower clamp bound |
| +0xda4 | CompoundMax | Upper clamp bound |
| +0x1b34 | TireMode | Mode selector (1-4) |

**Moddability:** `hardcoded` — compound values (12, 14, 16) are constant

<!-- target: docs/10-vehicle-physics.md -->

### FUN_004C6810 — MergeSortLinkedList

Generic merge sort for linked list. Recursively splits list at midpoint, sorts halves, and merges by comparison via FUN_004c5d30.

**Key logic:**
- Walks list to count nodes (linked via offset +4)
- Splits at midpoint (count/2 - 1)
- Recursively sorts both halves via tail recursion
- Merges using FUN_004c5d30(*first_element) for comparison
- Returns sorted list head

**Struct (linked list node):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x00 | Key/Data | Passed to comparison function |
| +0x04 | NextPtr | Next node pointer |

**Calls:** FUN_004c6810 (self, recursive), FUN_004c5d30 (comparator)

<!-- target: docs/10-vehicle-physics.md -->

### FUN_004C2E20 — MergeSortLinkedListByFloat

Generic merge sort for linked list. Sorts by comparing float value at element+4. Same structure as FUN_004C6810 but uses float comparison.

**Key logic:**
- Walks list to count nodes (linked via offset +4)
- Splits at midpoint
- Recursively sorts both halves
- Merges comparing *(float*)(*node_ptr + 4) — ascending order (<= places first)
- Returns sorted list head

**Struct (linked list node):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x00 | DataPtr | Pointer to data element |
| +0x04 | NextPtr | Next node pointer |

**Data element:**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x04 | SortKey | float comparison value |

**Calls:** FUN_004c2e20 (self, recursive)

<!-- target: docs/10-vehicle-physics.md -->

### FUN_005418E0 — SoundInstanceInit

Initializes sound instance struct with default parameters. Sets volume, pitch, position, and copies name string.

**Key logic:**
- Sets param_1+4 = 1.0f (volume), +8 = 1000.0f (pitch), +0xc through +0x20 = 0 (position/velocity)
- Calls FUN_00541cd0 (init audio system state)
- Zeros offsets +0x3c through +0x78
- Sets +0x6c = 90.0f, +0x70 = 75.0f (cone angles), +0x74 = 1.0f (cone outside volume)
- Sets +0x7c = LAB_00484848 (function pointer/callback), +0x80 = 0x22 (flags), +0x84 = -1, +0x88 = 1.0f
- Zeros offsets +0x19c through +0x1b8
- Copies null-terminated param_2 string to +0x8c (name/path)
- Zeros 0x60 bytes starting at +0x9c

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x04 | Volume | 1.0f default |
| +0x08 | Pitch | 1000.0f default |
| +0x0c | Position | Zeroed (3 floats?) |
| +0x6c | InnerConeAngle | 90.0f |
| +0x70 | OuterConeAngle | 75.0f |
| +0x74 | OuterConeVolume | 1.0f |
| +0x7c | CallbackPtr | Function pointer |
| +0x80 | Flags | 0x22 |
| +0x84 | Unset | -1 |
| +0x88 | Scale | 1.0f |
| +0x8c | NameBuffer | String copy destination |

**Calls:** FUN_00541cd0

<!-- target: docs/10-vehicle-physics.md -->

### FUN_0054F5C0 — SceneBatchRenderCheck

Rendering visibility and batching check. Tests if a rendered object is within draw distance and dispatches to appropriate render path.

**Key logic:**
- Checks param_2+0x3c for flag bit 1; if set, returns early
- Compares render counter (DAT_008c5f40) against capacity from param_1+0x1e0
- If param_2 has flag bit 4 (shadow/alternate): calls FUN_0054b570 to reset batch state
  - Sets iVar6+0x14 bit 0x20000000 if not already set
  - Calls D3D device transform via DAT_008b8f24 vtable+4
- When flag bit 0x40 set on iVar6:
  - Computes distance vector (position differences)
  - If squared distance < (radius)^2 and param_3 has bit 0 set:
    - Dispatches to FUN_0054f2f0 (primary) or FUN_0054eed0 (alternate) based on flag bit 4
    - Increments render counter DAT_008c5f40 and returns 0
- Returns 1 if render capacity exceeded (buffer full)

**Globals:** DAT_008c5f40 (render batch counter), DAT_008b8f24 (D3DDeviceWrapperPtr)

**Calls:** FUN_0054b570, FUN_0054f2f0, FUN_0054eed0

## FUN_0051cc8e — Wheel Geometry Data Initialization

Source: Vehicle/WheelSetup.cpp. Initializes wheel position, brake bias, and suspension lookup data arrays.

**Key logic:**
- Gets wheel data array pointer from `this + 0x19c`
- Allocates 4 wheel data blocks via vtable+4 (4-wheel car)
- For each wheel: stores position offset (>> 16), data table pointer (DAT_005b6900), and brake bias
- Iterates data table with complex arithmetic stepping:
  - x position: -0xb2f480 >> 16, increments by +0x166e9 per wheel
  - y position: -0xe25100 >> 16, increments by +0x1c5a2 per wheel
  - ptr table: starts at DAT_005b6900, steps by -0xb6d2 per wheel
  - brake bias: starts at 0x2c8d00, decrements by -0x581a per wheel
- Loop continues while brake bias > -0x2b34e7 (~11310 iterations)

**Struct offsets (this, in_EAX):**
| Offset | Field | Notes |
|--------|-------|-------|
| +4 | allocator | allocation vtable |
| +0x19c | wheel_data_ptr | wheel data array pointer |

**Globals:**
- `DAT_005b6900` — wheel data table (suspension/damper lookup data)

**Calls:** vtable+4 (memory allocation)

**Moddability:** `hardcoded`

---

<!-- target: docs/10-vehicle-physics.md -->

## FUN_0051dfa8 — Vehicle Update Frame Setup

Source: Vehicle/VehicleFrame.cpp. Sets up vehicle frame data for current update tick.

**Key logic:**
- Reads frame data pointer from param_1+0x1a4
- Copies frame counter from frame_data+0x10 to param_1+0x74
- Calls FUN_0051d80a with timestamp from frame_data+0x14
- Sets frame_data+0x1c byte to 1 (frame active)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x74 | frame_counter | current simulation frame |
| +0x1a4 | frame_data_ptr | physics frame data pointer |

**Calls:** FUN_0051d80a

**Moddability:** `hardcoded`

---


<!-- target: docs/10-vehicle-physics.md -->

## FUN_00462410 — Data Table Row Accessor (Stride 0x8C, 35 Dwords)

Source: vehicle/track data accessor. Copies one row from an indexed data table into caller buffer.

**Key logic:**
- Validates param_2 (index) in range [0, this+0x3e14)
- Copies 0x23 (35) dwords from `this + 0x394 + param_2 * 0x8c` into param_3 buffer
- Copies one extra int from `this + 0x3c74 + param_2 * 4` into param_4
- Returns 1 on success, 0 on invalid index

**Struct offsets (param_1 is `*this`):**
| Offset | Size | Field |
|--------|------|-------|
| +0x394 | 0x8c × N | Data table base — stride 0x8c, 35 dwords per row |
| +0x3c74 | int × N | Parallel int table — one int per row index |
| +0x3e14 | int | Table row count |

**Moddability:** hardcoded — table format fixed in code.

**Orphan classification:** `game_logic_isolated` — regular data accessor, no cross-refs found. Called through typed interface (this+0x3e14 count suggests virtual dispatch). Missing edges likely due to function pointer dispatch.

## FUN_004a1ea0 — Reverse Dynamics Stub

Source: ui_dynamics.cpp or vtable wrapper. Delegates to the reverse dynamics/evaluation function.

**Key logic:**
- Passes `a1` straight through to `sub_566650(a1)`
- Returns 1

**Calls:** FUN_00566650 (reverse dynamics evaluation or path processing, docs/10)

**Moddability:** `hookable` — vtable entry point

<!-- target: docs/01-engine-architecture.md -->

## FUN_00435406 — Setup Array Element Setter

Source: setup_data.cpp. Sets three consecutive elements of an array (indices 22, 23, 24) to the same value.

**Key logic:**
- Sets `result[22] = a2` — array element at index 22 (byte offset 0x58)
- Sets `result[23] = a2` — array element at index 23 (0x5C)
- Sets `result[24] = a2` — array element at index 24 (0x60)
- Returns `result` pointer

**Calls:** none

**Moddability:** `configurable` — likely a setup parameter array

<!-- target: docs/01-engine-architecture.md -->

## FUN_00476060 — Car Flag Byte Setter

Source: vehicle.cpp. Sets byte at `this+44` to `a2`.

**Key logic:**
- `this[44] = a2` — stores the byte parameter
- Returns `a2` as result

**Struct offsets (this):**
| Offset | Field | Notes |
|--------|-------|-------|
| +44 | flag_byte | 1-byte vehicle state flag |

**Moddability:** `configurable` — vehicle state flag setter

<!-- target: docs/01-engine-architecture.md -->

## FUN_004db120 — Float Constant Setter

Source: vehicle_init.cpp. Sets `this[4]` to 1092616192 (10.0f as int).

**Key logic:**
- `this[4] = 1092616192` — stores float constant 10.0f

**Struct offsets (this):**
| Offset | Field | Notes |
|--------|-------|-------|
| +16 | value | float, initialized to 10.0 |

**Moddability:** `configurable` — default speed/threshold value

<!-- target: docs/08-file-formats.md -->

## FUN_0051BFA6 — Vehicle Struct Field Copy

Source: vehicle_state.cpp. Copies two vehicle state values from source struct to sub-object.

**Key logic:**
- Reads `v1 = a1[103]` — target sub-object pointer
- Sets `*(v1 + 92) = a1[68]` — copies value at source offset 0x110 (68*4) to target offset 92
- Sets `*(v1 + 96) = a1[24]` — copies value at source offset 0x60 (24*4) to target offset 96
- Returns `a1[24]`

**Struct offsets (a1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x60 (24×4) | SourceValue1 | copied to target+96 |
| +0x110 (68×4) | SourceValue2 | copied to target+92 |

**Calls:** none

**Moddability:** `hardcoded` — vehicle struct internals

<!-- target: docs/01-engine-architecture.md -->

## FUN_0047a080 — Parameter value clamping across array

Source: vehicle_controls.cpp. Clamps a value from `this` vtable+180 against per-parameter bounds across a parameter array at 0x7D1448 with stride 27 floats.

**Key logic:**
- Calls sub_466910 (init)
- Gets v2 from dword_7CD8C0 vtable[28] with arg 8
- Checks this[256] (enable flag), returns 0 if not set
- Gets value v7 via this vtable+180
- Checks sub_490190(v2) (validation)
- Iterates array at 0x7D1448 stride 27 floats (108 bytes):
  - Each entry: v3[0] = value, v3[2] = lower bound, v3[3] = upper bound
  - Sets v3[0] = v7, clamps to [v3[2], v3[3]]
- Ends at flt_7D17A8 (sentinel)

**Globals:**
- `dword_7CD8C0` — system object
- `unk_7D1448` — parameter array base
- `flt_7D17A8` — array end

**Calls:** FUN_00466910 (init), FUN_00490190 (validation)

**Moddability:** hardcoded

<!-- target: docs/10-vehicle-physics.md -->

## FUN_004569b0 — Steering/input smoothing with saturation

Source: vehicle_input.cpp. Scales an input value by direction-dependent factor, accumulates to two state fields with clamping.

**Key logic:**
- Base scale v4 = 0.5; if a3 == 1 → v4 = 2.0
- If LOBYTE(a2) == 0 → v4 = -v4 (negate direction)
- v6 = v4 × a4 (scaled input)
- Adds v6 to this[40], clamps via sub_58957A
- Adds v6 to this[47], clamps via sub_58957A

**Calls:** FUN_0058957A (float saturation/clamp)

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_0044cff4 — Float/float init to (0, 1)

Source: init_parameters.cpp. Initializes two globals to 0.0 and 1.0.

**Key logic:**
- Sets flt_7CC9F4 = 0.0f
- Sets dword_7CC9F8 = 1065353216 (= 1.0f)

**Globals:**
- `flt_7CC9F4` — init to 0.0
- `dword_7CC9F8` — init to 1.0 (0x3F800000)

**Moddability:** hardcoded

<!-- target: docs/10-vehicle-physics.md -->

## FUN_004fc901 — Object field initializer (3 fields)

Source: object_init.cpp. Sets three fields of output struct: result[3]=a2, result[4]=20.0, result[5]=20.0.

**Key logic:**
- result[3] = a2 (parameter)
- result[4] = 20.0f (1101004800 = 0x41A00000)
- result[5] = 20.0f

**Moddability:** hardcoded

<!-- target: docs/10-vehicle-physics.md -->

## FUN_00575875 — Enum value check (== 34)

Source: enum_check.cpp. Trivial comparison: returns a1 == 34.

**Key logic:**
- Returns a1 == 34 (some enum or ID constant)

**Moddability:** hardcoded

<!-- target: docs/19-renderer.md -->

## FUN_00414E54 — PlayerSteeringUpdate

Source: player_steering.cpp. Adds signed delta to steering byte with overflow detection; on valid range, updates ESI position tracking struct.

**Key logic:**
- Adds a1 (signed char delta) to byte at (a2+51) (steering value)
- Checks for overflow/underflow via signed addition overflow flag (__OFADD__) and zero flag
- If no overflow: stores a2 (player struct ptr) at ESI+12 and a1 (delta) at ESI+16
- Executes rcr byte ptr [esi-7Fh], 0C4h (rotate-through-carry — likely flag/state update)

**Struct offsets:**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x33 (51) | SteeringInput | byte, accumulated steering delta |

**Calls:** none (inline asm)

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->

## FUN_004adf10 — Driving Mode Parameter Setup

Source: unknown | Confidence: high
State machine that configures preset parameter values for 6 driving modes (0–5). Reads mode selector at param_1+0x1cc0, sets multiple integer config fields, pushes parameter values to a stack via FUN_004b20d0/FUN_004b1de0, and calls FUN_0047f1f0/FUN_004646c0 for float clamping.

**Key logic:**
- Switch on *(param_1+0x1cc0):
  - Case 0: no-op
  - Case 1 (race): sets 12 fields (values 1–3), calls FUN_0047f1f0 for each, stores 0.25f at +0x1ce4, calls FUN_004646c0
  - Case 2 (quali?): similar pattern, slightly different field values, stores 0.25f at +0x1ce4
  - Case 3 (practice?): sets fields (values 0–1), pushes 4 ints (3,2,2,0) then 0x5f=95 via FUN_004b20d0
  - Case 4: pushes 9 ints via FUN_004b20d0 (0,0,0,0,0,0,3,2,2,0) then 100, then calls FUN_004b1de0(0.25f)
  - Case 5: pushes ints (0,0,0,0,0,0,1,1,1,0) then 100, then calls FUN_004b1de0(0.5f)
  - Default: pushes int 0
- Post-switch: if mode != 0, pushes int 1 and int 100

**Struct offsets (param_1 — config struct):**
| Offset | Type | Notes |
|--------|------|-------|
| +0x1cc0 | int | Mode selector (0–5) |
| +0x214, +0x334, +0x280 | int | Gear/setup config values (0–3) |
| +0x358, +0x2c8, +0x2ec | int | Gear/setup config values (0–3) |
| +0x40c, +0x25c, +0x2a4, +0x310 | int | Gear/setup config values (0–3) |
| +0x1ce4 | float | Config value (0.25f or 0.5f) |
| +0x1cec, +0x1cf0 | float | Pair for FUN_004646c0 |
| +0x1d08 | int | Push value (0x4b=75, 0x55=85, 0x5f=95, 100) |
| +0x1d14 | ptr | Parameter for FUN_0047f1f0 |

**Calls:**
- FUN_0047f1f0 — Float Clamp (docs/20)
- FUN_004646c0 — Float Clamp (docs/20)
- FUN_004b20d0 — Push int to parameter stack (docs/18)
- FUN_004b1de0 — Clamped Float Setter (docs/18)

**Used by system:** docs/20-math-utilities.md

**Moddability:** hardcoded (preset values per mode)

<!-- target: docs/20-math-utilities.md -->

## FUN_004e19d0 — VehicleStateUpdate

Source: vehicle_update.cpp | Confidence: high
Per-tick vehicle state update — processes wheel contacts, team-specific effects, distance-based suspension animation, steering angle, and timer accumulation.

**Key logic:**
- **Wheel contact pass (4 wheels, stride 0x4A ints):** For each wheel corner: checks active flag at base-0x21 and enabled flag at base-0x11, transforms 6 floats via `FUN_0054b4d0`. Checks second contact set. If node pointer at base+6 is non-null, calls `FUN_004e21d0` (node update).
- **Scene node transform pass:** Loops `param_1[0xAF4]` entries from `param_1[0xAF5]` array (stride 0x14). Reads position offsets, transforms via `FUN_0054b4d0`, processes via `FUN_0054c0b0`/`FUN_0054c030`, calls `FUN_005506a0` for each. Iterates `DAT_008ad3ec`-`DAT_008ad3f8` calling `FUN_005506a0`.
- **Player proximity check:** If ScoringGate==2 or active control profile mode 1, race active, same team as player: checks distance to player via `FUN_0040c870`, if less than `DAT_0059f110` threshold -> run suspension animation.
- **Suspension anim (mode `param_1[0x259]`):** 0=reset 4 wheels; 1=reset front+rear pair; 2=conditional on `DAT_007cfcc8`.
- **Steering anim:** If `param_1[0x228]` != 0: angle = `param_1[0x254]` x `DAT_005ad158`, builds matrix, transforms via `FUN_00567120`/`FUN_0054b450`.
- **Player effects:** If `param_1[0x226]` != 0 and byte at +0x96D != 0: if same team as player sends flag=1 via `FUN_0054c030`, loops `param_1[0x22D]` items calling `FUN_00551810`; else flag=0.
- **State sync (4 channels):** Compares bytes at +0x979, +0x975/0x976, +0x977/0x25E — calls `FUN_005506a0` on change for audio/event broadcast.
- **Timer accumulation:** If `param_1[0x22C]` != 0: gets time from `FUN_004b9ce0` (ScoringGate==2, replay) or `DAT_008afea0` (race time). Computes delta from target `param_1[0x261]`, if within `[DAT_0059e440, param_1[0x262])` rounds and writes to `param_1[0x260]`, calls `FUN_005506a0`.

**Struct offsets (param_1 as vehicle struct, int-indexed):**
| Offset (int) | Real offset | Field | Notes |
|---|---|---|---|
| +0x72 | +0x1C8 | WheelContactBase | Per-wheel contact base, stride 0x4A ints |
| +0xAF4 | +0x2BD0 | SceneNodeCount | Node count for transform pass |
| +0xAF5 | +0x2BD4 | SceneNodeArray | Array of node descriptors, stride 0x14 |
| +0x228 | +0x8A0 | SteeringActive | Steering anim enable |
| +0x226 | +0x898 | PlayerEffectFlag | Player effect enable |
| +0x22D | +0x8B4 | PlayerEffectCount | Count of effect targets |
| +0x259 | +0x964 | SuspAnimMode | 0=all4, 1=pair, 2=conditional |
| +0x254 | +0x950 | SteeringScalar | Steering multiplier |
| +0x256 | +0x958 | SteeringAngleBase | Base steering angle |
| +0x35 | +0xD4 | SuspNodeBase | Base for wheel suspension nodes |
| +0x260 | +0x980 | AccumulatedTicks | Timer accumulator output |
| +0x261 | +0x984 | TimerTarget | Timer target value |
| +0x262 | +0x988 | TimerMaxDelta | Max delta for timer change |
| +0x22C | +0x8B0 | TimerAccumEnable | Timer accumulation enable |

**Globals:**
- `DAT_007c54f0` (VehiclePtrArray) — vehicle array for team comparison
- `DAT_007c54dc` (CurrentPlayerIndex) — player index
- `DAT_008ab6e4` (ScoringGate) — if 2, replay mode
- `DAT_007cf7f4` — game mode / race-active flag
- `DAT_005ea518` (ActiveControlProfilePtr) — active input profile
- `DAT_005ea528` — compared with active profile
- `DAT_0059f110` (PhysicsBrakeBias) — distance squared threshold
- `DAT_008afea0` (SessionTime) — current race time
- `DAT_007cfcc8` — queued mode flag
- `DAT_005ad158` — steering animation parameter
- `DAT_0059e43c` — physics constant
- `DAT_0059e450` (NormalizationHalf) — 0.5f
- `DAT_007cf740` (MaxDamageTimer) — timer scale factor

**Calls:**
- FUN_0054b4d0 — 6-float vector/transform (docs/20)
- FUN_004e21d0 — node positional update (docs/10)
- FUN_004e3090 — suspension node reset (docs/10)
- FUN_0054c0b0 — scene/audio state query (docs/06)
- FUN_0054c030 — audio state broadcast (docs/06)
- FUN_005506a0 — audio/event notification (docs/06)
- FUN_0040c870 — player position getter (docs/01)
- FUN_004b9ce0 — replay time getter (docs/06)
- FUN_00567120 — matrix transform (docs/20)
- FUN_0054b450 — 3-float vector transform (docs/20)
- FUN_00551810 — per-target effect dispatch (docs/20)
- FUN_0058957a — random/periodic function (docs/20)

**Used by system:** docs/20-math-utilities.md (triage), docs/10-vehicle-physics.md (actual)

**Moddability:** hardcoded — internal state fields only

<!-- target: docs/17-physics-collision.md -->

