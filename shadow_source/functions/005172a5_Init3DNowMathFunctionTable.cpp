// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005172A5
// Canonical corpus name: sub_5172A5
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5172A5_005172a5.c

void UnknownObject::Init3DNowMathFunctionTable()
{
    // CPU-guarded function-pointer table initializer for the 3DNow/MMX math dispatch table. Probes CPU feature flags via sub_5171D0; when bits 0x20 and 0x80 of the result are set, fills the 57 dword slots of the table at a1 with 3DNow/MMX-optimized math routines (matrix multiply/transpose/inverse, quaternion product/composition/rotation, vector normalize/blend/negate, barycentric/cubic/bezier/quadrilinear interpolation, axis-angle and transform-matrix construction). When bits 0x100 and 0x200 are additionally set, overrides five entries (slots 15, 18, 24, 38, 39) with alternative optimized implementations. Returns the feature flags from sub_5171D0. Invoked by sub_50FEA7 during dispatch-table setup.
    // GUARD: Probe CPU feature flags by calling sub_5171D0; the whole table fill runs only when both bit 0x20 and bit 0x80 of the returned value are set. [callee:0x005171D0, source:raw]
    // ASSIGNMENT: Write 3DNow/MMX math dispatch routine slot 0 (byte offset 0x0) of the function-pointer table to sub_526CA8. [field:this:0x00000000, global:0x00526CA8]
    // ASSIGNMENT: Write 3DNow/MMX math dispatch routine slot 1 (byte offset 0x4) of the function-pointer table to sub_5261EA. [field:this:0x00000004, global:0x005261EA]
    // ASSIGNMENT: Write 3DNow/MMX math dispatch routine slot 2 (byte offset 0x8) of the function-pointer table to sub_526F69. [field:this:0x00000008, global:0x00526F69]
    // ASSIGNMENT: Write 3DNow/MMX math dispatch routine slot 3 (byte offset 0xC) of the function-pointer table to F_4x4MatrixMultiply_243a. [field:this:0x0000000C, global:0x0052243A]
    // ASSIGNMENT: Write 3DNow/MMX math dispatch routine slot 4 (byte offset 0x10) of the function-pointer table to F_3DNow44MatrixMultiply. [field:this:0x00000010, global:0x00525AA2]
    // ASSIGNMENT: Write 3DNow/MMX math dispatch routine slot 5 (byte offset 0x14) of the function-pointer table to sub_526CFD. [field:this:0x00000014, global:0x00526CFD]
    // ASSIGNMENT: Write 3DNow/MMX math dispatch routine slot 6 (byte offset 0x18) of the function-pointer table to sub_52625B. [field:this:0x00000018, global:0x0052625B]
    // ASSIGNMENT: Write 3DNow/MMX math dispatch routine slot 7 (byte offset 0x1C) of the function-pointer table to sub_5262C2. [field:this:0x0000001C, global:0x005262C2]
    // ASSIGNMENT: Write 3DNow/MMX math dispatch routine slot 8 (byte offset 0x20) of the function-pointer table to sub_526FEB. [field:this:0x00000020, global:0x00526FEB]
    // ASSIGNMENT: Write 3DNow/MMX math dispatch routine slot 9 (byte offset 0x24) of the function-pointer table to sub_526D36. [field:this:0x00000024, global:0x00526D36]
    // ASSIGNMENT: Write 3DNow/MMX math dispatch routine slot 10 (byte offset 0x28) of the function-pointer table to j_F_4DVectorTransform. [field:this:0x00000028, global:0x005267A2]
    // ASSIGNMENT: Write 3DNow/MMX math dispatch routine slot 11 (byte offset 0x2C) of the function-pointer table to F_4ElementDeterminant. [field:this:0x0000002C, global:0x0052266C]
    // ASSIGNMENT: Write 3DNow/MMX math dispatch routine slot 12 (byte offset 0x30) of the function-pointer table to sub_527393. [field:this:0x00000030, global:0x00527393]
    // ASSIGNMENT: Write 3DNow/MMX math dispatch routine slot 13 (byte offset 0x34) of the function-pointer table to sub_5273D6. [field:this:0x00000034, global:0x005273D6]
    // ASSIGNMENT: Write 3DNow/MMX math dispatch routine slot 14 (byte offset 0x38) of the function-pointer table to QuaternionTransformComposition. [field:this:0x00000038, global:0x005267A7]
    // ASSIGNMENT: Write 3DNow/MMX math dispatch routine slot 15 (byte offset 0x3C) of the function-pointer table to MatrixInterpolationBlend. [field:this:0x0000003C, global:0x0052692F]
    // ASSIGNMENT: Write 3DNow/MMX math dispatch routine slot 16 (byte offset 0x40) of the function-pointer table to QuaternionProduct3DNow. [field:this:0x00000040, global:0x0052704A]
    // ASSIGNMENT: Write 3DNow/MMX math dispatch routine slot 17 (byte offset 0x44) of the function-pointer table to sub_526D9A. [field:this:0x00000044, global:0x00526D9A]
    // ASSIGNMENT: Write 3DNow/MMX math dispatch routine slot 18 (byte offset 0x48) of the function-pointer table to F_3DNow44MatrixMultiplyWrapper. [field:this:0x00000048, global:0x005261CE]
    // ASSIGNMENT: Write 3DNow/MMX math dispatch routine slot 19 (byte offset 0x4C) of the function-pointer table to sub_520ED0. [field:this:0x0000004C, global:0x00520ED0]
    // ASSIGNMENT: Write 3DNow/MMX math dispatch routine slot 20 (byte offset 0x50) of the function-pointer table to sub_520F69. [field:this:0x00000050, global:0x00520F69]
    // ASSIGNMENT: Write 3DNow/MMX math dispatch routine slot 21 (byte offset 0x54) of the function-pointer table to F_3DVectorNormalize_7578. [field:this:0x00000054, global:0x00527578]
    // ASSIGNMENT: Write 3DNow/MMX math dispatch routine slot 22 (byte offset 0x58) of the function-pointer table to sub_5274BA. [field:this:0x00000058, global:0x005274BA]
    // ASSIGNMENT: Write 3DNow/MMX math dispatch routine slot 23 (byte offset 0x5C) of the function-pointer table to sub_520FC6. [field:this:0x0000005C, global:0x00520FC6]
    // ASSIGNMENT: Write 3DNow/MMX math dispatch routine slot 24 (byte offset 0x60) of the function-pointer table to F_3DNowBarycentricInterpolationWithNormalization. [field:this:0x00000060, global:0x00521079]
    // ASSIGNMENT: Write 3DNow/MMX math dispatch routine slot 25 (byte offset 0x64) of the function-pointer table to QuaternionMul3DNow. [field:this:0x00000064, global:0x005214AA]
    // ASSIGNMENT: Write 3DNow/MMX math dispatch routine slot 26 (byte offset 0x68) of the function-pointer table to F_3DNowMatrixConstructor. [field:this:0x00000068, global:0x0052273B]
    // ASSIGNMENT: Write 3DNow/MMX math dispatch routine slot 27 (byte offset 0x6C) of the function-pointer table to F_3DNowQuaternionFromAngle. [field:this:0x0000006C, global:0x0052278B]
    // ASSIGNMENT: Write 3DNow/MMX math dispatch routine slot 28 (byte offset 0x70) of the function-pointer table to QuaternionTo4x4RotationMatrix. [field:this:0x00000070, global:0x00522876]
    // ASSIGNMENT: Write 3DNow/MMX math dispatch routine slot 29 (byte offset 0x74) of the function-pointer table to Media3DNowMathOperation. [field:this:0x00000074, global:0x0052156F]
    // ASSIGNMENT: Write 3DNow/MMX math dispatch routine slot 30 (byte offset 0x78) of the function-pointer table to F_3DNowTransformationMatrixConstruction. [field:this:0x00000078, global:0x00522952]
    // ASSIGNMENT: Write 3DNow/MMX math dispatch routine slot 31 (byte offset 0x7C) of the function-pointer table to SymmetricTransformMatrix3DNow. [field:this:0x0000007C, global:0x005229B5]
    // ASSIGNMENT: Write 3DNow/MMX math dispatch routine slot 32 (byte offset 0x80) of the function-pointer table to F_3DNowQuaternionFromEncodedAxisAngle. [field:this:0x00000080, global:0x00522A13]
    // ASSIGNMENT: Write 3DNow/MMX math dispatch routine slot 33 (byte offset 0x84) of the function-pointer table to F_4x4TransformMatrixFrom3Ints. [field:this:0x00000084, global:0x00522A6C]
    // ASSIGNMENT: Write 3DNow/MMX math dispatch routine slot 34 (byte offset 0x88) of the function-pointer table to Matrix2x23DNow. [field:this:0x00000088, global:0x005275DC]
    // ASSIGNMENT: Write 3DNow/MMX math dispatch routine slot 35 (byte offset 0x8C) of the function-pointer table to SIMDVectorNormalization. [field:this:0x0000008C, global:0x005215DB]
    // ASSIGNMENT: Write 3DNow/MMX math dispatch routine slot 36 (byte offset 0x90) of the function-pointer table to MMX3DNowVectorTransform. [field:this:0x00000090, global:0x00521712]
    // ASSIGNMENT: Write 3DNow/MMX math dispatch routine slot 37 (byte offset 0x94) of the function-pointer table to F_4x4MatrixTranspose_2ab3. [field:this:0x00000094, global:0x00522AB3]
    // ASSIGNMENT: Write 3DNow/MMX math dispatch routine slot 38 (byte offset 0x98) of the function-pointer table to F_3x3MatrixInverse3DNow. [field:this:0x00000098, global:0x00522B5B]
    // ASSIGNMENT: Write 3DNow/MMX math dispatch routine slot 39 (byte offset 0x9C) of the function-pointer table to F_3DNowMatrixVectorMath. [field:this:0x0000009C, global:0x00522CE2]
    // ASSIGNMENT: Write 3DNow/MMX math dispatch routine slot 40 (byte offset 0xA0) of the function-pointer table to F_3DNowPackedFloatMatrixQuaternionOps. [field:this:0x000000A0, global:0x00523E7A]
    // ASSIGNMENT: Write 3DNow/MMX math dispatch routine slot 41 (byte offset 0xA4) of the function-pointer table to F_4x4TransformationMatrixConstructor. [field:this:0x000000A4, global:0x0052401F]
    // ASSIGNMENT: Write 3DNow/MMX math dispatch routine slot 42 (byte offset 0xA8) of the function-pointer table to SIMDQuaternionRotationArithmetic. [field:this:0x000000A8, global:0x00524553]
    // ASSIGNMENT: Write 3DNow/MMX math dispatch routine slot 43 (byte offset 0xAC) of the function-pointer table to F_3DVectorBlend. [field:this:0x000000AC, global:0x0052179F]
    // ASSIGNMENT: Write 3DNow/MMX math dispatch routine slot 44 (byte offset 0xB0) of the function-pointer table to F_3DVectorNegateAndNormalize. [field:this:0x000000B0, global:0x00521831]
    // ASSIGNMENT: Write 3DNow/MMX math dispatch routine slot 45 (byte offset 0xB4) of the function-pointer table to Quaternion3DMath. [field:this:0x000000B4, global:0x005219E1]
    // ASSIGNMENT: Write 3DNow/MMX math dispatch routine slot 46 (byte offset 0xB8) of the function-pointer table to sub_526E7B. [field:this:0x000000B8, global:0x00526E7B]
    // ASSIGNMENT: Write 3DNow/MMX math dispatch routine slot 47 (byte offset 0xBC) of the function-pointer table to sub_526EBE. [field:this:0x000000BC, global:0x00526EBE]
    // ASSIGNMENT: Write 3DNow/MMX math dispatch routine slot 48 (byte offset 0xC0) of the function-pointer table to sub_526E32. [field:this:0x000000C0, global:0x00526E32]
    // ASSIGNMENT: Write 3DNow/MMX math dispatch routine slot 49 (byte offset 0xC4) of the function-pointer table to CubicInterp3DNow. [field:this:0x000000C4, global:0x00526392]
    // ASSIGNMENT: Write 3DNow/MMX math dispatch routine slot 50 (byte offset 0xC8) of the function-pointer table to QuadrilinearInterp3DNow. [field:this:0x000000C8, global:0x00526466]
    // ASSIGNMENT: Write 3DNow/MMX math dispatch routine slot 51 (byte offset 0xCC) of the function-pointer table to BilinearInterp3DNow. [field:this:0x000000CC, global:0x00526321]
    // ASSIGNMENT: Write 3DNow/MMX math dispatch routine slot 52 (byte offset 0xD0) of the function-pointer table to F_3DNowCubicPolynomialInterpolation. [field:this:0x000000D0, global:0x005271ED]
    // ASSIGNMENT: Write 3DNow/MMX math dispatch routine slot 53 (byte offset 0xD4) of the function-pointer table to F_3DNowCubicBezierInterpolation. [field:this:0x000000D4, global:0x005272B5]
    // ASSIGNMENT: Write 3DNow/MMX math dispatch routine slot 54 (byte offset 0xD8) of the function-pointer table to F_3DNowBarycentricInterpolation. [field:this:0x000000D8, global:0x0052717C]
    // ASSIGNMENT: Write 3DNow/MMX math dispatch routine slot 55 (byte offset 0xDC) of the function-pointer table to F_3DAudioListenerTransform. [field:this:0x000000DC, global:0x00521895]
    // ASSIGNMENT: Write 3DNow/MMX math dispatch routine slot 56 (byte offset 0xE0) of the function-pointer table to F_3DVectorNormalize. [field:this:0x000000E0, global:0x0052193C]
    // GUARD: When the returned feature flags additionally have bit 0x100 and bit 0x200 set, apply alternative routine overrides to five table slots. [source:raw]
    // ASSIGNMENT: Override slot 15 with slot 15 (byte offset 0x3C) of the function-pointer table to F_3DNowVectorTransform. [field:this:0x0000003C, global:0x00526B55]
    // ASSIGNMENT: Override slot 18 with slot 18 (byte offset 0x48) of the function-pointer table to F_4x4MatrixInversion. [field:this:0x00000048, global:0x005257C0]
    // ASSIGNMENT: Override slot 24 with slot 24 (byte offset 0x60) of the function-pointer table to F_3DNowQuadEdgeIntersect. [field:this:0x00000060, global:0x00521295]
    // ASSIGNMENT: Override slot 38 with slot 38 (byte offset 0x98) of the function-pointer table to F_4x4RotationMatrixBuild. [field:this:0x00000098, global:0x00522C2D]
    // ASSIGNMENT: Override slot 39 with slot 39 (byte offset 0x9C) of the function-pointer table to MMXPackedFloatingPointSIMDMath. [field:this:0x0000009C, global:0x0052466C]
    // RETURN: Return the CPU feature flags value obtained from sub_5171D0. [callee:0x005171D0, function:0x005172A5, source:raw]
    // CALL: Invoked by sub_50FEA7; the packet reports no per-frame tick-root path, so the table is prepared during setup rather than per frame. [caller:0x0050FEA7, source:raw]

    // Conservative worker pseudocode:
    //   flags = sub_5171D0();
    //   if ((flags & 0x20) && (flags & 0x80)) {
    //     table[0] = sub_526CA8;
    //     table[1] = sub_5261EA;
    //     table[2] = sub_526F69;
    //     table[3] = F_4x4MatrixMultiply_243a;
    //     table[4] = F_3DNow44MatrixMultiply;
    //     table[5] = sub_526CFD;
    //     table[6] = sub_52625B;
    //     table[7] = sub_5262C2;
    //     table[8] = sub_526FEB;
    //     table[9] = sub_526D36;
    //     table[10] = j_F_4DVectorTransform;
    //     table[11] = F_4ElementDeterminant;
    //     table[12] = sub_527393;
    //     table[13] = sub_5273D6;
    //     table[14] = QuaternionTransformComposition;
    //     table[15] = MatrixInterpolationBlend;
    //     table[16] = QuaternionProduct3DNow;
    //     table[17] = sub_526D9A;
    //     table[18] = F_3DNow44MatrixMultiplyWrapper;
    //     table[19] = sub_520ED0;
    //     table[20] = sub_520F69;
    //     table[21] = F_3DVectorNormalize_7578;
    //     table[22] = sub_5274BA;
    //     table[23] = sub_520FC6;
    //     table[24] = F_3DNowBarycentricInterpolationWithNormalization;
    //     table[25] = QuaternionMul3DNow;
    //     table[26] = F_3DNowMatrixConstructor;
    //     table[27] = F_3DNowQuaternionFromAngle;
    //     table[28] = QuaternionTo4x4RotationMatrix;
    //     table[29] = Media3DNowMathOperation;
    //     table[30] = F_3DNowTransformationMatrixConstruction;
    //     table[31] = SymmetricTransformMatrix3DNow;
    //     table[32] = F_3DNowQuaternionFromEncodedAxisAngle;
    //     table[33] = F_4x4TransformMatrixFrom3Ints;
    //     table[34] = Matrix2x23DNow;
    //     table[35] = SIMDVectorNormalization;
    //     table[36] = MMX3DNowVectorTransform;
    //     table[37] = F_4x4MatrixTranspose_2ab3;
    //     table[38] = F_3x3MatrixInverse3DNow;
    //     table[39] = F_3DNowMatrixVectorMath;
    //     table[40] = F_3DNowPackedFloatMatrixQuaternionOps;
    //     table[41] = F_4x4TransformationMatrixConstructor;
    //     table[42] = SIMDQuaternionRotationArithmetic;
    //     table[43] = F_3DVectorBlend;
    //     table[44] = F_3DVectorNegateAndNormalize;
    //     table[45] = Quaternion3DMath;
    //     table[46] = sub_526E7B;
    //     table[47] = sub_526EBE;
    //     table[48] = sub_526E32;
    //     table[49] = CubicInterp3DNow;
    //     table[50] = QuadrilinearInterp3DNow;
    //     table[51] = BilinearInterp3DNow;
    //     table[52] = F_3DNowCubicPolynomialInterpolation;
    //     table[53] = F_3DNowCubicBezierInterpolation;
    //     table[54] = F_3DNowBarycentricInterpolation;
    //     table[55] = F_3DAudioListenerTransform;
    //     table[56] = F_3DVectorNormalize;
    //     if ((flags & 0x100) && (flags & 0x200)) {
    //       table[15] = F_3DNowVectorTransform;
    //       table[18] = F_4x4MatrixInversion;
    //       table[24] = F_3DNowQuadEdgeIntersect;
    //       table[38] = F_4x4RotationMatrixBuild;
    //       table[39] = MMXPackedFloatingPointSIMDMath;
    //     }
    //   }
    //   return flags;
    // UNRESOLVED: sub_5171D0 is not decomposed in this packet; the exact meanings of feature bits 0x20, 0x80, 0x100 and 0x200 (which CPU SIMD capabilities each denotes) cannot be determined here.
    // UNRESOLVED: The owning object of the table at a1 is not evidenced; slot semantics are inferred from routine names only, not from a caller-side dispatch contract.
    // UNRESOLVED: The inner-guard writes overwrite the base assignments on slots 15, 18, 24, 38 and 39; whether the replacement routines are faster variants or semantically different operations is unknown.
}
