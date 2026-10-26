## EulerAnglesTo33RotationMatrix_0056bd40 — EulerAnglesToRotationMatrix

**Summary:** Converts Euler angles (x, y, z) from a2 to a 3x3 rotation matrix stored at `this`. Uses standard sin/cos trigonometric rotation formula. Part of vehicle physics orientation math.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** SuspensionSetupSectionReader (00435410), SuspensionDataCopyToPhysicsEngine (004389b0), VehiclePhysicsInitializer (00439210), RigidBodyConstraintSolve (0043e4b0), F_3x3RotationTensorMatrixTransform (005691d0), sub_56F100 (0056f100)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | rotation matrix row 0 col 0 |
| this | 0x8 | RW | — | rotation matrix row 0 col 1 |
| this | 0x10 | RW | — | rotation matrix row 0 col 2 |
| this | 0x18 | RW | — | rotation matrix row 1 col 0 |
| this | 0x20 | RW | — | rotation matrix row 1 col 1 |
| this | 0x28 | RW | — | rotation matrix row 1 col 2 |
| this | 0x30 | RW | — | rotation matrix row 2 col 0 |
| this | 0x38 | RW | — | rotation matrix row 2 col 1 |
| this | 0x40 | RW | — | rotation matrix row 2 col 2 |

**Written-by note (persistence):**
- this 0x0: recalc every frame — external poke does NOT persist
- this 0x8: recalc every frame — external poke does NOT persist
- this 0x10: recalc every frame — external poke does NOT persist
- this 0x18: recalc every frame — external poke does NOT persist
- this 0x20: recalc every frame — external poke does NOT persist
- this 0x28: recalc every frame — external poke does NOT persist
- this 0x30: recalc every frame — external poke does NOT persist
- this 0x38: recalc every frame — external poke does NOT persist
- this 0x40: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard — always executes fully with no early-return branches.
