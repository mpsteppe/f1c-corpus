# Chain: UI Cursor/Selection Rectangle Render with Interpolation — Animated selection rectangle

Seed: FUN_0045b660  |  System: docs/17-physics-collision.md  |  Depth: 6  |  Functions: ~10

---

## Overview

FUN_0045b660 renders an animated selection rectangle or cursor with smooth interpolation. Called from UI cursor setup, it checks cursor state, computes interpolated target positions, smoothly lerps current values toward targets, and renders a rectangle border. The chain includes array max computation, float-to-int conversion, field getters, and line rendering.

## Call Tree

```
FUN_0045b660 — UI Cursor/Selection Rectangle Render  [trigger: UI cursor/frame update]
  +-- FUN_0045bb00 — Array threshold search  [leaf]
  +-- FUN_0045b5c0 — Array Max Computation  [4 callees]
  |     +-- FUN_0045bb00 — Array threshold search  [leaf]
  |     +-- FUN_0045b580 — Physics channel iteration  [leaf]
  |     +-- FUN_00456040 — Double Field Getter at +0x30/+0x34  [leaf]
  |     +-- FUN_004dd400 — Normalized Coordinate Calculator  [sub: 1]
  +-- FUN_004dcda0 — Float-to-Int Conversion + Dispatch  [sub: 1]
  +-- FUN_004dcee0 — Float-to-Int Chain Delegate  [sub: 1]
  +-- FUN_004dcd60 — Conditional Call  [sub: 1]
  +-- FUN_004dcf30 — Twin Field Getter (+0x14, +0x18)  [leaf]
  +-- FUN_004dcf50 — Triple Field Getter  [leaf]
  +-- FUN_00494c20 — Float Vector with Conditional Transform  [leaf]
```

## Step-by-Step Trace

### Level 0: FUN_0045b660 — UI Cursor/Selection Rectangle Render with Interpolation

**Called by:** FUN_0045b840 (setup)
**Purpose:** Renders animated selection rectangle or cursor with smooth interpolation.

**Key actions:**
1. Checks state via FUN_0045bb00; if inactive and value at +0x328 == DAT_0059e440, resets
2. Computes target values via FUN_0045b5c0
3. Smoothly interpolates +0x324 and +0x328 toward targets
4. If difference small: snaps to target; else: lerps with coefficient
5. Renders rectangle border via FUN_00494c20 with color 0xff999999

**Globals:** DAT_008b8dc8 (render target), DAT_0059e440, DAT_0059e448, DAT_0059f078, DAT_0059f088, DAT_0059e8c8

### Level 1: FUN_0045b5c0 — Array Max Computation

**Called by:** FUN_0045b660 (target computation)
**Purpose:** Computes maximum value from an array of floats for interpolation target.

**Key actions:**
1. Iterates 8 physics channels
2. Finds Nth with positive value above threshold
3. Returns computed target

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_0045b660 | Cursor state, position inputs | Interpolation + border render | Animated selection rectangle |

## Globals Written in This Chain

None documented (reads globals for coefficients but writes are internal to struct).

## Notes

- Chain is shallow (depth 2 max) with most callees being leaf field getters/setters.
- FUN_0045bb00 is reused as both a direct callee and as a sub-callee of FUN_0045b5c0.
- Cross-system: FUN_0045b580 (physics channel iteration) goes to docs/18-physics-dynamics.

---
