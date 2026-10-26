## UnidentifiedLogicFunctionTable_00516fb0 — MathFunctionTableInitializer

**Summary:** Populates a pre-allocated function pointer table (vtable-like dispatch table) with pointers to SIMD/SSE math library functions — vector normalization, spline interpolation, matrix multiplication, axis-angle conversion, and related utilities. Initialization/startup system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_50FEA7 (0050fea7)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | slot 0: sub_51EC00 — math utility entry |
| this | 0x4 | RW | — | slot 1: sub_51ECE0 — math utility entry |
| this | 0x8 | RW | — | slot 2: sub_520140 — math utility entry |
| this | 0xC | RW | — | slot 3: sub_520200 — math utility entry |
| this | 0x10 | RW | — | slot 4: sub_51EF50 — math utility entry |
| this | 0x14 | RW | — | slot 5: SSEWeightedVectorSum |
| this | 0x18 | RW | — | slot 6: sub_51FF80 — math utility entry |
| this | 0x1C | RW | — | slot 7: sub_51EDA0 — math utility entry |
| this | 0x20 | RW | — | slot 8: F_4ComponentVectorNormalize |
| this | 0x24 | RW | — | slot 9: sub_51EC40 — math utility entry |
| this | 0x28 | RW | — | slot 10: sub_520040 — math utility entry |
| this | 0x2C | RW | — | slot 11: sub_51F7C0 — math utility entry |
| this | 0x34 | RW | — | slot 13: sub_51F890 — math utility entry |
| this | 0x40 | RW | — | slot 16: sub_51F0B0 — math utility entry |
| this | 0x44 | RW | — | slot 17: HermiteSplineBasis |
| this | 0x48 | RW | — | slot 18: sub_520500 — math utility entry |
| this | 0x4C | RW | — | slot 19: RotMatrixMul3x3 |
| this | 0x50 | RW | — | slot 20: VectorNormalizeWithNewtonRaphsonRefinement |
| this | 0x54 | RW | — | slot 21: sub_51EE70 — math utility entry |
| this | 0x58 | RW | — | slot 22: NewtonRaphsonReciprocalWithVectorInterpolation |
| this | 0x60 | RW | — | slot 24: RotationMatrixToAxisAngleConversion |
| this | 0x64 | RW | — | slot 25: sub_51FEB0 — math utility entry |
| this | 0x6C | RW | — | slot 27: sub_51F980 — math utility entry |
| this | 0x70 | RW | — | slot 28: sub_51FB10 — math utility entry |
| this | 0xB0 | RW | — | slot 44: sub_51FD20 — math utility entry |
| this | 0xBC | RW | — | slot 47: SSECubicSplineInterpolation |
| this | 0xC0 | RW | — | slot 48: SSELinearInterpolationBetweenTwoPoints |
| this | 0xC4 | RW | — | slot 49: CubicSpline |
| this | 0xC8 | RW | — | slot 50: SSEHermiteCubicInterp |
| this | 0xCC | RW | — | slot 51: F_3VectorBlendLerp |
| this | 0xD0 | RW | — | slot 52: SSECubicBezierBernsteinPolynomialEvaluation |
| this | 0xD4 | RW | — | slot 53: SSECubicHermiteBasisFunctionEvaluation |
| this | 0xD8 | RW | — | slot 54: BilinearInterpolation_f650 |

