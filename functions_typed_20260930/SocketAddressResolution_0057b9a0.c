bool __thiscall sub_57B9A0(struct sockaddr *name, SOCKET s)
{
  bool v3; // bl
  int namelen; // [esp+Ch] [ebp-4h] BYREF

  namelen = 16;
  v3 = getpeername(s, name, &namelen) == 0;
  return !getsockname(s, name + 1, &namelen) && v3;
}

