int __cdecl __wctomb_mt(UINT *a1, LPSTR lpMultiByteStr, WCHAR WideCharStr)
{
  CHAR *v3; // ecx
  int result; // eax
  int v5; // [esp-Ch] [ebp-10h]

  v3 = lpMultiByteStr;
  if ( !lpMultiByteStr )
    return 0;
  if ( !a1[5] )
  {
    if ( WideCharStr <= 0xFFu )
    {
      *lpMultiByteStr = WideCharStr;
      return 1;
    }
    goto LABEL_8;
  }
  v5 = a1[10];
  lpMultiByteStr = 0;
  result = WideCharToMultiByte(a1[1], 0, &WideCharStr, 1, v3, v5, 0, (LPBOOL)&lpMultiByteStr);
  if ( !result || lpMultiByteStr )
  {
LABEL_8:
    *_errno() = 42;
    return -1;
  }
  return result;
}
