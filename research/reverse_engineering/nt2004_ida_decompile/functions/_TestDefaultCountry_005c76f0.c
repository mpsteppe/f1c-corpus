int __cdecl TestDefaultCountry(__int16 a1)
{
  _WORD *v1; // eax

  v1 = &unk_625ED4;
  while ( a1 != *v1 )
  {
    if ( (int)++v1 >= (int)&off_625EE8 )
      return 1;
  }
  return 0;
}
