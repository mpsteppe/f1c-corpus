// f1c  0x0050c78c  size=209
float *__stdcall sub_50C78C(float *a1, float *a2, float *a3, float *a4, float *a5, float a6)
{
  double v6; // st7
  float *result; // eax
  double v8; // st6
  double v9; // st6
  double v10; // st5
  double v11; // st4
  double v12; // st3
  float v13; // [esp+0h] [ebp-Ch]
  float v14; // [esp+4h] [ebp-8h]
  float v15; // [esp+8h] [ebp-4h]

  v6 = a6 * a6;
  result = a1;
  v8 = a6 * v6;
  v15 = v8;
  v13 = v8 + v8;
  v14 = 3.0 * v6;
  v9 = v13 - v14 + 1.0;
  v10 = v15 - (v6 + v6) + a6;
  v11 = v14 - v13;
  v12 = v15 - v6;
  *a1 = v9 * *a2 + v10 * *a3 + v11 * *a4 + v12 * *a5;
  a1[1] = v12 * a5[1] + v11 * a4[1] + v10 * a3[1] + v9 * a2[1];
  a1[2] = v12 * a5[2] + v11 * a4[2] + v10 * a3[2] + v9 * a2[2];
  a1[3] = v12 * a5[3] + v11 * a4[3] + v10 * a3[3] + v9 * a2[3];
  return result;
}
