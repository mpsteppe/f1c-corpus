float *__thiscall sub_4B2580(__int16 *this, float *a2)
{
  float *result; // eax

  result = a2;
  *a2 = (double)this[15] * 0.02;
  a2[1] = (double)this[16] * 0.02;
  a2[2] = (double)this[17] * 0.02;
  return result;
}
