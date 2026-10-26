float *__stdcall sub_50E491(float *a1, float *a2, float *a3, float *a4)
{
  double v4; // st7
  double v5; // st6
  float *result; // eax
  float v7; // [esp+1Ch] [ebp+Ch]

  v4 = *a2 * *a3 + a2[1] * a3[1] + a3[2] * a2[2];
  v5 = v4 - (*a2 * *a4 + a4[2] * a2[2] + a2[1] * a4[1]);
  if ( v5 == 0.0 )
    return 0;
  v7 = (v4 + a2[3]) / v5;
  if ( !ArithmeticComparison_a88f(COERCE_UNSIGNED_INT64(v7), HIDWORD(COERCE_UNSIGNED_INT64(v7))) )
    return 0;
  result = a1;
  *a1 = (*a4 - *a3) * v7 + *a3;
  a1[1] = (a4[1] - a3[1]) * v7 + a3[1];
  a1[2] = (a4[2] - a3[2]) * v7 + a3[2];
  return result;
}
