int __cdecl __crtsetenv(char *Str, int a2)
{
  unsigned __int8 *v2; // eax
  unsigned __int8 *v3; // esi
  void *v4; // eax
  BOOL v5; // ebx
  _DWORD *v7; // eax
  _DWORD *v8; // eax
  _DWORD *v9; // edi
  int v10; // eax
  int v11; // esi
  _DWORD *v12; // edi
  void *v13; // eax
  size_t v14; // eax
  char *v15; // eax
  CHAR *v16; // esi
  unsigned __int8 *v17; // eax
  void *v18; // [esp-4h] [ebp-18h]
  unsigned __int8 *v19; // [esp+Ch] [ebp-8h]
  void *lpMem; // [esp+10h] [ebp-4h]

  if ( !Str )
    return -1;
  v2 = _mbschr((const unsigned __int8 *)Str, 0x3Du);
  v3 = v2;
  v19 = v2;
  if ( !v2 || Str == (char *)v2 )
    return -1;
  v4 = dword_7FF138;
  v5 = v3[1] == 0;
  if ( dword_7FF138 == (LPVOID)dword_7FF13C )
  {
    v4 = (void *)copy_environ(dword_7FF138);
    dword_7FF138 = v4;
  }
  if ( !v4 )
  {
    if ( a2 && dword_7FF140 )
    {
      if ( __wtomb_environ() )
        return -1;
    }
    else
    {
      if ( v5 )
        return 0;
      v7 = malloc(4u);
      dword_7FF138 = v7;
      if ( !v7 )
        return -1;
      *v7 = 0;
      if ( !dword_7FF140 )
      {
        v8 = malloc(4u);
        dword_7FF140 = (int)v8;
        if ( !v8 )
          return -1;
        *v8 = 0;
      }
    }
  }
  v9 = dword_7FF138;
  lpMem = dword_7FF138;
  v10 = findenv((unsigned __int8 *)Str, v3 - (unsigned __int8 *)Str);
  v11 = v10;
  if ( v10 >= 0 && *v9 )
  {
    if ( !v5 )
    {
      v9[v10] = Str;
      goto LABEL_31;
    }
    v18 = (void *)v9[v10];
    v12 = &v9[v10];
    sub_5C1B88(v18);
    while ( *v12 )
    {
      ++v11;
      *v12 = v12[1];
      ++v12;
    }
    v13 = sub_5C293D(lpMem, 4 * v11);
    if ( !v13 )
    {
LABEL_31:
      if ( a2 )
      {
        v14 = strlen(Str);
        v15 = (char *)malloc(v14 + 2);
        v16 = v15;
        if ( v15 )
        {
          strcpy(v15, Str);
          v17 = &v19[v16 - Str];
          *v17 = 0;
          SetEnvironmentVariableA(v16, !v5 ? (LPCSTR)v17 + 1 : 0);
          sub_5C1B88(v16);
        }
      }
      return 0;
    }
LABEL_30:
    dword_7FF138 = v13;
    goto LABEL_31;
  }
  if ( !v5 )
  {
    if ( v10 < 0 )
      v11 = -v10;
    v13 = sub_5C293D(v9, 4 * v11 + 8);
    if ( !v13 )
      return -1;
    *((_DWORD *)v13 + v11) = Str;
    *((_DWORD *)v13 + v11 + 1) = 0;
    goto LABEL_30;
  }
  return 0;
}
