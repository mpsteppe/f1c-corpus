=== TRIAGE LINES ===

=== FULL ENTRIES ===
<!-- target: docs/01-engine-architecture.md -->
### FUN_0042d5d0 — Game::Setup()

Game state machine state 2. Initializes game subsystems after Enter().

**Key logic:**
- Sets param_1[0] = 2 (state)
- Gate: if FUN_004a0eb0 (steward init) returns nonzero → abort early (return 1)
- Calls HWInput::Setup, Sound::Setup, OnScreen::Setup, VidMan::Setup in sequence
- Gate: if FUN_004b1870 (replay/Bink) returns nonzero → abort (return 1)
- Calls SpecialFX::Setup, FUN_004d36d0 (sound), FUN_0042c170 (game), FUN_00463ef0

**Calls:** FUN_004f9160 (player file load), FUN_004a0eb0 (steward init), FUN_004b1870 (replay/Bink setup), FUN_00455c60 (HWInput::Setup), FUN_004c8ab0 (Sound::Setup), FUN_0049ef70 (OnScreen::Setup), FUN_004fa2f0 (VidMan::Setup)

<!-- target: docs/01-engine-architecture.md -->
### FUN_004c8a20 — Sound::Enter()

Sound module initialization — first call in sound lifecycle.

**Key logic:**
- Debug log entry
- If FUN_004c82c0 returns 0 → calls FUN_004c82f0 (fallback path)
- Calls FUN_004c83b0, FUN_004c8560, FUN_004c8900(DAT_007cf380) — configures sound with display handle
- Calls FUN_004184f0 (audio mixer)
- Initiates two channels via FUN_004116c0(0) and FUN_004116c0(1)

<!-- target: docs/01-engine-architecture.md -->
### FUN_0049f0d0 — OnScreen::Post()

OnScreen display manager post-update tick. Called each frame after state transitions.

**Key logic:**
- Debug log entry
- Calls FUN_004d8720 (session state tick)
- Calls FUN_0049d150 (HUD/overlay update)
- Calls FUN_0049b1c0 (display element update)

**Calls:** FUN_004d8720 (session state), FUN_0049d150 (HUD update), FUN_0049b1c0 (display elements)

<!-- target: docs/01-engine-architecture.md -->
### FUN_004fa320 — VidMan::Init()

Video manager initialization. Sets up display, render state, and loads scene file.

**Key logic:**
- Sets DAT_008afe70 = 0; configures display mode (FUN_0053d400) with DAT_007cf65c
- Sets display resolution from DAT_007cfbfc (width) and DAT_007cfc20 (height)
- Branches on DAT_007cfb90 (render mode: 1, 2, or 3) → calls FUN_0054a1c0 to set D3D render states
- Resolves scene file path from DAT_008ac48c (current scene index) into SceneArray (DAT_008ac490, stride 0x18c); strips directory to get scene name
- Loads scene via FUN_0053c800; also loads season path from DAT_005ec3d8 + DAT_005ec428
- Calls FUN_00546010(&DAT_008afe88, scenePath, 0) — scene init; if 0 → loads placeholder scene, returns 0
- Error handler prints "CUBE error loading scene file %s: %s"

**Calls:** FUN_0053d400 (display mode), FUN_0054a1c0 (render state), FUN_004c55b0 (settings), FUN_00546010 (scene init), FUN_0053c800 (scene load), FUN_00546230 (scene manager)

<!-- target: docs/01-engine-architecture.md -->
### FUN_0040cce0 — CamMan::Post()

Camera manager post-update. Releases temporary camera objects and resets state.

**Key logic:**
- Clears param_1+0x08 (current camera pointer) to 0
- Calls FUN_004083e0 (camera transform update)
- Releases 3 camera objects at param_1+0x18, +0x1c, +0x20 via vtable dispatch(1) then nulls them
- Sets param_1+0x2e (flag) to 0

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x08 | CurrentCamera | Pointer, cleared to 0 |
| +0x18 | CameraObj1 | Released via vtable |
| +0x1c | CameraObj2 | Released via vtable |
| +0x20 | CameraObj3 | Released via vtable |
| +0x2e | Flag | Set to 0 |

