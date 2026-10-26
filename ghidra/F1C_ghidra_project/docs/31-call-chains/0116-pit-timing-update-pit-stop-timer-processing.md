# Chain: Pit Timing Update — Pit Stop Timer Processing

Seed: 0x004b7a90  |  System: docs/07-pit-system.md  |  Depth: 3  |  Functions: 8

---

## Overview

Pit Timing Update processes pit stop timers for all vehicles each frame. Called by 0x004b9870 (unknown pit manager), it skips if paused, optionally sets up pit stops for a specific vehicle, loops through all vehicles to add elapsed time to pit timers and check thresholds, then processes pending pit commands from a ring buffer. The chain covers vehicle instance list building, time measurement, pit stall proximity detection, render batch sorting, and pit action sequencing.

## Call Tree

```
FUN_004b7a90 — Pit Timing Update  [trigger: per-frame pit system tick]
  +-- FUN_004b5c50 — Vehicle Instance List Builder
  |     +-- FUN_004baa50 — memory allocation  [leaf]
  |     +-- FUN_004baf10 — Dual Linked List Insert with Tagged Nodes  [leaf]
  |     +-- FUN_004bb0c0 — [PARTIAL] Unknown  [leaf]
  |     +-- FUN_004b51e0 — Driver Name/Team Copy
  |     +-- FUN_004b5120 — Vehicle Identity String Comparison  [leaf]
  +-- FUN_00568d90 — Performance Counter Diff with Scaling  [leaf]
  +-- FUN_004c71c0 — SetupCarLightingAndRender  [cross-system: docs/19 →]
  +-- FUN_004b5da0 — Pit Stall Proximity Check
  |     +-- FUN_004b68c0 — CircularBufferCheck
  |     +-- FUN_004b6940 — init pit stalls
  |     +-- FUN_004b6920 — IndexedPointerLookup  [leaf]
  |     +-- FUN_004b48e0 — Collision Object Insertion
  +-- FUN_004b6190 — Render Batch Sorting/Culling  [cross-system: docs/19 →]
  |     +-- FUN_004b68c0 — CircularBufferCheck
  |     +-- FUN_004b4840 — Hash Table Lookup  [leaf]
  |     +-- FUN_004b4800 — Bitfield Setter  [leaf]
  |     +-- FUN_004b6360 — Game Command Data Validator
  |     +-- FUN_004b4a30 — Network Packet Router & Queue Manager
  +-- FUN_004b3b30 — SessionDataCopy  [leaf]
  +-- FUN_004b3af0 — AdvanceRingBuffer
  |     +-- FUN_004b3a90 — process buffer element  [leaf]
  +-- FUN_004b6940 — Pitstop Action Set
  |     +-- FUN_004b7860 — Render Batch Node Allocator  [cross-system: docs/19 →]
  |     +-- FUN_004b69f0 — Coordinate Bound Check  [leaf]
  |     +-- FUN_004b69a0 — CircularCounterIncrement
  |     +-- FUN_004b4e10 — Physics Object List Manager  [cross-system: docs/17 →]
```

## Step-by-Step Trace

### Level 0: FUN_004b7a90 — Pit Timing Update

**Trigger:** Called per-frame from pit manager (0x004b9870)
**Called by:** 0x004b9870 (unknown pit manager)
**Purpose:** Updates elapsed time for vehicles in pit, processes pending pit commands.

**Key actions:**
1. If paused flag set: skip entire update
2. If param_3 != 0: setup pit stop for specific vehicle
3. Loop vehicles: add elapsed time to pit timer, check threshold
4. Process pending pit commands from linked list/ring buffer

**Data passed to callees:** vehicle struct pointers, pit state struct, timer values

### Level 1: FUN_004b5c50 — Vehicle Instance List Builder

**Trigger:** Called to enumerate vehicles for pit processing
**Purpose:** Builds list of active vehicles in pit range
**Key actions:** Allocates vehicle instance list, inserts into dual linked list, copies driver name/team identity

### Level 1: FUN_004b5da0 — Pit Stall Proximity Check

**Trigger:** Called to check if vehicle is near its pit stall
**Purpose:** Verifies vehicle position relative to assigned pit stall
**Key actions:** Gets pit stall count via circular buffer, locates stall data, triggers pit stop animation on proximity

### Level 1: FUN_004b6940 — Pitstop Action Set

**Trigger:** Called to execute pit stop actions (tire change, fuel, repair)
**Purpose:** Sequences pit stop operations for a vehicle
**Key actions:** Allocates render batch nodes (visual feedback), validates coordinates, increments circular counter, manages physics objects

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| Pit Timing | paused flag | early exit check | skip or process |
| Pit Timing | param_3 | pit stop setup | vehicle pit init |
| Pit Timing | vehicle list | elapsed time accumulate | pit timer update |
| Pit Timing | ring buffer | pending command process | command execution |

## Globals Written in This Chain

- None directly — operates on pit state structs passed through params

## Notes

- Cross-system handoffs: FUN_004c71c0 (renderer — car lighting), FUN_004b6190 (renderer — batch sorting), FUN_004b7860 (renderer — node allocator), FUN_004b4e10 (collision — physics object list)
- FUN_00568d90 (Performance Counter Diff) is used for precise elapsed time measurement
- Ring buffer (FUN_004b3af0/FUN_004b3a90) handles pending pit command queue
- High moddability: timer thresholds, ring buffer size, pit stop durations all tunable

---
