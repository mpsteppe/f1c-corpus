## QuatNormalize_0050decf — Quaternion normalization (unit-length)

**Summary:** Normalizes a quaternion `a2` to unit length and writes result to `a1`. Skips computation if already unit-length (within FloatRangeCheck), zeroes output if norm is below FLT_MIN.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Quaternion x (read from source, written normalized) |
| this | 0x4 | RW | — | Quaternion y (read from source, written normalized) |
| this | 0x8 | RW | — | Quaternion z (read from source, written normalized) |
| this | 0xC | RW | — | Quaternion w (read from source, written normalized) |

**Written-by note (persistence):**
- this 0x0: unconditional write every call (zero, normalized, or copy) — external poke does not survive
- this 0x4: unconditional write every call — external poke does not survive
- this 0x8: unconditional write every call — external poke does not survive
- this 0xC: unconditional write every call — external poke does not survive

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 005ade40 | flt_5ADE40 | R | NearZeroEpsilonPtr [DERIVED] (also: small threshold pointer (near-zero) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0050c042 | FloatRangeCheck | Checks if squared norm is approximately 1.0 (within epsilon) to skip normalization |

**Guard conditions:** If `FloatRangeCheck(sq_norm, 1.0)` returns true, the quaternion is already unit-length — only a copy (or no-op if same buffer) is performed. If `sq_norm <= 1.1754944e-38` (FLT_MIN), output is zeroed (degenerate fallback). The normalize-with-rsqrt path runs only for intermediate squared norms.
