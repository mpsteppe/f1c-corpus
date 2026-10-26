char __thiscall sub_56F810(int this, int a2)
{
  u_short v3; // ax
  SOCKET v4; // edx
  int v5; // ecx
  int v6; // esi
  int v7; // edi
  _BYTE *v8; // ecx
  _BYTE *v9; // ecx
  int namelen; // [esp+Ch] [ebp-14h] BYREF
  struct sockaddr name; // [esp+10h] [ebp-10h] BYREF

  name.sa_family = 2;
  *(_DWORD *)&name.sa_data[2] = htonl(0);
  v3 = htons(0);
  v4 = *(_DWORD *)(this + 2364);
  *(_WORD *)name.sa_data = v3;
  namelen = 16;
  getsockname(v4, &name, &namelen);
  *(_WORD *)(this + 2668) = *(_WORD *)name.sa_data;
  v5 = *(_DWORD *)(this + 2372);
  v6 = this + 2368;
  *(_DWORD *)(a2 + 4) = v5;
  v7 = v6 - a2;
  v8 = (_BYTE *)(a2 + 8);
  do
  {
    *v8 = v8[v7];
    ++v8;
  }
  while ( (unsigned int)&v8[-8 - a2] < 0x20 );
  *(_BYTE *)(a2 + 40) = *(_BYTE *)(v6 + 40);
  *(_BYTE *)(a2 + 41) = *(_BYTE *)(v6 + 41);
  *(_BYTE *)(a2 + 42) = *(_BYTE *)(v6 + 42);
  *(_BYTE *)(a2 + 43) = *(_BYTE *)(v6 + 43);
  *(_BYTE *)(a2 + 44) = *(_BYTE *)(v6 + 44);
  v9 = (_BYTE *)(a2 + 45);
  do
  {
    *v9 = v9[v7];
    ++v9;
  }
  while ( (unsigned int)&v9[-45 - a2] < 0xFF );
  *(_WORD *)(a2 + 300) = *(_WORD *)(v6 + 300);
  *(_DWORD *)(a2 + 304) = *(_DWORD *)(v6 + 304);
  return 1;
}
