int __cdecl sub_59B9F3(LPCSTR lpPathName)
{
  DWORD LastError; // eax

  if ( RemoveDirectoryA(lpPathName) )
    LastError = 0;
  else
    LastError = GetLastError();
  if ( !LastError )
    return 0;
  ErrorIDLookupTable(LastError);
  return -1;
}