**Written-by note (persistence):**
- this 0x0: written unconditionally on every call — external poke does NOT persist
- this 0x4: written unconditionally on every call — external poke does NOT persist
- this 0x8: written unconditionally on every call — external poke does NOT persist
- this 0xC: written unconditionally on every call — external poke does NOT persist
- this 0x10: written unconditionally on every call — external poke does NOT persist
- this 0x14: written unconditionally on every call — external poke does NOT persist
- this 0x18: written unconditionally on every call — external poke does NOT persist
- this 0x1C: written unconditionally on every call — external poke does NOT persist
- this 0x20: written unconditionally on every call — external poke does NOT persist
- this 0x24: written unconditionally on every call — external poke does NOT persist
- this 0x28: written unconditionally on every call — external poke does NOT persist
- this 0x2C: written unconditionally on every call — external poke does NOT persist
- this 0x34: written unconditionally on every call — external poke does NOT persist
- this 0x40: written unconditionally on every call — external poke does NOT persist
- this 0x44: written unconditionally on every call — external poke does NOT persist
- this 0x48: written unconditionally on every call — external poke does NOT persist
- this 0x4C: written unconditionally on every call — external poke does NOT persist
- this 0x50: written unconditionally on every call — external poke does NOT persist
- this 0x54: written unconditionally on every call — external poke does NOT persist
- this 0x58: written unconditionally on every call — external poke does NOT persist
- this 0x60: written unconditionally on every call — external poke does NOT persist
- this 0x64: written unconditionally on every call — external poke does NOT persist
- this 0x6C: written unconditionally on every call — external poke does NOT persist
- this 0x70: written unconditionally on every call — external poke does NOT persist
- this 0xB0: written unconditionally on every call — external poke does NOT persist
- this 0xBC: written unconditionally on every call — external poke does NOT persist
- this 0xC0: written unconditionally on every call — external poke does NOT persist
- this 0xC4: written unconditionally on every call — external poke does NOT persist
- this 0xC8: written unconditionally on every call — external poke does NOT persist
- this 0xCC: written unconditionally on every call — external poke does NOT persist
- this 0xD0: written unconditionally on every call — external poke does NOT persist
- this 0xD4: written unconditionally on every call — external poke does NOT persist
- this 0xD8: written unconditionally on every call — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0051ec00 | sub_51EC00 | R | function pointer for slot 0 — math utility |
| 0051ec40 | sub_51EC40 | R | function pointer for slot 9 — math utility |
| 0051eca0 | SSEWeightedVectorSum | R | function pointer for slot 5 — SSE weighted vector sum |
| 0051ece0 | sub_51ECE0 | R | function pointer for slot 1 — math utility |
| 0051eda0 | sub_51EDA0 | R | function pointer for slot 7 — math utility |
| 0051ee70 | sub_51EE70 | R | function pointer for slot 21 — math utility |
| 0051ef50 | sub_51EF50 | R | function pointer for slot 4 — math utility |
| 0051f0b0 | sub_51F0B0 | R | function pointer for slot 16 — math utility |
| 0051f160 | F_4ComponentVectorNormalize | R | function pointer for slot 8 — 4-component vector normalization |
| 0051f200 | SSEHermiteCubicInterp | R | function pointer for slot 50 — SSE Hermite cubic interpolation |
| 0051f2c0 | SSECubicSplineInterpolation | R | function pointer for slot 47 — SSE cubic spline interpolation |
| 0051f350 | SSECubicHermiteBasisFunctionEvaluation | R | function pointer for slot 53 — SSE cubic Hermite basis evaluation |
| 0051f400 | CubicSpline | R | function pointer for slot 49 — cubic spline |
| 0051f4c0 | SSECubicBezierBernsteinPolynomialEvaluation | R | function pointer for slot 52 — SSE cubic Bezier/Bernstein polynomial evaluation |
| 0051f560 | HermiteSplineBasis | R | function pointer for slot 17 — Hermite spline basis |
| 0051f5f0 | F_3VectorBlendLerp | R | function pointer for slot 51 — 3-vector blend/lerp |
| 0051f650 | BilinearInterpolation_f650 | R | function pointer for slot 54 — bilinear interpolation |
| 0051f6a0 | SSELinearInterpolationBetweenTwoPoints | R | function pointer for slot 48 — SSE linear interpolation between two points |
| 0051f700 | NewtonRaphsonReciprocalWithVectorInterpolation | R | function pointer for slot 22 — Newton-Raphson reciprocal with vector interpolation |
| 0051f7c0 | sub_51F7C0 | R | function pointer for slot 11 — math utility |
| 0051f890 | sub_51F890 | R | function pointer for slot 13 — math utility |
| 0051f980 | sub_51F980 | R | function pointer for slot 27 — math utility |
| 0051fb10 | sub_51FB10 | R | function pointer for slot 28 — math utility |
| 0051fbf0 | RotMatrixMul3x3 | R | function pointer for slot 19 — 3x3 rotation matrix multiplication |
| 0051fc80 | VectorNormalizeWithNewtonRaphsonRefinement | R | function pointer for slot 20 — vector normalize with Newton-Raphson refinement |
| 0051fd20 | sub_51FD20 | R | function pointer for slot 44 — math utility |
| 0051fd90 | RotationMatrixToAxisAngleConversion | R | function pointer for slot 24 — rotation matrix to axis-angle conversion |
| 0051feb0 | sub_51FEB0 | R | function pointer for slot 25 — math utility |
| 0051ff80 | sub_51FF80 | R | function pointer for slot 6 — math utility |
| 00520040 | sub_520040 | R | function pointer for slot 10 — math utility |
| 00520140 | sub_520140 | R | function pointer for slot 2 — math utility |
| 00520200 | sub_520200 | R | function pointer for slot 3 — math utility |
| 00520500 | sub_520500 | R | function pointer for slot 18 — math utility |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — all assignments are unconditional (no branches, no early returns)
