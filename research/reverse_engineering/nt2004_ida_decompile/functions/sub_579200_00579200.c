int __fastcall sub_579200(float *a1, float *a2)
{
  __int16 v2; // fps
  long double v3; // st7
  bool v4; // c0
  char v5; // c2
  bool v6; // c3
  int result; // eax
  long double v8; // st6
  long double v9; // st7
  __int16 v10; // fps
  double v11; // st7
  bool v12; // c0
  char v13; // c2
  bool v14; // c3
  __int16 v15; // fps
  double v16; // st7
  bool v17; // c0
  char v18; // c2
  bool v19; // c3
  long double v20; // st7
  long double v21; // st6
  long double v22; // st7
  __int16 v23; // fps
  double v24; // st7
  bool v25; // c0
  char v26; // c2
  bool v27; // c3
  long double v28; // st7
  long double v29; // st7

  v3 = a1[4] + *a1 + a1[8] + 1.0;
  v4 = v3 < 0.0625;
  v5 = 0;
  v6 = v3 == 0.0625;
  result = v2 & 0x4100;
  if ( (v2 & 0x4100) != 0 )
  {
    v11 = *a1;
    v12 = v11 < a1[4];
    v13 = 0;
    v14 = v11 == a1[4];
    if ( (v10 & 0x4100) != 0
      || (v16 = *a1, v17 = v16 < a1[8], v18 = 0, v19 = v16 == a1[8], result = v15 & 0x4100, (v15 & 0x4100) != 0) )
    {
      v24 = a1[4];
      v25 = v24 < a1[8];
      v26 = 0;
      v27 = v24 == a1[8];
      result = v23 & 0x4100;
      if ( (v23 & 0x4100) != 0 )
      {
        v29 = sqrt(a1[8] + 1.0 - *a1 - a1[4]);
        *a2 = (a1[1] - a1[3]) * (0.5 / v29);
        a2[1] = (a1[6] + a1[2]) * (0.5 / v29);
        a2[2] = (a1[7] + a1[5]) * (0.5 / v29);
        a2[3] = v29 * 0.5;
      }
      else
      {
        v28 = sqrt(a1[4] + 1.0 - *a1 - a1[8]);
        *a2 = (a1[2] - a1[6]) * (0.5 / v28);
        a2[1] = (a1[3] + a1[1]) * (0.5 / v28);
        a2[2] = v28 * 0.5;
        a2[3] = (a1[7] + a1[5]) * (0.5 / v28);
      }
    }
    else
    {
      v20 = sqrt(*a1 + 1.0 - a1[4] - a1[8]);
      *a2 = (a1[5] - a1[7]) * (0.5 / v20);
      v21 = v20;
      v22 = 0.5 / v20;
      a2[1] = v21 * 0.5;
      a2[2] = (a1[3] + a1[1]) * v22;
      a2[3] = (a1[6] + a1[2]) * v22;
    }
  }
  else
  {
    v8 = sqrt(v3);
    v9 = 0.5 / v8;
    *a2 = v8 * 0.5;
    a2[1] = (a1[7] - a1[5]) * v9;
    a2[2] = (a1[2] - a1[6]) * v9;
    a2[3] = (a1[3] - a1[1]) * v9;
  }
  return result;
}
