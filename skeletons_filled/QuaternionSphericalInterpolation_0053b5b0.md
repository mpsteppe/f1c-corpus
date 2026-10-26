## QuaternionSphericalInterpolation_0053b5b0 — QuaternionSLERP

**Summary:** Performs spherical linear interpolation (SLERP) between two quaternions. Computes dot product, handles shortest-path negation, and blends either via trigonometric SLERP (sin-based) or linear approximation for small angles. Part of 3D math/quaternion library.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_551210 (00551210)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | result quaternion w component |
| this | 0x4 | RW | — | result quaternion x component |
| this | 0x8 | RW | — | result quaternion y component |
| this | 0xC | RW | — | result quaternion z component |

**Written-by note (persistence):**
- this 0x0: recalc every frame — external poke does NOT persist
- this 0x4: recalc every frame — external poke does NOT persist
- this 0x8: recalc every frame — external poke does NOT persist
- this 0xC: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e6ec | flt_59E6EC | R | ShortIntToWorldScale [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005894a0 | FloatFunctionPassThrough | unknown, called before sin computation (FPU state check or interrupt dispatch) |

**Guard conditions:**
- Dot product >= 0: use source quaternion a3 directly
- Dot product < 0: negate source quaternion a3 (shortest-path on hypersphere)
- `1.0 - dot > 0.02`: full SLERP using sin-based interpolation with FloatFunctionPassThrough
- `1.0 - dot <= 0.02`: linear interpolation (small angle approximation, avoids near-zero sin division)
