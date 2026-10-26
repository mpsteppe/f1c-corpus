float *__stdcall sub_50D85D(float *a1, float *a2)
{
  double v3; // st7
  double v4; // st6
  double v5; // st5
  double v6; // st4
  double v7; // st3
  float *result; // eax
  double v9; // st2
  float v10; // [esp+0h] [ebp-10h]
  float v11; // [esp+4h] [ebp-Ch]
  float v12; // [esp+8h] [ebp-8h]
  float v13; // [esp+Ch] [ebp-4h]
  float v14; // [esp+Ch] [ebp-4h]
  float v15; // [esp+18h] [ebp+8h]
  float v16; // [esp+1Ch] [ebp+Ch]
  float v17; // [esp+1Ch] [ebp+Ch]

  v13 = *a2 * 2.0;
  v16 = a2[1] * 2.0;
  v3 = 2.0 * a2[2];
  v4 = v13 * a2[3];
  v5 = v16 * a2[3];
  v6 = v3 * a2[3];
  v10 = v13 * *a2;
  v14 = v16 * *a2;
  v12 = v3 * *a2;
  v11 = v16 * a2[1];
  v17 = v3 * a2[1];
  v7 = v3 * a2[2];
  result = a1;
  *a1 = 1.0 - v11 - v7;
  a1[1] = v14 + v6;
  a1[2] = v12 - v5;
  a1[3] = 0.0;
  a1[4] = v14 - v6;
  v9 = 1.0 - v10;
  v15 = v9;
  result[5] = v9 - v7;
  result[6] = v17 + v4;
  result[7] = 0.0;
  result[8] = v12 + v5;
  result[9] = v17 - v4;
  result[10] = v15 - v11;
  result[11] = 0.0;
  result[12] = 0.0;
  result[13] = 0.0;
  result[14] = 0.0;
  result[15] = 1.0;
  return result;
}
