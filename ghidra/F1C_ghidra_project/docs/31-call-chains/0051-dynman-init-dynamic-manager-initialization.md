# Chain: DynMan::Init — Dynamic Manager Initialization

Seed: 0x0042c1a0  |  System: docs/01-engine-architecture.md  |  Depth: 5  |  Functions: 15+

---

## Overview

Initializes the dynamic management system during game setup. Triggered by Game::Setup() (0x0042d6b0). Iterates vehicle grid array, branches on session type (championship vs practice vs race), loads AI driver config, sets up per-vehicle UI, and resolves player settings. Outputs: initialized vehicle grid, AI driver slots populated, per-vehicle scene files loaded, player name and settings resolved.

## Call Tree

```
0x0042c1a0 — DynMan::Init  [trigger: Game::Setup() calls this via 0x0042d6b0]
  +-- 0x004d7a50 — Trace Gate  [logging gate check]
  |     +-- 0x00587c20 — [leaf]
  |     +-- 0x004d7aa0 — Trace Log  [leaf]
  +-- 0x004d7aa0 — Trace Log  [leaf]
  +-- 0x0040fe50 — [undocumented]
  +-- 0x0042bbd0 — Error Handler  [no vehicles found]
  +-- 0x0042bc40 — Error Handler  [no vehicles found]
  +-- 0x004b1520 — Config Loader  [loads setup config]
  +-- 0x004bfd90 — AI Driver Count Setup  [10 sub-calls, sets up AI opponents]
  |     +-- 0x004bf630 — Zero-Init 4 Ints  [leaf]
  |     +-- 0x0042bc10 — ScoringGateCheck  [docs/06]
  |     |     +-- 0x00461cd0 — Session State Check  [leaf]
  |     +-- 0x004b3c60 — Deterministic Hash/Pseudo-Random  [docs/20]
  |     |     +-- 0x0055687b — RDTSC Timestamp Read  [leaf]
  |     +-- 0x0042bc80 — Build Active Vehicle Pointer Array  [leaf]
  |     +-- 0x004bf790 — AI Opponent Selection / NotAI Slot Filler  [7 sub-calls]
  |     |     +-- 0x004bfa00 — AI Path/Performance Function  [leaf]
  |     |     +-- 0x004bf6a0 — [leaf]
  |     |     +-- 0x004c5070 — Random Vehicle Selector  [docs/20]
  |     |     |     +-- 0x005871f0 — Read Field at +0x14  [leaf]
  |     |     |     +-- 0x004c6760 — Bounds-Checked Index Setter  [leaf]
  |     |     +-- 0x004c50e0 — Guarded List Accessor  [docs/20]
  |     |     |     +-- 0x005871f0 — Read Field at +0x14  [leaf]
  |     |     |     +-- 0x004c6760 — Bounds-Checked Index Setter  [leaf]
  |     |     +-- 0x00588410 — [leaf]
  |     |     +-- 0x004c2e20 — MergeSortLinkedListByFloat  [docs/20, recursive]
  |     |     |     +-- 0x004c2e20 — self  [recursive]
  |     |     +-- 0x0058815f — String Format w/ Overflow Check  [leaf]
  |     +-- 0x004ef5a0 — SessionStateTransition  [docs/18, 6 sub-calls]
  |     |     +-- 0x004efb20 — 3D Transform w/ Matrix Mult  [leaf]
  |     |     +-- 0x004ef7c0 — AI Path Position Tracking  [docs/18]
  |     |     +-- 0x00447780 — Suspension Force Computation  [docs/18]
  |     |     +-- 0x004e9630 — PositionChangeMonitor  [docs/18]
  |     |     +-- 0x0042adb0 — Session Cleanup Flag Clear  [leaf]
  |     |     +-- 0x0042aca0 — AISpeedDeltaSetter  [docs/18]
  |     +-- 0x004bfd40 — Indexed List Lookup  [leaf]
  |     +-- 0x004c78f0 — Nationality/Driver Info Loader  [leaf]
  |     +-- 0x004c6960 — TeamIDSetter  [docs/20]
  |     |     +-- 0x00424060 — Multi-Field Setter  [leaf]
  |     +-- 0x004c3f80 — Vehicle Lookup by Name  [docs/20]
  |           +-- 0x00588410 — [leaf]
  +-- 0x004bff70 — Race Init Path  [race session branch]
  +-- 0x004c01a0 — Practice Init Path  [practice session branch]
  +-- 0x0042bc80 — Build Active Vehicle Pointer Array  [leaf]
  +-- 0x005895a2 — Sqrt Lookup  [math leaf]
  +-- 0x004f9480 — [undocumented]
  +-- 0x004c6c40 — vehgen.scn File Loader  [per-vehicle scene file, 9 sub-calls]
  |     +-- 0x004ddf90 — Scene File TEAMDIR/VEHDIR Writer  [docs/08, 9 sub-calls]
  |     |     +-- 0x00534b00 — Single Call Wrapper  [leaf]
  |     |     +-- 0x00587db0 — Delegation w/ Fixed Arg  [leaf]
  |     |     +-- 0x00587c20 — [leaf]
  |     |     +-- 0x005887b1 — String Format w/ Nested I/O  [docs/08]
  |     |     +-- 0x00588410 — [leaf]
  |     |     +-- 0x0058815f — String Format w/ Overflow Check  [leaf]
  |     |     +-- 0x00589898 — Buffered Char Write  [docs/08]
  |     |     +-- 0x005355a0 — Stream/File Type Check  [leaf]
  |     |     +-- 0x004d7a50 — String Split Loop  [docs/01]
  |     +-- 0x004a4900 — Scene Processing  [leaf]
  |     +-- 0x004dfce0 — Vehicle Graphics Scene Loader  [docs/19, leaf]
  |     +-- 0x004f8370 — Physics Init / Vehicle Positioning  [docs/20]
  |     |     +-- 0x004f83b0 — DoubleBufferFree  [docs/20]
  |     |     +-- 0x004f70c0 — [leaf]
  |     |     +-- 0x004f6d60 — Array Non-Zero Counter  [leaf]
  |     +-- 0x004bb800 — Grid Setup  [leaf]
  |     +-- 0x004c6980 — SetDriverName  [docs/02]
  |     |     +-- 0x004c6a10 — Driver Abbreviation Formatter  [docs/02]
  |     +-- 0x004c7b50 — Vehicle Setup Driver Number  [docs/02]
  |     |     +-- 0x00415230 — Named Entry Lookup  [docs/08]
  |     |     +-- 0x00415550 — Linked List Index Scanner  [docs/08]
  |     +-- 0x00410b20 — Short Computation / Call Wrapper  [docs/20]
  |     |     +-- 0x00410ad0 — Indexed Array Slot Insert  [leaf]
  |     +-- 0x00587bcf — Free Wrapper  [heap free]
  +-- 0x004326e0 — Player Name Setup  [8 sub-calls]
  |     +-- 0x00432180 — Settings Setup File Read  [docs/08]
  |     |     +-- 0x004b0220 — Path Truncation  [docs/08]
  |     |     +-- 0x00566650 — String Copy w/ Realloc  [leaf]
  |     |     +-- 0x00431db0 — Directory File Enumerator  [docs/08]
  |     +-- 0x00432220 — SettingsCopy: Setup File Copy  [leaf]
  |     +-- 0x004326d0 — Wrapper  [leaf]
  |     +-- 0x004326a0 — SettingsFolder Resolver  [leaf]
  |     +-- 0x00423a00 — Binary Search in String Table  [docs/08]
  |     |     +-- 0x00588410 — [leaf]
  |     +-- 0x00588410 — [leaf]
  |     +-- 0x00566650 — String Copy w/ Realloc  [leaf]
  |     +-- 0x00432980 — Path Normalizer + File Enumeration  [docs/08]
  |           +-- 0x00568620 — [leaf]
  |           +-- 0x005665b0 — path append  [leaf]
  |           +-- 0x00431db0 — Directory File Enumerator  [docs/08]
  +-- 0x004336f0 — Load AI Driver Names from Config  [docs/02, 2 sub-calls]
        +-- 0x00433890 — AI Settings File Resolver  [leaf]
        +-- 0x004339e0 — Look Up Vehicle Config Entry  [docs/08]
              +-- 0x00432e70 — AutoLoadEntry List Loader  [leaf]
              +-- 0x00432e50 — IterationCountMap  [leaf]
```

