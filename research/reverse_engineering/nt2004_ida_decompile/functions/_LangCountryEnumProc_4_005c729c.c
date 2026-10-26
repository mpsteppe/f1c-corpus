BOOL __stdcall LangCountryEnumProc(LPSTR a1)
{
  int v1; // esi
  int v2; // eax
  int v4; // eax
  char String2[120]; // [esp+Ch] [ebp-78h] BYREF

  v1 = LcidFromHexString(a1);
  v2 = -(dword_7FF24C != 0);
  LOWORD(v2) = v2 & 0xF005;
  if ( !dword_7FF268(v1, v2 + 4098, String2, 120) )
    goto LABEL_17;
  if ( !_strcmpi(dword_7FF25C, String2) )
  {
    if ( !dword_7FF268(v1, dword_7FF254 != 0 ? 3 : 4097, String2, 120) )
    {
LABEL_17:
      dword_7FF260 = 0;
      return 1;
    }
    if ( !_strcmpi(dword_7FF258, String2) )
    {
      LOWORD(dword_7FF260) = dword_7FF260 | 0x304;
      dword_7FF264 = v1;
LABEL_6:
      Locale = v1;
      goto LABEL_15;
    }
    if ( (dword_7FF260 & 2) == 0 )
    {
      if ( MaxCount && !_strnicmp(dword_7FF258, String2, MaxCount) )
      {
        dword_7FF260 |= 2u;
        dword_7FF264 = v1;
        if ( strlen(dword_7FF258) == MaxCount )
          goto LABEL_6;
      }
      else if ( (dword_7FF260 & 1) == 0 && TestDefaultCountry(v1) )
      {
        dword_7FF260 |= 1u;
        dword_7FF264 = v1;
      }
    }
  }
LABEL_15:
  if ( (dword_7FF260 & 0x300) != 0x300 )
  {
    if ( !dword_7FF268(v1, dword_7FF254 != 0 ? 3 : 4097, String2, 120) )
      goto LABEL_17;
    if ( _strcmpi(dword_7FF258, String2) )
    {
      if ( dword_7FF254 || !MaxCount || _strnicmp(dword_7FF258, String2, MaxCount) )
        return ((unsigned int)~dword_7FF260 >> 2) & 1;
      v4 = TestDefaultLanguage(v1, 0);
    }
    else
    {
      BYTE1(dword_7FF260) |= 2u;
      if ( dword_7FF254 || !MaxCount || strlen(dword_7FF258) != MaxCount )
        goto LABEL_28;
      v4 = TestDefaultLanguage(v1, 1);
    }
    if ( v4 )
    {
LABEL_28:
      BYTE1(dword_7FF260) |= 1u;
      if ( !Locale )
        Locale = v1;
    }
  }
  return ((unsigned int)~dword_7FF260 >> 2) & 1;
}
