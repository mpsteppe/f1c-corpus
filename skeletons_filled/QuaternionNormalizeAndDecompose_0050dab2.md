## QuaternionNormalizeAndDecompose_0050dab2 — Quaternion normalize-and-decompose — normalized vector part and scaled scalar

**Summary:** Normalizes a quaternion (x,y,z,w) and decomposes it: writes normalized vector part (x,y,z) into `a2` and twice the scalar part (2*w) into `a3`. Falls back to identity on degenerate (near-zero) quaternion.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Quaternion x component (vector part) |
| this | 0x4 | R | — | Quaternion y component (vector part) |
| this | 0x8 | R | — | Quaternion z component (vector part) |
| this | 0xC | R | — | Quaternion w component (scalar part) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 005ade40 | flt_5ADE40 | R | NearZeroEpsilonPtr [DERIVED] (also: small threshold pointer (near-zero) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005894a0 | FloatFunctionPassThrough | Called before computing `*a3 = 2*w`; actual effect unclear (may modify floating-point state or be a no-op) |

**Guard conditions:** If squared norm `x²+y²+z²+w² <= 1.1754944e-38` (FLT_MIN), the quaternion is treated as degenerate: `a2` set to {1,0,0} identity direction and `a3` set to 0.0. The normalization/angle-extraction path is skipped.
