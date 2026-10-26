void __fastcall sub_614E80(float *a1, float *a2)
{
  double v2; // st7
  long double v3; // st7
  long double v4; // st7
  long double v5; // st7
  double v6; // st6
  float v7; // [esp+8h] [ebp-4h]
  float v8; // [esp+8h] [ebp-4h]

  v2 = 1.0 - *a1 * *a1;
  v7 = v2;
  if ( v2 <= 0.0 )
  {
    *a2 = 0.0;
    a2[1] = 0.0;
    a2[2] = 0.0;
  }
  else
  {
    v3 = acos(*a1);
    v4 = (v3 + v3) / sqrt(v7);
    v8 = v4;
    v5 = v4 * a1[3];
    v6 = v8 * a1[2];
    *a2 = v8 * a1[1];
    a2[1] = v6;
    a2[2] = v5;
  }
}
