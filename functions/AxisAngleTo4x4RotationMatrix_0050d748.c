float *__stdcall sub_50D748(float *a1, float *a2, float a3)
{
  float *result; // eax
  double v4; // st7
  double v5; // st5
  double v6; // st4
  double v7; // st3
  double v8; // st2
  double v9; // st3
  float v10; // [esp+8h] [ebp-1Ch]
  float v11; // [esp+Ch] [ebp-18h]
  float v12; // [esp+10h] [ebp-14h]
  float v13; // [esp+1Ch] [ebp-8h]
  float v14; // [esp+20h] [ebp-4h]
  float v15; // [esp+30h] [ebp+Ch]
  float v16; // [esp+34h] [ebp+10h]
  float v17; // [esp+34h] [ebp+10h]

  v14 = cos(a3);
  v13 = sin(a3);
  v10 = *a2;
  v16 = 1.0 - v14;
  v11 = a2[1];
  v12 = a2[2];
  ThunkTo();
  result = a1;
  v4 = v16;
  v17 = v11 * v10 * v16;
  v5 = v11 * v12 * v4;
  v6 = v12 * v10 * v4;
  *a1 = v10 * v10 * v4 + v14;
  v7 = v12 * v13;
  a1[1] = v17 + v7;
  v8 = v11 * v13;
  v15 = v8;
  a1[2] = v6 - v8;
  a1[3] = 0.0;
  a1[4] = v17 - v7;
  a1[5] = v11 * v11 * v4 + v14;
  v9 = v10 * v13;
  a1[6] = v9 + v5;
  a1[7] = 0.0;
  a1[8] = v15 + v6;
  a1[9] = v5 - v9;
  a1[10] = v12 * v12 * v4 + v14;
  a1[11] = 0.0;
  a1[12] = 0.0;
  a1[13] = 0.0;
  a1[14] = 0.0;
  a1[15] = 1.0;
  return result;
}
