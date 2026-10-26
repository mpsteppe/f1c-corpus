const char *__fastcall sub_40D7B0(const char *a1)
{
  const char *result; // eax

  result = &a1[strlen(a1)];
  if ( result > a1 )
  {
    while ( *result != 92 )
    {
      if ( --result <= a1 )
        return result;
    }
    ++result;
  }
  return result;
}
