# Chain: Options::Setup() — Options Menu Lifecycle

Seed: 0x004a0eb0  |  System: docs/01-engine-architecture.md  |  Depth: 2  |  Functions: 7

---

## Overview

Options::Setup() is the options menu entry point/callback. Called from Game::Setup() (0x0042d5d0) during steward initialization, it displays the options screen and processes keyboard-driven menu interaction. The chain covers frame timing, UI rendering, keyboard input dispatch, frame counting, and Windows message pumping.

## Call Tree

```
FUN_004a0eb0 — Options::Setup()  [trigger: Game::Setup → steward init sequence]
  +-- FUN_004f9f00 — Conditional Init  [frame timing]
  +-- FUN_004537b0 — Tire Compound Struct Layout  [UI render]
  +-- FUN_00485b90 — [keyboard input — not in functions.json]
  +-- FUN_004186f0 — Text/Overlay Display Timer
  +-- FUN_004f9ad0 — Arithmetic/Comparison (Time Accumulation)
  +-- FUN_00404b60 — [unidentified — not in functions.json]
  +-- FUN_004a1830 — Windows Message Pump with Sleep
```

## Step-by-Step Trace

### Level 0: FUN_004a0eb0 — Options::Setup()

**Trigger:** Called during Game::Setup() steward initialization
**Called by:** 0x0042d5d0 (Game::Setup — docs/01)
**Purpose:** Options menu main loop — displays options screen, processes keyboard input, handles mode switching.

**Key actions:**
1. Logs "Entered Options::Setup()" from options.cpp
2. If DAT_007ce260 == 0 (normal init mode):
   - Sub-mode 0: enters menu loop — frame timing (FUN_004f9f00), UI render (FUN_004537b0), increment frame counter (DAT_007ce250), keyboard check (FUN_00485b90), dispatch frame (FUN_004186f0), call UI/input handlers (FUN_004f9ad0, FUN_00404b60)
   - Sub-mode non-0: checks DAT_005ccfe4 exit flag, clears and exits if set
3. If DAT_007ce260 != 0: sets DAT_007c5690 = 1 (init state), returns 0

**Data passed to callees:** UI state, keyboard input buffers

### Level 1: FUN_004f9f00 — Frame Timing

**Trigger:** Called at start of menu loop iteration
**Purpose:** Conditional initialization of frame timing — manages frame delta for smooth menu rendering

### Level 1: FUN_00485b90 — Keyboard Input Handler

**Trigger:** Called per menu loop iteration to poll input
**Purpose:** Reads keyboard state, translates to menu navigation commands (ESC → exit, Enter → select)

### Level 1: FUN_004a1830 — Windows Message Pump with Sleep

**Trigger:** Called during menu loop
**Purpose:** Pumps Windows message queue with sleep — allows OS to process events

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| Options::Setup() | DAT_007ce260 | mode check | normal init or special mode |
| Options::Setup() | keyboard state | input polling | menu navigation |
| Options::Setup() | frame counter | increment | DAT_007ce250+1 |
| Options::Setup() | exit flags | check | exit or continue |

## Globals Written in This Chain

- `DAT_007ce250` — frame counter (incremented each iteration)
- `DAT_007ce25c` — exit flag (set on ESC/Enter)
- `DAT_005ccfe4` — sub-mode exit flag
- `DAT_007c5690` — init state flag
- `DAT_007ce260` — options init guard (read)
- `DAT_007ce264` — sub-mode selector (read)

## Notes

- Called during Game::Setup(), before main game loop starts
- Menu exit is triggered either by user input (ESC/Enter) or by sub-mode auto-exit flag
- FUN_00485b90 and FUN_00404b60 are not in functions.json — likely small inline or unanalyzed helpers
- FUN_004a1830 (message pump) prevents Windows from showing "not responding" during menu

---
