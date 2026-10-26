int __cdecl __crtsetenv(const unsigned __int8 **a1, int a2)
{
  const unsigned __int8 *v3; // esi
  unsigned __int8 *v4; // eax
  bool v5; // zf
  char **v6; // eax
  _DWORD *v7; // eax
  _DWORD *v8; // eax
  _DWORD *v9; // esi
  int v10; // eax
  int v11; // edi
  unsigned __int8 **v12; // esi
  char *v13; // eax
  unsigned __int8 **v14; // ecx
  int v15; // eax
  char *v16; // eax
  CHAR *v17; // esi
  unsigned __int8 *v18; // eax
  int v19; // [esp+8h] [ebp-10h]
  unsigned __int8 *v20; // [esp+Ch] [ebp-Ch]
  BOOL v21; // [esp+10h] [ebp-8h]
  unsigned __int8 *Block; // [esp+14h] [ebp-4h]

  v19 = 0;
  if ( !a1 )
    return -1;
  v3 = *a1;
  Block = (unsigned __int8 *)*a1;
  if ( !*a1 )
    return -1;
  v4 = _mbschr(v3, 0x3Du);
  v20 = v4;
  if ( !v4 || v3 == v4 )
    return -1;
  v5 = v4[1] == 0;
  v6 = (char **)dword_FB81B4;
  v21 = v5;
  if ( dword_FB81B4 == (void *)dword_FB81B8 )
  {
    v6 = copy_environ((char **)dword_FB81B4);
    dword_FB81B4 = v6;
  }
  if ( !v6 )
  {
    if ( a2 && dword_FB81BC )
    {
      if ( __wtomb_environ() )
        return -1;
    }
    else
    {
      if ( v21 )
        return 0;
      v7 = malloc(4u);
      dword_FB81B4 = v7;
      if ( !v7 )
        return -1;
      *v7 = 0;
      if ( !dword_FB81BC )
      {
        v8 = malloc(4u);
        dword_FB81BC = (int)v8;
        if ( !v8 )
          return -1;
        *v8 = 0;
      }
    }
  }
  v9 = dword_FB81B4;
  v10 = findenv(v20 - Block, Block);
  v11 = v10;
  if ( v10 < 0 || !*v9 )
  {
    if ( !v21 )
    {
      if ( v10 < 0 )
        v11 = -v10;
      v13 = (char *)realloc(dword_FB81B4, 4 * v11 + 8);
      if ( !v13 )
        return -1;
      v14 = (unsigned __int8 **)&v13[4 * v11];
      *v14 = Block;
      v14[1] = 0;
      *a1 = 0;
      goto LABEL_33;
    }
    free(Block);
    *a1 = 0;
    return 0;
  }
  v12 = (unsigned __int8 **)&v9[v10];
  free(*v12);
  if ( !v21 )
  {
    *v12 = Block;
    *a1 = 0;
    goto LABEL_34;
  }
  while ( *v12 )
  {
    *v12 = v12[1];
    ++v11;
    ++v12;
  }
  v13 = (char *)realloc(dword_FB81B4, 4 * v11);
  if ( !v13 )
    goto LABEL_34;
LABEL_33:
  dword_FB81B4 = v13;
LABEL_34:
  if ( a2 )
  {
    v15 = sub_6354D0((int)Block);
    v16 = (char *)malloc(v15 + 2);
    v17 = v16;
    if ( v16 )
    {
      strcpy(v16, (const char *)Block);
      v18 = &v20[v17 - (CHAR *)Block];
      *v18 = 0;
      if ( !SetEnvironmentVariableA(v17, !v21 ? (LPCSTR)v18 + 1 : 0) )
        v19 = -1;
      free(v17);
    }
  }
  if ( v21 )
    free(Block);
  return v19;
}
