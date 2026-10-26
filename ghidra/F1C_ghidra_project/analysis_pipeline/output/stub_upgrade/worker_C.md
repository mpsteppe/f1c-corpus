=== TRIAGE LINES ===

=== FULL ENTRIES ===

<!-- target: docs/01-engine-architecture.md -->
### FUN_0042D7A0 — Game::Restart()

Game module restart — state 4 in game lifecycle. Sets param_1[0]=4, then calls restart on all subsystems.

**Key logic:**
- Sets internal state to 4 (Restart phase)
- Calls 19 subsystem restart/init functions in sequence: NetComm (FUN_00464290), Sound (FUN_004c8b20), Steward (FUN_004a40f0), RaceTimer (FUN_004a0fb0), Session (FUN_004d3cf0), HWInput (FUN_00455da0), CamMan (FUN_0040c9e0), Render (FUN_004b4060), OnScreen (FUN_0049f000), VidMan (FUN_004fa640), replay, OS, and scene rendering
- Returns 0

**Calls:** FUN_00464290 (NetComm, docs/21), FUN_004c8b20 (Sound::Restart, docs/01), FUN_004a40f0 (steward init, docs/01), FUN_004a0fb0 (race timer, docs/06), FUN_00455da0 (HWInput::Restart, docs/01), FUN_0040c9e0 (CamMan::Restart, docs/01), FUN_004b4060 (Render::Restart, docs/01), FUN_0049f000 (OnScreen::Restart, docs/01), FUN_004fa640 (VidMan::Restart, docs/01)

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->
### FUN_004C8AE0 — Sound::Init()

Sound module init — single subsystem call with profile logging.

**Key logic:**
- Profile entry trace (source: sound.cpp)
- Delegates to FUN_004c7ca0 (sound hardware init)

**Calls:** FUN_004c7ca0 (sound init, docs/01)

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->
### FUN_00455BF0 — HWInput::Enter()

Hardware input manager enter — cursor hide and control binding init.

**Key logic:**
- Profile entry trace (source: hwinput.cpp)
- Calls FUN_0044f4e0 (cursor initialization)
- Loops ShowCursor(0) until cursor hidden (returns -1)
- Calls FUN_00455290 (control binding setup)
- If DAT_007d13a0 (input mode flag) == 1, calls FUN_004f8ae0 (input device init)
- Returns 0

**Calls:** FUN_0044f4e0 (cursor init), FUN_00455290 (control binding, docs/01), FUN_004f8ae0 (input device)

**Globals:** DAT_007d13a0 (input mode flag, docs/01)

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->
### FUN_004FAC00 — VidMan::Post()

Video manager post — scene release and path cleanup.

**Key logic:**
- Profile entry trace (source: vidman.cpp)
- Calls FUN_004f8ea0 (post-render operations)
- Releases scene handle via FUN_005461b0(DAT_008afe88), then zeros DAT_008afe88
- Resets render state via FUN_0053d400(0)
- Extracts directory from current scene path: indexes SceneArray (DAT_008ac490, stride 0x18c) by CurrentSceneIndex (DAT_008ac48c), strips filename leaving directory
- Calls FUN_0053c900(local_200) with extracted directory

**Calls:** FUN_004f8ea0 (post-render), FUN_005461b0 (scene release), FUN_0053d400 (render state reset), FUN_0053c900 (file/directory operation)

**Globals:** DAT_008afe88 (scene handle), DAT_008ac48c (CurrentSceneIndex, docs/12), DAT_008ac490 (SceneArray, docs/12)

**Moddability:** hardcoded

<!-- target: docs/01-engine-architecture.md -->
### FUN_004A1930 — OSMan::Exit()

OS manager exit — closes application mutex handle.

**Key logic:**
- Profile entry trace (source: osman.cpp)
- Calls CloseHandle(DAT_007ce2d8) — releases "F1 Challenge 99-02_APP_MUTEX"

**Calls:** CloseHandle (Win32 API)

**Globals:** DAT_007ce2d8 (mutex handle, docs/01)

**Moddability:** hardcoded

<!-- target: docs/09-track-system.md -->
### FUN_004CA480 — Material Shader/Reaction Effect Parser

Parses an .MTS file section to configure particle/shader material effects: smoke types, shader flags, scale/growth/duration envelopes.