**Calls:** FUN_004083e0 (camera transform)

<!-- target: docs/09-track-system.md -->
### FUN_004d4a80 — Telemetry Data Dump

Debug telemetry logger. Outputs comprehensive vehicle state data to log stream via FUN_004d5be0.

**Key logic:**
- Gate: checks VehicleCount > 0, DAT_007ce9d0 > 0, and (SessionType != 7 or DAT_007ce9f4 != 0)
- Finds first vehicle in VehiclePtrArray (DAT_007c54f0) with param_2+13000 == 0 (active)
- Generates random 4-byte seed, computes XOR-based session identifier (DAT_007c935c ^ 0x516141f2)
- Outputs labeled telemetry for each wheel: wheelspin, suspension deflection, ride height, tire temps (left/center/right), tire pressure, tire wear, corner weight
- Outputs vehicle-level: water temp, oil temp, RPM, clutch, throttle, brake, steering (raw/filtered), elapsed time, position, yaw, accelerations
- Reads vehicle struct: DriverName (+0x4620), VehicleDescription (+0x4678), FilePath (+0x4714), data at +0x4794, UnknownID1 (+0x4898) for vehicle file lookup

**Struct offsets (param_2 - vehicle):**
| Offset | Field |
|--------|-------|
| +0x4620 | DriverName |
| +0x4678 | VehicleDescription |
| +0x4714 | FilePath |
| +0x4794 | Data field |
| +0x4898 | UnknownID1 |

**Globals:**
- `DAT_007c56a4` — SessionType (7 = race, gates output)
- `DAT_005c329c` — VehicleCount
- `DAT_007c54f0` — VehiclePtrArray
- `DAT_007ce9d0` — telemetry enable flag
- `DAT_007ce9f4` — telemetry gate flag
- `DAT_008ac488` — SceneFileCount
- `DAT_008ac394` — VehicleArray (stride 0x424)
- `DAT_007ce5ec` — settings file path
- `DAT_007ce5d0` — scene file path

**Calls:** FUN_004d5be0 (log output), FUN_0042bc10 (telemetry allowed?), FUN_004d5840 (time stamp), FUN_00587db0 (random), FUN_00588678 (RNG seed), FUN_004ceef0, FUN_004f34e0, FUN_0042e320, FUN_004f4270, FUN_004b3c60, FUN_00568a60, FUN_00566650, FUN_00588410, FUN_0042ddd0, FUN_004d5af0

<!-- target: docs/09-track-system.md -->
### FUN_004cfed0 — SpecialFX::Post()

Special effects manager post-update cleanup. Frees all allocated effect arrays.

**Key logic:**
- Sets param_1[0] = 0 (LPTREE count)
- Frees LPTREE array (param_1[1]): iterates each element calling FUN_004ca280, then frees array via FUN_00587bcf
- Calls FUN_0044c470 (particle cleanup)
- Frees feedback array (param_1[3]): iterates FUN_00499ae0 per element, then frees
- Zeros param_1[2] (feedback count)
- Frees loose material array (param_1[5]): iterates FUN_004ca410 per element, then frees
- Zeros all remaining struct fields param_1[0] through param_1[0xb]

**Struct offsets (param_1):**
| Offset | Field |
|--------|-------|
| [0] | LPTREE count |
| [1] | LPTREE array ptr |
| [2] | Feedback count |
| [3] | Feedback array ptr |
| [4] | Loose material count |
| [5] | Loose material array ptr |
| [6]–[0xb] | Zeros |

**Calls:** FUN_004ca280 (LPTREE destroy), FUN_00499ae0 (feedback destroy), FUN_004ca410 (loose material destroy), FUN_00587bcf (free), FUN_0044c470 (particle cleanup)

<!-- target: docs/10-vehicle-physics.md -->
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
