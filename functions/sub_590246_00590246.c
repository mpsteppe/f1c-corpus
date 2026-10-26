BOOL __stdcall sub_590246(LPSTR a1)
{
  int v1; // esi
  int v2; // eax
  int v4; // eax
  _BYTE v5[120]; // [esp+4h] [ebp-78h] BYREF

  v1 = HexStringToIntParser(a1);
  v2 = -(dword_8D3FA4 != 0);
  LOWORD(v2) = v2 & 0xF002;
  if ( !dword_8D3FB8(v1, v2 + 4097, v5, 120) )
  {
    dword_8D3FB0 = 0;
    return 1;
  }
  if ( sub_588410((_BYTE *)dword_8D3FA8, v5) )
  {
    if ( dword_8D3FA4 || !dword_8D3FA0 || sub_596C80(dword_8D3FA8, v5, dword_8D3FA0) )
      return ((unsigned int)~dword_8D3FB0 >> 2) & 1;
    v4 = sub_59045F(v1, 0);
  }
  else
  {
    if ( dword_8D3FA4 )
    {
LABEL_11:
      dword_8D3FB0 |= 4u;
      dword_8D3FB4 = v1;
      Locale = v1;
      return ((unsigned int)~dword_8D3FB0 >> 2) & 1;
    }
    v4 = sub_59045F(v1, 1);
  }
  if ( v4 )
    goto LABEL_11;
  return ((unsigned int)~dword_8D3FB0 >> 2) & 1;
}
