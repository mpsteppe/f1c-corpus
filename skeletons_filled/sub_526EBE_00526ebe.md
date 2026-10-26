## sub_526EBE_00526ebe — QuarticInterpPacked

**Summary:** Quartic/quadrilinear interpolation of packed float pairs using 3DNow! SIMD. Computes higher-order weight coefficients from factor t, blends 4 control points (a2-a5), scales result by 0.5.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Output interpolated float pair (a1[0] = full 64-bit write) |

**Written-by note (persistence):**
- this 0x0: Written every call (all 64 bits); external poke would not survive

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005af900 | qword_5AF900 | R | AngleConstantPair1 [DERIVED] (also: ` — SIMD constant (likely PI or angle scalar) |
| 005af910 | qword_5AF910 | R | SIMDMathConst [DERIVED] |
| 005af920 | qword_5AF920 | R | MMXSignFlipConst [DERIVED] |
| 005af968 | qword_5AF968 | R | ThreeDNow_Constant_5AF968 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — no conditional branches; all inputs processed unconditionally.
