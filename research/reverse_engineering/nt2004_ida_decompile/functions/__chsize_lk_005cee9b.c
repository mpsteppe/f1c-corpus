int __cdecl _chsize_lk(int FileHandle, LONG lDistanceToMove)
{
  int v2; // esi
  DWORD v3; // eax
  int v4; // edi
  DWORD v5; // eax
  int v6; // eax
  void *osfhandle; // eax
  BOOL v8; // eax
  DWORD LastError; // edi
  _BYTE Buffer[4096]; // [esp+8h] [ebp-1004h] BYREF
  LONG v12; // [esp+1008h] [ebp-4h]
  LONG lDistanceToMovea; // [esp+1018h] [ebp+Ch]

  v2 = 0;
  v12 = _lseek_lk(FileHandle, 0, 1u);
  if ( v12 == -1 )
    return -1;
  v3 = _lseek_lk(FileHandle, 0, 2u);
  if ( v3 == -1 )
    return -1;
  v4 = lDistanceToMove - v3;
  if ( (int)(lDistanceToMove - v3) <= 0 )
  {
    if ( (int)(lDistanceToMove - v3) < 0 )
    {
      _lseek_lk(FileHandle, lDistanceToMove, 0);
      osfhandle = (void *)_get_osfhandle(FileHandle);
      v8 = SetEndOfFile(osfhandle);
      v2 = v8 - 1;
      if ( !v8 )
      {
        *_errno() = 13;
        LastError = GetLastError();
        *__doserrno() = LastError;
      }
    }
  }
  else
  {
    memset(Buffer, 0, sizeof(Buffer));
    lDistanceToMovea = _setmode_lk(FileHandle, 0x8000);
    while ( 1 )
    {
      v5 = 4096;
      if ( v4 < 4096 )
        v5 = v4;
      v6 = _write_lk(FileHandle, Buffer, v5);
      if ( v6 == -1 )
        break;
      v4 -= v6;
      if ( v4 <= 0 )
        goto LABEL_13;
    }
    if ( *__doserrno() == 5 )
      *_errno() = 13;
    v2 = -1;
LABEL_13:
    _setmode_lk(FileHandle, lDistanceToMovea);
  }
  _lseek_lk(FileHandle, v12, 0);
  return v2;
}
