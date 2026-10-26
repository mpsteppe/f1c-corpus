## QuaternionProduct3DNow_0052704a — QuaternionProduct3DNow

**Summary:** Compute quaternion product using 3DNow! SIMD packed float arithmetic. Combines two input quaternions with cross-product-like terms via pfsub, pfmul, pfacc operations with sign-flip constants.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Quaternion component pair (w,x) — read from a2[0], written to a1[0] |
| this | 0x8 | R | — | Quaternion component (y,z) — read from a2[1], a3[1], a4[1] as input |

**Written-by note (persistence):**
- this 0x0: Written every call (full 64-bit write to a1[0]); external poke would not survive

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005af980 | qword_5AF980 | R | SIMD_Const_5AF980 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — no conditional branches; all inputs processed unconditionally.
