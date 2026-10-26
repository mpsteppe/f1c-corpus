bool __stdcall sub_5668F0(LPCSTR lpFileName)
{
  bool result; // al

  result = 1;
  if ( FileAttributeCheckWithErrorHandling(lpFileName, 0) != -1 )
  {
    if ( FileAttributeCheckWithErrorHandling(lpFileName, 6) )
    {
      ToggleFileReadOnlyAttributeViaWin32API(lpFileName, 128);
      if ( FileAttributeCheckWithErrorHandling(lpFileName, 6) )
        return 0;
    }
  }
  return result;
}

