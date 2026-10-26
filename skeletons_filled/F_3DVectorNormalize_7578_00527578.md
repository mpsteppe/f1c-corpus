## F_3DVectorNormalize_7578_00527578 — F_3DVectorNormalize4

**Summary:** Normalize 4-component vector (x,y,z,w) using 3DNow! SIMD. Computes squared length via pfmul+pfacc, reciprocal sqrt with Newton-Raphson refinement, zero-guard against near-zero length.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** F_3DNowQuaternionFromAngle (0052278b), QuaternionTo4x4RotationMatrix (00522876)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Output normalized first component pair (x,y) — a1[0] = a2[0] * rsqrt(length²) |
| this | 0x8 | R | — | Input second component pair (z,w) — a2[1] read, z component squared added to length |

**Written-by note (persistence):**
- this 0x0: Written every call (full 64-bit); zeroed if guard triggers; external poke would not survive

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005af950 | qword_5AF950 | R | SIMDQuadMask [DERIVED] |
| 005af970 | qword_5AF970 | R | VectorLengthSquaredThreshold [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Packed comparison of squared length (v5 = pfacc of component squares) against threshold 0x0080000000800000 (~1.17e-38). If length² > threshold: normalize via rsqrt+Newton, store to a1[0] and a1[1]. If length² <= threshold: output zeroed (pand with zero mask).
