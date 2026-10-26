# Chain: Game::Init — Full game initialization sequence

Seed: FUN_0042d6b0  |  System: docs/01-engine-architecture.md  |  Depth: 6  |  Functions: ~80

---

## Overview

Game::Init (FUN_0042d6b0) is called by Game Main Entry (FUN_0045b200) during game startup. It sets the game state machine to state 3 (Init), then initializes all major game subsystems in sequence: replay system, video manager, hardware input, physics globals, special effects, camera manager, sound system, renderer, on-screen display, and session state. If VidMan::Init fails, the function aborts with error code 1. The chain ends with subsystem-specific initialization — each callee is a self-contained module init that reaches leaf utility functions (memory allocation, TLS access, critical section operations) within 4-6 levels.

## Call Tree

```
FUN_0042d6b0 — Game::Init  [trigger: Game Main Entry calls during startup, GameState → 3]
  +-- FUN_004ba1f0 — Replay Playback Loader  [replay system init]
  |     +-- FUN_004b9da0 — MenuActionDispatch  [state dispatch]
  |     |     +-- FUN_004b81a0 — SortedLinkedListInsert  [playback list build]
  |     |     +-- FUN_004b8360 — Sprite/Overlay Display List Cleanup  [mem cleanup → free wrapper]
  |     |     +-- FUN_004b8480 — Linked List Destructor  [play start]
  |     |     +-- FUN_004b84f0 — SortedListSeekByValue  [pause]
  |     |     +-- FUN_004b85d0 — Linked List Priority Search  [stop]
  |     +-- FUN_00566b20 — AudioStreamOpen  [file I/O for replay data]
  |     +-- FUN_00568540 — File Attributes + Existence Check  [timer/sync]
  |     +-- FUN_00566c00 — File Write with Backend Dispatch  [packet streaming]
  |     +-- FUN_00423a00 — Binary Search in String Table  [string copy]
  |     +-- [3 additional leaves]
  +-- FUN_004fa320 — VidMan::Init  [video manager init — gates rest of init]
  |     +-- FUN_00546010 — Audio Engine Initialization  [scene/mixer init]
  |     +-- FUN_004c55b0 — Track/Scene Loader  [settings]
  |     +-- FUN_0053d400 — Single Global Setter  [display mode]
  |     +-- FUN_0054a1c0 — Bitmask Global Set/Clear  [render state]
  |     +-- FUN_0053c800 — String Registry  [scene load]
  |     +-- FUN_00546230 — Short Computation / Global Setter Pair  [scene manager]
  +-- FUN_00455d50 — HWInput::Init  [hardware input init]
  |     +-- FUN_004d7a50 — String Split Loop  [trace guard]
  |     +-- FUN_004d7aa0 — Debug Log Write  [trace printf]
  |     +-- FUN_004532d0 — AudioSceneUpdateLoop  [input init]
  |     +-- FUN_004533a0 — Global State Initializer  [input init]
  |     +-- FUN_00453560 — Camera/Viewport Config Batch  [input init]
  +-- FUN_004cf070 — SpecialFX::Init  [special effects init]
  |     +-- FUN_004cef30 — Light/Display Iteration  [config lookup]
  |     +-- FUN_004ca480 — Material Shader/Reaction Effect Parser  [shader parse]
  |     +-- FUN_004c9fb0 — ParticleCollisionSpawn  [particle init]
  |     +-- FUN_00568a60 — Weighted Running Checksum  [file checksum]
  +-- FUN_0042c1a0 — DynMan::Init  [dynamics manager]
  +-- FUN_0040c920 — CamMan::Init  [camera manager]
  +-- FUN_004c8ae0 — Sound::Init  [sound manager]
  +-- FUN_004b4030 — Render::Init  [renderer]
  +-- FUN_0049efa0 — OnScreen::Init  [on-screen display]
  +-- FUN_004a1830 — Windows Message Pump with Sleep  [message pump]
  +-- FUN_00463f70 — Session Type Setter  [session state]
  +-- [4 undocumented leaf callees: FUN_004bdc10, FUN_004fcaa0, FUN_004d38f0, FUN_004040a0]
```

## Step-by-Step Trace

### Level 0: FUN_0042d6b0 — Game::Init

**Trigger:** Called from Game Main Entry (FUN_0045b200) during engine startup
**Called by:** FUN_0045b200 (Game Main Entry / Initialization)
**Purpose:** Sets GameState to 3 (Init), initializes all major subsystems

**Key actions:**
1. Sets `*param_1 = 3` (GameState = Init)
2. Calls FUN_004ba1f0 (replay/load state init)
3. Calls FUN_004fa320 (VidMan::Init) — abort with code 1 if fail
4. Calls subsystem inits: HWInput, SpecialFX, DynMan, CamMan, Sound, Render, OnScreen, session

