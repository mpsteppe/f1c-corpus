double __stdcall sub_4E32F0(char *String1)
{
  int v1; // eax
  char *v2; // esi
  int v3; // edi
  int v4; // eax
  int v5; // esi
  const char *v6; // eax
  double result; // st7
  const char *v8; // eax

  if ( !String1 )
    return -1.0;
  v1 = dword_7D6B58 + 400 * dword_7D6B54;
  if ( !v1 )
    return -1.0;
  v2 = (char *)(v1 + 260);
  if ( v1 == -260 || !sub_57AE50(aSeasonraces) || !sub_57A720(v2) || !sub_57A720(aQualifying) )
    return -1.0;
  v3 = 0;
  while ( 1 )
  {
    v4 = sub_57A700(v3);
    v5 = v4;
    if ( v4 )
    {
      v6 = (const char *)sub_57A6C0(v4);
      if ( !_strcmpi(String1, v6) )
        break;
    }
    if ( ++v3 >= 48 )
      return -1.0;
  }
  v8 = (const char *)sub_57A6D0(v5);
  result = atof(v8);
  if ( result < 10.0 )
    return -1.0;
  return result;
}
