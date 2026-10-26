int __thiscall NetworkSocketInitializationAndListen(__int16 *this, char *a2, char a3)
{
  char v4; // bl
  SOCKET v5; // edx
  __int16 v6; // cx
  int v7; // edx
  int v9; // [esp+10h] [ebp-110h] BYREF
  char v10; // [esp+14h] [ebp-10Ch]
  int v11; // [esp+11Ch] [ebp-4h]

  (*(void (__thiscall **)(__int16 *))(*(_DWORD *)this + 72))(this);
  ThreadResumeWithMutexWait((int)this);
  v4 = 1;
  v10 = 0;
  v5 = *((_DWORD *)this + 591);
  v6 = this[1160];
  v11 = 0;
  if ( SocketBindPortScan(v5, v6) < 0 || SocketBindPortScan(*((_DWORD *)this + 590), this[1160] + 50) < 0 )
    v4 = 0;
  sub_587DD0((_BYTE *)this + 2376, a2, 0x1Fu);
  *((_BYTE *)this + 2407) = 0;
  *((_BYTE *)this + 2408) = 1;
  *((_BYTE *)this + 2411) = a3;
  *((_BYTE *)this + 2410) = 1;
  if ( !v4 )
    return 6;
  listen(*((_DWORD *)this + 590), 0x7FFFFFFF);
  ThreadSafeWriteWithMutex(this, 4);
  v7 = *(_DWORD *)this;
  v9 = 0;
  (*(void (__thiscall **)(__int16 *, int *, int, int))(v7 + 144))(this, &v9, 2, 1);
  MutexProtectedFieldWrite(this, v9);
  return 0;
}
