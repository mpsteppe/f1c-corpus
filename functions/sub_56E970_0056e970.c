LPVOID __thiscall sub_56E970(void *this)
{
  int v2; // eax
  void *v3; // ebp
  char *v4; // esi
  int v5; // ebx
  int v6; // ecx
  int v7; // eax
  void *v8; // ebx
  int v9; // esi
  int v10; // eax
  int v11; // ebp
  void *v12; // eax
  int v13; // ecx
  int v14; // eax
  void *v15; // ebx
  int v16; // esi
  int v17; // eax
  int v18; // ebp
  void *v19; // eax
  int v20; // ecx
  int v21; // eax
  void *v22; // ebx
  int v23; // edx
  int v24; // eax
  int v25; // esi
  int v26; // ebp
  void *v27; // eax

  v2 = *((_DWORD *)this + 1);
  *(_DWORD *)this = 0;
  if ( v2 )
  {
    v3 = (void *)(v2 - 4);
    v4 = (char *)(v2 + 580 * *(_DWORD *)(v2 - 4));
    if ( *(_DWORD *)(v2 - 4) - 1 >= 0 )
    {
      v5 = *(_DWORD *)(v2 - 4);
      do
      {
        v4 -= 580;
        MultiFieldCleanupDestructor(v4);
        --v5;
      }
      while ( v5 );
    }
    FreeWrapper_7bcf(v3);
    *((_DWORD *)this + 1) = 0;
  }
  v6 = *((_DWORD *)this + 3);
  *((_DWORD *)this + 2) = 0;
  if ( v6 )
  {
    v7 = *(_DWORD *)(v6 - 4);
    v8 = (void *)(v6 - 4);
    v9 = v6 + 48 * v7;
    v10 = v7 - 1;
    if ( v10 >= 0 )
    {
      v11 = v10 + 1;
      do
      {
        v12 = *(void **)(v9 - 48);
        v9 -= 48;
        if ( v12 )
          FreeWrapper_7bcf(v12);
        --v11;
      }
      while ( v11 );
    }
    FreeWrapper_7bcf(v8);
    *((_DWORD *)this + 3) = 0;
  }
  v13 = *((_DWORD *)this + 5);
  *((_DWORD *)this + 4) = 0;
  if ( v13 )
  {
    v14 = *(_DWORD *)(v13 - 4);
    v15 = (void *)(v13 - 4);
    v16 = v13 + 48 * v14;
    v17 = v14 - 1;
    if ( v17 >= 0 )
    {
      v18 = v17 + 1;
      do
      {
        v19 = *(void **)(v16 - 48);
        v16 -= 48;
        if ( v19 )
          FreeWrapper_7bcf(v19);
        --v18;
      }
      while ( v18 );
    }
    FreeWrapper_7bcf(v15);
    *((_DWORD *)this + 5) = 0;
  }
  v20 = *((_DWORD *)this + 7);
  *((_DWORD *)this + 6) = 0;
  if ( v20 )
  {
    v21 = *(_DWORD *)(v20 - 4);
    v22 = (void *)(v20 - 4);
    v23 = 9 * v21;
    v24 = v21 - 1;
    v25 = v20 + 8 * v23;
    if ( v24 >= 0 )
    {
      v26 = v24 + 1;
      do
      {
        v27 = *(void **)(v25 - 72);
        v25 -= 72;
        if ( v27 )
          FreeWrapper_7bcf(v27);
        --v26;
      }
      while ( v26 );
    }
    FreeWrapper_7bcf(v22);
    *((_DWORD *)this + 7) = 0;
  }
  if ( *((_DWORD *)this + 9) )
  {
    FreeWrapper_7bcf(*((LPVOID *)this + 9));
    if ( *((_DWORD *)this + 10) )
      FreeWrapper_7bcf(*((LPVOID *)this + 10));
    if ( *((_DWORD *)this + 11) )
      FreeWrapper_7bcf(*((LPVOID *)this + 11));
  }
  *((_DWORD *)this + 8) = 0;
  *((_DWORD *)this + 9) = 0;
  *((_DWORD *)this + 10) = 0;
  *((_DWORD *)this + 11) = 0;
  *((_DWORD *)this + 12) = 0;
  return QuadPointerFree((LPVOID *)this + 13);
}
