int __fastcall sub_5BA7B0(SOCKET *a1, char *a2, int *a3)
{
  int v3; // esi
  SOCKET v5; // edi
  int v7; // ebp
  u_long v8; // eax
  int v9; // eax
  int namelen; // [esp+10h] [ebp-18h] BYREF
  SOCKET *v11; // [esp+14h] [ebp-14h]
  struct sockaddr name; // [esp+18h] [ebp-10h] BYREF

  v3 = *a3;
  v11 = a1;
  sub_5BDB90();
  v5 = socket(2, 2, 17);
  if ( v5 == -1 )
    return 1;
  v7 = v3 + 100;
  if ( __OFSUB__(v3, v3 + 100) )
  {
    v9 = (int)a3;
LABEL_10:
    if ( v9 )
      return 2;
  }
  else
  {
    while ( 1 )
    {
      sub_5BAC40(a2, v3, (int)&name, 0);
      v8 = htonl(0x7F000001u);
      if ( *(_DWORD *)&name.sa_data[2] == v8 )
        *(_DWORD *)&name.sa_data[2] = 0;
      v9 = bind(v5, &name, 16);
      if ( !v9 )
        break;
      if ( ++v3 >= v7 )
        goto LABEL_10;
    }
  }
  if ( !v3 )
  {
    namelen = 16;
    if ( getsockname(v5, &name, &namelen) )
      return 2;
    v3 = ntohs(*(u_short *)name.sa_data);
  }
  *v11 = v5;
  *a3 = v3;
  return 0;
}
