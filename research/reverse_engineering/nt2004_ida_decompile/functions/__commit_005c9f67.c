int __cdecl _commit(int FileHandle)
{
  int v1; // esi
  void *osfhandle; // eax
  DWORD LastError; // esi

  if ( FileHandle < uNumber )
  {
    v1 = 36 * (FileHandle & 0x1F);
    if ( (*(_BYTE *)(dword_8003E0[FileHandle >> 5] + v1 + 4) & 1) != 0 )
    {
      _lock_fhandle(FileHandle);
      if ( (*(_BYTE *)(dword_8003E0[FileHandle >> 5] + v1 + 4) & 1) != 0 )
      {
        osfhandle = (void *)_get_osfhandle(FileHandle);
        if ( FlushFileBuffers(osfhandle) )
          LastError = 0;
        else
          LastError = GetLastError();
        if ( !LastError )
          goto LABEL_10;
        *__doserrno() = LastError;
      }
      *_errno() = 9;
      LastError = -1;
LABEL_10:
      _unlock_fhandle(FileHandle);
      return LastError;
    }
  }
  *_errno() = 9;
  return -1;
}
