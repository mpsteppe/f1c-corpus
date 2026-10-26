int __thiscall sub_65E255(int this, _BYTE *a2, int *a3)
{
  unsigned int v3; // edi
  int v4; // eax
  int v5; // ecx
  char *i; // esi
  char v7; // dl

  v3 = *(_DWORD *)(this + 4);
  if ( (unsigned int)a2 >= v3 || *a2 != 48 )
    return 0;
  v4 = 0;
  v5 = 0;
  for ( i = a2 + 1; (unsigned int)i < v3; ++i )
  {
    v7 = *i;
    if ( *i < 48 || v7 > 55 )
      break;
    if ( (v4 & 0xE0000000) != 0 )
      v5 = 1;
    v4 = v7 + 8 * v4 - 48;
  }
  if ( a3 )
    *a3 = v4;
  if ( v5 )
    sub_65DD1F(*(_DWORD **)(this + 48), this + 8, 1003, "octal value truncated to 32bits");
  return i - a2;
}
