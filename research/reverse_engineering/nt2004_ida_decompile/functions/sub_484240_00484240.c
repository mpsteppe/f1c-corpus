int __thiscall sub_484240(_DWORD *this, int a2)
{
  int v2; // esi
  int i; // edx
  int v4; // eax
  int v5; // eax

  v2 = this[218];
  i = -1;
  if ( v2 )
  {
    v4 = this[216];
    for ( i = 0; v4; ++i )
    {
      if ( v4 == v2 )
        break;
      v4 = *(_DWORD *)(v4 + 4);
    }
  }
  v5 = i;
  if ( a2 )
  {
    if ( a2 == 1 )
      v5 = i + 1;
  }
  else
  {
    v5 = i - 1;
  }
  if ( v5 < 0 )
    return sub_4845B0(this[219] - 1);
  if ( v5 >= this[219] )
    v5 = 0;
  return sub_4845B0(v5);
}
