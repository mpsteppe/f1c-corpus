# Chain: AudioDSPStateUpdate — Audio DSP processing state update

Seed: FUN_00448330  |  System: docs/18-physics-dynamics.md  |  Depth: 2  |  Functions: 8

---

## Overview

Updates audio DSP processing state with timing and volume control. Checks activity threshold (>1.0f at +0x8), queries time, iterates active audio sources, sets volume/pan with normalized time. Handles DSP state transitions via vtable dispatch and conditional restart/update paths.

## Call Tree

```
FUN_00448330 — AudioDSPStateUpdate  [trigger: per-frame audio DSP update]
  +-- FUN_0058957a — TimeQuery  [QPC time query — leaf]
  +-- FUN_0054c210 — ActiveSourceCount  [get active audio source count — leaf]
  +-- FUN_0054c230 — SourceIteration  [iterate audio sources — leaf]
  +-- FUN_00551810 — VolumePanSet  [set volume/pan — leaf]
  +-- FUN_0054b950 — ChannelValuesGet  [get channel values — leaf]
  +-- FUN_00550620 — DSPStateUpdate  [update DSP state — leaf]
  +-- FUN_005505a0 — DSPStateRestart  [restart DSP state — leaf]
```

## Step-by-Step Trace

### Level 0: FUN_00448330 — AudioDSPStateUpdate

**Trigger:** Per-frame from audio mixer pipeline
**Called by:** Audio system update loop
**Purpose:** Updates audio DSP processing state with timing and volume control.

**Key actions:**
1. If value at +0x8 > 1.0f (active threshold): gets time via FUN_0058957a
2. Iterates audio sources (FUN_0054c210 count), calling FUN_0054c230 and FUN_00551810 with normalized time
3. Calls FUN_0054b950 for color/channel values
4. If vtable pointer at +4 is non-null: calls through vtable at offset 4 with transform params DAT_007cf2cc and 1.0f scale
5. Handles state at +0x10: if null, sets +0x18 = param_2; else if param_2 unchanged, calls FUN_00550620; else calls FUN_005505a0
6. Stores param_2 at +0x18

**Data passed to callees:** Audio state pointer (param_1), state value (param_2)

### Level 1: All 7 callees

All callees are single-purpose audio processing helpers, all leaf functions.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_00448330 | param_1+0x8 | Compare > 1.0f threshold | Active/inactive |
| FUN_00448330 | Audio sources | Iterate and set volume/pan | Audio output |
| FUN_00448330 | param_2 | DSP state transition | DSP update/restart |
| FUN_00448330 | vtable+4 | Transform call | DSP transform |

## Globals Written in This Chain

| Global | Name | Written by | Value meaning |
|--------|------|-----------|---------------|
| DAT_007cf2cc | DSP transform param | (read by FUN_00448330) | DSP transform parameter |

## Notes

- Despite being in docs/18-physics-dynamics.md, this is purely an audio function
- Threshold at +0x8 > 1.0f gates the entire processing path
- Two DSP state paths: update (FUN_00550620) when param_2 unchanged, restart (FUN_005505a0) when changed
- vtable dispatch at offset +4 for DSP transform

---
