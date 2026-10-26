## CameraViewSetupFromVehiclePosition_0045af50 — CameraFrustumSetupFromVehicle

**Summary:** Computes camera view frustum dimensions from vehicle bounding box. Calculates half-width and half-height from bounding box extents plus distance ratio offset, stores frustum size at offsets 0x318/0x320, computes diagonal distance at 0xCC, initializes 9 view-frustum structures with zeroed positions, then allocates vertex/particle render buffer.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x28 | R | — | double divisor for distance ratio computation |
| this | 0x50 | RW | 9 | view count / frustum plane count, initialized to 9 |
| this | 0x58 | R | — | start of 9x3-DWORD view frustum plane structures |
| this | 0x5C | RW | 0 | second DWORD of first view plane structure (zeroed each frame) |
| this | 0xCC | RW | — | diagonal distance = sqrt(halfWidth² + halfHeight²) |
| this | 0x180 | R | — | double numerator for distance ratio |
| this | 0x318 | RW | — | computed frustum half-width |
| this | 0x320 | RW | — | computed frustum half-height |

**Written-by note (persistence):**
- this 0x50: written to 9 every call. External poke overwritten.
- this 0x5C: zeroed every call. External poke overwritten.
- this 0xCC: recomputed every call from frustum dimensions. External poke overwritten.
- this 0x318: recomputed every call from bounding box + ratio. External poke overwritten.
- this 0x320: recomputed every call from bounding box + ratio. External poke overwritten.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e880 | dbl_59E880 | R | HalfStep [DERIVED] (also: ` — lower threshold constant) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004dd550 | BoundingBoxComputation | compute 3D bounding box extents (min/max X, Y, Z) into v15[0..5] |
| 0054f830 | VertexParticleBufferAllocator | allocate render buffer for vertices/particles based on view count |

**Guard conditions:** No early exit guards. Second loop (rebuild view structures) checks v7 > 0 before iterating (v7 = count 9 set earlier). First loop uses count from this[0x50] (which was just set to 9).
