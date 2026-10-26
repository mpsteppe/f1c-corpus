BOOL __stdcall sub_65AE9D(int a1, int a2)
{
  int v2; // eax
  int v3; // ecx
  int v4; // edx
  int i; // ecx
  int v6; // eax
  BOOL v7; // eax
  _BYTE *v9; // esi
  _BYTE *v10; // eax
  bool v11; // cf
  unsigned __int8 v12; // bl
  int v13; // eax
  int v14; // edi
  int j; // edi
  int v16; // eax
  _BYTE *v17; // esi
  _BYTE *v18; // eax
  unsigned __int8 v19; // bl
  int v20; // [esp+Ch] [ebp-Ch]
  int v21; // [esp+10h] [ebp-8h]
  int v22; // [esp+14h] [ebp-4h]
  int v23; // [esp+20h] [ebp+8h]
  int v24; // [esp+24h] [ebp+Ch]

  if ( strcmp(*(const char **)a1, *(const char **)a2) )
    return 0;
  v2 = *(_DWORD *)(a1 + 4);
  v3 = *(_DWORD *)(a2 + 4);
  v21 = v2;
  v20 = v3;
  if ( v2 )
  {
    do
    {
      if ( !v3 )
        break;
      v2 = *(_DWORD *)(v2 + 12);
      v3 = *(_DWORD *)(v3 + 12);
    }
    while ( v2 );
    if ( v2 )
      return 0;
  }
  if ( v3 )
    return 0;
  v4 = *(_DWORD *)(a1 + 8);
  for ( i = *(_DWORD *)(a2 + 8); ; i = *(_DWORD *)(i + 12) )
  {
    v24 = i;
    if ( !v4 )
      break;
    if ( !i )
      return 0;
    v6 = *(_DWORD *)(v4 + 16);
    if ( v6 != *(_DWORD *)(i + 16) )
      return 0;
    if ( v6 > 8 )
    {
      if ( v6 == 9 )
      {
        v14 = v21;
        v22 = 0;
        v23 = 1;
        if ( v21 )
        {
          while ( strcmp(*(const char **)(v4 + 24), *(const char **)(v14 + 24)) )
          {
            v14 = *(_DWORD *)(v14 + 12);
            ++v23;
            if ( !v14 )
              goto LABEL_38;
          }
          v22 = 1;
        }
LABEL_38:
        for ( j = v20; ; j = *(_DWORD *)(j + 12) )
        {
          --v23;
          if ( !j )
            break;
          v16 = strcmp(*(const char **)(i + 24), *(const char **)(j + 24));
          i = v24;
          if ( !v16 )
          {
            v22 = 1;
            break;
          }
        }
        if ( v22 )
        {
          v7 = v23 == 0;
          goto LABEL_54;
        }
        v17 = *(_BYTE **)(i + 24);
        v18 = *(_BYTE **)(v4 + 24);
        while ( 1 )
        {
          v11 = *v18 < *v17;
          if ( *v18 != *v17 )
            break;
          if ( *v18 )
          {
            v19 = v18[1];
            v11 = v19 < v17[1];
            if ( v19 != v17[1] )
              break;
            v18 += 2;
            v17 += 2;
            if ( v19 )
              continue;
          }
LABEL_32:
          v13 = 0;
          goto LABEL_53;
        }
      }
      else
      {
        if ( v6 > 11 )
          goto LABEL_55;
        v9 = *(_BYTE **)(i + 24);
        v10 = *(_BYTE **)(v4 + 24);
        while ( 1 )
        {
          v11 = *v10 < *v9;
          if ( *v10 != *v9 )
            break;
          if ( !*v10 )
            goto LABEL_32;
          v12 = v10[1];
          v11 = v12 < v9[1];
          if ( v12 != v9[1] )
            break;
          v10 += 2;
          v9 += 2;
          if ( !v12 )
            goto LABEL_32;
        }
      }
      v13 = -v11 - (v11 - 1);
LABEL_53:
      v7 = v13 == 0;
      i = v24;
LABEL_54:
      if ( !v7 )
        return 0;
      goto LABEL_55;
    }
    if ( v6 >= 5 )
    {
      if ( *(double *)(v4 + 24) != *(double *)(i + 24) )
        return 0;
      goto LABEL_55;
    }
    if ( !v6 )
      goto LABEL_15;
    if ( v6 != 1 )
    {
      if ( v6 <= 1 )
        goto LABEL_55;
LABEL_15:
      v7 = *(_DWORD *)(i + 24) == *(_DWORD *)(v4 + 24);
      goto LABEL_54;
    }
    if ( *(_BYTE *)(v4 + 24) != *(_BYTE *)(i + 24)
      || *(_BYTE *)(v4 + 25) != *(_BYTE *)(i + 25)
      || *(_BYTE *)(v4 + 26) != *(_BYTE *)(i + 26)
      || *(_BYTE *)(v4 + 27) != *(_BYTE *)(i + 27) )
    {
      return 0;
    }
LABEL_55:
    v4 = *(_DWORD *)(v4 + 12);
  }
  return !i;
}
