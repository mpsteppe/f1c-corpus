float *__thiscall sub_586190(int this, float a2, float a3, float a4, float *a5, float *a6)
{
  float *result; // eax

  *a6 = a2 * *(double *)(this + 1496) + a3 * *(double *)(this + 1480) + *(double *)(this + 1280);
  result = a5;
  *a5 = fabs(*(double *)(this + 1176));
  a5[1] = fabs(*(double *)(this + 1232));
  a5[2] = a2 * *(double *)(this + 1488)
        + a3 * *(double *)(this + 1472)
        + a4 * *(double *)(this + 1104)
        + *(double *)(this + 1096);
  return result;
}
