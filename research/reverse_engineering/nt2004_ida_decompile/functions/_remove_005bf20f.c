int __cdecl remove(const char *FileName)
{
  DWORD LastError; // eax

  if ( DeleteFileA(FileName) )
    LastError = 0;
  else
    LastError = GetLastError();
  if ( !LastError )
    return 0;
  _dosmaperr(LastError);
  return -1;
}
