float *__thiscall sub_4F6950(int this, float a2, float *a3, float *a4)
{
  float *result; // eax

  if ( *(_BYTE *)(this + 760) )
  {
    *a4 = a2 * *(double *)(this + 804) * a2 + a2 * *(double *)(this + 796) + *(double *)(this + 788);
    result = a3;
    *a3 = fabs(*(double *)(this + 844));
    a3[1] = fabs(*(double *)(this + 900));
    a3[2] = a2 * *(double *)(this + 780) * a2 + a2 * *(double *)(this + 772) + *(double *)(this + 764);
  }
  else
  {
    result = a3;
    *a4 = 0.0;
    *a3 = 0.0;
    a3[1] = 0.0;
    a3[2] = 0.0;
  }
  return result;
}
