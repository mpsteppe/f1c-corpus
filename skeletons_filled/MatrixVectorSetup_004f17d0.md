## MatrixVectorSetup_004f17d0 — MatrixVectorSetup

**Summary:** Copies a 3x3 rotation matrix and input vector, computes their product, stores result. Part of vehicle physics/matrix transformation system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehiclePhysicsTimeStep (004c73f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x34B0 | R | — | Rotation matrix [0][0] (copied from a2) |
| this | 0x34B4 | R | — | Rotation matrix [0][1] |
| this | 0x34B8 | R | — | elapsedTime (alt) [CONFIRMED] |
| this | 0x34BC | R | — | Rotation matrix [1][0] |
| this | 0x34C0 | R | — | Rotation matrix [1][1] |
| this | 0x34C4 | R | — | Rotation matrix [1][2] |
| this | 0x34C8 | R | — | Rotation matrix [2][0] |
| this | 0x34CC | R | — | Rotation matrix [2][1] |
| this | 0x34D0 | R | — | Rotation matrix [2][2] |
| this | 0x3534 | RW | — | Input vector X (copied from a3[0]) |
| this | 0x3538 | RW | — | Input vector Y (copied from a3[1]) |
| this | 0x353C | RW | — | Input vector Z (copied from a3[2]) |
| this | 0x3540 | RW | — | Output vector X (rotation * input, computed) |
| this | 0x3544 | RW | — | Output vector Y |
| this | 0x3548 | RW | — | Output vector Z |

**Written-by note (persistence):**
- this 0x3534: recalc every frame — external poke does NOT persist
- this 0x3538: recalc every frame — external poke does NOT persist
- this 0x353C: recalc every frame — external poke does NOT persist
- this 0x3540: recalc every frame — external poke does NOT persist
- this 0x3544: recalc every frame — external poke does NOT persist
- this 0x3548: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — always copies data and computes matrix-vector product.
