int __thiscall sub_563AB0(int this)
{
  int v2; // ebp
  int v3; // eax
  int v4; // edi
  u_int v5; // edx
  SOCKET *v6; // ecx
  int v7; // eax
  SOCKET *v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // ecx
  int v12; // eax
  int v13; // ebx
  BOOL v14; // edi
  int v15; // eax
  int v16; // ebx
  int v17; // edi
  int v18; // ecx
  int v19; // ebp
  int v20; // ebx
  int j; // edi
  int v22; // ebp
  int v23; // ebp
  int v24; // ecx
  const char *v25; // eax
  u_short v26; // ax
  int v28; // [esp+0h] [ebp-714h]
  int i; // [esp+10h] [ebp-704h]
  int fromlen; // [esp+14h] [ebp-700h] BYREF
  int v31; // [esp+18h] [ebp-6FCh]
  struct timeval timeout; // [esp+1Ch] [ebp-6F8h] BYREF
  struct sockaddr from; // [esp+24h] [ebp-6F0h] BYREF
  fd_set readfds; // [esp+34h] [ebp-6E0h] BYREF
  char buf[1500]; // [esp+138h] [ebp-5DCh] BYREF

  v2 = 0;
  v3 = *(_DWORD *)(this + 108);
  v4 = 0;
  v5 = 0;
  v31 = 0;
  timeout.tv_sec = 0;
  timeout.tv_usec = 0;
  fromlen = 16;
  readfds.fd_count = 0;
  if ( v3 > 0 )
  {
    v6 = *(SOCKET **)(this + 8);
    do
    {
      if ( v6[1] )
      {
        ++v4;
        if ( v5 < 0x40 )
        {
          readfds.fd_array[v5] = *v6;
          v5 = ++readfds.fd_count;
        }
      }
      v6 += 7;
      --v3;
    }
    while ( v3 );
    v31 = v4;
    if ( v4 > 0 )
    {
      v7 = select(64, &readfds, 0, 0, &timeout);
      if ( v7 != -1 )
      {
        if ( v7 )
        {
          for ( i = 0; i < *(_DWORD *)(this + 108); ++i )
          {
            v8 = (SOCKET *)(*(_DWORD *)(this + 8) + v2);
            if ( v8[1] )
            {
              if ( _WSAFDIsSet(*v8, &readfds) )
              {
                v9 = *(_DWORD *)(this + 8);
                fromlen = 16;
                v10 = recvfrom(*(_DWORD *)(v9 + v2), buf, 1499, 0, &from, &fromlen);
                v11 = *(_DWORD *)(this + 8) + v2;
                if ( *(_DWORD *)&from.sa_data[2] == *(_DWORD *)(v11 + 16)
                  && *(_WORD *)from.sa_data == *(_WORD *)(v11 + 14) )
                {
                  if ( v10 == -1 )
                  {
                    *(_DWORD *)(v11 + 4) = 0;
                  }
                  else
                  {
                    buf[v10] = 0;
                    v12 = sub_587C20(buf, aFinal);
                    v13 = *(_DWORD *)(*(_DWORD *)(this + 8) + v2 + 4);
                    v14 = v12 != 0;
                    if ( *(_WORD *)(v13 + 6) == 9999 )
                      *(_WORD *)(v13 + 6) = GetTickCount() - *(_WORD *)(*(_DWORD *)(this + 8) + v2 + 8);
                    AudioMixerPollingUpdateLoop(v13, buf);
                    if ( v14 )
                    {
                      v15 = sub_563E70(*(_DWORD *)(this + 4));
                      (*(void (__cdecl **)(int, int, _DWORD, int, int))(this + 120))(
                        this,
                        2,
                        *(_DWORD *)(this + 124),
                        v13,
                        100 * *(_DWORD *)(this + 112) / v15);
                      *(_DWORD *)(*(_DWORD *)(this + 8) + v2 + 4) = 0;
                    }
                  }
                }
              }
            }
            v2 += 28;
          }
        }
      }
    }
  }
  v16 = 0;
  if ( *(int *)(this + 108) > 0 )
  {
    v17 = 0;
    do
    {
      v18 = *(_DWORD *)(this + 8);
      if ( *(_DWORD *)(v17 + v18 + 4) )
      {
        v19 = v17 + v18;
        if ( GetTickCount() - *(_DWORD *)(v17 + v18 + 8) > 0xBB8 )
          *(_DWORD *)(v19 + 4) = 0;
      }
      ++v16;
      v17 += 28;
    }
    while ( v16 < *(_DWORD *)(this + 108) );
  }
  if ( *(_DWORD *)(this + 116) || *(_DWORD *)(this + 112) >= sub_563E70(*(_DWORD *)(this + 4)) && !v31 )
  {
    NetworkSocketArrayCleanup(this);
    AudioValueSetterCall(this, 0);
  }
  else
  {
    v20 = 0;
    if ( *(int *)(this + 108) > 0 )
    {
      for ( j = 0; ; j += 28 )
      {
        v22 = *(_DWORD *)(this + 112);
        if ( v22 >= sub_563E70(*(_DWORD *)(this + 4)) )
          break;
        if ( !*(_DWORD *)(j + *(_DWORD *)(this + 8) + 4) )
        {
          v23 = *(_DWORD *)LinearInterpolation(*(_DWORD *)(this + 4), v22);
          v24 = *(_DWORD *)(this + 8);
          ++*(_DWORD *)(this + 112);
          *(_DWORD *)(j + v24 + 4) = v23;
          *(_WORD *)(j + *(_DWORD *)(this + 8) + 12) = 2;
          v25 = (const char *)IPAddressToString(v23, v28);
          *(_DWORD *)(j + *(_DWORD *)(this + 8) + 16) = inet_addr(v25);
          v26 = ShortFieldGetter(v23);
          *(_WORD *)(j + *(_DWORD *)(this + 8) + 14) = htons(v26);
          sendto(
            *(_DWORD *)(j + *(_DWORD *)(this + 8)),
            off_5E4F38[*(_DWORD *)(v23 + 8)],
            dword_5B89A0[*(_DWORD *)(v23 + 8)],
            0,
            (const struct sockaddr *)(j + *(_DWORD *)(this + 8) + 12),
            16);
          *(_DWORD *)(j + *(_DWORD *)(this + 8) + 8) = GetTickCount();
        }
        if ( ++v20 >= *(_DWORD *)(this + 108) )
          return 0;
      }
    }
  }
  return 0;
}

