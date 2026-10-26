## CubicSpline_0051f400 — SSECubicSplineInterpolation

**Summary:** Performs cubic B-spline interpolation between 4 input float pairs (a4-a7) using SSE intrinsics. Evaluates cubic polynomial basis at parameter t (a8) with precomputed spline coefficients (xmmword_5D8A90/AA0/AB0/AC0), blends inputs, and stores interleaved result at output pointer a3. Part of SSE-accelerated spline library.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d8a90 | xmmword_5D8A90 | R | Cubic B-spline basis coefficient (t^3 term) |
| 005d8aa0 | dword_5D8AA0 | R | Cubic B-spline polynomial bias (constant offset) |
| 005d8ab0 | xmmword_5D8AB0 | R | Cubic B-spline basis coefficient (t^2 term) |
| 005d8ac0 | xmmword_5D8AC0 | R | Cubic B-spline basis coefficient (t term) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard — always computes interpolation unconditionally.
