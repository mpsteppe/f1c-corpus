char __stdcall sub_59BEA0(SOCKET s, int optval)
{
  bool v2; // zf
  SOCKET v3; // esi

  v2 = (_BYTE)optval == 0;
  v3 = s;
  optval = 1;
  if ( v2 )
  {
    setsockopt(s, 0xFFFF, 32, (const char *)&optval, 4);
  }
  else
  {
    setsockopt(s, 6, 1, (const char *)&optval, 4);
    s = 1;
    setsockopt(v3, 0xFFFF, 8, (const char *)&s, 4);
  }
  WSAAsyncSelect(v3, dword_FB22D0, 0x1A0Au, 63);
  return 1;
}
