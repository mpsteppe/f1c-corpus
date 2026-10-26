# Chain: Per-Driver Race Commentary — Driver Event Commentary Message Generation

Seed: FUN_00419c50  |  System: docs/09-track-system.md  |  Depth: 3  |  Functions: 8

---

## Overview

Generates per-driver race commentary messages during a session. Called from the RaceFinishHandler (FUN_004a0ba0, docs/06). Operates per finished driver (+0x4064 == 1) with no previous message (+0x4070 == 0). Checks if driver is player (matching team ID) or AI, then selects commentary format (winning, P2, P7+, or non-player lead/gain). Reads season/championship data for clinch scenarios.

## Call Tree

```
FUN_00419c50 — Per-Driver Race Commentary  [trigger: called by FUN_004a0ba0]
  +-- FUN_004144d0 — Struct Init with Sentinel Values  [commentary struct init: docs/20]
  +-- FUN_004144f0 — Driver Data Table Lookup  [time conversion: docs/02]
  +-- FUN_00418560 — InsertDriverTableEntry  [text output: docs/02]
  |     +-- FUN_00418b90 — Score/Threshold Gate Check  [docs/06]
  |     +-- FUN_00418b70 — Short Computation  [docs/20]
  |     +-- FUN_004145c0 — Struct Copy (32 bytes)  [docs/20]
  +-- FUN_00566810 — String Read (unknown)  [docs/06]
  +-- FUN_004c2850 — Linked List Dereference  [season data: docs/01]
  +-- FUN_004c11d0 — FlagsGetter  [race count: docs/06]
  +-- FUN_004c1190 — SceneOrder Reader  [remaining races: docs/08]
  +-- FUN_004c13a0 — Short Computation / Index Validation  [driver points: docs/08]
```

## Step-by-Step Trace

### Level 0: FUN_00419c50 — Per-Driver Race Commentary

**Trigger:** Called from RaceFinishHandler (FUN_004a0ba0, docs/06) after a driver finishes.
**Called by:** FUN_004a0ba0 (RaceFinishHandler, docs/06).
**Purpose:** Generates commentary text for individual driver finish events.

**Key actions:**
1. Checks DAT_007d0308 (RaceActiveFlag) and DAT_007cf3c8 (TrackConditionState)
2. Only for finished drivers (+0x4064 == 1) with no previous message (+0x4070 == 0)
3. If driver is player (matching +0x4894 TeamID):
   - Position 1: championship clinch check — reads remaining races via FUN_004c2850/FUN_004c11d0/FUN_004c1190
   - Position 2+: position commentary (P2 "good", P7+ "need improvement")
4. If non-player:
   - Position 1: announces driver name in lead (ID 0x105)
   - Position 2–5: announces driver gaining (ID 0x104)
5. All output routed through FUN_00418560 (InsertDriverTableEntry) for display

**Globals read:** DAT_007d0308 (RaceActiveFlag), DAT_007cf3c8 (TrackConditionState).

**Data passed to callees:** driver struct pointer, commentary format ID, position value.

### Level 1: FUN_004c2850 — Linked List Dereference

**Trigger:** Called for championship/clinch context.
**Called by:** FUN_00419c50.
**Purpose:** Accesses season data linked list for race count and championship state.

**Key actions:**
1. Dereferences season data linked list
2. Returns season/race count data for clinch determination

### Level 1: FUN_00418560 — InsertDriverTableEntry

**Trigger:** Called for each commentary output.
**Called by:** FUN_00419c50.
**Purpose:** Registers commentary text in the driver display table.

**Key actions:**
1. Validates score/threshold via FUN_00418b90
2. Performs table lookup with sentinel via FUN_00418b70
3. Copies 32-byte struct via FUN_004145c0

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_00419c50 | driver ptr + finish state | commentary selection | format ID |
| FUN_004c2850 | season linked list | dereference | race count |
| FUN_004c11d0 | session data | flags read | race position context |
| FUN_004c1190 | scene data | order read | remaining races |
| FUN_00418560 | format ID + driver | table insert | display output |

## Globals Written in This Chain

None. Read-only — generates display output via table insertion.

## Notes

- Commentary format IDs: 0x9d (championship context), 0x9e (normal position), 0x9f (clinch), 0xa0-0xb1 (track-specific), 0x104 (non-player gain), 0x105 (non-player lead).
- FUN_004144d0/FUN_004144f0/FUN_00418560 triple appears again — this is the standard commentary output pipeline.
- Season data access crosses into docs/01 (engine architecture) for linked list infrastructure.

---
