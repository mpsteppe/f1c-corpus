int __thiscall sub_646241(_DWORD *this, LPCWCH lpWideCharStr, unsigned int a3)
{
  int v3; // ebx
  int result; // eax
  void *v6; // eax

  v3 = 1;
  if ( a3 >= 2 )
  {
    v3 = 2;
    if ( a3 != 2 )
      return -2147467259;
    result = sub_677265(1024, lpWideCharStr);
    if ( result < 0 )
      return result;
    this[5] = *(_DWORD *)lpWideCharStr;
LABEL_9:
    this[4] = v3;
    return 0;
  }
  v6 = operator new(0x10000u);
  this[6] = v6;
  if ( !v6 )
    return -2147024882;
  result = sub_659A69(lpWideCharStr, a3 == 1);
  if ( result >= 0 )
    goto LABEL_9;
  return result;
}
