## QuaternionConjugateAndNormalize_0050df9b — Quaternion conjugate and normalize

**Summary:** Computes conjugate (negate vector part x,y,z) of input quaternion `a2`, then normalizes to unit length. Writes result to `a1`. Skips normalization if already unit-length within tolerance; zeroes output if norm is below ultra-small threshold.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Quaternion x (negated, then normalized) |
| this | 0x4 | RW | — | Quaternion y (negated, then normalized) |
| this | 0x8 | RW | — | Quaternion z (negated, then normalized) |
| this | 0xC | RW | — | Quaternion w (unchanged sign, then normalized) |

**Written-by note (persistence):**
- this 0x0: unconditional write every call — external poke does not survive
- this 0x4: unconditional write every call — external poke does not survive
- this 0x8: unconditional write every call — external poke does not survive
- this 0xC: unconditional write every call — external poke does not survive

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ade44 | flt_5ADE44 | R | Unknown_Float_QuatThreshold [DERIVED] (also: ` — zero-length epsilon) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0050c042 | FloatRangeCheck | Checks if squared norm is approximately 1.0 to skip normalization scaling |

**Guard conditions:** If squared norm `<= 1.0842022e-19` (near-zero threshold), all four output components are set to 0.0 (degenerate quaternion). If `FloatRangeCheck(sq_norm, 1.0)` returns true, only negation is applied without scaling (already unit-length). Otherwise, conjugate is followed by reciprocal-of-norm scaling.
