void __fastcall sub_614B90(float *a1, float *a2)
{
  long double v2; // st7
  long double v3; // st6
  long double v4; // st7
  long double v5; // st7
  long double v6; // st6
  long double v7; // st7
  long double v8; // st7
  long double v9; // st7

  v2 = a1[4] + *a1 + a1[8] + 1.0;
  if ( v2 <= 0.0625 )
  {
    if ( *a1 <= (double)a1[4] || *a1 <= (double)a1[8] )
    {
      if ( a1[4] <= (double)a1[8] )
      {
        v9 = sqrt(a1[8] + 1.0 - *a1 - a1[4]);
        *a2 = (a1[3] - a1[1]) * (0.5 / v9);
        a2[1] = (a1[6] + a1[2]) * (0.5 / v9);
        a2[2] = (a1[7] + a1[5]) * (0.5 / v9);
        a2[3] = v9 * 0.5;
      }
      else
      {
        v8 = sqrt(a1[4] + 1.0 - *a1 - a1[8]);
        *a2 = (a1[2] - a1[6]) * (0.5 / v8);
        a2[1] = (a1[3] + a1[1]) * (0.5 / v8);
        a2[2] = v8 * 0.5;
        a2[3] = (a1[7] + a1[5]) * (0.5 / v8);
      }
    }
    else
    {
      v5 = sqrt(*a1 + 1.0 - a1[4] - a1[8]);
      *a2 = (a1[7] - a1[5]) * (0.5 / v5);
      v6 = v5;
      v7 = 0.5 / v5;
      a2[1] = v6 * 0.5;
      a2[2] = (a1[3] + a1[1]) * v7;
      a2[3] = (a1[6] + a1[2]) * v7;
    }
  }
  else
  {
    v3 = sqrt(v2);
    v4 = 0.5 / v3;
    *a2 = v3 * 0.5;
    a2[1] = (a1[7] - a1[5]) * v4;
    a2[2] = (a1[2] - a1[6]) * v4;
    a2[3] = (a1[3] - a1[1]) * v4;
  }
}
