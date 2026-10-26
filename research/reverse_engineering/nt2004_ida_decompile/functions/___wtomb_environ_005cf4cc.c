int __wtomb_environ()
{
  int v0; // esi
  const WCHAR *v1; // eax
  size_t v2; // eax
  int v3; // ebp
  CHAR *v4; // eax
  char *Str; // [esp+10h] [ebp-4h]

  v0 = dword_7FF140;
  v1 = *(const WCHAR **)dword_7FF140;
  if ( !*(_DWORD *)dword_7FF140 )
    return 0;
  while ( 1 )
  {
    v2 = WideCharToMultiByte(1u, 0, v1, -1, 0, 0, 0, 0);
    v3 = v2;
    if ( !v2 )
      break;
    v4 = (CHAR *)malloc(v2);
    Str = v4;
    if ( !v4 || !WideCharToMultiByte(1u, 0, *(LPCWCH *)v0, -1, v4, v3, 0, 0) )
      break;
    __crtsetenv(Str, 0);
    v1 = *(const WCHAR **)(v0 + 4);
    v0 += 4;
    if ( !v1 )
      return 0;
  }
  return -1;
}
