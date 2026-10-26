void __thiscall sub_572DB0(int *this)
{
  int *v1; // ebp
  int v2; // esi
  int v3; // edi
  int v4; // edi
  int v5; // ebx
  void **v6; // ebp

  v1 = this;
  v2 = this[4];
  while ( v2 )
  {
    v3 = v2;
    v2 = *(_DWORD *)(v2 + 4);
    if ( *(_BYTE *)(v3 + 8) && *(_DWORD *)v3 )
      sub_5BE8AE();
    sub_5BE8AE();
  }
  v1[4] = 0;
  v1[5] = 0;
  v1[6] = 0;
  v1[7] = 0;
  v4 = *v1;
  while ( v4 )
  {
    v5 = v4;
    v4 = *(_DWORD *)(v4 + 4);
    if ( *(_BYTE *)(v5 + 8) )
    {
      v6 = *(void ***)v5;
      if ( *(_DWORD *)v5 )
      {
        if ( *v6 )
        {
          `eh vector destructor iterator'(*v6, 0x4840u, *((_DWORD *)*v6 - 1), (void (__thiscall *)(void *))nullsub_5);
          sub_5BE8AE();
        }
        sub_5BE8AE();
      }
      v1 = this;
    }
    sub_5BE8AE();
  }
  *v1 = 0;
  v1[1] = 0;
  v1[2] = 0;
  v1[3] = 0;
}
