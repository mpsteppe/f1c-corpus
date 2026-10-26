# Chain: 2D Text Rendering with Scissor Rectangle — Renders clipped 2D text with background fill

Seed: FUN_0049b370  |  System: docs/19-renderer.md  |  Depth: 6  |  Functions: ~9

---

## Overview

FUN_0049b370 renders 2D text with scissor rectangle clipping and background fill. Called from the main text render pipeline, it handles font glyph lookup, text layout, scissor clipping, background fill, and final text rendering. All 9 callees are leaf or near-leaf functions — the chain is flat.

## Call Tree

```
FUN_0049b370 — 2D Text Rendering with Scissor Rectangle  [trigger: on-screen text render]
  +-- FUN_005531f0 — undocumented  [leaf]
  +-- FUN_00553a20 — Float-to-Int Conversion Chain  [leaf]
  +-- FUN_004dcdd0 — Position Computation with Alignment (9 cases)  [leaf]
  +-- FUN_004dcd80 — Two-Field Setter + Update  [sub: 1]
  +-- FUN_004dcf20 — Field Setter + Call  [sub: 1]
  +-- FUN_004dcd60 — Conditional Call  [sub: 1]
  +-- FUN_00552fc0 — Field Setter at +0x48  [leaf]
  +-- FUN_00553070 — glyph rendering pipeline  [leaf]
  +-- FUN_0049b200 — Random Color Generator  [sub: 1]
```

## Step-by-Step Trace

### Level 0: FUN_0049b370 — 2D Text Rendering with Scissor Rectangle

**Called by:** FUN_0049f870 (text render)
**Purpose:** Renders 2D text with scissor rectangle clipping and background fill.

**Key actions:**
1. Looks up font glyph via FUN_005531f0
2. Lays out text via FUN_00553a20
3. Clips text to scissor rectangle via FUN_004dcdd0, FUN_004dcd80
4. Fills background via FUN_004dcf20, FUN_004dcd60
5. Creates/selects font via FUN_00552fc0, FUN_00553070
6. Renders final text via FUN_0049b200

### Level 1: FUN_00553070 — glyph rendering pipeline

**Called by:** FUN_0049b370 (font selection/creation)
**Purpose:** Glyph rendering pipeline with vertex buffer allocation.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_0049b370 | Text string, font ID, scissor rect | Glyph layout + scissor clip + fill | Rendered text on screen |

## Globals Written in This Chain

None documented.

## Notes

- All callees are leaf or 1-level deep — this is a flat orchestration function.
- Cross-system: FUN_0049b200 (Random Color Generator) comes from docs/17-physics-collision.

---
