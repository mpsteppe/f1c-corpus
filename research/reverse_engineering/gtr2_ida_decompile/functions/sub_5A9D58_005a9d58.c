float *__stdcall sub_5A9D58(float *a1, float *a2, float *a3)
{
  float *result; // eax
  float v4; // [esp+8h] [ebp-Ch]
  float v5; // [esp+Ch] [ebp-8h]
  float v6; // [esp+10h] [ebp-4h]

  v4 = a3[8] * a2[2] + a3[4] * a2[1] + *a2 * *a3;
  v5 = a3[9] * a2[2] + a3[5] * a2[1] + a3[1] * *a2;
  result = a1;
  v6 = a3[10] * a2[2] + a3[6] * a2[1] + a3[2] * *a2;
  *a1 = v4;
  a1[1] = v5;
  a1[2] = v6;
  return result;
}
