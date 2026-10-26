int __thiscall sub_5BC450(int this)
{
  const char *v2; // edi
  int v3; // ecx
  char *v4; // eax
  char *v5; // edx
  char v6; // cl
  struct hostent *v7; // eax
  SOCKET v9; // eax
  struct sockaddr name; // [esp+8h] [ebp-90h] BYREF
  char Buffer[128]; // [esp+18h] [ebp-80h] BYREF

  v2 = (const char *)(this + 12);
  v3 = sub_5BA4C0((char *)(this + 12), 0x14u);
  v4 = (char *)dword_7FEFE4;
  if ( dword_7FEFE4 )
  {
    v5 = &Buffer[-dword_7FEFE4];
    do
    {
      v6 = *v4;
      v4[(_DWORD)v5] = *v4;
      ++v4;
    }
    while ( v6 );
  }
  else
  {
    sprintf(Buffer, "%s.ms%d.gamespy.com", v2, v3);
  }
  name.sa_family = 2;
  *(_WORD *)name.sa_data = htons(0x70EEu);
  *(_DWORD *)&name.sa_data[2] = inet_addr(Buffer);
  if ( *(_DWORD *)&name.sa_data[2] == -1 )
  {
    v7 = gethostbyname(Buffer);
    if ( !v7 )
      return 2;
    *(_DWORD *)&name.sa_data[2] = **(_DWORD **)v7->h_addr_list;
  }
  if ( *(_DWORD *)(this + 1184) == -1 )
  {
    v9 = socket(2, 1, 6);
    *(_DWORD *)(this + 1184) = v9;
    if ( v9 == -1 )
      return 1;
  }
  if ( !connect(*(_DWORD *)(this + 1184), &name, 16) )
    return 0;
  closesocket(*(_DWORD *)(this + 1184));
  *(_DWORD *)(this + 1184) = -1;
  return 3;
}
