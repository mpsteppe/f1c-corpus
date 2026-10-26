void __thiscall sub_582DC0(_DWORD *this)
{
  _DWORD *v1; // ebp
  int v2; // esi
  int v3; // edi
  _DWORD *v4; // edi
  _BYTE *v5; // ebx
  int *v6; // ebp
  int v7; // eax
  void *v8; // esi

  v1 = this;
  v2 = this[4];
  while ( v2 )
  {
    v3 = v2;
    v2 = *(_DWORD *)(v2 + 4);
    if ( *(_BYTE *)(v3 + 8) && *(_DWORD *)v3 )
      FreeWrapper_7bcf(*(LPVOID *)v3);
    FreeWrapper_7bcf((LPVOID)v3);
  }
  v1[4] = 0;
  v1[5] = 0;
  v1[6] = 0;
  v1[7] = 0;
  v4 = (_DWORD *)*v1;
  if ( *v1 )
  {
    do
    {
      v5 = v4;
      v4 = (_DWORD *)v4[1];
      if ( v5[8] )
      {
        v6 = *(int **)v5;
        if ( *(_DWORD *)v5 )
        {
          v7 = *v6;
          if ( *v6 )
          {
            v8 = (void *)(v7 - 4);
            NTimeCallbackLoopWithSEH(v7, 4156, *(_DWORD *)(v7 - 4), EmptyStub_aa60);
            FreeWrapper_7bcf(v8);
          }
          FreeWrapper_7bcf(v6);
        }
        v1 = this;
      }
      FreeWrapper_7bcf(v5);
    }
    while ( v4 );
  }
  *v1 = 0;
  v1[1] = 0;
  v1[2] = 0;
  v1[3] = 0;
}
