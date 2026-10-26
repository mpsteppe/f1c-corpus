// f1c  0x00561bf0  size=321
int __fastcall sub_561BF0(_DWORD *a1, char *a2, int hostshort, int a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
  _DWORD *v10; // ebx
  SOCKET v11; // edi
  int v12; // esi
  u_long v13; // eax
  int v14; // eax
  int namelen; // [esp+14h] [ebp-14h] BYREF
  sockaddr name; // [esp+18h] [ebp-10h] BYREF

  v10 = a1;
  if ( a1 )
    *a1 = 0;
  sub_564660();
  v11 = socket(2, 2, 17);
  if ( v11 == -1 )
    return 1;
  v12 = hostshort;
  if ( __OFSUB__(hostshort, hostshort + 100) )
  {
    v14 = hostshort;
LABEL_11:
    if ( v14 )
      return 2;
  }
  else
  {
    while ( 1 )
    {
      sub_562010(a2, v12, (int)&name, 0);
      v13 = htonl(0x7F000001u);
      if ( *(_DWORD *)&name.sa_data[2] == v13 )
        *(_DWORD *)&name.sa_data[2] = 0;
      v14 = bind(v11, &name, 16);
      if ( !v14 )
        break;
      if ( ++v12 >= hostshort + 100 )
        goto LABEL_11;
    }
  }
  if ( !v12 )
  {
    namelen = 16;
    if ( getsockname(v11, &name, &namelen) )
      return 2;
    ntohs(*(u_short *)name.sa_data);
  }
  sub_561D40(v11, v11, a4, a5, a6, a7, a8, a9, a10);
  if ( !v10 )
    v10 = &off_5E4DFC;
  return sub_561FF0(v11, aMasterOpenspyN, 27900, *v10 + 236);
}
