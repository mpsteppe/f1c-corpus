int __cdecl sub_59BA1D(LPCSTR lpPathName)
{
  DWORD LastError; // eax
  CHAR Buffer[264]; // [esp+0h] [ebp-108h] BYREF

  if ( SetCurrentDirectoryA(lpPathName) && GetCurrentDirectoryA(0x105u, Buffer) )
  {
    if ( (Buffer[0] == 92 || Buffer[0] == 47) && Buffer[0] == Buffer[1] )
      return 0;
    LOBYTE(lpPathName) = 61;
    BYTE1(lpPathName) = sub_59C0AC(Buffer[0]);
    HIWORD(lpPathName) = 58;
    if ( SetEnvironmentVariableA((LPCSTR)&lpPathName, Buffer) )
      return 0;
  }
  LastError = GetLastError();
  sub_58AF5C(LastError);
  return -1;
}
