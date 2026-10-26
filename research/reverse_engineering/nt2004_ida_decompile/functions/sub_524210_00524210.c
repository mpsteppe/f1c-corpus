float *__thiscall sub_524210(int this, float a2, float a3, float *a4, float *a5)
{
  float *result; // eax

  if ( *(_BYTE *)(this + 520) )
  {
    *a5 = (a3 + *(double *)(this + 788)) * *(double *)(this + 580)
        + a2 * *(double *)(this + 572) * a2
        + a2 * *(double *)(this + 564)
        + *(double *)(this + 556);
    result = a4;
    *a4 = fabs(*(double *)(this + 636));
    a4[1] = fabs(*(double *)(this + 692));
    a4[2] = a2 * *(double *)(this + 548) * a2 + a2 * *(double *)(this + 540) + *(double *)(this + 532);
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
