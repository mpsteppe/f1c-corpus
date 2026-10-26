int __endstdio()
{
  int result; // eax

  result = sub_5C1366();
  if ( byte_7FF150 )
    return _fcloseall();
  return result;
}
