int __cdecl sub_58986E(LPCSTR lpFileName)
{
  DWORD LastError; // eax

  if ( DeleteFileA(lpFileName) )
    LastError = 0;
  else
    LastError = GetLastError();
  if ( !LastError )
    return 0;
  ErrorIDLookupTable(LastError);
  return -1;
}

