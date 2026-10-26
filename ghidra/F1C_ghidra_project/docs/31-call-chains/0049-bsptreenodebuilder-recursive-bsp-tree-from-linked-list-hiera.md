# Chain 48: BSPTreeNodeBuilder — Recursive BSP tree from linked-list hierarchy

Seed: FUN_0044a4b0  |  System: docs/17-physics-collision.md  |  Depth: 2  |  Functions: 4 callees

---

## Overview

Triggered during collision tree construction. Recursively builds BSP/octree nodes from a linked-list hierarchy by sampling 14 candidate split positions, evaluating the closest-metric split, and recursively building left and right children. Handles leaf cases (single node or two nodes).

## Call Tree

```
FUN_0044a4b0 — BSPTreeNodeBuilder  [trigger: collision tree construction]
  +-- FUN_0044a450 — Sample Split / CollisionMaterialLookup  [evaluate split metric]
  +-- FUN_0044a2d0 — BVH Binary Tree Builder  [evaluate split metric — docs/17]
  |     +-- 2 leaf callees omitted
  +-- FUN_00449ed0 — Process Node / Spatial Hash Key Generation  [process node — docs/18]
  |     +-- 2 leaf callees omitted
  +-- FUN_00566bd0 — Conditional Dispatch / Serialise Byte  [serialise split data]
```

## Step-by-Step Trace

### Level 0: FUN_0044a4b0 — BSPTreeNodeBuilder

**Trigger:** Collision tree construction during scene load.
**Called by:** Orphan (no callers recorded).
**Purpose:** Recursively builds BSP/octree nodes from linked-list hierarchy.

**Key actions:**
1. Counts nodes in linked list via +0x1c next pointer
2. Determines sample stride: small trees (<11 nodes) → stride 7; medium (<101) → stride 15; large → 3
3. Samples idx 0..14 at computed stride, evaluates closest-metric via FUN_0044a450 + FUN_0044a2d0
4. Selects best split index (minimum distance)
5. Stores split direction at param_1 + 8 (0=left, 1=right) and split index at +0xa
6. Serialises via FUN_00566bd0 (1 byte each for direction and index)
7. Allocates output at param_1 + 0xc = vertex data pointer (size = 2 × 16 bytes)
8. Recursively builds left child (local_1c) and right child (local_10)
9. Leaf cases: single node → +0x8 = 0xffff; two nodes → +0x8 = 0xfffe

**Struct offsets (param_1 — node output):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x08 | splitDir | 0=left, 1=right, 0xffff=leaf, 0xfffe=2-node |
| +0x0a | splitIndex | Index of split plane (0..14 or 0xe - idx) |
| +0x0c | vertexPtr | Output vertex buffer pointer |

### Level 1: Key callees

**FUN_0044a450 — Sample Split / CollisionMaterialLookup** — Evaluates split metric at a candidate position. Leaf function.

**FUN_0044a2d0 — BVH Binary Tree Builder** — Builds bounding volume hierarchy from sorted node list. 2 callees (recursive builder functions). From docs/17.

**FUN_00449ed0 — Process Node / Spatial Hash Key Generation** — Generates spatial hash keys for node distribution. 2 callees. From docs/18.

**FUN_00566bd0 — Conditional Dispatch / Serialise Byte** — Writes split direction and index as serialized bytes. Leaf function.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_0044a4b0 | Linked list head | Count nodes, determine stride | Node count, sample stride |
| FUN_0044a450 | Candidate position | Evaluate split metric | Metric value |
| FUN_0044a2d0 | Sorted node list | Build subtree | Left/right subtrees |
| FUN_00566bd0 | Split params | Serialize | Serialized bytes |

## Globals Written in This Chain

None.

## Notes

- Recursive algorithm: base cases at single/two nodes
- Sample stride adapts to tree size: larger trees sample sparser
- `hardcoded`


---
