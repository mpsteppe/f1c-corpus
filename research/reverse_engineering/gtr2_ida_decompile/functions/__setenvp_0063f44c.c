int _setenvp()
{
  char *v0; // esi
  int v1; // edi
  _DWORD *v2; // edi
  char *i; // esi
  int v5; // eax
  int v6; // ebp
  char *v7; // eax

  if ( !dword_FBC614 )
    __initmbctable();
  v0 = dword_FB81D8;
  v1 = 0;
  if ( !dword_FB81D8 )
    return -1;
  while ( *v0 )
  {
    if ( *v0 != 61 )
      ++v1;
    v0 += sub_6354D0((int)v0) + 1;
  }
  v2 = malloc(4 * v1 + 4);
  dword_FB81B4 = v2;
  if ( !v2 )
    return -1;
  for ( i = dword_FB81D8; ; i += v6 )
  {
    if ( !*i )
    {
      free(dword_FB81D8);
      dword_FB81D8 = 0;
      *v2 = 0;
      dword_FBC608 = 1;
      return 0;
    }
    v5 = sub_6354D0((int)i);
    v6 = v5 + 1;
    if ( *i != 61 )
      break;
LABEL_15:
    ;
  }
  v7 = (char *)malloc(v5 + 1);
  *v2 = v7;
  if ( v7 )
  {
    strcpy(v7, i);
    ++v2;
    goto LABEL_15;
  }
  free(dword_FB81B4);
  dword_FB81B4 = 0;
  return -1;
}
