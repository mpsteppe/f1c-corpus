char __stdcall sub_57A820(unsigned __int8 *a1, char *Str)
{
  const char *v2; // edx
  unsigned __int8 i; // al
  char *v4; // eax
  unsigned __int8 *j; // edx
  _BYTE *v6; // edx
  char result; // al

  v2 = (const char *)a1;
  *Str = 0;
  if ( !a1 )
    return 0;
  for ( i = *a1; i; i = *++v2 )
  {
    if ( !sub_57A640(i) )
      break;
  }
  strcpy(Str, v2);
  v4 = strstr(Str, asc_5FD0CC);
  if ( v4 )
    *v4 = 0;
  for ( j = (unsigned __int8 *)&Str[strlen(Str) - 1]; j >= (unsigned __int8 *)Str; j = v6 - 1 )
  {
    if ( !sub_57A640(*j) )
      break;
    *v6 = 0;
  }
  result = 1;
  if ( !strlen(Str) )
    return 0;
  return result;
}
