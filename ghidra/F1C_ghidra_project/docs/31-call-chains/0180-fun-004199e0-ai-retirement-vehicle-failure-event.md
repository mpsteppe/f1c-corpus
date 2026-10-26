# Chain 179: FUN_004199e0 — AI Retirement/Vehicle Failure Event

Seed: FUN_004199e0  |  System: docs/02-ai-system.md  |  Depth: 2  |  Functions: 4

---

## Overview

Handles AI driver retirement event with audio commentary. Guard checks, plays retirement audio (ID 0x29) with driver position context. Checks retirement linked list at +0x40d0/+0x40d4. If laps remaining == 1: plays audio 0x111 (final lap retirement). If laps remaining 2..0x32: plays audio 0x110. Uses shared commentary infrastructure.

## Call Tree

```
FUN_004199e0 — AI Retirement/Vehicle Failure Event  [called by: AI retirement trigger]
  +-- FUN_004144d0 — [undocumented] commentary text init  [leaf]
  +-- FUN_004144f0 — [undocumented] commentary text dispatch  [leaf]
  +-- FUN_00418560 — [undocumented] text output (3 callees)
  |     +-- FUN_00418b90 — [undocumented]
  |     +-- FUN_00418b70 — [undocumented]
  |     +-- FUN_004145c0 — [undocumented]
  +-- FUN_0049b6d0 — [undocumented] race time query
        +-- FUN_004f01b0 — get current race time
```

## Step-by-Step Trace

### Level 0: FUN_004199e0 — AI Retirement/Vehicle Failure Event

**Trigger:** AI vehicle retirement/failure
**Called by:** (no callers in callers.json — likely callback or indirect dispatch)
**Purpose:** Plays retirement audio commentary based on context

**Key actions:**
1. Guard checks
2. Plays audio ID 0x29 with driver position
3. Checks retirement linked list at +0x40d0/+0x40d4
4. If laps remaining == 1: audio 0x111 (final lap)
5. If laps remaining 2..0x32: audio 0x110

**Data passed:** Vehicle struct pointer (param_1) — reads at +0x40d0/+0x40d4 for retirement links

### Level 1: FUN_00418560 — Text Output

**Purpose:** Outputs commentary text through shared infrastructure
**Called by:** All commentary event functions

**Key actions:**
1. Calls FUN_00418b90 (text processing)
2. Calls FUN_00418b70 (text processing)
3. Calls FUN_004145c0 (text processing)

### Level 1: FUN_0049b6d0 — Race Time Query

**Purpose:** Gets current race time for context

**Key actions:**
1. Calls FUN_004f01b0 to retrieve current race time

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| Guard | vehicle state | check validity | pass/fail |
| Audio 0x29 | driver position | play commentary | retirement announced |
| Lap check | total laps - current | compare remaining | choose 0x111 or 0x110 |
| Race time | time query | FUN_0049b6d0 → FUN_004f01b0 | current race time |

## Notes

- FUN_004144d0 and FUN_004144f0 are heavily reused commentary primitives (30+ callers each)
- FUN_00418560 is the most-called commentary text output function (30+ callers)
- All 4 callees are from decompiled_full — not indexed in functions.json
- Retirement linked list offsets at +0x40d0/+0x40d4 documented in docs/13

---
