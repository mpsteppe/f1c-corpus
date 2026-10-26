bool __stdcall sub_613B90(char *FileName)
{
  bool result; // al

  result = 1;
  if ( _access(FileName, 0) != -1 )
  {
    if ( _access(FileName, 6) )
    {
      _chmod(FileName, 384);
      if ( _access(FileName, 6) )
        return 0;
    }
  }
  return result;
}
