# Chain: VidMan::Enter — Video Manager Initialization

Seed: FUN_004fa000  |  System: docs/01-engine-architecture.md  |  Depth: 3  |  Functions: 22

---

## Overview

VidMan::Enter initializes the rendering subsystem during game startup (state 2, Game::Setup). It queries the Direct3D device, reads the configured device name from the player file, and either initializes the render chain (device matches config) or launches 3DCONFIG.EXE (device mismatch). The chain touches timer, tracing, render surface allocation, display mode setup, and Direct3D device creation.

## Call Tree

```
FUN_004FA000 — VidMan::Enter  [game startup, state 2]
  +-- FUN_00568be0 — QPC Timer Init  [starts high-res timer]
  +-- FUN_004d7a50 — Trace Gate (String Split Loop)  [profile entry gate]
  |     +-- FUN_00587c20 — string split
  |     +-- FUN_004d7aa0 — Debug Log Write
  +-- FUN_004d7aa0 — Debug Log Write  [profile trace]
  +-- FUN_0053d470 — D3D Device Test [undocumented, arithmetic/comparison]
  +-- FUN_0053d890 — Player File Device Name Read
  +-- FUN_0053d8e0 — [undocumented]
  +-- FUN_004f9160 — Global Index Setter / Utility  [reads device name]
  |     +-- FUN_0055bfc0 — [undocumented]
  |     +-- FUN_0055bfd0 — [undocumented]
  +-- FUN_004f91b0 — Global-Guarded Field Reader
  |     +-- FUN_0055bde0 — [undocumented]
  +-- FUN_004a1200 — Application Window Init
  |     +-- FUN_0059db88 — Win32 window creation
  |     +-- FUN_0058815f — Win32 error/assert
  +-- FUN_0053c680 — Three-Global Setter
  +-- FUN_005408f0 — Graphics Config State Setter
  +-- FUN_004f9420 — 3D Projection Setup with Global Store
  |     +-- FUN_004f9240 — [undocumented]
  +-- FUN_004f9310 — [undocumented]
  +-- FUN_004f9f00 — Conditional Init / Render Start
  |     +-- FUN_0055c9b0 — [undocumented]
  |     +-- FUN_005550a0 — [undocumented]
  +-- FUN_005434a0 — Float-to-Int Convert + Render Dispatch
  |     +-- FUN_00543540 — render clip region
  |     +-- FUN_005404d0 — [undocumented]
  +-- FUN_0055c060 — Call Wrapper → FUN_0055be60
  +-- FUN_004f9f30 — Conditional State Reset / Render End
  |     +-- FUN_0055c9b0 — [undocumented]
  |     +-- FUN_005550c0 — [undocumented]
  +-- FUN_00494690 — Render Surface Allocation and Text Init
  |     +-- FUN_0054fe10 — D3D surface create
  |     +-- FUN_0054fec0 — surface/texture alloc
  |     +-- FUN_00553980 — text/font init
  |     +-- FUN_00553650 — vertex set (undocumented)
  +-- FUN_00422be0 — [undocumented]
  +-- CreateProcessA (Win32) — launches 3DCONFIG.EXE on mismatch
```

## Step-by-Step Trace

### Level 0: FUN_004FA000 — VidMan::Enter

**Trigger:** Called from Game::Setup() during game startup state 2.
**Called by:** Game::Setup (FUN_0042d5d0) — entry point has no callers in knowledge graph (likely called from game state machine dispatch).
**Purpose:** Video manager initialization — detects display device, initializes rendering, or launches config tool.

**Key actions:**
1. Starts QPC timer via FUN_00568be0(1)
2. Tests Direct3D device via FUN_0053d470
3. Reads device name from player file (DAT_005ec488) via FUN_0053d890
4. Compares configured device name with current device handle (DAT_005ec480)
5. On match: initializes render subsystem (surfaces, display mode, projection)
6. On mismatch: launches 3DCONFIG.EXE via CreateProcessA, returns 1

**Data passed to callees:** Device name strings, window handles, config pointers.

### Level 1: FUN_00568be0 — QPC Timer Init

**Trigger:** Called by VidMan::Enter.
**Called by:** Not in callers graph.
**Purpose:** Initializes high-resolution performance counter (QueryPerformanceCounter).

**Key actions:**
- Starts QPC timer
- Returns timer handle

### Level 1: FUN_004d7a50 — Trace Gate (String Split Loop)

**Trigger:** Called by VidMan::Enter (profile entry trace).
**Called by:** Multiple setup functions — generic profile trace.
**Purpose:** Splits input string and gates debug trace output.

**Key actions:**
1. Calls FUN_00587c20 (string split)
2. Calls FUN_004d7aa0 (debug log write)

