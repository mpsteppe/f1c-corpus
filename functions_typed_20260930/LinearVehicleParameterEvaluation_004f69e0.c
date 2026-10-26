float *__thiscall sub_4F69E0(int this, float a2, float a3, float a4, float *a5, float *a6)
{
  float *result; // eax

  *a6 = a2 * *(double *)(this + 1328) + a3 * *(double *)(this + 1312) + *(double *)(this + 1196);
  result = a5;
  *a5 = fabs(*(double *)(this + 1092));
  a5[1] = fabs(*(double *)(this + 1148));
  a5[2] = a2 * *(double *)(this + 1320)
        + a3 * *(double *)(this + 1304)
        + a4 * *(double *)(this + 1020)
        + *(double *)(this + 1012);
  return result;
}

