char __fastcall sub_55393F(int a1, int a2)
{
  _DWORD *v2; // ecx
  char result; // al
  int v4; // edx

  if ( *(_BYTE *)(a2 + 72) )
    return 0;
  if ( *(_BYTE *)(a2 + 264) )
    return 0;
  if ( *(_DWORD *)(a2 + 36) != 3 )
    return 0;
  if ( *(_DWORD *)(a2 + 32) != 3 )
    return 0;
  if ( *(_DWORD *)(a2 + 40) != 2 )
    return 0;
  if ( *(_DWORD *)(a2 + 100) != 3 )
    return 0;
  v2 = *(_DWORD **)(a2 + 196);
  if ( v2[2] != 2 )
    return 0;
  result = 1;
  if ( v2[23] != 1 )
    return 0;
  if ( v2[44] != 1 )
    return 0;
  if ( (int)v2[3] > 2 )
    return 0;
  if ( v2[24] != 1 )
    return 0;
  if ( v2[45] != 1 )
    return 0;
  v4 = *(_DWORD *)(a2 + 276);
  if ( v2[9] != v4 || v2[30] != v4 || v2[51] != v4 )
    return 0;
  return result;
}
