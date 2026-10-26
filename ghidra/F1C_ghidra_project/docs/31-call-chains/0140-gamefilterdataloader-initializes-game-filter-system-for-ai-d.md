# Chain: GameFilterDataLoader — Initializes game filter system for AI difficulty/filtering

Seed: FUN_004c0db0  |  System: docs/08-file-formats.md  |  Depth: 3  |  Functions: 8

---

## Overview

Initializes the game filter system — reads binary configuration data and sets up per-driver filter state. Sets session filter type to 2, clears filter stack (104 calls to FUN_004c07f0), reads binary data via FUN_004b0b20, registers game filter data paths from DAT_007ce64c/DAT_007d0dcc, registers "Game Filter" INI section, then iterates all vehicles to set per-driver filter indices, flags, and active state. Controls AI difficulty filtering/selection.

## Call Tree

```
FUN_004c0db0 — GameFilterDataLoader  [trigger: session setup / game init]
  +-- FUN_004c07f0 — LapSessionDataArrayInit  [zeros 0x68-iterated filter stack]  [leaf]
  +-- FUN_004b0b20 — FilenameExtractionFromPath  [binary read, 3 callees]
  |     +-- FUN_00463c40 — [undocumented]
  |     +-- FUN_004b0b10 — [undocumented]
  |     +-- FUN_00566810 — validity check
  +-- FUN_00566650 — StringCopyWithBufferRealloc  [path registry/copy]  [leaf]
  +-- FUN_005681f0 — ConditionalDispatch  [section register]  [leaf]
  +-- FUN_004bfcd0 — PerDriverFilterRead  [per-driver filter data read]  [leaf]
  +-- FUN_004bf630 — ZeroInit4Ints  [zero-init filter init]  [leaf]
  +-- FUN_004bf640 — Linked List Destruction  [filter cleanup]  [leaf]
  +-- FUN_004bf790 — AIOpponentSelectionNotAISlotFiller  [filter setup, 7 callees]
        +-- [subtree: 7 callees — docs/02]
```

## Step-by-Step Trace

### Level 0: FUN_004c0db0 — GameFilterDataLoader

**Trigger:** Session setup — called during game/filter data initialization
**Called by:** FUN_004c2780 (from callers.json)
**Purpose:** Initialize game filter system with per-driver filter data for AI difficulty.

**Key actions:**
1. Sets session filter type to 2 at param_1 + 0xb144, current race to 0 at +0xb148
2. Calls FUN_004c07f0 104 times (0x68) — clears filter stack
3. Reads 0x1f bytes via FUN_004b0b20 into path buffer
4. Registers path via FUN_00566650
5. Registers "Game Filter" section via FUN_005681f0(s_Game_Filter_005c7130)
6. Registers filter data paths from DAT_007ce64c (primary) and DAT_007d0dcc (alternate)
7. Iterates all vehicles (DAT_007d0a20 count, stride 0x1b4):
   - Calls FUN_004bfcd0(i) to read per-driver filter data
   - Sets per-vehicle filter fields: +0x194 (start), +0x198 (end), +0x19c (flags), +0x1a0 (active)
   - Calls FUN_004bf790 to set up filter state
   - Calls FUN_004bf630/FUN_004bf640 for filter init/cleanup

**Data passed to callees:** filter struct (param_1, large struct with 0xb110+ offsets), vehicle count, per-vehicle filter state

### Level 1: Key callees

**FUN_004c07f0 — LapSessionDataArrayInit [leaf]**
Zeros filter stack entries — called 104 times sequentially. Part of filter stack pre-clear.

**FUN_004bfcd0 — PerDriverFilterRead [leaf]**
Reads per-driver filter data from binary configuration. Returns filter index range.

**FUN_004bf790 — AIOpponentSelectionNotAISlotFiller (7 callees)**
Main filter setup logic: determines which AI opponents are active, fills "NotAI" slot markers, assigns difficulty ratings. Cross-system handoff to docs/02-ai-system.md.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| Stack clear | filter stack | 104× zero | cleared |
| Binary read | config file | read 0x1f bytes | path data |
| Path reg | DAT_007ce64c/DAT_007d0dcc | register | registered paths |
| Section reg | "Game Filter" | register | section active |
| Per-vehicle loop | DAT_007d0a20 count | iterate stride 0x1b4 | filter state set |
| Filter setup | per-driver data | FUN_004bf790 | AI difficulty applied |

## Struct Offsets Touched (param_1)

| Offset | Field |
|--------|-------|
| +0xb110 | filter base start |
| +0xb114 | filter base repeat |
| +0xb118 | filter count |
| +0xb11c | filter active flag |
| +0xb144 | session filter type (=2) |
| +0xb148 | current race |

## Per-Vehicle Filter State (stride 0x1b4)

| Offset | Field |
|--------|-------|
| +0x194 | filter index start |
| +0x198 | filter index end |
| +0x19c | filter flags |
| +0x1a0 | filter active flag |

## Notes

- FUN_004c07f0 called 104 times (0x68) — brute-force stack clear, no loop batching
- The "Game Filter" system controls AI difficulty filtering — which AI opponents appear based on player skill
- DAT_007d0dcc is the alternate filter path (fallback if DAT_007ce64c is null)
- Filter stride 0x1b4 suggests a medium-sized per-vehicle tracking struct (436 bytes per vehicle)

---
