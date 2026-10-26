## PlaneFromEdgesNormalizeSSE_0052098e — SSEPlaneFromThreePointsB

**Summary:** Constructs a plane equation from three 3D points (a2, a3, a4) using SSE intrinsics. Algorithm is identical to PlaneFromThreePoints_0051f89e but uses distinct global constants (xmmword_5D8C30/40/50). Computes edge vectors, cross product (normal), Newton-Raphson normal refinement, and plane distance D. Stores result as (Nx, Ny, Nz, D) in output __m128. Part of SSE math library.

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
| 005d8c30 | xmmword_5D8C30 | R | Sign-flip XOR mask for plane D component |
| 005d8c40 | xmmword_5D8C40 | R | Newton-Raphson refinement coefficient (0.5) |
| 005d8c50 | xmmword_5D8C50 | R | Normalization scale constant |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard — always computes plane from three points unconditionally.
