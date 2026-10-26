## VehiclePhysicsInitializer_00439210 — Vehicle Physics Suspension/Tire Setup Initializer

**Summary:** Initializes vehicle physics parameters for suspension geometry, tire model, weight distribution, and collision energy. Computes ride height per corner, spring/damper rates from setup data, center of mass position, inertia tensor, and sets up per-corner force computation structures. Called each frame from TireModelInit to recalculate physics constants before the main physics update.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** TireModelInit (0043e050)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1114) | 0x4 | R | — | rear-right corner: ride height target from setup data |
| *(this+0x1114) | 0xC | R | — | rear-right corner: spring rate |
| *(this+0x1114) | 0x14 | R | — | rear-right corner: damper rate |
| *(this+0x141C) | 0x4 | R | — | front-left corner: ride height |
| *(this+0x141C) | 0xC | R | — | front-left corner: spring rate |
| *(this+0x141C) | 0x14 | R | — | front-left corner: damper bump |
| *(this+0x141C) | 0x1C | R | — | front-left corner: damper rebound |
| *(this+0x141C) | 0x24 | R | — | front-left corner: anti-roll bar stiffness |
| *(this+0x141C) | 0x2C | R | — | front-left corner: tire pressure |
| *(this+0x141C) | 0x34 | R | — | front-left corner: camber angle |
| *(this+0x141C) | 0x3C | R | — | front-left corner: toe angle |
| *(this+0x141C) | 0x44 | R | — | front-left corner: caster angle |
| *(this+0x141C) | 0x4C | R | — | front-left corner: track width offset |
| *(this+0x141C) | 0x54 | R | — | front-left corner: wheelbase offset |
| *(this+0x141C) | 0x5C | R | — | front-left corner: roll center height |
| *(this+0x141C) | 0xAC | R | — | front-left corner: suspension travel |
| *(this+0x15B0) | 0xAC | R | — | rear-left corner: suspension travel |
| *(this+0x15F0) | 0x4 | R | — | corner 0: computed ride height |
| *(this+0x15F0) | 0xC | R | — | corner 0: computed spring force |
| *(this+0x15F0) | 0x14 | R | — | corner 1: computed ride height |
| *(this+0x15F0) | 0x1C | R | — | corner 1: computed spring force |
| *(this+0x15F0) | 0x24 | R | — | corner 2: computed ride height |
| *(this+0x15F0) | 0x2C | R | — | corner 2: computed spring force |
| *(this+0x15F0) | 0x34 | R | — | corner 3: computed ride height |
| *(this+0x15F0) | 0x3C | R | — | corner 3: computed spring force |
| *(this+0x15F0) | 0x44 | R | — | corner 0: computed damper force |
| *(this+0x15F0) | 0x4C | R | — | corner 1: computed damper force |
| *(this+0x15F0) | 0x54 | R | — | corner 2: computed damper force |
| *(this+0x15F0) | 0x5C | R | — | corner 3: computed damper force |
| *(this+0x15F0) | 0xAC | RW | — | corner 0: computed suspension travel (per-frame) |
| *(this+0x15F0) | 0xB4 | RW | — | corner 0: computed suspension velocity (per-frame) |
| *(this+0x1D4) | 0xAC | RW | 0 | vehicle body sub-object: field at 0xAC (zeroed per-frame) |
| *(this+0x1D4) | 0xB0 | RW | 1072693248 → 1.875f | vehicle body sub-object: field at 0xB0 (init 1.875f per-frame) |
| *(this+0x1D4) | 0xB4 | RW | 0 | vehicle body sub-object: field at 0xB4 (zeroed per-frame) |
| *(this+0x1D4) | 0xB8 | RW | 1072693248 → 1.875f | vehicle body sub-object: field at 0xB8 (init 1.875f per-frame) |
| *(this+0x1F00) | 0x738 | RW | — | vehicle config: ride height front target (per-frame) |
| *(this+0x1F00) | 0x73C | RW | — | vehicle config: ride height rear target (per-frame) |
| *(this+0x1F00) | 0x740 | RW | — | vehicle config: spring preload offset (per-frame) |
| *(this+0x1F00) | 0x76C | R | — | vehicle config: track width front |
| *(this+0x1F00) | 0x8C8 | R | — | vehicle config: wheelbase |
| *(this+0x1F00) | 0x8CC | R | — | vehicle config: CG height |
| *(this+0x3EC) | 0xAC | R | — | vehicle dynamics: suspension travel limit |
| *(this+0xCB0) | 0x4 | R | — | per-corner struct array: corner 0 ride height |
| *(this+0xCB0) | 0xC | R | — | per-corner struct array: corner 0 spring rate |
| *(this+0xCB0) | 0x14 | R | — | per-corner struct array: corner 0 damper rate |
| this | 0xD4 | RW | — | vehicle body: position X (per-frame) |
| this | 0xDC | RW | — | vehicle body: position Y (per-frame) |
| this | 0xE4 | RW | — | vehicle body: position Z (per-frame) |
| this | 0x1D4 | R | — | vehicle body sub-object pointer |
| this | 0x1E8 | R | — | vehicle mass |
| this | 0x3E8 | R | — | vehicle wheelbase |
| this | 0x3EC | R | — | vehicle suspension travel |
| this | 0x400 | RW | — | computed weight distribution front (per-frame) |
| this | 0x420 | RW | — | computed roll stiffness front (per-frame) |
| this | 0x428 | RW | — | computed roll stiffness rear (per-frame) |
| this | 0x430 | RW | — | computed pitch stiffness (per-frame) |
| this | 0x451 | RW | 1 | byte flag for per-corner processing (set to 1 = active) |
| this | 0x454 | RW | 0 | per-corner ride height index (zeroed) |
| this | 0x458 | RW | 0 | per-corner spring rate index (zeroed) |
| this | 0x45C | RW | — | per-corner damper rate (per-frame) |
| this | 0x464 | RW | — | per-corner anti-roll bar (per-frame) |
| this | 0x46C | RW | 0 | per-corner tire pressure (zeroed) |
| this | 0x470 | RW | 0 | per-corner camber (zeroed) |
| this | 0xCB0 | R | — | per-corner setup data array pointer |
| this | 0x1114 | R | — | rear-right corner setup data sub-pointer |
| this | 0x141C | R | — | front-left corner setup data sub-pointer |
| this | 0x1420 | RW | — | per-corner processing: computed value (per-frame) |
| this | 0x1428 | RW | 0 | per-corner processing: index (zeroed) |
| this | 0x142C | RW | 0 | per-corner processing: counter (zeroed) |
| this | 0x1430 | RW | — | per-corner processing: computed damper (per-frame) |
| this | 0x1448 | RW | — | per-corner processing: spring preload (per-frame) |
| this | 0x1450 | RW | — | per-corner processing: ride height offset (per-frame) |
| this | 0x15AC | R | — | vehicle state: suspension mode flag |
| this | 0x15B0 | R | — | vehicle state: rear suspension travel |
| this | 0x15B4 | R | — | vehicle state: front suspension travel |
| this | 0x15B8 | R | — | vehicle state: rear roll stiffness |
| this | 0x15BC | R | — | vehicle state: front roll stiffness |
| this | 0x15C0 | R | — | vehicle state: rear spring rate |
| this | 0x15C4 | R | — | vehicle state: front spring rate |
| this | 0x15C8 | R | — | vehicle state: rear damper rate |
| this | 0x15F0 | R | — | per-corner suspension forces array pointer |
| this | 0x15F4 | RW | — | per-corner: corner 0 ride height computed (per-frame) |
| this | 0x15F8 | RW | — | per-corner: corner 0 spring force computed (per-frame) |
| this | 0x1614 | RW | — | per-corner: corner 1 ride height computed (per-frame) |
| this | 0x161C | RW | — | per-corner: corner 1 spring force computed (per-frame) |
| this | 0x1624 | RW | — | per-corner: corner 1 damper force computed (per-frame) |
| this | 0x1F00 | R | — | vehicle configuration block pointer |
| this | 0x1F34 | RW | — | computed CG position Z (per-frame) |

