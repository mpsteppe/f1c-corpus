int __cdecl sub_58C674(int CharType, int a2)
{
  int v2; // ecx
  int v3; // eax
  int result; // eax
  int SrcStr; // [esp+0h] [ebp-4h] BYREF

  SrcStr = v2;
  if ( (unsigned int)(CharType + 1) <= 0x100 )
  {
    v3 = (unsigned __int16)off_5E69C8[0][CharType];
    return a2 & v3;
  }
  if ( off_5E69C8[0][BYTE1(CharType)] >= 0 )
  {
    LOWORD(SrcStr) = (unsigned __int8)CharType;
    result = sub_595DC8(1u, (LPCSTR)&SrcStr, 1, (LPWORD)&CharType + 1, 0, 0, 1);
  }
  else
  {
    LOBYTE(SrcStr) = BYTE1(CharType);
    *(_WORD *)((char *)&SrcStr + 1) = (unsigned __int8)CharType;
    result = sub_595DC8(1u, (LPCSTR)&SrcStr, 2, (LPWORD)&CharType + 1, 0, 0, 1);
  }
  if ( result )
  {
    v3 = HIWORD(CharType);
    return a2 & v3;
  }
  return result;
}

