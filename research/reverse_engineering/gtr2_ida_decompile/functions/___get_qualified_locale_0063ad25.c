int __cdecl __get_qualified_locale(char *a1, _WORD *a2, char *Destination)
{
  char *v3; // eax
  char *v4; // ecx
  int v6; // edi
  LCID v7; // ecx
  __int16 v8; // dx

  if ( !dword_FB83D8 )
  {
    if ( dword_FB8194 == 2 )
      dword_FB83D8 = (int (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD))GetLocaleInfoA;
    else
      dword_FB83D8 = (int (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD))crtGetLocaleInfoA;
  }
  if ( !a1 )
  {
LABEL_24:
    GetLcidFromDefault();
    goto LABEL_25;
  }
  v3 = a1 + 64;
  v4 = a1;
  dword_FB83D4 = a1;
  dword_FB83CC = a1 + 64;
  if ( a1 != (char *)-64 && *v3 )
  {
    TranslateName((int)&off_731500, 22, (const char **)&dword_FB83CC);
    v4 = dword_FB83D4;
    v3 = dword_FB83CC;
  }
  dword_FB83B8 = 0;
  if ( !v4 || !*v4 )
  {
    if ( v3 && *v3 )
    {
      GetLcidFromCountry();
      goto LABEL_25;
    }
    goto LABEL_24;
  }
  if ( v3 && *v3 )
    GetLcidFromLangCountry();
  else
    GetLcidFromLanguage();
  if ( dword_FB83B8 )
    goto LABEL_27;
  if ( TranslateName((int)&off_7316B0, 64, (const char **)&dword_FB83D4) )
  {
    if ( dword_FB83CC && *dword_FB83CC )
      GetLcidFromLangCountry();
    else
      GetLcidFromLanguage();
  }
LABEL_25:
  if ( !dword_FB83B8 )
    return 0;
LABEL_27:
  v6 = ProcessCodePage(a1 + 128);
  if ( !v6 || !IsValidCodePage((unsigned __int16)v6) || !IsValidLocale(Locale, 1u) )
    return 0;
  v7 = Locale;
  if ( a2 )
  {
    v8 = dword_FB83C0;
    *a2 = Locale;
    a2[1] = v8;
    a2[2] = v6;
  }
  if ( !Destination )
    return 1;
  if ( *a2 == 2068 )
  {
    strcpy(Destination, "Norwegian-Nynorsk");
  }
  else if ( !dword_FB83D8(v7, 4097, Destination, 64) )
  {
    return 0;
  }
  if ( dword_FB83D8(dword_FB83C0, 4098, Destination + 64, 64) )
  {
    _itoa(v6, Destination + 128, 10);
    return 1;
  }
  return 0;
}