### Level 1: FUN_0053d470 — D3D Device Test

**Trigger:** Called by VidMan::Enter.
**Purpose:** Tests Direct3D device availability. Returns 0 if device OK, nonzero if failed.

**Key actions:**
- Arithmetic/comparison — likely D3D device enumeration call
- If fails → VidMan::Enter returns 1

### Level 1: FUN_004f9160 — Global Index Setter / Utility

**Trigger:** Called by VidMan::Enter (device match path).
**Purpose:** Sets global index or state, reads device name from player file.

**Key actions:**
1. Calls FUN_0055bfc0 — utility
2. Calls FUN_0055bfd0 — utility

### Level 1: FUN_004f91b0 — Global-Guarded Field Reader

**Trigger:** Called by VidMan::Enter.
**Purpose:** Reads a global field with guard check.

**Key actions:**
1. Calls FUN_0055bde0 — field reader

### Level 1: FUN_004a1200 — Application Window Init

**Trigger:** Called by VidMan::Enter.
**Purpose:** Initializes the application window for rendering.

**Key actions:**
1. Calls FUN_0059db88 — Win32 CreateWindow/RegisterClass
2. Calls FUN_0058815f — Win32 error/assert handler

### Level 1: FUN_0053c680 — Three-Global Setter

**Trigger:** Called by VidMan::Enter.
**Purpose:** Sets three globals to fixed values (likely display mode config).

### Level 1: FUN_005408f0 — Graphics Config State Setter

**Trigger:** Called by VidMan::Enter.
**Purpose:** Sets graphics config state — writes to config globals.

### Level 1: FUN_004f9420 — 3D Projection Setup with Global Store

**Trigger:** Called by VidMan::Enter.
**Purpose:** Sets up 3D projection matrix and stores to global.

**Key actions:**
1. Calls FUN_004f9240 — utility (projection setup)

### Level 1: FUN_004f9f00 — Conditional Init / Render Start

**Trigger:** Called by VidMan::Enter.
**Purpose:** Conditional init: if not initialized, sets up render state.

**Key actions:**
1. Calls FUN_0055c9b0 — conditional check
2. Calls FUN_005550a0 — state init

### Level 1: FUN_005434a0 — Float-to-Int Convert + Render Dispatch

**Trigger:** Called by VidMan::Enter.
**Purpose:** Converts float parameters to int, dispatches render.

**Key actions:**
1. Calls FUN_00543540 — render clip region
2. Calls FUN_005404d0 — unknown render dispatch

### Level 1: FUN_0055c060 — Call Wrapper

**Trigger:** Called by VidMan::Enter.
**Purpose:** Wraps FUN_0055be60 — thin call-through.

**Key actions:**
1. Calls FUN_0055be60 — utility

### Level 1: FUN_004f9f30 — Conditional State Reset / Render End

**Trigger:** Called by VidMan::Enter.
**Purpose:** Conditional state reset — mirrors FUN_004f9f00.

**Key actions:**
1. Calls FUN_0055c9b0 — conditional check
2. Calls FUN_005550c0 — state reset

### Level 1: FUN_00494690 — Render Surface Allocation and Text Init

**Trigger:** Called by VidMan::Enter.
**Called by:** Multiple render init paths.
**Purpose:** Allocates render surfaces and initializes text rendering subsystem.

**Key actions:**
1. Calls FUN_0054fe10 — create D3D surface
2. Calls FUN_0054fec0 — allocate texture surface
3. Calls FUN_00553980 — init text/font system
4. Calls FUN_00553650 — set vertex data

### Level 1: FUN_00422be0 — [undocumented]

**Trigger:** Called by VidMan::Enter.
**Purpose:** Unknown — leaf function with no further callees.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| VidMan::Enter | PlayerFile (DAT_005ec488) | Read device name | device_name string |
| VidMan::Enter | device_name vs DAT_005ec480 | Compare | match/mismatch |
| match path | match | Init render chain | render surfaces, display mode |
| mismatch path | mismatch | CreateProcessA(3DCONFIG.EXE) | child process |

## Globals Written in This Chain

| Global | Name | Written by | Value meaning |
|--------|------|-----------|---------------|
| DAT_005ec488 | PlayerFile | Setup | player config file path |
| DAT_005ec480 | DeviceHandle | VidMan::Enter | current display device handle |

## Notes

- 19 callees, but most are shallow (leaf or 1-level deep). The render surface allocation (FUN_00494690) is the deepest subtree.
- Chain splits into two disjoint paths: render init (device matches) vs config launcher (mismatch).
- Several callees are [undocumented] — these are leaf-level utility functions for Win32/D3D interaction.
- CreateProcessA is a Win32 API call, not a game function.

---
