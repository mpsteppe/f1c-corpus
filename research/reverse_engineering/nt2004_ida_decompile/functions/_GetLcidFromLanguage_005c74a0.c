BOOL GetLcidFromLanguage()
{
  size_t v0; // eax
  BOOL result; // eax

  v0 = strlen(dword_7FF258);
  dword_7FF254 = v0 == 3;
  if ( v0 == 3 )
    MaxCount = 2;
  else
    MaxCount = GetPrimaryLen(dword_7FF258);
  result = EnumSystemLocalesA(LanguageEnumProc, 1u);
  if ( (dword_7FF260 & 4) == 0 )
    dword_7FF260 = 0;
  return result;
}
