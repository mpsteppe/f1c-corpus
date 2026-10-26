int __cdecl sub_4D0C20(unsigned __int8 *a1, unsigned __int8 *a2)
{
  char *v2; // edx
  char *v3; // ecx
  int v4; // esi
  int v5; // eax
  int v6; // esi
  bool v7; // cc
  unsigned __int8 v10; // c0
  unsigned __int8 v11; // c2
  int v12; // eax
  int v13; // esi

  v2 = (char *)&MEMORY[0x5F070C] + 18624 * *a1;
  v3 = (char *)&MEMORY[0x5F070C] + 18624 * *a2;
  v4 = *((_DWORD *)v3 + 12);
  if ( *((_DWORD *)v2 + 12) == 3 )
  {
    if ( v4 != 3 )
      return 1;
    v5 = *((_DWORD *)v3 + 11);
    v6 = *((_DWORD *)v2 + 11);
    v7 = v6 <= v5;
    if ( v6 < v5 )
      return -1;
  }
  else
  {
    if ( v4 == 3 )
      return -1;
    if ( v10 | v11 )
    {
      if ( *((float *)v2 + 26) >= 0.0 )
        return -1;
    }
    else
    {
      if ( *((float *)v2 + 26) < 0.0 )
        return 1;
      if ( *((float *)v3 + 26) > (double)*((float *)v2 + 26) )
        return -1;
      if ( *((float *)v3 + 26) < (double)*((float *)v2 + 26) )
        return 1;
    }
    v12 = *((_DWORD *)v3 + 11);
    v13 = *((_DWORD *)v2 + 11);
    v7 = v13 <= v12;
    if ( v13 < v12 )
      return -1;
  }
  if ( !v7 )
    return 1;
  if ( v3 > v2 )
    return -1;
  return v3 < v2;
}

