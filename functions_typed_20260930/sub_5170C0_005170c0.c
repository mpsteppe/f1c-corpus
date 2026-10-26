__m128 *(__stdcall **__cdecl sub_5170C0(
        __m128 *(__stdcall **a1)(__m128 *, unsigned int *, __m128 *)))(__m128 *, unsigned int *, __m128 *)
{
  __m128 *(__stdcall **result)(__m128 *, unsigned int *, __m128 *); // eax

  result = a1;
  a1[28] = (__m128 *(__stdcall *)(__m128 *, unsigned int *, __m128 *))sub_520C00;
  *a1 = sub_51EC00;
  a1[13] = (__m128 *(__stdcall *)(__m128 *, unsigned int *, __m128 *))sub_520980;
  a1[27] = (__m128 *(__stdcall *)(__m128 *, unsigned int *, __m128 *))sub_520A70;
  a1[11] = (__m128 *(__stdcall *)(__m128 *, unsigned int *, __m128 *))sub_51F7C0;
  a1[48] = (__m128 *(__stdcall *)(__m128 *, unsigned int *, __m128 *))SSELinearInterpolationBetweenTwoPoints;
  a1[47] = (__m128 *(__stdcall *)(__m128 *, unsigned int *, __m128 *))SSECubicSplineInterpolation;
  a1[17] = (__m128 *(__stdcall *)(__m128 *, unsigned int *, __m128 *))HermiteSplineBasis;
  a1[54] = (__m128 *(__stdcall *)(__m128 *, unsigned int *, __m128 *))BilinearInterpolation_f650;
  a1[53] = (__m128 *(__stdcall *)(__m128 *, unsigned int *, __m128 *))SSECubicHermiteBasisFunctionEvaluation;
  a1[52] = (__m128 *(__stdcall *)(__m128 *, unsigned int *, __m128 *))SSECubicBezierBernsteinPolynomialEvaluation;
  a1[51] = (__m128 *(__stdcall *)(__m128 *, unsigned int *, __m128 *))F_3VectorBlendLerp;
  a1[50] = (__m128 *(__stdcall *)(__m128 *, unsigned int *, __m128 *))SSEHermiteCubicInterp;
  a1[49] = (__m128 *(__stdcall *)(__m128 *, unsigned int *, __m128 *))CubicSpline;
  a1[18] = (__m128 *(__stdcall *)(__m128 *, unsigned int *, __m128 *))sub_520500;
  a1[22] = (__m128 *(__stdcall *)(__m128 *, unsigned int *, __m128 *))NewtonRaphsonReciprocalWithVectorInterpolation;
  a1[25] = (__m128 *(__stdcall *)(__m128 *, unsigned int *, __m128 *))sub_520E00;
  a1[24] = (__m128 *(__stdcall *)(__m128 *, unsigned int *, __m128 *))TriangleClosestPointOrNormal;
  a1[31] = (__m128 *(__stdcall *)(__m128 *, unsigned int *, __m128 *))sub_5208F0;
  a1[30] = (__m128 *(__stdcall *)(__m128 *, unsigned int *, __m128 *))sub_520870;
  a1[19] = (__m128 *(__stdcall *)(__m128 *, unsigned int *, __m128 *))RotMatrixMul3x3;
  a1[20] = (__m128 *(__stdcall *)(__m128 *, unsigned int *, __m128 *))VectorNormalizeWithNewtonRaphsonRefinement;
  a1[16] = (__m128 *(__stdcall *)(__m128 *, unsigned int *, __m128 *))sub_5207C0;
  a1[21] = (__m128 *(__stdcall *)(__m128 *, unsigned int *, __m128 *))sub_520420;
  a1[8] = (__m128 *(__stdcall *)(__m128 *, unsigned int *, __m128 *))F_4ComponentVectorNormalize;
  a1[7] = (__m128 *(__stdcall *)(__m128 *, unsigned int *, __m128 *))sub_520350;
  a1[10] = (__m128 *(__stdcall *)(__m128 *, unsigned int *, __m128 *))sub_520040;
  a1[9] = (__m128 *(__stdcall *)(__m128 *, unsigned int *, __m128 *))sub_51EC40;
  a1[6] = (__m128 *(__stdcall *)(__m128 *, unsigned int *, __m128 *))sub_51FF80;
  a1[5] = (__m128 *(__stdcall *)(__m128 *, unsigned int *, __m128 *))SSEWeightedVectorSum;
  a1[4] = (__m128 *(__stdcall *)(__m128 *, unsigned int *, __m128 *))sub_51EF50;
  a1[3] = (__m128 *(__stdcall *)(__m128 *, unsigned int *, __m128 *))sub_520200;
  a1[2] = (__m128 *(__stdcall *)(__m128 *, unsigned int *, __m128 *))sub_520140;
  a1[1] = (__m128 *(__stdcall *)(__m128 *, unsigned int *, __m128 *))sub_51ECE0;
  return result;
}

