int __thiscall sub_4A3440(_DWORD *this)
{
  int result; // eax
  int v3; // ebx
  int v4; // edi

  if ( (*(_BYTE *)this & 1) != 0 )
  {
    result = this[3];
    v3 = 0;
    if ( result > 0 )
    {
      v4 = 0;
      do
      {
        if ( *(_DWORD *)(v4 + this[4] + 100) )
          sub_54C1A0(*(_DWORD *)(v4 + this[4] + 100));
        result = this[3];
        ++v3;
        v4 += 120;
      }
      while ( v3 < result );
    }
    if ( dword_7CF884 >= 2 && this[5] )
      result = sub_54C1B0(0, 0, 0);
  }
  *this &= 0xFFFFFFFC;
  return result;
}
