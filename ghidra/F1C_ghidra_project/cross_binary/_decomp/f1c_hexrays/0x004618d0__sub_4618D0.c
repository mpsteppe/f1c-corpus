// f1c  0x004618d0  size=37
const char *__fastcall sub_4618D0(const char *a1)
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
