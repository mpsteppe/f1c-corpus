float *__fastcall sub_5D4490(float *a1, float *a2, float *a3, float a4)
{
  float *result; // eax
  double v5; // st6
  double v6; // st5
  float v7; // [esp+4h] [ebp-1Ch]
  float v8; // [esp+8h] [ebp-18h]
  float v9; // [esp+Ch] [ebp-14h]
  float v10; // [esp+18h] [ebp-8h]
  float v11; // [esp+1Ch] [ebp-4h]

  result = a1;
  v5 = a4 * a3[1];
  v10 = a4 * a3[2];
  v11 = a4 * a3[3];
  v6 = 1.0 - a4;
  v7 = a2[1] * v6;
  v8 = a2[2] * v6;
  v9 = a2[3] * v6;
  *a1 = *a2 * v6 + a4 * *a3;
  a1[1] = v7 + v5;
  a1[2] = v8 + v10;
  a1[3] = v9 + v11;
  return result;
}
