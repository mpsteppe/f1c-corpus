void _setenvp()
{
  char *v0; // esi
  int v1; // edi
  char **v2; // esi
  const char *i; // edi
  size_t v4; // eax
  size_t v5; // ebp
  char *v6; // eax

  if ( !dword_80150C )
    __initmbctable();
  v0 = dword_7FF15C;
  v1 = 0;
  while ( *v0 )
  {
    if ( *v0 != 61 )
      ++v1;
    v0 += strlen(v0) + 1;
  }
  v2 = (char **)malloc(4 * v1 + 4);
  dword_7FF138 = v2;
  if ( !v2 )
    _amsg_exit(9u);
  for ( i = dword_7FF15C; *i; i += v5 )
  {
    v4 = strlen(i);
    v5 = v4 + 1;
    if ( *i != 61 )
    {
      v6 = (char *)malloc(v4 + 1);
      *v2 = v6;
      if ( !v6 )
        _amsg_exit(9u);
      strcpy(*v2++, i);
    }
  }
  sub_5C1B88(dword_7FF15C);
  dword_7FF15C = 0;
  *v2 = 0;
  dword_801508 = 1;
}
