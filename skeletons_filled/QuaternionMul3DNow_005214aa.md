## QuaternionMul3DNow_005214aa — 3DNow! quaternion multiply with 0.5 scaling

**Summary:** Multiplies two quaternions (a2, a3 as __m64 pairs) using 3DNow! intrinsics: pre-scales both by 0.5 (0x3F0000003F000000LL), calls PackedFloatingPointMath three times for component setup, then computes quaternion product via pfadd/pfmul with sign-flip XOR (0x8000000000000000). Writes result to a1.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | First half of output quaternion (xy) |
| this | 0x8 | R | — | Second half of output quaternion (zw) |

**Written-by note (persistence):**
- this 0x0: Written once at function end; purely output, no persistence.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005af980 | qword_5AF980 | R | SIMD_Const_5AF980 [DERIVED] |
| 005af990 | qword_5AF990 | R | MMX_3DNow_QuadConstant_0 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005295e0 | PackedFloatingPointMath | Component setup/expansion helper for 3DNow! quaternion arithmetic |

**Guard conditions:** None — no conditional branches; always executes full multiply path.
