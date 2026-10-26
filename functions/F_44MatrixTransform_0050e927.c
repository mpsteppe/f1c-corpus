float *__stdcall sub_50E927(float *a1, float *a2, float *a3)
{
  double v3; // st5
  double v4; // st6
  double v5; // st7
  bool v6; // zf
  float *result; // eax
  double v8; // st7
  float v9; // [esp+8h] [ebp-4h]

  v3 = *a2 * a3[1] + a2[1] * a3[5] + a2[2] * a3[9] + a3[13];
  v4 = *a2 * a3[2] + a2[1] * a3[6] + a2[2] * a3[10] + a3[14];
  v5 = *a2 * a3[3] + a2[1] * a3[7] + a2[2] * a3[11] + a3[15];
  *a1 = *a2 * *a3 + a2[1] * a3[4] + a2[2] * a3[8] + a3[12];
  a1[1] = v3;
  a1[2] = v4;
  v9 = v5;
  v6 = !FloatRangeCheck(v9, 1.0);
  result = a1;
  if ( v6 )
  {
    v8 = 1.0 / v9;
    *a1 = v8 * *a1;
    a1[1] = v8 * a1[1];
    a1[2] = v8 * a1[2];
  }
  return result;
}
