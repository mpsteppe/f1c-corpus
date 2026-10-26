int __stdcall sub_4E3130(char *String1)
{
  int v1; // eax
  char *v2; // esi
  int v3; // esi
  int v4; // eax
  const char *v5; // eax

  if ( !String1 )
    return 48;
  v1 = dword_7D6B58 + 400 * dword_7D6B54;
  if ( !v1 )
    return 48;
  v2 = (char *)(v1 + 260);
  if ( v1 == -260 || !sub_57AE50(aSeasonraces) || !sub_57A720(v2) || !sub_57A720(aQualifying) )
    return 48;
  v3 = 0;
  while ( 1 )
  {
    v4 = sub_57A700(v3);
    if ( v4 )
    {
      v5 = (const char *)sub_57A6C0(v4);
      if ( !_strcmpi(String1, v5) )
        break;
    }
    if ( ++v3 >= 48 )
      return 48;
  }
  return v3 + 1;
}
