// f1c  0x0059b0f5  size=275
int __cdecl sub_59B0F5(LPWSTR lpWideCharStr, unsigned __int8 *a2, unsigned int a3, CHAR *lpMultiByteStr, LCID *a5)
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
    v7 = dword_8D3F38;
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
    if ( cbMultiByte > 1 && MultiByteToWideChar(v8, 9u, lpMultiByteStr, 2, lpWideCharStr, lpWideCharStr != 0) )
    {
      *(_DWORD *)lpMultiByteStr = 0;
      return cbMultiByte;
    }
    *(_DWORD *)lpMultiByteStr = 0;
  }
  else if ( off_5E69C8[0][v5] >= 0 )
  {
    if ( MultiByteToWideChar(v8, 9u, (LPCCH)a2, 1, lpWideCharStr, lpWideCharStr != 0) )
      return 1;
  }
  else
  {
    if ( a3 < cbMultiByte )
    {
      *lpMultiByteStr = v5;
      return -2;
    }
    if ( cbMultiByte > 1 && MultiByteToWideChar(v8, 9u, (LPCCH)a2, cbMultiByte, lpWideCharStr, lpWideCharStr != 0)
      || a2[1] )
    {
      return cbMultiByte;
    }
    *(_DWORD *)lpMultiByteStr = 0;
  }
  *(_DWORD *)sub_58AFCF() = 42;
  return -1;
}
