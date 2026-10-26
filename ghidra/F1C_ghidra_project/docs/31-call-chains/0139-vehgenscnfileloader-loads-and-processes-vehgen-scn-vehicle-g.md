# Chain: VehgenScnFileLoader — Loads and processes vehgen.scn vehicle generation scene

Seed: FUN_004c6c40  |  System: docs/08-file-formats.md  |  Depth: 3  |  Functions: 9

---

## Overview

Loads and processes the `vehgen.scn` file — vehicle generation scene configuration for the current track. Allocates 0x80-byte buffer, constructs path from scene directory (DAT_005ec438) + "vehgen.scn", writes vehicle-specific scene data via FUN_004ddf90, parses generated data via FUN_004a4900/FUN_004dfce0, sets vehicle placement (FUN_004f8370) and grid position (FUN_004bb800). On first load (flag at +13000 == 0), reads driver nationality (FUN_004c6980) and stores at +0x4660. Called per-vehicle during track/scene initialization.

## Call Tree

```
FUN_004c6c40 — VehgenScnFileLoader  [trigger: per-vehicle during track/scene init]
  +-- FUN_004ddf90 — SceneFileTEAMDIRWriter  [writes TEAMDIR/VEHDIR/NOTSPIN, 9 callees]
  |     +-- [subtree: 9 callees — docs/08, file writing utilities]
  +-- FUN_004a4900 — SceneProcessing  [undocumented — NOT FOUND in functions.json]
  +-- FUN_004dfce0 — VehicleGraphicsSceneLoader  [loads vehicle graphics scene]  [leaf]
  +-- FUN_004f8370 — VehiclePositioningPhysicsInit  [physics init for placement, 3 callees]
  |     +-- [subtree: 3 callees — docs/18]
  +-- FUN_004bb800 — ZeroTwoFields  [zero two fields in grid setup]  [leaf]
  +-- FUN_004c6980 — SetDriverName  [reads nationality data, 1 callee]  [docs/08]
  |     +-- FUN_00587b8a — [undocumented]
  +-- FUN_004c7b50 — VehicleSetupDriverNumber  [sets driver number, 2 callees]
  |     +-- [subtree: 2 callees — docs/08]
  +-- FUN_00410b20 — ShortComputationCallWrapper  [init wrapper, 1 callee]
  |     +-- FUN_005895a2 — [undocumented]
  +-- FUN_00587bcf — FreeWrapper  [frees allocated 0x80-byte buffer]  [leaf]
```

## Step-by-Step Trace

### Level 0: FUN_004c6c40 — VehgenScnFileLoader

**Trigger:** Per-vehicle during track/scene initialization — iterated by VehicleCount (DAT_005c329c)
**Called by:** FUN_0042c1a0, FUN_004b8da0, FUN_0045fc50 (scene gen) — 3 callers
**Purpose:** Loads and processes vehicle generation scene file for track-specific vehicle appearance.

**Key actions:**
1. Allocates 0x80-byte buffer, zeros it
2. Registers scene directory path (DAT_005ec438)
3. Appends "vehgen.scn" to path via FUN_005665b0
4. Calls FUN_004ddf90(param_2) — writes vehicle-specific TEAMDIR/VEHDIR scene data
5. Calls FUN_004a4900 + FUN_004dfce0 — parses generated scene data into vehicle graphics
6. Calls FUN_004f8370 — initializes vehicle physics placement (position, orientation)
7. Calls FUN_004bb800 — zeroes two grid setup fields
8. Resets flags at param_1+0x48a4 and +0x48a8 to -1 (loaded markers)
9. **First load (param_1+13000 == 0):**
   - Reads driver nationality via FUN_004c6980
   - Copies nationality string to param_1+0x4660 (max 0x17 chars)
10. Calls FUN_004c7b50 (driver number setup), FUN_00410b20 (init wrapper)
11. Frees buffer via FUN_00587bcf

**Data passed to callees:** vehicle struct pointer (param_1, stride ~0x4900), scene file path buffer, nationality string buffer

### Level 1: Key callees

**FUN_004ddf90 — SceneFileTEAMDIRWriter (9 callees)**
Writes vehicle-specific scene configuration (team directory, vehicle directory, NOTSPIN flag) into a `.gen` file. The 9 callees handle file I/O and string formatting for the scene generation pipeline.

**FUN_004a4900 — SceneProcessing [undocumented]**
NOT FOUND in functions.json — likely a large Ghidra decompiled function not yet catalogued. Processes the generated scene data into vehicle appearance.

**FUN_004f8370 — VehiclePositioningPhysicsInit (3 callees)**
Initializes vehicle physics body for the track — sets position, orientation, collision shape based on grid slot.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| Buffer alloc | 0x80 | operator_new | workspace buffer |
| Path build | DAT_005ec438 + "vehgen.scn" | string concat | full path |
| Scene write | vehicle index | TEAMDIR write | .gen file |
| Scene parse | .gen file | FUN_004a4900+DFCE0 | graphics data |
| Physics init | vehicle struct | position/orient | physics body |
| Grid setup | grid data | zero fields | grid slot |
| Nationality | DAT_007ce684 | read + copy | +0x4660 string |
| Cleanup | buffer | free | dealloc |

## Struct Offsets Touched

| Offset | Field | Written by |
|--------|-------|-----------|
| +0x4660 | Nationality (max 0x17 chars) | FUN_004c6c40 |
| +0x4677 | Null terminator | FUN_004c6c40 |
| +0x4894 | Vehicle index | FUN_004c6c40 |
| +0x48a4 | Loaded flag (-1) | FUN_004c6c40 |
| +0x48a8 | Loaded flag 2 (-1) | FUN_004c6c40 |
| +13000 | First-load flag (0→set) | FUN_004c6c40 |

## Notes

- Called 3 times (3 callers): global init (FUN_0042c1a0), loading phase (FUN_004b8da0), and scene/reload (FUN_0045fc50)
- The "vehgen.scn" loading pattern: writes a temp file, reads it back immediately — serves as data interchange between the scene generator and graphics parser
- Nationality only read on first load — subsequent loads skip to avoid redundant I/O
- FUN_004a4900 is undocumented (missing from functions.json) — likely a decompiled full function

---
