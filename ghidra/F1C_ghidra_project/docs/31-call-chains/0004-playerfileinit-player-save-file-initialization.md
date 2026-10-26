# Chain: PlayerFileInit — Player Save File Initialization

Seed: FUN_004b0540  |  System: docs/08-file-formats.md  |  Depth: 3  |  Functions: 15

---

## Overview

Called during player file loading sequence. Reads .PLR file attributes, copies name strings, clamps AI difficulty and vehicle count (1-104). Calls init functions for related subsystems: FUN_004b0720 (player stats), FUN_004b0ef0 (player settings), FUN_00432e70 (car select), FUN_0042bc80 (config). Final effect: player data is validated, clamped, and subsystem init is triggered.

## Call Tree

```
FUN_004b0540 — PlayerFileInit  [trigger: player file loaded — .PLR parse complete]
  +-- FUN_005668b0 — [undocumented file I/O wrapper — likely MSS lock]
  +-- FUN_00568620 — [undocumented file I/O wrapper]
  +-- FUN_00566b20 — [undocumented MSS file open]
  +-- FUN_004ae750 — [undocumented player data util]
  +-- FUN_004a1d10 — [undocumented session state]
  +-- FUN_004c5690 — [undocumented file config]
  +-- FUN_0042bc10 — [undocumented config init]
  +-- FUN_0042bc80 — Config Init  [parse config values]
  +-- FUN_004b0720 — Player Stats Init  [initialize player statistics]
  |     [may have further sub-calls]
  +-- FUN_004b0ef0 — Player Settings Init  [initialize player settings from file]
  |     [may have further sub-calls]
  +-- FUN_00432e70 — Car Select Init  [initialize car selection data]
  |     [may have further sub-calls]
  +-- FUN_00415730 — [undocumented cleanup/string util]
```

## Step-by-Step Trace

### Level 0: FUN_004b0540 — PlayerFileInit

**Trigger:** Called after .PLR file content is loaded into memory.
**Called by:** One caller (from callers.json).
**Purpose:** Validates and processes player save data; clamps values, triggers subsystem init.

**Key actions:**
1. Checks file attributes, sets exists flag
2. Reads string from file, copies to buffer
3. Clamps AI level, boolean flag at +0x1f00
4. Computes vehicle count from +0x24f8, clamps 1-104
5. Calls init functions: FUN_0042bc80, FUN_004b0720, FUN_004b0ef0, FUN_00432e70

**Struct offsets:** +0x14 (FilePath), +0x114 (FileExistsFlag), +0x1f78 (GameMode), +0x24f8 (VehicleCountTable), +0x2f8c (AIDifficulty)

**Data passed to callees:** param_1 player data struct pointer

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_004b0540 | .PLR file data | Read attributes | FileExistsFlag set |
| FUN_004b0540 | player name string | String copy | Buffer copied |
| FUN_004b0540 | AI level value | Clamp to range | AIDifficulty clamped |
| FUN_004b0540 | vehicle count | Clamp 1-104 | VehicleCountTable fixed |
| FUN_0042bc80 | config struct | Parse config | Config values populated |
| FUN_004b0720 | player stats data | Init stats | Statistics initialized |

## Globals Written in This Chain

None identified — operates on param_1 player struct and calls subsystem inits.

## Notes

- Vehicle count clamping (1-104) prevents crashes from corrupted save files
- AI difficulty clamping prevents out-of-range driver ability values
- The four subsystem inits (FUN_0042bc80/4b0720/4b0ef0/00432e70) are the call depth

---

---
