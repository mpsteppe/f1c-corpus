# Chain: Pit/Race Status Message Dispatcher — HUD Message Dispatch

Seed: FUN_0041be60  |  System: docs/07-pit-system.md  |  Depth: 2  |  Functions: 5 callees

---

## Overview

FUN_0041be60 dispatches pit/race status messages to the HUD system. Not called by any known function (0 direct callers — likely invoked by HUD message system). Gets session type (2=quali, 3=race, 4=warmup, 5=practice) and vehicle mode, then dispatches cases 2-5. Falls back to default handler for other session types. Callees handle session type lookup (FUN_004ff130), vehicle mode lookup (FUN_004ff1d0), driver data table access (FUN_004144f0), and table insertion (FUN_00418560). Messages IDs 0x1fA-0x200 displayed depending on mode match. Checks time threshold for additional message 0x201.

## Call Tree

```
FUN_0041be60 — Pit/Race Status Message Dispatcher  [trigger: UI/message system callback]
  +-- FUN_004144d0 — Struct Init with Sentinel Values  [struct initialization]
  +-- FUN_004ff130 — Two-Point Interpolation  [session type lookup]
  +-- FUN_004ff1d0 — Audio Filter Parameter Calculation  [vehicle mode lookup]
  +-- FUN_004144f0 — Driver Data Table Lookup  [driver data read]
  +-- FUN_00418560 — InsertDriverTableEntry  [table entry insertion]
```

## Step-by-Step Trace

### Level 0: FUN_0041be60 — Pit/Race Status Message Dispatcher

**Trigger:** HUD message system callback (0 direct callers)
**Called by:** HUD message system (via function pointer or event queue)
**Purpose:** Dispatch pit/race status messages based on session type and vehicle mode

**Key actions:**
1. Gets session type via FUN_004ff130 (2=quali, 3=race, 4=warmup, 5=practice)
2. Gets vehicle mode via FUN_004ff1d0
3. Case 2 (practice/quali): messages 0x1fa-0x200 depending on mode match
4. Case 3 (race): messages 0x1fd/0x1fe/0x200
5. Case 4 (warmup): messages 0x1fe/0x200
6. Case 5 (practice): messages 0x1ff/0x200
7. Checks time threshold for additional message 0x201

### Level 1: Key Callees

**FUN_004ff130 — Two-Point Interpolation**
- Performs two-point interpolation to determine session type indicator
- Returns session type value used for case dispatch

**FUN_004ff1d0 — Audio Filter Parameter Calculation**
- Also used for vehicle mode detection in this context
- Returns current vehicle mode

**FUN_004144f0 — Driver Data Table Lookup**
- Reads from DriverDataTable (DAT_005bf9b0) at stride 0x14
- Returns default time value for message formatting

**FUN_00418560 — InsertDriverTableEntry**
- Inserts driver data entry into table
- Called during message formatting flow

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| Session type | — | FUN_004ff130 | 2/3/4/5 |
| Vehicle mode | — | FUN_004ff1d0 | Mode value |
| Dispatch | type + mode | Case switch | Message ID (0x1fa-0x201) |
| Format | Driver data | FUN_004144f0 | Formatted message |

## Globals Written in This Chain

| Global | Name | Written by | Value meaning |
|--------|------|-----------|---------------|
| DAT_007d0308 | RaceActiveFlag | (read by) | Race active state |
| DAT_007cf3c8 | TrackConditionState | (read by) | Track condition |
| DAT_008afef0 | PhysicsRef | (read by) | Physics reference |
| DAT_008afee8 | TrackGripValue | (read by) | Grip value |

## Notes

- Zero direct callers — likely called via HUD message system event queue
- Same callees used for multiple dispatch cases (FUN_004144f0 used for time formatting)
- Message IDs 0x1fa-0x201 are HUD message identifiers (docs/30-impl-specs/12-pit-system-spec.md)
- Time threshold check for message 0x201 uses DAT_0059e468

---
