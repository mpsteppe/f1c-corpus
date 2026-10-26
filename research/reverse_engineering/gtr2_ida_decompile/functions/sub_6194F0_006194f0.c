double *__thiscall sub_6194F0(double *this, double *a2, double *a3)
{
  double *result; // eax
  double v5; // st6
  double v6; // [esp+10h] [ebp-8h]

  result = a3;
  this[39] = this[39] - *a3;
  this[40] = this[40] - a3[1];
  this[41] = this[41] - a3[2];
  v5 = a2[2] * *result - result[2] * *a2;
  v6 = result[1] * *a2 - *result * a2[1];
  this[42] = this[42] - (a3[2] * a2[1] - a2[2] * a3[1]);
  this[43] = this[43] - v5;
  this[44] = this[44] - v6;
  return result;
}
