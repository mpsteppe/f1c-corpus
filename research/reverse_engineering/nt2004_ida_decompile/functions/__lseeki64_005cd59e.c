__int64 __cdecl _lseeki64(int FileHandle, __int64 Offset, int Origin)
{
  int v3; // edi
  unsigned int v4; // edx
  unsigned int v5; // ebx

  if ( FileHandle < uNumber && (*(_BYTE *)(dword_8003E0[FileHandle >> 5] + 36 * (FileHandle & 0x1F) + 4) & 1) != 0 )
  {
    _lock_fhandle(FileHandle);
    v3 = _lseeki64_lk(FileHandle, Offset, SHIDWORD(Offset), Origin);
    v5 = v4;
    _unlock_fhandle(FileHandle);
    return __PAIR64__(v5, v3);
  }
  else
  {
    *_errno() = 9;
    *__doserrno() = 0;
    return -1;
  }
}
