float *__thiscall sub_4F8850(float *this, int a2, int a3, float a4, float a5, float *a6)
{
  float *result; // eax

  HUDElementConfig(this, a2, a3, a4, a5);
  LOBYTE(this[8 * a2 + 49]) = 1;
  result = &this[8 * a2 + 50];
  *result = *a6;
  result[1] = a6[1];
  result[2] = a6[2];
  return result;
}
