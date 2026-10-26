int __thiscall sub_5AE470(_DWORD *this, int a2, int a3)
{
  int result; // eax
  _DWORD *i; // edi
  int v6; // esi
  int j; // ebx

  if ( this[17] )
    result = sub_5AE470(a2, 1);
  if ( this[19] )
  {
    result = a3;
    if ( a3 )
      result = sub_5AE470(a2, 1);
  }
  for ( i = (_DWORD *)this[129]; i; i = (_DWORD *)i[4] )
  {
    result = i[70];
    v6 = i[71];
    for ( j = 0; j < result; ++j )
    {
      *(_DWORD *)(v6 + 56) |= 0x400u;
      sub_5B5DC0(a2, 1);
      result = i[70];
      v6 += 64;
    }
    i[5] &= ~0x10000000u;
  }
  return result;
}
