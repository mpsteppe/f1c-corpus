int __initmbctable()
{
  if ( !dword_FBC614 )
  {
    _setmbcp(-3);
    dword_FBC614 = 1;
  }
  return 0;
}
