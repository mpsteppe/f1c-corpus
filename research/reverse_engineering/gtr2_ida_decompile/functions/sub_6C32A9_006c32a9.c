int __thiscall sub_6C32A9(int this, int a2)
{
  int v3; // eax
  unsigned int v4; // edx
  _DWORD *i; // eax
  _DWORD *v6; // ecx
  unsigned int v7; // esi
  unsigned int v8; // edi
  _DWORD *v9; // ecx
  unsigned int v11; // [esp+14h] [ebp+8h]

  v3 = *(_DWORD *)(*(_DWORD *)(this + 20) + 4 * a2);
  v4 = *(_DWORD *)(v3 + 84);
  if ( v4 == -1 )
    return 0;
  if ( (*(_BYTE *)(this + 111) & 0x20) != 0 )
    return 0;
  v11 = *(_DWORD *)(v3 + 88);
  if ( v4 > v11 )
    return 0;
  for ( i = (_DWORD *)(*(_DWORD *)(this + 24) + 4 * v4); ; ++i )
  {
    v6 = (_DWORD *)*i;
    if ( (*(_DWORD *)*i & 0xF0000000) == 0x60000000 )
    {
      v7 = v6[1];
      v8 = 0;
      if ( v7 )
        break;
    }
LABEL_10:
    if ( ++v4 > v11 )
      return 0;
  }
  v9 = (_DWORD *)v6[2];
  while ( *v9 != a2 )
  {
    ++v8;
    ++v9;
    if ( v8 >= v7 )
      goto LABEL_10;
  }
  return 1;
}
