int __cdecl _write(int FileHandle, const void *Buf, unsigned int MaxCharCount)
{
  int v3; // edi

  if ( FileHandle < uNumber && (*(_BYTE *)(dword_8003E0[FileHandle >> 5] + 36 * (FileHandle & 0x1F) + 4) & 1) != 0 )
  {
    _lock_fhandle(FileHandle);
    v3 = _write_lk(FileHandle, Buf, MaxCharCount);
    _unlock_fhandle(FileHandle);
    return v3;
  }
  else
  {
    *_errno() = 9;
    *__doserrno() = 0;
    return -1;
  }
}
