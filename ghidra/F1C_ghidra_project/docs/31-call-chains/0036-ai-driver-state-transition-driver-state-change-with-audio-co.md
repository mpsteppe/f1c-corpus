# Chain: AI Driver State Transition — Driver State Change with Audio Commentary

Seed: FUN_00419120  |  System: docs/02-ai-system.md  |  Depth: 3  |  Functions: 5

---

## Overview

Called on AI driver state change events (caller: FUN_004bc2f0). Transitions an AI driver to a new state and triggers audio commentary. Guards on session active (DAT_007d0308), track condition (DAT_007cf3c8), and race phase (DAT_007c56a8). If SessionType==7 (race) and same team as player, plays team-related audio commentary (0x103+0x78 or 0xc6). Updates the driver state array at param_1+0x1b0. Uses distance threshold and ring buffer filter for audio event rate limiting.

## Call Tree

```
FUN_00419120 — AI Driver State Transition  [on state change event: FUN_004bc2f0]
  +-- FUN_004144d0 — Struct Init with Sentinel Values  [docs/20: random init / state reset]
  +-- FUN_004189f0 — Array Search Returning Index  [docs/20: search driver in array]
  |     +-- FUN_004144d0 — Struct Init with Sentinel Values  [match handler]
  +-- FUN_004d1b50 — Driver ID Lookup  [docs/06: resolve driver ID from index]
  +-- FUN_004144f0 — Driver Data Table Lookup and Time Conversion  [docs/02: read driver data]
  +-- FUN_00418560 — InsertDriverTableEntry  [docs/02: insert/update driver state entry]
        +-- FUN_00418b90 — Score/Threshold Gate Check
        +-- FUN_00418b70 — Short Computation (Table Lookup with Sentinel)
        +-- FUN_004145c0 — Struct Copy (32 bytes)
```

## Step-by-Step Trace

### Level 0: FUN_00419120 — AI Driver State Transition

**Trigger:** Called when AI driver state needs to change (overtake, pit, retire, etc.)
**Called by:** FUN_004bc2f0 (docs/??)
**Purpose:** Transitions AI driver to new state with audio triggers.

**Key actions:**
1. Early exits if: DAT_007d0308==0, DAT_007cf3c8==DAT_0059e440, DAT_007c56a8==8
2. Random init via FUN_004144d0()
3. If SessionType==7 (race) and same team as player: plays audio 0x103+0x78 or 0xc6
4. Distance check with DAT_0059e804 threshold
5. Ring buffer filter DAT_008aae70 to rate-limit audio events
6. Updates state at param_1+0x1b0 (DriverStateArray)

**Globals read:**
- DAT_007d0308 (RaceActiveFlag)
- DAT_007cf3c8 (TrackConditionState)
- DAT_007c56a8 (RacePhase)
- DAT_007c56a4 (SessionType)
- DAT_008aae70 (RingBufferCounter)
- DAT_0059e804 (distance threshold)
- DAT_0059e440 (ZeroThreshold)

### Level 1: AI Data Functions

**FUN_004144d0 — Struct Init with Sentinel Values** [docs/20-math-utilities.md]
- Initializes random seed / state struct with sentinel values
- Uses -1 or 0xFFFFFFFF as sentinel markers
- Also called within FUN_004189f0 as match handler

**FUN_004189f0 — Array Search Returning Index** [docs/20-math-utilities.md]
- Searches driver index in array
- Calls FUN_004144d0 on match
- Returns index or -1 if not found

**FUN_004d1b50 — Driver ID Lookup** [docs/06-session-race-logic.md]
- Resolves driver ID from session index
- Leaf function (no further callees)

**FUN_004144f0 — Driver Data Table Lookup and Time Conversion** [docs/02-ai-system.md]
- Reads from DriverDataTable (DAT_005bf9b0) at stride 0x14
- Converts time values from internal format
- Default time when param_6 == -1: reads DAT_005bf9a4

**FUN_00418560 — InsertDriverTableEntry** [docs/02-ai-system.md]
- Inserts or updates driver state table entry
- 3 sub-callees:
  - FUN_00418b90: Score/threshold gate check
  - FUN_00418b70: Short computation with sentinel table lookup
  - FUN_004145c0: 32-byte struct copy

## Globals Read in This Chain

| Global | Name | Read by |
|--------|------|---------|
| DAT_007d0308 | RaceActiveFlag | FUN_00419120 |
| DAT_007cf3c8 | TrackConditionState | FUN_00419120 |
| DAT_007c56a8 | RacePhase | FUN_00419120 |
| DAT_007c56a4 | SessionType | FUN_00419120 |
| DAT_008aae70 | RingBufferCounter | FUN_00419120 |
| DAT_005bf9b0 | DriverDataTable | FUN_004144f0 |

## Notes

- All 5 callees are documented as utility or AI-specific functions
- Audio trigger uses fixed audio IDs (0x103+0x78=0x17b, 0xc6)
- Distance threshold at DAT_0059e804 gates audio event proximity
- FUN_004144d0 appears twice: once directly and once within FUN_004189f0

---
