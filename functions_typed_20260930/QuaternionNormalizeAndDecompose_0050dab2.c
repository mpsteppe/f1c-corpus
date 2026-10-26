void __stdcall sub_50DAB2(float *a1, float *a2, float *a3)
{
  long double v3; // st3
  long double v4; // st7
  double v5; // st7

  v3 = *a1 * *a1 + a1[1] * a1[1] + a1[2] * a1[2] + a1[3] * a1[3];
  if ( v3 <= 1.1754944e-38 )
  {
    if ( a2 )
    {
      *a2 = 1.0;
      a2[1] = 0.0;
      a2[2] = 0.0;
    }
    if ( a3 )
      *a3 = 0.0;
  }
  else
  {
    if ( a2 )
    {
      v4 = 1.0 / sqrt(v3);
      *a2 = v4 * *a1;
      a2[1] = v4 * a1[1];
      a2[2] = v4 * a1[2];
    }
    if ( a3 )
    {
      v5 = a1[3];
      FloatFunctionPassThrough();
      *a3 = v5 + v5;
    }
  }
}

