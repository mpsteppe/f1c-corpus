int __cdecl sub_596089(LPSTR lpMultiByteStr, WCHAR WideCharStr)
{
  int result; // eax

  result = (int)lpMultiByteStr;
  if ( lpMultiByteStr )
  {
    if ( !dword_8D3F38 )
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
               cbMultiByte,
               0,
               (LPBOOL)&lpMultiByteStr);
    if ( !result || lpMultiByteStr )
    {
LABEL_7:
      *(_DWORD *)sub_58AFCF() = 42;
      return -1;
    }
  }
  return result;
}
