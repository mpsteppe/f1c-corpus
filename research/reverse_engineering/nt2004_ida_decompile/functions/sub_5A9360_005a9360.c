int __thiscall sub_5A9360(_DWORD *this)
{
  int v2; // esi
  int i; // eax
  bool v4; // zf

  v2 = this[72];
  if ( v2 )
  {
    for ( i = *(_DWORD *)(v2 + 32); i; i = *(_DWORD *)(v2 + 32) )
    {
      v4 = v2 == 0;
      v2 = i;
      if ( !v4 )
        sub_5BE8AE();
    }
    sub_5BE8AE();
    this[72] = 0;
  }
  return 0;
}
