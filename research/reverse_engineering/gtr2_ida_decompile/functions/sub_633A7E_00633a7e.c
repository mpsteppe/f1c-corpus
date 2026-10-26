int __cdecl sub_633A7E(LPCSTR lpExistingFileName, LPCSTR lpNewFileName)
{
  DWORD LastError; // eax

  if ( MoveFileA(lpExistingFileName, lpNewFileName) )
    LastError = 0;
  else
    LastError = GetLastError();
  if ( !LastError )
    return 0;
  _dosmaperr(LastError);
  return -1;
}
