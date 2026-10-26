# Chain: Animation Playback Sequence — DirectX Mesh Animation

Seed: FUN_0044acb0  |  System: docs/19-renderer.md  |  Depth: 2  |  Functions: 13

---

## Overview

Triggered by scene/track rendering code to play animated mesh sequences. Iterates DirectX animation tracks, checks keyframe flags, applies vertex transforms, and looks up mesh objects by name. Uses time-based interpolation for smooth playback. Cross-system: calls FUN_0044aae0 (animation time step, physics/collision system).

## Call Tree

```
FUN_0044acb0 — Animation Playback Sequence  [trigger: D3D animation system frame update]
  +-- FUN_005452f0 — [undocumented D3D animation track iterator]
  +-- FUN_00545340 — [undocumented D3D animation track next]
  +-- FUN_0054c210 — [undocumented D3D mesh util]
  +-- FUN_0054c230 — [undocumented D3D mesh util]
  +-- FUN_0054e190 — [undocumented D3D animation utility]
  +-- FUN_0054e240 — [undocumented D3D animation utility]
  +-- FUN_00547370 — [undocumented vertex transform helper]
  |     [may call D3D transforms internally]
  +-- FUN_004ce860 — Mesh Lookup  [find mesh by name]
  |     [render state query]
  +-- FUN_004ce8d0 — [undocumented mesh helper]
  +-- FUN_004dd9f0 — [undocumented render timing]
  +-- FUN_0044aae0 — Animation Time Step  [cross-system: physics/collision docs/17]
        [computes interpolation factor for current time]
```

## Step-by-Step Trace

### Level 0: FUN_0044acb0 — Animation Playback Sequence

**Trigger:** Called per-frame during scene rendering when animated objects exist.
**Called by:** Scene/track render code.
**Purpose:** Plays back DirectX mesh animation sequences on 3D scene objects.

**Key actions:**
1. Iterates animation tracks via FUN_005452f0/FUN_00545340
2. Checks keyframe flag 0x100 for active animation state
3. For each active keyframe: calls FUN_00547370 for vertex transforms
4. Compares mesh names for matching
5. Calls FUN_004ce860 for mesh object lookup by name
6. Applies time-based interpolation via FUN_0044aae0 (cross-system to physics/collision)

**Data passed to callees:** param_1 (animation state struct), animation track handles, time delta

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_0044acb0 | anim state | Track iterate | Active keyframes |
| FUN_005452f0 | track handle | Get next track | Track data |
| FUN_00547370 | vertex buffer | Apply transform | Transformed vertices |
| FUN_004ce860 | mesh name | Lookup by name | Mesh handle |
| FUN_0044aae0 | current time | Interpolation factor | Animated transform |

## Globals Written in This Chain

None identified.

## Notes

- Cross-system handoff: FUN_0044aae0 is in docs/17 (physics-collision), used here for animation timing
- All D3D animation callees (FUN_0054xxxx) are DirectX 8 animation API wrappers
- Mesh name comparison suggests scene graph objects have string identifiers

---

---
