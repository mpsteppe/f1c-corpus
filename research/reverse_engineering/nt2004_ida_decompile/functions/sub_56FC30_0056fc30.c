char __thiscall sub_56FC30(int this)
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
  sub_56E5A0((_DWORD *)this);
  sub_56E720((int *)this);
  (*(void (__thiscall **)(int))(*(_DWORD *)this + 48))(this);
  sub_56E7A0((int *)this);
  sub_56E820((int *)this);
  if ( !*(_BYTE *)(this + 2676) )
    return 0;
  WSACleanup();
  *(_BYTE *)(this + 2676) = 0;
  return 1;
}
