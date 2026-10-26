char __stdcall sub_41CE70(const char *a1)
{
  char result; // al

  if ( a1 )
  {
    result = 0;
    if ( strlen(a1) )
    {
      result = a1[strlen(a1) - 1];
      if ( result != 92 )
      {
        result = word_5FB9F4[0];
        *(_WORD *)&a1[strlen(a1)] = *(_WORD *)word_5FB9F4;
      }
    }
  }
  return result;
}
