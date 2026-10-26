char __thiscall sub_5D4300(_DWORD *this, int a2)
{
  int v2; // edx
  int v3; // eax
  int v4; // esi
  int v5; // esi
  int v6; // edx
  _DWORD *i; // eax

  v2 = this[14];
  v3 = 0;
  if ( v2 <= 0 )
  {
LABEL_5:
    v5 = this[17];
    v6 = 0;
    if ( v5 <= 0 )
      return 0;
    for ( i = (_DWORD *)(this[19] + 4); *i != *(_DWORD *)(a2 + 400); i += 12 )
    {
      if ( ++v6 >= v5 )
        return 0;
    }
  }
  else
  {
    v4 = this[16];
    while ( *(_DWORD *)(*(_DWORD *)v4 + 12) != a2 )
    {
      ++v3;
      v4 += 4;
      if ( v3 >= v2 )
        goto LABEL_5;
    }
  }
  return 1;
}
