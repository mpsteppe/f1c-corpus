int __stdcall sub_433290(char **a1, const char *a2, int a3)
{
  char *v3; // esi
  const char *v4; // edx
  const char *i; // ecx
  char *v6; // edx
  unsigned int v7; // kr08_4
  int result; // eax
  const char *v9; // ecx

  v3 = *a1;
  v4 = *a1;
  if ( !*a1 )
    v4 = &byte_5EA438;
  for ( i = &v4[strlen(v4)]; i > v4; --i )
  {
    if ( *i == 92 )
      break;
  }
  v6 = PathAccessor_28e0((char ***)dword_7C73E0);
  if ( v6 )
  {
    v7 = strlen(v6) + 1;
    if ( !v3 )
      v3 = &byte_5EA438;
    sub_588640(v6, v3, v7 - 1);
  }
  sub_568910(a3);
  result = 0;
  v9 = &a2[strlen(a2)];
  if ( v9 > a2 )
  {
    while ( *v9 != 46 )
    {
      if ( --v9 <= a2 )
        goto LABEL_15;
    }
    *v9 = 0;
  }
LABEL_15:
  if ( !*a2 )
  {
    result = sub_587DD0(a2, asc_5C4068, a3 - 1);
    a2[a3 - 1] = 0;
  }
  return result;
}

