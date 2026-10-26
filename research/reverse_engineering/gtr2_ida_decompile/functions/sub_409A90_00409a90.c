int __stdcall sub_409A90(char *String1)
{
  int v1; // esi

  v1 = 0;
  while ( _stricmp(String1, (&off_75756C)[v1]) )
  {
    if ( ++v1 >= 5 )
      return 0;
  }
  return v1;
}
