int __stdcall sub_4E33C0(int a1)
{
  int v1; // edi
  int v2; // eax
  char *v3; // esi
  int v4; // ebx
  int v5; // edi
  int i; // esi
  const char *v7; // eax
  const char *v9; // [esp-4h] [ebp-10h]

  v1 = a1;
  if ( a1 >= 1 )
  {
    if ( a1 > 48 )
      v1 = 48;
  }
  else
  {
    v1 = 1;
  }
  v2 = dword_7D6B58 + 400 * dword_7D6B54;
  if ( !v2 )
    return 0;
  v3 = (char *)(v2 + 260);
  if ( v2 == -260 )
    return 0;
  if ( !sub_57AE50(aSeasonraces) )
    return 0;
  if ( !sub_57A720(v3) )
    return 0;
  if ( !sub_57A720(aQualifying) )
    return 0;
  v4 = sub_57A700(v1 - 1);
  if ( !v4 )
    return 0;
  v5 = 0;
  if ( dword_7D6A58 <= 0 )
    return 0;
  for ( i = 0; ; i += 1232 )
  {
    v9 = (const char *)(i + dword_7D6A5C + 246);
    v7 = (const char *)sub_57A6C0(v4);
    if ( !_strcmpi(v7, v9) )
      break;
    if ( ++v5 >= dword_7D6A58 )
      return 0;
  }
  return v5;
}
