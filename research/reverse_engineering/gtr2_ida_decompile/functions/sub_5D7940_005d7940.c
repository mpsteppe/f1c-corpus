float *__stdcall sub_5D7940(float *a1, float *a2, float *a3)
{
  float *result; // eax

  result = a1;
  *a3 = a2[2] * a1[1] - a2[1] * a1[2];
  a3[1] = *a2 * a1[2] - *a1 * a2[2];
  a3[2] = *a1 * a2[1] - *a2 * a1[1];
  return result;
}
