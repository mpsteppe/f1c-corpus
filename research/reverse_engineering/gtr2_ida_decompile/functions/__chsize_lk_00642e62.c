// bad sp value at call has been detected, the output may be wrong!
int __usercall _chsize_lk@<eax>(int a1@<edi>, int FileHandle, LONG lDistanceToMove)
{
  int v3; // esi
  DWORD v4; // eax
  int v5; // edi
  DWORD v6; // eax
  int v7; // eax
  void *osfhandle; // eax
  BOOL v9; // eax
  unsigned int *v10; // edi
  int v12; // [esp+0h] [ebp-100Ch]
  DWORD v13; // [esp+4h] [ebp-1008h]
  _DWORD Buffer[1025]; // [esp+8h] [ebp-1004h] BYREF
  int savedregs; // [esp+100Ch] [ebp+0h]

  sub_631BD0(0x100Cu, savedregs);
  v3 = 0;
  Buffer[1024] = dword_912B08;
  v13 = _lseek_lk(FileHandle, 0, 1u);
  if ( v13 == -1 )
    return -1;
  v4 = _lseek_lk(FileHandle, 0, 2u);
  if ( v4 == -1 )
    return -1;
  Buffer[1023] = a1;
  v5 = lDistanceToMove - v4;
  if ( (int)(lDistanceToMove - v4) <= 0 )
  {
    if ( (int)(lDistanceToMove - v4) < 0 )
    {
      _lseek_lk(FileHandle, lDistanceToMove, 0);
      osfhandle = (void *)_get_osfhandle(FileHandle);
      v9 = SetEndOfFile(osfhandle);
      v3 = v9 - 1;
      if ( !v9 )
      {
        *_errno() = 13;
        v10 = __doserrno();
        *v10 = GetLastError();
      }
    }
  }
  else
  {
    memset(Buffer, 0, 0x1000u);
    v12 = _setmode_lk(FileHandle, 0x8000);
    while ( 1 )
    {
      v6 = 4096;
      if ( v5 < 4096 )
        v6 = v5;
      v7 = _write_lk(FileHandle, (char *)Buffer, v6);
      if ( v7 == -1 )
        break;
      v5 -= v7;
      if ( v5 <= 0 )
        goto LABEL_13;
    }
    if ( *__doserrno() == 5 )
      *_errno() = 13;
    v3 = -1;
LABEL_13:
    _setmode_lk(FileHandle, v12);
  }
  _lseek_lk(FileHandle, v13, 0);
  return v3;
}
