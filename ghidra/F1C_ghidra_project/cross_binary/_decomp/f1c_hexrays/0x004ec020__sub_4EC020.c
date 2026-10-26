// f1c  0x004ec020  size=33
float *__thiscall sub_4EC020(float *this, float *a2)
{
  float *result; // eax

  result = this;
  *this = *a2 + *this;
  this[1] = a2[1] + this[1];
  this[2] = a2[2] + this[2];
  return result;
}
