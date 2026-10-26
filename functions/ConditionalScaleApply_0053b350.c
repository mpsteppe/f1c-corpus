int __thiscall sub_53B350(float *this)
{
  int result; // eax
  double v2; // st7

  result = *(_DWORD *)this;
  if ( (*(_DWORD *)this & 2) != 0 )
  {
    result &= ~2u;
    v2 = this[7] * this[10];
    *(_DWORD *)this = result;
    this[10] = v2;
    this[11] = this[7] * this[11];
    this[12] = this[7] * this[12];
    this[14] = this[8] * this[14];
    this[15] = this[15] * this[8];
    this[16] = this[16] * this[8];
    this[18] = this[18] * this[9];
    this[19] = this[19] * this[9];
    this[20] = this[20] * this[9];
  }
  return result;
}
