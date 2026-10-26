# Chain: Race Tick Advance / Frame Dispatch — Advances physics, sound, state for all vehicles per frame

Seed: FUN_004b9890  |  System: docs/06-session-race-logic.md  |  Depth: 6  |  Functions: ~35+

---

## Overview

FUN_004b9890 is the per-frame race tick dispatch. Called each game frame during a race session, it advances vehicle physics, sound, steward logic, and loading phases. It checks session state guards (DAT_007ce254), captures delta time, and dispatches to a dozen subsystems. The deepest subtrees are FUN_004b8ae0 (StateTriggerCheck, 15 callees) which handles weather, AI, steward, and UI updates, and FUN_004b8940 (LoadingPhase2, 11 callees) for post-race cleanup.

## Call Tree

```
FUN_004b9890 — Race Tick Advance / Frame Dispatch  [trigger: per-frame during race session]
  +-- FUN_0042d210 — undocumented  [leaf]
  +-- FUN_0040cd60 — Session Phase Decode  [leaf]
  +-- FUN_004b87c0 — LoadingPhase1  [9 callees]
  |     +-- FUN_004b7a00 — QueuePop  [sub: 2]
  |     +-- FUN_00566e20 — Resource Lookup Dispatcher  [sub: 2]
  |     +-- FUN_004e3a50 — MultiObjectRemove  [sub: 1]
  |     +-- FUN_004e1970 — Effect Data Table Initialization  [sub: 1]
  |     +-- FUN_004ef5a0 — SessionStateTransition  [sub: 6]
  |     +-- [4 additional callees omitted]
  +-- FUN_004b9cd0 — Delegation helper  [leaf]
  +-- FUN_004b9ce0 — Delegation helper  [sub: 1]
  +-- FUN_0040cde0 — Game Action State Machine  [sub: 2]
  +-- FUN_004b8bd0 — Key Priority Chain  [leaf]
  +-- FUN_004c8650 — Sound/Audio Playback  [sub: 1]
  +-- FUN_004b8ae0 — StateTriggerCheck  [15 callees]
  |     +-- FUN_004b8c40 — Float Switch with AI/Game Mode Dispatch  [sub: 3]
  |     +-- FUN_004ba180 — Conditional Multi-Path Dispatcher  [sub: 6]
  |     +-- FUN_004cfcc0 — Weather Particle Update  [sub: 6]
  |     +-- FUN_00404460 — Multi-Phase Processing State Machine  [sub: 3]
  |     +-- FUN_004d4580 — Steward Update Main Dispatch  [sub: 14]
  |     +-- [10 additional callees omitted]
  +-- FUN_0042bbd0 — Set Player Vehicle Index  [leaf]
  +-- FUN_004b8940 — LoadingPhase2  [11 callees]
  |     +-- FUN_00408450 — Safe Division with Zero Guard  [sub: 1]
  |     +-- FUN_004b8ae0 — StateTriggerCheck  [reuse - 15 callees]
  |     +-- FUN_004b86e0 — AngleClampWrap  [leaf]
  |     +-- FUN_004ef5a0 — SessionStateTransition  [sub: 6]
  |     +-- FUN_004e19a0 — UIElementIterateUpdate  [sub: 1]
  |     +-- [6 additional callees omitted]
  +-- FUN_004c8d60/70 — Arithmetic/Comparison (Virtual Dispatch via Global)  [leaf]
```

## Step-by-Step Trace

### Level 0: FUN_004b9890 — Race Tick Advance / Frame Dispatch

**Called by:** None documented (likely called from main game loop)
**Purpose:** Main per-frame tick for race session; advances physics, sound, state for all vehicles.

**Key actions:**
1. Guards on DAT_007ce254 (0=session active)
2. Captures timer, clamps delta
3. Calls vehicle tick loop
4. Dispatches to loading phases, sound, steward, state trigger checks
5. Calls FUN_0042bbd0 (set player vehicle index), FUN_0040cde0 (game action state machine)

**Data passed to callees:** Delta time, session state pointers

### Level 1: FUN_004b8ae0 — StateTriggerCheck

**Called by:** FUN_004b9890 (direct), FUN_004b8940 (via LoadingPhase2)
**Purpose:** Main state trigger dispatcher with 15 callees spanning weather, steward, AI, UI.

**Key actions:**
1. Dispatches to weather particle update (FUN_004cfcc0)
2. Runs steward main update (FUN_004d4580) — 14 callees for penalty/proximity/phase logic
3. Handles AI/Game mode dispatch
4. Multi-phase processing

### Level 1: FUN_004d4580 — Steward Update Main Dispatch

**Called by:** FUN_004b8ae0 (via StateTriggerCheck)
**Purpose:** Steward per-tick dispatch — penalties, proximity, phase logic.
**Sub-callees:** 14 total (race stewarding logic)

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_004b9890 | Delta time, session state | Dispatch to subsystems | Per-frame vehicle/session update |

## Globals Written in This Chain

| Global | Name | Written by | Value meaning |
|--------|------|-----------|---------------|
| DAT_007ce254 | SessionActiveFlag | FUN_004b9890 | Session active guard |

## Notes

- FUN_004b8ae0 (StateTriggerCheck) is reused by both main tick and LoadingPhase2.
- The chain is wide (12 direct callees) with moderate depth (2-3 levels).
- Cross-system handoffs: renderer (weather particles), steward (penalties), audio (sound), AI.

---
