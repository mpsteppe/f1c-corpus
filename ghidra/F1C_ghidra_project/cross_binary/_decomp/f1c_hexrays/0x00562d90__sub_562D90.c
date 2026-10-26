// f1c  0x00562d90  size=160
int __thiscall sub_562D90(SOCKET *this)
{
  struct hostent *v2; // eax
  SOCKET v4; // eax
  struct sockaddr name; // [esp+4h] [ebp-10h] BYREF

  name.sa_family = 2;
  *(_WORD *)name.sa_data = htons(0x70E4u);
  *(_DWORD *)&name.sa_data[2] = inet_addr(::name);
  if ( *(_DWORD *)&name.sa_data[2] == -1 )
  {
    v2 = gethostbyname(::name);
    if ( !v2 )
      return 2;
    *(_DWORD *)&name.sa_data[2] = **(_DWORD **)v2->h_addr_list;
  }
  v4 = socket(2, 1, 6);
  this[34] = v4;
  if ( v4 == -1 )
    return 1;
  if ( !connect(v4, &name, 16) )
    return 0;
  closesocket(this[34]);
  return 3;
}
