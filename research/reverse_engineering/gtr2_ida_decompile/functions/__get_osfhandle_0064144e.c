intptr_t __cdecl _get_osfhandle(int FileHandle)
{
  int v1; // eax

  if ( FileHandle < uNumber )
  {
    v1 = dword_FBB4E0[FileHandle >> 5] + 36 * (FileHandle & 0x1F);
    if ( (*(_BYTE *)(v1 + 4) & 1) != 0 )
      return *(_DWORD *)v1;
  }
  *_errno() = 9;
  *__doserrno() = 0;
  return -1;
}
