BOOL __stdcall LanguageEnumProc(LPSTR a1)
{
  int v1; // esi
  int v2; // eax
  int v4; // eax
  char String2[120]; // [esp+4h] [ebp-78h] BYREF

  v1 = LcidFromHexString(a1);
  v2 = -(dword_7FF254 != 0);
  LOWORD(v2) = v2 & 0xF002;
  if ( !dword_7FF268(v1, v2 + 4097, String2, 120) )
  {
    dword_7FF260 = 0;
    return 1;
  }
  if ( _strcmpi(dword_7FF258, String2) )
  {
    if ( dword_7FF254 || !MaxCount || _strnicmp(dword_7FF258, String2, MaxCount) )
      return ((unsigned int)~dword_7FF260 >> 2) & 1;
    v4 = TestDefaultLanguage(v1, 0);
  }
  else
  {
    if ( dword_7FF254 )
    {
LABEL_11:
      dword_7FF260 |= 4u;
      dword_7FF264 = v1;
      Locale = v1;
      return ((unsigned int)~dword_7FF260 >> 2) & 1;
    }
    v4 = TestDefaultLanguage(v1, 1);
  }
  if ( v4 )
    goto LABEL_11;
  return ((unsigned int)~dword_7FF260 >> 2) & 1;
}
