float *__thiscall sub_4F68B0(int this, float a2, float a3, float *a4, float *a5)
{
  float *result; // eax

  if ( *(_BYTE *)(this + 492) )
  {
    *a5 = (a3 + *(double *)(this + 744)) * *(double *)(this + 552)
        + a2 * *(double *)(this + 544) * a2
        + a2 * *(double *)(this + 536)
        + *(double *)(this + 528);
    result = a4;
    *a4 = fabs(*(double *)(this + 592));
    a4[1] = fabs(*(double *)(this + 648));
    a4[2] = a2 * *(double *)(this + 520) * a2 + a2 * *(double *)(this + 512) + *(double *)(this + 504);
  }
  else
  {
    result = a4;
    *a5 = 0.0;
    *a4 = 0.0;
    a4[1] = 0.0;
    a4[2] = 0.0;
  }
  return result;
}
