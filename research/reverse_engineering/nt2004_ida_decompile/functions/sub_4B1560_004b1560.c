int __stdcall sub_4B1560(char *String)
{
  int result; // eax

  if ( String )
  {
    _strupr(String);
    return sub_578600(String);
  }
  return result;
}
