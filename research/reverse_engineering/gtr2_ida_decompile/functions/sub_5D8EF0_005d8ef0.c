signed int __stdcall sub_5D8EF0(int a1, const char *a2, signed int a3)
{
  signed int result; // eax
  char v4; // cl

  sub_630FE0(a1);
  result = strlen(a2);
  if ( a3 >= result )
  {
    result = strlen(a2);
    *(_BYTE *)(result + a1) = 0;
  }
  else
  {
    *(_BYTE *)(a3 + a1) = v4;
  }
  return result;
}
