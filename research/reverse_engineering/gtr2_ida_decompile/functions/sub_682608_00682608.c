int __thiscall sub_682608(_DWORD *this, int a2)
{
  int v2; // eax
  int v3; // edx
  int v4; // eax
  int v5; // ecx

  v2 = a2;
  if ( a2 == -1 )
    return 0;
  v3 = this[5];
  while ( 1 )
  {
    v4 = *(_DWORD *)(v3 + 4 * v2);
    if ( (*(_BYTE *)v4 & 0x20) != 0 )
      break;
    v5 = *(_DWORD *)(v4 + 56);
    if ( v5 != -1 && (**(_BYTE **)(v3 + 4 * v5) & 0x20) != 0 )
      break;
    v2 = *(_DWORD *)(v4 + 8);
    if ( v2 == -1 )
      return 0;
  }
  return 1;
}
