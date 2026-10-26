# Chain 199: Player Name Setup — Driver Name Initialization

Seed: FUN_004326e0  |  System: docs/10-vehicle-physics.md  |  Depth: 3  |  Functions: 8 callees

---

## Overview

FUN_004326e0 initializes player name from message buffer (DAT_005ec4cc). It calls FUN_00432180 (Settings Setup File Read) for settings loading, FUN_00432220 (SettingsCopy Setup File Copy) for file copy, FUN_004326d0 (Wrapper, docs/18), FUN_004326a0 (SettingsFolder Resolver, docs/08) for folder resolution, FUN_00423a00 (Binary Search in String Table, docs/08) for name search, FUN_00588410 (string compare, docs/06) for comparison, FUN_00566650 (String Copy with Buffer Realloc, docs/20) for string handling, and FUN_00432980 (Path Normalizer + File Enumeration, docs/08) for path normalization. Triggered by FUN_0042c1a0 (DynMan::Init) during game initialization.

## Call Tree

```
FUN_004326e0 — Player Name Setup  [trigger: DynMan::Init via 0x0042c1a0]
  +-- FUN_00432180 — Settings Setup File Read  [docs/10 — vehicle setup]
  |     +-- FUN_00431db0 — Directory File Enumerator  [docs/08]
  |     +-- FUN_004326a0 — SettingsFolder Resolver  [docs/08 — leaf]
  |     +-- FUN_00566650 — String Copy with Buffer Realloc  [leaf, docs/20]
  +-- FUN_00432220 — SettingsCopy Setup File Copy  [leaf, docs/10]
  +-- FUN_004326d0 — Wrapper (docs/18 physics-dynamics)  [leaf]
  +-- FUN_004326a0 — SettingsFolder Resolver  [leaf, docs/08]
  +-- FUN_00423a00 — Binary Search in String Table  [docs/08]
  |     +-- FUN_00588410 — String Compare  [leaf, docs/06]
  +-- FUN_00588410 — String Compare  [leaf, docs/06]
  +-- FUN_00566650 — String Copy with Buffer Realloc  [leaf, docs/20]
  +-- FUN_00432980 — Path Normalizer + File Enumeration  [docs/08]
        +-- FUN_00431db0 — Directory File Enumerator  [docs/08]
        +-- FUN_004326a0 — SettingsFolder Resolver  [leaf, docs/08]
        +-- FUN_00566650 — String Copy with Buffer Realloc  [leaf, docs/20]
```

## Step-by-Step Trace

### Level 0: FUN_004326e0 — Player Name Setup

**Trigger:** Called by FUN_0042c1a0 (DynMan::Init) during game initialization sequence.
**Called by:** FUN_0042c1a0 (DynMan::Init)
**Purpose:** Initializes player name from message buffer DAT_005ec4cc.

**Key actions:**
1. Calls init functions: FUN_00432180 (settings read), FUN_00432220 (settings copy)
2. Gets name from DAT_005ec4cc via FUN_004326a0
3. Searches player name table via FUN_00423a00 (binary search)
4. Iterates linked list to find matching index
5. Calls FUN_00432980 with player name for path normalization

**Globals read:**
- DAT_005ec4cc (MessageBuffer) — player name source
- DAT_005ea438 — directory/file path

### Level 1: FUN_00432180 — Settings Setup File Read

**Trigger:** Called at start of player name init.
**Purpose:** Reads settings setup file for player configuration.

**Key actions:**
1. Enumerates directory via FUN_00431db0
2. Resolves settings folder via FUN_004326a0
3. Copies strings via FUN_00566650

### Level 1: FUN_00423a00 — Binary Search in String Table

**Trigger:** Called to search player name in existing table.
**Purpose:** Binary searches a string table for matching player name.

**Key actions:**
1. Compares input name against table entries via FUN_00588410
2. Returns index of matching entry or not-found

### Level 1: FUN_00432980 — Path Normalizer + File Enumeration

**Trigger:** Called after name is matched, to enumerate normalized path.
**Purpose:** Normalizes file path and enumerates matching files.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_004326e0 | DAT_005ec4cc | Read message buffer | Player name string |
| FUN_00432180 | Settings path | Read setup file | Settings data |
| FUN_00423a00 | Player name + table | Binary search | Name table index |
| FUN_00432980 | Matched name | Path normalization | Normalized path |

## Notes

- 8 callees, heavily string/file focused (docs/08, docs/10, docs/20)
- FUN_00566650 (String Copy with Buffer Realloc) called 3x in this chain — key utility
- FUN_004326a0 (SettingsFolder Resolver) called both from seed and as nested callee
- Cross-system: FUN_004326d0 from docs/18 (physics-dynamics) — undocumented wrapper

---
