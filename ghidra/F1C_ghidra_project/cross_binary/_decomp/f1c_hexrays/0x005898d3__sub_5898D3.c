// f1c  0x005898d3  size=46
int __cdecl sub_5898D3(LPCSTR lpExistingFileName, LPCSTR lpNewFileName)
{
  DWORD LastError; // eax

  if ( MoveFileA(lpExistingFileName, lpNewFileName) )
    LastError = 0;
  else
    LastError = GetLastError();
  if ( !LastError )
    return 0;
  sub_58AF5C(LastError);
  return -1;
}
