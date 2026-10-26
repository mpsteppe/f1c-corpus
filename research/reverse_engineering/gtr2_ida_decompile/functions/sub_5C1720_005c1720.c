float *__fastcall sub_5C1720(float *a1, float *a2, float *a3)
{
  long double v3; // st4
  long double v4; // st7
  double v5; // st6
  double v6; // st5
  long double v7; // st4
  long double v8; // st4
  double v9; // st3
  double v10; // st2
  double v11; // st4
  float *result; // eax
  float v13; // [esp+0h] [ebp-1Ch]
  float v14; // [esp+0h] [ebp-1Ch]
  float v15; // [esp+4h] [ebp-18h]
  float v16; // [esp+8h] [ebp-14h]
  float v17; // [esp+Ch] [ebp-10h]
  float v18; // [esp+Ch] [ebp-10h]
  float v19; // [esp+10h] [ebp-Ch]
  float v20; // [esp+14h] [ebp-8h]
  float v21; // [esp+14h] [ebp-8h]
  float v22; // [esp+18h] [ebp-4h]
  float v23; // [esp+18h] [ebp-4h]

  v3 = sqrt(*a1 * *a1 + a1[1] * a1[1] + a1[2] * a1[2]);
  v13 = 1.0 / v3;
  v4 = 1.0 / v3 * *a1;
  v5 = v13 * a1[1];
  v6 = v13 * a1[2];
  v7 = v6 * a2[2] + v5 * a2[1] + v4 * *a2;
  v20 = v5 * v7;
  v22 = v6 * v7;
  v8 = *a2 - v4 * v7;
  v9 = a2[1] - v20;
  v10 = a2[2] - v22;
  v17 = v10;
  v14 = 1.0 / sqrt(v10 * v17 + v9 * v9 + v8 * v8);
  v15 = v8 * v14;
  v16 = v9 * v14;
  v11 = v17 * v14;
  v18 = v11;
  v19 = v11 * v5 - v16 * v6;
  result = a3;
  v21 = v15 * v6 - v18 * v4;
  a3[4] = v15;
  a3[5] = v16;
  a3[6] = v18;
  a3[8] = v19;
  a3[9] = v21;
  v23 = v16 * v4 - v5 * v15;
  a3[10] = v23;
  *a3 = v4;
  a3[1] = v5;
  a3[2] = v6;
  return result;
}
