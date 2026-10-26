float *__stdcall sub_50DD40(float *a1, float a2, float a3, float a4)
{
  float *result; // eax
  double v5; // st7
  double v6; // st6
  double v7; // st7
  double v8; // st6
  float v9; // [esp+8h] [ebp-18h]
  float v10; // [esp+Ch] [ebp-14h]
  float v11; // [esp+10h] [ebp-10h]
  float v12; // [esp+14h] [ebp-Ch]
  float v13; // [esp+18h] [ebp-8h]
  float v14; // [esp+1Ch] [ebp-4h]
  float v15; // [esp+30h] [ebp+10h]
  float v16; // [esp+30h] [ebp+10h]
  float v17; // [esp+34h] [ebp+14h]

  v9 = a4 * 0.5;
  v14 = cos(v9);
  v17 = sin(v9);
  v15 = a3 * 0.5;
  v12 = cos(v15);
  v10 = sin(v15);
  v16 = a2 * 0.5;
  v13 = cos(v16);
  v11 = sin(v16);
  result = a1;
  v5 = v11 * v12;
  v6 = v13 * v10;
  *a1 = v14 * v6 + v5 * v17;
  a1[1] = v5 * v14 - v6 * v17;
  v7 = v13 * v12;
  v8 = v11 * v10;
  a1[2] = v7 * v17 - v8 * v14;
  a1[3] = v8 * v17 + v7 * v14;
  return result;
}
