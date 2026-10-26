char *__stdcall sub_436040(const char **a1, char *Destination, int a3)
{
  const char *v3; // esi
  const char *v4; // edx
  const char *i; // ecx
  const char *v6; // edx
  unsigned int v7; // kr08_4
  char *result; // eax
  char *v9; // ecx

  v3 = *a1;
  v4 = *a1;
  if ( !*a1 )
    v4 = &byte_629120;
  for ( i = &v4[strlen(v4)]; i > v4; --i )
  {
    if ( *i == 92 )
      break;
  }
  v6 = (const char *)sub_459B80(dword_75E8E8);
  if ( v6 )
  {
    v7 = strlen(v6) + 1;
    if ( !v3 )
      v3 = &byte_629120;
    strncmp(v6, v3, v7 - 1);
  }
  sub_57B340(a3);
  result = 0;
  v9 = &Destination[strlen(Destination)];
  if ( v9 > Destination )
  {
    while ( *v9 != 46 )
    {
      if ( --v9 <= Destination )
        goto LABEL_15;
    }
    *v9 = 0;
  }
LABEL_15:
  if ( !*Destination )
  {
    result = strncpy(Destination, asc_5FE190, a3 - 1);
    Destination[a3 - 1] = 0;
  }
  return result;
}
