## TransformWheelForcesToChassis_00541a70 — Transform wheel suspension forces to chassis frame

**Summary:** Copies a 4×4 rotation matrix from offset 0x15C, then iterates over 6 wheels (each 16 bytes starting at 0x104) transforming suspension forces via D3D device wrapper. Accumulates chassis position offset (0x24, 0x28, 0x2C) into the result.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SceneRenderTransform (00548c20), sub_556E70 (00556e70), sub_560FE0 (00560fe0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x24 | R | — | chassis position X component |
| this | 0x28 | R | — | chassis position Y component |
| this | 0x2C | R | — | chassis position Z component |
| this | 0x104 | R | — | start of per-wheel suspension data array (6 wheels, 16 bytes each) |
| this | 0x15C | R | — | 4×4 rotation matrix for wheel-to-chassis coordinate transform |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008b8f24 | dword_8B8F24 | R | D3DDeviceWrapperPtr [DERIVED] (also: D3D device wrapper / scene manager for coordinate transforms) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — always executes. No early return or conditional skip.
