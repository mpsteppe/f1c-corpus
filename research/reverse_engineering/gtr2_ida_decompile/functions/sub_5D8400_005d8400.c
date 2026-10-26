int __thiscall sub_5D8400(float *this)
{
  int result; // eax
  double v2; // st7

  result = *(_DWORD *)this;
  if ( (*(_DWORD *)this & 2) != 0 )
  {
    result &= ~2u;
    v2 = this[1] * this[24];
    *(_DWORD *)this = result;
    this[1] = v2;
    this[2] = this[24] * this[2];
    this[3] = this[24] * this[3];
    this[5] = this[5] * this[25];
    this[6] = this[6] * this[25];
    this[7] = this[7] * this[25];
    this[9] = this[26] * this[9];
    this[10] = this[26] * this[10];
    this[11] = this[26] * this[11];
  }
  return result;
}
