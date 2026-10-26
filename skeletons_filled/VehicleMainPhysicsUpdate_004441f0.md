## VehicleMainPhysicsUpdate_004441f0 — Vehicle Main Physics Per-Frame Update

**Summary:** Main per-frame vehicle physics tick: computes steering input, throttle/brake blending, suspension forces, tire model, aerodynamics, collision avoidance, lap state transitions, and visual state updates. Coordinates all vehicle dynamics subsystems each frame.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehiclePhysicsIntegrationStep (00441650)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(*(this+0xB4)+0x110)+0x110) | 0x110 | R | — | vehicle physics state — deep field read from vehicle dynamics sub-object |
| *(*(this+0x11C)+0x110) | 0x0 | R | — | per-corner wheel force vector X |
| *(*(this+0x11C)+0x110) | 0x8 | R | — | per-corner wheel force vector Y |
| *(*(this+0x1F00)+0x32E0) | 0x78 | R | — | tire contact patch aging / grip degradation counter |
| *(*(this+0x1F00)+0x32E0) | 0x7C | R | — | tire temperature accumulation value |
| *(*(this+0x1F00)+0x32E0) | 0x84 | R | — | tire wear / damage scalar |
| *(*(this+0xB4)+0x10C) | 0x3C | R | — | vehicle body angular velocity Z (yaw rate) |
| *(*(this+0xB4)+0x110) | 0x0 | R | — | vehicle world-space position X |
| *(*(this+0xB4)+0x110) | 0x4 | R | — | vehicle world-space position Y |
| *(*(this+0xB4)+0x110) | 0x8 | R | — | vehicle world-space position Z |
| *(*(this+0xB4)+0x110) | 0x20 | R | — | vehicle forward direction vector X |
| *(*(this+0xB4)+0x110) | 0x24 | R | — | vehicle forward direction vector Y |
| *(*(this+0xB4)+0x110) | 0x28 | R | — | vehicle forward direction vector Z |
| *(*(this+0xB4)+0x110) | 0x2C | R | — | vehicle right direction vector X |
| *(*(this+0xB4)+0x110) | 0x30 | R | — | vehicle right direction vector Y |
| *(*(this+0xB4)+0x110) | 0x88 | R | — | vehicle velocity vector X |
| *(*(this+0xB4)+0x110) | 0x94 | R | — | vehicle velocity vector Y |
| *(*(this+0xB4)+0x110) | 0x98 | R | — | vehicle velocity vector Z |
| *(*(this+0xB4)+0x110) | 0x9C | R | — | vehicle angular velocity X |
| *(*(this+0xB4)+0x110) | 0xA4 | R | — | vehicle angular velocity Y |
| *(*(this+0xB4)+0x110) | 0xA8 | R | — | vehicle angular velocity Z |
| *(*(this+0xB4)+0x110) | 0xAC | R | — | vehicle angular acceleration Z |
| *(*(this+0xB4)+0x110) | 0x110 | R | — | nested vehicle dynamics sub-object pointer |
| *(this+0x11C) | 0x0 | R | — | per-corner suspension force X |
| *(this+0x11C) | 0x4 | R | — | per-corner suspension force Y |
| *(this+0x11C) | 0x8 | R | — | per-corner suspension force Z |
| *(this+0x11C) | 0x20 | R | — | per-corner tire lateral force |
| *(this+0x11C) | 0x24 | R | — | per-corner tire longitudinal force |
| *(this+0x11C) | 0x28 | R | — | per-corner tire vertical load |
| *(this+0x11C) | 0x2C | R | — | per-corner slip angle |
| *(this+0x11C) | 0x30 | R | — | per-corner slip ratio |
| *(this+0x11C) | 0xA4 | R | — | per-corner tire temperature |
| *(this+0x11C) | 0xA8 | R | — | per-corner tire wear |
| *(this+0x11C) | 0xAC | R | — | per-corner tire grip factor |
| *(this+0x11C) | 0x110 | R | — | per-corner dynamics sub-object pointer |
| *(this+0x15F0) | 0x4 | R | — | suspension spring force corner 0 |
| *(this+0x15F0) | 0xC | R | — | suspension damper force corner 0 |
| *(this+0x15F0) | 0x14 | R | — | suspension spring force corner 1 |
| *(this+0x15F0) | 0x1C | R | — | suspension damper force corner 1 |
| *(this+0x15F0) | 0x24 | R | — | suspension spring force corner 2 |
| *(this+0x15F0) | 0x2C | R | — | suspension damper force corner 2 |
| *(this+0x15F0) | 0x34 | R | — | suspension spring force corner 3 |
| *(this+0x15F0) | 0x3C | R | — | suspension damper force corner 3 |
| *(this+0x15F0) | 0x44 | R | — | anti-roll bar force front |
| *(this+0x15F0) | 0x4C | R | — | anti-roll bar force rear |
| *(this+0x15F0) | 0x54 | R | — | aero downforce front |
| *(this+0x15F0) | 0x5C | R | — | aero downforce rear |
| *(this+0x15F0) | 0x64 | R | — | aero drag force |
| *(this+0x15F0) | 0x6C | R | — | engine braking torque |
| *(this+0x15F0) | 0x74 | R | — | drivetrain torque |
| *(this+0x15F0) | 0x7C | R | — | differential torque split |
| *(this+0x15F0) | 0x84 | R | — | wheel rotation speed FL |
| *(this+0x15F0) | 0x8C | R | — | wheel rotation speed FR |
| *(this+0x1630) | 0x0 | RW | — | computed steering input (per-frame) |
| *(this+0x1644) | 0x0 | RW | — | computed throttle/brake blend (per-frame) |
| *(this+0x1F00) | 0x834 | R | — | gearbox current gear |
| *(this+0x1F00) | 0x874 | R | — | engine RPM |
| *(this+0x1F00) | 0x95C | R | — | clutch engagement ratio |
| *(this+0x1F00) | 0x99C | R | — | engine torque output |
| *(this+0x1F00) | 0xA84 | R | — | brake bias front |
| *(this+0x1F00) | 0xAC4 | R | — | brake bias rear |
| *(this+0x1F00) | 0xBAC | R | — | differential locking ratio |
| *(this+0x1F00) | 0xBEC | R | — | traction control intervention |
| *(this+0x1F00) | 0x32E0 | R | — | tire physics state block pointer |
| *(this+0x1F00) | 0x344C | R | — | vehicle speed (m/s) |
| *(this+0x1F00) | 0x3450 | R | — | vehicle state mode (0=stopped, 1=forward, 2=reverse, 3=pitting, 4=grid) |
| *(this+0x1F00) | 0x4064 | R | — | damage accumulation value |
| *(this+0xB4) | 0x20 | R | — | vehicle body velocity X |
| *(this+0xB4) | 0x24 | R | — | vehicle body velocity Y |
| *(this+0xB4) | 0x28 | R | — | vehicle body velocity Z |
| *(this+0xB4) | 0x3C | R | — | vehicle body angular velocity Z |
| *(this+0xB4) | 0x88 | R | — | vehicle body linear velocity X |
| *(this+0xB4) | 0x94 | R | — | vehicle body linear velocity Y |
| *(this+0xB4) | 0x98 | R | — | vehicle body linear velocity Z |
| *(this+0xB4) | 0x9C | R | — | vehicle body angular velocity X |
| *(this+0xB4) | 0xA4 | R | — | vehicle body angular velocity Y |
| *(this+0xB4) | 0xA8 | R | — | vehicle body angular velocity Z |
| *(this+0xB4) | 0xAC | R | — | vehicle body angular acceleration Z |
| *(this+0xB4) | 0x10C | R | — | vehicle body dynamics sub-object |
| *(this+0xB4) | 0x110 | R | — | vehicle rigid-body state sub-object |
| this | 0x0 | RW | 0 | steering input (normalized -1..1 per-frame result) |
| this | 0x4 | RW | 1072693248 → 1.875f | throttle input (normalized 0..1, initialized to 1.875f) |
| this | 0x8 | RW | 0 | brake input (normalized 0..1, initialized 0) |
| this | 0xC | RW | 0 | clutch input (normalized 0..1) |
| this | 0x10 | RW | 0 | handbrake input |
| this | 0x14 | RW | 1072693248 → 1.875f | throttle blend smoothed value |
| this | 0x20 | RW | 0 | steering angle accumulator |
| this | 0x24 | RW | 1072693248 → 1.875f | steering rate of change |
| this | 0x28 | RW | — | steering target angle |
| this | 0x2C | RW | — | steering error |
| this | 0x30 | RW | 0 | steering override flag |
| this | 0x34 | R | — | vehicle session type (5=race, 6=qualifying) |
| this | 0x38 | R | — | vehicle control mode |
| this | 0x40 | RW | — | previous steering direction sign |
| this | 0x48 | RW | — | steering rate limit counter |
| this | 0x4C | RW | — | steering smoothing accumulator |
| this | 0x50 | RW | — | steering deadzone threshold |
| this | 0x54 | RW | — | steering centering force |
| this | 0x58 | RW | — | steering return rate |
| this | 0x60 | R | — | steering input raw (from controller) |
| this | 0x68 | R | — | throttle input raw |
| this | 0x70 | R | — | brake input raw |
| this | 0x71 | R | — | clutch input raw |
| this | 0x72 | R | — | handbrake input raw |
| this | 0x75 | R | — | gear shift mode (1=auto, 2=manual, 3=semi-auto) |
| this | 0x76 | R | — | driving aid flags |
| this | 0x7A | R | — | ABS enabled flag |
| this | 0x7C | R | — | traction control enabled flag |
| this | 0x8C | R | — | stability control enabled flag |
| this | 0x94 | R | — | anti-lock brake state |
| this | 0x9C | R | — | traction control state |
| this | 0xA4 | RW | — | collision avoidance steering override |
| this | 0xA8 | RW | — | collision avoidance throttle override |
| this | 0xAC | R | — | collision avoidance active flag |
| this | 0xB4 | RW | — | vehicle body dynamics sub-object pointer |
| this | 0xD0 | RW | 0 | vehicle state mode (0=garage, 1=track, 2=pit lane) |
| this | 0xEC | RW | 0 | lap state transition accumulator |
| this | 0xF0 | RW | 0 | lap state hold counter |
| this | 0xF4 | RW | 0 | lap distance traveled |
| this | 0xF8 | RW | 0 | sector time accumulator |
| this | 0xFC | RW | 0 | lap time accumulator |
| this | 0x100 | RW | 0 | best lap time |
| this | 0x104 | RW | 0 | previous lap time |
| this | 0x108 | RW | 0 | sector 1 time |
| this | 0x10C | RW | 0 | sector 2 time |
| this | 0x110 | RW | 0 | sector 3 time |
| this | 0x114 | RW | 0 | current lap number |
| this | 0x118 | RW | 0 | total laps completed |
| this | 0x11C | RW | — | per-corner wheel state array pointer |
| this | 0x138 | RW | — | anti-roll bar stiffness front |
| this | 0x140 | R | — | suspension spring rate front |
| this | 0x148 | R | — | suspension spring rate rear |
| this | 0x150 | R | — | suspension damper bump front |
| this | 0x158 | R | — | suspension damper rebound front |
| this | 0x160 | R | — | suspension damper bump rear |
| this | 0x168 | R | — | suspension damper rebound rear |
| this | 0x170 | RW | 0 | ride height front measured |
| this | 0x174 | RW | 0 | ride height rear measured |
| this | 0x178 | R | — | ride height front target |
| this | 0x17C | R | — | ride height rear target |
| this | 0x184 | R | — | spring preload front |
| this | 0x18C | R | — | spring preload rear |
| this | 0x194 | R | — | anti-roll bar stiffness rear |
| this | 0x3C8 | R | — | tire compound front |
| this | 0x3D0 | R | — | tire compound rear |
| this | 0x498 | R | — | aero downforce coefficient |
| this | 0x504 | RW | — | computed downforce front (per-frame) |
| this | 0x508 | RW | — | computed downforce rear (per-frame) |
| this | 0x514 | RW | — | computed drag force (per-frame) |
| this | 0x518 | RW | — | computed lift/drag ratio (per-frame) |
| this | 0x5B0 | R | — | brake disc temperature front |
| this | 0x5B8 | RW | — | brake disc temperature front updated |
| this | 0x5BC | RW | — | brake disc temperature rear updated |
| this | 0x670 | R | — | engine torque at wheels |
| this | 0x690 | RW | 18446744073022356849 | tire contact aging overflow sentinel |
| this | 0x694 | RW | 1083306147 → 4.5606f | tire contact aging threshold |
| this | 0x6D8 | R | — | wheel load front-left |
| this | 0x6DC | R | — | wheel load front-right |
| this | 0x6E0 | R | — | wheel load rear-left |
| this | 0x6E4 | R | — | wheel load rear-right |
| this | 0x6E8 | R | — | tire slip angle front-left |
| this | 0x6EC | R | — | tire slip ratio front-left |
| this | 0x82C | R | — | vehicle mass |
| this | 0x834 | R | — | vehicle inertia X |
| this | 0x8FC | R | — | vehicle inertia Y |
| this | 0xA14 | R | — | vehicle center of mass height |
| this | 0xC90 | R | — | wheelbase |
| this | 0xC98 | R | — | track width front |
| this | 0xD60 | R | — | track width rear |
| this | 0xE78 | R | — | front axle to CG distance |
| this | 0x10F4 | R | — | rear axle to CG distance |
| this | 0x10FC | R | — | CG height above ground |
| this | 0x11C4 | R | — | roll center height front |
| this | 0x12DC | R | — | roll center height rear |
| this | 0x1554 | R | — | camber angle front-left |
| this | 0x155C | R | — | camber angle front-right |
| this | 0x1564 | R | — | camber angle rear-left |
| this | 0x15F0 | R | — | suspension forces array pointer |
| this | 0x1630 | R | — | steering input array pointer |
| this | 0x1634 | R | — | throttle input array pointer |
| this | 0x163C | R | — | brake input array pointer |
| this | 0x1644 | R | — | throttle/brake blend array pointer |
| this | 0x1648 | R | — | clutch input array pointer |
| this | 0x1650 | R | — | handbrake array pointer |
| this | 0x1C50 | R | — | pit lane speed limiter flag |
| this | 0x1C5C | R | — | pit lane entry detection |
| this | 0x1C84 | R | — | DRS activation flag |
| this | 0x1C8C | R | — | DRS zone detection |
| this | 0x1C94 | R | — | ERS deployment mode |
| this | 0x1D30 | RW | 1 | visual state change trigger flag |
| this | 0x1D34 | R | — | visual state current value |
| this | 0x1D3C | R | — | visual state target value |
| this | 0x1D44 | R | — | visual state transition timer |
| this | 0x1E14 | R | — | collision detection sphere radius |
| this | 0x1E38 | R | — | collision response force scale |
| this | 0x1E58 | R | — | proximity warning distance |
| this | 0x1EAC | R | — | opponent vehicle relative position X |
| this | 0x1EB8 | R | — | opponent vehicle relative position Y |
| this | 0x1EF0 | R | — | opponent vehicle index (0xFFFFFFFFFFFFFFFF = none) |
| this | 0x1EF4 | R | — | opponent vehicle distance |
| this | 0x1EF8 | R | — | opponent vehicle closing speed |
| this | 0x1EFC | RW | 0 | collision avoidance steering command |
| this | 0x1F00 | R | — | vehicle configuration/state block pointer |

