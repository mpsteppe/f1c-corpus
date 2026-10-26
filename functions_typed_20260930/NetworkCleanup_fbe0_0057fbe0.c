char __thiscall sub_57FBE0(int this)
{
  void *v2; // eax
  void *v3; // eax
  void *v4; // eax

  v2 = *(void **)(this + 2776);
  if ( v2 )
    WaitForSingleObject(v2, *(_DWORD *)(this + 2780));
  v3 = *(void **)(this + 2776);
  if ( v3 )
    ReleaseMutex(v3);
  v4 = *(void **)(this + 2804);
  if ( v4 )
    WaitForSingleObject(v4, *(_DWORD *)(this + 2808));
  if ( *(_DWORD *)(this + 2804) )
    ReleaseMutex(*(HANDLE *)(this + 2804));
  sub_57E570((_DWORD *)this);
  ThreadSafeLinkedListDestructionWithMutex((_DWORD *)this);
  (*(void (__thiscall **)(int))(*(_DWORD *)this + 48))(this);
  MutexProtectedLinkedListFlushDestroy((int *)this);
  MutexProtectedLinkedListDestruction((int *)this);
  if ( !*(_BYTE *)(this + 2676) )
    return 0;
  WSACleanup();
  *(_BYTE *)(this + 2676) = 0;
  return 1;
}

