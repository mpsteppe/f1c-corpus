CHAR *__crtGetEnvironmentStringsA()
{
  int v0; // eax
  CHAR *v1; // ebx
  WCHAR *EnvironmentStringsW; // esi
  WCHAR *i; // eax
  size_t v4; // eax
  int v5; // ebp
  CHAR *v6; // eax
  LPCH EnvironmentStrings; // eax
  LPCH v9; // esi
  size_t v10; // ebp
  void *v11; // eax
  void *v12; // edi
  CHAR *Block; // [esp+10h] [ebp-8h]
  int cchWideChar; // [esp+14h] [ebp-4h]

  v0 = dword_FB8610;
  v1 = 0;
  EnvironmentStringsW = 0;
  if ( !dword_FB8610 )
  {
    EnvironmentStringsW = GetEnvironmentStringsW();
    if ( EnvironmentStringsW )
    {
      dword_FB8610 = 1;
LABEL_8:
      if ( EnvironmentStringsW || (EnvironmentStringsW = GetEnvironmentStringsW()) != 0 )
      {
        for ( i = EnvironmentStringsW; *i; ++i )
        {
          do
            ++i;
          while ( *i );
        }
        cchWideChar = i - EnvironmentStringsW + 1;
        v4 = WideCharToMultiByte(0, 0, EnvironmentStringsW, cchWideChar, 0, 0, 0, 0);
        v5 = v4;
        if ( v4 )
        {
          v6 = (CHAR *)malloc(v4);
          Block = v6;
          if ( v6 )
          {
            if ( !WideCharToMultiByte(0, 0, EnvironmentStringsW, cchWideChar, v6, v5, 0, 0) )
            {
              free(Block);
              Block = 0;
            }
            v1 = Block;
          }
        }
        FreeEnvironmentStringsW(EnvironmentStringsW);
        return v1;
      }
      return 0;
    }
    if ( GetLastError() == 120 )
    {
      v0 = 2;
      dword_FB8610 = 2;
    }
    else
    {
      v0 = dword_FB8610;
    }
  }
  if ( v0 == 1 )
    goto LABEL_8;
  if ( v0 != 2 && v0 )
    return 0;
  EnvironmentStrings = GetEnvironmentStrings();
  v9 = EnvironmentStrings;
  if ( !EnvironmentStrings )
    return 0;
  for ( ; *EnvironmentStrings; ++EnvironmentStrings )
  {
    do
      ++EnvironmentStrings;
    while ( *EnvironmentStrings );
  }
  v10 = EnvironmentStrings - v9 + 1;
  v11 = malloc(v10);
  v12 = v11;
  if ( v11 )
    memcpy_0(v11, v9, v10);
  else
    v12 = 0;
  FreeEnvironmentStringsA(v9);
  return (CHAR *)v12;
}
