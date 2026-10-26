UINT __cdecl __mbtowc_mt(UINT *a1, LPWSTR lpWideCharStr, unsigned __int8 *lpMultiByteStr, UINT a4)
{
  unsigned __int8 v4; // al
  int v6; // eax

  if ( !lpMultiByteStr || !a4 )
    return 0;
  v4 = *lpMultiByteStr;
  if ( !*lpMultiByteStr )
  {
    if ( lpWideCharStr )
      *lpWideCharStr = 0;
    return 0;
  }
  if ( !a1[5] )
  {
    if ( lpWideCharStr )
      *lpWideCharStr = v4;
    return 1;
  }
  if ( *(char *)(a1[18] + 2 * v4 + 1) >= 0 )
  {
    if ( MultiByteToWideChar(a1[1], 9u, (LPCCH)lpMultiByteStr, 1, lpWideCharStr, lpWideCharStr != 0) )
      return 1;
  }
  else
  {
    v6 = a1[10];
    if ( v6 > 1
      && (int)a4 >= v6
      && MultiByteToWideChar(a1[1], 9u, (LPCCH)lpMultiByteStr, v6, lpWideCharStr, lpWideCharStr != 0)
      || a4 >= a1[10] && lpMultiByteStr[1] )
    {
      return a1[10];
    }
  }
  *_errno() = 42;
  return -1;
}
