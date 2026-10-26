int __cdecl toupper_0(int C)
{
  int result; // eax
  int v2; // ebx
  int v3; // eax
  int v4; // eax
  CHAR DestStr[4]; // [esp+4h] [ebp-4h] BYREF

  if ( dword_7FF1E8 )
  {
    v2 = C;
    if ( (C >= 256 || ((int)SrcSizeInBytes <= 1 ? (v3 = *((_BYTE *)off_625680 + 2 * C) & 2) : (v3 = _isctype(C, 2)), v3))
      && (*((char *)off_625680 + 2 * BYTE1(v2) + 1) >= 0
        ? (LOWORD(C) = (unsigned __int8)v2, v4 = __crtLCMapStringA(
                                                   dword_7FF1E8,
                                                   0x200u,
                                                   (LPCSTR)&C,
                                                   1,
                                                   DestStr,
                                                   3,
                                                   0,
                                                   1))
        : (LOBYTE(C) = BYTE1(v2),
           *(_WORD *)((char *)&C + 1) = (unsigned __int8)v2,
           v4 = __crtLCMapStringA(dword_7FF1E8, 0x200u, (LPCSTR)&C, 2, DestStr, 3, 0, 1)),
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
    result = C;
    if ( C >= 97 && C <= 122 )
      return C - 32;
  }
  return result;
}
