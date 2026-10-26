# Chain: Pit Stop Operation Timer — Pit Stop Duration Computation

Seed: FUN_004a6340  |  System: docs/07-pit-system.md  |  Depth: 4  |  Functions: 11

---

## Overview

Computes pit stop return time for a vehicle in the pit. Called from the pit stop ready check (FUN_004a6200). Accumulates phase durations: wheel change (4 random cubic durations via ring buffer), repair time, refuel time with variance, and optional penalty time if disqualified. Calls a physics solver dispatch (FUN_0043b930) and an audio event scheduler (FUN_004a35f0). Writes results to vehicle pit state struct.

## Call Tree

```
FUN_004a6340 — Pit Stop Operation Timer  [trigger: called by FUN_004a6200]
  +-- FUN_004f1890 — Speed/Value Setter with Global Mirror  [set speed value: docs/06]
  +-- FUN_004a5820 — Nth Valid Part Lookup  [find wheel/part index: docs/07]
  |     +-- FUN_004d7570 — (N/A, unlabeled)
  +-- FUN_004d7570 — (N/A)  [part reference lookup]
  +-- FUN_004f1a60 — Loop with Conditional Sub-Call  [variance loop: docs/20]
  +-- FUN_004f1860 — ConditionalMathDispatch  [guarded solver: docs/06]
  |     +-- FUN_0043b930 — SolverDispatch  [physics solver: docs/18]
  |           +-- FUN_0043bb00 — DeltaUpdateTracking  [docs/18]
  |           +-- FUN_00436470 — QuadraticSpringEval  [docs/18]
  |           +-- FUN_0043ba20 — Constraint Force Solver  [docs/18]
  |           |     +-- FUN_0056d1c0 — RelativeVelocityCompute  [docs/18]
  |           |     +-- FUN_0056d2d0 — Body Force Application  [docs/18]
  |           +-- FUN_0043bb30 — QuadFunctionEval  [docs/18]
  |           +-- FUN_0043bb80 — Quadratic Force/Torque Calculator  [docs/18]
  |           +-- FUN_0043bbd0 — SpringDamperCompute  [docs/18]
  +-- FUN_004b33b0 — ProgressBarEventEncode  [encode progress: docs/20]
  +-- FUN_004a35f0— Audio Event Timing Scheduler  [audio timing: docs/21]
  |     +-- FUN_004a1fd0 — Range Proportion Initializer  [docs/20]
  +-- FUN_004a3560 — Flag Setter with OR  [set completion flag: docs/20]
```

## Step-by-Step Trace

### Level 0: FUN_004a6340 — Pit Stop Operation Timer

**Trigger:** Called by FUN_004a6200 (Pit Stop Ready Check, docs/07).
**Called by:** FUN_004a6200 — pit stop ready state machine.
**Purpose:** Computes total pit stop duration (return time) for a vehicle.

**Key actions:**
1. Accumulates phase durations: wheel change, repair, refuel
2. Wheel change: 4 random cubic durations via ring buffer (FUN_004f1a60)
3. Repair: adds repair time if needed
4. Refuel: increments global counter, adds fuel time with variance (FUN_004a35f0)
5. If disqualified: adds penalty time
6. Calls physics solver (FUN_004f1860 → FUN_0043b930) for vehicle dynamics
7. Writes progress via FUN_004b33b0

**Globals read:** EngineWearMode, fuel calculation constants.
**Data passed to callees:** vehicle struct pointer, part indices, time accumulators.

### Level 1: FUN_004f1860 — ConditionalMathDispatch

**Trigger:** Called once during pit stop physics update.
**Called by:** FUN_004a6340.
**Purpose:** Guards and dispatches to physics solver.

**Key actions:**
1. Checks preconditions before calling solver
2. Dispatches to FUN_0043b930 (SolverDispatch, docs/18)
3. Solver evaluates 6 sub-solvers: delta tracking, spring eval, constraint force, quad eval, torque calc, spring-damper

### Level 1: FUN_004a35f0 — Audio Event Timing Scheduler

**Trigger:** Called during refuel phase.
**Called by:** FUN_004a6340.
**Purpose:** Schedules audio events tied to pit stop timing.

**Key actions:**
1. Initializes range proportion via FUN_004a1fd0
2. Sets up audio timing for pit stop events (fuel nozzle, etc.)

### Level 1: FUN_004a5820 — Nth Valid Part Lookup

**Trigger:** Called for wheel/part index resolution.
**Called by:** FUN_004a6340.
**Purpose:** Finds the Nth valid part in the vehicle's part list.

**Key actions:**
1. Searches vehicle part list for Nth valid entry
2. Returns part index for wheel change operations

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_004a6340 | vehicle ptr + part params | duration accumulation | total pit return time |
| FUN_004f1860 | vehicle state | solver dispatch | physics state update |
| FUN_004a35f0 | phase timing | audio schedule | audio event at expected time |
| FUN_004a5820 | part list | Nth valid search | part index |
| FUN_004b33b0 | progress value | encode | UI progress event |

## Globals Written in This Chain

None identified. Reads only.

## Notes

- Cross-system call into physics dynamics (FUN_0043b930, docs/18) for solver update during pit stop.
- Cross-system call into audio (FUN_004a35f0, docs/21) for timing-aligned sound events.
- Wheel change uses 4 random cubic durations — produces realistic variance in pit stop times.
- Fuel time includes variance component for natural feel.

---
