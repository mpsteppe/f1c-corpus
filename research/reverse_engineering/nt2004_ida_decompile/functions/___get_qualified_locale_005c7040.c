int __cdecl __get_qualified_locale(char *a1, _WORD *a2, int a3)
{
  char *v3; // eax
  int v4; // edi

  if ( !dword_7FF268 )
  {
    if ( IsThisWindowsNT() )
      dword_7FF268 = (int (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD))GetLocaleInfoA;
    else
      dword_7FF268 = (int (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD))crtGetLocaleInfoA;
  }
  if ( !a1 )
    goto LABEL_20;
  dword_7FF258 = a1;
  if ( *a1 )
    TranslateName(&off_625FA0, 64, &dword_7FF258);
  v3 = a1 + 64;
  dword_7FF25C = a1 + 64;
  if ( a1 != (char *)-64 && *v3 )
  {
    TranslateName(&off_625EE8, 22, &dword_7FF25C);
    v3 = dword_7FF25C;
  }
  dword_7FF260 = 0;
  if ( !dword_7FF258 || !*dword_7FF258 )
  {
    if ( v3 && *v3 )
    {
      GetLcidFromCountry();
      goto LABEL_21;
    }
LABEL_20:
    GetLcidFromDefault();
    goto LABEL_21;
  }
  if ( v3 && *v3 )
    GetLcidFromLangCountry();
  else
    GetLcidFromLanguage();
LABEL_21:
  if ( dword_7FF260 )
  {
    v4 = ProcessCodePage(a1 + 128);
    if ( v4 )
    {
      if ( IsValidCodePage((unsigned __int16)v4) && IsValidLocale(Locale, 1u) )
      {
        if ( a2 )
        {
          *a2 = Locale;
          a2[1] = dword_7FF264;
          a2[2] = v4;
        }
        if ( !a3 )
          return 1;
        if ( dword_7FF268(Locale, 4097, a3, 64) && dword_7FF268(dword_7FF264, 4098, a3 + 64, 64) )
        {
          _itoa(v4, (char *)(a3 + 128), 10);
          return 1;
        }
      }
    }
  }
  return 0;
}