## Step-by-Step Trace

### Level 0: 0x0042c1a0 — DynMan::Init

**Trigger:** Game::Setup() calls DynMan::Init during game initialization sequence.
**Called by:** 0x0042d6b0 (Game::Setup post-init).
**Purpose:** Initializes dynamic management system: vehicle grid, AI setup, per-vehicle UI.

**Key actions:**
1. Reads DAT_007d0410 (RaceMode) — branches championship vs non-championship path
2. Iterates DAT_005ef9a0 (VehicleGridArray, stride 0x1230, up to 104 entries)
3. Checks DAT_007c5690 (InitStateFlag) — 0 = load config, non-0 = session path
4. If InitStateFlag == 0: calls FUN_004b1520 (config load), then branch to race init (FUN_004bfd90, FUN_004bff70) or practice path
5. If InitStateFlag != 0 and RaceMode == 4 (championship) and SessionType 1-4: calls FUN_004c01a0 (practice init)
6. After init: iterates VehicleCount (DAT_005c329c), calls FUN_004c6c40 per vehicle (vehgen.scn loader)
7. If CurrentVehicleIndex (DAT_007c54e4) valid: calls FUN_004336f0 (AI driver names)

**Data passed to callees:** VehicleGridArray pointer, per-vehicle struct pointers, SessionType, RaceMode.

