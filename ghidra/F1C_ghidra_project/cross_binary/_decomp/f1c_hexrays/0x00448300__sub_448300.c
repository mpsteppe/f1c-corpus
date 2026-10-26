// f1c  0x00448300  size=33
int __thiscall sub_448300(float *this)
{
  double v1; // st7
  int result; // eax

  v1 = flt_8AAE74[(unsigned __int8)dword_8AAE70];
  result = ++dword_8AAE70;
  this[5] = v1 * this[2];
  return result;
}
