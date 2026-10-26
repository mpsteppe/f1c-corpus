int __cdecl _read(int FileHandle, void *DstBuf, unsigned int MaxCharCount)
{
  int lk; // edi

  if ( FileHandle < uNumber && (*(_BYTE *)(dword_8003E0[FileHandle >> 5] + 36 * (FileHandle & 0x1F) + 4) & 1) != 0 )
  {
    _lock_fhandle(FileHandle);
    lk = _read_lk(FileHandle, DstBuf, MaxCharCount);
    _unlock_fhandle(FileHandle);
    return lk;
  }
  else
  {
    *_errno() = 9;
    *__doserrno() = 0;
    return -1;
  }
}
