# Chain: AI Overtake/Defend State Change — AI Driver State Machine + Audio

Seed: FUN_00419690  |  System: docs/02-ai-system.md  |  Depth: 3  |  Functions: 4

---

## Overview

Manages AI driver overtaking/defending state transitions with audio commentary. Called from Lap Time Comparison / Position Swap (FUN_004d1c40, docs/06). Three branches: param_2=0 (overtake attempt), 1 (defend), 2 (other). Sets driver state array at param_1+0x1b0+param_3×4 = 1. Plays different audio IDs based on session type and slot. Uses the standard commentary pipeline (FUN_004144d0/FUN_004144f0/FUN_00418560) and a boolean OR guard check (FUN_00418a20).

## Call Tree

```
FUN_00419690 — AI Overtake/Defend State Change  [trigger: position/gap change detected]
  +-- FUN_004144d0 — Struct Init with Sentinel Values  [commentary init: docs/20]
  +-- FUN_00418a20 — Boolean OR of Two Checks  [guard check: docs/20]
  |     +-- FUN_004189f0 — Array Search Returning Index  [docs/20]
  |     +-- FUN_004189b0 — State-Checked Virtual Dispatch  [docs/01]
  +-- FUN_004144f0 — Driver Data Table Lookup  [time conversion: docs/02]
  +-- FUN_00418560 — InsertDriverTableEntry  [commentary output: docs/02]
        +-- FUN_00418b90 — Score/Threshold Gate Check  [docs/06]
        +-- FUN_00418b70 — Short Computation  [docs/20]
        +-- FUN_004145c0 — Struct Copy (32 bytes)  [docs/20]
```

## Step-by-Step Trace

### Level 0: FUN_00419690 — AI Overtake/Defend State Change

**Trigger:** Called by FUN_004d1c40 (Lap Time Comparison / Position Swap, docs/06) when a position change event occurs.
**Called by:** FUN_004d1c40 (docs/06).
**Purpose:** Updates AI state and triggers audio for overtake/defend events.

**Key actions:**
1. Guard checks on globals (DAT_007d0308, DAT_007cf3c8, etc.)
2. Three branches based on param_2: 0 = overtake attempt, 1 = defend, 2 = other
3. Sets driver state array: param_1+0x1b0+param_3×4 = 1
4. Plays audio commentary IDs based on session type and driver slot
5. Output via FUN_00418560 (InsertDriverTableEntry)

**Data passed to callees:** driver struct pointer, event type (0/1/2), driver slot index.

### Level 1: FUN_00418a20 — Boolean OR of Two Checks

**Trigger:** Called as guard before state change.
**Called by:** FUN_00419690.
**Purpose:** Returns true if either of two sub-checks passes.

**Key actions:**
1. Calls FUN_004189f0 — array search returning index
2. Calls FUN_004189b0 — state-checked virtual dispatch
3. Returns OR of both results

### Level 1: FUN_00418560 — InsertDriverTableEntry

**Trigger:** Called for audio output.
**Called by:** FUN_00419690.
**Purpose:** Registers commentary/audio event in driver table.

**Key actions:**
1. Validates score/threshold (FUN_00418b90)
2. Table lookup with sentinel (FUN_00418b70)
3. Copies 32-byte struct (FUN_004145c0)

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_00419690 | driver + event type | state set + audio | state array[slot] = 1 |
| FUN_00418a20 | driver state | boolean OR check | pass/fail |
| FUN_00418560 | event format ID | table insert | audio event registered |

## Globals Written in This Chain

None. Writes driver state array (struct field, not global).

## Notes

- State array at +0x1b0 is indexed by param_3 × 4 — stores binary state (0/1) per driver slot.
- Audio commentary IDs differ by branch — overtake vs defend use different format IDs.
- Standard FUN_004144d0/FUN_004144f0/FUN_00418560 triple appears again for commentary output.
- Called from position swap logic — runs when AI driver gains or loses a position.

---
