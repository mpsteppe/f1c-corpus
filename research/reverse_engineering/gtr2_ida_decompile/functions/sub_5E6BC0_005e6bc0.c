void __thiscall sub_5E6BC0(_DWORD *this, _DWORD *a2, _DWORD *a3)
{
  if ( a2 && a3 && (*this & 0x80000) != 0 )
  {
    if ( ((unsigned int)&byte_800000 & *a3) == 0 )
      *a3 |= 0x400u;
    if ( !a2[156] && !sub_59D540(this + 161, (int)a2) )
    {
      sub_5FDFB0(a2, 0);
      *a2 |= (unsigned int)&dword_2000000;
    }
  }
}
