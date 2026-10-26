char *_setlocale_get_all()
{
  char *result; // eax
  int v1; // ebp
  const char **v2; // esi
  const char **v3; // ebx

  result = dword_912A4C;
  v1 = 1;
  if ( dword_912A4C || (result = (char *)malloc(0x351u), (dword_912A4C = result) != 0) )
  {
    *result = 0;
    _strcats(dword_912A4C, 3);
    v2 = (const char **)&off_912A58;
    v3 = (const char **)&off_912A58;
    do
    {
      strcat(dword_912A4C, ";");
      v2 += 3;
      if ( strcmp(*v3, *v2) )
        v1 = 0;
      v3 = v2;
      _strcats(dword_912A4C, 3);
    }
    while ( (int)v2 < (int)&off_912A88 );
    if ( v1 )
    {
      free(dword_912A4C);
      dword_912A4C = 0;
      return off_912A64;
    }
    else
    {
      return dword_912A4C;
    }
  }
  return result;
}
