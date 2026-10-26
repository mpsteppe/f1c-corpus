# Chain: Pit Timer / Race Phase State Machine — Session Steward Per-Frame Tick

Seed: FUN_004d2e50  |  System: docs/07-pit-system.md  |  Depth: 6  |  Functions: 18+

---

## Overview

Called once per frame from the session steward main dispatch (FUN_004d4580). Drives the race lifecycle: countdown sequence (phase 1), formation lap (phase 2–3), green-flag running (phase 4), and race finish (phase 5). Also handles non-race session timer display. Tracks pit window open/close timing, displays "Time Remaining" / "Time until pit closes" HUD messages, and transitions the session state via FUN_004d0ec0. Operates on per-vehicle session data (param_1), reading RacePhase (DAT_007c56a8) and SessionType (DAT_007c56a4) to select behavior.

## Call Tree

```
FUN_004d2e50 — Pit Timer / Race Phase State Machine  [trigger: called by FUN_004d4580 per frame]
  +-- FUN_0041a500 — Time-based Message Chain  [session timer: checks remaining time]
  |     +-- FUN_004144d0 — Struct Init with Sentinel Values  [zero-init struct]
  |     +-- FUN_004144f0 — Driver Data Table Lookup  [time conversion]
  |     +-- FUN_00418560 — InsertDriverTableEntry  [register driver entry]
  |     |     +-- FUN_00418b90 — Score/Threshold Gate Check  [validate threshold]
  |     |     +-- FUN_00418b70 — Short Computation  [table lookup with sentinel]
  |     |     +-- FUN_004145c0 — Struct Copy (32 bytes)  [memcpy]
  |     +-- FUN_004186a0 — Float Array Initializer (-1.0f)
  |           +-- FUN_004144d0 — Struct Init with Sentinel Values
  +-- FUN_0042d140 — Race Phase Set  [writes DAT_007c56a8]
  +-- FUN_004d0ec0 — Session State Transition  [Arithmetic/Comparison]
  +-- FUN_0041a6b0 — Display Message 0x113  [time update]
  |     +-- FUN_004186a0 — Float Array Initializer (-1.0f)
  |     +-- FUN_004144f0 — Driver Data Table Lookup
  |     +-- FUN_00418560 — InsertDriverTableEntry
  +-- FUN_004d1cd0 — Single Call Wrapper  [pit state display: 5-tier pit window]
  +-- FUN_004d2e20 — Arithmetic/Comparison  [pit countdown: conditional free]
  |     +-- FUN_004d0080 — Array-of-Struct Deallocator
  |     |     +-- FUN_00545150 — 3D Sound Source Destructor  [cross-system: docs/06]
  |     |     +-- FUN_004a2220 — Struct Init + Cleanup  [cross-system: docs/20]
  |     |     +-- FUN_00587bcf — Free Wrapper (thunk to FUN_0058aa6f)  [docs/01]
  |     +-- FUN_00587bcf — Free Wrapper
  +-- FUN_00423a00 — Binary Search in String Table  [string copy for HUD]
  |     +-- FUN_00588410 — String Compare Helper  [docs/06]
  +-- FUN_004d11d0 — Time Format Display  [formats time for HUD]
```

## Step-by-Step Trace

### Level 0: FUN_004d2e50 — Pit Timer / Race Phase State Machine

**Trigger:** Per-frame from FUN_004d4580 (Steward Update Main Dispatch, docs/06).
**Called by:** FUN_004d4580 (session steward per-tick).
**Purpose:** Drives race phase transitions, pit window timing, and countdown HUD.

**Key actions:**
1. Reads DAT_007c56a8 (RacePhase, 0–7) — selects current phase behavior
2. Reads DAT_007c56a4 (SessionType) — race vs non-race session branch
3. Phase 1 (countdown): computes time-to-start, transitions through sub-phases at 5s/4s/3s/2s/1s thresholds, tracks pit close time
4. Phase 4 (racing): manages pit window open/close with 5-tier display
5. Phase 5 (finish): checks finish state, calls FUN_004d0ec0 to stop session
6. Reads per-vehicle struct offsets: +0xb4 (race time remaining), +0xd8 (pit window), +0xf4 (finish state)

**Globals read/written:**
- DAT_007c56a8 (RacePhase) — read for dispatch, written by FUN_0042d140
- DAT_007c56a4 (SessionType) — read for race/non-race branch
- DAT_007cec30 (ReconPitOpen) — pit window time
- DAT_007cebf4 — timer update interval
- DAT_007c54e8 (PlayerVehiclePtr) — player vehicle lookup
- DAT_005c329c (VehicleCount) — vehicle iteration bound

**Data passed to callees:** param_1 pointer (per-vehicle session struct), phase-specific time deltas and flags.

### Level 1: FUN_0041a500 — Time-based Message Chain

**Trigger:** Called from phase 0/1/5 for time-remaining display.
**Called by:** FUN_004d2e50.
**Purpose:** Checks remaining race time and dispatches display messages.

**Key actions:**
1. Calls FUN_004144d0 to init struct with sentinel values
2. Calls FUN_004144f0 for driver data table time conversion
3. Calls FUN_00418560 to insert driver entry (register time for HUD)
4. Calls FUN_004186a0 to initialize float array buffer

### Level 1: FUN_004d2e20 — Pit Countdown / Conditional Free

**Trigger:** Called during pit window close (phase 4→5 transition).
**Called by:** FUN_004d2e50.
**Purpose:** Frees pit state array-of-structs when timer expires.

**Key actions:**
1. Calls FUN_004d0080 (Array-of-Struct Deallocator) which descends into sound source destructor chain
2. Calls FUN_00587bcf (Free Wrapper → heap deallocation)

### Level 1: FUN_00423a00 — Binary Search in String Table

**Trigger:** Called for HUD text formatting.
**Called by:** FUN_004d2e50.
**Purpose:** Copies formatted time string to MessageBuffer.

**Key actions:**
1. Calls FUN_00588410 for string compare/lookup

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_004d2e50 | RacePhase (global) | switch dispatch | phase-specific actions |
| FUN_004d2e50 | param_1+0xb4 | time remaining check | timer display / transition |
| FUN_004d2e50 | param_1+0xd8 | pit window check | 5-tier display (FUN_004d1cd0) |
| FUN_004d0ec0 | session state | state transition | DAT_004d0ec0 updated |
| FUN_00423a00 | string ID | binary search | formatted string to MessageBuffer |

## Globals Written in This Chain

| Global | Name | Written by | Value meaning |
|--------|------|-----------|---------------|
| DAT_007c56a8 | RacePhase | FUN_0042d140 | New race phase (0–7) |
| DAT_007cebf4 | TimerInterval | (read only) | Timer display frequency |

## Notes

- Heavy use of FUN_004144d0/FUN_004144f0/FUN_00418560 triple pattern: these are commentary/display message helper functions that appear throughout the session system.
- The 5-tier pit window display (FUN_004d1cd0) shows: 0=closed, 1=opening, 2-4=closing soon, 5=open.
- Cross-system call to sound source destructor (FUN_00545150, docs/06) when freeing pit state.
- FUN_00587bcf (free wrapper) appears 5+ times in this chain — separates MSVC heap management from game logic.

---
