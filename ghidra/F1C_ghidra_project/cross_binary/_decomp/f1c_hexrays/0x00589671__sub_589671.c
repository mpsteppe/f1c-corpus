// f1c  0x00589671  size=44
int __cdecl sub_589671(LPCSTR lpPathName)
{
  DWORD LastError; // eax

  if ( CreateDirectoryA(lpPathName, 0) )
    LastError = 0;
  else
    LastError = GetLastError();
  if ( !LastError )
    return 0;
  sub_58AF5C(LastError);
  return -1;
}
