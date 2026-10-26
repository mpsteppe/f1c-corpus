float *__thiscall sub_586060(int this, float a2, float a3, float *a4, float *a5)
{
  float *result; // eax

  if ( *(_BYTE *)(this + 536) )
  {
    *a5 = (a3 + *(double *)(this + 808)) * *(double *)(this + 600)
        + a2 * *(double *)(this + 592) * a2
        + a2 * *(double *)(this + 584)
        + *(double *)(this + 576);
    result = a4;
    *a4 = fabs(*(double *)(this + 656));
    a4[1] = fabs(*(double *)(this + 712));
    a4[2] = a2 * *(double *)(this + 568) * a2 + a2 * *(double *)(this + 560) + *(double *)(this + 552);
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
