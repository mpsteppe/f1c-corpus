float *__thiscall sub_586100(int this, float a2, float *a3, float *a4)
{
  float *result; // eax

  if ( *(_BYTE *)(this + 824) )
  {
    *a4 = a2 * *(double *)(this + 872) * a2 + a2 * *(double *)(this + 864) + *(double *)(this + 856);
    result = a3;
    *a3 = fabs(*(double *)(this + 928));
    a3[1] = fabs(*(double *)(this + 984));
    a3[2] = a2 * *(double *)(this + 848) * a2 + a2 * *(double *)(this + 840) + *(double *)(this + 832);
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
