# Chain: 2D Screen Quad Render (Collision Overlay) — Debug Rendering

Seed: FUN_00494a70  |  System: docs/17-physics-collision.md  |  Depth: 2  |  Functions: 6

---

## Overview

Renders a 2D textured quad in screen space for collision visualization or HUD overlay. Clamps dimensions to [0,256], computes UV coordinates, sets 4 vertices in triangle-strip order, and issues draw call through begin/render/end sequence.

## Call Tree

```
FUN_00494a70 — 2D Screen Quad Render (Collision Overlay)  [per-frame debug render]
  +-- FUN_00543250 — Clipped Render Region [clear]
  |     +-- FUN_00543540 — clip region set
  |     +-- FUN_00540250 — clear surface
  +-- FUN_00553650 — vertex set [undocumented]
  +-- FUN_004f9f00 — Conditional Init [render start]
  |     +-- FUN_0055c9b0 — conditional check
  |     +-- FUN_005550a0 — state init
  +-- FUN_00553700 — draw call [undocumented]
  +-- FUN_004f9f30 — Conditional State Reset [render end]
        +-- FUN_0055c9b0 — conditional check
        +-- FUN_005550c0 — state reset
```

## Step-by-Step Trace

### Level 0: FUN_00494a70 — 2D Screen Quad Render

**Trigger:** Called per-frame for collision debug overlay.
**Called by:** No callers in graph (likely called from debug render dispatch).
**Purpose:** Renders 2D textured quad for collision visualization.

**Key actions:**
1. Clamps param_4 (width), param_5 (height) to [0, 256]
2. If both dims > 0:
   - Calls FUN_00543250 — clear blit destination
   - Computes UV coords: width * DAT_005ac988, height * DAT_005ac988
   - Sets 4 vertices via FUN_00553650 (lower-left, upper-left, upper-right, lower-right)
   - Calls FUN_004f9f00 — begin rendering
   - Calls FUN_00553700 — draw call
   - Calls FUN_004f9f30 — end rendering

### Level 1: FUN_00543250 — Clipped Render Region [clear]

**Trigger:** Called to clear destination before render.
**Purpose:** Sets clip region and clears the destination surface.

### Level 1: FUN_00553650 — Vertex Set [undocumented]

**Trigger:** Called to set 4 quad vertices.
**Purpose:** Writes vertex positions and UVs into vertex buffer.

### Level 1: FUN_00553700 — Draw Call [undocumented]

**Trigger:** Called to issue draw.
**Purpose:** Issues D3D draw primitives call for the quad.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| Clamp | width, height | clamp [0,256] | clamped dims |
| UV compute | dims * scale | multiply | UV coordinates |
| Vertex set | pos+uv × 4 | FUN_00553650 | vertex buffer |
| Render cycle | vertex buffer | begin→draw→end | rendered quad |

## Notes

- 5 callees, linear pipeline (clear → vertex → begin → draw → end).
- FUN_00553650 and FUN_00553700 are [undocumented] — likely D3D device calls.
- Standard D3D immediate-mode rendering pattern.
- Globals: DAT_007cde08 (destination surface), DAT_005ac988 (UV scale).

---