### Level 1: Key Sub-functions

**0x004bfd90 — AI Driver Count Setup**
10 sub-calls. Sets up AI opponent slots: checks scoring gate, generates pseudo-random seeding, selects AI opponents, performs session state transition, looks up vehicles by name, sets team IDs.

**0x004c6c40 — vehgen.scn File Loader**
9 sub-calls. Loads per-vehicle scene files: writes scene file paths (TEAMDIR/VEHDIR), loads vehicle graphics scene, positions vehicle on grid, sets driver name/number, cleans up temporary allocations.

**0x004326e0 — Player Name Setup**
8 sub-calls. Reads player settings file, copies setup files, resolves settings folder path, performs binary search in string tables, normalizes paths.

**0x004336f0 — Load AI Driver Names from Config**
2 sub-calls. Resolves AI settings file, looks up vehicle config entries for each AI driver.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_0042c1a0 | session globals | branch on RaceMode, InitStateFlag | init path selected |
| FUN_004bfd90 | VehicleGridArray | setup AI driver count, seed | AI slots populated |
| FUN_004c6c40 | vehicle ptr, index | load vehgen.scn | vehicle scene initialized |
| FUN_004326e0 | settings path | read player name, config | player settings resolved |
| FUN_004336f0 | AI config files | load names from config | AI driver names set |

## Globals Written in This Chain

| Global | Name | Written by | Value meaning |
|--------|------|-----------|---------------|
| DAT_007d0410 | RaceMode | read by DynMan::Init | 4 = championship |
| DAT_007c56a4 | SessionType | read by DynMan::Init | 1-4 = practice |
| DAT_007c5690 | InitStateFlag | read by DynMan::Init | 0/1 init state |
| DAT_005c329c | VehicleCount | read | number of vehicles |
| DAT_007c54e4 | CurrentVehicleIndex | read | player's index |
| DAT_005ef9a0 | VehicleGridArray | read/write | grid entries, stride 0x1230 |

## Notes

This is the deepest chain — reaches level 5. DynMan::Init is a major initialization hub called once during game boot. The AI driver setup (0x004bfd90) is the most complex subtree with 10 immediate callees and nested recursion in MergeSort. The vehgen.scn loader (0x004c6c40) bridges to the file-format system (docs/08). Player name setup (0x004326e0) bridges to the settings file system.

---
