# Chain: AI Session Phase Change — Session phase audio and driver table management

Seed: FUN_0041a2b0  |  System: docs/02-ai-system.md  |  Depth: 3  |  Functions: ~6

---

## Overview

AI Session Phase Change (FUN_0041a2b0) handles session phase transitions with audio cues and driver table management. It emits audio events based on session type/phase (session 5: audio 0x15/0x16 based on phase count; session 6/7: audio 0xb2, or 0xb3 if position==1), initializes structs with sentinel values, performs driver data table lookups, and inserts driver table entries with position change events. Called from FUN_004a5ea0 (Entering Pits Under Red Penalty).

## Call Tree

```
FUN_0041a2b0 — AI Session Phase Change  [trigger: session phase transition]
  +-- FUN_004144d0 — Struct Init with Sentinel Values  [struct init]
  +-- FUN_004144f0 — Driver Data Table Lookup and Time Conversion  [table lookup]
  +-- FUN_00418560 — InsertDriverTableEntry  [table insert]
  |     +-- FUN_00418b90 — Score/Threshold Gate Check  [score gate]
  |     +-- FUN_00418b70 — Short Computation (Table Lookup with Sentinel)
  |     +-- FUN_004145c0 — Struct Copy (32 bytes)
  +-- FUN_004198b0 — AI Position Change Event  [position event]
        +-- FUN_004144d0 — Struct Init with Sentinel Values  [recurse]
        +-- FUN_004144f0 — Driver Data Table Lookup  [recurse]
        +-- FUN_00418560 — InsertDriverTableEntry  [recurse]
```

## Step-by-Step Trace

### Level 0: FUN_0041a2b0 — AI Session Phase Change

**Trigger:** Session phase transition — called from FUN_004a5ea0 (Entering Pits Under Red Penalty)
**Called by:** FUN_004a5ea0 (Entering Pits Under Red Penalty)
**Purpose:** Handle session phase transitions with audio and driver table updates

**Key actions:**
1. Session 5 (practice?): audio 0x15/0x16 depending on phase count < 0xc or >=
2. Session 6/7 (quali/race): audio 0xb2, or 0xb3 if position == 1
3. If session 5: call FUN_004198b0 (AI Position Change Event)
4. All paths: call FUN_00418560 (InsertDriverTableEntry)

### Level 1: FUN_004144d0 — Struct Init with Sentinel Values

**Trigger:** Called from AI Phase Change
**Called by:** FUN_0041a2b0, FUN_004198b0
**Purpose:** Initialize a struct with sentinel/default values

### Level 1: FUN_004144f0 — Driver Data Table Lookup and Time Conversion

**Trigger:** Called from AI Phase Change
**Called by:** FUN_0041a2b0, FUN_004198b0
**Purpose:** Look up driver data in DriverDataTable (DAT_005bf9b0) and convert time values

### Level 1: FUN_00418560 — InsertDriverTableEntry

**Trigger:** Called from AI Phase Change
**Called by:** FUN_0041a2b0, FUN_004198b0
**Purpose:** Insert entry into driver data table

**Key actions:**
1. Score/threshold gate check via FUN_00418b90
2. Table lookup with sentinel via FUN_00418b70
3. 32-byte struct copy via FUN_004145c0

### Level 1: FUN_004198b0 — AI Position Change Event

**Trigger:** Called from AI Phase Change for session 5
**Called by:** FUN_0041a2b0
**Purpose:** Handle position change events in AI driver table

**Key actions:**
1. FUN_004144d0 — struct init (recurse)
2. FUN_004144f0 — driver table lookup (recurse)
3. FUN_00418560 — insert entry (recurse)

## Notes

- This chain has recursion-like structure: FUN_004198b0 calls the same 3 functions as its parent
- All leaf functions are in docs/02-ai-system.md or docs/20-math-utilities.md
- No file I/O — pure data structure manipulation with audio side effects
- FUN_004144f0 reads DriverDataTable (DAT_005bf9b0) for driver-specific timing data
- Audio events (0x15/0x16/0xb2/0xb3) are likely Miles Sound System sample IDs

---

# Summary

| Chain | Seed | System | Depth | Functions | Callees | Key Pattern |
|-------|------|--------|-------|-----------|---------|-------------|
| 204 | FUN_0042d6b0 | docs/01 | 6 | ~80 | 17 | Subsystem init cascade; VidMan::Init gates rest |
| 205 | FUN_00468ee0 | docs/08 | 4 | ~18 | 14 | Directory search + bitmap load for player profiles |
| 206 | FUN_004a00a0 | docs/06 | 4 | ~16 | 12 | Bink video playback with retry UI |
| 207 | FUN_0040b850 | docs/10 | 4 | ~14 | 11 | Scene file tokenizer → camera array alloc |
| 208 | FUN_004b4b50 | docs/17 | 4 | ~12 | 10 | Collision list sort + proxy processing |
| 209 | FUN_00490ee0 | docs/17 | 6 | ~20 | 9 | Broadphase with spatial hash reindex |
| 210 | FUN_0044be70 | docs/10 | 6 | ~20 | 8 | Binary terrain file I/O with crit sect locks |
| 211 | FUN_004c6a10 | docs/08 | 3 | ~10 | 7 | Driver name abbreviation (hash lookup + format) |
| 212 | FUN_0046d060 | docs/08 | 5 | ~16 | 6 | Season setup with vehicle file I/O |
| 213 | FUN_0050070d | docs/21 | 4 | ~12 | 6 | D3D-backed network texture surface sync |
| 214 | FUN_0041a2b0 | docs/02 | 3 | ~6 | 4 | AI driver table management with audio events |
