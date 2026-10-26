int __thiscall sub_4DC2C0(_DWORD *this)
{
  int v2; // ecx

  if ( (unsigned int)dword_75CBB0 <= 6 )
  {
    v2 = *this;
    if ( *(_DWORD *)(*this + 16584) <= 1u )
    {
      sub_515870(v2 + 84);
      if ( this[29] == 2 )
        this[29] = 1;
      this[6] = -1082130432;
      this[7] = -1082130432;
      this[8] = -1082130432;
    }
  }
  *((_BYTE *)this + 36) = 0;
  this[50] = 0;
  *((_BYTE *)this + 188) = 0;
  this[48] = 0;
  *((_BYTE *)this + 204) = 0;
  this[52] = 0;
  this[53] = 0;
  this[54] = 0;
  this[55] = -8388609;
  this[56] = -8388609;
  this[57] = -1;
  this[58] = 0;
  this[59] = 0;
  this[60] = 0;
  this[61] = 0;
  *((_BYTE *)this + 248) = 0;
  this[69] = 0;
  this[70] = 0;
  this[82] = -2;
  return sub_4DEB50(0);
}
