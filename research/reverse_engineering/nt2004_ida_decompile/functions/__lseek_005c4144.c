int __cdecl _lseek(int FileHandle, int Offset, int Origin)
{
  int v3; // edi

  if ( FileHandle < uNumber && (*(_BYTE *)(dword_8003E0[FileHandle >> 5] + 36 * (FileHandle & 0x1F) + 4) & 1) != 0 )
  {
    _lock_fhandle(FileHandle);
    v3 = _lseek_lk(FileHandle, Offset, Origin);
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
