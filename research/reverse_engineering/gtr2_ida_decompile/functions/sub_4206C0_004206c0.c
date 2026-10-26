int __thiscall sub_4206C0(float *this)
{
  int result; // eax
  double v2; // st7

  result = dword_BE08A0 + 1;
  v2 = flt_BE08A4[(unsigned __int8)dword_BE08A0++] * 0.15000001;
  this[5121] = v2 + 0.15000001 - (double)dword_B71FD8 * 0.0099999998 * 0.1;
  return result;
}
