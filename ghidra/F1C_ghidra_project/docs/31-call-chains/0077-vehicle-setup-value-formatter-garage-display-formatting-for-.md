# Chain: Vehicle Setup Value Formatter — Garage display formatting for vehicle setup

Seed: FUN_0042f470  |  System: docs/10-vehicle-physics.md  |  Depth: 3  |  Functions: 15

---

## Overview

Formats vehicle setup parameter values for display in the garage setup screen. Dispatches by param_2 index to format each setup type (gears, suspension, alignment, tires, differential, etc.). Reads setup parameter array at param_1+0xbb0 (stride 0x40 per entry). Dispatches to specialized formatters for ratio, percentage, angle, time, speed, and bevel gear displays.

## Call Tree

```
FUN_0042f470 — Vehicle Setup Value Formatter  [trigger: garage UI display]
  +-- FUN_0042f180 — SimpleFormat  [basic numeric format — leaf]
  +-- FUN_0042f1e0 — PercentageFormat  [percentage display — leaf]
  +-- FUN_0042f260 — ShortFormat  [short value format — leaf]
  +-- FUN_00423a00 — StringCopy  [string copy utility]
  +-- FUN_0058815f — FormatPrint  [sprintf-style format]
  +-- FUN_004d7880 — TireBrandLookup  [tire brand name — docs/10]
  +-- FUN_004d7570 — TireDataLookup  [tire data read — docs/10]
  +-- FUN_0042dcc0 — BevelGearRatioDispatch  [bevel gear path]
  |     +-- FUN_0042dce0 — BevelGearRatioCompute
  |     +-- FUN_0042dd00 — AngleRatioCompute
  +-- FUN_0042dce0 — BevelGearRatioCompute  [bevel gear ratio — leaf]
  +-- FUN_0042dc80 — AngleRatioDispatch  [angle/ratio path]
  |     +-- FUN_0042dca0 — AngleCompute  [angle computation]
  |     +-- FUN_0042dd00 — AngleRatioCompute
  +-- FUN_0042dca0 — AngleCompute  [angle/value compute — leaf]
  +-- FUN_0042dd00 — AngleRatioCompute  [angle ratio — leaf]
```

## Step-by-Step Trace

### Level 0: FUN_0042f470 — Vehicle Setup Value Formatter

**Trigger:** Called when garage UI needs to display a setup parameter value
**Called by:** Garage UI display system
**Purpose:** Formats setup parameters for display dispatch by param_2 index.

**Key actions:**
1. Setup parameter array at param_1+0xbb0, stride 0x40 per entry, indexed by param_2
2. Each entry: base (double at +0x00), multiplier (double at +0x08), count (int at +0x10), value (int at +0x14), format name (string at +0x18), flags at +0x1c
3. Switch on param_2 for 30+ format types:
   - case 0: "Unknown [name]"
   - case 1-2: Ratio "%.1f/%.1f" (gear ratios)
   - case 3: Steering lock "X turns"
   - case 4, 0x34-0x36: Gear ratio with count precision
   - case 5-6: Speed "%.2f %s" / "%.3f %s"
   - case 7-8: Float with unit
   - case 9-10: Speed/distance with auto/manual variant
   - case 0xb-0xc, 0x22: Float with unit
   - case 0xd-0xf, 0x15: Short format (delegate to FUN_0042f260)
   - case 0x11-0x1a: Percentage (delegate to FUN_0042f1e0)
   - case 0x27: Time "%d.%03d" (ms → sec.ms)
   - case 0x2a: Bevel gear ratio (FUN_0042dcc0/FUN_0042dce0)
   - case 0x2b-0x32: Complex angle/ratio (FUN_0042dc80/FUN_0042dca0/FUN_0042dd00)

**Data passed to callees:** Format strings, numeric values, unit strings

### Level 1: FUN_0042dcc0 — BevelGearRatioDispatch

**Trigger:** Called when case 0x2a (bevel gear) selected
**Called by:** FUN_0042f470
**Purpose:** Computes bevel gear ratio from gear parameters.

### Level 1: FUN_0042dc80 — AngleRatioDispatch

**Trigger:** Called for cases 0x2b-0x32
**Called by:** FUN_0042f470
**Purpose:** Computes complex angle/ratio combinations.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_0042f470 | param_1+0xbb0[param_2] | Switch on param_2 format type | Formatted string |
| FUN_0042dcc0 | Gear params | Bevel gear ratio computation | Ratio string |
| FUN_0042dc80 | Angle params | Angle/ratio computation | Angle string |

## Struct Offsets Used

| Offset | Field | Notes |
|--------|-------|-------|
| +0xbb0 | SetupParamArray | Array of 64-byte setup parameter entries |
| +0x1884 | GearCount | Number of gears |

## Notes

- Pure UI formatting — no game state mutation
- FUN_004d7880/FUN_004d7570 are tire data lookups also used by SuspensionAndWheelPhysics
- FUN_0058815f is a format/print utility (sprintf-like)

---
