## EulerAngleToRotationMatrix_0053b240 — EulerToRotationMatrix3x3

**Summary:** Converts three Euler angles into a 3x3 rotation matrix stored as 15 float fields. Uses sin/cos trigonometric functions for each angle and computes cross-product terms for the rotation matrix. Part of 3D transformation/math library.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_54B570 (0054b570), VertexBufferTransform (0054c6c0), sub_558E70 (00558e70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x10 | RW | — | angle A (a2) stored as float, also used for cos/sin |
| this | 0x14 | RW | — | angle B (a3) stored as float, also used for cos/sin |
| this | 0x18 | RW | — | angle C (a4) stored as float, also used for cos/sin |
| this | 0x28 | RW | — | rotation matrix element [0][0] |
| this | 0x2C | RW | — | rotation matrix element [0][1] |
| this | 0x30 | RW | — | rotation matrix element [0][2] |
| this | 0x34 | RW | 0 | rotation matrix element [0][3] = 0 |
| this | 0x38 | RW | — | rotation matrix element [1][0] |
| this | 0x3C | RW | — | rotation matrix element [1][1] |
| this | 0x40 | RW | — | rotation matrix element [1][2] |
| this | 0x44 | RW | 0 | rotation matrix element [1][3] = 0 |
| this | 0x48 | RW | — | rotation matrix element [2][0] |
| this | 0x4C | RW | — | rotation matrix element [2][1] |
| this | 0x50 | RW | — | rotation matrix element [2][2] |
| this | 0x54 | RW | 0 | rotation matrix element [2][3] = 0 |

**Written-by note (persistence):**
- this 0x10: recalc every frame — external poke does NOT persist
- this 0x14: recalc every frame — external poke does NOT persist
- this 0x18: recalc every frame — external poke does NOT persist
- this 0x28: recalc every frame — external poke does NOT persist
- this 0x2C: recalc every frame — external poke does NOT persist
- this 0x30: recalc every frame — external poke does NOT persist
- this 0x34: recalc every frame — external poke does NOT persist
- this 0x38: recalc every frame — external poke does NOT persist
- this 0x3C: recalc every frame — external poke does NOT persist
- this 0x40: recalc every frame — external poke does NOT persist
- this 0x44: recalc every frame — external poke does NOT persist
- this 0x48: recalc every frame — external poke does NOT persist
- this 0x4C: recalc every frame — external poke does NOT persist
- this 0x50: recalc every frame — external poke does NOT persist
- this 0x54: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005b8960 | dbl_5B8960 | R | PhysicsDouble_5B8960 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058957a | InterruptDispatch | unknown, called before each angle store (FPU state check or interrupt dispatch) |

**Guard conditions:** No guard conditions — function always executes fully.
