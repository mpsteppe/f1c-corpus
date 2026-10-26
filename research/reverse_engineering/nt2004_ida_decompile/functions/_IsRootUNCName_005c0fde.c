BOOL __cdecl IsRootUNCName(char *Str)
{
  char v1; // al
  char v2; // cl
  char *v3; // eax
  char *v4; // eax
  char v5; // cl

  if ( strlen(Str) < 5 || *Str != 92 && *Str != 47 )
    return 0;
  v1 = Str[1];
  if ( v1 != 92 && v1 != 47 )
    return 0;
  v2 = Str[3];
  v3 = Str + 3;
  while ( v2 && v2 != 92 && v2 != 47 )
    v2 = *++v3;
  if ( !*v3 )
    return 0;
  v4 = v3 + 1;
  if ( !*v4 )
    return 0;
  while ( 1 )
  {
    v5 = *v4;
    if ( !*v4 || v5 == 92 || v5 == 47 )
      break;
    ++v4;
  }
  return !*v4 || !v4[1];
}
