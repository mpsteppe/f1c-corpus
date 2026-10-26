float *__thiscall sub_524340(int this, float a2, float a3, float a4, float *a5, float *a6)
{
  float *result; // eax

  *a6 = a2 * *(double *)(this + 1404) + a3 * *(double *)(this + 1388) + *(double *)(this + 1256);
  result = a5;
  *a5 = fabs(*(double *)(this + 1152));
  a5[1] = fabs(*(double *)(this + 1208));
  a5[2] = a2 * *(double *)(this + 1396)
        + a3 * *(double *)(this + 1380)
        + a4 * *(double *)(this + 1080)
        + *(double *)(this + 1072);
  return result;
}