**Data passed to callees:** param_1 = game state struct pointer

### Level 1: FUN_004ba1f0 — Replay Playback Loader

**Trigger:** Called from Game::Init
**Called by:** FUN_0042d6b0 (Game::Init)
**Purpose:** Initializes replay playback system, loads replay data if available

**Key actions:**
1. Calls FUN_004b9da0 (state update) for playback state management
2. Reads file I/O for replay data via FUN_00566b20 / FUN_00568540
3. Sets up packet streaming via FUN_00566c00
4. Calls FUN_004b9830, FUN_004b9810, FUN_004b9820 for replay buffer/flag management
5. Post-load config via FUN_0042bbd0 / FUN_0042bc40

### Level 1: FUN_004fa320 — VidMan::Init

**Trigger:** Called from Game::Init — gate: if returns non-zero, Game::Init aborts
**Called by:** FUN_0042d6b0 (Game::Init)
**Purpose:** Initializes video/scene manager, sets up rendering context

**Key actions:**
1. Calls FUN_00546010 (audio engine init — sound mixer/scene setup)
2. Calls FUN_004c55b0 (track/scene loader settings)
3. Sets up display mode, render state, scene loading

**Data passed to callees:** param_1 = video manager struct pointer

### Level 2: FUN_00546010 — Audio Engine Initialization

**Trigger:** Called from VidMan::Init
**Called by:** FUN_004fa320 (VidMan::Init)
**Purpose:** Audio engine initialization — mixer setup, sample init, processing chain

**Key actions:**
1. Calls FUN_00543fa0 (mixer init — vertex buffer allocation, scene management)
2. Calls FUN_00543a80 (sample init — memory allocation with fallback)
3. Calls FUN_00549170, FUN_00549380, FUN_00549440, FUN_00549470 (processing chain setup)
4. Audio mode init, channel allocation, buffer flush, cleanup

**Subtree (FUN_00543fa0):** 19 callees including scene list constructor, linked-list walk, cleanup functions, init structs with defaults

### Level 1: FUN_00455d50 — HWInput::Init

**Trigger:** Called from Game::Init
**Called by:** FUN_0042d6b0 (Game::Init)
**Purpose:** Initializes hardware input devices (keyboard, mouse, joystick/wheel)

**Key actions:**
1. Debug trace guard/printf via FUN_004d7a50/004d7aa0
2. Input init with dispatch to FUN_004532d0
3. Global state initialization via FUN_004533a0 → FUN_004530a0 (mode dispatch)
4. Camera/viewport config batch via FUN_00453560

### Level 1: FUN_004cf070 — SpecialFX::Init

**Trigger:** Called from Game::Init
**Called by:** FUN_0042d6b0 (Game::Init)
**Purpose:** Initializes special effects system (particles, weather, lighting)

**Key actions:**
1. Light/display iteration via FUN_004cef30 — config lookup, string table search
2. Material shader parser via FUN_004ca480 — INI float/string reader, D3D material constructor, hex color parser
3. Particle collision spawn via FUN_004c9fb0 — linked-list accessor, bounding box computation
4. Weighted running checksum via FUN_00568a60 — file I/O with getc/lock

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| Game::Init | GameState (param_1) | Set to 3 | state 3 = Init |
| Game::Init | VidMan::Init return | Abort if non-zero | error code 1 |
| Replay Init | Replay file data | Load + sort | playback-ready list |
| VidMan::Init | Video settings | Init renderer + scene | rendering context |
| HWInput::Init | Input devices | Enumerate + register | input pipeline ready |
| SpecialFX::Init | FX config files | Parse shaders/particles | effect system ready |

## Globals Written in This Chain

| Global | Name | Written by | Value meaning |
|--------|------|-----------|---------------|
| *param_1 | GameState | FUN_0042d6b0 | Set to 3 (Init) |
| DAT_007c54e0 | PlayerVehiclePtr+8 | FUN_004a00a0 | Current driver reference |
| DAT_007c54dc | CurrentPlayerIndex | FUN_004a00a0 | Current player index |

## Notes

- FUN_004ba1f0 has 17 callees — most complex subtree in this chain. 12 are listed as leaf after the 5 most complex.
- FUN_004fa320 (VidMan::Init) gates the entire rest of initialization — if it returns non-zero, Game::Init returns 1 immediately.
- 4 callees of Game::Init are undocumented: FUN_004bdc10, FUN_004fcaa0, FUN_004d38f0, FUN_004040a0
- FUN_00543fa0 (mixer init under VidMan) has 19 callees — deepest tree with many utility/cleanup leaves.
- Cross-system handoff: FUN_004cf070 → docs/09-track-system.md (SpecialFX), FUN_004c8ae0 → docs/01-engine-architecture.md (Sound)

---
