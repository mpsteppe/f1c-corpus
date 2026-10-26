# Chain: Client Grid Display Timer — Network Client Grid Page Wait and Transition

Seed: FUN_00460380  |  System: docs/09-track-system.md  |  Depth: 5  |  Functions: 9

---

## Overview

Network client-side grid display timer. Runs only for dedicated server clients (type == 3). Waits for a countdown timer (+0x1c), then finalizes session, checks grid readiness, waits for scene load, and transitions to the MPCLIENTGRID screen. Core flow: timer -> FINALIZE (FUN_00461550) + grid check (FUN_004630d0) -> scene load wait -> grid init (FUN_00461900) + grid setup (FUN_004c54f0) -> page navigate (FUN_004a0030/00497940).

## Call Tree

```
FUN_00460380 — Client Grid Display Timer  [trigger: per-frame NetComm tick]
  +-- FUN_00461550 — Pass-Through Wrapper  [session finalize: docs/20]
  |     +-- FUN_00461560 — Struct Init with Default Values  [docs/20]
  +-- FUN_004630d0 — Unique ID / Config Validation  [grid check: docs/20]
  |     +-- FUN_0057a880 — VTable Query with Stack Buffer  [session open: docs/01]
  |     +-- FUN_0057a8e0 — COM VTable Call via +0xc4  [session check: docs/20]
  |     +-- FUN_0057a230 — Byte-Aligned Memory Copy  [config/ID read: docs/01]
  |     +-- FUN_0057a8b0 — VTable Call via 0x7c  [session close: docs/01]
  +-- FUN_004c5690 — Scene Data Parser  [scene name format: docs/09]
  +-- FUN_00461900 — SessionConfigWriteback  [grid init: docs/06]
  |     +-- FUN_004c5690 — Scene Data Parser  (shared)
  |     +-- FUN_004c54f0 — .AIW/.SCN Filename Builder  [docs/08]
  |     |     +-- FUN_0058815f — String Format with Overflow Check  [docs/08]
  |     |     +-- FUN_00566650 — String Copy with Buffer Realloc  [docs/20]
  |     +-- FUN_004b1410 — Name Compare and Format  [docs/08]
  |     +-- FUN_0047f1f0 — Float Clamp  [docs/20]
  |     +-- FUN_004646c0 — Float Clamp  [docs/20]
  |     +-- FUN_00464720 — Byte Clamp  [docs/20]
  |     +-- FUN_004615f0 — Bit Flag Test at +0x6E  [docs/20]
  |     +-- FUN_004b0ef0 — Vehicle Setup Configuration  [docs/10]
  |           +-- FUN_0047f1f0 — Float Clamp
  |           +-- FUN_00464720 — Byte Clamp
  |           +-- FUN_004646c0 — Float Clamp
  |           +-- FUN_004b1190 — Session Config Loader  [docs/06]
  +-- FUN_004c54f0 — .AIW/.SCN Filename Builder  [vehicle grid setup: docs/08]
  |     +-- FUN_0058815f — String Format  [docs/08]
  |     +-- FUN_00566650 — String Copy  [docs/20]
  +-- FUN_004a0dc0 — System/OS API Call  [cursor hide: docs/20]
  +-- FUN_004a0030 — Monitor Page Display  [screen setup: docs/06]
  |     +-- FUN_004a0d30 — Global State Setter  [docs/20]
  |     +-- FUN_00497940 — Lookup Dispatch  [page display: docs/20]
  |     +-- FUN_004c8d90 — Global VTable Dispatch  [docs/20]
  |     +-- FUN_0042e400 — PenaltyStructInit  [docs/06]
  +-- FUN_00497940 — Lookup Dispatch  [page navigate: docs/20]
        +-- FUN_004976c0 — UI List Search by Name  [docs/19]
        +-- FUN_00497890 — General Utility  [docs/20]
```

## Step-by-Step Trace

### Level 0: FUN_00460380 — Client Grid Display Timer

**Trigger:** Per-frame NetComm tick for dedicated server clients.
**Called by:** [no callers recorded — per-frame network tick dispatch]
**Purpose:** Waits for grid display timer, then transitions client to grid screen.

**Key actions:**
1. Guards: only runs for session type == 3 (dedicated server client)
2. Decrements +0x1c (GridTimer) by frame time (DAT_008afe98)
3. When timer < 0:
   - Calls FUN_00461550 + FUN_004630d0 to finalize session and check grid readiness
   - If +0x20 == 0 and scene index changed: sets +0x20 = 1 (wait for scene load)
   - If +0x20 == 1 (scene loaded):
     - Calls FUN_00461900 + FUN_004c54f0 + FUN_004a0dc0 (grid finalize)
     - Calls FUN_00497940("MPCLIENTGRID") (navigate to grid)
     - Resets +0x20 = 0
   - Resets +0x1c = DAT_0059f0ac (NetTimeoutInterval)

**Globals read/written:** DAT_008afe98 (frame time), DAT_0059e440 (zero threshold), DAT_008ac48c (current scene index), DAT_007ce254 (screen display), DAT_0059f0ac (timer refill).

### Level 1: FUN_00461900 — SessionConfigWriteback

**Trigger:** Called when grid timer expires and scene is loaded.
**Called by:** FUN_00460380.
**Purpose:** Finalizes grid display configuration — writes session config.

**Key actions:**
1. Parses scene data (FUN_004c5690)
2. Builds .AIW/.SCN filenames (FUN_004c54f0)
3. Compares and formats driver names (FUN_004b1410)
4. Applies multiple clamps (float + byte) to config values
5. Tests bit flags at +0x6E
6. Loads vehicle setup configuration (FUN_004b0ef0 → session config loader)

### Level 1: FUN_004a0030 — Monitor Page Display

**Trigger:** Called to set up the grid display screen.
**Called by:** FUN_00460380.
**Purpose:** Configures the monitor page display for grid screen.

**Key actions:**
1. Sets global state (FUN_004a0d30)
2. Calls page lookup/dispatch (FUN_00497940)
3. Dispatches via global vtable (FUN_004c8d90)
4. Initializes penalty struct (FUN_0042e400)

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_00460380 | +0x1c timer | decrement | timer < 0 signal |
| FUN_004630d0 | session ID | validate | grid ready flag |
| FUN_00461900 | config data | writeback | grid display config |
| FUN_004c54f0 | scene/track name | format | .AIW/.SCN filename |
| FUN_00497940 | "MPCLIENTGRID" | page navigate | screen transition |

## Globals Written in This Chain

| Global | Name | Written by | Value meaning |
|--------|------|-----------|---------------|
| +0x1c | GridTimer | FUN_00460380 | Countdown for grid display |
| +0x20 | SceneLoadedFlag | FUN_00460380 | Scene load wait state |

## Notes

- Dedicated server client only (type == 3 check).
- Two-phase wait: first timer (grid ready), then scene load (flag +0x20).
- DAT_0059f0ac (NetTimeoutInterval, ~3.0f) is the timer refill constant — from docs/12.
- Shares FUN_004c5690 (Scene Data Parser) with track system (docs/09).
- FUN_004b0ef0 chain goes into vehicle setup configuration (docs/10) and session config loader (docs/06).

---
