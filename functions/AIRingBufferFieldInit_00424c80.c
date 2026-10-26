int __thiscall sub_424C80(float *this)
{
  int result; // eax
  double v2; // st7

  result = dword_8AAE70 + 1;
  v2 = flt_8AAE74[(unsigned __int8)dword_8AAE70++] * 0.15000001;
  this[4370] = v2 + 0.15000001 - (double)dword_7D01A0 * 0.0099999998 * 0.1;
  return result;
}
