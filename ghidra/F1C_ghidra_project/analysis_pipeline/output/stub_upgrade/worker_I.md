=== TRIAGE LINES ===

=== FULL ENTRIES ===
<!-- target: docs/01-engine-architecture.md -->
### FUN_0042c9f0 — DynMan::Post

Post-frame update for Dynamic Manager (dynman.cpp). Logs entry, runs per-vehicle update loop, then calls post-update hooks.

**Key logic:**
- Logs "Entered DynMan::Post()" via debug tracing
- Iterates VehicleCount (DAT_005c329c) times calling FUN_004c6e80 (per-vehicle post-update)
- Calls FUN_0043e230 (physics post-step), FUN_0042bd60 (AI/strategy update), FUN_0040fb30 (session/game post-update)

**Calls:** FUN_004c6e80 (per-vehicle post-update), FUN_0043e230 (physics), FUN_0042bd60 (AI), FUN_0040fb30 (game state)

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->
### FUN_0049efa0 — OnScreen::Init

On-screen display initialization (onscreen.cpp). Logs entry, initializes screen overlay system, sets up cockpit LEDs per vehicle.

**Key logic:**
- Logs "Entered OnScreen::Init()" via debug tracing
- Calls FUN_004d8220 (screen/overlay system init)
- If VehicleCount (DAT_005c329c) > 0, calls FUN_0049ca00 (per-vehicle cockpit LED/gauge init)
- Calls FUN_0045bbe0 and FUN_0049b0a0 (additional HUD/screen setup)

**Calls:** FUN_004d8220, FUN_0049ca00 (cockpit LED init), FUN_0045bbe0, FUN_0049b0a0

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->
### FUN_004fa000 — VidMan::Enter

Video manager entry/initialization (vidman.cpp). Detects display device from player file, initializes 3D renderer, or launches 3DCONFIG.EXE if device mismatch.

**Key logic:**
- Logs "Entered VidMan::Enter()", initializes performance timer (FUN_00568be0)
- Checks if already initialized via FUN_0053d470; returns 1 if so
- Reads display device name from PlayerFile (DAT_005ec488) or uses "No Device" string
- Compares device name against current config; if match → initializes 3D: FUN_004f9160 (device create), FUN_004f91b0 (display mode), FUN_004f9420 (viewport), FUN_004f9310 (render state)
- If no match → launches 3DCONFIG.EXE via CreateProcessA, returns 1
- Calls FUN_004f9f00, FUN_005434a0 (render setup), FUN_0055c060, FUN_00494690 (texture surface init)

**Calls:** FUN_00568be0 (timer), FUN_0053d470, FUN_0053d890, FUN_004f9160, FUN_004f91b0, FUN_004f9420, FUN_004f9310, FUN_004f9f00, FUN_005434a0, FUN_0055c060, FUN_00494690, CreateProcessA

**Moddability:** configurable — reads device name from PlayerFile (DAT_005ec488) and display settings from DAT_005ec48c

<!-- target: docs/01-engine-architecture.md -->
### FUN_0040c920 — CamMan::Init

Camera manager initialization (camera.cpp). Registers MAINVIEW camera, clears camera state globals, calls sub-system inits.

**Key logic:**
- Logs "Entered CamMan::Init()" via debug tracing
- Registers "MAINVIEW" camera view via FUN_00544f50, stores handle to param_1[0]
- Zeroes camera position globals DAT_005ea550–558 and DAT_005ea500–508
- Initializes camera subsystems: FUN_0040c240, FUN_0040c3b0, FUN_0040c520
- Sets param_1+0x2d = 0 (some camera state byte)
- If FUN_0040c140 (camera config check) returns 0, copies param_1[6] → param_1[2]
- Calls FUN_0054a200(0x20, 1) (scene graph/visibility init)

**Calls:** FUN_00544f50 (view registration), FUN_0040c240, FUN_0040c3b0, FUN_0040c520, FUN_0040c140, FUN_0054a200

**Moddability:** hardcoded

<!-- target: docs/08-file-formats.md -->
### FUN_004c6980 — SetDriverName

Sets driver name string on vehicle struct. Full entry at docs/06-session-race-logic.md.

**Key logic:**
- Copies param_2 (driver name) to param_1+0x4620 via strncpy with max 63 chars
- Null-terminates at param_1+0x465f
- Calls FUN_004c6a10 (name post-processing / hash compute)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x4620 | DriverName | char[64], copied from param_2 |
| +0x465f | NullTerminator | Always 0 |

