char __stdcall sub_4910D0(int a1)
{
  void **v1; // eax
  bool v2; // zf
  void *i; // eax
  int v4; // eax
  void **v5; // eax
  void **v6; // esi
  void **v7; // edi
  char v8; // al
  void *v9; // ebx

  v1 = *(void ***)a1;
  v2 = *(_DWORD *)a1 == 0;
  *(_DWORD *)(a1 + 8) = *(_DWORD *)a1;
  if ( !v2 )
  {
    for ( i = *v1; i; i = *v5 )
    {
      LinkedListNodePrepend(i);
      v4 = *(_DWORD *)(a1 + 8);
      if ( !v4 )
        break;
      v5 = *(void ***)(v4 + 4);
      *(_DWORD *)(a1 + 8) = v5;
      if ( !v5 )
        break;
    }
  }
  v6 = *(void ***)a1;
  if ( *(_DWORD *)a1 )
  {
    do
    {
      v7 = v6;
      v8 = *((_BYTE *)v6 + 8);
      v6 = (void **)v6[1];
      if ( v8 )
      {
        v9 = *v7;
        if ( *v7 )
        {
          EmptyStub_0170(*v7);
          FreeWrapper_7bcf(v9);
        }
      }
      FreeWrapper_7bcf(v7);
    }
    while ( v6 );
  }
  *(_DWORD *)a1 = 0;
  *(_DWORD *)(a1 + 4) = 0;
  *(_DWORD *)(a1 + 8) = 0;
  *(_DWORD *)(a1 + 12) = 0;
  return 1;
}

