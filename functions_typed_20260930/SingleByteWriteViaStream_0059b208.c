WCHAR __cdecl sub_59B208(int a1)
{
  WCHAR result; // ax
  bool v2; // sf
  CHAR v3[6]; // [esp+0h] [ebp-8h] BYREF
  WCHAR v4; // [esp+6h] [ebp-2h] BYREF

  if ( a1 == -1 )
    return -1;
  HIBYTE(a1) = a1;
  *(_DWORD *)v3 = 0;
  v2 = sub_59B092(&v4, (LPCCH)&a1 + 3, 1, v3, 0) < 0;
  result = -1;
  if ( !v2 )
    return v4;
  return result;
}

