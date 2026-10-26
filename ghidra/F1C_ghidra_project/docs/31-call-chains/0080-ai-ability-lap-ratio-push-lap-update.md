# Chain: AI Ability / Lap Ratio / Push Lap Update

Seed: FUN_00429470  |  System: docs/02-ai-system.md  |  Depth: 3  |  Functions: 11

---

## Overview

Per-lap AI ability update. Computes lap type (push/regular), updates LiveLapRatio from QualifyingAbility/RaceAbility, checks pit entry triggers (tire laps, compound mismatch, wear thresholds), and manages push-lap logic with random chance based on RaceAbility. Called each lap completion (race only).

## Call Tree

```
FUN_00429470 — AI Ability / Lap Ratio / Push Lap Update  [trigger: lap completion, race only]
  +-- FUN_004d1cf0 — VehicleTypeCheck  [branch on vehicle type — leaf]
  +-- FUN_0042a3d0 — AbilityBasedLapRatio  [compute lap ratio from ability]
  |     +-- FUN_0042a110 — ForcePitExitAdvanceState  [pit logic — docs/02]
  |           +-- FUN_004a5c40 — SessionAdvance [docs/06]
  |           +-- FUN_004a5e40 — SessionStateSet [docs/06]
  |           +-- FUN_0042ac70 — PhaseAdvance [docs/02]
  +-- FUN_004f1890 — RaceAbilityRead  [read RaceAbility — leaf]
  +-- FUN_0042a6f0 — PushLapRandomCheck  [random push lap check]
  |     +-- FUN_0042a110 — ForcePitExitAdvanceState (shared)
  +-- FUN_0042a110 — ForcePitExitAdvanceState  [pit entry trigger — docs/02]
  |     +-- FUN_004a5c40 — SessionAdvance [docs/06]
  |     +-- FUN_004a5e40 — SessionStateSet [docs/06]
  |     +-- FUN_0042ac70 — PhaseAdvance [docs/02]
  +-- FUN_004f1630 — TireLapCounterCheck  [check tire lap counter — leaf]
  +-- FUN_004a4830 — CompoundMismatchCheck  [check tire compound — docs/07]
  +-- FUN_00429eb0 — RacePhasePitEntryTrigger  [race-phase entry — docs/02]
  |     +-- FUN_0042ad20 — RandomProximityCheck [docs/10]
  |     +-- FUN_0042a110 — ForcePitExitAdvanceState (shared)
```

## Step-by-Step Trace

### Level 0: FUN_00429470 — AI Ability / Lap Ratio / Push Lap Update

**Trigger:** Called each lap completion (race session only)
**Called by:** AI per-lap update pipeline
**Purpose:** Updates AI current lap ratio, push-lap logic, pit entry triggers.

**Key actions:**
1. Branch on vehicle type via FUN_004d1cf0
2. Lap type: ability-based lap ratio, LiveLapRatio = min(QualiAbility + delta, RaceAbility + delta)
3. Push lap: random chance based on RaceAbility
4. Pit check: tire-lap counter vs current lap, calls FUN_0042a110
5. Compound mismatch: compare current vs intended, call pit if mismatch
6. Tire wear threshold check

**Data passed to callees:** Vehicle pointer, ability values, lap counters

### Level 1: FUN_0042a110 — ForcePitExitAdvanceState

**Trigger:** Called when pit entry conditions met
**Called by:** FUN_00429470, FUN_0042a3d0, FUN_0042a6f0, FUN_00429eb0, FUN_0042a180
**Purpose:** Forces AI to exit pit lane or advance session phase.

**Key actions:**
1. SessionType 7: check SeasonPoints vs total laps - 1
2. If not last: call advance (FUN_004a5c40/FUN_004a5e40). If last: skip
3. Non-race: always advance via FUN_0042ac70

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_00429470 | Vehicle ability offsets (+0x1130/0x1138) | Lap ratio = min(Quali+Race)/2 | LiveLapRatio |
| FUN_00429470 | RaceAbility (+0x1138) | Random push-lap chance | Push lap flag |
| FUN_00429470 | Tire lap counter + wear | Conditional pit call | Pit entry trigger |
| FUN_0042a110 | SessionType + SeasonPoints | Phase advance or skip | State transition |

## Struct Offsets Used

| Offset | Field | Notes |
|--------|-------|-------|
| +0x1130 | QualifyingAbility | AI qualifying skill |
| +0x1138 | RaceAbility | AI race skill |
| +0x114f | LiveLapRatio | Current lap performance ratio |
| +0x1142 | LapTypeFlag | Push/regular lap flag |

## Notes

- FUN_0042a110 is called from 5 different locations — shared utility for pit/phase management
- Cross-system calls into docs/06 (session state) and docs/07 (pit system)
- FUN_004f1890 and FUN_004f1630 are leaf AI data readers

---
