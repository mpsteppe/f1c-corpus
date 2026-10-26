# Chain 172: FUN_004b8da0 — ProcessDriverEntries

Seed: FUN_004b8da0  |  System: docs/08-file-formats.md  |  Depth: 3  |  Functions: 11

---

## Overview

Processes driver entries from a linked list during file loading. Reads driver name, team name, and number from each entry node. Validates entries, then handles three outcomes: empty slot (remove entry), new driver (register), or existing driver (update number). Updates VehicleCount accordingly. This is part of the setup phase where driver rosters are loaded from .svm/.veh files.

## Call Tree

```
FUN_004b8da0 — ProcessDriverEntries  [called by: file loading pipeline]
  +-- FUN_004b50c0 — [undocumented] Validation  [leaf]
  +-- FUN_004c69e0 — Path filename extractor  [leaf]
  +-- FUN_00588410 — [undocumented]  [leaf]
  +-- FUN_004c7b20 — Two-Call Delegation
  |     +-- FUN_004c3fe0  [undocumented]
  |     +-- FUN_004c78f0  [undocumented]
  +-- FUN_00566650 — String Copy with Buffer Realloc  [leaf]
  +-- FUN_004c6980 — SetDriverName
  |     +-- FUN_004c6a10  [undocumented]
  +-- FUN_004c6e80 — ResetDriverGridState (9 callees)
  |     +-- 9 leaf callees [undocumented]
  +-- FUN_004ef5a0 — SessionStateTransition (6 callees)
  |     +-- FUN_004efb20  [undocumented]
  |     +-- FUN_004ef7c0  [undocumented]
  |     +-- FUN_00447780 — vector math
  |     +-- FUN_004e9630 — session ctx
  |     +-- FUN_0042adb0  [undocumented]
  |     +-- FUN_0042aca0  [undocumented]
  +-- FUN_0042bc80 — Build Active Vehicle Pointer Array  [leaf]
  +-- FUN_004c6c40 — vehgen.scn File Loader (9 callees)
  |     +-- FUN_004ddf90 — scene file TEAMDIR/VEHDIR writer
  |     +-- FUN_004a4900 — scene processing
  |     +-- FUN_004dfce0 — scene config loader
  |     +-- FUN_004f8370 — vehicle positioning?
  |     +-- FUN_004bb800 — grid setup
  |     +-- FUN_004c6980 — nationality reader
  |     +-- FUN_004c7b50 — cleanup
  |     +-- FUN_00410b20 — init
  |     +-- FUN_00587bcf — free
  +-- FUN_004c6d90 — SceneRenderUpdate  [leaf]
```

## Step-by-Step Trace

### Level 0: FUN_004b8da0 — ProcessDriverEntries

**Trigger:** File loading pipeline encounters driver entries in linked list
**Called by:** (no callers registered in callers.json — likely called during setup/init)
**Purpose:** Processes driver entries — validates, registers/updates/removes drivers

**Key actions:**
1. Reads name, team name, number from each entry node
2. Validates via FUN_004b50c0
3. Three outcomes: empty slot (remove), new entry (register), existing (update number)
4. Increments/decrements VehicleCount
5. Calls setup helpers: FUN_004c6c40 (vehgen.scn load), FUN_004ef5a0 (session state transition)

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| entry node | name/team/number | validate via FUN_004b50c0 | valid/invalid |
| new entry | driver data | register via FUN_004c6980 | updated driver list |
| existing | updated number | update | modified entry |
| setup | session config | FUN_004c6c40 | vehgen.scn loaded |

## Notes

- FUN_004c6e80 (ResetDriverGridState) has 9 callees but all are undocumented leaves — omitted from detailed trace per rule (only most complex subtrees documented)
- FUN_004c6c40 (vehgen.scn File Loader) similarly has 9 callees — cross-system handoff to scene file loading (docs/08)
- FUN_004ef5a0 is SessionStateTransition — cross-system to docs/06 session logic
- Chain depth limited by undocumented leaf callees at level 2

---
