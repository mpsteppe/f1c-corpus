char __thiscall sub_59E230(int this, int a2)
{
  u_short v3; // ax
  SOCKET v4; // edx
  int namelen; // [esp+8h] [ebp-14h] BYREF
  struct sockaddr name; // [esp+Ch] [ebp-10h] BYREF

  name.sa_family = 2;
  *(_DWORD *)&name.sa_data[2] = htonl(0);
  v3 = htons(0);
  v4 = *(_DWORD *)(this + 2392);
  *(_WORD *)name.sa_data = v3;
  namelen = 16;
  getsockname(v4, &name, &namelen);
  *(_WORD *)(this + 2696) = *(_WORD *)name.sa_data;
  this += 2396;
  sub_59C130(a2, this);
  *(_WORD *)(a2 + 300) = *(_WORD *)(this + 300);
  *(_DWORD *)(a2 + 304) = *(_DWORD *)(this + 304);
  return 1;
}
