// f1c  0x0058ba36  size=63
int __cdecl sub_58BA36(LPCSTR lpFileName, char a2)
{
  DWORD FileAttributesA; // eax
  DWORD LastError; // eax

  FileAttributesA = GetFileAttributesA(lpFileName);
  if ( FileAttributesA != -1 )
  {
    LOBYTE(FileAttributesA) = a2 >= 0 ? FileAttributesA | 1 : FileAttributesA & 0xFE;
    if ( SetFileAttributesA(lpFileName, FileAttributesA) )
      return 0;
  }
  LastError = GetLastError();
  sub_58AF5C(LastError);
  return -1;
}
