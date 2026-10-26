int GetLcidFromLangCountry()
{
  size_t v0; // eax
  int result; // eax

  dword_7FF254 = strlen(dword_7FF258) == 3;
  v0 = strlen(dword_7FF25C);
  Locale = 0;
  dword_7FF24C = v0 == 3;
  if ( dword_7FF254 )
    MaxCount = 2;
  else
    MaxCount = GetPrimaryLen(dword_7FF258);
  EnumSystemLocalesA(LangCountryEnumProc, 1u);
  result = dword_7FF260;
  if ( (dword_7FF260 & 0x100) == 0 || (dword_7FF260 & 0x200) == 0 || (dword_7FF260 & 7) == 0 )
    dword_7FF260 = 0;
  return result;
}
