# Chain: AI Driver Count Setup — AI Grid Population

Seed: FUN_004bfd90  |  System: docs/02-ai-system.md  |  Depth: 3  |  Functions: 13

---

## Overview

Determines how many AI drivers to populate the grid with, loads their names, and registers them. Gated on VehicleCount. Handles multiplayer (name list from file), quick race (random count 3-5), and championship (match names from driver DB). Called during game setup state transition.

## Call Tree

```
FUN_004bfd90 — AI Driver Count Setup  [game setup, state 3→4 transition]
  +-- FUN_004bf630 — Zero-Init 4 Ints
  +-- FUN_0042bc10 — ScoringGateCheck
  |     +-- FUN_00461cd0 — gate check
  +-- FUN_004b3c60 — Deterministic Hash/Pseudo-Random Generator
  |     +-- FUN_0055687b — hash
  +-- FUN_0042bc80 — Build Active Vehicle Pointer Array
  +-- FUN_004bf790 — AI Opponent Selection / NotAI Slot Filler
  |     +-- FUN_004bfa00 — opponent select
  |     +-- FUN_004bf6a0 — slot fill
  |     +-- FUN_004c5070 — vehicle register
  |     +-- FUN_004c50e0 — vehicle validate
  |     +-- FUN_00588410 — name match
  +-- FUN_004ef5a0 — SessionStateTransition
  |     +-- FUN_004efb20 — state change
  |     +-- FUN_004ef7c0 — transition apply
  |     +-- FUN_00447780 — physics state
  |     +-- FUN_004e9630 — session data
  |     +-- FUN_0042adb0 — game state
  +-- FUN_004bfd40 — Indexed List Lookup
  +-- FUN_004c78f0 — Nationality/Driver Info Loader
  +-- FUN_004c6960 — TeamIDSetter
  |     +-- FUN_00424060 — team ID
  +-- FUN_004c3f80 — Vehicle Lookup by Name
        +-- FUN_00588410 — name match
```

## Step-by-Step Trace

### Level 0: FUN_004bfd90 — AI Driver Count Setup

**Trigger:** Called during game setup (FUN_0042c1a0, state machine transition 3→4).
**Called by:** FUN_0042c1a0 (dyn manager / game state init).
**Purpose:** Determines AI driver count, loads driver names, sets up starting grid.

**Key actions:**
1. Gate: if VehicleCount < 1: skip
2. Multiplayer: read driver name list from DAT_007ce64c
3. RaceMode 1: random count 3-5 or single driver
4. Otherwise: match driver names via FUN_004bf790, register vehicles

**Data passed to callees:** Vehicle struct arrays, name buffers, session type flag.

### Level 1: FUN_004bf630 — Zero-Init 4 Ints

**Trigger:** Called first to clear counters.
**Purpose:** Zero-initializes 4 integer counters (driver count state).

### Level 1: FUN_004bf790 — AI Opponent Selection / NotAI Slot Filler

**Trigger:** Main driver name matching and slot assignment.
**Purpose:** Iterates driver database, selects AI opponents, fills non-player slots.

**Key actions:**
1. Calls FUN_004bfa00 — select opponent
2. Calls FUN_004bf6a0 — fill slot
3. Calls FUN_004c5070 — register vehicle
4. Calls FUN_004c50e0 — validate vehicle
5. Calls FUN_00588410 — match driver name

### Level 1: FUN_004ef5a0 — SessionStateTransition

**Trigger:** Transitions session state after driver setup.
**Purpose:** Updates session state machine (likely to READY state).

**Key actions:**
1. Calls FUN_004efb20 — apply state change
2. Calls FUN_004ef7c0 — validate transition
3. Calls FUN_00447780 — update physics state
4. Calls FUN_004e9630 — session data update
5. Calls FUN_0042adb0 — game state update

### Level 1: FUN_004c3f80 — Vehicle Lookup by Name

**Trigger:** Looks up vehicle configuration by driver name.
**Purpose:** Finds matching vehicle entry in VehicleArray by driver name string.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| Count | VehicleCount | gate | skip/continue |
| Multiplayer | DAT_007ce64c | read name list | name array |
| Quick race | RaceMode | random(3-5) | driver count |
| Championship | driver DB | match names | active driver list |
| Register | matched drivers | assign slots | grid array |

## Globals Written in This Chain

| Global | Name | Written by | Value meaning |
|--------|------|-----------|---------------|
| DAT_005c329c | VehicleCount | AI Count Setup | final active vehicle count |

## Notes

- 10 callees, moderate depth (3 levels max).
- Key logic branch: multiplayer vs quick race vs championship.
- Cross-system: calls FUN_004ef5a0 (docs/06 session logic) for state transition.

---
