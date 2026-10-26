int __cdecl sub_54FB50(unsigned __int8 *a1, unsigned __int8 *a2)
{
  int v2; // eax
  int v3; // esi
  char *v4; // ecx
  char *v5; // edx
  int v6; // esi
  int v7; // eax
  int v8; // esi
  unsigned __int8 v11; // c0
  unsigned __int8 v12; // c2

  v4 = (char *)&unk_924FE8 + 22616 * *a1;
  v5 = (char *)&unk_924FE8 + 22616 * *a2;
  v6 = *((_DWORD *)v5 + 27);
  if ( *((_DWORD *)v4 + 27) == 3 )
  {
    if ( v6 != 3 )
      return 1;
    v7 = *((_DWORD *)v5 + 13);
    v8 = *((_DWORD *)v4 + 13);
    if ( v8 < v7 )
      return -1;
    if ( v8 > v7 )
      return 1;
    if ( v5 > v4 )
      return -1;
    return v5 < v4;
  }
  else
  {
    if ( v6 == 3 )
      return -1;
    if ( v11 | v12 )
    {
      if ( *((float *)v4 + 41) >= 0.0 )
        return -1;
    }
    else
    {
      if ( *((float *)v4 + 41) < 0.0 )
        return 1;
      if ( *((float *)v4 + 41) < (double)*((float *)v5 + 41) )
        return -1;
      if ( *((float *)v4 + 41) > (double)*((float *)v5 + 41) )
        return 1;
    }
    v2 = *((_DWORD *)v4 + 13);
    v3 = *((_DWORD *)v5 + 13);
    if ( v2 < v3 )
      return -1;
    if ( v2 > v3 )
      return 1;
    if ( v5 <= v4 )
      return v5 < v4;
    else
      return -1;
  }
}
