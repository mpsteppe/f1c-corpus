char __stdcall sub_421890(const char *a1)
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
        result = word_5C2AAC;
        *(_WORD *)&a1[strlen(a1)] = word_5C2AAC;
      }
    }
  }
  return result;
}
