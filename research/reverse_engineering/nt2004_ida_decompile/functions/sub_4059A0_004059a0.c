int __stdcall sub_4059A0(char *String1)
{
  int v1; // esi

  v1 = 0;
  while ( _strcmpi(String1, (&off_5FB7A4)[v1]) )
  {
    if ( ++v1 >= 5 )
      return 0;
  }
  return v1;
}
