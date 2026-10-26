# Chain 180: FUN_0041c0f0 — Pit Exit / Release Order Commentary

Seed: FUN_0041c0f0  |  System: docs/07-pit-system.md  |  Depth: 2  |  Functions: 3

---

## Overview

Determines pit exit commentary based on race context. Searches DAT_005f0738 array for entry matching param_2. Produces different commentary IDs based on pit state: State 1 (entering) → IDs 0x204-0x207 by ratio/count thresholds. State 2 (in pit) → IDs 0x209-0x20d by position/gap. State 3 (exiting, RaceMode 4) → IDs 0x210-0x217 with random 50% flip via _rand.

## Call Tree

```
FUN_0041c0f0 — Pit Exit / Release Order Commentary  [called by: pit event trigger]
  +-- FUN_004144d0 — [undocumented] commentary text init  [leaf]
  +-- FUN_004144f0 — [undocumented] commentary text dispatch  [leaf]
  +-- FUN_00418560 — [undocumented] text output (3 callees)
        +-- FUN_00418b90 — [undocumented]
        +-- FUN_00418b70 — [undocumented]
        +-- FUN_004145c0 — [undocumented]
```

## Step-by-Step Trace

### Level 0: FUN_0041c0f0 — Pit Exit / Release Order Commentary

**Trigger:** AI vehicle enters, is in, or exits pit
**Called by:** (no callers in callers.json — likely callback from pit system)
**Purpose:** Plays appropriate pit commentary based on driver pit state

**Key actions:**
1. Searches DAT_005f0738 array for entry matching param_2
2. State 1 (entering): IDs 0x204-0x207 by ratio/count thresholds
3. State 2 (in pit): IDs 0x209-0x20d by position/gap
4. State 3 (exiting, RaceMode 4): IDs 0x210-0x217 with random 50% flip via _rand

**Data passed:** Vehicle struct pointer, pit state parameter

### Level 1: FUN_004144d0 / FUN_004144f0 — Commentary Text Primitives

**Purpose:** Init/dispatch commentary text (shared utility — 30+ callers each)
**Used by system:** Commentary system (docs/02, docs/07)

### Level 1: FUN_00418560 — Text Output

**Purpose:** Outputs commentary text (shared utility — 30+ callers)

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| Search | param_2 | DAT_005f0738 lookup | matching entry |
| State 1 | entering pit | ratio/count threshold | ID 0x204-0x207 |
| State 2 | in pit | position/gap | ID 0x209-0x20d |
| State 3 | exiting (RaceMode 4) | 50% random flip | ID 0x210-0x217 |

## Notes

- Same 3 callees as Chain 179 — shared commentary infrastructure
- All 3 callees are heavily reused across the entire commentary system
- Uses RaceMode (DAT_007d0410) check for state 3 branching
- Commentary ID ranges documented in pit system spec (docs/30)

---
