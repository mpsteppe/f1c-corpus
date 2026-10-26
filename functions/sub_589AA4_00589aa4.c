int __cdecl sub_589AA4(int CharType)
{
  int result; // eax
  int v2; // ebx
  int v3; // eax
  int v4; // eax
  CHAR DestStr[4]; // [esp+4h] [ebp-4h] BYREF

  if ( dword_8D3F38 )
  {
    v2 = CharType;
    if ( (CharType >= 256
       || (cbMultiByte <= 1
         ? (v3 = off_5E69C8[0][CharType] & 2)
         : (v3 = CharacterEncodingConvertViaLookupTableFallback(CharType, 2)),
           v3))
      && (off_5E69C8[0][BYTE1(v2)] >= 0
        ? (LOWORD(CharType) = (unsigned __int8)v2,
           v4 = sub_591FA1(dword_8D3F38, 0x200u, (LPCSTR)&CharType, 1, DestStr, 3, 0, 1))
        : (LOBYTE(CharType) = BYTE1(v2),
           *(_WORD *)((char *)&CharType + 1) = (unsigned __int8)v2,
           v4 = sub_591FA1(dword_8D3F38, 0x200u, (LPCSTR)&CharType, 2, DestStr, 3, 0, 1)),
          v4) )
    {
      if ( v4 == 1 )
        return (unsigned __int8)DestStr[0];
      else
        return *(unsigned __int16 *)DestStr;
    }
    else
    {
      return v2;
    }
  }
  else
  {
    result = CharType;
    if ( CharType >= 97 && CharType <= 122 )
      return CharType - 32;
  }
  return result;
}
