float *__thiscall sub_585DC0(double *this, float a2, float *a3, float *a4)
{
  float *result; // eax

  if ( *(_BYTE *)this )
  {
    result = a3;
    *a3 = a2 * this[3] * a2 + a2 * this[2] + this[1];
    *a4 = a2 * this[6] * a2 + a2 * this[5] + this[4];
  }
  else
  {
    result = a4;
    *a3 = 0.0;
    *a4 = 0.0;
  }
  return result;
}
