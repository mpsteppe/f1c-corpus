BOOL __thiscall LanguageEnumProc(void *this, LPSTR a2)
{
  int v2; // esi
  BOOL v4; // eax
  char String2[120]; // [esp+4h] [ebp-7Ch] BYREF
  int v6; // [esp+7Ch] [ebp-4h]

  v6 = dword_912B08;
  v2 = LcidFromHexString((int)this, a2);
  if ( !dword_FB83D8(v2, dword_FB83C4 != 0 ? 3 : 4097, String2, 120) )
  {
    dword_FB83B8 = 0;
    return 1;
  }
  if ( !_stricmp(dword_FB83D4, String2) )
  {
    if ( dword_FB83C4 )
    {
LABEL_11:
      dword_FB83B8 |= 4u;
      dword_FB83C0 = v2;
      Locale = v2;
      return (dword_FB83B8 & 4) == 0;
    }
    v4 = TestDefaultLanguage(v2, 1);
  }
  else
  {
    if ( dword_FB83C4 || !MaxCount || _strnicmp(dword_FB83D4, String2, MaxCount) )
      return (dword_FB83B8 & 4) == 0;
    v4 = TestDefaultLanguage(v2, 0);
  }
  if ( v4 )
    goto LABEL_11;
  return (dword_FB83B8 & 4) == 0;
}
