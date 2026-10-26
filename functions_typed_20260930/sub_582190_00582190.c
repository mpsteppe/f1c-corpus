char __thiscall sub_582190(int this)
{
  int *v1; // ebp
  int v2; // eax
  int i; // esi
  LPVOID *v4; // edi
  int j; // edi
  _BYTE *v6; // ebx
  int *v7; // ebp
  int v8; // eax
  void *v9; // esi

  v1 = (int *)this;
  LOBYTE(v2) = *(_BYTE *)(this + 40);
  if ( (_BYTE)v2 )
  {
    v2 = CloseHandle(*(HANDLE *)(this + 32));
    if ( v2 )
      v1[8] = 0;
  }
  for ( i = v1[4]; i; LOBYTE(v2) = FreeWrapper_7bcf(v4) )
  {
    v4 = (LPVOID *)i;
    i = *(_DWORD *)(i + 4);
    if ( *((_BYTE *)v4 + 8) && *v4 )
      FreeWrapper_7bcf(*v4);
  }
  v1[4] = 0;
  v1[5] = 0;
  v1[6] = 0;
  v1[7] = 0;
  for ( j = *v1; j; LOBYTE(v2) = FreeWrapper_7bcf(v6) )
  {
    v6 = (_BYTE *)j;
    j = *(_DWORD *)(j + 4);
    if ( v6[8] )
    {
      v7 = *(int **)v6;
      if ( *(_DWORD *)v6 )
      {
        v8 = *v7;
        if ( *v7 )
        {
          v9 = (void *)(v8 - 4);
          NTimeCallbackLoopWithSEH(v8, 4156, *(_DWORD *)(v8 - 4), EmptyStub_aa60);
          FreeWrapper_7bcf(v9);
        }
        FreeWrapper_7bcf(v7);
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

