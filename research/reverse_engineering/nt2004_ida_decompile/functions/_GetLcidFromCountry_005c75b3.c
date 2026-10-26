BOOL GetLcidFromCountry()
{
  BOOL result; // eax

  dword_7FF24C = strlen(dword_7FF25C) == 3;
  result = EnumSystemLocalesA(CountryEnumProc, 1u);
  if ( (dword_7FF260 & 4) == 0 )
    dword_7FF260 = 0;
  return result;
}
