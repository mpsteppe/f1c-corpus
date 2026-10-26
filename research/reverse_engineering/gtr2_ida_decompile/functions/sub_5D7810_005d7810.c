float *__stdcall sub_5D7810(float *a1, float *a2, float *a3)
{
  float *result; // eax

  result = a3;
  *a2 = a3[8] * a1[2] + a3[4] * a1[1] + *a1 * *a3 + a3[12];
  a2[1] = a3[9] * a1[2] + a3[5] * a1[1] + a3[1] * *a1 + a3[13];
  a2[2] = a3[10] * a1[2] + a3[6] * a1[1] + a3[2] * *a1 + a3[14];
  return result;
}
