int __cdecl _close(int FileHandle)
{
  int v1; // edi

  if ( FileHandle < uNumber && (*(_BYTE *)(dword_8003E0[FileHandle >> 5] + 36 * (FileHandle & 0x1F) + 4) & 1) != 0 )
  {
    _lock_fhandle(FileHandle);
    v1 = _close_lk(FileHandle);
    _unlock_fhandle(FileHandle);
    return v1;
  }
  else
  {
    *_errno() = 9;
    *__doserrno() = 0;
    return -1;
  }
}