**Written-by note (persistence):**
- *(this+0x15F0) 0xAC: recalc every frame — external poke does NOT persist
- *(this+0x15F0) 0xB4: recalc every frame — external poke does NOT persist
- *(this+0x1D4) 0xAC: recalc every frame — external poke does NOT persist
- *(this+0x1D4) 0xB0: recalc every frame — external poke does NOT persist
- *(this+0x1D4) 0xB4: recalc every frame — external poke does NOT persist
- *(this+0x1D4) 0xB8: recalc every frame — external poke does NOT persist
- *(this+0x1F00) 0x738: recalc every frame — external poke does NOT persist
- *(this+0x1F00) 0x73C: recalc every frame — external poke does NOT persist
- *(this+0x1F00) 0x740: recalc every frame — external poke does NOT persist
- this 0xD4: recalc every frame — external poke does NOT persist
- this 0xDC: recalc every frame — external poke does NOT persist
- this 0xE4: recalc every frame — external poke does NOT persist
- this 0x400: recalc every frame — external poke does NOT persist
- this 0x420: recalc every frame — external poke does NOT persist
- this 0x428: recalc every frame — external poke does NOT persist
- this 0x430: recalc every frame — external poke does NOT persist
- this 0x451: recalc every frame — external poke does NOT persist
- this 0x454: recalc every frame — external poke does NOT persist
- this 0x458: recalc every frame — external poke does NOT persist
- this 0x45C: recalc every frame — external poke does NOT persist
- this 0x464: recalc every frame — external poke does NOT persist
- this 0x46C: recalc every frame — external poke does NOT persist
- this 0x470: recalc every frame — external poke does NOT persist
- this 0x1420: recalc every frame — external poke does NOT persist
- this 0x1428: recalc every frame — external poke does NOT persist
- this 0x142C: recalc every frame — external poke does NOT persist
- this 0x1430: recalc every frame — external poke does NOT persist
- this 0x1448: recalc every frame — external poke does NOT persist
- this 0x1450: recalc every frame — external poke does NOT persist
- this 0x15F4: recalc every frame — external poke does NOT persist
- this 0x15F8: recalc every frame — external poke does NOT persist
- this 0x1614: recalc every frame — external poke does NOT persist
- this 0x161C: recalc every frame — external poke does NOT persist
- this 0x1624: recalc every frame — external poke does NOT persist
- this 0x1F34: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |
| 0059e880 | dbl_59E880 | R | HalfStep [DERIVED] (also: ` — lower threshold constant) |
| 0059ea58 | dbl_59EA58 | R | TireFormulaConstant [DERIVED] (also: /60/50/48 � Tire formula constants) |
| 0059ea60 | dbl_59EA60 | R | DampingFactorB [DERIVED] (also: ` — angular threshold for partial response) |
| 0059eba8 | dbl_59EBA8 | R | Dbl_59EBA8_Physics [DERIVED] |
| 0059ebb0 | dbl_59EBB0 | R | Unknown_Double_59EBB0 [DERIVED] |
| 0059ebb8 | dbl_59EBB8 | R | PositionTransitionConst [DERIVED] |
| 0059ebc0 | dbl_59EBC0 | R | SuspensionDoubleConst [DERIVED] |
| 0059ebc8 | dbl_59EBC8 | R | Unknown_Double_59EBC8 [DERIVED] |
| 0059ebd0 | dbl_59EBD0 | R | Double_Unknown_Physics [DERIVED] |
| 0059ebd8 | dbl_59EBD8 | R | Unknown_Double_59EBD8 [DERIVED] |
| 0059ebe0 | dbl_59EBE0 | R | DoubleConst_59EBE0 [DERIVED] |
| 0059ebe8 | dbl_59EBE8 | R | ContactStiffnessScale [DERIVED] |
| 0059ebf0 | dbl_59EBF0 | R | AntiRollBarStiffness [DERIVED] |
| 0059ebf8 | dbl_59EBF8 | R | Unknown_Double_Damper [DERIVED] |
| 0059ec00 | dbl_59EC00 | R | DamperCoefficientB [DERIVED] |
| 0059ec08 | dbl_59EC08 | R | Physics_ConstantDouble_01 [DERIVED] |
| 005c41dc | aVehicleHasZero | R | VehicleHasZeroString [DERIVED] |
| 005c421c | aDDevF119992002 | R | SourcePathPrefix [DERIVED] |
| 007c569c | dword_7C569C | R | SessionType5 (5=server) [DERIVED] (also: ` — SessionType5 (guards dev logging) |
| 007ce958 | dword_7CE958 | R | TireModelMode [DERIVED] |
| 008ad254 | dword_8AD254 | R | StateFlagPair [DERIVED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00435e00 | Matrix3x3VectorMultiply | multiplies 3x3 matrix by vector |
| 004361d0 | F_3DVectorTransformBy33Matrix | transforms 3D vector by 3x3 rotation matrix |
| 004388d0 | Mat3x3MulVec | multiplies 3x3 matrix by 3D vector |
| 004390a0 | CollisionEnergy | computes collision energy for damage model |
| 0043aee0 | TransformApply3D | applies 3D transform to point |
| 0043b040 | FrontSteeringGeometrySetup | sets up front steering geometry parameters |
| 0043b590 | SteeringGeometryComputation | computes steering geometry angles |
| 0043bb00 | DeltaUpdateTracking | tracks delta updates for physics state |
| 004d6ae0 | VehicleSuspensionForceHelper | computes suspension force from spring/damper rates |
| 004d7570 | CompoundIndexLookup | looks up tire compound index from setup |
| 004d7880 | TireBrandLookup | looks up tire brand from setup data |
| 004d7a50 | StringSplitLoop | string split loop for dev logging |
| 004d7aa0 | DebugLogWrite | writes debug log message |
| 0054b3b0 | ThreeFieldSetterWithSubCall | sets three fields and calls sub-function |
| 005691d0 | F_3x3RotationTensorMatrixTransform | transforms rotation tensor matrix |
| 005697a0 | StructCopyWithReciprocalDivision | copies struct and applies reciprocal division |
| 0056bd40 | EulerAnglesTo33RotationMatrix | converts Euler angles to 3x3 rotation matrix |
| 0056bde0 | sub_56BDE0 | sub-function for rotation matrix setup |
| 0056cf70 | F_3x3MatrixVectorMultiply | multiplies 3x3 matrix by vector |
| 0056d020 | F_3x3MatrixInverseCoordinateTransform | inverse coordinate transform using 3x3 matrix |
| 0056d1c0 | RelativeVelocityCompute | computes relative velocity between bodies |
| 0056d2d0 | sub_56D2D0 | sub-function for relative velocity post-processing |
| 00588570 | FloatConvertWrapper | wraps float conversion for normalization |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x3EC | == | 0 | suspension travel == 0 — BLOCKS certain branch paths (no travel = no computation) |
| this | 0x15AC | > | 0 | suspension mode flag > 0 — PASSES into suspension geometry computation |
| this | 0x15B4 | <= | 0 | front suspension travel <= 0 — BLOCKS (invalid/negative travel) |
| this | 0x15B4 | > | 0 | front suspension travel > 0 — PASSES into front suspension setup |
| this | 0x15BC | > | 0 | front roll stiffness > 0 — PASSES into anti-roll bar computation |
| this | 0x15C4 | > | 0 | front spring rate > 0 — PASSES into spring rate computation |

**Guard interpretation:** Suspension travel must be positive (0x3EC != 0, 0x15B4 > 0) to enable physics computation. The suspension mode flag (0x15AC > 0) gates the overall suspension geometry setup. Individual corner parameters (spring rate, roll stiffness) gate their respective computation branches. When values are <= 0, the corresponding physics calculations are skipped.