**Written-by note (persistence):**
- *(this+0x1630) 0x0: recalc every frame — external poke does NOT persist
- *(this+0x1644) 0x0: recalc every frame — external poke does NOT persist
- this 0x0: recalc every frame — external poke does NOT persist
- this 0x4: recalc every frame — external poke does NOT persist
- this 0x8: recalc every frame — external poke does NOT persist
- this 0xC: recalc every frame — external poke does NOT persist
- this 0x10: recalc every frame — external poke does NOT persist
- this 0x14: recalc every frame — external poke does NOT persist
- this 0x20: recalc every frame — external poke does NOT persist
- this 0x24: recalc every frame — external poke does NOT persist
- this 0x28: recalc every frame — external poke does NOT persist
- this 0x2C: recalc every frame — external poke does NOT persist
- this 0x30: recalc every frame — external poke does NOT persist
- this 0x40: recalc every frame — external poke does NOT persist
- this 0x48: recalc every frame — external poke does NOT persist
- this 0x4C: recalc every frame — external poke does NOT persist
- this 0x50: recalc every frame — external poke does NOT persist
- this 0x54: recalc every frame — external poke does NOT persist
- this 0x58: recalc every frame — external poke does NOT persist
- this 0xA4: recalc every frame — external poke does NOT persist
- this 0xA8: recalc every frame — external poke does NOT persist
- this 0xB4: recalc every frame — external poke does NOT persist
- this 0xD0: recalc every frame — external poke does NOT persist
- this 0xEC: recalc every frame — external poke does NOT persist
- this 0xF0: recalc every frame — external poke does NOT persist
- this 0xF4: recalc every frame — external poke does NOT persist
- this 0xF8: recalc every frame — external poke does NOT persist
- this 0xFC: recalc every frame — external poke does NOT persist
- this 0x100: recalc every frame — external poke does NOT persist
- this 0x104: recalc every frame — external poke does NOT persist
- this 0x108: recalc every frame — external poke does NOT persist
- this 0x10C: recalc every frame — external poke does NOT persist
- this 0x110: recalc every frame — external poke does NOT persist
- this 0x114: recalc every frame — external poke does NOT persist
- this 0x118: recalc every frame — external poke does NOT persist
- this 0x11C: recalc every frame — external poke does NOT persist
- this 0x138: recalc every frame — external poke does NOT persist
- this 0x170: recalc every frame — external poke does NOT persist
- this 0x174: recalc every frame — external poke does NOT persist
- this 0x504: recalc every frame — external poke does NOT persist
- this 0x508: recalc every frame — external poke does NOT persist
- this 0x514: recalc every frame — external poke does NOT persist
- this 0x518: recalc every frame — external poke does NOT persist
- this 0x5B8: recalc every frame — external poke does NOT persist
- this 0x5BC: recalc every frame — external poke does NOT persist
- this 0x690: recalc every frame — external poke does NOT persist
- this 0x694: recalc every frame — external poke does NOT persist
- this 0x1D30: recalc every frame — external poke does NOT persist
- this 0x1EFC: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |
| 0059e428 | dbl_59E428 | R | NaNInvalidSentinel [DERIVED] (also: NaN sentinel constant) |
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e478 | flt_59E478 | R | SteeringCenterBoost [DERIVED] |
| 0059e660 | flt_59E660 | R | VehicleBodyDamping [DERIVED] |
| 0059e670 | flt_59E670 | R | SentinelFlagConstant [DERIVED] |
| 0059e7d0 | dbl_59E7D0 | R | AgeThreshold_D [DERIVED] |
| 0059e7d8 | dbl_59E7D8 | R | ThermalInflectionThreshold [DERIVED] (also: ` — inflection point threshold) |
| 0059e7e0 | dbl_59E7E0 | R | LookupThreshold_14 [DERIVED] |
| 0059e84c | flt_59E84C | R | VelocityRateLimit [DERIVED] (also: ` — display message threshold) |
| 0059e868 | flt_59E868 | R | SteeringResponseGain [DERIVED] |
| 0059e880 | dbl_59E880 | R | HalfStep [DERIVED] (also: ` — lower threshold constant) |
| 0059e888 | flt_59E888 | R | TwoPi [DERIVED] (also: ` â€” 2Ï€ (360Â° in radians) |
| 0059e890 | dbl_59E890 | R | YawErrorToleranceRad [DERIVED] (also: ` â€” yaw error tolerance (radians) |
| 0059e8cc | flt_59E8CC | R | WheelSpeedThreshold [DERIVED] (also: ` — wheel speed threshold (not in docs/12) |
| 0059e900 | dbl_59E900 | R | Physics_Double_59E900 [DERIVED] |
| 0059e920 | flt_59E920 | R | SuspensionAntirollFactor [DERIVED] |
| 0059e930 | dbl_59E930 | R | PhysicsDoubleThreshold [DERIVED] |
| 0059ea68 | dbl_59EA68 | R | WheelSpeedFactor [DERIVED] |
| 0059eae8 | dbl_59EAE8 | R | PhysicsDoubleConst_59EAE8 [DERIVED] |
| 0059eb08 | dbl_59EB08 | R | DoublePi [DERIVED] |
| 0059eb28 | dbl_59EB28 | R | Damper2MaxAdd [DERIVED] (also: ` — damper 2 max add (range limit) |
| 0059eb38 | dbl_59EB38 | R | Physics_Double_59EB38 [DERIVED] |
| 0059eb48 | dbl_59EB48 | R | RideHeightThreshold [DERIVED] |
| 0059eb50 | dbl_59EB50 | R | InputScaleFactor [DERIVED] |
| 0059eb78 | dbl_59EB78 | R | PhysicsSuspensionConst [DERIVED] |
| 0059eba0 | dbl_59EBA0 | R | EnergyToDamageScaleFactor [DERIVED] (also: ` — energy-to-damage conversion factor) |
| 0059ec70 | dbl_59EC70 | R | TireMultiplierFactor [DERIVED] |
| 0059edb8 | dbl_59EDB8 | R | ShiftPointFactor [DERIVED] |
| 0059edc8 | dbl_59EDC8 | R | Dynamics_Double_01 [DERIVED] |
| 0059edd0 | dbl_59EDD0 | R | Renderer_DoubleConstant_59EDD0 [DERIVED] |
| 0059edd8 | dbl_59EDD8 | R | WheelLoadTransferScale [DERIVED] |
| 0059ede0 | dbl_59EDE0 | R | TirePhysicsDoubleConst2 [DERIVED] |
| 0059ede8 | dbl_59EDE8 | R | TireBrush_LatForce [DERIVED] |
| 0059edf0 | dbl_59EDF0 | R | Unknown_Double_59EDF0 [DERIVED] |
| 0059edf8 | dbl_59EDF8 | R | TireContactGain [DERIVED] |
| 0059ee00 | dbl_59EE00 | R | TireBrushDoubleConst [DERIVED] |
| 0059ee08 | dbl_59EE08 | R | TireTempIntegration2 [DERIVED] |
| 0059ee10 | dbl_59EE10 | R | Unknown_Double_59EE10 [DERIVED] |
| 0059ee18 | dbl_59EE18 | R | Double_Unknown_Dynamics2 [DERIVED] |
| 0059ee20 | dbl_59EE20 | R | TireSlipThreshold [DERIVED] |
| 0059ee28 | dbl_59EE28 | R | AntiOverturningMoment [DERIVED] |
| 0059ee30 | dbl_59EE30 | R | TireWearAccumFactor [DERIVED] |
| 0059ee38 | dbl_59EE38 | R | TorqueSplitRatio [DERIVED] |
| 0059ee40 | dbl_59EE40 | R | Unknown_Double_Engine [DERIVED] |
| 0059ee48 | dbl_59EE48 | R | ConstraintSolverConst [DERIVED] |
| 0059ee50 | flt_59EE50 | R | Dynamics_Float_01 [DERIVED] |
| 0059ee58 | dbl_59EE58 | R | Renderer_DoubleConstant_59EE58 [DERIVED] |
| 0059ee60 | dbl_59EE60 | R | AntiRollBarStiffness [DERIVED] |
| 0059ee68 | flt_59EE68 | R | PhysicsConstant_59EE68 [DERIVED] |
| 0059ee70 | dbl_59EE70 | R | TireDoubleConstant_59EE70 [DERIVED] |
| 0059ee78 | dbl_59EE78 | R | PhysicsDoubleConst [DERIVED] |
| 0059ee80 | flt_59EE80 | R | TirePhysicsFloatConst [DERIVED] |
| 0059ee84 | flt_59EE84 | R | TireBrush_RollingResist [DERIVED] |
| 0059ee88 | flt_59EE88 | R | Unknown_Float_59EE88 [DERIVED] |
| 0059ee8c | flt_59EE8C | R | QualityThresholdHigh [DERIVED] |
| 0059ee90 | flt_59EE90 | R | ContactPatchScale [DERIVED] |
| 0059ee94 | flt_59EE94 | R | TireBrushSlipGain [DERIVED] |
| 0059ee98 | dbl_59EE98 | R | TireTempIntegration [DERIVED] |
| 0059eea0 | dbl_59EEA0 | R | Unknown_Double_59EEA0 [DERIVED] |
| 0059eea8 | dbl_59EEA8 | R | Double_Unknown_Dynamics [DERIVED] |
| 0059eeb0 | dbl_59EEB0 | R | TireSlipParam [DERIVED] |
| 0059eeb8 | dbl_59EEB8 | R | DampingForceMult [DERIVED] |
| 005c329c | dword_5C329C | R | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 005ea2c0 | dword_5EA2C0 | R | SetupScenePtr [DERIVED] |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |
| 007ca590 | ppvOut | R | ModulePtrArray [DERIVED] |
| 007cc184 | dword_7CC184 | R | Renderer_ColorConstant_7CC184 [DERIVED] |
| 007cc1b0 | dword_7CC1B0 | R | Dynamics_StateDWORD [DERIVED] |
| 007cc1b8 | dword_7CC1B8 | R | TireForceConstant [DERIVED] |
| 007cc1bc | dword_7CC1BC | R | VehicleDynamicsParam [DERIVED] |
| 007cc1dc | dword_7CC1DC | R | PhysicsStateFlag [DERIVED] |
| 007cc33c | dword_7CC33C | R | VehicleClassIndex [DERIVED] |
| 007cc368 | dword_7CC368 | R | Unknown_Ptr_7CC368 [DERIVED] |
| 007ce6d0 | dword_7CE6D0 | R | MultiplayerOptionFlag [DERIVED] |
| 007ce8c8 | flt_7CE8C8 | R | PhysicsFloatConst [DERIVED] |
| 007ce8ec | flt_7CE8EC | R | SuspensionDamperRate [DERIVED] |
| 007ce910 | dword_7CE910 | R | UIWidgetDataSource [DERIVED] |
| 008aae70 | dword_8AAE70 | RW | RingBufferCounter (QA/weather noise) [DERIVED] |
| 008aae74 | flt_8AAE74 | R | TrigLookup256 [DERIVED] (also: ` — 256-entry trig lookup table) |
| 008ab274 | flt_8AB274 | R | WeatherNoiseTable [DERIVED] (also: � random noise table (docs/12) |
| 008acee0 | dword_8ACEE0 | R | ForceFeedbackBase [CONFIRMED] |
| 008acfb4 | flt_8ACFB4 | R | IdleSpeedTarget [DERIVED] (also: ` â€” idle/reverse speed target) |
| 008acfd4 | dword_8ACFD4 | R | Int_RaceConfig_CFD4 [DERIVED] |
| 008acfd8 | dword_8ACFD8 | R | RaceTimeAccumulator [DERIVED] |
| 008ad078 | dword_8AD078 | R | AudioVisDataPtr [DERIVED] |
| 008afee8 | flt_8AFEE8 | R | TrackGripBase [DERIVED] |
| 008afeec | flt_8AFEEC | R | TrackGripComparison [DERIVED] (also: ` — additive globals) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00403640 | sub_403640 | bounding volume / collision tree lookup helper |
| 004352c0 | PlaneLineIntersectionRatio | computes intersection ratio of a line with a plane |
| 004361d0 | F_3DVectorTransformBy33Matrix | transforms a 3D vector by a 3x3 rotation matrix |
| 004388d0 | Mat3x3MulVec | multiplies a 3x3 matrix by a 3D vector |
| 00443af0 | BoundingVolumeHierarchyTraversalFilter | collision BHV tree traversal with filtering |
| 00443b70 | Gearbox | gearbox shift logic and gear selection |
| 00447c70 | VisualStateChange | triggers visual state transitions (e.g. pit entry/exit) |
| 00447e00 | PositionLapStateUpdate | updates lap/position state machine |
| 00454da0 | sub_454DA0 | input processing — maps controller inputs to vehicle commands |
| 004d1100 | ConditionalDelegateDispatch | conditional virtual dispatch to delegate handler |
| 004d1140 | RenderCallWithGuard | guarded render call with state validation |
| 004ef6c0 | CoordinateTransformWithOffset | coordinate frame transform with position offset |
| 004efb20 | F_3DTransformWithMatrixMultiplication | 3D transform using matrix multiplication chain |
| 004f87c0 | HUDElementConfig | configures HUD element visibility/parameters |
| 0054b950 | SceneNodePositionGetter | retrieves world-space position of a scene node |
| 00566e40 | EulerToRotationMatrix | converts Euler angles to 3x3 rotation matrix |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(*(this+0x1F00)+0x32E0) | 0x78 | != | 2 | tire contact aging mode — BLOCKS if == 2 (aged out contact patch) |
| *(this+0x1F00) | 0x3450 | == | 4 | vehicle state mode == 4 (grid) — BLOCKS physics when on starting grid |
| this | 0x34 | == | 6 | session type == 6 (qualifying) — enables qualifying-specific steering behavior |
| this | 0x34 | == | 5 | session type == 5 (race) — enables race-specific steering behavior |
| this | 0x34 | > | 3 | session type > 3 (active session) — PASSES for race/qualifying/practice |
| this | 0x75 | != | 3 | gear shift mode != 3 (not semi-auto) — BLOCKS semi-auto shift logic |
| this | 0xD0 | != | 2 | vehicle state != 2 (not in pit lane) — BLOCKS pit limiter logic |
| this | 0x1D30 | != | 1 | visual state change trigger != 1 — BLOCKS visual transition |
| this | 0x1EF0 | == | 18446744073709551615 | opponent index == 0xFFFFFFFFFFFFFFFF (no opponent) — BLOCKS collision avoidance |
| this | 0x1EF0 | == | 1 | opponent index == 1 (opponent exists) — PASSES collision avoidance |

**Guard interpretation:** The function gates on vehicle state mode (0x3450==4 blocks physics on starting grid), session type (0x34==5/6 enables session-specific behavior), gear shift mode (0x75!=3 blocks semi-auto), vehicle pit state (0xD0!=2 blocks pit limiter), and opponent presence (0x1EF0==0xFFFFFFFFFFFFFFFF blocks collision avoidance). Tire contact aging uses the mode field at 0x78: !=2 means contact patch is still valid and physics can proceed. Visual state transitions gate on the trigger flag at 0x1D30.
