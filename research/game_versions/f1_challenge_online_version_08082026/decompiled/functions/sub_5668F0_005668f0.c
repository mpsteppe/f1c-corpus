bool __stdcall sub_5668F0(LPCSTR lpFileName)
{
  bool result; // al

  result = 1;
  if ( sub_58BA75(lpFileName, 0) != -1 )
  {
    if ( sub_58BA75(lpFileName, 6) )
    {
      sub_58BA36(lpFileName, 128);
      if ( sub_58BA75(lpFileName, 6) )
        return 0;
    }
  }
  return result;
}
