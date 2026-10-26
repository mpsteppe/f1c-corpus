# Chain: AISessionModeTransition — AI behavior transition between practice/quali/race modes

Seed: FUN_004193a0  |  System: docs/02-ai-system.md  |  Depth: 2  |  Functions: 7

---

## Overview

Handles AI session mode transitions (practice → quali → race). Early-exits on session inactive guards, resolves driver index via FUN_004d7cc0, checks state via FUN_004d1ad0. Only proceeds if state==2 and stored mode != 2. Plays audio cues per mode (0x89/0x8a practice, 0x85/0x86 quali, 0x87/0x88 race). Updates stored mode at param_1+0x4f0.

## Call Tree

```
FUN_004193a0 — AISessionModeTransition  [trigger: session mode change event]
  +-- FUN_004d7c10 — FloatRangeIndexLookup  [lookup driver index by position]  [leaf]
  +-- FUN_004d7cc0 — ThreeWayEnumConverter  [converts session type to mode enum]  [leaf]
  +-- FUN_004d1ad0 — ScoringGateSelector  [state check, 2 callees]
  |     +-- FUN_004d1b50 — [undocumented]
  |     +-- FUN_004d0c20 — [undocumented]
  +-- FUN_004144d0 — StructInitWithSentinels  [init struct with -1 sentinels]  [leaf]
  +-- FUN_00418a20 — BooleanOROfTwoChecks  [guard condition check, 2 callees]
  |     +-- [subtree: 2 callees — docs/20]
  +-- FUN_004144f0 — DriverDataTableLookupTimeConversion  [lookup driver time]  [leaf]
  +-- FUN_00418560 — InsertDriverTableEntry  [insert into driver DB, 3 callees]
        +-- [subtree: 3 callees — docs/02]
```

## Step-by-Step Trace

### Level 0: FUN_004193a0 — AISessionModeTransition

**Trigger:** Session mode change event (practice→quali, quali→race)
**Called by:** No callers found (callers.json — 0 callers). Likely called via event dispatch or vtable callback.
**Purpose:** Handle AI driver transitions between session modes with audio announcements.

**Key actions:**
1. Early exit on session inactive guards (FUN_00418a20 checks)
2. Resolves driver index via FUN_004d7cc0 (maps session type to enum: 0=practice, 1=quali, 2=race)
3. Checks state via FUN_004d1ad0 — only proceeds if state==2 and stored mode != 2
4. Plays audio per mode:
   - Practice: 0x89/0x8a (entry/exit)
   - Qualifying: 0x85/0x86 (entry/exit)
   - Race: 0x87/0x88 (entry/exit)
5. Updates stored mode at param_1+0x4f0 to current mode
6. Calls FUN_00418560 to update driver table entry with new mode data

**Data passed to callees:** vehicle AI struct (param_1), session type data, audio ID constants

### Level 1: Callees

All 7 callees are leaf or shallow (max depth 2). Key functions:
- **FUN_004d7cc0:** Maps SessionType (0-7) to AI mode enum (0=practice, 1=quali, 2=race)
- **FUN_004d1ad0:** Checks state machine readiness — returns whether transition should proceed
- **FUN_00418a20:** Guard check — returns bool OR of two session active conditions
- **FUN_004144f0:** Driver data table lookup — converts driver time data for the new mode
- **FUN_00418560:** Inserts updated driver data entry into the driver database table

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| Guard | session flags | Boolean OR | active/inactive |
| Mode resolve | SessionType | 3-way enum | mode (0/1/2) |
| State check | state field | == 2 check | proceed/gate |
| Audio | mode | play 2 IDs | audio cues |
| DB update | mode data | insert | driver table updated |

## Notes

- Audio IDs are paired: 0x89/0x8A for practice, 0x85/0x86 for quali, 0x87/0x88 for race
- The state==2 check suggests a state machine where 2 = "transitioning" or "session active"
- 0 callers in callers.json suggests caller was not extracted — may be called from event handler vtable

---
