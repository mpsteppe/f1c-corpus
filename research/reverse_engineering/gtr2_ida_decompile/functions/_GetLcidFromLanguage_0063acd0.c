BOOL GetLcidFromLanguage()
{
  int v0; // eax
  BOOL result; // eax
  int v2; // [esp-4h] [ebp-4h]

  v0 = sub_6354D0((int)dword_FB83D4);
  dword_FB83C4 = v0 == 3;
  if ( v0 == 3 )
    MaxCount = 2;
  else
    MaxCount = GetPrimaryLen(v2, dword_FB83D4);
  result = EnumSystemLocalesA((LOCALE_ENUMPROCA)LanguageEnumProc, 1u);
  if ( (dword_FB83B8 & 4) == 0 )
    dword_FB83B8 = 0;
  return result;
}
