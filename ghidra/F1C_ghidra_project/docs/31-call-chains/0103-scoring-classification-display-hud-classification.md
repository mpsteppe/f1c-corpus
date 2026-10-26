# Chain: Scoring/Classification Display — HUD Classification

Seed: FUN_0041e320  |  System: docs/06-session-race-logic.md  |  Depth: 2  |  Functions: 11

---

## Overview

Renders the scoring/classification display on the HUD. Returns early if race is inactive. Gets session driver list (FUN_0041f340) and race results (FUN_0041f5d0), checks session state (FUN_004c11d0), and displays current classification with 3-way positions: current, best, and gap. Handles position change detection and gap/interval messages.

## Call Tree

```
FUN_0041e320 — Scoring/Classification Display  [per-frame HUD update]
  +-- FUN_004144d0 — Struct Init with Sentinel Values
  +-- FUN_004c2850 — Linked List Dereference
  +-- FUN_004c11d0 — FlagsGetter
  +-- FUN_0041f340 — Get Driver List [undocumented]
  +-- FUN_0041f5d0 — Get Race Results [undocumented]
  +-- FUN_00415550 — Linked List Index Scanner with Validation
  |     +-- FUN_00566810 — list scan
  +-- FUN_004144f0 — Driver Data Table Lookup and Time Conversion
  +-- FUN_00418560 — InsertDriverTableEntry
  |     +-- FUN_00418b90 — table insert
  |     +-- FUN_00418b70 — entry alloc
  |     +-- FUN_004145c0 — key compute
  +-- FUN_00420cf0 — [undocumented]
```

## Step-by-Step Trace

### Level 0: FUN_0041e320 — Scoring/Classification Display

**Trigger:** Called per-frame from HUD update (FUN_004a08e0, steward loop).
**Called by:** FUN_004a08e0 (steward main loop).
**Purpose:** Renders driver classification with positions, gaps, and best times.

**Key actions:**
1. Returns if race inactive (DAT_007d0308 check)
2. Gets session driver list via FUN_0041f340
3. Gets race results via FUN_0041f5d0
4. If FUN_004c11d0 == 1: displays current classification
5. Reads +0xb144 state flag for session type (3=race)
6. Compares driver name strings for identification
7. Shows gap/interval messages
8. Handles position change detection

### Level 1: FUN_004c2850 — Linked List Dereference

**Trigger:** Gets session data linked list head.
**Purpose:** Dereferences session data linked list to access driver entries.

### Level 1: FUN_004c11d0 — FlagsGetter

**Trigger:** Checks session display flags.
**Purpose:** Returns session state flags — gates whether classification is shown.

### Level 1: FUN_0041f340 — Get Driver List [undocumented]

**Trigger:** Gets active driver list.
**Purpose:** Builds driver list for current session.

### Level 1: FUN_0041f5d0 — Get Race Results [undocumented]

**Trigger:** Gets race result data.
**Purpose:** Reads current race results (positions, times, gaps).

### Level 1: FUN_00418560 — InsertDriverTableEntry

**Trigger:** Inserts driver into display table.
**Purpose:** Adds/updates driver entry in the scoring display table.

### Level 1: FUN_004144f0 — Driver Data Table Lookup and Time Conversion

**Trigger:** Looks up driver data.
**Purpose:** Reads driver performance data from driver table, converts time values.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| Gate | RaceActiveFlag | check | skip/display |
| Driver list | session data | FUN_0041f340 | driver entries |
| Results | session data | FUN_0041f5d0 | result array |
| Classification | flags, positions | format | HUD text |
| Position change | prev vs current | compare | delta display |

## Notes

- 9 callees, shallow depth (max 2 levels).
- Two key callees (FUN_0041f340, FUN_0041f5d0) are [undocumented].
- Heavy reading from session data structures via linked list (FUN_004c2850).
- Cross-system: FUN_004144d0 (docs/20 math utilities), FUN_004144f0 (docs/02 AI).

---
