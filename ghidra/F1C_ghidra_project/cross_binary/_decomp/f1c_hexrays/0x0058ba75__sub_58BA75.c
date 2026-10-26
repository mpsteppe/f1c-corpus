// f1c  0x0058ba75  size=70
int __cdecl sub_58BA75(LPCSTR lpFileName, char a2)
{
  DWORD FileAttributesA; // eax
  DWORD LastError; // eax

  FileAttributesA = GetFileAttributesA(lpFileName);
  if ( FileAttributesA == -1 )
  {
    LastError = GetLastError();
    sub_58AF5C(LastError);
    return -1;
  }
  if ( (FileAttributesA & 1) != 0 && (a2 & 2) != 0 )
  {
    *(_DWORD *)sub_58AFCF() = 13;
    *(_DWORD *)sub_58AFD8() = 5;
    return -1;
  }
  return 0;
}
