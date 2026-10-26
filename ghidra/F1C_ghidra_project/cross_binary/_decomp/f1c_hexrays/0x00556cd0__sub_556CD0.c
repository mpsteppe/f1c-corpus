// f1c  0x00556cd0  size=139
int __thiscall sub_556CD0(_DWORD *this, int a2, int a3)
{
  int result; // eax
  _DWORD *i; // edi
  int v6; // esi
  int j; // ebx

  if ( this[17] )
    result = sub_556CD0(a2, 1);
  if ( this[19] )
  {
    result = a3;
    if ( a3 )
      result = sub_556CD0(a2, 1);
  }
  for ( i = (_DWORD *)this[129]; i; i = (_DWORD *)i[4] )
  {
    result = i[70];
    v6 = i[71];
    for ( j = 0; j < result; ++j )
    {
      *(_DWORD *)(v6 + 56) |= 0x400u;
      sub_55D720(a2, 1);
      result = i[70];
      v6 += 64;
    }
    i[5] &= ~0x10000000u;
  }
  return result;
}
