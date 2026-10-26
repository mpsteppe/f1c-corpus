double *__thiscall sub_45F3B0(double *this, double *a2, double *a3)
{
  double *result; // eax

  this[184] = this[184] + *a2;
  this[185] = a2[1] + this[185];
  result = a3;
  this[186] = a2[2] + this[186];
  this[187] = this[187] + *a3;
  this[188] = a3[1] + this[188];
  this[189] = a3[2] + this[189];
  return result;
}
