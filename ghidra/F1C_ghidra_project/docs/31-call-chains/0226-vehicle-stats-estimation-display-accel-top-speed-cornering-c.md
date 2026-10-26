# Chain: Vehicle Stats Estimation Display — ACCEL/TOP SPEED/CORNERING Calculator

Seed: 0x00430f00  |  System: docs/10-vehicle-physics.md  |  Depth: 1  |  Functions: 4

---

## Overview

Called from setup display (0x00432180) and UI stats page (0x00486d90). Estimates vehicle performance metrics from current setup: 0-60/0-100 mph acceleration time, top speed, and cornering G-force. Uses acceleration simulation (0x00430a50) iteratively until target velocity is reached, then cornering simulation (0x00430750) for lateral G. Results formatted to display buffer. All 4 callees are leaf functions.

## Call Tree

```
0x00430f00 — Vehicle Stats Estimation Display  [trigger: user views setup stats screen]
  +-- 0x00430a50 — acceleration simulation  [called iteratively]
  +-- 0x00430750 — cornering simulation
  +-- 0x00423a00 — string copy
  +-- 0x0058815f — format/print
```

## Step-by-Step Trace

### Level 0: 0x00430f00 — Vehicle Stats Estimation Display

**Trigger:** User opens vehicle setup stats display
**Called by:** 0x00432180 (setup display), 0x00486d90 (UI stats page)
**Purpose:** Computes and formats acceleration/top speed/cornering estimates

**Key actions:**
1. Copies label strings to DAT_005ec4cc (MessageBuffer)
2. Clears 3 format buffers at param_1+0x1b26 (stride 0x80)
3. Metric/imperial branch via DAT_007d0474:
   - Metric (0): scale=100, label "EST. ACCEL" from DAT_005c3f64
   - Imperial (!=0): scale=150, label "EST. ACCEL (mph)" from DAT_005c3f68
4. Acceleration simulation loop:
   - Calls FUN_00430a50 repeatedly until velocity exceeds threshold
   - Formats "0-60/0-100 time: %.2f %s"
5. Top speed computation:
   - Calls FUN_00430a50 iteratively until acceleration ≈ 0
   - Writes "EST. TOP SPEED" + value
6. Cornering estimation:
   - Calls FUN_00430750(0, 74.5f)
   - Writes "EST. CORNERING" + G-force value
7. All writes via FUN_0058815f to param_1 buffer region (+0x19a6 to +0x1c26)

**Data passed to callees:** vehicle setup struct (param_1), simulation constants

**Globals used:** DAT_007d0474 (metric/imperial flag)

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| 0x00430f00 | DAT_007d0474 | Branch metric/imperial | scale, label |
| 0x00430a50 | setup params, dt | Integrate until velocity target | 0-60/0-100 time |
| 0x00430a50 | setup params, dt | Integrate until a=0 | top speed |
| 0x00430750 | setup params, 74.5f | Lateral G computation | cornering G |
| 0x0058815f | label, value, unit | Format string | display buffer |

## Globals Written in This Chain

| Global | Name | Written by | Value meaning |
|--------|------|-----------|---------------|
| DAT_005ec4cc | MessageBuffer | 0x00430f00 | Label strings for UI display |

## Notes

- All 4 callees are leaf functions
- Display-only — no game state mutation
- Format buffers at param_1+0x19a6..+0x1c26 (3 × 0x80 = 384 bytes)
