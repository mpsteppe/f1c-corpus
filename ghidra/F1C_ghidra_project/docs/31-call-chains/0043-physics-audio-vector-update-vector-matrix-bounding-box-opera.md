# Chain 42: Physics/Audio Vector Update — Vector/matrix/bounding box operations

Seed: FUN_004e2ad0  |  System: docs/20-math-utilities.md  |  Depth: 2  |  Functions: 10 callees

---

## Overview

Undocumented seed function (functions.json lists as "Physics/Audio Vector Update") that dispatches to 10 subroutines, primarily vector/matrix math utilities and bounding box computations. All callees are leaf or near-leaf functions.

## Call Tree

```
FUN_004e2ad0 — Physics/Audio Vector Update  [trigger: unknown — callers: 0]
  +-- FUN_004dd550 — Bounding Box Computation (Min/Max)  [compute AABB]
  +-- FUN_0054b420 — Copy Three Fields to Output  [field copy]
  +-- FUN_0054b3b0 — Three-Field Setter with Sub-Call  [set fields]
  +-- FUN_0054c210 — Scene Graph Child Count  [count children]
  +-- FUN_0054c230 — Linked List Indexed Accessor  [access list by index]
  +-- FUN_0054e100 — PackedArrayTotalSize  [array size]
  +-- FUN_0054e120 — PackedArrayIndexLookup  [lookup by index]
  +-- FUN_0054d520 — 3D Bounding-Box Extents Computation  [compute extents]
  +-- FUN_0054e270 — Bounding-Box Computation from Vertex Data  [compute from vertices]
  +-- FUN_0054d080 — Triangle Mesh Face Normal/AABB  [face normal]
```

## Step-by-Step Trace

### Level 0: FUN_004e2ad0 — Physics/Audio Vector Update

**Trigger:** Unknown — orphan function with no callers recorded.
**Called by:** None recorded in callers.json.
**Purpose:** Dispatches vector/matrix/bounding box operations.

**Key actions:**
1. Computes bounding boxes (FUN_004dd550, FUN_004d520, FUN_004e270)
2. Accesses scene graph child counts and array indices (FUN_004c210, FUN_004c230)
3. Sets or copies fields (FUN_004b420, FUN_004b3b0)
4. Computes triangle mesh face normals (FUN_004d080)

### Level 1: Key callees

**FUN_004dd550 — Bounding Box Computation (Min/Max)** — Computes AABB min/max from vertex data. Leaf.

**FUN_004d080 — Triangle Mesh Face Normal/AABB** — Computes face normals, bounding boxes, and dominant axis for triangle mesh. Leaf.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_004e2ad0 | Scene/vertex data | Dispatch to 10 utilities | Updated state |
| FUN_004dd550 | Vertex positions | Compute min/max | AABB |

## Globals Written in This Chain

None.

## Notes

- Undocumented seed — summary inferred from callee purposes
- All 10 callees are leaf or near-leaf math/scene graph accessors
- `hardcoded`

---
