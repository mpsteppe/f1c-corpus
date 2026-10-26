int GetLcidFromLangCountry()
{
  int v0; // eax
  int result; // eax
  int v2; // [esp-4h] [ebp-4h]

  dword_FB83C4 = sub_6354D0((int)dword_FB83D4) == 3;
  v0 = sub_6354D0((int)dword_FB83CC);
  Locale = 0;
  dword_FB83C8 = v0 == 3;
  if ( dword_FB83C4 )
    MaxCount = 2;
  else
    MaxCount = GetPrimaryLen(v2, dword_FB83D4);
  EnumSystemLocalesA((LOCALE_ENUMPROCA)LangCountryEnumProc, 1u);
  result = dword_FB83B8;
  if ( (dword_FB83B8 & 0x100) == 0 || (dword_FB83B8 & 0x200) == 0 || (dword_FB83B8 & 7) == 0 )
    dword_FB83B8 = 0;
  return result;
}
