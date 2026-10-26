int __cdecl sub_589671(LPCSTR lpPathName)
{
  DWORD LastError; // eax

  if ( CreateDirectoryA(lpPathName, 0) )
    LastError = 0;
  else
    LastError = GetLastError();
  if ( !LastError )
    return 0;
  ErrorIDLookupTable(LastError);
  return -1;
}

