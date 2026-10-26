float *__stdcall sub_5A9AE3(float *a1, float *a2, float *a3)
{
  float *result; // eax
  float v4; // [esp+8h] [ebp-10h]
  float v5; // [esp+Ch] [ebp-Ch]
  float v6; // [esp+10h] [ebp-8h]
  float v7; // [esp+14h] [ebp-4h]

  v4 = a3[8] * a2[2] + a3[4] * a2[1] + *a2 * *a3 + a3[12];
  v5 = a3[9] * a2[2] + a3[5] * a2[1] + a3[1] * *a2 + a3[13];
  v6 = a3[10] * a2[2] + a3[6] * a2[1] + a3[2] * *a2 + a3[14];
  result = a1;
  v7 = a3[11] * a2[2] + a3[7] * a2[1] + a3[3] * *a2 + a3[15];
  *a1 = v4;
  a1[1] = v5;
  a1[2] = v6;
  a1[3] = v7;
  return result;
}
