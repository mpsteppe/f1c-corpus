BOOL __stdcall LocaleEnumProc(LPSTR a1)
{
  int v1; // esi
  int v2; // eax
  int v4; // eax
  _BYTE v5[120]; // [esp+Ch] [ebp-78h] BYREF

  v1 = sub_5905DD(a1);
  v2 = -(dword_8D3F9C != 0);
  LOWORD(v2) = v2 & 0xF005;
  if ( !dword_8D3FB8(v1, v2 + 4098, v5, 120) )
    goto LABEL_17;
  if ( !sub_588410((_BYTE *)dword_8D3FAC, v5) )
  {
    if ( !dword_8D3FB8(v1, dword_8D3FA4 != 0 ? 3 : 4097, v5, 120) )
    {
LABEL_17:
      dword_8D3FB0 = 0;
      return 1;
    }
    if ( !sub_588410((_BYTE *)dword_8D3FA8, v5) )
    {
      LOWORD(dword_8D3FB0) = dword_8D3FB0 | 0x304;
      dword_8D3FB4 = v1;
LABEL_6:
      Locale = v1;
      goto LABEL_15;
    }
    if ( (dword_8D3FB0 & 2) == 0 )
    {
      if ( !dword_8D3FA0 || sub_596C80(dword_8D3FA8, v5, dword_8D3FA0) )
      {
        if ( (dword_8D3FB0 & 1) == 0 && sub_590440(v1) )
        {
          dword_8D3FB0 |= 1u;
          dword_8D3FB4 = v1;
        }
      }
      else
      {
        dword_8D3FB0 |= 2u;
        dword_8D3FB4 = v1;
        if ( sub_58E1B0((_DWORD *)dword_8D3FA8) == (char *)dword_8D3FA0 )
          goto LABEL_6;
      }
    }
  }
LABEL_15:
  if ( (dword_8D3FB0 & 0x300) != 0x300 )
  {
    if ( !dword_8D3FB8(v1, dword_8D3FA4 != 0 ? 3 : 4097, v5, 120) )
      goto LABEL_17;
    if ( sub_588410((_BYTE *)dword_8D3FA8, v5) )
    {
      if ( dword_8D3FA4 || !dword_8D3FA0 || sub_596C80(dword_8D3FA8, v5, dword_8D3FA0) )
        return ((unsigned int)~dword_8D3FB0 >> 2) & 1;
      v4 = sub_59045F(v1, 0);
    }
    else
    {
      BYTE1(dword_8D3FB0) |= 2u;
      if ( dword_8D3FA4 || !dword_8D3FA0 || sub_58E1B0((_DWORD *)dword_8D3FA8) != (char *)dword_8D3FA0 )
        goto LABEL_28;
      v4 = sub_59045F(v1, 1);
    }
    if ( v4 )
    {
LABEL_28:
      BYTE1(dword_8D3FB0) |= 1u;
      if ( !Locale )
        Locale = v1;
    }
  }
  return ((unsigned int)~dword_8D3FB0 >> 2) & 1;
}
