int __cdecl _wctomb_lk(LPSTR lpMultiByteStr, WCHAR WideCharStr)
{
  int result; // eax

  result = (int)lpMultiByteStr;
  if ( lpMultiByteStr )
  {
    if ( !dword_7FF1E8 )
    {
      if ( WideCharStr <= 0xFFu )
      {
        *lpMultiByteStr = WideCharStr;
        return 1;
      }
      goto LABEL_7;
    }
    lpMultiByteStr = 0;
    result = WideCharToMultiByte(
               CodePage,
               0x220u,
               &WideCharStr,
               1,
               (LPSTR)result,
               SrcSizeInBytes,
               0,
               (LPBOOL)&lpMultiByteStr);
    if ( !result || lpMultiByteStr )
    {
LABEL_7:
      *_errno() = 42;
      return -1;
    }
  }
  return result;
}
