int __stdcall sub_592D90(const char *a1, int a2, int a3, int a4, int a5, int a6)
{
  int result; // eax

  result = sub_592CD0(a1);
  if ( result )
  {
    sub_5A3F10(a2);
    sub_5A3F40(a3, a4);
    return sub_5A3F60(a5, a6);
  }
  return result;
}
