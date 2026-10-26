## PackedFloatingPointMath_005295e0 — MMX PackedFloatAbsoluteValue

**Summary:** Computes absolute value of lower 32-bit float in MMX register by clearing sign bit (0x80000000). Used by 3DNow! math routines for packed float abs.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** QuaternionMul3DNow (005214aa), Media3DNowMathOperation (0052156f), F_3DVectorNormalize (0052193c), Quaternion3DMath (005219e1), F_3DNowTransformationMatrixConstruction (00522952), SymmetricTransformMatrix3DNow (005229b5), F_3DNowQuaternionFromEncodedAxisAngle (00522a13), F_3DNowPackedFloatMatrixQuaternionOps (00523e7a), SIMDQuaternionRotationArithmetic (00524553)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d92d8 | qword_5D92D8 | R | MMX_PolyCoeff_SinCos [DERIVED] |
| 005d9320 | qword_5D9320 | R | TrigConst_qword_5D9320 [DERIVED] |
| 005d9328 | qword_5D9328 | R | TrigApproxCoeff [DERIVED] |
| 005d9330 | qword_5D9330 | R | PackedMathSinCosC0 [DERIVED] |
| 005d9338 | qword_5D9338 | R | MathSinCosPolyCoeff [DERIVED] |
| 005d9340 | qword_5D9340 | R | SinCosCoeff_5D9340 [DERIVED] |
| 005d9348 | qword_5D9348 | R | Math_TrigPolyCoeff7 [DERIVED] |
| 005d935c | dword_5D935C | R | ThreeDNowRsqrtPolyConst [DERIVED] |
| 005d9368 | dword_5D9368 | R | Math_Trig_SmallAngleBound [DERIVED] |
| 005d9410 | dword_5D9410 | R | PITableEntry [DERIVED] |
| 005d9414 | dword_5D9414 | R | Math_Trig_TableBound_9414 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — no branches in function body
