// f1c  0x0050e7cb  size=128
float *__stdcall sub_50E7CB(float *a1, float *a2, float *a3)
{
  double v3; // st6
  double v4; // st7
  bool v5; // zf
  float *result; // eax
  double v7; // st7
  float v8; // [esp+8h] [ebp-4h]

  v3 = *a2 * a3[1] + a2[1] * a3[5] + a3[13];
  v4 = *a2 * a3[3] + a2[1] * a3[7] + a3[15];
  *a1 = *a2 * *a3 + a2[1] * a3[4] + a3[12];
  a1[1] = v3;
  v8 = v4;
  v5 = !sub_50C042(v8, 1.0);
  result = a1;
  if ( v5 )
  {
    v7 = 1.0 / v8;
    *a1 = v7 * *a1;
    a1[1] = v7 * a1[1];
  }
  return result;
}
