## F_3DVectorNegateAndNormalize_00521831 — 3DNow! negate and divide by squared-length with zero guard

**Summary:** Computes squared length of 3DNow! vector a2 via pfadd/pfmul, inverts it with pfrcp + Newton-Raphson refinement (pfrcpit1/pfrcpit2), negates input components with XOR 0x80000000 sign flip, masks with threshold comparison, and writes (-a2) * (1/length²) to a1.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | First half of output (xy components of negated/scaled vector) |
| this | 0x8 | R | — | Second half of output (zw components of negated/scaled vector) |

**Written-by note (persistence):**
- this 0x0: Written once at function end; purely output, no persistence.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005af918 | qword_5AF918 | R | MMX_PackedConstant [DERIVED] |
| 005af970 | qword_5AF970 | R | VectorLengthSquaredThreshold [DERIVED] |
| 005af9d0 | qword_5AF9D0 | R | SIMD_Mask3DNow [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** `v7 = pfcmpgt(v4, 0x80000000800000LL)` checks if squared length > threshold. BLOCKED (length² <= threshold): pand mask zeroes output (avoids division by near-zero). PASSES (length² > threshold): output = negated_input * reciprocal(length²).
