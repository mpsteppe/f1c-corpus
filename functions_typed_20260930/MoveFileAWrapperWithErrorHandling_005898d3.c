int __cdecl sub_5898D3(LPCSTR lpExistingFileName, LPCSTR lpNewFileName)
{
  DWORD LastError; // eax

  if ( MoveFileA(lpExistingFileName, lpNewFileName) )
    LastError = 0;
  else
    LastError = GetLastError();
  if ( !LastError )
    return 0;
  ErrorIDLookupTable(LastError);
  return -1;
}

