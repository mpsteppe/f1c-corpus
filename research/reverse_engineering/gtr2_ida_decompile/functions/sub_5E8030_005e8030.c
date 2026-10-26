char __stdcall sub_5E8030(const char *a1)
{
  char result; // al
  int v2; // esi

  result = 0;
  v2 = 0;
  if ( strlen(a1) )
  {
    while ( a1[v2] != 46 )
    {
      if ( ++v2 >= strlen(a1) )
        return result;
    }
    return 1;
  }
  return result;
}
