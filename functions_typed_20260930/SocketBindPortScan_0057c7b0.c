int __stdcall sub_57C7B0(SOCKET s, __int16 a2)
{
  int v2; // ebp
  u_short hostshort[4]; // [esp+10h] [ebp-30h]
  int v5; // [esp+18h] [ebp-28h]
  int v6; // [esp+1Ch] [ebp-24h]
  struct sockaddr name; // [esp+20h] [ebp-20h] BYREF
  int v8; // [esp+30h] [ebp-10h]

  v2 = 0;
  hostshort[0] = 2;
  htonl(0);
  htons(0);
  while ( 1 )
  {
    hostshort[1] = a2 + v2;
    v8 = *(_DWORD *)hostshort;
    HIWORD(v8) = htons(a2 + v2);
    *(_DWORD *)&name.sa_family = v8;
    *(_DWORD *)&name.sa_data[2] = 0;
    *(_DWORD *)&name.sa_data[6] = v5;
    *(_DWORD *)&name.sa_data[10] = v6;
    if ( !bind(s, &name, 16) )
      break;
    if ( WSAGetLastError() != 10022 && ++v2 < 100 )
      continue;
    return -1;
  }
  return hostshort[1];
}

