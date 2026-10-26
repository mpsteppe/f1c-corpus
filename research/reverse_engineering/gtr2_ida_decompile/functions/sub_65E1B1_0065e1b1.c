int __thiscall sub_65E1B1(int this, _BYTE *a2, int *a3)
{
  char *v4; // edi
  int v5; // esi
  char v6; // al
  int v7; // esi
  int v8; // edi

  v4 = a2 + 2;
  if ( (unsigned int)(a2 + 2) >= *(_DWORD *)(this + 4) || *a2 != 48 || a2[1] != 120 || !isxdigit(*v4) )
    return 0;
  v5 = 0;
  while ( (unsigned int)v4 < *(_DWORD *)(this + 4) && isxdigit(*v4) )
  {
    v6 = *v4;
    v7 = 16 * v5;
    if ( *v4 < 97 )
    {
      if ( v6 < 65 )
        v5 = v7 + v6 - 48;
      else
        v5 = v7 + v6 - 55;
    }
    else
    {
      v5 = v7 + v6 - 87;
    }
    ++v4;
  }
  if ( a3 )
    *a3 = v5;
  v8 = v4 - a2;
  if ( v8 > 10 )
    sub_65DD1F(*(_DWORD **)(this + 48), this + 8, 1002, "hex value truncated to 32bits");
  return v8;
}
