int __thiscall sub_5E2E00(_DWORD *this, int a2)
{
  int v4; // ecx

  if ( (*this & 0x40000) != 0 && this[56] )
  {
    if ( byte_FB2740 )
    {
      sub_5F4CF0(this[55], 0, 0, 0);
      *(_DWORD *)this[55] &= ~0x100u;
      return this[55];
    }
  }
  else
  {
    v4 = this[55];
    if ( v4 && a2 >= 0 && a2 < this[1] )
      return v4 + 216 * a2;
  }
  return 0;
}
