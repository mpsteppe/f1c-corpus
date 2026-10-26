unsigned int __stdcall sub_59033A(LPSTR a1)
{
  int v1; // esi
  int v2; // eax
  _BYTE v4[120]; // [esp+4h] [ebp-78h] BYREF

  v1 = HexStringToIntParser(a1);
  v2 = -(dword_8D3F9C != 0);
  LOWORD(v2) = v2 & 0xF005;
  if ( dword_8D3FB8(v1, v2 + 4098, v4, 120) )
  {
    if ( !sub_588410((_BYTE *)dword_8D3FAC, v4) )
    {
      if ( ShortInRangeCheckAgainstStaticTable(v1) )
      {
        dword_8D3FB0 |= 4u;
        dword_8D3FB4 = v1;
        Locale = v1;
      }
    }
    return ((unsigned int)~dword_8D3FB0 >> 2) & 1;
  }
  else
  {
    dword_8D3FB0 = 0;
    return 1;
  }
}

