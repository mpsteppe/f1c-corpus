int __cdecl sub_6DFEC0(LPCSTR lpPathName)
{
  DWORD LastError; // eax

  if ( RemoveDirectoryA(lpPathName) )
    LastError = 0;
  else
    LastError = GetLastError();
  if ( !LastError )
    return 0;
  _dosmaperr(LastError);
  return -1;
}
