int __fastcall sub_5794F0(float *a1, float *a2)
{
  double v2; // st7
  __int16 v3; // fps
  bool v4; // c0
  char v5; // c2
  bool v6; // c3
  int result; // eax
  long double v8; // st7
  long double v9; // st7
  long double v10; // st7
  double v11; // st6
  float v12; // [esp+8h] [ebp-4h]
  float v13; // [esp+8h] [ebp-4h]

  v2 = 1.0 - *a1 * *a1;
  v12 = v2;
  v4 = v2 < 0.0;
  v5 = 0;
  v6 = v2 == 0.0;
  result = v3 & 0x4100;
  if ( (v3 & 0x4100) != 0 )
  {
    result = 0;
    *a2 = 0.0;
    a2[1] = 0.0;
    a2[2] = 0.0;
  }
  else
  {
    v8 = acos(*a1);
    v9 = (v8 + v8) / sqrt(v12);
    v13 = v9;
    v10 = v9 * a1[3];
    v11 = v13 * a1[2];
    *a2 = v13 * a1[1];
    a2[1] = v11;
    a2[2] = v10;
  }
  return result;
}
