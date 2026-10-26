int __cdecl _chdir(const char *Path)
{
  DWORD LastError; // eax
  CHAR Buffer[264]; // [esp+0h] [ebp-108h] BYREF

  if ( SetCurrentDirectoryA(Path) && GetCurrentDirectoryA(0x105u, Buffer) )
  {
    if ( (Buffer[0] == 92 || Buffer[0] == 47) && Buffer[0] == Buffer[1] )
      return 0;
    LOBYTE(Path) = 61;
    BYTE1(Path) = _mbctoupper((unsigned __int8)Buffer[0]);
    HIWORD(Path) = 58;
    if ( SetEnvironmentVariableA((LPCSTR)&Path, Buffer) )
      return 0;
  }
  LastError = GetLastError();
  _dosmaperr(LastError);
  return -1;
}
