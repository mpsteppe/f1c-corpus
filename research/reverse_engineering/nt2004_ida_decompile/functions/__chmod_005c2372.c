int __cdecl _chmod(const char *FileName, int Mode)
{
  DWORD FileAttributesA; // eax
  DWORD LastError; // eax

  FileAttributesA = GetFileAttributesA(FileName);
  if ( FileAttributesA != -1 )
  {
    LOBYTE(FileAttributesA) = (Mode & 0x80u) == 0 ? FileAttributesA | 1 : FileAttributesA & 0xFE;
    if ( SetFileAttributesA(FileName, FileAttributesA) )
      return 0;
  }
  LastError = GetLastError();
  _dosmaperr(LastError);
  return -1;
}
