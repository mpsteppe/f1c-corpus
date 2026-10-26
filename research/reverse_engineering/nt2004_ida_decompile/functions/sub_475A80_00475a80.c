BOOL __thiscall sub_475A80(_DWORD *this, int a2)
{
  const char *v3; // esi
  const char *v4; // eax
  CHAR *v5; // esi
  CHAR *v6; // eax
  bool v7; // cf
  unsigned __int8 v8; // dl
  unsigned __int8 v9; // bl
  CHAR *v11; // esi
  CHAR *v12; // eax
  unsigned __int8 v13; // dl
  unsigned __int8 v14; // bl

  v3 = *(const char **)(a2 + 4);
  if ( !v3 )
    v3 = &byte_629120;
  v4 = (const char *)this[1];
  if ( !v4 )
    v4 = &byte_629120;
  if ( !strcmp(v4, v3) )
  {
    v11 = *(CHAR **)(a2 + 12);
    if ( !v11 )
      v11 = &byte_629120;
    v12 = (CHAR *)this[3];
    if ( !v12 )
      v12 = &byte_629120;
    while ( 1 )
    {
      v7 = (unsigned __int8)*v12 < (unsigned __int8)*v11;
      if ( *v12 != *v11 )
        break;
      if ( *v12 )
      {
        v13 = v12[1];
        v14 = v11[1];
        v7 = v13 < v14;
        if ( v13 != v14 )
          return -v7 - (v7 - 1) < 0;
        v12 += 2;
        v11 += 2;
        if ( v13 )
          continue;
      }
      return 0;
    }
  }
  else
  {
    v5 = *(CHAR **)(a2 + 4);
    if ( !v5 )
      v5 = &byte_629120;
    v6 = (CHAR *)this[1];
    if ( !v6 )
      v6 = &byte_629120;
    while ( 1 )
    {
      v7 = (unsigned __int8)*v6 < (unsigned __int8)*v5;
      if ( *v6 != *v5 )
        break;
      if ( *v6 )
      {
        v8 = v6[1];
        v9 = v5[1];
        v7 = v8 < v9;
        if ( v8 != v9 )
          return -v7 - (v7 - 1) < 0;
        v6 += 2;
        v5 += 2;
        if ( v8 )
          continue;
      }
      return 0;
    }
  }
  return -v7 - (v7 - 1) < 0;
}
