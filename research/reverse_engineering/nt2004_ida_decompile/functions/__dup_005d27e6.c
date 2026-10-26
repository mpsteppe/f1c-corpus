int __cdecl _dup(int FileHandle)
{
  int v1; // esi
  char v2; // bl
  int v3; // edi
  HANDLE v4; // eax
  DWORD LastError; // esi
  void *osfhandle; // [esp-18h] [ebp-28h]
  HANDLE CurrentProcess; // [esp-14h] [ebp-24h]
  HANDLE TargetHandle; // [esp+Ch] [ebp-4h] BYREF

  if ( FileHandle < uNumber
    && (v1 = 36 * (FileHandle & 0x1F), (*(_BYTE *)(dword_8003E0[FileHandle >> 5] + v1 + 4) & 1) != 0) )
  {
    _lock_fhandle(FileHandle);
    v2 = *(_BYTE *)(dword_8003E0[FileHandle >> 5] + v1 + 4);
    v3 = _alloc_osfhnd();
    if ( v3 == -1 )
    {
      *_errno() = 24;
      *__doserrno() = 0;
      _unlock_fhandle(FileHandle);
    }
    else
    {
      CurrentProcess = GetCurrentProcess();
      osfhandle = (void *)_get_osfhandle(FileHandle);
      v4 = GetCurrentProcess();
      if ( DuplicateHandle(v4, osfhandle, CurrentProcess, &TargetHandle, 0, 1, 2u) )
      {
        _set_osfhnd(v3, TargetHandle);
        LastError = 0;
      }
      else
      {
        LastError = GetLastError();
      }
      _unlock_fhandle(v3);
      _unlock_fhandle(FileHandle);
      if ( !LastError )
      {
        *(_BYTE *)(dword_8003E0[v3 >> 5] + 36 * (v3 & 0x1F) + 4) = v2 & 0xEF;
        return v3;
      }
      _dosmaperr(LastError);
    }
  }
  else
  {
    *_errno() = 9;
    *__doserrno() = 0;
  }
  return -1;
}
