int __thiscall sub_43A200(double *this, double a2, double a3, double a4, double a5, int a6)
{
  int result; // eax

  result = a6;
  *this = a2;
  *((_DWORD *)this + 12) = a6;
  this[1] = a3;
  this[2] = a4;
  this[3] = a5;
  this[4] = 9.999999933815813e36;
  return result;
}
