## RigidBodyConstraintSolve_0043e4b0 — Rigid body constraint position solve

**Summary:** Computes position error between current and target pose using Euler-angle rotation matrix and body position, then applies constraint correction. Initializes wheel constraint state entries with default disabled values. Part of AI vehicle path tracking.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AIVehiclePathPositionTracking (004ef7c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xB4 | RW | 0 | Cleared constraint enable flag |
| this | 0x3A8 | RW | 18446744073709551615 | Wheel constraint init value (-1, all bits set) |
| this | 0x3AC | RW | 18446744073708503039 | Wheel constraint init value (-1048577) |
| this | 0x15F0 | R | — | Pointer to body struct for position/rotation data |
| this | 0x15FC | R | — | Body position X component |
| this | 0x1604 | R | — | Body position Y component |
| this | 0x160C | R | — | Body position Z component |

**Written-by note (persistence):**
- this 0xB4: recalc every frame — external poke does NOT persist
- this 0x3A8: recalc every frame — external poke does NOT persist
- this 0x3AC: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00567740 | FPUControlWordMaskExtract | Save FPU control word for later restore |
| 00567780 | EmptyStub_7780 | Restore FPU control word if changed |
| 0056bd40 | EulerAnglesTo33RotationMatrix | Convert Euler angles to 3x3 rotation matrix |
| 0056f100 | sub_56F100 | Apply constraint correction from position error |

**Guard conditions:** If FPU control word changed (!= 512), restore via EmptyStub_7780.
