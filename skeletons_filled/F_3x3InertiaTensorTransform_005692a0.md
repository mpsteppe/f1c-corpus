## F_3x3InertiaTensorTransform_005692a0 — TransformDiagonalInertiaToWorld

**Summary:** Transforms a diagonal inertia tensor from local to world space using the rotation matrix R: computes R * I * R^T where I is diagonal (elements at offsets 0xD4, 0xDC, 0xE4) and R is the 3x3 rotation matrix at offsets 0x1C-0x5C. Exploits symmetry by computing upper triangle then copying to lower triangle.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** SuspensionDataCopyToPhysicsEngine (004389b0), VehiclePhysicsIntegrationStep (00441650), sub_447780 (00447780), F_3x3RotationTensorMatrixTransform (005691d0), sub_569C10 (00569c10), sub_569DE0 (00569de0), VehiclePhysicsStateCopyTransform (0056a150)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1C | R | — | rotation matrix row 0 col 0 |
| this | 0x24 | R | — | rotation matrix row 0 col 1 |
| this | 0x2C | R | — | rotation matrix row 0 col 2 |
| this | 0x34 | R | — | rotation matrix row 1 col 0 |
| this | 0x3C | R | — | rotation matrix row 1 col 1 |
| this | 0x44 | R | — | rotation matrix row 1 col 2 |
| this | 0x4C | R | — | rotation matrix row 2 col 0 |
| this | 0x54 | R | — | rotation matrix row 2 col 1 |
| this | 0x5C | R | — | rotation matrix row 2 col 2 |
| this | 0xD4 | R | — | inertia diagonal X (Ixx) |
| this | 0xDC | R | — | inertia diagonal Y (Iyy) |
| this | 0xE4 | R | — | inertia diagonal Z (Izz) |
| this | 0xEC | RW | — | world-space inertia (0,0) element |
| this | 0xF4 | RW | — | world-space inertia (0,1) element |
| this | 0xF8 | R | — | (0,1) high word, read for symmetric copy |
| this | 0xFC | RW | — | world-space inertia (0,2) element |
| this | 0x100 | R | — | (0,2) high word, read for symmetric copy |
| this | 0x104 | RW | — | world-space inertia (1,0) element (copied from 0,1) |
| this | 0x108 | RW | — | world-space inertia (1,0) high word (copied) |
| this | 0x10C | RW | — | world-space inertia (1,1) element |
| this | 0x114 | RW | — | world-space inertia (1,2) element |
| this | 0x118 | R | — | (1,2) high word, read for symmetric copy |
| this | 0x11C | RW | — | world-space inertia (2,0) element (copied from 0,2) |
| this | 0x120 | RW | — | world-space inertia (2,0) high word (copied) |
| this | 0x124 | RW | — | world-space inertia (2,1) element (copied from 1,2) |
| this | 0x128 | RW | — | world-space inertia (2,1) high word (copied) |
| this | 0x12C | RW | — | world-space inertia (2,2) element |

**Written-by note (persistence):**
- this 0xEC: recalc every frame — external poke does NOT persist
- this 0xF4: recalc every frame — external poke does NOT persist
- this 0xFC: recalc every frame — external poke does NOT persist
- this 0x104: recalc every frame — external poke does NOT persist
- this 0x108: recalc every frame — external poke does NOT persist
- this 0x10C: recalc every frame — external poke does NOT persist
- this 0x114: recalc every frame — external poke does NOT persist
- this 0x11C: recalc every frame — external poke does NOT persist
- this 0x120: recalc every frame — external poke does NOT persist
- this 0x124: recalc every frame — external poke does NOT persist
- this 0x128: recalc every frame — external poke does NOT persist
- this 0x12C: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional computation, no branches or early returns.
