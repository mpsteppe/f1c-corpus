int __cdecl sub_5172A5(_DWORD *a1)
{
  int result; // eax

  result = sub_5171D0();
  if ( (result & 0x20) != 0 && (result & 0x80u) != 0 )
  {
    *a1 = sub_526CA8;
    a1[1] = sub_5261EA;
    a1[2] = sub_526F69;
    a1[3] = F_4x4MatrixMultiply_243a;
    a1[5] = sub_526CFD;
    a1[6] = sub_52625B;
    a1[7] = sub_5262C2;
    a1[8] = sub_526FEB;
    a1[9] = sub_526D36;
    a1[10] = j_F_4DVectorTransform;
    a1[11] = F_4ElementDeterminant;
    a1[12] = sub_527393;
    a1[13] = sub_5273D6;
    a1[14] = QuaternionTransformComposition;
    a1[15] = MatrixInterpolationBlend;
    a1[16] = QuaternionProduct3DNow;
    a1[17] = sub_526D9A;
    a1[18] = F_3DNow44MatrixMultiplyWrapper;
    a1[19] = sub_520ED0;
    a1[20] = sub_520F69;
    a1[21] = F_3DVectorNormalize_7578;
    a1[22] = sub_5274BA;
    a1[23] = sub_520FC6;
    a1[24] = F_3DNowBarycentricInterpolationWithNormalization;
    a1[25] = QuaternionMul3DNow;
    a1[26] = F_3DNowMatrixConstructor;
    a1[27] = F_3DNowQuaternionFromAngle;
    a1[28] = QuaternionTo4x4RotationMatrix;
    a1[29] = Media3DNowMathOperation;
    a1[30] = F_3DNowTransformationMatrixConstruction;
    a1[31] = SymmetricTransformMatrix3DNow;
    a1[32] = F_3DNowQuaternionFromEncodedAxisAngle;
    a1[33] = F_4x4TransformMatrixFrom3Ints;
    a1[34] = Matrix2x23DNow;
    a1[35] = SIMDVectorNormalization;
    a1[36] = MMX3DNowVectorTransform;
    a1[37] = F_4x4MatrixTranspose_2ab3;
    a1[38] = F_3x3MatrixInverse3DNow;
    a1[39] = F_3DNowMatrixVectorMath;
    a1[40] = F_3DNowPackedFloatMatrixQuaternionOps;
    a1[41] = F_4x4TransformationMatrixConstructor;
    a1[42] = SIMDQuaternionRotationArithmetic;
    a1[43] = F_3DVectorBlend;
    a1[44] = F_3DVectorNegateAndNormalize;
    a1[54] = F_3DNowBarycentricInterpolation;
    a1[51] = BilinearInterp3DNow;
    a1[48] = sub_526E32;
    a1[46] = sub_526E7B;
    a1[52] = F_3DNowCubicPolynomialInterpolation;
    a1[49] = CubicInterp3DNow;
    a1[55] = F_3DAudioListenerTransform;
    a1[56] = F_3DVectorNormalize;
    a1[53] = F_3DNowCubicBezierInterpolation;
    a1[47] = sub_526EBE;
    a1[50] = QuadrilinearInterp3DNow;
    a1[4] = F_3DNow44MatrixMultiply;
    a1[45] = Quaternion3DMath;
    if ( (result & 0x100) != 0 && (result & 0x200) != 0 )
    {
      a1[15] = F_3DNowVectorTransform;
      a1[18] = F_4x4MatrixInversion;
      a1[38] = F_4x4RotationMatrixBuild;
      a1[39] = MMXPackedFloatingPointSIMDMath;
      a1[24] = F_3DNowQuadEdgeIntersect;
    }
  }
  return result;
}

