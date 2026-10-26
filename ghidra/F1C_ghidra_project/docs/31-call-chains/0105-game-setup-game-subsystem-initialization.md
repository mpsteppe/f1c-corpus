# Chain: Game::Setup() — Game Subsystem Initialization

Seed: FUN_0042d5d0  |  System: docs/01-engine-architecture.md  |  Depth: 3  |  Functions: 9

---

## Overview

Game state machine state 2 entry. Initializes all game subsystems: player file loading, options/steward, replay/Bink, hardware input, sound, on-screen display, and video manager. Gated on steward init success — aborts early if steward init returns nonzero.

## Call Tree

```
FUN_0042d5d0 — Game::Setup()  [game state machine state 2]
  +-- FUN_004f9160 — Global Index Setter / Utility [player file load]
  |     +-- FUN_0055bfc0 — utility
  |     +-- FUN_0055bfd0 — utility
  +-- FUN_004a0eb0 — Options::Setup() [steward init]
  |     +-- FUN_004f9f00 — Conditional Init
  |     +-- FUN_004537b0 — options read
  |     +-- FUN_00485b90 — UI setup
  |     +-- FUN_004186f0 — driver table
  |     +-- FUN_004f9ad0 — render config
  |     +-- FUN_004f9f30 — Conditional State Reset
  +-- FUN_004b1870 — PlayerFile::Setup [replay/Bink setup]
  |     +-- FUN_004d7a50 — Trace Gate
  |     +-- FUN_004d7aa0 — Debug Log Write
  |     +-- FUN_004b0770 — Bink setup
  |     +-- FUN_004b0540 — replay init
  +-- FUN_00455c60 — HWInput::Setup()
  |     +-- FUN_0044ee10 — input device enum
  |     +-- FUN_0044fa60 — keyboard setup
  |     +-- FUN_0044fbe0 — mouse setup
  |     +-- FUN_004533a0 — joystick setup
  +-- FUN_004c8ab0 — Sound::Setup
  |     +-- FUN_004d7a50 — Trace Gate
  |     +-- FUN_004d7aa0 — Debug Log Write
  +-- FUN_0049ef70 — OnScreen::Setup()
  +-- FUN_004fa2f0 — VidMan::Setup()
        +-- FUN_004d7a50 — Trace Gate
        +-- FUN_004d7aa0 — Debug Log Write
```

## Step-by-Step Trace

### Level 0: FUN_0042d5d0 — Game::Setup()

**Trigger:** Game state machine enters state 2 (Setup).
**Called by:** FUN_0045b200 (game state machine dispatch).
**Purpose:** Initializes all game subsystems in sequence.

**Key actions:**
1. Sets param_1[0] = 2 (state)
2. Calls FUN_004f9160 to load player file
3. Calls FUN_004a0eb0 (steward init) — if nonzero → abort early (return 1)
4. Calls HWInput::Setup, Sound::Setup, OnScreen::Setup, VidMan::Setup in sequence
5. Calls FUN_004b1870 (replay/Bink) — if nonzero → abort (return 1)
6. Calls additional subsystem setup functions

**Data passed to callees:** State machine context pointer (param_1), config paths.

### Level 1: FUN_004a0eb0 — Options::Setup() [steward init]

**Trigger:** Called early in Game::Setup.
**Purpose:** Initializes options/steward subsystem — reads player options, configures game rules.

**Key actions:**
1. Calls FUN_004f9f00 — conditional init
2. Calls FUN_004537b0 — read options file
3. Calls FUN_00485b90 — UI setup
4. Calls FUN_004186f0 — initialize driver table
5. Calls FUN_004f9ad0 — render config
6. Calls FUN_004f9f30 — conditional state reset

### Level 1: FUN_004b1870 — PlayerFile::Setup [replay/Bink]

**Trigger:** Called to set up replay and Bink video playback.
**Purpose:** Initializes the replay system and Bink video decoder.

### Level 1: FUN_00455c60 — HWInput::Setup()

**Trigger:** Called to initialize hardware input.
**Purpose:** Enumerates and initializes input devices (keyboard, mouse, joystick).

**Key actions:**
1. Calls FUN_0044ee10 — enumerate input devices
2. Calls FUN_0044fa60 — setup keyboard
3. Calls FUN_0044fbe0 — setup mouse
4. Calls FUN_004533a0 — setup joystick

### Level 1: FUN_004c8ab0 — Sound::Setup

**Trigger:** Called to initialize audio subsystem.
**Purpose:** Initializes Miles Sound System, allocates audio buffers.

### Level 1: FUN_0049ef70 — OnScreen::Setup()

**Trigger:** Called to initialize HUD/OSD.
**Purpose:** Sets up on-screen display rendering context.

### Level 1: FUN_004fa2f0 — VidMan::Setup()

**Trigger:** Called last in Game::Setup sequence.
**Purpose:** Sets up video manager state after VidMan::Enter already ran.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| Player file | PlayerFile path | FUN_004f9160 | player config loaded |
| Steward | — | FUN_004a0eb0 | options active (gate) |
| Input | — | HWInput::Setup | devices enumerated |
| Sound | — | Sound::Setup | audio initialized |
| Video | — | VidMan::Setup | video rendering ready |

## Notes

- 7 callees, sequential pipeline (no branching except steward gate).
- Every major subsystem setup registered via the same trace pattern (FUN_004d7a50/7aa0).
- FUN_004a0eb0 has 6 sub-callees — the most complex subtree.
- Order matters: player file must load before other systems.

---
