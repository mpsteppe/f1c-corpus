float *__stdcall sub_50F199(float *a1, int a2)
{
  double v2; // st7
  float *result; // eax
  double v4; // st6
  double v5; // st5
  float v6; // [esp+0h] [ebp-10h]
  float v7; // [esp+4h] [ebp-Ch]
  float v8; // [esp+8h] [ebp-8h]
  float v9; // [esp+Ch] [ebp-4h]
  float v10; // [esp+1Ch] [ebp+Ch]

  ThunkToFUN0050e3cd();
  v2 = v6 * -2.0;
  result = a1;
  v4 = v7 * -2.0;
  v5 = v8 * -2.0;
  v10 = v5;
  *a1 = v6 * v2 + 1.0;
  a1[1] = v4 * v6;
  a1[2] = v5 * v6;
  a1[3] = 0.0;
  a1[4] = v7 * v2;
  a1[5] = v7 * v4 + 1.0;
  a1[6] = v5 * v7;
  a1[7] = 0.0;
  a1[8] = v8 * v2;
  a1[9] = v8 * v4;
  a1[10] = v8 * v5 + 1.0;
  a1[11] = 0.0;
  a1[12] = v9 * v2;
  a1[13] = v9 * v4;
  a1[14] = v9 * v10;
  a1[15] = 1.0;
  return result;
}

