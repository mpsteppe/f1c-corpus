DWORD __cdecl _lseek_lk(int FileHandle, LONG lDistanceToMove, DWORD dwMoveMethod)
{
  void *osfhandle; // eax
  DWORD v4; // edi
  DWORD LastError; // eax

  osfhandle = (void *)_get_osfhandle(FileHandle);
  if ( osfhandle == (void *)-1 )
  {
    *_errno() = 9;
    return -1;
  }
  v4 = SetFilePointer(osfhandle, lDistanceToMove, 0, dwMoveMethod);
  if ( v4 == -1 )
    LastError = GetLastError();
  else
    LastError = 0;
  if ( LastError )
  {
    _dosmaperr(LastError);
    return -1;
  }
  *(_BYTE *)(dword_8003E0[FileHandle >> 5] + 36 * (FileHandle & 0x1F) + 4) &= ~2u;
  return v4;
}
