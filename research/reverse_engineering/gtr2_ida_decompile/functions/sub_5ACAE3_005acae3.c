float *__stdcall sub_5ACAE3(float *a1, float *a2)
{
  float *v2; // ecx
  float *result; // eax
  float v4; // ecx
  long double v5; // st7
  long double v6; // st7
  float v7; // [esp+8h] [ebp-8h]
  float v8; // [esp+Ch] [ebp-4h]
  float v9; // [esp+1Ch] [ebp+Ch]

  v9 = *a2 * *a2 + a2[1] * a2[1];
  if ( sub_5A9357(v9, 1.0) )
  {
    result = a1;
    if ( a1 == v2 )
      return result;
    *a1 = *v2;
    v4 = v2[1];
    goto LABEL_4;
  }
  result = a1;
  if ( v9 > 1.1754944e-38 )
  {
    v5 = 1.0 / sqrt(v9);
    v7 = v5 * *v2;
    v6 = v5 * v2[1];
    *a1 = v7;
    v8 = v6;
    v4 = v8;
LABEL_4:
    result[1] = v4;
    return result;
  }
  *a1 = 0.0;
  a1[1] = 0.0;
  return result;
}
