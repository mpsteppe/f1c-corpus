void __thiscall sub_5FCDB0(_DWORD *this, int a2, int a3, int a4)
{
  _DWORD *v4; // eax

  if ( (*this & 0x200) != 0 && a2 < this[11] )
  {
    v4 = (_DWORD *)(this[13] + 132 * a2);
    if ( (*v4 & 0x100) != 0 )
    {
      if ( (*this & 0x400) != 0 )
        *(_DWORD *)(v4[32] + (a3 << 6) + 24) = a4;
      *this |= 0x80000u;
    }
  }
}
