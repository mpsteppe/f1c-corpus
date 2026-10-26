double *__thiscall sub_43AEE0(double *this, double *a2, double *a3, double *a4)
{
  double v4; // st6
  double *result; // eax
  double v6; // [esp+10h] [ebp-8h]

  v4 = this[3] * *a3 + this[5] * a3[2] + this[4] * a3[1];
  result = a2;
  v6 = this[6] * *a3 + this[8] * a3[2] + this[7] * a3[1];
  *a4 = this[2] * a3[2] + this[1] * a3[1] + *a3 * *this + *a2;
  a4[1] = v4 + a2[1];
  a4[2] = v6 + a2[2];
  return result;
}

