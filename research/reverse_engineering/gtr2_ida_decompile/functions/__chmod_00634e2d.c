int __cdecl _chmod(const char *FileName, int Mode)
{
  DWORD FileAttributesA; // eax
  DWORD v3; // eax
  DWORD LastError; // eax

  FileAttributesA = GetFileAttributesA(FileName);
  if ( FileAttributesA != -1 )
  {
    v3 = (Mode & 0x80u) == 0 ? FileAttributesA | 1 : FileAttributesA & 0xFFFFFFFE;
    if ( SetFileAttributesA(FileName, v3) )
      return 0;
  }
  LastError = GetLastError();
  _dosmaperr(LastError);
  return -1;
}
