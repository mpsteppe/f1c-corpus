float *__stdcall sub_54B602(float *a1, float *a2)
{
  float *v2; // esi
  float *result; // eax
  float *v4; // esi
  long double v5; // st7
  long double v6; // st7
  float v7[3]; // [esp+10h] [ebp-Ch] BYREF
  float v8; // [esp+28h] [ebp+Ch]

  v2 = a2;
  v8 = *a2 * *a2 + a2[1] * a2[1] + a2[2] * a2[2];
  if ( sub_548E48(v8, 1.0) )
  {
    result = a1;
    if ( a1 == v2 )
      return result;
    goto LABEL_3;
  }
  result = a1;
  if ( v8 > 1.1754944e-38 )
  {
    v5 = 1.0 / sqrt(v8);
    v7[0] = v5 * *v2;
    v7[1] = v5 * v2[1];
    v6 = v5 * v2[2];
    v2 = v7;
    v7[2] = v6;
LABEL_3:
    *result = *v2;
    v4 = v2 + 1;
    result[1] = *v4;
    result[2] = v4[1];
    return result;
  }
  *a1 = 0.0;
  a1[1] = 0.0;
  a1[2] = 0.0;
  return result;
}
