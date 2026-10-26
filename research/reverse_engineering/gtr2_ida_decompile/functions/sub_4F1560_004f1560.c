float *__fastcall sub_4F1560(float *a1, float *a2)
{
  long double v2; // st7
  long double v3; // st7
  double v4; // st7
  double v5; // st6
  long double v6; // st7
  long double v7; // st7
  double v8; // st5
  long double v9; // st7
  long double v10; // st7
  long double v11; // st7
  long double v12; // st7
  float v14; // [esp+0h] [ebp-18h]
  float v15; // [esp+0h] [ebp-18h]
  float v16; // [esp+4h] [ebp-14h]
  float v17; // [esp+4h] [ebp-14h]
  float v18; // [esp+10h] [ebp-8h]
  float v19; // [esp+14h] [ebp-4h]

  v2 = a2[5] + *a2 + a2[10] + 1.0;
  if ( v2 <= 0.0000099999997 )
  {
    if ( *a2 <= (double)a2[5] || *a2 <= (double)a2[10] )
    {
      if ( a2[5] <= (double)a2[10] )
      {
        v11 = sqrt(a2[10] + 1.0 - *a2 - a2[5]);
        v12 = v11 + v11;
        v17 = v12;
        v15 = 1.0 / v12;
        v4 = (a2[8] + a2[2]) * v15;
        v5 = (a2[9] + a2[6]) * v15;
        v18 = v17 * 0.25;
        v8 = a2[4] - a2[1];
      }
      else
      {
        v9 = sqrt(a2[5] + 1.0 - *a2 - a2[10]);
        v10 = v9 + v9;
        v16 = v10;
        v15 = 1.0 / v10;
        v4 = (a2[4] + a2[1]) * v15;
        v5 = v16 * 0.25;
        v18 = (a2[9] + a2[6]) * v15;
        v8 = a2[8] - a2[2];
      }
    }
    else
    {
      v6 = sqrt(*a2 + 1.0 - a2[5] - a2[10]);
      v7 = v6 + v6;
      v15 = 1.0 / v7;
      v4 = v7 * 0.25;
      v5 = (a2[4] + a2[1]) * v15;
      v18 = (a2[8] + a2[2]) * v15;
      v8 = a2[9] - a2[6];
    }
    v19 = v8 * v15;
  }
  else
  {
    v3 = 0.5 / sqrt(v2);
    v14 = v3;
    v19 = 0.25 / v3;
    v4 = (a2[6] - a2[9]) * v14;
    v5 = (a2[8] - a2[2]) * v14;
    v18 = (a2[1] - a2[4]) * v14;
  }
  *a1 = v4;
  a1[2] = v18;
  a1[1] = v5;
  a1[3] = v19;
  return a1;
}
