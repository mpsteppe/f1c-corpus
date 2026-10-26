# Chain: Packed ARGB Color Extraction and Conversion — Renderer Color Pipeline

Seed: FUN_004b32a0  |  System: docs/20-math-utilities.md  |  Depth: 1  |  Functions: 8 callees

---

## Overview

FUN_004b32a0 converts packed ARGB color data to floating-point components. Called by FUN_00500010 (renderer path B). Uses 8 subfunctions for angle validation (FUN_004b2480), float-to-fixed conversion (FUN_004b25d0), float-to-short clamped (FUN_004b2750), float-to-short normalized (FUN_004b2310), ternary select (FUN_004b2bf0), bitfield insert (FUN_004b29b0), bitfield extract+scale (FUN_004b2c50), and float-to-bitfield pack (FUN_004b2930). All callees are pure arithmetic/conversion utilities with no branching on game state.

## Call Tree

```
FUN_004b32a0 — Packed ARGB Color Extraction and Conversion  [trigger: renderer color pipeline]
  +-- FUN_004b2480 — Angle Validation  [validate input range]
  +-- FUN_004b25d0 — Float-to-Fixed  [quantize float to fixed-point]
  +-- FUN_004b2750 — Float-to-Short Clamped  [clamped float-to-int16 conversion]
  +-- FUN_004b2310 — Float-to-Short Normalized  [normalized float-to-int16]
  +-- FUN_004b2bf0 — Ternary Select  [conditional value select]
  +-- FUN_004b29b0 — Bitfield Insert  [pack bits into field]
  +-- FUN_004b2c50 — Bitfield Extract+Scale  [unpack + scale bitfield]
  +-- FUN_004b2930 — Float-to-Bitfield Pack  [float -> bitfield packing]
```

## Step-by-Step Trace

### Level 0: FUN_004b32a0 — Packed ARGB Color Extraction and Conversion

**Trigger:** Renderer color pipeline, called by FUN_00500010 (path B)
**Called by:** FUN_00500010 (renderer path B)
**Purpose:** Convert packed ARGB color data to floating-point components

**Key actions:**
1. Reads packed color input (likely 32-bit ARGB)
2. Validates input range via FUN_004b2480
3. Extracts color channels using bitfield operations (FUN_004b29b0, FUN_004b2c50)
4. Converts to float using scale factor DAT_0059e780 (VertexScaleFactor)
5. Packs result via FUN_004b2930

**Data passed to callees:** Color data, scale constants

### Level 1: Key Callees

**FUN_004b25d0 — Float-to-Fixed**
- Quantizes float to fixed-point integer
- Uses DAT_0059e91c (ShortConversionMult) for scaling

**FUN_004b29b0 — Bitfield Insert**
- Inserts value bits into specified bitfield position
- Used for channel reassembly

**FUN_004b2c50 — Bitfield Extract+Scale**
- Extracts bits from packed color, applies scale factor
- ARGB channel extraction

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| Extract | Packed ARGB | Bitfield extract | Channel values |
| Scale | Channel values | × DAT_0059e780 | Float components |
| Pack | Float channels | Bitfield insert | Output format |

## Globals Written in This Chain

None — pure math utility.

## Notes

- All callees are pure arithmetic/conversion (docs/20-math-utilities.md)
- DAT_0059e780 is VertexScaleFactor (~1/32768) for short-to-float conversion
- Functions 0x004b2480-0x004b2c50 are a family of color/vertex format converters
- No branching on game state — pure data conversion

---
