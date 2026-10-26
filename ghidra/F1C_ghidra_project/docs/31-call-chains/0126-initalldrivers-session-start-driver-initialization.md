# Chain: InitAllDrivers — Session Start Driver Initialization

Seed: FUN_004c1050  |  System: docs/06-session-race-logic.md  |  Depth: 3  |  Functions: 16

---

## Overview

Initializes all vehicle/driver entries at session start. Called once when a new session (race/qualifying/practice) begins. Resets UI theme, clears scoring slots for 103 sub-slots, stores game state, loads path strings, and validates driver data from configuration files.

## Call Tree

```
FUN_004c1050 — InitAllDrivers  [trigger: session start]
  +-- FUN_004c11d0 — FlagsGetter  [reads UI/theme flags]
  +-- FUN_004c11e0 — Race Weekend Config Reader  [reads SeasonRaces section]
  +-- FUN_004c55b0 — Track/Scene Loader  [loads track/scene data]
  |     +-- FUN_00566650 — String Copy with Buffer Realloc
  +-- FUN_004c54f0 — .AIW / .SCN Filename Builder  [builds track filenames]
  |     +-- FUN_00566650 — String Copy with Buffer Realloc (×2)
  +-- FUN_004c0850 — CopyDriverDataToScoringDB  [copies driver data to scoring DB]
  |     +-- FUN_004b8da0 — ProcessDriverEntries  [iterates driver entries]
  |     +-- FUN_004c1370 — ActiveEntityCounter  [counts active vehicles]
  |     +-- FUN_004ef5a0 — SessionStateTransition  [transitions session state]
  +-- FUN_004c1370 — ActiveEntityCounter  [counts active vehicles — leaf]
  +-- FUN_004ef5a0 — SessionStateTransition  [transitions session state machine]
  |     +-- FUN_004e1970 — Effect Data Table Initialization
  |     +-- FUN_004e3a50 [undocumented — physics init]
  |     +-- FUN_004c7c00 — Constant 5
  |     +-- FUN_004c8dc0 [undocumented]
  |     +-- FUN_004c7980 [undocumented]
  |     +-- FUN_00566db0 [undocumented]
  +-- FUN_004b1190 — Session Config Loader  [loads session .ini config]
  |     +-- FUN_005679c0 — string search (×2)
  |     +-- FUN_00588410 — string compare
  |     +-- FUN_004b1d90 — string copy
  |     +-- FUN_004b1c20 ×2 — string operations
  +-- FUN_00566650 — String Copy with Buffer Realloc  [path string utility]
  +-- FUN_00415730 — Short Computation (UI/Vehicle Setup Chain)  [validation math]
  |     +-- FUN_00566650 — String Copy with Buffer Realloc
  |     +-- [4 other utility callees]
```

## Key Actions

1. Resets UI theme flags via FUN_004c11d0
2. Reads race weekend config via FUN_004c11e0 (SeasonRaces section)
3. Loads track/scene data (FUN_004c55b0)
4. Builds .AIW/.SCN filenames for track (FUN_004c54f0)
5. Loops 103 sub-slots: copies driver data to scoring DB, clears unused slots
6. Stores GameState from param_1+0xb14c
7. Loads session config for path strings and validation
8. Transitions session state machine (FUN_004ef5a0) to active state

## Globals Read

- `DAT_007d2e48` — SeasonScoringDB (stride 0x48c0)
- `DAT_008ac488` — SceneFileCount
- `DAT_008ac48c` — CurrentSceneIndex

## Data Flow Summary

| Input | Operation | Output |
|-------|-----------|--------|
| Vehicle config | Parse +0x424 entries | Driver data in scoring DB |
| Track name | Build .AIW/.SCN paths | Track resource files |
| Session config files | Parse INI sections | Session configuration |
| Empty slots | Clear +0x48c0 blocks | Clean scoring slots |

## Notes

- 10 direct callees, most with sub-callees (depth 2-3)
- Heavy string/path operations: FUN_00566650 appears 4+ times
- FUN_004b1190 (Session Config Loader) handles INI parsing with string search/compare
- Central initialization — called once per session, not per-frame

---
