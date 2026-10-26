# Chain 47: AI Corner Speed Comparison — Compare AI vs player corner speed, trigger audio

Seed: FUN_00419500  |  System: docs/02-ai-system.md  |  Depth: 3  |  Functions: 5 callees

---

## Overview

Triggered during AI pace evaluation. Compares AI driver speed vs player speed at corner sections, triggers audio commentary (corner entry/exit sounds). Gated by SessionType 5 check and same-team requirement. Early-exits on session guards.

## Call Tree

```
FUN_00419500 — AI Corner Speed Comparison  [trigger: AI pace evaluation]
  +-- FUN_004144d0 — Struct Init with Sentinel Values  [init struct]
  +-- FUN_004d1b50 — Driver ID Lookup  [lookup driver — docs/06]
  +-- FUN_004144f0 — Driver Data Table Lookup and Time Conversion  [table lookup — docs/02]
  +-- FUN_00418560 — InsertDriverTableEntry  [insert speed entry]
  |     +-- FUN_00418b90 — Score/Threshold Gate Check
  |     +-- FUN_00418b70 — Table Lookup with Sentinel
  |     +-- FUN_004145c0 — Struct Copy (32 bytes)
  +-- FUN_0041a170 — AI Vehicle Damage Event  [damage event — docs/02]
        +-- FUN_004c7bd0 — IsDriverPlayer  [docs/06]
        +-- FUN_004144d0 — Struct Init  [docs/20]
        +-- FUN_004144f0 — Driver Table Lookup  [docs/02]
        +-- FUN_00418560 — Insert Driver Entry  [docs/02]
```

## Step-by-Step Trace

### Level 0: FUN_00419500 — AI Corner Speed Comparison

**Trigger:** AI pace evaluation during race session.
**Called by:** Orphan (no callers recorded).
**Purpose:** Compares AI speed vs player at corner sections, triggers audio commentary.

**Key actions:**
1. Early exits on session guards
2. Only proceeds if SessionType 5 and same team
3. Reads AI speed from DAT_005f0780 + stride 0x1230
4. Compares vs player speed at param_1+0x404c
5. If AI slower: audio 0x0d/0x0e (corner entry/exit). If faster: 0x13/0x14
6. If param_2==2 and pitState==1: calls FUN_0041a170

**Globals:** DAT_005f0780 (AI speed table, stride 0x1230)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x404c | PlayerSpeed | Player speed reference |

### Level 1: Key callees

**FUN_00418560 — InsertDriverTableEntry** — Inserts speed comparison entry into driver data table. 3 callees: score gate check, table lookup with sentinel, struct copy.

**FUN_0041a170 — AI Vehicle Damage Event** — Handles vehicle damage event triggered by pit state condition. 4 callees: IsDriverPlayer, struct init, driver table lookup, insert driver entry.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_00419500 | AI speed, player speed | Compare speeds | Audio trigger |
| FUN_00418560 | Speed data | Insert into table | Updated driver table |
| FUN_0041a170 | Damage event | Process damage | Damage state update |
| FUN_004144f0 | Driver ID | Lookup default time | Driver time value |

## Globals Written in This Chain

None directly — reads DAT_005f0780.

## Notes

- Only evaluates when SessionType == 5 (quali/practice context)
- Audio IDs: 0x0d/0x0e (AI slower = corner entry/exit), 0x13/0x14 (AI faster)
- `hardcoded`

---
