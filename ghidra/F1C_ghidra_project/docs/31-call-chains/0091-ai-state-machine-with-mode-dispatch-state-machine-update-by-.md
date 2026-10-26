# Chain: AI State Machine with Mode Dispatch — State Machine Update by Mode

Seed: FUN_004a5d10  |  System: docs/02-ai-system.md  |  Depth: 1-2  |  Functions: 9 callees

---

## Overview

Updates AI state machine based on mode at param_1[0x61] and input from param_2. Detects mode changes, dispatches to mode-specific handlers: mode 0 handles AI setup/init, modes 1-2 handle AI driving state. Connects to physics path data (FUN_004d1100).

## Call Tree

```
FUN_004a5d10 — AI State Machine with Mode Dispatch  [trigger: per-frame AI update]
  +-- FUN_0041a200 — Mode change handler                              [depth 1: HAS 0 callees]
  +-- FUN_004a5f20 — Mode 0: AI setup/init dispatch                   [depth 1: HAS 0 callees]
  +-- FUN_004a5ea0 — Mode 2: AI driving state dispatch                [depth 1: HAS 0 callees]
  +-- FUN_004a55e0 — AI state lookup/query                            [leaf — no further callees]
  +-- FUN_004a3440 — AI behavior computation                          [leaf — no further callees]
  +-- FUN_004a6db0 — AI data/parameter fetch                          [depth 1: HAS 0 callees]
  +-- FUN_004a3390 — AI driving helper dispatch                       [depth 1: HAS 0 callees]
  +-- FUN_004d1100 — Track/surface/path lookup                        [depth 1: HAS 0 callees]
  +-- FUN_004a3320 — AI state transition helper                       [depth 1: HAS 0 callees]
```

## Step-by-Step Trace

### Level 0: FUN_004a5d10 — AI State Machine with Mode Dispatch

**Trigger:** Per-frame AI state update. Called from AI subsystem tick.
**Called by:** Unknown (callers.json shows no callers — likely called from main AI update chain)
**Purpose:** Update AI state machine based on mode + input.

**Key actions:**
1. Compare param_2+8 byte with current mode at param_1[0x61]
2. If mode changed: call FUN_0041a200 (mode change handler)
3. Set param_1[0x62] from param_2+4
4. If game mode 2 or 3 (championship): dispatch:
   - Mode 0 → FUN_004a5f20 (AI setup/init)
   - Mode 2 → FUN_004a5ea0 (AI driving state)
5. Mode 0: call FUN_004a3440 if flag set
6. Modes 1-2: call FUN_004a6db0, dispatch FUN_004a3390, call FUN_004d1100 + FUN_004a3320

**Data passed to callees:** AI state struct (param_1), input/mode data (param_2).

### Level 1: Selected Callees

- **FUN_0041a200 (mode change handler):** Called when param_1[0x61] mode changes. Resets AI state for new mode.
- **FUN_004a5f20 (mode 0 dispatch):** AI setup/init — initializes AI for new session/state.
- **FUN_004a5ea0 (mode 2 dispatch):** AI driving state — per-frame driving behavior.
- **FUN_004d1100 (track/surface lookup):** Reads track surface data for AI path following.
- **FUN_004a3390 (AI driving helper):** Computes steering/throttle/brake targets.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_004a5d10 | AI ptr, input | mode dispatch | updated AI state |
| FUN_0041a200 | old/new mode | mode transition | reset state |
| FUN_004a5f20 | AI ptr | mode 0 init | AI initialized |
| FUN_004a5ea0 | AI ptr | mode 2 update | driving state |
| FUN_004d1100 | vehicle ptr | surface lookup | grip/traction data |

## Globals Written in This Chain

None documented — operates on AI struct fields.

## Notes

All 9 callees are shallow (depth 1-2). Mode dispatch is the core pattern — FUN_004a5d10 selects the handler based on game mode and AI mode byte.

---
