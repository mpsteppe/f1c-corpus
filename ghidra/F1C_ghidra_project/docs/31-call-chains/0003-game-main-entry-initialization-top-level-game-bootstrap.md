# Chain: Game Main Entry / Initialization — Top-Level Game Bootstrap

Seed: FUN_0045b200  |  System: docs/01-engine-architecture.md  |  Depth: 3  |  Functions: 18

---

## Overview

Root entry point called by WinMain or equivalent. Sets version globals, then calls config/init chain: FUN_00423070 (cmdline parsing) → FUN_00421cd0 (Config.ini loader) → FUN_004d7a00 (session init) → FUN_004a0d50 (UI init) → FUN_004b17f0 (networking) → FUN_00463160 (NetComm cmdline). Then enters the game state machine loop: Game::Enter → Game::Setup → [Init → Restart → Post → PostCleanup] repeated → Game::Exit. Writes version floats/strings to globals. Sets DAT_007c56a0 = 3 (session mode).

## Call Tree

```
FUN_0045b200 — Game Main Entry  [trigger: WinMain entry — no callers (root)]
  +-- FUN_00423070 — Config/Command Line Parser  [reads command line args]
  +-- FUN_00421cd0 — Config.ini Parser  [OS detection + config load + path registry]
  |     +-- [42 callees — see Chain 1]
  +-- FUN_004d7a00 — Session/Race Init  [session module bootstrap]
  +-- FUN_004a0d50 — UI Init  [OnScreen/menu UI system startup]
  +-- FUN_004b17f0 — Networking Init  [network stack bootstrap]
  +-- FUN_00463160 — NetComm ParseCommandLine  [multiplayer cmdline args]
  |     +-- FUN_004d7a50 — Debug Gate  [trace logging]
  |     +-- FUN_004d7aa0 — Debug Log Write
  +-- FUN_0042d370 — Game::Enter  [state machine entry]
  |     +-- [Game state machine loop start]
  +-- FUN_0042d5d0 — Game::Setup  [module setup — 7 callees]
  |     +-- FUN_004f9160 — Player File Load
  |     +-- FUN_004a0eb0 — Steward Init
  |     +-- FUN_004b1870 — Replay/Bink Setup
  |     +-- FUN_00455c60 — HWInput::Setup
  |     +-- FUN_004c8ab0 — Sound::Setup
  |     +-- FUN_0049ef70 — OnScreen::Setup
  |     +-- FUN_004fa2f0 — VidMan::Setup
  +-- FUN_0042d6b0 — Game::Init  [subsystem init — 10+ callees]
  |     +-- FUN_004ba1f0 — Replay Init
  |     +-- FUN_004fa320 — VidMan::Init  [display mode, render state, scene]
  |     +-- FUN_00455d50 — HWInput::Init
  |     +-- FUN_004cf070 — SpecialFX::Init
  |     +-- [other inits]
  +-- FUN_0042d7a0 — Game::Restart  [per-session restart — 10 callees]
  |     +-- FUN_004c8b20 — Sound::Restart
  |     +-- FUN_004a40f0 — Steward
  |     +-- FUN_004a0fb0 — Race Timer
  |     +-- FUN_00455da0 — HWInput::Restart
  |     +-- FUN_0040c9e0 — CamMan::Restart
  |     +-- FUN_004b4060 — Render::Restart
  |     +-- FUN_0049f000 — OnScreen::Restart
  |     +-- FUN_004fa640 — VidMan::Restart
  |     +-- FUN_00464290 — NetComm
  |     +-- FUN_004c01a0 — [undocumented]
  +-- FUN_0042d8a0 — Game::Post  [per-frame update loop]
  +-- FUN_0042da30 — Game::Post Cleanup
  +-- FUN_0042db20 — Game::Exit  [shutdown teardown — 10 callees]
        +-- FUN_004c8d00 — Sound::Exit
        +-- FUN_004cfff0 — SpecialFX::Exit
        +-- FUN_00455f00 — HWInput::Exit
        +-- FUN_0042ca70 — DynMan::Exit
        +-- FUN_0049f120 — OnScreen::Exit
        +-- FUN_004fad00 — VidMan::Exit
        +-- [other cleanup]
```

## Step-by-Step Trace

### Level 0: FUN_0045b200 — Game Main Entry / Initialization

**Trigger:** Called once by WinMain at process startup.
**Called by:** None (root function, callers: 0).
**Purpose:** Top-level game bootstrap — sets globals, initializes all subsystems, enters game state machine.

**Key actions:**
1. Sets DAT_007c56b0 = 0x3f8353f8 (version float ~1.025)
2. Sets DAT_007c56b4 = "ilya! _1011" (version/watermark string)
3. Sets DAT_007c56ad = 0 (flag)
4. Sets DAT_007c56a0 = 3 (session mode)
5. Stores param_1 in DAT_007ce2a0 (application handle)
6. Calls initializers in order: cmdline → config → session → UI → net → NetComm
7. Enters state machine: Enter → Setup → [Init → Restart → Post → PostCleanup] → Exit
8. Calls FUN_0042db20 (Game::Exit) on shutdown

**Data passed to callees:** App instance handle (stored globally), config struct, command line string

### Level 1: FUN_00421cd0 — Config.ini Parser (detailed in Chain 1)

**Trigger:** Step 2 of init chain, after cmdline parsing.
**Purpose:** OS detection, config path setup, component parameter dispatch.

### Level 1: FUN_0042d5d0 — Game::Setup

**Trigger:** Called from state machine entry — one-time setup.
**Purpose:** Sets up all game modules with persistent state: player file, steward, replay, input, sound, display, video.
**Key callees:** 7 module setup functions.

### Level 1: FUN_0042d6b0 — Game::Init

**Trigger:** Called each state machine cycle.
**Purpose:** (Re)initializes subsystems per session. 10+ callees.
**Key callees:** replay, VidMan, HWInput, SpecialFX inits.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_0045b200 | app handle | Store globals | DAT_007c56b0/b4/ad/a0/ce2a0 set |
| FUN_0045b200 | cmdline args | FUN_00423070 | Parsed config |
| FUN_0045b200 | config.ini path | FUN_00421cd0 | Config loaded |
| FUN_0042d5d0 | module structs | 7x Setup calls | Modules initialized |
| FUN_0042d6b0 | session config | 10+ Init calls | Subsystems ready |
| FUN_0042d7a0 | race state | 10 Restart calls | Per-session reset |
| FUN_0042db20 | module handles | 10 Exit calls | Clean shutdown |

## Globals Written in This Chain

| Global | Name | Written by | Value meaning |
|--------|------|-----------|---------------|
| DAT_007c56b0 | VersionFloat | FUN_0045b200 | ~1.025f |
| DAT_007c56b4 | VersionString | FUN_0045b200 | "ilya! _1011" |
| DAT_007c56ad | InitFlag | FUN_0045b200 | 0 |
| DAT_007c56a0 | SessionMode | FUN_0045b200 | 3 |
| DAT_007ce2a0 | AppHandle | FUN_0045b200 | Win32 hInstance |

## Notes

- Root of entire call graph — no callers. Called by WinMain/CRT startup.
- The game state machine loop (FUN_0042d5d0 → ... → FUN_0042da30) cycles every session transition.
- Each module follows lifecycle pattern: Enter → Setup → (Init/Restart/Post)* → Exit

---

---
