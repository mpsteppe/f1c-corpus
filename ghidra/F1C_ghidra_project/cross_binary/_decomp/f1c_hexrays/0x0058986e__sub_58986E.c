// f1c  0x0058986e  size=42
int __cdecl sub_58986E(LPCSTR lpFileName)
{
  DWORD LastError; // eax

  if ( DeleteFileA(lpFileName) )
    LastError = 0;
  else
    LastError = GetLastError();
  if ( !LastError )
    return 0;
  sub_58AF5C(LastError);
  return -1;
}
