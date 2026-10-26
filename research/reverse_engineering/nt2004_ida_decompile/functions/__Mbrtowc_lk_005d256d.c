size_t __cdecl _Mbrtowc_lk(LPWSTR lpWideCharStr, unsigned __int8 *a2, unsigned int a3, CHAR *lpMultiByteStr, LCID *a5)
{
  unsigned __int8 v5; // dl
  LCID v7; // ecx
  UINT v8; // eax

  if ( !a2 || !a3 )
    return 0;
  v5 = *a2;
  if ( !*a2 )
  {
    if ( lpWideCharStr )
      *lpWideCharStr = 0;
    return 0;
  }
  if ( a5 )
  {
    v7 = *a5;
    v8 = a5[1];
  }
  else
  {
    v7 = dword_7FF1E8;
    v8 = CodePage;
  }
  if ( !v7 )
  {
    if ( lpWideCharStr )
      *lpWideCharStr = v5;
    return 1;
  }
  if ( *(_DWORD *)lpMultiByteStr )
  {
    lpMultiByteStr[1] = v5;
    if ( (int)SrcSizeInBytes > 1 && MultiByteToWideChar(v8, 9u, lpMultiByteStr, 2, lpWideCharStr, lpWideCharStr != 0) )
    {
      *(_DWORD *)lpMultiByteStr = 0;
      return SrcSizeInBytes;
    }
    *(_DWORD *)lpMultiByteStr = 0;
  }
  else if ( *((char *)off_625680 + 2 * v5 + 1) >= 0 )
  {
    if ( MultiByteToWideChar(v8, 9u, (LPCCH)a2, 1, lpWideCharStr, lpWideCharStr != 0) )
      return 1;
  }
  else
  {
    if ( a3 < SrcSizeInBytes )
    {
      *lpMultiByteStr = v5;
      return -2;
    }
    if ( (int)SrcSizeInBytes > 1
      && MultiByteToWideChar(v8, 9u, (LPCCH)a2, SrcSizeInBytes, lpWideCharStr, lpWideCharStr != 0)
      || a2[1] )
    {
      return SrcSizeInBytes;
    }
    *(_DWORD *)lpMultiByteStr = 0;
  }
  *_errno() = 42;
  return -1;
}
