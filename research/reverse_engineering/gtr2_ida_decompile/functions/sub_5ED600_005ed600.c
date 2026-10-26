bool __thiscall sub_5ED600(_DWORD *this, int a2)
{
  int v2; // edx
  int v3; // eax
  int v4; // eax

  v2 = a2;
  v3 = this[136];
  if ( a2 >= v3 )
    return 0;
  if ( a2 < 0 || a2 >= v3 )
    return (MEMORY[0] & 0x100000) != 0;
  v4 = this[133];
  if ( a2 > 0 )
  {
    while ( v4 )
    {
      v4 = *(_DWORD *)(v4 + 4);
      if ( --v2 <= 0 )
        goto LABEL_7;
    }
    return (MEMORY[0] & 0x100000) != 0;
  }
LABEL_7:
  if ( !v4 )
    return (MEMORY[0] & 0x100000) != 0;
  return (**(_DWORD **)v4 & 0x100000) != 0;
}
