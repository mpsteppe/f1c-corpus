float *__thiscall sub_416420(float *this, float *a2, float *a3, float *a4)
{
  float *result; // eax

  *a4 = this[2] * a3[2] + this[1] * a3[1] + *a3 * *this;
  a4[1] = this[3] * *a3 + this[5] * a3[2] + this[4] * a3[1];
  result = a2;
  a4[2] = this[6] * *a3 + this[8] * a3[2] + this[7] * a3[1];
  *a4 = *a2 + *a4;
  a4[1] = a2[1] + a4[1];
  a4[2] = a2[2] + a4[2];
  return result;
}
