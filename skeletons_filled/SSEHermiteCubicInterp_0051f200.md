## SSEHermiteCubicInterp_0051f200 — SSEHermiteCubicInterpolation

**Summary:** Performs Hermite cubic interpolation between 4 input float pairs (a4-a7) using SSE intrinsics. Evaluates cubic basis functions via precomputed spline coefficients (xmmword_5D8A50/60/70/80) at parameter t (a8), blends inputs, and stores interleaved result at output pointer a3. Part of SSE-accelerated spline interpolation library.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d8a50 | xmmword_5D8A50 | R | Cubic Hermite basis coefficient (t^3 term) |
| 005d8a60 | xmmword_5D8A60 | R | Cubic Hermite basis constant term |
| 005d8a70 | xmmword_5D8A70 | R | Cubic Hermite basis coefficient (t^2 term) |
| 005d8a80 | xmmword_5D8A80 | R | Cubic Hermite basis coefficient (t term) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard — always computes interpolation unconditionally.
