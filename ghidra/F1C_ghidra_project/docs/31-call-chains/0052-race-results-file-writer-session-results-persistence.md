# Chain: Race Results File Writer — Session Results Persistence

Seed: 0x004d24d0  |  System: docs/06-session-race-logic.md  |  Depth: 3  |  Functions: 13

---

## Overview

Writes the `raceresults.txt` file to the `Results\` directory with full session data. Triggered at session end (race finish, DNF, DSQ). Produces timestamped filename, writes header with game version, per-race settings, and per-driver results sorted by finish position. Output: human-readable race results file on disk.

## Call Tree

```
0x004d24d0 — Race Results File Writer  [trigger: session end, race complete]
  +-- 0x00566650 — String Write  [builds filename from timestamp]
  +-- 0x005665b0 — Path Append  [appends Results\ path prefix]
  +-- 0x00589671 — mkdir  [creates Results\ directory]
  +-- 0x005896ee — fopen  [opens file for writing]
  +-- 0x00589e6c — Get Time  [reads system time for timestamp]
  +-- 0x00566940 — File Status  [checks file state]
  +-- 0x00566c30 — Write Header/Section  [3 sub-calls, writes INI-style headers]
  |     +-- 0x0058a163 — String Write  [writes formatted string to file]
  |     +-- 0x0058ac95 — Format  [formats values for output]
  |     +-- 0x00535220 — Alloc  [allocates temp buffer for formatting]
  +-- 0x00566b90 — File Close  [conditional close w/ flag dispatch]
  |     +-- 0x00587d02 — File Close Method A  [leaf]
  |     +-- 0x005355a0 — File Close Method B  [leaf]
  +-- 0x005668d0 — File Cleanup  [conditional field free]
  |     +-- 0x00566b90 — File Close  [recurse: conditional close]
  |     +-- 0x00587bcf — Free Wrapper  [heap free]
  +-- 0x004bc2a0 — Lap Time Read (wrapper)  [reads per-lap times from vehicle struct]
  +-- 0x004bc270 — Lap Time Read (core)  [reads lap time array at +0x403c]
  +-- 0x00567700 — Format Time  [formats time value to string]
  +-- 0x005676c0 — Format Time  [formats time value to string, alt format]
```

## Step-by-Step Trace

### Level 0: 0x004d24d0 — Race Results File Writer

**Trigger:** Session end — race finishes, driver DNFs, or DSQ occurs.
**Called by:** No callers documented (called from race steward completion path).
**Purpose:** Writes `raceresults.txt` with full session data: header, race settings, per-driver results.

**Key actions:**
1. Builds results path: `Results\` + timestamp filename (via FUN_00566650, FUN_005665b0)
2. Reads session time via FUN_00589e6c (returns packed date/time struct)
3. Branch on DAT_007d0b28 (MultiplayerFlag) and DAT_007c56a4 (SessionType):
   - If multiplayer: writes race timestamp
   - If singleplayer race (SessionType == 7) or multiplayer: writes full report
4. Writes `[Header]` section: Game = "F1 Challenge 99-02", Version = 1.0, TimeString
5. Writes `[Race]` section: RaceMode, Scene, AIDB, Qualify Laps, Race Laps, etc.
6. Writes `[Local Settings]` (multiplayer only): drive aids, mech fail rate, damage mult, fuel/tire mult
7. Writes `[Results]` section per driver (sorted by finish position):
   - Reads +0x4620 (DriverName), +0x4678 (VehicleDescription)
   - Reads +0x4058 (QualifyingPosition), +0x405c (QualifyingTime)
   - Reads +0x4060 (FinishPosition), +0x4064 (FinishState)
   - Iterates lap times from +0x403c via FUN_004bc2a0/FUN_004bc270
   - Reads +0x409c (BestLapTime), +0x4068 (ReasonCode), +0x40d8 (GapToLeader)

**Data passed to callees:** File handle, formatted string buffers, vehicle struct pointers.

### Level 1: Key Sub-functions

**0x00566c30 — Buffer Write with String Length Check**
Writes INI-style header/section blocks. Formats key=value pairs with string length validation.

**0x004bc2a0 / 0x004bc270 — Lap Time Read**
Reads lap time array from vehicle struct (+0x403c). Returns per-lap time values for results output.

**0x00567700 — Format Time**
Converts float seconds to formatted time string (MM:SS.mmm). Used for lap times, race times.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_004d24d0 | session globals | branch on type, mode | write path selected |
| FUN_00566650 | timestamp ints | format to string | timestamp filename |
| FUN_005896ee | filename | open file | file handle |
| FUN_00566c30 | file handle, sections | write formatted | file contents |
| FUN_004bc270 | vehicle ptr +0x403c | read lap array | lap time values |
| FUN_00567700 | float time | format | "1:23.456" string |

## Globals Written in This Chain

| Global | Name | Written by | Value meaning |
|--------|------|-----------|---------------|
| DAT_007d0b28 | MultiplayerFlag | read | 0 = singleplayer |
| DAT_007c56a4 | SessionType | read | 7 = race |
| DAT_007d0410 | RaceMode | read | race mode enum |
| DAT_007cea5c | EngineWearMode | read | mech fail rate |

## Notes

File format is INI-style key=value. The chain is purely output — no game state is mutated. All struct offsets read are for vehicle data (DriverName, FinishPosition, etc.). Two format time helpers exist (0x00567700, 0x005676c0) for different time display formats.

---
