## SIMDQuaternionRotationArithmetic_00524553 — QuaternionRotationMatrixSIMD

**Summary:** Build 4x4 rotation matrix from quaternion and angle scalar using 3DNow! SIMD intrinsics (pfmul, pfadd, pfsub, punpck). Core 3D math routine for transform system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Output matrix row 0 (two floats) |
| this | 0x8 | R | — | Input quaternion x component (low 32 bits read) |
| this | 0x10 | R | — | Input quaternion y component |
| this | 0x18 | R | — | Input quaternion z component |
| this | 0x20 | R | — | Input quaternion w component / angle-related packed float |
| this | 0x28 | R | — | Quaternion multiplication intermediate data |
| this | 0x30 | R | — | Quaternion multiplication intermediate data |
| this | 0x38 | R | — | Quaternion multiplication intermediate data |

**Written-by note (persistence):**
- this 0x0: Fully overwritten every call (all 8 __m64 slots from a1[0] to a1[7]); external poke would not survive

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005af900 | qword_5AF900 | R | AngleConstantPair1 [DERIVED] (also: ` — SIMD constant (likely PI or angle scalar) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005262c2 | sub_5262C2 | 64-bit packed float normalization/reduction on quaternion data in-place |
| 005295e0 | PackedFloatingPointMath | 3DNow! trigonometric helper (sin/cos approximation for the angle parameter) |

**Guard conditions:** None — no conditional branches; all inputs processed unconditionally.
