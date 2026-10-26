float *__thiscall sub_520570(char *this, float a2, float *a3, float *a4)
{
  float *result; // eax

  if ( *this )
  {
    result = a3;
    *a3 = a2 * *(double *)(this + 20) * a2 + a2 * *(double *)(this + 12) + *(double *)(this + 4);
    *a4 = a2 * *(double *)(this + 44) * a2 + a2 * *(double *)(this + 36) + *(double *)(this + 28);
  }
  else
  {
    result = a4;
    *a3 = 0.0;
    *a4 = 0.0;
  }
  return result;
}
