float *__stdcall sub_54A82D(float *a1, float *a2, float *a3)
{
  long double v3; // st7
  float *result; // eax
  long double v5; // st7
  long double v6; // st7

  v3 = *a1 * *a1 + a1[1] * a1[1] + a1[2] * a1[2] + a1[3] * a1[3];
  result = a2;
  if ( v3 <= 1.1754944e-38 )
  {
    if ( a2 )
    {
      *a2 = 1.0;
      a2[1] = 0.0;
      a2[2] = 0.0;
    }
    result = a3;
    if ( a3 )
      *a3 = 0.0;
  }
  else
  {
    if ( a2 )
    {
      v5 = 1.0 / sqrt(v3);
      *a2 = v5 * *a1;
      a2[1] = v5 * a1[1];
      a2[2] = v5 * a1[2];
    }
    if ( a3 )
    {
      v6 = acos(a1[3]);
      *a3 = v6 + v6;
    }
  }
  return result;
}