**Calls:** FUN_004c6a10 (name post-process)

**Moddability:** hardcoded — utility setter

<!-- target: docs/09-track-system.md -->
### FUN_004cf070 — SpecialFX::Init

Special effects system initialization (specialfx.cpp). Parses CMAPS.MAS archive to load track effects, feedback materials, reaction triggers, and tree models.

**Key logic:**
- Determines scene path from CurrentSceneIndex (DAT_008ac48c) into SceneArray (DAT_008ac490), stride 0x18c
- Opens CMAPS.MAS file via FUN_00587db0; logs error "Could not open %s" if missing
- Parses TRACKVARS section: reads key=value pairs, allocates track effect entries (0x28-byte objects), stores position/name at FUN_004c9d10 result+0x20/0x24
- Parses FEEDBACK section: counts REACTION entries, tracks INCLUDETRACKS/EXCLUDETRACKS per track
- Parses LOOSE section: counts REACTION entries
- Allocates two arrays: track effects (param_1[3], stride 0x6c) and feedback entries (param_1[5], stride 0x6c)
- For each FEEDBACK track: allocates REACTION materials via FUN_004ca480, links to track effect slots
- Constructs path from SeasonDir (DAT_005ec3d8) and SeasonName (DAT_005ec428)
- Loads CMAPS.MAS search paths for additional content
- Categorizes effect types into param_1[6..10] slots by type code (0xc, 0xd, 1, 3, 4)
- Reads AIDryGrip and AIWetGrip parameters from config via FUN_004c58a0
- Counts LPTREE scene nodes and allocates tree model array (param_1[1], stride 0x3c)
- Initializes collision system (FUN_0044c0e0) and track grid (FUN_0044c4c0)

**Calls:** FUN_004ceef0, FUN_00587db0, FUN_00587ca0, FUN_00587c20, FUN_005651b0, FUN_00565520, FUN_004c9d10, FUN_004c58a0, FUN_004ca480, FUN_004caed0, FUN_004cdd80, FUN_004c9fb0, FUN_0044c0e0, FUN_0044c4c0, FUN_0058815f, FUN_00587f64, FUN_00587d02

**Moddability:** configurable — reads AIDryGrip, AIWetGrip from track config (moddable in .gdb files per docs/16)

<!-- target: docs/10-vehicle-physics.md -->
### FUN_004af220 — Tire Compound Selector

Selects tire compound based on race mode, clamps to valid bounds. Full entry at docs/02-ai-system.md.

**Key logic:**
- Switch on param_1+0x1b34 (mode selector 1-4):
  - Case 1: default compound=12 (option), clamp to [+0xda0, +0xda4], set current index +0x1170=0 (soft)
  - Case 2: default compound=14 (medium), clamp, index=1
  - Case 3: default compound=16 (hard), clamp, index=2
  - Case 4: default compound=16, no index set (front-only)
- After switch: clamps +0x1170 to range [+0x1178, +0x117c] (compound index bounds)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x1b34 | ModeSelector | 1-4, compound type |
| +0xd98 | CompoundValue | Selected value (12/14/16) |
| +0xda0 | MinBound | Clamp lower |
| +0xda4 | MaxBound | Clamp upper |
| +0x1170 | CurrentCompoundIndex | 0-3, per docs/13 |
| +0x1178 | CompoundMin | Index lower bound |
| +0x117c | CompoundMax | Index upper bound |

**Moddability:** hardcoded — compound values hardcoded per mode

<!-- target: docs/10-vehicle-physics.md -->
### FUN_0054f5c0 — Scene Node Distance Cull / Render Dispatch

Distance-based scene node culling and render dispatch. Full entry at docs/17-physics-collision.md.

**Key logic:**
- Checks param_2+0x3c flags bit 2 — skip if set (already processed)
- Checks DAT_008c5f40 (audio/render handle) against capacity in param_1+0x1e0
- Checks param_2+0x3c bit 0x10 for secondary render path selection
- Computes distance between node position (param_1+0x204) and reference node (iVar6) using world-space delta
- If within squared distance threshold (fVar3²), dispatches render: FUN_0054f2f0 (primary path) or FUN_0054eed0 (secondary path)
- Uses DAT_008b8f24 (D3DDeviceWrapperPtr, docs/12) for D3D transform if bit 0x20000000 not set

**Calls:** FUN_0054b570, FUN_0054f2f0, FUN_0054eed0

**Moddability:** hardcoded
