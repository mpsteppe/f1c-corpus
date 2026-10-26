int __thiscall sub_5B5AD0(float *this, float a2, float a3, float a4)
{
  long double v4; // st7
  long double v5; // st7
  int result; // eax

  this[17] = a2;
  this[19] = a4;
  this[18] = a3;
  v4 = sqrt(a2 * a2 + a3 * a3 + a4 * a4);
  if ( v4 != 0.0 )
  {
    v5 = 1.0 / v4;
    this[17] = a2 * v5;
    this[18] = a3 * v5;
    this[19] = v5 * a4;
  }
  result = dword_7E8E5C;
  *(_DWORD *)(dword_7E8E5C + 240) |= 0x800u;
  return result;
}
