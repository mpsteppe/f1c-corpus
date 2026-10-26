# Chain: Main Session Execution Loop — Active Session Driver

Seed: 0x0046bf10  |  System: docs/06-session-race-logic.md  |  Depth: 3  |  Functions: 10

---

## Overview

Main Session Execution Loop runs the active game session (race, qualifying, practice) until completion. Called from session state machine (callers: 0x0046da20, 0x0046dc60), it sets time thresholds based on session type, then enters a loop calling AI/vehicle frame tick until done. The chain covers frame setup, AI behavior tick, race commentary tracking, and cleanup.

## Call Tree

```
FUN_0046bf10 — Main Session Execution Loop  [trigger: session state machine → run session]
  +-- FUN_004be6f0 — Delegation
  |     +-- FUN_004be700 — Performance/Setup Struct Initializer  [leaf]
  +-- FUN_004c8d80 — Virtual Call on DAT_008ac4c4  [leaf]
  +-- FUN_004988c0 — Byte Setter at +0x18f5  [leaf]
  +-- FUN_004beb10 — AI Overtake / Collision Detection Loop
  |     +-- FUN_004bf0a0 — AI Behavior Initialization / Tick
  |     +-- FUN_004bea10 — unidentified logic  [leaf]
  |     +-- FUN_004bef60 — AI Collision / Out-of-Bounds Check
  |     +-- FUN_004bf390 — AI Driver Sorting / Priority
  |     +-- FUN_004b33b0 — ProgressBarEventEncode  [sound?]
  +-- FUN_00496880 — [unidentified — docs/06]  [leaf]
  +-- FUN_00497250 — Short Computation (Byte Field Setter)  [leaf]
  +-- FUN_00496e90 — [unidentified — docs/06]  [leaf]
  +-- FUN_004186a0 — Init large buffer of floats to -1.0f  [leaf]
  +-- FUN_0041d630 — Race Commentary / Best Lap Tracking
  +-- FUN_004b0170 — Empty Stub (vtable slot)  [leaf]
```

## Step-by-Step Trace

### Level 0: FUN_0046bf10 — Main Session Execution Loop

**Trigger:** Session state machine transitions to active session
**Called by:** 0x0046da20, 0x0046dc60 (session state machine variants)
**Purpose:** Runs active session loop (race/practice/quali) until completion.

**Key actions:**
1. Sets time threshold based on SessionType
2. Loop: calls FUN_004beb10 (frame tick) until done
3. If race: cleanup via DAT_005eb10c
4. Returns 0 when done

**Data passed to callees:** session context, vehicle array pointers

### Level 1: FUN_004beb10 — AI Overtake / Collision Detection Loop

**Trigger:** Called every frame during session loop
**Purpose:** Per-frame AI behavior tick — overtaking logic, collision detection, driver sorting

**Key actions:**
1. FUN_004bf0a0 — AI Behavior Initialization / Tick (per-driver AI update)
2. FUN_004bea10 — unidentified logic
3. FUN_004bef60 — AI Collision / Out-of-Bounds Check (safety validation)
4. FUN_004bf390 — AI Driver Sorting / Priority (race order positioning)
5. FUN_004b33b0 — ProgressBarEventEncode (sound/UI progress reporting)

### Level 1: FUN_0041d630 — Race Commentary / Best Lap Tracking

**Trigger:** Called per-frame during session
**Purpose:** Tracks best lap times and triggers race commentary events

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| Main Session Loop | SessionType | time threshold setup | loop duration |
| Main Session Loop | vehicle array | per-frame AI tick | AI state update |
| AI Loop | driver data | overtake/collision check | position updates |
| AI Loop | driver data | sorting/priority | race order |

## Globals Written in This Chain

- `DAT_005eb10c` — race cleanup flag (written when race done)
- `DAT_007c56a4` — SessionType (read for threshold)

## Notes

- Core session loop is tight: AI tick + commentary is the entire per-frame workload
- FUN_004beb10 (AI loop) has 6 callees — represents the bulk of per-frame work
- FUN_004b33b0 (ProgressBarEventEncode) is cross-system handoff to audio/UI
- Cleanup path only executes for race sessions

---
