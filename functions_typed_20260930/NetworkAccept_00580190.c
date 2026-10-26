char __thiscall NetworkAccept(int this)
{
  int v1; // esi
  SOCKET v2; // eax
  int v3; // eax
  u_short v4; // ax
  SOCKET v5; // edx
  SOCKET v6; // edi
  void *v7; // eax
  int v8; // esi
  DWORD v9; // eax
  int v10; // ebx
  int *v11; // esi
  _DWORD *v12; // eax
  _DWORD *v13; // eax
  char *v14; // ecx
  char *v15; // eax
  SOCKET **v16; // edi
  void *v17; // eax
  int v18; // ebx
  DWORD v19; // eax
  char **v20; // eax
  bool v21; // zf
  char *v22; // eax
  int v23; // edi
  _DWORD *v24; // esi
  int v25; // eax
  int v26; // eax
  char **v27; // eax
  SOCKET **v28; // esi
  SOCKET *v29; // eax
  SOCKET **v30; // esi
  SOCKET **v31; // edi
  char v33; // [esp+13h] [ebp-13Dh]
  struct sockaddr addr; // [esp+18h] [ebp-138h] BYREF
  char optval[4]; // [esp+28h] [ebp-128h] BYREF
  int namelen; // [esp+2Ch] [ebp-124h] BYREF
  int addrlen; // [esp+30h] [ebp-120h] BYREF
  struct timeval timeout; // [esp+34h] [ebp-11Ch] BYREF
  _DWORD *v40; // [esp+3Ch] [ebp-114h]
  fd_set readfds; // [esp+40h] [ebp-110h] BYREF
  int v42; // [esp+14Ch] [ebp-4h]

  v1 = this;
  v2 = *(_DWORD *)(this + 2360);
  v33 = 0;
  timeout.tv_sec = 0;
  timeout.tv_usec = 0;
  readfds.fd_array[0] = v2;
  readfds.fd_count = 1;
  v3 = select(0, &readfds, 0, 0, &timeout);
  if ( v3 < -1 || v3 > 0 )
  {
    addr.sa_family = 2;
    *(_DWORD *)&addr.sa_data[2] = htonl(0);
    v4 = htons(0);
    v5 = *(_DWORD *)(v1 + 2360);
    *(_WORD *)addr.sa_data = v4;
    addrlen = 16;
    v6 = accept(v5, &addr, &addrlen);
    if ( v6 != -1 )
    {
      v7 = *(void **)(v1 + 3052);
      v8 = v1 + 3020;
      if ( v7 && ((v9 = WaitForSingleObject(v7, *(_DWORD *)(v8 + 36))) == 0 || v9 == 128) )
        v10 = v8;
      else
        v10 = 0;
      v11 = LinkedListNodeRemovalWithCleanupCallback((int **)(v10 + 16));
      if ( !v11 )
      {
        v12 = (_DWORD *)OperatorNewNhMallocWrapper(4);
        v40 = v12;
        v42 = 0;
        if ( v12 )
          v13 = ObjectAllocationWithSEH(v12, 0);
        else
          v13 = 0;
        v42 = -1;
        ZeroFillMemoryRegionWithStep((_DWORD *)v10, v13, 0);
        v11 = LinkedListNodeRemovalWithCleanupCallback((int **)(v10 + 16));
      }
      if ( *(_DWORD *)(this + 3052) )
        ReleaseMutex(*(HANDLE *)(this + 3052));
      Setter(v11, v6);
      v15 = PointerAdvance(v14);
      namelen = 16;
      getpeername(v6, (struct sockaddr *)v15, &namelen);
      sub_57DC10((_DWORD *)this, (int)v11);
      *(_DWORD *)optval = 1;
      setsockopt(v6, 6, 1, optval, 4);
      v1 = this;
      v33 = 1;
    }
  }
  if ( sub_57CB50((char *)v1, *(_DWORD *)(v1 + 2364), 1) )
    v33 = 1;
  v16 = 0;
  memset(&addr, 0, sizeof(addr));
  v17 = *(void **)(v1 + 2748);
  v18 = v1 + 2732;
  v42 = 1;
  if ( !v17 || (v19 = WaitForSingleObject(v17, *(_DWORD *)(v1 + 2752))) != 0 && v19 != 128 )
    v18 = 0;
  v20 = *(char ***)v18;
  v21 = *(_DWORD *)v18 == 0;
  *(_DWORD *)(v18 + 8) = *(_DWORD *)v18;
  if ( !v21 )
  {
    v22 = *v20;
    if ( v22 )
    {
      do
      {
        v23 = *(_DWORD *)OffsetGetter(v22);
        if ( v23 != -1 )
        {
          v24 = (_DWORD *)OperatorNewNhMallocWrapper(4);
          *v24 = v23;
          v25 = OperatorNewNhMallocWrapper(12);
          if ( v25 )
          {
            *(_DWORD *)v25 = v24;
            *(_DWORD *)(v25 + 4) = 0;
            *(_BYTE *)(v25 + 8) = 1;
          }
          else
          {
            v25 = 0;
          }
          if ( *(_DWORD *)&addr.sa_family )
          {
            *(_DWORD *)(*(_DWORD *)&addr.sa_data[2] + 4) = v25;
          }
          else
          {
            *(_DWORD *)&addr.sa_family = v25;
            *(_DWORD *)&addr.sa_data[6] = v25;
          }
          *(_DWORD *)&addr.sa_data[2] = v25;
          ++*(_DWORD *)&addr.sa_data[10];
        }
        v26 = *(_DWORD *)(v18 + 8);
        if ( !v26 )
          break;
        v27 = *(char ***)(v26 + 4);
        *(_DWORD *)(v18 + 8) = v27;
        if ( !v27 )
          break;
        v22 = *v27;
      }
      while ( v22 );
      v16 = *(SOCKET ***)&addr.sa_family;
    }
  }
  if ( *(_DWORD *)(this + 2748) )
    ReleaseMutex(*(HANDLE *)(this + 2748));
  v28 = v16;
  *(_DWORD *)&addr.sa_data[6] = v16;
  if ( v16 )
  {
    v29 = *v16;
    if ( *v16 )
    {
      do
      {
        if ( sub_57CB50((char *)this, *v29, 0) )
          v33 = 1;
        v28 = (SOCKET **)v28[1];
        *(_DWORD *)&addr.sa_data[6] = v28;
        if ( !v28 )
          break;
        v29 = *v28;
      }
      while ( *v28 );
    }
  }
  v30 = v16;
  while ( v30 )
  {
    v31 = v30;
    v30 = (SOCKET **)v30[1];
    if ( *((_BYTE *)v31 + 8) )
      FreeWrapper_7bcf(*v31);
    FreeWrapper_7bcf(v31);
  }
  return v33;
}

