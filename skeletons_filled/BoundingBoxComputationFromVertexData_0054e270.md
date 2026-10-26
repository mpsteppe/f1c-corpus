## BoundingBoxComputationFromVertexData_0054e270 — Oriented bounding box and sphere from vertex data

**Summary:** Computes oriented bounding box (via covariance matrix and QR decomposition for OBB axes) and bounding sphere radius from mesh vertex data. Accumulates vertex statistics, transforms AABB corners through D3D matrix, and stores sphere radius at offset 0x18.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** GlobalVectorOffsetUpdate (0040e1f0), PhysicsAudioVectorUpdate (004e2ad0), VertexBufferTransform (0054c6c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x11C) | 0x8 | R | — | Per-mesh vertex count |
| *(this+0x11C) | 0xC | R | — | Per-mesh vertex data pointer |
| *(this+0x11C) | 0x10 | R | — | Per-mesh element stride info |
| *(this+0x11C) | 0x14 | R | — | Per-mesh additional stride info |
| this | 0x14 | R | — | Flags (MMX stride bit 0x800000 selects 64 vs 48-byte stride) |
| this | 0x18 | RW | — | Bounding sphere radius (sqrt of max squared distance) |
| this | 0xDC | R | — | Mean X (center) from vertex accumulation |
| this | 0xE0 | R | — | Mean Y (center) from vertex accumulation |
| this | 0xE4 | R | — | Mean Z (center) from vertex accumulation |
| this | 0x118 | R | — | Mesh count (number of mesh elements) |
| this | 0x11C | R | — | Pointer to mesh data array (stride 64 bytes) |

**Written-by note (persistence):**
- this 0x18: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |
| 00800000 | unk_800000 | R | MMXFlag [DERIVED] |
| 008b8f24 | dword_8B8F24 | R | D3DDeviceWrapperPtr [DERIVED] (also: ` — D3D device wrapper / scene manager singleton vtable (docs/22) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0053b6f0 | QRDecomposition | Computes eigenvalues/eigenvectors from 3x3 covariance matrix for OBB axes |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(this+0x11C) | 0x8 | > | 0 | Per-mesh vertex count — must be positive to process vertices |

**Guard interpretation:** If `*(this+0x11C)+0x8` (vertex count in first mesh) ≤ 0 → skip vertex accumulation (first loop). If `this[0x118]` (mesh count) ≤ 0 → skip AABB computation and final bounding sphere iteration. Both must pass for full computation.
