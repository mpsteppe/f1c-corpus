int __cdecl sub_54FC20(unsigned __int8 *a1, unsigned __int8 *a2)
{
  int v2; // eax
  int v3; // esi
  char *v4; // ecx
  int v5; // edi
  char *v6; // edx
  int v7; // eax
  int v8; // esi
  int v10; // ebx
  int v11; // eax
  int v12; // esi
  int v13; // eax
  int v14; // esi

  v4 = (char *)&unk_924FE8 + 22616 * *a1;
  v5 = *((_DWORD *)v4 + 27);
  v6 = (char *)&unk_924FE8 + 22616 * *a2;
  if ( v5 == 3 )
  {
    if ( *((_DWORD *)v6 + 27) != 3 )
      return 1;
    v7 = *((_DWORD *)v6 + 13);
    v8 = *((_DWORD *)v4 + 13);
    if ( v8 < v7 )
      return -1;
    if ( v8 > v7 )
      return 1;
    if ( v6 > v4 )
      return -1;
    return v6 < v4;
  }
  v10 = *((_DWORD *)v6 + 27);
  if ( v10 == 3 )
    return -1;
  v11 = *((_DWORD *)v6 + 3);
  v12 = *((_DWORD *)v4 + 3);
  if ( v12 > v11 )
    return -1;
  if ( v12 < v11 )
    return 1;
  if ( v5 != 1 )
  {
    if ( v10 != 1 )
    {
      v13 = *((_DWORD *)v6 + 4);
      v14 = *((_DWORD *)v4 + 4);
      if ( v14 <= v13 )
      {
        if ( v14 < v13 )
          return 1;
        if ( *((float *)v4 + 5) > (double)*((float *)v6 + 5) )
          return -1;
        if ( *((float *)v4 + 5) < (double)*((float *)v6 + 5) )
          return 1;
        goto LABEL_25;
      }
    }
    return -1;
  }
  if ( v10 != 1 )
    return 1;
  if ( *((float *)v4 + 48) < (double)*((float *)v6 + 48) )
    return -1;
  if ( *((float *)v4 + 48) > (double)*((float *)v6 + 48) )
    return 1;
LABEL_25:
  v2 = *((_DWORD *)v4 + 13);
  v3 = *((_DWORD *)v6 + 13);
  if ( v2 < v3 )
    return -1;
  if ( v2 > v3 )
    return 1;
  if ( v6 <= v4 )
    return v6 < v4;
  else
    return -1;
}
