char __thiscall sub_5721B0(int this)
{
  int *v1; // ebp
  int v2; // eax
  int i; // esi
  int v4; // edi
  int j; // edi
  int v6; // ebx
  void **v7; // ebp

  v1 = (int *)this;
  LOBYTE(v2) = *(_BYTE *)(this + 40);
  if ( (_BYTE)v2 )
  {
    v2 = CloseHandle(*(HANDLE *)(this + 32));
    if ( v2 )
      v1[8] = 0;
  }
  for ( i = v1[4]; i; LOBYTE(v2) = sub_5BE8AE() )
  {
    v4 = i;
    i = *(_DWORD *)(i + 4);
    if ( *(_BYTE *)(v4 + 8) && *(_DWORD *)v4 )
      sub_5BE8AE();
  }
  v1[4] = 0;
  v1[5] = 0;
  v1[6] = 0;
  v1[7] = 0;
  for ( j = *v1; j; LOBYTE(v2) = sub_5BE8AE() )
  {
    v6 = j;
    j = *(_DWORD *)(j + 4);
    if ( *(_BYTE *)(v6 + 8) )
    {
      v7 = *(void ***)v6;
      if ( *(_DWORD *)v6 )
      {
        if ( *v7 )
        {
          `eh vector destructor iterator'(*v7, 0x4840u, *((_DWORD *)*v7 - 1), (void (__thiscall *)(void *))nullsub_5);
          sub_5BE8AE();
        }
        sub_5BE8AE();
      }
      v1 = (int *)this;
    }
  }
  *v1 = 0;
  v1[1] = 0;
  v1[2] = 0;
  v1[3] = 0;
  return v2;
}
