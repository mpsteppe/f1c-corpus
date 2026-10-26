char __stdcall sub_616680(unsigned __int8 *a1, char *Str)
{
  int v2; // eax
  unsigned __int8 i; // cl
  char *v4; // edx
  char v5; // cl
  char *v6; // eax
  char *j; // eax
  bool v8; // zf
  char result; // al

  v2 = (int)a1;
  *Str = 0;
  if ( !a1 )
    return 0;
  for ( i = *a1; i; i = *(_BYTE *)++v2 )
  {
    if ( i > 0x20u )
      break;
  }
  v4 = &Str[-v2];
  do
  {
    v5 = *(_BYTE *)v2;
    v4[v2] = *(_BYTE *)v2;
    ++v2;
  }
  while ( v5 );
  v6 = strstr(Str, "//");
  if ( v6 )
    *v6 = 0;
  for ( j = &Str[strlen(Str) - 1]; j >= Str; *j-- = 0 )
  {
    if ( (unsigned __int8)*j > 0x20u )
      break;
  }
  v8 = strlen(Str) == 0;
  result = 1;
  if ( v8 )
    return 0;
  return result;
}
