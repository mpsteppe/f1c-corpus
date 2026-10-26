# Chain: LoadVehicleEntries — Vehicle Entry Count and Registration

Seed: FUN_004b70b0  |  System: docs/08-file-formats.md  |  Depth: 5  |  Functions: 10

---

## Overview

Top-level vehicle entry loader. Counts and registers vehicle entries from parsed data. Validates each entry, registers driver name/team/number, sets VehicleCount (DAT_005c329c), resets team counters, and loads car models. Called during session setup. Dispatches to session state transition (FUN_004ef5a0), driver info loaders (FUN_004c6980), scene parsers (FUN_004c5690), and vehicle array builder (FUN_0042bc80).

## Call Tree

```
FUN_004b70b0 — LoadVehicleEntries  [trigger: session setup / file load]
  +-- FUN_004b87a0 — QueuePeek  [queue check: docs/06]
  +-- FUN_004b72a0 — Linked List Traversal with Filter  [validate entries: docs/20]
  |     +-- FUN_004b50c0 — General Utility  [validation check: docs/20]
  +-- FUN_004ef5a0 — SessionStateTransition  [timing freeze/session ctx: docs/06]
  |     +-- FUN_004efb20 — 3D Transform with Matrix Mult  [docs/18]
  |     +-- FUN_004ef7c0 — AI Vehicle Path Position Tracking  [docs/02]
  |     |     +-- FUN_00566e40 — EulerToRotationMatrix  [docs/18]
  |     |     +-- FUN_004ef680 — RideHeightDelta  [docs/06]
  |     |     +-- FUN_004e9bd0 — 3x3 Matrix Transform  [docs/06]
  |     |     +-- FUN_0043e4b0 — RigidBodyConstraintSolve  [docs/18]
  |     |           +-- FUN_00567740 — FPU Control Word Extract  [docs/20]
  |     |           +-- FUN_0056bd40 — Constraint Setup  [leaf]
  |     |           +-- FUN_0056f100 — Constraint Impulse Apply  [docs/20]
  |     |           +-- FUN_00567780 — Empty Stub (state restore)  [docs/20]
  |     +-- FUN_00447780 — Suspension Force Computation  [docs/18]
  |     |     +-- FUN_00447e00 — Position/Lap State Update  [docs/06]
  |     |     |     +-- FUN_004f89a0 — SoundEffectTrigger  [docs/21]
  |     |     |     +-- FUN_004f88a0 — SoundEffectTrigger (RPM)  [docs/21]
  |     |     +-- FUN_004471f0 — SuspensionVibration  [docs/10]
  |     |     +-- FUN_00569280 — Copy 6 Dwords + Call  [docs/20]
  |     |     +-- FUN_0056bde0 — 3x3 Rotation Matrix (leaf)  [docs/20]
  |     |     +-- FUN_005692a0 — Quadric/Tensor Math  [docs/20]
  |     |     +-- FUN_00569410 — Inertia Tensor World-Space  [docs/18]
  |     |     +-- FUN_00441450 — PhysicsSubObjectFree  [docs/18]
  |     +-- FUN_004e9630 — PositionChangeMonitor  [docs/06]
  |     +-- FUN_0042adb0 — Session Cleanup Flag Clear  [docs/06]
  |     +-- FUN_0042aca0 — AISpeedDeltaSetter  [docs/06]
  +-- FUN_004c7b20 — Two-Call Delegation  [driver info delegate: docs/20]
  |     +-- FUN_004c3fe0 — Vehicle Name Enumeration  [docs/08]
  |     +-- FUN_004c78f0 — Nationality/Driver Info Loader  [docs/08]
  +-- FUN_00566650 — String Copy with Buffer Realloc  [path registry: docs/20]
  +-- FUN_004c6980 — SetDriverName  [register driver: docs/08]
  |     +-- FUN_004c6a10 — Driver Abbreviation Name Formatter  [docs/08]
  |           +-- FUN_00568210 — Audio Channel Stop  [docs/21]
  |           +-- FUN_005679c0 — String-Keyed Linked List Search  [docs/20]
  |           +-- FUN_00567970 — Data Entry Accessor  [docs/08]
  |           +-- FUN_00587c20 — String Search for '.'  [docs/06]
  |           +-- FUN_0058815f — String Format with Overflow Check  [docs/08]
  |           +-- FUN_00589901 — (unknown string append)  [docs/20]
  |           +-- FUN_00423a00 — Binary Search in String Table  [docs/08]
  +-- FUN_0042bc80 — Build Active Vehicle Pointer Array  [docs/06]
  +-- FUN_004c5690 — Scene Data Parser  [track/scene: docs/09]
```

## Step-by-Step Trace

### Level 0: FUN_004b70b0 — LoadVehicleEntries

**Trigger:** Session setup / vehicle file load.
**Called by:** [no callers recorded — likely dispatcher-based]
**Purpose:** Counts, validates, and registers vehicle entries from loaded data.

**Key actions:**
1. Validates each entry via FUN_004b72a0 (linked list filter)
2. Registers driver name via FUN_004c6980 (SetDriverName)
3. Registers team name and number
4. Sets DAT_005c329c (VehicleCount) = valid entries - 1
5. Resets team counters
6. Calls FUN_004ef5a0 (session state transition — timing freeze)
7. Calls FUN_0042bc80 to build active vehicle pointer array
8. Calls FUN_004c5690 to parse track/scene data

**Globals written:** DAT_005c329c (VehicleCount).

### Level 1: FUN_004ef5a0 — SessionStateTransition

**Trigger:** Called during vehicle entry processing.
**Called by:** FUN_004b70b0.
**Purpose:** Freezes session timing, updates AI vehicle paths, and computes suspension forces.

**Key actions:**
1. Calls FUN_004efb20 (3D transform with matrix multiplication)
2. Calls FUN_004ef7c0 (AI vehicle path position tracking)
3. Calls FUN_00447780 (suspension force computation with vibration physics)
4. Calls FUN_004e9630 (position change monitor)
5. Clears session cleanup flags and sets AI speed delta

### Level 1: FUN_004c7b20 — Two-Call Delegation

**Trigger:** Called for driver info registration.
**Called by:** FUN_004b70b0.
**Purpose:** Delegates to vehicle name enumeration and nationality/driver info loading.

**Key actions:**
1. Calls FUN_004c3fe0 (Vehicle Name Enumeration, docs/08)
2. Calls FUN_004c78f0 (Nationality/Driver Info Loader, docs/08)

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_004b70b0 | vehicle entry list | validate + register | VehicleCount + arrays |
| FUN_004b72a0 | entry node | linked list filter | valid flag |
| FUN_004c6980 | driver name struct | register name | name stored |
| FUN_004ef5a0 | session state | timing freeze | session context updated |
| FUN_004c5690 | scene path | parse | scene data loaded |

## Globals Written in This Chain

| Global | Name | Written by | Value meaning |
|--------|------|-----------|---------------|
| DAT_005c329c | VehicleCount | FUN_004b70b0 | Number of valid vehicles |

## Notes

- Heavy cross-system chain: calls into physics (docs/18), AI (docs/02), audio (docs/21), and track system (docs/09).
- FUN_004ef5a0 alone spans 3 systems (physics, AI, session).
- Driver abbreviation formatting (FUN_004c6a10) calls audio channel stop — likely to ensure no stale audio from previous session.
- Scene data parser (FUN_004c5690) is shared with track system (docs/09).

---
