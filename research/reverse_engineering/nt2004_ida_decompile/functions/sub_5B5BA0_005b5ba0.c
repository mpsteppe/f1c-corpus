float *__thiscall sub_5B5BA0(float *this, unsigned int a2, float *a3)
{
  float *result; // eax

  if ( a2 <= 5 )
  {
    result = &this[4 * a2];
    result[21] = *a3;
    result[22] = a3[1];
    result[23] = a3[2];
    this[4 * a2 + 24] = -a3[3];
  }
  return result;
}
