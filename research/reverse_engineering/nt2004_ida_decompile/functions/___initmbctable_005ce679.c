int __initmbctable()
{
  int result; // eax

  if ( !dword_80150C )
  {
    result = _setmbcp(-3);
    dword_80150C = 1;
  }
  return result;
}