**Key logic:**
- Reads "REACTION" token via FUN_00565520; compares against 14 smoke/particle type names: REACTION (clear), WHITESMOKE=1, BLUESMOKE=2, BLACKSMOKE=3, FLAMES=4, SPRAY=5, SOFTSKID=7, WETSKID=8, GROOVE=9, WETGROOVE=10, PARTICLE=0xb, SPARK=0xc, (last)=0xd
- Assigns type code to param_1+4
- Parses numeric fields via FUN_00565870: SCALE (XYZ float3), GROWTH, GROWTHVEL, DURATION, ASDENVELOPE, POWER, RAMPSPEED, OFFSETVEL
- RAMPSPEED clamped: if below DAT_0059e43c → set to 1.0; if above DAT_0059eae0 → set to FLT_MAX
- ASDENVELOPE multiplied by global DAT_0059e8b4 for type 5 (SPRAY) when FUN_004f9230 returns < 0x18
- Reads NUMWAYPOINTS via FUN_00565520
- Allocates 0xb0-byte object at param_1+0x50 via operator_new + FUN_00557350 (D3D material/shader init)
- Initializes material flags at offsets +0x20, +0x58, +0x5c, +0x60, +0x64, +0x66, +0x68, +0x70, +0x38, +0x90 with render state constants
- Parses VERTEX, PIXEL, CHROMA, COLOR, DESTBLEND, ASRCBLEND shader sections setting render state bits

**Calls:** FUN_00565520 (INI string reader), FUN_00565870 (INI float reader), FUN_00557350 (D3D material object constructor), FUN_004cad30 (color parser), FUN_004cada0 (blend mode parser), FUN_004f9230 (renderer query), FUN_004b0170 (string op), FUN_00587bcf (memory free)

**Globals:** DAT_0059e8b4 (ASD envelope scale), DAT_0059e43c (physics constant), DAT_0059eae0 (FLT_MAX constant)

**Moddability:** configurable — REACTION type, SCALE, GROWTH, DURATION, etc. read from .MTS files

<!-- target: docs/10-vehicle-physics.md -->
### FUN_004D6AE0 — Vehicle Suspension Force Helper

Simple double-precision multiply-accumulate for suspension/damper force computation.

**Key logic:**
- Computes: ((+0x118 + DAT_0059eac8) × param_2 × DAT_0059eb40 × (+0x40)) + (+0x38)
- Structure at param_1 is a physics vehicle/component instance with offsets +0x38, +0x40, +0x118 as double-precision fields

**Calls:** none

**Moddability:** hardcoded

<!-- target: docs/10-vehicle-physics.md -->
### FUN_0043E770 — Wheel Collision Contact Flag Setter

Sets collision contact flags on vehicle struct based on wheel contact pairs.

**Key logic:**
- Computes per-wheel base: param_2 × 0x464 + 0x28c + param_1
- Checks if collider at +0x160 is zero (inactive):
  - Inactive: marks +0x1c4 as 1; iterates collision contact arrays at offsets +0x15b4/+0x15b8 (stride 0x30) and +0x15bc/+0x15c0 (stride 0x30) — if wheel collider matches contact pair (IDs at +4 and +0xc), sets bit 0 at +0x2c
  - Active: marks +0x200 as 1; iterates collision array at +0x15c4/+0x15c8 (stride 0x48) — if wheel ID matches at +4 or +0xc, sets bit 0 at +0x44
- Uses fields at param_1+0x141c (reference ID) and +0x15b4/+0x15b8/+0x15bc/+0x15c0/+0x15c4/+0x15c8 (collision contact arrays) as part of vehicle collision system

**Struct offsets (vehicle struct):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x141c | CollisionRefID | Reference identifier for contact matching |
| +0x15b4 | ContactCount1 | Count of contacts in first array |
| +0x15b8 | ContactArray1 | Array of contact entries (stride 0x30) |
| +0x15bc | ContactCount2 | Count of contacts in second array |
| +0x15c0 | ContactArray2 | Array of contact entries (stride 0x30) |
| +0x15c4 | ContactCount3 | Count of contacts in third array |
| +0x15c8 | ContactArray3 | Array of contact entries (stride 0x48) |

**Calls:** none

**Moddability:** hardcoded

<!-- target: docs/10-vehicle-physics.md -->
### FUN_004D6AE0 — Temperature/Energy Delta (cross-reference)

Already documented in docs/06-session-race-logic.md (## FUN_004d6ae0 — Temperature/Energy Delta). Thermal delta formula for engine/component temperature. Included here for vehicle physics completeness.

**Key logic:**
- `(param_1[0x118] + DAT_0059eac8) × dt × DAT_0059eb40 × param_1[0x40] + param_1[0x38]`
- Called from vehicle thermal/compliance functions (docs/18)

**Struct offsets:**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x38 | ThermalBase | Double — base temperature |
| +0x40 | ThermalCoeff | Double — scaling coefficient |
| +0x118 | ThermalInput | Double — input delta |

**Globals:** DAT_0059eac8 (thermal constant), DAT_0059eb40 (position scaling constant, docs/12)

**Calls:** none

**Moddability:** hardcoded
