float *__stdcall sub_5A9AA0(float *a1, float *a2, float *a3, float a4)
{
  float *result; // eax

  result = a1;
  *a3 = (*a2 - *a1) * a4 + *a1;
  a3[1] = (a2[1] - a1[1]) * a4 + a1[1];
  return result;
}
