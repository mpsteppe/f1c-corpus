int __cdecl __getlocaleinfo(int a1, LCID Locale, LCTYPE LCType, char **a4)
{
  char *v4; // edi
  size_t LocaleInfoA; // esi
  size_t v6; // eax
  int v7; // esi
  CHAR *v8; // eax
  char *v9; // eax
  WCHAR *v11; // esi
  unsigned __int8 v12; // bl
  int v13; // eax
  char Source[128]; // [esp+Ch] [ebp-80h] BYREF
  int v15; // [esp+94h] [ebp+8h]

  if ( a1 == 1 )
  {
    v4 = Source;
    v15 = 0;
    LocaleInfoA = __crtGetLocaleInfoA(Locale, LCType, Source, 128, 0);
    if ( !LocaleInfoA )
    {
      if ( GetLastError() != 122 )
        return -1;
      v6 = __crtGetLocaleInfoA(Locale, LCType, 0, 0, 0);
      v7 = v6;
      if ( !v6 )
        return -1;
      v8 = (CHAR *)malloc(v6);
      v4 = v8;
      if ( !v8 )
        return -1;
      v15 = 1;
      LocaleInfoA = __crtGetLocaleInfoA(Locale, LCType, v8, v7, 0);
      if ( !LocaleInfoA )
        goto LABEL_9;
    }
    v9 = (char *)malloc(LocaleInfoA);
    *a4 = v9;
    if ( !v9 )
    {
      if ( !v15 )
        return -1;
LABEL_9:
      sub_5C1B88(v4);
      return -1;
    }
    strncpy(v9, v4, LocaleInfoA);
    if ( v15 )
      sub_5C1B88(v4);
  }
  else
  {
    if ( a1 )
      return -1;
    v11 = &LCData;
    if ( !__crtGetLocaleInfoW(Locale, LCType, &LCData, 4, 0) )
      return -1;
    *(_BYTE *)a4 = 0;
    do
    {
      v12 = *(_BYTE *)v11;
      if ( (int)SrcSizeInBytes <= 1 )
        v13 = *((_BYTE *)off_625680 + 2 * v12) & 4;
      else
        v13 = _isctype(v12, 4);
      if ( !v13 )
        break;
      ++v11;
      *(_BYTE *)a4 = v12 + 10 * *(_BYTE *)a4 - 48;
    }
    while ( (int)v11 < (int)word_7FF47C );
  }
  return 0;
}
