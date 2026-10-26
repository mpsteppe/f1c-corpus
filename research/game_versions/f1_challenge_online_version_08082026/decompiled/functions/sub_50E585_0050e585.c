float *__stdcall sub_50E585(float *a1, float *a2, float *a3, float *a4)
{
  double v4; // st7
  double v5; // st6
  double v6; // st5
  double v7; // st4
  float *result; // eax
  float v9; // [esp+Ch] [ebp-18h]
  float v10; // [esp+10h] [ebp-14h]
  float v11; // [esp+14h] [ebp-10h]
  float v12; // [esp+18h] [ebp-Ch]
  float v13; // [esp+1Ch] [ebp-8h]

  v4 = *a2 - *a3;
  v5 = a2[1] - a3[1];
  v6 = a2[2] - a3[2];
  v12 = *a2 - *a4;
  v13 = a2[1] - a4[1];
  v7 = a2[2] - a4[2];
  v9 = v7 * v5 - v13 * v6;
  v10 = v6 * v12 - v7 * v4;
  v11 = v13 * v4 - v12 * v5;
  *a1 = v9;
  a1[1] = v10;
  a1[2] = v11;
  sub_50C2B3();
  result = a1;
  a1[3] = -(a1[2] * a2[2] + a1[1] * a2[1] + *a1 * *a2);
  return result;
}
