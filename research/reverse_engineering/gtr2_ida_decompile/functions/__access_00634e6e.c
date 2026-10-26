int __cdecl _access(const char *FileName, int AccessMode)
{
  DWORD FileAttributesA; // eax
  DWORD LastError; // eax

  FileAttributesA = GetFileAttributesA(FileName);
  if ( FileAttributesA == -1 )
  {
    LastError = GetLastError();
    _dosmaperr(LastError);
    return -1;
  }
  if ( (FileAttributesA & 1) != 0 && (AccessMode & 2) != 0 )
  {
    *_errno() = 13;
    *__doserrno() = 5;
    return -1;
  }
  return 0;
}
