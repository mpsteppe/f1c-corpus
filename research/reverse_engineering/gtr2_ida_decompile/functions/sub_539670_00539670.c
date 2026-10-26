int __stdcall sub_539670(char *String2)
{
  int result; // eax

  result = 0;
  if ( String2 )
  {
    sub_539600(String2);
    if ( dword_BE1BD0 >= dword_BE1BD4 || dword_BE1BD0 < 0 )
      return 0;
    else
      return dword_BE1BD8 + 2824 * dword_BE1BD0;
  }
  return result;
}
