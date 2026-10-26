float *__stdcall sub_50E3E0(float *a1, float *a2)
{
  float *result; // eax
  float *v4; // esi
  long double v5; // st7
  long double v6; // st7
  float v7; // [esp+18h] [ebp+Ch]

  v7 = *a2 * *a2 + a2[1] * a2[1] + a2[2] * a2[2];
  if ( FloatRangeCheck(v7, 1.0) )
  {
    result = a1;
    if ( a1 != a2 )
    {
      *a1 = *a2;
      v4 = a2 + 1;
      a1[1] = *v4++;
      a1[2] = *v4;
      a1[3] = v4[1];
    }
  }
  else
  {
    result = a1;
    if ( v7 <= 1.1754944e-38 )
    {
      *a1 = 0.0;
      a1[1] = 0.0;
      a1[2] = 0.0;
      v6 = 0.0;
    }
    else
    {
      v5 = 1.0 / sqrt(v7);
      *a1 = v5 * *a2;
      a1[1] = v5 * a2[1];
      a1[2] = v5 * a2[2];
      v6 = v5 * a2[3];
    }
    a1[3] = v6;
  }
  return result;
}

