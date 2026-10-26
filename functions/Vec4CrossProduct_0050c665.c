float *__stdcall sub_50C665(float *a1, float *a2, float *a3, float *a4)
{
  double v6; // st7
  double v8; // st6
  double v9; // st7
  double v10; // st6
  float *result; // eax
  float v12; // [esp+8h] [ebp-1Ch]
  float v13; // [esp+Ch] [ebp-18h]
  float v14; // [esp+10h] [ebp-14h]
  float v15; // [esp+14h] [ebp-10h]
  float v16; // [esp+18h] [ebp-Ch]
  float v17; // [esp+1Ch] [ebp-8h]
  float v18; // [esp+20h] [ebp-4h]
  float v19; // [esp+30h] [ebp+Ch]
  float v20; // [esp+34h] [ebp+10h]
  float v21; // [esp+38h] [ebp+14h]

  v6 = a4[3] * a3[2];
  v8 = a3[3] * a4[2];
  v20 = a4[3] * a3[1] - a3[3] * a4[1];
  v17 = a3[1] * a4[2];
  v18 = a3[2] * a4[1];
  v12 = (v6 - v8) * a2[1] - v20 * a2[2] + (v17 - v18) * a2[3];
  v19 = a3[3] * *a4;
  v21 = a4[3] * *a3;
  v16 = *a4 * a3[2] - *a3 * a4[2];
  v13 = (v8 - v6) * *a2 - (v19 - v21) * a2[2] + v16 * a2[3];
  v9 = *a3 * a4[1];
  v10 = *a4 * a3[1];
  v14 = v20 * *a2 - (v21 - v19) * a2[1] + (v9 - v10) * a2[3];
  result = a1;
  v15 = (v18 - v17) * *a2 - v16 * a2[1] + (v10 - v9) * a2[2];
  *a1 = v12;
  a1[1] = v13;
  a1[2] = v14;
  a1[3] = v15;
  return result;
}
