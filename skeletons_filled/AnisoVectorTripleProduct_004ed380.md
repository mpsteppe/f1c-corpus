## AnisoVectorTripleProduct_004ed380 — anisotropic scalar triple product

**Summary:** Computes anisotropic triple product (cross product scaled by per-axis factors, then dotted with second vector) with bias. Part of anisotropic force/spring computation.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehicleGeometryProximityTest (004ed420)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x3518 | R | — | bias term added to final result |
| this | 0x3528 | R | — | anisotropic scaling factor X for cross product |
| this | 0x352C | R | — | anisotropic scaling factor Y for cross product |
| this | 0x3530 | R | — | anisotropic scaling factor Z for cross product |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — always computes full anisotropic triple product.
