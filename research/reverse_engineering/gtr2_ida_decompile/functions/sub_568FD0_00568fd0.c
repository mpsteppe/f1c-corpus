float *__thiscall sub_568FD0(float *this, float *a2, float *a3)
{
  float *result; // eax

  result = a2;
  *this = *a2 * *a3 + a3[6] * a2[2] + a3[3] * a2[1];
  this[1] = a3[4] * a2[1] + *a2 * a3[1] + a3[7] * a2[2];
  this[2] = a3[2] * *a2 + a3[5] * a2[1] + a3[8] * a2[2];
  this[3] = a2[5] * a3[6] + a3[3] * a2[4] + a2[3] * *a3;
  this[4] = a3[4] * a2[4] + a2[3] * a3[1] + a2[5] * a3[7];
  this[5] = a2[5] * a3[8] + a3[2] * a2[3] + a3[5] * a2[4];
  this[6] = a2[6] * *a3 + a2[7] * a3[3] + a2[8] * a3[6];
  this[7] = a2[7] * a3[4] + a2[6] * a3[1] + a2[8] * a3[7];
  this[8] = a2[8] * a3[8] + a2[7] * a3[5] + a3[2] * a2[6];
  return result;
}
