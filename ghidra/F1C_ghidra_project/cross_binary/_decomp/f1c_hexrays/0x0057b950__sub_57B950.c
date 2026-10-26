// f1c  0x0057b950  size=76
bool __thiscall sub_57B950(void *this, int namelen, int a3, int a4, int a5, SOCKET s)
{
  *(_DWORD *)this = namelen;
  namelen = 16;
  *((_DWORD *)this + 1) = a3;
  *((_DWORD *)this + 2) = a4;
  *((_DWORD *)this + 3) = a5;
  return getsockname(s, (struct sockaddr *)this + 1, &namelen) == 0;
}
