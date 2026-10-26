unsigned int __cdecl sub_596773(LPWSTR lpWideCharStr, unsigned __int8 *lpMultiByteStr, unsigned int a3)
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
  if ( !dword_8D3F38 )
  {
    if ( lpWideCharStr )
      *lpWideCharStr = v3;
    return 1;
  }
  if ( off_5E69C8[0][v3] >= 0 )
  {
    if ( MultiByteToWideChar(CodePage, 9u, (LPCCH)lpMultiByteStr, 1, lpWideCharStr, lpWideCharStr != 0) )
      return 1;
    goto LABEL_18;
  }
  result = cbMultiByte;
  if ( cbMultiByte > 1 )
  {
    if ( (int)a3 >= cbMultiByte )
    {
      v5 = MultiByteToWideChar(CodePage, 9u, (LPCCH)lpMultiByteStr, cbMultiByte, lpWideCharStr, lpWideCharStr != 0) == 0;
      result = cbMultiByte;
      if ( !v5 )
        return result;
      goto LABEL_16;
    }
LABEL_18:
    *(_DWORD *)TLSOffsetGetter() = 42;
    return -1;
  }
LABEL_16:
  if ( a3 < result || !lpMultiByteStr[1] )
    goto LABEL_18;
  return result;
}

