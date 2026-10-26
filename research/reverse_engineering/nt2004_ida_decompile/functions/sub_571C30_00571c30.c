char __thiscall sub_571C30(int this)
{
  int *v1; // ebx
  int v2; // eax
  _DWORD *v3; // ebp
  int i; // esi
  int v5; // edi
  int v6; // edi
  int v7; // ebx
  void **v8; // ebp

  v1 = (int *)this;
  LOBYTE(v2) = *(_BYTE *)(this + 40);
  if ( (_BYTE)v2 )
  {
    v2 = CloseHandle(*(HANDLE *)(this + 32));
    if ( v2 )
      v1[8] = 0;
  }
  v3 = v1 + 4;
  for ( i = v1[4]; i; LOBYTE(v2) = sub_5BE8AE() )
  {
    v5 = i;
    i = *(_DWORD *)(i + 4);
    if ( *(_BYTE *)(v5 + 8) )
    {
      if ( *(_DWORD *)v5 )
      {
        sub_576830(*(void **)v5);
        sub_5BE8AE();
      }
      v1 = (int *)this;
    }
  }
  *v3 = 0;
  v3[1] = 0;
  v3[2] = 0;
  v3[3] = 0;
  v6 = *v1;
  if ( *v1 )
  {
    do
    {
      v7 = v6;
      v6 = *(_DWORD *)(v6 + 4);
      if ( *(_BYTE *)(v7 + 8) )
      {
        v8 = *(void ***)v7;
        if ( *(_DWORD *)v7 )
        {
          if ( *v8 )
          {
            `eh vector destructor iterator'(*v8, 0x54u, *((_DWORD *)*v8 - 1), sub_576830);
            sub_5BE8AE();
          }
          sub_5BE8AE();
        }
      }
      LOBYTE(v2) = sub_5BE8AE();
    }
    while ( v6 );
    v1 = (int *)this;
  }
  *v1 = 0;
  v1[1] = 0;
  v1[2] = 0;
  v1[3] = 0;
  return v2;
}
