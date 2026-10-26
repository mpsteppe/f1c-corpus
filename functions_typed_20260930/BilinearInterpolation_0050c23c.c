float *__stdcall sub_50C23C(float *a1, float *a2, float *a3, float *a4, float a5, float a6)
{
  float *result; // eax

  result = a1;
  *a1 = (*a3 - *a2) * a5 + (*a4 - *a2) * a6 + *a2;
  a1[1] = (a3[1] - a2[1]) * a5 + (a4[1] - a2[1]) * a6 + a2[1];
  return result;
}

