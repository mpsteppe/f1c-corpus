## BVHTreeTraversal_0044aa30 — BVHTreeTraversal

**Summary:** Recursive BVH tree traversal for collision detection. Tests ray/query against BVH node: leaf nodes test against quadratic surface(s), interior nodes compute split-plane side and recurse into children. Part of collision detection system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** SpatialGridQuery (0044c4c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | Node type / split-axis index (low 16 bits: >=0 interior, <0 leaf) |
| this | 0xA | R | — | Split axis direction index (signed 16-bit, indexes into axis tables) |
| this | 0xC | R | — | Split sign flag (0 = positive direction, non-zero = negative) |
| this | 0x10 | R | — | Child pointer / surface pointer (index 3 in double* array) |
| this | 0x1C | R | — | Child bounding box min (float at offset 4 of child float array) |
| this | 0x20 | R | — | Child pointer for next sibling (index 4 in double* array) |
| this | 0x24 | R | — | Next child bounding box max (float at offset 1 of next child float array) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007ca3a4 | unk_7CA3A4 | R | CollisionRestitutionTable [DERIVED] (also: ` — restitution/response table) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0044a070 | QuadraticSurfaceCollisionTest | Test ray against a quadratic surface and update closest-hit data |
| 0044aa30 | BVHTreeTraversal | Recursive self-call to traverse child subtree |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x8 | == | 18446744073709551614 | Full 64-bit sentinel at 0x8 matching 0xFFFFFFFFFFFFFFFE (-2), checked as word 0xFFFE |

**Guard interpretation:** Word at 0x8 < 0 identifies leaf nodes (PASS: surface test). Word at 0x8 == 0xFFFE identifies a special leaf with two surfaces (PASS: test primary surface at v2[3], then secondary at v2[3]+92). Word at 0x8 >= 0 identifies interior node (PASS: compute split plane, recurse into overlapping children; BLOCK child traversal when query split value falls outside child bounding box).
