BOOL GetLcidFromCountry()
{
  BOOL result; // eax

  dword_FB83C8 = sub_6354D0((int)dword_FB83CC) == 3;
  result = EnumSystemLocalesA((LOCALE_ENUMPROCA)CountryEnumProc, 1u);
  if ( (dword_FB83B8 & 4) == 0 )
    dword_FB83B8 = 0;
  return result;
}
