## QuadrilinearInterp3DNow_00526466 — QuarticInterp3DNow

**Summary:** Compute quadrilinear (quartic) interpolation between 4 control points using 3DNow! SIMD. Evaluates higher-order weight coefficients from factor t, blends packed float values from 4 input vectors, scales result by 0.5.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Output interpolated float pair (a1[0] = full 64-bit write) |
| this | 0x8 | R | — | Input control point data at offset 8 (a2[1]/a3[1]/a4[1]/a5[1] low 32 bits read) |

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
