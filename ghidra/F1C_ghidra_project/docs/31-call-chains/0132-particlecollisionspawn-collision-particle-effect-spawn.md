# Chain: ParticleCollisionSpawn — Collision Particle Effect Spawn

Seed: FUN_004c9fb0  |  System: docs/17-physics-collision.md  |  Depth: 2  |  Functions: 6

---

## Overview

Spawns particle effects at collision contact points. Called during collision response to generate visual particle effects (sparks, debris). Indexes into particle system arrays, computes bounding box for spawn position, copies transform data, and registers the particle effect for rendering.

## Call Tree

```
FUN_004c9fb0 — ParticleCollisionSpawn  [trigger: collision contact resolution]
  +-- FUN_0054c230 — Linked List Indexed Accessor  [indexes into particle system list]
  +-- FUN_004dd550 — Bounding Box Computation (Min/Max)  [computes spawn bounding box]
  +-- FUN_0054b420 — Three-Field Copy  [copies 3 transform fields from collision data]
  +-- FUN_0054e100 — PackedArrayTotalSize  [reads particle array size]
  +-- FUN_0054e120 — PackedArrayIndexLookup  [indexes into particle data array]
```

## Key Actions

1. Indexes into particle system linked list via FUN_0054c230
2. Computes bounding box for particle spawn position via FUN_004dd550
3. Copies collision transform data (3 fields) to particle system via FUN_0054b420
4. Reads packed array sizes for particle slot allocation
5. Registers particle effect with rendering system

## Data Flow Summary

| Input | Operation | Output |
|-------|-----------|--------|
| Collision point data | Bounding box compute | Spawn region |
| Collision transform | Copy 3 fields | Particle transform |
| Particle list | Indexed access + allocate | Particle effect registered |

## Notes

- 5 direct callees, all leaf functions (0 sub-callees) — pure utility
- All callees shared with FUN_0040e2b0 (Audio/Physics Mix) — these are shared utilities
- Moddability: particle count, spread angle, velocity scaling
- Called during collision response, not per-frame

---
