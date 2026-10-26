## VectorNormalization_0050e887 — 3D vector normalization with degenerate fallback

**Summary:** Normalizes a 3D vector `a2` to unit length, writing result to `a1`. Skips normalization if already unit-length; zeroes output if squared length is below FLT_MIN.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Vector X component |
| this | 0x4 | RW | — | Vector Y component |
| this | 0x8 | RW | — | Vector Z component |

**Written-by note (persistence):**
- this 0x0: unconditional write (zero, normalized, or copy) every call — external poke does not survive
- this 0x4: unconditional write every call — external poke does not survive
- this 0x8: unconditional write every call — external poke does not survive

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 005ade40 | flt_5ADE40 | R | NearZeroEpsilonPtr [DERIVED] (also: small threshold pointer (near-zero) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0050c042 | FloatRangeCheck | Checks if squared length is approximately 1.0 to skip normalization |

**Guard conditions:** If `FloatRangeCheck(sq_len, 1.0)` returns true (already unit-length), the vector is copied verbatim. If `sq_len <= 1.1754944e-38` (FLT_MIN), all three components are zeroed (degenerate fallback). Otherwise compute `1/sqrt(sq_len)` for normalization.
