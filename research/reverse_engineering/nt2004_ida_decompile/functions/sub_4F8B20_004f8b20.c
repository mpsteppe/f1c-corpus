int __cdecl sub_4F8B20(unsigned __int8 *a1, unsigned __int8 *a2)
{
  char *v2; // edx
  int v3; // edi
  char *v4; // ecx
  int v5; // eax
  int v6; // esi
  int v8; // ebx
  int v9; // eax
  int v10; // esi
  int v11; // eax
  int v12; // esi

  v2 = (char *)&unk_6310CC + 25304 * *a1;
  v3 = *((_DWORD *)v2 + 14);
  v4 = (char *)&unk_6310CC + 25304 * *a2;
  if ( v3 == 3 )
  {
    if ( *((_DWORD *)v4 + 14) == 3 )
      goto LABEL_3;
    return 1;
  }
  v8 = *((_DWORD *)v4 + 14);
  if ( v8 == 3 )
    return -1;
  v9 = *((_DWORD *)v4 + 3);
  v10 = *((_DWORD *)v2 + 3);
  if ( v10 > v9 )
    return -1;
  if ( v10 < v9 )
    return 1;
  if ( v3 == 1 )
  {
    if ( v8 != 1 )
      return 1;
    if ( *((float *)v4 + 38) > (double)*((float *)v2 + 38) )
      return -1;
    if ( *((float *)v4 + 38) < (double)*((float *)v2 + 38) )
      return 1;
  }
  else
  {
    if ( v8 == 1 )
      return -1;
    if ( v2[36] )
    {
      if ( !v4[36] )
        return 1;
    }
    else if ( v4[36] )
    {
      return -1;
    }
    v11 = *((_DWORD *)v4 + 4);
    v12 = *((_DWORD *)v2 + 4);
    if ( v12 > v11 )
      return -1;
    if ( v12 < v11 )
      return 1;
    if ( *((float *)v4 + 5) < (double)*((float *)v2 + 5) )
      return -1;
    if ( *((float *)v4 + 5) > (double)*((float *)v2 + 5) )
      return 1;
  }
LABEL_3:
  v5 = *((_DWORD *)v4 + 12);
  v6 = *((_DWORD *)v2 + 12);
  if ( v6 < v5 )
    return -1;
  if ( v6 > v5 )
    return 1;
  return v2 < v4 ? -1 : 1;
}
