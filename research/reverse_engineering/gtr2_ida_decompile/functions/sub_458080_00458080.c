int __thiscall sub_458080(float *this)
{
  double v1; // st7
  int result; // eax

  v1 = flt_BE08A4[(unsigned __int8)dword_BE08A0];
  result = ++dword_BE08A0;
  this[5] = v1 * this[2];
  return result;
}
