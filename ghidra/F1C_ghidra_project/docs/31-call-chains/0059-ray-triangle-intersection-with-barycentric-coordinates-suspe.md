# Chain: Ray-Triangle Intersection with Barycentric Coordinates — Suspension Collision Detection

Seed: 0x004efbd0  |  System: docs/17-physics-collision.md  |  Depth: 2  |  Functions: 6

---

## Overview

Performs ray-triangle intersection test against wheel suspension geometry. Triggered during suspension contact computation. Transforms collision triangle vertices into body space, computes intersection equation, returns distance along ray to impact. Output: hit distance or ride height (miss), clamped within valid range.

## Call Tree

```
0x004efbd0 — Ray-Triangle Intersection w/ Barycentric  [trigger: suspension contact detection]
  +-- 0x004ed750 — 3D Cross Product  [computes triangle normal, leaf]
  +-- 0x004ed710 — Vec3 Add  [edge vector subtraction, leaf]
  +-- 0x004ef680 — RideHeightDelta  [computes wheel offset from triangle, leaf]
  +-- 0x004ec020 — 3D Vector Addition  [applies wheel offset to triangle, leaf]
  +-- 0x004ed7b0 — 3×3 Matrix × Vector Multiply  [transforms vertices to body space, leaf]
  +-- 0x004efee0 — 3D Dot Product  [solves ray equation dot products, leaf]
```

## Step-by-Step Trace

### Level 0: 0x004efbd0 — Ray-Triangle Intersection with Barycentric Coordinates

**Trigger:** Suspension contact detection — per-wheel per-frame during collision processing.
**Called by:** 0x004bc390 (suspension collision path).
**Purpose:** Ray-triangle intersection for wheel suspension geometry, returns distance to impact.

**Key actions:**
1. Transforms collision triangle vertex positions into body space via rotation matrix (FUN_004ed7b0)
2. Computes triangle edge vectors (FUN_004ed710) and normal (FUN_004ed750)
3. Applies wheel offset via FUN_004ec020
4. Solves ray-triangle intersection equation: origin + t*direction = barycentric position
5. Returns t (distance along ray) or 0 if no intersection
6. Applies double-sided intersection test with both edge normals via FUN_004ed7b0
7. Clamps result within [_DAT_0059e87c, max] or returns ride height (+0x34ac)

**Data passed to callees:** Triangle vertex positions, ray origin/direction, wheel offset data, rotation matrix.

### Level 1: All callees are leaf functions

**0x004ed750** — 3D Cross Product. Computes triangle normal = (v1-v0) × (v2-v0).
**0x004ed710** — Vec3 Add. Computes edge vectors from triangle vertices.
**0x004ef680** — RideHeightDelta. Computes wheel-to-triangle height difference.
**0x004ec020** — 3D Vector Addition. Applies wheel offset to triangle vertex positions.
**0x004ed7b0** — 3×3 Matrix × Vector Multiply. Transforms triangle into body space.
**0x004efee0** — 3D Dot Product. Solves barycentric equation components.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_004ed7b0 | vertices, matrix | transform | body-space vertices |
| FUN_004ed710 | body-space verts | edge subtraction | edge vectors |
| FUN_004ed750 | edge vectors | cross product | triangle normal |
| FUN_004ec020 | triangle, offset | vector add | offset triangle |
| FUN_004efee0 | ray, edges, normal | dot products | barycentric coords |
| FUN_004efbd0 | t values | clamp | final distance or ride height |

## Globals Written in This Chain

None — all data is struct-based (vehicle struct +0x34ac for ride height).

## Notes

Pure math chain — all 6 callees are leaf functions performing basic 3D vector/matrix operations (cross product, dot product, vector add, matrix multiply). The double-sided intersection test allows hitting both front and back faces of triangles, which is necessary for suspension that may be inside or outside the collision mesh.

---
