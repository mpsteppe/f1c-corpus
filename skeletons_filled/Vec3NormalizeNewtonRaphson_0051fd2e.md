## Vec3NormalizeNewtonRaphson_0051fd2e — Vec3ScaleByReciprocalSqLenNR

**Summary:** Computes squared length of a 3-component vector loaded from a2, calculates refined reciprocal via Newton-Raphson (1/x), scales vector components by this reciprocal, applies Z sign-flip mask (xmmword_5D8C00), and stores result in output (a1). Part of SSE math library; may be used for cross-product or special vector orientation rather than standard normalization.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Output __m128 result (scaled vector with sign-flipped Z) |

**Written-by note (persistence):**
- this 0x0: unconditionally written with scaled vector; persists as output

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d8c00 | xmmword_5D8C00 | R | SSE sign mask to negate Z component |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard — always computes result unconditionally.
