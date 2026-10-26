float *__stdcall sub_54BEC5(float *a1, float *a2, int a3)
{
  float *result; // eax
  double v4; // st7
  double v5; // st6
  double v6; // st5
  double v7; // st4
  double v8; // st3
  float v9; // [esp+8h] [ebp-18h]
  float v10; // [esp+Ch] [ebp-14h]
  float v11; // [esp+10h] [ebp-10h]
  float v12; // [esp+14h] [ebp-Ch]
  float v13; // [esp+18h] [ebp-8h]
  float v14; // [esp+1Ch] [ebp-4h]

  sub_54B155();
  result = a1;
  v4 = v12 * a2[1] + v11 * *a2 + v14 * a2[3] + v13 * a2[2];
  v5 = -v11;
  v6 = -v12;
  v7 = -v13;
  v9 = v7;
  v8 = -v14;
  v10 = v8;
  *a1 = v5 * *a2 + v4;
  a1[4] = v6 * *a2;
  a1[8] = v7 * *a2;
  a1[12] = v8 * *a2;
  a1[1] = v5 * a2[1];
  a1[5] = v6 * a2[1] + v4;
  a1[9] = v7 * a2[1];
  a1[13] = v8 * a2[1];
  a1[2] = v5 * a2[2];
  a1[6] = v6 * a2[2];
  a1[10] = v7 * a2[2] + v4;
  a1[14] = v8 * a2[2];
  a1[3] = v5 * a2[3];
  a1[7] = v6 * a2[3];
  a1[11] = v9 * a2[3];
  a1[15] = v10 * a2[3] + v4;
  return result;
}
