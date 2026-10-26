unsigned int __cdecl _mbtowc_lk(LPWSTR lpWideCharStr, unsigned __int8 *lpMultiByteStr, unsigned int a3)
{
  unsigned __int8 v3; // al
  unsigned int result; // eax
  bool v5; // zf

  if ( !lpMultiByteStr || !a3 )
    return 0;
  v3 = *lpMultiByteStr;
  if ( !*lpMultiByteStr )
  {
    if ( lpWideCharStr )
      *lpWideCharStr = 0;
    return 0;
  }
  if ( !dword_7FF1E8 )
  {
    if ( lpWideCharStr )
      *lpWideCharStr = v3;
    return 1;
  }
  if ( *((char *)off_625680 + 2 * v3 + 1) >= 0 )
  {
    if ( MultiByteToWideChar(CodePage, 9u, (LPCCH)lpMultiByteStr, 1, lpWideCharStr, lpWideCharStr != 0) )
      return 1;
    goto LABEL_18;
  }
  result = SrcSizeInBytes;
  if ( (int)SrcSizeInBytes > 1 )
  {
    if ( (int)a3 >= (int)SrcSizeInBytes )
    {
      v5 = MultiByteToWideChar(CodePage, 9u, (LPCCH)lpMultiByteStr, SrcSizeInBytes, lpWideCharStr, lpWideCharStr != 0) == 0;
      result = SrcSizeInBytes;
      if ( !v5 )
        return result;
      goto LABEL_16;
    }
LABEL_18:
    *_errno() = 42;
    return -1;
  }
LABEL_16:
  if ( a3 < result || !lpMultiByteStr[1] )
    goto LABEL_18;
  return result;
}
