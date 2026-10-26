## PlaneFromThreePoints_0051f89e — SSEPlaneFromThreePoints

**Summary:** Constructs a plane equation from three 3D points (a2, a3, a4) using SSE intrinsics. Computes two edge vectors, their cross product (plane normal), normalizes with Newton-Raphson refinement, and calculates plane distance D from dot product with point A. Stores plane as (Nx, Ny, Nz, D) in output __m128. Part of SSE math library.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Output plane (normal X, normal Y, normal Z, D) |
| this | 0x4 | R | — | unknown |

**Written-by note (persistence):**
- this 0x0: unconditionally written with plane equation; persists as output

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d8ad0 | xmmword_5D8AD0 | R | Sign-flip XOR mask for plane D component |
| 005d8ae0 | xmmword_5D8AE0 | R | Newton-Raphson refinement coefficient (0.5) |
| 005d8af0 | xmmword_5D8AF0 | R | Normalization scale constant |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard — always computes plane from three points unconditionally.
