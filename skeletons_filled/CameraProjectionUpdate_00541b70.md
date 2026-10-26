## CameraProjectionUpdate_00541b70 — Update camera projection and view matrices

**Summary:** Builds a camera projection matrix (perspective or orthographic) and/or view matrix based on flag bits in a2. Uses near/far plane (0x4, 0x8), FOV (0x1C), aspect ratio (0x20), and flags at 0x80 to compute the transform via D3D device wrapper.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ViewportRectangleRenderSetup (0048e750), SceneRenderTransform (00548c20), sub_5550E0 (005550e0), sub_556E70 (00556e70), sub_560FE0 (00560fe0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | near clipping plane distance |
| this | 0x8 | R | — | far clipping plane distance |
| this | 0x1C | R | — | field of view (1/value used in projection) |
| this | 0x20 | R | — | aspect ratio (1/value used in projection) |
| this | 0x80 | R | — | camera flags (bit 4 tested for FOV sign flip) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (double constant 1.0) |
| 008b78a0 | dword_8B78A0 | R | SoundManager [DERIVED] |
| 008b8f24 | dword_8B8F24 | R | D3DDeviceWrapperPtr [DERIVED] (D3D device wrapper / scene manager for matrix upload) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0053ac70 | EmptyStubWithFlagCheck | debug/stub marker call before and after projection matrix build |
| 0055ca40 | EnumToVTableCallMapper | dispatch matrix data to D3D (4=projection, 2=view) |
| 0055cc20 | sub_55CC20 | additional camera update when a2 bit 3 (8) is set |

**Guard conditions:** Execution gated by a2 flag bits: bit 2 (4) triggers projection update; bit 1 (2) triggers view update; bit 3 (8) triggers sub_55CC20. Sub-checks within projection: a2 bit 4 (0x10) selects orthographic vs perspective mode.
