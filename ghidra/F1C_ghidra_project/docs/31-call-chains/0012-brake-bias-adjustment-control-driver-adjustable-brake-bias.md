# Chain: Brake Bias Adjustment Control — Driver-Adjustable Brake Bias

Seed: FUN_00447d00  |  System: docs/10-vehicle-physics.md  |  Depth: 2  |  Functions: 6

---

## Overview

Triggered by driver brake bias adjustment input (up/down control). Increments or decrements the current brake bias index, clamped to valid range [0, max_index]. Computes actual bias value via `index * slope + intercept` using double-precision fields at param_1+0x1564..0x1580. Clears display (FUN_0045bdf0), copies "BRAKE BIAS" string (FUN_00423a00), formats the rear:front split (FUN_0058815f), and writes to HUD (FUN_0045bd10). Moddable: slope and intercept from .svm setup file.

## Call Tree

```
FUN_00447d00 — Brake Bias Adjustment Control  [trigger: driver input — bias up/down]
  +-- FUN_0045bdf0 — Clear Display  [clears HUD message area]
        [called by: OnScreen::Restart docs/01, pit penalty, and brake bias]
  +-- FUN_00423a00 — String Copy  ["BRAKE BIAS" label copy]
  +-- FUN_0058815f — Format  [sprintf-style: "%s %4.1f:%4.1f"]
  +-- FUN_0045bd10 — HUD Write  [writes formatted bias string to HUD display]
```

## Step-by-Step Trace

### Level 0: FUN_00447d00 — Brake Bias Adjustment Control

**Trigger:** Called when driver adjusts brake bias (controls mapped to increment/decrement).
**Called by:** Vehicle setup/input handler (callers: 1 from callers.json).
**Purpose:** Adjusts brake bias index, computes bias value, displays on HUD.

**Key actions:**
1. param_2 < 0: decrements brake bias index, clamped to 0
2. param_2 > 0: increments brake bias index, clamped to max (param_1+0x157c)
3. Computes actual bias: `index * slope + intercept` from param_1 + 0x1564
4. Displays via FUN_0045bd10: "BRAKE BIAS %4.1f:%4.1f" (rear:front split)

**Struct offsets (param_1 — vehicle setup struct):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x1564 | ComputedBrakeBias | double, result value |
| +0x156c | BiasIntercept | double, from .svm |
| +0x1574 | BiasSlope | double, from .svm |
| +0x157c | MaxBiasIndex | int, clamp upper bound |
| +0x1580 | CurrentBiasIndex | int, current setting |

**Data passed to callees:** formatted string buffer, HUD display parameters

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_00447d00 | param_2 < 0 | Decrement index | Clamped to ≥ 0 |
| FUN_00447d00 | param_2 > 0 | Increment index | Clamped to ≤ max |
| FUN_00447d00 | index, slope, intercept | Bias compute | double bias value |
| FUN_0045bdf0 | — | Clear display | HUD area cleared |
| FUN_00423a00 | "BRAKE BIAS" | String copy | Buffer with label |
| FUN_0058815f | label, rear, front | Format | "%s %4.1f:%4.1f" |
| FUN_0045bd10 | formatted string | HUD write | Bias displayed |

## Globals Written in This Chain

None — operates on param_1 vehicle setup struct fields only.

## Notes

- Brake bias is a **moddable field** — slope and intercept come from .svm setup file
- Display format shows rear:front split (e.g., "BRAKE BIAS 58:42")
- FUN_0045bdf0 (Clear Display) is also called by OnScreen::Restart (docs/01) and pit penalty code — shared display utility
- Pure leaf chain: all 4 callees are terminal (no further sub-calls)

---

---
