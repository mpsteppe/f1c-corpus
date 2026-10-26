float *__stdcall sub_5AD9D1(float *a1, float *a2, int a3)
{
  float *result; // eax
  double v4; // st7
  float v5; // [esp+8h] [ebp-20h]
  float v6; // [esp+Ch] [ebp-1Ch]
  float v7; // [esp+10h] [ebp-18h]
  float v8; // [esp+14h] [ebp-14h]
  float v9; // [esp+18h] [ebp-10h]
  float v10; // [esp+1Ch] [ebp-Ch]
  float v11; // [esp+20h] [ebp-8h]
  float v12; // [esp+24h] [ebp-4h]

  sub_5AC6B8();
  result = a1;
  v4 = v10 * a2[1] + v9 * *a2 + v12 * a2[3] + v11 * a2[2];
  v5 = -v9;
  v6 = -v10;
  v7 = -v11;
  v8 = -v12;
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
  a1[11] = v7 * a2[3];
  a1[15] = v8 * a2[3] + v4;
  return result;
}
