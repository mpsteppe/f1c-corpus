BOOL __thiscall LangCountryEnumProc(void *this, LPSTR a2)
{
  int v2; // esi
  BOOL v4; // eax
  char String2[120]; // [esp+4h] [ebp-7Ch] BYREF
  int v6; // [esp+7Ch] [ebp-4h]

  v6 = dword_912B08;
  v2 = LcidFromHexString((int)this, a2);
  if ( !dword_FB83D8(v2, dword_FB83C8 != 0 ? 7 : 4098, String2, 120) )
  {
    dword_FB83B8 = 0;
    return 1;
  }
  if ( !_stricmp(dword_FB83CC, String2) )
  {
    if ( !dword_FB83D8(v2, dword_FB83C4 != 0 ? 3 : 4097, String2, 120) )
    {
LABEL_18:
      dword_FB83B8 = 0;
      return 1;
    }
    if ( !_stricmp(dword_FB83D4, String2) )
    {
      LOWORD(dword_FB83B8) = dword_FB83B8 | 0x304;
      Locale = v2;
LABEL_15:
      dword_FB83C0 = v2;
      goto LABEL_16;
    }
    if ( (dword_FB83B8 & 2) != 0 )
      goto LABEL_16;
    if ( MaxCount && !_strnicmp(dword_FB83D4, String2, MaxCount) )
    {
      dword_FB83B8 |= 2u;
      dword_FB83C0 = v2;
      if ( sub_6354D0((int)dword_FB83D4) == MaxCount )
        Locale = v2;
    }
    else if ( (dword_FB83B8 & 1) == 0 && TestDefaultCountry(v2) )
    {
      dword_FB83B8 |= 1u;
      goto LABEL_15;
    }
  }
LABEL_16:
  if ( (dword_FB83B8 & 0x300) != 0x300 )
  {
    if ( !dword_FB83D8(v2, dword_FB83C4 != 0 ? 3 : 4097, String2, 120) )
      goto LABEL_18;
    if ( !_stricmp(dword_FB83D4, String2) )
    {
      BYTE1(dword_FB83B8) |= 2u;
      if ( dword_FB83C4 || !MaxCount || sub_6354D0((int)dword_FB83D4) != MaxCount )
        goto LABEL_29;
      v4 = TestDefaultLanguage(v2, 1);
    }
    else
    {
      if ( dword_FB83C4 || !MaxCount || _strnicmp(dword_FB83D4, String2, MaxCount) )
        return (dword_FB83B8 & 4) == 0;
      v4 = TestDefaultLanguage(v2, 0);
    }
    if ( v4 )
    {
LABEL_29:
      BYTE1(dword_FB83B8) |= 1u;
      if ( !Locale )
        Locale = v2;
    }
  }
  return (dword_FB83B8 & 4) == 0;
}
