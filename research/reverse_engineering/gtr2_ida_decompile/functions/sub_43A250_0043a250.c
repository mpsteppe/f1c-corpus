double *__thiscall sub_43A250(double *this, double *a2, double a3)
{
  double *result; // eax
  double v4; // st7
  double v5; // [esp+8h] [ebp-10h]

  result = a2;
  v5 = a3 * this[1];
  v4 = a3 * this[2];
  *a2 = a3 * *this;
  a2[1] = v5;
  a2[2] = v4;
  return result;
}
