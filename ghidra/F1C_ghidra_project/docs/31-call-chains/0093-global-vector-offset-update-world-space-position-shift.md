# Chain: Global Vector Offset Update — World-Space Position Shift

Seed: FUN_0040e1f0  |  System: docs/01-engine-architecture.md  |  Depth: 1-2  |  Functions: 7 callees

---

## Overview

Iterates all vehicles/objects and subtracts a 3D offset vector from each sub-object's position. Used for world-space position adjustment (e.g., recentering all objects). Clears transform dirty flags, updates bounds and physics after modification.

## Call Tree

```
FUN_0040e1f0 — Global Vector Offset Update  [trigger: world-space reposition, e.g., load/recenter]
  +-- FUN_0054c210 — Get vehicle/object count                        [leaf]
  +-- FUN_0054c230 — Get vehicle by index                            [leaf]
  +-- FUN_0054e100 — Get part count for vehicle                      [leaf]
  +-- FUN_0054e120 — Get part position pointer                       [leaf]
  +-- FUN_0054d520 — Mark transform dirty (flag clear)               [leaf]
  +-- FUN_0054e270 — Update bounds                                   [depth 1: HAS 0 callees]
  +-- FUN_0054d080 — Update physics                                  [leaf]
```

## Step-by-Step Trace

### Level 0: FUN_0040e1f0 — Global Vector Offset Update

**Trigger:** World-space repositioning event (e.g., session load, track recenter).
**Called by:** Unknown (callers.json has no callers for this seed)
**Purpose:** Subtract offset vector from all vehicle sub-object positions, update transforms.

**Key actions:**
1. Get vehicle count via FUN_0054c210()
2. For each vehicle:
   - Get vehicle pointer via FUN_0054c230(index)
   - Get part count via FUN_0054e100()
   - For each part:
     - Get part position ptr via FUN_0054e120(partIdx)
     - Subtract param_2 offset from all 3 components (x,y,z)
   - Clear flag bits at ptr+0x14 (mask 0xfeffffdf — clears bits 0,5,23)
   - Call FUN_0054d520(1) — update transform
   - Call FUN_0054e270() — update bounds
   - Call FUN_0054d080(0) — update physics

**Data passed to callees:** vehicle/object indexes, update flags.

### Level 1: Callees

All callees are render/scene graph API functions:
- **FUN_0054c210** — Count query, returns total vehicles
- **FUN_0054c230** — Indexed vehicle pointer getter
- **FUN_0054e100** — Part count per vehicle
- **FUN_0054e120** — Part position pointer (for direct write)
- **FUN_0054d520** — Transform dirty flag set/clear
- **FUN_0054e270** — Bounds recomputation
- **FUN_0054d080** — Physics state update

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_0040e1f0 | offset vec3 | iterate all vehicles | shifted positions |
| FUN_0054c210 | none | count query | N vehicles |
| FUN_0054e120 | part index | position pointer | writeable float[3] |
| FUN_0054d520 | 1 | bit clear | transform dirty=0 |

## Globals Written in This Chain

None — operates on render/scene graph objects directly.

## Notes

All callees are leaf functions except FUN_0054e270 which has 0 further callees in call_graph.json (effectively leaf). This is a scene graph traversal utility, not game logic.

---
