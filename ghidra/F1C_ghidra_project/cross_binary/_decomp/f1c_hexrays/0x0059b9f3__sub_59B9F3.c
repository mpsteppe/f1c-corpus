// f1c  0x0059b9f3  size=42
int __cdecl sub_59B9F3(LPCSTR lpPathName)
{
  DWORD LastError; // eax

  if ( RemoveDirectoryA(lpPathName) )
    LastError = 0;
  else
    LastError = GetLastError();
  if ( !LastError )
    return 0;
  sub_58AF5C(LastError);
  return -1;
}
