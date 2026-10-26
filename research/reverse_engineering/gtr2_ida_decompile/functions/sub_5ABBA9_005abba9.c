float *__stdcall sub_5ABBA9(float *a1, float a2, float a3, float a4, float a5)
{
  float *result; // eax
  double v6; // st7
  double v7; // st7
  float v8; // [esp+8h] [ebp-8h]
  float v9; // [esp+Ch] [ebp-4h]
  float v10; // [esp+1Ch] [ebp+Ch]

  v8 = a2 * 0.5;
  v10 = cos(v8);
  v9 = sin(v8);
  result = a1;
  v6 = v10 / v9;
  *a1 = v6 / a3;
  a1[1] = 0.0;
  a1[2] = 0.0;
  a1[3] = 0.0;
  a1[4] = 0.0;
  a1[5] = v6;
  a1[6] = 0.0;
  a1[7] = 0.0;
  a1[8] = 0.0;
  a1[9] = 0.0;
  v7 = a5 / (a5 - a4);
  a1[10] = v7;
  a1[11] = 1.0;
  a1[12] = 0.0;
  a1[13] = 0.0;
  a1[14] = -(v7 * a4);
  a1[15] = 0.0;
  return result;
}
