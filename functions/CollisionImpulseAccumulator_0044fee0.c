double *__thiscall sub_44FEE0(double *this, double *a2, double *a3)
{
  double *result; // eax

  this[172] = this[172] + *a2;
  this[173] = a2[1] + this[173];
  result = a3;
  this[174] = a2[2] + this[174];
  this[175] = this[175] + *a3;
  this[176] = a3[1] + this[176];
  this[177] = a3[2] + this[177];
  return result;
}
