int __usercall sub_504731@<eax>(int a1@<ebp>)
{
  int v1; // ecx
  _DWORD *v2; // esi
  _DWORD *v4; // eax
  _DWORD *v5; // ecx
  unsigned int v6; // edx
  unsigned int v7; // edi
  unsigned int v8; // edx
  unsigned int v9; // edi
  unsigned int v10; // eax
  unsigned int v11; // ecx
  int v12; // edi
  int v13; // eax
  int v14; // eax
  int v15; // eax
  unsigned int v16; // ecx
  void *v17; // edi
  unsigned int v18; // ebx
  unsigned int v19; // ebx
  unsigned int i; // edi
  _DWORD *v21; // ecx
  unsigned int j; // edi
  _DWORD *v23; // ecx
  unsigned int v24; // eax
  unsigned int k; // edi

  SEHHandlerInit();
  v2 = (_DWORD *)v1;
  if ( *(_BYTE *)(v1 + 8) != 1 )
    return -2147467259;
  v4 = *(_DWORD **)(v1 + 4);
  v5 = *(_DWORD **)v1;
  v6 = v4[1046];
  v7 = v5[1046];
  *(_DWORD *)(a1 - 24) = v6;
  if ( v6 <= v7 )
    *(_DWORD *)(a1 - 24) = v7;
  v8 = v4[1047];
  v9 = v5[1047];
  *(_DWORD *)(a1 - 32) = v8;
  if ( v8 >= v9 )
    *(_DWORD *)(a1 - 32) = v9;
  v10 = v4[1048];
  v11 = v5[1048];
  *(_DWORD *)(a1 - 28) = v10;
  if ( v10 >= v11 )
    *(_DWORD *)(a1 - 28) = v11;
  v12 = 16 * *(_DWORD *)(a1 - 24);
  v13 = OperatorNewNhMallocWrapper(v12);
  *(_DWORD *)(a1 - 20) = v13;
  *(_DWORD *)(a1 - 4) = 0;
  if ( v13 )
  {
    sub_5008C2(v13, 16, *(_DWORD *)(a1 - 24), (int (__thiscall *)(int))sub_5007EC);
    *(_DWORD *)(a1 - 16) = *(_DWORD *)(a1 - 20);
  }
  else
  {
    *(_DWORD *)(a1 - 16) = 0;
  }
  *(_DWORD *)(a1 - 4) = -1;
  if ( !*(_DWORD *)(a1 - 16) )
    return -2147467259;
  v14 = *(_DWORD *)(v2[1] + 4184);
  *(_DWORD *)(a1 - 24) = v14;
  v15 = OperatorNewNhMallocWrapper(16 * v14);
  *(_DWORD *)(a1 - 20) = v15;
  *(_DWORD *)(a1 - 4) = 1;
  if ( v15 )
  {
    sub_5008C2(v15, 16, *(_DWORD *)(a1 - 24), (int (__thiscall *)(int))sub_5007EC);
    *(_DWORD *)(a1 - 24) = *(_DWORD *)(a1 - 20);
  }
  else
  {
    *(_DWORD *)(a1 - 24) = 0;
  }
  *(_DWORD *)(a1 - 4) = -1;
  if ( *(_DWORD *)(a1 - 24) )
  {
    v16 = v12;
    v17 = *(void **)(a1 - 16);
    v18 = *(_DWORD *)(a1 - 28);
    *(_DWORD *)(a1 - 20) = 0;
    memset(v17, 0, v16);
    memset(*(void **)(a1 - 24), 0, 16 * *(_DWORD *)(v2[1] + 4184));
    if ( v18 )
    {
      do
      {
        v19 = *(_DWORD *)(a1 - 32);
        for ( i = 0; i < v19; ++i )
        {
          (*(void (__thiscall **)(_DWORD, unsigned int, _DWORD, _DWORD))(*(_DWORD *)*v2 + 4))(
            *v2,
            i,
            *(_DWORD *)(a1 - 20),
            *(_DWORD *)(a1 - 16));
          (*(void (__thiscall **)(_DWORD, unsigned int, _DWORD, _DWORD))(*(_DWORD *)v2[1] + 8))(
            v2[1],
            i,
            *(_DWORD *)(a1 - 20),
            *(_DWORD *)(a1 - 16));
        }
        v21 = (_DWORD *)v2[1];
        for ( j = v19; j < v21[1047]; ++j )
        {
          (*(void (__thiscall **)(_DWORD *, unsigned int, _DWORD, _DWORD))(*v21 + 8))(
            v21,
            j,
            *(_DWORD *)(a1 - 20),
            *(_DWORD *)(a1 - 24));
          v21 = (_DWORD *)v2[1];
        }
        v18 = *(_DWORD *)(a1 - 28);
        ++*(_DWORD *)(a1 - 20);
      }
      while ( *(_DWORD *)(a1 - 20) < v18 );
    }
    v23 = (_DWORD *)v2[1];
    if ( v18 < v23[1048] )
    {
      v24 = v23[1047];
      do
      {
        for ( k = 0; k < v24; ++k )
        {
          (*(void (__thiscall **)(_DWORD *, unsigned int, unsigned int, _DWORD))(*v23 + 8))(
            v23,
            k,
            v18,
            *(_DWORD *)(a1 - 24));
          v23 = (_DWORD *)v2[1];
          v24 = v23[1047];
        }
        v23 = (_DWORD *)v2[1];
        ++v18;
      }
      while ( v18 < v23[1048] );
    }
    FreeWrapper_7bcf(*(LPVOID *)(a1 - 16));
    FreeWrapper_7bcf(*(LPVOID *)(a1 - 24));
    return 0;
  }
  else
  {
    FreeWrapper_7bcf(*(LPVOID *)(a1 - 16));
    return -2147467259;
  }
}

