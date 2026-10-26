double *__thiscall sub_43A660(double *this, double *a2)
{
  double *result; // eax

  result = a2;
  this[39] = this[39] + *a2;
  this[40] = a2[1] + this[40];
  this[41] = a2[2] + this[41];
  return result;
}
