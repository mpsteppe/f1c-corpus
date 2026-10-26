int __thiscall sub_540760(_DWORD *this)
{
  int v2; // esi
  int i; // eax
  int v4; // eax
  int v5; // eax
  int v6; // esi
  int j; // eax
  int v8; // eax
  int v9; // eax
  int v10; // esi
  int k; // eax
  int v12; // eax
  int v13; // eax
  int v14; // esi
  int m; // eax
  int v16; // eax
  int v17; // eax

  if ( this[1271] )
  {
    v2 = this[1109];
    if ( v2 )
    {
      for ( i = *(_DWORD *)(v2 + 28); i; i = *(_DWORD *)(v2 + 28) )
      {
        v2 = i;
        v4 = *(_DWORD *)(*(_DWORD *)(i + 24) + 32);
        if ( v4 )
          *this = (*(int (__stdcall **)(int))(*(_DWORD *)v4 + 8))(v4);
        if ( *(_DWORD *)(v2 + 24) )
          FreeWrapper_7bcf(*(LPVOID *)(v2 + 24));
      }
      v5 = *(_DWORD *)(v2 + 32);
      if ( v5 )
        *this = (*(int (__stdcall **)(_DWORD))(*(_DWORD *)v5 + 8))(*(_DWORD *)(v2 + 32));
      FreeWrapper_7bcf((LPVOID)v2);
      this[1109] = 0;
    }
    v6 = this[1111];
    if ( v6 )
    {
      for ( j = *(_DWORD *)(v6 + 28); j; j = *(_DWORD *)(v6 + 28) )
      {
        v6 = j;
        v8 = *(_DWORD *)(*(_DWORD *)(j + 24) + 32);
        if ( v8 )
          *this = (*(int (__stdcall **)(int))(*(_DWORD *)v8 + 8))(v8);
        if ( *(_DWORD *)(v6 + 24) )
          FreeWrapper_7bcf(*(LPVOID *)(v6 + 24));
      }
      v9 = *(_DWORD *)(v6 + 32);
      if ( v9 )
        *this = (*(int (__stdcall **)(_DWORD))(*(_DWORD *)v9 + 8))(*(_DWORD *)(v6 + 32));
      FreeWrapper_7bcf((LPVOID)v6);
      this[1111] = 0;
    }
    v10 = this[1113];
    if ( v10 )
    {
      for ( k = *(_DWORD *)(v10 + 20); k; k = *(_DWORD *)(v10 + 20) )
      {
        v10 = k;
        v12 = *(_DWORD *)(*(_DWORD *)(k + 16) + 24);
        if ( v12 )
          *this = (*(int (__stdcall **)(int))(*(_DWORD *)v12 + 8))(v12);
        if ( *(_DWORD *)(v10 + 16) )
          FreeWrapper_7bcf(*(LPVOID *)(v10 + 16));
      }
      v13 = *(_DWORD *)(v10 + 24);
      if ( v13 )
        *this = (*(int (__stdcall **)(_DWORD))(*(_DWORD *)v13 + 8))(*(_DWORD *)(v10 + 24));
      FreeWrapper_7bcf((LPVOID)v10);
      this[1113] = 0;
    }
    v14 = this[1115];
    if ( v14 )
    {
      for ( m = *(_DWORD *)(v14 + 20); m; m = *(_DWORD *)(v14 + 20) )
      {
        v14 = m;
        v16 = *(_DWORD *)(*(_DWORD *)(m + 16) + 24);
        if ( v16 )
          *this = (*(int (__stdcall **)(int))(*(_DWORD *)v16 + 8))(v16);
        if ( *(_DWORD *)(v14 + 16) )
          FreeWrapper_7bcf(*(LPVOID *)(v14 + 16));
      }
      v17 = *(_DWORD *)(v14 + 24);
      if ( v17 )
        *this = (*(int (__stdcall **)(_DWORD))(*(_DWORD *)v17 + 8))(*(_DWORD *)(v14 + 24));
      FreeWrapper_7bcf((LPVOID)v14);
      this[1115] = 0;
    }
  }
  return 0;
}

