char __thiscall sub_5A2340(HANDLE *this)
{
  HANDLE *v1; // esi
  SOCKET v2; // eax
  int v3; // ebp
  int v4; // eax
  u_short v5; // ax
  SOCKET v6; // edx
  HANDLE v7; // eax
  _DWORD *v8; // esi
  DWORD v9; // eax
  _DWORD *v10; // ebx
  int v11; // eax
  int **v12; // edi
  bool v13; // zf
  int *v14; // esi
  int *v15; // eax
  int v16; // esi
  _DWORD *v17; // esi
  _DWORD *v18; // eax
  int v19; // esi
  int *v20; // eax
  int *v21; // eax
  SOCKET v22; // edi
  SOCKET **v23; // ebx
  HANDLE v24; // eax
  _DWORD *v25; // esi
  DWORD v26; // eax
  int *v27; // eax
  int i; // eax
  int v29; // edi
  _DWORD *v30; // esi
  _DWORD *v31; // eax
  int v32; // eax
  int *v33; // eax
  SOCKET **v34; // esi
  SOCKET *v35; // eax
  int v37; // [esp-Ch] [ebp-160h]
  char v38; // [esp+Fh] [ebp-145h]
  _DWORD *v39; // [esp+10h] [ebp-144h]
  HANDLE *v40; // [esp+14h] [ebp-140h]
  HANDLE *v41; // [esp+18h] [ebp-13Ch] BYREF
  struct sockaddr addr; // [esp+1Ch] [ebp-138h] BYREF
  SOCKET s; // [esp+2Ch] [ebp-128h]
  int namelen; // [esp+30h] [ebp-124h] BYREF
  int addrlen; // [esp+38h] [ebp-11Ch] BYREF
  struct timeval timeout; // [esp+3Ch] [ebp-118h] BYREF
  fd_set readfds; // [esp+44h] [ebp-110h] BYREF
  int v48; // [esp+14Ch] [ebp-8h]
  int v49; // [esp+150h] [ebp-4h]

  v1 = this;
  v2 = (SOCKET)this[597];
  v3 = 0;
  v41 = this;
  HIBYTE(v39) = 0;
  timeout.tv_sec = 0;
  timeout.tv_usec = 0;
  readfds.fd_array[0] = v2;
  readfds.fd_count = 1;
  v4 = select(0, &readfds, 0, 0, &timeout);
  if ( v4 < -1 || v4 > 0 )
  {
    addr.sa_family = 2;
    *(_DWORD *)&addr.sa_data[2] = htonl(0);
    v5 = htons(0);
    v6 = (SOCKET)v1[597];
    *(_WORD *)addr.sa_data = v5;
    addrlen = 16;
    namelen = accept(v6, &addr, &addrlen);
    if ( namelen != -1 )
    {
      v7 = v1[770];
      v8 = v1 + 762;
      if ( v7 && ((v9 = WaitForSingleObject(v7, v8[9])) == 0 || v9 == 128) )
        v10 = v8;
      else
        v10 = 0;
      v11 = v10[4];
      v12 = (int **)(v10 + 4);
      v10[6] = v11;
      if ( v11 )
      {
        v3 = *(_DWORD *)v11;
        v13 = *(_DWORD *)v11 == 0;
        *(_BYTE *)(v11 + 8) = 0;
        if ( v13 || (v14 = *v12, v15 = 0, !*v12) )
        {
LABEL_14:
          v3 = 0;
        }
        else
        {
          while ( *v14 != v3 )
          {
            v15 = v14;
            v14 = (int *)v14[1];
            if ( !v14 )
              goto LABEL_14;
          }
          if ( v14 == (int *)v10[6] )
            v10[6] = v14[1];
          if ( v15 )
            v15[1] = v14[1];
          else
            *v12 = (int *)v14[1];
          if ( (int *)v10[5] == v14 )
            v10[5] = v15;
          --v10[7];
          if ( *((_BYTE *)v14 + 8) && *v14 )
            j__free((void *)*v14);
          j__free(v14);
        }
      }
      v16 = v3;
      if ( !v3 )
      {
        v40 = (HANDLE *)operator new(4u);
        v49 = 0;
        if ( v40 )
        {
          v17 = (_DWORD *)sub_59ECE0();
          v39 = v17;
        }
        else
        {
          v40 = 0;
          v17 = 0;
        }
        v48 = -1;
        if ( v17 )
        {
          v18 = operator new(0xCu);
          if ( v18 )
          {
            *v18 = v17;
            v18[1] = 0;
            *((_BYTE *)v18 + 8) = 1;
          }
          else
          {
            v18 = 0;
          }
          if ( *v10 )
          {
            *(_DWORD *)(v10[1] + 4) = v18;
          }
          else
          {
            *v10 = v18;
            v10[2] = v18;
          }
          v10[1] = v18;
          ++v10[3];
        }
        while ( 1 )
        {
          v19 = v3 + *v17;
          if ( v19 )
          {
            v20 = (int *)operator new(0xCu);
            if ( v20 )
            {
              *v20 = v19;
              v20[1] = 0;
              *((_BYTE *)v20 + 8) = 0;
            }
            else
            {
              v20 = 0;
            }
            if ( *v12 )
            {
              v20[1] = (int)*v12;
            }
            else
            {
              v10[5] = v20;
              v10[6] = v20;
            }
            *v12 = v20;
            ++v10[7];
          }
          v3 += 133192;
          if ( v3 >= 266384 )
            break;
          v17 = v39;
        }
        v21 = *v12;
        v16 = 0;
        v13 = *v12 == 0;
        v10[6] = v10[4];
        if ( !v13 )
        {
          v16 = *v21;
          v37 = *v21;
          *((_BYTE *)v21 + 8) = 0;
          if ( !sub_59F730(v10 + 4, v37, 1) )
            v16 = 0;
        }
      }
      if ( v40[770] )
        ReleaseMutex(v40[770]);
      v22 = s;
      *(_DWORD *)(v16 + 32) = s;
      namelen = 16;
      getpeername(v22, (struct sockaddr *)(v16 + 16), &namelen);
      sub_5A0B40((int)v40, v16);
      *(_DWORD *)&addr.sa_data[10] = 1;
      setsockopt(v22, 6, 1, &addr.sa_data[10], 4);
      v1 = v40;
      v38 = 1;
      v3 = 0;
    }
  }
  if ( sub_5A19D0((int)v1, (SOCKET)v1[598], 1) )
    v38 = 1;
  v23 = 0;
  v41 = 0;
  memset(&addr, 0, 12);
  v24 = v1[694];
  v25 = v1 + 690;
  v48 = 1;
  *(_DWORD *)&addr.sa_data[10] = v25;
  if ( v24 )
  {
    v26 = WaitForSingleObject(v24, v25[5]);
    if ( !v26 || v26 == 128 )
      v3 = (int)v25;
  }
  v27 = *(int **)v3;
  v13 = *(_DWORD *)v3 == 0;
  *(_DWORD *)(v3 + 8) = *(_DWORD *)v3;
  if ( !v13 )
  {
    for ( i = *v27; i; i = *v33 )
    {
      v29 = *(_DWORD *)(i + 32);
      if ( v29 != -1 )
      {
        v30 = operator new(4u);
        *v30 = v29;
        v31 = operator new(0xCu);
        if ( v31 )
        {
          *v31 = v30;
          v31[1] = 0;
          *((_BYTE *)v31 + 8) = 1;
        }
        else
        {
          v31 = 0;
        }
        if ( v23 )
        {
          *(_DWORD *)(*(_DWORD *)&addr.sa_family + 4) = v31;
        }
        else
        {
          v23 = (SOCKET **)v31;
          v41 = (HANDLE *)v31;
          *(_DWORD *)&addr.sa_data[2] = v31;
        }
        v25 = *(_DWORD **)&addr.sa_data[10];
        *(_DWORD *)&addr.sa_family = v31;
        ++*(_DWORD *)&addr.sa_data[6];
      }
      v32 = *(_DWORD *)(v3 + 8);
      if ( !v32 )
        break;
      v33 = *(int **)(v32 + 4);
      *(_DWORD *)(v3 + 8) = v33;
      if ( !v33 )
        break;
    }
  }
  if ( v25[4] )
    ReleaseMutex((HANDLE)v25[4]);
  v34 = v23;
  *(_DWORD *)&addr.sa_data[2] = v23;
  if ( v23 )
  {
    v35 = *v23;
    if ( *v23 )
    {
      do
      {
        if ( sub_5A19D0((int)v40, *v35, 0) )
          v38 = 1;
        v34 = (SOCKET **)v34[1];
        *(_DWORD *)&addr.sa_data[2] = v34;
        if ( !v34 )
          break;
        v35 = *v34;
      }
      while ( *v34 );
    }
  }
  sub_525140((int *)&v41);
  return v38;
}
